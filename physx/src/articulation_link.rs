// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created:  2 April 2019

#![warn(clippy::all)]

/*!
A link of a reduced coordinate multibody.
 */

use super::{
    articulation_base::ArticulationBase,
    articulation_joint_base::*,
    articulation_reduced_coordinate::ArticulationReducedCoordinate,
    body::PartHandle,
    geometry::*,
    math::Isometry,
    px_type::*,
    rigid_actor::RigidActor,
    rigid_body::RigidBody,
    shape::ShapeFlag,
    traits::{Collidable, Releasable},
    user_data::UserData,
};
use glam::{Mat4, Quat, Vec3};
use log::*;
use physx_macros::*;
use physx_sys::*;

////////////////////////////////////////////////////////////////////////////////
// Section ENUMS
////////////////////////////////////////////////////////////////////////////////

#[derive(Debug, Clone, Copy)]
pub enum ArticulationDriveType {
    Acceleration,
    Force,
}

impl Into<PxArticulationDriveType::Enum> for ArticulationDriveType {
    fn into(self) -> PxArticulationDriveType::Enum {
        match self {
            ArticulationDriveType::Acceleration => PxArticulationDriveType::eACCELERATION,
            ArticulationDriveType::Force => PxArticulationDriveType::eFORCE,
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
// Section ArticulationLink
////////////////////////////////////////////////////////////////////////////////

/// Link in a reduced coordinate (multibody) tree
/// N.b., with PhysX the position of the transform of the link is parametrized by the
/// joint that connects it to the parent. It does not itself have a transform.

impl Collidable for ArticulationLink {
    fn on_collide(&mut self, other: &RigidActor, pairs: &[PxContactPair]) {
        let this_data = self.get_shapes()[0].get_simulation_filter_data();
        let other_data = other.get_shapes()[0].get_simulation_filter_data();

        // Intersect collision masks (n.b. assymetric)
        if (this_data.word0 & other_data.word1) == 0 {
            return;
        }

        // for multibodies, we use upper two words for pointer-wise to not trigger self-collisions
        if this_data.word2 == other_data.word2 && this_data.word3 == other_data.word3 {
            return;
        }

        let count = pairs
            .iter()
            .fold(0, |acc, pair| acc + pair.contactCount as usize);

        let user_data = match self.user_data_mut() {
            UserData::RigidActor(data) => data,
            _ => unimplemented!("not handled yet"),
        };

        unsafe {
            let vec = &mut user_data.collision_points;
            vec.clear();
            vec.reserve(count);
            vec.set_len(count);
        }

        let mut offset = 0;
        for pair in pairs {
            let slice =
                &mut user_data.collision_points[offset..offset + pair.contactCount as usize];
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

////////////////////////////////////////////////////////////////////////////////

#[physx_type(inherit = "RigidBody")]
impl ArticulationLink {
    pub fn new(px_link: *mut PxArticulationLink) -> Self {
        let userdata = Box::new(UserData::new_rigid_actor());
        let mut _self = Self::from_ptr(px_link);
        unsafe {
            (*_self.ptr).userData = Box::into_raw(userdata) as *mut std::ffi::c_void;
        }
        _self
    }

    pub fn name(&self) -> &str {
        match self.user_data() {
            UserData::RigidActor(data) => &data.name,
            _ => &"None",
        }
    }

    /// Enable collisions for this link. Equivalent to setting SimulationShape to false for all attached shapes.
    pub fn enable_collision(&mut self, enable: bool) {
        for shape in self.get_shapes().iter_mut() {
            shape.set_flag(ShapeFlag::SimulationShape, enable);
        }
    }

    /// Get a handle to this part
    pub fn handle(&self) -> PartHandle {
        PartHandle(
            self.get_articulation().ptr as usize,
            self.get_raw() as usize,
        )
    }

    /// Get inbound joint for this link
    pub fn inbound_joint(&self) -> Option<ArticulationJointBase> {
        let joint = unsafe { PxArticulationLink_getInboundJoint(self.get_raw()) };

        if joint.is_null() {
            None
        } else {
            Some(ArticulationJointBase::from_ptr(joint))
        }
    }

    pub fn get_link_index(&self) -> usize {
        unsafe { PxArticulationLink_getLinkIndex(self.get_raw()) as usize }
    }

    pub fn get_inbound_joint_dof(&self) -> usize {
        unsafe { PxArticulationLink_getInboundJointDof(self.get_raw()) as usize }
    }

    /// Checks if this is the root link of the articulation
    pub fn is_root(&self) -> bool {
        self.inbound_joint().is_none()
    }

    pub fn is_end_effector(&self) -> bool {
        unsafe { PxArticulationLink_getNbChildren(self.get_raw()) == 0 }
    }

    pub fn get_articulation(&self) -> ArticulationBase {
        unsafe { ArticulationBase::from_ptr(PxArticulationLink_getArticulation(self.get_raw())) }
    }
}

////////////////////////////////////////////////////////////////////////////////
// Section BUILDER
////////////////////////////////////////////////////////////////////////////////

pub struct ArticulationLinkBuilder {
    pub(super) parent_offset: Vec3,
    pub(super) parent_rotation: Quat,
    pub(super) name: String,
    mass: f32,

    inertia_tensor: [f32; 6],
    pub collider_transform: Mat4,
    pub collider: Option<ColliderDesc>,
}

////////////////////////////////////////////////////////////////////////////////

impl Default for ArticulationLinkBuilder {
    fn default() -> Self {
        Self {
            parent_offset: Vec3::zero(),
            parent_rotation: Quat::identity(),
            name: String::from(""),
            mass: 1.0,
            inertia_tensor: [0.0; 6],

            collider_transform: Mat4::identity(),

            collider: None,
        }
    }
}

impl ArticulationLinkBuilder {
    pub fn build(
        &self,
        body: &mut ArticulationReducedCoordinate,
        parent: PartHandle,
        joint_transform: Option<Mat4>,
    ) -> PartHandle {
        let parent_quat = self.parent_rotation;

        let transform = Mat4::from_rotation_translation(parent_quat, self.parent_offset);
        let raw_link = body.create_link(parent, Some(transform), joint_transform);

        let mut link = ArticulationLink::new(raw_link);
        if let UserData::RigidActor(data) = link.user_data_mut() {
            data.name = self.name.clone();
        }

        if let Some(ref collider) = self.collider {
            let geometry: PhysicsGeometry = collider.into();
            let collider_pose = Isometry::from_mat4(&self.collider_transform);

            let collider_orientation: Mat4 = collider_pose.rotation;
            let collider_translation: Mat4 = collider_pose.translation;

            link.create_exclusive_shape(geometry, collider_orientation, collider_translation);
        } else {
            trace!("link count: {}", link.get_nb_shapes())
        }
        link.set_mass(self.mass);
        let handle = link.handle();
        body.add_link(link);
        handle
    }

    ////////////////////////////////////////////////////////////////////////////////

    pub fn set_name(&mut self, name: &str) {
        self.name = name.to_owned()
    }

    pub fn name(mut self, name: &str) -> Self {
        self.name = name.to_owned();
        self
    }

    pub fn parent_shift(mut self, parent_offset: Vec3) -> Self {
        self.parent_offset = parent_offset;
        self
    }

    pub fn parent_rotation(mut self, parent_rotation: Quat) -> Self {
        self.parent_rotation = parent_rotation;
        self
    }

    pub fn mass(mut self, mass: f32) -> Self {
        self.mass = mass;
        self
    }

    pub fn inertia_tensor(
        mut self,
        ixx: f32,
        ixy: f32,
        ixz: f32,
        iyy: f32,
        iyz: f32,
        izz: f32,
    ) -> Self {
        self.inertia_tensor = [ixx, ixy, ixz, iyy, iyz, izz];
        self
    }

    /// Add geometry with "transform" relative to link origin
    pub fn add_geometry(mut self, trans: Mat4, coll: ColliderDesc) -> Self {
        self.collider_transform = trans;
        self.collider = Some(coll);
        self
    }
}

impl Releasable for ArticulationLink {
    fn release(&mut self) {
        unsafe {
            Box::from_raw((*self.ptr).userData as *mut UserData);

            for shape in self.get_shapes() {
                for mtrl in shape.get_materials() {
                    PxMaterial_release_mut(mtrl);
                }
            }
            PxArticulationLink_release_mut(self.get_raw_mut());
        }
    }
}
