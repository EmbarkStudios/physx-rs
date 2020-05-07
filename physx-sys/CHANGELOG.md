## [Unreleased]

## [0.4.0] - 2020-05-07
### Changed
- [PR#59](https://github.com/EmbarkStudios/physx-rs/pull/59) made `cmake` into an optional, non-default, dependency for building the C++ code, in favor of just using the `cc` crate. CMake can be enabled via the `use-cmake` feature.
- [PR#59](https://github.com/EmbarkStudios/physx-rs/pull/59) updated the fork of the PhysX repository to include various changes to the C++ code to allow it to be cross-compiled for Windows via clang from Linux or Mac.
- [PR#59](https://github.com/EmbarkStudios/physx-rs/pull/59) added a `structgen` feature flag, to make the creation of the C++ executable that generates the Rust bindings for the C++ code optional, as the generated code is now checked in and should only need to be updated when PhysX itself is updated.

## [0.3.0] - 2020-03-04
### Added
- Ability to not run the default filter shader before the callback.

[Unreleased]: https://github.com/EmbarkStudios/physx-rs/compare/physx-sys-v0.3.0...HEAD
[0.3.0]: https://github.com/EmbarkStudios/physx-rs/compare/physx-sys-v0.2.4...physx-sys-v0.3.0