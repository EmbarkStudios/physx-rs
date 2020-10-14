// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 10 April 2019

#![warn(clippy::all)]
#![allow(clippy::missing_safety_doc)]
#![allow(deprecated)]

/*!
Wrapper for PhysX Scene
 */

use super::{
    articulation_reduced_coordinate::*,
    body::*,
    controller::*,
    physics::Physics,
    rigid_actor::RigidActor,
    rigid_dynamic::RigidDynamic,
    rigid_static::*,
    traits::*,
    transform::{gl_to_px_v3, px_to_gl_v3},
    user_data::UserData,
    visual_debugger::*,
};
use enumflags2::BitFlags;
use glam::Vec3;

use physx_sys::*;
use std::ops::{Deref, DerefMut};
use std::ptr::{null, null_mut};
use std::sync::RwLock;

pub struct Scene {
    px_scene: RwLock<Option<*mut PxScene>>,
    bodies: Vec<ArticulationReducedCoordinate>,
    statics: Vec<RigidStatic>,
    dynamics: Vec<RigidDynamic>,
    simulation_callback: Option<*mut PxSimulationEventCallback>,
    controller_manager: Option<ControllerManager>,
}

////////////////////////////////////////////////////////////////////////////////
// #[physx_type]
impl Scene {
    pub fn new(scene: *mut PxScene) -> Self {
        let mut _self = Self {
            px_scene: RwLock::new(Some(scene)),
            bodies: Vec::new(),
            dynamics: Vec::new(),
            statics: Vec::new(),
            simulation_callback: None,
            controller_manager: None,
        };
        _self.allocate_user_data();
        _self
    }

    fn allocate_user_data(&mut self) {
        let userdata = Box::new(UserData::new_scene());
        let scene = self.px_scene.write().unwrap().unwrap();
        unsafe {
            (*scene).userData = Box::into_raw(userdata) as *mut std::ffi::c_void;
        }
    }

    pub unsafe fn release(&mut self) {
        self.bodies.drain(..).for_each(|mut e| e.release());
        self.statics.drain(..).for_each(|mut e| e.release());
        self.dynamics.drain(..).for_each(|mut e| e.release());

        // destroy simulation callback if we have one
        if let Some(callback) = self.simulation_callback.take() {
            destroy_simulation_event_callbacks(callback);
        }

        if let Some(manager) = self.controller_manager.take() {
            manager.release();
        }

        // Release the scene object
        let mut scene = self.px_scene.write().unwrap();
        let scene = scene.take().expect("scene already released");
        let b: Box<UserData> = Box::from_raw((*scene).userData as *mut _);

        drop(b);
        PxScene_release_mut(scene);
    }

    /// Get the visual debugger client
    pub fn get_pvd_client(&self) -> PvdSceneClient {
        PvdSceneClient::from_ptr(unsafe {
            PxScene_getScenePvdClient_mut(
                self.px_scene.write().unwrap().expect("accessing null ptr"),
            )
        })
    }

    pub fn add_capsule_controller(
        &mut self,
        desc: &CapsuleControllerDesc,
    ) -> Result<Controller, ControllerError> {
        if self.controller_manager.is_none() {
            return Err(ControllerError::NoControllerManager);
        }

        let mut controller = self
            .controller_manager
            .as_ref()
            .unwrap()
            .create_controller(desc);

        Ok(Controller::new(controller.get_raw_mut()))
    }

    pub fn add_actor(&mut self, mut actor: RigidStatic) -> BodyHandle {
        unsafe {
            PxScene_addActor_mut(
                self.px_scene.write().unwrap().expect("accessing null ptr"),
                actor.get_raw_mut() as *mut PxActor,
                null(),
            );
        }

        let handle = BodyHandle(actor.get_raw() as usize);
        self.statics.push(actor);
        handle
    }

    pub fn add_dynamic(&mut self, mut actor: RigidDynamic) -> BodyHandle {
        unsafe {
            PxScene_addActor_mut(
                self.px_scene.write().unwrap().expect("accessing null ptr"),
                actor.get_raw_mut() as *mut PxActor,
                null(),
            );
        }

        let handle = BodyHandle(actor.get_raw() as usize);
        self.dynamics.push(actor);
        handle
    }

    /// Add a multibody articulation to the world
    /// TODO: Make this take a boxed-trait object or similar instead
    pub fn add_articulation<T: FnOnce(&mut ArticulationReducedCoordinate)>(
        &mut self,
        mut mb: ArticulationReducedCoordinate,
        func: T,
    ) -> PartHandle {
        let handle = mb.root_handle();
        func(&mut mb);

        let scene = self.px_scene.write().unwrap();
        unsafe {
            PxScene_addArticulation_mut(
                scene.expect("accessing null ptr"),
                mb.deref_mut().get_raw_mut(),
            );
        }
        mb.common_init();
        self.bodies.push(mb);
        handle
    }

    /// Remove an articulation from the world
    pub fn remove_articulation(&mut self, handle: BodyHandle) {
        unsafe {
            let articulation = handle.0 as *const PxArticulationBase;
            PxScene_removeArticulation_mut(
                self.px_scene.write().unwrap().expect("accessing null ptr"),
                articulation as *mut PxArticulationBase,
                false,
            );

            if let Some(idx) = self
                .bodies
                .iter()
                .position(|b| b.deref().get_raw() == articulation)
            {
                let mut body = self.bodies.swap_remove(idx);
                body.release();
            }
        }
    }

    ////////////////////////////////////////////////////////////////////////////////

    pub fn simulate(&mut self, duration: f32) {
        let scene = self.px_scene.write().unwrap();
        unsafe {
            PxScene_simulate_mut(
                scene.expect("accessing null ptr"),
                duration,
                null_mut(),
                null_mut(),
                0,
                true,
            );
        }
    }

    ////////////////////////////////////////////////////////////////////////////////

    pub fn fetch_results(&mut self, block: bool) -> Result<(), u32> {
        let scene = self.px_scene.write().unwrap();
        unsafe {
            let mut error: u32 = 0;
            PxScene_fetchResults_mut(scene.expect("accessing null ptr"), block, &mut error);
            if error == 0 {
                Ok(())
            } else {
                Err(error)
            }
        }
    }
    //    fn read(self) -> std::sync::RwLockReadGuard<Px>

    pub fn get_multibody(&self, handle: BodyHandle) -> Option<&ArticulationReducedCoordinate> {
        self.bodies.iter().find(|bod| bod.handle() == handle)
    }

    pub fn get_multibody_mut(
        &mut self,
        handle: BodyHandle,
    ) -> Option<&mut ArticulationReducedCoordinate> {
        self.bodies.iter_mut().find(|bod| bod.handle() == handle)
    }

    pub fn sample_height(
        &self,
        position: Vec3,
        ignored: Option<&RigidActor>,
        ignore_dynamic: bool,
    ) -> Option<Vec3> {
        // todo[tolsson]: clean this up
        let ignored_body = if let Some(body) = ignored {
            body.get_raw()
        } else {
            null_mut()
        };

        let down = -Vec3::unit_y();
        let max_dist = 1e5;

        unsafe {
            let mut filter_data = PxQueryFilterData_new_2(PxQueryFlags {
                mBits: (PxQueryFlag::ePREFILTER | PxQueryFlag::eSTATIC) as u16,
            });

            if !ignore_dynamic {
                filter_data.flags.mBits |= PxQueryFlag::eDYNAMIC as u16;
            }

            let filter_callback = create_raycast_filter_callback(ignored_body);
            let mut hit = std::mem::MaybeUninit::uninit();

            let hit_anything = PxSceneQueryExt_raycastSingle_mut(
                self.px_scene
                    .read()
                    .expect("failed reading from scene")
                    .expect("accessing null ptr"),
                &gl_to_px_v3(position),
                &gl_to_px_v3(down),
                max_dist,
                PxSceneQueryFlags {
                    mBits: PxHitFlag::ePOSITION as u16,
                },
                hit.as_mut_ptr(),
                &filter_data as *const PxQueryFilterData as *const PxSceneQueryFilterData,
                filter_callback as *mut PxQueryFilterCallback as *mut PxSceneQueryFilterCallback,
                null_mut(),
            );

            let hit = hit.assume_init();

            PxQueryFilterCallback_delete(filter_callback);

            if hit_anything {
                Some(px_to_gl_v3(hit.position))
            } else {
                None
            }
        }
    }

    // See below function `set_simulation_event_callbacks`.
    #[deprecated]
    pub fn set_simulation_event_callback<T>(
        &mut self,
        callback: physx_sys::CollisionCallback,
        userdata: *mut T,
    ) {
        unsafe {
            let callback_info = physx_sys::SimulationEventCallbackInfo {
                collision_callback: Some(callback),
                collision_user_data: userdata as *mut std::ffi::c_void,
                ..Default::default()
            };
            let callback = physx_sys::create_simulation_event_callbacks(&callback_info);
            self.simulation_callback = Some(callback);
            PxScene_setSimulationEventCallback_mut(
                self.px_scene
                    .write()
                    .expect("failed reading scene")
                    .expect("accessing null ptr"),
                callback,
            );
        }
    }

    pub fn set_simulation_event_callbacks(
        &mut self,
        callbacks: &physx_sys::SimulationEventCallbackInfo,
    ) {
        unsafe {
            let callback = physx_sys::create_simulation_event_callbacks(&*callbacks);
            self.simulation_callback = Some(callback);
            PxScene_setSimulationEventCallback_mut(
                self.px_scene
                    .write()
                    .expect("failed reading scene")
                    .expect("accessing null ptr"),
                callback,
            );
        }
    }

    /// Lookup and retrieve a RigidStatic reference for this handle
    pub fn get_static(&self, handle: BodyHandle) -> Option<&RigidStatic> {
        self.statics.iter().find(|elem| handle == elem.handle())
    }

    /// Lookup and retrieve a RigidStatic reference for this handle
    pub fn get_static_mut(&mut self, handle: BodyHandle) -> Option<&mut RigidStatic> {
        self.statics.iter_mut().find(|elem| handle == elem.handle())
    }

    /// Lookup and retrieve a RigidDynamic reference for this handle
    pub fn get_dynamic(&self, handle: BodyHandle) -> Option<&RigidDynamic> {
        self.dynamics.iter().find(|elem| handle == elem.handle())
    }

    /// Lookup and retrieve a RigidDynamic reference for this handle
    pub fn get_dynamic_mut(&mut self, handle: BodyHandle) -> Option<&mut RigidDynamic> {
        self.dynamics
            .iter_mut()
            .find(|elem| handle == elem.handle())
    }

    /// Lookup and retrieve a RigidActor reference for this handle
    pub fn get_rigid_actor(&self, handle: BodyHandle) -> Option<&RigidActor> {
        if let Some(dynamic) = self.get_dynamic(handle) {
            Some(dynamic)
        } else if let Some(static_) = self.get_static(handle) {
            Some(static_)
        } else {
            for body in &self.bodies {
                let art_handle = body.handle();
                let part_handle = PartHandle(art_handle.0, handle.0);
                let part = body.part_from_handle(part_handle);
                if part.is_some() {
                    return part.map(|link| link.deref().deref());
                }
            }
            None
        }
    }

    /// Retrieve a RigidActor based on the bodyhandle. Note: This API is unsafe
    /// and bypasses a lot of safety checks for lifetimes and ownership.
    pub unsafe fn get_rigid_actor_unchecked(&self, handle: &BodyHandle) -> &RigidActor {
        // Clippy this is the right way to do it instead of a transmute...
        &*(handle as *const BodyHandle as *const super::px_type::PxType<PxRigidActor>)
    }

    pub fn find_matching_rigid_actor_mut(
        &mut self,
        actor: *const PxRigidActor,
    ) -> Option<&mut RigidActor> {
        if let Some(rigid) = self
            .statics
            .iter_mut()
            .find(|elem| actor == elem.get_raw() as *const PxRigidActor)
        {
            return Some(rigid);
        } else if let Some(rigid) = self
            .dynamics
            .iter_mut()
            .find(|elem| actor == elem.get_raw() as *const PxRigidActor)
        {
            return Some(rigid);
        };

        for body in &mut self.bodies {
            let handle = body.handle();
            let handle = PartHandle(handle.0, actor as usize);
            let part = body.part_from_handle_mut(handle);
            if part.is_some() {
                return part.map(|link| link.deref_mut().deref_mut());
            }
        }

        None
    }

    // pub fn find_matching_rigid_actor(&self, actor: *const PxRigidActor) -> Option<&RigidActor> {
    //     if let Some(rigid) = self.statics.iter().find_map(|elem| {
    //         let actor_ptr = elem.get_raw() as *const PxRigidActor;
    //         if actor == actor_ptr {
    //             Some(elem)
    //         } else {
    //             None
    //         }
    //     }) {
    //         return Some(rigid);
    //     };

    //     for body in &self.bodies {
    //         let handle = body.handle();
    //         let handle = PartHandle(handle.0, actor as usize);
    //         let part = body.part_from_handle(handle);
    //         if part.is_some() {
    //             return part.map(|link| link.deref().deref());
    //         }
    //     }

    //     None
    // }

    /// Looking
    pub fn collide_raw_pair(
        &mut self,
        first_px_actor: *mut PxRigidActor,
        second_px_actor: *mut PxRigidActor,
        pairs: &[PxContactPair],
    ) {
        // This function is really unrustic, but I can't find a nice way to do it
        // since the lookup of either collision member will take a mutable borrow on the scene...
        // However doing it with two pointers bypasses this, disgustingly enough. The NonNull
        // probably adds a bit of overhead, but in comparison to the search it's likely fine.
        if first_px_actor != second_px_actor {
            unsafe {
                // Since each lookup might traverse a lot of pointers we verify each lookup directly.
                let first_actor = self
                    .find_matching_rigid_actor_mut(first_px_actor)
                    .map(|val| val as *mut RigidActor);

                if let Some(first) = first_actor {
                    #[allow(clippy::transmute_ptr_to_ref)]
                    let first: &mut RigidActor = std::mem::transmute(first);
                    let second_actor = self
                        .find_matching_rigid_actor_mut(second_px_actor)
                        .map(|val| val as *mut RigidActor);

                    if let Some(second) = second_actor {
                        #[allow(clippy::transmute_ptr_to_ref)]
                        let second: &mut RigidActor = std::mem::transmute(second);
                        first.on_collide(second, pairs);
                        second.on_collide(first, pairs);
                    }
                }
            }
        }
    }

    pub fn get_bodies(&self) -> &Vec<ArticulationReducedCoordinate> {
        &self.bodies
    }

    ////////////////////////////////////////////////////////////////////////////////

    pub fn step(&mut self, step: f32, block: bool) {
        let scene = self.px_scene.write().unwrap();
        unsafe {
            PxScene_simulate_mut(
                scene.expect("accessing null ptr"),
                step,
                null_mut(),
                null_mut(),
                0,
                true,
            );
            PxScene_fetchResults_mut(scene.expect("accessing null ptr"), block, null_mut());
        }
    }

    fn add_controller_manager(&mut self, locking_enabled: bool) {
        if self.controller_manager.is_none() {
            self.controller_manager = Some(ControllerManager::new(
                self.px_scene.write().unwrap().expect("accessing null ptr"),
                locking_enabled,
            ))
        }
    }
}

#[derive(Debug, Clone, Copy, BitFlags)]
#[repr(u32)]
pub enum BroadPhaseType {
    SweepAndPrune = 1,
    MultiBoxPruning = 2,
    AutomaticBoxPruning = 4,
    GPU = 8,
}

impl Into<PxBroadPhaseType::Enum> for BroadPhaseType {
    fn into(self) -> PxBroadPhaseType::Enum {
        match self {
            BroadPhaseType::SweepAndPrune => 0,
            BroadPhaseType::MultiBoxPruning => 1,
            BroadPhaseType::AutomaticBoxPruning => 2,
            BroadPhaseType::GPU => 3,
        }
    }
}

#[derive(Debug, Clone, Copy)]
#[repr(u32)]
pub enum SolverType {
    PGS = 1,
    TGS = 2,
}

impl Into<PxSolverType::Enum> for SolverType {
    fn into(self) -> PxSolverType::Enum {
        match self {
            SolverType::PGS => PxSolverType::ePGS,
            SolverType::TGS => PxSolverType::eTGS,
        }
    }
}

pub enum SimulationThreadType {
    Dedicated(u32),
    Shared(*mut PxCpuDispatcher),
    Default,
}

pub struct SceneBuilder {
    pub(crate) gravity: Vec3,
    pub(crate) simulation_filter_shader: Option<SimulationFilterShader>,
    pub(crate) simulation_threading: Option<SimulationThreadType>,
    pub(crate) broad_phase_type: BroadPhaseType,
    pub(crate) use_controller_manager: bool,
    pub(crate) controller_manager_locking: bool,
    pub(crate) call_default_filter_shader_first: bool,
    pub(crate) use_ccd: bool,
    pub(crate) enable_ccd_resweep: bool,
    pub(crate) solver_type: SolverType,
    pub(crate) enhanced_determinism: bool,
    pub(crate) friction_every_iteration: bool,
    pub(crate) stabilization: bool,
    pub(crate) adaptive_force: bool,
    pub(crate) ccd_max_passes: usize,
}

impl Default for SceneBuilder {
    fn default() -> Self {
        Self {
            gravity: Vec3::new(0.0, -9.80665, 0.0), // standard gravity value
            call_default_filter_shader_first: true,
            simulation_filter_shader: None,
            simulation_threading: None,
            broad_phase_type: BroadPhaseType::SweepAndPrune,
            use_controller_manager: false,
            controller_manager_locking: false,
            use_ccd: false,
            enable_ccd_resweep: false,
            solver_type: SolverType::PGS,
            enhanced_determinism: false,
            friction_every_iteration: false,
            stabilization: false,
            adaptive_force: false,
            ccd_max_passes: 1,
        }
    }
}

impl SceneBuilder {
    /// Set the gravity for the scene.
    ///
    /// Default: [0.0, -9.80665, 0.0] (standard gravity)
    pub fn set_gravity(&mut self, gravity: Vec3) -> &mut Self {
        self.gravity = gravity;
        self
    }

    /// Set a callback to be invoked on various simulation events. Note:
    /// Currently only handles collision events
    ///
    /// Default: not set
    pub fn set_simulation_filter_shader(
        &mut self,
        simulation_filter_shader: SimulationFilterShader,
    ) -> &mut Self {
        self.simulation_filter_shader = Some(simulation_filter_shader);
        self
    }

    /// Enable the controller manager on the scene.
    ///
    /// Default: false, false
    pub fn use_controller_manager(
        &mut self,
        use_controller_manager: bool,
        locking_enabled: bool,
    ) -> &mut Self {
        self.use_controller_manager = use_controller_manager;
        self.controller_manager_locking = locking_enabled;
        self
    }

    /// Sets whether the filter should begin by calling the default filter shader
    /// PxDefaultSimulationFilterShader that emulates the PhysX 2.8 rules.
    ///
    /// Default: true
    pub fn set_call_default_filter_shader_first(
        &mut self,
        call_default_filter_shader_first: bool,
    ) -> &mut Self {
        self.call_default_filter_shader_first = call_default_filter_shader_first;
        self
    }

    /// Set the number of threads to use for simulation
    ///
    /// Default: not set
    pub fn set_simulation_threading(
        &mut self,
        simulation_threading: SimulationThreadType,
    ) -> &mut Self {
        self.simulation_threading = Some(simulation_threading);
        self
    }

    /// Set collision detection type
    ///
    /// Default: Sweep and prune
    pub fn set_broad_phase_type(&mut self, broad_phase_type: BroadPhaseType) -> &mut Self {
        self.broad_phase_type = broad_phase_type;
        self
    }

    /// Set if CCD (continuous collision detection) should be available for use in the scene.
    /// Doesn't automatically enable it for all rigid bodies, they still need to be flagged.
    ///
    /// If you don't set enable_ccd_resweep to true, eDISABLE_CCD_RESWEEP is set, which improves performance
    /// at the cost of accuracy right after bounces.
    ///
    /// Default: false, false
    pub fn set_use_ccd(&mut self, use_ccd: bool, enable_ccd_resweep: bool) -> &mut Self {
        self.use_ccd = use_ccd;
        self.enable_ccd_resweep = enable_ccd_resweep;
        self
    }

    /// Maximum number of CCD passes.
    ///
    /// Default: 1
    pub fn set_ccd_max_passes(&mut self, ccd_max_passes: usize) -> &mut Self {
        self.ccd_max_passes = ccd_max_passes;
        self
    }

    /// Set solver type
    ///
    /// Default: PGS
    pub fn set_solver_type(&mut self, solver_type: SolverType) -> &mut Self {
        self.solver_type = solver_type;
        self
    }

    /// Set to enable enhanced determinism flag
    ///
    /// Default: false
    pub fn set_enhanced_determinism(&mut self, enhanced_determinism: bool) -> &mut Self {
        self.enhanced_determinism = enhanced_determinism;
        self
    }

    /// Set to evaluate friction every iteration instead of only in the final 3 position iterations
    ///
    /// Default: false
    pub fn set_friction_every_iteration(&mut self, friction_every_iteration: bool) -> &mut Self {
        self.friction_every_iteration = friction_every_iteration;
        self
    }

    /// Set to enable an additional stabilization pass in the solver.
    ///
    /// Default: false
    pub fn set_stabilization(&mut self, stabilization: bool) -> &mut Self {
        self.stabilization = stabilization;
        self
    }

    /// Set to enable adaptive force to accelerate convergence of the solver
    ///
    /// Default: false
    pub fn set_adaptive_force(&mut self, adaptive_force: bool) -> &mut Self {
        self.adaptive_force = adaptive_force;
        self
    }

    pub(super) fn build_desc(&self, physics: &mut Physics) -> PxSceneDesc {
        unsafe {
            let tolerances = physics.get_tolerances_scale();
            let mut scene_desc = PxSceneDesc_new(tolerances);

            let dispatcher = match self.simulation_threading.as_ref().expect("foo") {
                SimulationThreadType::Default => {
                    phys_PxDefaultCpuDispatcherCreate(1, null_mut()) as *mut _
                }
                SimulationThreadType::Dedicated(count) => {
                    phys_PxDefaultCpuDispatcherCreate(*count, null_mut()) as *mut _
                }
                SimulationThreadType::Shared(dispatcher) => *dispatcher as *mut _,
            };

            scene_desc.cpuDispatcher = dispatcher;
            scene_desc.gravity = gl_to_px_v3(self.gravity);
            scene_desc.solverType = self.solver_type.into();
            scene_desc.broadPhaseType = self.broad_phase_type.into();

            if self.use_ccd {
                scene_desc.flags.mBits |= PxSceneFlag::eENABLE_CCD;
                if !self.enable_ccd_resweep {
                    scene_desc.flags.mBits |= PxSceneFlag::eDISABLE_CCD_RESWEEP;
                }
                scene_desc.ccdMaxPasses = self.ccd_max_passes as u32;
            }

            if self.enhanced_determinism {
                scene_desc.flags.mBits |= PxSceneFlag::eENABLE_ENHANCED_DETERMINISM;
            }

            if self.friction_every_iteration {
                scene_desc.flags.mBits |= PxSceneFlag::eENABLE_FRICTION_EVERY_ITERATION;
            }

            if self.stabilization {
                scene_desc.flags.mBits |= PxSceneFlag::eENABLE_STABILIZATION;
            }

            if self.adaptive_force {
                scene_desc.flags.mBits |= PxSceneFlag::eADAPTIVE_FORCE;
            }

            if let Some(filter_shader) = self.simulation_filter_shader {
                physx_sys::enable_custom_filter_shader(
                    &mut scene_desc as *mut PxSceneDesc,
                    filter_shader,
                    if self.call_default_filter_shader_first {
                        1
                    } else {
                        0
                    },
                );
            } else {
                scene_desc.filterShader = get_default_simulation_filter_shader();
            }
            scene_desc
        }
    }

    /// Build a new Scene from the provided parameters
    pub(super) fn build(&self, physics: &mut Physics) -> Scene {
        unsafe {
            let scene_desc = self.build_desc(physics);
            let px_scene = PxPhysics_createScene_mut(physics.get_raw_mut(), &scene_desc);
            let mut scene = Scene::new(px_scene);

            if self.use_controller_manager {
                scene.add_controller_manager(self.controller_manager_locking);
            }
            scene
        }
    }
}
