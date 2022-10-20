// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created:  2 April 2019

/*!
Wrapper interface for PxPhysics
 */

#![allow(clippy::missing_safety_doc)]

mod assert_handler;
mod error_callback;
mod profiler;

use crate::{
    aggregate::{Aggregate, PxAggregate},
    articulation::{Articulation, PxArticulation},
    articulation_link::ArticulationLink,
    articulation_reduced_coordinate::{
        ArticulationReducedCoordinate, PxArticulationReducedCoordinate,
    },
    bvh_structure::BvhStructure,
    constraint::Constraint,
    convex_mesh::ConvexMesh,
    foundation::{AllocatorCallback, DefaultAllocator, Foundation, PxFoundation},
    geometry::Geometry,
    height_field::HeightField,
    material::Material,
    math::{PxTransform, PxVec3},
    owner::Owner,
    pruning_structure::PruningStructure,
    rigid_actor::RigidActor,
    rigid_dynamic::{PxRigidDynamic, RigidDynamic},
    rigid_static::{PxRigidStatic, RigidStatic},
    scene::PxScene,
    shape::{Shape, ShapeFlags},
    simulation_event_callback::*,
    traits::{Class, Descriptor, PxFlags, SceneDescriptor, UserData},
    triangle_mesh::TriangleMesh,
    visual_debugger::VisualDebugger,
};

use std::{marker::PhantomData, ptr::null_mut};

use physx_sys::{
    phys_PxCloseExtensions,
    phys_PxCreatePhysics,
    // TODO implement the extensions interface, move these there isntead of here?
    //phys_PxCreateBasePhysics,  used with extentions
    phys_PxInitExtensions,
    phys_PxSetAssertHandler,
    phys_PxSetProfilerCallback,
    physx_create_physics,
    //FilterShaderCallbackInfo,
    PxConstraintConnector,
    PxConstraintShaderTable,
    PxErrorCallback,
    //PxFilterFlag,
    PxInputStream,
    //PxPairFlag,
    PxPhysicsInsertionCallback,
    PxPhysics_createAggregate_mut,
    PxPhysics_createArticulationReducedCoordinate_mut,
    PxPhysics_createArticulation_mut,
    PxPhysics_createBVHStructure_mut,
    PxPhysics_createConstraint_mut,
    PxPhysics_createConvexMesh_mut,
    PxPhysics_createHeightField_mut,
    PxPhysics_createMaterial_mut,
    PxPhysics_createPruningStructure_mut,
    PxPhysics_createRigidDynamic_mut,
    PxPhysics_createRigidStatic_mut,
    PxPhysics_createShape_mut_1,
    PxPhysics_createTriangleMesh_mut,
    PxPhysics_getBVHStructures,
    PxPhysics_getConvexMeshes,
    PxPhysics_getHeightFields,
    PxPhysics_getMaterials,
    PxPhysics_getNbBVHStructures,
    PxPhysics_getNbConvexMeshes,
    PxPhysics_getNbHeightFields,
    PxPhysics_getNbMaterials,
    PxPhysics_getNbShapes,
    PxPhysics_getNbTriangleMeshes,
    PxPhysics_getPhysicsInsertionCallback_mut,
    PxPhysics_getShapes,
    PxPhysics_getTolerancesScale,
    PxPhysics_getTriangleMeshes,
    PxPhysics_release_mut,
    //PxPhysics_getNbScenes,
    //PxPhysics_getScenes,
    //PxPhysics_registerDeletionListener_mut,
    //PxPhysics_registerDeletionListenerObjects_mut,
    //PxPhysics_unregisterDeletionListener_mut,
    //PxPhysics_unregisterDeletionListenerObjects_mut,
    //PxPhysics_getFoundation_mut, // probably not necessary? also sketch wrt obrm
    //PxPhysics_createShape_mut, PxPhysics_createShape_mut_1 is the same but more
    PxTolerancesScale,
    PxTolerancesScale_new,
};

pub use self::assert_handler::AssertHandler;
pub use self::error_callback::ErrorCallback;
pub use self::profiler::ProfilerCallback;

pub const PX_PHYSICS_VERSION: u32 = crate::version(4, 1, 1);

/// A PxPhysics, PxFoundation and optional PxPvd combined into one struct for ease of use.
/// Parametrized by the Foundation's Allocator and the Physics' Shape type.
pub struct PhysicsFoundation<Allocator: AllocatorCallback, Geom: Shape> {
    // Order matters here for Drop. Foundation must be dropped last.
    physics: Owner<PxPhysics<Geom>>,
    pvd: Option<VisualDebugger>,
    foundation: Owner<PxFoundation<Allocator>>,
    extensions_loaded: bool,
}

unsafe impl<T, Allocator: AllocatorCallback, Geom: Shape> Class<T>
    for PhysicsFoundation<Allocator, Geom>
where
    physx_sys::PxPhysics: Class<T>,
{
    fn as_ptr(&self) -> *const T {
        self.physics.obj.as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut T {
        self.physics.obj.as_mut_ptr()
    }
}

impl<Allocator: AllocatorCallback, Geom: Shape> Physics for PhysicsFoundation<Allocator, Geom> {
    type Shape = Geom;
}

impl<Allocator: AllocatorCallback, Geom: Shape> PhysicsFoundation<Allocator, Geom> {
    pub fn new(allocator: Allocator) -> PhysicsFoundation<Allocator, Geom> {
        let mut foundation =
            PxFoundation::new(allocator).expect("Create Foundation returned a null pointer");
        let physics =
            PxPhysics::new(foundation.as_mut()).expect("Create PxPhysics returned a null pointer.");
        Self {
            foundation,
            physics,
            pvd: None,
            extensions_loaded: false,
        }
    }

    /// Set the profiler callback to a struct that implements the `ProfilerCallback` trait.
    pub fn set_profiler<P: ProfilerCallback>(&mut self, profiler: P) {
        unsafe {
            phys_PxSetProfilerCallback(profiler.into_px());
        }
    }

    /// Set the global PhysX assert handler to a struct that implements the `AssertHandler` trait.
    pub fn set_assert_handler<AH: AssertHandler>(&mut self, handler: AH) {
        unsafe { phys_PxSetAssertHandler(handler.into_px()) }
    }

    /// # Safety
    /// `error_callback` must live as long as the returned value
    pub unsafe fn with_allocator_error_callback(
        allocator: Allocator,
        error_callback: *mut PxErrorCallback,
    ) -> PhysicsFoundation<Allocator, Geom> {
        let mut foundation = PxFoundation::with_allocator_error_callback(allocator, error_callback)
            .expect("Create Foundation returned a null pointer");
        let physics =
            PxPhysics::new(foundation.as_mut()).expect("Create PxPhysics returned a null pointer.");
        Self {
            foundation,
            physics,
            pvd: None,
            extensions_loaded: false,
        }
    }

    pub fn physics(&self) -> &PxPhysics<Geom> {
        self.physics.as_ref()
    }

    pub fn foundation(&self) -> &PxFoundation<Allocator> {
        self.foundation.as_ref()
    }

    pub fn pvd(&self) -> Option<&VisualDebugger> {
        self.pvd.as_ref()
    }

    pub fn physics_mut(&mut self) -> &mut PxPhysics<Geom> {
        self.physics.as_mut()
    }

    pub fn foundation_mut(&mut self) -> &mut PxFoundation<Allocator> {
        self.foundation.as_mut()
    }

    pub fn pvd_mut(&mut self) -> Option<&mut VisualDebugger> {
        self.pvd.as_mut()
    }
}

impl<Geom: Shape> Default for PhysicsFoundation<DefaultAllocator, Geom> {
    fn default() -> Self {
        let mut foundation =
            PxFoundation::new(DefaultAllocator).expect("Create Foundation returned a null pointer");
        let physics =
            PxPhysics::new(foundation.as_mut()).expect("Create PxPhysics returned a null pointer.");
        Self {
            foundation,
            physics,
            pvd: None,
            extensions_loaded: false,
        }
    }
}

impl<Allocator: AllocatorCallback, Geom: Shape> Drop for PhysicsFoundation<Allocator, Geom> {
    fn drop(&mut self) {
        if self.extensions_loaded {
            unsafe {
                phys_PxCloseExtensions();
            }
        };
    }
}

/// A new type wrapper for PxPhysics.  Parametrized by the type of the Shapes it can create.
#[repr(transparent)]
pub struct PxPhysics<Geom: Shape> {
    obj: physx_sys::PxPhysics,
    phantom_user_data: PhantomData<Geom>,
}

impl<Geom: Shape> PxPhysics<Geom> {
    pub fn new(foundation: &mut impl Foundation) -> Option<Owner<Self>> {
        unsafe { PxPhysics::from_raw(physx_create_physics(foundation.as_mut_ptr())) }
    }

    /// # Safety
    /// Owner's own the pointer they wrap, using the pointer after dropping the Owner,
    /// or creating multiple Owners from the same pointer will cause UB.  Use `into_ptr` to
    /// retrieve the pointer and consume the Owner without dropping the pointee.
    pub(crate) unsafe fn from_raw(
        ptr: *mut physx_sys::PxPhysics,
    ) -> Option<Owner<PxPhysics<Geom>>> {
        Owner::from_raw(ptr as *mut PxPhysics<Geom>)
    }
}

impl<Geom: Shape> Drop for PxPhysics<Geom> {
    fn drop(&mut self) {
        unsafe {
            // should materials and shapes be dropped here? PxPhysics seems to be their owner.
            PxPhysics_release_mut(self.as_mut_ptr());
        }
    }
}

unsafe impl<T, Geom: Shape> Class<T> for PxPhysics<Geom>
where
    physx_sys::PxPhysics: Class<T>,
{
    fn as_ptr(&self) -> *const T {
        self.obj.as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut T {
        self.obj.as_mut_ptr()
    }
}

unsafe impl<Geom: Shape + Send> Send for PxPhysics<Geom> {}
unsafe impl<Geom: Shape + Sync> Sync for PxPhysics<Geom> {}

impl<Geom: Shape> Physics for PxPhysics<Geom> {
    type Shape = Geom;
}

pub trait Physics: Class<physx_sys::PxPhysics> + Sized {
    type Shape: Shape;

    fn create<Desc: Descriptor<Self>>(&mut self, desc: Desc) -> Desc::Target {
        desc.create(self)
    }

    /// Create a new scene with from a descriptor.
    #[allow(clippy::type_complexity)]
    fn create_scene<U, L, S, D, T, C, OC, OT, OCB, OWS, OA>(
        &mut self,
        scene_descriptor: SceneDescriptor<U, L, S, D, T, C, OC, OT, OCB, OWS, OA>,
    ) -> Option<Owner<PxScene<U, L, S, D, T, C, OC, OT, OCB, OWS, OA>>>
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
        scene_descriptor.create(self)
    }

    /// Create a new aggregate.  Must be added to a scene with the same actor user data types.
    #[allow(clippy::type_complexity)]
    fn create_aggregate<L, S, D, T, C>(
        &mut self,
        max_size: u32,
        self_collision: bool,
    ) -> Option<Owner<PxAggregate<L, S, D, T, C>>>
    where
        L: ArticulationLink,
        S: RigidStatic,
        D: RigidDynamic,
        T: Articulation,
        C: ArticulationReducedCoordinate,
    {
        unsafe {
            Aggregate::from_raw(PxPhysics_createAggregate_mut(
                self.as_mut_ptr(),
                max_size,
                self_collision,
            ))
        }
    }

    /// Create a new articulation.  Must be added to a scene with the same user data types.
    fn create_articulation<U, L: ArticulationLink>(
        &mut self,
        user_data: U,
    ) -> Option<Owner<PxArticulation<U, L>>> {
        unsafe {
            PxArticulation::from_raw(
                PxPhysics_createArticulation_mut(self.as_mut_ptr()),
                user_data,
            )
        }
    }

    /// Create a new articulation.  Must be added to a scene with the same user data types.
    fn create_articulation_reduced_coordinate<U, L: ArticulationLink>(
        &mut self,
        user_data: U,
    ) -> Option<Owner<PxArticulationReducedCoordinate<U, L>>> {
        unsafe {
            PxArticulationReducedCoordinate::from_raw(
                PxPhysics_createArticulationReducedCoordinate_mut(self.as_mut_ptr()),
                user_data,
            )
        }
    }

    /// Create a new BVH structure.  The BVH structure class-trait is not implemented yet.
    fn create_bvh_structure(&mut self, stream: &mut PxInputStream) -> Option<Owner<BvhStructure>> {
        unsafe {
            BvhStructure::from_raw(PxPhysics_createBVHStructure_mut(self.as_mut_ptr(), stream))
        }
    }

    /// Create a new constraint.  The constraint class-trait is not implemented yet.
    fn create_constraint(
        &mut self,
        first_actor: &mut impl RigidActor,
        second_actor: &mut impl RigidActor,
        connector: &mut PxConstraintConnector,
        shaders: &PxConstraintShaderTable,
        data_size: u32,
    ) -> Option<Owner<Constraint>> {
        unsafe {
            Constraint::from_raw(PxPhysics_createConstraint_mut(
                self.as_mut_ptr(),
                first_actor.as_mut_ptr(),
                second_actor.as_mut_ptr(),
                connector,
                shaders,
                data_size,
            ))
        }
    }

    /// Create a new convex mesh.  The convex mesh class-trait is not implemented yet.
    fn create_convex_mesh(&mut self, stream: &mut PxInputStream) -> Option<Owner<ConvexMesh>> {
        unsafe { ConvexMesh::from_raw(PxPhysics_createConvexMesh_mut(self.as_mut_ptr(), stream)) }
    }

    /// Create a new height field.
    fn create_height_field(&mut self, stream: &mut PxInputStream) -> Option<Owner<HeightField>> {
        unsafe { HeightField::from_raw(PxPhysics_createHeightField_mut(self.as_mut_ptr(), stream)) }
    }

    /// Create a new material with ref count set to one.
    fn create_material(
        &mut self,
        static_friction: f32,
        dynamic_friction: f32,
        restitution: f32,
        user_data: <<Self::Shape as Shape>::Material as UserData>::UserData,
    ) -> Option<Owner<<Self::Shape as Shape>::Material>> {
        unsafe {
            Material::from_raw(
                PxPhysics_createMaterial_mut(
                    self.as_mut_ptr(),
                    static_friction,
                    dynamic_friction,
                    restitution,
                ),
                user_data,
            )
        }
    }

    /// Create a new pruning structure.  The pruning structure class-trait is not implemented yet.
    fn create_pruning_structure(
        &mut self,
        actors: Vec<&mut impl RigidActor>,
    ) -> Option<Owner<PruningStructure>> {
        unsafe {
            PruningStructure::from_raw(PxPhysics_createPruningStructure_mut(
                self.as_mut_ptr(),
                actors.as_ptr() as *const *mut _,
                actors.len() as u32,
            ))
        }
    }

    /// Create a dynamic actor with given transform and user data.  Other fields are initialized
    /// to their defaults.
    fn create_dynamic<U>(
        &mut self,
        transform: &PxTransform,
        user_data: U,
    ) -> Option<Owner<PxRigidDynamic<U, Self::Shape>>> {
        unsafe {
            PxRigidDynamic::from_raw(
                PxPhysics_createRigidDynamic_mut(self.as_mut_ptr(), transform.as_ptr()),
                user_data,
            )
        }
    }

    /// Create a static actor with given transform and user data.  Other fields are initialized
    /// to their defaults.
    fn create_static<U>(
        &mut self,
        transform: PxTransform,
        user_data: U,
    ) -> Option<Owner<PxRigidStatic<U, Self::Shape>>> {
        unsafe {
            PxRigidStatic::from_raw(
                PxPhysics_createRigidStatic_mut(self.as_mut_ptr(), transform.as_ptr()),
                user_data,
            )
        }
    }

    /// Create a new shape.
    fn create_shape(
        &mut self,
        geometry: &impl Geometry,
        materials: &mut [&mut <Self::Shape as Shape>::Material],
        is_exclusive: bool,
        shape_flags: ShapeFlags,
        user_data: <Self::Shape as UserData>::UserData,
    ) -> Option<Owner<Self::Shape>> {
        unsafe {
            Shape::from_raw(
                PxPhysics_createShape_mut_1(
                    self.as_mut_ptr(),
                    geometry.as_ptr(),
                    materials.as_ptr() as *const *mut _,
                    materials.len() as u16,
                    is_exclusive,
                    shape_flags.into_px(),
                ),
                user_data,
            )
        }
    }

    /// Create a new pruning structure.  The pruning structure class-trait is not implemented yet.
    fn create_triangle_mesh(&mut self, stream: &mut PxInputStream) -> Option<Owner<TriangleMesh>> {
        unsafe {
            TriangleMesh::from_raw(PxPhysics_createTriangleMesh_mut(self.as_mut_ptr(), stream))
        }
    }

    /// Create a new rigid dynamic actor.
    fn create_rigid_dynamic<U>(
        &mut self,
        transform: PxTransform,
        geometry: &impl Geometry,
        material: &mut <Self::Shape as Shape>::Material,
        density: f32,
        shape_transform: PxTransform,
        user_data: U,
    ) -> Option<Owner<PxRigidDynamic<U, Self::Shape>>> {
        RigidDynamic::new(
            self,
            transform,
            geometry,
            material,
            density,
            shape_transform,
            user_data,
        )
    }

    /// Create a new rigid static actor.
    fn create_rigid_static<U>(
        &mut self,
        transform: PxTransform,
        geometry: &impl Geometry,
        material: &mut <Self::Shape as Shape>::Material,
        shape_transform: PxTransform,
        user_data: U,
    ) -> Option<Owner<PxRigidStatic<U, Self::Shape>>> {
        RigidStatic::new(
            self,
            transform,
            geometry,
            material,
            shape_transform,
            user_data,
        )
    }

    /// Create a plane, with plane equation `normal`.dot(v) + `offset` = 0.
    fn create_plane<U>(
        &mut self,
        normal: PxVec3,
        offset: f32,
        material: &mut <Self::Shape as Shape>::Material,
        user_data: U,
    ) -> Option<Owner<PxRigidStatic<U, Self::Shape>>> {
        unsafe {
            RigidStatic::from_raw(
                physx_sys::phys_PxCreatePlane(
                    self.as_mut_ptr(),
                    &physx_sys::PxPlane_new_2(normal.as_ptr(), offset),
                    material.as_mut_ptr(),
                ),
                user_data,
            )
        }
    }

    /// Get the BVH structures created by this physics object.
    fn get_bvh_structures(&self) -> Vec<&BvhStructure> {
        unsafe {
            let capacity = PxPhysics_getNbBVHStructures(self.as_ptr());
            let mut buffer: Vec<&BvhStructure> = Vec::with_capacity(capacity as usize);
            let len = PxPhysics_getBVHStructures(
                self.as_ptr(),
                buffer.as_mut_ptr() as *mut *mut _,
                capacity,
                0,
            );
            buffer.set_len(len as usize);
            buffer
        }
    }

    /// Get the convex meshes created by this physics object.
    fn get_convex_meshes(&self) -> Vec<&ConvexMesh> {
        unsafe {
            let capacity = PxPhysics_getNbConvexMeshes(self.as_ptr());
            let mut buffer: Vec<&ConvexMesh> = Vec::with_capacity(capacity as usize);
            let len = PxPhysics_getConvexMeshes(
                self.as_ptr(),
                buffer.as_mut_ptr() as *mut *mut _,
                capacity,
                0,
            );
            buffer.set_len(len as usize);
            buffer
        }
    }

    /// Get the height fields created by this physics object.
    fn get_height_fields(&self) -> Vec<&HeightField> {
        unsafe {
            let capacity = PxPhysics_getNbHeightFields(self.as_ptr());
            let mut buffer: Vec<&HeightField> = Vec::with_capacity(capacity as usize);
            let len = PxPhysics_getHeightFields(
                self.as_ptr(),
                buffer.as_mut_ptr() as *mut *mut _,
                capacity,
                0,
            );
            buffer.set_len(len as usize);
            buffer
        }
    }

    /// Get the height fields created by this physics object.
    fn get_materials(&self) -> Vec<&<Self::Shape as Shape>::Material> {
        unsafe {
            let capacity = PxPhysics_getNbMaterials(self.as_ptr());
            let mut buffer: Vec<&<Self::Shape as Shape>::Material> =
                Vec::with_capacity(capacity as usize);
            let len = PxPhysics_getMaterials(
                self.as_ptr(),
                buffer.as_mut_ptr() as *mut *mut _,
                capacity,
                0,
            );
            buffer.set_len(len as usize);
            buffer
        }
    }

    /// Get the shapes created by this physics object.
    fn get_shapes(&self) -> Vec<&Self::Shape> {
        unsafe {
            let capacity = PxPhysics_getNbShapes(self.as_ptr());
            let mut buffer: Vec<&Self::Shape> = Vec::with_capacity(capacity as usize);
            let len = PxPhysics_getShapes(
                self.as_ptr(),
                buffer.as_mut_ptr() as *mut *mut _,
                capacity,
                0,
            );
            buffer.set_len(len as usize);
            buffer
        }
    }

    /// Get the triangle mesghes created by this object.
    fn get_triangle_meshes(&self) -> Vec<&TriangleMesh> {
        unsafe {
            let capacity = PxPhysics_getNbTriangleMeshes(self.as_ptr());
            let mut buffer: Vec<&TriangleMesh> = Vec::with_capacity(capacity as usize);
            let len = PxPhysics_getTriangleMeshes(
                self.as_ptr(),
                buffer.as_mut_ptr() as *mut *mut _,
                capacity,
                0,
            );
            buffer.set_len(len as usize);
            buffer
        }
    }

    /// Get the tolerance scale.
    fn get_tolerances_scale(&self) -> Option<&PxTolerancesScale> {
        unsafe { PxPhysics_getTolerancesScale(self.as_ptr()).as_ref() }
    }

    /// Get the physics insertion callback, used for real-time cooking of physics meshes.
    fn get_physics_insertion_callback(&mut self) -> Option<&mut PxPhysicsInsertionCallback> {
        unsafe { PxPhysics_getPhysicsInsertionCallback_mut(self.as_mut_ptr()).as_mut() }
    }
}

pub struct PhysicsFoundationBuilder<Allocator: AllocatorCallback> {
    tolerances: PxTolerancesScale,
    enable_pvd: bool,
    pvd_port: i32,
    pvd_remote: Option<String>,
    load_extensions: bool,
    allocator: Allocator,
    error_callback: Option<*mut PxErrorCallback>,
}

impl Default for PhysicsFoundationBuilder<DefaultAllocator> {
    fn default() -> Self {
        let mut tolerances = unsafe { PxTolerancesScale_new() };
        tolerances.length = 1.0;

        Self {
            tolerances,
            enable_pvd: false,
            pvd_port: 5425,
            pvd_remote: None,
            load_extensions: false,
            allocator: DefaultAllocator,
            error_callback: None,
        }
    }
}

impl<Allocator: AllocatorCallback> PhysicsFoundationBuilder<Allocator> {
    pub fn new(allocator: Allocator) -> Self {
        let mut tolerances = unsafe { PxTolerancesScale_new() };
        tolerances.length = 1.0;

        Self {
            tolerances,
            enable_pvd: false,
            pvd_port: 5425,
            pvd_remote: None,
            load_extensions: false,
            allocator,
            error_callback: None,
        }
    }

    pub fn enable_visual_debugger(&mut self, enable: bool) -> &mut Self {
        self.enable_pvd = enable;
        self
    }

    /// Set the port number for the visual debuggers transport.  Default is 5425.
    pub fn set_pvd_port(&mut self, pvd_port: i32) -> &mut Self {
        self.pvd_port = pvd_port;
        self
    }

    /// Set the port number for the visual debuggers transport.  Default is 5425.
    pub fn set_pvd_host(&mut self, pvd_host: impl Into<String>) -> &mut Self {
        self.pvd_remote = Some(pvd_host.into());
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

    /// Enable or disable extensions.  Default is `false`.
    pub fn with_extensions(&mut self, load: bool) -> &mut Self {
        self.load_extensions = load;
        self
    }

    pub fn with_error_callback<EC: ErrorCallback>(&mut self, error_callback: EC) -> &mut Self {
        self.error_callback = unsafe { Some(error_callback.into_px()) };
        self
    }

    /// Build the PhysicsFoundation.
    pub fn build<Geom: Shape>(self) -> Option<PhysicsFoundation<Allocator, Geom>> {
        let mut foundation = if let Some(callback) = self.error_callback {
            unsafe { PxFoundation::with_allocator_error_callback(self.allocator, callback)? }
        } else {
            PxFoundation::new(self.allocator)?
        };
        let (mut pvd, mut physics) = unsafe {
            if self.enable_pvd {
                if !self.load_extensions {
                    log::warn!("Enabling PVD without extensions can lead to PVD crashing. Considering called `PhysicsFoundationBuilder::with_extensions(true). See https://github.com/NVIDIAGameWorks/PhysX/issues/306 for more info.");
                }

                let mut pvd = if let Some(remote) = self.pvd_remote {
                    VisualDebugger::new_remote(foundation.as_mut(), &remote, self.pvd_port)?
                } else {
                    VisualDebugger::new(foundation.as_mut(), self.pvd_port)?
                };
                let physics = PxPhysics::from_raw(phys_PxCreatePhysics(
                    PX_PHYSICS_VERSION,
                    foundation.as_mut_ptr(),
                    &self.tolerances as *const _,
                    true,
                    pvd.as_mut_ptr(),
                ))?;

                (Some(pvd), physics)
            } else {
                (None, PxPhysics::new(foundation.as_mut())?)
            }
        };

        let extensions_loaded = if self.load_extensions {
            unsafe {
                phys_PxInitExtensions(
                    physics.as_mut_ptr(),
                    pvd.as_mut().map_or_else(null_mut, |pv| pv.as_mut_ptr()),
                )
            }
        } else {
            false
        };

        Some(PhysicsFoundation {
            physics,
            pvd,
            foundation,
            extensions_loaded,
        })
    }
}
