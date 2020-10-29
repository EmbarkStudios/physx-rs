// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 19 June 2019

#![warn(clippy::all)]

/*!
Wrapper implementation for PxRigidDynamic
*/

use crate::{
    geometry::Geometry,
    material::Material,
    math::PxTransform,
    owner::Owner,
    physics::Physics,
    rigid_actor::RigidActor,
    rigid_body::RigidBody,
    traits::{Class, PxFlags, UserData},
};

use enumflags2::BitFlags;

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
        PxRigidDynamicLockFlags {
            mBits: self.bits() as u16,
        }
    }

    fn from_px(flags: Self::Target) -> Self {
        unsafe { BitFlags::new(flags.mBits as u8) }
    }
}

// TODO why is the sizing here all over the place? Docs and source code have PxU8,
// the ::Enum type is u32, and the PxRigidDynamicLockFlags is u16. What gives?
#[derive(Copy, Clone, Debug, BitFlags)]
#[repr(u8)]
pub enum RigidDynamicLockFlag {
    LockLinearX = 1 << 0,
    LockLinearY = 1 << 1,
    LockLinearZ = 1 << 2,
    LockAngularX = 1 << 3,
    LockAngularY = 1 << 4,
    LockAngularZ = 1 << 5,
}

impl Into<PxRigidDynamicLockFlag::Enum> for RigidDynamicLockFlag {
    fn into(self) -> PxRigidDynamicLockFlag::Enum {
        match self {
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
            _ => unimplemented!("Invalid enum variant."),
        }
    }
}

#[derive(Copy, Clone, Debug)]
pub struct SolverIterationCounts {
    pub min_position_iterations: u32,
    pub min_velocity_iterations: u32,
}

///////////////////////////////////////////////////

#[repr(transparent)]
pub struct RigidDynamic<D, H, M> {
    pub(crate) obj: physx_sys::PxRigidDynamic,
    phantom_user_data: PhantomData<(D, H, M)>,
}

unsafe impl<P, D, H, M> Class<P> for RigidDynamic<D, H, M>
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

impl<D, H, M> RigidActor for RigidDynamic<D, H, M> {
    type ShapeData = H;

    type MaterialData = M;
}
impl<D, H, M> RigidBody for RigidDynamic<D, H, M> {}

impl<D, H, M> RigidDynamic<D, H, M> {
    pub fn new(
        physics: &mut Physics<H, M>,
        transform: PxTransform,
        geometry: &impl Geometry,
        material: &mut Material<M>,
        density: f32,
        shape_transform: PxTransform,
        user_data: D,
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

    pub(crate) unsafe fn from_raw(
        ptr: *mut physx_sys::PxRigidDynamic,
        user_data: D,
    ) -> Option<Owner<Self>> {
        let actor = (ptr as *mut RigidDynamic<D, H, M>).as_mut();
        Owner::from_raw(actor?.init_user_data(user_data))
    }

    pub fn get_user_data(&self) -> &D {
        // Safety: construction must go through `from_raw` which calls `init_user_data`
        unsafe { UserData::get_user_data(self) }
    }

    pub fn get_user_data_mut(&mut self) -> &mut D {
        // Safety: construction must go through `from_raw` which calls `init_user_data`
        unsafe { UserData::get_user_data_mut(self) }
    }

    pub fn get_contact_report_threshold(&self) -> f32 {
        unsafe { PxRigidDynamic_getContactReportThreshold(self.as_ptr()) }
    }

    /// Returns a copy of the target transform if the actor is knematically controlled and has a target set,
    /// otherwise it returns None.
    pub fn get_kinematic_target(&self) -> Option<PxTransform> {
        let mut transform = PxTransform::default();
        unsafe {
            if PxRigidDynamic_getKinematicTarget(self.as_ptr(), transform.as_mut_ptr()) {
                Some(transform)
            } else {
                None
            }
        }
    }

    pub fn get_rigid_dynamic_lock_flags(&self) -> RigidDynamicLockFlags {
        unsafe {
            RigidDynamicLockFlags::from_px(PxRigidDynamic_getRigidDynamicLockFlags(self.as_ptr()))
        }
    }

    pub fn get_sleep_threshold(&self) -> f32 {
        unsafe { PxRigidDynamic_getSleepThreshold(self.as_ptr()) }
    }

    pub fn get_solver_iteration_counts(&self) -> SolverIterationCounts {
        let mut vel_iters = 0;
        let mut pos_iters = 0;
        unsafe {
            PxRigidDynamic_getSolverIterationCounts(self.as_ptr(), &mut vel_iters, &mut pos_iters);
        }
        SolverIterationCounts {
            min_position_iterations: pos_iters,
            min_velocity_iterations: vel_iters,
        }
    }

    pub fn get_stabilization_threshold(&self) -> f32 {
        unsafe { PxRigidDynamic_getStabilizationThreshold(self.as_ptr()) }
    }

    pub fn get_wake_counter(&self) -> f32 {
        unsafe { PxRigidDynamic_getWakeCounter(self.as_ptr()) }
    }

    pub fn is_sleeping(&self) -> bool {
        unsafe { PxRigidDynamic_isSleeping(self.as_ptr()) }
    }

    pub fn put_to_sleep(&mut self) {
        unsafe { PxRigidDynamic_putToSleep_mut(self.as_mut_ptr()) }
    }

    pub fn set_contact_report_threshold(&mut self, threshold: f32) {
        unsafe { PxRigidDynamic_setContactReportThreshold_mut(self.as_mut_ptr(), threshold) }
    }

    pub fn set_kinematic_target(&mut self, target: &PxTransform) {
        unsafe { PxRigidDynamic_setKinematicTarget_mut(self.as_mut_ptr(), target.as_ptr()) }
    }

    pub fn set_rigid_dynamic_lock_flag(&mut self, flag: RigidDynamicLockFlag, value: bool) {
        unsafe { PxRigidDynamic_setRigidDynamicLockFlag_mut(self.as_mut_ptr(), flag.into(), value) }
    }

    pub fn set_rigid_dynamic_lock_flags(&mut self, flags: RigidDynamicLockFlags) {
        unsafe { PxRigidDynamic_setRigidDynamicLockFlags_mut(self.as_mut_ptr(), flags.into_px()) }
    }

    pub fn set_sleep_threshold(&mut self, threshold: f32) {
        unsafe { PxRigidDynamic_setSleepThreshold_mut(self.as_mut_ptr(), threshold) }
    }

    pub fn set_solver_iteration_counts(&mut self, iter_counts: SolverIterationCounts) {
        unsafe {
            PxRigidDynamic_setSolverIterationCounts_mut(
                self.as_mut_ptr(),
                iter_counts.min_position_iterations,
                iter_counts.min_velocity_iterations,
            )
        }
    }

    pub fn set_stabilization_threshold(&mut self, threshold: f32) {
        unsafe { PxRigidDynamic_setStabilizationThreshold_mut(self.as_mut_ptr(), threshold) }
    }

    pub fn set_wake_counter(&mut self, wake_counter: f32) {
        unsafe { PxRigidDynamic_setWakeCounter_mut(self.as_mut_ptr(), wake_counter) }
    }

    pub fn wake_up(&mut self) {
        unsafe { PxRigidDynamic_wakeUp_mut(self.as_mut_ptr()) }
    }
}

unsafe impl<D: Send, H: Send, M: Send> Send for RigidDynamic<D, H, M> {}
unsafe impl<D: Sync, H: Sync, M: Sync> Sync for RigidDynamic<D, H, M> {}

impl<D, H, M> Drop for RigidDynamic<D, H, M> {
    fn drop(&mut self) {
        for shape in self.get_shapes() {
            for _material in shape.get_materials() {
                // is PxMaterial_release thread safe?
            }
            // is PxShape_release thread safe?
        }
        unsafe {
            drop_in_place(self.get_user_data_mut() as *mut _);
            PxRigidActor_release_mut(self.as_mut_ptr());
        }
    }
}
