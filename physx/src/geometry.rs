// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created:  2 April 2019

// The new methods in this module don't return the same type as the trait, but that's how it works
#![allow(clippy::new_ret_no_self)]

use crate::{
    convex_mesh::ConvexMesh, height_field::HeightField, traits::Class, triangle_mesh::TriangleMesh,
};

pub use physx_sys::{
    PxBoxGeometry, PxCapsuleGeometry, PxConvexMeshGeometry,
    PxConvexMeshGeometryFlag as ConvexMeshGeometryFlag,
    PxConvexMeshGeometryFlags as ConvexMeshGeometryFlags, PxGeometry,
    PxGeometryType as GeometryType, PxHeightFieldGeometry, PxMeshGeometryFlag as MeshGeometryFlag,
    PxMeshGeometryFlags as MeshGeometryFlags, PxPlaneGeometry, PxSphereGeometry,
    PxTriangleMeshGeometry,
};

use physx_sys::{
    PxBoxGeometry_isValid, PxBoxGeometry_new, PxCapsuleGeometry_isValid, PxCapsuleGeometry_new,
    PxConvexMeshGeometry_isValid, PxConvexMeshGeometry_new, PxGeometry_getType,
    PxHeightFieldGeometry_isValid, PxHeightFieldGeometry_new, PxMeshScale, PxPlaneGeometry_isValid,
    PxPlaneGeometry_new, PxSphereGeometry_isValid, PxSphereGeometry_new,
    PxTriangleMeshGeometry_isValid, PxTriangleMeshGeometry_new,
};

use std::ptr;

impl<T> Geometry for T where T: Class<PxGeometry> {}
pub trait Geometry: Class<PxGeometry> {
    fn get_type(&self) -> GeometryType {
        unsafe { PxGeometry_getType(self.as_ptr() as *const _) }
    }
}

impl<T> SphereGeometry for T where T: Class<PxSphereGeometry> + Geometry {}
pub trait SphereGeometry: Class<PxSphereGeometry> + Geometry {
    fn new(radius: f32) -> PxSphereGeometry {
        unsafe { PxSphereGeometry_new(radius) }
    }

    fn default() -> PxSphereGeometry {
        unsafe { PxSphereGeometry_new(0.0) }
    }

    fn is_valid(&self) -> bool {
        unsafe { PxSphereGeometry_isValid(self.as_ptr()) }
    }
}

impl<T> PlaneGeometry for T where T: Class<PxPlaneGeometry> + Geometry {}
pub trait PlaneGeometry: Class<PxPlaneGeometry> + Geometry {
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
    fn new(radius: f32, half_height: f32) -> PxCapsuleGeometry {
        unsafe { PxCapsuleGeometry_new(radius, half_height) }
    }

    fn default() -> PxCapsuleGeometry {
        unsafe { PxCapsuleGeometry_new(0.0, 0.0) }
    }

    fn is_valid(&self) -> bool {
        unsafe { PxCapsuleGeometry_isValid(self.as_ptr()) }
    }
}

impl<T> BoxGeometry for T where T: Class<PxBoxGeometry> + Geometry {}
pub trait BoxGeometry: Class<PxBoxGeometry> + Geometry {
    fn new(half_x: f32, half_y: f32, half_z: f32) -> PxBoxGeometry {
        unsafe { PxBoxGeometry_new(half_x, half_y, half_z) }
    }

    fn default() -> PxBoxGeometry {
        unsafe { PxBoxGeometry_new(0.0, 0.0, 0.0) }
    }

    fn is_valid(&self) -> bool {
        unsafe { PxBoxGeometry_isValid(self.as_ptr()) }
    }
}

impl<T> ConvexMeshGeometry for T where T: Class<PxConvexMeshGeometry> + Geometry {}
pub trait ConvexMeshGeometry: Class<PxConvexMeshGeometry> + Geometry {
    fn new(
        mesh: &mut ConvexMesh,
        scaling: &impl Class<PxMeshScale>,
        flags: ConvexMeshGeometryFlags,
    ) -> PxConvexMeshGeometry {
        unsafe { PxConvexMeshGeometry_new(mesh.as_mut_ptr(), scaling.as_ptr(), flags) }
    }

    fn default() -> PxConvexMeshGeometry {
        unsafe {
            PxConvexMeshGeometry_new(
                ptr::null_mut(),
                ptr::null(),
                ConvexMeshGeometryFlags::TightBounds,
            )
        }
    }

    fn is_valid(&self) -> bool {
        unsafe { PxConvexMeshGeometry_isValid(self.as_ptr()) }
    }
}

impl<T> TriangleMeshGeometry for T where T: Class<PxTriangleMeshGeometry> + Geometry {}
pub trait TriangleMeshGeometry: Class<PxTriangleMeshGeometry> + Geometry {
    fn new(
        mesh: &mut TriangleMesh,
        scaling: &impl Class<PxMeshScale>,
        flags: MeshGeometryFlags,
    ) -> PxTriangleMeshGeometry {
        unsafe { PxTriangleMeshGeometry_new(mesh.as_mut_ptr(), scaling.as_ptr(), flags) }
    }

    fn default() -> PxTriangleMeshGeometry {
        unsafe {
            PxTriangleMeshGeometry_new(ptr::null_mut(), ptr::null(), MeshGeometryFlags::empty())
        }
    }

    #[inline]
    fn is_valid(&self) -> bool {
        unsafe { PxTriangleMeshGeometry_isValid(self.as_ptr()) }
    }
}

impl<T> HeightFieldGeometry for T where T: Class<PxHeightFieldGeometry> + Geometry {}
pub trait HeightFieldGeometry: Class<PxHeightFieldGeometry> + Geometry {
    fn new(
        height_field: &mut HeightField,
        flags: MeshGeometryFlags,
        height_scale: f32,
        row_scale: f32,
        column_scale: f32,
    ) -> PxHeightFieldGeometry {
        unsafe {
            PxHeightFieldGeometry_new(
                height_field.as_mut_ptr(),
                flags,
                height_scale,
                row_scale,
                column_scale,
            )
        }
    }

    fn default() -> PxHeightFieldGeometry {
        unsafe {
            PxHeightFieldGeometry_new(ptr::null_mut(), MeshGeometryFlags::empty(), 1.0, 1.0, 1.0)
        }
    }

    fn is_valid(&self) -> bool {
        unsafe { PxHeightFieldGeometry_isValid(self.as_ptr()) }
    }
}
