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

macro_rules! Class {
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

#[macro_export(crate)]
/// Macro for quickly defining Class<...> impls for new type wrapeprs.
/// The type must be reprp(transparent), and have the Px object in a field
/// named obj.
// TODO remove this? It's only used in a couple places now.
macro_rules! ClassObj {
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

// TODO most of these aren't instantiable, so they really don't matter.  OTOH,
// if someone needed to use the raw types via the physx_sys crate, having these defined
// would probably make them very happy.  The instantiable ones need to stay due to the
// bound on the Class impl for the newtype wrappers.
Class!(PxBase);
Class!(PxActor: PxBase);
Class!(PxRigidActor: PxActor, PxBase);
Class!(PxRigidStatic: PxRigidActor, PxActor, PxBase);
Class!(PxRigidBody: PxRigidActor, PxActor, PxBase);
Class!(PxRigidDynamic: PxRigidBody, PxRigidActor, PxActor, PxBase);
Class!(
    PxArticulationLink: PxRigidBody,
    PxRigidActor,
    PxActor,
    PxBase
);
Class!(PxAggregate: PxBase);
Class!(PxArticulationBase: PxBase);
Class!(PxArticulation: PxArticulationBase, PxBase);
Class!(PxArticulationReducedCoordinate: PxArticulationBase, PxBase);
Class!(PxArticulationJointBase: PxBase);
Class!(PxArticulationJoint: PxArticulationJointBase, PxBase);
Class!(
    PxArticulationJointReducedCoordinate: PxArticulationJointBase,
    PxBase
);
Class!(PxBVHStructure: PxBase);
Class!(PxConstraint: PxBase);
Class!(PxConvexMesh: PxBase);
Class!(PxHeightField: PxBase);
Class!(PxJoint: PxBase);
Class!(PxContactJoint: PxJoint, PxBase);
Class!(PxD6Joint: PxJoint, PxBase);
Class!(PxDistanceJoint: PxJoint, PxBase);
Class!(PxFixedJoint: PxJoint, PxBase);
Class!(PxPrismaticJoint: PxJoint, PxBase);
Class!(PxRevoluteJoint: PxJoint, PxBase);
Class!(PxSphericalJoint: PxJoint, PxBase);
Class!(PxMaterial: PxBase);
Class!(PxPruningStructure: PxBase);
Class!(PxShape: PxBase);
Class!(PxTriangleMesh: PxBase);
Class!(PxVehicleWheels: PxBase);
Class!(PxVehicleNoDrive: PxVehicleWheels, PxBase);
Class!(PxVehicleDrive: PxVehicleWheels, PxBase);
Class!(PxVehicleDrive4W: PxVehicleDrive, PxVehicleWheels, PxBase);
Class!(PxVehicleDriveNW: PxVehicleDrive, PxVehicleWheels, PxBase);
Class!(PxVehicleDriveTank: PxVehicleDrive, PxVehicleWheels, PxBase);

Class!(PxFoundation);
Class!(PxPhysics);
Class!(PxScene);
Class!(PxPvd);
Class!(PxPvdSceneClient);
Class!(PxPvdTransport);
Class!(PxCooking);

Class!(PxControllerManager);
Class!(PxController);
Class!(PxCapsuleController: PxController);
Class!(PxBoxController: PxController);
Class!(PxControllerDesc);
Class!(PxCapsuleControllerDesc: PxControllerDesc);
Class!(PxBoxControllerDesc: PxControllerDesc);

Class!(PxTransform);
Class!(PxQuat);
Class!(PxVec3);
Class!(PxExtendedVec3);
Class!(PxMeshScale);
Class!(PxBounds3);

Class!(PxArticulationCache);

macro_rules! ImplClassForGeometries {
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

ImplClassForGeometries!(
    PxSphereGeometry,
    PxBoxGeometry,
    PxCapsuleGeometry,
    PxHeightFieldGeometry,
    PxTriangleMeshGeometry,
    PxConvexMeshGeometry,
    PxPlaneGeometry,
);
