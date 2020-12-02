use crate::{owner::Owner, traits::Class};

use physx_sys::PxPruningStructure_release_mut;

#[repr(transparent)]
pub struct PruningStructure {
    obj: physx_sys::PxPruningStructure,
}

crate::DeriveClassForNewType!(PruningStructure: PxPruningStructure, PxBase);

impl PruningStructure {
    /// # Safety
    /// Owner's own the pointer they wrap, using the pointer after dropping the Owner,
    /// or creating multiple Owners from the same pointer will cause UB.  Use `into_ptr` to
    /// retrieve the pointer and consume the Owner without dropping the pointee.
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
