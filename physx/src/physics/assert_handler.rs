use std::ffi::{c_void, CStr};

use physx_sys::{create_assert_handler, PxAssertHandler};

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
            this: *const c_void,
        ) {
            let this = &*this.cast::<L>();
            let expr = CStr::from_ptr(expr.cast());
            let expr = expr.to_string_lossy();

            let file = CStr::from_ptr(file.cast());
            let file = file.to_string_lossy();

            this.on_assert(&expr, &file, line, &mut *should_ignore);
        }

        create_assert_handler(
            on_message_shim::<Self>,
            Box::into_raw(Box::new(self)) as *mut c_void,
        )
    }
}
