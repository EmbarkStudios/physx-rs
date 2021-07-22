use crate::{math::PxVec3, traits::Class};

use physx_sys::{
    PxQuat_dot, PxQuat_getAngle, PxQuat_getAngle_1, PxQuat_getBasisVector0, PxQuat_getBasisVector1,
    PxQuat_getBasisVector2, PxQuat_getConjugate, PxQuat_getImaginaryPart, PxQuat_getNormalized,
    PxQuat_isFinite, PxQuat_isIdentity, PxQuat_isSane, PxQuat_isUnit, PxQuat_magnitude,
    PxQuat_magnitudeSquared, PxQuat_new_1, PxQuat_new_3, PxQuat_new_4, PxQuat_normalize_mut,
    PxQuat_rotate, PxQuat_rotateInv, PxQuat_toRadiansAndUnitAxis,
};

#[derive(Copy, Clone)]
#[repr(transparent)]
pub struct PxQuat {
    pub(super) obj: physx_sys::PxQuat,
}

crate::DeriveClassForNewType!(PxQuat: PxQuat);

impl Default for PxQuat {
    fn default() -> PxQuat {
        unsafe { PxQuat_new_1(0).into() }
    }
}

impl From<physx_sys::PxQuat> for PxQuat {
    fn from(quat: physx_sys::PxQuat) -> Self {
        Self { obj: quat }
    }
}

impl From<PxQuat> for physx_sys::PxQuat {
    fn from(value: PxQuat) -> Self {
        value.obj
    }
}

impl PxQuat {
    pub fn new(x: f32, y: f32, z: f32, w: f32) -> PxQuat {
        unsafe { PxQuat_new_3(x, y, z, w).into() }
    }

    pub fn x(&self) -> f32 {
        self.obj.x
    }

    pub fn y(&self) -> f32 {
        self.obj.y
    }

    pub fn z(&self) -> f32 {
        self.obj.z
    }

    pub fn w(&self) -> f32 {
        self.obj.w
    }

    pub fn x_mut(&mut self) -> &mut f32 {
        &mut self.obj.x
    }

    pub fn y_mut(&mut self) -> &mut f32 {
        &mut self.obj.y
    }

    pub fn z_mut(&mut self) -> &mut f32 {
        &mut self.obj.z
    }

    pub fn w_mut(&mut self) -> &mut f32 {
        &mut self.obj.w
    }

    pub fn dot(&self, other: &PxQuat) -> f32 {
        unsafe { PxQuat_dot(self.as_ptr(), other.as_ptr()) }
    }

    pub fn get_identity_angle(&self) -> f32 {
        unsafe { PxQuat_getAngle(self.as_ptr()) }
    }

    pub fn get_angle(&self, other: &PxQuat) -> f32 {
        unsafe { PxQuat_getAngle_1(self.as_ptr(), other.as_ptr()) }
    }

    pub fn get_basis_vector_x(&self) -> PxVec3 {
        unsafe { PxQuat_getBasisVector0(self.as_ptr()).into() }
    }

    pub fn get_basis_vector_y(&self) -> PxVec3 {
        unsafe { PxQuat_getBasisVector1(self.as_ptr()).into() }
    }

    pub fn get_basis_vector_z(&self) -> PxVec3 {
        unsafe { PxQuat_getBasisVector2(self.as_ptr()).into() }
    }

    pub fn get_conjugate(&self) -> PxQuat {
        unsafe { PxQuat_getConjugate(self.as_ptr()).into() }
    }

    pub fn get_imaginary_part(&self) -> PxVec3 {
        unsafe { PxQuat_getImaginaryPart(self.as_ptr()).into() }
    }

    pub fn get_normalized(&self) -> PxQuat {
        unsafe { PxQuat_getNormalized(self.as_ptr()).into() }
    }

    pub fn is_finite(&self) -> bool {
        unsafe { PxQuat_isFinite(self.as_ptr()) }
    }

    pub fn is_identity(&self) -> bool {
        unsafe { PxQuat_isIdentity(self.as_ptr()) }
    }

    pub fn is_sane(&self) -> bool {
        unsafe { PxQuat_isSane(self.as_ptr()) }
    }

    pub fn is_unit(&self) -> bool {
        unsafe { PxQuat_isUnit(self.as_ptr()) }
    }

    pub fn magnitude(&self) -> f32 {
        unsafe { PxQuat_magnitude(self.as_ptr()) }
    }

    pub fn magnitude_squared(&self) -> f32 {
        unsafe { PxQuat_magnitudeSquared(self.as_ptr()) }
    }

    /// Returns the magnitude of the quaternion before normalization.
    pub fn normalize(&mut self) -> f32 {
        unsafe { PxQuat_normalize_mut(self.as_mut_ptr()) }
    }

    /// Rotates the vector.
    pub fn rotate(&self, vector: &PxVec3) -> PxVec3 {
        unsafe { PxQuat_rotate(self.as_ptr(), vector.as_ptr()).into() }
    }

    pub fn rotate_inverse(&self, vector: &PxVec3) -> PxVec3 {
        unsafe { PxQuat_rotateInv(self.as_ptr(), vector.as_ptr()).into() }
    }

    /// returns the angle in radians and a normalized axis vector
    #[allow(clippy::wrong_self_convention)]
    pub fn to_angle_axis(&self) -> (f32, PxVec3) {
        let mut angle = 0.0;
        let mut axis = PxVec3::default();
        unsafe {
            PxQuat_toRadiansAndUnitAxis(self.as_ptr(), &mut angle, axis.as_mut_ptr());
        }
        (angle, axis)
    }

    pub fn from_angle_axis(angle: f32, axis: PxVec3) -> PxQuat {
        unsafe { PxQuat_new_4(angle, axis.as_ptr()).into() }
    }
}

unsafe impl Send for PxQuat {}
unsafe impl Sync for PxQuat {}
