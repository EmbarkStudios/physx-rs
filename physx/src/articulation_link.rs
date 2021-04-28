// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created:  2 April 2019

#![warn(clippy::all)]

/*!
A link of a reduced coordinate multibody.
 */

use crate::{
    articulation_joint_base::JointMap,
    owner::Owner,
    rigid_actor::RigidActor,
    rigid_body::RigidBody,
    shape::{Shape, ShapeFlag},
    traits::{Class, UserData},
};

use std::{marker::PhantomData, ptr::drop_in_place};

use physx_sys::{
    PxArticulationDriveType,
    PxArticulationLink_getChildren,
    PxArticulationLink_getInboundJoint,
    //PxArticulationLink_getArticulation,
    //PxArticulationLink_getConcreteTypeName,
    PxArticulationLink_getInboundJointDof,
    PxArticulationLink_getLinkIndex,
    PxArticulationLink_getNbChildren,
    PxArticulationLink_release_mut,
};

////////////////////////////////////////////////////////////////////////////////
// Section ENUMS
////////////////////////////////////////////////////////////////////////////////

#[derive(Debug, Clone, Copy)]
pub enum ArticulationDriveType {
    Acceleration,
    Force,
}

impl From<ArticulationDriveType> for PxArticulationDriveType::Enum {
    fn from(value: ArticulationDriveType) -> Self {
        match value {
            ArticulationDriveType::Acceleration => PxArticulationDriveType::eACCELERATION,
            ArticulationDriveType::Force => PxArticulationDriveType::eFORCE,
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
// Section PxArticulationLink
// /////////////////////////////////////////////////////////////////////////////

/// A new type wrapper for PxArticulationLink.  Parametrized by it's user data type,
/// and the type of it's Shapes.
#[repr(transparent)]
pub struct PxArticulationLink<L, Geom: Shape> {
    pub(crate) obj: physx_sys::PxArticulationLink,
    phantom_user_data: PhantomData<(L, Geom)>,
}

unsafe impl<L, Geom: Shape> UserData for PxArticulationLink<L, Geom> {
    type UserData = L;

    fn user_data_ptr(&self) -> &*mut std::ffi::c_void {
        &self.obj.userData
    }

    fn user_data_ptr_mut(&mut self) -> &mut *mut std::ffi::c_void {
        &mut self.obj.userData
    }
}

impl<L, Geom: Shape> Drop for PxArticulationLink<L, Geom> {
    fn drop(&mut self) {
        unsafe {
            drop_in_place(self.get_user_data_mut() as *mut _);
            PxArticulationLink_release_mut(self.as_mut_ptr());
        }
    }
}

unsafe impl<P, L, Geom: Shape> Class<P> for PxArticulationLink<L, Geom>
where
    physx_sys::PxArticulationLink: Class<P>,
{
    fn as_ptr(&self) -> *const P {
        self.obj.as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut P {
        self.obj.as_mut_ptr()
    }
}

unsafe impl<L: Send, Geom: Shape + Send> Send for PxArticulationLink<L, Geom> {}
unsafe impl<L: Sync, Geom: Shape + Sync> Sync for PxArticulationLink<L, Geom> {}

impl<L, Geom: Shape> RigidActor for PxArticulationLink<L, Geom> {
    type Shape = Geom;
}

impl<L, Geom: Shape> ArticulationLink for PxArticulationLink<L, Geom> {}

pub trait ArticulationLink: Class<physx_sys::PxArticulationLink> + RigidBody + UserData {
    /// # Safety
    /// Owner's own the pointer they wrap, using the pointer after dropping the Owner,
    /// or creating multiple Owners from the same pointer will cause UB.  Use `into_ptr` to
    /// retrieve the pointer and consume the Owner without dropping the pointee.
    /// Initializes user data.
    unsafe fn from_raw(
        ptr: *mut physx_sys::PxArticulationLink,
        user_data: Self::UserData,
    ) -> Option<Owner<Self>> {
        Owner::from_raw((ptr as *mut Self).as_mut()?.init_user_data(user_data))
    }

    /// Get the user data.
    fn get_user_data(&self) -> &Self::UserData {
        // Safety: all construction goes through from_raw, which calls init_user_data
        unsafe { UserData::get_user_data(self) }
    }

    /// Get the user data.
    fn get_user_data_mut(&mut self) -> &mut Self::UserData {
        // Safety: all construction goes through from_raw, which calls init_user_data
        unsafe { UserData::get_user_data_mut(self) }
    }

    /// Enable collisions for this link. Equivalent to setting SimulationShape to false for all attached shapes.
    fn enable_collision(&mut self, enable: bool) {
        for shape in self.get_shapes_mut() {
            shape.set_flag(ShapeFlag::SimulationShape, enable);
        }
    }

    /// Get inbound joint for this link
    fn get_inbound_joint(&self) -> Option<&JointMap> {
        unsafe {
            (&PxArticulationLink_getInboundJoint(self.as_ptr())
                as *const *mut physx_sys::PxArticulationJointBase as *const JointMap)
                .as_ref()
        }
    }

    /// Get the index of the this link in it's parent articulation's link list.
    fn get_link_index(&self) -> u32 {
        unsafe { PxArticulationLink_getLinkIndex(self.as_ptr()) }
    }

    /// Get the degrees of freedom of the inbound joint.
    fn get_inbound_joint_dof(&self) -> u32 {
        unsafe { PxArticulationLink_getInboundJointDof(self.as_ptr()) }
    }

    /// Get the number of children links this link has.
    fn get_nb_children(&self) -> u32 {
        unsafe { PxArticulationLink_getNbChildren(self.as_ptr()) }
    }

    /// Gets a Vec of the child links of this link.
    fn get_children(&self) -> Vec<&Self> {
        let capacity = self.get_nb_children();
        let mut buffer: Vec<&Self> = Vec::with_capacity(capacity as usize);
        unsafe {
            let new_len = PxArticulationLink_getChildren(
                self.as_ptr(),
                buffer.as_mut_ptr() as *mut *mut _,
                capacity,
                0,
            );
            buffer.set_len(new_len as usize);
            buffer
        }
    }
}
