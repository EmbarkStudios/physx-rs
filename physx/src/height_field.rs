// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 11 April 2019

#![warn(clippy::all)]

/*!

*/
use crate::{
    owner::Owner,
    //cooking::{Cooking, HEIGHT_SCALE, XZ_SCALE},
    //geometry::PxHeightFieldGeometry,
    //math::PxVec3,
    traits::Class,
};
use enumflags2::BitFlags;
use physx_sys::{
    //PxHeightFieldFlag,
    PxHeightField_release_mut,
    /*
    PxHeightFieldFlags,
    PxHeightFieldDesc,
    PxHeightFieldDesc_new,
    PxHeightFieldSample,
    PxHeightField_acquireReference_mut,
    PxHeightField_getConcreteTypeName,
    PxHeightField_getConvexEdgeThreshold,
    PxHeightField_getFlags,
    PxHeightField_getFormat,
    PxHeightField_getHeight,
    PxHeightField_getNbColumns,
    PxHeightField_getNbRows,
    PxHeightField_getReferenceCount,
    PxHeightField_getSample,
    PxHeightField_getSampleStride,
    PxHeightField_getTimestamp,
    PxHeightField_getTriangleMaterialIndex,
    PxHeightField_getTriangleNormal,
    PxHeightField_modifySamples_mut,
    PxHeightField_saveCells,
    */
};

#[repr(transparent)]
pub struct HeightField {
    obj: physx_sys::PxHeightField,
}

crate::ClassObj!(HeightField : PxHeightField, PxBase);

impl HeightField {
    pub(crate) unsafe fn from_raw(ptr: *mut physx_sys::PxHeightField) -> Option<Owner<Self>> {
        Owner::from_raw(ptr as *mut Self)
    }
}

impl Drop for HeightField {
    fn drop(&mut self) {
        unsafe {
            PxHeightField_release_mut(self.as_mut_ptr())
        }
    }
}

#[derive(Debug, Copy, Clone)]
#[repr(u32)]
pub enum HeightFieldFormat {
    S16TM = 1,
}

#[derive(BitFlags, Debug, Copy, Clone)]
#[repr(u16)]
pub enum HeightFieldFlag {
    NoboundaryEdges = 1,
}

/*
pub type HeightFieldSampler = dyn Fn(usize, usize) -> f32;

pub(crate) struct HeightFieldBuilder<'a> {
    _sampler: &'a HeightFieldSampler,
    size: (usize, usize),
    edge_threshold: f32,
    format: HeightFieldFormat,
    flags: BitFlags<HeightFieldFlag>,
}

impl<'a> Default for HeightFieldBuilder<'a> {
    fn default() -> Self {
        Self {
            sampler: &|_, _| 0.0,
            size: (1, 1),
            edge_threshold: 1.0,
            format: HeightFieldFormat::S16TM,
            flags: BitFlags::empty(),
        }
    }
}

impl<'a> HeightFieldBuilder<'a> {
    pub fn sampler(self, sampler: &'a HeightFieldSampler) -> Self {
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

    pub fn format(self, format: HeightFieldFormat) -> Self {
        Self { format, ..self }
    }

    pub fn flags(self, flags: BitFlags<HeightFieldFlag>) -> Self {
        Self { flags, ..self }
    }

    pub fn generate_heights(&self) -> Vec<f32> {
        let mut heights = vec![0.0; self.size.0 * self.size.1];
        for y in 0..self.size.1 {
            for x in 0..self.size.0 {
                heights[y * self.size.0 + x] = (self.sampler)(x, y);
            }
        }
        heights
    }

    ////////////////////////////////////////////////////////////////////////////////
    pub fn generate_vertices(&self, heights: &[f32]) -> Vec<PxVec3> {
        let mut vertices: Vec<PxVec3> = Vec::new();
        vertices.reserve(heights.len());
        for y in 0..self.size.1 {
            for x in 0..self.size.0 {
                let index = y * self.size.0 + x;
                vertices.push(PxVec3::new(
                    x as f32 * XZ_SCALE,
                    heights[index] * HEIGHT_SCALE,
                    y as f32 * XZ_SCALE,
                    
                ));
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
    pub fn build(&self, cooking: &mut impl Cooking) -> PxHeightFieldGeometry {
        let heights = self.generate_heights();
        let heightfield_desc = self.create_desc(&heights);
        cooking.create_heightfield(heightfield_desc, false)
    }
}
*/
