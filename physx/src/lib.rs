// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created:  2 April 2019

#![warn(clippy::all)]
#![warn(rust_2018_idioms)]

//! # 🎳 physx
//!
//! ![Build Status](https://github.com/EmbarkStudios/physx-rs/workflows/CI/badge.svg)
//! [![Crates.io](https://img.shields.io/crates/v/physx.svg)](https://crates.io/crates/physx)
//! [![Docs](https://docs.rs/physx/badge.svg)](https://docs.rs/physx)
//! [![Contributor Covenant](https://img.shields.io/badge/contributor%20covenant-v1.4%20adopted-ff69b4.svg)](../CODE_OF_CONDUCT.md)
//! [![Embark](https://img.shields.io/badge/embark-open%20source-blueviolet.svg)](http://embark.games)
//!
//! [**This is a work in progress** 🚧](https://github.com/EmbarkStudios/physx-rs/issues/3)
//!
//! `physx` is intended to be an easy to use high-level wrapper for the [`physx-sys`](https://crates.io/crates/physx)
//! bindings. The goal of this is to make ownership clearer and leverage the safety of Rust.
//!
//! The overall goal is to maintain a close mapping to the underlying PhysX API while improving safety and reliability
//! of the code. This means, for example, that we do not expose the `PxLoadExtensions()` function but rather attach
//! this to the [`Physics`](source/physics.rs) builder.
//!
//! Please also see the [repository](https://github.com/EmbarkStudios/physx-rs) containing an unsafe low-level binding.
//!
//! ## Example
//!
//! ## Basic usage
//!
//! ``` rust
//! const PX_PHYSICS_VERSION: u32 = physx::version(4, 1, 1);
//! let mut foundation = Foundation::new(PX_PHYSICS_VERSION);
//!
//! let mut physics = PhysicsBuilder::default()
//!     .load_extensions(false) // Flip this flag to load extensions during setup
//!     .build(&mut foundation);
//!
//! let mut scene = physics.create_scene(
//!     SceneBuilder::default()
//!         .set_gravity(Vec3::new(0.0, -9.81, 0.0))
//!         .set_simulation_threading(SimulationThreadType::Dedicated(1)),
//! );
//!
//! // Your physics simulation goes here
//! ```
//!
//! For a full example, have a look at the [bouncing ball example](examples/ball_physx.rs)
//! and compare it to the [raw sys example](../physx-sys/examples/ball.rs).
//!
//! ## How it works
//!
//! Wrapping a C++ API in Rust is not straightforward, and requires some extra steps
//! to work. The first, and most basic one is creating a C wrapper over the C++ API.
//! Using C as an intermediary allows us to leverage a stable ABI through which C++
//! and Rust can communicate. The `physx-sys` crate provides this interface.
//!
//! Since `PhysX` makes significant use of inheritance, there is no straightforward mapping to Rust code. To simulate
//! the inheritance, we have a pointer-wrapper called [`PxType<T>`](src/px_type.rs). We implement the functions on each
//! wrapped `PxType<PxRgidiActor>` and expose an alias `RigidActor`.
//!
//! The [deref pattern](https://github.com/rust-unofficial/patterns/blob/master/anti_patterns/deref.md) is used to
//! simulate inheritance. For example `RigidBody::set_angular_damping`, can be called from the child `RigidDynamic`
//! because `RigidDynamic` implements `Deref<Target = RigidBody>`.
//!
//! ```Rust
//! // `set_angular_damping` is not defined in `RigidDynamic`, it is defined in `RidigBody`.
//! // This works because `Deref` is used to emulate inheritance.
//! let mut sphere_actor: RigidDynamic = unsafe { physics.create_dynamic(..) };
//! sphere_actor.set_angular_damping(0.5);
//! ```
//!
//! ```Rust
//! // The verbose example to show what happens behind the scenes.
//! let mut sphere_actor: RigidDynamic = unsafe { physics.create_dynamic(..) };
//! {
//!     // `RidigDynamic` implements `Deref/DerefMut` to a `RigidBody`.
//!     let sphere_actor: &mut RigidBody = &mut *sphere_actor;
//!     sphere_actor.set_angular_damping(0.5);
//! }
//! ```
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

// Utility traits
mod px_type;
pub mod traits;

// Utility data
pub mod user_data;

// Conversion utilities
pub mod math;
pub mod transform;

// Wrappers
pub mod actor;
pub mod articulation_base;
pub mod articulation_cache;
pub mod articulation_joint;
pub mod articulation_joint_base;
pub mod articulation_joint_reduced_coordinate;
pub mod articulation_link;
pub mod articulation_reduced_coordinate;
pub mod base;
pub mod body;
pub mod controller;
pub mod cooking;
pub mod foundation;
pub mod geometry;
pub mod heightfield;
pub mod physics;
pub mod rigid_actor;
pub mod rigid_body;
pub mod rigid_dynamic;
pub mod rigid_static;
pub mod scene;
pub mod shape;
pub mod visual_debugger;

pub mod prelude;
pub use physx_sys::version;
