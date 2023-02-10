struct RecordOutput {
    structgen: String,
    size_asserts: String,
    rust_decls: String,
}

fn gen_records(which: &str, to_emit: &'static [&str]) -> anyhow::Result<RecordOutput> {
    let ast = pxbind::get_parsed_ast(format!("tests/data/record/{which}"))?;

    let mut consumer = pxbind::consumer::AstConsumer::default();
    consumer.consume(&ast)?;

    let record_filter =
        |rb: &pxbind::consumer::RecBinding<'_>| to_emit.iter().any(|te| *te == rb.name);

    let generator = pxbind::generator::Generator {
        record_filter: Box::new(record_filter),
        ..Default::default()
    };

    let structgen = {
        let mut sg = Vec::new();
        generator.generate_structgen(&consumer, &mut sg)?;
        String::from_utf8(sg)?
    };

    let size_asserts = {
        let mut sa = Vec::new();
        generator.generate_size_asserts(&consumer, &mut sa)?;
        String::from_utf8(sa)?
    };

    let rust_decls = {
        let mut rd = Vec::new();
        generator.generate_rust_records(&consumer, &mut rd)?;
        String::from_utf8(rd)?
    };

    Ok(RecordOutput {
        structgen,
        size_asserts,
        rust_decls,
    })
}

/// Verifies that reference fields are reflected in the size and layout, but aren't
/// actually publicly exposed
#[test]
fn ref_fields() {
    let ro = gen_records("ref_fields.h", &["SupportLocal"]).unwrap();

    insta::assert_snapshot!(ro.structgen);
    insta::assert_snapshot!(ro.size_asserts);
    insta::assert_snapshot!(ro.rust_decls);
}
