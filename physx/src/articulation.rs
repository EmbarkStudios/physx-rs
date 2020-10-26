use crate::{
    articulation_base::ArticulationBase,
    articulation_link::ArticulationLink,
    math::PxVec3,
    traits::{Class, UserData},
    owner::Owner,
};

use std::marker::PhantomData;

use physx_sys::{
    PxArticulationDriveCache,
    PxArticulation_applyImpulse_mut,
    PxArticulation_computeImpulseResponse,
    PxArticulation_createDriveCache,
    PxArticulation_getExternalDriveIterations,
    PxArticulation_getInternalDriveIterations,
    PxArticulation_getMaxProjectionIterations,
    PxArticulation_getSeparationTolerance,
    PxArticulation_release_mut,
    PxArticulation_releaseDriveCache,
    PxArticulation_setExternalDriveIterations_mut,
    PxArticulation_setInternalDriveIterations_mut,
    PxArticulation_setMaxProjectionIterations_mut,
    PxArticulation_setSeparationTolerance_mut,
    PxArticulation_updateDriveCache,
};

pub struct ImpulseResponse {
    pub angular: PxVec3,
    pub linear: PxVec3,
}

#[repr(transparent)]
pub struct Articulation<U, L, H, M> {
    pub(crate) obj: physx_sys::PxArticulation,
    phantom_user_data: PhantomData<(U, L, H, M)>,
}

impl<U, L, H, M> ArticulationBase<L, H, M> for Articulation<U, L, H, M> {}
unsafe impl<S, U, L, H, M> Class<S> for Articulation<U, L, H, M> where physx_sys::PxArticulation: Class<S> {
    fn as_ptr(&self) -> *const S {
        self.obj.as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut S {
        self.obj.as_mut_ptr()
    }
}

impl<U, L, H, M> Articulation<U, L, H, M> {
    pub(crate) unsafe fn from_raw(ptr: *mut physx_sys::PxArticulation, user_data: U) -> Option<Owner<Self>> {
        Owner::from_raw((ptr as *mut Self).as_mut()?.init_user_data(user_data))
    }

    pub fn get_user_data(&self) -> &U {
        // Safety: construction must go through `from_raw` which calls `init_user_data`
        unsafe { UserData::get_user_data(self) }
    }

    pub fn get_user_data_mut(&mut self) -> &mut U {
        // Safety: construction must go through `from_raw` which calls `init_user_data`
        unsafe { UserData::get_user_data_mut(self) }
    }

    pub fn apply_impulse(
        &mut self,
        link: &mut ArticulationLink<L, H, M>,
        cache: &PxArticulationDriveCache,
        linear_impulse: &PxVec3,
        angular_impulse: &PxVec3,
    ) {
        unsafe {
            PxArticulation_applyImpulse_mut(
                self.as_mut_ptr(),
                link.as_mut_ptr(),
                cache,
                linear_impulse.as_ptr(),
                angular_impulse.as_ptr(),
            )
        }
    }

    pub fn compute_impulse_response(
        &self,
        link: &mut ArticulationLink<L, H, M>,
        cache: &PxArticulationDriveCache,
        linear_impulse: &PxVec3,
        angular_impulse: &PxVec3
    ) -> ImpulseResponse {
        unsafe {
            let mut angular = PxVec3::default();
            let mut linear = PxVec3::default();
            PxArticulation_computeImpulseResponse(
                self.as_ptr(),
                link.as_mut_ptr(),
                linear.as_mut_ptr(),
                angular.as_mut_ptr(),
                cache,
                linear_impulse.as_ptr(),
                angular_impulse.as_ptr(),
            );
            ImpulseResponse{
                angular,
                linear,
            }
        }
    }

    pub fn create_drive_cache(&self, compliance: f32, drive_iterations: u32) -> Option<&mut PxArticulationDriveCache> {
        unsafe {
            PxArticulation_createDriveCache(
                self.as_ptr(),
                compliance,
                drive_iterations
            ).as_mut()
        }
    }

    pub fn update_drive_cache(&self, cache: &mut PxArticulationDriveCache, compliance: f32, iterations: u32) {
        unsafe {
            PxArticulation_updateDriveCache(self.as_ptr(), cache, compliance, iterations)
        }
    }

    pub fn get_external_drive_iterations(&self) -> u32 {
        unsafe {
            PxArticulation_getExternalDriveIterations(self.as_ptr())
        }
    }

    pub fn get_internal_drive_iterations(&self) -> u32 {
        unsafe {
            PxArticulation_getInternalDriveIterations(self.as_ptr())
        }
    }

    pub fn get_max_projection_iterations(&self) -> u32 {
        unsafe {
            PxArticulation_getMaxProjectionIterations(self.as_ptr())
        }
    }

    pub fn get_separation_tolerance(&self) -> f32 {
        unsafe {
            PxArticulation_getSeparationTolerance(self.as_ptr())
        }
    }

    pub fn release_drive_cache(&self, cache: &mut PxArticulationDriveCache) {
        unsafe {
            PxArticulation_releaseDriveCache(self.as_ptr(), cache) 
        }
    }

    pub fn set_external_drive_iterations(&mut self, iterations: u32) {
        unsafe {
            PxArticulation_setExternalDriveIterations_mut(self.as_mut_ptr(),iterations)
        }
    }

    pub fn set_internal_drive_iterations(&mut self, iterations: u32) {
        unsafe {
            PxArticulation_setInternalDriveIterations_mut(self.as_mut_ptr(), iterations)
        }
    }

    pub fn set_max_projection_iterations(&mut self, iterations: u32) {
        unsafe {
            PxArticulation_setMaxProjectionIterations_mut(self.as_mut_ptr(), iterations)
        }
    }

    pub fn set_separation_tolerance(&mut self, tolerance: f32) {
        unsafe {
            PxArticulation_setSeparationTolerance_mut(self.as_mut_ptr(), tolerance)
        }
    }
}

unsafe impl<U: Send, L: Send, H: Send, M: Send> Send for Articulation<U, L, H, M> {}
unsafe impl<U: Sync, L: Sync, H: Sync, M: Sync> Sync for Articulation<U, L, H, M> {}

impl<U, L, H, M> Drop for Articulation<U, L, H, M> {
    fn drop(&mut self) {
        // All parents are before the children, so popping one at a time ensures proper deletion order (from child to parent)
        for link in self.get_links().drain(..).rev() {
            drop(link);
        }
        drop(self.get_user_data_mut());
        unsafe {
            PxArticulation_release_mut(self.as_mut_ptr())
        }
    }
}