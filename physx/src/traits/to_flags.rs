// Author: Tom Olsson <mail@tomolsson.se>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 16 April 2019

#![warn(clippy::all)]
#![warn(rust_2018_idioms)]

/*!
Extension trait for Into to use for local enums
 */

pub trait ToFlags<T> {
    fn to_flags(self) -> T;
}
