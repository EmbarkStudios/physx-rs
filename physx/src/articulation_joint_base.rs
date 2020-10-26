// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 16 April 2019

#![warn(clippy::all)]

/*!

*/

use crate::{
    base::Base,
    traits::Class,
    math::PxTransform,
    articulation_joint::ArticulationJoint,
    articulation_joint_reduced_coordinate::ArticulationJointReducedCoordinate,
};

pub(crate) use physx_sys::PxArticulationJointBase;

use physx_sys::{
    PxArticulationJointBase_getChildPose,
    PxArticulationJointBase_getParentPose,
    PxArticulationJointBase_setChildPose_mut,
    PxArticulationJointBase_setParentPose_mut,
    // PxArticulationJointBase_getParentArticulationLink,
    // PxArticulationJointBase_getChildArticulationLink,
};

/*******************************************************************************
 * Section IMPLEMENTATION                                                      *
 ******************************************************************************/

impl <T> ArticulationJointBase for T where T: Class<PxArticulationJointBase> + Base {}
pub trait ArticulationJointBase: Class<PxArticulationJointBase> + Base {
    /// Set the pose of the joint in the child frame
    fn set_child_pose(&mut self, pose: &PxTransform) {
        unsafe {
            PxArticulationJointBase_setChildPose_mut(self.as_mut_ptr(), pose.as_ptr());
        }
    }

    /// Get the pose of the joint in the child frame
    fn get_child_pose(&self) -> PxTransform {
        unsafe { PxArticulationJointBase_getChildPose(self.as_ptr()).into() }
    }

    /// Set the pose of the joint in the parent frame
    fn set_parent_pose(&mut self, pose: &PxTransform) {
        unsafe {
            PxArticulationJointBase_setParentPose_mut(self.as_mut_ptr(), pose.as_ptr());
        }
    }

    /// Get the pose of the joint in the parent frame
    fn get_parent_pose(&self) -> PxTransform {
        unsafe { PxArticulationJointBase_getParentPose(self.as_ptr()).into() }
    }
/*
    fn get_joint_transform_global(&self) -> PxTransform {
        let outbound_link = self.get_parent_articulation_link();
        let outbound_link_global_pose = outbound_link.get_global_pose();

        let joint_pose = self.get_parent_pose();

        // model_to_world * model
        outbound_link_global_pose.transform(&joint_pose)
    }
    */
}

pub struct JointMap {
    obj: *mut physx_sys::PxArticulationJointBase,
    //phantom_user_data: PhantomData<>,
}

unsafe impl<P> Class<P> for JointMap where physx_sys::PxArticulationBase: Class<P> {
    fn as_ptr(&self) -> *const P {
        self.obj as *const _ as *const _
    }

    fn as_mut_ptr(&mut self) -> *mut P {
        self.obj as *mut _
    }
}

impl JointMap {
    pub fn map<Ret, ArtJoFn, ArcJoFn>(
        &mut self,
        art_fn: ArtJoFn,
        arc_fn: ArcJoFn,
    ) -> Ret
    where
        ArtJoFn: FnOnce(&mut ArticulationJoint) -> Ret,
        ArcJoFn: FnOnce(&mut ArticulationJointReducedCoordinate) -> Ret,
    {
        match self.get_concrete_type() {
            crate::base::ConcreteType::ArticulationJoint => {
                art_fn(
                    unsafe {
                        &mut*(self.obj as *mut ArticulationJoint)
                    }
                )
            }
            crate::base::ConcreteType::ArticulationJointReducedCoordinate => {
                arc_fn(
                    unsafe {
                        &mut*(self.obj as *mut ArticulationJointReducedCoordinate)
                    }
                )
            }
            _ => unreachable!(),
        }
    }
}