use std::{env, path::PathBuf};

struct Environment {
    host: String,
    emit_debug_info: bool,
    target_os: String,
    //target_arch: String,
    target_env: Option<String>,
    mode: String,
    target_compiler: Option<String>,
    //target_linker: Option<String>,
    static_crt: bool,
}

struct Context {
    root: PathBuf,
    builder: cc::Build,
    env: Environment,
    includes: Vec<PathBuf>,
}

include!("cc.rs");
include!("cmake.rs");

fn main() {
    // Use the optimization level to determine the build profile to pass, we
    // don't use cfg!(debug_assertions) here because I'm not sure what happens
    // with that when build dependencies are configured to be debug and the
    // actual target is meant to be release, so this seems safer
    let build_mode = match env::var("OPT_LEVEL")
        .ok()
        .and_then(|s| s.parse::<i32>().ok())
        .unwrap_or(1)
    {
        0 => "debug",
        _ => "profile",
    };

    let use_cmake = env::var("CARGO_FEATURE_USE_CMAKE").is_ok();

    let host = env::var("HOST").expect("HOST not specified");

    {
        let target_compiler = env::var("CXX").ok();
        let target_os = env::var("CARGO_CFG_TARGET_OS").expect("target os not specified");
        let target_env = env::var("CARGO_CFG_TARGET_ENV").ok();
        let static_crt = env::var("CARGO_CFG_TARGET_FEATURE")
            .unwrap_or_default()
            .contains("crt-static");

        let environment = Environment {
            emit_debug_info: env::var("DEBUG")
                .ok()
                .and_then(|s| s.parse::<bool>().ok())
                .unwrap_or(false),
            //target_arch,
            //target_linker,
            target_os,
            target_env,
            target_compiler,
            mode: build_mode.to_owned(),
            host: host.clone(),
            static_crt,
        };

        if use_cmake {
            cmake_compile(environment);
        } else {
            cc_compile(environment)
        }
    }

    let mut cc_builder = cc::Build::new();
    let physx_cc = cc_builder
        .cpp(true)
        .opt_level(3)
        .debug(false)
        .use_plt(false)
        .warnings(false)
        .extra_warnings(false)
        .define("NDEBUG", None)
        .define("PX_PHYSX_STATIC_LIB", None)
        .include("PhysX/physx/include")
        .include("PhysX/pxshared/include")
        .include("PhysX/physx/source/foundation/include");

    if env::var("CXX").is_err() && host.contains("-linux-") {
        physx_cc.compiler("clang++");
    }

    physx_cc.flag(if physx_cc.get_compiler().is_like_msvc() {
        "/std:c++14"
    } else {
        "-std=c++14"
    });

    use std::ffi::OsString;
    let output_dir_path =
        PathBuf::from(env::var("OUT_DIR").expect("output directory not specified"));

    let include_path = if env::var("CARGO_FEATURE_STRUCTGEN").is_ok() {
        let mut structgen_path = output_dir_path.join("structgen");

        let structgen_compiler = physx_cc.get_compiler();
        let mut cmd = structgen_compiler.to_command();
        if structgen_compiler.is_like_msvc() {
            let mut s = OsString::from("/Fe");
            s.push(&structgen_path);
            cmd.arg(s);

            let mut s = OsString::from("/Fo");
            s.push(&structgen_path);
            s.push(".obj");
            cmd.arg(s);
        } else {
            cmd.arg("-o").arg(&structgen_path);
        }

        cmd.arg("src/structgen/structgen.cpp");
        cmd.status().expect("c++ compiler failed to execute");

        // The above status check has been shown to fail, ie, the compiler
        // fails to output a binary, but reports success anyway
        if host.contains("-windows-") {
            structgen_path.set_extension("exe");
        }

        std::fs::metadata(&structgen_path)
            .expect("failed to compile structgen even though compiler reported no failures");

        let mut structgen = std::process::Command::new(&structgen_path);
        structgen.current_dir(&output_dir_path);
        structgen.status().expect("structgen failed to execute");

        output_dir_path
    } else {
        let target = env::var("TARGET").expect("TARGET not specified");
        let mut include = PathBuf::from("src/generated");

        match target.as_str() {
            "x86_64-apple-darwin" | "x86_64-pc-windows-msvc" => {
                include.push(target);
            }
            nix if nix.starts_with("x86_64-unknown-linux") => {
                include.push("x86_64-unknown-linux");
            }
            _ => panic!("unknown TARGET triple '{}'", target),
        }

        include
    };

    if physx_cc.get_compiler().is_like_msvc() && !use_cmake {
        physx_cc.flag("/MD");
    }

    physx_cc
        .include(include_path)
        .file("src/physx_api.cpp")
        .compile("physx_api");

    // if physx_cc.get_compiler().is_like_msvc() && !use_cmake {
    //     panic!("If /MD isn't in the compile options....");
    // }

    println!("cargo:rerun-if-changed=src/structgen/structgen.cpp");
    println!("cargo:rerun-if-changed=src/structgen/structgen.hpp");
    println!("cargo:rerun-if-changed=src/lib.rs");
    println!("cargo:rerun-if-changed=src/physx_generated.hpp");
    println!("cargo:rerun-if-changed=src/physx_generated.rs");
    println!("cargo:rerun-if-changed=src/physx_apicpp");

    // TODO: use the cloned git revision number instead
    println!("cargo:rerun-if-changed=PhysX/physx/include/PxPhysicsVersion.h");

    // Remove PxConfig.h since we're only allowed to modify OUT_DIR.
    if use_cmake {
        let _ = std::fs::remove_file(
            env::current_dir()
                .unwrap()
                .join("PhysX/physx/include/PxConfig.h"),
        );
    }
}
