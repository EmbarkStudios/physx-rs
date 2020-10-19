// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 10 April 2019

#![warn(clippy::all)]

/*!
Wrapper for PxFoundation class
 */

use super::px_type::*;
use super::traits::*;
use enumflags2::BitFlags;
use physx_macros::*;
use physx_sys::*;

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

#[physx_type]
impl Foundation {
    pub fn new(version: u32) -> Self {
        let px_foundation = unsafe {
            phys_PxCreateFoundation(
                version,
                get_default_allocator() as *mut PxAllocatorCallback,
                get_default_error_callback() as *mut PxErrorCallback,
            )
        };
        Self::from_ptr(px_foundation)
    }

    pub fn new_with_alloc(version: u32, allocator: *mut PxAllocatorCallback) -> Self {
        let px_foundation = unsafe {
            phys_PxCreateFoundation(
                version,
                allocator,
                get_default_error_callback() as *mut PxErrorCallback,
            )
        };
        Self::from_ptr(px_foundation)
    }

    pub fn get_error_callback(&mut self) -> *mut PxErrorCallback {
        unsafe { PxFoundation_getErrorCallback_mut(self.get_raw_mut()) }
    }

    pub fn set_error_level(&mut self, mask: BitFlags<ErrorCode>) {
        unsafe { PxFoundation_setErrorLevel_mut(self.get_raw_mut(), mask.bits() as i32) }
    }

    pub fn get_error_level(&self) -> BitFlags<ErrorCode> {
        unsafe {
            BitFlags::from_bits(PxFoundation_getErrorLevel(self.get_raw()) as u32)
                .expect("got invalid bits for error flags")
        }
    }

    pub fn get_allocator_callback(&mut self) -> *mut PxAllocatorCallback {
        unsafe { PxFoundation_getAllocatorCallback_mut(self.get_raw_mut()) }
    }

    pub fn get_report_allocation_names(&self) -> bool {
        unsafe { PxFoundation_getReportAllocationNames(self.get_raw()) }
    }

    pub fn set_report_allocation_names(&mut self, value: bool) {
        unsafe { PxFoundation_setReportAllocationNames_mut(self.get_raw_mut(), value) }
    }
}

impl Releasable for Foundation {
    fn release(&mut self) {
        unsafe { PxFoundation_release_mut(self.get_raw_mut()) }
    }
}
