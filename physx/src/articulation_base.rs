// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 15 April 2019

#![warn(clippy::all)]

/*!
Wrapper for PxArticulationBase
 */

use crate::{
    articulation::Articulation, articulation_joint_base::ArticulationJointBase,
    articulation_link::ArticulationLink,
    articulation_reduced_coordinate::ArticulationReducedCoordinate, base::Base, math::PxBounds3,
    math::PxTransform, owner::Owner, traits::Class,
};
//use glam::Mat4;

use std::{marker::PhantomData, ptr::null_mut};

pub(crate) use physx_sys::PxArticulationBase;

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

pub trait ArticulationBase<L, H, M>: Class<PxArticulationBase> + Base {
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
    fn set_solver_iteration_counts(&mut self, min_position_iters: u32, min_velocity_iters: u32) {
        unsafe {
            PxArticulationBase_setSolverIterationCounts_mut(
                self.as_mut_ptr(),
                min_position_iters,
                min_velocity_iters,
            );
        }
    }

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
    fn get_number_links(&self) -> usize {
        unsafe { PxArticulationBase_getNbLinks(self.as_ptr()) as usize }
    }

    fn root_link(&self) -> Option<&ArticulationLink<L, H, M>> {
        unsafe {
            let mut buffer: Vec<*const ArticulationLink<L, H, M>> = vec![null_mut()];
            PxArticulationBase_getLinks(self.as_ptr(), buffer.as_mut_ptr() as *mut *mut _, 1, 0);
            // Safety: if there is no root link, rather than crash on an invalid index,
            // let as_ref return None.
            buffer.set_len(1);
            buffer[0].as_ref()
        }
    }

    /// Get a vec of all the links
    fn get_links(&self) -> Vec<&ArticulationLink<L, H, M>> {
        unsafe {
            let capacity = PxArticulationBase_getNbLinks(self.as_ptr());
            let mut buffer: Vec<&ArticulationLink<L, H, M>> = Vec::with_capacity(capacity as usize);
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
    fn get_links_mut(&mut self) -> Vec<&mut ArticulationLink<L, H, M>> {
        unsafe {
            let capacity = PxArticulationBase_getNbLinks(self.as_ptr());
            let mut buffer: Vec<&mut ArticulationLink<L, H, M>> =
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
        parent: Option<&mut ArticulationLink<L, H, M>>,
        pose: &PxTransform,
        user_data: L,
    ) -> Option<Owner<ArticulationLink<L, H, M>>> {
        unsafe {
            ArticulationLink::from_raw(
                PxArticulationBase_createLink_mut(
                    self.as_mut_ptr(),
                    parent
                        .map(|parent| parent.as_mut_ptr())
                        .unwrap_or(null_mut()),
                    pose.as_ptr(),
                ),
                user_data,
            )
        }
    }

    // TODO not clear on how this is used, the docs imply that articulation joints are created automatically
    // when creating a link, and shows how to manipulate them not what creating one on it's own is for/if it's useful.
    fn create_articulation_joint<J: ArticulationJointBase>(
        &mut self,
        parent: &mut ArticulationLink<L, H, M>,
        parent_frame: &PxTransform,
        child: &mut ArticulationLink<L, H, M>,
        child_frame: &PxTransform,
    ) -> Option<Owner<J>> {
        unsafe {
            Owner::from_raw(PxArticulationBase_createArticulationJoint_mut(
                self.as_mut_ptr(),
                parent.as_mut_ptr(),
                parent_frame.as_ptr(),
                child.as_mut_ptr(),
                child_frame.as_ptr(),
            ) as *mut J)
        }
    }

    unsafe fn release_articulation_joint(&mut self, joint: &mut impl ArticulationJointBase) {
        PxArticulationBase_releaseArticulationJoint_mut(self.as_mut_ptr(), joint.as_mut_ptr())
    }
}

pub struct ArticulationMap<T, C, L, H, M> {
    obj: *mut physx_sys::PxArticulationBase,
    phantom_user_data: PhantomData<(T, C, L, H, M)>,
}

unsafe impl<S, T, C, L, H, M> Class<S> for ArticulationMap<T, C, L, H, M>
where
    physx_sys::PxArticulationBase: Class<S>,
{
    fn as_ptr(&self) -> *const S {
        self.obj as *const _ as *const _
    }

    fn as_mut_ptr(&mut self) -> *mut S {
        self.obj as *mut _
    }
}

impl<T, C, L, H, M> ArticulationMap<T, C, L, H, M> {
    pub fn map<Ret, ArtFn, ArcFn>(&mut self, art_fn: ArtFn, arc_fn: ArcFn) -> Ret
    where
        ArtFn: FnOnce(&mut Articulation<T, L, H, M>) -> Ret,
        ArcFn: FnOnce(&mut ArticulationReducedCoordinate<C, L, H, M>) -> Ret,
    {
        match self.get_concrete_type() {
            crate::base::ConcreteType::Articulation => {
                art_fn(unsafe { &mut *(self.obj as *mut Articulation<T, L, H, M>) })
            }
            crate::base::ConcreteType::ArticulationReducedCoordinate => arc_fn(unsafe {
                &mut *(self.obj as *mut ArticulationReducedCoordinate<C, L, H, M>)
            }),
            _ => unreachable!(),
        }
    }
}
