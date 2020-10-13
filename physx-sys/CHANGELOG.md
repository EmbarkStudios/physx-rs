# `physx-sys` Changelog

<!-- markdownlint-disable MD024 -->

## [Unreleased]

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

[Unreleased]: https://github.com/EmbarkStudios/physx-rs/compare/physx-sys-v0.4.9...HEAD
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
