use cmake::Config;
use std::env;
use std::ffi::OsString;
use std::path::PathBuf;

fn get_physx_target_os_name() -> String {
    let os = env::var("CARGO_CFG_TARGET_OS").unwrap();
    match os.as_str() {
        // CARGO_CFG_TARGET_OS uses "linux", "windows", and "macos"
        // PhysX uses "linux", "windows", and "mac"
        "macos" => "mac".to_owned(),
        _ => os,
    }
}

// Find the time of the most recent modification among all the files in a directory
fn most_recent_modification_time_in_dir(path: &PathBuf) -> Option<std::time::SystemTime> {
    use std::fs;

    fs::read_dir(&path).ok().and_then(|entries| {
        entries
            .filter_map(std::result::Result::ok)
            .filter_map(|entry| {
                let meta = entry.metadata().ok();
                meta.and_then(|meta| {
                    if meta.is_dir() {
                        None
                    } else {
                        meta.modified().ok()
                    }
                })
            })
            .max()
    })
}

// Get the sub-directory of the CMAKE build result which contains static libs.
// The CMAKE files in PhysX compute a compiler-dependent path, which can look like some of the following:
//
// "bin/linux.clang/debug"
// "bin/win.x86_64.vc141.md/debug"
// "bin/win.x86_64.vc142.md/profile"
// "bin/mac.x86_64/debug"
//
// In order not to have to replicate the CMAKE logic, we will inspect all paths with the structure
// "bin/*/debug" or "bin/*/profile", depending on the build profile passed to CMAKE.
// Among those directories, we choose the one containing the most recently modified files.
// This is to ensure that we find the correct folder even if it contains stale results from different compilers.
fn locate_output_lib_dir(mut cmake_build_out: PathBuf, build_profile: &str) -> String {
    use std::fs;

    // Always within the "bin" folder of the CMAKE output
    cmake_build_out.push("bin");

    if let Ok(entries) = fs::read_dir(&cmake_build_out) {
        // Get all sub-directories in "bin"
        let out_dirs = entries
            .filter_map(std::result::Result::ok)
            .filter(|entry| entry.metadata().map(|m| m.is_dir()).unwrap_or(false));

        // Find the ones containing "debug" or "profile", and pick the most recently modified.
        let out_dir = out_dirs
            .filter_map(|out_dir| {
                let mut out_dir = out_dir.path();
                out_dir.push(build_profile);

                let newest_in_dir = most_recent_modification_time_in_dir(&out_dir)?;
                Some((out_dir, newest_in_dir))
            })
            .max_by_key(|(_, m)| *m)
            .map(|(d, _)| d);

        out_dir
            .expect("could not locate output directory for PhysX static libs")
            .display()
            .to_string()
    } else {
        panic!("Could not inspect cmake build output directory");
    }
}

fn compile_physx() {}

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

    let target_os = get_physx_target_os_name();
    let target_os = target_os.as_str();
    let mut physx_cfg = Config::new("PhysX/physx/source/compiler/cmake");

    if target_os == "linux" {
        physx_cfg.define("CMAKE_LIBRARY_ARCHITECTURE", "x86_64-unknown-linux-gnu");
    }

    let linkage = env::var("CARGO_CFG_TARGET_FEATURE").unwrap_or_default();
    let crt_static = linkage.contains("crt-static");
    if crt_static {
        physx_cfg.define("NV_USE_STATIC_WINCRT", "True");
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
        .define("CMAKE_BUILD_TYPE", build_mode)
        .define("CMAKE_C_COMPILER_WORKS", "1")
        .define("CMAKE_CXX_COMPILER_WORKS", "1")
        .profile(build_mode);

    //if env::var("CARGO_FEATURE_NINJA").is_ok() {
    physx.generator("Ninja");
    //}

    let mut using_clang_cl = false;

    // If the user has explicitly specified the C/C++/linker variable(s), use
    // them instead of the defaults for the host platform. This is important,
    // especially for cross-compilation scenarios (eg clang-cl on linux to
    // compile for Windows)
    if let Ok(cxx) = env::var("CXX") {
        physx.define("CMAKE_CXX_COMPILER", &cxx);

        // If using clang-cl to pretend like we're using MSVC, physx uses a
        // CMAKE_CL_64 define for some reason, which cmake will faceplant on
        // when not using "actual" cl.exe, so force set it. If you're using the
        // 32-bit version of cl.exe....uhh fix this I guess? Note that this
        // (supposedly) is the arch of the actual cl.exe, not the host nor
        // target arch you are actually compiling on/for.
        if cxx.contains("clang-cl") && target_os == "windows" {
            physx
                .define("CMAKE_CL_64", "1")
                .define("PHYSX_AR", "llvm-lib");

            using_clang_cl = true;
        }
    }

    if let Ok(cc) = env::var("CC") {
        physx.define("CMAKE_C_COMPILER", &cc);
    }

    if let Ok(linker) = env::var("RUSTC_LINKER") {
        physx.define("CMAKE_LINKER", linker);
    }

    if let Ok(cxx_flags) = env::var("TARGET_CFLAGS") {
        physx.define("CMAKE_C_FLAGS", &cxx_flags);
    }

    if let Ok(cxx_flags) = env::var("TARGET_CXXFLAGS") {
        physx.define("PHYSX_CXX_FLAGS", &cxx_flags);
    }

    if let Ok(ar) = env::var("TARGET_AR") {
        physx.env("PHYSX_AR", ar);
    }

    let physx = physx.build();

    let lib_dir = locate_output_lib_dir(physx, build_mode);
    println!("cargo:rustc-link-search=native={}", lib_dir);

    println!("cargo:rustc-link-lib=static=PhysXVehicle_static_64");
    println!("cargo:rustc-link-lib=static=PhysX_static_64");
    println!("cargo:rustc-link-lib=static=PhysXCooking_static_64");
    println!("cargo:rustc-link-lib=static=PhysXPvdSDK_static_64");
    println!("cargo:rustc-link-lib=static=PhysXCommon_static_64");
    println!("cargo:rustc-link-lib=static=PhysXFoundation_static_64");
    println!("cargo:rustc-link-lib=static=PhysXCharacterKinematic_static_64");
    println!("cargo:rustc-link-lib=static=PhysXExtensions_static_64");

    let host = env::var("HOST").expect("HOST not set");

    // If we're cross compiling, we need to unset some environment variables, as
    // structgen is meant to be compiled and run on the current host only
    env::set_var("TARGET", &host);
    env::remove_var("CXX");
    env::remove_var("TARGET_CXXFLAGS");
    env::remove_var("TARGET_AR");

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

    physx_cc.flag(if physx_cc.get_compiler().is_like_msvc() {
        "/std:c++14"
    } else {
        "-std=c++14"
    });

    // We force clang++ on linux hosts since it appears some distros
    // *COUGH* UBUNTU *COUGH* use way too old versions of g++ which will
    // generally be picked up as the default C++ compiler over clang.
    // We only set this if CXX is _NOT_ set, as presumably the user will be
    // pointing at the compiler they actually want
    if (env::var("CXX").is_err() || using_clang_cl) && host.contains("-linux-") {
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
    eprintln!("RUNNING {:#?}", cmd);
    cmd.status().expect("c++ compiler failed to execute");

    // The above status check has been shown to fail, ie, the compiler
    // fails to output a binary, but reports success anyway
    if env::var("HOST")
        .map(|hs| hs.contains("-windows-"))
        .unwrap_or(false)
    {
        structgen_path.set_extension("exe");
    }

    std::fs::metadata(&structgen_path)
        .expect("failed to compile structgen even though compiler reported no failures");

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

    // Remove PxConfig.h since we're only allowed to modify OUT_DIR.
    let _ = std::fs::remove_file(physx_root_dir.join("include/PxConfig.h"));
}
