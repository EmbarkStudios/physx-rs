use anyhow::Context as _;

fn main() -> anyhow::Result<()> {
    env_logger::init();

    // It takes clang++ around 30 seconds to dump the JSON, so just keep a file
    // around to reduce iteration times
    let root = if let Ok(json) = std::fs::read("ast-dump.json") {
        serde_json::from_slice(&json).context("failed to parse ast-dump.json")?
    } else {
        // This is the root API include that includes all the other public APIs
        let api_h = format!("{}/PxPhysicsAPI.h", pxbind::get_include_dir()?);
        let (root, raw) = pxbind::get_parsed_ast(api_h)?;

        std::fs::write("ast-dump.json", raw).context("failed to write ast-dump.json")?;

        root
    };

    let mut ast = pxbind::consumer::AstConsumer::default();
    ast.consume(&root)?;

    let rr: std::path::PathBuf = pxbind::get_repo_root()?.into();

    use std::fs::File;

    let mut structgen = File::create(rr.join("physx-sys/src/structgen/structgen.cpp"))?;
    let mut cpp = File::create(rr.join("physx-sys/src/physx_generated.hpp"))?;
    let mut rust = File::create(rr.join("physx-sys/src/physx_generated.rs"))?;

    let generator = pxbind::generator::Generator::default();
    generator.generate_all(&ast, &mut structgen, &mut cpp, &mut rust)?;

    Ok(())
}
