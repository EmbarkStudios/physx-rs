// PxBase hierarchy
use physx_sys::{
    PxBase,
    PxActor,
    PxRigidActor,
    PxRigidStatic,
    PxRigidBody,
    PxRigidDynamic,
    PxArticulationLink,
    PxAggregate,
    PxArticulationBase,
    PxArticulation,
    PxArticulationReducedCoordinate,
    PxArticulationJointBase,
    PxArticulationJoint,
    PxArticulationJointReducedCoordinate,
    PxBVHStructure,
    PxConstraint,
    PxConvexMesh,
    PxHeightField,
    PxJoint,
    PxContactJoint,
    PxD6Joint,
    PxDistanceJoint,
    PxFixedJoint,
    PxPrismaticJoint,
    PxRevoluteJoint,
    PxSphericalJoint,
    PxMaterial,
    PxPruningStructure,
    PxShape,
    PxTriangleMesh,
    PxVehicleWheels,
    PxVehicleNoDrive,
    PxVehicleDrive,
    PxVehicleDrive4W,
    PxVehicleDriveNW,
    PxVehicleDriveTank,
    //PxBVH34TriangleMesh, // Doesn't exist?
    //PxBVH33TriangleMesh, // Doesn't exist?
};

// Main classes
use physx_sys::{
    PxCooking,
    PxFoundation,
    PxPhysics,
    PxPvdSceneClient,
    PxPvdTransport,
    PxPvd,
    PxScene,
};

// Controller stuff
use physx_sys::{
    PxControllerManager,
    PxController,
    PxCapsuleController,
    PxBoxController,
    PxControllerDesc,
    PxCapsuleControllerDesc,
    PxBoxControllerDesc,
};

// Math
use physx_sys::{
    PxTransform,
    PxVec3,
    PxExtendedVec3,
    PxQuat,
    PxMeshScale,
    PxBounds3,
};

// Geometries
use physx_sys::{
    PxGeometry,
    PxSphereGeometry,
    PxBoxGeometry,
    PxCapsuleGeometry,
    PxHeightFieldGeometry,
    PxTriangleMeshGeometry,
    PxConvexMeshGeometry,
    PxPlaneGeometry,
};

// Misc
use physx_sys::{
    PxArticulationCache,
};

////////////////////////////////////////////////
// Class
/// Trait for getting raw pointers for FFI calls, used to provide default implementations
/// of traits that "re-object" a C wrapper of a C++ library.
///
/// # Safety
/// **Implementing `Class<S>` for `T` where `S` is not a superclass of `T` will cause Undefined Behaviour.**
///
/// This trait may hide a raw pointer cast from `*Self` to `*T`.  It is intended for use in
/// default implementations for traits wrapping C++ classes.  In C++-land these are just
/// upcasts to a super-class, which is a-ok.  From the Rust side of things, this is madness.
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

// TODO delete? most of these aren't instantiable, so they really don't matter.  OTOH,
// if someone needed to use the raw types via the physx_sys crate, having these defined
// would probably make them very happy.
Class!(PxBase);
Class!(PxActor: PxBase);
Class!(PxRigidActor: PxActor, PxBase);
Class!(PxRigidStatic: PxRigidActor, PxActor, PxBase);
Class!(PxRigidBody: PxRigidActor, PxActor, PxBase);
Class!(PxRigidDynamic: PxRigidBody, PxRigidActor, PxActor, PxBase);
Class!(PxArticulationLink: PxRigidBody, PxRigidActor, PxActor, PxBase);
Class!(PxAggregate: PxBase);
Class!(PxArticulationBase: PxBase);
Class!(PxArticulation: PxArticulationBase, PxBase);
Class!(PxArticulationReducedCoordinate: PxArticulationBase, PxBase);
Class!(PxArticulationJointBase: PxBase);
Class!(PxArticulationJoint: PxArticulationJointBase, PxBase);
Class!(PxArticulationJointReducedCoordinate: PxArticulationJointBase, PxBase);
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

Class!(PxArticulationCache);