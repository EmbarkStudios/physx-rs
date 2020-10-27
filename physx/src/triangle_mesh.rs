use crate::{owner::Owner, traits::Class};

use physx_sys::PxTriangleMesh_release_mut;

#[repr(transparent)]
pub struct TriangleMesh {
    obj: physx_sys::PxTriangleMesh,
}

crate::ClassObj!(TriangleMesh: PxTriangleMesh, PxBase);

impl TriangleMesh {
    pub(crate) unsafe fn from_raw(
        ptr: *mut physx_sys::PxTriangleMesh,
    ) -> Option<Owner<TriangleMesh>> {
        Owner::from_raw(ptr as *mut Self)
    }
}

unsafe impl Send for TriangleMesh {}
unsafe impl Sync for TriangleMesh {}

impl Drop for TriangleMesh {
    fn drop(&mut self) {
        unsafe { PxTriangleMesh_release_mut(self.as_mut_ptr()) }
    }
}
