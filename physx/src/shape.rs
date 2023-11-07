// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 29 April 2019

#![allow(non_upper_case_globals)]

use crate::{
    material::Material,
    owner::Owner,
    traits::{Class, UserData},
};

use std::marker::PhantomData;

use physx_sys::UserDataField;
#[rustfmt::skip]
use physx_sys::{
    PxFilterData,
    PxFilterData_new_1,
    PxShape_getMaterials,
    PxShape_getNbMaterials,
    PxShape_getQueryFilterData,
    PxShape_getSimulationFilterData,
    PxShape_setFlag_mut,
    PxShape_setFlags_mut,
    PxShape_setQueryFilterData_mut,
    PxShape_setSimulationFilterData_mut,
};

bitflags::bitflags! {
    /// Layers used for collision/querying of shapes
    #[repr(transparent)]
    pub struct CollisionLayers: u32 {
        const Ghost = 1 << 0;
        const Terrain = 1 << 1;
        const Static = 1 << 2;
        const Character = 1 << 3;
    }
}

pub use physx_sys::{PxShapeFlag as ShapeFlag, PxShapeFlags as ShapeFlags};

/// A new type wrapper for PxShape.  Parametrized by it's user data type,
/// and the type of it's Material.
#[repr(transparent)]
pub struct PxShape<U, M: Material> {
    pub(crate) obj: physx_sys::PxShape,
    phantom_user_data: PhantomData<(U, M)>,
}

unsafe impl<U, M: Material> UserData for PxShape<U, M> {
    type UserData = U;

    fn user_data_ptr(&self) -> &UserDataField {
        &self.obj.userData
    }

    fn user_data_ptr_mut(&mut self) -> &mut UserDataField {
        &mut self.obj.userData
    }
}

impl<U, M: Material> Drop for PxShape<U, M> {
    fn drop(&mut self) {
        unsafe {
            self.drop_and_dealloc_user_data();
            use crate::base::RefCounted;
            self.release();
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
        unsafe {
            let shape = (ptr as *mut Self).as_mut();
            Owner::from_raw(shape?.init_user_data(user_data))
        }
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
        this_layers: CollisionLayers,
        other_layers: CollisionLayers,
        word3: u32,
        word4: u32,
    ) {
        let mut data = unsafe { PxFilterData_new_1() };
        data.word0 = this_layers.bits();
        data.word1 = other_layers.bits();
        data.word2 = word3;
        data.word3 = word4;

        unsafe { PxShape_setSimulationFilterData_mut(self.as_mut_ptr(), &data) }
    }

    /// Read the collision filter data of this shape
    fn get_simulation_filter_data(&self) -> PxFilterData {
        unsafe { PxShape_getSimulationFilterData(self.as_ptr()) }
    }

    /// Set the query filter of this shape
    fn set_query_filter_data(&mut self, this_layers: CollisionLayers) {
        let mut data = unsafe { PxFilterData_new_1() };
        data.word0 = this_layers.bits();
        data.word1 = 0;
        data.word2 = 0;
        data.word3 = 0;

        unsafe { PxShape_setQueryFilterData_mut(self.as_mut_ptr(), &data) }
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
        unsafe { PxShape_setFlag_mut(self.as_mut_ptr(), flag, enable) }
    }

    /// Sets the flags on this shape to the specified bitset
    fn set_flags(&mut self, flags: ShapeFlags) {
        unsafe { PxShape_setFlags_mut(self.as_mut_ptr(), flags) }
    }
}
