// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created:  2 April 2019

#![warn(clippy::all)]

use crate::{
    convex_mesh::ConvexMesh, height_field::HeightField, traits::Class, triangle_mesh::TriangleMesh,
};

pub use physx_sys::{
    PxBoxGeometry, PxCapsuleGeometry, PxConvexMeshGeometry, PxGeometry, PxHeightFieldGeometry,
    PxPlaneGeometry, PxSphereGeometry, PxTriangleMeshGeometry,
};

use physx_sys::{
    PxBoxGeometry_isValid, PxBoxGeometry_new, PxBoxGeometry_new_1, PxCapsuleGeometry_isValid,
    PxCapsuleGeometry_new, PxCapsuleGeometry_new_1, PxConvexMeshGeometryFlag,
    PxConvexMeshGeometryFlags, PxConvexMeshGeometry_isValid, PxConvexMeshGeometry_new,
    PxConvexMeshGeometry_new_1, PxGeometryType, PxGeometry_getType, PxHeightFieldGeometry_isValid,
    PxHeightFieldGeometry_new, PxHeightFieldGeometry_new_1, PxMeshGeometryFlag,
    PxMeshGeometryFlags, PxMeshScale, PxPlaneGeometry_isValid, PxPlaneGeometry_new,
    PxSphereGeometry_isValid, PxSphereGeometry_new, PxSphereGeometry_new_1,
    PxTriangleMeshGeometry_isValid, PxTriangleMeshGeometry_new, PxTriangleMeshGeometry_new_1,
};

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
#[repr(u8)]
pub enum MeshGeometryFlag {
    DoubleSided = 1u8,
}

impl From<MeshGeometryFlag> for PxMeshGeometryFlags {
    fn from(flag: MeshGeometryFlag) -> Self {
        PxMeshGeometryFlags { mBits: flag as _ }
    }
}

impl From<PxMeshGeometryFlag::Enum> for MeshGeometryFlag {
    fn from(val: PxMeshGeometryFlag::Enum) -> Self {
        match val {
            PxMeshGeometryFlag::eDOUBLE_SIDED => MeshGeometryFlag::DoubleSided,
            _ => unreachable!("Invalid PxMeshGeometryFlag variant."),
        }
    }
}

impl From<MeshGeometryFlag> for PxMeshGeometryFlag::Enum {
    fn from(val: MeshGeometryFlag) -> PxMeshGeometryFlag::Enum {
        match val {
            MeshGeometryFlag::DoubleSided => PxMeshGeometryFlag::eDOUBLE_SIDED,
        }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
#[repr(u8)]
pub enum ConvexMeshGeometryFlag {
    TightBounds = 1u8,
}

impl From<ConvexMeshGeometryFlag> for PxConvexMeshGeometryFlags {
    fn from(flag: ConvexMeshGeometryFlag) -> Self {
        Self { mBits: flag as _ }
    }
}

impl From<PxConvexMeshGeometryFlag::Enum> for ConvexMeshGeometryFlag {
    fn from(val: PxConvexMeshGeometryFlag::Enum) -> Self {
        match val {
            PxConvexMeshGeometryFlag::eTIGHT_BOUNDS => ConvexMeshGeometryFlag::TightBounds,
            _ => unreachable!("Invalid PxConvexMeshGeometryFlag enum."),
        }
    }
}

impl From<ConvexMeshGeometryFlag> for PxConvexMeshGeometryFlag::Enum {
    fn from(val: ConvexMeshGeometryFlag) -> PxConvexMeshGeometryFlag::Enum {
        match val {
            ConvexMeshGeometryFlag::TightBounds => PxConvexMeshGeometryFlag::eTIGHT_BOUNDS,
        }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
#[repr(i32)]
pub enum GeometryType {
    Sphere = 0,
    Plane = 1,
    Capsule = 2,
    Box = 3,
    ConvexMesh = 4,
    TriangleMesh = 5,
    HeightField = 6,
    GeometryCount = 7,
    Invalid = -1,
}

impl From<PxGeometryType::Enum> for GeometryType {
    fn from(val: PxGeometryType::Enum) -> Self {
        match val {
            PxGeometryType::eSPHERE => GeometryType::Sphere,
            PxGeometryType::ePLANE => GeometryType::Plane,
            PxGeometryType::eCAPSULE => GeometryType::Capsule,
            PxGeometryType::eBOX => GeometryType::Box,
            PxGeometryType::eCONVEXMESH => GeometryType::ConvexMesh,
            PxGeometryType::eTRIANGLEMESH => GeometryType::TriangleMesh,
            PxGeometryType::eHEIGHTFIELD => GeometryType::HeightField,
            PxGeometryType::eGEOMETRY_COUNT => GeometryType::GeometryCount,
            PxGeometryType::eINVALID => GeometryType::Invalid,
            _ => unreachable!("invalid pxgeometry enum"),
        }
    }
}

impl From<GeometryType> for PxGeometryType::Enum {
    fn from(val: GeometryType) -> PxGeometryType::Enum {
        match val {
            GeometryType::Sphere => PxGeometryType::eSPHERE,
            GeometryType::Plane => PxGeometryType::ePLANE,
            GeometryType::Capsule => PxGeometryType::eCAPSULE,
            GeometryType::Box => PxGeometryType::eBOX,
            GeometryType::ConvexMesh => PxGeometryType::eCONVEXMESH,
            GeometryType::TriangleMesh => PxGeometryType::eTRIANGLEMESH,
            GeometryType::HeightField => PxGeometryType::eHEIGHTFIELD,
            GeometryType::GeometryCount => PxGeometryType::eGEOMETRY_COUNT,
            GeometryType::Invalid => PxGeometryType::eINVALID,
        }
    }
}

impl<T> Geometry for T where T: Class<PxGeometry> {}
pub trait Geometry: Class<PxGeometry> {
    fn get_type(&self) -> GeometryType {
        unsafe { PxGeometry_getType(self.as_ptr() as *const _).into() }
    }
}

impl<T> SphereGeometry for T where T: Class<PxSphereGeometry> + Geometry {}
pub trait SphereGeometry: Class<PxSphereGeometry> + Geometry {
    #[allow(clippy::new_ret_no_self)]
    fn new(radius: f32) -> PxSphereGeometry {
        unsafe { PxSphereGeometry_new_1(radius) }
    }

    fn default() -> PxSphereGeometry {
        unsafe { PxSphereGeometry_new() }
    }

    fn is_valid(&self) -> bool {
        unsafe { PxSphereGeometry_isValid(self.as_ptr()) }
    }
}

impl<T> PlaneGeometry for T where T: Class<PxPlaneGeometry> + Geometry {}
pub trait PlaneGeometry: Class<PxPlaneGeometry> + Geometry {
    #[allow(clippy::new_ret_no_self)]
    fn new() -> PxPlaneGeometry {
        unsafe { PxPlaneGeometry_new() }
    }

    fn default() -> PxPlaneGeometry {
        unsafe { PxPlaneGeometry_new() }
    }

    fn is_valid(&self) -> bool {
        unsafe { PxPlaneGeometry_isValid(self.as_ptr()) }
    }
}

impl<T> CapsuleGeometry for T where T: Class<PxCapsuleGeometry> + Geometry {}
pub trait CapsuleGeometry: Class<PxCapsuleGeometry> + Geometry {
    #[allow(clippy::new_ret_no_self)]
    fn new(radius: f32, half_height: f32) -> PxCapsuleGeometry {
        unsafe { PxCapsuleGeometry_new_1(radius, half_height) }
    }

    fn default() -> PxCapsuleGeometry {
        unsafe { PxCapsuleGeometry_new() }
    }

    fn is_valid(&self) -> bool {
        unsafe { PxCapsuleGeometry_isValid(self.as_ptr()) }
    }
}

impl<T> BoxGeometry for T where T: Class<PxBoxGeometry> + Geometry {}
pub trait BoxGeometry: Class<PxBoxGeometry> + Geometry {
    #[allow(clippy::new_ret_no_self)]
    fn new(half_x: f32, half_y: f32, half_z: f32) -> PxBoxGeometry {
        unsafe { PxBoxGeometry_new_1(half_x, half_y, half_z) }
    }

    fn default() -> PxBoxGeometry {
        unsafe { PxBoxGeometry_new() }
    }

    fn is_valid(&self) -> bool {
        unsafe { PxBoxGeometry_isValid(self.as_ptr()) }
    }
}

impl<T> ConvexMeshGeometry for T where T: Class<PxConvexMeshGeometry> + Geometry {}
pub trait ConvexMeshGeometry: Class<PxConvexMeshGeometry> + Geometry {
    #[allow(clippy::new_ret_no_self)]
    fn new(
        mesh: &mut ConvexMesh,
        scaling: &impl Class<PxMeshScale>,
        flags: PxConvexMeshGeometryFlags,
    ) -> PxConvexMeshGeometry {
        unsafe { PxConvexMeshGeometry_new_1(mesh.as_mut_ptr(), scaling.as_ptr(), flags) }
    }

    fn default() -> PxConvexMeshGeometry {
        unsafe { PxConvexMeshGeometry_new() }
    }

    fn is_valid(&self) -> bool {
        unsafe { PxConvexMeshGeometry_isValid(self.as_ptr()) }
    }
}

impl<T> TriangleMeshGeometry for T where T: Class<PxTriangleMeshGeometry> + Geometry {}
pub trait TriangleMeshGeometry: Class<PxTriangleMeshGeometry> + Geometry {
    #[allow(clippy::new_ret_no_self)]
    fn new(
        mesh: &mut TriangleMesh,
        scaling: &impl Class<PxMeshScale>,
        flags: PxMeshGeometryFlags,
    ) -> PxTriangleMeshGeometry {
        unsafe { PxTriangleMeshGeometry_new_1(mesh.as_mut_ptr(), scaling.as_ptr(), flags) }
    }

    fn default() -> PxTriangleMeshGeometry {
        unsafe { PxTriangleMeshGeometry_new() }
    }

    fn is_valid(&self) -> bool {
        unsafe { PxTriangleMeshGeometry_isValid(self.as_ptr()) }
    }
}

impl<T> HeightFieldGeometry for T where T: Class<PxHeightFieldGeometry> + Geometry {}
pub trait HeightFieldGeometry: Class<PxHeightFieldGeometry> + Geometry {
    #[allow(clippy::new_ret_no_self)]
    fn new(
        height_field: &mut HeightField,
        flags: PxMeshGeometryFlags,
        height_scale: f32,
        row_scale: f32,
        column_scale: f32,
    ) -> PxHeightFieldGeometry {
        unsafe {
            PxHeightFieldGeometry_new_1(
                height_field.as_mut_ptr(),
                flags,
                height_scale,
                row_scale,
                column_scale,
            )
        }
    }

    fn default() -> PxHeightFieldGeometry {
        unsafe { PxHeightFieldGeometry_new() }
    }

    fn is_valid(&self) -> bool {
        unsafe { PxHeightFieldGeometry_isValid(self.as_ptr()) }
    }
}
