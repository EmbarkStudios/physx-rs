use physx::{physics::PhysicsFoundationBuilder, prelude::*};
use std::ffi::CString;

type PxMaterial = physx::material::PxMaterial<()>;
type PxShape = physx::shape::PxShape<(), PxMaterial>;

struct AssertHandler;

impl physx::physics::AssertHandler for AssertHandler {
    fn on_assert(&self, expr: &str, file: &str, line: u32, should_ignore: &mut bool) {
        eprintln!("[{file:}:{line:}] Assertion failed: {expr:} ({should_ignore})");
        *should_ignore = true;
    }
}

fn main() {
    // Holds a PxFoundation and a PxPhysics.
    // Also has an optional Pvd and transport, not enabled by default.
    // The default allocator is the one provided by PhysX.
    let builder = PhysicsFoundationBuilder::default();
    let mut physics: PhysicsFoundation<physx::foundation::DefaultAllocator, PxShape> =
        builder.build().expect("a foundation being built");

    physics.set_assert_handler(AssertHandler);
    unsafe {
        let assert_handler = physx_sys::phys_PxGetAssertHandler();

        let expr = CString::new("1 != 2").unwrap();
        let file = CString::new(file!()).unwrap();

        let mut should_ignore = false;
        physx_sys::PxAssertHandler_opCall_mut(
            assert_handler,
            expr.as_ptr(),
            file.as_ptr(),
            line!() as _,
            &mut should_ignore as *mut _,
        );

        let expr = CString::new("false").unwrap();
        physx_sys::PxAssertHandler_opCall_mut(
            assert_handler,
            expr.as_ptr(),
            file.as_ptr(),
            line!() as _,
            &mut should_ignore as *mut _,
        );
    }
}
