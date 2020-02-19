#![warn(clippy::all)]
#![warn(rust_2018_idioms)]

use glam::Vec3;
use physx_sys::{
    PxController, PxController_getPosition, PxController_release_mut, PxController_setPosition_mut,
    PxExtendedVec3,
};

pub struct Controller {
    controller: *mut PxController,
}

impl Controller {
    pub fn new(controller: *mut PxController) -> Self {
        Self { controller }
    }

    pub fn get_raw_mut(&mut self) -> *mut PxController {
        self.controller
    }

    pub fn get_raw(&mut self) -> *const PxController {
        self.controller
    }

    pub fn set_position(&mut self, position: Vec3) {
        unsafe {
            PxController_setPosition_mut(self.get_raw_mut(), &(to_extended(&position)));
        }
    }

    pub fn get_position(&mut self) -> Vec3 {
        unsafe { from_extended(*PxController_getPosition(self.get_raw_mut())) }
    }
    pub fn release(&mut self) {
        unsafe {
            PxController_release_mut(self.get_raw_mut());
        }
    }
}

impl Drop for Controller {
    fn drop(&mut self) {
        self.release()
    }
}

fn to_extended(vec: &Vec3) -> PxExtendedVec3 {
    PxExtendedVec3 {
        x: vec.x() as f64,
        y: vec.y() as f64,
        z: vec.z() as f64,
    }
}

fn from_extended(vec: PxExtendedVec3) -> Vec3 {
    Vec3::new(vec.x as f32, vec.y as f32, vec.z as f32)
}
