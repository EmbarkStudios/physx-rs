// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created:  2 April 2019

#![warn(clippy::all)]

/*!

*/

/* Stolen from world/physics.rs */

use glam::Vec3;
use physx_sys::*;

pub type Point3 = PxVec3;

#[derive(Debug, Clone, Copy, PartialEq)]
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

impl Into<PxGeometryType::Enum> for GeometryType {
    fn into(self) -> PxGeometryType::Enum {
        match self {
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

#[derive(Clone)]
pub enum ColliderDesc {
    Sphere(f32),
    Box(f32, f32, f32),
    Capsule(f32, f32),
    Cylinder(f32, f32), // not supported by physx

    TriMesh {
        vertices: Vec<Point3>,
        indices: Vec<u32>,
        mesh_scale: Vec3,
    },
}

pub enum Geometry {
    Sphere(PxSphereGeometry),
    Plane(PxPlaneGeometry),
    Capsule(PxCapsuleGeometry),
    Box(PxBoxGeometry),
    ConvexMesh(PxConvexMeshGeometry),
    TriangleMesh(PxTriangleMeshGeometry),
    HeightField(PxHeightFieldGeometry),
}

impl Geometry {
    pub fn as_ptr(&self) -> *const PxGeometry {
        match self {
            Geometry::Sphere(val) => val as *const PxSphereGeometry as *const PxGeometry,
            Geometry::Plane(val) => val as *const PxPlaneGeometry as *const PxGeometry,
            Geometry::Capsule(val) => val as *const PxCapsuleGeometry as *const PxGeometry,
            Geometry::Box(val) => val as *const PxBoxGeometry as *const PxGeometry,
            Geometry::ConvexMesh(val) => val as *const PxConvexMeshGeometry as *const PxGeometry,
            Geometry::TriangleMesh(val) => {
                val as *const PxTriangleMeshGeometry as *const PxGeometry
            }
            Geometry::HeightField(val) => val as *const PxHeightFieldGeometry as *const PxGeometry,
        }
    }

    pub fn as_ptr_mut(&mut self) -> *mut PxGeometry {
        match self {
            Geometry::Sphere(val) => val as *mut PxSphereGeometry as *mut PxGeometry,
            Geometry::Plane(val) => val as *mut PxPlaneGeometry as *mut PxGeometry,
            Geometry::Capsule(val) => val as *mut PxCapsuleGeometry as *mut PxGeometry,
            Geometry::Box(val) => val as *mut PxBoxGeometry as *mut PxGeometry,
            Geometry::ConvexMesh(val) => val as *mut PxConvexMeshGeometry as *mut PxGeometry,
            Geometry::TriangleMesh(val) => val as *mut PxTriangleMeshGeometry as *mut PxGeometry,
            Geometry::HeightField(val) => val as *mut PxHeightFieldGeometry as *mut PxGeometry,
        }
    }
}

pub struct PhysicsGeometry {
    pub geometry: Geometry,
}

impl From<&ColliderDesc> for PhysicsGeometry {
    fn from(desc: &ColliderDesc) -> Self {
        let geometry: Geometry = unsafe {
            match desc {
                ColliderDesc::Sphere(radius) => Geometry::Sphere(PxSphereGeometry_new_1(*radius)),
                ColliderDesc::Box(x, y, z) => Geometry::Box(PxBoxGeometry_new_1(*x, *y, *z)),
                ColliderDesc::Capsule(r, h) => {
                    Geometry::Capsule(PxCapsuleGeometry_new_1(*r, *h / 2.0))
                }
                ColliderDesc::Cylinder(r, h) => {
                    Geometry::Capsule(PxCapsuleGeometry_new_1(*r, *h / 2.0))
                }
                _ => panic!("cannot do simple cook for trimeshes"),
            }
        };
        PhysicsGeometry::new(geometry)
    }
}

impl PhysicsGeometry {
    pub fn new(geometry: Geometry) -> Self {
        Self { geometry }
    }

    pub fn get_type(&self) -> GeometryType {
        unsafe { PxGeometry_getType(self.geometry.as_ptr() as *const PxGeometry).into() }
    }

    pub fn as_raw(&self) -> *const PxGeometry {
        self.geometry.as_ptr()
    }

    pub fn as_raw_mut(&mut self) -> *mut PxGeometry {
        self.geometry.as_ptr_mut()
    }

    // pub fn get_convex_mesh(&self) -> ConvexMesh {
    //     let px_convex = unsafe {
    //         (*PxGeometryHolder_convexMesh(&PxGeometryHolder_new_1(self.geometry.as_ptr())))
    //             .convexMesh
    //     };
    //     ConvexMesh { px_convex }
    // }
}

// pub struct ConvexMesh {
//     px_convex: *const PxConvexMesh,
// }

// impl ConvexMesh {
//     /// Get the number of vertices in this mesh
//     pub fn get_nb_vertices(&self) -> usize {
//         unsafe { PxConvexMesh_getNbVertices(self.px_convex) as usize }
//     }

//     pub fn get_vertices(&self) -> &[PxVec3] {
//         unsafe {
//             let raw_data = PxConvexMesh_getVertices(self.px_convex);
//             let item_count = self.get_nb_vertices();
//             std::slice::from_raw_parts(raw_data, item_count)
//         }
//     }

//     pub fn get_nb_polygons(&self) -> usize {
//         unsafe { PxConvexMesh_getNbPolygons(self.px_convex) as usize }
//     }

//     pub fn get_indices(&self) -> &[usize]
// }
