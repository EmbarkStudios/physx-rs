// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created:  2 April 2019

#![warn(clippy::all)]

/*!

*/
use super::{
    articulation_joint_base::*, articulation_link::ArticulationDriveType, body::*, px_type::*,
};
use glam::{Mat4, Vec3};
use log::*;
use physx_macros::*;
use physx_sys::*;

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
// Section BUILDER
////////////////////////////////////////////////////////////////////////////////

#[physx_type(inherit = "ArticulationJointBase")]
impl ArticulationJointReducedCoordinate {
    /// Set target angle around axis for this joint
    pub fn set_target(&mut self, rot: f32, axis: ArticulationAxis) {
        unsafe {
            PxArticulationJointReducedCoordinate_setDriveTarget_mut(
                self.get_raw_mut(),
                axis.into(),
                rot,
            )
        };
    }

    /// set joint type
    pub fn set_type(&mut self, _type: ArticulationJointType) {
        unsafe {
            PxArticulationJointReducedCoordinate_setJointType_mut(self.get_raw_mut(), _type.into())
        }
    }

    /// get joint type
    pub fn get_type(&self) -> ArticulationJointType {
        ArticulationJointType::from(unsafe {
            PxArticulationJointReducedCoordinate_getJointType(self.get_raw())
        })
    }

    /// Set motion limits for Axis
    pub fn set_limit(&mut self, axis: ArticulationAxis, min: f32, max: f32) {
        unsafe {
            PxArticulationJointReducedCoordinate_setLimit_mut(
                self.get_raw_mut(),
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
        _type: ArticulationDriveType,
    ) {
        unsafe {
            PxArticulationJointReducedCoordinate_setDrive_mut(
                self.get_raw_mut(),
                axis.into(),
                stiffness,
                damping,
                max_force,
                _type.into(),
            )
        }
    }

    pub fn set_motion(&mut self, axis: ArticulationAxis, motion: ArticulationMotion) {
        unsafe {
            PxArticulationJointReducedCoordinate_setMotion_mut(
                self.get_raw_mut(),
                axis.into(),
                motion.into(),
            );
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
// Section BUILDER
////////////////////////////////////////////////////////////////////////////////

// todo[tolsson]
pub struct JointBuilder {
    joint_type: ArticulationJointType,
    axis: Vec3,
    joint_frame: Mat4,
    joint_limit: [f32; 2],
}

impl Default for JointBuilder {
    fn default() -> Self {
        Self {
            joint_type: ArticulationJointType::Undefined,
            axis: Vec3::unit_x(),
            joint_frame: Mat4::identity(),
            joint_limit: [-std::f32::consts::PI, std::f32::consts::PI],
        }
    }
}

impl JointBuilder {
    pub fn build(&self, part: PartHandle) -> ArticulationJointReducedCoordinate {
        let z_axis = self.axis == Vec3::unit_z();
        let link = part.1 as *mut PxArticulationLink;

        unsafe {
            let joint = PxArticulationLink_getInboundJoint(link);

            let mut joint = ArticulationJointReducedCoordinate::from_ptr(
                joint as *mut PxArticulationJointReducedCoordinate,
            );
            joint.set_child_pose(Mat4::identity());
            joint.set_parent_pose(self.joint_frame);

            joint.set_type(self.joint_type);
            match self.joint_type {
                ArticulationJointType::Revolute => {
                    let axis = if z_axis {
                        ArticulationAxis::Swing2
                    } else {
                        ArticulationAxis::Twist
                    };
                    joint.set_motion(axis, ArticulationMotion::Limited);
                    joint.set_limit(axis, self.joint_limit[0], self.joint_limit[1]);
                }

                ArticulationJointType::Spherical => {
                    for axis in ArticulationAxis::angular_axes() {
                        joint.set_motion(*axis, ArticulationMotion::Free);
                    }
                }
                _ => { /* fixme */ }
            }

            joint
        }
    }

    pub fn joint_type(mut self, joint_type: ArticulationJointType) -> Self {
        self.joint_type = joint_type;
        self
    }

    pub fn axis(mut self, axis: Vec3) -> Self {
        self.axis = axis;
        self
    }

    pub fn transform_from_parent(mut self, transform: Mat4) -> Self {
        self.joint_frame = transform;
        self
    }

    pub fn limit(mut self, lower: f32, upper: f32) -> Self {
        self.joint_limit = [lower, upper];
        self
    }

    pub fn get_joint_type(&self) -> ArticulationJointType {
        self.joint_type
    }

    pub fn joint_transform(&self) -> Mat4 {
        self.joint_frame
    }
}
