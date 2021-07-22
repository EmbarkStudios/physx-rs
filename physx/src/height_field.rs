// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 11 April 2019

#![warn(clippy::all)]

/*!

*/
use crate::{owner::Owner, traits::Class};
use enumflags2::bitflags;
use physx_sys::PxHeightField_release_mut;

pub const HEIGHT_SCALE: f32 = 1.0;
pub const XZ_SCALE: f32 = 100.0;

#[repr(transparent)]
pub struct HeightField {
    obj: physx_sys::PxHeightField,
}

crate::DeriveClassForNewType!(HeightField: PxHeightField, PxBase);

impl HeightField {
    /// # Safety
    /// Owner's own the pointer they wrap, using the pointer after dropping the Owner,
    /// or creating multiple Owners from the same pointer will cause UB.  Use `into_ptr` to
    /// retrieve the pointer and consume the Owner without dropping the pointee.
    pub(crate) unsafe fn from_raw(ptr: *mut physx_sys::PxHeightField) -> Option<Owner<Self>> {
        Owner::from_raw(ptr as *mut Self)
    }
}

impl Drop for HeightField {
    fn drop(&mut self) {
        unsafe { PxHeightField_release_mut(self.as_mut_ptr()) }
    }
}

#[derive(Debug, Copy, Clone)]
#[repr(u32)]
pub enum HeightFieldFormat {
    S16tm = 1,
}

#[bitflags]
#[derive(Debug, Copy, Clone)]
#[repr(u16)]
pub enum HeightFieldFlag {
    NoboundaryEdges = 1,
}
