use crate::{
    bvh::Bvh, convex_mesh::ConvexMesh, height_field::HeightField, owner::Owner, physics::Physics,
    traits::Class, triangle_mesh::TriangleMesh,
};

#[rustfmt::skip]
use physx_sys::{
    phys_PxCreateBVH,
    phys_PxCreateConvexMesh,
    phys_PxCreateHeightField,
    phys_PxCreateTriangleMesh,
    phys_PxValidateConvexMesh,
    phys_PxValidateTriangleMesh,
    PxBVHDesc_isValid,
    PxBVHDesc_new,
    PxBVHDesc_setToDefault_mut,
    PxConvexMeshDesc_isValid,
    PxConvexMeshDesc_new,
    PxConvexMeshDesc_setToDefault_mut,
    PxCookingParams_new,
    PxHeightFieldDesc_isValid,
    PxHeightFieldDesc_new,
    PxHeightFieldDesc_setToDefault_mut,
    PxTriangleMeshDesc_isValid,
    PxTriangleMeshDesc_new,
    PxTriangleMeshDesc_setToDefault_mut,
};

/// Cooks and creates a bounding volume hierarchy without going through a stream.
///
/// This method does the same as `cook_bvh`, but the produced BVH is not stored
/// into a stream but is directly inserted into the provided `Physics`.
///
/// A [`crate::Bvh`] object on success
#[inline]
pub fn create_bvh(physics: &mut impl Physics, desc: &PxBVHDesc) -> Option<Owner<Bvh>> {
    unsafe {
        Bvh::from_raw(phys_PxCreateBVH(
            desc.as_ptr(),
            physics.get_physics_insertion_callback()?,
        ))
    }
}

/// Cooks and creates a convex mesh without going through a stream.
///
/// This method does the same as `cook_convex_mesh`, but the produced mesh is not
/// stored into a stream but but is directly inserted into the provided `Physics`.
#[inline]
pub fn create_convex_mesh(
    physics: &mut impl Physics,
    params: &PxCookingParams,
    desc: &PxConvexMeshDesc,
) -> ConvexMeshCookingResult {
    if !desc.is_valid() {
        return ConvexMeshCookingResult::InvalidDescriptor;
    };
    if let Some(callback) = physics.get_physics_insertion_callback() {
        let mut result = ConvRes::Failure;
        let ptr = unsafe {
            ConvexMesh::from_raw(phys_PxCreateConvexMesh(
                params.as_ptr(),
                desc.as_ptr(),
                callback,
                &mut result,
            ))
        };
        ConvexMeshCookingResult::from_raw(result, ptr)
    } else {
        ConvexMeshCookingResult::Failure
    }
}

/// Cooks and creates a heightfield mesh and inserts it into PxPhysics.
///
/// PxHeightField pointer on success
#[inline]
pub fn create_height_field(
    physics: &mut impl Physics,
    desc: &PxHeightFieldDesc,
) -> Option<Owner<HeightField>> {
    unsafe {
        HeightField::from_raw(phys_PxCreateHeightField(
            desc.as_ptr(),
            physics.get_physics_insertion_callback()?,
        ))
    }
}

/// Cooks and creates a triangle mesh without going through a stream.
///
/// This method does the same as `cook_triangle_mesh`, but the produced mesh is
/// not stored stored into a stream but but is directly inserted into the provided `Physics`.
#[inline]
pub fn create_triangle_mesh(
    physics: &mut impl Physics,
    params: &PxCookingParams,
    desc: &PxTriangleMeshDesc,
) -> TriangleMeshCookingResult {
    if !desc.is_valid() {
        return TriangleMeshCookingResult::InvalidDescriptor;
    };
    if let Some(callback) = physics.get_physics_insertion_callback() {
        let mut result = TriResult::Failure;
        let ptr = unsafe {
            TriangleMesh::from_raw(phys_PxCreateTriangleMesh(
                params.as_ptr(),
                desc.as_ptr(),
                callback,
                &mut result,
            ))
        };
        TriangleMeshCookingResult::from_raw(result, ptr)
    } else {
        TriangleMeshCookingResult::Failure
    }
}

/// Validate a convex mesh descriptor.
#[inline]
pub fn validate_convex_mesh(params: &PxCookingParams, desc: &PxConvexMeshDesc) -> bool {
    unsafe { phys_PxValidateConvexMesh(params.as_ptr(), desc.as_ptr()) }
}

/// Verifies if the triangle mesh is valid. Prints an error message for each inconsistency found.
///
/// The following conditions are true for a valid triangle mesh:
/// 1. There are no duplicate vertices (within specified vertexWeldTolerance. See PxCookingParams::meshWeldTolerance)
/// 2. There are no large triangles (within specified PxTolerancesScale.)
///
/// true if all the validity conditions hold, false otherwise.
#[inline]
pub fn validate_triangle_mesh(params: &PxCookingParams, desc: &PxTriangleMeshDesc) -> bool {
    unsafe { phys_PxValidateTriangleMesh(params.as_ptr(), desc.as_ptr()) }
}

use physx_sys::PxConvexMeshCookingResult as ConvRes;

pub enum ConvexMeshCookingResult {
    Success(Owner<ConvexMesh>),
    ZeroAreaTestFailed,
    PolygonsLimitReached,
    Failure,
    InvalidDescriptor,
}

impl ConvexMeshCookingResult {
    fn from_raw(px_result: ConvRes, ptr: Option<Owner<ConvexMesh>>) -> Self {
        match px_result {
            ConvRes::Success => {
                if let Some(ptr) = ptr {
                    Self::Success(ptr)
                } else {
                    Self::Failure
                }
            }
            ConvRes::ZeroAreaTestFailed => Self::ZeroAreaTestFailed,
            ConvRes::PolygonsLimitReached => Self::PolygonsLimitReached,
            ConvRes::Failure => Self::Failure,
        }
    }
}

use physx_sys::PxTriangleMeshCookingResult as TriResult;

pub enum TriangleMeshCookingResult {
    Success(Owner<TriangleMesh>),
    LargeTriangle,
    Failure,
    InvalidDescriptor,
}

impl TriangleMeshCookingResult {
    fn from_raw(px_result: TriResult, ptr: Option<Owner<TriangleMesh>>) -> Self {
        match px_result {
            TriResult::Success => {
                if let Some(ptr) = ptr {
                    Self::Success(ptr)
                } else {
                    Self::Failure
                }
            }
            TriResult::LargeTriangle => Self::LargeTriangle,
            TriResult::Failure => Self::Failure,
        }
    }
}

pub struct PxConvexMeshDesc {
    pub obj: physx_sys::PxConvexMeshDesc,
}

unsafe impl Class<physx_sys::PxConvexMeshDesc> for PxConvexMeshDesc {
    fn as_ptr(&self) -> *const physx_sys::PxConvexMeshDesc {
        &self.obj
    }

    fn as_mut_ptr(&mut self) -> *mut physx_sys::PxConvexMeshDesc {
        &mut self.obj
    }
}

impl Default for PxConvexMeshDesc {
    fn default() -> Self {
        Self::new()
    }
}

impl PxConvexMeshDesc {
    /// Create a new convex mesh descriptor.
    pub fn new() -> Self {
        unsafe {
            Self {
                obj: PxConvexMeshDesc_new(),
            }
        }
    }

    /// Check if the descriptor is valid.
    pub fn is_valid(&self) -> bool {
        unsafe { PxConvexMeshDesc_isValid(self.as_ptr()) }
    }

    /// Set the descriptor to its default values.
    pub fn set_to_default(&mut self) -> &mut Self {
        unsafe {
            PxConvexMeshDesc_setToDefault_mut(self.as_mut_ptr());
        }
        self
    }
}

pub struct PxTriangleMeshDesc {
    pub obj: physx_sys::PxTriangleMeshDesc,
}

unsafe impl Class<physx_sys::PxTriangleMeshDesc> for PxTriangleMeshDesc {
    fn as_ptr(&self) -> *const physx_sys::PxTriangleMeshDesc {
        &self.obj
    }

    fn as_mut_ptr(&mut self) -> *mut physx_sys::PxTriangleMeshDesc {
        &mut self.obj
    }
}

impl Default for PxTriangleMeshDesc {
    fn default() -> Self {
        Self::new()
    }
}

impl PxTriangleMeshDesc {
    /// Create a new triangle mesh descriptor.
    pub fn new() -> Self {
        unsafe {
            Self {
                obj: PxTriangleMeshDesc_new(),
            }
        }
    }

    /// Check if the descriptor is valid.
    pub fn is_valid(&self) -> bool {
        unsafe { PxTriangleMeshDesc_isValid(self.as_ptr()) }
    }

    /// Set the descriptor to its default values.
    pub fn set_to_default(&mut self) -> &mut Self {
        unsafe {
            PxTriangleMeshDesc_setToDefault_mut(self.as_mut_ptr());
        }
        self
    }
}

pub struct PxHeightFieldDesc {
    pub obj: physx_sys::PxHeightFieldDesc,
}

unsafe impl Class<physx_sys::PxHeightFieldDesc> for PxHeightFieldDesc {
    fn as_ptr(&self) -> *const physx_sys::PxHeightFieldDesc {
        &self.obj
    }

    fn as_mut_ptr(&mut self) -> *mut physx_sys::PxHeightFieldDesc {
        &mut self.obj
    }
}

impl Default for PxHeightFieldDesc {
    fn default() -> Self {
        Self::new()
    }
}

impl PxHeightFieldDesc {
    /// Create a new height field descriptor.
    pub fn new() -> Self {
        unsafe {
            Self {
                obj: PxHeightFieldDesc_new(),
            }
        }
    }

    /// Check if the descriptor is valid.
    pub fn is_valid(&self) -> bool {
        unsafe { PxHeightFieldDesc_isValid(self.as_ptr()) }
    }

    /// Set the descriptor to its default values.
    pub fn set_to_default(&mut self) -> &mut Self {
        unsafe {
            PxHeightFieldDesc_setToDefault_mut(self.as_mut_ptr());
        }
        self
    }
}

pub struct PxBVHDesc {
    pub obj: physx_sys::PxBVHDesc,
}

unsafe impl Class<physx_sys::PxBVHDesc> for PxBVHDesc {
    fn as_ptr(&self) -> *const physx_sys::PxBVHDesc {
        &self.obj
    }

    fn as_mut_ptr(&mut self) -> *mut physx_sys::PxBVHDesc {
        &mut self.obj
    }
}

impl Default for PxBVHDesc {
    fn default() -> Self {
        Self::new()
    }
}

impl PxBVHDesc {
    /// Create a new BVH structure descriptor.
    pub fn new() -> Self {
        unsafe {
            Self {
                obj: PxBVHDesc_new(),
            }
        }
    }

    /// Check if the descriptor is valid.
    pub fn is_valid(&self) -> bool {
        unsafe { PxBVHDesc_isValid(self.as_ptr()) }
    }

    /// Set the descriptor to its default values.
    pub fn set_to_default(&mut self) -> &mut Self {
        unsafe {
            PxBVHDesc_setToDefault_mut(self.as_mut_ptr());
        }
        self
    }
}

pub struct PxCookingParams {
    pub obj: physx_sys::PxCookingParams,
}

unsafe impl Class<physx_sys::PxCookingParams> for PxCookingParams {
    fn as_ptr(&self) -> *const physx_sys::PxCookingParams {
        &self.obj
    }

    fn as_mut_ptr(&mut self) -> *mut physx_sys::PxCookingParams {
        &mut self.obj
    }
}

impl PxCookingParams {
    /// Create a new cooking params.
    pub fn new(physics: &impl Physics) -> Option<Self> {
        unsafe {
            physics.get_tolerances_scale().map(|tolerances| Self {
                obj: PxCookingParams_new(tolerances),
            })
        }
    }
}
