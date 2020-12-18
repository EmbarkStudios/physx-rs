// Author: Nick Caplinger <the.nick.caplinger@gmail.com>
// Copyright © 2020, Embark Studios, all rights reserved.
// Created: 14 December 2020

//! Scene queries are used to perform tests against the actors and geometry held in a scene.

use crate::{owner::Owner, traits::Class};
use physx_sys::{
    create_overlap_buffer, create_overlap_callback, create_raycast_buffer, create_raycast_callback,
    create_sweep_buffer, create_sweep_callback, delete_overlap_callback, delete_raycast_callback,
    delete_sweep_callback,
};
use std::ffi::c_void;
use std::{marker::PhantomData, slice};

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

// RAYCAST CALLBACKS

pub struct RaycastCallbackDefault;

impl RaycastCallback for RaycastCallbackDefault {
    fn process_touches(&mut self, _touches: &[physx_sys::PxRaycastHit]) -> bool {
        unimplemented!()
    }
    fn finalize_query(&mut self) {
        unimplemented!()
    }
}

pub struct PxRaycastCallback<'buffer, T: RaycastCallback> {
    pub(crate) obj: Option<Owner<physx_sys::PxRaycastCallback>>,
    phantom_touch_buffer: PhantomData<Option<&'buffer mut [physx_sys::PxRaycastHit]>>,
    phantom_user_callback: PhantomData<T>,
}

impl<'buffer, T: RaycastCallback> Drop for PxRaycastCallback<'buffer, T> {
    fn drop(&mut self) {
        if let Some(obj) = &mut self.obj {
            unsafe {
                delete_raycast_callback(obj.as_mut_ptr());
            }
        }
    }
}

impl<'buffer, T: RaycastCallback> Default for PxRaycastCallback<'buffer, T> {
    fn default() -> Self {
        unsafe {
            Self {
                obj: Owner::from_raw(create_raycast_buffer()),
                phantom_touch_buffer: PhantomData,
                phantom_user_callback: PhantomData,
            }
        }
    }
}

impl<'buffer, T: RaycastCallback> PxRaycastCallback<'buffer, T> {
    pub fn with_user_callbacks(
        user_callback: &mut T,
        touch_buffer: Option<&'buffer mut [physx_sys::PxRaycastHit]>,
    ) -> Self {
        use std::convert::TryInto;

        let (buffer_ptr, buffer_len) = touch_buffer
            .map(|v| (v.as_mut_ptr(), v.len()))
            .unwrap_or((std::ptr::null_mut(), 0));

        // FIXME replace unwrap
        let buffer_len = buffer_len.try_into().unwrap();

        unsafe {
            Self {
                obj: Owner::from_raw(create_raycast_callback(
                    Self::process_touches,
                    Self::finalize_query,
                    buffer_ptr,
                    buffer_len,
                    user_callback as *mut _ as *mut c_void,
                )),
                phantom_touch_buffer: PhantomData,
                phantom_user_callback: PhantomData,
            }
        }
    }

    pub fn get_blocking_hit(&self) -> Option<&physx_sys::PxRaycastHit> {
        if let Some(obj) = &self.obj {
            let callback = obj.as_ref();
            if callback.hasBlock {
                return Some(&callback.block);
            }
        }

        None
    }

    pub fn get_touching_hits(&self) -> Option<&[physx_sys::PxRaycastHit]> {
        if let Some(obj) = &self.obj {
            let callback = obj.as_ref();
            if !callback.touches.is_null() && callback.nbTouches > 0 {
                unsafe {
                    return Some(std::slice::from_raw_parts(
                        callback.touches,
                        callback.nbTouches as usize,
                    ));
                }
            }
        }

        None
    }

    /// Must not panic.
    unsafe extern "C" fn process_touches(
        buffer: *const physx_sys::PxRaycastHit,
        num_hits: u32,
        user_callback: *mut c_void,
    ) -> bool {
        std::panic::catch_unwind(|| {
            (&mut *(user_callback as *mut T))
                .process_touches(slice::from_raw_parts(buffer, num_hits as usize))
        })
        .unwrap_or(true)
    }

    /// Must not panic.
    unsafe extern "C" fn finalize_query(user_callback: *mut c_void) {
        let _explicitly_ignored = std::panic::catch_unwind(|| {
            (&mut *(user_callback as *mut T)).finalize_query();
        });
    }
}

/// A safe wrapper around raycast PhysX callbacks
pub trait RaycastCallback {
    fn process_touches(&mut self, touches: &[physx_sys::PxRaycastHit]) -> bool;
    fn finalize_query(&mut self);
}

// SWEEP CALLBACKS

pub struct SweepCallbackDefault;

impl SweepCallback for SweepCallbackDefault {
    fn process_touches(&mut self, _touches: &[physx_sys::PxSweepHit]) -> bool {
        unimplemented!()
    }
    fn finalize_query(&mut self) {
        unimplemented!()
    }
}

pub struct PxSweepCallback<'buffer, T: SweepCallback> {
    pub(crate) obj: Option<Owner<physx_sys::PxSweepCallback>>,
    phantom_touch_buffer: PhantomData<Option<&'buffer mut [physx_sys::PxSweepHit]>>,
    phantom_user_callback: PhantomData<T>,
}

impl<'buffer, T: SweepCallback> Drop for PxSweepCallback<'buffer, T> {
    fn drop(&mut self) {
        if let Some(obj) = &mut self.obj {
            unsafe {
                delete_sweep_callback(obj.as_mut_ptr());
            }
        }
    }
}

impl<'buffer, T: SweepCallback> Default for PxSweepCallback<'buffer, T> {
    fn default() -> Self {
        unsafe {
            Self {
                obj: Owner::from_raw(create_sweep_buffer()),
                phantom_touch_buffer: PhantomData,
                phantom_user_callback: PhantomData,
            }
        }
    }
}

impl<'buffer, T: SweepCallback> PxSweepCallback<'buffer, T> {
    pub fn with_user_callbacks(
        user_callback: &mut T,
        touch_buffer: Option<&'buffer mut [physx_sys::PxSweepHit]>,
    ) -> Self {
        use std::convert::TryInto;

        let (buffer_ptr, buffer_len) = touch_buffer
            .map(|v| (v.as_mut_ptr(), v.len()))
            .unwrap_or((std::ptr::null_mut(), 0));

        // FIXME replace unwrap
        let buffer_len = buffer_len.try_into().unwrap();

        unsafe {
            Self {
                obj: Owner::from_raw(create_sweep_callback(
                    Self::process_touches,
                    Self::finalize_query,
                    buffer_ptr,
                    buffer_len,
                    user_callback as *mut _ as *mut c_void,
                )),
                phantom_touch_buffer: PhantomData,
                phantom_user_callback: PhantomData,
            }
        }
    }

    pub fn get_blocking_hit(&self) -> Option<&physx_sys::PxSweepHit> {
        if let Some(obj) = &self.obj {
            let callback = obj.as_ref();
            if callback.hasBlock {
                return Some(&callback.block);
            }
        }

        None
    }

    pub fn get_touching_hits(&self) -> Option<&[physx_sys::PxSweepHit]> {
        if let Some(obj) = &self.obj {
            let callback = obj.as_ref();
            if !callback.touches.is_null() && callback.nbTouches > 0 {
                unsafe {
                    return Some(std::slice::from_raw_parts(
                        callback.touches,
                        callback.nbTouches as usize,
                    ));
                }
            }
        }

        None
    }

    /// Must not panic.
    unsafe extern "C" fn process_touches(
        buffer: *const physx_sys::PxSweepHit,
        num_hits: u32,
        user_callback: *mut c_void,
    ) -> bool {
        std::panic::catch_unwind(|| {
            (&mut *(user_callback as *mut T))
                .process_touches(slice::from_raw_parts(buffer, num_hits as usize))
        })
        .unwrap_or(true)
    }

    /// Must not panic.
    unsafe extern "C" fn finalize_query(user_callback: *mut c_void) {
        let _explicitly_ignored = std::panic::catch_unwind(|| {
            (&mut *(user_callback as *mut T)).finalize_query();
        });
    }
}

/// A safe wrapper around sweep PhysX callbacks
pub trait SweepCallback {
    fn process_touches(&mut self, touches: &[physx_sys::PxSweepHit]) -> bool;
    fn finalize_query(&mut self);
}

// OVERLAP CALLBACKS

pub struct OverlapCallbackDefault;

impl OverlapCallback for OverlapCallbackDefault {
    fn process_touches(&mut self, _touches: &[physx_sys::PxOverlapHit]) -> bool {
        unimplemented!()
    }
    fn finalize_query(&mut self) {
        unimplemented!()
    }
}

pub struct PxOverlapCallback<'buffer, T: OverlapCallback> {
    pub(crate) obj: Option<Owner<physx_sys::PxOverlapCallback>>,
    phantom_touch_buffer: PhantomData<Option<&'buffer mut [physx_sys::PxOverlapHit]>>,
    phantom_user_callback: PhantomData<T>,
}

impl<'buffer, T: OverlapCallback> Drop for PxOverlapCallback<'buffer, T> {
    fn drop(&mut self) {
        if let Some(obj) = &mut self.obj {
            unsafe {
                delete_overlap_callback(obj.as_mut_ptr());
            }
        }
    }
}

impl<'buffer, T: OverlapCallback> Default for PxOverlapCallback<'buffer, T> {
    fn default() -> Self {
        unsafe {
            Self {
                obj: Owner::from_raw(create_overlap_buffer()),
                phantom_touch_buffer: PhantomData,
                phantom_user_callback: PhantomData,
            }
        }
    }
}

impl<'buffer, T: OverlapCallback> PxOverlapCallback<'buffer, T> {
    pub fn with_user_callbacks(
        user_callback: &mut T,
        touch_buffer: Option<&'buffer mut [physx_sys::PxOverlapHit]>,
    ) -> Self {
        use std::convert::TryInto;

        let (buffer_ptr, buffer_len) = touch_buffer
            .map(|v| (v.as_mut_ptr(), v.len()))
            .unwrap_or((std::ptr::null_mut(), 0));

        // FIXME replace unwrap
        let buffer_len = buffer_len.try_into().unwrap();

        unsafe {
            Self {
                obj: Owner::from_raw(create_overlap_callback(
                    Self::process_touches,
                    Self::finalize_query,
                    buffer_ptr,
                    buffer_len,
                    user_callback as *mut _ as *mut c_void,
                )),
                phantom_touch_buffer: PhantomData,
                phantom_user_callback: PhantomData,
            }
        }
    }

    pub fn get_blocking_hit(&self) -> Option<&physx_sys::PxOverlapHit> {
        if let Some(obj) = &self.obj {
            let callback = obj.as_ref();
            if callback.hasBlock {
                return Some(&callback.block);
            }
        }

        None
    }

    pub fn get_touching_hits(&self) -> Option<&[physx_sys::PxOverlapHit]> {
        if let Some(obj) = &self.obj {
            let callback = obj.as_ref();
            if !callback.touches.is_null() && callback.nbTouches > 0 {
                unsafe {
                    return Some(std::slice::from_raw_parts(
                        callback.touches,
                        callback.nbTouches as usize,
                    ));
                }
            }
        }

        None
    }

    /// Must not panic.
    unsafe extern "C" fn process_touches(
        buffer: *const physx_sys::PxOverlapHit,
        num_hits: u32,
        user_callback: *mut c_void,
    ) -> bool {
        std::panic::catch_unwind(|| {
            (&mut *(user_callback as *mut T))
                .process_touches(slice::from_raw_parts(buffer, num_hits as usize))
        })
        .unwrap_or(true)
    }

    /// Must not panic.
    unsafe extern "C" fn finalize_query(user_callback: *mut c_void) {
        let _explicitly_ignored = std::panic::catch_unwind(|| {
            (&mut *(user_callback as *mut T)).finalize_query();
        });
    }
}

/// A safe wrapper around overlap PhysX callbacks
pub trait OverlapCallback {
    fn process_touches(&mut self, touches: &[physx_sys::PxOverlapHit]) -> bool;
    fn finalize_query(&mut self);
}
