// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 10 April 2019

#![warn(clippy::all)]
#![allow(clippy::missing_safety_doc)]
#![allow(deprecated)]

/*!
Wrapper for PhysX PxScene
 */

use crate::{
    actor::{Actor, ActorMap},
    aggregate::{Aggregate, PxAggregate},
    articulation::Articulation,
    articulation_base::{ArticulationBase, ArticulationMap},
    articulation_link::ArticulationLink,
    articulation_reduced_coordinate::ArticulationReducedCoordinate,
    constraint::Constraint,
    controller_manager::ControllerManager,
    foundation::ScratchBuffer,
    math::PxVec3,
    owner::Owner,
    physics::Physics,
    pruning_structure::PruningStructure,
    rigid_actor::RigidActor,
    rigid_dynamic::RigidDynamic,
    rigid_static::RigidStatic,
    simulation_event_callback::{
        AdvanceCallback, CollisionCallback, ConstraintBreakCallback, PxSimulationEventCallback,
        TriggerCallback, WakeSleepCallback,
    },
    traits::{Class, PxFlags, UserData},
    visual_debugger::PvdSceneClient,
};

use enumflags2::BitFlags;
use std::{
    ffi::c_void,
    marker::PhantomData,
    ptr::{drop_in_place, null, null_mut},
};

// TODO write proper wrappers for these rather than re-export
pub use physx_sys::PxRaycastCallback;

// A glob import is super tempting, but the wrappers shadow the names of the physx_sys types,
// so those types cannot be in scope.  Plus, it easier to see what's been implemented.
use physx_sys::{
    get_default_simulation_filter_shader,
    phys_PxCreateControllerManager,
    phys_PxDefaultCpuDispatcherCreate,
    PxActorTypeFlags,
    PxBaseTask,
    PxBroadPhaseCallback,
    PxBroadPhaseType,
    PxCCDContactModifyCallback,
    /*
    PxOverlapCallback,
    PxSweepCallback,
    PxQueryFilterData,
    PxQueryFilterData_new,
    PxQueryFilterCallback,
    PxQueryCache,
    */
    PxContactModifyCallback,
    PxCpuDispatcher,
    PxPairFilteringMode,
    PxPruningStructureType,
    PxSceneDesc_new,
    //PxHitFlags,
    //PxSceneFlags,
    PxScene_addActor_mut,
    PxScene_addActors_mut,
    PxScene_addActors_mut_1,
    PxScene_addAggregate_mut,
    PxScene_addArticulation_mut,
    PxScene_fetchResults_mut,
    /*
    PxScene_advance_mut,
    PxScene_collide_mut,
    PxScene_checkQueries_mut,
    PxScene_checkResults_mut,
    PxScene_createBatchQuery_mut,
    PxScene_createClient_mut,
    PxScene_fetchCollision_mut,
    PxScene_fetchResultsStart_mut,
    PxScene_fetchResultsFinish_mut,
    PxScene_flushSimulation_mut,
    PxScene_fetchQueries_mut,
    */
    PxScene_flushQueryUpdates_mut,
    // PxScene_overlap,
    // PxScene_raycast,
    // PxScene_sweep,
    PxScene_getActiveActors_mut,
    PxScene_getActors,
    PxScene_getAggregates,
    PxScene_getArticulations,
    PxScene_getBroadPhaseCallback,
    PxScene_getCCDContactModifyCallback,
    PxScene_getConstraints,
    PxScene_getContactModifyCallback,
    PxScene_getDynamicStructure,
    PxScene_getFilterCallback,
    //PxScene_getFilterShader,
    PxScene_getFilterShaderData,
    PxScene_getFilterShaderDataSize,
    PxScene_getKinematicKinematicFilteringMode,
    PxScene_getNbActors,
    PxScene_getNbAggregates,
    PxScene_getNbArticulations,
    PxScene_getNbConstraints,
    PxScene_getScenePvdClient_mut,
    PxScene_getSimulationEventCallback,
    PxScene_getStaticKinematicFilteringMode,
    PxScene_getStaticStructure,
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
    PxScene_setFilterShaderData_mut,
    //PxScene_setSimulationEventCallback_mut,
    /*
    PxScene_addBroadPhaseRegion_mut,
    PxScene_addCollection_mut,
    PxScene_forceDynamicTreeRebuild_mut,
    PxScene_getBounceThresholdVelocity,
    PxScene_getBroadPhaseCaps,
    PxScene_getBroadPhaseRegions,
    PxScene_getBroadPhaseType,
    PxScene_getCCDMaxPasses,
    PxScene_getContactReportStreamBufferSize,
    PxScene_getCpuDispatcher,
    PxScene_getCudaContextManager,
    PxScene_getDominanceGroupPair,
    PxScene_getDynamicTreeRebuildRateHint,
    PxScene_getFlags,
    PxScene_getFrictionOffsetThreshold,
    PxScene_getFrictionType,
    PxScene_getGravity,
    PxScene_getLimits,
    PxScene_getMaxNbContactDataBlocksUsed,
    PxScene_getNbBroadPhaseRegions,
    PxScene_getNbContactDataBlocksUsed,
    PxScene_getRenderBuffer_mut,
    PxScene_getSceneQueryStaticTimestamp,
    PxScene_getSceneQueryUpdateMode,
    PxScene_getSimulationStatistics,
    PxScene_getSolverArticulationBatchSize,
    PxScene_getSolverBatchSize,
    PxScene_getTaskManager,
    PxScene_getTimestamp,
    PxScene_getVisualizationCullingBox,
    PxScene_getVisualizationParameter,
    PxScene_getWakeCounterResetValue,
    PxScene_processCallbacks_mut,
    PxScene_removeBroadPhaseRegion_mut,
    PxScene_sceneQueriesUpdate_mut,
    PxScene_setBounceThresholdVelocity_mut,
    PxScene_setCCDMaxPasses_mut,
    PxScene_setDominanceGroupPair_mut,
    PxScene_setDynamicTreeRebuildRateHint_mut,
    PxScene_setFlag_mut,
    PxScene_setFrictionType_mut,
    PxScene_setGravity_mut,
    PxScene_setLimits_mut,
    PxScene_setNbContactDataBlocks_mut,
    PxScene_setSceneQueryUpdateMode_mut,
    PxScene_setSolverArticulationBatchSize_mut,
    PxScene_setSolverBatchSize_mut,
    PxScene_setVisualizationCullingBox_mut,
    PxScene_setVisualizationParameter_mut,
    PxScene_shiftOrigin_mut,
    */
    // PxScene_getPhysics_mut,
    // PxScene_lockRead_mut,
    // PxScene_unlockRead_mut,
    // PxScene_lockWrite_mut,
    // PxScene_unlockWrite_mut,
    PxScene_simulate_mut,
    PxSimulationFilterCallback,
    PxSolverType,
};

pub type ActorTypeFlags = BitFlags<ActorTypeFlag>;

impl PxFlags for ActorTypeFlags {
    type Target = PxActorTypeFlags;

    fn into_px(self) -> Self::Target {
        PxActorTypeFlags { mBits: self.bits() }
    }

    fn from_px(flags: Self::Target) -> Self {
        unsafe { BitFlags::new(flags.mBits) }
    }
}

#[derive(BitFlags, Copy, Clone, Debug)]
#[repr(u16)]
pub enum ActorTypeFlag {
    RigidStatic = 1,
    RigidDynamic = 1 << 1,
}

/// A new type wrapper for PxScene.  Parametrized by it's user data type,
/// the ArticulationLink, RigidStatic, and RigidDynamic actors, Articulation, and
/// ArticulationReducedCoordinate articulations, and Collision, Trigger, ConstraintBreak,
/// WakeSleep and Advance Callbacks.  Due to the number of generic type parameters,
/// creating a type alias is recommended.
#[repr(transparent)]
pub struct PxScene<U, L, S, D, T, C, OC, OT, OCB, OWS, OA>
where
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,
    T: Articulation,
    C: ArticulationReducedCoordinate,
    OC: CollisionCallback,
    OT: TriggerCallback,
    OCB: ConstraintBreakCallback,
    OWS: WakeSleepCallback<L, S, D>,
    OA: AdvanceCallback<L, D>,
{
    pub(crate) obj: physx_sys::PxScene,
    phantom_user_data: PhantomData<(U, L, S, D, T, C, OC, OT, OCB, OWS, OA)>,
}

unsafe impl<U, L, S, D, T, C, OC, OT, OCB, OWS, OA> UserData
    for PxScene<U, L, S, D, T, C, OC, OT, OCB, OWS, OA>
where
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,
    T: Articulation,
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

impl<U, L, S, D, T, C, OC, OT, OCB, OWS, OA> Drop
    for PxScene<U, L, S, D, T, C, OC, OT, OCB, OWS, OA>
where
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,
    T: Articulation,
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
                ptr.cast_map(
                    |ptr| drop_in_place(ptr as *mut _),
                    |ptr| drop_in_place(ptr as *mut _),
                )
            }
            for ptr in self.get_actors(ActorTypeFlag::RigidDynamic | ActorTypeFlag::RigidStatic)
            {
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

unsafe impl<P, U, L, S, D, T, C, OC, OT, OCB, OWS, OA> Class<P>
    for PxScene<U, L, S, D, T, C, OC, OT, OCB, OWS, OA>
where
    physx_sys::PxScene: Class<P>,
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,
    T: Articulation,
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

unsafe impl<U, L, S, D, T, C, OC, OT, OCB, OWS, OA> Send
    for PxScene<U, L, S, D, T, C, OC, OT, OCB, OWS, OA>
where
    L: ArticulationLink + Send,
    S: RigidStatic + Send,
    D: RigidDynamic + Send,
    T: Articulation + Send,
    C: ArticulationReducedCoordinate + Send,
    OC: CollisionCallback + Send,
    OT: TriggerCallback + Send,
    OCB: ConstraintBreakCallback + Send,
    OWS: WakeSleepCallback<L, S, D>,
    OA: AdvanceCallback<L, D>,
{
}
unsafe impl<U, L, S, D, T, C, OC, OT, OCB, OWS, OA> Sync
    for PxScene<U, L, S, D, T, C, OC, OT, OCB, OWS, OA>
where
    L: ArticulationLink + Sync,
    S: RigidStatic + Sync,
    D: RigidDynamic + Sync,
    T: Articulation + Sync,
    C: ArticulationReducedCoordinate + Sync,
    OC: CollisionCallback + Sync,
    OT: TriggerCallback + Sync,
    OCB: ConstraintBreakCallback + Sync,
    OWS: WakeSleepCallback<L, S, D>,
    OA: AdvanceCallback<L, D>,
{
}

impl<U, L, S, D, T, C, OC, OT, OCB, OWS, OA> Scene
    for PxScene<U, L, S, D, T, C, OC, OT, OCB, OWS, OA>
where
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,
    T: Articulation,
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

    type Articulation = T;

    type ArticulationReducedCoordinate = C;

    type ActorMap = ActorMap<L, S, D>;

    type ArticulationMap = ArticulationMap<T, C>;

    type Aggregate = PxAggregate<L, S, D, T, C>;
}

pub trait Scene: Class<physx_sys::PxScene> + UserData {
    type ArticulationLink: ArticulationLink;
    type RigidStatic: RigidStatic;
    type RigidDynamic: RigidDynamic;
    type Articulation: Articulation;
    type ArticulationReducedCoordinate: ArticulationReducedCoordinate;

    type ActorMap: RigidActor;
    type ArticulationMap: ArticulationBase;
    type Aggregate: Aggregate;

    /// Safety: Owners will free the wrapped pointer on drop, use of it after this point is UB.
    unsafe fn from_raw(ptr: *mut physx_sys::PxScene) -> Option<Owner<Self>> {
        // userData is initialized by the descriptor.
        Owner::from_raw(ptr as *mut Self)
    }

    fn get_user_data(&self) -> &Self::UserData {
        // Safety: Scenes are constructed from SceneDescriptor which sets up user data appropriately
        unsafe { UserData::get_user_data(self) }
    }

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

    fn create_controller_manager(
        &mut self,
        locking_enabled: bool,
    ) -> Option<Owner<ControllerManager>> {
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

    unsafe fn remove_actor(&mut self, actor: &mut impl Actor, wake_touching: bool) {
        //unsafe
        {
            PxScene_removeActor_mut(self.as_mut_ptr(), actor.as_mut_ptr(), wake_touching);
        }
    }

    unsafe fn remove_actors(&mut self, mut actors: Vec<&mut impl Actor>, wake_touching: bool) {
        PxScene_removeActors_mut(
            self.as_mut_ptr(),
            actors.as_mut_ptr() as *const *mut _,
            actors.len() as u32,
            wake_touching,
        );
    }

    /// Add an articulation to the world.
    fn add_articulation(&mut self, articulation: Owner<impl ArticulationBase>) {
        unsafe {
            PxScene_addArticulation_mut(self.as_mut_ptr(), articulation.into_ptr());
        };
    }

    /// Remove an articulation from the world
    fn remove_articulation(
        &mut self,
        articulation: &mut impl ArticulationBase,
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

    fn add_aggregate(&mut self, aggregate: Owner<Self::Aggregate>) {
        unsafe {
            PxScene_addAggregate_mut(self.as_mut_ptr(), aggregate.into_ptr());
        }
    }

    fn remove_aggregate(&mut self, aggregate: &mut Self::Aggregate, wake_touching: bool) {
        unsafe {
            PxScene_removeAggregate_mut(self.as_mut_ptr(), aggregate.as_mut_ptr(), wake_touching);
        }
    }

    /* TODO implement Collection and the rest of the serialization pipeline
        fn add_collection(&mut self, collection: &PxCollection) {
            unsafe {
                PxScene_addCollection_mut(
                    self.as_mut_ptr(),
                    collection
                );
            }
        }
    */

    fn add_pruning_structure(&mut self, pruning_structure: Owner<PruningStructure>) {
        unsafe {
            PxScene_addActors_mut_1(self.as_mut_ptr(), pruning_structure.into_ptr());
        }
    }

    ////////////////////////////////////////////////////////////////////////////////
    // Simulation
    // TODO write a proper type for the scratch buffer.
    fn simulate(
        &mut self,
        time_step: f32,
        completion_task: Option<&mut PxBaseTask>,
        scratch: Option<&mut ScratchBuffer>,
    ) {
        let completion_task = completion_task.map(|t| t as *mut _).unwrap_or(null_mut());

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

    // TODO implement the rest of the simulation methods.

    ////////////////////////////////////////////////////////////////////////////////
    // Queries

    unsafe fn get_static_structure(&self) -> PruningStructureType {
        PxScene_getStaticStructure(self.as_ptr()).into()
    }

    unsafe fn get_dynamic_structure(&self) -> PruningStructureType {
        PxScene_getDynamicStructure(self.as_ptr()).into()
    }

    unsafe fn flush_query_updates(&mut self) {
        PxScene_flushQueryUpdates_mut(self.as_mut_ptr());
    }

    // TODO make the queries more idiomatic:
    //  - Return an Option<HitResult> type thing
    //  - callbacks should probably be stored in the scene or someething, not passed in?
    //  - verify mutability/lifetimes
    // TODO: PxSweepCallback, PxRaycastCallback and PxOverlapCallback are not instantiable.
    // Passing them is an MaybeUninit seems to cause a memory access violation.
    // Without those types, queries are not usable.
    /*
    unsafe fn raycast(
        &self,
        origin: &PxVec3,
        direction: &PxVec3,
        distance: f32,
        hit_flags: BitFlags<HitFlag>,
    ) -> Option<PxRaycastCallback> {
        if PxScene_raycast(
            self.as_ptr(),
            origin.as_ptr(),
            direction.as_ptr(),
            distance,
            hit.as_mut_ptr(), // :/
            PxHitFlags{mBits: hit_flags.bits()},
            filter_data,
            filter_callback,
            null()
        ) {
            Some(hit.assume_init())
        } else {
            None
        }
    }

    unsafe fn sweep(
        &self,
        geometry: &impl Geometry,
        pose: &PxTransform,
        direction: &PxVec3,
        distance: f32,
        hit_callback: &mut PxSweepCallback,
        hit_flags: BitFlags<HitFlag>,
        filter_data: &PxQueryFilterData,
        filter_callback: Option<&mut PxQueryFilterCallback>,
        cache: Option<&PxQueryCache>,
        inflation: f32,
    ) -> bool {
        PxScene_sweep(
            self.as_ptr(),
            geometry.as_ptr(),
            pose.as_ptr(),
            direction.as_ptr(),
            distance,
            hit_callback,
            PxHitFlags{mBits: hit_flags.bits()},
            filter_data,
            filter_callback.map(
                |callback|
                callback as *mut _
            ).unwrap_or(null_mut()),
            cache.map(
                |cache|
                cache as *const _
            ).unwrap_or(null()),
            inflation
        )
    }

    unsafe fn overlap(
        &self,
        geometry: &impl Geometry,
        pose: &PxTransform,
        hit_callback: &mut PxOverlapCallback,
        filter_data: &PxQueryFilterData,
        filter_callback: Option<&mut PxQueryFilterCallback>,
    ) -> bool {
        PxScene_overlap(
            self.as_ptr(),
            geometry.as_ptr(),
            pose.as_ptr(),
            hit_callback,
            filter_data,
            filter_callback.map(
                |callback|
                callback as *mut _
            ).unwrap_or(null_mut())
        )
    }
    */

    /* TODO implement!
    unsafe fn set_dynamic_tree_rebuild_rate_hint(&mut self, rate_hint: u32) {}

    unsafe fn get_dynamic_tree_rebuild_rate_hint(&self) -> u32 {}

    unsafe fn force_dynamic_tree_rebuild(&mut self, rebuild_static: bool, rebuild_dynamic: bool) {}

    unsafe fn set_scene_query_update_mode(&mut self, query_mode: SceneQueryMode) {}

    unsafe fn get_scene_query_update_mode(&self) -> SceneQueryMode {}

    unsafe fn scene_queries_update(&mut self, completion_task: Option<fn()>, control_simulation: bool) {}

    unsafe fn check_queries(&self, blocking: bool) -> bool {}

    unsafe fn fetch_queries(&mut self, blocking: bool) -> bool {}

    unsafe fn get_scene_query_static_timestampt(&self) -> u32 {}
    */

    ////////////////////////////////////////////////////////////////////////////////
    // Bulk Getters

    /// Get a Vec of the articulations in the scene.  This is intended for use when getting data out of
    /// PhysX after running a simulation step along with [get_actors], [get_active_actors], and [get_aggregates].
    fn get_articulations(&mut self) -> Vec<&mut Self::ArticulationMap> {
        unsafe {
            let capacity = PxScene_getNbArticulations(self.as_ptr());
            let mut buffer: Vec<&mut Self::ArticulationMap> = Vec::with_capacity(capacity as usize);
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

    fn get_actors(&mut self, actor_type: ActorTypeFlags) -> Vec<&mut Self::ActorMap> {
        unsafe {
            let flags = actor_type.into_px();
            let capacity = PxScene_getNbActors(self.as_ptr(), flags);
            let mut buffer: Vec<&mut Self::ActorMap> = Vec::with_capacity(capacity as usize);
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

    // This cannot return a Vec.  Vec has specific allocation/alignment requirements
    // that the C++-allocated buffer does not meet, and dropping the fake vec causes a crash.
    fn get_active_actors(&mut self) -> &mut [&mut Self::ActorMap] {
        unsafe {
            let mut length = 0;
            let actors = PxScene_getActiveActors_mut(self.as_mut_ptr(), &mut length);
            std::slice::from_raw_parts_mut(actors as *mut &mut Self::ActorMap, length as usize)
        }
    }

    fn get_static_actors(&mut self) -> Vec<&mut Self::RigidStatic> {
        unsafe {
            let flags = PxActorTypeFlags {
                mBits: ActorTypeFlag::RigidStatic as u16,
            };
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

    fn get_dynamic_actors(&mut self) -> Vec<&mut Self::RigidDynamic> {
        unsafe {
            let flags = PxActorTypeFlags {
                mBits: ActorTypeFlag::RigidDynamic as u16,
            };
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
    /*
        fn set_simulation_event_callback(&mut self, callback: Self::SimulationEventDescriptor) {
            unsafe {
                let callback = create_simulation_event_callbacks(&*callbacks);
                PxScene_setSimulationEventCallback_mut(self.as_mut_ptr(), &mut *callback);
            }
        }

        fn get_simulation_event_callbacks(&self) -> Option<&SimulationEventCallback> {
            unsafe {
                (PxScene_getSimulationEventCallback(self.as_ptr()) as *const SimulationEventCallback)
                    .as_ref()
            }
        }
    */
    unsafe fn set_contact_modify_callback(&mut self, callback: &mut PxContactModifyCallback) {
        PxScene_setContactModifyCallback_mut(self.as_mut_ptr(), callback);
    }

    unsafe fn get_contact_modify_callback(&self) -> &PxContactModifyCallback {
        &*PxScene_getContactModifyCallback(self.as_ptr())
    }

    unsafe fn set_ccd_contact_modify_callback(
        &mut self,
        callback: &mut PxCCDContactModifyCallback,
    ) {
        PxScene_setCCDContactModifyCallback_mut(self.as_mut_ptr(), callback);
    }

    unsafe fn get_ccd_contact_callback(&self) -> &PxCCDContactModifyCallback {
        &*PxScene_getCCDContactModifyCallback(self.as_ptr())
    }

    unsafe fn set_broad_phase_callback(&mut self, callback: &mut PxBroadPhaseCallback) {
        PxScene_setBroadPhaseCallback_mut(self.as_mut_ptr(), callback);
    }

    unsafe fn get_broad_phase_callback(&self) -> &PxBroadPhaseCallback {
        &*PxScene_getBroadPhaseCallback(self.as_ptr())
    }

    //////////////////////////////////////////////////////////////////////////
    // Collision Filtering

    // TODO add a generic type to PxScene for this so it's typesafe :)
    unsafe fn set_filter_shader_data(&mut self, data: &[u8]) {
        PxScene_setFilterShaderData_mut(
            self.as_mut_ptr(),
            data.as_ptr() as *const std::ffi::c_void,
            data.len() as u32,
        );
    }

    unsafe fn get_filter_shader_data(&self) -> &[u8] {
        std::slice::from_raw_parts(
            PxScene_getFilterShaderData(self.as_ptr()) as *const u8,
            PxScene_getFilterShaderDataSize(self.as_ptr()) as usize,
        )
    }

    /* TODO this returns a function pointer, which still needs to have a type defined that is inline with the C++
    // definition:
    typedef PxFilterFlags (*PxSimulationFilterShader)
    (PxFilterObjectAttributes attributes0, PxFilterData filterData0,
     PxFilterObjectAttributes attributes1, PxFilterData filterData1,
     PxPairFlags& pairFlags, const void* constantBlock, PxU32 constantBlockSize);

    unsafe fn get_filter_shader(&self) -> PxSimulationFilterShader {
        PxScene_getFilterShader(self.as_ptr())
    }
    */

    unsafe fn get_filter_callback(&self) -> &PxSimulationFilterCallback {
        &*PxScene_getFilterCallback(self.as_ptr())
    }

    unsafe fn reset_filtering(&mut self, actor: &mut impl Actor) {
        PxScene_resetFiltering_mut(self.as_mut_ptr(), actor.as_mut_ptr())
    }

    unsafe fn reset_rigid_actor_filtering<R: RigidActor>(
        &mut self,
        actor: &mut R,
        shapes: &[&mut R::Shape],
    ) {
        PxScene_resetFiltering_mut_1(
            self.as_mut_ptr(),
            actor.as_mut_ptr(),
            shapes.as_ptr() as *const *mut physx_sys::PxShape,
            shapes.len() as u32,
        );
    }

    unsafe fn get_kinematic_kinematic_filtering_mode(&self) -> PairFilteringMode {
        PxScene_getKinematicKinematicFilteringMode(self.as_ptr()).into()
    }

    unsafe fn get_static_kinematic_filtering_mode(&self) -> PairFilteringMode {
        PxScene_getStaticKinematicFilteringMode(self.as_ptr()).into()
    }
}

#[derive(Copy, Clone, Debug, BitFlags)]
#[repr(u16)]
pub enum HitFlag {
    Position = 1 << 0,
    Normal = 1 << 1,
    UV = 1 << 3,
    AssumeNoInitialOverlap = 1 << 4,
    MeshMultiple = 1 << 5,
    MeshAny = 1 << 6,
    MeshBothSides = 1 << 7,
    PreciseSweep = 1 << 8,
    MTD = 1 << 9,
    FaceIndex = 1 << 10,
}

impl HitFlag {
    pub fn default() -> BitFlags<HitFlag> {
        HitFlag::Position | HitFlag::Normal | HitFlag::FaceIndex
    }
}

#[derive(Copy, Clone, Debug)]
#[repr(u32)]
pub enum PruningStructureType {
    None = 0,
    DynamicAABBTree = 1,
    StaticAABBTree = 2,
}

impl Into<PxPruningStructureType::Enum> for PruningStructureType {
    fn into(self) -> PxPruningStructureType::Enum {
        match self {
            PruningStructureType::None => PxPruningStructureType::eNONE,
            PruningStructureType::DynamicAABBTree => PxPruningStructureType::eDYNAMIC_AABB_TREE,
            PruningStructureType::StaticAABBTree => PxPruningStructureType::eSTATIC_AABB_TREE,
        }
    }
}

impl From<PxPruningStructureType::Enum> for PruningStructureType {
    fn from(val: PxPruningStructureType::Enum) -> Self {
        debug_assert!(val < PxPruningStructureType::eLAST);
        match val {
            PxPruningStructureType::eNONE => PruningStructureType::None,
            PxPruningStructureType::eDYNAMIC_AABB_TREE => PruningStructureType::DynamicAABBTree,
            PxPruningStructureType::eSTATIC_AABB_TREE => PruningStructureType::StaticAABBTree,
            _ => unimplemented!("Invalid enum variant."),
        }
    }
}

#[derive(Debug, Copy, Clone)]
#[repr(u32)]
pub enum PairFilteringMode {
    Keep = 0,
    Suppress = 1,
    Kill = 2,
}

impl Default for PairFilteringMode {
    fn default() -> Self {
        PairFilteringMode::Suppress
    }
}

impl Into<PxPairFilteringMode::Enum> for PairFilteringMode {
    fn into(self) -> PxPairFilteringMode::Enum {
        match self {
            PairFilteringMode::Keep => PxPairFilteringMode::eKEEP,
            PairFilteringMode::Suppress => PxPairFilteringMode::eSUPPRESS,
            PairFilteringMode::Kill => PxPairFilteringMode::eKILL,
        }
    }
}

impl From<PxPairFilteringMode::Enum> for PairFilteringMode {
    fn from(mode: PxPairFilteringMode::Enum) -> Self {
        match mode {
            PxPairFilteringMode::eKEEP => PairFilteringMode::Keep,
            PxPairFilteringMode::eSUPPRESS => PairFilteringMode::Suppress,
            PxPairFilteringMode::eKILL => PairFilteringMode::Kill,
            // eDEFAULT has the same integer value as eSUPPRESS so it will get caught by that branch
            //PxPairFilteringMode::eDEFAULT => PairFilteringMode::Suppress,
            _ => unimplemented!("Invalid enum variant."),
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

#[derive(Copy, Clone, Debug, BitFlags)]
#[repr(u32)]
///  eMUTABLE_FLAGS = eENABLE_ACTIVE_ACTORS|eEXCLUDE_KINEMATICS_FROM_ACTIVE_ACTORS
pub enum SceneFlag {
    EnableActiveActors = 1,
    EnableCcd = 2,
    DisableCcdResweep = 4,
    AdaptiveForce = 8,
    EnablePcm = 64,
    DisableContactReportBufferResize = 128,
    DisableContactCache = 256,
    RequireRwLock = 512,
    EnableStabilization = 1024,
    EnableAveragePoint = 2048,
    ExcludeKinematicsFromActiveActors = 4096,
    EnableGpuDynamics = 8192,
    EnableEnhancedDeterminism = 16384,
    EnableFrictionEveryIteration = 32768,
}

pub struct PxSceneDesc<U, L, S, D, OC, OT, OCB, OWS, OA>
where
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,

    OC: CollisionCallback,
    OT: TriggerCallback,
    OCB: ConstraintBreakCallback,
    OWS: WakeSleepCallback<L, S, D>,
    OA: AdvanceCallback<L, D>,
{
    obj: physx_sys::PxSceneDesc,
    phantom_user_data: PhantomData<(U, L, S, D, OC, OT, OCB, OWS, OA)>,
}

impl<U, L, S, D, OC, OT, OCB, OWS, OA> PxSceneDesc<U, L, S, D, OC, OT, OCB, OWS, OA>
where
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,
    OC: CollisionCallback,
    OT: TriggerCallback,
    OCB: ConstraintBreakCallback,
    OWS: WakeSleepCallback<L, S, D>,
    OA: AdvanceCallback<L, D>,
{
    pub fn new(
        physics: &impl Physics,
        user_data: U,
        simulation_event_callback: Owner<PxSimulationEventCallback<L, S, D, OC, OT, OCB, OWS, OA>>,
        simulation_filter_shader: FilterShaderDescriptor,
        thread_count: u32,
    ) -> Option<Owner<PxSceneDesc<U, L, S, D, OC, OT, OCB, OWS, OA>>> {
        unsafe {
            let mut desc = PxSceneDesc_new(physics.get_tolerances_scale()?);
            desc.gravity = PxVec3::new(0.0, -9.81, 0.0).into();
            desc.cpuDispatcher =
                phys_PxDefaultCpuDispatcherCreate(thread_count, null_mut()) as *mut _;
            match simulation_filter_shader {
                FilterShaderDescriptor::Default => {
                    desc.filterShader = get_default_simulation_filter_shader();
                }
                FilterShaderDescriptor::CallDefaultFirst(shader) => {
                    physx_sys::enable_custom_filter_shader(&mut desc, shader, 1);
                }
                FilterShaderDescriptor::Custom(shader) => {
                    physx_sys::enable_custom_filter_shader(&mut desc, shader, 0);
                }
            };
            desc.simulationEventCallback = simulation_event_callback.into_ptr();
            let desc = Box::into_raw(Box::new(desc)) as *mut Self;
            (&mut *desc).init_user_data(user_data);
            Owner::from_raw(desc)
        }
    }
}

unsafe impl<U, L, S, D, OA, OT, OWS, OC, OCB> UserData
    for PxSceneDesc<U, L, S, D, OC, OT, OCB, OWS, OA>
where
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,
    OC: CollisionCallback,
    OT: TriggerCallback,
    OCB: ConstraintBreakCallback,
    OWS: WakeSleepCallback<L, S, D>,
    OA: AdvanceCallback<L, D>,
{
    type UserData = U;

    fn user_data_ptr(&self) -> &*mut c_void {
        &self.obj.userData
    }

    fn user_data_ptr_mut(&mut self) -> &mut *mut c_void {
        &mut self.obj.userData
    }
}

unsafe impl<U, L, S, D, OA, OT, OWS, OC, OCB> Class<physx_sys::PxSceneDesc>
    for PxSceneDesc<U, L, S, D, OC, OT, OCB, OWS, OA>
where
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,
    OC: CollisionCallback,
    OT: TriggerCallback,
    OCB: ConstraintBreakCallback,
    OWS: WakeSleepCallback<L, S, D>,
    OA: AdvanceCallback<L, D>,
{
    fn as_ptr(&self) -> *const physx_sys::PxSceneDesc {
        &self.obj
    }

    fn as_mut_ptr(&mut self) -> *mut physx_sys::PxSceneDesc {
        &mut self.obj
    }
}

pub enum FilterShaderDescriptor {
    Default,
    Custom(physx_sys::SimulationFilterShader),
    CallDefaultFirst(physx_sys::SimulationFilterShader),
}
