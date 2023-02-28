fn gen_structgen(which: &str, _to_emit: &'static [&str]) -> anyhow::Result<String> {
    let (ast, _) = pxbind::get_parsed_ast(format!("tests/data/{which}"))?;

    let mut consumer = pxbind::consumer::AstConsumer::default();
    consumer.consume(&ast)?;

    let record_filter = |rb: &pxbind::consumer::RecBinding<'_>| rb.name().starts_with("Px");

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

struct StructgenOut {
    cpp: String,
    rust: String,
}

fn run_structgen(sg: String) -> anyhow::Result<StructgenOut> {
    let td = tempfile::tempdir()?;
    let tp = td.path();
    let sg_src = tp.join("structgen.cpp");

    std::fs::write(&sg_src, sg)?;
    std::fs::copy("tests/structgen.hpp", tp.join("structgen.hpp"))?;

    // Compile the structgen program for the host target
    let mut cmd = std::process::Command::new("clang++");
    cmd.current_dir(&td);

    let include_dir = pxbind::get_include_dir()?;
    cmd.args([
        "-fuse-ld=lld",
        "-std=c++11",
        "-fcolor-diagnostics",
        "-o",
        "structgen",
        "-DNDEBUG",
        "-I",
    ]);
    cmd.arg(include_dir);
    cmd.arg(&sg_src);

    anyhow::ensure!(cmd.status()?.success(), "failed to compile structgen");

    let mut sg = std::process::Command::new(tp.join("structgen"));
    sg.current_dir(tp);

    anyhow::ensure!(sg.status()?.success(), "failed to run structgen");

    let cpp = std::fs::read_to_string(tp.join("structgen_out.hpp"))?;
    let rust = std::fs::read_to_string(tp.join("structgen_out.rs"))?;

    Ok(StructgenOut { cpp, rust })
}

#[test]
fn many_things() {
    let sg = gen_structgen("functions/methods_complex.h", &[]).unwrap();

    insta::assert_snapshot!(sg);

    let generated = run_structgen(sg).unwrap();

    insta::assert_snapshot!(generated.cpp);
    insta::assert_snapshot!(generated.rust);
}

#[test]
fn all_the_things() {
    let sg = gen_structgen("all_the_things.h", &[]).unwrap();

    insta::assert_snapshot!(sg);

    let generated = run_structgen(sg).unwrap();

    insta::assert_snapshot!(generated.cpp);
    insta::assert_snapshot!(generated.rust);
}
