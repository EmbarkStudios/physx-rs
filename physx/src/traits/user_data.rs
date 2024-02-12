use physx_sys::UserData;

/// `HasUserData` allows easy access and initialization of `void* userData` (in Rust, `UserData`)
/// fields on Px objects.
///
/// Not all Px objects with user data expose them as a field, so not all
/// objects with user data can use this. Objects which only allow getting the user data through
/// an accessor function cannot use this trait because returning a (mutable) reference to the
/// user data field itself isn't possible.
///
/// The default implementations try to exploit packing `UserData` into the space of the pointer
/// field itself. If `UserData` has larger size or alignment than a pointer, it will be stored
/// on the heap. Other implementations may modify this behavior to, for example, always store the
/// data on the heap, if it suits them. An example of this are the `Px__ControllerDesc` objects,
/// which will be used to create `Px__Controller`s that implement the `Controller` trait. That
/// `Controller` trait expects the user data to always be on the heap because it is one of the
/// objects for which user data is only accessible through an acessor method. As such, the
/// `Desc` objects must follow suit and always place the data on the heap.
pub trait HasUserData: Sized {
    type UserData;
    /// Returns a reference to the userData field
    fn user_data_ptr(&self) -> &UserData;

    /// Returns a mutable reference to the userData field.
    fn user_data_ptr_mut(&mut self) -> &mut UserData;

    /// Initialize the user data
    #[inline(always)]
    fn init_user_data(&mut self, user_data: Self::UserData) -> &mut Self {
        self.user_data_ptr_mut()
            .initialize_maybe_packed::<Self::UserData>(user_data);
        self
    }

    /// Drop and dealloc the user data
    ///
    /// # Safety
    ///
    /// The user data field must have previously been initialized via `init_user_data`
    #[inline(always)]
    unsafe fn drop_and_dealloc_user_data(&mut self) {
        // SAFETY: same as function-level safety
        unsafe {
            self.user_data_ptr_mut()
                .maybe_packed_drop_and_dealloc::<Self::UserData>()
        }
    }

    /// Get a shared ref to the user data, whether packed in the pointer or on the heap.
    ///
    /// # Safety
    ///
    /// The user data field must have previously been initialized via `init_user_data`.
    #[inline(always)]
    unsafe fn get_user_data(&self) -> &Self::UserData {
        // SAFETY: same as function-level safety
        unsafe {
            self.user_data_ptr()
                .maybe_packed_data_ref::<Self::UserData>()
        }
    }

    /// Get a mutable ref to the user data, whether packed in the pointer or on the heap.
    ///
    /// # Safety
    ///
    /// The user data field must have previously been initialized via `init_user_data`.
    #[inline(always)]
    unsafe fn get_user_data_mut(&mut self) -> &mut Self::UserData {
        // SAFETY: same as function-level safety
        unsafe {
            self.user_data_ptr_mut()
                .maybe_packed_data_mut::<Self::UserData>()
        }
    }
}

#[cfg(test)]
mod tests {
    use std::{fmt::Debug, marker::PhantomData};

    use physx_sys::UserData;

    use super::HasUserData;

    struct TestUserData<U> {
        user_data: UserData,
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

    impl<U> HasUserData for TestUserData<U> {
        type UserData = U;

        fn user_data_ptr(&self) -> &UserData {
            &self.user_data
        }

        fn user_data_ptr_mut(&mut self) -> &mut UserData {
            &mut self.user_data
        }
    }

    fn do_test<U: PartialEq + Clone + Debug>(user_data: U) {
        unsafe {
            let mut object: TestUserData<U> = TestUserData::default();
            object.init_user_data(user_data.clone());

            assert_eq!(HasUserData::get_user_data(&object), &user_data);
            assert_eq!(HasUserData::get_user_data_mut(&mut object), &user_data);

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
