// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created:  2 April 2019

#![warn(clippy::all)]

/*!
This defines utility conversion functions from PhysX data types to glm datatypes
for easier usage.

All functions are on the form `SRC_to_TRG_TYPE`, e.g., `gl_to_px_v3` is a
conversion from glam::Vec3 to PxVec3. Of special note is that we use
Mat4 as the corresponding type for a PxTransform which is a (Quaternion,
Vector) pair.
*/

use glam::{Mat4, Quat, Vec3};
use physx_sys::{
    PxIdentity, PxQuat, PxQuat_new_3, PxTransform, PxTransform_new_2, PxTransform_new_4, PxVec3,
    PxVec3_new_3,
};

pub fn px_identity_tf() -> PxTransform {
    unsafe { PxTransform_new_2(PxIdentity) }
}

struct PxQuatWrap(PxQuat);
impl From<Quat> for PxQuatWrap {
    fn from(other: Quat) -> Self {
        let (x, y, z, w) = other.into();
        PxQuatWrap(unsafe { PxQuat_new_3(x, y, z, w) })
    }
}

impl Into<PxQuat> for PxQuatWrap {
    /// Unwrap helper
    fn into(self) -> PxQuat {
        self.0
    }
}

/// Convert a Mat4 to a PxTransform
pub fn gl_to_px_tf(trans: Mat4) -> PxTransform {
    gl_to_px_tf_ref(&trans)
}

/// Convert a reference to a Mat4 to a PxTransform
pub fn gl_to_px_tf_ref(trans: &Mat4) -> PxTransform {
    let quat: PxQuatWrap = Quat::from_rotation_mat4(&trans).into();
    let (x, y, z, _) = trans.w_axis.into();
    unsafe { PxTransform_new_4(x, y, z, quat.0) }
}

/// Convert a PxTransform to a Mat4
pub fn px_to_gl_tf(trans: PxTransform) -> Mat4 {
    let translation = px_to_gl_v3(trans.p);
    let quaternion = px_to_gl_q(trans.q);
    Mat4::from_rotation_translation(quaternion, translation)
}

/// Convert a PxQuat to a Quat
#[inline(always)]
pub fn px_to_gl_q(quat: PxQuat) -> Quat {
    Quat::from_xyzw(quat.x, quat.y, quat.z, quat.w)
}

/// Convert a PxQuat to a Quat
#[inline(always)]
pub fn gl_to_px_q(quat: Quat) -> PxQuat {
    PxQuatWrap::from(quat).into()
}

/// Convert a PxVec3 to a Vec3
#[inline(always)]
pub fn px_to_gl_v3(pos: PxVec3) -> Vec3 {
    Vec3::new(pos.x, pos.y, pos.z)
}

/// Convert a PxVec3 to a Vec3
#[inline(always)]
pub fn gl_to_px_v3(pos: Vec3) -> PxVec3 {
    let (x, y, z) = pos.into();
    unsafe { PxVec3_new_3(x, y, z) }
}
