// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 12 June 2019

#![warn(clippy::all)]

/*!

*/

use super::articulation_link::ArticulationLink;
use physx_sys::PxContactPairPoint;

/*******************************************************************************
 * Section RIGIDACTORUSERDATA                                                  *
 ******************************************************************************/

pub struct RigidActorUserData {
    pub name: String,
    pub has_collide: bool,
    pub collision_points: Vec<PxContactPairPoint>,
}

impl Default for RigidActorUserData {
    fn default() -> Self {
        Self {
            name: String::from(""),
            has_collide: false,
            collision_points: Vec::new(),
        }
    }
}

/*******************************************************************************
 * Section ARTICULATIONBASEUSERDATA                                            *
 ******************************************************************************/

pub struct ArticulationBaseUserData {
    pub links: Vec<ArticulationLink>,
}

impl Default for ArticulationBaseUserData {
    fn default() -> Self {
        Self { links: Vec::new() }
    }
}

/*******************************************************************************
 * Section SCENEUSERDATA                                            *
 ******************************************************************************/

pub struct SceneUserData {
    // px_scene: RwLock<()>,
// bodies: Vec<ArticulationReducedCoordinate>,
// statics: Vec<RigidStatic>,
// simulation_callback: Option<*mut PxSimulationEventCallback>,
}

impl Default for SceneUserData {
    fn default() -> Self {
        Self {}
    }
}

pub enum UserData {
    RigidActor(RigidActorUserData),
    ArticulationBase(ArticulationBaseUserData),
    Scene(SceneUserData),
    UserDefined(*mut std::ffi::c_void),
}

impl UserData {
    pub fn new_rigid_actor() -> UserData {
        UserData::RigidActor(RigidActorUserData::default())
    }

    pub fn new_articulation_base() -> UserData {
        UserData::ArticulationBase(ArticulationBaseUserData::default())
    }

    pub fn new_scene() -> UserData {
        UserData::Scene(SceneUserData::default())
    }
}
