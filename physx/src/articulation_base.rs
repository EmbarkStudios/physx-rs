// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 15 April 2019

#![warn(clippy::all)]

/*!
Wrapper for PxArticulationBase
 */

use crate::{
    articulation::Articulation,
    articulation_joint_base::ArticulationJointBase,
    articulation_link::ArticulationLink,
    articulation_reduced_coordinate::ArticulationReducedCoordinate,
    base::Base,
    base::ConcreteType,
    math::PxBounds3,
    math::PxTransform,
    traits::{Class, UserData},
};

use std::{marker::PhantomData, ptr::null_mut};

use physx_sys::{
    PxArticulationBase_createArticulationJoint_mut,
    PxArticulationBase_createLink_mut,
    PxArticulationBase_getLinks,
    PxArticulationBase_getNbLinks,
    PxArticulationBase_getSleepThreshold,
    PxArticulationBase_getSolverIterationCounts,
    PxArticulationBase_getStabilizationThreshold,
    PxArticulationBase_getWakeCounter,
    PxArticulationBase_getWorldBounds,
    PxArticulationBase_isSleeping,
    PxArticulationBase_putToSleep_mut,
    PxArticulationBase_releaseArticulationJoint_mut,
    PxArticulationBase_setSleepThreshold_mut,
    PxArticulationBase_setSolverIterationCounts_mut,
    PxArticulationBase_setStabilizationThreshold_mut,
    PxArticulationBase_setWakeCounter_mut,
    PxArticulationBase_wakeUp_mut,
    //PxArticulationBase_getName,
    //PxArticulationBase_getScene,
    //PxArticulationBase_setName_mut
    //PxArticulationBase_getAggregate,
};

pub trait ArticulationBase: Class<physx_sys::PxArticulationBase> + Base {
    type ArticulationLink: ArticulationLink;
    /*
    fixme[tgolsson]: Unsupported so far!
        pub fn set_name(&mut self, name: *const i8) {}
        pub fn get_name(&self) -> *const i8 {}
        pub pub fn get_scene(&self) -> *mut PxScene
        pub pub fn get_aggregate(&self) -> *mut PxAggregate;

        // PxArticulationImpl appears to be meaningless/unimplemented/ZST.
        // "you don't pay for what you don't use" but also 1 byte ZSTs (:
        pub pub fn get_impl(&mut self) -> *mut PxArticulationImpl;
        pub pub fn get_impl(&self) -> *const PxArticulationImpl;
    */
    /// Sets the number of iterations the solver should perform.  If the articulation is behaving
    /// erratically, increasing the iteration counts may improve stability.
    fn set_solver_iteration_counts(&mut self, min_position_iters: u32, min_velocity_iters: u32) {
        unsafe {
            PxArticulationBase_setSolverIterationCounts_mut(
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
            PxArticulationBase_getSolverIterationCounts(
                self.as_ptr(),
                &mut min_position_iters as *mut u32,
                &mut min_velocity_iters as *mut u32,
            );
            (min_position_iters, min_velocity_iters)
        }
    }

    /// Check if the articulation is sleeping
    fn is_sleeping(&self) -> bool {
        unsafe { PxArticulationBase_isSleeping(self.as_ptr()) }
    }

    /// Set the inactivity threshold for sleeping this articulation
    fn set_sleep_threshold(&mut self, threshold: f32) {
        unsafe {
            PxArticulationBase_setSleepThreshold_mut(self.as_mut_ptr(), threshold);
        }
    }

    /// Read back the inactivity threshold
    fn get_sleep_threshold(&self) -> f32 {
        unsafe { PxArticulationBase_getSleepThreshold(self.as_ptr()) }
    }

    /// Set the stabilization threshold for this articulation
    fn set_stabilization_threshold(&mut self, threshold: f32) {
        unsafe {
            PxArticulationBase_setStabilizationThreshold_mut(self.as_mut_ptr(), threshold);
        }
    }

    /// Get the stabilization threshold for this articulation
    fn get_stabilization_threshold(&self) -> f32 {
        unsafe { PxArticulationBase_getStabilizationThreshold(self.as_ptr()) }
    }

    /// Set the counter for how many steps more the articulation will be awake
    /// if below the energy threshold. When this is non-zero, the articulation
    /// may sleep but is not required to do so depending on other factors.
    fn set_wake_counter(&mut self, threshold: f32) {
        unsafe {
            PxArticulationBase_setWakeCounter_mut(self.as_mut_ptr(), threshold);
        }
    }

    /// Get the counter for how many steps more the agent will be awake if below the energy threshold.
    fn get_wake_counter(&self) -> f32 {
        unsafe { PxArticulationBase_getWakeCounter(self.as_ptr()) }
    }

    /// Wake up the articulation
    fn wake_up(&mut self) {
        unsafe {
            PxArticulationBase_wakeUp_mut(self.as_mut_ptr());
        }
    }

    /// Put the articulation to sleep immediately
    fn put_to_sleep(&mut self) {
        unsafe {
            PxArticulationBase_putToSleep_mut(self.as_mut_ptr());
        }
    }

    /// Get the total number of links on this articulation
    fn get_nb_links(&self) -> usize {
        unsafe { PxArticulationBase_getNbLinks(self.as_ptr()) as usize }
    }

    /// Get a reference the root link of this articulation if it has one
    fn root_link(&self) -> Option<&Self::ArticulationLink> {
        unsafe {
            let mut root: *mut Self::ArticulationLink = null_mut();
            PxArticulationBase_getLinks(
                self.as_ptr(),
                &mut root as *mut *mut Self::ArticulationLink
                    as *mut *mut physx_sys::PxArticulationLink,
                1,
                0,
            );
            root.as_ref()
        }
    }

    /// Get a mutable reference to the root link of this articulation if it has one
    fn root_link_mut(&mut self) -> Option<&mut Self::ArticulationLink> {
        unsafe {
            let mut root: *mut Self::ArticulationLink = null_mut();
            PxArticulationBase_getLinks(
                self.as_ptr(),
                &mut root as *mut *mut Self::ArticulationLink
                    as *mut *mut physx_sys::PxArticulationLink,
                1,
                0,
            );
            root.as_mut()
        }
    }

    /// Get a vec of all the links
    fn get_links(&self) -> Vec<&Self::ArticulationLink> {
        unsafe {
            let capacity = PxArticulationBase_getNbLinks(self.as_ptr());
            let mut buffer: Vec<&Self::ArticulationLink> = Vec::with_capacity(capacity as usize);
            let len = PxArticulationBase_getLinks(
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
            let capacity = PxArticulationBase_getNbLinks(self.as_ptr());
            let mut buffer: Vec<&mut Self::ArticulationLink> =
                Vec::with_capacity(capacity as usize);
            let len = PxArticulationBase_getLinks(
                self.as_ptr(),
                buffer.as_mut_ptr() as *mut *mut _,
                capacity,
                0,
            );
            buffer.set_len(len as usize);
            buffer
        }
    }

    /// Get the world bounds of this articulation
    fn get_world_bounds(&self, inflation: f32) -> PxBounds3 {
        unsafe { PxArticulationBase_getWorldBounds(self.as_ptr(), inflation).into() }
    }

    /// Add a link to this articulation
    fn create_link(
        &mut self,
        parent: Option<&mut Self::ArticulationLink>,
        pose: &PxTransform,
        user_data: <Self::ArticulationLink as UserData>::UserData,
    ) -> Option<&mut Self::ArticulationLink> {
        unsafe {
            (PxArticulationBase_createLink_mut(
                self.as_mut_ptr(),
                parent.map_or(null_mut(), |parent| parent.as_mut_ptr()),
                pose.as_ptr(),
            ) as *mut Self::ArticulationLink)
                .as_mut()
                .map(|link| UserData::init_user_data(link, user_data))
        }
    }

    /// Create a joint between two articulation Links
    fn create_articulation_joint<J: ArticulationJointBase>(
        &mut self,
        parent: &mut Self::ArticulationLink,
        parent_frame: &PxTransform,
        child: &mut Self::ArticulationLink,
        child_frame: &PxTransform,
    ) -> Option<&mut J> {
        unsafe {
            (PxArticulationBase_createArticulationJoint_mut(
                self.as_mut_ptr(),
                parent.as_mut_ptr(),
                parent_frame.as_ptr(),
                child.as_mut_ptr(),
                child_frame.as_ptr(),
            ) as *mut J)
                .as_mut()
        }
    }

    /// Release an articulation joint, freeing it.
    /// # Safety
    /// attempting to use the joint after this call is invalid.
    unsafe fn release_articulation_joint(&mut self, joint: &mut impl ArticulationJointBase) {
        PxArticulationBase_releaseArticulationJoint_mut(self.as_mut_ptr(), joint.as_mut_ptr())
    }
}

/// A wrapper for ArticulationBase, parametrized by the Articulation and
/// ArticulationReducedCoordinate that may be it's most derived type.  Use `try_cast_map`
/// or `as_*` to cast to it's most derived type if specialized functionality is needed.
#[repr(transparent)]
pub struct ArticulationMap<T, C>
where
    T: Articulation,
    C: ArticulationReducedCoordinate,
{
    obj: physx_sys::PxArticulationBase,
    phantom_user_data: PhantomData<(*const T, *const C)>,
}

unsafe impl<S, T, C> Class<S> for ArticulationMap<T, C>
where
    physx_sys::PxArticulationBase: Class<S>,
    T: Articulation,
    C: ArticulationReducedCoordinate,
{
    fn as_ptr(&self) -> *const S {
        self.obj.as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut S {
        self.obj.as_mut_ptr()
    }
}

impl<T, C> ArticulationBase for ArticulationMap<T, C>
where
    T: Articulation,
    C: ArticulationReducedCoordinate,
{
    type ArticulationLink = T::ArticulationLink;
}

impl<T, C> ArticulationMap<T, C>
where
    T: Articulation,
    C: ArticulationReducedCoordinate,
{
    /// # Safety
    /// this relies on `get_concrete_type` to determine the articulation type,
    /// which has had issues with returning ConcreteType::Undefined for Actor subclasses.
    /// `try_cast_map` will return `None` when this would crash.
    pub unsafe fn cast_map<'a, Ret, ArtFn, ArcFn>(
        &'a mut self,
        mut art_fn: ArtFn,
        mut arc_fn: ArcFn,
    ) -> Ret
    where
        ArtFn: FnMut(&'a mut T) -> Ret,
        ArcFn: FnMut(&'a mut C) -> Ret,
    {
        match self.get_concrete_type() {
            ConcreteType::Articulation => {
                art_fn(
                    //unsafe
                    &mut *(self as *mut _ as *mut T),
                )
            }
            ConcreteType::ArticulationReducedCoordinate => arc_fn(&mut *(self as *mut _ as *mut C)),
            _ => panic!(
                "get_concrete_type for {:?} returned an invalid ConcreteType: {:?}",
                self.get_concrete_type_name(),
                self.get_concrete_type()
            ),
        }
    }

    /// Calls one of the given functions and returns the result if the articulation can be
    /// safely cast to that type. If `get_concrete_type` does not return `ConcreteType::Articulation`
    /// or `ConcreteType::ArticulationReducedCoordinate` this call returns `None`.
    pub fn try_cast_map<'a, Ret, ArtFn, ArcFn>(
        &'a mut self,
        mut art_fn: ArtFn,
        mut arc_fn: ArcFn,
    ) -> Option<Ret>
    where
        ArtFn: FnMut(&'a mut T) -> Ret,
        ArcFn: FnMut(&'a mut C) -> Ret,
    {
        match self.get_concrete_type() {
            ConcreteType::Articulation => Some(art_fn(unsafe { &mut *(self as *mut _ as *mut T) })),
            ConcreteType::ArticulationReducedCoordinate => {
                Some(arc_fn(unsafe { &mut *(self as *mut _ as *mut C) }))
            }
            _ => None,
        }
    }

    /// Tries to cast to PxArticulation, returns `None` if `get_concrete_type` does not
    /// return ConcreteType::Articulation.
    pub fn as_articulation(&mut self) -> Option<&mut T> {
        match self.get_concrete_type() {
            ConcreteType::Articulation => Some(unsafe { &mut *(self as *mut _ as *mut T) }),
            _ => None,
        }
    }

    /// Tries to cast to PxArticulationReducedCoordinate, returns `None` if `get_concrete_type`
    /// does not return ConcreteType::ArticulationReducedCoordinate.
    pub fn as_articulation_reduced_coordinate(&mut self) -> Option<&mut T> {
        match self.get_concrete_type() {
            ConcreteType::ArticulationReducedCoordinate => {
                Some(unsafe { &mut *(self as *mut _ as *mut T) })
            }
            _ => None,
        }
    }
}
