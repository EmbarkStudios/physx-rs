// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 17 June 2019

#![warn(clippy::all)]

/*!

*/

mod transform;
pub use transform::PxTransform;
mod quat;
pub use quat::PxQuat;
mod vec3;
pub use vec3::PxVec3;
#[cfg(feature = "glam")]
mod glam;

#[derive(Copy, Clone)]
#[repr(transparent)]
pub struct PxExtendedVec3 {
    obj: physx_sys::PxExtendedVec3,
}

crate::DeriveClassForNewType!(PxExtendedVec3: PxExtendedVec3);

impl From<(f64, f64, f64)> for PxExtendedVec3 {
    fn from(vec: (f64, f64, f64)) -> Self {
        Self {
            obj: physx_sys::PxExtendedVec3 {
                x: vec.0,
                y: vec.1,
                z: vec.2,
            },
        }
    }
}

impl From<physx_sys::PxExtendedVec3> for PxExtendedVec3 {
    fn from(bounds: physx_sys::PxExtendedVec3) -> Self {
        PxExtendedVec3 { obj: bounds }
    }
}

impl From<PxExtendedVec3> for physx_sys::PxExtendedVec3 {
    fn from(value: PxExtendedVec3) -> Self {
        value.obj
    }
}

use crate::traits::Class;

#[repr(transparent)]
pub struct PxBounds3 {
    obj: physx_sys::PxBounds3,
}

impl PxBounds3 {
    /// Creates largest bounds that avoid floating point exceptions.
    pub fn max_bounds_extents() -> Self {
        unsafe {
            physx_sys::PxBounds3_new_1(
                &physx_sys::PxVec3_new_2(-f32::MAX / 4.0),
                &physx_sys::PxVec3_new_2(f32::MAX / 4.0),
            )
            .into()
        }
    }
}

crate::DeriveClassForNewType!(PxBounds3: PxBounds3);

impl From<physx_sys::PxBounds3> for PxBounds3 {
    fn from(bounds: physx_sys::PxBounds3) -> Self {
        PxBounds3 { obj: bounds }
    }
}

impl From<PxBounds3> for physx_sys::PxBounds3 {
    fn from(value: PxBounds3) -> Self {
        value.obj
    }
}

impl Default for PxBounds3 {
    fn default() -> Self {
        Self::max_bounds_extents()
    }
}
