use physx::{physics::PhysicsFoundationBuilder, prelude::*, traits::Class};
use std::ffi::CString;

type PxMaterial = physx::material::PxMaterial<()>;
type PxShape = physx::shape::PxShape<(), PxMaterial>;

struct ErrorCallback;

impl physx::physics::ErrorCallback for ErrorCallback {
    fn report_error(
        &self,
        code: enumflags2::BitFlags<physx::foundation::ErrorCode>,
        message: &str,
        file: &str,
        line: u32,
    ) {
        eprintln!("[{file:}:{line:}] {code:40}: {message:}");
    }
}
fn main() {
    // Holds a PxFoundation and a PxPhysics.
    // Also has an optional Pvd and transport, not enabled by default.
    // The default allocator is the one provided by PhysX.
    let mut builder = PhysicsFoundationBuilder::default();
    builder.with_error_callback(ErrorCallback);
    let mut physics: PhysicsFoundation<physx::foundation::DefaultAllocator, PxShape> =
        builder.build().expect("a foundation being built");

    unsafe {
        let error_callback =
            physx_sys::PxFoundation_getErrorCallback_mut(physics.foundation_mut().as_mut_ptr());
        let msg = CString::new("this is just a warning").unwrap();
        let file = CString::new(file!()).unwrap();

        physx_sys::PxErrorCallback_reportError_mut(
            error_callback,
            physx_sys::PxErrorCode::eDEBUG_WARNING,
            msg.as_ptr(),
            file.as_ptr(),
            line!() as _,
        );

        let msg = CString::new("this is an invalid operation").unwrap();
        physx_sys::PxErrorCallback_reportError_mut(
            error_callback,
            physx_sys::PxErrorCode::eINVALID_OPERATION,
            msg.as_ptr(),
            file.as_ptr(),
            line!() as _,
        );
    }
}
