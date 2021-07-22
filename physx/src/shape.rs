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

use enumflags2::{bitflags, BitFlags};

use std::{marker::PhantomData, ptr::drop_in_place};

use physx_sys::{
    PxFilterData, PxFilterData_new_1, PxShapeFlag, PxShapeFlags, PxShape_getMaterials,
    PxShape_getNbMaterials, PxShape_getQueryFilterData, PxShape_getReferenceCount,
    PxShape_getSimulationFilterData, PxShape_release_mut, PxShape_setFlag_mut,
    PxShape_setQueryFilterData_mut, PxShape_setSimulationFilterData_mut,
};

/// Layers used for collision/querying of shapes
#[bitflags]
#[derive(Debug, Copy, Clone)]
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
        unsafe { BitFlags::from_bits_unchecked(flags.mBits as u32) }
    }
}
/// Layers used for collision/querying of shapes
#[bitflags]
#[derive(Debug, Copy, Clone)]
#[repr(u32)]
pub enum ShapeFlag {
    SimulationShape = 1u32,
    SceneQueryShape = 2u32,
    TriggerShape = 4u32,
    Visualization = 8u32,
}

impl From<ShapeFlag> for PxShapeFlag::Enum {
    fn from(value: ShapeFlag) -> Self {
        match value {
            ShapeFlag::SimulationShape => 1u32,
            ShapeFlag::SceneQueryShape => 2u32,
            ShapeFlag::TriggerShape => 4u32,
            ShapeFlag::Visualization => 8u32,
        }
    }
}

/// A new type wrapper for PxShape.  Parametrized by it's user data type,
/// and the type of it's Material.
#[repr(transparent)]
pub struct PxShape<U, M: Material> {
    pub(crate) obj: physx_sys::PxShape,
    phantom_user_data: PhantomData<(U, M)>,
}

unsafe impl<U, M: Material> UserData for PxShape<U, M> {
    type UserData = U;

    fn user_data_ptr(&self) -> &*mut std::ffi::c_void {
        &self.obj.userData
    }

    fn user_data_ptr_mut(&mut self) -> &mut *mut std::ffi::c_void {
        &mut self.obj.userData
    }
}

impl<U, M: Material> Drop for PxShape<U, M> {
    fn drop(&mut self) {
        unsafe {
            for material in self.get_materials_mut() {
                drop_in_place(material as *mut _);
            }
            drop_in_place(self.get_user_data_mut());
            PxShape_release_mut(self.as_mut_ptr());
        }
    }
}

unsafe impl<S, U, M: Material> Class<S> for PxShape<U, M>
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

unsafe impl<U: Send, M: Material + Send> Send for PxShape<U, M> {}
unsafe impl<U: Sync, M: Material + Send> Sync for PxShape<U, M> {}

impl<U, M: Material> Shape for PxShape<U, M> {
    type Material = M;
}

pub trait Shape: Class<physx_sys::PxShape> + UserData {
    type Material: Material;

    /// # Safety
    /// Owner's own the pointer they wrap, using the pointer after dropping the Owner,
    /// or creating multiple Owners from the same pointer will cause UB.  Use `into_ptr` to
    /// retrieve the pointer and consume the Owner without dropping the pointee.
    unsafe fn from_raw(
        ptr: *mut physx_sys::PxShape,
        user_data: Self::UserData,
    ) -> Option<Owner<Self>> {
        let shape = (ptr as *mut Self).as_mut();
        Owner::from_raw(shape?.init_user_data(user_data))
    }

    /// Get a reference to the user data.
    fn get_user_data(&self) -> &Self::UserData {
        // Safety: all construction goes through from_raw, which calls init_user_data
        unsafe { UserData::get_user_data(self) }
    }

    /// Get a mutable reference to the user data.
    fn get_user_data_mut(&mut self) -> &mut Self::UserData {
        // Safety: all construction goes through from_raw, which calls init_user_data
        unsafe { UserData::get_user_data_mut(self) }
    }

    /// Set the simulation (collision) filter of this shape
    fn set_simulation_filter_data(
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
    fn get_simulation_filter_data(&self) -> PxFilterData {
        unsafe { PxShape_getSimulationFilterData(self.as_ptr()) }
    }

    /// Get the reference count
    fn get_reference_count(&self) -> u32 {
        unsafe { PxShape_getReferenceCount(self.as_ptr()) }
    }

    /// Set the query filter of this shape
    fn set_query_filter_data(&mut self, this_layers: BitFlags<CollisionLayer>) {
        let mut data = unsafe { PxFilterData_new_1() };
        data.word0 = this_layers.bits();
        data.word1 = 0;
        data.word2 = 0;
        data.word3 = 0;

        unsafe { PxShape_setQueryFilterData_mut(self.as_mut_ptr(), &data as *const PxFilterData) }
    }

    /// Read the query filter data of this shape
    fn get_query_filter_data(&self) -> PxFilterData {
        unsafe { PxShape_getQueryFilterData(self.as_ptr()) }
    }

    /// Get the number of materials associated with this shape
    fn get_nb_materials(&self) -> u16 {
        unsafe { PxShape_getNbMaterials(self.as_ptr()) }
    }

    /// Get a vector of all materials associated with this shape
    fn get_materials(&self) -> Vec<&Self::Material> {
        unsafe {
            let capacity = self.get_nb_materials();
            let mut buffer: Vec<&Self::Material> = Vec::with_capacity(capacity as usize);
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

    /// Get a mut vector of all materials associated with this shape
    fn get_materials_mut(&mut self) -> Vec<&mut Self::Material> {
        unsafe {
            let capacity = self.get_nb_materials();
            let mut buffer: Vec<&mut Self::Material> = Vec::with_capacity(capacity as usize);
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
    fn set_flag(&mut self, flag: ShapeFlag, enable: bool) {
        unsafe { PxShape_setFlag_mut(self.as_mut_ptr(), flag.into(), enable) }
    }
}
