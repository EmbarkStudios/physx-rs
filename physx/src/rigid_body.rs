// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 17 April 2019

#![warn(clippy::all)]

/*!

*/
use super::{px_type::*, rigid_actor::RigidActor, transform::*};
use enumflags2::*;
use glam::{Mat4, Vec3};
use physx_macros::*;
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

#[physx_type(inherit = "RigidActor")]
impl RigidBody {
    /// Set the mass of this body
    pub fn set_mass(&mut self, mass: f32) {
        unsafe {
            PxRigidBody_setMass_mut(self.get_raw_mut(), mass);
        };
    }

    pub fn get_angular_velocity(&self) -> Vec3 {
        px_to_gl_v3(unsafe { PxRigidBody_getAngularVelocity(self.get_raw()) })
    }

    pub fn get_linear_velocity(&self) -> Vec3 {
        px_to_gl_v3(unsafe { PxRigidBody_getLinearVelocity(self.get_raw()) })
    }

    /// Get a tuple (linear_velocity, angular_velocity)
    pub fn get_velocities(&self) -> (Vec3, Vec3) {
        (self.get_linear_velocity(), self.get_angular_velocity())
    }

    pub fn set_c_mass_local_pose(&mut self, pose: &Mat4) {
        unsafe { PxRigidBody_setCMassLocalPose_mut(self.get_raw_mut(), &gl_to_px_tf(*pose)) }
    }

    pub fn get_c_mass_local_pose(&self) -> Mat4 {
        unsafe { px_to_gl_tf(PxRigidBody_getCMassLocalPose(self.get_raw())) }
    }

    pub fn get_mass(&self) -> f32 {
        unsafe { PxRigidBody_getMass(self.get_raw()) }
    }

    pub fn get_inv_mass(&self) -> f32 {
        unsafe { PxRigidBody_getInvMass(self.get_raw()) }
    }

    pub fn set_mass_space_inertia_tensor(&mut self, m: Vec3) {
        unsafe { PxRigidBody_setMassSpaceInertiaTensor_mut(self.get_raw_mut(), &gl_to_px_v3(m)) }
    }

    pub fn get_mass_space_inertia_tensor(&self) -> Vec3 {
        unsafe { px_to_gl_v3(PxRigidBody_getMassSpaceInertiaTensor(self.get_raw())) }
    }

    pub fn get_mass_space_inv_inertia_tensor(&self) -> Vec3 {
        unsafe { px_to_gl_v3(PxRigidBody_getMassSpaceInvInertiaTensor(self.get_raw())) }
    }

    pub fn set_linear_damping(&mut self, lin_damp: f32) {
        unsafe { PxRigidBody_setLinearDamping_mut(self.get_raw_mut(), lin_damp) }
    }

    pub fn get_linear_damping(&self) -> f32 {
        unsafe { PxRigidBody_getLinearDamping(self.get_raw()) }
    }

    pub fn set_angular_damping(&mut self, ang_damp: f32) {
        unsafe { PxRigidBody_setAngularDamping_mut(self.get_raw_mut(), ang_damp) }
    }

    pub fn get_angular_damping(&self) -> f32 {
        unsafe { PxRigidBody_getAngularDamping(self.get_raw()) }
    }

    pub fn set_linear_velocity(&mut self, lin_vel: Vec3, autowake: bool) {
        unsafe {
            PxRigidBody_setLinearVelocity_mut(self.get_raw_mut(), &gl_to_px_v3(lin_vel), autowake)
        }
    }

    pub fn set_angular_velocity(&mut self, ang_vel: Vec3, autowake: bool) {
        unsafe {
            PxRigidBody_setAngularVelocity_mut(self.get_raw_mut(), &gl_to_px_v3(ang_vel), autowake)
        }
    }

    pub fn set_max_angular_velocity(&mut self, max_ang_vel: f32) {
        unsafe { PxRigidBody_setMaxAngularVelocity_mut(self.get_raw_mut(), max_ang_vel) }
    }

    pub fn get_max_angular_velocity(&self) -> f32 {
        unsafe { PxRigidBody_getMaxAngularVelocity(self.get_raw()) }
    }

    pub fn set_max_linear_velocity(&mut self, max_lin_vel: f32) {
        unsafe { PxRigidBody_setMaxLinearVelocity_mut(self.get_raw_mut(), max_lin_vel) }
    }

    pub fn get_max_linear_velocity(&self) -> f32 {
        unsafe { PxRigidBody_getMaxLinearVelocity(self.get_raw()) }
    }

    pub fn add_force(&mut self, force: Vec3, mode: ForceMode, autowake: bool) {
        unsafe {
            PxRigidBody_addForce_mut(
                self.get_raw_mut(),
                &gl_to_px_v3(force),
                mode.into(),
                autowake,
            )
        }
    }

    pub fn add_torque(&mut self, torque: Vec3, mode: ForceMode, autowake: bool) {
        unsafe {
            PxRigidBody_addTorque_mut(
                self.get_raw_mut(),
                &gl_to_px_v3(torque),
                mode.into(),
                autowake,
            )
        }
    }

    pub fn clear_force(&mut self, mode: ForceMode) {
        unsafe { PxRigidBody_clearForce_mut(self.get_raw_mut(), mode.into()) }
    }

    pub fn clear_torque(&mut self, mode: ForceMode) {
        unsafe { PxRigidBody_clearTorque_mut(self.get_raw_mut(), mode.into()) }
    }

    pub fn set_force_and_torque(&mut self, force: Vec3, torque: Vec3, mode: ForceMode) {
        unsafe {
            PxRigidBody_setForceAndTorque_mut(
                self.get_raw_mut(),
                &gl_to_px_v3(force),
                &gl_to_px_v3(torque),
                mode.into(),
            )
        }
    }

    pub fn set_rigid_body_flag(&mut self, flag: RigidBodyFlag, value: bool) {
        unsafe { PxRigidBody_setRigidBodyFlag_mut(self.get_raw_mut(), flag.into(), value) }
    }
    #[allow(non_snake_case)]
    pub fn set_rigid_body_flags(&mut self, in_flags: BitFlags<RigidBodyFlag>) {
        unsafe {
            PxRigidBody_setRigidBodyFlags_mut(
                self.get_raw_mut(),
                PxRigidBodyFlags {
                    mBits: in_flags.bits(),
                },
            )
        }
    }

    pub fn get_rigid_body_flags(&self) -> BitFlags<RigidBodyFlag> {
        unsafe {
            BitFlags::from_bits(PxRigidBody_getRigidBodyFlags(self.get_raw()).mBits)
                .expect("invalid flags")
        }
    }

    pub fn set_min_ccd_advance_coefficient(&mut self, advance_coefficient: f32) {
        unsafe {
            PxRigidBody_setMinCCDAdvanceCoefficient_mut(self.get_raw_mut(), advance_coefficient)
        }
    }

    pub fn get_min_ccd_advance_coefficient(&self) -> f32 {
        unsafe { PxRigidBody_getMinCCDAdvanceCoefficient(self.get_raw()) }
    }

    /// sET the maximum allowed depenetration velocity
    pub fn set_max_depenetration_velocity(&mut self, bias_clamp: f32) {
        unsafe { PxRigidBody_setMaxDepenetrationVelocity_mut(self.get_raw_mut(), bias_clamp) }
    }

    /// Get the maximum allowed depenetration velocity
    pub fn get_max_depenetration_velocity(&self) -> f32 {
        unsafe { PxRigidBody_getMaxDepenetrationVelocity(self.get_raw()) }
    }

    /// Set the max number of contact impulses this body may experience
    pub fn set_max_contact_impulse(&mut self, max_impulse: f32) {
        unsafe { PxRigidBody_setMaxContactImpulse_mut(self.get_raw_mut(), max_impulse) }
    }

    /// Get the max number of contact impulses this body may experience
    pub fn get_max_contact_impulse(&self) -> f32 {
        unsafe { PxRigidBody_getMaxContactImpulse(self.get_raw()) }
    }
}
