fn gen_enums(which: &str) -> anyhow::Result<String> {
    let ast = pxbind::get_parsed_ast(format!("tests/data/enum/{which}"))?;

    let mut consumer = pxbind::consumer::AstConsumer::default();
    consumer.consume(&ast)?;

    let mut buffer = Vec::new();
    consumer.generate_rust_enums(&mut buffer, 0)?;

    Ok(String::from_utf8(buffer)?)
}

/// Verifies we can generate appropriate Rust enums for vanilla, i32 default C++ enums
#[test]
fn i32() {
    insta::assert_snapshot!(gen_enums("i32.h").unwrap());
}

/// Verifies we can generate appropriate Rust enums for C++ enums that have been
/// old school style forced to be u32
#[test]
fn u32() {
    insta::assert_snapshot!(gen_enums("u32.h").unwrap());
}

/// Verifies that enums not scoped to a struct can be parsed
#[test]
fn simple() {
    insta::assert_snapshot!(gen_enums("simple.h").unwrap());
}

/// Verifies that enums and their `PxFlags<>` wrappers can be properly bound
#[test]
fn flags() {
    insta::assert_snapshot!(gen_enums("flags.h").unwrap());
}
