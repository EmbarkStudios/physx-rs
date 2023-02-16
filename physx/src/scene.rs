// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 10 April 2019

#![warn(clippy::all)]
#![allow(clippy::missing_safety_doc)]

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
    traits::{Class, PxFlags, UserData},
    visual_debugger::PvdSceneClient,
};

use enumflags2::{bitflags, BitFlags};

use std::{
    marker::PhantomData,
    ptr::{drop_in_place, null, null_mut},
};

// A glob import is super tempting, but the wrappers shadow the names of the physx_sys types,
// so those types cannot be in scope.  Plus, it easier to see what's been implemented.
use physx_sys::{
    phys_PxCreateControllerManager,
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
    PxFrictionType,
    PxPairFilteringMode,
    PxPruningStructureType,
    //PxHitFlags,
    PxSceneFlag,
    PxSceneFlags,
    PxSceneLimits,
    PxSceneQueryUpdateMode,
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
    //PxScene_getFilterCallback,
    //PxScene_getFilterShader,
    //PxScene_getFilterShaderData,
    //PxScene_getFilterShaderDataSize,
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
    PxScene_setGravity_mut,
    //PxScene_setFilterShaderData_mut,
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
    //PxSimulationFilterCallback,
    PxSolverType,
};

pub type ActorTypeFlags = BitFlags<ActorTypeFlag>;

impl PxFlags for ActorTypeFlags {
    type Target = PxActorTypeFlags;

    fn into_px(self) -> Self::Target {
        PxActorTypeFlags { mBits: self.bits() }
    }

    fn from_px(flags: Self::Target) -> Self {
        unsafe { BitFlags::from_bits_unchecked(flags.mBits) }
    }
}

#[bitflags]
#[derive(Copy, Clone, Debug)]
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
#[allow(clippy::type_complexity)]
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
            for ptr in self.get_actors(ActorTypeFlag::RigidDynamic | ActorTypeFlag::RigidStatic) {
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

    /// # Safety
    /// Owner's own the pointer they wrap, using the pointer after dropping the Owner,
    /// or creating multiple Owners from the same pointer will cause UB.  Use `into_ptr` to
    /// retrieve the pointer and consume the Owner without dropping the pointee.
    unsafe fn from_raw(ptr: *mut physx_sys::PxScene) -> Option<Owner<Self>> {
        // userData is initialized by the descriptor.
        Owner::from_raw(ptr as *mut Self)
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
    fn add_articulation(&mut self, articulation: Owner<impl ArticulationBase>) {
        unsafe {
            PxScene_addArticulation_mut(self.as_mut_ptr(), articulation.into_ptr());
        };
    }

    /// Remove an articulation from the scene.
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

    // TODO implement the rest of the simulation methods.

    ////////////////////////////////////////////////////////////////////////////////
    // Queries

    /// Get the pruning structure type for static physics objects that was set when creating the scene.
    fn get_static_structure(&self) -> PruningStructureType {
        unsafe { PxScene_getStaticStructure(self.as_ptr()).into() }
    }

    /// Get the pruning structure type for dynamic physics objects that was set when creating the scene.
    fn get_dynamic_structure(&self) -> PruningStructureType {
        unsafe { PxScene_getDynamicStructure(self.as_ptr()).into() }
    }

    /// Fluish any changes to the scene query represenation, forcing any buffered changes to be applied now,
    /// rather than when the next scene query is executed.
    fn flush_query_updates(&mut self) {
        unsafe {
            PxScene_flushQueryUpdates_mut(self.as_mut_ptr());
        }
    }

    ////////////////////////////////////////////////////////////////////////////////
    // Bulk Getters

    /// Get a Vec of the articulations in the scene.
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

    /// Get the actors in the scene, filtered by ActorTypeFlags.
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

    /// Get the dynamic actors in the scene.
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
        PxScene_setContactModifyCallback_mut(self.as_mut_ptr(), callback);
    }

    /// # Safety
    /// PxContactModifyCallback does not have a safe wrapper, using it requires use of [`physx_sys`].
    unsafe fn get_contact_modify_callback(&self) -> &PxContactModifyCallback {
        &*PxScene_getContactModifyCallback(self.as_ptr())
    }

    /// # Safety
    /// PxCCDContactModifyCallback does not have a safe wrapper, using it requires use of [`physx_sys`].
    unsafe fn set_ccd_contact_modify_callback(
        &mut self,
        callback: &mut PxCCDContactModifyCallback,
    ) {
        PxScene_setCCDContactModifyCallback_mut(self.as_mut_ptr(), callback);
    }

    /// # Safety
    /// PxCCDContactModifyCallback does not have a safe wrapper, using it requires use of [`physx_sys`].
    unsafe fn get_ccd_contact_callback(&self) -> &PxCCDContactModifyCallback {
        &*PxScene_getCCDContactModifyCallback(self.as_ptr())
    }

    /// # Safety
    /// PxBroadPhaseCallback does not have a safe wrapper, using it requires use of [`physx_sys`].
    unsafe fn set_broad_phase_callback(&mut self, callback: &mut PxBroadPhaseCallback) {
        PxScene_setBroadPhaseCallback_mut(self.as_mut_ptr(), callback);
    }

    /// # Safety
    /// PxBroadPhaseCallback does not have a safe wrapper, using it requires use of [`physx_sys`].
    unsafe fn get_broad_phase_callback(&self) -> &PxBroadPhaseCallback {
        &*PxScene_getBroadPhaseCallback(self.as_ptr())
    }

    //////////////////////////////////////////////////////////////////////////
    // Collision Filtering

    /// Reset the collision filtering for an actor.
    fn reset_filtering(&mut self, actor: &mut impl Actor) {
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
        unsafe { PxScene_getKinematicKinematicFilteringMode(self.as_ptr()).into() }
    }

    /// Get the static-kinematic filtering mode.
    fn get_static_kinematic_filtering_mode(&self) -> PairFilteringMode {
        unsafe { PxScene_getStaticKinematicFilteringMode(self.as_ptr()).into() }
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

#[bitflags]
#[derive(Copy, Clone, Debug)]
#[repr(u16)]
pub enum HitFlag {
    Position = 1 << 0,
    Normal = 1 << 1,
    Uv = 1 << 3,
    AssumeNoInitialOverlap = 1 << 4,
    MeshMultiple = 1 << 5,
    MeshAny = 1 << 6,
    MeshBothSides = 1 << 7,
    PreciseSweep = 1 << 8,
    Mtd = 1 << 9,
    FaceIndex = 1 << 10,
}

impl HitFlag {
    // Note[TSolberg]: This cannot be Default::default because it returns BitFlags<Self>, not Self.
    #[allow(clippy::should_implement_trait)]
    pub fn default() -> BitFlags<HitFlag> {
        HitFlag::Position | HitFlag::Normal | HitFlag::FaceIndex
    }
}

#[derive(Debug, Copy, Clone)]
#[repr(u32)]
pub enum SceneQueryUpdateMode {
    BuildEnabledCommitEnabled = 0,
    BuildEnabledCommitDisabled = 1,
    BuildDisabledCommitDisabled = 2,
}

impl From<SceneQueryUpdateMode> for PxSceneQueryUpdateMode::Enum {
    fn from(value: SceneQueryUpdateMode) -> Self {
        match value {
            SceneQueryUpdateMode::BuildEnabledCommitEnabled => {
                PxSceneQueryUpdateMode::eBUILD_ENABLED_COMMIT_ENABLED
            }
            SceneQueryUpdateMode::BuildEnabledCommitDisabled => {
                PxSceneQueryUpdateMode::eBUILD_ENABLED_COMMIT_DISABLED
            }
            SceneQueryUpdateMode::BuildDisabledCommitDisabled => {
                PxSceneQueryUpdateMode::eBUILD_DISABLED_COMMIT_DISABLED
            }
        }
    }
}

impl Default for SceneQueryUpdateMode {
    fn default() -> Self {
        SceneQueryUpdateMode::BuildEnabledCommitEnabled
    }
}

#[derive(Copy, Clone, Debug)]
#[repr(u32)]
pub enum PruningStructureType {
    None = 0,
    DynamicAabbTree = 1,
    StaticAabbTree = 2,
}

impl From<PruningStructureType> for PxPruningStructureType::Enum {
    fn from(value: PruningStructureType) -> Self {
        match value {
            PruningStructureType::None => PxPruningStructureType::eNONE,
            PruningStructureType::DynamicAabbTree => PxPruningStructureType::eDYNAMIC_AABB_TREE,
            PruningStructureType::StaticAabbTree => PxPruningStructureType::eSTATIC_AABB_TREE,
        }
    }
}

impl From<PxPruningStructureType::Enum> for PruningStructureType {
    fn from(val: PxPruningStructureType::Enum) -> Self {
        debug_assert!(val < PxPruningStructureType::eLAST);
        match val {
            PxPruningStructureType::eNONE => PruningStructureType::None,
            PxPruningStructureType::eDYNAMIC_AABB_TREE => PruningStructureType::DynamicAabbTree,
            PxPruningStructureType::eSTATIC_AABB_TREE => PruningStructureType::StaticAabbTree,
            _ => unreachable!("Invalid enum variant."),
        }
    }
}

impl Default for PruningStructureType {
    fn default() -> Self {
        PruningStructureType::DynamicAabbTree
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

impl From<PairFilteringMode> for PxPairFilteringMode::Enum {
    fn from(value: PairFilteringMode) -> Self {
        match value {
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
            _ => unreachable!("Invalid enum variant."),
        }
    }
}

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

#[derive(Debug, Clone, Copy)]
#[repr(u32)]
pub enum FrictionType {
    Patch = 0,
    OneDirectional = 1,
    TwoDirectional = 2,
}

impl From<FrictionType> for PxFrictionType::Enum {
    fn from(value: FrictionType) -> Self {
        match value {
            FrictionType::Patch => PxFrictionType::ePATCH,
            FrictionType::OneDirectional => PxFrictionType::eONE_DIRECTIONAL,
            FrictionType::TwoDirectional => PxFrictionType::eTWO_DIRECTIONAL,
        }
    }
}

impl Default for FrictionType {
    fn default() -> Self {
        FrictionType::Patch
    }
}

#[derive(Debug, Clone, Copy)]
#[repr(u32)]
pub enum BroadPhaseType {
    SweepAndPrune = 0,
    MultiBoxPruning = 1,
    AutomaticBoxPruning = 2,
    Gpu = 3,
}

impl From<BroadPhaseType> for PxBroadPhaseType::Enum {
    fn from(value: BroadPhaseType) -> Self {
        match value {
            BroadPhaseType::SweepAndPrune => PxBroadPhaseType::eSAP,
            BroadPhaseType::MultiBoxPruning => PxBroadPhaseType::eMBP,
            BroadPhaseType::AutomaticBoxPruning => PxBroadPhaseType::eABP,
            BroadPhaseType::Gpu => PxBroadPhaseType::eGPU,
        }
    }
}

impl Default for BroadPhaseType {
    fn default() -> Self {
        BroadPhaseType::AutomaticBoxPruning
    }
}

#[derive(Debug, Clone, Copy)]
#[repr(u32)]
pub enum SolverType {
    Pgs = 0,
    Tgs = 1,
}

impl From<SolverType> for PxSolverType::Enum {
    fn from(value: SolverType) -> Self {
        match value {
            SolverType::Pgs => PxSolverType::ePGS,
            SolverType::Tgs => PxSolverType::eTGS,
        }
    }
}

impl Default for SolverType {
    fn default() -> Self {
        SolverType::Pgs
    }
}

pub enum SimulationThreadType {
    Dedicated(u32),
    Shared(*mut PxCpuDispatcher),
    Default,
}

#[bitflags]
#[derive(Copy, Clone, Debug)]
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

impl From<SceneFlag> for PxSceneFlag::Enum {
    fn from(value: SceneFlag) -> Self {
        value as PxSceneFlag::Enum
    }
}

impl PxFlags for BitFlags<SceneFlag> {
    type Target = PxSceneFlags;

    fn into_px(self) -> Self::Target {
        PxSceneFlags { mBits: self.bits() }
    }

    fn from_px(flags: Self::Target) -> Self {
        BitFlags::from_bits_truncate(flags.mBits)
    }
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
