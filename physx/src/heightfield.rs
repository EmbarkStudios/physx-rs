// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 11 April 2019

#![warn(clippy::all)]
#![warn(rust_2018_idioms)]

/*!

*/
use super::{cooking::Cooking, geometry::Geometry};
use enumflags2::BitFlags;

use physx_sys::*;

#[derive(Debug, Copy, Clone)]
#[repr(u32)]
pub enum HeightfieldFormat {
    S16TM = 1,
}

#[derive(BitFlags, Debug, Copy, Clone)]
#[repr(u16)]
pub enum HeightfieldFlag {
    NoboundaryEdges = 1,
}

pub type HeightfieldSampler<'a> = dyn Fn(usize, usize) -> f32 + 'a;

pub struct HeightfieldBuilder<'a> {
    sampler: &'a HeightfieldSampler<'a>,
    size: (usize, usize),

    edge_threshold: f32,
    format: HeightfieldFormat,
    flags: BitFlags<HeightfieldFlag>,
    width: f32,
    length: f32,
    height: f32,
}

impl Default for HeightfieldBuilder<'_> {
    fn default() -> Self {
        Self {
            sampler: &|_, _| 0.0,
            size: (1,1),
            edge_threshold: 1.0,
            format: HeightfieldFormat::S16TM,
            flags: BitFlags::empty(),
            width: 1.0,
            length: 1.0,
            height: 1.0,
        }
    }
}

impl<'a> HeightfieldBuilder<'a> {
    pub fn edge_threshold(self, edge_threshold: f32) -> Self {
        Self {
            edge_threshold,
            ..self
        }
    }

    pub fn sampler(self, sampler: &'a HeightfieldSampler<'a>) -> Self {
        Self { sampler, ..self }
    }

    pub fn size(self, xsiz: usize, ysiz: usize) -> Self {
        let size = (xsiz, ysiz);
        Self { size, ..self }
    }

    pub fn scale(self, width: f32, length: f32, height: f32) -> Self {
        Self {
            width,
            length,
            height,
            ..self
        }
    }

    pub fn format(self, format: HeightfieldFormat) -> Self {
        Self { format, ..self }
    }

    pub fn flags(self, flags: BitFlags<HeightfieldFlag>) -> Self {
        Self { flags, ..self }
    }

    pub fn generate_heights(&self) -> Vec<PxHeightFieldSample> {
        let mut heights = Vec::new();
        for y in 0..self.size.1 {
            for x in 0..self.size.0 {
                let s = (self.sampler)(x, y);
                heights.push(PxHeightFieldSample {
                    height: (s * 2.0_f32.powf(15.0)) as i16,
                    materialIndex0: PxBitAndByte { mData: 0 },
                    materialIndex1: PxBitAndByte { mData: 0 },
                });
            }
        }
        heights
    }

    ////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////

    /// Convert an array of heights to a height field description we can give to PhysX
    fn create_desc(&self, heights: &[PxHeightFieldSample]) -> PxHeightFieldDesc {
        let mut heightfield_desc = unsafe { PxHeightFieldDesc_new() };
        heightfield_desc.nbRows = self.size.0 as u32;
        heightfield_desc.nbColumns = self.size.1 as u32;
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
        cooking.create_heightfield(
            heightfield_desc,
            false,
            self.width,
            self.length,
            self.height,
        )
    }
}
