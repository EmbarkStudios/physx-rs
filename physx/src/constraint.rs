use crate::{owner::Owner, traits::Class};

use physx_sys::PxConstraint_release_mut;

#[repr(transparent)]
pub struct Constraint {
    obj: physx_sys::PxConstraint,
}

crate::DeriveClassForNewType!(Constraint: PxConstraint, PxBase);

impl Constraint {
    /// # Safety
    /// Owner's own the pointer they wrap, using the pointer after dropping the Owner,
    /// or creating multiple Owners from the same pointer will cause UB.  Use `into_ptr` to
    /// retrieve the pointer and consume the Owner without dropping the pointee.
    #[allow(dead_code)]
    pub(crate) unsafe fn from_raw(ptr: *mut physx_sys::PxConstraint) -> Option<Owner<Self>> {
        Owner::from_raw(ptr as *mut Self)
    }
}

unsafe impl Send for Constraint {}
unsafe impl Sync for Constraint {}

impl Drop for Constraint {
    fn drop(&mut self) {
        unsafe { PxConstraint_release_mut(self.as_mut_ptr()) }
    }
}
