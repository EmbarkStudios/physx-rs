use std::ffi::CStr;

use physx_sys::{create_assert_handler, ConstUserData, PxAssertHandler, UserData};

/// This represents the (deprecated) PxAssertHandler interface.
pub trait AssertHandler: Sized {
    /// Called as a result of a failed assert in PhysX.
    ///
    /// The `should_ignore` parameter is a static bool in C++ and can be used to disable asserts when received.
    fn on_assert(&self, expr: &str, file: &str, line: u32, should_ignore: &mut bool);

    /// # Safety
    ///
    /// Do not override this method.
    unsafe fn into_px(self) -> *mut PxAssertHandler {
        unsafe extern "C" fn on_message_shim<L: AssertHandler>(
            expr: *const i8,
            file: *const i8,
            line: u32,
            should_ignore: *mut bool,
            user_data: ConstUserData,
        ) {
            unsafe {
                let expr = CStr::from_ptr(expr.cast());
                let expr = expr.to_string_lossy();

                let file = CStr::from_ptr(file.cast());
                let file = file.to_string_lossy();

                let this = user_data.heap_data_ref::<L>();
                this.on_assert(&expr, &file, line, &mut *should_ignore);
            }
        }

        unsafe { create_assert_handler(on_message_shim::<Self>, UserData::new_on_heap(self)) }
    }
}
