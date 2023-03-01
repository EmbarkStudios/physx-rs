// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 10 April 2019

use super::{
    articulation_cache::{ArticulationCache, ArticulationCacheFlags},
    articulation_link::ArticulationLink,
    math::PxTransform,
    math::*,
    owner::Owner,
    rigid_actor::RigidActor,
    shape::CollisionLayers,
    traits::{Class, UserData},
};

use std::{marker::PhantomData, ptr::drop_in_place};

use physx_sys::{
    PxArticulationReducedCoordinate_applyCache_mut, PxArticulationReducedCoordinate_commonInit,
    PxArticulationReducedCoordinate_computeCoefficientMatrix,
    PxArticulationReducedCoordinate_computeCoriolisAndCentrifugalForce,
    PxArticulationReducedCoordinate_computeDenseJacobian,
    PxArticulationReducedCoordinate_computeGeneralizedExternalForce,
    PxArticulationReducedCoordinate_computeGeneralizedGravityForce,
    PxArticulationReducedCoordinate_computeGeneralizedMassMatrix,
    PxArticulationReducedCoordinate_computeJointAcceleration,
    PxArticulationReducedCoordinate_computeJointForce,
    PxArticulationReducedCoordinate_computeLambda,
    PxArticulationReducedCoordinate_copyInternalStateToCache,
    PxArticulationReducedCoordinate_createCache,
    PxArticulationReducedCoordinate_getArticulationFlags,
    PxArticulationReducedCoordinate_getCacheDataSize, PxArticulationReducedCoordinate_getDofs,
    PxArticulationReducedCoordinate_getLinks, PxArticulationReducedCoordinate_getNbLinks,
    PxArticulationReducedCoordinate_getRootGlobalPose,
    PxArticulationReducedCoordinate_getSolverIterationCounts,
    PxArticulationReducedCoordinate_packJointData, PxArticulationReducedCoordinate_release_mut,
    PxArticulationReducedCoordinate_setArticulationFlag_mut,
    PxArticulationReducedCoordinate_setArticulationFlags_mut,
    PxArticulationReducedCoordinate_setRootGlobalPose_mut,
    PxArticulationReducedCoordinate_setSolverIterationCounts_mut,
    PxArticulationReducedCoordinate_unpackJointData,
    PxRigidBodyExt_computeMassPropertiesFromShapes_mut, PxRigidBodyExt_getVelocityAtPos_mut,
};

pub use physx_sys::{
    PxArticulationFlag as ArticulationFlag, PxArticulationFlags as ArticulationFlags,
};

/*******************************************************************************
 * Section ARTICULATION                                                        *
*******************************************************************************/

/// A new type wrapper for PxArticulationReducedCoordinate.
///
/// Parametrized by its user data type, and the type of its ArticulationLinks.
#[repr(transparent)]
pub struct PxArticulationReducedCoordinate<U, Link: ArticulationLink> {
    pub(crate) obj: physx_sys::PxArticulationReducedCoordinate,
    phantom_user_data: PhantomData<(U, Link)>,
}

unsafe impl<U, Link: ArticulationLink> UserData for PxArticulationReducedCoordinate<U, Link> {
    type UserData = U;

    fn user_data_ptr(&self) -> &*mut std::ffi::c_void {
        &self.obj.userData
    }

    fn user_data_ptr_mut(&mut self) -> &mut *mut std::ffi::c_void {
        &mut self.obj.userData
    }
}

impl<U, Link: ArticulationLink> Drop for PxArticulationReducedCoordinate<U, Link> {
    fn drop(&mut self) {
        // All parents are before the children, so popping one at a time ensures proper deletion order (from child to parent)
        unsafe {
            for link in self.get_links_mut().drain(..).rev() {
                drop_in_place(link as *mut _);
            }
            drop_in_place(self.get_user_data_mut() as *mut _);
            PxArticulationReducedCoordinate_release_mut(self.as_mut_ptr());
        }
    }
}

unsafe impl<S, U, Link: ArticulationLink> Class<S> for PxArticulationReducedCoordinate<U, Link>
where
    physx_sys::PxArticulationReducedCoordinate: Class<S>,
{
    fn as_ptr(&self) -> *const S {
        self.obj.as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut S {
        self.obj.as_mut_ptr()
    }
}

unsafe impl<U: Send, Link: ArticulationLink + Send> Send
    for PxArticulationReducedCoordinate<U, Link>
{
}
unsafe impl<U: Sync, Link: ArticulationLink + Send> Sync
    for PxArticulationReducedCoordinate<U, Link>
{
}

impl<U, L: ArticulationLink> ArticulationReducedCoordinate
    for PxArticulationReducedCoordinate<U, L>
{
    type ArticulationLink = L;
}

pub trait ArticulationReducedCoordinate:
    Class<physx_sys::PxArticulationReducedCoordinate> + UserData
{
    type ArticulationLink: ArticulationLink;

    /// # Safety
    ///
    /// Owner's own the pointer they wrap, using the pointer after dropping the Owner,
    /// or creating multiple Owners from the same pointer will cause UB.  Use `into_ptr` to
    /// retrieve the pointer and consume the Owner without dropping the pointee.
    /// This also sets the user data field, all constructors must initialize user data.
    unsafe fn from_raw(
        ptr: *mut physx_sys::PxArticulationReducedCoordinate,
        user_data: Self::UserData,
    ) -> Option<Owner<Self>> {
        let articulation = (ptr as *mut Self).as_mut();
        Owner::from_raw(articulation?.init_user_data(user_data))
    }

    /// Get a reference to the user data.
    fn get_user_data(&self) -> &Self::UserData {
        // Safety: construction must go through `from_raw` which calls `init_user_data`
        unsafe { UserData::get_user_data(self) }
    }

    /// Get a mutable reference to the user data.
    fn get_user_data_mut(&mut self) -> &mut Self::UserData {
        // Safety: construction must go through `from_raw` which calls `init_user_data`
        unsafe { UserData::get_user_data_mut(self) }
    }

    #[inline]
    fn common_init(&mut self) {
        unsafe { PxArticulationReducedCoordinate_commonInit(self.as_ptr()) }
    }

    /// Get the number of dofs for the body
    #[inline]
    fn get_dofs(&self) -> usize {
        unsafe { PxArticulationReducedCoordinate_getDofs(self.as_ptr()) as usize }
    }

    /// Set an articulation flag
    #[inline]
    fn set_articulation_flag(&mut self, flag: ArticulationFlag, value: bool) {
        unsafe {
            PxArticulationReducedCoordinate_setArticulationFlag_mut(self.as_mut_ptr(), flag, value)
        }
    }

    /// Set the articulation flags
    #[inline]
    fn set_articulation_flags(&mut self, flags: ArticulationFlags) {
        unsafe {
            PxArticulationReducedCoordinate_setArticulationFlags_mut(self.as_mut_ptr(), flags)
        }
    }

    /// Get the articulation flags
    #[inline]
    fn get_articulation_flags(&self) -> ArticulationFlags {
        unsafe { PxArticulationReducedCoordinate_getArticulationFlags(self.as_ptr()) }
    }

    /// Get the total number of links on this articulation
    #[inline]
    fn get_nb_links(&self) -> u32 {
        unsafe { PxArticulationReducedCoordinate_getNbLinks(self.as_ptr()) }
    }

    /// Get a reference the root link of this articulation if it has one
    #[inline]
    fn root_link(&self) -> Option<&Self::ArticulationLink> {
        unsafe {
            let mut root: *mut Self::ArticulationLink = std::ptr::null_mut();
            PxArticulationReducedCoordinate_getLinks(
                self.as_ptr(),
                &mut root as *mut *mut Self::ArticulationLink
                    as *mut *mut physx_sys::PxArticulationLink,
                1,
                0,
            );
            root.as_ref()
        }
    }

    /// See [`physx_sys::PxArticulationReducedCoordinate_setRootGlobalPose_mut`], prefer using [`ArticulationCache::set_root_link_data`]
    fn set_root_global_pose(&mut self, pose: &PxTransform) {
        // self.links[0].set_transform(pose);
        self.common_init();
        unsafe {
            PxArticulationReducedCoordinate_setRootGlobalPose_mut(
                self.as_mut_ptr(),
                pose.as_ptr(),
                true,
            );
        }
    }

    /// See [`physx_sys::PxArticulationReducedCoordinate_getRootGlobalPose`], prefer using [`ArticulationCache::get_root_link_data`]
    #[inline]
    fn get_root_global_pose(&self) -> PxTransform {
        unsafe { PxArticulationReducedCoordinate_getRootGlobalPose(self.as_ptr()).into() }
    }

    ////////////////////////////////////////////////////////////////////////////////
    // Section CACHE
    ////////////////////////////////////////////////////////////////////////////////

    /// Create a new cache for this articulation
    fn create_cache(&self) -> Option<ArticulationCache> {
        unsafe {
            let mut articulation_cache = ArticulationCache::from_raw(
                PxArticulationReducedCoordinate_createCache(self.as_ptr()),
            )?;
            articulation_cache.compute_dof_information(self);
            Some(articulation_cache)
        }
    }

    /// Get the memory size of this cache
    fn get_cache_data_size(&self) -> u32 {
        unsafe { PxArticulationReducedCoordinate_getCacheDataSize(self.as_ptr()) }
    }

    /// Apply the cache to the articulation
    fn apply_cache(
        &mut self,
        cache: &mut ArticulationCache,
        flags: ArticulationCacheFlags,
        autowake: bool,
    ) {
        unsafe {
            PxArticulationReducedCoordinate_applyCache_mut(
                self.as_mut_ptr(),
                cache.as_mut_ptr(),
                flags,
                autowake,
            )
        }
    }

    /// Copy from the articulation to the cache based on the flags
    fn copy_internal_state_to_cache(
        &self,
        cache: &mut ArticulationCache,
        flags: ArticulationCacheFlags,
    ) {
        unsafe {
            PxArticulationReducedCoordinate_copyInternalStateToCache(
                self.as_ptr(),
                cache.as_mut_ptr(),
                flags,
            )
        }
    }

    /// Compute generalized gravity forces acting upon the body and store in cache
    fn compute_generalized_gravity_force(&self, cache: &mut ArticulationCache) {
        unsafe {
            PxArticulationReducedCoordinate_computeGeneralizedGravityForce(
                self.as_ptr(),
                cache.as_mut_ptr(),
            )
        }
    }

    /// Compute the coriolis and centrifugal forces acting upon the multibody
    fn compute_coriolis_and_centrifugal_force(&self, cache: &mut ArticulationCache) {
        unsafe {
            PxArticulationReducedCoordinate_computeCoriolisAndCentrifugalForce(
                self.as_ptr(),
                cache.as_mut_ptr(),
            )
        }
    }

    /// Compute joint force changes caused by external forces
    fn compute_generalized_external_force(&self, cache: &mut ArticulationCache) {
        unsafe {
            PxArticulationReducedCoordinate_computeGeneralizedExternalForce(
                self.as_ptr(),
                cache.as_mut_ptr(),
            )
        }
    }

    /// Compute joint acceleration caused by current joint forces
    fn compute_joint_acceleration(&self, cache: &mut ArticulationCache) {
        unsafe {
            PxArticulationReducedCoordinate_computeJointAcceleration(
                self.as_ptr(),
                cache.as_mut_ptr(),
            )
        }
    }

    /// Compute joint force caused by changes in joint acceleration
    fn compute_joint_force(&self, cache: &mut ArticulationCache) {
        unsafe {
            PxArticulationReducedCoordinate_computeJointForce(self.as_ptr(), cache.as_mut_ptr())
        }
    }

    /// Compute dense jacobian and store into the cache.
    /// Returns: (cols, rows)
    fn compute_dense_jacobian(&self, cache: &mut ArticulationCache) -> (u32, u32) {
        let mut rows = 0;
        let mut cols = 0;
        unsafe {
            PxArticulationReducedCoordinate_computeDenseJacobian(
                self.as_ptr(),
                cache.as_mut_ptr(),
                &mut rows,
                &mut cols,
            );
        }

        (cols, rows)
    }

    /// Compute the coefficient matrix and store into cache
    fn compute_coefficient_matrix(&self, cache: &mut ArticulationCache) {
        unsafe {
            PxArticulationReducedCoordinate_computeCoefficientMatrix(
                self.as_ptr(),
                cache.as_mut_ptr(),
            )
        }
    }

    /// Compute the force needed to match the velocity and acceleration values given in initial_state
    fn compute_lambda(
        &self,
        cache: &mut ArticulationCache,
        initial_state: &mut ArticulationCache,
        joint_torques: &[f32],
        max_iter: u32,
    ) -> bool {
        unsafe {
            PxArticulationReducedCoordinate_computeLambda(
                self.as_ptr(),
                cache.as_mut_ptr(),
                initial_state.as_mut_ptr(),
                joint_torques.as_ptr(),
                max_iter,
            )
        }
    }

    /// Compute the generalized mass matrix and store into the cache
    fn compute_generalized_mass_matrix(&self, cache: &mut ArticulationCache) {
        unsafe {
            PxArticulationReducedCoordinate_computeGeneralizedMassMatrix(
                self.as_ptr(),
                cache.as_mut_ptr(),
            );
        }
    }

    /// Pack the maximum coordinates data in `maximum` into the `reduced` coordinates data.
    fn pack_joint_data(&self, maximum: &[f32], reduced: &mut [f32]) {
        unsafe {
            PxArticulationReducedCoordinate_packJointData(
                self.as_ptr(),
                maximum.as_ptr(),
                reduced.as_mut_ptr(),
            )
        }
    }

    /// Unpack the reduced/generalized coordinates data in `reduced` into `maximum`. Maximum needs to have six slots for every joint.
    fn unpack_joint_data(&self, reduced: &[f32], maximum: &mut [f32]) {
        unsafe {
            PxArticulationReducedCoordinate_unpackJointData(
                self.as_ptr(),
                reduced.as_ptr(),
                maximum.as_mut_ptr(),
            )
        }
    }

    /// Compute the total center of mass w.r.t. all attached shapes
    fn get_center_of_mass(&self) -> PxVec3 {
        let links = self.get_links();
        let nb_shapes = links
            .iter()
            .fold(0, |accum, link| accum + link.get_nb_shapes());
        let mut shape_ptrs = Vec::with_capacity(nb_shapes as usize);
        for link in links {
            for shape in link.get_shapes() {
                shape_ptrs.push(shape.as_ptr());
            }
        }
        let props = unsafe {
            PxRigidBodyExt_computeMassPropertiesFromShapes_mut(shape_ptrs.as_ptr(), nb_shapes)
        };
        PxVec3::new(
            props.centerOfMass.x,
            props.centerOfMass.y,
            props.centerOfMass.z,
        )
    }

    /// Compute the total center of mass and velocity w.r.t. all attached shapes
    fn get_center_of_mass_and_velocity(&self) -> (PxVec3, PxVec3) {
        let center_of_mass = self.get_center_of_mass();
        if let Some(body) = self.root_link() {
            let com_vel = unsafe {
                PxRigidBodyExt_getVelocityAtPos_mut(
                    Class::<physx_sys::PxRigidBody>::as_ptr(body),
                    &center_of_mass.into(),
                )
                .into()
            };

            (center_of_mass, com_vel)
        } else {
            (center_of_mass, PxVec3::new(0.0, 0.0, 0.0))
        }
    }

    /// Set the collision layer on all links and shapes of this body
    fn set_collision_filter(&mut self, this_layer: CollisionLayers, other_layer: CollisionLayers) {
        let (a, b) = (
            (self as *const _ as usize >> 32) as u32,
            self as *const _ as usize as u32,
        );
        for link in self.get_links_mut() {
            link.set_collision_filter(this_layer, other_layer, a, b);
        }
    }

    /// Set the collision layer on all links and shapes of this body
    fn set_query_filter(&mut self, this_layer: CollisionLayers) {
        for link in self.get_links_mut() {
            link.set_query_filter(this_layer);
        }
    }

    /// Sets the number of iterations the solver should perform.  If the articulation is behaving
    /// erratically, increasing the iteration counts may improve stability.
    fn set_solver_iteration_counts(&mut self, min_position_iters: u32, min_velocity_iters: u32) {
        unsafe {
            PxArticulationReducedCoordinate_setSolverIterationCounts_mut(
                self.as_mut_ptr(),
                min_position_iters,
                min_velocity_iters,
            );
        }
    }

    /// Get the number of (position, velocity) iterations the solver will perform.
    fn get_solver_iteration_counts(&self) -> (u32, u32) {
        unsafe {
            let mut min_position_iters: u32 = 0;
            let mut min_velocity_iters: u32 = 0;
            PxArticulationReducedCoordinate_getSolverIterationCounts(
                self.as_ptr(),
                &mut min_position_iters as *mut u32,
                &mut min_velocity_iters as *mut u32,
            );
            (min_position_iters, min_velocity_iters)
        }
    }

    /// Get a vec of all the links
    fn get_links(&self) -> Vec<&Self::ArticulationLink> {
        unsafe {
            let capacity = self.get_nb_links();
            let mut buffer: Vec<&Self::ArticulationLink> = Vec::with_capacity(capacity as usize);
            let len = PxArticulationReducedCoordinate_getLinks(
                self.as_ptr(),
                buffer.as_mut_ptr() as *mut *mut _,
                capacity,
                0,
            );
            buffer.set_len(len as usize);
            buffer
        }
    }

    /// Get a mutable vec of all the links
    fn get_links_mut(&mut self) -> Vec<&mut Self::ArticulationLink> {
        unsafe {
            let capacity = self.get_nb_links();
            let mut buffer: Vec<&mut Self::ArticulationLink> =
                Vec::with_capacity(capacity as usize);
            let len = PxArticulationReducedCoordinate_getLinks(
                self.as_ptr(),
                buffer.as_mut_ptr() as *mut *mut _,
                capacity,
                0,
            );
            buffer.set_len(len as usize);
            buffer
        }
    }
}
