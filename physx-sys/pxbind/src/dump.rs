use crate::Node;
use anyhow::Context as _;

pub fn get_ast(header: impl AsRef<std::path::Path>) -> anyhow::Result<Vec<u8>> {
    let mut cmd = std::process::Command::new("clang++");

    // Acquire the repo root so we don't need to care about where we are executing
    // this from (eg root, tests, wherever)
    let repo_root = {
        let mut git = std::process::Command::new("git");
        git.args(["rev-parse", "--show-toplevel"]);
        git.stdout(std::process::Stdio::piped());
        let captured = git
            .output()
            .context("failed to run git to find repo root")?;

        String::from_utf8(captured.stdout).context("git output was non-utf8")?
    };

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
        "-DPX_DPRECATED=__attribute__((deprecated()))",
        // Ignore the actual warning about deprecation, we don't care about
        // warnings
        "-Wno-deprecated-declarations",
        // Add the root include directory so that clang knows how to find
        // all of the includes
        "-I",
        &format!("{repo_root}/physx-sys/physx/physx/include"),
        // Sigh, physx asserts that this is defined :p
        "-DNDEBUG",
    ]);
    cmd.arg(header.as_ref());

    cmd.stdout(std::process::Stdio::piped());

    let captured = cmd
        .output()
        .context("failed to run clang++ to gather AST")?;

    anyhow::ensure!(
        captured.status.success(),
        "clang++ failed to gather AST {:?}",
        captured.status
    );

    Ok(captured.stdout)
}

/// Dump the AST of a header and all of its includes and parses it into a [`Node`]
pub fn get_parsed_ast(header: impl AsRef<std::path::Path>) -> anyhow::Result<Node> {
    let ast = get_ast(header)?;

    Ok(serde_json::from_slice(&ast).context("failed to parse AST")?)
}
