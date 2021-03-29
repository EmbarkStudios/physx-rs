use crate::{
    math::{PxQuat, PxVec3},
    traits::Class,
};

//pub use physx_sys::PxTransform;
use physx_sys::{
    PxPlane, PxTransform_getInverse, PxTransform_getNormalized, PxTransform_inverseTransform,
    PxTransform_isFinite, PxTransform_isSane, PxTransform_isValid, PxTransform_new_1,
    PxTransform_new_2, PxTransform_new_3, PxTransform_new_5, PxTransform_rotate,
    PxTransform_rotateInv, PxTransform_transform, PxTransform_transformInv,
    PxTransform_transformInv_1, PxTransform_transform_1, PxTransform_transform_2,
};

#[derive(Copy, Clone)]
#[repr(transparent)]
pub struct PxTransform {
    obj: physx_sys::PxTransform,
}

crate::DeriveClassForNewType!(PxTransform: PxTransform);

impl Default for PxTransform {
    fn default() -> Self {
        unsafe {
            Self {
                obj: PxTransform_new_2(0),
            }
        }
    }
}

impl From<physx_sys::PxTransform> for PxTransform {
    fn from(transform: physx_sys::PxTransform) -> Self {
        PxTransform { obj: transform }
    }
}

impl From<PxTransform> for physx_sys::PxTransform {
    fn from(value: PxTransform) -> Self {
        value.obj
    }
}

impl PxTransform {
    pub fn translation(&self) -> PxVec3 {
        self.obj.p.into()
    }

    pub fn rotation(&self) -> PxQuat {
        self.obj.q.into()
    }

    pub fn translation_mut(&mut self) -> &mut PxVec3 {
        // Safety: PxVec3 is a new-type wrapper around physx_sys::PxVec3, they are identical.
        unsafe { &mut *(&mut self.obj.p as *mut _ as *mut _) }
    }

    pub fn rotation_mut(&mut self) -> &mut PxQuat {
        // Safety: PxQuat is a new-type wrapper around physx_sys::PxQuat, they are identical.
        unsafe { &mut *(&mut self.obj.q as *mut _ as *mut _) }
    }

    pub fn from_translation(translation: &PxVec3) -> PxTransform {
        unsafe { PxTransform_new_1(translation.as_ptr()).into() }
    }

    pub fn from_rotation(rotation: &PxQuat) -> PxTransform {
        unsafe { PxTransform_new_3(rotation.as_ptr()).into() }
    }

    pub fn from_translation_rotation(translation: &PxVec3, rotation: &PxQuat) -> PxTransform {
        unsafe { PxTransform_new_5(translation.as_ptr(), rotation.as_ptr()).into() }
    }

    pub fn get_inverse(&self) -> PxTransform {
        unsafe { PxTransform_getInverse(self.as_ptr()).into() }
    }

    pub fn get_normalized(&self) -> PxTransform {
        unsafe { PxTransform_getNormalized(self.as_ptr()).into() }
    }

    pub fn is_finite(&self) -> bool {
        unsafe { PxTransform_isFinite(self.as_ptr()) }
    }

    pub fn is_sane(&self) -> bool {
        unsafe { PxTransform_isSane(self.as_ptr()) }
    }

    pub fn is_valid(&self) -> bool {
        unsafe { PxTransform_isValid(self.as_ptr()) }
    }

    pub fn rotate(&self, vector: &PxVec3) -> PxVec3 {
        unsafe { PxTransform_rotate(self.as_ptr(), vector.as_ptr()).into() }
    }

    pub fn rotate_inv(&self, vector: &PxVec3) -> PxVec3 {
        unsafe { PxTransform_rotateInv(self.as_ptr(), vector.as_ptr()).into() }
    }

    pub fn transform(&self, other: &PxTransform) -> PxTransform {
        unsafe { PxTransform_transform_1(self.as_ptr(), other.as_ptr()).into() }
    }

    pub fn transform_inv(&self, other: &PxTransform) -> PxTransform {
        unsafe { PxTransform_transformInv_1(self.as_ptr(), other.as_ptr()).into() }
    }

    pub fn transform_vector(&self, vector: &PxVec3) -> PxVec3 {
        unsafe { PxTransform_transform(self.as_ptr(), vector.as_ptr()).into() }
    }

    pub fn transform_vector_inv(&self, vector: &PxVec3) -> PxVec3 {
        unsafe { PxTransform_transformInv(self.as_ptr(), vector.as_ptr()).into() }
    }

    pub fn transform_plane(&self, plane: &PxPlane) -> PxPlane {
        unsafe { PxTransform_transform_2(self.as_ptr(), plane) }
    }

    pub fn transform_plane_inv(&self, plane: &PxPlane) -> PxPlane {
        unsafe { PxTransform_inverseTransform(self.as_ptr(), plane) }
    }
}

unsafe impl Send for PxTransform {}
unsafe impl Sync for PxTransform {}
