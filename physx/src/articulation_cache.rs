// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 16 April 2019

#![warn(clippy::all)]

/*!

*/
use crate::{
    articulation_link::ArticulationLink,
    articulation_reduced_coordinate::ArticulationReducedCoordinate,
    math::{PxTransform, PxVec3},
    traits::Class,
};

use enumflags2::bitflags;
use std::ptr::NonNull;

use physx_sys::{PxArticulationCache, PxArticulationRootLinkData};

////////////////////////////////////////////////////////////////////////////////
// Section ENUMS
////////////////////////////////////////////////////////////////////////////////

#[bitflags]
#[derive(Debug, Clone, Copy)]
#[repr(u8)]
pub enum ArticulationCacheFlag {
    Velocity = 1,
    Acceleration = 2,
    Position = 4,
    Force = 8,
    Root = 16,
}

macro_rules! ptr_to_slice_mut {
    ($ptr: ident, $me: ident) => {
        unsafe {
            std::slice::from_raw_parts_mut(
                (*$me.px_articulation_cache.as_mut()).$ptr,
                $me.total_dofs as usize,
            )
        }
    };
}

macro_rules! ptr_to_slice {
    ($ptr: ident, $me: ident) => {
        unsafe {
            std::slice::from_raw_parts(
                (*$me.px_articulation_cache.as_ptr()).$ptr,
                $me.total_dofs as usize,
            )
        }
    };
}

pub struct ArticulationRootLinkData {
    pub transform: PxTransform,
    pub world_lin_vel: PxVec3,
    pub world_ang_vel: PxVec3,
    pub world_lin_accel: PxVec3,
    pub world_ang_accel: PxVec3,
}

impl From<PxArticulationRootLinkData> for ArticulationRootLinkData {
    fn from(data: PxArticulationRootLinkData) -> Self {
        Self {
            transform: data.transform.into(),
            world_lin_vel: data.worldLinVel.into(),
            world_ang_vel: data.worldAngVel.into(),
            world_lin_accel: data.worldLinAccel.into(),
            world_ang_accel: data.worldAngAccel.into(),
        }
    }
}

impl From<ArticulationRootLinkData> for PxArticulationRootLinkData {
    fn from(value: ArticulationRootLinkData) -> Self {
        Self {
            transform: value.transform.into(),
            worldLinVel: value.world_lin_vel.into(),
            worldAngVel: value.world_ang_vel.into(),
            worldLinAccel: value.world_lin_accel.into(),
            worldAngAccel: value.world_ang_accel.into(),
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
// Section STRUCT
////////////////////////////////////////////////////////////////////////////////

/*
Definition of PxArticulationCache:
    pub externalForces: *mut PxSpatialForce,
    pub denseJacobian: *mut f32,
    pub massMatrix: *mut f32,
    pub jointVelocity: *mut f32,
    pub jointAcceleration: *mut f32,
    pub jointPosition: *mut f32,
    pub jointForce: *mut f32,
    pub rootLinkData: *mut PxArticulationRootLinkData,
    pub coefficientMatrix: *mut f32,
    pub lambda: *mut f32,
    pub scratchMemory: *mut std::ffi::c_void,
    pub scratchAllocator: *mut std::ffi::c_void,
    pub version: u32,
    pub structgen_pad0: [u8; 4],
 */

pub struct ArticulationCache {
    px_articulation_cache: NonNull<PxArticulationCache>,
    /*
    NB:

    PxReducedCoordinateArticulations (which are the only users of cached) of the
        cache support a maximum of 64 links, so we simply preallocate that
        instead of doing heap allocations
         */
    link_offsets: [u32; 64], // 256 bytes
    link_dofs: [u8; 64],     // 64 bytes
    total_dofs: u32,
}

unsafe impl Class<PxArticulationCache> for ArticulationCache {
    fn as_ptr(&self) -> *const PxArticulationCache {
        self.px_articulation_cache.as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut PxArticulationCache {
        self.px_articulation_cache.as_ptr()
    }
}

////////////////////////////////////////////////////////////////////////////////

impl ArticulationCache {
    pub fn new(px_articulation_cache: NonNull<PxArticulationCache>) -> ArticulationCache {
        Self {
            px_articulation_cache,
            link_offsets: [0; 64],
            link_dofs: [0; 64],
            total_dofs: 0,
        }
    }

    /// # Safety
    /// Owner's own the pointer they wrap, using the pointer after dropping the Owner,
    /// or creating multiple Owners from the same pointer will cause UB.  Use `into_ptr` to
    /// retrieve the pointer and consume the Owner without dropping the pointee.
    pub(crate) fn from_raw(
        px_articulation_cache: *mut PxArticulationCache,
    ) -> Option<ArticulationCache> {
        Some(Self {
            px_articulation_cache: NonNull::new(px_articulation_cache)?,
            link_offsets: [0; 64],
            link_dofs: [0; 64],
            total_dofs: 0,
        })
    }

    pub fn proxy(&self) -> Self {
        Self {
            px_articulation_cache: self.px_articulation_cache,
            link_offsets: self.link_offsets,
            link_dofs: self.link_dofs,
            total_dofs: self.total_dofs,
        }
    }

    pub fn compute_dof_information(&mut self, articulation: &impl ArticulationReducedCoordinate) {
        let mut offsets = [0u32; 64];
        let mut dofs = [0u8; 64];
        offsets[0] = 0; //We know that the root link does not have a joint

        for link in articulation.get_links().into_iter().skip(1) {
            let link_index = link.get_link_index() as usize;
            let link_dofs = link.get_inbound_joint_dof() as usize;
            offsets[link_index] = link_dofs as u32;
            dofs[link_index] = link_dofs as u8;
        }

        let mut count = 0;
        for offset in offsets.iter_mut().take(articulation.get_nb_links()).skip(1) {
            let link_dofs = *offset;
            *offset = count;
            count += link_dofs;
        }

        self.link_offsets = offsets;
        self.link_dofs = dofs;
        self.total_dofs = count;
    }

    pub fn get_offset(&self, link_index: usize) -> u32 {
        self.link_offsets[link_index]
    }

    pub fn get_dofs(&self, link_index: usize) -> u8 {
        self.link_dofs[link_index]
    }

    pub fn set_joint_position(&mut self, link_index: usize, data: &[f32]) {
        let offset = self.get_offset(link_index) as usize;
        let dofs = self.get_dofs(link_index) as usize;
        // eprintln!(
        //     "Setting joint {} to {:?}, dofs={}, offset={}",
        //     link_index, data, dofs, offset
        // );
        let array = ptr_to_slice_mut!(jointPosition, self);
        array[offset..(dofs + offset)].clone_from_slice(&data[..dofs])
    }

    pub fn set_joint_velocity(&mut self, link_index: usize, data: &[f32]) {
        // pub jointVelocity: *mut f32,
        let array = ptr_to_slice_mut!(jointVelocity, self);
        let offset = self.get_offset(link_index) as usize;
        let dofs = self.get_dofs(link_index) as usize;
        array[offset..(dofs + offset)].clone_from_slice(&data[..dofs]);
    }

    pub fn set_joint_acceleration(&mut self, link_index: usize, data: &[f32]) {
        // pub jointAcceleration: *mut f32,
        let array = ptr_to_slice_mut!(jointAcceleration, self);
        let offset = self.get_offset(link_index) as usize;
        let dofs = self.get_dofs(link_index) as usize;
        array[offset..(dofs + offset)].clone_from_slice(&data[..dofs]);
    }

    pub fn set_joint_force(&mut self, link_index: usize, data: &[f32]) {
        // pub jointForce: *mut f32,
        let array = ptr_to_slice_mut!(jointForce, self);
        let offset = self.get_offset(link_index) as usize;
        let dofs = self.get_dofs(link_index) as usize;
        array[offset..(dofs + offset)].clone_from_slice(&data[..dofs]);
    }

    pub fn read_joint_position(&self, link_index: usize) -> &[f32] {
        let offset = self.get_offset(link_index) as usize;
        let dofs = self.get_dofs(link_index) as usize;
        &ptr_to_slice!(jointPosition, self)[offset..offset + dofs]
    }

    pub fn read_joint_velocity(&self, link_index: usize) -> &[f32] {
        let offset = self.get_offset(link_index) as usize;
        let dofs = self.get_dofs(link_index) as usize;
        &ptr_to_slice!(jointVelocity, self)[offset..offset + dofs]
    }

    pub fn read_joint_acceleration(&self, link_index: usize) -> &[f32] {
        let offset = self.get_offset(link_index) as usize;
        let dofs = self.get_dofs(link_index) as usize;
        &ptr_to_slice!(jointAcceleration, self)[offset..offset + dofs]
    }

    pub fn read_joint_force(&self, link_index: usize) -> &[f32] {
        let offset = self.get_offset(link_index) as usize;
        let dofs = self.get_dofs(link_index) as usize;
        &ptr_to_slice!(jointForce, self)[offset..offset + dofs]
    }

    pub fn read_root_link_data(&self) -> ArticulationRootLinkData {
        unsafe {
            ArticulationRootLinkData::from(*(*self.px_articulation_cache.as_ptr()).rootLinkData)
        }
    }

    pub fn set_root_link_data(&mut self, data: ArticulationRootLinkData) {
        unsafe {
            *(self.px_articulation_cache.as_mut().rootLinkData) = data.into();
        }
    }
}
