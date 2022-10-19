// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 10 April 2019

#![warn(clippy::all)]

/*!
Wrapper for PxFoundation class
*/

use crate::{owner::Owner, traits::Class};
use enumflags2::{bitflags, BitFlags};
use physx_sys::{
    create_alloc_callback, get_alloc_callback_user_data, get_default_allocator,
    get_default_error_callback, phys_PxCreateFoundation, PxAllocatorCallback, PxErrorCallback,
    PxFoundation_getAllocatorCallback_mut, PxFoundation_getErrorCallback_mut,
    PxFoundation_getErrorLevel, PxFoundation_getReportAllocationNames, PxFoundation_release_mut,
    PxFoundation_setErrorLevel_mut, PxFoundation_setReportAllocationNames_mut,
};
use std::{
    alloc::{alloc, dealloc, Layout},
    ffi::c_void,
    marker::PhantomData,
    mem::{align_of, size_of},
    sync::atomic::{AtomicUsize, Ordering::SeqCst},
};

#[bitflags]
#[derive(Copy, Clone, Debug, PartialEq, Eq)]
#[repr(u32)]
pub enum ErrorCode {
    DebugInfo = 1u32,
    DebugWarning = 2u32,
    InvalidParameter = 4u32,
    InvalidOperation = 8u32,
    OutOfMemory = 16u32,
    InternalError = 32u32,
    Abort = 64u32,
    PerfWarning = 128u32,
}

/// A new type wrapper for PxFoundation.  Parametrized by it's Allocator type.
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
    /// # Safety
    /// `error_callback` must live as long as the returned `Foundation`
    unsafe fn with_allocator_error_callback(
        allocator: Self::Allocator,
        error_callback: *mut PxErrorCallback,
    ) -> Option<Owner<Self>> {
        Owner::from_raw(
            phys_PxCreateFoundation(
                crate::physics::PX_PHYSICS_VERSION,
                allocator.into_px(),
                error_callback,
            )
            .cast::<Self>(),
        )
    }

    /// Get the error callback.
    fn get_error_callback(&mut self) -> Option<&mut PxErrorCallback> {
        unsafe { PxFoundation_getErrorCallback_mut(self.as_mut_ptr()).as_mut() }
    }

    /// Set the error level.
    fn set_error_level(&mut self, mask: BitFlags<ErrorCode>) {
        unsafe { PxFoundation_setErrorLevel_mut(self.as_mut_ptr(), mask.bits() as i32) }
    }

    /// Get the error level.
    fn get_error_level(&self) -> BitFlags<ErrorCode> {
        unsafe {
            BitFlags::from_bits(PxFoundation_getErrorLevel(self.as_ptr()) as u32)
                .expect("got invalid bits for error flags")
        }
    }

    /// Get the allocator callback.
    fn get_allocator_callback(&mut self) -> Option<&mut Self::Allocator> {
        unsafe {
            (get_alloc_callback_user_data(PxFoundation_getAllocatorCallback_mut(self.as_mut_ptr()))
                as *mut Self::Allocator)
                .as_mut()
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
struct ScratchBufferBlock([u8; 16384]);

pub struct ScratchBuffer {
    ptr: *mut c_void,
    size: usize,
}

impl ScratchBuffer {
    pub(crate) fn as_ptr_and_size(&mut self) -> (*mut c_void, u32) {
        (self.ptr, self.size as u32)
    }

    /// # Safety
    ///
    /// The buffer must live at least until fetch_results returns.
    pub unsafe fn new(nb_blocks: usize) -> Self {
        let size = size_of::<ScratchBufferBlock>() * nb_blocks;
        let align = align_of::<ScratchBufferBlock>();
        let ptr = alloc(Layout::from_size_align(size, align).unwrap()) as *mut c_void;
        Self { ptr, size }
    }
}

/// A trait for creating allocator callbacks for PhysX.
///
/// Reporting the name, file and line is not enabled by default.
/// Use [`Foundation::set_report_allocation_names`] to toggle this on or off.
#[allow(clippy::missing_safety_doc)]
pub unsafe trait AllocatorCallback: Sized {
    /// # Safety
    ///
    /// Allocations must be aligned 16. This should not panic, since it is
    /// called in an FFI context and unwinding across the FFI barrier is UB.
    unsafe extern "C" fn allocate(
        size: u64,
        name: *const c_void,
        file: *const c_void,
        line: u32,
        user_data: *const c_void,
    ) -> *mut c_void;

    /// # Safety
    ///
    /// Must not panic.
    unsafe extern "C" fn deallocate(ptr: *const c_void, user_data: *const c_void);

    /// # Safety
    ///
    /// Do not override this method.
    unsafe fn into_px(self) -> *mut PxAllocatorCallback {
        create_alloc_callback(
            Self::allocate,
            Self::deallocate,
            Box::into_raw(Box::new(self)) as *mut c_void,
        )
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
        _user_data: *const c_void,
    ) -> *mut c_void {
        let alloc_size = size as usize + 16;
        let layout = std::alloc::Layout::from_size_align(alloc_size, 16).unwrap();
        let allocation = alloc(layout) as *mut u64;
        *allocation = alloc_size as u64;
        (allocation as usize + 16) as *mut c_void
    }

    unsafe extern "C" fn deallocate(ptr: *const c_void, _user_data: *const c_void) {
        let ptr = (ptr as usize - 16) as *mut u64;
        let size = *ptr;
        let layout = Layout::from_size_align(size as usize, 16).unwrap();
        dealloc(ptr as *mut u8, layout)
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
        user_data: *const c_void,
    ) -> *mut c_void {
        let user_data = &*(user_data as *const Self);
        let alloc_size = size as usize + 16;
        let layout = std::alloc::Layout::from_size_align(alloc_size, 16).unwrap();
        user_data.allocated.fetch_add(layout.size(), SeqCst);
        let allocation = alloc(layout) as *mut u64;
        *allocation = alloc_size as u64;
        (allocation as usize + 16) as *mut c_void
    }

    unsafe extern "C" fn deallocate(ptr: *const c_void, user_data: *const c_void) {
        let user_data = &*(user_data as *const Self);
        let ptr = (ptr as usize - 16) as *mut u64;
        let size = *ptr;
        let layout = Layout::from_size_align(size as usize, 16).unwrap();
        user_data.deallocated.fetch_add(layout.size(), SeqCst);
        dealloc(ptr as *mut u8, layout)
    }
}

/// The PhysX-provided default allocator.
pub struct DefaultAllocator;

unsafe impl AllocatorCallback for DefaultAllocator {
    unsafe fn into_px(self) -> *mut PxAllocatorCallback {
        get_default_allocator() as *mut PxAllocatorCallback
    }

    unsafe extern "C" fn allocate(
        _size: u64,
        _name: *const c_void,
        _file: *const c_void,
        _line: u32,
        _user_data: *const c_void,
    ) -> *mut c_void {
        unreachable!()
    }

    unsafe extern "C" fn deallocate(_ptr: *const c_void, _user_data: *const c_void) {
        unreachable!()
    }
}
