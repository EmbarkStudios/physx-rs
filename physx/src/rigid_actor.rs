// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 15 April 2019

#![warn(clippy::all)]

/*!
Trait for RigidActor
 */

use super::{
    actor::Actor,
    constraint::Constraint,
    math::{PxQuat, PxTransform, PxVec3},
    shape::CollisionLayer,
    shape::Shape,
    traits::Class,
};
use enumflags2::BitFlags;

use physx_sys::{
    PxRigidActor,
    //PxContactPair,
    //PxContactPairPoint,
    PxRigidActor_attachShape_mut,
    PxRigidActor_detachShape_mut,
    PxRigidActor_getConstraints,
    PxRigidActor_getGlobalPose,
    PxRigidActor_getNbConstraints,
    PxRigidActor_getNbShapes,
    PxRigidActor_getShapes,
    PxRigidActor_setGlobalPose_mut,
    //PxRigidActor_release_mut,
};

pub trait RigidActor: Class<PxRigidActor> + Actor {
    type Shape: Shape;

    /// Get the number of constraints on this rigid actor.
    fn get_nb_constraints(&self) -> u32 {
        unsafe { PxRigidActor_getNbConstraints(self.as_ptr()) }
    }

    /// Get the constraints effecting this rigid actor.
    fn get_constraints(&mut self) -> Vec<&mut Constraint> {
        let capacity = self.get_nb_constraints();
        let mut buffer: Vec<&mut Constraint> = Vec::with_capacity(capacity as usize);
        unsafe {
            let len = PxRigidActor_getConstraints(
                self.as_ptr(),
                buffer.as_mut_ptr() as *mut *mut _,
                capacity,
                0,
            );
            buffer.set_len(len as usize);
        }
        buffer
    }

    /// Get the global pose of this rigid actor. The scale is implicitly 1.0.
    fn get_global_pose(&self) -> PxTransform {
        unsafe { PxRigidActor_getGlobalPose(self.as_ptr()).into() }
    }

    /// Get the global pose of this rigid actor.
    fn get_global_position(&self) -> PxVec3 {
        unsafe { PxRigidActor_getGlobalPose(self.as_ptr()).p.into() }
    }

    /// Get the global rotation of this rigid actor.
    fn get_global_rotation(&self) -> PxQuat {
        unsafe { PxRigidActor_getGlobalPose(self.as_ptr()).q.into() }
    }

    /// Set the global pose of this rigid actor
    fn set_global_pose(&mut self, pose: &PxTransform, autowake: bool) {
        unsafe {
            PxRigidActor_setGlobalPose_mut(self.as_mut_ptr(), pose.as_ptr(), autowake);
        }
    }

    /// Get number of attached shapes
    fn get_nb_shapes(&self) -> u32 {
        unsafe { PxRigidActor_getNbShapes(self.as_ptr()) }
    }

    /// Get a reference to every Shape attached to this actor.
    fn get_shapes(&self) -> Vec<&Self::Shape> {
        let capacity = self.get_nb_shapes();
        let mut buffer: Vec<&Self::Shape> = Vec::with_capacity(capacity as usize);
        unsafe {
            let len = PxRigidActor_getShapes(
                self.as_ptr(),
                buffer.as_mut_ptr() as *mut *mut _,
                capacity,
                0,
            );
            buffer.set_len(len as usize);
        }
        buffer
    }

    /// Get a mutable reference to every Shape attached to this actor.
    fn get_shapes_mut(&mut self) -> Vec<&mut Self::Shape> {
        let capacity = self.get_nb_shapes();
        let mut buffer: Vec<&mut Self::Shape> = Vec::with_capacity(capacity as usize);
        unsafe {
            let len = PxRigidActor_getShapes(
                self.as_ptr(),
                buffer.as_mut_ptr() as *mut *mut _,
                capacity,
                0,
            );
            buffer.set_len(len as usize);
        }
        buffer
    }

    /// Set the collision filter. Collisions will only occur if this_layers & other_layers != 0.
    fn set_collision_filter(
        &mut self,
        this_layers: BitFlags<CollisionLayer>,
        other_layers: BitFlags<CollisionLayer>,
        word3: u32,
        word4: u32,
    ) {
        for shape in self.get_shapes_mut() {
            shape.set_simulation_filter_data(this_layers, other_layers, word3, word4);
        }
    }

    /// Set the query filter. Queries will only find this item if queried with one of the flags.
    fn set_query_filter(&mut self, this_layers: BitFlags<CollisionLayer>) {
        for shape in self.get_shapes_mut() {
            shape.set_query_filter_data(this_layers);
        }
    }

    /// Attach a shape.
    fn attach_shape(&mut self, shape: &mut Self::Shape) -> bool {
        unsafe { PxRigidActor_attachShape_mut(self.as_mut_ptr(), shape.as_mut_ptr()) }
    }

    /// Detach a shape.
    fn detach_shape(&mut self, shape: &mut Self::Shape) {
        unsafe { PxRigidActor_detachShape_mut(self.as_mut_ptr(), shape.as_mut_ptr(), true) };
    }
}
