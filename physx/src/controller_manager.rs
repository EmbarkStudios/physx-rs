use crate::{
    traits::Class,
    owner::Owner,
    controller::{CapsuleController, CapsuleControllerDescriptor},
};

use physx_sys::{
    PxControllerManager_createController_mut,
    PxControllerManager_purgeControllers_mut,
    PxControllerManager_release_mut,
};

#[repr(transparent)]
pub struct ControllerManager {
    obj: physx_sys::PxControllerManager,
}

crate::ClassObj!(ControllerManager : PxControllerManager);

impl ControllerManager {
    pub(crate) unsafe fn from_raw<'a>(ptr: *mut physx_sys::PxControllerManager) -> Option<Owner<ControllerManager>> {
        Owner::from_raw(ptr as *mut Self)
    }

    pub fn create_capsule_controller<'a, U, M>(
        &mut self,
        desc: CapsuleControllerDescriptor<'a, U, M>
    ) -> Option<Owner<CapsuleController<U>>> {
        unsafe {
            CapsuleController::from_raw(
                PxControllerManager_createController_mut(
                    self.as_mut_ptr(),
                    desc.into_desc()?.as_ptr(),
                ) as *mut _
            )
        }
    }
}

unsafe impl Send for ControllerManager {}
unsafe impl Sync for ControllerManager {}

impl Drop for ControllerManager {
    fn drop(&mut self) {
        unsafe {
            // TODO this most likely leaks the controllers user data. Unless userData is small
            // enough for the size optimization to work, the data on the heap won't have it's dtor called.
            PxControllerManager_purgeControllers_mut(self.as_mut_ptr());
            PxControllerManager_release_mut(self.as_mut_ptr());
        }
    }
}