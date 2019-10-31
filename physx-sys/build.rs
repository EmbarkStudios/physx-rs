use cmake::Config;
use std::env;
use std::ffi::OsString;
use std::path::PathBuf;

#[cfg(debug_assertions)]
fn get_bin_dir() -> (&'static str, &'static str) {
    match env::var("CARGO_CFG_TARGET_OS").unwrap().as_str() {
        "linux" => ("linux", "bin/linux.clang/debug"),
        "windows" => ("windows", "bin/win.x86_64.vc141.md/debug"),
        "macos" => ("mac", "bin/mac.x86_64/debug"),
        p @ _ => panic!("Unsupported platform: {}", p),
    }
}

#[cfg(not(debug_assertions))]
fn get_bin_dir() -> (&'static str, &'static str) {
    match env::var("CARGO_CFG_TARGET_OS").unwrap().as_str() {
        "linux" => ("linux", "bin/linux.clang/profile"),
        "windows" => ("windows", "bin/win.x86_64.vc141.md/profile"),
        "macos" => ("mac", "bin/mac.x86_64/profile"),
        p @ _ => panic!("Unsupported platform: {}", p),
    }
}

fn main() {
    let physx_root_dir = env::current_dir().unwrap().join("PhysX/physx");
    let physx_parent_dir = physx_root_dir.parent().unwrap();

    // Based on PhysX/physx/generate_projects.sh
    env::set_var(
        "PHYSX_ROOT_DIR",
        &physx_root_dir.to_string_lossy().into_owned(),
    );
    env::set_var(
        "PM_PxShared_PATH",
        physx_parent_dir
            .join("pxshared")
            .to_string_lossy()
            .into_owned(),
    );
    env::set_var(
        "PM_CMakeModules_PATH",
        physx_parent_dir
            .join("externals/cmakemodules")
            .to_string_lossy()
            .into_owned(),
    );
    env::set_var(
        "PM_opengllinux_PATH",
        physx_parent_dir
            .join("externals/opengl-linux")
            .to_string_lossy()
            .into_owned(),
    );
    env::set_var("PM_PATHS", env::var("PM_opengllinux_PATH").unwrap());

    let output_dir = env::var("OUT_DIR").unwrap();
    let output_dir_path: PathBuf = output_dir.clone().into();

    let build_mode = if cfg!(debug_assertions) {
        "debug"
    } else {
        "profile"
    };

    let (target_os, bin_dir) = get_bin_dir();

    let mut physx_cfg = Config::new("PhysX/physx/source/compiler/cmake");

    match target_os {
        "linux" => {
            physx_cfg.define("CMAKE_LIBRARY_ARCHITECTURE", "x86_64-unknown-linux-gnu");
        }
        _ => {}
    }

    let physx = physx_cfg
        .define("PX_OUTPUT_LIB_DIR", &output_dir)
        .define("PX_OUTPUT_BIN_DIR", &output_dir)
        .define("PX_OUTPUT_ARCH", "x86")
        .define("PX_BUILDSNIPPETS", "False")
        .define("PX_BUILDSAMPLES", "False")
        .define("PX_GENERATE_STATIC_LIBRARIES", "True")
        .define("PX_GENERATE_GPU_PROJECTS", "False")
        .define("TARGET_BUILD_PLATFORM", target_os)
        .define("CMAKE_C_COMPILER", "clang")
        .define("CMAKE_CXX_COMPILER", "clang++")
        .define("CMAKE_BUILD_TYPE", build_mode)
        .profile(build_mode)
        .build();

    println!(
        "cargo:rustc-link-search=native={}",
        (physx.join(bin_dir)).display()
    );

    println!("cargo:rustc-link-lib=static=PhysXVehicle_static_64");
    println!("cargo:rustc-link-lib=static=PhysX_static_64");
    println!("cargo:rustc-link-lib=static=PhysXCooking_static_64");
    println!("cargo:rustc-link-lib=static=PhysXPvdSDK_static_64");
    println!("cargo:rustc-link-lib=static=PhysXCommon_static_64");
    println!("cargo:rustc-link-lib=static=PhysXFoundation_static_64");
    println!("cargo:rustc-link-lib=static=PhysXCharacterKinematic_static_64");
    println!("cargo:rustc-link-lib=static=PhysXExtensions_static_64");

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
        .include("PhysX/physx/source/foundation/include")
        .flag(if "windows" == target_os {
            "/std:c++14"
        } else {
            "-std=c++14"
        });

    // We force clang++ on linux hosts since it appears some distros
    // *COUGH* UBUNTU *COUGH* use way too old versions of g++ which will
    // generally be picked up as the default C++ compiler over clang.
    // This should be host_os, but we don't cross compile
    if target_os == "linux" {
        physx_cc.compiler("clang++");
    }

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
    if target_os == "windows" {
        structgen_path.set_extension("exe");
    }

    if !std::fs::metadata(&structgen_path).is_ok() {
        panic!("failed to compile structgen even though compiler reported no failures");
    }

    let mut structgen = std::process::Command::new(&structgen_path);
    structgen.current_dir(&output_dir_path);
    structgen.status().expect("structgen failed to execute");

    physx_cc
        .include(output_dir_path)
        .file("src/physx.cpp")
        .compile("physx_api");

    println!("cargo:rerun-if-changed=src/structgen/structgen.cpp");
    println!("cargo:rerun-if-changed=src/structgen/structgen.hpp");
    println!("cargo:rerun-if-changed=src/lib.rs");
    println!("cargo:rerun-if-changed=src/physx_generated.hpp");
    println!("cargo:rerun-if-changed=src/physx_generated.rs");
    println!("cargo:rerun-if-changed=src/physx.cpp");

    // TODO: use the cloned git revision number instead
    println!("cargo:rerun-if-changed=PhysX/physx/include/PxPhysicsVersion.h");
}
