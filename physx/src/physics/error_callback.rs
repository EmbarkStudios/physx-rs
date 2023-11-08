use physx_sys::{create_error_callback, ConstUserData, PxErrorCallback, PxErrorCode, UserData};
use std::ffi::CStr;

pub trait ErrorCallback: Sized {
    fn report_error(&self, code: PxErrorCode, message: &str, file: &str, line: u32);
    /// # Safety
    ///
    /// Do not override this method.
    unsafe fn into_px(self) -> *mut PxErrorCallback {
        unsafe extern "C" fn on_message_shim<L: ErrorCallback>(
            code: PxErrorCode,
            message: *const i8,
            file: *const i8,
            line: u32,
            user_data: ConstUserData,
        ) {
            unsafe {
                let msg = CStr::from_ptr(message.cast());
                let msg = msg.to_string_lossy();

                let file = CStr::from_ptr(file.cast());
                let file = file.to_string_lossy();

                let this = user_data.heap_data_ref::<L>();
                this.report_error(code, &msg, &file, line);
            }
        }

        unsafe { create_error_callback(on_message_shim::<Self>, UserData::new_on_heap(self)) }
    }
}
