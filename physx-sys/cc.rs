impl Context {
    fn add_includes(&mut self, rel_root: &str, includes: &[&str]) -> &mut Self {
        let root = self.root.join(rel_root);
        self.includes
            .extend(includes.iter().map(|inc| root.join(inc)));

        self
    }

    fn add_sources(&mut self, rel_root: &str, files: &[&str]) -> &mut Self {
        let root = self.root.join(rel_root);
        self.builder.files(files.iter().map(|src| {
            let mut p = root.join(src);
            p.set_extension("cpp");
            p
        }));

        // Always add the src directory as an include as well
        self.includes.push(root);

        self
    }

    fn add_component(&mut self, name: &str, sources: &[&str]) -> &mut Self {
        let src_dir = format!("source/{}/src", name);
        self.add_sources(&src_dir, sources);

        let mut comproot = self.root.join("source");
        comproot.push(name);
        self.includes.push(comproot.join("include"));

        self
    }
}

macro_rules! component {
    ($name:ident) => {
        fn $name(ctx: &mut Context) {
            let sources = include!(concat!("sources/", stringify!($name)));
            ctx.add_component(stringify!($name), &sources);
        }
    };
}

component! {common}
component! {fastxml}
component! {lowlevelaabb}
component! {lowleveldynamics}
component! {physxcharacterkinematic}
component! {pvd}
component! {scenequery}
component! {simulationcontroller}
component! {task}

// The foundation component is really the only one that references platform
// specific compilands, so just calculate them here
fn foundation(ctx: &mut Context) {
    let sources = include!("sources/foundation");
    ctx.add_component("foundation", &sources);

    let target_family = env::var("CARGO_CFG_TARGET_FAMILY").expect("TARGET_FAMILY not specified");
    let sources = match target_family.as_str() {
        "unix" => &include!("sources/foundation_unix"),
        "windows" => &include!("sources/foundation_windows"),
        other => panic!("unknown TARGET_FAMILY '{}'", other),
    };

    ctx.add_sources(&format!("source/foundation/src/{}", target_family), sources);
}

fn lowlevel(ctx: &mut Context) {
    // API
    ctx.builder
        .file(ctx.root.join("source/lowlevel/api/src/px_globals.cpp"));

    // pipeline
    {
        let sources = include!("sources/lowlevel_pipeline");
        ctx.add_sources("source/lowlevel/common/src/pipeline", &sources);
    }

    // software, otherwise known as non-gpu
    {
        let sources = include!("sources/lowlevel_software");
        ctx.add_sources("source/lowlevel/software/src", &sources);
    }

    ctx.add_includes(
        "source/lowlevel",
        &[
            "api/include",
            "common/include/collision",
            "common/include/pipeline",
            "common/include/utils",
            "software/include",
        ],
    );
}

fn vehicle(ctx: &mut Context) {
    let sources = include!("sources/vehicle");
    ctx.add_component("physxvehicle", &sources);

    let sources = include!("sources/vehicle_metadata");
    ctx.add_sources("source/physxvehicle/src/physxmetadata/src", &sources);

    ctx.add_includes("source/physxvehicle/src/physxmetadata", &["include"]);
}

fn extensions(ctx: &mut Context) {
    let sources = include!("sources/extensions");
    ctx.add_component("physxextensions", &sources);

    // metadata
    ctx.add_sources(
        "source/physxmetadata/extensions/src",
        &["PxExtensionAutoGeneratedMetaDataObjects"],
    );

    // serialization
    let sources = include!("sources/extensions_serialization");
    ctx.add_sources("source/physxextensions/src/serialization", &sources);
    ctx.add_includes("source/physxextensions/src/serialization", &["File"]);

    // xml
    let sources = include!("sources/extensions_xml");
    ctx.add_sources("source/physxextensions/src/serialization/Xml", &sources);

    // binary
    let sources = include!("sources/extensions_binary");
    ctx.add_sources("source/physxextensions/src/serialization/Binary", &sources);

    ctx.add_includes("source/physxmetadata/extensions", &["include"]);
}

fn geomutils(ctx: &mut Context) {
    // root
    let sources = include!("sources/geomutils");
    ctx.add_sources("source/geomutils/src", &sources);
    ctx.add_includes("source/geomutils", &["include"]);

    // ccd
    let sources = include!("sources/geomutils_ccd");
    ctx.add_sources("source/geomutils/src/ccd", &sources);

    // common
    let sources = include!("sources/geomutils_common");
    ctx.add_sources("source/geomutils/src/common", &sources);

    // contact
    let sources = include!("sources/geomutils_contact");
    ctx.add_sources("source/geomutils/src/contact", &sources);

    // convex
    let sources = include!("sources/geomutils_convex");
    ctx.add_sources("source/geomutils/src/convex", &sources);

    // distance
    let sources = include!("sources/geomutils_distance");
    ctx.add_sources("source/geomutils/src/distance", &sources);

    // gjk
    let sources = include!("sources/geomutils_gjk");
    ctx.add_sources("source/geomutils/src/gjk", &sources);

    // hf
    let sources = include!("sources/geomutils_hf");
    ctx.add_sources("source/geomutils/src/hf", &sources);

    // intersection
    let sources = include!("sources/geomutils_intersection");
    ctx.add_sources("source/geomutils/src/intersection", &sources);

    // mesh
    let sources = include!("sources/geomutils_mesh");
    ctx.add_sources("source/geomutils/src/mesh", &sources);

    // pcm
    let sources = include!("sources/geomutils_pcm");
    ctx.add_sources("source/geomutils/src/pcm", &sources);

    // sweep
    let sources = include!("sources/geomutils_sweep");
    ctx.add_sources("source/geomutils/src/sweep", &sources);
}

fn cooking(ctx: &mut Context) {
    // root
    let sources = include!("sources/cooking");
    ctx.add_sources("source/physxcooking/src", &sources);
    ctx.add_includes("source/include", &["cooking"]);

    // mesh
    let sources = include!("sources/cooking_mesh");
    ctx.add_sources("source/physxcooking/src/mesh", &sources);

    // convex
    let sources = include!("sources/cooking_convex");
    ctx.add_sources("source/physxcooking/src/convex", &sources);

    // physx gates various cooking functionality with this define
    ctx.builder.define("PX_COOKING", None);
}

fn physx(ctx: &mut Context) {
    // metadata
    {
        let sources = ["PxAutoGeneratedMetaDataObjects", "PxMetaDataObjects"];
        ctx.add_sources("source/physxmetadata/core/src", &sources);
        ctx.add_includes("source", &["physxmetadata/core/include"]);
    }

    // immediate mode
    ctx.builder.file(
        ctx.root
            .join("source/immediatemode/src/NpImmediateMode.cpp"),
    );

    // buffering
    let sources = include!("sources/buffering");
    ctx.add_sources("source/physx/src/buffering", &sources);

    // there's always a "core"
    let sources = include!("sources/core");
    ctx.add_sources("source/physx/src", &sources);
}

fn add_common(ctx: &mut Context) {
    let shared_root = ctx.root.parent().unwrap().join("pxshared");

    let builder = &mut ctx.builder;
    let ccenv = &ctx.env;
    let root = &ctx.root;
    builder.cpp(true);

    // These includes are used by pretty much everything so just add them first
    ctx.includes.push(shared_root.join("include"));
    ctx.includes.extend(
        [
            "include",
            "source/foundation/include",
            "source/common/src",
            "source/filebuf/include", // only used by pvd
        ]
        .iter()
        .map(|inc| root.join(inc)),
    );

    // If we're targetting msvc, just silence all the annoying warnings
    if ccenv.target_env.as_deref() == Some("msvc") {
        builder
            .define("_CRT_SECURE_NO_WARNINGS", None)
            .define("_WINSOCK_DEPRECATED_NO_WARNINGS", None)
            .define("_ITERATOR_DEBUG_LEVEL", "0");
    }

    // Always build as a static library
    builder.define("PX_PHYSX_STATIC_LIB", None);
    // Always disable GPU features, at least for now
    builder.define("DISABLE_CUDA_PHYSX", None);

    if ccenv.emit_debug_info {
        builder.define("PX_DEBUG", None).define("PX_CHECKED", None);
    }

    builder.define("PX_SUPPORT_PVD", "1");

    // If we're on linux, we already require clang++ for structgen, for reasons,
    // so just force clang++ for the normal compile as well...except in the case
    // where a user has expliclity set CXX....
    // We _also_ set it explicitly for mac hosts, due to cc-rs's current
    // compiler detection, as macos uses cc still, but it's actually a symlink
    // to clang++, but that means that cc rs will by default think the compiler
    // is gcc
    if (ccenv.host.contains("-linux-") || ccenv.host == "x86_64-apple-darwin")
        && ccenv.target_compiler.is_none()
    {
        builder.compiler("clang++");
    }

    let flags = if builder.get_compiler().is_like_clang() {
        vec![
            "-std=c++14",
            "-ferror-limit=0",
            "-Wall",
            "-Wextra",
            "-Werror",
            "-Wstrict-aliasing=2",
            "-Weverything",
            "-Wno-documentation-deprecated-sync",
            "-Wno-documentation-unknown-command",
            "-Wno-gnu-anonymous-struct",
            "-Wno-undef",
            "-Wno-unused-function",
            "-Wno-nested-anon-types",
            "-Wno-float-equal",
            "-Wno-padded",
            "-Wno-weak-vtables",
            "-Wno-cast-align",
            "-Wno-conversion",
            "-Wno-missing-noreturn",
            "-Wno-missing-variable-declarations",
            "-Wno-shift-sign-overflow",
            "-Wno-covered-switch-default",
            "-Wno-exit-time-destructors",
            "-Wno-global-constructors",
            "-Wno-missing-prototypes",
            "-Wno-unreachable-code",
            "-Wno-unused-macros",
            "-Wno-unused-member-function",
            "-Wno-used-but-marked-unused",
            "-Wno-weak-template-vtables",
            "-Wno-deprecated",
            "-Wno-non-virtual-dtor",
            "-Wno-invalid-noreturn",
            "-Wno-return-type-c-linkage",
            "-Wno-reserved-id-macro",
            "-Wno-c++98-compat-pedantic",
            "-Wno-unused-local-typedef",
            "-Wno-old-style-cast",
            "-Wno-newline-eof",
            "-Wno-unused-private-field",
            "-Wno-format-nonliteral",
            "-Wno-implicit-fallthrough",
            "-Wno-undefined-reinterpret-cast",
            "-Wno-disabled-macro-expansion",
            "-Wno-zero-as-null-pointer-constant",
            "-Wno-shadow",
            "-Wno-unknown-warning-option",
            "-Wno-atomic-implicit-seq-cst",
            "-Wno-extra-semi-stmt",
        ]
    } else if builder.get_compiler().is_like_gnu() {
        vec!["-Wall -Werror -Wno-invalid-offsetof -Wno-uninitialized"]
    } else if builder.get_compiler().is_like_msvc() {
        // Disable defaults and force certain flags
        builder.no_default_flags(true);
        let mut flags = vec!["-nologo"];

        if ccenv.static_crt {
            flags.push("/MT");
        } else {
            flags.push("/MD");
        }

        if ccenv.emit_debug_info {
            flags.push("/Z7");
        }

        if ccenv.mode.as_str() == "profile" {
            flags.push("/O2");
        }

        flags.push("/std:c++14");

        flags.extend(["/WX", "/W4", "/GF", "/GS-", "/GR-", "/Gd"].iter());

        // Disable some warnings
        flags.extend(
            [
                "/wd4514", "/wd4820", "/wd4127", "/wd4710", "/wd4711", "/wd4577", "/wd4996",
            ]
            .iter(),
        );

        flags
    } else {
        vec![]
    };

    for flag in flags {
        builder.flag(flag);
    }

    builder.define("NDEBUG", "1");

    // if !builder.get_compiler().is_like_msvc() {
    //     match ccenv.mode.as_str() {
    //         "debug" => {
    //             builder.define("_DEBUG", "1");
    //         }
    //         "profile" => {

    //         }
    //         o => panic!("unknown mode '{}'", o),
    //     }
    // }

    // cc sets PIC by default for most targets, but if we're compiling with
    // clang for windows, we need to unset it, as clang (at least as of 9)
    // doesn't support it
    if builder.get_compiler().is_like_clang() && ccenv.target_os == "windows" {
        builder.pic(false);
    }
}

fn cc_compile(target_env: Environment) {
    let root = env::current_dir().unwrap().join("PhysX/physx");

    let ccenv = target_env;

    let mut ctx = Context {
        builder: cc::Build::new(),
        root,
        env: ccenv,
        includes: Vec::with_capacity(1000),
    };

    add_common(&mut ctx);

    // Add the sources and includes for each major physx component
    fastxml(&mut ctx);
    task(&mut ctx);
    foundation(&mut ctx);
    lowlevel(&mut ctx);
    lowlevelaabb(&mut ctx);
    lowleveldynamics(&mut ctx);
    vehicle(&mut ctx);
    extensions(&mut ctx);
    physxcharacterkinematic(&mut ctx);
    common(&mut ctx);
    geomutils(&mut ctx);
    cooking(&mut ctx);
    pvd(&mut ctx);
    physx(&mut ctx);
    scenequery(&mut ctx);
    simulationcontroller(&mut ctx);

    ctx.includes.push(ctx.root.join("source/pvd/include"));

    // Strip out duplicate include paths, C++ already has it hard enough as it is
    ctx.includes.sort();
    ctx.includes.dedup();

    for dir in ctx.includes {
        ctx.builder.include(dir);
    }

    ctx.builder.compile("physx");

    // if ctx.builder.get_compiler().is_like_msvc() {
    //     panic!("OK, WHAT HAVE WE HERE THEN");
    // }
}