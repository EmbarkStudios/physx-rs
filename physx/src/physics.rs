// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created:  2 April 2019

/*!
Wrapper interface for Physics
 */

#![allow(clippy::not_unsafe_ptr_arg_deref)]
#![allow(clippy::missing_safety_doc)]

use super::{
    articulation_link::*, articulation_reduced_coordinate::*, body::*, cooking::*, foundation::*,
    rigid_dynamic::*, rigid_static::*, scene::*, traits::GetRaw, transform::*, visual_debugger::*,
};

use glam::{Mat4, Vec3};
use physx_sys::*;
use std::ptr::null_mut;

pub const PX_PHYSICS_VERSION: u32 = (4 << 24) + (1 << 16);

#[no_mangle]
pub extern "C" fn on_contact_callback(
    userdata: *mut std::ffi::c_void,
    header: *const PxContactPairHeader,
    pairs: *const PxContactPair,
    count: u32,
) {
    unsafe {
        if let Some(header) = header.as_ref() {
            let scene: &mut Scene = &mut *(userdata as *mut Scene);
            let first_px_actor = header.actors[0];
            let second_px_actor = header.actors[1];
            let pairs = std::slice::from_raw_parts(pairs, count as usize);
            scene.collide_raw_pair(first_px_actor, second_px_actor, pairs);
        }
    }
}

#[no_mangle]
pub extern "C" fn simulation_filter_shader(info: *mut FilterShaderCallbackInfo) -> u16 {
    unsafe {
        if let Some(info) = info.as_ref() {
            (*info.pairFlags).mBits |= (PxPairFlag::eSOLVE_CONTACT
                | PxPairFlag::eNOTIFY_TOUCH_FOUND
                | PxPairFlag::eNOTIFY_CONTACT_POINTS) as u16;
            if (info.filterData0.word0 & info.filterData1.word1) == 0 {
                PxFilterFlag::eSUPPRESS as u16
            } else {
                PxFilterFlag::eDEFAULT as u16
            }
        } else {
            PxFilterFlag::eDEFAULT as u16
        }
    }
}

pub struct Physics {
    pub physics: *mut PxPhysics,
    pvd: Option<VisualDebugger>,
    extensions_loaded: bool,
}

impl GetRaw<PxPhysics> for Physics {
    /// Get a pointer to the underlying Physics object
    fn get_raw(&self) -> *const PxPhysics {
        self.physics
    }

    /// Get a mutable pointer to the underlying Physics object
    fn get_raw_mut(&mut self) -> *mut PxPhysics {
        self.physics
    }
}

impl Physics {
    /// Create a new Physics wrapper
    fn new(builder: &PhysicsBuilder, foundation: &mut Foundation) -> Self {
        let (mut pvd, physics) = unsafe {
            if builder.enable_pvd {
                let mut pvd = VisualDebugger::new(foundation, 5425 /* default from Physics */);

                let physics = phys_PxCreatePhysics(
                    PX_PHYSICS_VERSION,
                    foundation.get_raw_mut(),
                    &builder.tolerances as *const _,
                    true,
                    pvd.get_raw_mut(),
                );

                (Some(pvd), physics)
            } else {
                (None, physx_create_physics(foundation.get_raw_mut()))
            }
        };

        let extensions_loaded = if builder.load_extensions {
            unsafe {
                phys_PxInitExtensions(
                    physics,
                    pvd.as_mut()
                        .map(|pv| pv.get_raw_mut())
                        .unwrap_or_else(null_mut),
                )
            }
        } else {
            false
        };

        Self {
            physics,
            pvd,
            extensions_loaded,
        }
    }

    ////////////////////////////////////////////////////////////////////////////////

    /// Create a new multibody
    pub fn create_multibody<T: FnOnce(&mut ArticulationReducedCoordinate)>(
        &mut self,
        scene: &mut Scene,
        func: T,
    ) -> PartHandle {
        let mb = ArticulationReducedCoordinate::new(self);
        scene.add_articulation(mb, func)
    }

    ////////////////////////////////////////////////////////////////////////////////

    pub fn create_multibody_with_root<T: FnOnce(&mut ArticulationReducedCoordinate)>(
        &mut self,
        builder: &ArticulationLinkBuilder,
        scene: &mut Scene,
        cooking: &mut Cooking,
        func: T,
    ) -> PartHandle {
        let mb = ArticulationReducedCoordinate::new_with_link(builder, self, cooking);
        scene.add_articulation(mb, func)
    }

    pub fn remove_body(&mut self, scene: &mut Scene, handle: BodyHandle) {
        scene.remove_articulation(handle);
    }

    pub fn create_rigid_static(&mut self, transform: Mat4) -> RigidStatic {
        let px_rs =
            unsafe { PxPhysics_createRigidStatic_mut(self.get_raw_mut(), &gl_to_px_tf(transform)) };

        RigidStatic::new(px_rs)
    }

    pub unsafe fn create_dynamic(
        &mut self,
        transform: Mat4,
        geometry: *const PxGeometry,
        material: *mut PxMaterial,
        density: f32,
        shape_transform: Mat4,
    ) -> RigidDynamic {
        let px_rs = phys_PxCreateDynamic(
            self.get_raw_mut(),
            &gl_to_px_tf(transform),
            geometry,
            material,
            density,
            &gl_to_px_tf(shape_transform),
        );

        RigidDynamic::new(px_rs)
    }

    pub unsafe fn create_static(
        &mut self,
        transform: Mat4,
        geometry: *const PxGeometry,
        material: *mut PxMaterial,
        shape_transform: Mat4,
    ) -> RigidStatic {
        let px_rs = phys_PxCreateStatic(
            self.get_raw_mut(),
            &gl_to_px_tf(transform),
            geometry,
            material,
            &gl_to_px_tf(shape_transform),
        );

        RigidStatic::new(px_rs)
    }

    /// Create an infinite plane with a normal pointing up, at origin, with a rough standard material.
    pub fn create_surface(&mut self) -> RigidStatic {
        unsafe {
            let plane = PxPlane_new_1(0.0, 1.0, 0.0, 0.0);
            let mtrl = PxPhysics_createMaterial_mut(phys_PxGetPhysics(), 0.9, 0.9, 0.0);
            RigidStatic::new(phys_PxCreatePlane(self.get_raw_mut(), &plane, mtrl))
        }
    }

    /// Create an infinite plane, parametrized by a normal, an offset, and a material of the surface.
    pub unsafe fn create_plane(
        &mut self,
        normal: Vec3,
        offset: f32,
        material: *mut PxMaterial,
    ) -> RigidStatic {
        let plane = PxPlane_new_1(normal.x, normal.y, normal.z, offset);
        RigidStatic::new(phys_PxCreatePlane(self.get_raw_mut(), &plane, material))
    }

    pub fn get_tolerances_scale(&self) -> &PxTolerancesScale {
        unsafe { &*PxPhysics_getTolerancesScale(self.get_raw()) as &PxTolerancesScale }
    }

    /// Creates a raw `*mut PxScene` scene without a `Scene` wrapper. Useful for applications
    /// where the `Scene` wrapper isn't appropriate.
    /// Does not support the `ControllerManager` wrapper.
    pub fn create_scene_raw(&mut self, scene_builder: &SceneBuilder) -> *mut PxScene {
        let desc = scene_builder.build_desc(self);
        unsafe { PxPhysics_createScene_mut(self.get_raw_mut(), &desc) }
    }

    /// The recommended way to create a new scene.
    pub fn create_scene(&mut self, scene_builder: &SceneBuilder) -> Box<Scene> {
        let scene = scene_builder.build(self);
        let mut scene = Box::new(scene);
        let scene_ptr = scene.as_mut() as *mut Scene;
        let callback_info = SimulationEventCallbackInfo {
            collision_callback: Some(on_contact_callback),
            collision_user_data: scene_ptr as *mut std::os::raw::c_void,
            ..Default::default()
        };
        scene.set_simulation_event_callbacks(&callback_info);
        scene
    }

    pub fn get_physics_insertion_callback(&mut self) -> *mut PxPhysicsInsertionCallback {
        unsafe { PxPhysics_getPhysicsInsertionCallback_mut(self.get_raw_mut()) }
    }

    pub fn create_material(
        &mut self,
        static_friction: f32,
        dynamic_friction: f32,
        restitution: f32,
    ) -> *mut PxMaterial {
        unsafe {
            PxPhysics_createMaterial_mut(
                self.get_raw_mut(),
                static_friction,
                dynamic_friction,
                restitution,
            )
        }
    }

    pub fn visual_debugger(&self) -> Option<&VisualDebugger> {
        self.pvd.as_ref()
    }

    pub fn visual_debugger_mut(&mut self) -> Option<&mut VisualDebugger> {
        self.pvd.as_mut()
    }
}

impl Drop for Physics {
    fn drop(&mut self) {
        unsafe {
            if self.extensions_loaded {
                phys_PxCloseExtensions();
            }
            PxPhysics_release_mut(self.get_raw_mut());
        }
    }
}

pub struct PhysicsBuilder {
    enable_pvd: bool,
    load_extensions: bool,
    tolerances: PxTolerancesScale,
}

impl Default for PhysicsBuilder {
    fn default() -> Self {
        let mut tolerances = unsafe { PxTolerancesScale_new() };
        tolerances.length = 1.0;

        Self {
            enable_pvd: false,
            load_extensions: false,
            tolerances,
        }
    }
}

impl PhysicsBuilder {
    pub fn enable_visual_debugger(&mut self, enable: bool) -> &mut Self {
        self.enable_pvd = enable;
        self
    }

    /// Set the tolerance scale for lengths in the simulation. This should be
    /// approximately the ratio between the scale of simulation and one
    /// meter. For example, if a regular simulation object is 1 centimeter 100
    /// is a good scale here.
    ///
    /// Default: 1.0
    pub fn set_length_tolerance(&mut self, length: f32) -> &mut Self {
        self.tolerances.length = length;
        self
    }

    /// Set the tolerance scale for speeds in the simulation. This should be
    /// approximately the magnitude of speeds of simulation objects.
    ///
    /// Default: 1.0
    pub fn set_speed_tolerance(&mut self, speed: f32) -> &mut Self {
        self.tolerances.speed = speed;
        self
    }

    pub fn load_extensions(&mut self, load: bool) -> &mut Self {
        self.load_extensions = load;
        self
    }

    pub fn build(&self, foundation: &mut Foundation) -> Physics {
        Physics::new(self, foundation)
    }
}
