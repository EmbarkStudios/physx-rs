// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 10 April 2019

#![warn(clippy::all)]

/*!
Wrapper for PxFoundation class
*/

use crate::{owner::Owner, traits::Class, version};
use enumflags2::BitFlags;
use physx_sys::{
    create_alloc_callback, get_default_allocator, get_default_error_callback,
    phys_PxCreateFoundation, PxAllocatorCallback, PxErrorCallback,
    PxFoundation_getAllocatorCallback_mut, PxFoundation_getErrorCallback_mut,
    PxFoundation_getErrorLevel, PxFoundation_getReportAllocationNames, PxFoundation_release_mut,
    PxFoundation_setErrorLevel_mut, PxFoundation_setReportAllocationNames_mut,
};
use std::{
    alloc::{alloc, dealloc, Layout},
    ffi::c_void,
    ptr::null_mut,
    sync::atomic::{AtomicUsize, Ordering::SeqCst},
};

#[derive(BitFlags, Copy, Clone, Debug, PartialEq)]
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

#[repr(transparent)]
pub struct Foundation {
    obj: physx_sys::PxFoundation,
}

crate::ClassObj!(Foundation: PxFoundation);

impl Foundation {
    /// Tries to create a Foundation of the given version with the default allocator and error callbacks.
    /// Returns `None` if `phys_PxCreateFoundation` returns a null pointer.
    pub fn new<A: AllocatorCallback>() -> Option<Owner<Self>> {
        let allocator = unsafe { A::new() };
        unsafe {
            Foundation::from_raw(phys_PxCreateFoundation(
                version(4, 1, 1),
                allocator,
                get_default_error_callback() as *mut PxErrorCallback,
            ))
        }
    }

    pub(crate) fn from_raw(ptr: *mut physx_sys::PxFoundation) -> Option<Owner<Foundation>> {
        unsafe { Owner::from_raw(ptr as *mut Foundation) }
    }

    pub fn get_error_callback(&mut self) -> Option<&mut PxErrorCallback> {
        unsafe { PxFoundation_getErrorCallback_mut(self.as_mut_ptr()).as_mut() }
    }

    pub fn set_error_level(&mut self, mask: BitFlags<ErrorCode>) {
        unsafe { PxFoundation_setErrorLevel_mut(self.as_mut_ptr(), mask.bits() as i32) }
    }

    pub fn get_error_level(&self) -> BitFlags<ErrorCode> {
        unsafe {
            BitFlags::from_bits(PxFoundation_getErrorLevel(self.as_ptr()) as u32)
                .expect("got invalid bits for error flags")
        }
    }

    pub fn get_allocator_callback(&mut self) -> Option<&mut PxAllocatorCallback> {
        unsafe { PxFoundation_getAllocatorCallback_mut(self.as_mut_ptr()).as_mut() }
    }

    pub fn get_report_allocation_names(&self) -> bool {
        unsafe { PxFoundation_getReportAllocationNames(self.as_ptr()) }
    }

    pub fn set_report_allocation_names(&mut self, value: bool) {
        unsafe { PxFoundation_setReportAllocationNames_mut(self.as_mut_ptr(), value) }
    }
}

unsafe impl Send for Foundation {}
unsafe impl Sync for Foundation {}

impl Drop for Foundation {
    fn drop(&mut self) {
        let allocated = ALLOCATED.load(SeqCst);
        let deallocated = ALLOCATED.load(SeqCst);
        let leaked = allocated - deallocated;
        if allocated != 0 {
            println!(
                "Allocated: {} | Deallocated: {} | Leaked: {}",
                allocated, deallocated, leaked
            );
        }
        unsafe { PxFoundation_release_mut(self.as_mut_ptr()) }
    }
}

/// An trait for creating allocator callbacks for PhysX.
/// Implement the interface on a ZST.  Currently, user_data is unused
/// since there isn't a good way of communicating ownership, or calling
/// it's dtor.  If user_data is needed, call `physx_sys::create_alloc_callback`
/// directly.
pub unsafe trait AllocatorCallback: Sized {
    unsafe extern "C" fn allocate(
        size: u64,
        name: *const c_void,
        file: *const c_void,
        line: u32,
        user_data: *const c_void,
    ) -> *mut c_void;

    unsafe extern "C" fn deallocate(ptr: *const c_void, user_data: *const c_void);

    unsafe fn new() -> *mut PxAllocatorCallback {
        create_alloc_callback(Self::allocate, Self::deallocate, null_mut())
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
        println!("alloc: {}", layout.size());
        let allocation = alloc(layout) as *mut u64;
        *allocation = alloc_size as u64;
        (allocation as usize + 16) as *mut c_void
    }

    unsafe extern "C" fn deallocate(ptr: *const c_void, _user_data: *const c_void) {
        let ptr = (ptr as usize - 16) as *mut u64;
        let size = *ptr;
        let layout = Layout::from_size_align(size as usize, 16).unwrap();
        println!("dealloc: {}", layout.size());
        dealloc(ptr as *mut u8, layout)
    }
}

/// A simple tracking allocator that calls through to Rust's GlobalAllocator.
/// Note that it tracks the amount of space needed for storing the allocation sizes
/// as well as the actual data.  PhysX seems to allocate a fair few 4 byte align-16
/// objects, so the 16 bytes of overhead per alloc is a huge waste: 32 bytes, 4 are data.
// "You dont pay for what you dont use" (:
pub struct TrackingAllocator;
pub static ALLOCATED: AtomicUsize = AtomicUsize::new(0);
pub static DEALLOCATED: AtomicUsize = AtomicUsize::new(0);

unsafe impl AllocatorCallback for TrackingAllocator {
    unsafe extern "C" fn allocate(
        size: u64,
        _name: *const c_void,
        _file: *const c_void,
        _line: u32,
        _user_data: *const c_void,
    ) -> *mut c_void {
        let alloc_size = size as usize + 16;
        let layout = std::alloc::Layout::from_size_align(alloc_size, 16).unwrap();
        ALLOCATED.fetch_add(layout.size(), SeqCst);
        let allocation = alloc(layout) as *mut u64;
        *allocation = alloc_size as u64;
        (allocation as usize + 16) as *mut c_void
    }

    unsafe extern "C" fn deallocate(ptr: *const c_void, _user_data: *const c_void) {
        let ptr = (ptr as usize - 16) as *mut u64;
        let size = *ptr;
        let layout = Layout::from_size_align(size as usize, 16).unwrap();
        DEALLOCATED.fetch_add(layout.size(), SeqCst);
        dealloc(ptr as *mut u8, layout)
    }
}

/// The PhysX-provided default allocator.
pub struct DefaultAllocator;

unsafe impl AllocatorCallback for DefaultAllocator {
    unsafe fn new() -> *mut PxAllocatorCallback {
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
