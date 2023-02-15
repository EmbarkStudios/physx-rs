struct Functions {
    cpp: String,
    rust: String,
}

fn gen_functions(which: &str) -> anyhow::Result<Functions> {
    let ast = pxbind::get_parsed_ast(format!("tests/data/functions/{which}"))?;

    let mut consumer = pxbind::consumer::AstConsumer::default();
    consumer.consume(&ast)?;

    let record_filter = |_rb: &pxbind::consumer::RecBinding<'_>| false;
    let enum_filter = |_eb: &pxbind::consumer::EnumBinding<'_>| false;
    let func_filter = |fb: &pxbind::consumer::FuncBinding<'_>| {
        if fb.owning_class().is_some() {
            false
        } else {
            true
        }
    };

    let generator = pxbind::generator::Generator {
        record_filter: Box::new(record_filter),
        enum_filter: Box::new(enum_filter),
        func_filter: Box::new(func_filter),
        ..Default::default()
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

/// Verifies we can collect free functions
#[test]
fn plain_functions() {
    let mo = gen_functions("functions.h").unwrap();

    insta::assert_snapshot!(mo.cpp);
    insta::assert_snapshot!(mo.rust);
}
