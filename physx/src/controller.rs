#![warn(clippy::all)]
#![warn(rust_2018_idioms)]

use crate::transform::gl_to_px_v3;
use glam::Vec3;
use physx_sys::PxControllerFilterCallback;
use physx_sys::{
    PxController, PxControllerFilters, PxControllerFilters_new, PxController_getActor,
    PxController_getPosition, PxController_move_mut, PxController_release_mut,
    PxController_setPosition_mut, PxExtendedVec3, PxQueryFilterCallback, PxRigidDynamic,
};
use std::ptr::null;

pub struct Controller {
    controller: *mut PxController,
    filters: PxControllerFilters,
}

impl Controller {
    pub fn new(controller: *mut PxController) -> Self {
        unsafe {
            let filters = PxControllerFilters_new(
                null(),
                null::<PxQueryFilterCallback>() as *mut PxQueryFilterCallback,
                null::<PxControllerFilterCallback>() as *mut PxControllerFilterCallback,
            );

            Self {
                controller,
                filters,
            }
        }
    }

    pub fn get_raw_mut(&mut self) -> *mut PxController {
        self.controller
    }

    pub fn get_raw(&self) -> *const PxController {
        self.controller
    }

    pub fn set_position(&mut self, position: Vec3) {
        unsafe {
            PxController_setPosition_mut(self.get_raw_mut(), &(to_extended(&position)));
        }
    }

    pub fn move_by(&mut self, disp: &Vec3, min_distance: f32, elapsed_time: f32) {
        unsafe {
            PxController_move_mut(
                self.get_raw_mut(),
                &gl_to_px_v3(*disp),
                min_distance,
                elapsed_time,
                &self.filters,
                null(),
            );
        }
    }

    pub fn get_position(&self) -> Vec3 {
        unsafe { from_extended(*PxController_getPosition(self.get_raw())) }
    }

    pub fn get_actor(&self) -> *mut PxRigidDynamic {
        unsafe { PxController_getActor(self.controller) }
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
