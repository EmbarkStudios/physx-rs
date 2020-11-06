// PxBase hierarchy
use physx_sys::{
    PxActor,
    PxAggregate,
    PxArticulation,
    PxArticulationBase,
    PxArticulationJoint,
    PxArticulationJointBase,
    PxArticulationJointReducedCoordinate,
    PxArticulationLink,
    PxArticulationReducedCoordinate,
    PxBVHStructure,
    PxBase,
    PxConstraint,
    PxContactJoint,
    PxConvexMesh,
    PxD6Joint,
    PxDistanceJoint,
    PxFixedJoint,
    PxHeightField,
    PxJoint,
    PxMaterial,
    PxPrismaticJoint,
    PxPruningStructure,
    PxRevoluteJoint,
    PxRigidActor,
    PxRigidBody,
    PxRigidDynamic,
    PxRigidStatic,
    PxShape,
    PxSphericalJoint,
    PxTriangleMesh,
    PxVehicleDrive,
    PxVehicleDrive4W,
    PxVehicleDriveNW,
    PxVehicleDriveTank,
    //PxBVH34TriangleMesh, // Doesn't exist?
    //PxBVH33TriangleMesh, // Doesn't exist?
    PxVehicleNoDrive,
    PxVehicleWheels,
};

// Main classes
use physx_sys::{
    PxCooking, PxFoundation, PxPhysics, PxPvd, PxPvdSceneClient, PxPvdTransport, PxScene,
};

// Controller stuff
use physx_sys::{
    PxBoxController, PxBoxControllerDesc, PxCapsuleController, PxCapsuleControllerDesc,
    PxController, PxControllerDesc, PxControllerManager,
};

// Math
use physx_sys::{PxBounds3, PxExtendedVec3, PxMeshScale, PxQuat, PxTransform, PxVec3};

// Geometries
use physx_sys::{
    PxBoxGeometry, PxCapsuleGeometry, PxConvexMeshGeometry, PxGeometry, PxHeightFieldGeometry,
    PxPlaneGeometry, PxSphereGeometry, PxTriangleMeshGeometry,
};

// Misc
use physx_sys::PxArticulationCache;

////////////////////////////////////////////////
// Class
/// Trait for getting raw pointers for FFI calls, used to provide default implementations
/// of traits that "re-object" a C wrapper of a C++ library.
///
/// # Safety
/// **Implementing `Class<S>` for `T` where `S` is not a superclass of `T` will cause Undefined Behaviour.**
///
/// This trait may hide a raw pointer cast from `*Self` to `*T`.  It is intended for use in
/// default implementations for traits wrapping C++ classes.  In C++-land this is just how
/// things are done, but From Rust's perspective, this is madness.
/// The relations defined between types using this trait must align with the C++ class hierarchy.
/// The [Inherit] trait can be used to simplify implementing `Class<S> for T where T: Class<T>`.
pub unsafe trait Class<S> {
    /// Returns a raw const pointer to the wrapped type.
    /// Retrieving a raw pointer is safe.  However, pretty much any use of a raw pointer is unsafe.
    /// In particular: this pointer should not be used to construct a second owning wrapper around the pointer.
    fn as_ptr(&self) -> *const S;

    /// Returns a raw mut pointer to the wrapped type.
    /// Retrieving a raw pointer is safe.  However, pretty much any use of a raw pointer is unsafe.
    /// In particular: this pointer should not be used to construct a second owning wrapper around the pointer.
    fn as_mut_ptr(&mut self) -> *mut S;
}

#[macro_export(crate)]
/// Macro for quickly defining Class<...> impls for new type wrappers.
/// The type must be repr(transparent), and have the Px object in a field
/// named obj.  Will not work if the type parameters have trait bounds.
macro_rules! DeriveClassForNewType {
    ($PxWrap:ident : $($PxClass:ident),+) => {
        $(unsafe impl Class<::physx_sys::$PxClass> for $PxWrap {
            fn as_ptr(&self) -> *const ::physx_sys::$PxClass {
                &self.obj as *const _ as *const _
            }
            fn as_mut_ptr(&mut self) -> *mut ::physx_sys::$PxClass {
                &mut self.obj as *mut _ as *mut _
            }
        })+
    }
}

/// Derive Class<T> for the raw Px* types.
macro_rules! DeriveClass {
    ($PxType:ty $(: $($PxClass:ty),*)?) => {
        unsafe impl Class<$PxType> for $PxType {
            fn as_ptr(&self) -> *const $PxType {
                self
            }
            fn as_mut_ptr(&mut self) -> *mut $PxType {
                self
            }
        }

        $($(unsafe impl Class<$PxClass> for $PxType {
            fn as_ptr(&self) -> *const $PxClass {
                self as *const _ as *const _
            }
            fn as_mut_ptr(&mut self) -> *mut $PxClass {
                self as *mut _ as *mut _
            }
        })*)?
    }
}

DeriveClass!(PxBase);
DeriveClass!(PxActor: PxBase);
DeriveClass!(PxRigidActor: PxActor, PxBase);
DeriveClass!(PxRigidStatic: PxRigidActor, PxActor, PxBase);
DeriveClass!(PxRigidBody: PxRigidActor, PxActor, PxBase);
DeriveClass!(PxRigidDynamic: PxRigidBody, PxRigidActor, PxActor, PxBase);
DeriveClass!(
    PxArticulationLink: PxRigidBody,
    PxRigidActor,
    PxActor,
    PxBase
);
DeriveClass!(PxAggregate: PxBase);
DeriveClass!(PxArticulationBase: PxBase);
DeriveClass!(PxArticulation: PxArticulationBase, PxBase);
DeriveClass!(PxArticulationReducedCoordinate: PxArticulationBase, PxBase);
DeriveClass!(PxArticulationJointBase: PxBase);
DeriveClass!(PxArticulationJoint: PxArticulationJointBase, PxBase);
DeriveClass!(
    PxArticulationJointReducedCoordinate: PxArticulationJointBase,
    PxBase
);
DeriveClass!(PxBVHStructure: PxBase);
DeriveClass!(PxConstraint: PxBase);
DeriveClass!(PxConvexMesh: PxBase);
DeriveClass!(PxHeightField: PxBase);
DeriveClass!(PxJoint: PxBase);
DeriveClass!(PxContactJoint: PxJoint, PxBase);
DeriveClass!(PxD6Joint: PxJoint, PxBase);
DeriveClass!(PxDistanceJoint: PxJoint, PxBase);
DeriveClass!(PxFixedJoint: PxJoint, PxBase);
DeriveClass!(PxPrismaticJoint: PxJoint, PxBase);
DeriveClass!(PxRevoluteJoint: PxJoint, PxBase);
DeriveClass!(PxSphericalJoint: PxJoint, PxBase);
DeriveClass!(PxMaterial: PxBase);
DeriveClass!(PxPruningStructure: PxBase);
DeriveClass!(PxShape: PxBase);
DeriveClass!(PxTriangleMesh: PxBase);
DeriveClass!(PxVehicleWheels: PxBase);
DeriveClass!(PxVehicleNoDrive: PxVehicleWheels, PxBase);
DeriveClass!(PxVehicleDrive: PxVehicleWheels, PxBase);
DeriveClass!(PxVehicleDrive4W: PxVehicleDrive, PxVehicleWheels, PxBase);
DeriveClass!(PxVehicleDriveNW: PxVehicleDrive, PxVehicleWheels, PxBase);
DeriveClass!(PxVehicleDriveTank: PxVehicleDrive, PxVehicleWheels, PxBase);

DeriveClass!(PxFoundation);
DeriveClass!(PxPhysics);
DeriveClass!(PxScene);
DeriveClass!(PxPvd);
DeriveClass!(PxPvdSceneClient);
DeriveClass!(PxPvdTransport);
DeriveClass!(PxCooking);

DeriveClass!(PxControllerManager);
DeriveClass!(PxController);
DeriveClass!(PxCapsuleController: PxController);
DeriveClass!(PxBoxController: PxController);
DeriveClass!(PxControllerDesc);
DeriveClass!(PxCapsuleControllerDesc: PxControllerDesc);
DeriveClass!(PxBoxControllerDesc: PxControllerDesc);

DeriveClass!(PxTransform);
DeriveClass!(PxQuat);
DeriveClass!(PxVec3);
DeriveClass!(PxExtendedVec3);
DeriveClass!(PxMeshScale);
DeriveClass!(PxBounds3);

DeriveClass!(PxArticulationCache);

macro_rules! DeriveClassForGeometries {
    ($($Px: ty,)*) => {
        $(
            unsafe impl Class<$Px> for $Px {
                fn as_ptr(&self) -> *const $Px {
                    self
                }
                fn as_mut_ptr(&mut self) -> *mut $Px {
                    self
                }
            }
            unsafe impl Class<PxGeometry> for $Px {
                fn as_ptr(&self) -> *const PxGeometry {
                    self as *const _ as *const _
                }
                fn as_mut_ptr(&mut self) -> *mut PxGeometry {
                    self as *mut _ as *mut _
                }
            }
        )*
    }
}

DeriveClassForGeometries!(
    PxSphereGeometry,
    PxBoxGeometry,
    PxCapsuleGeometry,
    PxHeightFieldGeometry,
    PxTriangleMeshGeometry,
    PxConvexMeshGeometry,
    PxPlaneGeometry,
);
