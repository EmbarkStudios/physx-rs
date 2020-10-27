// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 12 June 2019

#![warn(clippy::all)]

/*!

*/

mod collidable;
//pub use collidable::Collidable;

mod class;
pub use class::Class;

mod user_data;
pub(crate) use user_data::UserData;

pub trait PxFlags: Copy {
    type Target;
    fn into_px(self) -> Self::Target;
    fn from_px(flags: Self::Target) -> Self;
}
