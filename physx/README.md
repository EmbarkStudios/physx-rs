# 🎳 physx

Early Rust crate that is intended to be a safe and easy to use high-level
wrapper for the unsafe `physx-sys` bindings.

This is a work in progress :construction:. This means that here be dragons, and
things might change often. The goal of this is to make ownership clearer and
leverage the safety of Rust even for an external package. At the same time, the
usage of `unsafe` helps clarify *where* danger lies, which helps us make better
choices when writing software.

Thus; the goal is not to remove all *unsafe* code, but rather to give us the
choice. The `physx-sys` crate still lets you break out of the safe-mode, and
this crate exposes some unsafe functionality where it makes sense. Some of these
usages will go away over time as we add more abstractions, while some will
get added to help build better software.

The overall goal is to maintain a close mapping to the underlying PhysX API
while improving safety and reliability of the code. This means, for example,
that we do not expose the `PxLoadExtensions()` function but rather attach this
to the [`Physics`](source/physics.rs) builder.

## Example

## Basic usage

``` rust
const PX_PHYSICS_VERSION: u32 = (4 << 24) + (1 << 16);
let mut foundation = Foundation::new(PX_PHYSICS_VERSION);

let mut physics = PhysicsBuilder::default()
    .load_extensions(false) // Flip this flag to load extensions during setup
    .build(&mut foundation);

let mut scene = physics.create_scene(
    SceneBuilder::default()
        .set_gravity(glm::vec3(0.0, -9.81, 0.0))
        .set_simulation_threading(SimulationThreadType::Dedicated(1)),
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

Since `PhysX` makes significant use of dynamic inheritance, there is no straightforward mapping to Rust code. To simulate the inheritance, we have a pointer-wrapper called
[`PxType`](src/px_type.rs) which does most of our heavy-lifting. Through type
specialization and macro-magic, we implement the functions on each wrapped type,
so the API for `PxRigidActor` is implemented in the specialization
`PxType<PxRgidiActor>`. Since this is a mouthful, we also define aliases for
most types by droppping the `Px`, giving us `RigidActor` in the above case.

This gets us halfway there, but still doesn't help with inheritance. To allow
calling the virtual functions, we also use the [*Deref
Pattern*](https://github.com/rust-unofficial/patterns/blob/master/anti_patterns/deref.md). This
is listed as an anti-pattern and rightly so, but after several iterations it is
the only one that has worked well for us. We also leverage this type for blanket
implementations to allow cross-type comparison and pointer comparisons.

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
