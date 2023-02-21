fn main() -> anyhow::Result<()> {
    // This is the root API include that includes all the other public APIs
    let api_h = format!("{}/PxPhysicsAPI.h", pxbind::get_include_dir()?);
    let root = pxbind::get_parsed_ast(api_h)?;

    let mut ast = pxbind::consumer::AstConsumer::default();
    ast.consume(&root)?;

    let rr: std::path::PathBuf = pxbind::get_repo_root()?.into();

    use std::fs::File;

    let mut structgen = File::create(rr.join("physx-sys/src/structgen/structgen2.cpp"))?;
    let mut cpp = File::create(rr.join("physx-sys/src/physx_generated2.hpp"))?;
    let mut rust = File::create(rr.join("physx-sys/src/physx_generated2.rs"))?;

    let generator = pxbind::generator::Generator::default();
    generator.generate_all(&ast, &mut structgen, &mut cpp, &mut rust)?;

    Ok(())
}
