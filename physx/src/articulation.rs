use crate::{
    articulation_base::ArticulationBase,
    articulation_link::ArticulationLink,
    math::PxVec3,
    owner::Owner,
    traits::{Class, UserData},
};

use std::{marker::PhantomData, ptr::drop_in_place};

use physx_sys::{
    PxArticulationDriveCache, PxArticulation_applyImpulse_mut,
    PxArticulation_computeImpulseResponse, PxArticulation_createDriveCache,
    PxArticulation_getExternalDriveIterations, PxArticulation_getInternalDriveIterations,
    PxArticulation_getMaxProjectionIterations, PxArticulation_getSeparationTolerance,
    PxArticulation_releaseDriveCache, PxArticulation_release_mut,
    PxArticulation_setExternalDriveIterations_mut, PxArticulation_setInternalDriveIterations_mut,
    PxArticulation_setMaxProjectionIterations_mut, PxArticulation_setSeparationTolerance_mut,
    PxArticulation_updateDriveCache,
};

pub struct ImpulseResponse {
    pub angular: PxVec3,
    pub linear: PxVec3,
}

/// A new type wrapper for PxArticulation.  Parametrized by it's user data type,
/// and the type of it's ArticulationLinks.
#[repr(transparent)]
pub struct PxArticulation<U, Link: ArticulationLink> {
    pub(crate) obj: physx_sys::PxArticulation,
    phantom_user_data: PhantomData<(U, Link)>,
}

unsafe impl<U, Link: ArticulationLink> UserData for PxArticulation<U, Link> {
    type UserData = U;

    fn user_data_ptr(&self) -> &*mut std::ffi::c_void {
        &self.obj.userData
    }

    fn user_data_ptr_mut(&mut self) -> &mut *mut std::ffi::c_void {
        &mut self.obj.userData
    }
}

impl<U, Link: ArticulationLink> Drop for PxArticulation<U, Link> {
    fn drop(&mut self) {
        // All parents are before the children, so popping one at a time ensures proper deletion order (from child to parent)
        unsafe {
            for link in self.get_links_mut().drain(..).rev() {
                drop_in_place(link as *mut _);
            }
            drop_in_place(self.get_user_data_mut() as *mut _);
            PxArticulation_release_mut(self.as_mut_ptr())
        }
    }
}

unsafe impl<S, U, Link: ArticulationLink> Class<S> for PxArticulation<U, Link>
where
    physx_sys::PxArticulation: Class<S>,
{
    fn as_ptr(&self) -> *const S {
        self.obj.as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut S {
        self.obj.as_mut_ptr()
    }
}

unsafe impl<U: Send, Link: ArticulationLink + Send> Send for PxArticulation<U, Link> {}
unsafe impl<U: Sync, Link: ArticulationLink + Sync> Sync for PxArticulation<U, Link> {}

impl<U, Link: ArticulationLink> ArticulationBase for PxArticulation<U, Link> {
    type ArticulationLink = Link;
}

impl<U, Link: ArticulationLink> Articulation for PxArticulation<U, Link> {}

pub trait Articulation: Class<physx_sys::PxArticulation> + ArticulationBase + UserData {
    /// # Safety
    /// Owner's own the pointer they wrap, using the pointer after dropping the Owner,
    /// or creating multiple Owners from the same pointer will cause UB.  Use `into_ptr` to
    /// retrieve the pointer and consume the Owner without dropping the pointee.
    /// All construction of this object must initialize user data.
    unsafe fn from_raw(
        ptr: *mut physx_sys::PxArticulation,
        user_data: Self::UserData,
    ) -> Option<Owner<Self>> {
        let articulation = (ptr as *mut Self).as_mut();
        Owner::from_raw(articulation?.init_user_data(user_data))
    }

    /// Get a reference to the user data.
    fn get_user_data(&self) -> &Self::UserData {
        // Safety: construction must go through `from_raw` which calls `init_user_data`
        unsafe { UserData::get_user_data(self) }
    }

    /// Get a mutable reference to the user data.
    fn get_user_data_mut(&mut self) -> &mut Self::UserData {
        // Safety: construction must go through `from_raw` which calls `init_user_data`
        unsafe { UserData::get_user_data_mut(self) }
    }

    fn apply_impulse(
        &mut self,
        link: &mut Self::ArticulationLink,
        cache: &PxArticulationDriveCache,
        linear_impulse: &PxVec3,
        angular_impulse: &PxVec3,
    ) {
        unsafe {
            PxArticulation_applyImpulse_mut(
                self.as_mut_ptr(),
                Class::<physx_sys::PxArticulationLink>::as_mut_ptr(link),
                cache,
                linear_impulse.as_ptr(),
                angular_impulse.as_ptr(),
            )
        }
    }

    fn compute_impulse_response(
        &self,
        link: &mut Self::ArticulationLink,
        cache: &PxArticulationDriveCache,
        linear_impulse: &PxVec3,
        angular_impulse: &PxVec3,
    ) -> ImpulseResponse {
        unsafe {
            let mut angular = PxVec3::default();
            let mut linear = PxVec3::default();
            PxArticulation_computeImpulseResponse(
                self.as_ptr(),
                Class::<physx_sys::PxArticulationLink>::as_mut_ptr(link),
                linear.as_mut_ptr(),
                angular.as_mut_ptr(),
                cache,
                linear_impulse.as_ptr(),
                angular_impulse.as_ptr(),
            );
            ImpulseResponse { angular, linear }
        }
    }

    fn create_drive_cache(
        &self,
        compliance: f32,
        drive_iterations: u32,
    ) -> Option<&mut PxArticulationDriveCache> {
        unsafe {
            PxArticulation_createDriveCache(self.as_ptr(), compliance, drive_iterations).as_mut()
        }
    }

    fn update_drive_cache(
        &self,
        cache: &mut PxArticulationDriveCache,
        compliance: f32,
        iterations: u32,
    ) {
        unsafe { PxArticulation_updateDriveCache(self.as_ptr(), cache, compliance, iterations) }
    }

    fn get_external_drive_iterations(&self) -> u32 {
        unsafe { PxArticulation_getExternalDriveIterations(self.as_ptr()) }
    }

    fn get_internal_drive_iterations(&self) -> u32 {
        unsafe { PxArticulation_getInternalDriveIterations(self.as_ptr()) }
    }

    fn get_max_projection_iterations(&self) -> u32 {
        unsafe { PxArticulation_getMaxProjectionIterations(self.as_ptr()) }
    }

    fn get_separation_tolerance(&self) -> f32 {
        unsafe { PxArticulation_getSeparationTolerance(self.as_ptr()) }
    }

    fn release_drive_cache(&self, cache: &mut PxArticulationDriveCache) {
        unsafe { PxArticulation_releaseDriveCache(self.as_ptr(), cache) }
    }

    fn set_external_drive_iterations(&mut self, iterations: u32) {
        unsafe { PxArticulation_setExternalDriveIterations_mut(self.as_mut_ptr(), iterations) }
    }

    fn set_internal_drive_iterations(&mut self, iterations: u32) {
        unsafe { PxArticulation_setInternalDriveIterations_mut(self.as_mut_ptr(), iterations) }
    }

    fn set_max_projection_iterations(&mut self, iterations: u32) {
        unsafe { PxArticulation_setMaxProjectionIterations_mut(self.as_mut_ptr(), iterations) }
    }

    fn set_separation_tolerance(&mut self, tolerance: f32) {
        unsafe { PxArticulation_setSeparationTolerance_mut(self.as_mut_ptr(), tolerance) }
    }
}
