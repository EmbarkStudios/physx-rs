# 🎳 physx

![Build Status](https://github.com/EmbarkStudios/physx-rs/workflows/CI/badge.svg)
[![Crates.io](https://img.shields.io/crates/v/physx.svg)](https://crates.io/crates/physx)
[![Docs](https://docs.rs/physx/badge.svg)](https://docs.rs/physx)
[![Contributor Covenant](https://img.shields.io/badge/contributor%20covenant-v1.4%20adopted-ff69b4.svg)](../CODE_OF_CONDUCT.md)
[![Embark](https://img.shields.io/badge/embark-open%20source-blueviolet.svg)](http://embark.games)
[![Embark](https://img.shields.io/badge/discord-ark-%237289da.svg?logo=discord)](https://discord.gg/dAuKfZS)

[**This is a work in progress** 🚧](https://github.com/EmbarkStudios/physx-rs/issues/3)

`physx` is intended to be an easy to use high-level wrapper for the [`physx-sys`](https://crates.io/crates/physx) bindings. The goal of this is to make ownership clearer and leverage the safety of Rust.

The overall goal is to maintain a close mapping to the underlying PhysX API
while improving safety and reliability of the code. This means, for example,
that we do not expose the `PxLoadExtensions()` function but rather attach this
to the [`Physics`](src/physics.rs) builder.

Please also see the [repository](https://github.com/EmbarkStudios/physx-rs) containing an unsafe low-level binding.

## Example

## Basic usage

``` rust
let mut physics = PhysicsFoundation::default();

let mut scene = physics.create(
    SceneDescriptor {
        gravity: PxVec3::new(0.0, 0.0, -9.81),
        ..SceneDescriptor::new(MySceneUserData::default())
    }
);

// Your physics simulation goes here
```

For a full example, have a look at the [bouncing ball example](examples/ball_physx.rs)
and compare it to the [raw sys example](../physx-sys/examples/ball.rs).

## How it works

Wrapping a C++ API in Rust is not straightforward, and requires some extra steps
to work. The first, and most basic one is creating a C wrapper over the C++ API.
Using C as an intermediary allows us to leverage a stable ABI through which C++
and Rust can communicate. The `physx-sys` crate provides this interface.

`PhysX` makes significant use of inheritance, which isn't directly translatable to Rust.  The class interfaces are directly translated into traits with full default implementations that are just calls to the unsafe FFI functions.  These traits are bounded by their super class trait, as well as a `Class<T>` trait, where `T` is the class data struct found in `physx_sys`.  The class interface methods all take pointers to self, and the `Class<T>` trait provides `as_ptr` and `as_mut_ptr` methods to retrieve `*const` and `*mut` pointers to `T`.  Types that have a `userData` class member also have a `UserData` trait bound.

```Rust
trait RigidDynamic: RigidActor + Class<physx_sys::PxRigidDynamic> + UserData {
    fn get_sleep_threshold(&self) -> f32 {
        unsafe { PxRigidDynamic_getSleepThreshold(self.as_ptr()) }
    }
    // ...
}
```

## License

Licensed under either of

* Apache License, Version 2.0, ([LICENSE-APACHE](../LICENSE-APACHE) or http://www.apache.org/licenses/LICENSE-2.0)
* MIT license ([LICENSE-MIT](../LICENSE-MIT) or http://opensource.org/licenses/MIT)

at your option.

Note that the [PhysX C++ SDK](https://github.com/NVIDIAGameWorks/PhysX) has it's [own BSD 3 license](https://gameworksdocs.nvidia.com/PhysX/4.1/documentation/physxguide/Manual/License.html) and depends on [additional C++ third party libraries](https://github.com/NVIDIAGameWorks/PhysX/tree/4.1/externals).

### Contribution

Unless you explicitly state otherwise, any contribution intentionally
submitted for inclusion in the work by you, as defined in the Apache-2.0
license, shall be dual licensed as above, without any additional terms or
conditions.
