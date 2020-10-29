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
    math::PxTransform,
    math::*,
    owner::Owner,
    rigid_actor::RigidActor,
    shape::CollisionLayer,
    traits::{Class, PxFlags, UserData},
};

use std::{
    marker::PhantomData,
    ptr::{drop_in_place, NonNull},
};

use enumflags2::BitFlags;

use physx_sys::{
    PxArticulationCacheFlags,
    PxArticulationFlag,
    PxArticulationFlags,
    //PxArticulationReducedCoordinate_addLoopJoint_mut,
    PxArticulationReducedCoordinate_applyCache_mut,
    PxArticulationReducedCoordinate_commonInit,
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
    PxArticulationReducedCoordinate_getCacheDataSize,
    //PxArticulationReducedCoordinate_getCoefficientMatrixSize,
    PxArticulationReducedCoordinate_getDofs,
    //PxArticulationReducedCoordinate_getLoopJoints,
    //PxArticulationReducedCoordinate_getNbLoopJoints,
    PxArticulationReducedCoordinate_packJointData,
    PxArticulationReducedCoordinate_releaseCache,
    PxArticulationReducedCoordinate_release_mut,
    //PxArticulationReducedCoordinate_removeLoopJoint_mut,
    PxArticulationReducedCoordinate_setArticulationFlag_mut,
    PxArticulationReducedCoordinate_setArticulationFlags_mut,
    PxArticulationReducedCoordinate_teleportRootLink_mut,
    PxArticulationReducedCoordinate_unpackJointData,
    PxArticulationReducedCoordinate_zeroCache_mut,
    PxRigidBodyExt_computeMassPropertiesFromShapes_mut,
    PxRigidBodyExt_getVelocityAtPos_mut,
};

/*******************************************************************************
 * Section FLAGS                                                               *
 ******************************************************************************/

pub type ArticulationFlags = BitFlags<ArticulationFlag>;

impl PxFlags for ArticulationFlags {
    type Target = PxArticulationFlags;

    fn into_px(self) -> Self::Target {
        PxArticulationFlags { mBits: self.bits() }
    }

    fn from_px(flags: Self::Target) -> Self {
        unsafe { BitFlags::new(flags.mBits) }
    }
}

#[derive(Copy, Clone, Debug, BitFlags)]
#[repr(u8)]
pub enum ArticulationFlag {
    FixBase = 1 << 0,
    DriveLimitsAreForces = 1 << 1,
}

impl Into<PxArticulationFlag::Enum> for ArticulationFlag {
    fn into(self) -> PxArticulationFlag::Enum {
        self as _
    }
}

/*******************************************************************************
 * Section ARTICULATION                                                        *
*******************************************************************************/

#[repr(transparent)]
pub struct ArticulationReducedCoordinate<U, L, H, M> {
    pub(crate) obj: physx_sys::PxArticulationReducedCoordinate,
    phantom_user_data: PhantomData<(U, L, H, M)>,
}

impl<U, L, H, M> ArticulationBase for ArticulationReducedCoordinate<U, L, H, M> {
    type LinkData = L;

    type ShapeData = H;

    type MaterialData = M;
}
unsafe impl<S, U, L, H, M> Class<S> for ArticulationReducedCoordinate<U, L, H, M>
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

impl<U, L, H, M> ArticulationReducedCoordinate<U, L, H, M> {
    pub(crate) unsafe fn from_raw(
        ptr: *mut physx_sys::PxArticulationReducedCoordinate,
        user_data: U,
    ) -> Option<Owner<Self>> {
        let arc = (ptr as *mut Self).as_mut();
        Owner::from_raw(arc?.init_user_data(user_data))
    }

    pub fn get_user_data(&self) -> &U {
        // Safety: construction must go through `from_raw` which calls `init_user_data`
        unsafe { UserData::get_user_data(self) }
    }

    pub fn get_user_data_mut(&mut self) -> &mut U {
        // Safety: construction must go through `from_raw` which calls `init_user_data`
        unsafe { UserData::get_user_data_mut(self) }
    }

    #[inline]
    pub fn common_init(&mut self) {
        unsafe { PxArticulationReducedCoordinate_commonInit(self.as_ptr()) }
    }

    /// Get the number of dofs for the body
    #[inline]
    pub fn get_dofs(&self) -> usize {
        unsafe { PxArticulationReducedCoordinate_getDofs(self.as_ptr()) as usize }
    }

    /// Set an articulation flag
    #[inline]
    pub fn set_articulation_flag(&mut self, flag: ArticulationFlag, value: bool) {
        unsafe {
            PxArticulationReducedCoordinate_setArticulationFlag_mut(
                self.as_mut_ptr(),
                flag.into(),
                value,
            )
        }
    }

    /// Set the articulation flags
    #[inline]
    pub fn set_articulation_flags(&mut self, flag: ArticulationFlag) {
        unsafe {
            PxArticulationReducedCoordinate_setArticulationFlags_mut(
                self.as_mut_ptr(),
                PxArticulationFlags { mBits: flag as u8 },
            )
        }
    }

    /// Get the articulation flags
    #[inline]
    pub fn get_articulation_flags(&self) -> ArticulationFlags {
        unsafe {
            ArticulationFlags::from_px(PxArticulationReducedCoordinate_getArticulationFlags(
                self.as_ptr(),
            ))
        }
    }

    /// Teleport the whole body to the transform and and orientation given by `Pose`
    pub fn teleport_to(&mut self, pose: &PxTransform) {
        // self.links[0].set_transform(pose);
        self.common_init();
        unsafe {
            PxArticulationReducedCoordinate_teleportRootLink_mut(
                self.as_mut_ptr(),
                pose.as_ptr(),
                true,
            );
        }
    }

    ////////////////////////////////////////////////////////////////////////////////
    // Section CACHE
    ////////////////////////////////////////////////////////////////////////////////

    /// Create a new cache for this articulation
    pub fn create_cache(&self) -> Option<ArticulationCache> {
        let mut articulation_cache = ArticulationCache::new(NonNull::new(unsafe {
            PxArticulationReducedCoordinate_createCache(self.as_ptr())
        })?);
        unsafe { articulation_cache.compute_dof_information(self) };
        Some(articulation_cache)
    }

    /// Release the cache and free the memory
    pub fn release_cache(&self, mut cache: ArticulationCache) {
        unsafe { PxArticulationReducedCoordinate_releaseCache(self.as_ptr(), cache.as_mut_ptr()) }
    }

    /// Get the memory size of this cache
    pub fn get_cache_data_size(&self) -> u32 {
        unsafe { PxArticulationReducedCoordinate_getCacheDataSize(self.as_ptr()) }
    }

    /// Zero everything in the cache
    pub fn zero_cache(&mut self, cache: &mut ArticulationCache) {
        unsafe {
            PxArticulationReducedCoordinate_zeroCache_mut(self.as_mut_ptr(), cache.as_mut_ptr())
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
                self.as_mut_ptr(),
                cache.as_mut_ptr(),
                PxArticulationCacheFlags { mBits: flag.bits() },
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
                self.as_ptr(),
                cache.as_mut_ptr(),
                PxArticulationCacheFlags { mBits: flag.bits() },
            )
        }
    }

    /// Compute generalized gravity forces acting upon the body and store in cache
    pub fn compute_generalized_gravity_force(&self, cache: &mut ArticulationCache) {
        unsafe {
            PxArticulationReducedCoordinate_computeGeneralizedGravityForce(
                self.as_ptr(),
                cache.as_mut_ptr(),
            )
        }
    }

    /// Compute the coriolis and centrifugal forces acting upon the multibody
    pub fn compute_coriolis_and_centrifugal_force(&self, cache: &mut ArticulationCache) {
        unsafe {
            PxArticulationReducedCoordinate_computeCoriolisAndCentrifugalForce(
                self.as_ptr(),
                cache.as_mut_ptr(),
            )
        }
    }

    /// Compute joint force changes caused by external forces
    pub fn compute_generalized_external_force(&self, cache: &mut ArticulationCache) {
        unsafe {
            PxArticulationReducedCoordinate_computeGeneralizedExternalForce(
                self.as_ptr(),
                cache.as_mut_ptr(),
            )
        }
    }

    /// Compute joint acceleration caused by current joint forces
    pub fn compute_joint_acceleration(&self, cache: &mut ArticulationCache) {
        unsafe {
            PxArticulationReducedCoordinate_computeJointAcceleration(
                self.as_ptr(),
                cache.as_mut_ptr(),
            )
        }
    }

    /// Compute joint force caused by changes in joint acceleration
    pub fn compute_joint_force(&self, cache: &mut ArticulationCache) {
        unsafe {
            PxArticulationReducedCoordinate_computeJointForce(self.as_ptr(), cache.as_mut_ptr())
        }
    }

    /// Compute dense jacobian and store into the cache.
    /// Returns: (cols, rows)
    pub fn compute_dense_jacobian(&self, cache: &mut ArticulationCache) -> (u32, u32) {
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
    pub fn compute_coefficient_matrix(&self, cache: &mut ArticulationCache) {
        unsafe {
            PxArticulationReducedCoordinate_computeCoefficientMatrix(
                self.as_ptr(),
                cache.as_mut_ptr(),
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
                self.as_ptr(),
                cache.as_mut_ptr(),
                initial_state.as_mut_ptr(),
                joint_torques.as_ptr(),
                max_iter,
            )
        }
    }

    /// Compute the generalized mass matrix and store into the cache
    pub fn compute_generalized_mass_matrix(&self, cache: &mut ArticulationCache) {
        unsafe {
            PxArticulationReducedCoordinate_computeGeneralizedMassMatrix(
                self.as_ptr(),
                cache.as_mut_ptr(),
            );
        }
    }

    /// Pack the maximum coordinates data in `maximum` into the `reduced` coordinates data.
    pub fn pack_joint_data(&self, maximum: &[f32], reduced: &mut [f32]) {
        unsafe {
            PxArticulationReducedCoordinate_packJointData(
                self.as_ptr(),
                maximum.as_ptr(),
                reduced.as_mut_ptr(),
            )
        }
    }

    /// Unpack the reduced/generalized coordinates data in `reduced` into `maximum`. Maximum needs to have six slots for every joint.
    pub fn unpack_joint_data(&self, reduced: &[f32], maximum: &mut [f32]) {
        unsafe {
            PxArticulationReducedCoordinate_unpackJointData(
                self.as_ptr(),
                reduced.as_ptr(),
                maximum.as_mut_ptr(),
            )
        }
    }

    /// Compute the total center of mass w.r.t. all attached shapes
    pub fn get_center_of_mass(&self) -> PxVec3 {
        let links = self.get_links();
        let nb_shapes = links
            .iter()
            .fold(0, |accum, link| accum + link.get_nb_shapes());
        let mut shape_ptrs = Vec::with_capacity(nb_shapes as usize);
        let props = unsafe {
            for link in links {
                for shape in link.get_shapes() {
                    shape_ptrs.push(shape.as_ptr());
                }
            }
            PxRigidBodyExt_computeMassPropertiesFromShapes_mut(shape_ptrs.as_ptr(), nb_shapes)
        };
        PxVec3::new(
            props.centerOfMass.x,
            props.centerOfMass.y,
            props.centerOfMass.z,
        )
    }

    /// Compute the total center of mass and velocity w.r.t. all attached shapes
    pub fn get_center_of_mass_and_velocity(&self) -> (PxVec3, PxVec3) {
        let center_of_mass = self.get_center_of_mass();

        let com_vel = unsafe {
            PxRigidBodyExt_getVelocityAtPos_mut(
                self.root_link().expect("root link is null").as_ptr(),
                &center_of_mass.into(),
            )
            .into()
        };

        (center_of_mass, com_vel)
    }

    /// Set the collision layer on all links and shapes of this body
    pub fn set_collision_filter(
        &mut self,
        this_layer: BitFlags<CollisionLayer>,  // word1
        other_layer: BitFlags<CollisionLayer>, // word2
    ) {
        let (a, b) = (
            (self as *const _ as usize >> 32) as u32,
            self as *const _ as usize as u32,
        );
        for link in self.get_links_mut() {
            link.set_collision_filter(this_layer, other_layer, a, b);
        }
    }

    /// Set the collision layer on all links and shapes of this body
    pub fn set_query_filter(&mut self, this_layer: BitFlags<CollisionLayer>) {
        for link in self.get_links_mut() {
            link.set_query_filter(this_layer);
        }
    }

    /*
        /// Clears collision flag on all links
        pub fn clear_collisions(&mut self) {
            for link in self.get_links_mut() {
                link.reset_collide()
            }
        }

        pub fn get_origin(&self) -> Vec3 {
            Vec3::zero() // todo[tolsson]
        }
    */
}

unsafe impl<U: Send, L: Send, H: Send, M: Send> Send for ArticulationReducedCoordinate<U, L, H, M> {}
unsafe impl<U: Sync, L: Send, H: Sync, M: Send> Sync for ArticulationReducedCoordinate<U, L, H, M> {}

impl<U, L, H, M> Drop for ArticulationReducedCoordinate<U, L, H, M> {
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
