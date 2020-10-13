// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 12 June 2019

#![warn(clippy::all)]

/*!

*/
use super::super::rigid_actor::RigidActor;
use physx_sys::{PxContactPair, PxContactPairPoint};

pub trait Collidable {
    fn on_collide(&mut self, other: &RigidActor, pairs: &[PxContactPair]);
    fn reset_collide(&mut self);
    fn has_collide(&self) -> bool;
    fn read_collision_points(&self) -> &[PxContactPairPoint];
}
