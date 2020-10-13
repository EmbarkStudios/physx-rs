// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 16 April 2019

#![warn(clippy::all)]

/*!
Trait for PxActor
 */

use super::{base::Base, math::*, px_type::*};
use enumflags2::*;
use physx_macros::*;
use physx_sys::{
    PxActor, PxActorFlag, PxActorFlags, PxActorType, PxActor_getActorFlags, PxActor_getAggregate,
    PxActor_getDominanceGroup, PxActor_getOwnerClient, PxActor_getScene, PxActor_getType,
    PxActor_getWorldBounds, PxActor_release_mut, PxActor_setActorFlag_mut,
    PxActor_setActorFlags_mut, PxActor_setDominanceGroup_mut, PxActor_setOwnerClient_mut,
    PxAggregate, PxScene,
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

#[physx_type(inherit = "Base")]
impl Actor {
    /*
    fixme[tolsson]: when I tried implementing these it had no effect, and it
        introduces a risk of memory leaks since physx does not copy the data, so
        we need to convert a string into an OsString and then not recover it
        until some later point. For types that define a userData, it is much
        safer to define it there.

    pub fn setName(&mut self, name: &str)  {PxActor_setName_mut(self.get_raw_mut(), name) }
    pub fn getName(&self) -> *const i8  {PxActor_getName(self.get_raw())}
     */

    /// Release this actor
    pub fn release(&mut self) {
        unsafe { PxActor_release_mut(self.get_raw_mut()) }
    }

    /// Get the actual type of the actor
    pub fn get_type(&self) -> PxActorType::Enum {
        unsafe { PxActor_getType(self.get_raw()) }
    }

    /// Get the scene this Actor is part of
    pub fn get_scene(&self) -> *mut PxScene {
        unsafe { PxActor_getScene(self.get_raw()) }
    }

    /// Get the world bounds of this actor
    pub fn get_world_bounds(&self, inflation: f32) -> Bounds {
        unsafe { PxActor_getWorldBounds(self.get_raw(), inflation).into() }
    }

    /// Set a flag on this actor
    pub fn set_actor_flag(&mut self, flag: ActorFlag, value: bool) {
        unsafe { PxActor_setActorFlag_mut(self.get_raw_mut(), flag.into(), value) }
    }

    /// Set the flags to the provided value
    pub fn set_actor_flags(&mut self, flags: BitFlags<ActorFlag>) {
        unsafe {
            PxActor_setActorFlags_mut(
                self.get_raw_mut(),
                PxActorFlags {
                    mBits: flags.bits(),
                },
            )
        }
    }

    /// Get all actor flags
    pub fn get_actor_flags(&self) -> PxActorFlags {
        unsafe { PxActor_getActorFlags(self.get_raw()) }
    }

    /// Set the dominance group
    pub fn set_dominance_group(&mut self, group: u8) {
        unsafe { PxActor_setDominanceGroup_mut(self.get_raw_mut(), group) }
    }

    /// Read the dominance group
    pub fn get_dominance_group(&self) -> u8 {
        unsafe { PxActor_getDominanceGroup(self.get_raw()) }
    }

    /// Set the owner client of this actor
    pub fn set_owner_client(&mut self, client: u8) {
        unsafe { PxActor_setOwnerClient_mut(self.get_raw_mut(), client) }
    }

    /// Read the owner client of this actor
    pub fn get_owner_client(&self) -> u8 {
        unsafe { PxActor_getOwnerClient(self.get_raw()) }
    }

    /// Get the aggregate this actor belongs to
    pub fn get_aggregate(&self) -> *mut PxAggregate {
        unsafe { PxActor_getAggregate(self.get_raw()) }
    }

    /// Enable visualization of this actor
    pub fn enable_visualization(&mut self, enable: bool) {
        unsafe {
            PxActor_setActorFlag_mut(self.get_raw_mut(), PxActorFlag::eVISUALIZATION, enable);
        }
    }

    /// set gravity state
    pub fn enable_gravity(&mut self, enable: bool) {
        unsafe {
            PxActor_setActorFlag_mut(self.get_raw_mut(), PxActorFlag::eDISABLE_GRAVITY, !enable);
        }
    }
}
