use cmake::Config;

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
fn most_recent_modification_time_in_dir(path: &std::path::Path) -> Option<std::time::SystemTime> {
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

fn cmake_compile(target_env: Environment) {
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

    let target_os = get_physx_target_os_name();
    let target_os = target_os.as_str();
    let mut physx_cfg = Config::new("PhysX/physx/source/compiler/cmake");

    if target_os == "linux" {
        physx_cfg.define("CMAKE_LIBRARY_ARCHITECTURE", "x86_64-unknown-linux-gnu");
    }

    if target_env.static_crt {
        physx_cfg.define("NV_USE_STATIC_WINCRT", "True");
    }

    let compiler = target_env
        .target_compiler
        .unwrap_or_else(|| "clang++".to_owned());

    let physx = physx_cfg
        .define("PX_OUTPUT_LIB_DIR", &output_dir)
        .define("PX_OUTPUT_BIN_DIR", &output_dir)
        .define("PX_OUTPUT_ARCH", "x86")
        .define("PX_BUILDSNIPPETS", "False")
        .define("PX_BUILDSAMPLES", "False")
        .define("PX_GENERATE_STATIC_LIBRARIES", "True")
        .define("PX_GENERATE_GPU_PROJECTS", "False")
        .define("TARGET_BUILD_PLATFORM", target_os)
        // We don't care about the C compiler as it is never used for PhysX
        //.define("CMAKE_C_COMPILER", "clang")
        .define("CMAKE_CXX_COMPILER", compiler)
        .define("CMAKE_BUILD_TYPE", &target_env.mode)
        .profile(&target_env.mode)
        // Currently there's bugs when compiling with the latest clang.
        // See: https://github.com/NVIDIAGameWorks/PhysX/issues/321
        .cxxflag("-Wno-alloca")
        .cxxflag("-Wno-anon-enum-enum-conversion")
        .build();

    let lib_dir = locate_output_lib_dir(physx, &target_env.mode);
    println!("cargo:rustc-link-search=native={}", lib_dir);

    println!("cargo:rustc-link-lib=static=PhysXVehicle_static_64");
    println!("cargo:rustc-link-lib=static=PhysX_static_64");
    println!("cargo:rustc-link-lib=static=PhysXCooking_static_64");
    println!("cargo:rustc-link-lib=static=PhysXPvdSDK_static_64");
    println!("cargo:rustc-link-lib=static=PhysXCommon_static_64");
    println!("cargo:rustc-link-lib=static=PhysXFoundation_static_64");
    println!("cargo:rustc-link-lib=static=PhysXCharacterKinematic_static_64");
    println!("cargo:rustc-link-lib=static=PhysXExtensions_static_64");
}
