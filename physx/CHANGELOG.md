# `physx-rs` Changelog

<!-- markdownlint-disable MD024 -->

## [Unreleased]

- [PR#124](https://github.com/EmbarkStudios/physx-rs/pull/124) Upgrade glam
  v0.11 -> v0.12

## [0.10.0]

- [PR#113](https://github.com/EmbarkStudios/physx-rs/pull/98) Fix various issues
  found using physx-rs in practice after the big PR#98 merge from 0.9.0.
  You now create a scene using `Physics::create()` with a new scene descriptor
  that can represent all the parameters of PxSceneDesc.
- [PR#120](https://github.com/EmbarkStudios/physx-rs/pull/120) Make convex and
  triangle mesh validation optional.

## [0.9.0] - 2020-12-03

### Refactored

- [PR#98](https://github.com/EmbarkStudios/physx-rs/pull/98) Use Class<T>
  instead of Deref, track user data types This change is a significant refactor.
  The API is now very close to the underlying PhysX API, but with Rust's type
  and memory safety.  Method names mirror the C++ API, but `like_this` instead
  of `likeThis`. Much of the additional behaviour that was built on top of the
  underlying API has been removed.  The prelude exports the class-traits, but
  intentionally does not export the new-type wrappers.  Instead of importing
  them, create type aliases for them with the generic params filled in to cut
  down on the amount of typing (see the example). The PR has a detailed summary
  of the changes, with links to the relevant code.

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

[Unreleased]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.10.0...HEAD
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
