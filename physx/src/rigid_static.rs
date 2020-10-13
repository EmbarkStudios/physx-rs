// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 15 April 2019

#![warn(clippy::all)]

/*!

*/

use super::{px_type::*, rigid_actor::RigidActor};
use physx_macros::*;
use physx_sys::{PxRigidStatic, PxRigidStatic_getConcreteTypeName};

#[physx_type(inherit = "RigidActor")]
impl RigidStatic {
    pub fn new(px_link: *mut PxRigidStatic) -> Self {
        let mut _self = Self::from_ptr(px_link);
        _self.allocate_user_data();

        _self
    }

    /// Get the name of the real type referenced by this pointer, or None if the returned string is not valid
    pub fn get_concrete_type_name(&self) -> Option<&str> {
        unsafe {
            std::ffi::CStr::from_ptr(PxRigidStatic_getConcreteTypeName(self.get_raw()) as _)
                .to_str()
                .ok()
        }
    }
}
