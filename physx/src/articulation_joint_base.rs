// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 16 April 2019

#![warn(clippy::all)]

/*!

*/

use super::transform::{gl_to_px_tf, px_to_gl_tf};
use super::{
    articulation_joint_reduced_coordinate::ArticulationJointReducedCoordinate,
    articulation_link::ArticulationLink, base::Base, px_type::*,
};
use glam::Mat4;
use physx_macros::*;
use physx_sys::{
    PxArticulationJointBase, PxArticulationJointBase_getChildPose,
    PxArticulationJointBase_getParentArticulationLink, PxArticulationJointBase_getParentPose,
    PxArticulationJointBase_setChildPose_mut, PxArticulationJointBase_setParentPose_mut,
};

/*******************************************************************************
 * Section IMPLEMENTATION                                                               *
 ******************************************************************************/

#[physx_type(inherit = "Base")]
impl ArticulationJointBase {
    /// Set the pose of the joint in the child frame
    pub fn set_child_pose(&mut self, pose: Mat4) {
        unsafe {
            PxArticulationJointBase_setChildPose_mut(self.get_raw_mut(), &gl_to_px_tf(pose));
        }
    }

    /// Get the pose of the joint in the child frame
    pub fn get_child_pose(&self) -> Mat4 {
        px_to_gl_tf(unsafe { PxArticulationJointBase_getChildPose(self.get_raw()) })
    }

    /// Set the pose of the joint in the parent frame
    pub fn set_parent_pose(&mut self, pose: Mat4) {
        unsafe {
            PxArticulationJointBase_setParentPose_mut(self.get_raw_mut(), &gl_to_px_tf(pose));
        }
    }

    /// Get the pose of the joint in the parent frame
    pub fn get_parent_pose(&self) -> Mat4 {
        px_to_gl_tf(unsafe { PxArticulationJointBase_getParentPose(self.get_raw()) })
    }

    pub fn get_parent_articulation_link(&self) -> ArticulationLink {
        ArticulationLink::from_ptr(unsafe {
            PxArticulationJointBase_getParentArticulationLink(self.get_raw())
        })
    }

    pub fn get_joint_transform_global(&self) -> Mat4 {
        let outbound_link = self.get_parent_articulation_link();
        let outbound_link_global_pose = outbound_link.get_global_pose();

        let joint_pose = self.get_parent_pose();

        // model_to_world * model
        outbound_link_global_pose * joint_pose
    }

    pub fn as_reduced_joint_mut(&mut self) -> &mut ArticulationJointReducedCoordinate {
        assert!(self.is_type("PxArticulationJointReducedCoordinate"));

        unsafe {
            &mut *(self as *mut ArticulationJointBase as *mut ArticulationJointReducedCoordinate)
        }
    }

    pub fn as_reduced_joint(&self) -> &ArticulationJointReducedCoordinate {
        assert!(self.is_type("PxArticulationJointReducedCoordinate"));

        unsafe {
            &*(self as *const ArticulationJointBase as *const ArticulationJointReducedCoordinate)
        }
    }
}
