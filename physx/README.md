# 🎳 physx
This is a work in progress :construction:

`physx` is intended to be an easy to use high-level wrapper for the `physx-sys` bindings. The goal of this is to make ownership clearer and leverage the safety of Rust.
The goal is not to remove all *unsafe* code and this crate exposes some safe functionality where it makes sense. 

The overall goal is to maintain a close mapping to the underlying PhysX API
while improving safety and reliability of the code. This means, for example,
that we do not expose the `PxLoadExtensions()` function but rather attach this
to the [`Physics`](source/physics.rs) builder.

## Example

## Basic usage

``` rust
const PX_PHYSICS_VERSION: u32 = physx::version(4, 1, 0);
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

Since `PhysX` makes significant use of inheritance, there is no straightforward mapping to Rust code. To simulate the inheritance, we have a pointer-wrapper called [`PxType<T>`](src/px_type.rs). We implement the functions on each wrapped `PxType<PxRgidiActor>` and expose an alias `RigidActor`.

The [deref pattern](https://github.com/rust-unofficial/patterns/blob/master/anti_patterns/deref.md) is used to simulate inheritance.

```Rust
// `set_angular_damping` is not defined in `RigidDynamic`, it is defined in `RidigBody`.
// This works because `Deref` is used to emulate inheritance.
let mut sphere_actor: RigidDynamic = unsafe { physics.create_dynamic(..) };
sphere_actor.set_angular_damping(0.5);
```

```Rust
let mut sphere_actor: RigidDynamic = unsafe { physics.create_dynamic(..) };
{
    // `RidigDynamic` implements `Deref/DerefMut` to a `RigidBody`.
    let sphere_actor: &mut RigidBody = &mut *sphere_actor;
    sphere_actor.set_angular_damping(0.5);
}
```



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
