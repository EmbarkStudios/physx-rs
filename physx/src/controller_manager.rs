use crate::{
    controller::{CapsuleController, CapsuleControllerDescriptor},
    owner::Owner,
    traits::Class,
};

use physx_sys::{
    PxControllerManager_createController_mut, PxControllerManager_getController_mut,
    PxControllerManager_getNbControllers, PxControllerManager_purgeControllers_mut,
    PxControllerManager_release_mut,
};

#[repr(transparent)]
pub struct ControllerManager {
    obj: physx_sys::PxControllerManager,
}

crate::DeriveClassForNewType!(ControllerManager: PxControllerManager);

impl ControllerManager {
    pub(crate) unsafe fn from_raw(
        ptr: *mut physx_sys::PxControllerManager,
    ) -> Option<Owner<ControllerManager>> {
        Owner::from_raw(ptr as *mut Self)
    }

    pub fn create_capsule_controller<'a, U, M>(
        &mut self,
        desc: CapsuleControllerDescriptor<'a, U, M>,
    ) -> Option<Owner<CapsuleController<U>>> {
        unsafe {
            CapsuleController::from_raw(PxControllerManager_createController_mut(
                self.as_mut_ptr(),
                desc.into_desc()?.as_ptr(),
            ) as *mut _)
        }
    }

    pub fn get_nb_controllers(&self) -> u32 {
        unsafe { PxControllerManager_getNbControllers(self.as_ptr()) }
    }

    // TODO make this type aware
    pub fn get_controller(&mut self, idx: u32) -> Option<&mut CapsuleController<()>> {
        unsafe {
            if idx < self.get_nb_controllers() {
                Some(
                    &mut *(PxControllerManager_getController_mut(self.as_mut_ptr(), idx)
                        as *mut CapsuleController<()>),
                )
            } else {
                None
            }
        }
    }

    // TODO make this type aware
    pub fn get_controllers(&mut self) -> Vec<&mut CapsuleController<()>> {
        let count = self.get_nb_controllers();
        let mut vec = Vec::with_capacity(count as usize);
        for idx in 0..count {
            vec.push(unsafe {
                &mut *(PxControllerManager_getController_mut(self.as_mut_ptr(), idx)
                    as *mut CapsuleController<()>)
            });
        }
        vec
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
