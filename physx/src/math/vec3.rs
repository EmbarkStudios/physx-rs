use crate::traits::Class;

use physx_sys::{
    PxVec3_abs, PxVec3_cross, PxVec3_dot, PxVec3_getNormalized, PxVec3_isFinite,
    PxVec3_isNormalized, PxVec3_isZero, PxVec3_magnitude, PxVec3_magnitudeSquared,
    PxVec3_maxElement, PxVec3_maximum, PxVec3_minElement, PxVec3_minimum, PxVec3_multiply,
    PxVec3_new_1, PxVec3_new_3, PxVec3_normalize_mut,
};

#[derive(Copy, Clone)]
#[repr(transparent)]
pub struct PxVec3 {
    pub(super) obj: physx_sys::PxVec3,
}

crate::DeriveClassForNewType!(PxVec3: PxVec3);

impl Default for PxVec3 {
    fn default() -> Self {
        unsafe { PxVec3_new_1(0).into() }
    }
}

impl From<physx_sys::PxVec3> for PxVec3 {
    fn from(vec3: physx_sys::PxVec3) -> Self {
        PxVec3 { obj: vec3 }
    }
}

impl From<PxVec3> for physx_sys::PxVec3 {
    fn from(value: PxVec3) -> Self {
        value.obj
    }
}

impl From<physx_sys::PxExtendedVec3> for PxVec3 {
    fn from(vec3: physx_sys::PxExtendedVec3) -> Self {
        PxVec3 {
            obj: physx_sys::PxVec3 {
                x: vec3.x as f32,
                y: vec3.y as f32,
                z: vec3.z as f32,
            },
        }
    }
}

impl From<PxVec3> for physx_sys::PxExtendedVec3 {
    fn from(value: PxVec3) -> Self {
        Self {
            x: value.obj.x as f64,
            y: value.obj.y as f64,
            z: value.obj.z as f64,
        }
    }
}

impl PxVec3 {
    pub fn x(&self) -> f32 {
        self.obj.x
    }

    pub fn y(&self) -> f32 {
        self.obj.y
    }

    pub fn z(&self) -> f32 {
        self.obj.z
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

    pub fn new(x: f32, y: f32, z: f32) -> PxVec3 {
        unsafe {
            PxVec3 {
                obj: PxVec3_new_3(x, y, z),
            }
        }
    }

    pub fn abs(&self) -> PxVec3 {
        unsafe { PxVec3_abs(self.as_ptr()).into() }
    }

    pub fn cross(&self, other: &PxVec3) -> PxVec3 {
        unsafe { PxVec3_cross(self.as_ptr(), other.as_ptr()).into() }
    }

    pub fn dot(&self, other: &PxVec3) -> f32 {
        unsafe { PxVec3_dot(self.as_ptr(), other.as_ptr()) }
    }

    pub fn get_normalized(&self) -> PxVec3 {
        unsafe { PxVec3_getNormalized(self.as_ptr()).into() }
    }

    pub fn is_finite(&self) -> bool {
        unsafe { PxVec3_isFinite(self.as_ptr()) }
    }

    pub fn is_normalized(&self) -> bool {
        unsafe { PxVec3_isNormalized(self.as_ptr()) }
    }

    pub fn is_zero(&self) -> bool {
        unsafe { PxVec3_isZero(self.as_ptr()) }
    }

    pub fn magnitude(&self) -> f32 {
        unsafe { PxVec3_magnitude(self.as_ptr()) }
    }

    pub fn magnitude_squared(&self) -> f32 {
        unsafe { PxVec3_magnitudeSquared(self.as_ptr()) }
    }

    pub fn max_element(&self) -> f32 {
        unsafe { PxVec3_maxElement(self.as_ptr()) }
    }

    pub fn maximum(&self, other: &PxVec3) -> PxVec3 {
        unsafe { PxVec3_maximum(self.as_ptr(), other.as_ptr()).into() }
    }

    pub fn min_element(&self) -> f32 {
        unsafe { PxVec3_minElement(self.as_ptr()) }
    }

    pub fn minimum(&self, other: &PxVec3) -> PxVec3 {
        unsafe { PxVec3_minimum(self.as_ptr(), other.as_ptr()).into() }
    }

    pub fn multiply(&self, other: &PxVec3) -> PxVec3 {
        unsafe { PxVec3_multiply(self.as_ptr(), other.as_ptr()).into() }
    }

    /// normalize in place and returns the original magnitude.
    pub fn normalize(&mut self) -> f32 {
        unsafe { PxVec3_normalize_mut(self.as_mut_ptr()) }
    }
}

unsafe impl Send for PxVec3 {}
unsafe impl Sync for PxVec3 {}
