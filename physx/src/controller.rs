#![warn(clippy::all)]

use crate::{
    material::Material,
    math::{PxExtendedVec3, PxVec3},
    owner::Owner,
    traits::{Class, UserData},
};

use std::{ffi::c_void, marker::PhantomData, mem::size_of, ptr::drop_in_place};

use thiserror::Error;

use physx_sys::{
    PxBoxControllerDesc_delete,
    PxBoxControllerDesc_isValid,
    PxBoxControllerDesc_new_alloc,
    PxBoxController_getHalfForwardExtent,
    PxBoxController_getHalfHeight,
    PxBoxController_getHalfSideExtent,
    PxBoxController_setHalfForwardExtent_mut,
    PxBoxController_setHalfHeight_mut,
    PxBoxController_setHalfSideExtent_mut,
    PxCapsuleControllerDesc_delete,
    PxCapsuleControllerDesc_isValid,
    PxCapsuleControllerDesc_new_alloc,
    //PxController_getActor,
    PxCapsuleController_getClimbingMode,
    PxCapsuleController_getHeight,
    PxCapsuleController_getRadius,
    PxCapsuleController_setClimbingMode_mut,
    PxCapsuleController_setHeight_mut,
    PxCapsuleController_setRadius_mut,
    PxController,
    PxController_getPosition,
    PxController_getUserData,
    PxController_release_mut,
    PxController_setPosition_mut,
    PxController_setUserData_mut,
};

pub trait Controller: Class<PxController> + Sized {
    type UserData;
    type Descriptor: Class<physx_sys::PxControllerDesc>;

    /// Retrieve the user data from the controller.
    // Due to the size trick employed and the API decision to expose this userData via method calls,
    // get_user_data_mut will not work for small sizes of U, since getUserData returns a copy of the field,
    // rather than being able to write a method that returns a pointer to the field or the field itself.
    fn get_user_data(&self) -> &Self::UserData {
        unsafe {
            if size_of::<Self::UserData>() > size_of::<*mut c_void>() {
                // Cast *mut c_void to appropriate type and reborrow
                &*(PxController_getUserData(self.as_ptr()) as *const Self::UserData)
            } else {
                // DATA_SIZE < VOID_SIZE
                // The data is packed into the "*mut c_void"
                &*(&PxController_getUserData(self.as_ptr()) as *const *mut c_void
                    as *const Self::UserData)
            }
        }
    }

    /// Sets the controllers user data.  If U is larger than a *mut _, it is heap allocated in a box.
    /// Otherwise, it is packed directly into the *mut c_void userData field.
    fn set_user_data(&mut self, user_data: Self::UserData) -> &mut Self {
        unsafe {
            let user_data: *mut c_void = if size_of::<Self::UserData>() > size_of::<*mut c_void>() {
                // Allocate on heap since it is too large to pack into *mut c_void field
                let user_data = Box::new(user_data);
                // Cast to *mut c_void
                Box::into_raw(user_data) as *mut c_void
            } else {
                // DATA_SIZE < VOID_SIZE
                // The data is small enough to be packed directly into the "*mut c_void"
                *(&user_data as *const Self::UserData as *const *mut c_void)
            };
            PxController_setUserData_mut(self.as_mut_ptr(), user_data);
        }
        self
    }

    /// Set the position of teh controller
    fn set_position(&mut self, position: impl Into<PxExtendedVec3>) {
        unsafe {
            let position: PxExtendedVec3 = position.into();
            PxController_setPosition_mut(self.as_mut_ptr(), position.as_ptr());
        }
    }

    /// Get the position of the controller.
    fn get_position(&self) -> PxVec3 {
        unsafe { (*PxController_getPosition(self.as_ptr())).into() }
    }
}

#[repr(transparent)]
pub struct PxCapsuleController<U> {
    obj: physx_sys::PxCapsuleController,
    phantom_user_data: PhantomData<U>,
}

unsafe impl<T, U> Class<T> for PxCapsuleController<U>
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

impl<U> Drop for PxCapsuleController<U> {
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

unsafe impl<U: Send> Send for PxCapsuleController<U> {}
unsafe impl<U: Sync> Sync for PxCapsuleController<U> {}

impl<U> Controller for PxCapsuleController<U> {
    type UserData = U;
    type Descriptor = PxCapsuleControllerDesc<U>;
}

impl<U> CapsuleController for PxCapsuleController<U> {}

pub trait CapsuleController: Class<physx_sys::PxCapsuleController> + Controller {
    /// Get the climbing mode of the capsule controller.
    fn get_climbing_mode(&self) -> CapsuleClimbingMode {
        unsafe { PxCapsuleController_getClimbingMode(self.as_ptr()).into() }
    }

    /// Get the height of the capsule.
    fn get_height(&self) -> f32 {
        unsafe { PxCapsuleController_getHeight(self.as_ptr()) }
    }

    /// Get the radius of the capsule.
    fn get_radius(&self) -> f32 {
        unsafe { PxCapsuleController_getRadius(self.as_ptr()) }
    }

    /// Set the climbing mode of the capsule controller.
    fn set_climbing_mode(&mut self, mode: CapsuleClimbingMode) -> bool {
        unsafe { PxCapsuleController_setClimbingMode_mut(self.as_mut_ptr(), mode.into()) }
    }

    /// Set the height of the capsule.
    fn set_height(&mut self, height: f32) -> bool {
        unsafe { PxCapsuleController_setHeight_mut(self.as_mut_ptr(), height) }
    }

    /// Set the radius of the capsule.
    fn set_radius(&mut self, radius: f32) -> bool {
        unsafe { PxCapsuleController_setRadius_mut(self.as_mut_ptr(), radius) }
    }
}

/// A new type wrapper for `physx_sys::PxCapsuleControllerDesc`, parametrized by the user data type.
#[repr(transparent)]
pub struct PxCapsuleControllerDesc<U> {
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
    /// Create a new capsule controller descriptor.
    pub fn new<M: Material>(
        height: f32,
        radius: f32,
        step_offset: f32,
        material: &mut M,
        user_data: U,
        position: PxExtendedVec3,
    ) -> Option<Owner<Self>> {
        unsafe {
            let mut desc =
                PxCapsuleControllerDesc::from_raw(PxCapsuleControllerDesc_new_alloc(), user_data)?;
            desc.obj.height = height;
            desc.obj.radius = radius;
            desc.obj.stepOffset = step_offset;
            desc.obj.material = material.as_mut_ptr();
            desc.obj.upDirection = PxVec3::new(0.0, 1.0, 0.0).into();
            desc.obj.position = position.into();

            if PxCapsuleControllerDesc_isValid(desc.as_ptr()) {
                Some(desc)
            } else {
                None
            }
        }
    }

    /// # Safety
    /// Owner's own the pointer they wrap, using the pointer after dropping the Owner,
    /// or creating multiple Owners from the same pointer will cause UB.  Use `into_ptr` to
    /// retrieve the pointer and consume the Owner without dropping the pointee.
    unsafe fn from_raw(
        ptr: *mut physx_sys::PxCapsuleControllerDesc,
        user_data: U,
    ) -> Option<Owner<Self>> {
        Owner::from_raw((ptr as *mut Self).as_mut()?.init_user_data(user_data))
    }
}

unsafe impl<U> UserData for PxCapsuleControllerDesc<U> {
    type UserData = U;

    fn user_data_ptr(&self) -> &*mut c_void {
        &self.obj.userData
    }

    fn user_data_ptr_mut(&mut self) -> &mut *mut c_void {
        &mut self.obj.userData
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

#[repr(transparent)]
pub struct PxBoxController<U> {
    obj: physx_sys::PxBoxController,
    phantom_user_data: PhantomData<U>,
}

unsafe impl<T, U> Class<T> for PxBoxController<U>
where
    physx_sys::PxBoxController: Class<T>,
{
    fn as_ptr(&self) -> *const T {
        self.obj.as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut T {
        self.obj.as_mut_ptr()
    }
}

impl<U> Drop for PxBoxController<U> {
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

unsafe impl<U: Send> Send for PxBoxController<U> {}
unsafe impl<U: Sync> Sync for PxBoxController<U> {}

impl<U> Controller for PxBoxController<U> {
    type UserData = U;
    type Descriptor = PxBoxControllerDesc<U>;
}

impl<U> BoxController for PxBoxController<U> {}

pub trait BoxController: Class<physx_sys::PxBoxController> + Controller {
    /// Get the half forward extent.
    fn get_half_forward_extent(&self) -> f32 {
        unsafe { PxBoxController_getHalfForwardExtent(self.as_ptr()) }
    }

    /// Get the half height.
    fn get_half_height(&self) -> f32 {
        unsafe { PxBoxController_getHalfHeight(self.as_ptr()) }
    }

    /// Get the half side extent.
    fn get_half_side_extent(&self) -> f32 {
        unsafe { PxBoxController_getHalfSideExtent(self.as_ptr()) }
    }

    /// Set the half forward extent.
    fn set_half_forward_extent(&mut self, extent: f32) -> bool {
        unsafe { PxBoxController_setHalfForwardExtent_mut(self.as_mut_ptr(), extent) }
    }

    /// Set the half height.
    fn set_half_height(&mut self, height: f32) -> bool {
        unsafe { PxBoxController_setHalfHeight_mut(self.as_mut_ptr(), height) }
    }

    /// Set the half side extent.
    fn set_half_side_extent(&mut self, extent: f32) -> bool {
        unsafe { PxBoxController_setHalfSideExtent_mut(self.as_mut_ptr(), extent) }
    }
}

/// A new type wrapper for `physx_sys::PxBoxControllerDesc`, parametrized by the user data type.
#[repr(transparent)]
pub struct PxBoxControllerDesc<U> {
    obj: physx_sys::PxBoxControllerDesc,
    phantom_user_data: PhantomData<U>,
}

unsafe impl<T, U> Class<T> for PxBoxControllerDesc<U>
where
    physx_sys::PxBoxControllerDesc: Class<T>,
{
    fn as_ptr(&self) -> *const T {
        self.obj.as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut T {
        self.obj.as_mut_ptr()
    }
}

impl<U> PxBoxControllerDesc<U> {
    /// Create a new box controller descriptor.
    pub fn new<M: Material>(
        half_height: f32,
        half_side_extent: f32,
        half_forward_extent: f32,
        step_offset: f32,
        material: &mut M,
        user_data: U,
        position: PxExtendedVec3,
    ) -> Option<Owner<Self>> {
        unsafe {
            let mut desc =
                PxBoxControllerDesc::from_raw(PxBoxControllerDesc_new_alloc(), user_data)?;
            desc.obj.halfHeight = half_height;
            desc.obj.halfSideExtent = half_side_extent;
            desc.obj.halfForwardExtent = half_forward_extent;
            desc.obj.stepOffset = step_offset;
            desc.obj.material = material.as_mut_ptr();
            desc.obj.upDirection = PxVec3::new(0.0, 1.0, 0.0).into();
            desc.obj.position = position.into();

            if PxBoxControllerDesc_isValid(desc.as_ptr()) {
                Some(desc)
            } else {
                None
            }
        }
    }

    /// # Safety
    /// Owner's own the pointer they wrap, using the pointer after dropping the Owner,
    /// or creating multiple Owners from the same pointer will cause UB.  Use `into_ptr` to
    /// retrieve the pointer and consume the Owner without dropping the pointee.
    unsafe fn from_raw(
        ptr: *mut physx_sys::PxBoxControllerDesc,
        user_data: U,
    ) -> Option<Owner<Self>> {
        Owner::from_raw((ptr as *mut Self).as_mut()?.init_user_data(user_data))
    }
}

unsafe impl<U> UserData for PxBoxControllerDesc<U> {
    type UserData = U;

    fn user_data_ptr(&self) -> &*mut c_void {
        &self.obj.userData
    }

    fn user_data_ptr_mut(&mut self) -> &mut *mut c_void {
        &mut self.obj.userData
    }
}

impl<U> Drop for PxBoxControllerDesc<U> {
    fn drop(&mut self) {
        unsafe {
            drop_in_place(UserData::get_user_data_mut(self) as *mut _);
            PxBoxControllerDesc_delete(self.as_mut_ptr())
        }
    }
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

#[derive(Copy, Clone)]
pub enum CapsuleClimbingMode {
    Easy,
    Constrained,
}

impl From<CapsuleClimbingMode> for physx_sys::PxCapsuleClimbingMode::Enum {
    fn from(value: CapsuleClimbingMode) -> Self {
        match value {
            CapsuleClimbingMode::Easy => physx_sys::PxCapsuleClimbingMode::eEASY,
            CapsuleClimbingMode::Constrained => physx_sys::PxCapsuleClimbingMode::eCONSTRAINED,
        }
    }
}

impl From<physx_sys::PxCapsuleClimbingMode::Enum> for CapsuleClimbingMode {
    fn from(mode: physx_sys::PxCapsuleClimbingMode::Enum) -> Self {
        match mode {
            physx_sys::PxCapsuleClimbingMode::eEASY => CapsuleClimbingMode::Easy,
            physx_sys::PxCapsuleClimbingMode::eCONSTRAINED => CapsuleClimbingMode::Constrained,
            _ => unreachable!("invalid PxCapsuleClimbingMode: {:?}", mode),
        }
    }
}
