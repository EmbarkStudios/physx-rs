use std::ptr::{drop_in_place, NonNull};

use crate::traits::Class;

/// An owning wrapper around a pointer.  PhysX object creation returns pointers
/// which in normal Rust would be a Box, but Box cannot be used here because it
/// has specific allocation requirements that the C++ code does not fulfill.
#[repr(transparent)]
pub struct Owner<T> {
    ptr: NonNull<T>,
}

impl<T> Owner<T> {
    /// Create a new owner from a raw pointer.  Use the `from_raw` method on the type!
    ///
    /// # Safety
    /// Only one of these may be constructed per pointer.  In particular,
    /// this must not be called on a pointer attained via Class::as_mut_ptr.  The
    /// intended pattern is to wrap the raw FFI constructors in this call, so that
    /// the amount of time spent dealing with raw pointers is as little as possible.
    pub(crate) unsafe fn from_raw(ptr: *mut T) -> Option<Self> {
        Some(Self {
            ptr: NonNull::new(ptr)?,
        })
    }

    /// Consumes the Owner without calling Drop and returns the raw pointer it was wrapping.
    #[allow(clippy::mem_forget)]
    pub fn into_ptr<S>(mut self) -> *mut S
    where
        T: Class<S>,
    {
        let ptr = self.as_mut_ptr();
        std::mem::forget(self);
        ptr
    }
}

unsafe impl<T, S> Class<S> for Owner<T>
where
    T: Class<S>,
{
    fn as_ptr(&self) -> *const S {
        self.as_ref().as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut S {
        self.as_mut().as_mut_ptr()
    }
}

unsafe impl<T: Send> Send for Owner<T> {}
unsafe impl<T: Sync> Sync for Owner<T> {}

impl<T> Drop for Owner<T> {
    fn drop(&mut self) {
        unsafe { drop_in_place(self.ptr.as_ptr()) }
    }
}

impl<T> AsRef<T> for Owner<T> {
    fn as_ref(&self) -> &T {
        unsafe { self.ptr.as_ref() }
    }
}

impl<T> AsMut<T> for Owner<T> {
    fn as_mut(&mut self) -> &mut T {
        unsafe { self.ptr.as_mut() }
    }
}

impl<T> std::ops::Deref for Owner<T> {
    type Target = T;

    fn deref(&self) -> &Self::Target {
        self.as_ref()
    }
}

impl<T> std::ops::DerefMut for Owner<T> {
    fn deref_mut(&mut self) -> &mut Self::Target {
        self.as_mut()
    }
}
