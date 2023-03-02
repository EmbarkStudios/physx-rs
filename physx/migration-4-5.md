# physx-sys 4.1 -> 5.1 migration guide

This is a migration guide for the `physx` crate from the version (0.16.*) that was wrapping PhysX SDK 4.1, and the version (0.17) that transition to PhysX SDK 5.1.3. (see [PR#183] for the PR that actually made a bulk of the transition)

See the [`physx-sys`](../physx-sys/migration-4-5.md) migration guide for more in depth information on the FFI API changes.

Note that there is a migration guide from NVidia for the C++ code [here](https://nvidia-omniverse.github.io/PhysX/physx/5.1.3/docs/MigrationTo51.html).

## Enums changes

All enums are now re-exported from `physx-sys` as the C++ enums are now both bound as normal Rust enums with the appropriately sized integer representation, and all of the enum variants are now named in `UpperCamelCase` to make them pleasant to use directly in Rust.

```diff
-#[bitflags]
-#[derive(Debug, Copy, Clone)]
-#[repr(u8)]
-pub enum ActorFlag {
-    Visualization = 1,
-    DisableGravity = 2,
-    SendSleepNotifies = 4,
-    DisableSimulation = 8,
-}

-impl From<ActorFlag> for PxActorFlag::Enum {
-    fn from(value: ActorFlag) -> Self {
-        match value {
-            ActorFlag::Visualization => 1,
-            ActorFlag::DisableGravity => 2,
-            ActorFlag::SendSleepNotifies => 4,
-            ActorFlag::DisableSimulation => 8,
-        }
-    }
-}

-impl From<PxActorFlag::Enum> for ActorFlag {
-    fn from(other: PxActorFlag::Enum) -> Self {
-        match other {
-            1 => ActorFlag::Visualization,
-            2 => ActorFlag::DisableGravity,
-            4 => ActorFlag::SendSleepNotifies,
-            8 => ActorFlag::DisableSimulation,
-            _ => unreachable!("InvalidActorFlag"),
-        }
-    }
-}
+pub use physx_sys::PxActorFlag as ActorFlag;
```

## Flags changes

Previously the `physx` crate used `enumflags2` to create bitsets for the various enums that acted as flags in the API. These have all been removed as the `physx-sys` crate now creates these automatically during binding generation, with a few exceptions (ie `physx::foundation::ErrorCodes`, `physx::physics::AggregateFilterHint`, and `physx::shape::CollisionLayers`), and are directly reexported from the physx-sys crate with the same name as it had in the previous version of the `physx` crate.

```diff
-pub type ActorFlags = BitFlags<ActorFlag>;
-
-impl PxFlags for ActorFlags {
-    type Target = PxActorFlags;
-
-    fn into_px(self) -> Self::Target {
-        PxActorFlags { mBits: self.bits() }
-    }
-
-    fn from_px(flags: Self::Target) -> Self {
-        BitFlags::from_bits_truncate(flags.mBits)
-    }
-}
+pub use physx_sys::PxActorFlags as ActorFlags;
```

The API for [`bitflags`](https://docs.rs/bitflags/1.3.2/bitflags/#methods) is largely the same as [`enumflags2`](https://docs.rs/enumflags2/latest/enumflags2/struct.BitFlags.html) so this change should mostly be transparent.

This also means that the `PxFlags` trait has been completely removed as it is no longer needed.

## Deprecated

- The `PxCooking` structure has been marked as `#[deprecated]`. It is deprecated in the underlying C++ SDK and we will replace it in a future version.

## Removed

- `ArticulationBase` and `Articulation` have been removed from PhysX, with some of their functionality moving into `ArticulationReducedCoordinate`
- `ArticulationMap` has been removed
- `ArticulationJointBase` and `ArticulationJoint` have been removed from PhysX, with some of their functionality moving into `ArticulationJointReducedCoordinate`
- `JointMap` has been removed
- `ArticulationLink::get_inbound_joint` has been _temporarily_ removed

## Renamed

- `BvhStructure` has been renamed to `Bvh`, methods have that operate on `Bvh` have also been renamed
- `PxBvhStructureDesc` has been renamed to `PxBVHDesc`
