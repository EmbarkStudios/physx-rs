// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 11 April 2019

#![warn(clippy::all)]
#![warn(rust_2018_idioms)]

/*!

*/
use super::{
    cooking::{Cooking, HEIGHT_SCALE, XZ_SCALE},
    geometry::Geometry,
};
use enumflags2::BitFlags;
use enumflags2_derive::EnumFlags;
use nalgebra_glm as glm;
use ncollide3d::procedural::{quad_with_vertices, TriMesh};
use physx_sys::*;

#[derive(Debug, Copy, Clone)]
#[repr(u32)]
pub enum HeightfieldFormat {
    S16TM = 1,
}

#[derive(EnumFlags, Debug, Copy, Clone)]
#[repr(u16)]
pub enum HeightfieldFlag {
    NoboundaryEdges = 1,
}

pub type HeightfieldSampler = dyn Fn(usize, usize) -> f32;

pub struct HeightfieldBuilder<'a> {
    sampler: &'a HeightfieldSampler,
    size: (usize, usize),
    edge_threshold: f32,
    format: HeightfieldFormat,
    flags: BitFlags<HeightfieldFlag>,
}

impl<'a> Default for HeightfieldBuilder<'a> {
    fn default() -> Self {
        Self {
            sampler: &|_, _| 0.0,
            size: (1, 1),
            edge_threshold: 1.0,
            format: HeightfieldFormat::S16TM,
            flags: BitFlags::empty(),
        }
    }
}

impl<'a> HeightfieldBuilder<'a> {
    pub fn sampler(self, sampler: &'a HeightfieldSampler) -> Self {
        Self { sampler, ..self }
    }

    pub fn size(self, xsiz: usize, ysiz: usize) -> Self {
        let size = (xsiz, ysiz);
        Self { size, ..self }
    }

    pub fn edge_threshold(self, edge_threshold: f32) -> Self {
        Self {
            edge_threshold,
            ..self
        }
    }

    pub fn format(self, format: HeightfieldFormat) -> Self {
        Self { format, ..self }
    }

    pub fn flags(self, flags: BitFlags<HeightfieldFlag>) -> Self {
        Self { flags, ..self }
    }

    fn generate_heights(&self) -> Vec<f32> {
        let mut heights = vec![0.0; self.size.0 * self.size.1];
        for y in 0..self.size.1 {
            for x in 0..self.size.0 {
                heights[y * self.size.0 + x] = (self.sampler)(x, y);
            }
        }
        heights
    }

    ////////////////////////////////////////////////////////////////////////////////

    fn generate_vertices(&self, heights: &[f32]) -> Vec<nalgebra::Point3<f32>> {
        let mut vertices: Vec<nalgebra::Point3<f32>> = Vec::new();
        vertices.reserve(heights.len());
        for y in 0..self.size.1 {
            for x in 0..self.size.0 {
                let index = y * self.size.0 + x;
                vertices.push(
                    glm::vec3(
                        x as f32 * XZ_SCALE,
                        heights[index] * HEIGHT_SCALE,
                        y as f32 * XZ_SCALE,
                    )
                    .into(),
                );
            }
        }
        vertices
    }

    ////////////////////////////////////////////////////////////////////////////////

    /// Convert an array of heights to a height field description we can give to PhysX
    fn create_desc(&self, heights: &[f32]) -> PxHeightFieldDesc {
        let mut heightfield_desc = unsafe { PxHeightFieldDesc_new() };
        heightfield_desc.nbRows = self.size.1 as u32;
        heightfield_desc.nbColumns = self.size.0 as u32;
        heightfield_desc.format = self.format as u32;
        heightfield_desc.flags = PxHeightFieldFlags {
            mBits: self.flags.bits(),
        };
        heightfield_desc.convexEdgeThreshold = self.edge_threshold;
        heightfield_desc.samples.data = heights.as_ptr() as *const std::ffi::c_void;
        heightfield_desc.samples.stride = std::mem::size_of::<PxHeightFieldSample>() as u32;
        heightfield_desc
    }

    ////////////////////////////////////////////////////////////////////////////////

    /// Build the heightfield into a PhysX geometry
    pub fn build(&self, cooking: &mut Cooking) -> Geometry {
        let heights = self.generate_heights();
        let heightfield_desc = self.create_desc(&heights);
        cooking.create_heightfield(heightfield_desc, false)
    }

    ////////////////////////////////////////////////////////////////////////////////

    /// Build the heightfield into a PhysX geometry and a trimesh we can use for rendering.
    pub fn build_with_trimesh(&self, cooking: &mut Cooking) -> (Geometry, TriMesh<f32>) {
        let heights = self.generate_heights();
        let heightfield_desc = self.create_desc(&heights);

        let vertices = self.generate_vertices(&heights);
        (
            cooking.create_heightfield(heightfield_desc, true),
            quad_with_vertices(&vertices[..], self.size.0, self.size.1),
        )
    }
}
