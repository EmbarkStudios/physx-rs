// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 12 June 2019

#![warn(clippy::all)]

/*!

*/

pub use super::traits::GetRaw;
use std::ops::{Deref, DerefMut};

pub trait PxPtr {}

pub struct PxType<T> {
    pub ptr: *mut T,
}

/// Blanket implementation of GetRaw for all PxTypes
impl<U> GetRaw<U> for PxType<U> {
    fn get_raw(&self) -> *const U {
        self.ptr
    }

    fn get_raw_mut(&mut self) -> *mut U {
        self.ptr
    }
}

impl<T> PxType<T> {
    pub fn from_ptr(ptr: *mut T) -> Self {
        Self { ptr }
    }

    pub fn as_ptr<U>(&self) -> &PxType<U>
    where
        Self: Deref<Target = PxType<U>>,
    {
        unsafe { &*(self as *const PxType<T> as *const PxType<U>) }
    }

    pub fn as_ptr_mut<U>(&mut self) -> &mut PxType<U>
    where
        Self: DerefMut<Target = PxType<U>>,
    {
        unsafe { &mut *(self as *mut PxType<T> as *mut PxType<U>) }
    }
}

impl<T, U> PartialEq<PxType<U>> for PxType<T> {
    fn eq(&self, other: &PxType<U>) -> bool {
        self.ptr as usize == other.ptr as usize
    }
}

impl<T, U: PxPtr> PartialEq<*const U> for PxType<T> {
    fn eq(&self, other: &*const U) -> bool {
        self.ptr as usize == *other as usize
    }
}
