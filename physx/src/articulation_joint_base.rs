// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 16 April 2019

#![warn(clippy::all)]

/*!

*/

use crate::{
    articulation_joint::ArticulationJoint,
    articulation_joint_reduced_coordinate::ArticulationJointReducedCoordinate, base::Base,
    math::PxTransform, traits::Class,
};

use physx_sys::{
    PxArticulationJointBase_getChildPose,
    PxArticulationJointBase_getParentArticulationLink,
    PxArticulationJointBase_getParentPose,
    PxArticulationJointBase_setChildPose_mut,
    PxArticulationJointBase_setParentPose_mut,
    // PxArticulationJointBase_getChildArticulationLink,
    PxRigidActor_getGlobalPose,
};

/*******************************************************************************
 * Section IMPLEMENTATION                                                      *
 ******************************************************************************/

impl<T> ArticulationJointBase for T where T: Class<physx_sys::PxArticulationJointBase> + Base {}
pub trait ArticulationJointBase: Class<physx_sys::PxArticulationJointBase> + Base {
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

    /// Get the global pose of this joint.
    fn get_joint_transform_global(&self) -> PxTransform {
        // Avoid dealing with ArticulationLink directly so it's user data
        // type info doesn't need to be passed in here, since it's not needed.
        let outbound_link_global_pose: PxTransform = unsafe {
            PxRigidActor_getGlobalPose(PxArticulationJointBase_getParentArticulationLink(
                self.as_ptr(),
            ) as *mut _)
            .into()
        };
        let joint_pose = self.get_parent_pose();

        // model_to_world * model
        outbound_link_global_pose.transform(&joint_pose)
    }
}

/// A PxArticulatiopnJointBase new type wrapper with methods for safe casts.
pub struct JointMap {
    obj: physx_sys::PxArticulationJointBase,
}

unsafe impl<P> Class<P> for JointMap
where
    physx_sys::PxArticulationJointBase: Class<P>,
{
    fn as_ptr(&self) -> *const P {
        self.obj.as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut P {
        self.obj.as_mut_ptr()
    }
}

impl JointMap {
    /// # Safety
    /// this relies on `get_concrete_type` to determine the joint type,
    /// which has had issues with returning ConcreteType::Undefined for Actor subclasses.
    /// `try_cast_map` will return `None` when this would crash.
    pub unsafe fn cast_map<'a, Ret, ArtJoFn, ArcJoFn>(
        &'a mut self,
        mut art_fn: ArtJoFn,
        mut arc_fn: ArcJoFn,
    ) -> Ret
    where
        ArtJoFn: FnMut(&'a mut ArticulationJoint) -> Ret,
        ArcJoFn: FnMut(&'a mut ArticulationJointReducedCoordinate) -> Ret,
    {
        match self.get_concrete_type() {
            crate::base::ConcreteType::ArticulationJoint => {
                art_fn(&mut *(self as *mut _ as *mut ArticulationJoint))
            }
            crate::base::ConcreteType::ArticulationJointReducedCoordinate => {
                arc_fn(&mut *(self as *mut _ as *mut ArticulationJointReducedCoordinate))
            }
            _ => panic!(
                "get_concrete_type for {:?} returned an invalid type: {:?}",
                self.get_concrete_type_name(),
                self.get_concrete_type()
            ),
        }
    }

    pub fn try_cast_map<'a, Ret, ArtJoFn, ArcJoFn>(
        &mut self,
        mut art_fn: ArtJoFn,
        mut arc_fn: ArcJoFn,
    ) -> Option<Ret>
    where
        ArtJoFn: FnMut(&'a mut ArticulationJoint) -> Ret,
        ArcJoFn: FnMut(&'a mut ArticulationJointReducedCoordinate) -> Ret,
    {
        match self.get_concrete_type() {
            crate::base::ConcreteType::ArticulationJoint => Some(art_fn(unsafe {
                &mut *(self as *mut _ as *mut ArticulationJoint)
            })),
            crate::base::ConcreteType::ArticulationJointReducedCoordinate => Some(arc_fn(unsafe {
                &mut *(self as *mut _ as *mut ArticulationJointReducedCoordinate)
            })),
            _ => None,
        }
    }

    pub fn as_articulation_joint(&mut self) -> Option<&mut ArticulationJoint> {
        match self.get_concrete_type() {
            crate::base::ConcreteType::ArticulationJoint => unsafe {
                Some(&mut *(self as *mut _ as *mut ArticulationJoint))
            },
            _ => None,
        }
    }

    pub fn as_articulation_joint_reduced_coordinate(
        &mut self,
    ) -> Option<&mut ArticulationJointReducedCoordinate> {
        match self.get_concrete_type() {
            crate::base::ConcreteType::ArticulationJointReducedCoordinate => unsafe {
                Some(&mut *(self as *mut _ as *mut ArticulationJointReducedCoordinate))
            },
            _ => None,
        }
    }
}
