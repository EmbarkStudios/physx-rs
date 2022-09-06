/*!
Wrapper for PxBase.
 */

use crate::traits::Class;
use enumflags2::{bitflags, BitFlags};

pub(crate) use physx_sys::PxBase;

use physx_sys::{
    PxBaseFlag,
    PxBaseFlags,
    PxBase_getBaseFlags,
    PxBase_getConcreteType,
    PxBase_getConcreteTypeName,
    PxBase_isReleasable,
    PxBase_setBaseFlag_mut,
    PxBase_setBaseFlags_mut,
    //PxBase is non-instatiable, and any objects that use this dtor should call it directly
    //PxBase_release_mut,
};

/*******************************************************************************
 * Section ENUMERATIONS                                                        *
 ******************************************************************************/

#[bitflags]
#[derive(Copy, Clone, Debug)]
#[repr(u16)]
pub enum BaseFlag {
    OwnsMemory = 1,
    IsReleasable = 2,
}

impl From<BaseFlag> for PxBaseFlag::Enum {
    fn from(value: BaseFlag) -> Self {
        value as PxBaseFlag::Enum
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum ConcreteType {
    Undefined = 0,
    Heightfield = 1,
    ConvexMesh = 2,
    TriangleMeshBvh33 = 3,
    TriangleMeshBvh34 = 4,
    RigidDynamic = 5,
    RigidStatic = 6,
    Shape = 7,
    Material = 8,
    Constraint = 9,
    Aggregate = 10,
    Articulation = 11,
    ArticulationReducedCoordinate = 12,
    ArticulationLink = 13,
    ArticulationJoint = 14,
    ArticulationJointReducedCoordinate = 15,
    PruningStructure = 16,
    BvhStructure = 17,
    PhysxCoreCount = 18,
    FirstPhysxExtension = 256,
    FirstVehicleExtension = 512,
    FirstUserExtension = 1024,
}

impl From<u16> for ConcreteType {
    fn from(val: u16) -> Self {
        match val {
            1 => ConcreteType::Heightfield,
            2 => ConcreteType::ConvexMesh,
            3 => ConcreteType::TriangleMeshBvh33,
            4 => ConcreteType::TriangleMeshBvh34,
            5 => ConcreteType::RigidDynamic,
            6 => ConcreteType::RigidStatic,
            7 => ConcreteType::Shape,
            8 => ConcreteType::Material,
            9 => ConcreteType::Constraint,
            10 => ConcreteType::Aggregate,
            11 => ConcreteType::Articulation,
            12 => ConcreteType::ArticulationReducedCoordinate,
            13 => ConcreteType::ArticulationLink,
            14 => ConcreteType::ArticulationJoint,
            15 => ConcreteType::ArticulationJointReducedCoordinate,
            16 => ConcreteType::PruningStructure,
            17 => ConcreteType::BvhStructure,
            18 => ConcreteType::PhysxCoreCount,
            256 => ConcreteType::FirstPhysxExtension,
            512 => ConcreteType::FirstVehicleExtension,
            1024 => ConcreteType::FirstUserExtension,
            _ => ConcreteType::Undefined,
        }
    }
}

/*******************************************************************************
 * Section BASE                                                                *
 ******************************************************************************/
impl<T> Base for T where T: Class<PxBase> + Sized {}
pub trait Base: Class<PxBase> + Sized {
    /// Get the name of the real type referenced by this pointer, or None if the returned string is not valid
    fn get_concrete_type_name(&self) -> Option<&str> {
        unsafe {
            std::ffi::CStr::from_ptr(PxBase_getConcreteTypeName(self.as_ptr() as *const _) as _)
                .to_str()
                .ok()
        }
    }

    /// Returns an enumerated value identifying the type.  This may return ConcreteType::Undefined
    /// in surprising situations, notably this does not seem to work with `get_active_actors`.  Use
    /// `get_type` for actors if possible.
    fn get_concrete_type(&self) -> ConcreteType {
        unsafe { PxBase_getConcreteType(self.as_ptr()).into() }
    }

    /// Set or unset the specified flag on this object.
    fn set_base_flag(&mut self, flag: BaseFlag, value: bool) {
        unsafe {
            PxBase_setBaseFlag_mut(self.as_mut_ptr() as *mut _, flag.into(), value);
        }
    }

    /// Set the BaseFlags of this object. Note that replaces all flags currently
    /// on the object. Use `set_base_flag` to set individual flags.
    fn set_base_flags(&mut self, in_flags: BitFlags<BaseFlag>) {
        unsafe {
            PxBase_setBaseFlags_mut(
                self.as_mut_ptr() as *mut _,
                PxBaseFlags {
                    mBits: in_flags.bits(),
                },
            );
        }
    }

    /// Read the BaseFlags of this object
    fn get_base_flags(&self) -> BitFlags<BaseFlag> {
        let flags = unsafe { PxBase_getBaseFlags(self.as_ptr() as *const _) };
        unsafe { BitFlags::from_bits_unchecked(flags.mBits) }
    }

    ////////////////////////////////////////////////////////////////////////////////

    /// Returns true if this object can be released, i.e., it is not subordinate.
    fn is_releasable(&self) -> bool {
        unsafe { PxBase_isReleasable(self.as_ptr() as *const _) }
    }
}
