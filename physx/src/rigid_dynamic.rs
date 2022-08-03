// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 19 June 2019

#![warn(clippy::all)]

/*!
Wrapper implementation for PxRigidDynamic
*/

use crate::{
    geometry::Geometry,
    math::PxTransform,
    owner::Owner,
    physics::Physics,
    rigid_actor::RigidActor,
    rigid_body::RigidBody,
    shape::Shape,
    traits::{Class, PxFlags, UserData},
};

use enumflags2::{bitflags, BitFlags};

use std::{marker::PhantomData, ptr::drop_in_place};

use physx_sys::{
    phys_PxCreateDynamic, PxRigidActor_release_mut, PxRigidDynamicLockFlag,
    PxRigidDynamicLockFlags, PxRigidDynamic_getContactReportThreshold,
    PxRigidDynamic_getKinematicTarget, PxRigidDynamic_getRigidDynamicLockFlags,
    PxRigidDynamic_getSleepThreshold, PxRigidDynamic_getSolverIterationCounts,
    PxRigidDynamic_getStabilizationThreshold, PxRigidDynamic_getWakeCounter,
    PxRigidDynamic_isSleeping, PxRigidDynamic_putToSleep_mut,
    PxRigidDynamic_setContactReportThreshold_mut, PxRigidDynamic_setKinematicTarget_mut,
    PxRigidDynamic_setRigidDynamicLockFlag_mut, PxRigidDynamic_setRigidDynamicLockFlags_mut,
    PxRigidDynamic_setSleepThreshold_mut, PxRigidDynamic_setSolverIterationCounts_mut,
    PxRigidDynamic_setStabilizationThreshold_mut, PxRigidDynamic_setWakeCounter_mut,
    PxRigidDynamic_wakeUp_mut,
};

///////////////////////////////////////////////////
// Flags
pub type RigidDynamicLockFlags = BitFlags<RigidDynamicLockFlag>;

impl PxFlags for RigidDynamicLockFlags {
    type Target = PxRigidDynamicLockFlags;

    fn into_px(self) -> Self::Target {
        PxRigidDynamicLockFlags { mBits: self.bits() }
    }

    fn from_px(flags: Self::Target) -> Self {
        unsafe { BitFlags::from_bits_unchecked(flags.mBits) }
    }
}

#[bitflags]
#[derive(Copy, Clone, Debug)]
#[repr(u8)]
pub enum RigidDynamicLockFlag {
    LockLinearX = 1 << 0,
    LockLinearY = 1 << 1,
    LockLinearZ = 1 << 2,
    LockAngularX = 1 << 3,
    LockAngularY = 1 << 4,
    LockAngularZ = 1 << 5,
}

impl From<RigidDynamicLockFlag> for PxRigidDynamicLockFlag::Enum {
    fn from(value: RigidDynamicLockFlag) -> Self {
        match value {
            RigidDynamicLockFlag::LockLinearX => PxRigidDynamicLockFlag::eLOCK_LINEAR_X,
            RigidDynamicLockFlag::LockLinearY => PxRigidDynamicLockFlag::eLOCK_LINEAR_Y,
            RigidDynamicLockFlag::LockLinearZ => PxRigidDynamicLockFlag::eLOCK_LINEAR_Z,
            RigidDynamicLockFlag::LockAngularX => PxRigidDynamicLockFlag::eLOCK_ANGULAR_X,
            RigidDynamicLockFlag::LockAngularY => PxRigidDynamicLockFlag::eLOCK_ANGULAR_Y,
            RigidDynamicLockFlag::LockAngularZ => PxRigidDynamicLockFlag::eLOCK_ANGULAR_Z,
        }
    }
}

impl From<PxRigidDynamicLockFlag::Enum> for RigidDynamicLockFlag {
    fn from(flag: PxRigidDynamicLockFlag::Enum) -> Self {
        match flag {
            PxRigidDynamicLockFlag::eLOCK_LINEAR_X => RigidDynamicLockFlag::LockLinearX,
            PxRigidDynamicLockFlag::eLOCK_LINEAR_Y => RigidDynamicLockFlag::LockLinearY,
            PxRigidDynamicLockFlag::eLOCK_LINEAR_Z => RigidDynamicLockFlag::LockLinearZ,
            PxRigidDynamicLockFlag::eLOCK_ANGULAR_X => RigidDynamicLockFlag::LockAngularX,
            PxRigidDynamicLockFlag::eLOCK_ANGULAR_Y => RigidDynamicLockFlag::LockAngularY,
            PxRigidDynamicLockFlag::eLOCK_ANGULAR_Z => RigidDynamicLockFlag::LockAngularZ,
            _ => unreachable!("Invalid enum variant."),
        }
    }
}

///////////////////////////////////////////////////

/// A new type wrapper for PxRigidDynamic.  Parametrized by it's user data type,
/// and the type of it's Shapes.
#[repr(transparent)]
pub struct PxRigidDynamic<D, Geom: Shape> {
    pub(crate) obj: physx_sys::PxRigidDynamic,
    phantom_user_data: PhantomData<(D, Geom)>,
}

unsafe impl<U, Geom: Shape> UserData for PxRigidDynamic<U, Geom> {
    type UserData = U;

    fn user_data_ptr(&self) -> &*mut std::ffi::c_void {
        &self.obj.userData
    }

    fn user_data_ptr_mut(&mut self) -> &mut *mut std::ffi::c_void {
        &mut self.obj.userData
    }
}

impl<D, Geom: Shape> Drop for PxRigidDynamic<D, Geom> {
    fn drop(&mut self) {
        unsafe {
            drop_in_place(self.get_user_data_mut() as *mut _);
            PxRigidActor_release_mut(self.as_mut_ptr());
        }
    }
}

unsafe impl<P, D, Geom: Shape> Class<P> for PxRigidDynamic<D, Geom>
where
    physx_sys::PxRigidDynamic: Class<P>,
{
    fn as_ptr(&self) -> *const P {
        self.obj.as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut P {
        self.obj.as_mut_ptr()
    }
}

unsafe impl<D: Send, Geom: Shape + Send> Send for PxRigidDynamic<D, Geom> {}
unsafe impl<D: Sync, Geom: Shape + Sync> Sync for PxRigidDynamic<D, Geom> {}

impl<D, Geom: Shape> RigidActor for PxRigidDynamic<D, Geom> {
    type Shape = Geom;
}

impl<D, Geom: Shape> RigidDynamic for PxRigidDynamic<D, Geom> {}

pub trait RigidDynamic: Class<physx_sys::PxRigidDynamic> + RigidBody + UserData {
    /// Create a new RigidDynamic.
    fn new(
        physics: &mut impl Physics,
        transform: PxTransform,
        geometry: &impl Geometry,
        material: &mut <Self::Shape as Shape>::Material,
        density: f32,
        shape_transform: PxTransform,
        user_data: Self::UserData,
    ) -> Option<Owner<Self>> {
        unsafe {
            RigidDynamic::from_raw(
                phys_PxCreateDynamic(
                    physics.as_mut_ptr(),
                    transform.as_ptr(),
                    geometry.as_ptr(),
                    material.as_mut_ptr(),
                    density,
                    shape_transform.as_ptr(),
                ),
                user_data,
            )
        }
    }

    /// Create a new Owner wrapper around a raw pointer.
    /// # Safety
    /// Owner's own the pointer they wrap, using the pointer after dropping the Owner,
    /// or creating multiple Owners from the same pointer will cause UB.  Use `into_ptr` to
    /// retrieve the pointer and consume the Owner without dropping the pointee.
    /// Initializes user data.
    unsafe fn from_raw(
        ptr: *mut physx_sys::PxRigidDynamic,
        user_data: Self::UserData,
    ) -> Option<Owner<Self>> {
        let actor = (ptr as *mut Self).as_mut();
        Owner::from_raw(actor?.init_user_data(user_data))
    }

    /// Get the user data.
    fn get_user_data(&self) -> &Self::UserData {
        // Safety: all construction goes through from_raw, which calls init_user_data
        unsafe { UserData::get_user_data(self) }
    }

    /// Get the user data.
    fn get_user_data_mut(&mut self) -> &mut Self::UserData {
        // Safety: all construction goes through from_raw, which calls init_user_data
        unsafe { UserData::get_user_data_mut(self) }
    }

    /// Get the contact report threshold.  If the force between two actors exceeds this threshold for either actor,
    /// a contact report will be generated in accordance with the filter shader.
    fn get_contact_report_threshold(&self) -> f32 {
        unsafe { PxRigidDynamic_getContactReportThreshold(self.as_ptr()) }
    }

    /// Returns a copy of the target transform if the actor is knematically controlled and has a target set,
    /// otherwise it returns None.
    fn get_kinematic_target(&self) -> Option<PxTransform> {
        let mut transform = PxTransform::default();
        unsafe {
            if PxRigidDynamic_getKinematicTarget(self.as_ptr(), transform.as_mut_ptr()) {
                Some(transform)
            } else {
                None
            }
        }
    }

    /// Get the lock flags.
    fn get_rigid_dynamic_lock_flags(&self) -> RigidDynamicLockFlags {
        unsafe {
            RigidDynamicLockFlags::from_px(PxRigidDynamic_getRigidDynamicLockFlags(self.as_ptr()))
        }
    }

    /// Get the sleep threshold.  If the actor's mass-normalized kinetic energy is below this value,
    /// the actor might go to sleep.
    fn get_sleep_threshold(&self) -> f32 {
        unsafe { PxRigidDynamic_getSleepThreshold(self.as_ptr()) }
    }

    /// Get the number of (position, velocity) iterations done by the solver.
    fn get_solver_iteration_counts(&self) -> (u32, u32) {
        let mut pos_iters = 0;
        let mut vel_iters = 0;
        unsafe {
            PxRigidDynamic_getSolverIterationCounts(self.as_ptr(), &mut vel_iters, &mut pos_iters);
        }
        (pos_iters, vel_iters)
    }

    /// Get the stabilization threshold.  Actors with mass-normalized kinetic energy may participate in stabilization.
    fn get_stabilization_threshold(&self) -> f32 {
        unsafe { PxRigidDynamic_getStabilizationThreshold(self.as_ptr()) }
    }

    /// Get the wake counter.
    fn get_wake_counter(&self) -> f32 {
        unsafe { PxRigidDynamic_getWakeCounter(self.as_ptr()) }
    }

    /// Returns true if the actor is sleeping.  Sleeping actors are not simulated.  If an actor is sleeping,
    /// it's linear and angular velocities are zero, no force or torque updates are pending, and the wake counter is zero.
    fn is_sleeping(&self) -> bool {
        unsafe { PxRigidDynamic_isSleeping(self.as_ptr()) }
    }

    /// Put the actor to sleep.  Pending force and torque is cleared, and the wake counter and linear and angular
    /// velocities are all set to zero.
    fn put_to_sleep(&mut self) {
        unsafe { PxRigidDynamic_putToSleep_mut(self.as_mut_ptr()) }
    }

    /// Set the contact report threshold, used when determining if a contact report should be generated.
    fn set_contact_report_threshold(&mut self, threshold: f32) {
        unsafe { PxRigidDynamic_setContactReportThreshold_mut(self.as_mut_ptr(), threshold) }
    }

    /// Set the kinematic target of the actor.  Set an actor as kinematic using `RigidBodyFlag::Kinematic`.
    /// The actor will have it's velocity set such that it gets moved to the desired pose in a single timestep,
    /// then the velocity will be zeroed.  Movement along a path requires continuous calls.  Consecutive calls
    /// in a single frame will overwrite the prior.
    fn set_kinematic_target(&mut self, target: &PxTransform) {
        unsafe { PxRigidDynamic_setKinematicTarget_mut(self.as_mut_ptr(), target.as_ptr()) }
    }

    /// Set a lock flag, preventing movement along or about an axis.
    fn set_rigid_dynamic_lock_flag(&mut self, flag: RigidDynamicLockFlag, value: bool) {
        unsafe { PxRigidDynamic_setRigidDynamicLockFlag_mut(self.as_mut_ptr(), flag.into(), value) }
    }

    /// Set the lock flags.
    fn set_rigid_dynamic_lock_flags(&mut self, flags: RigidDynamicLockFlags) {
        unsafe { PxRigidDynamic_setRigidDynamicLockFlags_mut(self.as_mut_ptr(), flags.into_px()) }
    }

    /// Set the mass normalized kinetic energy under which an actor is a candidate for being slept.  Default is
    /// 5e-5f * PxTolerancesScale.speed ^ 2.  Value is clamped to range [0.0 .. ].
    fn set_sleep_threshold(&mut self, mut threshold: f32) {
        if threshold.is_sign_negative() {
            threshold = 0.0
        };
        unsafe { PxRigidDynamic_setSleepThreshold_mut(self.as_mut_ptr(), threshold) }
    }

    /// Set the number of solver iterations for the position and velocity solvers clamped to range [1..=255].
    /// Defualt is position = 4 and velocity = 1. If bodies are oscillating, increase the position iterations.
    /// If bodies are being depenetrated too quickly, increase the velocity iterations.
    fn set_solver_iteration_counts(
        &mut self,
        min_position_iterations: u32,
        min_velocity_iterations: u32,
    ) {
        unsafe {
            PxRigidDynamic_setSolverIterationCounts_mut(
                self.as_mut_ptr(),
                min_position_iterations,
                min_velocity_iterations,
            )
        }
    }

    /// Set the stabilization threshold.  Actors with mass-normalized kinetic energy above this value will
    /// not participate in stabilization.
    fn set_stabilization_threshold(&mut self, threshold: f32) {
        unsafe { PxRigidDynamic_setStabilizationThreshold_mut(self.as_mut_ptr(), threshold) }
    }

    /// Sets the wake counter.  This is the minimum amount of time until an actor must spend below the
    /// sleep threshold before it is put to sleep.  Setting this to a positive value will wake the actor.
    /// Default is 0.4, value is in seconds.
    fn set_wake_counter(&mut self, wake_counter: f32) {
        unsafe { PxRigidDynamic_setWakeCounter_mut(self.as_mut_ptr(), wake_counter) }
    }

    /// Wake the actor.  May wake touching actors.  Sets the wake counter to the `wake_counter_reset_value`
    /// set at scene creation.
    fn wake_up(&mut self) {
        unsafe { PxRigidDynamic_wakeUp_mut(self.as_mut_ptr()) }
    }
}
