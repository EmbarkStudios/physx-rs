// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 15 April 2019

#![warn(clippy::all)]

/*!

*/

use std::{marker::PhantomData, ptr::drop_in_place};

use crate::{
    geometry::PxGeometry,
    math::PxTransform,
    owner::Owner,
    physics::Physics,
    rigid_actor::RigidActor,
    shape::Shape,
    traits::{Class, UserData},
};

use physx_sys::{phys_PxCreateStatic, PxRigidActor_release_mut, PxRigidStatic_getConcreteTypeName};

/// A new type wrapper for PxArticulation.  Parametrized by it's user data type,
/// and the type of it's Shapes.
#[repr(transparent)]
pub struct PxRigidStatic<S, Geom: Shape> {
    pub(crate) obj: physx_sys::PxRigidStatic,
    phantom_user_data: PhantomData<(S, Geom)>,
}

unsafe impl<U, Geom: Shape> UserData for PxRigidStatic<U, Geom> {
    type UserData = U;

    fn user_data_ptr(&self) -> &*mut std::ffi::c_void {
        &self.obj.userData
    }

    fn user_data_ptr_mut(&mut self) -> &mut *mut std::ffi::c_void {
        &mut self.obj.userData
    }
}

impl<S, Geom: Shape> Drop for PxRigidStatic<S, Geom> {
    fn drop(&mut self) {
        for shape in self.get_shapes() {
            for _material in shape.get_materials() {
                // is PxMAterial_release thread safe?
            }
            // is PxShape_release thread safe?
        }
        unsafe {
            drop_in_place(self.get_user_data_mut() as *mut _);
            PxRigidActor_release_mut(self.as_mut_ptr())
        }
    }
}

unsafe impl<P, S, Geom: Shape> Class<P> for PxRigidStatic<S, Geom>
where
    physx_sys::PxRigidStatic: Class<P>,
{
    fn as_ptr(&self) -> *const P {
        self.obj.as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut P {
        self.obj.as_mut_ptr()
    }
}

unsafe impl<S: Send, Geom: Shape + Send> Send for PxRigidStatic<S, Geom> {}
unsafe impl<S: Sync, Geom: Shape + Sync> Sync for PxRigidStatic<S, Geom> {}

impl<S, Geom: Shape> RigidActor for PxRigidStatic<S, Geom> {
    type Shape = Geom;
}

impl<S, Geom: Shape> RigidStatic for PxRigidStatic<S, Geom> {}

pub trait RigidStatic: Class<physx_sys::PxRigidStatic> + RigidActor + UserData {
    fn new(
        physics: &mut impl Physics,
        transform: PxTransform,
        geometry: &impl Class<PxGeometry>,
        material: &mut <Self::Shape as Shape>::Material,
        shape_transform: PxTransform,
        user_data: Self::UserData,
    ) -> Option<Owner<Self>> {
        unsafe {
            Self::from_raw(
                phys_PxCreateStatic(
                    physics.as_mut_ptr(),
                    transform.as_ptr(),
                    geometry.as_ptr(),
                    material.as_mut_ptr(),
                    shape_transform.as_ptr(),
                ),
                user_data,
            )
        }
    }

    /// Safety: Calling this twice on the same pointer may result in a double-free or other use-after-free.
    /// FFI calls that return a *mut PxRigidStatic should be wrapped in this to avoid working with raw pointers.
    unsafe fn from_raw(
        ptr: *mut physx_sys::PxRigidStatic,
        user_data: Self::UserData,
    ) -> Option<Owner<Self>> {
        let actor = (ptr as *mut Self).as_mut();
        Owner::from_raw(actor?.init_user_data(user_data))
    }

    fn get_user_data(&self) -> &Self::UserData {
        // Safety: all construction goes through from_raw, which calls init_user_data
        unsafe { UserData::get_user_data(self) }
    }

    fn get_user_data_mut(&mut self) -> &mut Self::UserData {
        // Safety: all construction goes through from_raw, which calls init_user_data
        unsafe { UserData::get_user_data_mut(self) }
    }

    /// Get the name of the real type referenced by this pointer, or None if the returned string is not valid
    // TODO does this leak memory? or is it returning a pointer into the object or maybe an interned string?
    fn get_concrete_type_name(&self) -> Option<&str> {
        unsafe {
            std::ffi::CStr::from_ptr(PxRigidStatic_getConcreteTypeName(self.as_ptr()) as _)
                .to_str()
                .ok()
        }
    }
}
