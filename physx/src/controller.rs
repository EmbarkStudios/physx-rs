#![warn(clippy::all)]

use crate::px_type::*;
use crate::rigid_dynamic::RigidDynamic;

use glam::Vec3;
use physx_macros::*;

use physx_sys::{
    phys_PxCreateControllerManager, PxCapsuleControllerDesc, PxCapsuleControllerDesc_delete,
    PxCapsuleControllerDesc_isValid, PxCapsuleControllerDesc_new_alloc, PxController,
    PxControllerDesc, PxControllerManager, PxControllerManager_createController_mut,
    PxControllerManager_release_mut, PxController_getActor, PxController_getPosition,
    PxController_release_mut, PxController_setPosition_mut, PxExtendedVec3, PxMaterial, PxScene,
};
use thiserror::Error;

#[physx_type]
impl ControllerDesc {}

#[physx_type]
impl ControllerManager {
    pub fn new(scene: *mut PxScene, locking_enabled: bool) -> Self {
        let ptr = unsafe { phys_PxCreateControllerManager(scene, locking_enabled) };
        ControllerManager { ptr }
    }

    pub fn create_controller(&self, desc: &ControllerDesc) -> Controller {
        let controller =
            unsafe { PxControllerManager_createController_mut(self.ptr, desc.get_raw()) };
        Controller::new(controller)
    }

    pub unsafe fn release(self) {
        PxControllerManager_release_mut(self.ptr);
    }
}

#[physx_type(inherit = "ControllerDesc")]
impl CapsuleControllerDesc {
    pub fn new(
        height: f32,
        radius: f32,
        step_offset: f32,
        material: *mut PxMaterial,
    ) -> Result<Self, ControllerError> {
        unsafe {
            let c = PxCapsuleControllerDesc_new_alloc();
            (*c).height = height;
            (*c).radius = radius;
            (*c).stepOffset = step_offset;
            (*c).material = material;

            if PxCapsuleControllerDesc_isValid(c) {
                Ok(CapsuleControllerDesc { ptr: c })
            } else {
                PxCapsuleControllerDesc_delete(c);
                Err(ControllerError::InvalidDescription {
                    height,
                    radius,
                    step_offset,
                })
            }
        }
    }

    pub fn release(self) {
        unsafe { PxCapsuleControllerDesc_delete(self.ptr) };
    }
}

#[physx_type]
impl Controller {
    pub fn new(controller: *mut PxController) -> Self {
        Self { ptr: controller }
    }

    pub fn set_position(&mut self, position: Vec3) {
        unsafe {
            PxController_setPosition_mut(self.get_raw_mut(), &to_extended(&position));
        }
    }

    pub fn get_position(&self) -> Vec3 {
        unsafe { from_extended(*PxController_getPosition(self.get_raw())) }
    }

    pub fn get_actor(&self) -> RigidDynamic {
        unsafe { RigidDynamic::from_ptr(PxController_getActor(self.ptr)) }
    }

    pub fn release(&mut self) {
        unsafe {
            PxController_release_mut(self.get_raw_mut());
        }
    }
}

fn to_extended(vec: &Vec3) -> PxExtendedVec3 {
    PxExtendedVec3 {
        x: vec.x as f64,
        y: vec.y as f64,
        z: vec.z as f64,
    }
}

fn from_extended(vec: PxExtendedVec3) -> Vec3 {
    Vec3::new(vec.x as f32, vec.y as f32, vec.z as f32)
}

#[derive(Error, Debug)]
pub enum ControllerError {
    #[error(
        "Controller description is invalid. height={}, radius={}, step_offset={}",
        height,
        radius,
        step_offset
    )]
    InvalidDescription {
        height: f32,
        radius: f32,
        step_offset: f32,
    },

    #[error("No controller manager present")]
    NoControllerManager,
}
