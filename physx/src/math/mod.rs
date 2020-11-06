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

impl From<glam::Vec3> for PxExtendedVec3 {
    fn from(vec: glam::Vec3) -> Self {
        Self {
            obj: physx_sys::PxExtendedVec3 {
                x: vec.x() as f64,
                y: vec.y() as f64,
                z: vec.z() as f64,
            },
        }
    }
}

impl From<physx_sys::PxExtendedVec3> for PxExtendedVec3 {
    fn from(bounds: physx_sys::PxExtendedVec3) -> Self {
        PxExtendedVec3 { obj: bounds }
    }
}

impl Into<physx_sys::PxExtendedVec3> for PxExtendedVec3 {
    fn into(self) -> physx_sys::PxExtendedVec3 {
        self.obj
    }
}

use crate::traits::Class;

#[repr(transparent)]
pub struct PxBounds3 {
    obj: physx_sys::PxBounds3,
}

crate::DeriveClassForNewType!(PxBounds3: PxBounds3);

impl From<physx_sys::PxBounds3> for PxBounds3 {
    fn from(bounds: physx_sys::PxBounds3) -> Self {
        PxBounds3 { obj: bounds }
    }
}

impl Into<physx_sys::PxBounds3> for PxBounds3 {
    fn into(self) -> physx_sys::PxBounds3 {
        self.obj
    }
}
