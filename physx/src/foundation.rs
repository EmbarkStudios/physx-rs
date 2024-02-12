// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 10 April 2019

#![allow(non_upper_case_globals)]

use crate::{owner::Owner, traits::Class};

use physx_sys::{ConstUserData, UserData};
#[rustfmt::skip]
use physx_sys::{
    create_alloc_callback,
    get_alloc_callback_user_data,
    get_default_allocator,
    get_default_error_callback,
    phys_PxCreateFoundation,
    PxAllocatorCallback,
    PxErrorCallback,
    PxErrorCode,
    PxFoundation_getAllocatorCallback_mut,
    PxFoundation_getErrorCallback_mut,
    PxFoundation_getErrorLevel,
    PxFoundation_getReportAllocationNames,
    PxFoundation_release_mut,
    PxFoundation_setErrorLevel_mut,
    PxFoundation_setReportAllocationNames_mut,
};
use std::{
    alloc::{alloc, dealloc, Layout},
    ffi::c_void,
    marker::PhantomData,
    mem::{align_of, size_of},
    sync::atomic::{AtomicUsize, Ordering::SeqCst},
};

bitflags::bitflags! {
    #[repr(transparent)]
    pub struct ErrorCodes: u32 {
        /// An informational message.
        const DebugInfo = PxErrorCode::DebugInfo as u32;
        /// A warning message for the user to help with debugging
        const DebugWarning = PxErrorCode::DebugWarning as u32;
        /// Method called with invalid parameter(s)
        const InvalidParameter = PxErrorCode::InvalidParameter as u32;
        /// Method was called at a time when an operation is not possible
        const InvalidOperation = PxErrorCode::InvalidOperation as u32;
        /// Method failed to allocate some memory
        const OutOfMemory = PxErrorCode::OutOfMemory as u32;
        /// The library failed for some reason.
        ///
        /// Possibly you have passed invalid values like NaNs, which are not checked for.
        const InternalError = PxErrorCode::InternalError as u32;
        /// An unrecoverable error, execution should be halted and log output flushed
        const Abort = PxErrorCode::Abort as u32;
        /// The SDK has determined that an operation may result in poor performance.
        const PerfWarning = PxErrorCode::PerfWarning as u32;
    }
}

/// A new type wrapper for PxFoundation.
///
/// Parametrized by its Allocator type.
#[repr(transparent)]
pub struct PxFoundation<Allocator: AllocatorCallback> {
    obj: physx_sys::PxFoundation,
    phantom_interface: PhantomData<Allocator>,
}

impl<Allocator: AllocatorCallback> Drop for PxFoundation<Allocator> {
    fn drop(&mut self) {
        unsafe {
            if let Some(allocator) = self.get_allocator_callback() {
                drop(Box::from_raw(allocator));
            };
            PxFoundation_release_mut(self.as_mut_ptr());
        }
    }
}

unsafe impl<P, Allocator: AllocatorCallback> Class<P> for PxFoundation<Allocator>
where
    physx_sys::PxFoundation: Class<P>,
{
    fn as_ptr(&self) -> *const P {
        self.obj.as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut P {
        self.obj.as_mut_ptr()
    }
}

unsafe impl<Allocator: AllocatorCallback + Send> Send for PxFoundation<Allocator> {}
unsafe impl<Allocator: AllocatorCallback + Sync> Sync for PxFoundation<Allocator> {}

impl<Allocator: AllocatorCallback> Foundation for PxFoundation<Allocator> {
    type Allocator = Allocator;
}

pub trait Foundation: Class<physx_sys::PxFoundation> + Sized {
    type Allocator: AllocatorCallback;

    /// Tries to create a PxFoundation of the given version with the default allocator and error callbacks.
    /// Returns `None` if `phys_PxCreateFoundation` returns a null pointer.
    fn new(allocator: Self::Allocator) -> Option<Owner<Self>> {
        unsafe {
            Self::with_allocator_error_callback(
                allocator,
                get_default_error_callback() as *mut PxErrorCallback,
            )
        }
    }

    /// Tries to create a PxFoundation with the provided allocator and error callbacks.
    /// Returns `None` if `phys_PxCreateFoundation` returns a null pointer.
    ///
    /// # Safety
    ///
    /// `error_callback` must live as long as the returned `Foundation`
    unsafe fn with_allocator_error_callback(
        allocator: Self::Allocator,
        error_callback: *mut PxErrorCallback,
    ) -> Option<Owner<Self>> {
        unsafe {
            Owner::from_raw(
                phys_PxCreateFoundation(
                    crate::physics::PX_PHYSICS_VERSION,
                    allocator.into_px(),
                    error_callback,
                )
                .cast::<Self>(),
            )
        }
    }

    /// Get the error callback.
    fn get_error_callback(&mut self) -> Option<&mut PxErrorCallback> {
        unsafe { PxFoundation_getErrorCallback_mut(self.as_mut_ptr()).as_mut() }
    }

    /// Set the error level.
    fn set_error_level(&mut self, mask: ErrorCodes) {
        unsafe { PxFoundation_setErrorLevel_mut(self.as_mut_ptr(), mask.bits()) }
    }

    /// Get the error level.
    fn get_error_level(&self) -> ErrorCodes {
        unsafe {
            ErrorCodes::from_bits(PxFoundation_getErrorLevel(self.as_ptr()))
                .expect("got invalid bits for error flags")
        }
    }

    /// Get the allocator callback.
    fn get_allocator_callback(&mut self) -> Option<&mut Self::Allocator> {
        let px_allocatorcallback =
            unsafe { PxFoundation_getAllocatorCallback_mut(self.as_mut_ptr()) };
        if px_allocatorcallback.is_null() {
            None
        } else {
            // SAFETY: we know px_allocatorcallback is not null, and the only way for that to happen when using
            // the safe wrapper is if we initialized it properly
            let mut userdata = unsafe { get_alloc_callback_user_data(px_allocatorcallback) };
            // SAFETY: if we got a non-null allocatorcallback object back, then we must also have a non-null pointer
            // to a `Self::Allocator` in the userdata because we initialize it ourselves in the implementation of `AllocatorCallback`,
            // which `Self::Allocator` implements and uses to initialize itself.
            //
            // we assert the lifetime of `allocator_mut` to be at least as long as the borrow of `self`, which is true since it's on the heap
            // and we don't clean it up
            Some(unsafe { &mut *userdata.as_mut_ptr::<Self::Allocator>() })
        }
    }

    /// Get whether allocation names are reported.
    fn get_report_allocation_names(&self) -> bool {
        unsafe { PxFoundation_getReportAllocationNames(self.as_ptr()) }
    }

    /// Set whether allocation names are reported.
    fn set_report_allocation_names(&mut self, value: bool) {
        unsafe { PxFoundation_setReportAllocationNames_mut(self.as_mut_ptr(), value) }
    }
}

#[repr(align(16))]
struct ScratchBufferBlock([u8; 16 * 1024]);

pub struct ScratchBuffer {
    ptr: *mut c_void,
    size: usize,
}

impl ScratchBuffer {
    #[inline]
    pub(crate) fn as_ptr_and_size(&mut self) -> (*mut c_void, u32) {
        (self.ptr, self.size as u32)
    }

    /// # Safety
    ///
    /// The buffer must live at least until fetch_results returns.
    pub unsafe fn new(nb_blocks: usize) -> Self {
        let size = size_of::<ScratchBufferBlock>() * nb_blocks;
        let align = align_of::<ScratchBufferBlock>();
        let ptr = unsafe { alloc(Layout::from_size_align(size, align).unwrap()) as *mut c_void };
        Self { ptr, size }
    }
}

/// A trait for creating allocator callbacks for PhysX.
///
/// Reporting the name, file and line is not enabled by default.
/// Use [`Foundation::set_report_allocation_names`] to toggle this on or off.
///
/// When you use `AllocatorCallback::into_px(self)`, the `self` you pass in will be
/// placed on the heap and a pointer to it will be passed into the `user_data` in the
/// `allocate` and `deallocate` functions. Keep in mind the threading context you're using and
/// ensure that the type you're implementing this on is sufficiently thread-safe for the kinds
/// of access you are doing.
#[allow(clippy::missing_safety_doc)]
pub unsafe trait AllocatorCallback: Sized {
    /// `user_data` will be a forced-heap-pointer to a `Self`. So you can access the `self` that
    /// `into_px` was called on by calling `user_data.heap_data_ref::<Self>()`.
    ///
    /// # Safety
    ///
    /// Allocations must be aligned 16. This should not panic, since it is
    /// called in an FFI context and unwinding across the FFI barrier is UB.
    unsafe extern "C" fn allocate(
        size: u64,
        name: *const c_void,
        file: *const c_void,
        line: u32,
        user_data: ConstUserData,
    ) -> *mut c_void;

    /// `user_data` will be a forced-heap-pointer to a `Self`. So you can access the `self` that
    /// `into_px` was called on by calling `user_data.heap_data_ref::<Self>()`.
    ///
    /// # Safety
    ///
    /// Must not panic.
    unsafe extern "C" fn deallocate(ptr: *const c_void, user_data: ConstUserData);

    /// # Safety
    ///
    /// Do not override this method.
    unsafe fn into_px(self) -> *mut PxAllocatorCallback {
        unsafe {
            create_alloc_callback(
                Self::allocate,
                Self::deallocate,
                UserData::new_on_heap(self),
            )
        }
    }
}

/// A very simple allocator that calls through to Rust's GlobalAllocator.
pub struct GlobalAllocCallback;

unsafe impl AllocatorCallback for GlobalAllocCallback {
    unsafe extern "C" fn allocate(
        size: u64,
        _name: *const c_void,
        _file: *const c_void,
        _line: u32,
        _user_data: ConstUserData,
    ) -> *mut c_void {
        let alloc_size = size as usize + 16;
        let layout = std::alloc::Layout::from_size_align(alloc_size, 16).unwrap();
        unsafe {
            let allocation = alloc(layout) as *mut u64;
            *allocation = alloc_size as u64;
            (allocation as usize + 16) as *mut c_void
        }
    }

    unsafe extern "C" fn deallocate(ptr: *const c_void, _user_data: ConstUserData) {
        let ptr = (ptr as usize - 16) as *mut u64;
        unsafe {
            let size = *ptr;
            let layout = Layout::from_size_align(size as usize, 16).unwrap();
            dealloc(ptr as *mut u8, layout)
        }
    }
}

/// A simple tracking allocator that calls through to Rust's GlobalAllocator.
/// Note that it tracks the amount of space needed for storing the allocation sizes
/// as well as the actual data.
pub struct TrackingAllocator {
    pub allocated: AtomicUsize,
    pub deallocated: AtomicUsize,
}

impl Default for TrackingAllocator {
    fn default() -> Self {
        Self {
            allocated: AtomicUsize::new(0),
            deallocated: AtomicUsize::new(0),
        }
    }
}

unsafe impl AllocatorCallback for TrackingAllocator {
    unsafe extern "C" fn allocate(
        size: u64,
        _name: *const c_void,
        _file: *const c_void,
        _line: u32,
        user_data: ConstUserData,
    ) -> *mut c_void {
        let alloc_size = size as usize + 16;
        let layout = std::alloc::Layout::from_size_align(alloc_size, 16).unwrap();
        let this = unsafe { user_data.heap_data_ref::<Self>() };
        this.allocated.fetch_add(layout.size(), SeqCst);
        unsafe {
            let allocation = alloc(layout) as *mut u64;
            *allocation = alloc_size as u64;
            (allocation as usize + 16) as *mut c_void
        }
    }

    unsafe extern "C" fn deallocate(ptr: *const c_void, user_data: ConstUserData) {
        let ptr = (ptr as usize - 16) as *mut u64;
        let size = unsafe { *ptr };
        let layout = Layout::from_size_align(size as usize, 16).unwrap();
        let this = unsafe { user_data.heap_data_ref::<Self>() };
        this.deallocated.fetch_add(layout.size(), SeqCst);
        unsafe { dealloc(ptr as *mut u8, layout) }
    }
}

/// The PhysX-provided default allocator.
pub struct DefaultAllocator;

unsafe impl AllocatorCallback for DefaultAllocator {
    unsafe fn into_px(self) -> *mut PxAllocatorCallback {
        unsafe { get_default_allocator() as *mut PxAllocatorCallback }
    }

    unsafe extern "C" fn allocate(
        _size: u64,
        _name: *const c_void,
        _file: *const c_void,
        _line: u32,
        _user_data: ConstUserData,
    ) -> *mut c_void {
        unreachable!()
    }

    unsafe extern "C" fn deallocate(_ptr: *const c_void, _user_data: ConstUserData) {
        unreachable!()
    }
}
