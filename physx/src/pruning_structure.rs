use crate::{owner::Owner, traits::Class};

use physx_sys::PxPruningStructure_release_mut;

#[repr(transparent)]
pub struct PruningStructure {
    obj: physx_sys::PxPruningStructure,
}

crate::DeriveClassForNewType!(PruningStructure: PxPruningStructure, PxBase);

impl PruningStructure {
    pub(crate) unsafe fn from_raw(
        ptr: *mut physx_sys::PxPruningStructure,
    ) -> Option<Owner<PruningStructure>> {
        Owner::from_raw(ptr as *mut Self)
    }
}

unsafe impl Send for PruningStructure {}
unsafe impl Sync for PruningStructure {}

impl Drop for PruningStructure {
    fn drop(&mut self) {
        unsafe { PxPruningStructure_release_mut(self.as_mut_ptr()) }
    }
}
