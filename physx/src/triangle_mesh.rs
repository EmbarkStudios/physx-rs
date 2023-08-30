use std::mem::MaybeUninit;

use crate::{
    math::{PxBounds3, PxVec3},
    owner::Owner,
    traits::Class,
};

use physx_sys::{
    // TODO: high level wrapper for PxMassProperties
    PxMassProperties,
    PxTriangleMesh_getLocalBounds,
    // TODO: SDF getters
    //PxTriangleMesh_getSDF,
    //PxTriangleMesh_getSDFDimensions,
    //PxTriangleMesh_setPreferSDFProjection_mut,
    //PxTriangleMesh_getPreferSDFProjection,
    PxTriangleMesh_getMassInformation,
    PxTriangleMesh_getNbTriangles,
    PxTriangleMesh_getNbVertices,
    PxTriangleMesh_getTriangleMaterialIndex,
    PxTriangleMesh_getTriangleMeshFlags,
    PxTriangleMesh_getTriangles,
    PxTriangleMesh_getTrianglesRemap,
    PxTriangleMesh_getVertices,
    PxTriangleMesh_getVerticesForModification_mut,
    PxTriangleMesh_refitBVH_mut,
    PxTriangleMesh_release_mut,
};

pub use physx_sys::{
    PxTriangleMeshFlag as TriangleMeshFlag, PxTriangleMeshFlags as TriangleMeshFlags,
};

#[repr(transparent)]
pub struct TriangleMesh {
    obj: physx_sys::PxTriangleMesh,
}

crate::DeriveClassForNewType!(TriangleMesh: PxTriangleMesh, PxBase);

impl TriangleMesh {
    /// # Safety
    ///
    /// Owner's own the pointer they wrap, using the pointer after dropping the Owner,
    /// or creating multiple Owners from the same pointer will cause UB.  Use `into_ptr` to
    /// retrieve the pointer and consume the Owner without dropping the pointee.
    pub unsafe fn from_raw(ptr: *mut physx_sys::PxTriangleMesh) -> Option<Owner<TriangleMesh>> {
        unsafe { Owner::from_raw(ptr as *mut Self) }
    }

    /// Returns the number of vertices.
    pub fn get_nb_vertices(&self) -> u32 {
        unsafe { PxTriangleMesh_getNbVertices(self.as_ptr()) }
    }

    /// Returns the vertices.
    pub fn get_vertices(&self) -> &[PxVec3] {
        unsafe {
            std::slice::from_raw_parts(
                PxTriangleMesh_getVertices(self.as_ptr()) as *const PxVec3,
                self.get_nb_vertices() as usize,
            )
        }
    }

    /// Returns all mesh vertices for modification.
    pub fn get_vertices_mut(&mut self) -> &mut [PxVec3] {
        unsafe {
            std::slice::from_raw_parts_mut(
                PxTriangleMesh_getVerticesForModification_mut(self.as_mut_ptr()) as *mut PxVec3,
                self.get_nb_vertices() as usize,
            )
        }
    }

    /// Refits BVH for mesh vertices.
    pub fn refit_bvh(&mut self) -> PxBounds3 {
        unsafe { PxTriangleMesh_refitBVH_mut(self.as_mut_ptr()) }.into()
    }

    /// Returns the number of triangles.
    pub fn get_nb_triangles(&self) -> u32 {
        unsafe { PxTriangleMesh_getNbTriangles(self.as_ptr()) }
    }

    /// Returns the triangle indices.
    pub fn get_triangles(&self) -> TriangleMeshIndices<'_> {
        let buffer = unsafe { PxTriangleMesh_getTriangles(self.as_ptr()) };
        let length = self.get_nb_triangles() as usize * 3;

        if self
            .get_triangle_mesh_flags()
            .contains(TriangleMeshFlags::E16BitIndices)
        {
            TriangleMeshIndices::U16(unsafe {
                std::slice::from_raw_parts(buffer as *const u16, length)
            })
        } else {
            TriangleMeshIndices::U32(unsafe {
                std::slice::from_raw_parts(buffer as *const u32, length)
            })
        }
    }

    /// Reads the TriangleMesh flags.
    pub fn get_triangle_mesh_flags(&self) -> TriangleMeshFlags {
        unsafe { PxTriangleMesh_getTriangleMeshFlags(self.as_ptr()) }
    }

    /// Returns the triangle remapping table.
    pub fn get_triangles_remap(&self) -> &[u32] {
        unsafe {
            std::slice::from_raw_parts(
                PxTriangleMesh_getTrianglesRemap(self.as_ptr()),
                self.get_nb_triangles() as usize,
            )
        }
    }

    /// Returns material table index of given triangle.
    pub fn get_triangle_material_index(&self, triangle_index: u32) -> u16 {
        unsafe { PxTriangleMesh_getTriangleMaterialIndex(self.as_ptr(), triangle_index) }
    }

    /// Returns the mass properties of the mesh assuming unit density.
    pub fn get_mass_information(&self) -> PxMassProperties {
        let mut mass = MaybeUninit::uninit();
        let mut local_inertia = MaybeUninit::uninit();
        let mut local_center_of_mass = MaybeUninit::uninit();

        unsafe {
            PxTriangleMesh_getMassInformation(
                self.as_ptr(),
                mass.as_mut_ptr(),
                local_inertia.as_mut_ptr(),
                local_center_of_mass.as_mut_ptr(),
            );

            PxMassProperties {
                inertiaTensor: local_inertia.assume_init(),
                centerOfMass: local_center_of_mass.assume_init(),
                mass: mass.assume_init(),
            }
        }
    }

    /// Returns the local-space (vertex space) AABB from the triangle mesh.
    pub fn get_local_bounds(&self) -> PxBounds3 {
        unsafe { PxTriangleMesh_getLocalBounds(self.as_ptr()) }.into()
    }
}

unsafe impl Send for TriangleMesh {}
unsafe impl Sync for TriangleMesh {}

impl Drop for TriangleMesh {
    fn drop(&mut self) {
        unsafe { PxTriangleMesh_release_mut(self.as_mut_ptr()) }
    }
}

#[derive(Debug)]
pub enum TriangleMeshIndices<'a> {
    U16(&'a [u16]),
    U32(&'a [u32]),
}

impl<'a> TriangleMeshIndices<'a> {
    pub fn len(&self) -> usize {
        match self {
            Self::U16(vec) => vec.len(),
            Self::U32(vec) => vec.len(),
        }
    }

    pub fn is_empty(&self) -> bool {
        self.len() == 0
    }
}
