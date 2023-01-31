autocxx::include_cpp! {
    #include "PxPhysicsAPI.h"
    safety!(unsafe_ffi)
    generate!("physx::PxFoundation")
    generate!("physx::PxPhysics")
    generate!("physx::PxCpuDispatcher")

    generate!("physx::PxScene")
    generate!("physx::PxRigidActor")

    generate!("physx::PxGeometry")
    generate!("physx::PxSphereGeometry")
}
