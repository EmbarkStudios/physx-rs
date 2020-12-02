use crate::{controller::Controller, owner::Owner, traits::Class};

use std::{marker::PhantomData, ptr::drop_in_place};

use physx_sys::{
    PxControllerManager_createController_mut, PxControllerManager_getController_mut,
    PxControllerManager_getNbControllers, PxControllerManager_purgeControllers_mut,
    PxControllerManager_release_mut,
};

#[repr(transparent)]
pub struct PxControllerManager<C>
where
    C: Controller,
{
    obj: physx_sys::PxControllerManager,
    phantom_controller_types: PhantomData<C>,
}

unsafe impl<T, C> Class<T> for PxControllerManager<C>
where
    physx_sys::PxControllerManager: Class<T>,
    C: Controller,
{
    fn as_ptr(&self) -> *const T {
        self.obj.as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut T {
        self.obj.as_mut_ptr()
    }
}

impl<C: Controller> ControllerManager for PxControllerManager<C> {
    type Controller = C;
}

pub trait ControllerManager: Class<physx_sys::PxControllerManager> + Sized {
    type Controller: Controller;

    /// # Safety
    /// the pointee will be dropped when the Owner is dropped.  Use `into_ptr` to
    /// retrieve the pointer from the Owner without dropping it.
    unsafe fn from_raw(ptr: *mut physx_sys::PxControllerManager) -> Option<Owner<Self>> {
        Owner::from_raw(ptr as *mut Self)
    }

    /// Create a controller.
    fn create_controller(
        &mut self,
        desc: Owner<<Self::Controller as Controller>::Descriptor>,
    ) -> Option<&mut Self::Controller> {
        unsafe {
            (PxControllerManager_createController_mut(self.as_mut_ptr(), desc.into_ptr())
                as *mut Self::Controller)
                .as_mut()
        }
    }

    /// Get the number of controllers currently being managed.
    fn get_nb_controllers(&self) -> u32 {
        unsafe { PxControllerManager_getNbControllers(self.as_ptr()) }
    }

    /// Get a controller by index.  Returns `None`
    fn get_controller(&mut self, idx: u32) -> Option<&mut Self::Controller> {
        unsafe {
            if idx < self.get_nb_controllers() {
                (PxControllerManager_getController_mut(self.as_mut_ptr(), idx)
                    as *mut Self::Controller)
                    .as_mut()
            } else {
                None
            }
        }
    }

    /// Get a Vec of all the controllers being managed.
    fn get_controllers(&mut self) -> Vec<&mut Self::Controller> {
        let count = self.get_nb_controllers();
        let mut vec = Vec::with_capacity(count as usize);
        for idx in 0..count {
            vec.push(unsafe {
                &mut *(PxControllerManager_getController_mut(self.as_mut_ptr(), idx)
                    as *mut Self::Controller)
            });
        }
        vec
    }
}

unsafe impl<C: Controller + Send> Send for PxControllerManager<C> {}
unsafe impl<C: Controller + Sync> Sync for PxControllerManager<C> {}

impl<C: Controller> Drop for PxControllerManager<C> {
    fn drop(&mut self) {
        unsafe {
            for controller in self.get_controllers() {
                drop_in_place(controller as *mut _);
            }
            PxControllerManager_purgeControllers_mut(self.as_mut_ptr());
            PxControllerManager_release_mut(self.as_mut_ptr());
        }
    }
}
