// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 29 April 2019

#![warn(clippy::all)]

/*!
Wrapper for PxShape
 */

use super::{base::Base, px_type::*, traits::*};
use enumflags2::BitFlags;
use physx_macros::*;
use physx_sys::{
    PxFilterData, PxFilterData_new_1, PxMaterial, PxMaterial_release_mut, PxShape, PxShapeFlag,
    PxShape_getMaterials, PxShape_getNbMaterials, PxShape_getQueryFilterData,
    PxShape_getSimulationFilterData, PxShape_release_mut, PxShape_setFlag_mut,
    PxShape_setQueryFilterData_mut, PxShape_setSimulationFilterData_mut,
};

/// Layers used for collision/querying of shapes
#[derive(Debug, Copy, Clone, BitFlags)]
#[repr(u32)]
pub enum CollisionLayer {
    Ghost = 1,
    Terrain = 2,
    Static = 4,
    Character = 8,
}

/// Layers used for collision/querying of shapes
#[derive(Debug, Copy, Clone, BitFlags)]
#[repr(u32)]
pub enum ShapeFlag {
    SimulationShape = 1u32,
    SceneQueryShape = 2u32,
    TriggerShape = 4u32,
    Visualization = 8u32,
}

impl Into<PxShapeFlag::Enum> for ShapeFlag {
    fn into(self) -> PxShapeFlag::Enum {
        match self {
            ShapeFlag::SimulationShape => 1u32,
            ShapeFlag::SceneQueryShape => 2u32,
            ShapeFlag::TriggerShape => 4u32,
            ShapeFlag::Visualization => 8u32,
        }
    }
}

#[physx_type(inherit = "Base")]
impl Shape {
    /// Release the PhysX resource - any operation on this item after this operation is undefined.
    pub fn destroy(&mut self) {
        unsafe {
            for mtrl in self.get_materials() {
                PxMaterial_release_mut(mtrl);
            }
            PxShape_release_mut(self.get_raw_mut());
        }
    }

    /// Set the simulation (collision) filter of this shape
    pub fn set_simulation_filter_data(
        &mut self,
        this_layers: BitFlags<CollisionLayer>,
        other_layers: BitFlags<CollisionLayer>,
        word3: u32,
        word4: u32,
    ) {
        let mut data = unsafe { PxFilterData_new_1() };
        data.word0 = this_layers.bits();
        data.word1 = other_layers.bits();
        data.word2 = word3;
        data.word3 = word4;

        unsafe {
            PxShape_setSimulationFilterData_mut(self.get_raw_mut(), &data as *const PxFilterData)
        }
    }

    /// Read the collision filter data of this shape
    pub fn get_simulation_filter_data(&self) -> PxFilterData {
        unsafe { PxShape_getSimulationFilterData(self.get_raw()) }
    }

    /// Set the query filter of this shape
    pub fn set_query_filter_data(&mut self, this_layers: BitFlags<CollisionLayer>) {
        let mut data = unsafe { PxFilterData_new_1() };
        data.word0 = this_layers.bits();
        data.word1 = 0;
        data.word2 = 0;
        data.word3 = 0;

        unsafe { PxShape_setQueryFilterData_mut(self.get_raw_mut(), &data as *const PxFilterData) }
    }

    /// Read the query filter data of this shape
    pub fn get_query_filter_data(&self) -> PxFilterData {
        unsafe { PxShape_getQueryFilterData(self.get_raw()) }
    }

    /// Get the number of materials associated with this shape
    pub fn get_nb_materials(&self) -> usize {
        unsafe { PxShape_getNbMaterials(self.get_raw()) as usize }
    }

    /// Get a vector of all materials associated with this shape
    pub fn get_materials(&self) -> Vec<*mut PxMaterial> {
        let count_materials = self.get_nb_materials();
        let mut materials_vec = Vec::new();
        materials_vec.reserve(count_materials);

        unsafe {
            let actual = PxShape_getMaterials(
                self.get_raw(),
                materials_vec.as_mut_ptr(),
                count_materials as u32,
                0,
            ) as usize;
            materials_vec.set_len(actual);
        }

        materials_vec
    }

    /// Toggle a flag on this shape
    pub fn set_flag(&mut self, flag: ShapeFlag, enable: bool) {
        unsafe { PxShape_setFlag_mut(self.get_raw_mut(), flag.into(), enable) }
    }
}
