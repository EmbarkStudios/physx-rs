// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 10 April 2019

#![allow(clippy::missing_safety_doc)]

use crate::{
    actor::{Actor, ActorMap},
    aggregate::{Aggregate, PxAggregate},
    articulation_link::ArticulationLink,
    articulation_reduced_coordinate::ArticulationReducedCoordinate,
    constraint::Constraint,
    controller::Controller,
    controller_manager::{ControllerManager, PxControllerManager},
    foundation::ScratchBuffer,
    math::PxVec3,
    owner::Owner,
    pruning_structure::PruningStructure,
    rigid_actor::RigidActor,
    rigid_dynamic::RigidDynamic,
    rigid_static::RigidStatic,
    simulation_event_callback::{
        AdvanceCallback, CollisionCallback, ConstraintBreakCallback, PxSimulationEventCallback,
        TriggerCallback, WakeSleepCallback,
    },
    traits::{Class, UserData},
    visual_debugger::PvdSceneClient,
};

use std::{
    marker::PhantomData,
    ptr::{drop_in_place, null, null_mut},
};

// A glob import is super tempting, but the wrappers shadow the names of the physx_sys types,
// so those types cannot be in scope.  Plus, it easier to see what's been implemented.
#[rustfmt::skip]
use physx_sys::{
    phys_PxCreateControllerManager,
    PxBaseTask,
    PxBroadPhaseCallback,
    PxCCDContactModifyCallback,
    PxContactModifyCallback,
    PxCpuDispatcher,
    PxSceneLimits,
    PxScene_addActor_mut,
    PxScene_addActors_mut,
    PxScene_addActors_mut_1,
    PxScene_addAggregate_mut,
    PxScene_addArticulation_mut,
    PxScene_fetchResults_mut,
    PxScene_getActiveActors_mut,
    PxScene_getActors,
    PxScene_getAggregates,
    PxScene_getArticulations,
    PxScene_getBroadPhaseCallback,
    PxScene_getCCDContactModifyCallback,
    PxScene_getConstraints,
    PxScene_getContactModifyCallback,
    PxScene_getKinematicKinematicFilteringMode,
    PxScene_getNbActors,
    PxScene_getNbAggregates,
    PxScene_getNbArticulations,
    PxScene_getNbConstraints,
    PxScene_getScenePvdClient_mut,
    PxScene_getSimulationEventCallback,
    PxScene_getStaticKinematicFilteringMode,
    PxScene_release_mut,
    PxScene_removeActor_mut,
    PxScene_removeActors_mut,
    PxScene_removeAggregate_mut,
    PxScene_removeArticulation_mut,
    PxScene_resetFiltering_mut,
    PxScene_resetFiltering_mut_1,
    PxScene_setBroadPhaseCallback_mut,
    PxScene_setCCDContactModifyCallback_mut,
    PxScene_setContactModifyCallback_mut,
    PxScene_setGravity_mut,
    PxScene_simulate_mut,
};

#[rustfmt::skip]
pub use physx_sys::{
    PxActorTypeFlag as ActorTypeFlag,
    PxActorTypeFlags as ActorTypeFlags,
    PxBroadPhaseType as BroadPhaseType,
    PxFrictionType as FrictionType,
    PxHitFlag as HitFlag,
    PxHitFlags as HitFlags,
    PxPairFilteringMode as PairFilteringMode,
    PxPruningStructureType as PruningStructureType,
    PxSceneFlag as SceneFlag,
    PxSceneFlags as SceneFlags,
    PxSceneQueryUpdateMode as SceneQueryUpdateMode,
    PxSolverType as SolverType,
};

#[derive(Default, Copy, Clone, Debug)]
/// 0 means no limit.
pub struct SceneLimits {
    pub max_nb_actors: u32,
    pub max_nb_bodies: u32,
    pub max_nb_static_shapes: u32,
    pub max_nb_dynamic_shapes: u32,
    pub max_nb_aggregates: u32,
    pub max_nb_constraints: u32,
    pub max_nb_regions: u32,
    pub max_nb_broad_phase_overlaps: u32,
}

impl From<SceneLimits> for PxSceneLimits {
    fn from(value: SceneLimits) -> Self {
        Self {
            maxNbActors: value.max_nb_actors,
            maxNbBodies: value.max_nb_bodies,
            maxNbStaticShapes: value.max_nb_static_shapes,
            maxNbDynamicShapes: value.max_nb_dynamic_shapes,
            maxNbAggregates: value.max_nb_aggregates,
            maxNbConstraints: value.max_nb_constraints,
            maxNbRegions: value.max_nb_regions,
            maxNbBroadPhaseOverlaps: value.max_nb_broad_phase_overlaps,
        }
    }
}

pub enum SimulationThreadType {
    Dedicated(u32),
    Shared(*mut PxCpuDispatcher),
    Default,
}

pub enum FilterShaderDescriptor {
    Default,
    Custom(physx_sys::SimulationFilterShader),
    CallDefaultFirst(physx_sys::SimulationFilterShader),
}

impl Default for FilterShaderDescriptor {
    fn default() -> Self {
        FilterShaderDescriptor::Default
    }
}

/// A new type wrapper for PxScene.  Parametrized by its user data type,
/// the ArticulationLink, RigidStatic, and RigidDynamic actors, Articulation, and
/// ArticulationReducedCoordinate articulations, and Collision, Trigger, ConstraintBreak,
/// WakeSleep and Advance Callbacks.  Due to the number of generic type parameters,
/// creating a type alias is recommended.
#[repr(transparent)]
#[allow(clippy::type_complexity)]
pub struct PxScene<U, L, S, D, C, OC, OT, OCB, OWS, OA>
where
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,
    C: ArticulationReducedCoordinate,
    OC: CollisionCallback,
    OT: TriggerCallback,
    OCB: ConstraintBreakCallback,
    OWS: WakeSleepCallback<L, S, D>,
    OA: AdvanceCallback<L, D>,
{
    pub(crate) obj: physx_sys::PxScene,
    phantom_user_data: PhantomData<(U, L, S, D, C, OC, OT, OCB, OWS, OA)>,
}

unsafe impl<U, L, S, D, C, OC, OT, OCB, OWS, OA> UserData
    for PxScene<U, L, S, D, C, OC, OT, OCB, OWS, OA>
where
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,
    C: ArticulationReducedCoordinate,
    OC: CollisionCallback,
    OT: TriggerCallback,
    OCB: ConstraintBreakCallback,
    OWS: WakeSleepCallback<L, S, D>,
    OA: AdvanceCallback<L, D>,
{
    type UserData = U;

    fn user_data_ptr(&self) -> &*mut std::ffi::c_void {
        &self.obj.userData
    }

    fn user_data_ptr_mut(&mut self) -> &mut *mut std::ffi::c_void {
        &mut self.obj.userData
    }
}

impl<U, L, S, D, C, OC, OT, OCB, OWS, OA> Drop for PxScene<U, L, S, D, C, OC, OT, OCB, OWS, OA>
where
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,
    C: ArticulationReducedCoordinate,
    OC: CollisionCallback,
    OT: TriggerCallback,
    OCB: ConstraintBreakCallback,
    OWS: WakeSleepCallback<L, S, D>,
    OA: AdvanceCallback<L, D>,
{
    fn drop(&mut self) {
        unsafe {
            for ptr in self.get_aggregates() {
                drop_in_place(ptr as *mut _)
            }
            for ptr in self.get_constraints() {
                drop_in_place(ptr as *mut _)
            }
            for ptr in self.get_articulations() {
                drop_in_place(ptr as *mut _);
            }
            for ptr in self.get_actors(ActorTypeFlags::RigidDynamic | ActorTypeFlags::RigidStatic) {
                ptr.cast_map(
                    |ptr| drop_in_place(ptr as *mut _),
                    |ptr| drop_in_place(ptr as *mut _),
                    |_| (), // ArticulationLinks are dropped when the articulation they are in is dropped
                )
            }
            drop_in_place(self.get_user_data_mut() as *mut _);
            drop_in_place(PxScene_getSimulationEventCallback(self.as_ptr())
                as *mut PxSimulationEventCallback<L, S, D, OC, OT, OCB, OWS, OA>);
            PxScene_release_mut(self.as_mut_ptr());
        }
    }
}

unsafe impl<P, U, L, S, D, C, OC, OT, OCB, OWS, OA> Class<P>
    for PxScene<U, L, S, D, C, OC, OT, OCB, OWS, OA>
where
    physx_sys::PxScene: Class<P>,
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,
    C: ArticulationReducedCoordinate,
    OC: CollisionCallback,
    OT: TriggerCallback,
    OCB: ConstraintBreakCallback,
    OWS: WakeSleepCallback<L, S, D>,
    OA: AdvanceCallback<L, D>,
{
    fn as_ptr(&self) -> *const P {
        self.obj.as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut P {
        self.obj.as_mut_ptr()
    }
}

unsafe impl<U, L, S, D, C, OC, OT, OCB, OWS, OA> Send
    for PxScene<U, L, S, D, C, OC, OT, OCB, OWS, OA>
where
    L: ArticulationLink + Send,
    S: RigidStatic + Send,
    D: RigidDynamic + Send,
    C: ArticulationReducedCoordinate + Send,
    OC: CollisionCallback + Send,
    OT: TriggerCallback + Send,
    OCB: ConstraintBreakCallback + Send,
    OWS: WakeSleepCallback<L, S, D>,
    OA: AdvanceCallback<L, D>,
{
}

unsafe impl<U, L, S, D, C, OC, OT, OCB, OWS, OA> Sync
    for PxScene<U, L, S, D, C, OC, OT, OCB, OWS, OA>
where
    L: ArticulationLink + Sync,
    S: RigidStatic + Sync,
    D: RigidDynamic + Sync,
    C: ArticulationReducedCoordinate + Sync,
    OC: CollisionCallback + Sync,
    OT: TriggerCallback + Sync,
    OCB: ConstraintBreakCallback + Sync,
    OWS: WakeSleepCallback<L, S, D>,
    OA: AdvanceCallback<L, D>,
{
}

impl<U, L, S, D, C, OC, OT, OCB, OWS, OA> Scene for PxScene<U, L, S, D, C, OC, OT, OCB, OWS, OA>
where
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,
    C: ArticulationReducedCoordinate,
    OC: CollisionCallback,
    OT: TriggerCallback,
    OCB: ConstraintBreakCallback,
    OWS: WakeSleepCallback<L, S, D>,
    OA: AdvanceCallback<L, D>,
{
    type ArticulationLink = L;
    type RigidStatic = S;
    type RigidDynamic = D;
    type ArticulationReducedCoordinate = C;
    type ActorMap = ActorMap<L, S, D>;
    type Aggregate = PxAggregate<L, S, D, C>;
}

pub trait Scene: Class<physx_sys::PxScene> + UserData {
    type ArticulationLink: ArticulationLink;
    type RigidStatic: RigidStatic;
    type RigidDynamic: RigidDynamic;
    type ArticulationReducedCoordinate: ArticulationReducedCoordinate;
    type ActorMap: RigidActor;
    type Aggregate: Aggregate;

    /// # Safety
    /// Owner's own the pointer they wrap, using the pointer after dropping the Owner,
    /// or creating multiple Owners from the same pointer will cause UB.  Use `into_ptr` to
    /// retrieve the pointer and consume the Owner without dropping the pointee.
    unsafe fn from_raw(ptr: *mut physx_sys::PxScene) -> Option<Owner<Self>> {
        // userData is initialized by the descriptor.
        unsafe { Owner::from_raw(ptr as *mut Self) }
    }

    /// Get the user data.
    fn get_user_data(&self) -> &Self::UserData {
        // Safety: Scenes are constructed from SceneDescriptor which sets up user data appropriately
        unsafe { UserData::get_user_data(self) }
    }

    /// Get the user data.
    fn get_user_data_mut(&mut self) -> *mut Self::UserData {
        // Safety: Scenes are constructed from SceneDescriptor which sets up user data appropriately
        unsafe { UserData::get_user_data_mut(self) }
    }

    /// Get the visual debugger client
    fn get_pvd_client(&mut self) -> Option<&mut PvdSceneClient> {
        unsafe {
            (PxScene_getScenePvdClient_mut(self.as_mut_ptr()) as *mut PvdSceneClient).as_mut()
        }
    }

    /// Create a controller manager.
    fn create_controller_manager<C: Controller>(
        &mut self,
        locking_enabled: bool,
    ) -> Option<Owner<PxControllerManager<C>>> {
        unsafe {
            ControllerManager::from_raw(phys_PxCreateControllerManager(
                self.as_mut_ptr(),
                locking_enabled,
            ))
        }
    }

    ///////////////////////////////////////////////////////////////////////////////
    // Adding/removing objects

    /// Add a dynamic actor to the world.
    fn add_dynamic_actor(&mut self, actor: Owner<Self::RigidDynamic>) {
        unsafe {
            PxScene_addActor_mut(self.as_mut_ptr(), actor.into_ptr(), null());
        }
    }

    /// Add dynamic actors to the world.
    fn add_dynamic_actors(&mut self, mut actors: Vec<Owner<Self::RigidDynamic>>) {
        unsafe {
            PxScene_addActors_mut(
                self.as_mut_ptr(),
                actors.as_ptr() as *const *mut _,
                actors.len() as u32,
            );
            // set len to zero instead of calling forget so the Vec itself is cleaned up,
            // but the actors in the vec are not.
            actors.set_len(0);
        }
    }

    /// Add a static actor to the world.
    fn add_static_actor(&mut self, actor: Owner<Self::RigidStatic>) {
        unsafe {
            PxScene_addActor_mut(self.as_mut_ptr(), actor.into_ptr(), null());
        }
    }

    /// Add dynamic actors to the world.
    fn add_static_actors(&mut self, mut actors: Vec<Owner<Self::RigidStatic>>) {
        unsafe {
            PxScene_addActors_mut(
                self.as_mut_ptr(),
                actors.as_ptr() as *const *mut _,
                actors.len() as u32,
            );
            // set len to zero instead of calling forget so the Vec itself is cleaned up,
            // but the actors in the vec are not.
            actors.set_len(0);
        }
    }

    /// Add an articulation link to the world.
    fn add_articulation_link(&mut self, actor: Owner<Self::ArticulationLink>) {
        unsafe {
            PxScene_addActor_mut(self.as_mut_ptr(), actor.into_ptr(), null());
        }
    }

    /// Add articulation links to the world.
    fn add_articulation_links(&mut self, mut actors: Vec<Owner<Self::ArticulationLink>>) {
        unsafe {
            PxScene_addActors_mut(
                self.as_mut_ptr(),
                actors.as_ptr() as *const *mut _,
                actors.len() as u32,
            );
            // set len to zero instead of calling forget so the Vec itself is cleaned up,
            // but the actors in the vec are not.
            actors.set_len(0);
        }
    }

    /// Remove an actor from the scene.
    fn remove_actor(&mut self, actor: &mut impl Actor, wake_touching: bool) {
        unsafe {
            PxScene_removeActor_mut(self.as_mut_ptr(), actor.as_mut_ptr(), wake_touching);
        }
    }

    /// Remove actors from the scene.
    fn remove_actors(&mut self, mut actors: Vec<&mut impl Actor>, wake_touching: bool) {
        unsafe {
            PxScene_removeActors_mut(
                self.as_mut_ptr(),
                actors.as_mut_ptr() as *const *mut _,
                actors.len() as u32,
                wake_touching,
            );
        }
    }

    /// Add an articulation to the scene.
    fn add_articulation(&mut self, articulation: Owner<Self::ArticulationReducedCoordinate>) {
        unsafe {
            PxScene_addArticulation_mut(self.as_mut_ptr(), articulation.into_ptr());
        };
    }

    /// Remove an articulation from the scene.
    fn remove_articulation(
        &mut self,
        articulation: &mut Self::ArticulationReducedCoordinate,
        wake_touching: bool,
    ) {
        unsafe {
            PxScene_removeArticulation_mut(
                self.as_mut_ptr(),
                articulation.as_mut_ptr(),
                wake_touching,
            );
        }
    }

    /// Add an aggregate to the scene.
    fn add_aggregate(&mut self, aggregate: Owner<Self::Aggregate>) {
        unsafe {
            PxScene_addAggregate_mut(self.as_mut_ptr(), aggregate.into_ptr());
        }
    }

    /// Remove an aggregate from the scene.
    fn remove_aggregate(&mut self, aggregate: &mut Self::Aggregate, wake_touching: bool) {
        unsafe {
            PxScene_removeAggregate_mut(self.as_mut_ptr(), aggregate.as_mut_ptr(), wake_touching);
        }
    }

    /// Add a rpuning structure to the scene.
    fn add_pruning_structure(&mut self, pruning_structure: Owner<PruningStructure>) {
        unsafe {
            PxScene_addActors_mut_1(self.as_mut_ptr(), pruning_structure.into_ptr());
        }
    }

    ////////////////////////////////////////////////////////////////////////////////
    // Simulation

    /// Run a simulation update step.
    fn simulate(
        &mut self,
        time_step: f32,
        completion_task: Option<&mut PxBaseTask>,
        scratch: Option<&mut ScratchBuffer>,
    ) {
        let completion_task = completion_task.map_or(null_mut(), |t| t as *mut _);

        let (scratch_ptr, scratch_size) = if let Some(scratch) = scratch {
            scratch.as_ptr_and_size()
        } else {
            (null_mut(), 0)
        };

        unsafe {
            PxScene_simulate_mut(
                self.as_mut_ptr(),
                time_step,
                completion_task,
                scratch_ptr,
                scratch_size,
                true,
            );
        }
    }

    /// Check if or wait until `simulate` has completed.  Returns Ok(()) when it has, Err otherwise.
    fn fetch_results(&mut self, block: bool) -> Result<(), u32> {
        unsafe {
            let mut error: u32 = 0;
            let fetched = PxScene_fetchResults_mut(self.as_mut_ptr(), block, &mut error);
            if fetched && error == 0 {
                Ok(())
            } else {
                Err(error)
            }
        }
    }

    /// Combines `simulate` and `fetch_results` into one call.
    fn step(
        &mut self,
        time_step: f32,
        completion_task: Option<&mut PxBaseTask>,
        scratch: Option<&mut ScratchBuffer>,
        block: bool,
    ) -> Result<(), u32> {
        self.simulate(time_step, completion_task, scratch);
        self.fetch_results(block)
    }

    ////////////////////////////////////////////////////////////////////////////////
    // Bulk Getters

    /// Get a Vec of the articulations in the scene.
    fn get_articulations(&mut self) -> Vec<&mut Self::ArticulationReducedCoordinate> {
        unsafe {
            let capacity = PxScene_getNbArticulations(self.as_ptr());
            let mut buffer: Vec<&mut Self::ArticulationReducedCoordinate> =
                Vec::with_capacity(capacity as usize);
            let len = PxScene_getArticulations(
                self.as_ptr(),
                buffer.as_mut_ptr() as *mut *mut _,
                capacity,
                0,
            );
            buffer.set_len(len as usize);
            buffer
        }
    }

    /// Get the actors in the scene, filtered by ActorTypeFlags.
    fn get_actors(&mut self, actor_types: ActorTypeFlags) -> Vec<&mut Self::ActorMap> {
        unsafe {
            let capacity = PxScene_getNbActors(self.as_ptr(), actor_types);
            let mut buffer: Vec<&mut Self::ActorMap> = Vec::with_capacity(capacity as usize);
            let len = PxScene_getActors(
                self.as_ptr(),
                actor_types,
                buffer.as_mut_ptr() as *mut *mut _,
                capacity,
                0,
            );
            buffer.set_len(len as usize);
            buffer
        }
    }

    /// Get the active actor buffer of actors that were updated during the last `simulate` call.
    fn get_active_actors(&mut self) -> &mut [&mut Self::ActorMap] {
        // This cannot return a Vec.  Vec has specific allocation/alignment requirements
        // that the C++-allocated buffer does not meet, and dropping the fake vec causes a crash.
        unsafe {
            let mut length = 0;
            let actors = PxScene_getActiveActors_mut(self.as_mut_ptr(), &mut length);
            std::slice::from_raw_parts_mut(actors as *mut &mut Self::ActorMap, length as usize)
        }
    }

    /// Get the static actors in the scene.
    fn get_static_actors(&mut self) -> Vec<&mut Self::RigidStatic> {
        unsafe {
            let flags = ActorTypeFlags::RigidStatic;
            let capacity = PxScene_getNbActors(self.as_ptr(), flags);
            let mut buffer: Vec<&mut Self::RigidStatic> = Vec::with_capacity(capacity as usize);
            let len = PxScene_getActors(
                self.as_ptr(),
                flags,
                buffer.as_mut_ptr() as *mut *mut _,
                capacity,
                0,
            );
            buffer.set_len(len as usize);
            buffer
        }
    }

    /// Get the dynamic actors in the scene.
    fn get_dynamic_actors(&mut self) -> Vec<&mut Self::RigidDynamic> {
        unsafe {
            let flags = ActorTypeFlags::RigidDynamic;
            let capacity = PxScene_getNbActors(self.as_ptr(), flags);
            let mut buffer: Vec<&mut Self::RigidDynamic> = Vec::with_capacity(capacity as usize);
            let len = PxScene_getActors(
                self.as_ptr(),
                flags,
                buffer.as_mut_ptr() as *mut *mut _,
                capacity,
                0,
            );
            buffer.set_len(len as usize);
            buffer
        }
    }

    /// Get the aggregates in the scene.
    fn get_aggregates(&mut self) -> Vec<&mut Self::Aggregate> {
        unsafe {
            let capacity = PxScene_getNbAggregates(self.as_ptr());
            let mut buffer: Vec<&mut Self::Aggregate> = Vec::with_capacity(capacity as usize);
            let len = PxScene_getAggregates(
                self.as_ptr(),
                buffer.as_mut_ptr() as *mut *mut physx_sys::PxAggregate,
                capacity,
                0,
            );
            buffer.set_len(len as usize);
            buffer
        }
    }

    /// Get all the constraints currently in this scene.
    fn get_constraints(&mut self) -> Vec<&mut Constraint> {
        unsafe {
            let capacity = PxScene_getNbConstraints(self.as_ptr());
            let mut buffer: Vec<&mut Constraint> = Vec::with_capacity(capacity as usize);
            let len = PxScene_getConstraints(
                self.as_ptr(),
                buffer.as_mut_ptr() as *mut *mut physx_sys::PxConstraint,
                capacity,
                0,
            );
            buffer.set_len(len as usize);
            buffer
        }
    }

    //////////////////////////////////////////////////////////////////////////
    // Callbacks

    /// # Safety
    /// PxContactModifyCallback does not have a safe wrapper, using it requires use of [`physx_sys`].
    unsafe fn set_contact_modify_callback(&mut self, callback: &mut PxContactModifyCallback) {
        unsafe {
            PxScene_setContactModifyCallback_mut(self.as_mut_ptr(), callback);
        }
    }

    /// # Safety
    /// PxContactModifyCallback does not have a safe wrapper, using it requires use of [`physx_sys`].
    unsafe fn get_contact_modify_callback(&self) -> &PxContactModifyCallback {
        unsafe { &*PxScene_getContactModifyCallback(self.as_ptr()) }
    }

    /// # Safety
    /// PxCCDContactModifyCallback does not have a safe wrapper, using it requires use of [`physx_sys`].
    unsafe fn set_ccd_contact_modify_callback(
        &mut self,
        callback: &mut PxCCDContactModifyCallback,
    ) {
        unsafe {
            PxScene_setCCDContactModifyCallback_mut(self.as_mut_ptr(), callback);
        }
    }

    /// # Safety
    /// PxCCDContactModifyCallback does not have a safe wrapper, using it requires use of [`physx_sys`].
    unsafe fn get_ccd_contact_callback(&self) -> &PxCCDContactModifyCallback {
        unsafe { &*PxScene_getCCDContactModifyCallback(self.as_ptr()) }
    }

    /// # Safety
    /// PxBroadPhaseCallback does not have a safe wrapper, using it requires use of [`physx_sys`].
    unsafe fn set_broad_phase_callback(&mut self, callback: &mut PxBroadPhaseCallback) {
        unsafe {
            PxScene_setBroadPhaseCallback_mut(self.as_mut_ptr(), callback);
        }
    }

    /// # Safety
    /// PxBroadPhaseCallback does not have a safe wrapper, using it requires use of [`physx_sys`].
    unsafe fn get_broad_phase_callback(&self) -> &PxBroadPhaseCallback {
        unsafe { &*PxScene_getBroadPhaseCallback(self.as_ptr()) }
    }

    //////////////////////////////////////////////////////////////////////////
    // Collision Filtering

    /// Reset the collision filtering for an actor.
    fn reset_filtering(&mut self, actor: &mut impl Actor) -> bool {
        unsafe { PxScene_resetFiltering_mut(self.as_mut_ptr(), actor.as_mut_ptr()) }
    }

    /// Reset collision filtering for a RigidActor and shapes.
    fn reset_rigid_actor_filtering<R: RigidActor>(
        &mut self,
        actor: &mut R,
        shapes: &[&mut R::Shape],
    ) {
        unsafe {
            PxScene_resetFiltering_mut_1(
                self.as_mut_ptr(),
                actor.as_mut_ptr(),
                shapes.as_ptr() as *const *mut physx_sys::PxShape,
                shapes.len() as u32,
            );
        }
    }

    /// Get the kinematic-kinematic filtering mode.
    fn get_kinematic_kinematic_filtering_mode(&self) -> PairFilteringMode {
        unsafe { PxScene_getKinematicKinematicFilteringMode(self.as_ptr()) }
    }

    /// Get the static-kinematic filtering mode.
    fn get_static_kinematic_filtering_mode(&self) -> PairFilteringMode {
        unsafe { PxScene_getStaticKinematicFilteringMode(self.as_ptr()) }
    }

    //////////////////////////////////////////////////////////////////////////
    // Other simulation settings

    /// Sets the gravity vector.
    fn set_gravity(&mut self, x: f32, y: f32, z: f32) {
        unsafe {
            PxScene_setGravity_mut(self.as_mut_ptr(), &PxVec3::new(x, y, z).into());
        }
    }
}
