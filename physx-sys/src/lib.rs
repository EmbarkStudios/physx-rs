#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(clippy::unreadable_literal)]

//! # 🎳 physx-sys
//!
//! [![Build Status](https://travis-ci.com/EmbarkStudios/physx-rs.svg?branch=master)](https://travis-ci.com/EmbarkStudios/physx-rs)
//! [![Crates.io](https://img.shields.io/crates/v/physx-sys.svg)](https://crates.io/crates/physx-sys)
//! [![Docs](https://docs.rs/physx-sys/badge.svg)](https://docs.rs/physx-sys)
//! [![Contributor Covenant](https://img.shields.io/badge/contributor%20covenant-v1.4%20adopted-ff69b4.svg)](../CODE_OF_CONDUCT.md)
//! [![Embark](https://img.shields.io/badge/embark-open%20source-blueviolet.svg)](http://embark.games)
//!
//! Unsafe automatically-generated Rust bindings for [NVIDIA PhysX 4.1](https://github.com/NVIDIAGameWorks/PhysX) C++ API.
//!
//! Please also see the [repository](https://github.com/EmbarkStudios/physx-rs) containing a work-in-progress safe wrapper.
//!
//! ## Presentation
//!
//! [Tomasz Stachowiak](https://github.com/h3r2tic) did a presentation at the Stockholm Rust Meetup on October 2019
//! about this project that goes through the tecnical details of how C++ to Rust bindings of `physx-sys` works:
//!
//! [![](http://img.youtube.com/vi/RxtXGeDHu0w/0.jpg)](http://www.youtube.com/watch?v=RxtXGeDHu0w "An unholy fusion of
//! Rust and C++ in physx-rs (Stockholm Rust Meetup, October 2019)")
//!
//!
//! ## Basic usage
//!
//! ```Rust
//! unsafe {
//!     let foundation = physx_create_foundation();
//!     let physics = physx_create_physics(foundation);
//!
//!     let mut scene_desc = PxSceneDesc_new(PxPhysics_getTolerancesScale(physics));
//!     scene_desc.gravity = PxVec3 {
//!         x: 0.0,
//!         y: -9.81,
//!         z: 0.0,
//!     };
//!
//!     let dispatcher = PxDefaultCpuDispatcherCreate(2, null_mut());
//!
//!     scene_desc.cpuDispatcher = dispatcher as *mut PxCpuDispatcher;
//!     scene_desc.filterShader = Some(PxDefaultSimulationFilterShader);
//!
//!     let scene = PxPhysics_createScene_mut(physics, &scene_desc);
//!
//!     // Your physics simulation goes here
//! }
//! ```
//!
//! ## Examples
//!
//! ### [Ball](examples/ball.rs)
//!
//! A simple example to showcase how to use physx-sys. It can be run with `cargo run --examples ball`.
//!
//! ```
//!  o
//!
//!   o
//!    o
//!
//!     o
//!                       ooooooooo
//!      o              oo         oo
//!                    o             o
//!       o           o               o
//!                  o                 oo
//!        o        o                    o
//!                o                                ooooooo
//!               o                       o       oo       oo
//!         o    o                         o    oo           oo
//!             o                           o  o               o    ooooooooo
//!          o                                o                 o oo         oooooooooo oo
//!
//! ```
//!
//! ## How it works
//!
//! The binding is generated using a custom C++ app written against clang's
//! [libtooling](https://clang.llvm.org/docs/LibTooling.html). It queries the compiler's abstract syntax tree, and maps
//! the C++ PhysX functions and types to Rust using heuristics chosen specifically for this SDK. It is not a general
//! C++ <-> Rust binding generator, and using it on other projects *will* likely crash and burn.
//!
//! Since C++ does not have a standardized and stable ABI, it's generally not safe to call it from Rust code; since
//! PhysX exposes a C++ interface, we can't use it directly. That's why `physx-sys` generates both a Rust interface as
//! well as a plain C wrapper. The C code is compiled into a static library at build time, and Rust then talks to C.
//!
//! In order to minimize the amount of work required to marshall data between the C wrapper and the original C++ API, we
//! generate a **bespoke C wrapper for each build target**. The wrapper is based on metadata about structure layout
//! extracted directly from compiling and running a tiny program against the PhysX SDK using the specific C++ compiler
//! used in the build process.
//!
//! The build process comprises a few steps:
//!
//! 1. The `pxbind` utility uses `clang` to extract metadata about PhysX functions and types, and generates partial
//! Rust and C bindings as `physx_generated.hpp` and `physx_generated.rs`. Those contain all function definitions, and
//! a small subset of types. It also generates a C++ utility called `structgen` by emitting `structgen.cpp`.
//! 2. `structgen` is compiled against the PhysX SDK, and generates all the remaining type wrappers. For each struct, it
//! queries the size and offset of its members, and generates `structgen_out.hpp` and `structgen_out.rs`. The types are
//! "plain old data" structs which will perfectly match the memory layout of the C++ types.
//! 3. All the generated C types are compiled together to form `physx_api`, a static library for Rust to link with.
//! 4. The Rust wrapper is compiled, and linked with PhysX and the C wrapper.
//!
//! Steps *2..4* are performed completely automatically from within `build.rs`, while step *1* is only necessary when
//! upgrading the PhysX SDK or modifying the generator. As such, building and running `pxbind` is a manual task, and is
//! currently only supported on \*nix systems.
//!
//! ## License
//!
//! Licensed under either of
//!
//! * Apache License, Version 2.0, ([LICENSE-APACHE](LICENSE-APACHE) or http://www.apache.org/licenses/LICENSE-2.0)
//! * MIT license ([LICENSE-MIT](LICENSE-MIT) or http://opensource.org/licenses/MIT)
//!
//! at your option.
//!
//! Note that the [PhysX C++ SDK](https://github.com/NVIDIAGameWorks/PhysX) has it's
//! [own BSD 3 license](https://gameworksdocs.nvidia.com/PhysX/4.1/documentation/physxguide/Manual/License.html) and
//! depends on [additional C++ third party libraries](https://github.com/NVIDIAGameWorks/PhysX/tree/4.1/externals).
//!
//! ### Contribution
//!
//! Unless you explicitly state otherwise, any contribution intentionally
//! submitted for inclusion in the work by you, as defined in the Apache-2.0
//! license, shall be dual licensed as above, without any additional terms or
//! conditions.  

#[cfg(feature = "structgen")]
include!(concat!(env!("OUT_DIR"), "/structgen_out.rs"));

#[cfg(all(
    not(feature = "structgen"),
    target_os = "linux",
    target_arch = "x86_64",
))]
include!("generated/x86_64-unknown-linux/structgen.rs");

#[cfg(all(
    not(feature = "structgen"),
    target_os = "darwin",
    target_arch = "x86_64",
))]
include!("generated/x86_64-apple-darwin/structgen.rs");

#[cfg(all(
    not(feature = "structgen"),
    target_os = "windows",
    target_arch = "x86_64",
    target_env = "msvc",
))]
include!("generated/x86_64-pc-windows-msvc/structgen.rs");

include!("physx_generated.rs");

use std::ffi::c_void;

pub const fn version(major: u32, minor: u32, patch: u32) -> u32 {
    (major << 24) + (minor << 16) + (patch << 8)
}

pub type CollisionCallback =
    unsafe extern "C" fn(*mut c_void, *const PxContactPairHeader, *const PxContactPair, count: u32);

#[repr(C)]
pub struct FilterShaderCallbackInfo {
    pub attributes0: u32,
    pub attributes1: u32,
    pub filterData0: PxFilterData,
    pub filterData1: PxFilterData,
    pub pairFlags: *mut PxPairFlags,
    pub constantBlock: *const std::ffi::c_void,
    pub constantBlockSize: u32,
}

pub type SimulationFilterShader = unsafe extern "C" fn(*mut FilterShaderCallbackInfo) -> u16;

extern "C" {
    pub fn physx_create_foundation() -> *mut PxFoundation;
    pub fn physx_create_physics(foundation: *mut PxFoundation) -> *mut PxPhysics;
    pub fn get_default_allocator() -> *mut PxDefaultAllocator;
    pub fn get_default_error_callback() -> *mut PxDefaultErrorCallback;
    pub fn create_raycast_filter_callback(
        actor_to_ignore: *const PxRigidActor,
    ) -> *mut PxQueryFilterCallback;

    pub fn get_default_simulation_filter_shader() -> *mut c_void;

    /// Create a C++ proxy callback which will forward contact events to `Callback`.
    /// The returned pointer must be freed by calling `destroy_contact_callback` when done using.
    pub fn create_contact_callback(
        callback: CollisionCallback,
        userdata: *mut c_void,
    ) -> *mut PxSimulationEventCallback;

    /// Deallocates the PxSimulationEventCallback that has previously been created
    pub fn destroy_contact_callback(callback: *mut PxSimulationEventCallback);

    /// Override the default filter shader in the scene with a custom function.
    /// If call_default_filter_shader_first is set to true, this will first call the
    /// built-in PhysX filter (that matches Physx 2.8 behavior) before your callback.
    pub fn enable_custom_filter_shader(
        scene_desc: *mut PxSceneDesc,
        shader: SimulationFilterShader,
        call_default_filter_shader_first: u32,
    );
}
