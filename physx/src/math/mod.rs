// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 17 June 2019

#![warn(clippy::all)]

/*!

*/

use super::transform::*;
use glam::{Mat4, Vec3, Vec4};
use physx_sys::PxBounds3;

pub struct Bounds {
    pub min_size: Vec3,
    pub max_size: Vec3,
}

impl From<PxBounds3> for Bounds {
    fn from(other: PxBounds3) -> Self {
        Self {
            min_size: px_to_gl_v3(other.minimum),
            max_size: px_to_gl_v3(other.maximum),
        }
    }
}

pub struct Isometry {
    pub translation: Mat4,
    pub rotation: Mat4,
}
impl Isometry {
    /// Extracts the rotation and translation matrix from a matrix.
    pub fn from_mat4(m: &Mat4) -> Self {
        let x = m.x_axis;
        let y = m.y_axis;
        let z = m.z_axis;
        assert!(
            x.is_normalized() && y.is_normalized() && z.is_normalized(),
            "All axis have to be of length 1"
        );
        assert!(x.w == 0.0 && y.w == 0.0 && z.w == 0.0, "Unable to extract the rotation matrix because one of the W components of the axis wasn't 0.0");

        let rotation = Mat4::from_cols(x, y, z, Vec4::unit_w());
        let translation = Mat4::from_translation(m.w_axis.truncate());
        Self {
            rotation,
            translation,
        }
    }
}

#[cfg(test)]
mod tests {
    use super::Isometry;
    use glam::f32::{Mat4, Vec3};
    #[test]
    fn isometry() {
        let rot_z = Mat4::from_rotation_z(f32::to_radians(40.0));
        let rot_y = Mat4::from_rotation_y(f32::to_radians(30.0));
        let rot_x = Mat4::from_rotation_x(f32::to_radians(20.0));
        let rot = rot_y * rot_x * rot_z;
        let trans = Mat4::from_translation(Vec3::new(1.0, 2.0, 3.0));
        let m = trans * rot;

        let iso = Isometry::from_mat4(&m);
        assert!(iso.translation == trans);
        assert!(iso.rotation == rot);
    }
}
