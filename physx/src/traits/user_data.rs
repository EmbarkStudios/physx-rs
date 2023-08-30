use std::{ffi::c_void, mem::size_of};

/// UserData allows easy access and initialization of userData *mut c_void fields on Px objects.
/// Not all Px objects with user data expose them as a field, so not all objects with user data can use this.
///
/// # Safety
///
/// all constructors of implementing types must call `init_user_data` during construction.
/// If this does not happen, calling get_user_data or get_user_data_mut may return garbage data, or
/// dereference an invalid pointer.  If UserData is larger than a *mut ptr it will be stored on the heap,
/// and it may need to be explicitly dropped by turning the field back into a Box and droppig it.
/// If UserData implements Drop, this may be as simple as calling `get_user_data_mut` and then calling drop(),
/// but implementation is left to the concrete type's Drop impl.
pub unsafe trait UserData: Sized {
    type UserData;
    /// Returns a reference to the userData field
    fn user_data_ptr(&self) -> &*mut c_void;
    /// Returns a mutable reference to the userData field.
    fn user_data_ptr_mut(&mut self) -> &mut *mut c_void;

    unsafe fn init_user_data(&mut self, user_data: Self::UserData) -> &mut Self {
        if size_of::<Self::UserData>() > size_of::<*mut c_void>() {
            // Too big to pack into a *mut c_void, kick it to the heap.
            let data = Box::into_raw(Box::new(user_data));
            *(self.user_data_ptr_mut() as *mut *mut c_void as *mut *mut Self::UserData) = data;
        } else {
            // DATA_SIZE <= VOID_SIZE
            *(self.user_data_ptr_mut() as *mut *mut c_void as *mut Self::UserData) = user_data;
        }
        self
    }

    /// # Safety
    ///
    /// The user data field must have previously been initialized via `init_user_data`.
    unsafe fn get_user_data(this: &Self) -> &Self::UserData {
        unsafe {
            if size_of::<Self::UserData>() > size_of::<*mut c_void>() {
                &*((*this.user_data_ptr()) as *const Self::UserData)
            } else {
                // DATA_SIZE <= VOID_SIZE
                // Data is stored directly in the userData field.
                &*(this.user_data_ptr() as *const *mut c_void as *const Self::UserData)
            }
        }
    }

    /// # Safety
    ///
    /// The user data field must have previously been initialized via `init_user_data`.
    unsafe fn get_user_data_mut(this: &mut Self) -> &mut Self::UserData {
        unsafe {
            if size_of::<Self::UserData>() > size_of::<*mut c_void>() {
                // Data is stored in a Box<UserData> on the heap, and userData is just a pointer to it.
                &mut *((*this.user_data_ptr_mut()) as *mut Self::UserData)
            } else {
                // DATA_SIZE <= VOID_SIZE
                // Data is stored directly in the userData field.
                &mut *(this.user_data_ptr_mut() as *mut *mut c_void as *mut Self::UserData)
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use std::{ffi::c_void, fmt::Debug, marker::PhantomData, ptr::null_mut};

    use super::UserData;

    struct TestUserData<U> {
        user_data: *mut c_void,
        phantom: PhantomData<U>,
    }

    impl<U> Default for TestUserData<U> {
        fn default() -> Self {
            Self {
                user_data: null_mut(),
                phantom: PhantomData,
            }
        }
    }

    unsafe impl<U> UserData for TestUserData<U> {
        type UserData = U;

        fn user_data_ptr(&self) -> &*mut c_void {
            &self.user_data
        }

        fn user_data_ptr_mut(&mut self) -> &mut *mut c_void {
            &mut self.user_data
        }
    }

    fn do_test<U: PartialEq + Clone + Debug>(user_data: U) {
        unsafe {
            let mut object: TestUserData<U> = TestUserData::default();
            object.init_user_data(user_data.clone());

            assert_eq!(UserData::get_user_data(&object), &user_data);
            assert_eq!(UserData::get_user_data_mut(&mut object), &user_data);
        }
    }

    #[test]
    fn test_user_data() {
        do_test(()); // unit type
        do_test(100u8); // smaller than pointer
        do_test(100usize); // same size as pointer
        do_test([100usize; 4]); // larger than pointer
    }
}
