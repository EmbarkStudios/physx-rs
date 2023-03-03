fn gen_enums(which: &str, to_emit: &'static [&str]) -> anyhow::Result<String> {
    let (ast, _) = pxbind::get_parsed_ast(format!("tests/data/enum/{which}"))?;

    let mut consumer = pxbind::consumer::AstConsumer::default();
    consumer.consume(&ast)?;

    let generated = {
        let record_filter = |_rb: &pxbind::consumer::RecBinding<'_>| false;
        let enum_filter = |eb: &pxbind::consumer::EnumBinding<'_>| {
            to_emit.is_empty() || to_emit.iter().any(|te| *te == eb.name)
        };

        let generator = pxbind::generator::Generator {
            record_filter: Box::new(record_filter),
            enum_filter: Box::new(enum_filter),
            ..Default::default()
        };

        let mut buffer = Vec::new();
        generator.generate_rust_enums(&consumer, &mut buffer, 0)?;
        String::from_utf8(buffer)?
    };

    Ok(generated)
}

/// Verifies we can generate appropriate Rust enums for vanilla, i32 default C++ enums
#[test]
fn i32() {
    insta::assert_snapshot!(gen_enums("i32.h", &[]).unwrap());
}

/// Verifies we can generate appropriate Rust enums for C++ enums that have been
/// old school style forced to be u32
#[test]
fn u32() {
    insta::assert_snapshot!(gen_enums("u32.h", &[]).unwrap());
}

/// Verifies that enums not scoped to a struct can be parsed
#[test]
fn simple() {
    insta::assert_snapshot!(gen_enums("simple.h", &[]).unwrap());
}

/// Verifies that enums and their `PxFlags<>` wrappers can be properly bound
#[test]
fn flags() {
    insta::assert_snapshot!(gen_enums(
        "flags.h",
        &[
            "PxActorCacheFlag",
            "PxArticulationCacheFlag",
            "PxShapeFlag",
            "PxArticulationSensorFlag"
        ]
    )
    .unwrap());
}
