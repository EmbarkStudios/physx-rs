//! # 🎳 physx-sys
//!
//! ![Build Status](https://github.com/EmbarkStudios/physx-rs/workflows/CI/badge.svg)
//! [![Crates.io](https://img.shields.io/crates/v/physx-sys.svg)](https://crates.io/crates/physx-sys)
//! [![Docs](https://docs.rs/physx-sys/badge.svg)](https://docs.rs/physx-sys)
//! [![Contributor Covenant](https://img.shields.io/badge/contributor%20covenant-v1.4%20adopted-ff69b4.svg)](../CODE_OF_CONDUCT.md)
//! [![Embark](https://img.shields.io/badge/embark-open%20source-blueviolet.svg)](http://embark.games)
//!
//! Unsafe automatically-generated Rust bindings for [NVIDIA PhysX 4.1](https://github.com/NVIDIAGameWorks/PhysX) C++ API.
//!
//! Please also see the [repository](https://github.com/EmbarkStudios/physx-rs) containing a work-in-progress safe wrapper.
//!
//! ## Presentation
//!
//! [Tomasz Stachowiak](https://github.com/h3r2tic) did a presentation at the Stockholm Rust Meetup on October 2019
//! about this project that goes through the tecnical details of how C++ to Rust bindings of `physx-sys` works:
//!
//! [![](http://img.youtube.com/vi/RxtXGeDHu0w/0.jpg)](http://www.youtube.com/watch?v=RxtXGeDHu0w "An unholy fusion of
//! Rust and C++ in physx-rs (Stockholm Rust Meetup, October 2019)")
//!
//!
//! ## Basic usage
//!
//! ```Rust
//! unsafe {
//!     let foundation = physx_create_foundation();
//!     let physics = physx_create_physics(foundation);
//!
//!     let mut scene_desc = PxSceneDesc_new(PxPhysics_getTolerancesScale(physics));
//!     scene_desc.gravity = PxVec3 {
//!         x: 0.0,
//!         y: -9.81,
//!         z: 0.0,
//!     };
//!
//!     let dispatcher = PxDefaultCpuDispatcherCreate(2, null_mut());
//!
//!     scene_desc.cpuDispatcher = dispatcher as *mut PxCpuDispatcher;
//!     scene_desc.filterShader = Some(PxDefaultSimulationFilterShader);
//!
//!     let scene = PxPhysics_createScene_mut(physics, &scene_desc);
//!
//!     // Your physics simulation goes here
//! }
//! ```
//!
//! ## Examples
//!
//! ### [Ball](examples/ball.rs)
//!
//! A simple example to showcase how to use physx-sys. It can be run with `cargo run --examples ball`.
//!
//! ```
//!  o
//!
//!   o
//!    o
//!
//!     o
//!                       ooooooooo
//!      o              oo         oo
//!                    o             o
//!       o           o               o
//!                  o                 oo
//!        o        o                    o
//!                o                                ooooooo
//!               o                       o       oo       oo
//!         o    o                         o    oo           oo
//!             o                           o  o               o    ooooooooo
//!          o                                o                 o oo         oooooooooo oo
//!
//! ```
//!
//! ## How it works
//!
//! The binding is generated using a custom C++ app written against clang's
//! [libtooling](https://clang.llvm.org/docs/LibTooling.html). It queries the compiler's abstract syntax tree, and maps
//! the C++ PhysX functions and types to Rust using heuristics chosen specifically for this SDK. It is not a general
//! C++ <-> Rust binding generator, and using it on other projects *will* likely crash and burn.
//!
//! Since C++ does not have a standardized and stable ABI, it's generally not safe to call it from Rust code; since
//! PhysX exposes a C++ interface, we can't use it directly. That's why `physx-sys` generates both a Rust interface as
//! well as a plain C wrapper. The C code is compiled into a static library at build time, and Rust then talks to C.
//!
//! In order to minimize the amount of work required to marshall data between the C wrapper and the original C++ API, we
//! generate a **bespoke C wrapper for each build target**. The wrapper is based on metadata about structure layout
//! extracted directly from compiling and running a tiny program against the PhysX SDK using the specific C++ compiler
//! used in the build process.
//!
//! The build process comprises a few steps:
//!
//! 1. The `pxbind` utility uses `clang` to extract metadata about PhysX functions and types, and generates partial
//! Rust and C bindings as `physx_generated.hpp` and `physx_generated.rs`. Those contain all function definitions, and
//! a small subset of types. It also generates a C++ utility called `structgen` by emitting `structgen.cpp`.
//! 2. `structgen` is compiled against the PhysX SDK, and generates all the remaining type wrappers. For each struct, it
//! queries the size and offset of its members, and generates `structgen_out.hpp` and `structgen_out.rs`. The types are
//! "plain old data" structs which will perfectly match the memory layout of the C++ types.
//! 3. All the generated C types are compiled together to form `physx_api`, a static library for Rust to link with.
//! 4. The Rust wrapper is compiled, and linked with PhysX and the C wrapper.
//!
//! Steps *2..4* are performed completely automatically from within `build.rs`, while step *1* is only necessary when
//! upgrading the PhysX SDK or modifying the generator. As such, building and running `pxbind` is a manual task, and is
//! currently only supported on \*nix systems.
//!
//! ## License
//!
//! Licensed under either of
//!
//! * Apache License, Version 2.0, ([LICENSE-APACHE](LICENSE-APACHE) or http://www.apache.org/licenses/LICENSE-2.0)
//! * MIT license ([LICENSE-MIT](LICENSE-MIT) or http://opensource.org/licenses/MIT)
//!
//! at your option.
//!
//! Note that the [PhysX C++ SDK](https://github.com/NVIDIAGameWorks/PhysX) has it's
//! [own BSD 3 license](https://gameworksdocs.nvidia.com/PhysX/4.1/documentation/physxguide/Manual/License.html) and
//! depends on [additional C++ third party libraries](https://github.com/NVIDIAGameWorks/PhysX/tree/4.1/externals).
//!
//! ### Contribution
//!
//! Unless you explicitly state otherwise, any contribution intentionally
//! submitted for inclusion in the work by you, as defined in the Apache-2.0
//! license, shall be dual licensed as above, without any additional terms or
//! conditions.

// crate-specific exceptions:
#![allow(
    unsafe_code,
    non_upper_case_globals,
    non_camel_case_types,
    non_snake_case,
    clippy::doc_markdown, // TODO: fixup comments and docs (though annoyingly complains about "PhysX")
    clippy::unreadable_literal,
    clippy::unused_unit,
    clippy::upper_case_acronyms
)]

#[cfg(feature = "structgen")]
include!(concat!(env!("OUT_DIR"), "/structgen_out.rs"));

#[cfg(all(
    not(feature = "structgen"),
    target_os = "linux",
    target_arch = "x86_64",
))]
include!("generated/unix/structgen.rs");

#[cfg(all(
    not(feature = "structgen"),
    target_os = "linux",
    target_arch = "aarch64",
))]
include!("generated/unix/structgen.rs");

#[cfg(all(
    not(feature = "structgen"),
    target_os = "android",
    target_arch = "x86_64",
))]
include!("generated/unix/structgen.rs");

#[cfg(all(
    not(feature = "structgen"),
    target_os = "android",
    target_arch = "aarch64",
))]
include!("generated/unix/structgen.rs");

#[cfg(all(
    not(feature = "structgen"),
    target_os = "macos",
    target_arch = "x86_64",
))]
include!("generated/unix/structgen.rs");

#[cfg(all(
    not(feature = "structgen"),
    target_os = "macos",
    target_arch = "aarch64",
))]
include!("generated/unix/structgen.rs");

#[cfg(all(
    not(feature = "structgen"),
    target_os = "windows",
    target_arch = "x86_64",
    target_env = "msvc",
))]
include!("generated/x86_64-pc-windows-msvc/structgen.rs");

include!("physx_generated.rs");

use core::mem::MaybeUninit;
use std::ffi::c_void;

pub const fn version(major: u32, minor: u32, patch: u32) -> u32 {
    (major << 24) + (minor << 16) + (patch << 8)
}

const fn can_pack_into_pointer<T>() -> bool {
    core::mem::size_of::<T>() <= core::mem::size_of::<*mut c_void>()
        && core::mem::align_of::<T>() <= core::mem::align_of::<*mut c_void>()
}

/// The type of `const void* userData` parameters in functions. Only allows shared access to the
/// underlying data. Modification is still possible for data on the heap by using internal
/// mutability.
#[repr(transparent)]
#[derive(Clone, Copy, Debug)]
pub struct ConstUserData(UserData);

impl ConstUserData {
    /// Get a reference to previously-initialized data of type `T`.
    ///
    /// # Safety
    ///
    /// You must have previously initialized `self` by calling `new_maybe_packed` or `intialize_maybe_packed` with
    /// data of the same exact `T` on the `UserData` that this came from, and not have already
    /// called `drop_and_dealloc` on `self` since doing so.
    #[inline(always)]
    pub unsafe fn maybe_packed_data_ref<T>(&self) -> &T {
        self.0.maybe_packed_data_ref::<T>()
    }

    /// Get a reference to previously-initialized data of type `T` which you know was initialized
    /// on the heap (i.e. through `new_on_heap` or `initialize_on_heap`).
    ///
    /// # Safety
    ///
    /// You must have previously initialized `self` by calling `new_on_heap` or `initialize_on_heap`
    /// with data of the same exact `T` on the `UserData` that this came from, and not have already
    /// called `heap_drop_and_dealloc` on `self` since doing so.
    #[inline(always)]
    pub unsafe fn heap_data_ref<T>(&self) -> &T {
        self.0.heap_data_ref::<T>()
    }
}

/// The type of `void* userData` fields and function parameters, which is a `void*` pointer in the
/// PhysX api, but which we turn into this `union` on the Rust side to be able to pack small user
/// data types inline into the space of the pointer itself when possible.
///
/// In a given situation, you should choose whether you want to exploit the idea of trying to pack
/// data into the size of the pointer or not. If so, use the `maybe_packed` family of methods.
/// If not, use the `heap` family of methods.
///
/// NOTE: In a world where cross-language C-to-Rust link-time optimization existed and we statically
/// linked PhysX, this could possibly break since on the PhsyX side it's a `void*` which is
/// `noundef` under Clang whereas we explicitly allow types with arbitrary layout (including
/// padding) to be packed as long as they have the necessary size an alignment. But, cross-lang
/// LTO like that does not currently exist and is unlikely to happen, so it's Fine TM.
#[repr(C)]
#[derive(Clone, Copy)]
pub union UserData {
    heap_pointer: *mut c_void,
    packed_data: MaybeUninit<*mut c_void>,
}

impl Default for UserData {
    #[inline(always)]
    fn default() -> Self {
        Self::null()
    }
}

impl std::fmt::Debug for UserData {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        f.write_str("<opaque UserData>")
    }
}

impl UserData {
    /// Create a new `UserData` which is immediately initialized with the given `data`.
    ///
    /// See [`UserData::initialize_maybe_packed`] for more details.
    #[inline]
    pub fn new_maybe_packed<T>(data: T) -> Self {
        let mut ret = UserData {
            packed_data: MaybeUninit::uninit(),
        };
        ret.initialize_maybe_packed(data);
        ret
    }

    /// Create a new `UserData` by placing `data` of type `T` on the heap and then making `self`
    /// a pointer to that data.
    ///
    /// See [`UserData::initialize_on_heap`] for more information.
    #[inline]
    pub fn new_on_heap<T>(data: T) -> Self {
        let mut ret = UserData {
            packed_data: MaybeUninit::uninit(),
        };
        ret.initialize_on_heap(data);
        ret
    }

    /// Create a new `UserData` which is zeroed, i.e. a null pointer. You still must
    /// initialize it before using any of the data accessor methods!
    #[inline(always)]
    pub fn null() -> Self {
        UserData {
            heap_pointer: core::ptr::null_mut(),
        }
    }

    /// Returns true if `T` would be packed when using the maybe-packed initialization methods
    /// on `UserData`
    #[inline(always)]
    pub const fn can_pack<T>() -> bool {
        can_pack_into_pointer::<T>()
    }

    /// Initialize the field by placing `data` of type `T` on the heap and then making `self`
    /// a pointer to that data.
    ///
    /// This is useful in cases where a `user_data` will be passed back through a callback function
    /// and you want to be able to guarantee you can modify the actual stored user data. In such
    /// cases, if we packed the data into the `void*` pointer, that data is passed by-value into
    /// our callback function and so any modifications that happen to it inline wouldn't actually
    /// be written back to where the data is stored in memory.
    ///
    /// In order to access it, you should use `heap_data_ref`, `heap_data_mut`, and dealloc/drop
    /// it with `heap_drop_and_dealloc`. This is because if `T`'s layout can fit within the
    /// size of a pointer, the regular `data_ref`, `data_mut`, and `drop_and_dealloc` functions
    /// will assume `self` has been initialized as packed data, which would result in
    /// undefined behavior when `self` (which is a pointer) is interpreted as a `T`.
    #[inline(always)]
    pub fn initialize_on_heap<T>(&mut self, data: T) {
        let heap_ptr = Box::into_raw(Box::new(data));
        self.heap_pointer = heap_ptr.cast();
    }

    /// Initialize the field with arbitrary user data of type `T`.
    ///
    /// If the data can be packed into the space of a `*mut c_void` (its size and alignement are
    /// both less than or equal to the size and alignment of a pointer on your platform), then
    /// it will be written inline into the space of the pointer. If it cannot, it will be placed
    /// on the heap and a pointer to it will be written to this field.
    ///
    /// You can access data you've initialized using the other functions available on this type.
    /// If `T` could not be packed and was put on the heap, you must call
    /// [`UserData::drop_and_dealloc`] with the same `T` in order to drop and deallocate it,
    /// if you care about it being dropped or dealloced (if not, the memory will leak).
    ///
    /// If you call this when data has already been initialized, it will be clobbered if
    /// it was written inline and if it was on the heap the old data will be leaked and replaced
    /// with the new data.
    #[inline]
    pub fn initialize_maybe_packed<T>(&mut self, data: T) {
        if can_pack_into_pointer::<T>() {
            // SAFETY: We've checked T's size and align are both < *mut c_void, which `self` must
            // be at least size/align of
            unsafe {
                core::ptr::write(core::ptr::addr_of_mut!(self.packed_data).cast::<T>(), data);
            }
        } else {
            self.initialize_on_heap::<T>(data);
        }
    }

    /// Get a reference to previously-initialized data of type `T`.
    ///
    /// # Safety
    ///
    /// You must have previously initialized `self` by calling `new_maybe_packed` or `initialize_maybe_packed` with
    /// data of the same exact `T`, and not have already called `drop_and_dealloc` on `self` since
    /// doing so.
    #[inline(always)]
    pub unsafe fn maybe_packed_data_ref<T>(&self) -> &T {
        if can_pack_into_pointer::<T>() {
            // SAFETY: if function level safety is true, we must have initialized a valid T inside
            // self as packed, since we use the same check in `auto_initialize_with_data`
            unsafe { &*(core::ptr::addr_of!(self.packed_data).cast::<T>()) }
        } else {
            // SAFETY: if function level safety is true, we must have initialized a valid T on
            // the heap which we point to, since we use the same check in `auto_initialize_with_data`
            self.heap_data_ref::<T>()
        }
    }

    /// Get a reference to previously-initialized data of type `T` which you know was initialized
    /// on the heap (i.e. through `new_on_heap` or `initialize_on_heap`).
    ///
    /// Note that the lifetime of the returned reference is scoped to the borrow of `self`, which is
    /// the most conservative estimate of its lifetime. However, in some cases this is overly
    /// restrictive. In that case you can either use `&mut *slf.as_mut_ptr()` and deref or
    /// `transmute` the returned reference from this function to extend the lifetime if you know
    /// doing so is valid.
    ///
    /// # Safety
    ///
    /// You must have previously initialized `self` by calling `new_on_heap` or `initialize_on_heap`
    /// with data of the same exact `T` on the `UserData` that this came from, and not have already
    /// called `heap_drop_and_dealloc` on `self` since doing so.
    #[inline(always)]
    pub unsafe fn heap_data_ref<T>(&self) -> &T {
        unsafe { &*(self.heap_pointer.cast::<T>().cast_const()) }
    }

    /// Get a reference to previously-initialized data of type `T`.
    ///
    /// # Safety
    ///
    /// You must have previously initialized `self` by calling `new_maybe_packed` or `initialize_maybe_packed` with
    /// data of the same exact `T`, and not have already called `drop_and_dealloc` on `self` since
    /// doing so.
    #[inline(always)]
    pub unsafe fn maybe_packed_data_mut<T>(&mut self) -> &mut T {
        if can_pack_into_pointer::<T>() {
            // SAFETY: if function level safety is true, we must have initialized a valid T inside
            // self as packed, since we use the same check in `initialize_maybe_packed`
            unsafe { &mut *(core::ptr::addr_of_mut!(self.packed_data).cast::<T>()) }
        } else {
            // SAFETY: if function level safety is true, we must have initialized a valid T on
            // the heap which we point to, since we use the same check in `initialize_maybe_packed`
            self.heap_data_mut::<T>()
        }
    }

    /// Get a reference to previously-initialized data of type `T` which you know was initialized
    /// on the heap (i.e. through `new_on_heap` or `initialize_on_heap`).
    ///
    /// Note that the lifetime of the returned reference is scoped to the borrow of `self`, which is
    /// the most conservative estimate of its lifetime. However, in some cases this is overly
    /// restrictive. In that case you can either use `&mut *slf.as_mut_ptr()` and deref or
    /// `transmute` the returned reference from this function to extend the lifetime if you know
    /// doing so is valid.
    ///
    /// # Safety
    ///
    /// You must have previously initialized `self` by calling `new_on_heap` or `initialize_on_heap`
    /// with data of the same exact `T` on the `UserData` that this came from, and not have already
    /// called `heap_drop_and_dealloc` on `self` since doing so.
    #[inline(always)]
    pub unsafe fn heap_data_mut<T>(&mut self) -> &mut T {
        unsafe { &mut *(self.heap_pointer.cast::<T>()) }
    }

    /// Drop and deallocate the space that was allocated for the data on the heap.
    ///
    /// # Safety
    ///
    /// You must have previously initialized `self` by calling `new_on_heap` or `initialize_on_heap`
    /// with data of the same exact `T`, and not have already called `drop_and_dealloc` on `self`
    /// since doing so.
    #[inline]
    pub unsafe fn heap_drop_and_dealloc<T>(&mut self) {
        // SAFETY: self is a heap_pointer and must have been initialized due to function safety
        let ptr = unsafe { self.heap_pointer }.cast::<T>();
        // SAFETY: we must have constructed the value pointed to by `ptr` by putting it in a box
        // if the function level safety is met.
        let reconsructed_box = unsafe { Box::from_raw(ptr) };
        drop(reconsructed_box);
    }

    /// Drop and deallocate the space that was allocated for the data on the heap, if there was
    /// any.
    ///
    /// For types that were packed inline, it runs `drop`, if it exists for `T`, or otherwise does
    /// nothing.
    ///
    /// # Safety
    ///
    /// You must have previously initialized `self` by calling `new_maybe_packed` or `initialize_maybe_packed` with
    /// data of the same exact `T`, and not have already called `drop_and_dealloc` on `self` since
    /// doing so.
    #[inline(always)]
    pub unsafe fn maybe_packed_drop_and_dealloc<T>(&mut self) {
        if can_pack_into_pointer::<T>() {
            // SAFETY: self is a packed T and has not been dropped according to function safety
            // and the fact we use the same check in `initialize_maybe_packed`
            unsafe { core::ptr::drop_in_place(self.maybe_packed_data_mut::<T>()) }
        } else {
            // SAFETY: we must have constructed the value pointed to by `ptr` by putting it in a box
            // if the function level safety is met.
            unsafe { self.heap_drop_and_dealloc::<T>() }
        }
    }

    /// Interpret `self` as a `*mut T`
    ///
    /// # Safety
    ///
    /// `self` must have been previously initialized as a pointer, i.e. through one of the
    /// heap initialization functions or [`UserData::null`]. It **must not** contain any
    /// uninit bytes, i.e. [`UserData::uninit`] or writing a `T` that is not a pointer packed
    /// into `self`
    #[inline(always)]
    pub unsafe fn as_mut_ptr<T>(&mut self) -> *mut T {
        self.heap_pointer.cast::<T>()
    }

    /// Interpret `self` as a `*const T`
    ///
    /// # Safety
    ///
    /// `self` must have been previously initialized as a pointer, i.e. through one of the
    /// heap initialization functions or [`UserData::null`]. It **must not** contain any
    /// uninit bytes, i.e. [`UserData::uninit`] or writing a `T` that is not a pointer packed
    /// into `self`
    #[inline(always)]
    pub unsafe fn as_ptr<T>(&self) -> *const T {
        self.heap_pointer.cast::<T>().cast_const()
    }

    /// Interpret `self` as a `*const c_void` and check if it is null.
    ///
    /// # Safety
    ///
    /// `self` must have been previously initialized as a pointer, i.e. through one of the
    /// heap initialization functions or [`UserData::null`]. It **must not** contain any
    /// uninit bytes, i.e. [`UserData::uninit`] or writing a `T` that is not a pointer packed
    /// into `self`
    #[inline(always)]
    pub unsafe fn is_null(&self) -> bool {
        self.as_ptr::<c_void>().is_null()
    }
}

pub type CollisionCallback =
    unsafe extern "C" fn(UserData, *const PxContactPairHeader, *const PxContactPair, u32);

pub type TriggerCallback = unsafe extern "C" fn(UserData, *const PxTriggerPair, u32);

pub type ConstraintBreakCallback = unsafe extern "C" fn(UserData, *const PxConstraintInfo, u32);

pub type WakeSleepCallback = unsafe extern "C" fn(UserData, *const *const PxActor, u32, bool);

pub type AdvanceCallback =
    unsafe extern "C" fn(UserData, *const *const PxRigidBody, *const PxTransform, u32);

// Function pointers in Rust are normally not nullable (which is why they don't require unsafe to call)
// but we need them to be, so we simply wrap them in Option<>. An Option<funcptr> is luckily represented
// by the compiler as a simple pointer with null representing None, so this is compatible with the C struct.
#[repr(C)]
#[derive(Default)]
pub struct SimulationEventCallbackInfo {
    // Callback for collision events.
    pub collision_callback: Option<CollisionCallback>,
    pub collision_user_data: UserData,
    // Callback for trigger shape events (an object entered or left a trigger shape).
    pub trigger_callback: Option<TriggerCallback>,
    pub trigger_user_data: UserData,
    // Callback for when a constraint breaks (such as a joint with a force limit)
    pub constraint_break_callback: Option<ConstraintBreakCallback>,
    pub constraint_break_user_data: UserData,
    // Callback for when an object falls asleep or is awoken.
    pub wake_sleep_callback: Option<WakeSleepCallback>,
    pub wake_sleep_user_data: UserData,
    // Callback to get the next pose early for objects (if flagged with eENABLE_POSE_INTEGRATION_PREVIEW).
    pub advance_callback: Option<AdvanceCallback>,
    pub advance_user_data: UserData,
}

pub type RaycastHitCallback = unsafe extern "C" fn(
    *const PxRigidActor,
    *const PxFilterData,
    *const PxShape,
    hit_flags: u32,
    ConstUserData,
) -> PxQueryHitType;

pub type PostFilterCallback =
    unsafe extern "C" fn(*const PxFilterData, *const PxQueryHit, ConstUserData) -> PxQueryHitType;

#[repr(C)]
pub struct FilterShaderCallbackInfo {
    pub attributes0: u32,
    pub attributes1: u32,
    pub filterData0: PxFilterData,
    pub filterData1: PxFilterData,
    pub pairFlags: *mut PxPairFlags,
    pub constantBlock: *const std::ffi::c_void,
    pub constantBlockSize: u32,
}

pub type SimulationFilterShader =
    unsafe extern "C" fn(*mut FilterShaderCallbackInfo) -> PxFilterFlags;

pub type RaycastProcessTouchesCallback =
    unsafe extern "C" fn(*const PxRaycastHit, u32, UserData) -> bool;
pub type SweepProcessTouchesCallback =
    unsafe extern "C" fn(*const PxSweepHit, u32, UserData) -> bool;
pub type OverlapProcessTouchesCallback =
    unsafe extern "C" fn(*const PxOverlapHit, u32, UserData) -> bool;

pub type FinalizeQueryCallback = unsafe extern "C" fn(UserData);

pub type AllocCallback =
    unsafe extern "C" fn(u64, *const c_void, *const c_void, u32, ConstUserData) -> *mut c_void;

pub type DeallocCallback = unsafe extern "C" fn(*const c_void, ConstUserData);

pub type ZoneStartCallback =
    unsafe extern "C" fn(*const i8, bool, u64, ConstUserData) -> *mut c_void;

pub type ZoneEndCallback = unsafe extern "C" fn(*const c_void, *const i8, bool, u64, ConstUserData);

pub type ErrorCallback =
    unsafe extern "C" fn(PxErrorCode, *const i8, *const i8, u32, ConstUserData);

pub type AssertHandler = unsafe extern "C" fn(*const i8, *const i8, u32, *mut bool, ConstUserData);

extern "C" {
    pub fn physx_create_foundation() -> *mut PxFoundation;
    pub fn physx_create_foundation_with_alloc(
        allocator: *mut PxDefaultAllocator,
    ) -> *mut PxFoundation;
    pub fn physx_create_physics(foundation: *mut PxFoundation) -> *mut PxPhysics;

    pub fn get_default_allocator() -> *mut PxDefaultAllocator;
    pub fn get_default_error_callback() -> *mut PxDefaultErrorCallback;

    /// Destroy the returned callback object using PxQueryFilterCallback_delete.
    pub fn create_raycast_filter_callback(
        actor_to_ignore: *const PxRigidActor,
    ) -> *mut PxQueryFilterCallback;

    /// Destroy the returned callback object using PxQueryFilterCallback_delete.
    pub fn create_raycast_filter_callback_func(
        callback: RaycastHitCallback,
        userdata: *mut c_void,
    ) -> *mut PxQueryFilterCallback;

    /// Destroy the returned callback object using PxQueryFilterCallback_delete.
    pub fn create_pre_and_post_raycast_filter_callback_func(
        preFilter: RaycastHitCallback,
        postFilter: PostFilterCallback,
        userdata: *mut c_void,
    ) -> *mut PxQueryFilterCallback;

    pub fn create_raycast_buffer() -> *mut PxRaycastCallback;
    pub fn create_sweep_buffer() -> *mut PxSweepCallback;
    pub fn create_overlap_buffer() -> *mut PxOverlapCallback;

    pub fn create_raycast_callback(
        process_touches_callback: RaycastProcessTouchesCallback,
        finalize_query_callback: FinalizeQueryCallback,
        touches_buffer: *mut PxRaycastHit,
        num_touches: u32,
        userdata: UserData,
    ) -> *mut PxRaycastCallback;
    pub fn create_sweep_callback(
        process_touches_callback: SweepProcessTouchesCallback,
        finalize_query_callback: FinalizeQueryCallback,
        touches_buffer: *mut PxSweepHit,
        num_touches: u32,
        userdata: UserData,
    ) -> *mut PxSweepCallback;
    pub fn create_overlap_callback(
        process_touches_callback: OverlapProcessTouchesCallback,
        finalize_query_callback: FinalizeQueryCallback,
        touches_buffer: *mut PxOverlapHit,
        num_touches: u32,
        userdata: UserData,
    ) -> *mut PxOverlapCallback;

    pub fn delete_raycast_callback(callback: *mut PxRaycastCallback);
    pub fn delete_sweep_callback(callback: *mut PxSweepCallback);
    pub fn delete_overlap_callback(callback: *mut PxOverlapCallback);

    pub fn create_alloc_callback(
        alloc_callback: AllocCallback,
        dealloc_callback: DeallocCallback,
        userdata: UserData,
    ) -> *mut PxAllocatorCallback;

    pub fn create_profiler_callback(
        zone_start_callback: ZoneStartCallback,
        zone_end_callback: ZoneEndCallback,
        userdata: UserData,
    ) -> *mut PxProfilerCallback;

    pub fn get_alloc_callback_user_data(alloc_callback: *mut PxAllocatorCallback) -> UserData;

    pub fn create_error_callback(
        error_callback: ErrorCallback,
        userdata: UserData,
    ) -> *mut PxErrorCallback;

    pub fn create_assert_handler(
        error_callback: AssertHandler,
        userdata: UserData,
    ) -> *mut PxAssertHandler;

    pub fn get_default_simulation_filter_shader() -> *mut c_void;

    /// Create a C++ proxy callback which will forward contact events to `Callback`.
    /// The returned pointer must be freed by calling `destroy_contact_callback` when done using.
    #[deprecated]
    pub fn create_contact_callback(
        callback: CollisionCallback,
        userdata: UserData,
    ) -> *mut PxSimulationEventCallback;

    /// Deallocates the PxSimulationEventCallback that has previously been created
    #[deprecated()]
    pub fn destroy_contact_callback(callback: *mut PxSimulationEventCallback);

    /// New interface to handle simulation events, replacing create_contact_callback.
    pub fn create_simulation_event_callbacks(
        callbacks: *const SimulationEventCallbackInfo,
    ) -> *mut PxSimulationEventCallback;

    pub fn get_simulation_event_info(
        callback: *mut PxSimulationEventCallback,
    ) -> *mut SimulationEventCallbackInfo;

    pub fn destroy_simulation_event_callbacks(callback: *mut PxSimulationEventCallback);

    /// Override the default filter shader in the scene with a custom function.
    /// If call_default_filter_shader_first is set to true, this will first call the
    /// built-in PhysX filter (that matches Physx 2.8 behavior) before your callback.
    pub fn enable_custom_filter_shader(
        scene_desc: *mut PxSceneDesc,
        shader: SimulationFilterShader,
        call_default_filter_shader_first: u32,
    );

    #[doc(hidden)]
    /// Should only be used in testing etc! This isn't generated as we don't generate op functions.
    pub fn PxAssertHandler_opCall_mut(
        self_: *mut PxAssertHandler,
        expr: *const i8,
        file: *const i8,
        line: i32,
        ignore: *mut bool,
    ) -> ();
}
