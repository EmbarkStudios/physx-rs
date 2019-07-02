// Author: Tom Olsson <mail@tomolsson.se>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created:  2 April 2019

#![warn(clippy::all)]
#![warn(rust_2018_idioms)]
/*!

*/

// Utility traits
mod px_type;
pub mod traits;

// Utility data
pub mod user_data;

// Conversion utilities
pub mod math;
pub mod transform;

// Wrappers
pub mod actor;
pub mod articulation_base;
pub mod articulation_cache;
pub mod articulation_joint;
pub mod articulation_joint_base;
pub mod articulation_joint_reduced_coordinate;
pub mod articulation_link;
pub mod articulation_reduced_coordinate;
pub mod base;
pub mod body;
pub mod cooking;
pub mod foundation;
pub mod geometry;
pub mod heightfield;
pub mod physics;
pub mod rigid_actor;
pub mod rigid_body;
pub mod rigid_dynamic;
pub mod rigid_static;
pub mod scene;
pub mod shape;
pub mod visual_debugger;

pub mod prelude;
