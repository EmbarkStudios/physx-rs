// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 12 April 2019

#![warn(clippy::all)]

/*!

*/

use super::{foundation::*, geometry::*, px_type::*, transform::gl_to_px_v3};
use glam::Vec3;
use physx_macros::*;
use physx_sys::*;

/*
todo[tolsson]: Make these into builder parameters
*/
pub const HEIGHT_SCALE: f32 = 1.0;
pub const XZ_SCALE: f32 = 100.0;

#[physx_type]
impl Cooking {
    pub fn new(
        physx_version: u32,
        foundation: &mut Foundation,
        cook_params: PxCookingParams,
    ) -> Self {
        let px_cooking =
            unsafe { phys_PxCreateCooking(physx_version, foundation.get_raw_mut(), &cook_params) };

        Self::from_ptr(px_cooking)
    }

    /// Validate that the provided description is valid
    pub fn validate_triangle_mesh(&self, mesh_desc: &PxTriangleMeshDesc) -> bool {
        unsafe { PxCooking_validateTriangleMesh(self.get_raw(), mesh_desc) }
    }

    pub fn create_triangle_mesh(
        &self,
        mesh_desc: &PxTriangleMeshDesc,
        mesh_scale: Vec3,
    ) -> Result<Geometry, ()> {
        let mut cooking_result = PxTriangleMeshCookingResult::eSUCCESS;
        unsafe {
            if !self.validate_triangle_mesh(mesh_desc) {
                Err(())
            } else {
                let insertion_callback =
                    PxPhysics_getPhysicsInsertionCallback_mut(phys_PxGetPhysics());

                let tri_mesh = PxCooking_createTriangleMesh(
                    self.get_raw(),
                    mesh_desc,
                    insertion_callback,
                    &mut cooking_result,
                );

                let mesh_scale = PxMeshScale_new_2(&gl_to_px_v3(mesh_scale));

                Ok(Geometry::TriangleMesh(PxTriangleMeshGeometry_new_1(
                    tri_mesh,
                    &mesh_scale,
                    PxMeshGeometryFlags { mBits: 0 },
                )))
            }
        }
    }

    /// Build heightfield geometry from a description
    pub fn create_heightfield(
        &self,
        heightfield_desc: PxHeightFieldDesc,
        double_sided: bool,
    ) -> Geometry {
        unsafe {
            let insertion_callback = PxPhysics_getPhysicsInsertionCallback_mut(phys_PxGetPhysics());

            let heightfield =
                PxCooking_createHeightField(self.get_raw(), &heightfield_desc, insertion_callback);
            let mesh_flags = if double_sided {
                PxMeshGeometryFlag::eDOUBLE_SIDED
            } else {
                0
            };

            let heightfield_geom = PxHeightFieldGeometry_new_1(
                heightfield,
                PxMeshGeometryFlags {
                    mBits: mesh_flags as u8,
                },
                HEIGHT_SCALE,
                XZ_SCALE,
                XZ_SCALE,
            );

            Geometry::HeightField(heightfield_geom)
        }
    }

    pub fn make_geometry(&mut self, desc: ColliderDesc) -> PhysicsGeometry {
        let geometry: Geometry = unsafe {
            match desc {
                ColliderDesc::Sphere(radius) => Geometry::Sphere(PxSphereGeometry_new_1(radius)),
                ColliderDesc::Box(x, y, z) => Geometry::Box(PxBoxGeometry_new_1(x, y, z)),
                ColliderDesc::Capsule(r, h) => {
                    Geometry::Capsule(PxCapsuleGeometry_new_1(r, h / 2.0))
                }
                ColliderDesc::Cylinder(r, h) => {
                    Geometry::Capsule(PxCapsuleGeometry_new_1(r, h / 2.0))
                }
                ColliderDesc::TriMesh {
                    vertices,
                    indices,
                    mesh_scale,
                } => {
                    let mut mesh_desc = PxTriangleMeshDesc_new();

                    mesh_desc.points.count = vertices.len() as u32;
                    mesh_desc.points.stride = (3 * std::mem::size_of::<f32>()) as u32;
                    mesh_desc.points.data = vertices.as_ptr() as *const std::ffi::c_void;

                    mesh_desc.triangles.count = (indices.len() as u32) / 3;
                    mesh_desc.triangles.stride = (3 * std::mem::size_of::<u32>()) as u32;
                    mesh_desc.triangles.data = indices.as_ptr() as *const std::ffi::c_void;

                    self.create_triangle_mesh(&mesh_desc, mesh_scale)
                        .expect("failed creating triangle mesh")
                }
            }
        };

        PhysicsGeometry::new(geometry)
    }
}
