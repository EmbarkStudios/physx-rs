// Author: Nick Caplinger <the.nick.caplinger@gmail.com>
// Copyright © 2020, Embark Studios, all rights reserved.
// Created: 14 December 2020

//! Scene queries are used to perform tests against the actors and geometry held in a scene.

use crate::{owner::Owner, traits::Class};
use physx_sys::{
    create_overlap_buffer, create_overlap_callback, create_raycast_buffer, create_raycast_callback,
    create_sweep_buffer, create_sweep_callback,
};
use std::ffi::c_void;

#[repr(transparent)]
pub struct PxQueryFilterData {
    pub(crate) obj: physx_sys::PxQueryFilterData,
}

crate::DeriveClassForNewType!(PxQueryFilterData: PxQueryFilterData);

impl Default for PxQueryFilterData {
    fn default() -> Self {
        unsafe { physx_sys::PxQueryFilterData_new().into() }
    }
}

impl From<physx_sys::PxQueryFilterData> for PxQueryFilterData {
    fn from(data: physx_sys::PxQueryFilterData) -> Self {
        PxQueryFilterData { obj: data }
    }
}

impl Into<physx_sys::PxQueryFilterData> for PxQueryFilterData {
    fn into(self) -> physx_sys::PxQueryFilterData {
        self.obj
    }
}

#[repr(transparent)]
pub struct PxRaycastCallback {
    pub obj: Owner<physx_sys::PxRaycastCallback>,
}

#[repr(transparent)]
pub struct PxRaycastBuffer(PxRaycastCallback);

unsafe impl Class<PxRaycastCallback> for PxRaycastBuffer {
    fn as_ptr(&self) -> *const PxRaycastCallback {
        self.0.obj.as_ptr() as *const _ as *const _
    }
    fn as_mut_ptr(&mut self) -> *mut PxRaycastCallback {
        self.0.obj.as_mut_ptr() as *mut _ as *mut _
    }
}

unsafe impl Class<physx_sys::PxRaycastCallback> for PxRaycastBuffer {
    fn as_ptr(&self) -> *const physx_sys::PxRaycastCallback {
        self.0.obj.as_ptr() as *const _ as *const _
    }
    fn as_mut_ptr(&mut self) -> *mut physx_sys::PxRaycastCallback {
        self.0.obj.as_mut_ptr() as *mut _ as *mut _
    }
}

unsafe impl RaycastCallback for PxRaycastBuffer {
    unsafe fn new() -> Self {
        Self(PxRaycastCallback {
            obj: Owner::from_raw(create_raycast_buffer()).unwrap(),
        })
    }

    unsafe fn get_raycast_hit(&mut self) -> Option<physx_sys::PxRaycastHit> {
        Some(self.0.obj.block)
    }

    unsafe extern "C" fn process_touches(
        _buffer: *const physx_sys::PxRaycastHit,
        _num_hits: u32,
        _user_data: *const c_void,
    ) -> bool {
        // Unused by this impl
        false
    }

    unsafe extern "C" fn finalize_query(_user_data: *const c_void) {
        // Unused by this impl
    }

    unsafe fn into_px(&mut self) -> *mut physx_sys::PxRaycastCallback {
        self.0.obj.as_mut_ptr()
    }
}

/// A trait for creating custom raycast callbacks for PhysX.
pub unsafe trait RaycastCallback: Sized {
    unsafe fn new() -> Self;
    unsafe fn get_raycast_hit(&mut self) -> Option<physx_sys::PxRaycastHit>;

    /// # Safety
    /// Must not panic.
    unsafe extern "C" fn process_touches(
        buffer: *const physx_sys::PxRaycastHit,
        num_hits: u32,
        user_data: *const c_void,
    ) -> bool;

    /// # Safety
    /// Must not panic.
    unsafe extern "C" fn finalize_query(user_data: *const c_void);

    /// # Safety
    /// Do not override this method.
    unsafe fn into_px(&mut self) -> *mut physx_sys::PxRaycastCallback {
        create_raycast_callback(
            Self::process_touches,
            Self::finalize_query,
            Box::into_raw(Box::new(self)) as *mut c_void,
        )
    }
}

#[repr(transparent)]
pub struct PxSweepCallback {
    pub obj: Owner<physx_sys::PxSweepCallback>,
}

#[repr(transparent)]
pub struct PxSweepBuffer(PxSweepCallback);

unsafe impl Class<PxSweepCallback> for PxSweepBuffer {
    fn as_ptr(&self) -> *const PxSweepCallback {
        self.0.obj.as_ptr() as *const _ as *const _
    }
    fn as_mut_ptr(&mut self) -> *mut PxSweepCallback {
        self.0.obj.as_mut_ptr() as *mut _ as *mut _
    }
}

unsafe impl Class<physx_sys::PxSweepCallback> for PxSweepBuffer {
    fn as_ptr(&self) -> *const physx_sys::PxSweepCallback {
        self.0.obj.as_ptr() as *const _ as *const _
    }
    fn as_mut_ptr(&mut self) -> *mut physx_sys::PxSweepCallback {
        self.0.obj.as_mut_ptr() as *mut _ as *mut _
    }
}

unsafe impl SweepCallback for PxSweepBuffer {
    unsafe fn new() -> Self {
        Self(PxSweepCallback {
            obj: Owner::from_raw(create_sweep_buffer()).unwrap(),
        })
    }

    unsafe fn get_sweep_hit(&mut self) -> Option<physx_sys::PxSweepHit> {
        Some(self.0.obj.block)
    }

    unsafe extern "C" fn process_touches(
        _buffer: *const physx_sys::PxSweepHit,
        _num_hits: u32,
        _user_data: *const c_void,
    ) -> bool {
        // Unused by this impl
        false
    }

    unsafe extern "C" fn finalize_query(_user_data: *const c_void) {
        // Unused by this impl
    }

    unsafe fn into_px(&mut self) -> *mut physx_sys::PxSweepCallback {
        self.0.obj.as_mut_ptr()
    }
}

/// A trait for creating custom sweep callbacks for PhysX.
pub unsafe trait SweepCallback: Sized {
    unsafe fn new() -> Self;
    unsafe fn get_sweep_hit(&mut self) -> Option<physx_sys::PxSweepHit>;

    /// # Safety
    /// Must not panic.
    unsafe extern "C" fn process_touches(
        buffer: *const physx_sys::PxSweepHit,
        num_hits: u32,
        user_data: *const c_void,
    ) -> bool;

    /// # Safety
    /// Must not panic.
    unsafe extern "C" fn finalize_query(user_data: *const c_void);

    /// # Safety
    /// Do not override this method.
    unsafe fn into_px(&mut self) -> *mut physx_sys::PxSweepCallback {
        create_sweep_callback(
            Self::process_touches,
            Self::finalize_query,
            Box::into_raw(Box::new(self)) as *mut c_void,
        )
    }
}

#[repr(transparent)]
pub struct PxOverlapCallback {
    pub obj: Owner<physx_sys::PxOverlapCallback>,
}

#[repr(transparent)]
pub struct PxOverlapBuffer(PxOverlapCallback);

unsafe impl Class<PxOverlapCallback> for PxOverlapBuffer {
    fn as_ptr(&self) -> *const PxOverlapCallback {
        self.0.obj.as_ptr() as *const _ as *const _
    }
    fn as_mut_ptr(&mut self) -> *mut PxOverlapCallback {
        self.0.obj.as_mut_ptr() as *mut _ as *mut _
    }
}

unsafe impl Class<physx_sys::PxOverlapCallback> for PxOverlapBuffer {
    fn as_ptr(&self) -> *const physx_sys::PxOverlapCallback {
        self.0.obj.as_ptr() as *const _ as *const _
    }
    fn as_mut_ptr(&mut self) -> *mut physx_sys::PxOverlapCallback {
        self.0.obj.as_mut_ptr() as *mut _ as *mut _
    }
}

unsafe impl OverlapCallback for PxOverlapBuffer {
    unsafe fn new() -> Self {
        Self(PxOverlapCallback {
            obj: Owner::from_raw(create_overlap_buffer()).unwrap(),
        })
    }

    unsafe fn get_overlap_hit(&mut self) -> Option<physx_sys::PxOverlapHit> {
        Some(self.0.obj.block)
    }

    unsafe extern "C" fn process_touches(
        _buffer: *const physx_sys::PxOverlapHit,
        _num_hits: u32,
        _user_data: *const c_void,
    ) -> bool {
        // Unused by this impl
        false
    }

    unsafe extern "C" fn finalize_query(_user_data: *const c_void) {
        // Unused by this impl
    }

    unsafe fn into_px(&mut self) -> *mut physx_sys::PxOverlapCallback {
        self.0.obj.as_mut_ptr()
    }
}

/// A trait for creating custom overlap callbacks for PhysX.
pub unsafe trait OverlapCallback: Sized {
    unsafe fn new() -> Self;
    unsafe fn get_overlap_hit(&mut self) -> Option<physx_sys::PxOverlapHit>;

    /// # Safety
    /// Must not panic.
    unsafe extern "C" fn process_touches(
        buffer: *const physx_sys::PxOverlapHit,
        num_hits: u32,
        user_data: *const c_void,
    ) -> bool;

    /// # Safety
    /// Must not panic.
    unsafe extern "C" fn finalize_query(user_data: *const c_void);

    /// # Safety
    /// Do not override this method.
    unsafe fn into_px(&mut self) -> *mut physx_sys::PxOverlapCallback {
        create_overlap_callback(
            Self::process_touches,
            Self::finalize_query,
            Box::into_raw(Box::new(self)) as *mut c_void,
        )
    }
}
