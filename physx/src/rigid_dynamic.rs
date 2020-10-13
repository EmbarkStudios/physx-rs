// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 19 June 2019

#![warn(clippy::all)]

/*!
Wrapper implementation for PxRigidDynamic
*/

use super::{px_type::*, rigid_body::*};
use physx_macros::*;
use physx_sys::PxRigidDynamic;

#[physx_type(inherit = "RigidBody")]
impl RigidDynamic {
    pub fn new(ptr: *mut PxRigidDynamic) -> Self {
        let mut _self = Self { ptr };
        _self.allocate_user_data();
        _self
    }
}
