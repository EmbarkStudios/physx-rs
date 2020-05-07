## [Unreleased]

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

[Unreleased]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.5.1...HEAD
[0.5.1]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.5.0...physx-v0.5.1
[0.5.0]: https://github.com/EmbarkStudios/physx-rs/compare/physx-v0.4.2...physx-v0.5.0
