// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created:  2 April 2019

#![warn(clippy::all)]

/*!

*/
use super::{articulation_link::ArticulationDriveType, traits::Class};

use physx_sys::{
    PxArticulationAxis, PxArticulationJointDriveType,
    PxArticulationJointReducedCoordinate_getJointType,
    PxArticulationJointReducedCoordinate_setDriveTarget_mut,
    PxArticulationJointReducedCoordinate_setDrive_mut,
    PxArticulationJointReducedCoordinate_setJointType_mut,
    PxArticulationJointReducedCoordinate_setLimit_mut,
    PxArticulationJointReducedCoordinate_setMotion_mut,
    /* TODO implement
    PxArticulationJointReducedCoordinate_getDrive_mut,
    PxArticulationJointReducedCoordinate_getDriveTarget_mut,
    PxArticulationJointReducedCoordinate_getDriveVelocity_mut,
    PxArticulationJointReducedCoordinate_getFrictionCoefficient,
    PxArticulationJointReducedCoordinate_getLimit_mut,
    PxArticulationJointReducedCoordinate_getMaxJointVelocity,
    PxArticulationJointReducedCoordinate_getMotion,
    PxArticulationJointReducedCoordinate_setDriveVelocity_mut,
    PxArticulationJointReducedCoordinate_setMaxJointVelocity_mut,
    PxArticulationJointReducedCoordinate_setFrictionCoefficient_mut,
    */
    //PxArticulationJointReducedCoordinate_getConcreteTypeName,
    PxArticulationJointType, PxArticulationMotion,
};

/* todo[tolsson]
add a wrapper struct for PxArticulationJointReducedCoordinate (or trait object)
 */

////////////////////////////////////////////////////////////////////////////////
// Section ENUMS
////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////

#[allow(dead_code)]
#[derive(Debug, Clone, Copy)]
pub enum ArticulationMotion {
    Locked,
    Limited,
    Free,
}

impl Into<PxArticulationAxis::Enum> for ArticulationMotion {
    fn into(self) -> PxArticulationMotion::Enum {
        match self {
            ArticulationMotion::Locked => PxArticulationMotion::eLOCKED,
            ArticulationMotion::Limited => PxArticulationMotion::eLIMITED,
            ArticulationMotion::Free => PxArticulationMotion::eFREE,
        }
    }
}

////////////////////////////////////////////////////////////////////////////////

#[derive(Debug, Clone, Copy)]
pub enum ArticulationAxis {
    Twist,
    Swing1,
    Swing2,
    X,
    Y,
    Z,
}

impl ArticulationAxis {
    /// Iterator over all available axes
    pub fn all_axes() -> impl Iterator<Item = &'static Self> {
        [
            ArticulationAxis::Twist,
            ArticulationAxis::Swing1,
            ArticulationAxis::Swing2,
            ArticulationAxis::X,
            ArticulationAxis::Y,
            ArticulationAxis::Z,
        ]
        .iter()
    }

    /// Iterator over all linear (translative) axss
    pub fn linear_axes() -> impl Iterator<Item = &'static Self> {
        [
            ArticulationAxis::X,
            ArticulationAxis::Y,
            ArticulationAxis::Z,
        ]
        .iter()
    }

    /// Iterator over all angular (rotational) axes
    pub fn angular_axes() -> impl Iterator<Item = &'static Self> {
        [
            ArticulationAxis::Twist,
            ArticulationAxis::Swing1,
            ArticulationAxis::Swing2,
        ]
        .iter()
    }
}

impl Into<PxArticulationAxis::Enum> for ArticulationAxis {
    fn into(self) -> PxArticulationAxis::Enum {
        match self {
            ArticulationAxis::Twist => PxArticulationAxis::eTWIST,
            ArticulationAxis::Swing1 => PxArticulationAxis::eSWING1,
            ArticulationAxis::Swing2 => PxArticulationAxis::eSWING2,
            ArticulationAxis::X => PxArticulationAxis::eX,
            ArticulationAxis::Y => PxArticulationAxis::eY,
            ArticulationAxis::Z => PxArticulationAxis::eZ,
        }
    }
}

/******************************************************************************/

#[derive(Debug, Clone, Copy, PartialEq)]
pub enum ArticulationJointType {
    Prismatic,
    Revolute,
    Spherical,
    Fix,
    Undefined,
}

impl Into<PxArticulationJointType::Enum> for ArticulationJointType {
    fn into(self) -> PxArticulationJointType::Enum {
        match self {
            ArticulationJointType::Prismatic => PxArticulationJointType::ePRISMATIC,
            ArticulationJointType::Revolute => PxArticulationJointType::eREVOLUTE,
            ArticulationJointType::Spherical => PxArticulationJointType::eSPHERICAL,
            ArticulationJointType::Fix => PxArticulationJointType::eFIX,
            ArticulationJointType::Undefined => PxArticulationJointType::eUNDEFINED,
        }
    }
}

impl From<PxArticulationJointType::Enum> for ArticulationJointType {
    fn from(other: PxArticulationJointType::Enum) -> Self {
        match other {
            PxArticulationJointType::ePRISMATIC => ArticulationJointType::Prismatic,
            PxArticulationJointType::eREVOLUTE => ArticulationJointType::Revolute,
            PxArticulationJointType::eSPHERICAL => ArticulationJointType::Spherical,
            PxArticulationJointType::eFIX => ArticulationJointType::Fix,
            PxArticulationJointType::eUNDEFINED => ArticulationJointType::Undefined,
            _ => panic!("invalid joint type"),
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
// Section ArticulationJointReducedCoordinate

#[repr(transparent)]
pub struct ArticulationJointReducedCoordinate {
    obj: physx_sys::PxArticulationJointReducedCoordinate,
}

crate::ClassObj!(
    ArticulationJointReducedCoordinate: PxArticulationJointReducedCoordinate,
    PxArticulationBase,
    PxBase
);

impl ArticulationJointReducedCoordinate {
    /// Set target angle around axis for this joint
    pub fn set_drive_target(&mut self, rot: f32, axis: ArticulationAxis) {
        unsafe {
            PxArticulationJointReducedCoordinate_setDriveTarget_mut(
                self.as_mut_ptr(),
                axis.into(),
                rot,
            )
        };
    }

    /// set joint type
    pub fn set_joint_type(&mut self, joint_type: ArticulationJointType) {
        unsafe {
            PxArticulationJointReducedCoordinate_setJointType_mut(
                self.as_mut_ptr(),
                joint_type.into(),
            )
        }
    }

    /// get joint type
    pub fn get_joint_type(&self) -> ArticulationJointType {
        ArticulationJointType::from(unsafe {
            PxArticulationJointReducedCoordinate_getJointType(self.as_ptr())
        })
    }

    /// Set motion limits for Axis
    pub fn set_limit(&mut self, axis: ArticulationAxis, min: f32, max: f32) {
        unsafe {
            PxArticulationJointReducedCoordinate_setLimit_mut(
                self.as_mut_ptr(),
                axis.into(),
                min,
                max,
            );
        }
    }

    /// set drive type of the associated joints
    pub fn set_drive(
        &mut self,
        axis: ArticulationAxis,
        stiffness: f32,
        damping: f32,
        max_force: f32,
        drive_type: ArticulationDriveType,
    ) {
        unsafe {
            PxArticulationJointReducedCoordinate_setDrive_mut(
                self.as_mut_ptr(),
                axis.into(),
                stiffness,
                damping,
                max_force,
                drive_type.into(),
            )
        }
    }

    pub fn set_motion(&mut self, axis: ArticulationAxis, motion: ArticulationMotion) {
        unsafe {
            PxArticulationJointReducedCoordinate_setMotion_mut(
                self.as_mut_ptr(),
                axis.into(),
                motion.into(),
            );
        }
    }
}
