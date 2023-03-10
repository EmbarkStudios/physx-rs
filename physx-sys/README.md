<div align="center">

# 🎳 physx-sys

**Unsafe automatically-generated Rust bindings for [NVIDIA PhysX 5.1](https://github.com/NVIDIA-Omniverse/PhysX) C++ API.**

![Build Status](https://github.com/EmbarkStudios/physx-rs/workflows/CI/badge.svg)
[![Crates.io](https://img.shields.io/crates/v/physx-sys.svg)](https://crates.io/crates/physx-sys)
[![Docs](https://docs.rs/physx-sys/badge.svg)](https://docs.rs/physx-sys)
[![Contributor Covenant](https://img.shields.io/badge/contributor%20covenant-v1.4%20adopted-ff69b4.svg)](../CODE_OF_CONDUCT.md)
[![Embark](https://img.shields.io/badge/embark-open%20source-blueviolet.svg)](http://embark.games)
[![Embark](https://img.shields.io/badge/discord-ark-%237289da.svg?logo=discord)](https://discord.gg/dAuKfZS)

</div>

Please also see the [repository](https://github.com/EmbarkStudios/physx-rs) containing a work-in-progress safe wrapper.

## Presentation

[Tomasz Stachowiak](https://github.com/h3r2tic) did a presentation at the Stockholm Rust Meetup on October 2019 about this project that goes through the technical details of how C++ to Rust bindings of `physx-sys` works:

[![An unholy fusion of Rust and C++ in physx-rs (Stockholm Rust Meetup, October 2019)](http://img.youtube.com/vi/RxtXGeDHu0w/0.jpg)](http://www.youtube.com/watch?v=RxtXGeDHu0w)

## Basic usage

```rust
unsafe {
    let foundation = physx_create_foundation();
    let physics = physx_create_physics(foundation);

    let mut scene_desc = PxSceneDesc_new(PxPhysics_getTolerancesScale(physics));
    scene_desc.gravity = PxVec3 {
        x: 0.0,
        y: -9.81,
        z: 0.0,
    };

    let dispatcher = phys_PxDefaultCpuDispatcherCreate(
        1,
        null_mut(),
        PxDefaultCpuDispatcherWaitForWorkMode::WaitForWork,
        0,
    );
    scene_desc.cpuDispatcher = dispatcher.cast();
    scene_desc.filterShader = get_default_simulation_filter_shader();

    let scene = PxPhysics_createScene_mut(physics, &scene_desc);

    // Your physics simulation goes here
}
```

## Examples

### [Ball](examples/ball.rs)

A simple example to showcase how to use physx-sys. It can be run with `cargo run --examples ball`.

```txt
 o

  o
   o

    o
                      ooooooooo
     o              oo         oo
                   o             o
      o           o               o
                 o                 oo
       o        o                    o
               o                                ooooooo
              o                       o       oo       oo
        o    o                         o    oo           oo
            o                           o  o               o    ooooooooo
         o                                o                 o oo         oooooooooo oo

```

## How it works

The binding is generated using a custom Rust app that parses the abstract syntax tree of the SDK, and maps the C++ PhysX functions and types to Rust using heuristics chosen specifically for this SDK. It is not a general C++ <-> Rust binding generator, and using it on other projects *will* likely crash and burn.

Since C++ does not have a standardized and stable ABI, it's generally not safe to call it from Rust code; since PhysX exposes a C++ interface, we can't use it directly. That's why `physx-sys` generates both a Rust interface as well as a plain C wrapper. The C code is compiled into a static library at build time, and Rust then talks to C.

In order to minimize the amount of work required to marshall data between the C wrapper and the original C++ API, we generate a **bespoke C wrapper for each build target**. The wrapper is based on metadata about structure layout extracted directly from compiling and running a tiny program against the PhysX SDK using the specific C++ compiler used in the build process.

The build process comprises a few steps:

1. The `pxbind` utility uses `clang` to extract metadata about PhysX functions and types, and generates partial Rust and C bindings as `physx_generated.hpp` and `physx_generated.rs`. Those contain all function definitions, and a small subset of types. It also generates a C++ utility called `structgen` by emitting `structgen.cpp`.
2. `structgen` is compiled against the PhysX SDK, and generates all the remaining type wrappers. For each struct, it queries the size and offset of its members, and generates `structgen_out.hpp` and `structgen_out.rs`. The types are "plain old data" structs which will perfectly match the memory layout of the C++ types.
3. All the generated C types are compiled together to form `physx_api`, a static library for Rust to link with.
4. The Rust wrapper is compiled, and linked with PhysX and the C wrapper.

Steps *2..4* are performed completely automatically from within `build.rs`, while step *1* is only necessary when upgrading the PhysX SDK or modifying the generator. As such, building and running `pxbind` is a manual task, and is currently only supported on \*nix systems.

## License

Licensed under either of

* Apache License, Version 2.0, ([LICENSE-APACHE](LICENSE-APACHE) or <http://www.apache.org/licenses/LICENSE-2.0>)
* MIT license ([LICENSE-MIT](LICENSE-MIT) or <http://opensource.org/licenses/MIT>)

at your option.

Note that the [PhysX C++ SDK](https://github.com/NVIDIA-Omniverse/PhysX) has its [own BSD 3 license](LICENSE-BSD).

### Contribution

Unless you explicitly state otherwise, any contribution intentionally
submitted for inclusion in the work by you, as defined in the Apache-2.0
license, shall be dual licensed as above, without any additional terms or
conditions.
