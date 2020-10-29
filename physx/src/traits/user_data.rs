use std::{ffi::c_void, mem::size_of};

use crate::{
    articulation::Articulation, articulation_link::ArticulationLink,
    articulation_reduced_coordinate::ArticulationReducedCoordinate,
    controller::PxCapsuleControllerDesc, material::Material, rigid_dynamic::RigidDynamic,
    rigid_static::RigidStatic, scene::Scene, shape::Shape,
};

/// UserData allows easy access and initialization of userData *mut c_void fields on Px objects.
/// Not all Px objects with user data expose them as a field, so not all objects with user data can use this.
/// Safety: all constructors of implementing types must call `init_user_data` during construction.
/// If this does not happen, calling get_user_data or get_user_data_mut may return garbage data, or
/// dereference an invalid pointer.  If U is larger than a *mut ptr it will be stored on the heap,
/// and it may need to be explicitly dropped by turning the field back into a Box and droppig it.
/// If U implements Drop, this may be as simple as calling `get_user_data_mut` and then calling drop(),
/// but implementation is left to the concrete type's Drop impl.
pub unsafe trait UserData: Sized {
    type U;
    /// Returns a reference to the userData field
    fn user_data_ptr(&self) -> &*mut c_void;
    /// Returns a mutable reference to the userData field.
    fn user_data_ptr_mut(&mut self) -> &mut *mut c_void;

    unsafe fn init_user_data(&mut self, user_data: Self::U) -> &mut Self {
        if size_of::<Self::U>() > size_of::<*mut c_void>() {
            // Too big to pack into a *mut c_void, kick it to the heap.
            let data = Box::new(user_data);
            *self.user_data_ptr_mut() = Box::into_raw(data) as *mut c_void;
        } else {
            // DATA_SIZE <= VOID_SIZE
            *self.user_data_ptr_mut() = *(&user_data as *const Self::U as *const *mut c_void)
        }
        self
    }

    /// Safety: The user data field must have previously been initialized via `init_user_data`.
    unsafe fn get_user_data(this: &Self) -> &Self::U {
        if size_of::<Self::U>() > size_of::<*mut c_void>() {
            &*((*this.user_data_ptr()) as *const Self::U)
        } else {
            // DATA_SIZE <= VOID_SIZE
            // Data is stored directly in the userData field.
            &*(this.user_data_ptr() as *const *mut c_void as *const Self::U)
        }
    }

    /// Safety: The user data field must have previously been initialized via `init_user_data`.
    unsafe fn get_user_data_mut(this: &mut Self) -> &mut Self::U {
        if size_of::<Self::U>() > size_of::<*mut c_void>() {
            // Data is stored in a Box<U> on the heap, and userData is just a pointer to it.
            &mut *((*this.user_data_ptr_mut()) as *mut Self::U)
        } else {
            // DATA_SIZE <= VOID_SIZE
            // Data is stored directly in the userData field.
            &mut *(this.user_data_ptr_mut() as *mut *mut c_void as *mut Self::U)
        }
    }
}

macro_rules! UserData {
    ($PxType:ident <$UserType:ident$(,$UserTypes:ident)*>) => {
        unsafe impl<$UserType$(,$UserTypes)*> $crate::traits::UserData for $PxType<$UserType$(,$UserTypes)*> {
            type U = $UserType;

            fn user_data_ptr(&self) -> &*mut c_void {
                &self.obj.userData
            }

            fn user_data_ptr_mut(&mut self) -> &mut *mut c_void {
                &mut self.obj.userData
            }
        }
    }
}

UserData!(RigidStatic<S, H, M>);
UserData!(RigidDynamic<D, H, M>);
UserData!(ArticulationLink<L, H, M>);

UserData!(Articulation<U, L, H, M>);
UserData!(ArticulationReducedCoordinate<U, L, H, M>);

UserData!(Scene<U, L, S, D, M, H, T, C>);
UserData!(PxCapsuleControllerDesc<U>);

UserData!(Shape<U, M>);
UserData!(Material<U>);
