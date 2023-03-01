struct Functions {
    cpp: String,
    rust: String,
}

fn gen_functions(which: &str, to_emit: &'static [&str]) -> anyhow::Result<Functions> {
    let (ast, _) = pxbind::get_parsed_ast(format!("tests/data/functions/{which}"))?;

    let mut consumer = pxbind::consumer::AstConsumer::default();
    consumer.consume(&ast)?;

    let record_filter = |_rb: &pxbind::consumer::RecBinding<'_>| false;
    let enum_filter = |_eb: &pxbind::consumer::EnumBinding<'_>| false;
    let func_filter = |fb: &pxbind::consumer::FuncBinding<'_>| {
        if let Some(cname) = fb.owning_class() {
            to_emit.is_empty() || to_emit.iter().any(|te| *te == cname)
        } else {
            false
        }
    };

    let generator = pxbind::generator::Generator {
        record_filter: Box::new(record_filter),
        enum_filter: Box::new(enum_filter),
        func_filter: Box::new(func_filter),
    };

    let cpp = {
        let mut buffer = Vec::new();
        generator.generate_cpp_functions(&consumer, &mut buffer, 0)?;
        String::from_utf8(buffer)?
    };

    let rust = {
        let mut buffer = Vec::new();
        generator.generate_rust_functions(&consumer, &mut buffer, 0)?;
        String::from_utf8(buffer)?
    };

    Ok(Functions { cpp, rust })
}

/// Verifies that reference fields are reflected in the size and layout, but aren't
/// actually publicly exposed
#[test]
fn methods_complex() {
    let mo = gen_functions("methods_complex.h", &["PxShape", "PxThreadImpl"]).unwrap();

    insta::assert_snapshot!(mo.cpp);
    insta::assert_snapshot!(mo.rust);
}

/// Verifies constructors of various kinds are properly bound, and properly
/// named to avoid clashes
#[test]
fn constructors() {
    let mo = gen_functions("constructors.h", &["PxBoxControllerDesc", "PxFilterData"]).unwrap();

    insta::assert_snapshot!(mo.cpp);
    insta::assert_snapshot!(mo.rust);
}

/// Verifies destructors are properly emitted or omitted
#[test]
fn destructor() {
    let mo = gen_functions(
        "destructors.h",
        &[
            "PxActor",
            "PxJointLimitParameters",
            "PxJointAngularLimitPair",
        ],
    )
    .unwrap();

    insta::assert_snapshot!(mo.cpp);
    insta::assert_snapshot!(mo.rust);
}
