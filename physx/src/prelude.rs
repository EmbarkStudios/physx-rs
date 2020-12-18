// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created:  9 May 2019

#![warn(clippy::all)]

/*!
Prelude for commonly useful types

 */

pub use crate::actor::{Actor, ActorFlag, ActorFlags};
pub use crate::aggregate::Aggregate;
pub use crate::articulation::Articulation;
pub use crate::articulation_base::ArticulationBase;
pub use crate::articulation_cache::*;
pub use crate::articulation_joint::{ArticulationJoint, ArticulationJointDriveType};
pub use crate::articulation_joint_base::ArticulationJointBase;
pub use crate::articulation_joint_reduced_coordinate::*;
pub use crate::articulation_link::{ArticulationDriveType, ArticulationLink};
pub use crate::articulation_reduced_coordinate::{
    ArticulationFlag, ArticulationFlags, ArticulationReducedCoordinate,
};
pub use crate::base::{Base, BaseFlag, ConcreteType};
pub use crate::controller::Controller;
pub use crate::controller_manager::ControllerManager;
//pub use crate::cooking::*;
pub use crate::foundation::{AllocatorCallback, Foundation, ScratchBuffer};
pub use crate::geometry::*;
pub use crate::height_field::*;
pub use crate::math::*;
pub use crate::owner::Owner;
pub use crate::physics::{Physics, PhysicsFoundation, PX_PHYSICS_VERSION};
pub use crate::rigid_actor::RigidActor;
pub use crate::rigid_body::{ForceMode, RigidBody, RigidBodyFlag, RigidBodyFlags};
pub use crate::rigid_dynamic::{RigidDynamic, RigidDynamicLockFlag, RigidDynamicLockFlags};
pub use crate::rigid_static::RigidStatic;
pub use crate::scene::{
    BroadPhaseType, FilterShaderDescriptor, PairFilteringMode, PruningStructureType, Scene,
    SceneFlag, SimulationThreadType, SolverType,
};
pub use crate::shape::{CollisionLayer, Shape, ShapeFlag, ShapeFlags};
pub use crate::simulation_event_callback::{
    AdvanceCallback, CollisionCallback, ConstraintBreakCallback, PxSimulationEventCallback,
    TriggerCallback, WakeSleepCallback,
};
pub use crate::traits::descriptor::{
    ConstraintDescriptor, MaterialDescriptor, PlaneDescriptor, RigidDynamicDescriptor,
    RigidStaticDescriptor, SceneDescriptor, ShapeDescriptor,
};
