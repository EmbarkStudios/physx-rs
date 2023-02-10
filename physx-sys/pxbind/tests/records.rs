struct RecordOutput {
    structgen: String,
    //size_asserts: String,
    //rust_decls: String,
}

fn gen_records(which: &str) -> anyhow::Result<RecordOutput> {
    let ast = pxbind::get_parsed_ast(format!("tests/data/record/{which}"))?;

    let mut consumer = pxbind::consumer::AstConsumer::default();
    consumer.consume(&ast)?;

    let generator = pxbind::generator::Generator {};

    let structgen = {
        let mut sg = Vec::new();
        generator.generate_structgen(&consumer, &mut sg)?;
        String::from_utf8(sg)?
    };

    // let mut sa = Vec::new();
    // consumer.generate_size_asserts(&mut sa, 0)?;
    // let size_asserts = String::from_utf8(sa)?;

    // let mut rp = Vec::new();
    // consumer.generate_rust_pods(&mut rp, 0)?;
    // let rust_decls = String::from_utf8(rp)?;

    Ok(RecordOutput {
        structgen,
        //size_asserts,
        //rust_decls,
    })
}

/// Verifies that reference fields are reflected in the size and layout, but aren't
/// actually publicly exposed
#[test]
fn ref_fields() {
    let ro = gen_records("ref_fields.h").unwrap();

    insta::assert_snapshot!(ro.structgen);
    //insta::assert_snapshot!(ro.size_asserts);
    //insta::assert_snapshot!(ro.rust_decls);
}
