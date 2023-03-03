# physx-sys 4.1 -> 5.1 migration guide

This is a migration guide for the physx-sys crate from the version (0.8.*) that was wrapping PhysX SDK 4.1, and the version (0.10) that transition to PhysX SDK 5.1.3. (see [PR#183] for the PR that actually made a bulk of the transition)

Note that there is a migration guide from NVidia for the C++ code [here](https://nvidia-omniverse.github.io/PhysX/physx/5.1.3/docs/MigrationTo51.html).

## General Changes

### `pxbind`

The pxbind program, used to query the C++ AST and generate both the FFI binding functions in Rust and their C++ implementation, as well as the structgen program used to generate the POD types used on both sides of the FFI boundary, has been rewritten from C++ to Rust. This was done to get rid of the annoying dependency on libclang and just...not have C++ code that had bitrotted since the original implementation. Transitioning to Rust means it should be easier for contributors to make changes to the binding generation and just iterate on and improve the generated binding code. This change is not directly visible to end users of the crate, it is just mentioned since it makes up a large part of the new code in [PR#183].

### Enums

Enums exposed by physx-sys have been changed to be more Rust like. We'll use [`PxShapeFlag`](https://github.com/EmbarkStudios/PhysX-5/blob/main/physx/include/PxShape.h#L62-L119) to illustrate the changes.

#### Old enum output

```rust
pub mod PxShapeFlag{
pub type Enum = u32;
pub const eSIMULATION_SHAPE: Enum = 1u64 as u32;
pub const eSCENE_QUERY_SHAPE: Enum = 2u64 as u32;
pub const eTRIGGER_SHAPE: Enum = 4u64 as u32;
pub const eVISUALIZATION: Enum = 8u64 as u32;
}
```

#### New enum output

```rust
/// Flags which affect the behavior of PxShapes.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
#[repr(i32)]
pub enum PxShapeFlag {
    /// The shape will partake in collision in the physical simulation.
    ///
    /// It is illegal to raise the eSIMULATION_SHAPE and eTRIGGER_SHAPE flags.
    /// In the event that one of these flags is already raised the sdk will reject any
    /// attempt to raise the other.  To raise the eSIMULATION_SHAPE first ensure that
    /// eTRIGGER_SHAPE is already lowered.
    ///
    /// This flag has no effect if simulation is disabled for the corresponding actor (see [`PxActorFlag::eDISABLE_SIMULATION`]).
    SimulationShape = 1,
    /// The shape will partake in scene queries (ray casts, overlap tests, sweeps, ...).
    SceneQueryShape = 2,
    /// The shape is a trigger which can send reports whenever other shapes enter/leave its volume.
    ///
    /// Triangle meshes and heightfields can not be triggers. Shape creation will fail in these cases.
    ///
    /// Shapes marked as triggers do not collide with other objects. If an object should act both
    /// as a trigger shape and a collision shape then create a rigid body with two shapes, one being a
    /// trigger shape and the other a collision shape. It is illegal to raise the eTRIGGER_SHAPE and
    /// eSIMULATION_SHAPE flags on a single PxShape instance.  In the event that one of these flags is already
    /// raised the sdk will reject any attempt to raise the other.  To raise the eTRIGGER_SHAPE flag first
    /// ensure that eSIMULATION_SHAPE flag is already lowered.
    ///
    /// Trigger shapes will no longer send notification events for interactions with other trigger shapes.
    ///
    /// Shapes marked as triggers are allowed to participate in scene queries, provided the eSCENE_QUERY_SHAPE flag is set.
    ///
    /// This flag has no effect if simulation is disabled for the corresponding actor (see [`PxActorFlag::eDISABLE_SIMULATION`]).
    TriggerShape = 4,
    /// Enable debug renderer for this shape
    Visualization = 8,
}
```

#### Enum differences

1. Enums are now regular Rust enums, rather than modules.
1. Enum variants now named in `UpperCamelCase` like standard Rust enum variants (minus the `e` suffix)
1. Enums now have the documentation for the enum itself, as well as each variant, pulled from the C++ declaration

#### Migrating enums

Migrating enums is trivial in most cases as it is just a matter of renaming the variant from the C++ name to the new form. In the case the type itself is used, it's just a matter of removing the `::Enum` from the type.

```diff
PxShape_setFlag_mut(
    shape,
-   PxShapeFlag::eVISUALIZATION,
+   PxShapeFlag::Visualization,
    enable_physics_shape_debug_rendering,
);

-fn is_flag_enabled(shape: *const PxShape, flag: PxShapeFlag::Enum) -> bool {
+fn is_flag_enabled(shape: *const PxShape, flag: PxShapeFlag) -> bool {
```

One wrinkle with this new form is that converting to and from integer types is not as easy. If this is problematic we can add generation of `From` for 1 or more integer types for enums.

### Flags

PhysX uses bitsets fairly heavily in the API, using `PxFlags<_enum_type_, _integer_type_>` to create wrappers for an enum. We'll use [`PxShapeFlags`](https://github.com/EmbarkStudios/PhysX-5/blob/6efb3c60eb7869e8f9d694a674aafb58127b7173/physx/include/PxShape.h#L121-L127), the flags version of `PxShapeFlag`.

#### Old flags output

```rust
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxShapeFlags{
    pub mBits: u8,
}
```

#### New flags output

```rust
bitflags::bitflags! {
    /// Flags for [`PxShapeFlag`]
    #[derive(Default)]
    #[repr(transparent)]
    pub struct PxShapeFlags: u8 {
        const SimulationShape = 1 << 0;
        const SceneQueryShape = 1 << 1;
        const TriggerShape = 1 << 2;
        const Visualization = 1 << 3;
    }
}
```

#### Flags differences

1. Flags now create a [`bitflags`](https://crates.io/crates/bitflags) backed bitset, using a transparent repr using the same sized integer as in C++, allowing for transparent usage across the FFI boundary.
1. Normal bitset operations are now generated by `bitflags`
1. As with enums, each flag variant is named in `UpperCamelCase`

#### Migrating flags

Since the generated `*Flags` bitset has all of the bitset operations the migrated code should be much cleaner as there is no longer a need to convert to the underlying integer type.

```diff
-let mut shape_flags = PxShapeFlags {
-    mBits: (PxShapeFlag::eSCENE_QUERY_SHAPE | PxShapeFlag::eVISUALIZATION) as u8,
-};
+let mut shape_flags = PxShapeFlags::SceneQueryShape | PxShapeFlags::Visualization;

if config.trigger_volume {
-    shape_flags.mBits |= PxShapeFlag::eTRIGGER_SHAPE as u8;
+    shape_flags |= PxShapeFlags::TriggerShape;
} else {
-    shape_flags.mBits |= PxShapeFlag::eSIMULATION_SHAPE as u8;
+    shape_flags |= PxShapeFlags::SimulationShape;
}

PxPhysics_createShape_mut(
    px_physics.as_mut_ptr(),
    geom.geometry.as_ptr(),
    config.material,
    is_exclusive,
    shape_flags,
)
```

### Structs

The only difference, other than actual changes in the C++ classes/structs themselves, is that we now expose the `debug-structs` feature, which enables `Debug` to be derived for all of the generated POD structs. This is not enabled by default as the compile time and binary size increases are generally not going to be worthwhile in normal usage.

```rust
#[derive(Clone, Copy)]
#[cfg_attr(feature = "debug-structs", derive(Debug))]
#[repr(C)]
pub struct PxActorShape {
    pub actor: *mut PxRigidActor,
    pub shape: *mut PxShape,
}
```

### Functions

Static methods are now no longer suffixed with `_mut`.

```diff
-fn PxArticulationReducedCoordinate_setSolverIterationCounts_mut();
+fn PxArticulationReducedCoordinate_setSolverIterationCounts();
```

All generated Rust functions now include the comments from the C++ code, for convenience.

```diff
-pub fn PxRigidDynamic_getKinematicTarget(self_: *const PxRigidDynamic, target: *mut PxTransform, ) -> bool;
+/// Get target pose of a kinematically controlled dynamic actor.
+///
+/// True if the actor is a kinematically controlled dynamic and the target has been set, else False.
+pub fn PxRigidDynamic_getKinematicTarget(self_: *const PxRigidDynamic, target: *mut PxTransform) -> bool;
```

### Other

One other change of note is that the old pxbind was incorrectly binding `unsigned long long/uint64_t` to `usize`. It is now bound to `u64`. This would also apply to `i64`, but there are no instances of this in the public PhysX API.

Functions that don't return anything no longer specify the return type as `-> ()`.

## API Changes

This section contains API changes in the C++ code that are reflected in the API exposed by this crate. This is **not exhaustive**, as there are frankly too many changes both trivial and large to document here. That being said, please submit PRs to improve this section if you run up against issues when migrating from the 4.1 based crate to the 5.1 based crate that you think make sense to document.

If you want an exhaustive listing of API changes you can use [cargo public-api](https://crates.io/crates/cargo-public-api)

```sh
cargo install --locked cargo-public-api
cd physx-rs/physx-sys
cargo public-api --simplified diff 0.8.2
```

It's also recommended to checkout the [PhysX CHANGELOG](https://github.com/EmbarkStudios/PhysX-5/blob/main/physx/CHANGELOG.md) though note that this is **also not exhaustive**!

### Embark Changes

While most of the API changes are just reflecting the changes in the underlying C++ code, we've also made a few changes to how we generate bindings.

- We no longer bind the math functions from `PxMath.h`, there is no functionality there that cannot be done in pure Rust, without crossing the FFI boundary
- We no longer bind the functions from `PxString.h`, `PxUtilities.h`, `PxAtomic.h` or `PxHash.h`, these are all APIs that though "public" are really only used inside C++ itself

### Deprecated

One major change from the old bindings is that deprecated items (classes/structs/typedefs/enum variants/fields/functions/methods) are now **not generated**. This means some items that were already deprecated in the 4.1 SDK or no longer present, in addition to items that were deprecated in the transition from 4.1 -> 5.1.

We also abuse the `PX_DEPRECATED` macro to remove items that we intentionally don't expose in this crate, notably some of the new features added in 5.1 like soft bodies and cloth which are only available on NVidia GPUs and whose source is not part of the open source SDK.

If you were using an API in the former crate that is now deprecated (check [here](https://github.com/search?q=repo%3AEmbarkStudios%2FPhysX-5%20PX_DEPRECATED&type=code)) you can open a [PR](https://github.com/EmbarkStudios/PhysX-5/pulls) to un-deprecate the item (if it makes sense).

#### Notable Deprecations

- [**Vehicles**](https://nvidia-omniverse.github.io/PhysX/physx/5.1.3/docs/MigrationTo51.html#vehicles): All of the former Vehicle SDK components were deprecated and replaced with new APIs. These are not bound yet, see [#186](https://github.com/EmbarkStudios/physx-rs/issues/186)
- [**PxCooking**](https://nvidia-omniverse.github.io/PhysX/physx/5.1.3/docs/MigrationTo51.html#cooking): Deprecated and replaced with lower level individual functions/classes. This is temporarily [un-deprecated](https://github.com/EmbarkStudios/PhysX-5/commit/5cdbcf6c0ff9c9ff60397c909227243ea0fd8177) but will be replaced later, see [#187](https://github.com/EmbarkStudios/physx-rs/issues/187)
- [**Joint Projections**](https://github.com/EmbarkStudios/PhysX-5/blob/main/physx/CHANGELOG.md#deprecated-1): get/setProjectionAngular/LinearTolerance have been deprecated in all joints

### `PxRefCounted`

In PhysX 4 many classes had their own `release`, `getReferenceCount` and `acquireReference` methods. These methods have now all been moved to `PxRefCounted`, a new base class in PhysX 5. So now you will use those `PxRefCounted_*` methods instead of the former class methods, casting the pointer to a `PxRefCounted`.

```diff
-PxMaterial_release(material);
+PxRefCounted_release(material.cast());
```

- `PxMaterial`
- `PxShape`
- `PxConvexMesh`
- `PxHeightField`
- `PxTriangleMesh`

### Removed

Several APIs were completely removed, with their functionality either going away, or being absorbed into other classes.

- `PxArticulationBase` and `PxArticulation` were completely removed, most functionality was moved to `PxArticulationReducedCoordinate`
- `PxArticulationJointBase` and `PxArticulationJoint` were completely removed, most functionality was moved to `PxArticulationJointReducedCoordinate`
- `PxBatchQueryDesc` has been removed
- `PxBatchQueryMemory` has been removed

### Renamed

- `PxBVHStructure` was renamed to [`PxBVH`](https://nvidia-omniverse.github.io/PhysX/physx/5.1.3/docs/MigrationTo51.html#pxbvhstructure)
- `PxBVHStructureDesc` was renamed to [`PxBVHDesc`](https://nvidia-omniverse.github.io/PhysX/physx/5.1.3/docs/MigrationTo51.html#pxbvhstructure)
- `PxPhysicsInsertionCallback` was renamed to [`PxInsertionCallback`](https://nvidia-omniverse.github.io/PhysX/physx/5.1.3/docs/MigrationTo51.html#cooking)

### Replaced/Moved

- `PxBatchQuery` has been replaced by [`PxBatchQueryExt`](https://nvidia-omniverse.github.io/PhysX/physx/5.1.3/docs/MigrationTo51.html#scene-queries)
- `PxScene` queries have _mostly_ been moved to [`PxSceneQueryExt`](https://github.com/EmbarkStudios/PhysX-5/blob/4d33492253ab64c2246d80257ac4ce0f37b40b22/physx/include/extensions/PxSceneQueryExt.h#L60)
- `PxRigidBody_setAngularVelocity_mut` and `PxRigidBody_setLinearVelocity_mut` have been moved to [`PxRigidDynamic`](https://github.com/EmbarkStudios/PhysX-5/blob/main/physx/CHANGELOG.md#changed-3)
- Many class constructors have been consolidated, so instead of having, for example, a default constructor and a constructor that takes two `f32` parameters, there will now be single constructor that takes two `f32` parameters, both having default values that used to be set in the default constructor. If you were calling a `_new` function (a wrapper for a constructor) that now fails since the signature is different, you can look at the code to determine what arguments to pass to retain the default constructor behavior.

```diff
-pub fn PxCapsuleGeometry_new() -> PxCapsuleGeometry;
+pub fn PxCapsuleGeometry_new(radius_: f32, halfHeight_: f32) -> PxCapsuleGeometry;
```

[PR#183]: https://github.com/EmbarkStudios/physx-rs/pull/183
