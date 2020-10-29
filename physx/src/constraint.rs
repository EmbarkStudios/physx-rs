use crate::{owner::Owner, traits::Class};

use physx_sys::PxConstraint_release_mut;

#[repr(transparent)]
pub struct Constraint {
    obj: physx_sys::PxConstraint,
}

crate::ClassObj!(Constraint: PxConstraint, PxBase);

impl Constraint {
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
