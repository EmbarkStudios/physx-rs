/*!
Wrapper for PxBase.
 */

use super::px_type::*;
use enumflags2::BitFlags;
use physx_macros::physx_type;
use physx_sys::{
    PxBase, PxBaseFlag, PxBaseFlags, PxBase_getBaseFlags, PxBase_getConcreteType,
    PxBase_getConcreteTypeName, PxBase_isReleasable, PxBase_release_mut, PxBase_setBaseFlag_mut,
    PxBase_setBaseFlags_mut,
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
    AticulationJoint = 14,
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
            14 => AticulationJoint,
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

#[physx_type]
impl Base {
    /// Release this object, invalidating the pointer
    pub fn release(&mut self) {
        unsafe {
            PxBase_release_mut(self.get_raw_mut());
        }
    }

    /// Get the name of the real type referenced by this pointer, or None if the returned string is not valid
    pub fn get_concrete_type_name(&self) -> Option<&str> {
        unsafe {
            std::ffi::CStr::from_ptr(PxBase_getConcreteTypeName(self.get_raw()) as _)
                .to_str()
                .ok()
        }
    }

    /// Returns an enumerated value identifying the type. You can match this against the raw values in ConcreteType to identify the type of this object
    pub fn get_concrete_type(&self) -> ConcreteType {
        unsafe { PxBase_getConcreteType(self.get_raw()).into() }
    }

    /// Set or unset the specified flag on this object.
    pub fn set_base_flag(&mut self, flag: BaseFlag, value: bool) {
        unsafe {
            PxBase_setBaseFlag_mut(self.get_raw_mut(), flag.into(), value);
        }
    }

    /// Set the BaseFlags of this object. Note that replaces all flags currently
    /// on the object. Use `set_base_flag` to set individual flags.
    pub fn set_base_flags(&mut self, in_flags: BitFlags<BaseFlag>) {
        unsafe {
            PxBase_setBaseFlags_mut(
                self.get_raw_mut(),
                PxBaseFlags {
                    mBits: in_flags.bits(),
                },
            );
        }
    }

    /// Read the BaseFlags of this object
    pub fn get_base_flags(&self) -> BitFlags<BaseFlag> {
        let flags = unsafe { PxBase_getBaseFlags(self.get_raw()) };
        unsafe { BitFlags::new(flags.mBits) }
    }

    ////////////////////////////////////////////////////////////////////////////////

    /// Returns true if this object can be released, i.e., it is not subordinate.
    pub fn is_releasable(&self) -> bool {
        unsafe { PxBase_isReleasable(self.get_raw()) }
    }

    /// Checks if the concrete type of this object matches the string. N.B: This
    /// is NOT equivalent to the PhysX `is_kind_of`, which accounts for derived
    /// types. This function does exact matching.
    pub fn is_type(&self, name: &str) -> bool {
        self.get_concrete_type_name()
            .map(|n| n == name)
            .unwrap_or(false)
    }

    /// Checks if the concrete type of this object matches the string. N.B: This
    /// is NOT equivalent to the PhysX `is_kind_of`, which accounts for derived
    /// types. This function does exact matching.
    pub fn is_type_enum(&self, _type: ConcreteType) -> bool {
        self.get_concrete_type() == _type
    }
}
