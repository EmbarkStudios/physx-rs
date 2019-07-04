#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(clippy::unreadable_literal)]

include!(concat!(env!("OUT_DIR"), "/structgen_out.rs"));
include!("physx_generated.rs");

use std::ffi::c_void;

#[macro_export]
macro_rules! version {
    ($major: literal , $minor: literal , $patch: literal) => {
        ($major << 24) + ($minor << 16) + ($patch << 8)
    };
}

pub type CollisionCallback =
    unsafe extern "C" fn(*mut c_void, *const PxContactPairHeader, *const PxContactPair, count: u32);

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

pub type SimulationFilterShader = unsafe extern "C" fn(*mut FilterShaderCallbackInfo) -> u16;

extern "C" {
    pub fn physx_create_foundation() -> *mut PxFoundation;
    pub fn physx_create_physics(foundation: *mut PxFoundation) -> *mut PxPhysics;
    pub fn get_default_allocator() -> *mut PxDefaultAllocator;
    pub fn get_default_error_callback() -> *mut PxDefaultErrorCallback;
    pub fn create_raycast_filter_callback(
        actor_to_ignore: *const PxRigidActor,
    ) -> *mut PxQueryFilterCallback;

    pub fn get_default_simulation_filter_shader() -> *mut c_void;

    /// Create a C++ proxy callback which will forward contact events to `Callback`.
    /// The returned pointer must be freed by calling `destroy_contact_callback` when done using.
    pub fn create_contact_callback(
        callback: CollisionCallback,
        userdata: *mut c_void,
    ) -> *mut PxSimulationEventCallback;

    /// Deallocates the PxSimulationEventCallback that has previously been created
    pub fn destroy_contact_callback(callback: *mut PxSimulationEventCallback);

    /// Sets a trampoline which will invoke *both* the default filter shader for the pair flags
    /// *as well as* the custom filter shader which can add pair flags and set the collision handler flag
    pub fn enable_custom_filter_shader(
        scene_desc: *mut PxSceneDesc,
        shader: SimulationFilterShader,
    );
}
