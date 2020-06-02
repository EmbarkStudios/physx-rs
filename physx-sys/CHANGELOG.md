## [Unreleased]

## [0.4.3] - 2020-05-26

### Added

- [PR#66](https://github.com/EmbarkStudios/physx-rs/pull/66) Added support for android (`aarch64`) to the build system and to `pxbind`.

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

[Unreleased]: https://github.com/EmbarkStudios/physx-rs/compare/physx-sys-v0.4.2...HEAD
[0.4.2]: https://github.com/EmbarkStudios/physx-rs/compare/physx-sys-v0.4.1...physx-sys-v0.4.2
[0.4.1]: https://github.com/EmbarkStudios/physx-rs/compare/physx-sys-v0.4.0...physx-sys-v0.4.1
[0.4.0]: https://github.com/EmbarkStudios/physx-rs/compare/physx-sys-v0.3.0...physx-sys-v0.4.0
[0.3.0]: https://github.com/EmbarkStudios/physx-rs/compare/physx-sys-v0.2.4...physx-sys-v0.3.0
