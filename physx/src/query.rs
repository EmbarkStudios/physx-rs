// Author: Nick Caplinger <the.nick.caplinger@gmail.com>
// Copyright © 2020, Embark Studios, all rights reserved.
// Created: 14 December 2020

//! Scene queries are used to perform tests against the actors and geometry held in a scene.

use crate::{owner::Owner, traits::Class};
use physx_sys::{
    create_overlap_buffer, create_overlap_callback, create_raycast_buffer, create_raycast_callback,
    create_sweep_buffer, create_sweep_callback, delete_raycast_callback
};
use std::ffi::c_void;
use std::{slice, marker::PhantomData};

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

pub struct RaycastCallbackDefault;

impl RaycastCallback for RaycastCallbackDefault {
    fn process_touches(&mut self, touches: &[physx_sys::PxRaycastHit]) -> bool {
        unimplemented!()
    }
    fn finalize_query(&mut self) {
        unimplemented!()
    }
}

pub struct PxRaycastCallback<T: RaycastCallback> {
    pub(crate) obj: Option<Owner<physx_sys::PxRaycastCallback>>,
    phantom_user_callback: PhantomData<T>,
}

impl<T: RaycastCallback> Drop for PxRaycastCallback<T> {
    fn drop(&mut self) {
        if let Some(obj) = &mut self.obj {
            unsafe {
                delete_raycast_callback(obj.as_mut_ptr());
            }
        }
    }
}

impl<T: RaycastCallback> PxRaycastCallback<T> {

    // pub fn new(touch_buffer: Option<&mut [physx_sys::PxRaycastHit]>) -> Self {
    pub fn new() -> Self {
        unsafe {
            Self {
                obj: Owner::from_raw(
                    create_raycast_buffer()
                ),
                phantom_user_callback: PhantomData,
            }
        }
    }

    pub fn with_user_callbacks(user_callback: &mut T, touch_buffer: Option<&mut [physx_sys::PxRaycastHit]>) -> Self {
        use std::convert::TryInto;

        let (buffer_ptr, buffer_len) = touch_buffer
            .map(|v| (v.as_mut_ptr(), v.len()))
            .unwrap_or((std::ptr::null_mut(), 0));

        // FIXME replace unwrap
        let buffer_len = buffer_len.try_into().unwrap();

        unsafe {
            Self {
                obj: Owner::from_raw(
                    create_raycast_callback(
                        Self::process_touches,
                        Self::finalize_query,
                        buffer_ptr,
                        buffer_len,
                        user_callback as *mut _ as *mut c_void,
                    )
                ),
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
            if callback.touches != std::ptr::null_mut() && callback.nbTouches > 0 {
                unsafe {
                    return Some(std::slice::from_raw_parts(callback.touches, callback.nbTouches as usize));
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
            (&mut *(user_callback as *mut T)).process_touches(slice::from_raw_parts(buffer, num_hits as usize))
        }).unwrap_or(true)
    }

    /// Must not panic.
    unsafe extern "C" fn finalize_query(
        user_callback: *mut c_void,
    ) {
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

// /// A trait for creating custom raycast callbacks for PhysX.
// pub unsafe trait RaycastCallback {
//     unsafe fn get_raycast_hit(&mut self) -> Option<physx_sys::PxRaycastHit>;
//     // TODO
//     // unsafe fn get_raycast_touches(&mut self) -> Option<physx_sys::PxRaycastHit>;

//     /// # Safety
//     /// Must not panic.
//     unsafe extern "C" fn process_touches(
//         buffer: *const physx_sys::PxRaycastHit,
//         num_hits: u32,
//         user_data: *const c_void,
//     ) -> bool;

//     /// # Safety
//     /// Must not panic.
//     unsafe extern "C" fn finalize_query(user_data: *const c_void);

//     /// # Safety
//     /// Do not override this method.
//     unsafe fn into_px(&mut self) -> *mut physx_sys::PxRaycastCallback {
//         create_raycast_callback(
//             Self::process_touches,
//             Self::finalize_query,
//             std::ptr::null_mut(),
//             0,
//             Box::into_raw(Box::new(self)) as *mut c_void,
//         )
//     }
// }
