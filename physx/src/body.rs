// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 10 April 2019

#![warn(clippy::all)]

/*!
Utility for handle-based usage
*/

/// Handle for a whole body
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct BodyHandle(pub usize);

/// Handle for a link inside a body
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct PartHandle(pub usize, pub usize);

/// Extract the body handle from the parthandle
impl Into<BodyHandle> for PartHandle {
    fn into(self) -> BodyHandle {
        BodyHandle(self.0)
    }
}

/// Trait for a body
trait Body {
    fn handle(&self) -> BodyHandle;
    fn root(&self) -> PartHandle;
}

/// Trait for a body part, e.g. link
trait BodyPart {
    fn body(&self) -> BodyHandle;
    fn handle(&self) -> PartHandle;
}
