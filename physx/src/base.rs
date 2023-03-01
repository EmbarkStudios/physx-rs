use crate::traits::Class;
pub(crate) use physx_sys::{PxBase, PxRefCounted};

use physx_sys::{
    PxBase_getBaseFlags, PxBase_getConcreteType, PxBase_getConcreteTypeName, PxBase_isReleasable,
    PxBase_setBaseFlag_mut, PxBase_setBaseFlags_mut, PxRefCounted_acquireReference_mut,
    PxRefCounted_getReferenceCount, PxRefCounted_release_mut,
};

pub use physx_sys::{
    PxBaseFlag as BaseFlag, PxBaseFlags as BaseFlags, PxConcreteType as ConcreteType,
};

impl<T> Base for T where T: Class<PxBase> + Sized {}

pub trait Base: Class<PxBase> + Sized {
    /// Get the name of the real type referenced by this pointer, or None if the returned string is not valid
    fn get_concrete_type_name(&self) -> Option<&str> {
        unsafe {
            std::ffi::CStr::from_ptr(PxBase_getConcreteTypeName(self.as_ptr() as *const _) as _)
                .to_str()
                .ok()
        }
    }

    /// Returns an enumerated value identifying the type.
    ///
    /// This may return [`ConcreteType::Undefined`] in surprising situations,
    /// notably this does not seem to work with `get_active_actors`.  Use
    /// `get_type` for actors if possible.
    #[inline]
    fn get_concrete_type(&self) -> ConcreteType {
        unsafe { PxBase_getConcreteType(self.as_ptr()).into() }
    }

    /// Set or unset the specified flag on this object.
    fn set_base_flag(&mut self, flag: BaseFlag, value: bool) {
        unsafe {
            PxBase_setBaseFlag_mut(self.as_mut_ptr() as *mut _, flag, value);
        }
    }

    /// Set the BaseFlags of this object. Note that replaces all flags currently
    /// on the object. Use `set_base_flag` to set individual flags.
    fn set_base_flags(&mut self, in_flags: BaseFlags) {
        unsafe {
            PxBase_setBaseFlags_mut(self.as_mut_ptr() as *mut _, in_flags);
        }
    }

    /// Read the BaseFlags of this object
    fn get_base_flags(&self) -> BaseFlags {
        unsafe { PxBase_getBaseFlags(self.as_ptr() as *const _) }
    }

    ////////////////////////////////////////////////////////////////////////////////

    /// Returns true if this object can be released, i.e., it is not subordinate.
    fn is_releasable(&self) -> bool {
        unsafe { PxBase_isReleasable(self.as_ptr() as *const _) }
    }
}

impl<T> RefCounted for T where T: Class<PxRefCounted> + Sized {}

pub trait RefCounted: Class<PxRefCounted> + Sized {
    /// Decrements the reference count of the object and releases it if the new reference count is zero.
    #[inline]
    fn release(&mut self) {
        unsafe { PxRefCounted_release_mut(self.as_mut_ptr().cast()) }
    }

    /// Returns the reference count of the object.
    ///
    /// At creation, the reference count of the object is 1. Every other object
    /// referencing this object increments the count by 1. When the reference
    /// count reaches 0, and only then, the object gets destroyed automatically.
    fn get_reference_count(&self) -> u32 {
        unsafe { PxRefCounted_getReferenceCount(self.as_ptr().cast()) }
    }

    /// Acquires a counted reference to this object.
    ///
    /// This method increases the reference count of the object by 1. Decrement
    /// the reference count by calling [`Self::release`]
    fn acquire_reference(&mut self) {
        unsafe { PxRefCounted_acquireReference_mut(self.as_mut_ptr().cast()) }
    }
}
