// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 12 June 2019

mod class;
pub use class::Class;
pub(crate) use class::DeriveClassForNewType;

mod user_data;
pub(crate) use user_data::HasUserData;

pub mod descriptor;
pub(crate) use descriptor::*;
