# 🎳 Rust bindings for NVIDIA PhysX 4.1

Unsafe automatically-generated Rust bindings for [NVIDIA PhysX](https://github.com/NVIDIAGameWorks/PhysX) C++ API.

## Basic usage

```Rust
unsafe {
    let foundation = physx_create_foundation();
    let physics = physx_create_physics(foundation);

    let mut scene_desc = PxSceneDesc_new(PxPhysics_getTolerancesScale(physics));
    scene_desc.gravity = PxVec3 {
        x: 0.0,
        y: -9.81,
        z: 0.0,
    };

    let dispatcher = PxDefaultCpuDispatcherCreate(2, null_mut());

    scene_desc.cpuDispatcher = dispatcher as *mut PxCpuDispatcher;
    scene_desc.filterShader = Some(PxDefaultSimulationFilterShader);

    let scene = PxPhysics_createScene_mut(physics, &scene_desc);

    // Your physics simulation goes here
}
```

## Examples

### [Ball](examples/ball.rs)

A simple example to showcase how to use physx-sys. It can be run with `cargo run --examples ball`.

```
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

The binding is generated using a custom C++ app written against clang's [libtooling](https://clang.llvm.org/docs/LibTooling.html). It queries the compiler's abstract syntax tree, and translates the C++ PhysX types to Rust using heuristics chosen specifically for this SDK. It is not a general C++ <-> Rust binding generator, and using it on other projects *will* likely crash and burn.

TODO: Some high-level info about the two-stage generation and compilation.

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
