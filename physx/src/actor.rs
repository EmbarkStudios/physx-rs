// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 16 April 2019

#![warn(clippy::all)]

/*!
Trait for PxActor
 */

use crate::{
    math::*,
    base::Base,
    traits::Class,
    rigid_dynamic::RigidDynamic,
    rigid_static::RigidStatic,
    articulation_link::ArticulationLink,
};
use enumflags2::BitFlags;

use std::marker::PhantomData;

use physx_sys::{
    PxActor,
    PxActorFlag,
    PxActorFlags,
    PxActorType,
    PxActor_getActorFlags,
    PxActor_getDominanceGroup,
    PxActor_getOwnerClient,
    PxActor_getType,
    PxActor_getWorldBounds,
    PxActor_setActorFlag_mut,
    PxActor_release_mut,
    PxActor_setActorFlags_mut,
    PxActor_setDominanceGroup_mut,
    PxActor_setOwnerClient_mut,
    // PxActor_getScene,
    //PxActor_getAggregate,
    //PxActor_getName,
    //PxActor_setName_mut,
};

/* TODO:
* Define PxAggerate
* Define PxScene conversion
*/

/*******************************************************************************
 * Section ENUMS                                                               *
 ******************************************************************************/

#[derive(Debug, Copy, Clone, BitFlags)]
#[repr(u8)]
pub enum ActorFlag {
    Visualization = 1,
    DisableGravity = 2,
    SendSleepNotifies = 4,
    DisableSimulation = 8,
}

impl Into<PxActorFlag::Enum> for ActorFlag {
    fn into(self) -> PxActorFlag::Enum {
        match self {
            ActorFlag::Visualization => 1,
            ActorFlag::DisableGravity => 2,
            ActorFlag::SendSleepNotifies => 4,
            ActorFlag::DisableSimulation => 8,
        }
    }
}

impl From<PxActorFlag::Enum> for ActorFlag {
    fn from(other: PxActorFlag::Enum) -> Self {
        match other {
            1 => ActorFlag::Visualization,
            2 => ActorFlag::DisableGravity,
            4 => ActorFlag::SendSleepNotifies,
            8 => ActorFlag::DisableSimulation,
            _ => unreachable!("InvalidActorFlag"),
        }
    }
}

impl <T> Actor for T where T: Class<PxActor> + Base {}
pub trait Actor: Class<PxActor> + Base {
    /*
    fixme[tolsson]: when I tried implementing these it had no effect, and it
        introduces a risk of memory leaks since physx does not copy the data, so
        we need to convert a string into an OsString and then not recover it
        until some later point. For types that define a userData, it is much
        safer to define it there.

    pub fn setName(&mut self, name: &str)  {PxActor_setName_mut(self.as_mut_ptr(), name) }
    pub fn getName(&self) -> *const i8  {PxActor_getName(self.as_ptr())}
     */

    /// Release this actor
    unsafe fn release(&mut self) {
        PxActor_release_mut(self.as_mut_ptr())
    }

    /// Get the actual type of the actor
    fn get_type(&self) -> PxActorType::Enum {
        unsafe { PxActor_getType(self.as_ptr()) }
    }

    /// Get the world bounds of this actor
    fn get_world_bounds(&self, inflation: f32) -> PxBounds3 {
        unsafe { PxActor_getWorldBounds(self.as_ptr(), inflation).into() }
    }

    /// Set a flag on this actor
    fn set_actor_flag(&mut self, flag: ActorFlag, value: bool) {
        unsafe { PxActor_setActorFlag_mut(self.as_mut_ptr(), flag.into(), value) }
    }

    /// Set the flags to the provided value
    fn set_actor_flags(&mut self, flags: BitFlags<ActorFlag>) {
        unsafe {
            PxActor_setActorFlags_mut(
                self.as_mut_ptr(),
                PxActorFlags {
                    mBits: flags.bits(),
                },
            )
        }
    }

    /// Get all actor flags
    fn get_actor_flags(&self) -> PxActorFlags {
        unsafe { PxActor_getActorFlags(self.as_ptr()) }
    }

    /// Set the dominance group
    fn set_dominance_group(&mut self, group: u8) {
        unsafe { PxActor_setDominanceGroup_mut(self.as_mut_ptr(), group) }
    }

    /// Read the dominance group
    fn get_dominance_group(&self) -> u8 {
        unsafe { PxActor_getDominanceGroup(self.as_ptr()) }
    }

    /// Set the owner client of this actor
    fn set_owner_client(&mut self, client: u8) {
        unsafe { PxActor_setOwnerClient_mut(self.as_mut_ptr(), client) }
    }

    /// Read the owner client of this actor
    fn get_owner_client(&self) -> u8 {
        unsafe { PxActor_getOwnerClient(self.as_ptr()) }
    }

    /// Enable visualization of this actor
    fn enable_visualization(&mut self, enable: bool) {
        unsafe {
            PxActor_setActorFlag_mut(self.as_mut_ptr(), PxActorFlag::eVISUALIZATION, enable);
        }
    }

    /// set gravity state
    fn enable_gravity(&mut self, enable: bool) {
        unsafe {
            PxActor_setActorFlag_mut(self.as_mut_ptr(), PxActorFlag::eDISABLE_GRAVITY, !enable);
        }
    }
}

#[repr(transparent)]
pub struct ActorMap<L, S, D, H, M> {
    obj: *mut physx_sys::PxActor,
    phantom_user_data: PhantomData<(L, S, D, H, M)>,
}

unsafe impl<P, L, S, D, H, M> Class<P> for ActorMap<L, S, D, H, M> where physx_sys::PxActor: Class<P> {
    fn as_ptr(&self) -> *const P {
        self.obj as *const _ as *const _
    }

    fn as_mut_ptr(&mut self) -> *mut P {
        self.obj as *mut _
    }
}

impl<L, S, D, H, M> ActorMap<L, S, D, H, M> {
    pub fn map<'a, Ret: 'a, RDFn, RSFn, ALFn>(
        &'a mut self,
        rigid_dynamic_fn: RDFn,
        rigid_static_fn: RSFn,
        articulation_link_fn: ALFn,
    ) -> Ret
    where
        RDFn: FnOnce(&'a mut RigidDynamic<D, H, M>) -> Ret,
        RSFn: FnOnce(&'a mut RigidStatic<S, H, M>) -> Ret,
        ALFn: FnOnce(&'a mut ArticulationLink<L, H, M>) -> Ret
    {
        match self.get_concrete_type() {
            crate::base::ConcreteType::RigidDynamic => {
                rigid_dynamic_fn(
                    unsafe {
                        &mut*(self.obj as *mut RigidDynamic<D, H, M>)
                    }
                )
            }
            crate::base::ConcreteType::RigidStatic => {
                rigid_static_fn(
                    unsafe {
                        &mut*(self.obj as *mut RigidStatic<S, H, M>)
                    }
                )
            }
            crate::base::ConcreteType::ArticulationLink => {
                articulation_link_fn(
                    unsafe {
                        &mut*(self.obj as *mut ArticulationLink<L, H, M>)
                    }
                )
            }
            _ => unreachable!(),
        }
    }

    /// Tries to cast to RigidStatic.
    pub fn as_rigid_static(&mut self) -> Option<&mut RigidStatic<S, H, M>> {
        match self.get_concrete_type() {
            crate::base::ConcreteType::RigidStatic => {
                unsafe {
                    Some(&mut*(self.obj as *mut RigidStatic<S, H, M>))
                }
            }
            _ => None,
        }
    }

    /// Tries to cast to RigidDynamic.
    pub fn as_rigid_dynamic(&mut self) -> Option<&mut RigidDynamic<D, H, M>> {
        match self.get_concrete_type() {
            crate::base::ConcreteType::RigidDynamic => {
                unsafe {
                    Some(&mut*(self.obj as *mut RigidDynamic<D, H, M>))
                }
            }
            _ => None,
        }
    }

    /// Tries to cast to ArticulationLink.
    pub fn as_articulation_link(&mut self) -> Option<&mut ArticulationLink<L, H, M>> {
        match self.get_concrete_type() {
            crate::base::ConcreteType::ArticulationLink => {
                unsafe {
                    Some(&mut*(self.obj as *mut ArticulationLink<L, H, M>))
                }
            }
            _ => None,
        }
    }
}