use physx_sys::UserDataField;

/// UserData allows easy access and initialization of userData *mut c_void fields on Px objects.
/// Not all Px objects with user data expose them as a field, so not all objects with user data can use this.
///
/// # Safety
///
/// all constructors of implementing types must call `init_user_data` during construction.
/// If this does not happen, calling get_user_data or get_user_data_mut may return garbage data, or
/// dereference an invalid pointer.  If UserData is larger than a *mut ptr it will be stored on the heap,
/// and it may need to be explicitly dropped by turning the field back into a Box and dropping it.
/// If UserData implements Drop, this may be as simple as calling `get_user_data_mut` and then calling drop(),
/// but implementation is left to the concrete type's Drop impl.
pub unsafe trait UserData: Sized {
    type UserData;
    /// Returns a reference to the userData field
    fn user_data_ptr(&self) -> &UserDataField;

    /// Returns a mutable reference to the userData field.
    fn user_data_ptr_mut(&mut self) -> &mut UserDataField;

    #[inline(always)]
    fn init_user_data(&mut self, user_data: Self::UserData) -> &mut Self {
        self.user_data_ptr_mut().initialize_with_data::<Self::UserData>(user_data);
        self
    }

    /// # Safety
    ///
    /// The user data field must have previously been initialized via `init_user_data`
    #[inline(always)]
    unsafe fn drop_and_dealloc_user_data(&mut self) {
        // SAFETY: same as function-level safety
        unsafe { self.user_data_ptr_mut().drop_and_dealloc::<Self::UserData>() }
    }

    /// # Safety
    ///
    /// The user data field must have previously been initialized via `init_user_data`.
    #[inline(always)]
    unsafe fn get_user_data(&self) -> &Self::UserData {
        unsafe { self.user_data_ptr().data_ref::<Self::UserData>() }
    }

    /// # Safety
    ///
    /// The user data field must have previously been initialized via `init_user_data`.
    #[inline(always)]
    unsafe fn get_user_data_mut(&mut self) -> &mut Self::UserData {
        unsafe { self.user_data_ptr_mut().data_ref_mut::<Self::UserData>() }
    }
}

#[cfg(test)]
mod tests {
    use std::{fmt::Debug, marker::PhantomData};

    use physx_sys::UserDataField;

    use super::UserData;

    struct TestUserData<U> {
        user_data: UserDataField,
        phantom: PhantomData<U>,
    }

    impl<U> Default for TestUserData<U> {
        fn default() -> Self {
            Self {
                user_data: Default::default(),
                phantom: PhantomData,
            }
        }
    }

    unsafe impl<U> UserData for TestUserData<U> {
        type UserData = U;

        fn user_data_ptr(&self) -> &UserDataField {
            &self.user_data
        }

        fn user_data_ptr_mut(&mut self) -> &mut UserDataField {
            &mut self.user_data
        }
    }

    fn do_test<U: PartialEq + Clone + Debug>(user_data: U) {
        unsafe {
            let mut object: TestUserData<U> = TestUserData::default();
            object.init_user_data(user_data.clone());

            assert_eq!(UserData::get_user_data(&object), &user_data);
            assert_eq!(UserData::get_user_data_mut(&mut object), &user_data);

            object.drop_and_dealloc_user_data();
        }
    }

    #[repr(align(16))]
    #[derive(Debug, PartialEq, Eq, Clone, Copy)]
    struct WeirdZst([u128; 0]);

    // should be run through miri.
    // ```
    // $ cargo +nightly miri test user_data
    // ```
    #[test]
    fn test_user_data() {
        do_test(()); // unit type
        do_test(WeirdZst([])); // weird zst with high align
        do_test(100u8); // smaller than pointer
        do_test(100usize); // same size as pointer
        do_test(Box::new([1u8; 100])); // a pointer which should not leak
        do_test([100usize; 4]); // larger than pointer
    }
}
