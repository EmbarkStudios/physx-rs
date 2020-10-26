// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 10 April 2019

#![warn(clippy::all)]

/*!
Wrapper for PxFoundation class
*/

use crate::{
    traits::Class,
    owner::Owner,
};
use enumflags2::BitFlags;
use physx_sys::{
    PxErrorCallback,
    PxAllocatorCallback,
    PxFoundation_getAllocatorCallback_mut,
    PxFoundation_getErrorCallback_mut,
    PxFoundation_getErrorLevel,
    PxFoundation_getReportAllocationNames,
    PxFoundation_release_mut,
    PxFoundation_setErrorLevel_mut,
    PxFoundation_setReportAllocationNames_mut,
    phys_PxCreateFoundation,
    get_default_allocator,
    get_default_error_callback,
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

crate::ClassObj!(Foundation : PxFoundation);

impl Foundation {
    /// Tries to create a Foundation of the given version with the default allocator and error callbacks.
    /// Returns `None` if `phys_PxCreateFoundation` returns a null pointer.
    pub fn new<'a>(version: u32) -> Option<Owner<Self>> {
        unsafe {
            Foundation::from_raw(
                phys_PxCreateFoundation(
                    version,
                    get_default_allocator() as *mut PxAllocatorCallback,
                    get_default_error_callback() as *mut PxErrorCallback,
                )
            )
        }
    }

    pub(crate) fn from_raw(ptr: *mut physx_sys::PxFoundation) -> Option<Owner<Foundation>> {
        unsafe {
            Owner::from_raw(ptr as *mut Foundation)
        }
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
        unsafe {
            PxFoundation_release_mut(self.as_mut_ptr())
        }
    }
}