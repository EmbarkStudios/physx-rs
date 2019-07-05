# 🎳 physx-rs

[![Build Status](https://travis-ci.com/EmbarkStudios/physx-rs.svg?branch=master)](https://travis-ci.com/EmbarkStudios/physx-rs)

Rust binding and wrapper over [NVIDIA PhysX](https://github.com/NVIDIAGameWorks/PhysX), a popular and mature physics engine particularly well-suited for games.

Created and mantained by [Embark](http://embark.games) and _**not**_ officially supported by NVIDIA.

This repository contains 3 crates:

| Name | Description | Links |
| --- | --- | --- |
| [`physx`](physx/) | High-level interface on top of `physx-sys` 🚧 | [![Crates.io](https://img.shields.io/crates/v/physx.svg)](https://crates.io/crates/physx) [![Docs](https://docs.rs/physx/badge.svg)](https://docs.rs/physx) |
| [`physx-sys`](physx-sys/) | Unsafe bindings to the PhysX C++ API | [![Crates.io](https://img.shields.io/crates/v/physx-sys.svg)](https://crates.io/crates/physx-sys) [![Docs](https://docs.rs/physx-sys/badge.svg)](https://docs.rs/physx-sys) |
| [`physx-macros`](physx-macros/) | Utility macros used internally by the `physx` crate | [![Crates.io](https://img.shields.io/crates/v/physx-macros.svg)](https://crates.io/crates/physx-macros) [![Docs](https://docs.rs/physx-macros/badge.svg)](https://docs.rs/physx-macros) |

## Why?

* You want a feature-rich and performant physics engine to use in your project.

## Why not?

* It's a large C++ codebase which requires a C++ toolchain, and comes with a non-trivial build system.

* The high-level `physx` wrapper is work-in-progress, and only covers a part of PhysX functionality with a rust friendly interface.

### Alternatives

* [nphysics](https://github.com/rustsim/nphysics) a 2 and 3-dimensional physics engine for games and animations written in Rust.

## How?

The PhysX user guide can be found [here](https://gameworksdocs.nvidia.com/PhysX/4.1/documentation/physxguide/Manual/Introduction.html).

``` Rust
const PX_PHYSICS_VERSION: u32 = physx::version(4, 1, 0);
let mut foundation = Foundation::new(PX_PHYSICS_VERSION);

let mut physics = PhysicsBuilder::default()
    .load_extensions(false) // switch this flag to load extensions during setup
    .build(&mut foundation);

let mut scene = physics.create_scene(
    SceneBuilder::default()
        .set_gravity(glm::vec3(0.0, -9.81, 0.0))
        .set_simulation_threading(SimulationThreadType::Dedicated(1)),
);
```

Please refer to `physx` crate docs for more information. You can run an example with `cargo run --example ball`, which should show the following output:

![Example](images/example-ball.png)

## Prerequisites

* C++ compiler ([see the `cc` crate](https://crates.io/crates/cc) for requirements)
* CMake ([see the `cmake` crate](https://crates.io/crates/cmake) for requirements)

## License

Licensed under either of

* Apache License, Version 2.0, ([LICENSE-APACHE](LICENSE-APACHE) or http://www.apache.org/licenses/LICENSE-2.0)
* MIT license ([LICENSE-MIT](LICENSE-MIT) or http://opensource.org/licenses/MIT)

at your option.

### Contribution

Unless you explicitly state otherwise, any contribution intentionally
submitted for inclusion in the work by you, as defined in the Apache-2.0
license, shall be dual licensed as above, without any additional terms or
conditions.
