// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 16 April 2019

#![warn(clippy::all)]

/*!

*/
use super::{
    articulation_reduced_coordinate::ArticulationReducedCoordinate,
    traits::*,
    transform::{gl_to_px_q, gl_to_px_v3, px_to_gl_q, px_to_gl_v3},
};
use enumflags2::BitFlags;
use glam::{Quat, Vec3};
use physx_sys::{
    PxArticulationCache, PxArticulationCacheFlags, PxArticulationRootLinkData, PxTransform_new_5,
};

////////////////////////////////////////////////////////////////////////////////
// Section ENUMS
////////////////////////////////////////////////////////////////////////////////

#[derive(Debug, Clone, Copy, BitFlags)]
#[repr(u8)]
pub enum ArticulationCacheFlag {
    Velocity = 1,
    Acceleration = 2,
    Position = 4,
    Force = 8,
    Root = 16,
}

impl ToFlags<PxArticulationCacheFlags> for BitFlags<ArticulationCacheFlag> {
    fn to_flags(self) -> PxArticulationCacheFlags {
        PxArticulationCacheFlags { mBits: self.bits() }
    }
}

macro_rules! ptr_to_slice_mut {
    ($ptr: ident, $me: ident) => {
        unsafe {
            std::slice::from_raw_parts_mut((*$me.get_raw_mut()).$ptr, $me.total_dofs as usize)
        }
    };
}

macro_rules! ptr_to_slice {
    ($ptr: ident, $me: ident) => {
        unsafe { std::slice::from_raw_parts((*$me.get_raw()).$ptr, $me.total_dofs as usize) }
    };
}

pub struct ArticulationRootLinkData {
    pub transform: (Quat, Vec3),
    pub world_lin_vel: Vec3,
    pub world_ang_vel: Vec3,
    pub world_lin_accel: Vec3,
    pub world_ang_accel: Vec3,
}

impl From<PxArticulationRootLinkData> for ArticulationRootLinkData {
    fn from(data: PxArticulationRootLinkData) -> Self {
        Self {
            transform: (px_to_gl_q(data.transform.q), px_to_gl_v3(data.transform.p)),
            world_lin_vel: px_to_gl_v3(data.worldLinVel),
            world_ang_vel: px_to_gl_v3(data.worldAngVel),
            world_lin_accel: px_to_gl_v3(data.worldLinAccel),
            world_ang_accel: px_to_gl_v3(data.worldAngAccel),
        }
    }
}

impl Into<PxArticulationRootLinkData> for ArticulationRootLinkData {
    fn into(self) -> PxArticulationRootLinkData {
        PxArticulationRootLinkData {
            transform: unsafe {
                PxTransform_new_5(
                    &gl_to_px_v3(self.transform.1),
                    &gl_to_px_q(self.transform.0),
                )
            },
            worldLinVel: gl_to_px_v3(self.world_lin_vel),
            worldAngVel: gl_to_px_v3(self.world_ang_vel),
            worldLinAccel: gl_to_px_v3(self.world_lin_accel),
            worldAngAccel: gl_to_px_v3(self.world_ang_accel),
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
    px_articulation_cache: *mut PxArticulationCache,
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

////////////////////////////////////////////////////////////////////////////////

impl ArticulationCache {
    pub fn new(px_articulation_cache: *mut PxArticulationCache) -> Self {
        Self {
            px_articulation_cache,
            link_offsets: [0; 64],
            link_dofs: [0; 64],
            total_dofs: 0,
        }
    }

    pub fn proxy(&self) -> Self {
        Self {
            px_articulation_cache: self.px_articulation_cache,
            link_offsets: self.link_offsets,
            link_dofs: self.link_dofs,
            total_dofs: self.total_dofs,
        }
    }

    pub fn compute_dof_information(&mut self, body: &ArticulationReducedCoordinate) {
        let mut offsets = [0u32; 64];
        let mut dofs = [0u8; 64];
        offsets[0] = 0; //We know that the root link does not have a joint

        for i in 1..body.get_nb_links() {
            if let Some(link) = body.part(i) {
                let link_index = link.get_link_index();
                let link_dofs = link.get_inbound_joint_dof();
                offsets[link_index] = link_dofs as u32;
                dofs[link_index] = link_dofs as u8;
            }
        }

        let mut count = 0;
        for offset in offsets.iter_mut().take(body.get_nb_links()).skip(1) {
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
        unsafe { ArticulationRootLinkData::from(*(*self.get_raw()).rootLinkData) }
    }

    pub fn set_root_link_data(&self, data: ArticulationRootLinkData) {
        unsafe {
            *(*self.get_raw()).rootLinkData = data.into();
        }
    }
}

impl GetRaw<PxArticulationCache> for ArticulationCache {
    fn get_raw(&self) -> *const PxArticulationCache {
        self.px_articulation_cache
    }

    fn get_raw_mut(&mut self) -> *mut PxArticulationCache {
        self.px_articulation_cache
    }
}
