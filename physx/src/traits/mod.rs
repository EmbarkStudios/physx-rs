// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 12 June 2019

#![warn(clippy::all)]

/*!

*/

mod class;
pub use class::Class;

mod user_data;
pub(crate) use user_data::UserData;

pub mod descriptor;
pub(crate) use descriptor::*;

pub trait PxFlags: Copy {
    /// The target physx_sys flags type.
    type Target;
    /// Convert to Px type.
    fn into_px(self) -> Self::Target;
    /// Convert to BitFlags<> type.
    fn from_px(flags: Self::Target) -> Self;
}
