// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created:  2 April 2019

/*!
Wrapper interface for Physics
 */

#![allow(clippy::not_unsafe_ptr_arg_deref)]
#![allow(clippy::missing_safety_doc)]

use crate::{
    aggregate::Aggregate,
    articulation::Articulation,
    articulation_reduced_coordinate::ArticulationReducedCoordinate,
    bvh_structure::BVHStructure,
    constraint::Constraint,
    convex_mesh::ConvexMesh,
    foundation::{DefaultAllocator, Foundation},
    geometry::Geometry,
    height_field::HeightField,
    material::Material,
    math::{PxTransform, PxVec3},
    owner::Owner,
    pruning_structure::PruningStructure,
    rigid_actor::RigidActor,
    rigid_dynamic::RigidDynamic,
    rigid_static::RigidStatic,
    scene::{Scene, SceneDescriptor},
    shape::{Shape, ShapeFlags},
    traits::{Class, PxFlags},
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
    physx_create_physics, // TODO remove this? it just calls through to PxCreatePhysics
    FilterShaderCallbackInfo,
    PxConstraintConnector,
    PxConstraintShaderTable,
    PxFilterFlag,
    // TODO write wrappers and import from them instead
    PxInputStream,
    PxPairFlag,
    PxPhysicsInsertionCallback,
    // TODO unify creation into `fn create<D: Descriptor<T>>(descriptor: &D) -> Option<&mut T>`
    // or `fn create<T>(descriptor: Descriptor<T>) -> Option<&mut T>`
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
    PxPhysics_createScene_mut,
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
    PxPhysics_getNbScenes,
    PxPhysics_getNbShapes,
    PxPhysics_getNbTriangleMeshes,
    PxPhysics_getPhysicsInsertionCallback_mut,
    PxPhysics_getScenes,
    PxPhysics_getShapes,
    PxPhysics_getTolerancesScale,
    PxPhysics_getTriangleMeshes,
    PxPhysics_release_mut,
    //PxPhysics_registerDeletionListener_mut,
    //PxPhysics_registerDeletionListenerObjects_mut,
    //PxPhysics_unregisterDeletionListener_mut,
    //PxPhysics_unregisterDeletionListenerObjects_mut,
    //PxPhysics_getFoundation_mut, // probably not necessary? also sketch wrt obrm
    // PxPhysics_createShape_mut, PxPhysics_createShape_mut_1 is the same but more
    // TODO move PxTolerancesScale, callbacks and ContactPair stuff to their own files?
    PxTolerancesScale,
    PxTolerancesScale_new,
};

pub const PX_PHYSICS_VERSION: u32 = crate::version(4, 1, 1);

/*
#[no_mangle]
pub extern "C" fn on_contact_callback(
    _userdata: *mut std::ffi::c_void,
    _header: *const PxContactPairHeader,
    _pairs: *const PxContactPair,
    _count: u32,
) {
    // TODO rewrite this so it's calling a function pointer on the Scene
    // or passed in via the SceneDescriptor or something.  This must to be exposed! (The truth is out there!)
    unsafe {
        if let Some(header) = header.as_ref() {
            let actors = [
                &mut*header.actors[0],
                &mut*header.actors[1]
            ];
            let pairs = std::slice::from_raw_parts(pairs, count as usize);
            //scene.collide_pair(actors, pairs);
        }
    }
}
*/

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

pub struct PhysicsFoundation<H, M> {
    pub physics: Owner<Physics<H, M>>,
    pub pvd: Option<VisualDebugger>,
    pub foundation: Owner<Foundation>,
    extensions_loaded: bool,
}

impl<H, M> Default for PhysicsFoundation<H, M> {
    fn default() -> Self {
        let mut foundation = Foundation::new::<DefaultAllocator>()
            .expect("Create Foundation returned a null pointer");
        let physics =
            Physics::new(foundation.as_mut()).expect("Create Physics returned a null pointer.");
        Self {
            foundation,
            physics,
            pvd: None,
            extensions_loaded: false,
        }
    }
}

impl<H, M> Drop for PhysicsFoundation<H, M> {
    fn drop(&mut self) {
        if self.extensions_loaded {
            unsafe {
                phys_PxCloseExtensions();
            }
        };
    }
}

impl<H, M> PhysicsFoundation<H, M> {
    pub fn create() -> PhysicsFoundationBuilder {
        PhysicsFoundationBuilder::default()
    }

    pub fn physics(&mut self) -> &mut Physics<H, M> {
        self.physics.as_mut()
    }
}

#[repr(transparent)]
pub struct Physics<H, M> {
    obj: physx_sys::PxPhysics,
    phantom_user_data: PhantomData<(H, M)>,
}

unsafe impl<T, H, M> Class<T> for Physics<H, M>
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

unsafe impl<H: Send, M: Send> Send for Physics<H, M> {}
unsafe impl<H: Sync, M: Sync> Sync for Physics<H, M> {}

impl<H, M> Drop for Physics<H, M> {
    fn drop(&mut self) {
        unsafe {
            PxPhysics_release_mut(self.as_mut_ptr());
        }
    }
}

impl<H, M> Physics<H, M> {
    pub fn new(foundation: &mut Foundation) -> Option<Owner<Self>> {
        unsafe { Physics::from_raw(physx_create_physics(foundation.as_mut_ptr())) }
    }

    pub(crate) unsafe fn from_raw(ptr: *mut physx_sys::PxPhysics) -> Option<Owner<Physics<H, M>>> {
        Owner::from_raw(ptr as *mut Physics<H, M>)
    }

    /// Create a new scene with from a descriptor and user data types.
    /// The type parameeters and their px type, in order:
    /// <U: Scene, L: ArticulationLink, S: RigidStatic, >
    pub fn create_scene<E, L, S, D, T, C>(
        &mut self,
        scene_descriptor: SceneDescriptor<E, L, S, D, T, C>,
    ) -> Option<Owner<Scene<E, L, S, D, M, H, T, C>>> {
        let desc = scene_descriptor.into_desc(self);
        unsafe { Scene::from_raw(PxPhysics_createScene_mut(self.as_mut_ptr(), &desc)) }
    }

    pub fn create_aggregate<L, S, D>(
        &mut self,
        max_size: u32,
        self_collision: bool,
    ) -> Option<Owner<Aggregate<L, S, D, H, M>>> {
        unsafe {
            Aggregate::from_raw(PxPhysics_createAggregate_mut(
                self.as_mut_ptr(),
                max_size,
                self_collision,
            ))
        }
    }

    pub fn create_articulation<U, L>(
        &mut self,
        user_data: U,
    ) -> Option<Owner<Articulation<U, L, H, M>>> {
        unsafe {
            Articulation::from_raw(
                PxPhysics_createArticulation_mut(self.as_mut_ptr()),
                user_data,
            )
        }
    }

    pub fn create_articulation_reduced_coordiante<U, L>(
        &mut self,
        user_data: U,
    ) -> Option<Owner<ArticulationReducedCoordinate<U, L, H, M>>> {
        unsafe {
            ArticulationReducedCoordinate::from_raw(
                PxPhysics_createArticulationReducedCoordinate_mut(self.as_mut_ptr()),
                user_data,
            )
        }
    }

    /// Missing BVHStructure trait
    pub fn create_bvh_structure(
        &mut self,
        stream: &mut PxInputStream,
    ) -> Option<Owner<BVHStructure>> {
        unsafe {
            BVHStructure::from_raw(PxPhysics_createBVHStructure_mut(self.as_mut_ptr(), stream))
        }
    }

    /// Missing Constraint trait
    pub fn create_constraint(
        &mut self,
        first_actor: &mut impl RigidActor<H, M>,
        second_actor: &mut impl RigidActor<H, M>,
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

    /// Missing ConvexMesh trait
    pub fn create_convex_mesh(&mut self, stream: &mut PxInputStream) -> Option<Owner<ConvexMesh>> {
        unsafe { ConvexMesh::from_raw(PxPhysics_createConvexMesh_mut(self.as_mut_ptr(), stream)) }
    }

    pub fn create_height_field(
        &mut self,
        stream: &mut PxInputStream,
    ) -> Option<Owner<HeightField>> {
        unsafe { HeightField::from_raw(PxPhysics_createHeightField_mut(self.as_mut_ptr(), stream)) }
    }

    pub fn create_material(
        &mut self,
        static_friction: f32,
        dynamic_friction: f32,
        restitution: f32,
        user_data: M,
    ) -> Option<Owner<Material<M>>> {
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

    /// Missing PruningStructure impl
    pub fn create_pruning_structure(
        &mut self,
        actors: Vec<&mut impl RigidActor<H, M>>,
    ) -> Option<Owner<PruningStructure>> {
        unsafe {
            PruningStructure::from_raw(PxPhysics_createPruningStructure_mut(
                self.as_mut_ptr(),
                actors.as_ptr() as *const *mut _,
                actors.len() as u32,
            ))
        }
    }

    pub fn create_dynamic<U>(
        &mut self,
        transform: &PxTransform,
        user_data: U,
    ) -> Option<Owner<RigidDynamic<U, H, M>>> {
        unsafe {
            RigidDynamic::from_raw(
                PxPhysics_createRigidDynamic_mut(self.as_mut_ptr(), transform.as_ptr()),
                user_data,
            )
        }
    }

    pub fn create_static<U>(
        &mut self,
        transform: PxTransform,
        user_data: U,
    ) -> Option<Owner<RigidStatic<U, H, M>>> {
        unsafe {
            RigidStatic::from_raw(
                PxPhysics_createRigidStatic_mut(self.as_mut_ptr(), transform.as_ptr()),
                user_data,
            )
        }
    }

    pub fn create_shape<U>(
        &mut self,
        geometry: &impl Geometry,
        materials: &[&mut Material<M>],
        is_exclusive: bool,
        shape_flags: ShapeFlags,
        user_data: U,
    ) -> Option<Owner<Shape<U, M>>> {
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

    /// Missing TriangleMesh impl
    pub fn create_triangle_mesh(
        &mut self,
        stream: &mut PxInputStream,
    ) -> Option<Owner<TriangleMesh>> {
        unsafe {
            TriangleMesh::from_raw(PxPhysics_createTriangleMesh_mut(self.as_mut_ptr(), stream))
        }
    }

    pub fn create_rigid_dynamic<U>(
        &mut self,
        transform: PxTransform,
        geometry: &impl Geometry,
        material: &mut Material<M>,
        density: f32,
        shape_transform: PxTransform,
        user_data: U,
    ) -> Option<Owner<RigidDynamic<U, H, M>>> {
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

    pub fn create_rigid_static<U>(
        &mut self,
        transform: PxTransform,
        geometry: &impl Geometry,
        material: &mut Material<M>,
        shape_transform: PxTransform,
        user_data: U,
    ) -> Option<Owner<RigidStatic<U, H, M>>> {
        RigidStatic::new(
            self,
            transform,
            geometry,
            material,
            shape_transform,
            user_data,
        )
    }

    pub fn create_plane<U>(
        &mut self,
        normal: PxVec3,
        offset: f32,
        material: &mut Material<M>,
        user_data: U,
    ) -> Option<Owner<RigidStatic<U, H, M>>> {
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

    pub fn get_bvh_structures(&self) -> Vec<&BVHStructure> {
        unsafe {
            let capacity = PxPhysics_getNbBVHStructures(self.as_ptr());
            let mut buffer: Vec<&BVHStructure> = Vec::with_capacity(capacity as usize);
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

    pub fn get_convex_meshes(&self) -> Vec<&ConvexMesh> {
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

    pub fn get_height_fields(&self) -> Vec<&HeightField> {
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

    pub fn get_materials(&self) -> Vec<&Material<M>> {
        unsafe {
            let capacity = PxPhysics_getNbMaterials(self.as_ptr());
            let mut buffer: Vec<&Material<M>> = Vec::with_capacity(capacity as usize);
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

    /// Safety: Scenes may have different user data type parameters, and this method is happy
    /// to perform a cast to whatever type it is told to without regard for safety.  Either
    /// set them all to () so they can't be used, or pass in the appriopriate types for the desired scene.
    /// If possible, store the scenes separately so that type info is not lost.
    // TODO should this type info just be part of Physics? I think creating scenes with different
    // user data types could prove useful, and getting rid of this may be a batter approach.
    pub unsafe fn get_scenes<U, L, S, D, T, C>(&self) -> Vec<&Scene<U, L, S, D, M, H, T, C>> {
        //unsafe
        {
            let capacity = PxPhysics_getNbScenes(self.as_ptr());
            let mut buffer: Vec<&Scene<U, L, S, D, M, H, T, C>> =
                Vec::with_capacity(capacity as usize);
            let len = PxPhysics_getScenes(
                self.as_ptr(),
                buffer.as_mut_ptr() as *mut *mut _,
                capacity,
                0,
            );
            buffer.set_len(len as usize);
            buffer
        }
    }

    pub fn get_shapes(&self) -> Vec<&Shape<H, M>> {
        unsafe {
            let capacity = PxPhysics_getNbShapes(self.as_ptr());
            let mut buffer: Vec<&Shape<H, M>> = Vec::with_capacity(capacity as usize);
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

    pub fn get_triangle_meshes(&self) -> Vec<&TriangleMesh> {
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

    pub fn get_tolerances_scale(&self) -> Option<&PxTolerancesScale> {
        unsafe { PxPhysics_getTolerancesScale(self.as_ptr()).as_ref() }
    }

    pub fn get_physics_insertion_callback(&mut self) -> Option<&mut PxPhysicsInsertionCallback> {
        unsafe { PxPhysics_getPhysicsInsertionCallback_mut(self.as_mut_ptr()).as_mut() }
    }
}

pub struct PhysicsFoundationBuilder {
    tolerances: PxTolerancesScale,
    enable_pvd: bool,
    pvd_port: i32,
    load_extensions: bool,
}

impl Default for PhysicsFoundationBuilder {
    fn default() -> Self {
        let mut tolerances = unsafe { PxTolerancesScale_new() };
        tolerances.length = 1.0;

        Self {
            tolerances,
            enable_pvd: false,
            pvd_port: 5425,
            load_extensions: false,
        }
    }
}

impl PhysicsFoundationBuilder {
    pub fn enable_visual_debugger(&mut self, enable: bool) -> &mut Self {
        self.enable_pvd = enable;
        self
    }

    /// Set the port number for the visual debuggers transport.  Default is 5425.
    pub fn set_pvd_port(&mut self, pvd_port: i32) -> &mut Self {
        self.pvd_port = pvd_port;
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

    pub fn build<H, M>(
        &self,
        mut foundation: Owner<Foundation>,
    ) -> Option<PhysicsFoundation<H, M>> {
        let (mut pvd, mut physics) = unsafe {
            if self.enable_pvd {
                let mut pvd = VisualDebugger::new(foundation.as_mut(), self.pvd_port)?;

                let physics = Physics::from_raw(phys_PxCreatePhysics(
                    PX_PHYSICS_VERSION,
                    foundation.as_mut_ptr(),
                    &self.tolerances as *const _,
                    true,
                    pvd.as_mut_ptr(),
                ))?;

                (Some(pvd), physics)
            } else {
                (None, Physics::new(foundation.as_mut())?)
            }
        };

        let extensions_loaded = if self.load_extensions {
            unsafe {
                phys_PxInitExtensions(
                    physics.as_mut_ptr(),
                    pvd.as_mut()
                        .map(|pv| pv.as_mut_ptr())
                        .unwrap_or_else(null_mut),
                )
            }
        } else {
            false
        };

        Some(PhysicsFoundation {
            foundation,
            physics,
            pvd,
            extensions_loaded,
        })
    }
}
