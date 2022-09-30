use physx_sys::{create_profiler_callback, PxProfilerCallback};
use std::ffi::c_void;

/// A trait for creating profiler callbacks for PhysX.
///
#[allow(clippy::missing_safety_doc)]
pub unsafe trait ProfilerCallback: Sized {
    /// # Safety
    ///
    /// The name is a static string. If detached, consider threading support of your allocators. Not all support
    /// cross-thread events.
    unsafe extern "C" fn zone_start(
        name: *const i8,
        detached: bool,
        context_id: u64,
        user_data: *const c_void,
    ) -> *mut c_void;

    /// # Safety
    ///
    /// The name is a static string. If detached, consider threading support of your allocators. Not all support
    /// cross-thread events. Context is the value return from `ProfilerCallback::zone_start`.
    unsafe extern "C" fn zone_end(
        context: *const c_void,
        name: *const i8,
        detached: bool,
        context_id: u64,
        user_data: *const c_void,
    );

    /// # Safety
    ///
    /// Do not override this method.
    unsafe fn into_px(self) -> *mut PxProfilerCallback {
        create_profiler_callback(
            Self::zone_start,
            Self::zone_end,
            Box::into_raw(Box::new(self)) as *mut c_void,
        )
    }
}
