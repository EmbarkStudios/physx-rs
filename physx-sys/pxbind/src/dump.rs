use crate::Node;
use anyhow::Context as _;

pub fn get_repo_root() -> anyhow::Result<String> {
    let mut git = std::process::Command::new("git");
    git.args(["rev-parse", "--show-toplevel"]);
    git.stdout(std::process::Stdio::piped());
    let captured = git
        .output()
        .context("failed to run git to find repo root")?;

    let mut rr = String::from_utf8(captured.stdout).context("git output was non-utf8")?;
    // Removing trailing newline
    rr.pop();
    Ok(rr)
}

#[inline]
pub fn get_include_dir() -> anyhow::Result<String> {
    // Acquire the repo root so we don't need to care about where we are executing
    // this from (eg root, tests, wherever)
    let repo_root = get_repo_root()?;

    Ok(format!("{repo_root}/physx-sys/physx/physx/include"))
}

pub fn get_ast(header: impl AsRef<std::path::Path>) -> anyhow::Result<Vec<u8>> {
    let mut cmd = std::process::Command::new("clang++");

    let include_dir = get_include_dir()?;

    cmd.args([
        "-Xclang",
        // Requests the AST dump
        "-ast-dump=json",
        // We aren't actually compiling, just gathering type info
        "-fsyntax-only",
        // clang will complain about all physx headers when we are in C++
        // mode because it treats .h as "c headers", this is useless
        "-xc++-header",
        // Define PX_DEPRECATED so that the attribute is emitted into the AST
        "-DPX_DEPRECATED=__attribute__((deprecated()))",
        // Ignore all warnings, we don't care about C++ shenanigans
        "-w",
        // We don't want this
        "-DDISABLE_CUDA_PHYSX",
        "-fcolor-diagnostics",
        // Add the root include directory so that clang knows how to find
        // all of the includes
        "-I",
        &include_dir,
        // Sigh, physx asserts that this is defined :p
        "-DNDEBUG",
    ]);
    cmd.arg(header.as_ref());

    // note that this is _terribly_ slow but hopefully fixed in 1.69?
    // https://github.com/rust-lang/rust/issues/108223
    cmd.stdout(std::process::Stdio::piped());
    cmd.stderr(std::process::Stdio::piped());

    let captured = cmd
        .output()
        .context("failed to run clang++ to gather AST")?;

    anyhow::ensure!(
        captured.status.success(),
        "clang++ failed to gather AST {:?}\n{}",
        captured.status,
        String::from_utf8(captured.stderr).unwrap_or_default(),
    );

    Ok(captured.stdout)
}

/// Dump the AST of a header and all of its includes and parses it into a [`Node`]
pub fn get_parsed_ast(header: impl AsRef<std::path::Path>) -> anyhow::Result<(Node, Vec<u8>)> {
    log::info!("Gathering AST via clang...");
    let t = std::time::Instant::now();
    let ast = get_ast(header)?;
    log::info!("Gathered AST in {}ms", t.elapsed().as_millis());

    log::info!("Parsing AST...");
    let t = std::time::Instant::now();
    let root_node: Node = serde_json::from_slice(&ast).context("failed to parse AST")?;
    log::info!("Parsed AST in {}ms", t.elapsed().as_millis());
    Ok((root_node, ast))
}
