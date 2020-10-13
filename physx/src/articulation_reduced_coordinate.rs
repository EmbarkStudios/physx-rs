// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 10 April 2019

#![warn(clippy::all)]

/*!
ArticulationReducedCoordinate wrapper for PhysX.
 */

use super::{
    articulation_base::ArticulationBase,
    articulation_cache::{ArticulationCache, ArticulationCacheFlag},
    articulation_link::*,
    body::*,
    cooking::*,
    physics::Physics,
    px_type::*,
    shape::CollisionLayer,
    traits::*,
    transform::*,
    user_data::UserData,
};
use enumflags2::BitFlags;
use glam::{Mat4, Vec3};
use physx_macros::*;
use physx_sys::*;
use std::ptr::{null, null_mut};

/*******************************************************************************
 * Section FLAGS                                                               *
 ******************************************************************************/

#[repr(u8)]
pub enum ArticulationFlag {
    FixBase = 1,
}

impl Into<PxArticulationFlag::Enum> for ArticulationFlag {
    fn into(self) -> PxArticulationFlag::Enum {
        self as _
    }
}

impl ToFlags<PxArticulationFlags> for ArticulationFlag {
    fn to_flags(self) -> PxArticulationFlags {
        PxArticulationFlags { mBits: self as _ }
    }
}

/*******************************************************************************
 * Section ARTICULATION                                                        *
 ******************************************************************************/

////////////////////////////////////////////////////////////////////////////////

#[physx_type(inherit = "ArticulationBase")]
impl ArticulationReducedCoordinate {
    /// Construct a new multibody with a fixed root
    pub fn new(world: &mut Physics) -> Self {
        let articulation =
            unsafe { PxPhysics_createArticulationReducedCoordinate_mut(world.physics) };

        let root_raw_link = unsafe {
            PxArticulationBase_createLink_mut(
                articulation as *mut PxArticulationBase,
                null_mut(),
                &px_identity_tf(),
            )
        };

        let mut root_link = ArticulationLink::new(root_raw_link);
        if let UserData::RigidActor(data) = root_link.user_data_mut() {
            data.name = String::from("noname")
        }

        let mut _self = Self { ptr: articulation };
        _self.allocate_user_data();
        _self
    }

    /// Create a new multibody, using data from builder to construct the root link
    pub fn new_with_link(
        builder: &ArticulationLinkBuilder,
        physics: &mut Physics,
        cooking: &mut Cooking,
    ) -> Self {
        let articulation =
            unsafe { PxPhysics_createArticulationReducedCoordinate_mut(physics.get_raw_mut()) };

        let parent_quat = builder.parent_rotation;

        let transform = Mat4::from_rotation_translation(parent_quat, builder.parent_offset);
        let root_raw_link = unsafe {
            PxArticulationBase_createLink_mut(
                articulation as *mut PxArticulationBase,
                null_mut(),
                &gl_to_px_tf(transform),
            )
        };

        let mut link = ArticulationLink::new(root_raw_link);
        if let UserData::RigidActor(data) = link.user_data_mut() {
            data.name = builder.name.clone()
        }

        if let Some(ref collider) = builder.collider {
            let geometry = cooking.make_geometry(collider.clone());
            link.create_exclusive_shape(geometry, Mat4::identity(), Mat4::identity());
        }

        let mut _self = Self { ptr: articulation };
        _self.allocate_user_data();
        _self.add_link(link);
        _self
    }

    #[inline]
    /// Retrieve a handle for this body
    pub fn handle(&self) -> BodyHandle {
        BodyHandle(self.ptr as usize)
    }

    #[inline]
    /// Retrieve a handle for the root link of this body
    pub fn root_handle(&self) -> PartHandle {
        PartHandle(self.ptr as usize, self.links()[0].handle().1)
    }

    #[inline]
    /// Retrieve the root link of this body
    pub fn root(&self) -> &ArticulationLink {
        &self.links()[0]
    }

    #[inline]
    /// Mutably retrieve the root link of this body
    pub fn root_mut(&mut self) -> &mut ArticulationLink {
        &mut self.links_mut()[0]
    }

    #[inline]
    /// Retrieve part by index
    pub fn part(&self, part: usize) -> Option<&ArticulationLink> {
        self.links().get(part)
    }

    #[inline]
    /// Retrieve part by index
    pub fn part_mut(&mut self, part: usize) -> Option<&mut ArticulationLink> {
        self.links_mut().get_mut(part)
    }

    #[inline]
    /// Retrieve part by handle
    pub fn part_from_handle(&self, handle: PartHandle) -> Option<&ArticulationLink> {
        self.iter_links().find(|link| link.handle() == handle)
    }

    #[inline]
    /// Retrieve part by handle
    pub fn part_from_handle_mut(&mut self, handle: PartHandle) -> Option<&mut ArticulationLink> {
        self.iter_links_mut().find(|link| link.handle() == handle)
    }

    ////////////////////////////////////////////////////////////////////////////////
    // Section PASSTHROUGH
    ////////////////////////////////////////////////////////////////////////////////

    #[inline]
    pub fn common_init(&mut self) {
        unsafe {
            PxArticulationReducedCoordinate_commonInit(self.get_raw());
        }
    }

    #[inline]
    /// Get the number of dofs for the body
    pub fn get_dofs(&self) -> usize {
        unsafe { PxArticulationReducedCoordinate_getDofs(self.get_raw()) as usize }
    }

    #[inline]
    /// Set an articulation flag
    pub fn set_articulation_flag(&mut self, flag: ArticulationFlag, value: bool) {
        unsafe {
            PxArticulationReducedCoordinate_setArticulationFlag_mut(
                self.get_raw_mut(),
                flag.into(),
                value,
            );
        }
    }

    #[inline]
    /// Set the articulation flags
    pub fn set_articulation_flags(&mut self, flag: ArticulationFlag) {
        unsafe {
            PxArticulationReducedCoordinate_setArticulationFlags_mut(
                self.get_raw_mut(),
                flag.to_flags(),
            );
        }
    }

    #[inline]
    /// Set the articulation flags
    pub fn get_articulation_flags(&self) {
        unsafe {
            PxArticulationReducedCoordinate_getArticulationFlags(self.get_raw());
        }
    }

    #[inline]
    /// Get the number of joints across the whole tree
    pub fn get_nb_joints(&self) -> usize {
        self.iter_links().fold(0, |accum, link| {
            accum + if link.inbound_joint().is_some() { 1 } else { 0 }
        })
    }
    //
    /// Get the pose of the body in the world
    pub fn global_pose(&self) -> Mat4 {
        self.root().get_global_pose()
    }

    /// Teleport the whole body to the transform and and orientation given by `Pose`
    pub fn teleport_to(&mut self, pose: Mat4) {
        // self.links[0].set_transform(pose);
        self.common_init();
        unsafe {
            PxArticulationReducedCoordinate_teleportRootLink_mut(
                self.get_raw_mut(),
                &gl_to_px_tf(pose),
                true,
            );
        }
    }

    ////////////////////////////////////////////////////////////////////////////////
    // Section CACHE
    ////////////////////////////////////////////////////////////////////////////////

    /// Create a new cache for this articulation
    pub fn create_cache(&self) -> ArticulationCache {
        let mut cache = ArticulationCache::new(unsafe {
            PxArticulationReducedCoordinate_createCache(self.get_raw())
        });
        cache.compute_dof_information(self);
        cache
    }

    /// Release the cache and free the memory
    pub fn release_cache(&self, mut cache: ArticulationCache) {
        unsafe { PxArticulationReducedCoordinate_releaseCache(self.get_raw(), cache.get_raw_mut()) }
    }

    /// Get the memory size of this cache
    pub fn get_cache_data_size(&self) -> u32 {
        unsafe { PxArticulationReducedCoordinate_getCacheDataSize(self.get_raw()) }
    }

    /// Zero everything in the cache
    pub fn zero_cache(&mut self, cache: &mut ArticulationCache) {
        unsafe {
            PxArticulationReducedCoordinate_zeroCache_mut(self.get_raw_mut(), cache.get_raw_mut())
        }
    }

    /// Apply the cache to the articulation
    pub fn apply_cache(
        &mut self,
        cache: &mut ArticulationCache,
        flag: BitFlags<ArticulationCacheFlag>,
        autowake: bool,
    ) {
        unsafe {
            PxArticulationReducedCoordinate_applyCache_mut(
                self.get_raw_mut(),
                cache.get_raw_mut(),
                flag.to_flags(),
                autowake,
            )
        }
    }

    /// Copy from the articulation to the cache based on the flags
    pub fn copy_internal_state_to_cache(
        &self,
        cache: &mut ArticulationCache,
        flag: BitFlags<ArticulationCacheFlag>,
    ) {
        unsafe {
            PxArticulationReducedCoordinate_copyInternalStateToCache(
                self.get_raw(),
                cache.get_raw_mut(),
                flag.to_flags(),
            )
        }
    }

    /// Compute generalized gravity forces acting upon the body and store in cache
    pub fn compute_generalized_gravity_force(&self, cache: &mut ArticulationCache) {
        unsafe {
            PxArticulationReducedCoordinate_computeGeneralizedGravityForce(
                self.get_raw(),
                cache.get_raw_mut(),
            )
        }
    }

    /// Compute the coriolis and centrifugal forces acting upon the multibody
    pub fn compute_coriolis_and_centrifugal_force(&self, cache: &mut ArticulationCache) {
        unsafe {
            PxArticulationReducedCoordinate_computeCoriolisAndCentrifugalForce(
                self.get_raw(),
                cache.get_raw_mut(),
            )
        }
    }

    /// Compute joint force changes caused by external forces
    pub fn compute_generalized_external_force(&self, cache: &mut ArticulationCache) {
        unsafe {
            PxArticulationReducedCoordinate_computeGeneralizedExternalForce(
                self.get_raw(),
                cache.get_raw_mut(),
            )
        }
    }

    /// Compute joint acceleration caused by current joint forces
    pub fn compute_joint_acceleration(&self, cache: &mut ArticulationCache) {
        unsafe {
            PxArticulationReducedCoordinate_computeJointAcceleration(
                self.get_raw(),
                cache.get_raw_mut(),
            )
        }
    }

    /// Compute joint force caused by changes in joint acceleration
    pub fn compute_joint_force(&self, cache: &mut ArticulationCache) {
        unsafe {
            PxArticulationReducedCoordinate_computeJointForce(self.get_raw(), cache.get_raw_mut())
        }
    }

    /// Compute dense jacobian and store into the cache.
    /// Returns: (cols, rows)
    pub fn compute_dense_jacobian(&self, cache: &mut ArticulationCache) -> (u32, u32) {
        let mut rows = 0;
        let mut cols = 0;
        unsafe {
            PxArticulationReducedCoordinate_computeDenseJacobian(
                self.get_raw(),
                cache.get_raw_mut(),
                &mut rows as *mut u32,
                &mut cols as *mut u32,
            );
        }

        (cols, rows)
    }

    /// Compute the coefficient matrix and store into cache
    pub fn compute_coefficient_matrix(&self, cache: &mut ArticulationCache) {
        unsafe {
            PxArticulationReducedCoordinate_computeCoefficientMatrix(
                self.get_raw(),
                cache.get_raw_mut(),
            )
        }
    }

    /// Compute the force needed to match the velocity and acceleration values given in initial_state
    pub fn compute_lambda(
        &self,
        cache: &mut ArticulationCache,
        initial_state: &mut ArticulationCache,
        joint_torques: &[f32],
        max_iter: u32,
    ) -> bool {
        unsafe {
            PxArticulationReducedCoordinate_computeLambda(
                self.get_raw(),
                cache.get_raw_mut(),
                initial_state.get_raw_mut(),
                joint_torques.as_ptr(),
                max_iter,
            )
        }
    }

    /// Compute the generalized mass matrix and store into the cache
    pub fn compute_generalized_mass_matrix(&self, cache: &mut ArticulationCache) {
        unsafe {
            PxArticulationReducedCoordinate_computeGeneralizedMassMatrix(
                self.get_raw(),
                cache.get_raw_mut(),
            );
        }
    }

    /// Pack the maximum coordinates data in `maximum` into the `reduced` coordinates data.
    pub fn pack_joint_data(&self, maximum: &[f32], reduced: &mut [f32]) {
        unsafe {
            PxArticulationReducedCoordinate_packJointData(
                self.get_raw(),
                maximum.as_ptr(),
                reduced.as_mut_ptr(),
            )
        }
    }

    /// Unpack the reduced/generalized coordinates data in `reduced` into `maximum`. Maximum needs to have six slots for every joint.
    pub fn unpack_joint_data(&self, reduced: &[f32], maximum: &mut [f32]) {
        unsafe {
            PxArticulationReducedCoordinate_unpackJointData(
                self.get_raw(),
                reduced.as_ptr(),
                maximum.as_mut_ptr(),
            )
        }
    }

    /// Compute the total center of mass w.r.t. all attached shapes
    pub fn get_center_of_mass(&self) -> Vec3 {
        let nb_shapes = self
            .iter_links()
            .fold(0, |accum, link| accum + link.get_nb_shapes()) as usize;
        let mut shape_ptrs = vec![null(); nb_shapes];
        let mut offset = 0;
        let props = unsafe {
            for link in self.links() {
                for shape in link.get_shapes() {
                    shape_ptrs[offset] = shape.get_raw();
                    offset += 1;
                }
            }

            PxRigidBodyExt_computeMassPropertiesFromShapes_mut(
                shape_ptrs.as_ptr(),
                nb_shapes as u32,
            )
        };

        Vec3::new(
            props.centerOfMass.x,
            props.centerOfMass.y,
            props.centerOfMass.z,
        )
    }

    /// Compute the total center of mass and velocity w.r.t. all attached shapes
    pub fn get_center_of_mass_and_velocity(&self) -> (Vec3, Vec3) {
        let nb_shapes = self
            .iter_links()
            .fold(0, |accum, link| accum + link.get_nb_shapes()) as usize;
        let mut shape_ptrs = vec![null(); nb_shapes];
        let mut offset = 0;
        let props = unsafe {
            for link in self.links() {
                for shape in link.get_shapes() {
                    shape_ptrs[offset] = shape.get_raw();
                    offset += 1;
                }
            }

            PxRigidBodyExt_computeMassPropertiesFromShapes_mut(
                shape_ptrs.as_ptr(),
                nb_shapes as u32,
            )
        };

        let com_vel = unsafe {
            PxRigidBodyExt_getVelocityAtPos_mut(self.root().deref().get_raw(), &props.centerOfMass)
        };

        (px_to_gl_v3(props.centerOfMass), px_to_gl_v3(com_vel))
    }

    pub fn get_origin(&self) -> Vec3 {
        Vec3::zero() // todo[tolsson]
    }

    /// Set the collision layer on all links and shapes of this body
    pub fn set_collision_filter(
        &mut self,
        this_layer: BitFlags<CollisionLayer>,  // word1
        other_layer: BitFlags<CollisionLayer>, // word2
    ) {
        let (a, b) = ((self.ptr as usize >> 32) as u32, self.ptr as usize as u32);
        for link in self.iter_links_mut() {
            link.set_collision_filter(this_layer, other_layer, a, b);
        }
    }

    /// Set the collision layer on all links and shapes of this body
    pub fn set_query_filter(&mut self, this_layer: BitFlags<CollisionLayer>) {
        for link in self.iter_links_mut() {
            link.set_query_filter(this_layer);
        }
    }

    /// Clears collision flag on all links
    pub fn clear_collisions(&mut self) {
        for link in self.iter_links_mut() {
            link.reset_collide()
        }
    }
    pub unsafe fn release(&mut self) {
        // All parents are before the children, so popping one at a time ensures proper deletion order (from child to parent)
        for mut link in self.links_mut().drain(..).rev() {
            link.release();
        }

        PxArticulationReducedCoordinate_release_mut(self.get_raw_mut());
    }
}
