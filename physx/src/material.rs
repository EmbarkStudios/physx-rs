use crate::{
    owner::Owner,
    traits::{Class, UserData},
};

use std::marker::PhantomData;

use enumflags2::{bitflags, BitFlags};

use physx_sys::{
    PxCombineMode,
    PxMaterialFlags,
    PxMaterial_acquireReference_mut,
    PxMaterial_getDynamicFriction,
    PxMaterial_getFlags,
    PxMaterial_getFrictionCombineMode,
    PxMaterial_getReferenceCount,
    PxMaterial_getRestitution,
    PxMaterial_getRestitutionCombineMode,
    PxMaterial_getStaticFriction,
    PxMaterial_release_mut,
    PxMaterial_setDynamicFriction_mut,
    PxMaterial_setFlag_mut,
    PxMaterial_setFlags_mut,
    PxMaterial_setFrictionCombineMode_mut,
    PxMaterial_setRestitutionCombineMode_mut,
    PxMaterial_setRestitution_mut,
    PxMaterial_setStaticFriction_mut,
    //PxMaterial_getConcreteTypeName,
};

#[bitflags]
#[derive(Copy, Clone, Debug)]
#[repr(u16)]
pub enum MaterialFlag {
    DisableFriction = 1 << 0,
    DisableStrongFriction = 1 << 1,
    ImprovedPatchFriction = 1 << 2,
}

pub type MaterialFlags = BitFlags<MaterialFlag>;

/// Determines how the restitution and friction properties of materials are combined
/// to produce the coefficients for that interaction.
#[derive(Copy, Clone, Debug)]
#[repr(u32)]
pub enum CombineMode {
    Average = 0,
    Min = 1,
    Multiply = 2,
    Max = 3,
    //NValues, // These are not valid variants, and they don't need to be defined in Rust
    //Pad32,
}

impl From<PxCombineMode::Enum> for CombineMode {
    fn from(mode: PxCombineMode::Enum) -> Self {
        match mode {
            PxCombineMode::eAVERAGE => CombineMode::Average,
            PxCombineMode::eMIN => CombineMode::Min,
            PxCombineMode::eMULTIPLY => CombineMode::Multiply,
            PxCombineMode::eMAX => CombineMode::Max,
            _ => unreachable!("Invalid enum variant: {:?}.", mode),
        }
    }
}

/// A new type wrapper for PxMaterial.  Parametrized by it's user data type.
#[repr(transparent)]
pub struct PxMaterial<U> {
    pub(crate) obj: physx_sys::PxMaterial,
    phantom_user_data: PhantomData<U>,
}

unsafe impl<U> UserData for PxMaterial<U> {
    type UserData = U;

    fn user_data_ptr(&self) -> &*mut std::ffi::c_void {
        &self.obj.userData
    }

    fn user_data_ptr_mut(&mut self) -> &mut *mut std::ffi::c_void {
        &mut self.obj.userData
    }
}

impl<U> Drop for PxMaterial<U> {
    fn drop(&mut self) {
        unsafe {
            PxMaterial_release_mut(self.as_mut_ptr());
        }
    }
}

unsafe impl<P, U> Class<P> for PxMaterial<U>
where
    physx_sys::PxMaterial: Class<P>,
{
    fn as_ptr(&self) -> *const P {
        self.obj.as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut P {
        self.obj.as_mut_ptr()
    }
}

unsafe impl<U: Send> Send for PxMaterial<U> {}
unsafe impl<U: Sync> Sync for PxMaterial<U> {}

impl<M> Material for PxMaterial<M> {}

pub trait Material: Class<physx_sys::PxMaterial> + UserData {
    /// # Safety
    /// Owner's own the pointer they wrap, using the pointer after dropping the Owner,
    /// or creating multiple Owners from the same pointer will cause UB.  Use `into_ptr` to
    /// retrieve the pointer and consume the Owner without dropping the pointee.
    unsafe fn from_raw(
        ptr: *mut physx_sys::PxMaterial,
        user_data: Self::UserData,
    ) -> Option<Owner<Self>> {
        Owner::from_raw((ptr as *mut Self).as_mut()?.init_user_data(user_data))
    }

    /// Get a reference to the user data.
    #[inline]
    fn get_user_data(&self) -> &Self::UserData {
        // Safety: all constructors go through from_raw which calls init_user_data
        unsafe { UserData::get_user_data(self) }
    }

    /// Get a mutable reference to the user data.
    #[inline]
    fn get_user_data_mut(&mut self) -> &mut Self::UserData {
        // Safety: all constructors go through from_raw which calls init_user_data
        unsafe { UserData::get_user_data_mut(self) }
    }

    /// Get the current ref count of the material.
    #[inline]
    fn get_reference_count(&self) -> u32 {
        unsafe { PxMaterial_getReferenceCount(self.as_ptr()) }
    }

    /// Increment the ref count of the material.
    #[inline]
    fn acquire_reference(&mut self) {
        unsafe { PxMaterial_acquireReference_mut(self.as_mut_ptr()) }
    }

    /// Set the dynamic friction.
    /// - Friction must be positive.
    /// - If greater than static friction, effective static friction will be increased to match.
    /// - Will not wake actors.
    #[inline]
    fn set_dynamic_friction(&mut self, mut coefficient: f32) {
        if coefficient.is_sign_negative() {
            coefficient = 0.0;
        }
        unsafe {
            PxMaterial_setDynamicFriction_mut(self.as_mut_ptr(), coefficient);
        }
    }

    /// Get the dynamic friction.
    #[inline]
    fn get_dynamic_friction(&self) -> f32 {
        unsafe { PxMaterial_getDynamicFriction(self.as_ptr()) }
    }

    /// Set the static friction.
    /// - Friction must be positive, negative friction is set to 0.0.
    /// - Will not wake actors.
    #[inline]
    fn set_static_friction(&mut self, mut coefficient: f32) {
        if coefficient.is_sign_negative() {
            coefficient = 0.0;
        }
        unsafe {
            PxMaterial_setStaticFriction_mut(self.as_mut_ptr(), coefficient);
        }
    }

    /// Get the static frction.
    #[inline]
    fn get_static_friction(&self) -> f32 {
        unsafe { PxMaterial_getStaticFriction(self.as_ptr()) }
    }

    /// Set the restitution.
    /// - Restitution must be in [0.0 ..= 1.0], values outside tyhe range are clamped.
    /// - A reitution of 0.0 minimizes bouncing, higher values mean more bounce.
    #[inline]
    fn set_restitution(&mut self, mut restitution: f32) {
        if restitution.is_sign_negative() {
            restitution = 0.0;
        } else if restitution > 1.0 {
            restitution = 1.0
        };
        unsafe {
            PxMaterial_setRestitution_mut(self.as_mut_ptr(), restitution);
        }
    }

    /// Get the restitution.
    #[inline]
    fn get_restitution(&self) -> f32 {
        unsafe { PxMaterial_getRestitution(self.as_ptr()) }
    }

    /// Set a material flag.
    #[inline]
    fn set_flag(&mut self, flag: MaterialFlag, set: bool) {
        unsafe { PxMaterial_setFlag_mut(self.as_mut_ptr(), flag as _, set) }
    }

    /// Set all the material flags.
    #[inline]
    fn set_flags(&mut self, flags: MaterialFlags) {
        unsafe {
            PxMaterial_setFlags_mut(
                self.as_mut_ptr(),
                PxMaterialFlags {
                    mBits: flags.bits(),
                },
            );
        }
    }

    /// Get the material flags.
    #[inline]
    fn get_flags(&self) -> MaterialFlags {
        unsafe {
            let PxMaterialFlags { mBits } = PxMaterial_getFlags(self.as_ptr());
            BitFlags::from_bits_unchecked(mBits)
        }
    }

    /// Set the friction combine mode.
    #[inline]
    fn set_friction_combined_mode(&mut self, combine_mode: CombineMode) {
        unsafe {
            PxMaterial_setFrictionCombineMode_mut(self.as_mut_ptr(), combine_mode as _);
        }
    }

    /// Get the friction combine mode.
    #[inline]
    fn get_friction_combine_mode(&self) -> CombineMode {
        let combine_mode = unsafe { PxMaterial_getFrictionCombineMode(self.as_ptr()) };
        debug_assert!(combine_mode < PxCombineMode::eN_VALUES);
        combine_mode.into()
    }

    /// Set the restitution combine mode.
    #[inline]
    fn set_restitution_combine_mode(&mut self, combine_mode: CombineMode) {
        unsafe {
            PxMaterial_setRestitutionCombineMode_mut(self.as_mut_ptr(), combine_mode as _);
        }
    }

    /// Get the restitution combine mode.
    #[inline]
    fn get_restitution_combine_mode(&self) -> CombineMode {
        let combine_mode = unsafe { PxMaterial_getRestitutionCombineMode(self.as_ptr()) };
        debug_assert!(combine_mode < PxCombineMode::eN_VALUES);
        combine_mode.into()
    }
}
