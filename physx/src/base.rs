/*!
Wrapper for PxBase.
 */

use crate::traits::Class;
use enumflags2::BitFlags;

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

#[derive(Copy, Clone, BitFlags, Debug)]
#[repr(u16)]
pub enum BaseFlag {
    OwnsMemory = 1,
    IsReleasable = 2,
}

impl Into<PxBaseFlag::Enum> for BaseFlag {
    fn into(self) -> PxBaseFlag::Enum {
        self as PxBaseFlag::Enum
    }
}

#[derive(Debug, Clone, Copy, PartialEq)]
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
        use ConcreteType::*;
        match val {
            0 => Undefined,
            1 => Heightfield,
            2 => ConvexMesh,
            3 => TriangleMeshBvh33,
            4 => TriangleMeshBvh34,
            5 => RigidDynamic,
            6 => RigidStatic,
            7 => Shape,
            8 => Material,
            9 => Constraint,
            10 => Aggregate,
            11 => Articulation,
            12 => ArticulationReducedCoordinate,
            13 => ArticulationLink,
            14 => ArticulationJoint,
            15 => ArticulationJointReducedCoordinate,
            16 => PruningStructure,
            17 => BvhStructure,
            18 => PhysxCoreCount,
            256 => FirstPhysxExtension,
            512 => FirstVehicleExtension,
            1024 => FirstUserExtension,
            _ => Undefined,
        }
    }
}

/*******************************************************************************
 * Section BASE                                                                *
 ******************************************************************************/
impl<T> Base for T where T: Class<PxBase> + Sized {}
pub trait Base: Class<PxBase> + Sized {
    /// Get the name of the real type referenced by this pointer, or None if the returned string is not valid
    // TODO is this useful? The ConcreteType enum has the same info neatly packed into a u16, and C strings are sketch.
    fn get_concrete_type_name(&self) -> Option<&str> {
        unsafe {
            std::ffi::CStr::from_ptr(PxBase_getConcreteTypeName(self.as_ptr() as *const _) as _)
                .to_str()
                .ok()
        }
    }

    /// Returns an enumerated value identifying the type. You can match this against the raw values in ConcreteType to identify the type of this object
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
        unsafe { BitFlags::new(flags.mBits) }
    }

    ////////////////////////////////////////////////////////////////////////////////

    /// Returns true if this object can be released, i.e., it is not subordinate.
    fn is_releasable(&self) -> bool {
        unsafe { PxBase_isReleasable(self.as_ptr() as *const _) }
    }
}
