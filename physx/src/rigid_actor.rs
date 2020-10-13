// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 15 April 2019

#![warn(clippy::all)]

/*!
Trait for RigidActor
 */

use super::{
    actor::Actor,
    body::BodyHandle,
    geometry::*,
    px_type::*,
    shape::CollisionLayer,
    shape::Shape,
    traits::*,
    transform::{gl_to_px_tf, px_to_gl_tf, px_to_gl_v3},
    user_data::UserData,
};
use enumflags2::BitFlags;
use glam::{Mat4, Vec3};
use physx_macros::physx_type;
use physx_sys::{
    phys_PxGetPhysics, PxContactPair, PxContactPairPoint, PxContactPair_extractContacts,
    PxPhysics_createMaterial_mut, PxRigidActor, PxRigidActorExt_createExclusiveShape_mut_1,
    PxRigidActor_detachShape_mut, PxRigidActor_getGlobalPose, PxRigidActor_getNbShapes,
    PxRigidActor_getShapes, PxRigidActor_setGlobalPose_mut, PxShapeExt_getGlobalPose_mut,
    PxShapeFlag, PxShapeFlags, PxShape_setLocalPose_mut,
};

use std::ptr::null_mut;

#[physx_type(inherit = "Actor")]
impl RigidActor {
    pub fn new(px_link: *mut PxRigidActor) -> Self {
        let mut _self = Self::from_ptr(px_link);
        _self.allocate_user_data();
        _self
    }

    /// Get a handle which can later be converted back into this body via the Scene.
    pub fn handle(&self) -> BodyHandle {
        BodyHandle(self.get_raw() as usize)
    }

    /// Get the global pose of this rigid actor
    pub fn get_global_pose(&self) -> Mat4 {
        px_to_gl_tf(unsafe { PxRigidActor_getGlobalPose(self.get_raw()) })
    }

    /// Get the global pose of this rigid actor
    pub fn get_global_position(&self) -> Vec3 {
        px_to_gl_v3(unsafe { PxRigidActor_getGlobalPose(self.get_raw()).p })
    }

    /// Set the global pose of this rigid actor
    pub fn set_global_pose(&mut self, pose: Mat4, autowake: bool) {
        unsafe {
            PxRigidActor_setGlobalPose_mut(self.get_raw_mut(), &gl_to_px_tf(pose), autowake);
        }
    }

    /// Get number of attached shapes
    pub fn get_nb_shapes(&self) -> u32 {
        unsafe { PxRigidActor_getNbShapes(self.get_raw()) }
    }

    /// Get transform for shape with index
    pub fn get_shape_transform(&self, index: u32) -> Mat4 {
        assert!(
            index < self.get_nb_shapes(),
            "shape index out of bounds: {} >= {}",
            index,
            self.get_nb_shapes()
        );

        unsafe {
            /* todo[tolsson]: We can use self.get_global_pose() * shape.get_local_pose() */
            let mut buffer = [null_mut(); 1];
            PxRigidActor_getShapes(self.get_raw(), buffer.as_mut_ptr(), 1, index);

            px_to_gl_tf(PxShapeExt_getGlobalPose_mut(buffer[0], self.get_raw()))
        }
    }

    /// Get a wrapped instance of every Shape attached to this actor.
    pub fn get_shapes(&self) -> Vec<Shape> {
        let nb_shapes = self.get_nb_shapes();
        let mut buffer = vec![null_mut(); nb_shapes as usize];
        unsafe {
            PxRigidActor_getShapes(self.get_raw(), buffer.as_mut_ptr(), nb_shapes, 0);
        }
        buffer.into_iter().map(Shape::from_ptr).collect()
    }

    /// Set the collision filter. Collisions will only occur if this_layers & other_layers != 0.
    pub fn set_collision_filter(
        &mut self,
        this_layers: BitFlags<CollisionLayer>,
        other_layers: BitFlags<CollisionLayer>,
        word3: u32,
        word4: u32,
    ) {
        for mut shape in self.get_shapes() {
            shape.set_simulation_filter_data(this_layers, other_layers, word3, word4);
        }
    }

    /// Set the query filter. Queries will only find this item if queried with one of the flags.
    pub fn set_query_filter(&mut self, this_layers: BitFlags<CollisionLayer>) {
        for mut shape in self.get_shapes() {
            shape.set_query_filter_data(this_layers);
        }
    }

    pub fn detach_shape(&mut self, shape: &mut Shape) {
        unsafe { PxRigidActor_detachShape_mut(self.get_raw_mut(), shape.get_raw_mut(), true) };
    }

    pub fn create_exclusive_shape(
        &mut self,
        geometry: PhysicsGeometry,
        orientation: Mat4,
        translation: Mat4,
    ) {
        let shapeflags = PxShapeFlags {
            mBits: (PxShapeFlag::eVISUALIZATION | PxShapeFlag::eSIMULATION_SHAPE) as u8,
        };

        unsafe {
            let mtrl = PxPhysics_createMaterial_mut(phys_PxGetPhysics(), 0.9, 0.9, 0.0);
            let angle = f32::to_radians(-90.0);
            let rotation = if geometry.get_type() == GeometryType::Capsule {
                Mat4::from_axis_angle(Vec3::unit_y(), angle)
            } else {
                Mat4::identity()
            };

            let shape = PxRigidActorExt_createExclusiveShape_mut_1(
                self.get_raw_mut(),
                geometry.as_raw(),
                mtrl,
                shapeflags,
            );

            PxShape_setLocalPose_mut(shape, &gl_to_px_tf((translation * orientation) * rotation));
        };
    }

    pub(crate) fn allocate_user_data(&mut self) {
        let userdata = Box::new(UserData::new_rigid_actor());
        unsafe {
            (*self.ptr).userData = Box::into_raw(userdata) as *mut std::ffi::c_void;
        }
    }

    pub fn user_data(&self) -> &UserData {
        unsafe { &*((*self.ptr).userData as *const UserData) }
    }

    pub fn user_data_mut(&mut self) -> &mut UserData {
        unsafe { &mut *((*self.ptr).userData as *mut UserData) }
    }
}

impl Collidable for RigidActor {
    fn on_collide(&mut self, other: &RigidActor, pairs: &[PxContactPair]) {
        // Fixme in the future
        let this_data = self.get_shapes()[0].get_simulation_filter_data();
        let other_data = other.get_shapes()[0].get_simulation_filter_data();

        // Intersect collision masks (n.b. assymetric)
        if (this_data.word0 & other_data.word1) == 0 {
            return;
        }

        let count = pairs
            .iter()
            .fold(0, |acc, pair| acc + pair.contactCount as usize);

        let user_data = match self.user_data_mut() {
            UserData::RigidActor(data) => data,
            _ => unimplemented!(),
        };

        let collision_points = &mut user_data.collision_points;
        unsafe {
            collision_points.reserve(count);
            collision_points.set_len(count);
        }

        let mut offset = 0;
        for pair in pairs {
            let slice = &mut collision_points[offset..offset + pair.contactCount as usize];
            unsafe {
                PxContactPair_extractContacts(
                    pair as *const _,
                    slice.as_ptr() as *mut PxContactPairPoint,
                    u32::from(pair.contactCount),
                );
            }
            offset += pair.contactCount as usize;
        }

        user_data.has_collide = true;
    }

    fn reset_collide(&mut self) {
        let user_data = match self.user_data_mut() {
            UserData::RigidActor(data) => data,
            _ => unimplemented!(),
        };

        user_data.collision_points.clear();
        user_data.has_collide = false;
    }

    fn has_collide(&self) -> bool {
        let user_data = match self.user_data() {
            UserData::RigidActor(data) => data,
            _ => unimplemented!(),
        };

        user_data.has_collide
    }

    fn read_collision_points(&self) -> &[PxContactPairPoint] {
        match self.user_data() {
            UserData::RigidActor(data) => data.collision_points.as_slice(),
            _ => unimplemented!(),
        }
    }
}

impl Releasable for RigidActor {
    fn release(&mut self) {
        unsafe {
            Box::from_raw((*self.ptr).userData as *mut UserData);
        }
    }
}
