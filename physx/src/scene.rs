// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 10 April 2019

#![warn(clippy::all)]
#![allow(clippy::missing_safety_doc)]
#![allow(deprecated)]

/*!
Wrapper for PhysX Scene
 */

use crate::{
    actor::{Actor, ActorMap},
    aggregate::Aggregate,
    articulation_base::{ArticulationBase, ArticulationMap},
    articulation_link::ArticulationLink,
    constraint::Constraint,
    controller_manager::ControllerManager,
    owner::Owner,
    physics::Physics,
    pruning_structure::PruningStructure,
    visual_debugger::PvdSceneClient,
    rigid_actor::RigidActor,
    rigid_dynamic::RigidDynamic,
    rigid_static::RigidStatic,
    shape::Shape,
    math::PxVec3,
    traits::{Class, UserData, PxFlags},
};

use enumflags2::BitFlags;
use std::{
    ptr::{null, null_mut},
    marker::PhantomData,
    ffi::c_void,
    mem::size_of,
};

// TODO write proper wrappers for these rather than re-export
pub use physx_sys::{
    SimulationEventCallbackInfo,
    PxContactPair,
    PxContactPairHeader,
    PxRaycastCallback,
};

// A glob import is super tempting, but the wrappers shadow the names of the physx_sys types,
// so those types cannot be in scope.  Plus, it easier to see what's been implemented.
use physx_sys::{
    PxActorTypeFlags,
    PxBaseTask,
    /*
    PxOverlapCallback,
    PxSweepCallback,
    PxQueryFilterData,
    PxQueryFilterData_new,
    PxQueryFilterCallback,
    PxQueryCache,
    */
    PxContactModifyCallback,
    PxCCDContactModifyCallback,
    PxBroadPhaseCallback,
    //PxHitFlags,
    PxSceneFlags,
    PxPairFilteringMode,
    PxBroadPhaseType,
    PxPruningStructureType,
    PxSimulationFilterCallback,
    get_default_simulation_filter_shader,
    PxCpuDispatcher,
    phys_PxDefaultCpuDispatcherCreate,
    PxSceneDesc,
    PxSceneDesc_new,
    phys_PxCreateControllerManager,
    create_simulation_event_callbacks,
    destroy_simulation_event_callbacks,
    PxScene_addActor_mut,
    PxScene_addActors_mut,
    PxScene_addActors_mut_1,
    PxScene_addAggregate_mut,
    PxScene_addArticulation_mut,
    PxScene_simulate_mut,
    PxScene_fetchResults_mut,
    /* TODO implement the more involved simulation controls
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
    PxScene_getNbActors,
    PxScene_getAggregates,
    PxScene_getNbAggregates,
    PxScene_getArticulations,
    PxScene_getNbArticulations,
    PxScene_getConstraints,
    PxScene_getNbConstraints,
    PxScene_getBroadPhaseCallback,
    PxScene_getCCDContactModifyCallback,
    PxScene_getContactModifyCallback,
    PxScene_getFilterCallback,
    PxScene_getSimulationEventCallback,
    //PxScene_getFilterShader,
    PxScene_getFilterShaderData,
    PxScene_getFilterShaderDataSize,
    PxScene_getDynamicStructure,
    PxScene_getKinematicKinematicFilteringMode,
    PxScene_getScenePvdClient_mut,
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
    PxScene_setSimulationEventCallback_mut,
    /* TODO implement
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
};

pub type ActorTypeFlags = BitFlags<ActorTypeFlag>;

impl PxFlags for ActorTypeFlags {
    type Target = PxActorTypeFlags;

    fn into_px(self) -> Self::Target {
        PxActorTypeFlags{ mBits: self.bits() }
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

#[repr(transparent)]
pub struct Scene<U, L, S, D, M, H, T, C> {
    pub(crate) obj: physx_sys::PxScene,
    phantom_user_data: PhantomData<(U, L, S, D, M, H, T, C)>
}

unsafe impl<P, U, L, S, D, M, H, T, C> Class<P> for Scene<U, L, S, D, M, H, T, C> where physx_sys::PxScene: Class<P> {
    fn as_ptr(&self) -> *const P {
        self.obj.as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut P {
        self.obj.as_mut_ptr()
    }
}

impl<U, L, S, D, M, H, T, C> Scene<U, L, S, D, M, H, T, C> {
    pub(crate) unsafe fn from_raw(ptr: *mut physx_sys::PxScene) -> Option<Owner<Self>> {
        Owner::from_raw(ptr as *mut Self)
    }

    pub fn get_user_data(&self) -> &U {
        // Safety: Scenes are constructed from SceneDescriptor which sets up user data appropriately
        unsafe { UserData::get_user_data(self) }
    }

    pub fn get_user_data_mut(&mut self) -> *mut U {
        // Safety: Scenes are constructed from SceneDescriptor which sets up user data appropriately
        unsafe { UserData::get_user_data_mut(self) }
    }
    
    /// Get the visual debugger client
    pub fn get_pvd_client(&mut self) -> Option<&mut PvdSceneClient> {
        unsafe {
            (PxScene_getScenePvdClient_mut(
                self.as_mut_ptr(),
            )as *mut PvdSceneClient).as_mut()
        }
    }

    pub fn create_controller_manager(&mut self, locking_enabled: bool) -> Option<Owner<ControllerManager>> {
        unsafe {
            ControllerManager::from_raw(
                phys_PxCreateControllerManager(
                    self.as_mut_ptr(),
                    locking_enabled
                )
            )
        }
    }

    ///////////////////////////////////////////////////////////////////////////////
    // Adding/removing objects

    /// Add a dynamic actor to the world.
    pub fn add_dynamic_actor(&mut self, mut actor: Owner<RigidDynamic<D, H, M>>) {
        unsafe {
            PxScene_addActor_mut(
                self.as_mut_ptr(),
                actor.as_mut_ptr(),
                null(),
            );
        }
    }

    /// Add dynamic actors to the world.
    pub fn add_dynamic_actors(&mut self, actors: Vec<Owner<RigidDynamic<D, H, M>>>) {
        unsafe {
            PxScene_addActors_mut(
                self.as_mut_ptr(),
                actors.as_ptr() as *const *mut _,
                actors.len() as u32
            );
        }
    }
    /// Add a static actor to the world.
    pub fn add_static_actor(&mut self, mut actor: Owner<RigidStatic<S, H, M>>) {
        unsafe {
            PxScene_addActor_mut(
                self.as_mut_ptr(),
                actor.as_mut_ptr(),
                null(),
            );
        }
    }

    /// Add dynamic actors to the world.
    pub fn add_static_actors(&mut self, actors: Vec<Owner<RigidStatic<S, H, M>>>) {
        unsafe {
            PxScene_addActors_mut(
                self.as_mut_ptr(),
                actors.as_ptr() as *const *mut _,
                actors.len() as u32
            );
        }
    }
    /// Add an actor to the world.
    pub fn add_articulation_link(&mut self, mut actor: Owner<ArticulationLink<L, H, M>>) {
        unsafe {
            PxScene_addActor_mut(
                self.as_mut_ptr(),
                actor.as_mut_ptr(),
                null(),
            );
        }
    }

    pub fn add_articulation_links(&mut self, actors: Vec<Owner<ArticulationLink<L, H, M>>>) {
        unsafe {
            PxScene_addActors_mut(
                self.as_mut_ptr(),
                actors.as_ptr() as *const *mut _,
                actors.len() as u32
            );
        }
    }

    pub unsafe fn remove_actor(&mut self, actor: &mut impl Actor, wake_touching: bool) {
        //unsafe
        {
            PxScene_removeActor_mut(self.as_mut_ptr(), actor.as_mut_ptr(), wake_touching);
        }
    }

    pub unsafe fn remove_actors(&mut self, mut actors:Vec<&mut impl Actor>, wake_touching: bool) {
        PxScene_removeActors_mut(
            self.as_mut_ptr(),
            actors.iter_mut().map(
                    |actor|
                    actor.as_mut_ptr()
                ).collect::<Vec<_>>().as_ptr(),
            actors.len() as u32,
            wake_touching
        );
    }

    /// Add a articulation to the world.
    pub fn add_articulation(&mut self, mut articulation: Owner<impl ArticulationBase<L, H, M>>) {
        unsafe {
            PxScene_addArticulation_mut(
                self.as_mut_ptr(),
                articulation.as_mut_ptr(),
            );
        };
    }

    /// Remove an articulation from the world
    pub fn remove_articulation(&mut self, articulation: &mut impl ArticulationBase<L, H, M>, wake_touching: bool) {
        unsafe {
            PxScene_removeArticulation_mut(
                self.as_mut_ptr(),
                articulation.as_mut_ptr(),
                wake_touching,
            );
        }
    }

    pub fn add_aggregate(&mut self, mut aggregate: Owner<Aggregate<L, S, D, H, M>>) {
        unsafe {
            PxScene_addAggregate_mut(
                self.as_mut_ptr(),
                aggregate.as_mut_ptr()
            );
        }
    }

    pub fn remove_aggregate(&mut self, aggregate: &mut Aggregate<L, S, D, H, M>, wake_touching: bool) {
        unsafe {
            PxScene_removeAggregate_mut(
                self.as_mut_ptr(),
                aggregate.as_mut_ptr(),
                wake_touching
            );
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

    // TODO implement PruningStructure trait
    pub fn add_pruning_structure(&mut self, mut pruning_structure: Owner<PruningStructure>) {
        unsafe {
            PxScene_addActors_mut_1(
                self.as_mut_ptr(),
                pruning_structure.as_mut_ptr()
            )
        }
    }

    ////////////////////////////////////////////////////////////////////////////////
    // Simulation
    // TODO write a proper type for the scratch buffer.
    pub fn simulate(
        &mut self,
        time_step: f32,
        completion_task: Option<&mut PxBaseTask>,
        // scratch memory must be 16-align, 16K blocks
        scratch: Option<&mut [[(u64, u64); 1024]]>,
    ) {
        let completion_task = if let Some(task) = completion_task {
            task
        } else {
            null_mut()
        };

        let (scratch_ptr, scratch_size) = if let Some(scratch) = scratch {
            (scratch.as_mut_ptr() as *mut std::ffi::c_void, (scratch.len() * 16_384) as u32)
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

    // TODO maybe this should actually fetch the results? Crazy idea, I know!
    pub fn fetch_results(&mut self, block: bool) -> Result<(), u32> {
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

    // TODO pass through the fetched results
    pub fn step(
        &mut self,
        time_step: f32,
        completion_task: Option<&mut PxBaseTask>,
        // scratch memory must be 16-align, 16K blocks
        scratch: Option<&mut [[(u64, u64); 1024]]>,
        block: bool
    ) -> Result<(), u32> {
        self.simulate(time_step, completion_task, scratch);
        self.fetch_results(block)
    }

    // TODO implement the rest of the simulation methods.

    ////////////////////////////////////////////////////////////////////////////////
    // Queries

    pub unsafe fn get_static_structure(&self) -> PruningStructureType {
        PxScene_getStaticStructure(self.as_ptr()).into()
    }

    pub unsafe fn get_dynamic_structure(&self) -> PruningStructureType {
        PxScene_getDynamicStructure(self.as_ptr()).into()
    }

    pub unsafe fn flush_query_updates(&mut self) {
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
    pub unsafe fn raycast(
        &self,
        origin: &PxVec3,
        direction: &PxVec3,
        distance: f32,
        hit_flags: BitFlags<HitFlag>,
    ) -> Option<PxRaycastCallback> {
        let filter_callback = physx_sys::create_raycast_filter_callback(null_mut());
        let mut hit = std::mem::MaybeUninit::uninit();
        let filter_data = &physx_sys::PxQueryFilterData_new_2(
            physx_sys::PxQueryFlags{mBits: physx_sys::PxQueryFlag::eDYNAMIC as u16}
        );
        
        dbg!("hi");
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

    pub unsafe fn sweep(
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

    pub unsafe fn overlap(
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
    pub unsafe fn get_articulations(&mut self) -> Vec<&mut ArticulationMap<T, C, L, H, M>> {
        let capacity = PxScene_getNbArticulations(self.as_ptr());
        let mut buffer: Vec<&mut ArticulationMap<T, C, L, H, M>> = Vec::with_capacity(capacity as usize);
        let len = PxScene_getArticulations(
            self.as_ptr(),
            buffer.as_mut_ptr() as *mut *mut _,
            capacity,
            0
        );
        buffer.set_len(len as usize);
        buffer
    }

    pub unsafe fn get_actors(&mut self, actor_type: ActorTypeFlags) -> Vec<&mut ActorMap<L, S, D, H, M>> {
        let flags = actor_type.into_px();
        let capacity = PxScene_getNbActors(self.as_ptr(), flags);
        let mut buffer: Vec<&mut ActorMap<L, S, D, H, M>> = Vec::with_capacity(capacity as usize);
        let len = PxScene_getActors(
            self.as_ptr(),
            flags,
            buffer.as_mut_ptr() as *mut *mut _,
            capacity,
            0
        );
        buffer.set_len(len as usize);
        buffer
    }

    pub fn get_active_actors(&mut self) -> &mut[&mut ActorMap<L, S, D, H, M>] {
        unsafe {
            let mut length = 0;
            let actors = PxScene_getActiveActors_mut(self.as_mut_ptr(), &mut length);
            std::slice::from_raw_parts_mut(actors as *mut &mut ActorMap<L, S, D, H, M>, length as usize)
        }
    }

    pub fn get_static_actors(&mut self) -> Vec<&mut RigidStatic<S, H, M>> {
        unsafe {
            let flags = PxActorTypeFlags{mBits: ActorTypeFlag::RigidStatic as u16};
            let capacity = PxScene_getNbActors(self.as_ptr(), flags);
            let mut buffer: Vec<&mut RigidStatic<S, H, M>> = Vec::with_capacity(capacity as usize);
            let len = PxScene_getActors(
                self.as_ptr(),
                flags,
                buffer.as_mut_ptr() as *mut *mut _,
                capacity,
                0
            );
            buffer.set_len(len as usize);
            buffer
        }
    }

    /// Safety: `U` must be the same user data type as the actors were instantiated with.
    pub fn get_dynamic_actors(&mut self) -> Vec<&mut RigidDynamic<D, H, M>> {
        unsafe {
            let flags = PxActorTypeFlags{mBits: ActorTypeFlag::RigidDynamic as u16};
            let capacity = PxScene_getNbActors(self.as_ptr(), flags);
            let mut buffer: Vec<&mut RigidDynamic<D, H, M>> = Vec::with_capacity(capacity as usize);
            let len = PxScene_getActors(
                self.as_ptr(),
                flags,
                buffer.as_mut_ptr() as *mut *mut _,
                capacity,
                0
            );
            buffer.set_len(len as usize);
            buffer
        }
    }

    pub fn get_aggregates(&self) -> Vec<&Aggregate<L, S, D, H, M>> {
        unsafe {
            let capacity = PxScene_getNbAggregates(self.as_ptr());
            let mut buffer: Vec<&Aggregate<L, S, D, H, M>> = Vec::with_capacity(capacity as usize);
            let len = PxScene_getAggregates(
                self.as_ptr(),
                buffer.as_mut_ptr() as *mut *mut physx_sys::PxAggregate,
                capacity,
                0
            );
            buffer.set_len(len as usize);
            buffer
        }
    }

    pub fn get_constraints(&mut self) -> Vec<&mut Constraint> {
        unsafe {
            let capacity = PxScene_getNbConstraints(self.as_ptr());
            let mut buffer: Vec<&mut Constraint> = Vec::with_capacity(capacity as usize);
            let len = PxScene_getConstraints(
                self.as_ptr(),
                buffer.as_mut_ptr() as *mut *mut physx_sys::PxConstraint,
                capacity,
                0
            );
            buffer.set_len(len as usize);
            buffer
        }
    }

    //////////////////////////////////////////////////////////////////////////
    // Callbacks

    pub fn set_simulation_event_callback(
        &mut self,
        callbacks: &SimulationEventCallbackInfo,
    ) {
        unsafe {
            let callback = create_simulation_event_callbacks(&*callbacks);
            PxScene_setSimulationEventCallback_mut(
                self.as_mut_ptr(),
                &mut *callback,
            );
        }
    }

    pub fn get_simulation_event_callbacks(&self) -> Option<&PxSimulationEventCallback> {
        unsafe {PxSimulationEventCallback::from_raw(PxScene_getSimulationEventCallback(self.as_ptr()))}
        .map(|mut_ref|&*mut_ref)
    }

    pub unsafe fn set_contact_modify_callback(&mut self, callback: &mut PxContactModifyCallback) {
        PxScene_setContactModifyCallback_mut(self.as_mut_ptr(), callback);
    }

    pub unsafe fn get_contact_modify_callback(&self) -> &PxContactModifyCallback {
        &*PxScene_getContactModifyCallback(self.as_ptr())
    }

    pub unsafe fn set_ccd_contact_modify_callback(&mut self, callback: &mut PxCCDContactModifyCallback) {
        PxScene_setCCDContactModifyCallback_mut(self.as_mut_ptr(), callback);
    }

    pub unsafe fn get_ccd_contact_callback(&self) -> &PxCCDContactModifyCallback {
        &*PxScene_getCCDContactModifyCallback(self.as_ptr())
    }

    pub unsafe fn set_broad_phase_callback(&mut self, callback: &mut PxBroadPhaseCallback) {
        PxScene_setBroadPhaseCallback_mut(self.as_mut_ptr(), callback);
    }

    pub unsafe fn get_broad_phase_callback(&self) -> &PxBroadPhaseCallback {
        &*PxScene_getBroadPhaseCallback(self.as_ptr())
    }

    //////////////////////////////////////////////////////////////////////////
    // Collision Filtering

    // TODO add a generic type to Scene for this so it's typesafe :)
    pub unsafe fn set_filter_shader_data(&mut self, data: &[u8]) {
        PxScene_setFilterShaderData_mut(
            self.as_mut_ptr(),
            data.as_ptr() as *const std::ffi::c_void,
            data.len() as u32
        );
    }

    // TODO if this was typed, it would be a much friendlier interface :)
    pub unsafe fn get_filter_shader_data(&self) -> &[u8] {
        std::slice::from_raw_parts(
            PxScene_getFilterShaderData(self.as_ptr()) as *const u8,
            PxScene_getFilterShaderDataSize(self.as_ptr()) as usize
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

    pub unsafe fn get_filter_callback(&self)-> &PxSimulationFilterCallback {
        &*PxScene_getFilterCallback(self.as_ptr())
    }

    pub unsafe fn reset_filtering(&mut self, actor: &mut impl Actor) {
        PxScene_resetFiltering_mut(self.as_mut_ptr(), actor.as_mut_ptr())
    }

    pub unsafe fn reset_rigid_actor_filtering(
        &mut self,
        actor: &mut impl RigidActor<H, M>,
        shapes: &[&mut Shape<H, M>]
    ) {
        PxScene_resetFiltering_mut_1(
            self.as_mut_ptr(),
            actor.as_mut_ptr(),
            shapes.as_ptr() as *const *mut physx_sys::PxShape,
            shapes.len() as u32
        );
    }

    pub unsafe fn get_kinematic_kinematic_filtering_mode(&self) -> PairFilteringMode {
        PxScene_getKinematicKinematicFilteringMode(self.as_ptr()).into()
    }

    pub unsafe fn get_static_kinematic_filtering_mode(&self) -> PairFilteringMode {
        PxScene_getStaticKinematicFilteringMode(self.as_ptr()).into()
    }
}

unsafe impl<U: Send, L: Send, S: Send, D: Send, M: Send, H: Send, T: Send, C: Send> Send for Scene<U, L, S, D, M, H, T, C> {}
unsafe impl<U: Sync, L: Sync, S: Sync, D: Sync, M: Sync, H: Sync, T: Sync, C: Sync> Sync for Scene<U, L, S, D, M, H, T, C> {}

impl<U, L, S, D, M, H, T, C> Drop for Scene<U, L, S, D, M, H, T, C> {
    fn drop(&mut self) {
        unsafe {
            PxScene_release_mut(self.as_mut_ptr());
        }
    }
}

#[repr(transparent)]
pub struct PxSimulationEventCallback {
    obj: physx_sys::PxSimulationEventCallback,
}

crate::ClassObj!(PxSimulationEventCallback : PxSimulationEventCallback);

impl PxSimulationEventCallback {
    fn new<'a>(callbacks: SimulationEventCallbackInfo) -> Option<&'a mut Self> {
        unsafe {
            Self::from_raw(create_simulation_event_callbacks(&callbacks))
        }
    }

    unsafe fn from_raw<'a>(ptr: *mut physx_sys::PxSimulationEventCallback) -> Option<&'a mut PxSimulationEventCallback> {
        (ptr as *mut Self).as_mut()
    }
}

impl Drop for PxSimulationEventCallback {
    fn drop(&mut self) {
        unsafe {
            destroy_simulation_event_callbacks(self.as_mut_ptr());
        }
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
            _ => unimplemented!("Invalid enum variant.")
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
            _ => unimplemented!("Invalid enum variant.")
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

pub struct SceneDescriptor<E, L, S, D, T, C> {
    pub gravity: PxVec3,
    pub controller_manager: Option<Owner<ControllerManager>>,
    pub simulation_threading: SimulationThreadType,
    pub scene_flags: BitFlags<SceneFlag>,
    pub simulation_event_callback: SimulationEventCallbackInfo,
    pub scene_user_data: E,
    // filter_shader: Option<SimulationFilterShader>,
    // broad_phase_type: BroadPhaseType,
    // call_default_filter_shader_first: bool,
    pub phantom_user_data: PhantomData<(
        L, // ArticulationLink user data
        S, // RigidStatic user data
        D, // RigidDynamic user data
        T, // Articulation user data
        C  // ArticulationReducedCoordinate user data
    )>,
}

impl Default for SceneDescriptor<(), (), (), (), (), ()> {
    fn default() -> SceneDescriptor<(), (), (), (), (), ()> {
        SceneDescriptor {
            gravity: PxVec3::new(0.0, -9.81, 0.0),
            controller_manager: None,
            simulation_threading: SimulationThreadType::Default,
            scene_flags: SceneFlag::EnablePcm | SceneFlag::EnableActiveActors,
            simulation_event_callback: SimulationEventCallbackInfo::default(),
            scene_user_data: (),
            phantom_user_data: PhantomData::<((), (), (), (), ())>,
        }
    }
}

impl<E, L, S, D, T, C> SceneDescriptor<E, L, S, D, T, C> {
    pub fn set_all_user_data_types<U>(self) -> SceneDescriptor<E, U, U, U, U, U> {
        SceneDescriptor {
            phantom_user_data: PhantomData::<(U, U, U, U, U)>,
            gravity: self.gravity,
            controller_manager: self.controller_manager,
            simulation_threading: self.simulation_threading,
            scene_flags: self.scene_flags,
            simulation_event_callback: self.simulation_event_callback,
            scene_user_data: self.scene_user_data,
        }
    }

    pub fn set_actor_user_data_types<U>(self) -> SceneDescriptor<E, U, U, U, T, C> {
        SceneDescriptor {
            phantom_user_data: PhantomData::<(U, U, U, T, C)>,
            gravity: self.gravity,
            controller_manager: self.controller_manager,
            simulation_threading: self.simulation_threading,
            scene_flags: self.scene_flags,
            simulation_event_callback: self.simulation_event_callback,
            scene_user_data: self.scene_user_data,
        }
    }

    /// Set the type of ArticulationLink's user data field.
    pub fn articulation_link_type<U>(self) -> SceneDescriptor<E, U, S, D, T, C> {
        SceneDescriptor {
            phantom_user_data: PhantomData::<(U, S, D, T, C)>,
            gravity: self.gravity,
            controller_manager: self.controller_manager,
            simulation_threading: self.simulation_threading,
            scene_flags: self.scene_flags,
            simulation_event_callback: self.simulation_event_callback,
            scene_user_data: self.scene_user_data,
        }
    }

    /// Set the type of RigidStatic's user data field.
    pub fn rigid_static_type<U>(self) -> SceneDescriptor<E, L, U, D, T, C> {
        SceneDescriptor {
            phantom_user_data: PhantomData::<(L, U, D, T, C)>,
            gravity: self.gravity,
            controller_manager: self.controller_manager,
            simulation_threading: self.simulation_threading,
            scene_flags: self.scene_flags,
            simulation_event_callback: self.simulation_event_callback,
            scene_user_data: self.scene_user_data,
        }
    }

    /// Set the type of RigidDynamic's user data field.
    pub fn rigid_dynamic_type<U>(self) -> SceneDescriptor<E, L, S, U, T, C> {
        SceneDescriptor {
            phantom_user_data: PhantomData::<(L, S, U, T, C)>,
            gravity: self.gravity,
            controller_manager: self.controller_manager,
            simulation_threading: self.simulation_threading,
            scene_flags: self.scene_flags,
            simulation_event_callback: self.simulation_event_callback,
            scene_user_data: self.scene_user_data,
        }
    }

    /// Set the type of Articulation's user data field.
    pub fn articulation_type<U>(self) -> SceneDescriptor<E, L, S, D, U, C> {
        SceneDescriptor {
            phantom_user_data: PhantomData::<(L, S, D, U, C)>,
            gravity: self.gravity,
            controller_manager: self.controller_manager,
            simulation_threading: self.simulation_threading,
            scene_flags: self.scene_flags,
            simulation_event_callback: self.simulation_event_callback,
            scene_user_data: self.scene_user_data,
        }
    }

    /// Set the type of ArticulationReducedCoordinate's user data field.
    pub fn articulation_reduced_coordinate_type<U>(self) -> SceneDescriptor<E, L, S, D, T, U> {
        SceneDescriptor {
            phantom_user_data: PhantomData::<(L, S, D, T, U)>,
            gravity: self.gravity,
            controller_manager: self.controller_manager,
            simulation_threading: self.simulation_threading,
            scene_flags: self.scene_flags,
            simulation_event_callback: self.simulation_event_callback,
            scene_user_data: self.scene_user_data,
        }
    }

    pub(crate) fn into_desc<H, M>(self, physics: &mut Physics<H, M>) -> PxSceneDesc {
        let mut desc = unsafe {
            PxSceneDesc_new(physics.get_tolerances_scale().unwrap())
        };

        desc.cpuDispatcher = match self.simulation_threading {
            SimulationThreadType::Default => {
                unsafe {
                    phys_PxDefaultCpuDispatcherCreate(1, null_mut()) as *mut _
                }
            }
            SimulationThreadType::Dedicated(count) => {
                unsafe {
                    phys_PxDefaultCpuDispatcherCreate(count, null_mut()) as *mut _
                }
            }
            SimulationThreadType::Shared(dispatcher) => dispatcher,
        };
        desc.gravity = self.gravity.into();
        desc.flags = PxSceneFlags{mBits: self.scene_flags.bits()};
        desc.simulationEventCallback = {
            PxSimulationEventCallback::new(self.simulation_event_callback)
            .expect("Simulation event callback creation returned a null pointer.")
            as *mut PxSimulationEventCallback as *mut physx_sys::PxSimulationEventCallback
        };
        unsafe {
            desc.filterShader = get_default_simulation_filter_shader();
            desc.userData = if size_of::<E>() > size_of::<*mut c_void>() {
                // Too big to pack into a *mut c_void, kick it to the heap.
                let data = Box::new(self.scene_user_data);
                Box::into_raw(data) as *mut c_void
    
            } else { // DATA_SIZE < VOID_SIZE
                *(&self.scene_user_data as *const E as *const *mut c_void)
            }
        }
        
        desc
    }
}