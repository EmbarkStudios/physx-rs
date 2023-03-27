// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 11 April 2019

use std::ffi::c_void;

use crate::{cooking::PxHeightFieldDesc, math::PxVec3, owner::Owner, traits::Class};

use physx_sys::{
    PxBitAndByte,
    PxHeightField_getConvexEdgeThreshold,
    PxHeightField_getFlags,
    PxHeightField_getFormat,
    PxHeightField_getHeight,
    PxHeightField_getNbColumns,
    PxHeightField_getNbRows,
    PxHeightField_getSample,
    PxHeightField_getSampleStride,
    PxHeightField_getTimestamp,
    //PxHeightField_getConcreteTypeName,
    PxHeightField_getTriangleMaterialIndex,
    PxHeightField_getTriangleNormal,
    PxHeightField_modifySamples_mut,
    PxHeightField_release_mut,
    PxHeightField_saveCells,
};

pub use physx_sys::{
    //PxHeightFieldTessFlag as HeightFieldTessFlag,
    PxHeightFieldFlag as HeightFieldFlag,
    PxHeightFieldFlags as HeightFieldFlags,
    //PxHeightFieldMaterial as HeightFieldMaterial,
    PxHeightFieldFormat as HeightFieldFormat,
};

pub const HEIGHT_SCALE: f32 = 1.0;
pub const XZ_SCALE: f32 = 100.0;

#[repr(transparent)]
pub struct HeightField {
    obj: physx_sys::PxHeightField,
}

crate::DeriveClassForNewType!(HeightField: PxHeightField, PxBase);

impl HeightField {
    /// # Safety
    ///
    /// Owner's own the pointer they wrap, using the pointer after dropping the Owner,
    /// or creating multiple Owners from the same pointer will cause UB.  Use `into_ptr` to
    /// retrieve the pointer and consume the Owner without dropping the pointee.
    pub(crate) unsafe fn from_raw(ptr: *mut physx_sys::PxHeightField) -> Option<Owner<Self>> {
        unsafe { Owner::from_raw(ptr as *mut Self) }
    }

    /// Writes out the sample data array.
    pub fn save_cells(&self) -> Vec<HeightFieldSample> {
        let buffer_size = self.get_nb_columns() * self.get_nb_rows();
        let byte_size = buffer_size * std::mem::size_of::<HeightFieldSample>() as u32;
        let mut samples = Vec::with_capacity(buffer_size as usize);

        unsafe {
            // SAFETY: HeightFieldSample is repr(transparent) of PxHeightFieldSample
            assert_eq!(
                PxHeightField_saveCells(
                    self.as_ptr(),
                    samples.as_mut_ptr() as *mut c_void,
                    byte_size
                ),
                byte_size
            );

            // SAFETY: call above should populate all the values, as verified by the assertion
            samples.set_len(buffer_size as usize)
        }

        samples
    }

    /// Replaces a rectangular subfield in the sample data array.
    pub fn modify_samples(
        &mut self,
        start_col: i32,
        start_row: i32,
        subfield_desc: &PxHeightFieldDesc,
        shrink_bounds: bool,
    ) -> bool {
        unsafe {
            PxHeightField_modifySamples_mut(
                self.as_mut_ptr(),
                start_col,
                start_row,
                subfield_desc.as_ptr(),
                shrink_bounds,
            )
        }
    }

    /// Retrieves the number of sample rows in the samples array.
    pub fn get_nb_rows(&self) -> u32 {
        unsafe { PxHeightField_getNbRows(self.as_ptr()) }
    }

    /// Retrieves the number of sample columns in the samples array.
    pub fn get_nb_columns(&self) -> u32 {
        unsafe { PxHeightField_getNbColumns(self.as_ptr()) }
    }

    /// Retrieves the format of the sample data.
    pub fn get_format(&self) -> HeightFieldFormat {
        unsafe { PxHeightField_getFormat(self.as_ptr()) }
    }

    /// Retrieves the offset in bytes between consecutive samples in the array.
    pub fn get_sample_stride(&self) -> u32 {
        unsafe { PxHeightField_getSampleStride(self.as_ptr()) }
    }

    /// Retrieves the convex edge threshold.
    pub fn get_convex_edge_threshold(&self) -> f32 {
        unsafe { PxHeightField_getConvexEdgeThreshold(self.as_ptr()) }
    }

    /// Retrieves the flags bits, combined from values of the enum HeightFieldFlag.
    pub fn get_flags(&self) -> HeightFieldFlags {
        unsafe { PxHeightField_getFlags(self.as_ptr()) }
    }

    /// Retrieves the height at the given coordinates in grid space.
    pub fn get_height(&self, x: f32, z: f32) -> f32 {
        unsafe { PxHeightField_getHeight(self.as_ptr(), x, z) }
    }

    /// Returns material table index of given triangle.
    pub fn get_triangle_material_index(&self, triangle_index: u32) -> u16 {
        unsafe { PxHeightField_getTriangleMaterialIndex(self.as_ptr(), triangle_index) }
    }

    /// Returns a triangle face normal for a given triangle index.
    pub fn get_triangle_normal(&self, triangle_index: u32) -> PxVec3 {
        unsafe { PxHeightField_getTriangleNormal(self.as_ptr(), triangle_index) }.into()
    }

    /// Returns heightfield sample of given row and column.
    pub fn get_sample(&self, row: u32, column: u32) -> Option<&HeightFieldSample> {
        // need to do bound checks, otherwise C++ code will crash with assertion error
        if row < self.get_nb_rows() || column < self.get_nb_columns() {
            // SAFETY: HeightFieldSample is repr(transparent) of PxHeightFieldSample
            Some(unsafe {
                std::mem::transmute(&*PxHeightField_getSample(self.as_ptr(), row, column))
            })
        } else {
            None
        }
    }

    /// Returns the number of times the heightfield data has been modified.
    pub fn get_timestamp(&self) -> u32 {
        unsafe { PxHeightField_getTimestamp(self.as_ptr()) }
    }
}

unsafe impl Send for HeightField {}
unsafe impl Sync for HeightField {}

impl Drop for HeightField {
    fn drop(&mut self) {
        unsafe { PxHeightField_release_mut(self.as_mut_ptr()) }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Default)]
pub struct HeightFieldMaterial(i8);

impl HeightFieldMaterial {
    pub const HOLE: Self = Self(physx_sys::PxHeightFieldMaterial::Hole as _);

    pub const fn new(index: i8) -> Self {
        assert!(
            index >= 0,
            "HeightFieldMaterial index must be in 0x00..0x7F range"
        );
        Self(index)
    }

    pub const fn get(&self) -> i8 {
        self.0
    }
}

#[derive(Copy, Clone)]
#[repr(transparent)]
pub struct HeightFieldSample {
    obj: physx_sys::PxHeightFieldSample,
}

crate::DeriveClassForNewType!(HeightFieldSample: PxHeightFieldSample);

impl From<physx_sys::PxHeightFieldSample> for HeightFieldSample {
    fn from(value: physx_sys::PxHeightFieldSample) -> Self {
        Self { obj: value }
    }
}

impl From<HeightFieldSample> for physx_sys::PxHeightFieldSample {
    fn from(value: HeightFieldSample) -> Self {
        value.obj
    }
}

impl HeightFieldSample {
    // In PhysX, material can only be in 0x00..0x7F range, high bit has special meaning.
    // In material0 high bit is tesselation flag, in material1 it is reserved.
    // We can use PxHeightFieldSample_tessFlag methods, but it's easier to just do bit arithmetic in Rust.
    const BIT_MASK: u8 = 0x80;

    pub fn new(
        height: i16,
        material0: HeightFieldMaterial,
        material1: HeightFieldMaterial,
        tess_flag: bool,
    ) -> Self {
        let mut result: Self = physx_sys::PxHeightFieldSample {
            height,
            materialIndex0: PxBitAndByte {
                structgen_pad0: [material0.0 as u8],
            },
            materialIndex1: PxBitAndByte {
                structgen_pad0: [material1.0 as u8],
            },
        }
        .into();

        if tess_flag {
            result.set_tess_flag();
        }

        result
    }

    pub fn height(&self) -> i16 {
        self.obj.height
    }

    pub fn set_height(&mut self, height: i16) {
        self.obj.height = height;
    }

    pub fn tess_flag(&self) -> bool {
        // same as PxHeightFieldSample_tessFlag
        self.obj.materialIndex0.structgen_pad0[0] & Self::BIT_MASK != 0
    }

    pub fn set_tess_flag(&mut self) {
        // same as PxHeightFieldSample_setTessFlag_mut
        self.obj.materialIndex0.structgen_pad0[0] |= Self::BIT_MASK;
    }

    pub fn clear_tess_flag(&mut self) {
        // same as PxHeightFieldSample_clearTessFlag_mut
        self.obj.materialIndex0.structgen_pad0[0] &= !Self::BIT_MASK;
    }

    pub fn material0(&self) -> HeightFieldMaterial {
        HeightFieldMaterial::new(
            (self.obj.materialIndex0.structgen_pad0[0] & !Self::BIT_MASK) as i8,
        )
    }

    pub fn material1(&self) -> HeightFieldMaterial {
        HeightFieldMaterial::new(
            (self.obj.materialIndex1.structgen_pad0[0] & !Self::BIT_MASK) as i8,
        )
    }

    pub fn set_material0(&mut self, material: HeightFieldMaterial) {
        self.obj.materialIndex0.structgen_pad0[0] =
            material.get() as u8 | self.obj.materialIndex0.structgen_pad0[0] & Self::BIT_MASK;
    }

    pub fn set_material1(&mut self, material: HeightFieldMaterial) {
        self.obj.materialIndex1.structgen_pad0[0] =
            material.get() as u8 | self.obj.materialIndex1.structgen_pad0[0] & Self::BIT_MASK;
    }
}
