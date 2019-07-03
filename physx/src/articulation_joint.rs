// Author: Tom Olsson <mail@tomolsson.se>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 16 April 2019

#![warn(clippy::all)]
#![warn(rust_2018_idioms)]

/*!

*/

use super::articulation_joint_base::ArticulationJointBase;
use super::px_type::*;
use super::transform::na_to_px_q;
use log::*;
use nalgebra_glm as glm;
use physx_macros::*;
use physx_sys::*;

/*******************************************************************************
 * Section ENUMS                                                               *
 ******************************************************************************/

#[derive(Debug, Clone, Copy)]
pub enum ArticulationJointDriveType {
    Target,
    Error,
}

impl Into<PxArticulationJointDriveType::Enum> for ArticulationJointDriveType {
    fn into(self) -> PxArticulationJointDriveType::Enum {
        match self {
            ArticulationJointDriveType::Target => PxArticulationJointDriveType::eTARGET,
            ArticulationJointDriveType::Error => PxArticulationJointDriveType::eERROR,
        }
    }
}

/*******************************************************************************
 * Section ARTICULATIONJOINT                                                   *
 ******************************************************************************/

#[physx_type(inherit = "ArticulationJointBase")]
impl ArticulationJoint {
    /// set drive type of the associated joints
    pub fn set_drive_type(&mut self, _type: ArticulationJointDriveType) {
        unsafe { PxArticulationJoint_setDriveType_mut(self.get_raw_mut(), _type.into()) }
    }

    /// not implemented yet, not work for reduced coordinate
    pub fn set_orientation(&mut self, quat: glm::Quat) {
        unsafe {
            PxArticulationJoint_setTargetOrientation_mut(self.get_raw_mut(), &na_to_px_q(quat))
        };
    }
}
