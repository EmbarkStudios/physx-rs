use crate::{
    articulation::Articulation,
    articulation_link::ArticulationLink,
    articulation_reduced_coordinate::ArticulationReducedCoordinate,
    constraint::Constraint,
    geometry::Geometry,
    material::Material,
    math::{PxBounds3, PxTransform, PxVec3},
    owner::Owner,
    physics::Physics,
    rigid_actor::RigidActor,
    rigid_dynamic::{PxRigidDynamic, RigidDynamic},
    rigid_static::{PxRigidStatic, RigidStatic},
    scene::{
        BroadPhaseType, FilterShaderDescriptor, FrictionType, PairFilteringMode,
        PruningStructureType, PxScene, Scene, SceneFlag, SceneLimits, SceneQueryUpdateMode,
        SolverType,
    },
    shape::{Shape, ShapeFlags},
    simulation_event_callback::{
        AdvanceCallback, CollisionCallback, ConstraintBreakCallback, PxSimulationEventCallback,
        TriggerCallback, WakeSleepCallback,
    },
    traits::{PxFlags, UserData},
};

use enumflags2::BitFlags;

use std::{ffi::c_void, marker::PhantomData, mem::size_of, ptr::null_mut};

pub trait Descriptor<P> {
    type Target;
    fn create(self, creator: &mut P) -> Self::Target;
}

pub struct SceneDescriptor<
    U,
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
> {
    pub phantom_marker: PhantomData<(L, S, D, T, C)>,
    pub user_data: U,
    pub on_collide: Option<OC>,
    pub on_trigger: Option<OT>,
    pub on_constraint_break: Option<OCB>,
    pub on_wake_sleep: Option<OWS>,
    pub on_advance: Option<OA>,
    pub gravity: PxVec3,
    pub kine_kine_filtering_mode: PairFilteringMode,
    pub static_kine_filtering_mode: PairFilteringMode,
    pub broad_phase_type: BroadPhaseType,
    pub limits: SceneLimits,
    pub friction_type: FrictionType,
    pub solver_type: SolverType,
    pub bounce_threshold_velocity: f32,
    pub friction_offset_threshold: f32,
    pub ccd_max_separation: f32,
    pub solver_offset_slop: f32,
    pub flags: BitFlags<SceneFlag>,
    pub static_structure: PruningStructureType,
    pub dynamic_structure: PruningStructureType,
    pub dynamic_tree_rebuild_rate_hint: u32,
    pub scene_query_update_mode: SceneQueryUpdateMode,
    pub solver_batch_size: u32,
    pub solver_articulation_batch_size: u32,
    pub nb_contact_data_blocks: u32,
    pub max_nb_contact_data_blocks: u32,
    pub max_bias_coefficient: f32,
    pub contact_report_stream_buffer_size: u32,
    pub ccd_max_passes: u32,
    pub ccd_threshold: f32,
    pub wake_counter_reset_value: f32,
    pub sanity_bounds: PxBounds3,

    pub simulation_filter_shader: FilterShaderDescriptor,

    pub thread_count: u32, //pub cpu_dispatcher: *mut PxCpuDispatcher,
    pub broad_phase_callback: *mut physx_sys::PxBroadPhaseCallback,
    pub contact_modify_callback: *mut physx_sys::PxContactModifyCallback,
    pub ccd_contact_modify_callback: *mut physx_sys::PxCCDContactModifyCallback,

    pub cuda_context_manager: *mut physx_sys::PxCudaContextManager,
    pub gpu_dynamics_config: physx_sys::PxgDynamicsMemoryConfig,
    pub gpu_max_num_partitions: u32,
    pub gpu_compute_version: u32,
}

impl<
        U,
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
    > SceneDescriptor<U, L, S, D, T, C, OC, OT, OCB, OWS, OA>
{
    pub fn new(user_data: U) -> Self {
        Self {
            phantom_marker: PhantomData,
            user_data,
            on_collide: None,
            on_trigger: None,
            on_constraint_break: None,
            on_wake_sleep: None,
            on_advance: None,
            gravity: PxVec3::new(0.0, 0.0, 0.0),
            kine_kine_filtering_mode: PairFilteringMode::Suppress,
            static_kine_filtering_mode: PairFilteringMode::Suppress,
            broad_phase_type: BroadPhaseType::AutomaticBoxPruning,
            limits: SceneLimits {
                max_nb_actors: 0,
                max_nb_bodies: 0,
                max_nb_static_shapes: 0,
                max_nb_dynamic_shapes: 0,
                max_nb_aggregates: 0,
                max_nb_constraints: 0,
                max_nb_regions: 0,
                max_nb_broad_phase_overlaps: 0,
            },
            friction_type: FrictionType::Patch,
            solver_type: SolverType::Pgs,
            bounce_threshold_velocity: 2.0,
            friction_offset_threshold: 0.04,
            ccd_max_separation: 0.04,
            solver_offset_slop: 0.0,
            flags: SceneFlag::EnablePcm.into(),
            static_structure: PruningStructureType::DynamicAabbTree,
            dynamic_structure: PruningStructureType::DynamicAabbTree,
            dynamic_tree_rebuild_rate_hint: 100,
            scene_query_update_mode: SceneQueryUpdateMode::BuildEnabledCommitEnabled,
            solver_batch_size: 128,
            solver_articulation_batch_size: 16,
            nb_contact_data_blocks: 0,
            max_nb_contact_data_blocks: 1 << 16,
            max_bias_coefficient: f32::MAX,
            contact_report_stream_buffer_size: 8192,
            ccd_max_passes: 1,
            ccd_threshold: f32::MAX,
            wake_counter_reset_value: 0.4,
            sanity_bounds: PxBounds3::max_bounds_extents(),
            simulation_filter_shader: FilterShaderDescriptor::Default,
            thread_count: 1,
            broad_phase_callback: null_mut(),
            contact_modify_callback: null_mut(),
            ccd_contact_modify_callback: null_mut(),
            cuda_context_manager: null_mut(),
            gpu_dynamics_config: unsafe { physx_sys::PxgDynamicsMemoryConfig_new() },
            gpu_max_num_partitions: 8,
            gpu_compute_version: 0,
        }
    }
}

impl<
        P: Physics,
        U,
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
    > Descriptor<P> for SceneDescriptor<U, L, S, D, T, C, OC, OT, OCB, OWS, OA>
{
    #[allow(clippy::type_complexity)]
    type Target = Option<Owner<PxScene<U, L, S, D, T, C, OC, OT, OCB, OWS, OA>>>;

    fn create(self, creator: &mut P) -> Self::Target {
        let mut desc = unsafe {
            physx_sys::PxSceneDesc {
                gravity: self.gravity.into(),
                limits: self.limits.into(),
                bounceThresholdVelocity: self.bounce_threshold_velocity,
                frictionOffsetThreshold: self.friction_offset_threshold,
                ccdMaxSeparation: self.ccd_max_separation,
                solverOffsetSlop: self.solver_offset_slop,
                flags: self.flags.into_px(),
                userData: if size_of::<U>() > size_of::<*mut c_void>() {
                    // Too big to pack into a *mut c_void, kick it to the heap.
                    Box::into_raw(Box::new(self.user_data)) as *mut c_void
                } else {
                    // DATA_SIZE <= VOID_SIZE
                    *(&self.user_data as *const U as *const *mut c_void)
                },
                solverBatchSize: self.solver_batch_size,
                solverArticulationBatchSize: self.solver_articulation_batch_size,
                maxBiasCoefficient: self.max_bias_coefficient,
                ccdMaxPasses: self.ccd_max_passes,
                ccdThreshold: self.ccd_threshold,
                wakeCounterResetValue: self.wake_counter_reset_value,
                sanityBounds: self.sanity_bounds.into(),
                simulationEventCallback: PxSimulationEventCallback::new(
                    self.on_collide,
                    self.on_trigger,
                    self.on_constraint_break,
                    self.on_wake_sleep,
                    self.on_advance,
                )?
                .into_ptr(),
                kineKineFilteringMode: self.kine_kine_filtering_mode.into(),
                staticKineFilteringMode: self.static_kine_filtering_mode.into(),
                frictionType: self.friction_type.into(),
                solverType: self.solver_type.into(),
                broadPhaseType: self.broad_phase_type.into(),
                dynamicStructure: self.dynamic_structure.into(),
                staticStructure: self.static_structure.into(),
                dynamicTreeRebuildRateHint: self.dynamic_tree_rebuild_rate_hint,
                sceneQueryUpdateMode: self.scene_query_update_mode.into(),
                nbContactDataBlocks: self.nb_contact_data_blocks,
                maxNbContactDataBlocks: self.max_nb_contact_data_blocks,
                contactReportStreamBufferSize: self.contact_report_stream_buffer_size,
                cpuDispatcher: physx_sys::phys_PxDefaultCpuDispatcherCreate(
                    self.thread_count,
                    null_mut(),
                ) as *mut physx_sys::PxCpuDispatcher,
                contactModifyCallback: self.contact_modify_callback,
                ccdContactModifyCallback: self.ccd_contact_modify_callback,
                broadPhaseCallback: self.broad_phase_callback,
                cudaContextManager: self.cuda_context_manager,
                gpuDynamicsConfig: self.gpu_dynamics_config,
                gpuMaxNumPartitions: self.gpu_max_num_partitions,
                gpuComputeVersion: self.gpu_compute_version,
                ..physx_sys::PxSceneDesc_new(creator.get_tolerances_scale()?)
            }
        };
        unsafe {
            match self.simulation_filter_shader {
                FilterShaderDescriptor::Default => {
                    desc.filterShader = physx_sys::get_default_simulation_filter_shader();
                }
                FilterShaderDescriptor::CallDefaultFirst(shader) => {
                    physx_sys::enable_custom_filter_shader(&mut desc, shader, 1);
                }
                FilterShaderDescriptor::Custom(shader) => {
                    physx_sys::enable_custom_filter_shader(&mut desc, shader, 0);
                }
            }
        };
        unsafe {
            Scene::from_raw(physx_sys::PxPhysics_createScene_mut(
                creator.as_mut_ptr(),
                &desc,
            ))
        }
    }
}

pub struct ConstraintDescriptor<'a, RA: RigidActor> {
    first_actor: &'a mut RA,
    second_actor: &'a mut RA,
    connector: &'a mut physx_sys::PxConstraintConnector,
    shaders: &'a physx_sys::PxConstraintShaderTable,
    data_size: u32,
}

impl<P: Physics, RA: RigidActor> Descriptor<P> for ConstraintDescriptor<'_, RA> {
    type Target = Option<Owner<Constraint>>;

    fn create(self, creator: &mut P) -> Self::Target {
        creator.create_constraint(
            self.first_actor,
            self.second_actor,
            self.connector,
            self.shaders,
            self.data_size,
        )
    }
}

pub struct MaterialDescriptor<U> {
    pub static_friction: f32,
    pub dynamic_friction: f32,
    pub restitution: f32,
    pub user_data: U,
}

impl<P: Physics> Descriptor<P>
    for MaterialDescriptor<<<<P as Physics>::Shape as Shape>::Material as UserData>::UserData>
{
    type Target = Option<Owner<<<P as Physics>::Shape as Shape>::Material>>;
    fn create(self, physics: &mut P) -> Self::Target {
        physics.create_material(
            self.static_friction,
            self.dynamic_friction,
            self.restitution,
            self.user_data,
        )
    }
}

pub struct ShapeDescriptor<'a, U, G: Geometry, M: Material> {
    pub geometry: &'a G,
    pub materials: &'a mut [&'a mut M],
    pub is_exclusive: bool,
    pub shape_flags: ShapeFlags,
    pub user_data: U,
}

impl<P: Physics, G: Geometry> Descriptor<P>
    for ShapeDescriptor<'_, <P::Shape as UserData>::UserData, G, <P::Shape as Shape>::Material>
{
    type Target = Option<Owner<P::Shape>>;

    fn create(self, creator: &mut P) -> Self::Target {
        creator.create_shape(
            self.geometry,
            self.materials,
            self.is_exclusive,
            self.shape_flags,
            self.user_data,
        )
    }
}

pub struct RigidDynamicDescriptor<'a, U, G: Geometry, M: Material> {
    pub transform: PxTransform,
    pub geometry: &'a G,
    pub material: &'a mut M,
    pub density: f32,
    pub shape_transform: PxTransform,
    pub user_data: U,
}

impl<P: Physics, U, G: Geometry> Descriptor<P>
    for RigidDynamicDescriptor<'_, U, G, <P::Shape as Shape>::Material>
{
    type Target = Option<Owner<PxRigidDynamic<U, P::Shape>>>;

    fn create(self, creator: &mut P) -> Self::Target {
        creator.create_rigid_dynamic(
            self.transform,
            self.geometry,
            self.material,
            self.density,
            self.shape_transform,
            self.user_data,
        )
    }
}

pub struct RigidStaticDescriptor<'a, U, G: Geometry, M: Material> {
    pub transform: PxTransform,
    pub geometry: &'a G,
    pub material: &'a mut M,
    pub shape_transform: PxTransform,
    pub user_data: U,
}

impl<P: Physics, U, G: Geometry> Descriptor<P>
    for RigidStaticDescriptor<'_, U, G, <P::Shape as Shape>::Material>
{
    type Target = Option<Owner<PxRigidStatic<U, P::Shape>>>;

    fn create(self, creator: &mut P) -> Self::Target {
        creator.create_rigid_static(
            self.transform,
            self.geometry,
            self.material,
            self.shape_transform,
            self.user_data,
        )
    }
}

pub struct PlaneDescriptor<'a, U, M: Material> {
    pub normal: PxVec3,
    pub offset: f32,
    pub material: &'a mut M,
    pub user_data: U,
}

impl<P: Physics, U> Descriptor<P> for PlaneDescriptor<'_, U, <P::Shape as Shape>::Material> {
    type Target = Option<Owner<PxRigidStatic<U, P::Shape>>>;

    fn create(self, creator: &mut P) -> Self::Target {
        creator.create_plane(self.normal, self.offset, self.material, self.user_data)
    }
}
