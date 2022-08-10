# `physx-sys` Changelog

<!-- markdownlint-disable no-duplicate-heading blanks-around-headers -->

<!-- next-header -->
## [Unreleased] - ReleaseDate
## [0.5.0] - 2022-08-10

- [PR#157](https://github.com/EmbarkStudios/physx-rs/pull/157) Remove cmake support
- [PR#154](https://github.com/EmbarkStudios/physx-rs/pull/154) Add support for `aarch64-unknown-linux-gnu`
- [PR#158](https://github.com/EmbarkStudios/physx-rs/pull/158) Update pre generated `aarch64-linux-android` files
    - `PxRepXObject` typename field changed from `*const u8` to `*const i8`
    - `PxDebugText` typename field changed from `*const u8` to `*const i8`
    - `PxProfileScoped` typename field changed from `*const u8` to `*const i8`
    - `PxVehicleGraphChannelDesc` typename field changed from `*mut u8` to `*mut i8`
- [PR#156](https://github.com/EmbarkStudios/physx-rs/pull/156) Update pre generated `aarch64-apple-darwin` files
    - Adds `PxSpatialVelocity` to the `PxArticulationRootLinkData` struct as `linkVelocity` and `linkAcceleration` fields.
- [PR#153](https://github.com/EmbarkStudios/physx-rs/pull/153) Update clang/llvm lib used by `pxbind` and update `x86_64-apple-darwin`, `x86_64-pc-windows-msvc`, `x86_64-unknown-linux` pre generated files.
    - Mostly an internal change but adds `PxSpatialVelocity` to the `PxArticulationRootLinkData` struct as `linkVelocity` and `linkAcceleration` fields.

## [0.4.16] - 2021-12-21
### Fixed

- [PR#142](https://github.com/EmbarkStudios/physx-rs/pull/141) added the license texts to the crate, and added a note in the README about how to clarify the licenses in cargo deny until crates.io supports parentheses in license expressions.
- [PR#144](https://github.com/EmbarkStudios/physx-rs/pull/144) fixed a few clang warnings about set but unused variables.

## [0.4.15] - 2021-08-22

### Changed

- [PR#140](https://github.com/EmbarkStudios/physx-rs/pull/140) updated to Embark lint v0.4, though we allow several clippy lints at the moment due to how endemic a few of them are.

### Fixed

- [PR#140](https://github.com/EmbarkStudios/physx-rs/pull/140) updated the C++ code to fix several `unused-but-set-variable` errors when compiling with clang-13.

## [0.4.14] - 2021-07-22

### Fixed

- [PR#138](https://github.com/EmbarkStudios/physx-rs/pull/138) silenced the `dtor-name`, `suggest-overrides`, and `suggest-override-destructor` warnings in the cmake build to silence warnings causing [build failures in clang-11+](https://github.com/NVIDIAGameWorks/PhysX/issues/417).

## [0.4.13] - 2021-05-03

### Fixed

- [PR#135](https://github.com/EmbarkStudios/physx-rs/pull/135) Update PhysX submodule with ARM64 buildfix for Xcode 14.5

## [0.4.12] - 2020-12-03

### Added

- [PR#123](https://github.com/EmbarkStudios/physx-rs/pull/123) Initial `aarch64-apple-darwin` support

## [0.4.11] - 2020-12-03

### Added

- [PR#198](https://github.com/EmbarkStudios/physx-rs/pull/98) Major refactor of
  the high-level `physx` crate exposed the following low-level calls:
  - `pub fn get_simulation_event_info(callback: *mut PxSimulationEventCallback,) -> *mut SimulationEventCallbackInfo;`
  - `pub fn get_alloc_callback_user_data(alloc_callback: *mut PxAllocatorCallback) -> *mut c_void;`

## [0.4.10] - 2020-10-20

### Added

- [PR#94](https://github.com/EmbarkStudios/physx-rs/pull/94) Allow overriding the PxAllocatorCallback with a pair of custom callback functions

## [0.4.9] - 2020-08-13

### Added

- [PR#80](https://github.com/EmbarkStudios/physx-rs/pull/80) New way to register simulation event callbacks, supporting all callback types this time.

## [0.4.8] - 2020-07-02

### Fixed

- [PR#77](https://github.com/EmbarkStudios/physx-rs/pull/77) Ignore potential PhysX C++ compile warnings

## [0.4.7] - 2020-07-02

### Fixed

- [PR#76](https://github.com/EmbarkStudios/physx-rs/pull/76) Use proper `ANDROID_NDK_ROOT` env var instead of `NDK_HOME`

## [0.4.6] - 2020-07-01

### Added

- [PR#73](https://github.com/EmbarkStudios/physx-rs/pull/73) Added `create_raycast_filter_callback_func`, allowing custom filtering of raycast hits

### Fixed

- [PR#74](https://github.com/EmbarkStudios/physx-rs/pull/74) Fix Android NDK toolchain path selection on Mac & Windows

## [0.4.4] - 2020-06-02

### Added

- [PR#66](https://github.com/EmbarkStudios/physx-rs/pull/66) Added support for android (`aarch64`) to the build system and to `pxbind`.

## [0.4.3] - 2020-05-27

### Fixed

- [PR#70](https://github.com/EmbarkStudios/physx-rs/pull/70) cleaned up some build script problems for Windows.

## [0.4.2] - 2020-05-25

### Fixed

- [PR#67](https://github.com/EmbarkStudios/physx-rs/pull/67) Reduce crate size from 10 MB to 2.7 MB by removing unused PhysX binary files

## [0.4.1] - 2020-05-07

### Fixed

- [PR#62](https://github.com/EmbarkStudios/physx-rs/pull/62) fixed C++ compile warnings/errors when compiling with clang 10.0.0.

## [0.4.0] - 2020-05-07

### Changed

- Use `SetThreadDescription` inside PhysX on Windows 10 to get worker thread names in profilers, instead of just the debugger.
- [PR#59](https://github.com/EmbarkStudios/physx-rs/pull/59) made `cmake` into an optional, non-default, dependency for building the C++ code, in favor of just using the `cc` crate. CMake can be enabled via the `use-cmake` feature.
- [PR#59](https://github.com/EmbarkStudios/physx-rs/pull/59) updated the fork of the PhysX repository to include various changes to the C++ code to allow it to be cross-compiled for Windows via clang from Linux or Mac.
- [PR#59](https://github.com/EmbarkStudios/physx-rs/pull/59) added a `structgen` feature flag, to make the creation of the C++ executable that generates the Rust bindings for the C++ code optional, as the generated code is now checked in and should only need to be updated when PhysX itself is updated.

## [0.3.0] - 2020-03-04

### Added

- Ability to not run the default filter shader before the callback.

<!-- next-url -->
[Unreleased]: https://github.com/EmbarkStudios/physx-rs/compare/physx-sys-v0.5.0...HEAD
[0.5.0]: https://github.com/EmbarkStudios/physx-rs/compare/physx-sys-v0.4.16...physx-sys-v0.5.0
[0.4.16]: https://github.com/EmbarkStudios/physx-rs/compare/physx-sys-v0.4.15...physx-sys-v0.4.16
[0.4.15]: https://github.com/EmbarkStudios/physx-rs/compare/physx-sys-v0.4.14...physx-sys-v0.4.15
[0.4.14]: https://github.com/EmbarkStudios/physx-rs/compare/physx-sys-v0.4.13...physx-sys-v0.4.14
[0.4.13]: https://github.com/EmbarkStudios/physx-rs/compare/physx-sys-v0.4.12...physx-sys-v0.4.13
[0.4.12]: https://github.com/EmbarkStudios/physx-rs/compare/physx-sys-v0.4.11...physx-sys-v0.4.12
[0.4.11]: https://github.com/EmbarkStudios/physx-rs/compare/physx-sys-v0.4.10...physx-sys-v0.4.11
[0.4.10]: https://github.com/EmbarkStudios/physx-rs/compare/physx-sys-v0.4.9...physx-sys-v0.4.10
[0.4.9]: https://github.com/EmbarkStudios/physx-rs/compare/physx-sys-v0.4.8...physx-sys-v0.4.9
[0.4.8]: https://github.com/EmbarkStudios/physx-rs/compare/physx-sys-v0.4.7...physx-sys-v0.4.8
[0.4.7]: https://github.com/EmbarkStudios/physx-rs/compare/physx-sys-v0.4.6...physx-sys-v0.4.7
[0.4.6]: https://github.com/EmbarkStudios/physx-rs/compare/physx-sys-v0.4.4...physx-sys-v0.4.6
[0.4.4]: https://github.com/EmbarkStudios/physx-rs/compare/physx-sys-v0.4.3...physx-sys-v0.4.4
[0.4.3]: https://github.com/EmbarkStudios/physx-rs/compare/physx-sys-v0.4.2...physx-sys-v0.4.3
[0.4.2]: https://github.com/EmbarkStudios/physx-rs/compare/physx-sys-v0.4.1...physx-sys-v0.4.2
[0.4.1]: https://github.com/EmbarkStudios/physx-rs/compare/physx-sys-v0.4.0...physx-sys-v0.4.1
[0.4.0]: https://github.com/EmbarkStudios/physx-rs/compare/physx-sys-v0.3.0...physx-sys-v0.4.0
[0.3.0]: https://github.com/EmbarkStudios/physx-rs/compare/physx-sys-v0.2.4...physx-sys-v0.3.0
