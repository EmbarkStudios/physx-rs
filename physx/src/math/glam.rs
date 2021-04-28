use super::*;
use ::glam::*;

impl From<Vec3> for PxExtendedVec3 {
    fn from(vec: Vec3) -> Self {
        Self {
            obj: physx_sys::PxExtendedVec3 {
                x: vec.x as f64,
                y: vec.y as f64,
                z: vec.z as f64,
            },
        }
    }
}

impl From<Quat> for PxQuat {
    fn from(quat: Quat) -> Self {
        let (x, y, z, w) = quat.into();
        Self::new(x, y, z, w)
    }
}

impl From<PxQuat> for Quat {
    fn from(value: PxQuat) -> Self {
        let physx_sys::PxQuat { x, y, z, w } = value.obj;
        Quat::from_xyzw(x, y, z, w)
    }
}

impl From<Mat4> for PxTransform {
    fn from(mat: Mat4) -> Self {
        let (_, rotation, translation) = mat.to_scale_rotation_translation();
        Self::from_translation_rotation(&translation.into(), &rotation.into())
    }
}

impl From<PxTransform> for Mat4 {
    fn from(value: PxTransform) -> Self {
        Self::from_rotation_translation(value.rotation().into(), value.translation().into())
    }
}

impl From<Vec3> for PxVec3 {
    fn from(v: Vec3) -> Self {
        let (x, y, z) = v.into();
        Self::new(x, y, z)
    }
}

impl From<PxVec3> for Vec3 {
    fn from(value: PxVec3) -> Self {
        let physx_sys::PxVec3 { x, y, z } = value.obj;
        Vec3::new(x, y, z)
    }
}
