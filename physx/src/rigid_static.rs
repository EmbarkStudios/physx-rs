// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created: 15 April 2019

#![warn(clippy::all)]

/*!

*/

use std::marker::PhantomData;

use crate::{
    owner::Owner,
    geometry::PxGeometry,
    material::Material,
    physics::Physics,
    math::PxTransform,
    rigid_actor::RigidActor,
    traits::{Class, UserData},
};

use physx_sys::{
    phys_PxCreateStatic,
    PxRigidActor_release_mut,
    PxRigidStatic_getConcreteTypeName,
};

#[repr(transparent)]
pub struct RigidStatic<S, H, M>{
    pub(crate) obj: physx_sys::PxRigidStatic,
    phantom_user_data: PhantomData<(S, H, M)>
}

impl<S, H, M> RigidActor<H, M> for RigidStatic<S, H, M> {}

unsafe impl<P, S, H, M> Class<P> for RigidStatic<S, H, M> where physx_sys::PxRigidStatic: Class<P> {
    fn as_ptr(&self) -> *const P {
        self.obj.as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut P {
        self.obj.as_mut_ptr()
    }
}

impl<S, H, M> RigidStatic<S, H, M> {
    pub fn new(
        physics: &mut Physics<H, M>,
        transform: PxTransform,
        geometry: &impl Class<PxGeometry>,
        material: &mut Material<M>,
        shape_transform: PxTransform,
        user_data: S
    ) -> Option<Owner<Self>> {
        unsafe { Self::from_raw(
            phys_PxCreateStatic(
                physics.as_mut_ptr(),
                transform.as_ptr(),
                geometry.as_ptr(),
                material.as_mut_ptr(),
                shape_transform.as_ptr(),
            ),
            user_data
        ) }
    }

    /// Safety: Calling this twice on the same pointer may result in a double-free or other use-after-free.
    /// FFI calls that return a *mut PxRigidStatic should be wrapped in this to avoid working with raw pointers.
    pub(crate) unsafe fn from_raw(ptr: *mut physx_sys::PxRigidStatic, user_data: S) -> Option<Owner<Self>> {
        let actor = (ptr as *mut Self).as_mut();
        Owner::from_raw(actor?.init_user_data(user_data))
    }

    pub fn get_user_data(&self) -> &S {
        // Safety: user data was initiliazed during construction, see `new` and `from_raw`.
        unsafe { UserData::get_user_data(self) }
    }

    pub fn get_user_data_mut(&mut self) -> &mut S {
        // Safety: user data was initiliazed during construction, see `new` and `from_raw`.
        unsafe { UserData::get_user_data_mut(self) }
    }

    /// Get the name of the real type referenced by this pointer, or None if the returned string is not valid
    // TODO does this leak memory? or is it returning a pointer into the object or to an interned string?
    pub fn get_concrete_type_name(&self) -> Option<&str> {
        unsafe {
            std::ffi::CStr::from_ptr(PxRigidStatic_getConcreteTypeName(self.as_ptr()) as _)
                .to_str()
                .ok()
        }
    }
}

unsafe impl<S: Send, H: Send, M: Send> Send for RigidStatic<S, H, M> {}
unsafe impl<S: Sync, H: Sync, M: Sync> Sync for RigidStatic<S, H, M> {}

impl<S, H, M> Drop for RigidStatic<S, H, M> {
    fn drop(&mut self) {
        for shape in self.get_shapes() {
            for material in shape.get_materials() {
                drop(material)
            }
        }
        drop(self.get_user_data_mut());
        unsafe { PxRigidActor_release_mut(self.as_mut_ptr()) }
    }
}