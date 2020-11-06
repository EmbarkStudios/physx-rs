#![warn(clippy::all)]

use crate::{
    material::PxMaterial,
    math::{PxExtendedVec3, PxVec3},
    owner::Owner,
    traits::{Class, UserData},
};

use std::{ffi::c_void, marker::PhantomData, mem::size_of, ptr::drop_in_place};

use thiserror::Error;

use physx_sys::{
    PxCapsuleControllerDesc_delete,
    PxCapsuleControllerDesc_isValid,
    PxCapsuleControllerDesc_new_alloc,
    PxController,
    PxControllerDesc,
    PxController_getPosition,
    PxController_getUserData,
    PxController_release_mut,
    PxController_setPosition_mut,
    PxController_setUserData_mut,
    //PxController_getActor,
};

impl<T> Controller for T where T: Class<PxController> {}
pub trait Controller: Class<PxController> {
    fn set_position(&mut self, position: impl Into<PxExtendedVec3>) {
        unsafe {
            let position: PxExtendedVec3 = position.into();
            PxController_setPosition_mut(self.as_mut_ptr(), position.as_ptr());
        }
    }

    fn get_position(&self) -> PxVec3 {
        unsafe { (*PxController_getPosition(self.as_ptr())).into() }
    }
}

#[repr(transparent)]
pub struct CapsuleController<U> {
    obj: physx_sys::PxCapsuleController,
    phantom_user_data: PhantomData<U>,
}

unsafe impl<T, U> Class<T> for CapsuleController<U>
where
    physx_sys::PxCapsuleController: Class<T>,
{
    fn as_ptr(&self) -> *const T {
        self.obj.as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut T {
        self.obj.as_mut_ptr()
    }
}

impl<U> CapsuleController<U> {
    pub(crate) unsafe fn from_raw(ptr: *mut physx_sys::PxCapsuleController) -> Option<Owner<Self>> {
        // User data is set in the descriptor, which is passed into the FFI ctor to produce this raw ptr.
        Owner::from_raw(ptr as *mut Self)
    }
    /// Retrieve the user data from the controller.
    // Due to the size trick employed and the API decision to expose this userData via method calls,
    // get_user_data_mut will not work for small sizes of U, since getUserData returns a copy of the field,
    // rather than being able to write a method that returns a pointer to the field or the field itself. Shame :/
    pub fn get_user_data(&self) -> &U {
        unsafe {
            if size_of::<U>() > size_of::<*mut c_void>() {
                // Cast *mut c_void to appropriate type and reborrow
                &*(PxController_getUserData(self.as_ptr()) as *const U)
            } else {
                // DATA_SIZE < VOID_SIZE
                // The data is packed into the "*mut c_void"
                &*(&PxController_getUserData(self.as_ptr()) as *const *mut c_void as *const U)
            }
        }
    }

    /// Sets the controllers user data.  If U is larger than a *mut _, it is heap allocated in a box.
    /// Otherwise, it is packed directly into the *mut c_void userData field.
    pub fn set_user_data(&mut self, user_data: U) -> &mut Self {
        unsafe {
            let user_data: *mut c_void = if size_of::<U>() > size_of::<*mut c_void>() {
                // Allocate on heap since it is too large to pack into *mut c_void field
                let user_data = Box::new(user_data);
                // Cast to *mut c_void
                Box::into_raw(user_data) as *mut c_void
            } else {
                // DATA_SIZE < VOID_SIZE
                // The data is small enough to be packed directly into the "*mut c_void"
                *(&user_data as *const U as *const *mut c_void)
            };
            PxController_setUserData_mut(self.as_mut_ptr(), user_data);
        }
        self
    }
}

impl<U> Drop for CapsuleController<U> {
    fn drop(&mut self) {
        unsafe {
            if size_of::<U>() > size_of::<*mut c_void>() {
                drop_in_place(PxController_getUserData(self.as_ptr()) as *mut U);
            } else {
                drop_in_place(
                    (&mut PxController_getUserData(self.as_ptr())) as *mut *mut c_void as *mut U,
                );
            };
            PxController_release_mut(self.as_mut_ptr())
        }
    }
}

unsafe impl<U: Send> Send for CapsuleController<U> {}
unsafe impl<U: Sync> Sync for CapsuleController<U> {}

pub struct CapsuleControllerDescriptor<'a, U, M> {
    pub height: f32,
    pub radius: f32,
    pub step_offset: f32,
    pub material: &'a mut PxMaterial<M>,
    pub user_data: U,
    pub position: PxExtendedVec3,
}

impl<'a, U, M> CapsuleControllerDescriptor<'a, U, M> {
    pub(crate) fn into_desc(self) -> Option<Owner<PxCapsuleControllerDesc<U>>> {
        unsafe {
            let mut desc = PxCapsuleControllerDesc::from_raw(
                PxCapsuleControllerDesc_new_alloc(),
                self.user_data,
            )?;
            desc.obj.height = self.height;
            desc.obj.radius = self.radius;
            desc.obj.stepOffset = self.step_offset;
            desc.obj.material = self.material.as_mut_ptr();
            desc.obj.upDirection = PxVec3::new(0.0, 1.0, 0.0).into();
            desc.obj.position = self.position.into();

            if desc.is_valid() {
                Some(desc)
            } else {
                None
            }
        }
    }
}

#[repr(transparent)]
pub(crate) struct PxCapsuleControllerDesc<U> {
    pub(crate) obj: physx_sys::PxCapsuleControllerDesc,
    phantom_user_data: PhantomData<U>,
}

unsafe impl<T, U> Class<T> for PxCapsuleControllerDesc<U>
where
    physx_sys::PxCapsuleControllerDesc: Class<T>,
{
    fn as_ptr(&self) -> *const T {
        self.obj.as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut T {
        self.obj.as_mut_ptr()
    }
}

impl<U> PxCapsuleControllerDesc<U> {
    unsafe fn from_raw<'a>(
        ptr: *mut physx_sys::PxCapsuleControllerDesc,
        user_data: U,
    ) -> Option<Owner<Self>> {
        Owner::from_raw((ptr as *mut Self).as_mut()?.init_user_data(user_data))
    }
}

impl<U> Drop for PxCapsuleControllerDesc<U> {
    fn drop(&mut self) {
        unsafe {
            drop_in_place(UserData::get_user_data_mut(self) as *mut _);
            PxCapsuleControllerDesc_delete(self.as_mut_ptr());
        }
    }
}

impl<T> CapsuleControllerDesc for T where
    T: Class<physx_sys::PxCapsuleControllerDesc> + ControllerDesc
{
}
pub trait CapsuleControllerDesc:
    Class<physx_sys::PxCapsuleControllerDesc> + ControllerDesc
{
    unsafe fn is_valid(&self) -> bool {
        PxCapsuleControllerDesc_isValid(self.as_ptr())
    }
}

impl<T> ControllerDesc for T where T: Class<PxControllerDesc> {}
pub trait ControllerDesc: Class<PxControllerDesc> {
    // ???
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
