use std::ffi::{c_void, CStr};

use enumflags2::BitFlags;
use physx_sys::{create_error_callback, PxErrorCallback};

use crate::foundation::ErrorCode;

pub trait ErrorCallback: Sized {
    fn report_error(&self, code: BitFlags<ErrorCode>, message: &str, file: &str, line: u32);
    /// # Safety
    ///
    /// Do not override this method.
    unsafe fn into_px(self) -> *mut PxErrorCallback {
        unsafe extern "C" fn on_message_shim<L: ErrorCallback>(
            code: physx_sys::PxErrorCode::Enum,
            message: *const i8,
            file: *const i8,
            line: u32,
            this: *const c_void,
        ) {
            let this = &*this.cast::<L>();
            let msg = CStr::from_ptr(message.cast());
            let msg = msg.to_str().unwrap(); // SAFETY: We're dealing with basic char* here, so should always convert cleanly to str.

            let file = CStr::from_ptr(file.cast());
            let file = file.to_str().unwrap(); // SAFETY: We're dealing with basic char* here, so should always convert cleanly to str.

            let code = if code == -1 {
                BitFlags::ALL
            } else {
                BitFlags::from_bits(code as u32).unwrap_or(ErrorCode::InvalidParameter.into())
            };

            this.report_error(code, msg, file, line);
        }

        create_error_callback(
            on_message_shim::<Self>,
            Box::into_raw(Box::new(self)) as *mut c_void,
        )
    }
}
