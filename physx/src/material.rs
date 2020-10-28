use crate::{
    owner::Owner,
    traits::{Class, UserData},
};

use std::marker::PhantomData;

use enumflags2::BitFlags;

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

#[derive(Copy, Clone, BitFlags, Debug)]
#[repr(u16)]
pub enum MaterialFlag {
    DisableFriction = 1 << 0,
    DisableStrongFriction = 1 << 1,
    ImprovedPatchFriction = 1 << 2,
}

pub type MaterialFlags = BitFlags<MaterialFlag>;

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
            _ => unimplemented!("Invalid enum variant: {:?}.", mode),
        }
    }
}

#[repr(transparent)]
pub struct Material<U> {
    pub(crate) obj: physx_sys::PxMaterial,
    phantom_user_data: PhantomData<U>,
}

unsafe impl<P, U> Class<P> for Material<U>
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

impl<U> Material<U> {
    pub(crate) unsafe fn from_raw<'a>(
        ptr: *mut physx_sys::PxMaterial,
        user_data: U,
    ) -> Option<Owner<Self>> {
        let material = (ptr as *mut Self).as_mut();
        Owner::from_raw(material?.init_user_data(user_data))
    }

    pub fn get_user_data(&self) -> &U {
        // Safety: all constructors go through from_raw which calls init_user_data
        unsafe { UserData::get_user_data(self) }
    }

    pub fn get_user_data_mut(&mut self) -> &mut U {
        // Safety: all constructors go through from_raw which calls init_user_data
        unsafe { UserData::get_user_data_mut(self) }
    }

    #[inline]
    pub unsafe fn get_ref_count(&self) -> u32 {
        PxMaterial_getReferenceCount(self.as_ptr())
    }

    #[inline]
    pub unsafe fn acquire_reference(&mut self) {
        PxMaterial_acquireReference_mut(self.as_mut_ptr())
    }

    #[inline]
    pub unsafe fn set_dynamic_friction(&mut self, coefficient: f32) {
        PxMaterial_setDynamicFriction_mut(self.as_mut_ptr(), coefficient);
    }

    #[inline]
    pub unsafe fn get_dynamic_friction(&self) -> f32 {
        PxMaterial_getDynamicFriction(self.as_ptr())
    }

    #[inline]
    pub unsafe fn set_static_friction(&mut self, coefficient: f32) {
        PxMaterial_setStaticFriction_mut(self.as_mut_ptr(), coefficient);
    }

    #[inline]
    pub unsafe fn get_static_friction(&self) -> f32 {
        PxMaterial_getStaticFriction(self.as_ptr())
    }

    #[inline]
    pub unsafe fn set_restitution(&mut self, restitution: f32) {
        PxMaterial_setRestitution_mut(self.as_mut_ptr(), restitution);
    }

    #[inline]
    pub unsafe fn get_restitution(&self) -> f32 {
        PxMaterial_getRestitution(self.as_ptr())
    }

    #[inline]
    pub unsafe fn set_flag(&mut self, flag: MaterialFlag, set: bool) {
        PxMaterial_setFlag_mut(self.as_mut_ptr(), flag as _, set)
    }

    #[inline]
    pub unsafe fn set_flags(&mut self, flags: MaterialFlags) {
        PxMaterial_setFlags_mut(
            self.as_mut_ptr(),
            PxMaterialFlags {
                mBits: flags.bits(),
            },
        );
    }

    #[inline]
    pub unsafe fn get_flags(&self) -> MaterialFlags {
        let PxMaterialFlags { mBits } = PxMaterial_getFlags(self.as_ptr());
        BitFlags::new(mBits)
    }

    #[inline]
    pub unsafe fn set_friction_combined_mode(&mut self, combine_mode: CombineMode) {
        PxMaterial_setFrictionCombineMode_mut(self.as_mut_ptr(), combine_mode as _);
    }

    #[inline]
    pub unsafe fn get_friction_combine_mode(&self) -> CombineMode {
        let combine_mode = PxMaterial_getFrictionCombineMode(self.as_ptr());
        debug_assert!(combine_mode < PxCombineMode::eN_VALUES);
        combine_mode.into()
    }

    #[inline]
    pub unsafe fn set_restitution_combine_mode(&mut self, combine_mode: CombineMode) {
        PxMaterial_setRestitutionCombineMode_mut(self.as_mut_ptr(), combine_mode as _);
    }

    #[inline]
    pub unsafe fn get_restitution_combine_mode(&self) -> CombineMode {
        let combine_mode = PxMaterial_getRestitutionCombineMode(self.as_ptr());
        debug_assert!(combine_mode < PxCombineMode::eN_VALUES);
        combine_mode.into()
    }
}

unsafe impl<U: Send> Send for Material<U> {}
unsafe impl<U: Sync> Sync for Material<U> {}

impl<U> Drop for Material<U> {
    fn drop(&mut self) {
        unsafe {
            PxMaterial_release_mut(self.as_mut_ptr());
        }
    }
}
