// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 10 April 2019

#![warn(clippy::all)]

/*!
Utility for handle-based usage
*/

/// The type of actor pointed to by a handle, used primarily for internal tracking.
#[derive(Debug, Clone, Copy, PartialEq)]
pub enum ActorType {
    Unknown, // a necessary evil until we remove ambigious type handle creation (specifically creating handles from raw PxRigidActor ptrs)
    Static,
    Dynamic,
    ArticulationLink(ArticulationHandle),
}

/// A handle associated with an actor. Also contains some type information.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct ActorHandle(pub usize, pub ActorType);

/// A handle associated with an articulation
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct ArticulationHandle(pub usize);
