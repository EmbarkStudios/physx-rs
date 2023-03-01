use crate::{math::PxBounds3, owner::Owner, traits::Class};

use physx_sys::{PxBVH_getBounds, PxBVH_getNbBounds, PxBase_release_mut};

#[repr(transparent)]
pub struct Bvh {
    obj: physx_sys::PxBVH,
}

crate::DeriveClassForNewType!(Bvh: PxBVH, PxBase);

impl Bvh {
    /// # Safety
    /// Owner's own the pointer they wrap, using the pointer after dropping the Owner,
    /// or creating multiple Owners from the same pointer will cause UB.  Use `into_ptr` to
    /// retrieve the pointer and consume the Owner without dropping the pointee.
    pub(crate) unsafe fn from_raw(ptr: *mut physx_sys::PxBVH) -> Option<Owner<Self>> {
        Owner::from_raw(ptr as *mut Self)
    }
}

unsafe impl Send for Bvh {}
unsafe impl Sync for Bvh {}

impl Drop for Bvh {
    fn drop(&mut self) {
        unsafe { PxBase_release_mut(self.as_mut_ptr()) }
    }
}

impl Bvh {
    /// Get the bounds in the BvhStructure.
    pub fn get_bounds(&self) -> &[PxBounds3] {
        unsafe {
            std::slice::from_raw_parts(
                PxBVH_getBounds(self.as_ptr()) as *const PxBounds3,
                PxBVH_getNbBounds(self.as_ptr()) as usize,
            )
        }
    }

    /// Get the number of bounds in the BvhStructure.
    pub fn get_nb_bounds(&self) -> u32 {
        unsafe { PxBVH_getNbBounds(self.as_ptr()) }
    }
}
