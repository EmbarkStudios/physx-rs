# `physx-rs` Changelog

<!-- markdownlint-disable no-duplicate-header blanks-around-headers blanks-around-lists -->

<!-- next-header -->
## [Unreleased] - ReleaseDate
## [0.19.0] - 2023-10-11
### Changed
- [PR#206](https://github.com/EmbarkStudios/physx-rs/pull/206) split `ActorMap` functions
into mutable and immutable variants.
  - `ActorMap::cast_map` -> `ActorMap::cast_map_mut`
  - `ActorMap::as_rigid_dynamic` -> `ActorMap::as_rigid_dynamic_mut`
  - `ActorMap::as_rigid_static` -> `ActorMap::as_rigid_static_mut`
  - `ActorMap::as_articulation_link` -> `ActorMap::as_articulation_link_mut`

### Fixed
- [PR#211](https://github.com/EmbarkStudios/physx-rs/pull/211) fixed misaligned pointer dereference when using `UserData` with small-size values.
- [PR#215](https://github.com/EmbarkStudios/physx-rs/pull/215) fixed double free of materials used by shapes

## [0.18.0] - 2023-03-03
### Changed
- [PR#191](https://github.com/EmbarkStudios/physx-rs/pull/191) replaced `PxCooking` with regular functions as `PxCooking` is deprecated in the C++ code.
  - `PxCooking::create_bvh` -> `physx::cooking::create_bvh`
  - `PxCooking::create_convex_mesh` -> `physx::cooking::create_convex_mesh`
  - `PxCooking::validate_convex_mesh` -> `physx::cooking::validate_convex_mesh`
  - `PxCooking::create_height_field` -> `physx::cooking::create_height_field`
  - `PxCooking::create_triangle_mesh` -> `physx::cooking::create_triangle_mesh`
  - `PxCooking::validate_triangle_mesh` -> `physx::cooking::validate_triangle_mesh`

## [0.17.0] - 2023-03-03
### Changed
- [PR#183](https://github.com/EmbarkStudios/physx-rs/pull/183) resolved [#175](https://github.com/EmbarkStudios/physx-rs/issues/175) by upgrading from PhysX 4.1 to PhysX 5.1.3. See the [physx](migration-4-5.md) migration guide for more information for updating your code to work with this big breaking change.

## [0.16.1] - 2023-02-17
### Fixed
- [PR#182](https://github.com/EmbarkStudios/physx-rs/pull/182) fixed a clippy lint that triggers in 1.66.0.
- [PR#176](https://github.com/EmbarkStudios/physx-rs/pull/176) fixed a clippy lint that triggers in 1.65.0.

## [0.16.0] - 2022-10-20
- Add new `PhysicsFoundation::set_assert_handler` API with corresponding trait. This allows plugging in
  a Rust-side handler for assertions.

## [0.15.0] - 2022-10-19

- Add new `PhysicsFoundationBuilder::with_error_callback` API with corresponding trait. This allows plugging in
  a Rust-side logging framework to consume PhysX errors.

## [0.14.1] - 2022-10-03

- Fixed a bug where the Pvd host string would get deallocated and fail to connect.

## [0.14.0] - 2022-10-03

- Warn when enabling PVD without extensions enabled to help diagnose PVD crashes: <https://github.com/NVIDIAGameWorks/PhysX/issues/306>
- Allow overriding PVD host with `PhysicsFoundationBuilder::set_pvd_host`
- Add new `PhysicsFoundation::set_profiler` API with corresponding types. This allows plugging in a Rust-side scope
  tracing tool like Puffin and consuming PhysX profiling information.

## [0.13.0] - 2022-08-10

- [PR#157](https://github.com/EmbarkStudios/physx-rs/pull/157) Remove cmake support
- [PR#154](https://github.com/EmbarkStudios/physx-rs/pull/154) Add support for `aarch64-unknown-linux-gnu`

## [0.12.2] - 2022-02-07

- [PR#146](https://github.com/EmbarkStudios/physx-rs/pull/146) updated the optional glam dependency to 0.20.

## [0.12.1] - 2021-08-22

### Changed

- [PR#140](https://github.com/EmbarkStudios/physx-rs/pull/140) updated to Embark lints v0.4, though we allow several clippy lints at the moment due to how endemic a few of them are.

## [0.12.0] - 2021-07-22

### Changed
- [PR#129](https://github.com/EmbarkStudios/physx-rs/pull/129) made [`glam`](https://crates.io/crates/glam) an optional dependency and has been updated. You can enable the `glam` feature to continue to use `glam` with `physx-sys` types.
- [Updated various struct names and trait implementations](https://github.com/EmbarkStudios/physx-rs/pull/130):
  - `BVHStructure` is now named `BvhStructure`.
  - `PxBVHStructureDesc` is now named `PxBvhStructureDesc`.
  - `HeightFieldFormat::S16TM` is now named `S16tm`.
  - `BroadPhaseType::GPU` is now named `Gpu`.
  - `SolverType::{PGS, TGS}` are now named `Pgs`, and `Tgs`.
  - `RigidBodyFlag::{EnableCCD, EnableCCDFriction, EnableSpeculativeCCD,
     EnableCCDMaxContactImpulse}` are now named `EnableCcd`,
     `EnableCcdFriction`, `EnableSpeculativeCcd`, `EnableCcdMaxContactImpulse`.
  - `PruningStructureType::{DynamicAABBTree, StaticAABBTree}` are now named
    `DynamicAabbTree`, `StaticAabbTree`.
  - `Mat4` now implements `From<physx_sys::PxTransform>`.
  - `Quat` now implements `From<physx_sys::PxQuat>`.
  - `Vec3` now implements `From<physx_sys::PxVec3>`.
  - `physx_sys::PxActorType::Enum` now implements `From<ActorType>`.
  - `physx_sys::PxActorFlag::Enum` now implements `From<ActorFlag>`.
  - `physx_sys::PxArticulationAxis::Enum` now implements `From<ArticulationAxis>`.
  - `physx_sys::PxArticulationAxis::Enum` now implements `From<ArticulationMotion>`.
  - `physx_sys::PxArticulationDriveType::Enum` now implements `From<ArticulationDriveType>`.
  - `physx_sys::PxArticulationFlag::Enum` now implements `From<ArticulationFlag>`.
  - `physx_sys::PxArticulationJointDriveType::Enum` now implements `From<ArticulationJointDriveType>`.
  - `physx_sys::PxArticulationJointType::Enum` now implements `From<ArticulationJointType>`.
  - `physx_sys::PxArticulationRootLinkData` now implements `From<ArticulationRootLinkData>`.
  - `physx_sys::PxBaseFlag::Enum` now implements `From<BaseFlag>`.
  - `physx_sys::PxBounds3` now implements `From<PxBounds3>`.
  - `physx_sys::PxCapsuleClimbingMode::Enum` now implements `From<CapsuleClimbingMode>`.
  - `physx_sys::PxExtendedVec3` now implements `From<PxExtendedVec3>`.
  - `physx_sys::PxExtendedVec3` now implements `From<PxVec3>`.
  - `physx_sys::PxForceMode::Enum` now implements `From<ForceMode>`.
  - `physx_sys::PxFrictionType::Enum` now implements `From<FrictionType>`.
  - `physx_sys::PxPairFilteringMode::Enum` now implements `From<PairFilteringMode>`.
  - `physx_sys::PxPruningStructureType::Enum` now implements `From<PruningStructureType>`.
  - `physx_sys::PxQuat` now implements `From<PxQuat>`.
  - `physx_sys::PxRigidBodyFlag::Enum` now implements `From<RigidBodyFlag>`.
  - `physx_sys::PxRigidDynamicLockFlag::Enum` now implements `From<RigidDynamicLockFlag>`.
  - `physx_sys::PxSceneFlag::Enum` now implements `From<SceneFlag>`.
  - `physx_sys::PxSceneLimits` now implements `From<SceneLimits>`.
  - `physx_sys::PxSceneQueryUpdateMode::Enum` now implements `From<SceneQueryUpdateMode>`.
  - `physx_sys::PxShapeFlag::Enum` now implements `From<ShapeFlag>`.
  - `physx_sys::PxSolverType::Enum` now implements `From<SolverType>`.
  - `physx_sys::PxTransform` now implements `From<PxTransform>`.
  - `physx_sys::PxVec3` now implements `From<PxVec3>`.
- [PR#138](https://github.com/EmbarkStudios/physx-rs/pull/138) updated `enumflags2` to 0.7.

## [0.11.0]

- [PR#124](https://github.com/EmbarkStudios/physx-rs/pull/124) Upgrade glam
  v0.11 -> v0.12

## [0.10.0]

- [PR#113](https://github.com/EmbarkStudios/physx-rs/pull/98) Fix various issues found using physx-rs in practice after the big PR#98 merge from 0.9.0. You now create a scene using `Physics::create()` with a new scene descriptor that can represent all the parameters of PxSceneDesc.
- [PR#120](https://github.com/EmbarkStudios/physx-rs/pull/120) Make convex and triangle mesh validation optional.

## [0.9.0] - 2020-12-03

### Refactored

- [PR#98](https://github.com/EmbarkStudios/physx-rs/pull/98) Use Class<T> instead of Deref, track user data types This change is a significant refactor. The API is now very close to the underlying PhysX API, but with Rust's type and memory safety. Method names mirror the C++ API, but `like_this` instead of `likeThis`. Much of the additional behaviour that was built on top of the underlying API has been removed.  The prelude exports the class-traits, but intentionally does not export the new-type wrappers.  Instead of importing them, create type aliases for them with the generic params filled in to cut down on the amount of typing (see the example). The PR has a detailed summary of the changes, with links to the relevant code.

### Dependencies

- [PR#110](https://github.com/EmbarkStudios/physx-rs/pull/110) Upgrade glam v0.10 -> v0.11

## [0.8.0] - 2020-11-10

### Added

- [PR#102](https://github.com/EmbarkStudios/physx-rs/pull/102) Upgrade glam v0.9 -> v0.10

## [0.7.4] - 2020-10-20

### Added

- [PR#94](https://github.com/EmbarkStudios/physx-rs/pull/94) Allow overriding the PxAllocatorCallback with a pair of custom callback functions

## [0.7.3] - 2020-10-14

### Added

- [PR#90](https://github.com/EmbarkStudios/physx-rs/pull/90) Expose a bunch of additional parameters on SceneBuilder

## [0.7.2] - 2020-10-13

### Added

- [PR#87](https://github.com/EmbarkStudios/physx-rs/pull/87) Allow setting the solver type when creating a scene

## [0.7.1] - 2020-08-13

### Added

- [PR#80](https://github.com/EmbarkStudios/physx-rs/pull/80) New way to register simulation event callbacks, supporting all callback types this time. Deprecates `set_simulation_event_callback` in favor of `set_simulation_event_callbacks`.

## [0.7.0] - 2020-06-29

### Changed

- [PR#72](https://github.com/EmbarkStudios/physx-rs/pull/72) Upgrade `glam` to 0.9. This includes a change of `Vec3` internal representation from 16-byte SIMD type to 12-byte 3x floats.

## [0.6.1] - 2020-06-02

### Added

- [PR#66](https://github.com/EmbarkStudios/physx-rs/pull/66) minor change to take the fact that the internal pointer type may differ across platforms into account.

## [0.6.0] - 2020-05-07

### Changed

- [PR#59](https://github.com/EmbarkStudios/physx-rs/pull/59) made `cmake` into an optional, non-default, dependency for building the C++ code, in favor of just using the `cc` crate. CMake can be enabled via the `use-cmake` feature.
- [PR#59](https://github.com/EmbarkStudios/physx-rs/pull/59) added a `structgen` feature flag, to make the creation of the C++ executable that generates the Rust bindings for the C++ code optional, as the generated code is now checked in and should only need to be updated when PhysX itself is updated.

## [0.5.1] - 2020-03-04

### Changed

- Restored a way to create a PxScene without a Scene wrapper.

## [0.5.0] - 2020-03-04

### Added

- Character controller wrapper, character manager available via Scene.

### Changed

- Ability to not run the default filter shader before the callback.
- Fix for triangle mesh data when using glam with SSE enabled

<!-- next-url -->
[Unreleased]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.19.0...HEAD
[0.19.0]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.18.0...physx-v0.19.0
[0.18.0]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.17.0...physx-v0.18.0
[0.17.0]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.16.1...physx-v0.17.0
[0.16.1]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.16.0...physx-v0.16.1
[0.16.0]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.15.0...physx-v0.16.0
[0.15.0]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.14.1...physx-v0.15.0
[0.14.1]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.14.0...physx-v0.14.1
[0.14.0]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.13.0...physx-v0.14.0
[0.13.0]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.12.2...physx-v0.13.0
[0.12.2]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.12.1...physx-v0.12.2
[0.12.1]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.12.0...physx-v0.12.1
[0.12.0]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.11.0...physx-v0.12.0
[0.11.0]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.10.0...physx-v0.11.0
[0.10.0]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.9.0...physx-v0.10.0
[0.9.0]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.8.0...physx-v0.9.0
[0.8.0]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.7.4...physx-v0.8.0
[0.7.4]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.7.3...physx-v0.7.4
[0.7.3]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.7.2...physx-v0.7.3
[0.7.2]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.7.1...physx-v0.7.2
[0.7.1]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.7.0...physx-v0.7.1
[0.7.0]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.6.1...physx-v0.7.0
[0.6.1]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.6.0...physx-v0.6.1
[0.6.0]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.5.1...physx-v0.6.0
[0.5.1]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.5.0...physx-v0.5.1
[0.5.0]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.4.2...physx-v0.5.0
