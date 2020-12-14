use crate::{owner::Owner, traits::Class};

use physx_sys::PxTriangleMesh_release_mut;

#[repr(transparent)]
pub struct TriangleMesh {
    obj: physx_sys::PxTriangleMesh,
}

crate::DeriveClassForNewType!(TriangleMesh: PxTriangleMesh, PxBase);

impl TriangleMesh {
    /// # Safety
    /// Owner's own the pointer they wrap, using the pointer after dropping the Owner,
    /// or creating multiple Owners from the same pointer will cause UB.  Use `into_ptr` to
    /// retrieve the pointer and consume the Owner without dropping the pointee.
    pub unsafe fn from_raw(ptr: *mut physx_sys::PxTriangleMesh) -> Option<Owner<TriangleMesh>> {
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
