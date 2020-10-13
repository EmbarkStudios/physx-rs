// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 15 April 2019

#![warn(clippy::all)]

/*!
Wrapper for PxArticulationBase
 */

use super::{
    articulation_link::ArticulationLink, base::Base, body::*, math::Bounds, px_type::*,
    transform::*, user_data::UserData,
};
use glam::Mat4;
use physx_macros::*;
use physx_sys::{
    PxArticulationBase, PxArticulationBase_createLink_mut, PxArticulationBase_getNbLinks,
    PxArticulationBase_getSleepThreshold, PxArticulationBase_getSolverIterationCounts,
    PxArticulationBase_getStabilizationThreshold, PxArticulationBase_getWakeCounter,
    PxArticulationBase_getWorldBounds, PxArticulationBase_isSleeping,
    PxArticulationBase_putToSleep_mut, PxArticulationBase_setSleepThreshold_mut,
    PxArticulationBase_setSolverIterationCounts_mut,
    PxArticulationBase_setStabilizationThreshold_mut, PxArticulationBase_setWakeCounter_mut,
    PxArticulationBase_wakeUp_mut, PxArticulationLink, PxRigidActor, PxRigidActor_getGlobalPose,
};
use std::ptr::null_mut;

#[physx_type(inherit = "Base")]
impl ArticulationBase {
    /*
    fixme[tgolsson]: Unsupported so far!
        pub fn set_name(&mut self, name: *const i8) {}
        pub fn get_name(&self) -> *const i8 {}
        pub pub fn get_scene(&self) -> *mut PxScene
        pub pub fn create_link(&mut self, parent: *mut PxArticulationLink, pose: *const PxTransform) -> *mut PxArticulationLink;
        pub pub fn get_aggregate(&self) -> *mut PxAggregate;
        pub pub fn get_impl(&mut self) -> *mut PxArticulationImpl;
        pub pub fn get_impl(&self) -> *const PxArticulationImpl;
        pub pub fn create_articulation_joint(&mut self, parent: *mut PxArticulationLink, parentFrame: *const PxTransform, child: *mut PxArticulationLink, childFrame: *const PxTransform) -> *mut PxArticulationJointBase;
        pub pub fn release_articulation_joint(&mut self, joint: *mut PxArticulationJointBase);
     */

    pub fn new(ptr: *mut PxArticulationBase) -> Self {
        let mut _self = Self::from_ptr(ptr);
        _self.allocate_user_data();
        _self
    }

    pub fn set_solver_iteration_counts(
        &mut self,
        min_position_iters: u32,
        min_velocity_iters: u32,
    ) {
        unsafe {
            PxArticulationBase_setSolverIterationCounts_mut(
                self.get_raw_mut(),
                min_position_iters,
                min_velocity_iters,
            );
        }
    }

    pub fn get_solver_iteration_counts(&self) -> (u32, u32) {
        unsafe {
            let mut min_position_iters: u32 = 0;
            let mut min_velocity_iters: u32 = 0;
            PxArticulationBase_getSolverIterationCounts(
                self.get_raw(),
                &mut min_position_iters as *mut u32,
                &mut min_velocity_iters as *mut u32,
            );
            (min_position_iters, min_velocity_iters)
        }
    }

    /// Check if the articulation is sleeping
    pub fn is_sleeping(&self) -> bool {
        unsafe { PxArticulationBase_isSleeping(self.get_raw()) }
    }

    /// Set the inactivity threshold for sleeping this articulation
    pub fn set_sleep_threshold(&mut self, threshold: f32) {
        unsafe {
            PxArticulationBase_setSleepThreshold_mut(self.get_raw_mut(), threshold);
        }
    }

    /// Read back the inactivity threshold
    pub fn get_sleep_threshold(&self) -> f32 {
        unsafe { PxArticulationBase_getSleepThreshold(self.get_raw()) }
    }

    /// Set the stabilization threshold for this articulation
    pub fn set_stabilization_threshold(&mut self, threshold: f32) {
        unsafe {
            PxArticulationBase_setStabilizationThreshold_mut(self.get_raw_mut(), threshold);
        }
    }

    /// Get the stabilization threshold for this articulation
    pub fn get_stabilization_threshold(&self) -> f32 {
        unsafe { PxArticulationBase_getStabilizationThreshold(self.get_raw()) }
    }

    /// Set the counter for how many steps more the articulation will be awake
    /// if below the energy threshold. When this is non-zero, the articulation
    /// may sleep but is not required to do so depending on other factors.
    pub fn set_wake_counter(&mut self, threshold: f32) {
        unsafe {
            PxArticulationBase_setWakeCounter_mut(self.get_raw_mut(), threshold);
        }
    }

    /// Get the counter for how many steps more the agent will be awake if below the energy threshold.
    pub fn get_wake_counter(&self) -> f32 {
        unsafe { PxArticulationBase_getWakeCounter(self.get_raw()) }
    }

    /// Wake up the articulation
    pub fn wake_up(&mut self) {
        unsafe {
            PxArticulationBase_wakeUp_mut(self.get_raw_mut());
        }
    }

    /// Put the articulation to sleep immediately
    pub fn put_to_sleep(&mut self) {
        unsafe {
            PxArticulationBase_putToSleep_mut(self.get_raw_mut());
        }
    }

    /// Get the total number of links on this articulation
    pub fn get_nb_links(&self) -> usize {
        unsafe { PxArticulationBase_getNbLinks(self.get_raw()) as usize }
    }

    #[inline]
    /// Get an iterator over all links
    pub fn iter_links(&self) -> impl std::iter::Iterator<Item = &ArticulationLink> {
        match self.user_data() {
            UserData::ArticulationBase(data) => data.links.iter(),
            _ => unimplemented!(),
        }
    }

    #[inline]
    /// Get an iterator over all links
    pub fn iter_links_mut(&mut self) -> impl std::iter::Iterator<Item = &mut ArticulationLink> {
        match self.user_data_mut() {
            UserData::ArticulationBase(data) => data.links.iter_mut(),
            _ => unimplemented!(),
        }
    }

    #[inline]
    /// Get an iterator over all links
    pub fn links(&self) -> &Vec<ArticulationLink> {
        match self.user_data() {
            UserData::ArticulationBase(data) => &data.links,
            _ => unimplemented!(),
        }
    }

    #[inline]
    /// Get an iterator over all links
    pub fn links_mut(&mut self) -> &mut Vec<ArticulationLink> {
        match self.user_data_mut() {
            UserData::ArticulationBase(data) => &mut data.links,
            _ => unimplemented!(),
        }
    }

    /// Create a child link for parent, with the given transform
    pub fn create_link(
        &mut self,
        parent: PartHandle,
        transform: Option<Mat4>,
        joint_transform: Option<Mat4>,
    ) -> *mut PxArticulationLink {
        let (parent, trans) = if parent.1 == 0 {
            (null_mut(), Mat4::identity())
        } else {
            let parent_link = parent.1 as *mut PxArticulationLink;
            (parent_link, unsafe {
                px_to_gl_tf(PxRigidActor_getGlobalPose(
                    parent_link as *const PxRigidActor,
                ))
            })
        };

        let transform = joint_transform.unwrap_or_else(Mat4::identity)
            * transform.unwrap_or_else(Mat4::identity);
        // eprintln!("creating link with transform: {}", trans * transform);
        unsafe {
            PxArticulationBase_createLink_mut(
                self.get_raw_mut(),
                parent,
                &gl_to_px_tf(trans * transform),
            )
        }
    }

    /// Get the world bounds of this articulation
    pub fn get_world_bounds(&self, inflation: f32) -> Bounds {
        unsafe { PxArticulationBase_getWorldBounds(self.get_raw(), inflation).into() }
    }

    /// Add a link to this articulation
    pub fn add_link(&mut self, link: ArticulationLink) {
        if let UserData::ArticulationBase(data) = self.user_data_mut() {
            data.links.push(link)
        }
    }

    /// Get the user data
    pub fn user_data(&self) -> &UserData {
        unsafe { &*((*self.ptr).userData as *const UserData) }
    }

    /// Get the user data
    pub fn user_data_mut(&mut self) -> &mut UserData {
        unsafe { &mut *((*self.ptr).userData as *mut UserData) }
    }

    pub(crate) fn allocate_user_data(&mut self) {
        let userdata = Box::new(UserData::new_articulation_base());

        unsafe {
            (*self.ptr).userData = Box::into_raw(userdata) as *mut std::ffi::c_void;
        }
    }
}
