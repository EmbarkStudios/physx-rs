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
    shape::ShapeFlag,
    traits::{Class, UserData},
};

use std::marker::PhantomData;

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

impl Into<PxArticulationDriveType::Enum> for ArticulationDriveType {
    fn into(self) -> PxArticulationDriveType::Enum {
        match self {
            ArticulationDriveType::Acceleration => PxArticulationDriveType::eACCELERATION,
            ArticulationDriveType::Force => PxArticulationDriveType::eFORCE,
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
// Section ArticulationLink
// /////////////////////////////////////////////////////////////////////////////

#[repr(transparent)]
pub struct ArticulationLink<L, H, M> {
    pub(crate) obj: physx_sys::PxArticulationLink,
    // U is this objects user data type, M is the user data of the shapes
    // that may be attached to this body, which must be dropped :/
    // Tracking M is necessary for proper Drop impl, but it's a pain.
    phantom_user_data: PhantomData<(L, H, M)>,
}

unsafe impl<P, L, H, M> Class<P> for ArticulationLink<L, H, M>
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

impl<L, H, M> RigidActor<H, M> for ArticulationLink<L, H, M> {}
impl<L, H, M> RigidBody<H, M> for ArticulationLink<L, H, M> {}

impl<L, H, M> ArticulationLink<L, H, M> {
    pub(crate) unsafe fn from_raw<'a>(
        ptr: *mut physx_sys::PxArticulationLink,
        user_data: L,
    ) -> Option<Owner<Self>> {
        let link = (ptr as *mut Self).as_mut();
        Owner::from_raw(link?.init_user_data(user_data))
    }

    pub fn get_user_data(&self) -> &L {
        // Safety: all construction goes through from_raw, which calls init_user_data
        unsafe { UserData::get_user_data(self) }
    }

    pub fn get_user_data_mut(&mut self) -> &mut L {
        // Safety: all construction goes through from_raw, which calls init_user_data
        unsafe { UserData::get_user_data_mut(self) }
    }

    /// Enable collisions for this link. Equivalent to setting SimulationShape to false for all attached shapes.
    pub fn enable_collision(&mut self, enable: bool) {
        for shape in self.get_shapes_mut() {
            shape.set_flag(ShapeFlag::SimulationShape, enable);
        }
    }

    /// Get inbound joint for this link
    pub unsafe fn get_inbound_joint(&self) -> Option<&JointMap> {
        (PxArticulationLink_getInboundJoint(self.as_ptr()) as *const JointMap).as_ref()
    }

    pub fn get_link_index(&self) -> u32 {
        unsafe { PxArticulationLink_getLinkIndex(self.as_ptr()) }
    }

    pub fn get_inbound_joint_dof(&self) -> u32 {
        unsafe { PxArticulationLink_getInboundJointDof(self.as_ptr()) }
    }

    pub fn get_nb_children(&self) -> u32 {
        unsafe { PxArticulationLink_getNbChildren(self.as_ptr()) }
    }

    pub fn get_children(&self) -> Vec<&ArticulationLink<L, H, M>> {
        let capacity = self.get_nb_children();
        let mut buffer: Vec<&ArticulationLink<L, H, M>> = Vec::with_capacity(capacity as usize);
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

unsafe impl<L: Send, H: Send, M: Send> Send for ArticulationLink<L, H, M> {}
unsafe impl<L: Sync, H: Sync, M: Sync> Sync for ArticulationLink<L, H, M> {}

impl<L, H, M> Drop for ArticulationLink<L, H, M> {
    fn drop(&mut self) {
        for shape in self.get_shapes() {
            for material in shape.get_materials() {
                drop(material)
            }
        }
        drop(self.get_user_data_mut());
        unsafe {
            PxArticulationLink_release_mut(self.as_mut_ptr());
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
/* TODO collision callback!
impl Collidable for PxArticulationLink {
    fn on_collide(&mut self, _other: &impl RigidActor, _pairs: &[PxContactPair]) {
        todo!()
        /* TODO figure out contact callbacks, this solution is unworkable.
        let this_data = self.get_shapes()[0].get_simulation_filter_data();
        let other_data = other.get_shapes()[0].get_simulation_filter_data();

        // Intersect collision masks (n.b. assymetric)
        if (this_data.word0 & other_data.word1) == 0 {
            return;
        }

        // for multibodies, we use upper two words for pointer-wise to not trigger self-collisions
        if this_data.word2 == other_data.word2 && this_data.word3 == other_data.word3 {
            return;
        }

        let count = pairs
            .iter()
            .fold(0, |acc, pair| acc + pair.contactCount as usize);

        let user_data = self.user_data_mut();

        unsafe {
            let vec = &mut user_data.collision_points;
            vec.clear();
            vec.reserve(count);
            vec.set_len(count);
        }

        let mut offset = 0;
        for pair in pairs {
            let slice =
                &mut user_data.collision_points[offset..offset + pair.contactCount as usize];
            unsafe {
                PxContactPair_extractContacts(
                    pair,
                    slice.as_ptr() as *mut PxContactPairPoint,
                    u32::from(pair.contactCount),
                );
            }
            offset += pair.contactCount as usize;
        }

        user_data.has_collide = true;
        */
    }

    fn reset_collide(&mut self) {
        todo!()
    }

    fn has_collide(&self) -> bool {
        todo!()
    }

    fn read_collision_points(&self) -> &[PxContactPairPoint] {
        todo!()
    }
}
*/
////////////////////////////////////////////////////////////////////////////////
// Section BUILDER
////////////////////////////////////////////////////////////////////////////////
// TODO write a descriptor,
