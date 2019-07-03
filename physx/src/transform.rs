// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created:  2 April 2019

#![warn(clippy::all)]
#![warn(rust_2018_idioms)]

/*!
This defines utility conversion functions from PhysX data types to glm datatypes
for easier usage.

All functions are on the form `SRC_to_TRG_TYPE`, e.g., `na_to_px_v3` is a
conversion from nalgebra_glm::Vector3 to PxVec3. Of special note is that we use
glm::Mat4 as the corresponding type for a PxTransform which is a (Quaternion,
Vector) pair.
*/

use nalgebra::Isometry3;
use nalgebra_glm as glm;
use physx_sys::{
    PxIdentity, PxQuat, PxQuat_new_3, PxTransform, PxTransform_new_2, PxTransform_new_4, PxVec3,
    PxVec3_new_3,
};

pub fn px_identity_tf() -> PxTransform {
    unsafe { PxTransform_new_2(PxIdentity) }
}

struct PxQuatWrap(PxQuat);
impl From<glm::Quat> for PxQuatWrap {
    /// Convert from an nalgebra isometry into a PxTransform
    fn from(other: glm::Quat) -> Self {
        PxQuatWrap(unsafe {
            PxQuat_new_3(
                other.coords.x,
                other.coords.y,
                other.coords.z,
                other.coords.w,
            )
        })
    }
}

impl Into<PxQuat> for PxQuatWrap {
    /// Unwrap helper
    fn into(self) -> PxQuat {
        self.0
    }
}

struct PxTransformWrap(PxTransform);
impl From<Isometry3<f32>> for PxTransformWrap {
    /// Convert from an nalgebra isometry into a PxTransform
    fn from(other: Isometry3<f32>) -> Self {
        let quat: glm::Quat = glm::convert(other.rotation);
        let quaternion: PxQuat = PxQuatWrap::from(quat).into();
        let trans = other.translation;
        PxTransformWrap(unsafe { PxTransform_new_4(trans.x, trans.y, trans.z, quaternion) })
    }
}

impl Into<PxTransform> for PxTransformWrap {
    /// Unwrap helper
    fn into(self) -> PxTransform {
        self.0
    }
}

/// Convert a glm::Mat4 to a PxTransform
pub fn na_to_px_tf(trans: glm::Mat4) -> PxTransform {
    let iso: Isometry3<f32> = glm::try_convert(trans).expect("non isometric transform");

    PxTransformWrap::from(iso).into()
}

/// Convert a reference to a glm::Mat4 to a PxTransform
pub fn na_to_px_tf_ref(trans: &glm::Mat4) -> PxTransform {
    let iso: Isometry3<f32> = glm::try_convert(*trans).expect("non isometric transform");

    PxTransformWrap::from(iso).into()
}

/// Convert a PxTransform to a glm::Mat4
pub fn px_to_na_tf(trans: PxTransform) -> glm::Mat4 {
    let translation = px_to_na_v3(trans.p);
    let quaternion = px_to_na_q(trans.q);

    nalgebra::Isometry3::from_parts(
        translation.into(),
        nalgebra::UnitQuaternion::new_normalize(quaternion),
    )
    .into()
}

/// Convert a PxQuat to a glm::Quat
#[inline(always)]
pub fn px_to_na_q(quat: PxQuat) -> glm::Quat {
    glm::quat(quat.x, quat.y, quat.z, quat.w)
}

/// Convert a PxQuat to a glm::Quat
#[inline(always)]
pub fn na_to_px_q(quat: glm::Quat) -> PxQuat {
    PxQuatWrap::from(quat).into()
}

/// Convert a PxVec3 to a glm::Vec3
#[inline(always)]
pub fn px_to_na_v3(pos: PxVec3) -> glm::Vec3 {
    glm::vec3(pos.x, pos.y, pos.z)
}

/// Convert a PxVec3 to a glm::Vec3
#[inline(always)]
pub fn na_to_px_v3(pos: glm::Vec3) -> PxVec3 {
    unsafe { PxVec3_new_3(pos.x, pos.y, pos.z) }
}
