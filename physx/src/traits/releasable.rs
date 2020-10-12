// Author: Tom Olsson <mail@tomolsson.se>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 12 June 2019

#![warn(clippy::all)]

/*!
Release trait to make sure our Deref hack calls the right Release
 */

pub trait Releasable {
    fn release(&mut self);
}
