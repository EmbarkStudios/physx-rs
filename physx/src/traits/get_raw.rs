// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 15 April 2019

#![warn(clippy::all)]

/*!
Utility trait for dealing with wrapped inheritance
 */

pub trait GetRaw<T> {
    fn get_raw(&self) -> *const T;
    fn get_raw_mut(&mut self) -> *mut T;
}
