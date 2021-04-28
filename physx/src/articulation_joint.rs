// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 16 April 2019

#![warn(clippy::all)]

/*!

*/

use crate::{math::PxQuat, traits::Class};

use physx_sys::{
    PxArticulationJointDriveType, PxArticulationJoint_setDriveType_mut,
    PxArticulationJoint_setTargetOrientation_mut,
    /* TODO implement!
    PxArticulationJoint_getDamping,
    PxArticulationJoint_getDriveType,
    PxArticulationJoint_getExternalCompliance,
    PxArticulationJoint_getInternalCompliance,
    PxArticulationJoint_getStiffness,
    PxArticulationJoint_getSwingLimit,
    PxArticulationJoint_getSwingLimitContactDistance,
    PxArticulationJoint_getSwingLimitEnabled,
    PxArticulationJoint_getTangentialDamping,
    PxArticulationJoint_getTangentialStiffness,
    PxArticulationJoint_getTargetOrientation,
    PxArticulationJoint_getTargetVelocity,
    PxArticulationJoint_getTwistLimit,
    PxArticulationJoint_getTwistLimitContactDistance,
    PxArticulationJoint_getTwistLimitEnabled,
    PxArticulationJoint_setDamping_mut,
    PxArticulationJoint_setExternalCompliance_mut,
    PxArticulationJoint_setInternalCompliance_mut,
    PxArticulationJoint_setStiffness_mut,
    PxArticulationJoint_setSwingLimit_mut,
    PxArticulationJoint_setSwingLimitContactDistance_mut,
    PxArticulationJoint_setSwingLimitEnabled_mut,
    PxArticulationJoint_setTangentialDamping_mut,
    PxArticulationJoint_setTangentialStiffness_mut,
    PxArticulationJoint_setTargetVelocity_mut,
    PxArticulationJoint_setTwistLimit_mut,
    PxArticulationJoint_setTwistLimitContactDistance_mut,
    PxArticulationJoint_setTwistLimitEnabled_mut,
    */
    //PxArticulationJoint_getConcreteTypeName,
};

/*******************************************************************************
 * Section ENUMS                                                               *
 ******************************************************************************/

#[derive(Debug, Clone, Copy)]
pub enum ArticulationJointDriveType {
    Target,
    Error,
}

impl From<ArticulationJointDriveType> for PxArticulationJointDriveType::Enum {
    fn from(value: ArticulationJointDriveType) -> Self {
        match value {
            ArticulationJointDriveType::Target => PxArticulationJointDriveType::eTARGET,
            ArticulationJointDriveType::Error => PxArticulationJointDriveType::eERROR,
        }
    }
}

/*******************************************************************************
 * Section ARTICULATIONJOINT                                                   *
*******************************************************************************/

/// A new type wrapper for PxArticulationJoint.
#[repr(transparent)]
pub struct ArticulationJoint {
    obj: physx_sys::PxArticulationJoint,
}

crate::DeriveClassForNewType!(
    ArticulationJoint: PxArticulationJoint,
    PxArticulationJointBase,
    PxBase
);

unsafe impl Send for ArticulationJoint {}
unsafe impl Sync for ArticulationJoint {}

impl ArticulationJoint {
    /// set drive type of the associated joints
    pub fn set_drive_type(&mut self, drive_type: ArticulationJointDriveType) {
        unsafe { PxArticulationJoint_setDriveType_mut(self.as_mut_ptr(), drive_type.into()) }
    }

    /// not implemented yet, not work for reduced coordinate
    pub fn set_target_orientation(&mut self, quat: &PxQuat) {
        unsafe { PxArticulationJoint_setTargetOrientation_mut(self.as_mut_ptr(), quat.as_ptr()) };
    }
}
