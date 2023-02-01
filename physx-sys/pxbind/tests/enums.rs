fn gen_enums(which: &str) -> anyhow::Result<String> {
    let ast = pxbind::get_ast(format!("tests/data/{which}"))?;
    std::fs::write(format!("tests/data/{which}.json"), ast)?;
    unreachable!();
}

/// Verifies we can generate appropriate Rust enums for vanilla, i32 default C++ enums
#[test]
fn i32() {
    gen_enums("i32.h").unwrap();
}

/// Verifies we can generate appropriate Rust enums for C++ enums that are use
#[test]
fn u32() {}
