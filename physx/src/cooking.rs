// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 12 April 2019

#![warn(clippy::all)]

/*!

*/

/*
use super::{
    foundation::*,
    geometry::*,
};
use physx_sys::{
    // TODO import things individually and fix safety holes
};

todo[tolsson]: Make these into builder parameters
*/
pub const HEIGHT_SCALE: f32 = 1.0;
pub const XZ_SCALE: f32 = 100.0;
/*
impl Release for PxCooking {
    unsafe fn release(pointer: &mut Self) {
        PxCooking_release_mut(pointer)
    }
}

impl PxCooking {
    pub fn new(
        physx_version: u32,
        foundation: &mut impl Foundation,
        cook_params: PxCookingParams,
    ) -> Option<Self> {
        unsafe {
            PxCooking::from_raw(
                phys_PxCreateCooking(
                    physx_version,
                    foundation.as_mut_ptr(),
                    &cook_params
                )
            )
        }
    }
}

pub trait Cooking {
    fn as_ptr(&self) -> *const PxCooking;

    fn as_mut_ptr(&mut self) -> *mut PxCooking {
        self.as_ptr() as *mut PxCooking
    }

    /// Validate that the provided description is valid
    fn validate_triangle_mesh(&self, mesh_desc: &PxTriangleMeshDesc) -> bool {
        unsafe { PxCooking_validateTriangleMesh(self.as_ptr(), mesh_desc) }
    }

    fn create_triangle_mesh(
        &self,
        mesh_desc: &PxTriangleMeshDesc,
        mesh_scale: &PxVec3,
    ) -> Result<PxTriangleMeshGeometry, ()> {
        let mut cooking_result = PxTriangleMeshCookingResult::eSUCCESS;
        unsafe {
            if !self.validate_triangle_mesh(mesh_desc) {
                Err(())
            } else {
                let insertion_callback =
                    PxPhysics_getPhysicsInsertionCallback_mut(phys_PxGetPhysics());

                let tri_mesh = PxTriangleMesh::from_raw(PxCooking_createTriangleMesh(
                    self.as_ptr(),
                    mesh_desc,
                    insertion_callback,
                    &mut cooking_result,
                ));

                let mesh_scale = PxMeshScale_new_2(mesh_scale);

                Ok(<PxTriangleMeshGeometry as TriangleMeshGeometry>::new(
                    tri_mesh,
                    &mesh_scale,
                    PxMeshGeometryFlags { mBits: 0 },
                ))
            }
        }
    }

    /// Build heightfield geometry from a description
    fn create_heightfield(
        &self,
        heightfield_desc: PxHeightFieldDesc,
        double_sided: bool,
    ) -> PxHeightFieldGeometry {
        unsafe {
            let insertion_callback = PxPhysics_getPhysicsInsertionCallback_mut(phys_PxGetPhysics());

            let heightfield =
                PxCooking_createHeightField(self.as_ptr(), &heightfield_desc, insertion_callback);
            let mesh_flags = if double_sided {
                PxMeshGeometryFlag::eDOUBLE_SIDED
            } else {
                0
            };

            <PxHeightFieldGeometry as HeightFieldGeometry>::new(
                &mut*heightfield,
                PxMeshGeometryFlags {
                    mBits: mesh_flags as u8,
                },
                HEIGHT_SCALE,
                XZ_SCALE,
                XZ_SCALE,
            )
        }
    }

    /* TODO make sense of  PxGeometry creation :)
    fn make_geometry<T>(&mut self, desc: ColliderDesc) -> Geometry<T> {
        unsafe {
            match desc {
                ColliderDesc::Sphere(radius) => Geometry::<PxSphereGeometry>(PxSphereGeometry_new_1(radius)),
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
        }
    }
    */
}
*/
