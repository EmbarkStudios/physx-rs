// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 29 April 2019

#![warn(clippy::all)]

/*!
Wrapper for PxShape
 */

use crate::{
    material::Material,
    owner::Owner,
    traits::{Class, PxFlags, UserData},
};

use enumflags2::BitFlags;

use std::marker::PhantomData;

use physx_sys::{
    PxFilterData, PxFilterData_new_1, PxShapeFlag, PxShapeFlags, PxShape_getMaterials,
    PxShape_getNbMaterials, PxShape_getQueryFilterData, PxShape_getSimulationFilterData,
    PxShape_release_mut, PxShape_setFlag_mut, PxShape_setQueryFilterData_mut,
    PxShape_setSimulationFilterData_mut,
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

pub type ShapeFlags = BitFlags<ShapeFlag>;

impl PxFlags for ShapeFlags {
    type Target = PxShapeFlags;

    fn into_px(self) -> Self::Target {
        PxShapeFlags {
            mBits: self.bits() as u8,
        }
    }

    fn from_px(flags: Self::Target) -> Self {
        unsafe { BitFlags::new(flags.mBits as u32) }
    }
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

#[repr(transparent)]
pub struct Shape<H, M> {
    pub(crate) obj: physx_sys::PxShape,
    phantom_user_data: PhantomData<(H, M)>,
}

unsafe impl<S, H, M> Class<S> for Shape<H, M>
where
    physx_sys::PxShape: Class<S>,
{
    fn as_ptr(&self) -> *const S {
        self.obj.as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut S {
        self.obj.as_mut_ptr()
    }
}

impl<H, M> Shape<H, M> {
    pub(crate) unsafe fn from_raw(
        ptr: *mut physx_sys::PxShape,
        user_data: H,
    ) -> Option<Owner<Self>> {
        let shape = (ptr as *mut Self).as_mut();
        Owner::from_raw(shape?.init_user_data(user_data))
    }

    pub fn get_user_data(&self) -> &H {
        // Safety: all construction goes through from_raw, which calls init_user_data
        unsafe { UserData::get_user_data(self) }
    }

    pub fn get_user_data_mut(&mut self) -> &mut H {
        // Safety: all construction goes through from_raw, which calls init_user_data
        unsafe { UserData::get_user_data_mut(self) }
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
            PxShape_setSimulationFilterData_mut(self.as_mut_ptr(), &data as *const PxFilterData)
        }
    }

    /// Read the collision filter data of this shape
    pub fn get_simulation_filter_data(&self) -> PxFilterData {
        unsafe { PxShape_getSimulationFilterData(self.as_ptr()) }
    }

    /// Set the query filter of this shape
    pub fn set_query_filter_data(&mut self, this_layers: BitFlags<CollisionLayer>) {
        let mut data = unsafe { PxFilterData_new_1() };
        data.word0 = this_layers.bits();
        data.word1 = 0;
        data.word2 = 0;
        data.word3 = 0;

        unsafe { PxShape_setQueryFilterData_mut(self.as_mut_ptr(), &data as *const PxFilterData) }
    }

    /// Read the query filter data of this shape
    pub fn get_query_filter_data(&self) -> PxFilterData {
        unsafe { PxShape_getQueryFilterData(self.as_ptr()) }
    }

    /// Get the number of materials associated with this shape
    pub fn get_nb_materials(&self) -> u16 {
        unsafe { PxShape_getNbMaterials(self.as_ptr()) }
    }

    /// Get a vector of all materials associated with this shape
    pub fn get_materials(&self) -> Vec<&Material<M>> {
        unsafe {
            let capacity = self.get_nb_materials();
            let mut buffer: Vec<&Material<M>> = Vec::with_capacity(capacity as usize);
            let len = PxShape_getMaterials(
                self.as_ptr(),
                buffer.as_mut_ptr() as *mut *mut _,
                capacity as u32,
                0,
            );
            buffer.set_len(len as usize);
            buffer
        }
    }

    /// Toggle a flag on this shape
    pub fn set_flag(&mut self, flag: ShapeFlag, enable: bool) {
        unsafe { PxShape_setFlag_mut(self.as_mut_ptr(), flag.into(), enable) }
    }
}

unsafe impl<H: Send, M: Send> Send for Shape<H, M> {}
unsafe impl<H: Sync, M: Send> Sync for Shape<H, M> {}

impl<H, M> Drop for Shape<H, M> {
    fn drop(&mut self) {
        unsafe {
            for material in (self).get_materials() {
                drop(material)
            }
            drop(self.get_user_data_mut());
            PxShape_release_mut(self.as_mut_ptr());
        }
    }
}
