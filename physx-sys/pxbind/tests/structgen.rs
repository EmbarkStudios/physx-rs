fn gen_structgen(_which: &str, to_emit: &'static [&str]) -> anyhow::Result<String> {
    let ast = pxbind::get_parsed_ast("../physx/physx/include/PxPhysicsAPI.h")?;

    let mut consumer = pxbind::consumer::AstConsumer::default();
    consumer.consume(&ast)?;

    let record_filter = |rb: &pxbind::consumer::RecBinding<'_>| {
        to_emit.is_empty() || to_emit.iter().any(|te| *te == rb.name)
    };

    let generator = pxbind::generator::Generator {
        record_filter: Box::new(record_filter),
        ..Default::default()
    };

    let structgen = {
        let mut sg = Vec::new();
        generator.generate_structgen(&consumer, &mut sg)?;
        String::from_utf8(sg)?
    };

    Ok(structgen)
}

fn run_structgen(sg: String) -> anyhow::Result<String> {
    let td = tempfile::tempdir()?;
    let sg_main = td.path().join("structgen.cpp");

    std::fs::write(&sg_main, sg)?;

    // Compile the structgen program for the host target
    let mut cmd = std::process::Command::new("clang++");
    cmd.current_dir(&td);
    cmd.args(["-static", "-o", "structgen"]);

    unreachable!()
}

#[test]
fn all_the_things() {
    let sg = gen_structgen("", &[]).unwrap();
    let generated = run_structgen(sg).unwrap();

    insta::assert_snapshot!(generated);
}
