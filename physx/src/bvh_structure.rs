use crate::{owner::Owner, traits::Class};

use physx_sys::PxBase_release_mut;

#[repr(transparent)]
pub struct BVHStructure {
    obj: physx_sys::PxBVHStructure,
}

crate::ClassObj!(BVHStructure: PxBVHStructure, PxBase);

impl BVHStructure {
    #[allow(dead_code)]
    pub(crate) unsafe fn from_raw(ptr: *mut physx_sys::PxBVHStructure) -> Option<Owner<Self>> {
        Owner::from_raw(ptr as *mut Self)
    }
}

unsafe impl Send for BVHStructure {}
unsafe impl Sync for BVHStructure {}

impl Drop for BVHStructure {
    fn drop(&mut self) {
        unsafe { PxBase_release_mut(self.as_mut_ptr()) }
    }
}
