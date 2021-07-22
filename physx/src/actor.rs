// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 16 April 2019

#![warn(clippy::all)]

/*!
Trait for PxActor
 */

use crate::{
    articulation_link::ArticulationLink,
    base::Base,
    math::*,
    rigid_actor::RigidActor,
    rigid_dynamic::RigidDynamic,
    rigid_static::RigidStatic,
    traits::{Class, PxFlags},
};
use enumflags2::{bitflags, BitFlags};

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
    PxActor_setActorFlags_mut,
    PxActor_setDominanceGroup_mut,
    PxActor_setOwnerClient_mut,
    // PxActor_release_mut,
    // PxActor_getScene,
    //  PxActor_getAggregate,
    //  PxActor_getName,
    //  PxActor_setName_mut,
};

/*
* Define PxAggerate
* Define PxScene conversion
*/

pub type ActorFlags = BitFlags<ActorFlag>;

impl PxFlags for ActorFlags {
    type Target = PxActorFlags;

    fn into_px(self) -> Self::Target {
        PxActorFlags { mBits: self.bits() }
    }

    fn from_px(flags: Self::Target) -> Self {
        BitFlags::from_bits_truncate(flags.mBits)
    }
}

impl<T> Actor for T where T: Class<PxActor> + Base {}

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
    /// Get the concrete type of the actor
    fn get_type(&self) -> ActorType {
        unsafe { PxActor_getType(self.as_ptr()).into() }
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
    fn get_actor_flags(&self) -> BitFlags<ActorFlag> {
        unsafe { PxFlags::from_px(PxActor_getActorFlags(self.as_ptr())) }
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

/// A wrapper for PxActor or PxRigidActor objects that implements `RigidActor`.
/// It is parametrized by the ArticulationLink, RigidStatic, and RigidDynamic types,
/// use `as_articulation_link` and co. or `cast_map` to cast to them safely.
#[repr(transparent)]
pub struct ActorMap<L, S, D>
where
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,
{
    obj: physx_sys::PxRigidActor,
    phantom_user_data: PhantomData<(*const L, *const S, *const D)>,
}

unsafe impl<P, L, S, D> Class<P> for ActorMap<L, S, D>
where
    // All PxActor's are PxRigidActor's, might as well get the additional API
    physx_sys::PxRigidActor: Class<P>,
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,
{
    fn as_ptr(&self) -> *const P {
        self.obj.as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut P {
        self.obj.as_mut_ptr()
    }
}

impl<L, S, D> RigidActor for ActorMap<L, S, D>
where
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,
{
    type Shape = L::Shape;
}

impl<L, S, D> ActorMap<L, S, D>
where
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,
{
    /// Cast to the most-derived type as determined by `get_type`, which returns the ActorType.
    /// Because this does not use `get_concrete_type`, this method does not have the safety
    /// concerns of the other `cast_map`s, and a `try_cast_map` method is unneded.
    pub fn cast_map<'a, Ret, ALFn, RSFn, RDFn>(
        &'a mut self,
        mut articulation_link_fn: ALFn,
        mut rigid_static_fn: RSFn,
        mut rigid_dynamic_fn: RDFn,
    ) -> Ret
    where
        ALFn: FnMut(&'a mut L) -> Ret,
        RSFn: FnMut(&'a mut S) -> Ret,
        RDFn: FnMut(&'a mut D) -> Ret,
    {
        // This uses get_type not get_concrete_type because get_concrete_type does not seem to
        // work for actors retrieved via get_active_actors.
        match self.get_type() {
            ActorType::RigidDynamic => {
                rigid_dynamic_fn(unsafe { &mut *(self as *mut _ as *mut D) })
            }
            ActorType::RigidStatic => rigid_static_fn(unsafe { &mut *(self as *mut _ as *mut S) }),
            ActorType::ArticulationLink => {
                articulation_link_fn(unsafe { &mut *(self as *mut _ as *mut L) })
            }
        }
    }

    /// Tries to cast to RigidDynamic.
    pub fn as_rigid_dynamic(&mut self) -> Option<&mut D> {
        match self.get_type() {
            ActorType::RigidDynamic => unsafe { Some(&mut *(self as *mut _ as *mut D)) },
            _ => None,
        }
    }

    /// Tries to cast to RigidStatic.
    pub fn as_rigid_static(&mut self) -> Option<&mut S> {
        match self.get_type() {
            ActorType::RigidStatic => unsafe { Some(&mut *(self as *mut _ as *mut S)) },
            _ => None,
        }
    }

    /// Tries to cast to ArticulationLink.
    pub fn as_articulation_link(&mut self) -> Option<&mut L> {
        match self.get_type() {
            ActorType::ArticulationLink => unsafe { Some(&mut *(self as *mut _ as *mut L)) },
            _ => None,
        }
    }
}

/*******************************************************************************
 * Section ENUMS                                                               *
******************************************************************************/

#[derive(Debug, Copy, Clone)]
#[repr(u32)]
pub enum ActorType {
    RigidStatic = 0,
    RigidDynamic = 1,
    ArticulationLink = 2,
}

impl From<ActorType> for PxActorType::Enum {
    fn from(value: ActorType) -> Self {
        value as u32
    }
}

impl From<PxActorType::Enum> for ActorType {
    fn from(ty: PxActorType::Enum) -> Self {
        match ty {
            0 => ActorType::RigidStatic,
            1 => ActorType::RigidDynamic,
            2 => ActorType::ArticulationLink,
            _ => panic!("invalid enum variant"),
        }
    }
}

#[bitflags]
#[derive(Debug, Copy, Clone)]
#[repr(u8)]
pub enum ActorFlag {
    Visualization = 1,
    DisableGravity = 2,
    SendSleepNotifies = 4,
    DisableSimulation = 8,
}

impl From<ActorFlag> for PxActorFlag::Enum {
    fn from(value: ActorFlag) -> Self {
        match value {
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
