// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created:  2 April 2019

use super::traits::Class;

use physx_sys::{
    PxArticulationDrive, PxArticulationJointReducedCoordinate_getJointType,
    PxArticulationJointReducedCoordinate_setDriveParams_mut,
    PxArticulationJointReducedCoordinate_setDriveTarget_mut,
    PxArticulationJointReducedCoordinate_setJointType_mut,
    PxArticulationJointReducedCoordinate_setLimitParams_mut,
    PxArticulationJointReducedCoordinate_setMotion_mut, PxArticulationLimit,
};

pub use physx_sys::{
    PxArticulationAxis as ArticulationAxis, PxArticulationDriveType as ArticulationDriveType,
    PxArticulationJointType as ArticulationJointType, PxArticulationMotion as ArticulationMotion,
};

/// PxArticulationJointReducedCoordinate new type wrapper.
#[repr(transparent)]
pub struct ArticulationJointReducedCoordinate {
    obj: physx_sys::PxArticulationJointReducedCoordinate,
}

crate::DeriveClassForNewType!(
    ArticulationJointReducedCoordinate: PxArticulationJointReducedCoordinate,
    PxBase
);

unsafe impl Send for ArticulationJointReducedCoordinate {}
unsafe impl Sync for ArticulationJointReducedCoordinate {}

impl ArticulationJointReducedCoordinate {
    /// Set target angle around axis for this joint
    #[inline]
    pub fn set_drive_target(&mut self, rot: f32, axis: ArticulationAxis) {
        unsafe {
            PxArticulationJointReducedCoordinate_setDriveTarget_mut(
                self.as_mut_ptr(),
                axis,
                rot,
                true, // autowake, this is the default value, physx 4 didn't have this parameter
            )
        };
    }

    /// Set the Joint type.
    #[inline]
    pub fn set_joint_type(&mut self, joint_type: ArticulationJointType) {
        unsafe {
            PxArticulationJointReducedCoordinate_setJointType_mut(self.as_mut_ptr(), joint_type)
        }
    }

    /// Get the joint type.
    #[inline]
    pub fn get_joint_type(&self) -> ArticulationJointType {
        unsafe { PxArticulationJointReducedCoordinate_getJointType(self.as_ptr()) }
    }

    /// Set motion limits for Axis
    #[inline]
    pub fn set_limit(&mut self, axis: ArticulationAxis, min: f32, max: f32) {
        let limit = PxArticulationLimit {
            low: min,
            high: max,
        };
        unsafe {
            PxArticulationJointReducedCoordinate_setLimitParams_mut(
                self.as_mut_ptr(),
                axis,
                &limit,
            );
        }
    }

    /// set drive type of the associated joints
    #[inline]
    pub fn set_drive(
        &mut self,
        axis: ArticulationAxis,
        stiffness: f32,
        damping: f32,
        max_force: f32,
        drive_type: ArticulationDriveType,
    ) {
        let params = PxArticulationDrive {
            stiffness,
            damping,
            maxForce: max_force,
            driveType: drive_type,
        };

        unsafe {
            PxArticulationJointReducedCoordinate_setDriveParams_mut(
                self.as_mut_ptr(),
                axis,
                &params,
            )
        }
    }

    /// Set the ArticulationMotion for an axis.
    #[inline]
    pub fn set_motion(&mut self, axis: ArticulationAxis, motion: ArticulationMotion) {
        unsafe {
            PxArticulationJointReducedCoordinate_setMotion_mut(self.as_mut_ptr(), axis, motion);
        }
    }
}
