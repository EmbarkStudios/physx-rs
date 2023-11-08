#![warn(clippy::all)]

use crate::{
    material::Material,
    math::{PxExtendedVec3, PxVec3},
    owner::Owner,
    traits::{Class, HasUserData},
};

use std::marker::PhantomData;

use physx_sys::UserData;
use thiserror::Error;

#[rustfmt::skip]
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

pub use physx_sys::PxCapsuleClimbingMode as CapsuleClimbingMode;

pub trait Controller: Class<PxController> + Sized {
    type UserData;
    type Descriptor: Class<physx_sys::PxControllerDesc>;

    /// Sets the controller's user data.
    fn set_user_data(&mut self, user_data: Self::UserData) -> &mut Self {
        let user_data = UserData::new_on_heap(user_data);
        // SAFETY: self is not null and is Class<PxController> user_data is valid
        unsafe { PxController_setUserData_mut(self.as_mut_ptr(), user_data) }
        self
    }

    /// Retrieve the user data from the controller. Must have been already created with
    /// `set_user_data` or in the `Desc` this came from or will return `None`
    fn get_user_data(&self) -> Option<&Self::UserData> {
        // SAFETY: self is a valid reference and is Class<PxController>
        let user_data = unsafe { PxController_getUserData(self.as_ptr()) };
        // SAFETY: we only ever init the user data as a pointer, so if it's nonnull we know we have
        // valid data, and it will live on the heap at least as long as we have a borrow of self
        // since it only will go out of scope by being able to have a mut ref to self
        unsafe { user_data.as_ptr::<Self::UserData>().as_ref() }
    }

    /// Retrieve a mutable reference to the user data from the controller. Must have been already
    /// created with `set_user_data` or in the `Desc` this came from or will return `None`.
    fn get_user_data_mut(&mut self) -> Option<&mut Self::UserData> {
        // SAFETY: self is a valid reference and is Class<PxController>
        let mut user_data = unsafe { PxController_getUserData(self.as_ptr()) };
        // SAFETY: we only ever init the user data as a pointer, so if it's nonnull we know we have
        // valid data, and it will live on the heap at least as long as we have a borrow of self
        // since it only will go out of scope by being able to have a mut ref to self
        unsafe { user_data.as_mut_ptr::<Self::UserData>().as_mut() }
    }

    /// If it exists, drop and dealloc associated user data.
    fn drop_and_dealloc_user_data(&mut self) {
        // SAFETY: self is a valid reference and is Class<PxController>
        let mut user_data = unsafe { PxController_getUserData(self.as_ptr()) };
        // SAFETY: we only initialize user_data as a pointer ever
        let is_null = unsafe { user_data.is_null() };
        if !is_null {
            // SAFETY: if the user_data is not null, we must have allocated it as on the heap
            // and it may be drop and dealloced
            unsafe {
                user_data.heap_drop_and_dealloc::<Self::UserData>();
            }
        }
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
            self.drop_and_dealloc_user_data();
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
        unsafe { PxCapsuleController_getClimbingMode(self.as_ptr()) }
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
        unsafe { PxCapsuleController_setClimbingMode_mut(self.as_mut_ptr(), mode) }
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
    ///
    /// Owner's own the pointer they wrap, using the pointer after dropping the Owner,
    /// or creating multiple Owners from the same pointer will cause UB.  Use `into_ptr` to
    /// retrieve the pointer and consume the Owner without dropping the pointee.
    unsafe fn from_raw(
        ptr: *mut physx_sys::PxCapsuleControllerDesc,
        user_data: U,
    ) -> Option<Owner<Self>> {
        unsafe { Owner::from_raw((ptr as *mut Self).as_mut()?.init_user_data(user_data)) }
    }
}

// override default behavior because we need the `userData` that gets passed along to the
// `Controller` this creates to be on the heap, which expects it to be so (see implementation
// of `Controller` trait)
impl<U> HasUserData for PxCapsuleControllerDesc<U> {
    type UserData = U;

    fn user_data_ptr(&self) -> &UserData {
        &self.obj.userData
    }

    fn user_data_ptr_mut(&mut self) -> &mut UserData {
        &mut self.obj.userData
    }

    fn init_user_data(&mut self, user_data: Self::UserData) -> &mut Self {
        self.user_data_ptr_mut()
            .initialize_on_heap::<Self::UserData>(user_data);
        self
    }

    unsafe fn drop_and_dealloc_user_data(&mut self) {
        // SAFETY: same as function-level safety
        unsafe {
            self.user_data_ptr_mut()
                .heap_drop_and_dealloc::<Self::UserData>()
        }
    }

    unsafe fn get_user_data(&self) -> &Self::UserData {
        unsafe { self.user_data_ptr().heap_data_ref::<Self::UserData>() }
    }

    unsafe fn get_user_data_mut(&mut self) -> &mut Self::UserData {
        unsafe { self.user_data_ptr_mut().heap_data_mut::<Self::UserData>() }
    }
}

impl<U> Drop for PxCapsuleControllerDesc<U> {
    fn drop(&mut self) {
        unsafe {
            // SAFETY: we always initialize this in the only public constructors
            self.drop_and_dealloc_user_data();
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
            self.drop_and_dealloc_user_data();
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
    ///
    /// Owner's own the pointer they wrap, using the pointer after dropping the Owner,
    /// or creating multiple Owners from the same pointer will cause UB.  Use `into_ptr` to
    /// retrieve the pointer and consume the Owner without dropping the pointee.
    unsafe fn from_raw(
        ptr: *mut physx_sys::PxBoxControllerDesc,
        user_data: U,
    ) -> Option<Owner<Self>> {
        unsafe { Owner::from_raw((ptr as *mut Self).as_mut()?.init_user_data(user_data)) }
    }
}

// override default behavior because we need the `userData` that gets passed along to the
// `Controller` this creates to be on the heap, which expects it to be so (see implementation
// of `Controller` trait)
impl<U> HasUserData for PxBoxControllerDesc<U> {
    type UserData = U;

    fn user_data_ptr(&self) -> &UserData {
        &self.obj.userData
    }

    fn user_data_ptr_mut(&mut self) -> &mut UserData {
        &mut self.obj.userData
    }

    fn init_user_data(&mut self, user_data: Self::UserData) -> &mut Self {
        self.user_data_ptr_mut()
            .initialize_on_heap::<Self::UserData>(user_data);
        self
    }

    unsafe fn drop_and_dealloc_user_data(&mut self) {
        // SAFETY: same as function-level safety
        unsafe {
            self.user_data_ptr_mut()
                .heap_drop_and_dealloc::<Self::UserData>()
        }
    }

    unsafe fn get_user_data(&self) -> &Self::UserData {
        unsafe { self.user_data_ptr().heap_data_ref::<Self::UserData>() }
    }

    unsafe fn get_user_data_mut(&mut self) -> &mut Self::UserData {
        unsafe { self.user_data_ptr_mut().heap_data_mut::<Self::UserData>() }
    }
}

impl<U> Drop for PxBoxControllerDesc<U> {
    fn drop(&mut self) {
        unsafe {
            // SAFETY: we always initialize this in the only public constructors
            self.drop_and_dealloc_user_data();
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
