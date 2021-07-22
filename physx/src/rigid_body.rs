// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 17 April 2019

#![warn(clippy::all)]

/*!

*/
use std::marker::PhantomData;

use crate::{
    actor::{Actor, ActorFlag, ActorType},
    articulation_link::ArticulationLink,
    math::{PxTransform, PxVec3},
    rigid_actor::RigidActor,
    rigid_dynamic::RigidDynamic,
    traits::{Class, PxFlags},
};

use enumflags2::{bitflags, BitFlags};

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
        unsafe { BitFlags::from_bits_unchecked(flags.mBits) }
    }
}

#[bitflags]
#[derive(Debug, Copy, Clone)]
#[repr(u8)]
pub enum RigidBodyFlag {
    Kinematic = 1,
    UseKinematicTargetForSceneQueries = 2,
    EnableCcd = 4,
    EnableCcdFriction = 8,
    EnablePoseIntegrationPreview = 16,
    EnableSpeculativeCcd = 32,
    EnableCcdMaxContactImpulse = 64,
    RetainAccelerations = 128,
}

impl From<RigidBodyFlag> for PxRigidBodyFlag::Enum {
    fn from(value: RigidBodyFlag) -> Self {
        match value {
            RigidBodyFlag::Kinematic => 1,
            RigidBodyFlag::UseKinematicTargetForSceneQueries => 2,
            RigidBodyFlag::EnableCcd => 4,
            RigidBodyFlag::EnableCcdFriction => 8,
            RigidBodyFlag::EnablePoseIntegrationPreview => 16,
            RigidBodyFlag::EnableSpeculativeCcd => 32,
            RigidBodyFlag::EnableCcdMaxContactImpulse => 64,
            RigidBodyFlag::RetainAccelerations => 128,
        }
    }
}

impl From<PxRigidBodyFlag::Enum> for RigidBodyFlag {
    fn from(other: PxRigidBodyFlag::Enum) -> RigidBodyFlag {
        match other {
            1 => RigidBodyFlag::Kinematic,
            2 => RigidBodyFlag::UseKinematicTargetForSceneQueries,
            4 => RigidBodyFlag::EnableCcd,
            8 => RigidBodyFlag::EnableCcdFriction,
            16 => RigidBodyFlag::EnablePoseIntegrationPreview,
            32 => RigidBodyFlag::EnableSpeculativeCcd,
            64 => RigidBodyFlag::EnableCcdMaxContactImpulse,
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

impl From<ForceMode> for PxForceMode::Enum {
    fn from(value: ForceMode) -> Self {
        match value {
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

impl<T> RigidBody for T where T: Class<PxRigidBody> + RigidActor {}

pub trait RigidBody: Class<PxRigidBody> + RigidActor {
    /// Set the mass of this body
    fn set_mass(&mut self, mass: f32) {
        unsafe {
            PxRigidBody_setMass_mut(self.as_mut_ptr(), mass);
        };
    }

    /// Get the angular velocity.
    fn get_angular_velocity(&self) -> PxVec3 {
        unsafe { PxRigidBody_getAngularVelocity(self.as_ptr()).into() }
    }

    /// Get the linear velocity.
    fn get_linear_velocity(&self) -> PxVec3 {
        unsafe { PxRigidBody_getLinearVelocity(self.as_ptr()).into() }
    }

    /// Get the (linear, angular) velocities.
    fn get_velocities(&self) -> (PxVec3, PxVec3) {
        (self.get_linear_velocity(), self.get_angular_velocity())
    }

    /// Set the pose of the position and orientation of the center of mass.  This does not move tha body,
    /// Setting the center of mass too far away may cause instability.
    fn set_c_mass_local_pose(&mut self, pose: &PxTransform) {
        unsafe { PxRigidBody_setCMassLocalPose_mut(self.as_mut_ptr(), pose.as_ptr()) }
    }

    /// Get the pose of the center of mass.
    fn get_c_mass_local_pose(&self) -> PxTransform {
        unsafe { PxRigidBody_getCMassLocalPose(self.as_ptr()).into() }
    }

    /// Get the mass of the body.
    fn get_mass(&self) -> f32 {
        unsafe { PxRigidBody_getMass(self.as_ptr()) }
    }

    /// Get the inverse of the mass of this body.
    fn get_inv_mass(&self) -> f32 {
        unsafe { PxRigidBody_getInvMass(self.as_ptr()) }
    }

    /// Sets the inertia tensor using mass space coordinates.  Non-diagonal space inertia tensors
    /// must be diagonalized, only the diagonal is passed in.  The tensor elements must be non-negative.
    /// Values of 0 represent infinite inertia along that axis, and are not permitted for `PxArticulationLink`s.
    fn set_mass_space_inertia_tensor(&mut self, m: &PxVec3) {
        unsafe { PxRigidBody_setMassSpaceInertiaTensor_mut(self.as_mut_ptr(), m.as_ptr()) }
    }

    /// Gets the diagonal of the inertia tensor relative to the body's mass coordinate frame.
    /// A value of 0 represents infinite inertia along that axis.
    fn get_mass_space_inertia_tensor(&self) -> PxVec3 {
        unsafe { PxRigidBody_getMassSpaceInertiaTensor(self.as_ptr()).into() }
    }

    /// Gets the diagonal of the inverse inertia tensor relative to the body's mass coordinate frame.
    /// A value of 0 represents infinite inertia along that axis.
    fn get_mass_space_inv_inertia_tensor(&self) -> PxVec3 {
        unsafe { PxRigidBody_getMassSpaceInvInertiaTensor(self.as_ptr()).into() }
    }

    /// Sets the linear damping.  Zero represents no damping.  Values clamped to [0.0 .. ].
    fn set_linear_damping(&mut self, mut lin_damp: f32) {
        if lin_damp.is_sign_negative() {
            lin_damp = 0.0
        };
        unsafe { PxRigidBody_setLinearDamping_mut(self.as_mut_ptr(), lin_damp) }
    }

    /// Gets the linear damping.
    fn get_linear_damping(&self) -> f32 {
        unsafe { PxRigidBody_getLinearDamping(self.as_ptr()) }
    }

    /// Sets the angular damping.  Zero represents no damping.  Values clamped to (0.0, .. ).
    fn set_angular_damping(&mut self, mut ang_damp: f32) {
        if ang_damp.is_sign_negative() {
            ang_damp = 0.0
        };
        unsafe { PxRigidBody_setAngularDamping_mut(self.as_mut_ptr(), ang_damp) }
    }

    /// Get the angular damping.
    fn get_angular_damping(&self) -> f32 {
        unsafe { PxRigidBody_getAngularDamping(self.as_ptr()) }
    }

    /// Set the linear velocity.  Continuously setting this will override the effects of gravity or friction
    /// because forces effect the body via velocity.  If ActorFlag::DisableSimulation is set, this does nothing,
    /// otherwise this call will wake the actor.
    fn set_linear_velocity(&mut self, lin_vel: &PxVec3, autowake: bool) {
        if !self
            .get_actor_flags()
            .contains(ActorFlag::DisableSimulation)
        {
            unsafe {
                PxRigidBody_setLinearVelocity_mut(self.as_mut_ptr(), lin_vel.as_ptr(), autowake)
            }
        };
    }

    /// Set the angular velocity.  Continuously setting this will override the effects of gravity or friction
    /// because forces effect the body via velocity.  If ActorFlag::DisableSimulation is set, this does nothing,
    /// otherwise this call will wake the actor.
    fn set_angular_velocity(&mut self, ang_vel: &PxVec3, autowake: bool) {
        unsafe { PxRigidBody_setAngularVelocity_mut(self.as_mut_ptr(), ang_vel.as_ptr(), autowake) }
    }

    /// Set the maximum angular velocity.  Very rapid rotation can cause simulation errors, setting this value
    /// will clamp velocty *before* the solver is ran (so velocty may briefly exceed this value).
    fn set_max_angular_velocity(&mut self, max_ang_vel: f32) {
        unsafe { PxRigidBody_setMaxAngularVelocity_mut(self.as_mut_ptr(), max_ang_vel) }
    }

    /// Get the maximum angular velocity.
    fn get_max_angular_velocity(&self) -> f32 {
        unsafe { PxRigidBody_getMaxAngularVelocity(self.as_ptr()) }
    }

    /// Set the maximum linear velocity.  Very rapid movement can cause simulation errors, setting this value
    /// will clamp velocty *before* the solver is ran (so velocty may briefly exceed this value).
    fn set_max_linear_velocity(&mut self, max_lin_vel: f32) {
        unsafe { PxRigidBody_setMaxLinearVelocity_mut(self.as_mut_ptr(), max_lin_vel) }
    }

    /// Get the maximum linear velocity.
    fn get_max_linear_velocity(&self) -> f32 {
        unsafe { PxRigidBody_getMaxLinearVelocity(self.as_ptr()) }
    }

    /// Apply a force to the actor.  This will not cause torque.  ForceMode determines how this force is applied.
    /// `ForceMode::Acceleration` and `ForceMode::VelocityChange` directly effect the acceleration and velocity change
    /// accumulators.  `ForceMode::Force` and `ForceMode::Impulse` are multiplied by inverse mass first.
    fn add_force(&mut self, force: &PxVec3, mode: ForceMode, autowake: bool) {
        unsafe {
            PxRigidBody_addForce_mut(self.as_mut_ptr(), force.as_ptr(), mode.into(), autowake)
        }
    }

    /// Apply a torque to the actor.  ForceMode determines how this force is applied.  `ForceMode::Acceleration`
    /// and `ForceMode::VelocityChange` directly effect the angular acceleration and angular velocity change
    /// accumulators.  `ForceMode::Force` and `ForceMode::Impulse` are multiplied by inverse mass first.
    fn add_torque(&mut self, torque: &PxVec3, mode: ForceMode, autowake: bool) {
        unsafe {
            PxRigidBody_addTorque_mut(self.as_mut_ptr(), torque.as_ptr(), mode.into(), autowake)
        }
    }

    /// Clear the accumulated acceleration or velocity change.  `ForceMode::Acceleration` and `ForceMode::Force`
    /// clear the same accumulator, as do `ForceMode::VelocityChange` and `ForceMode::Impulse`.
    fn clear_force(&mut self, mode: ForceMode) {
        unsafe { PxRigidBody_clearForce_mut(self.as_mut_ptr(), mode.into()) }
    }

    /// Clear the accumulated angular acceleration or angular velocity change.  `ForceMode::Acceleration`
    /// and `ForceMode::Force` clear the same accumulator, as do `ForceMode::VelocityChange` and `ForceMode::Impulse`.
    fn clear_torque(&mut self, mode: ForceMode) {
        unsafe { PxRigidBody_clearTorque_mut(self.as_mut_ptr(), mode.into()) }
    }

    /// Set the force and torque accumulators.
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

    /// Set a rigid body flag.
    fn set_rigid_body_flag(&mut self, flag: RigidBodyFlag, value: bool) {
        unsafe { PxRigidBody_setRigidBodyFlag_mut(self.as_mut_ptr(), flag.into(), value) }
    }

    /// Set all the rigid body flags.
    fn set_rigid_body_flags(&mut self, flags: RigidBodyFlags) {
        unsafe { PxRigidBody_setRigidBodyFlags_mut(self.as_mut_ptr(), flags.into_px()) }
    }

    /// Get the rigid body flags.
    fn get_rigid_body_flags(&self) -> RigidBodyFlags {
        unsafe { RigidBodyFlags::from_px(PxRigidBody_getRigidBodyFlags(self.as_ptr())) }
    }

    /// Set the CCD advance coefficient, clamped to range [0.0 ..= 1.0].  Default is 0.15.  Values near 1.0
    /// ensures that some will be advanced, but objects may slowly drift through eachother.  Values near 0.0
    /// will never drift through eachother, but may "jam" ie. not advance through time during a given CCD pass.
    fn set_min_ccd_advance_coefficient(&mut self, mut advance_coefficient: f32) {
        if advance_coefficient.is_sign_negative() {
            advance_coefficient = 0.0
        } else if advance_coefficient > 1.0 {
            advance_coefficient = 1.0
        };
        unsafe {
            PxRigidBody_setMinCCDAdvanceCoefficient_mut(self.as_mut_ptr(), advance_coefficient)
        }
    }

    /// Get the CCD advance coefficient.
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

/// A wrapper for RigidBody, parametrized by the ArticulationLink and
/// RigidDynamic that may be it's most derived type.  Use `cast_map`
/// or `as_*` to cast to it's most derived type if specialized functionality is needed.
#[repr(transparent)]
pub struct RigidBodyMap<L, D>
where
    L: ArticulationLink,
    D: RigidDynamic,
{
    obj: PxRigidBody,
    phantom_user_data: PhantomData<(L, D)>,
}

unsafe impl<P, L, D> Class<P> for RigidBodyMap<L, D>
where
    PxRigidBody: Class<P>,
    L: ArticulationLink,
    D: RigidDynamic,
{
    fn as_ptr(&self) -> *const P {
        self.obj.as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut P {
        self.obj.as_mut_ptr()
    }
}

impl<L, D> RigidBodyMap<L, D>
where
    L: ArticulationLink,
    D: RigidDynamic,
{
    /// Cast to the most-derived type as determined by `get_type`, which returns the ActorType.
    /// Because this does not use `get_concrete_type`, this method does not have the safety
    /// concerns of the other `cast_map`s, and a `try_cast_map` method is unneded.
    pub fn cast_map<'a, Ret, RDFn, ALFn>(
        &'a mut self,
        mut rigid_dynamic_fn: RDFn,
        mut articulation_link_fn: ALFn,
    ) -> Ret
    where
        RDFn: FnMut(&'a mut D) -> Ret,
        ALFn: FnMut(&'a mut L) -> Ret,
    {
        match self.get_type() {
            ActorType::RigidDynamic => {
                rigid_dynamic_fn(unsafe { &mut *(self as *mut _ as *mut D) })
            }
            ActorType::ArticulationLink => {
                articulation_link_fn(unsafe { &mut *(self as *mut _ as *mut L) })
            }
            ActorType::RigidStatic => unreachable!("RigidStatic is not a RigidBody"),
        }
    }

    /// Tries to cast to RigidDynamic.
    pub fn as_rigid_dynamic(&mut self) -> Option<&mut D> {
        match self.get_type() {
            ActorType::RigidDynamic => unsafe { Some(&mut *(self as *mut _ as *mut D)) },
            _ => None,
        }
    }

    /// Tries to cast to ArticulationLink.
    pub fn as_articulation_link(&mut self) -> Option<&mut L> {
        match self.get_type() {
            ActorType::ArticulationLink => unsafe { Some(&mut *(self as *mut _ as *mut L)) },
            _ => None,
        }
    }
}
