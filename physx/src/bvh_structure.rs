use crate::{math::PxBounds3, owner::Owner, traits::Class};

use physx_sys::{
    PxBVHStructure_getBounds,
    PxBVHStructure_getNbBounds,
    //PxBVHStructure_getConcreteTypeName,
    //PxBVHStructure_overlap,
    //PxBVHStructure_raycast,
    //PxBVHStructure_sweep,
    PxBase_release_mut,
};

#[repr(transparent)]
pub struct BVHStructure {
    obj: physx_sys::PxBVHStructure,
}

crate::DeriveClassForNewType!(BVHStructure: PxBVHStructure, PxBase);

impl BVHStructure {
    /// # Safety
    /// Owner's own the pointer they wrap, using the pointer after dropping the Owner,
    /// or creating multiple Owners from the same pointer will cause UB.  Use `into_ptr` to
    /// retrieve the pointer and consume the Owner without dropping the pointee.
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

impl BVHStructure {
    /// Get the bounds in the BVHStructure.
    pub fn get_bounds(&self) -> &[PxBounds3] {
        unsafe {
            std::slice::from_raw_parts(
                PxBVHStructure_getBounds(self.as_ptr()) as *const PxBounds3,
                PxBVHStructure_getNbBounds(self.as_ptr()) as usize,
            )
        }
    }

    /// Get the number of bounds in the BVHStructure.
    pub fn get_nb_bounds(&self) -> u32 {
        unsafe { PxBVHStructure_getNbBounds(self.as_ptr()) }
    }
}
