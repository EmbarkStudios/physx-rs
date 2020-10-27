// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 17 April 2019

#![warn(clippy::all)]

/*!

*/
use crate::{
    math::{PxTransform, PxVec3},
    rigid_actor::RigidActor,
    traits::{Class, PxFlags},
};
use enumflags2::BitFlags;

use physx_sys::{
    PxForceMode, PxRigidBody, PxRigidBodyFlag, PxRigidBodyFlags, PxRigidBody_addForce_mut,
    PxRigidBody_addTorque_mut, PxRigidBody_clearForce_mut, PxRigidBody_clearTorque_mut,
    PxRigidBody_getAngularDamping, PxRigidBody_getAngularVelocity, PxRigidBody_getCMassLocalPose,
    PxRigidBody_getInvMass, PxRigidBody_getLinearDamping, PxRigidBody_getLinearVelocity,
    PxRigidBody_getMass, PxRigidBody_getMassSpaceInertiaTensor,
    PxRigidBody_getMassSpaceInvInertiaTensor, PxRigidBody_getMaxAngularVelocity,
    PxRigidBody_getMaxContactImpulse, PxRigidBody_getMaxDepenetrationVelocity,
    PxRigidBody_getMaxLinearVelocity, PxRigidBody_getMinCCDAdvanceCoefficient,
    PxRigidBody_getRigidBodyFlags, PxRigidBody_setAngularDamping_mut,
    PxRigidBody_setAngularVelocity_mut, PxRigidBody_setCMassLocalPose_mut,
    PxRigidBody_setForceAndTorque_mut, PxRigidBody_setLinearDamping_mut,
    PxRigidBody_setLinearVelocity_mut, PxRigidBody_setMassSpaceInertiaTensor_mut,
    PxRigidBody_setMass_mut, PxRigidBody_setMaxAngularVelocity_mut,
    PxRigidBody_setMaxContactImpulse_mut, PxRigidBody_setMaxDepenetrationVelocity_mut,
    PxRigidBody_setMaxLinearVelocity_mut, PxRigidBody_setMinCCDAdvanceCoefficient_mut,
    PxRigidBody_setRigidBodyFlag_mut, PxRigidBody_setRigidBodyFlags_mut,
};

/*******************************************************************************
 * Section ENUMERATIONS                                                        *
 ******************************************************************************/
pub type RigidBodyFlags = BitFlags<RigidBodyFlag>;

impl PxFlags for RigidBodyFlags {
    type Target = PxRigidBodyFlags;

    fn into_px(self) -> Self::Target {
        PxRigidBodyFlags { mBits: self.bits() }
    }

    fn from_px(flags: Self::Target) -> Self {
        unsafe { BitFlags::new(flags.mBits) }
    }
}
#[derive(Debug, Copy, Clone, BitFlags)]
#[repr(u8)]
pub enum RigidBodyFlag {
    Kinematic = 1,
    UseKinematicTargetForSceneQueries = 2,
    EnableCCD = 4,
    EnableCCDFriction = 8,
    EnablePoseIntegrationPreview = 16,
    EnableSpeculativeCCD = 32,
    EnableCCDMaxContactImpulse = 64,
    RetainAccelerations = 128,
}

impl Into<PxRigidBodyFlag::Enum> for RigidBodyFlag {
    fn into(self) -> PxRigidBodyFlag::Enum {
        match self {
            RigidBodyFlag::Kinematic => 1,
            RigidBodyFlag::UseKinematicTargetForSceneQueries => 2,
            RigidBodyFlag::EnableCCD => 4,
            RigidBodyFlag::EnableCCDFriction => 8,
            RigidBodyFlag::EnablePoseIntegrationPreview => 16,
            RigidBodyFlag::EnableSpeculativeCCD => 32,
            RigidBodyFlag::EnableCCDMaxContactImpulse => 64,
            RigidBodyFlag::RetainAccelerations => 128,
        }
    }
}

impl From<PxRigidBodyFlag::Enum> for RigidBodyFlag {
    fn from(other: PxRigidBodyFlag::Enum) -> RigidBodyFlag {
        match other {
            1 => RigidBodyFlag::Kinematic,
            2 => RigidBodyFlag::UseKinematicTargetForSceneQueries,
            4 => RigidBodyFlag::EnableCCD,
            8 => RigidBodyFlag::EnableCCDFriction,
            16 => RigidBodyFlag::EnablePoseIntegrationPreview,
            32 => RigidBodyFlag::EnableSpeculativeCCD,
            64 => RigidBodyFlag::EnableCCDMaxContactImpulse,
            128 => RigidBodyFlag::RetainAccelerations,
            _ => panic!("invalid value in RigidBodyFlag"),
        }
    }
}

#[derive(Debug, Copy, Clone)]
#[repr(u32)]
pub enum ForceMode {
    Force = 0,
    Impulse = 1,
    VelocityChange = 2,
    Acceleration = 3,
}

impl Into<PxForceMode::Enum> for ForceMode {
    fn into(self) -> PxForceMode::Enum {
        match self {
            ForceMode::Force => 0,
            ForceMode::Impulse => 1,
            ForceMode::VelocityChange => 2,
            ForceMode::Acceleration => 3,
        }
    }
}

impl From<PxForceMode::Enum> for ForceMode {
    fn from(other: PxForceMode::Enum) -> ForceMode {
        match other {
            0 => ForceMode::Force,
            1 => ForceMode::Impulse,
            2 => ForceMode::VelocityChange,
            3 => ForceMode::Acceleration,
            _ => panic!("invalid value in ForceMode"),
        }
    }
}

pub trait RigidBody<H, M>: Class<PxRigidBody> + RigidActor<H, M> {
    /// Set the mass of this body
    fn set_mass(&mut self, mass: f32) {
        unsafe {
            PxRigidBody_setMass_mut(self.as_mut_ptr(), mass);
        };
    }

    fn get_angular_velocity(&self) -> PxVec3 {
        unsafe { PxRigidBody_getAngularVelocity(self.as_ptr()).into() }
    }

    fn get_linear_velocity(&self) -> PxVec3 {
        unsafe { PxRigidBody_getLinearVelocity(self.as_ptr()).into() }
    }

    /// Get a tuple (linear_velocity, angular_velocity)
    fn get_velocities(&self) -> (PxVec3, PxVec3) {
        (self.get_linear_velocity(), self.get_angular_velocity())
    }

    fn set_c_mass_local_pose(&mut self, pose: &PxTransform) {
        unsafe { PxRigidBody_setCMassLocalPose_mut(self.as_mut_ptr(), pose.as_ptr()) }
    }

    fn get_c_mass_local_pose(&self) -> PxTransform {
        unsafe { PxRigidBody_getCMassLocalPose(self.as_ptr()).into() }
    }

    fn get_mass(&self) -> f32 {
        unsafe { PxRigidBody_getMass(self.as_ptr()) }
    }

    fn get_inv_mass(&self) -> f32 {
        unsafe { PxRigidBody_getInvMass(self.as_ptr()) }
    }

    fn set_mass_space_inertia_tensor(&mut self, m: &PxVec3) {
        unsafe { PxRigidBody_setMassSpaceInertiaTensor_mut(self.as_mut_ptr(), m.as_ptr()) }
    }

    fn get_mass_space_inertia_tensor(&self) -> PxVec3 {
        unsafe { PxRigidBody_getMassSpaceInertiaTensor(self.as_ptr()).into() }
    }

    fn get_mass_space_inv_inertia_tensor(&self) -> PxVec3 {
        unsafe { PxRigidBody_getMassSpaceInvInertiaTensor(self.as_ptr()).into() }
    }

    fn set_linear_damping(&mut self, lin_damp: f32) {
        unsafe { PxRigidBody_setLinearDamping_mut(self.as_mut_ptr(), lin_damp) }
    }

    fn get_linear_damping(&self) -> f32 {
        unsafe { PxRigidBody_getLinearDamping(self.as_ptr()) }
    }

    fn set_angular_damping(&mut self, ang_damp: f32) {
        unsafe { PxRigidBody_setAngularDamping_mut(self.as_mut_ptr(), ang_damp) }
    }

    fn get_angular_damping(&self) -> f32 {
        unsafe { PxRigidBody_getAngularDamping(self.as_ptr()) }
    }

    fn set_linear_velocity(&mut self, lin_vel: &PxVec3, autowake: bool) {
        unsafe { PxRigidBody_setLinearVelocity_mut(self.as_mut_ptr(), lin_vel.as_ptr(), autowake) }
    }

    fn set_angular_velocity(&mut self, ang_vel: &PxVec3, autowake: bool) {
        unsafe { PxRigidBody_setAngularVelocity_mut(self.as_mut_ptr(), ang_vel.as_ptr(), autowake) }
    }

    fn set_max_angular_velocity(&mut self, max_ang_vel: f32) {
        unsafe { PxRigidBody_setMaxAngularVelocity_mut(self.as_mut_ptr(), max_ang_vel) }
    }

    fn get_max_angular_velocity(&self) -> f32 {
        unsafe { PxRigidBody_getMaxAngularVelocity(self.as_ptr()) }
    }

    fn set_max_linear_velocity(&mut self, max_lin_vel: f32) {
        unsafe { PxRigidBody_setMaxLinearVelocity_mut(self.as_mut_ptr(), max_lin_vel) }
    }

    fn get_max_linear_velocity(&self) -> f32 {
        unsafe { PxRigidBody_getMaxLinearVelocity(self.as_ptr()) }
    }

    fn add_force(&mut self, force: &PxVec3, mode: ForceMode, autowake: bool) {
        unsafe {
            PxRigidBody_addForce_mut(self.as_mut_ptr(), force.as_ptr(), mode.into(), autowake)
        }
    }

    fn add_torque(&mut self, torque: &PxVec3, mode: ForceMode, autowake: bool) {
        unsafe {
            PxRigidBody_addTorque_mut(self.as_mut_ptr(), torque.as_ptr(), mode.into(), autowake)
        }
    }

    fn clear_force(&mut self, mode: ForceMode) {
        unsafe { PxRigidBody_clearForce_mut(self.as_mut_ptr(), mode.into()) }
    }

    fn clear_torque(&mut self, mode: ForceMode) {
        unsafe { PxRigidBody_clearTorque_mut(self.as_mut_ptr(), mode.into()) }
    }

    fn set_force_and_torque(&mut self, force: &PxVec3, torque: &PxVec3, mode: ForceMode) {
        unsafe {
            PxRigidBody_setForceAndTorque_mut(
                self.as_mut_ptr(),
                force.as_ptr(),
                torque.as_ptr(),
                mode.into(),
            )
        }
    }

    fn set_rigid_body_flag(&mut self, flag: RigidBodyFlag, value: bool) {
        unsafe { PxRigidBody_setRigidBodyFlag_mut(self.as_mut_ptr(), flag.into(), value) }
    }

    fn set_rigid_body_flags(&mut self, flags: RigidBodyFlags) {
        unsafe { PxRigidBody_setRigidBodyFlags_mut(self.as_mut_ptr(), flags.into_px()) }
    }

    fn get_rigid_body_flags(&self) -> RigidBodyFlags {
        unsafe { RigidBodyFlags::from_px(PxRigidBody_getRigidBodyFlags(self.as_ptr())) }
    }

    fn set_min_ccd_advance_coefficient(&mut self, advance_coefficient: f32) {
        unsafe {
            PxRigidBody_setMinCCDAdvanceCoefficient_mut(self.as_mut_ptr(), advance_coefficient)
        }
    }

    fn get_min_ccd_advance_coefficient(&self) -> f32 {
        unsafe { PxRigidBody_getMinCCDAdvanceCoefficient(self.as_ptr()) }
    }

    /// sET the maximum allowed depenetration velocity
    fn set_max_depenetration_velocity(&mut self, bias_clamp: f32) {
        unsafe { PxRigidBody_setMaxDepenetrationVelocity_mut(self.as_mut_ptr(), bias_clamp) }
    }

    /// Get the maximum allowed depenetration velocity
    fn get_max_depenetration_velocity(&self) -> f32 {
        unsafe { PxRigidBody_getMaxDepenetrationVelocity(self.as_ptr()) }
    }

    /// Set the max number of contact impulses this body may experience
    fn set_max_contact_impulse(&mut self, max_impulse: f32) {
        unsafe { PxRigidBody_setMaxContactImpulse_mut(self.as_mut_ptr(), max_impulse) }
    }

    /// Get the max number of contact impulses this body may experience
    fn get_max_contact_impulse(&self) -> f32 {
        unsafe { PxRigidBody_getMaxContactImpulse(self.as_ptr()) }
    }
}
