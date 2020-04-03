using namespace physx;
#include "structgen_out.hpp"
static_assert(sizeof(physx::PxAllocatorCallback) == sizeof(physx_PxAllocatorCallback_Pod), "POD wrapper for physx::PxAllocatorCallback has incorrect size.");
static_assert(sizeof(physx::PxAssertHandler) == sizeof(physx_PxAssertHandler_Pod), "POD wrapper for physx::PxAssertHandler has incorrect size.");
static_assert(sizeof(physx::PxVec3) == sizeof(physx_PxVec3_Pod), "POD wrapper for physx::PxVec3 has incorrect size.");
static_assert(sizeof(physx::PxQuat) == sizeof(physx_PxQuat_Pod), "POD wrapper for physx::PxQuat has incorrect size.");
static_assert(sizeof(physx::PxMat33) == sizeof(physx_PxMat33_Pod), "POD wrapper for physx::PxMat33 has incorrect size.");
static_assert(sizeof(physx::PxPlane) == sizeof(physx_PxPlane_Pod), "POD wrapper for physx::PxPlane has incorrect size.");
static_assert(sizeof(physx::PxTransform) == sizeof(physx_PxTransform_Pod), "POD wrapper for physx::PxTransform has incorrect size.");
static_assert(sizeof(physx::PxVec4) == sizeof(physx_PxVec4_Pod), "POD wrapper for physx::PxVec4 has incorrect size.");
static_assert(sizeof(physx::PxMat44) == sizeof(physx_PxMat44_Pod), "POD wrapper for physx::PxMat44 has incorrect size.");
static_assert(sizeof(physx::PxBounds3) == sizeof(physx_PxBounds3_Pod), "POD wrapper for physx::PxBounds3 has incorrect size.");
static_assert(sizeof(physx::PxErrorCallback) == sizeof(physx_PxErrorCallback_Pod), "POD wrapper for physx::PxErrorCallback has incorrect size.");
static_assert(sizeof(physx::PxInputStream) == sizeof(physx_PxInputStream_Pod), "POD wrapper for physx::PxInputStream has incorrect size.");
static_assert(sizeof(physx::PxInputData) == sizeof(physx_PxInputData_Pod), "POD wrapper for physx::PxInputData has incorrect size.");
static_assert(sizeof(physx::PxOutputStream) == sizeof(physx_PxOutputStream_Pod), "POD wrapper for physx::PxOutputStream has incorrect size.");
static_assert(sizeof(physx::PxVec2) == sizeof(physx_PxVec2_Pod), "POD wrapper for physx::PxVec2 has incorrect size.");
static_assert(sizeof(physx::PxStridedData) == sizeof(physx_PxStridedData_Pod), "POD wrapper for physx::PxStridedData has incorrect size.");
static_assert(sizeof(physx::PxBoundedData) == sizeof(physx_PxBoundedData_Pod), "POD wrapper for physx::PxBoundedData has incorrect size.");
static_assert(sizeof(physx::PxDebugPoint) == sizeof(physx_PxDebugPoint_Pod), "POD wrapper for physx::PxDebugPoint has incorrect size.");
static_assert(sizeof(physx::PxDebugLine) == sizeof(physx_PxDebugLine_Pod), "POD wrapper for physx::PxDebugLine has incorrect size.");
static_assert(sizeof(physx::PxDebugTriangle) == sizeof(physx_PxDebugTriangle_Pod), "POD wrapper for physx::PxDebugTriangle has incorrect size.");
static_assert(sizeof(physx::PxDebugText) == sizeof(physx_PxDebugText_Pod), "POD wrapper for physx::PxDebugText has incorrect size.");
static_assert(sizeof(physx::PxRenderBuffer) == sizeof(physx_PxRenderBuffer_Pod), "POD wrapper for physx::PxRenderBuffer has incorrect size.");
static_assert(sizeof(physx::PxProcessPxBaseCallback) == sizeof(physx_PxProcessPxBaseCallback_Pod), "POD wrapper for physx::PxProcessPxBaseCallback has incorrect size.");
static_assert(sizeof(physx::PxBase) == sizeof(physx_PxBase_Pod), "POD wrapper for physx::PxBase has incorrect size.");
static_assert(sizeof(physx::PxSerializationContext) == sizeof(physx_PxSerializationContext_Pod), "POD wrapper for physx::PxSerializationContext has incorrect size.");
static_assert(sizeof(physx::PxCollection) == sizeof(physx_PxCollection_Pod), "POD wrapper for physx::PxCollection has incorrect size.");
static_assert(sizeof(physx::PxDeserializationContext) == sizeof(physx_PxDeserializationContext_Pod), "POD wrapper for physx::PxDeserializationContext has incorrect size.");
static_assert(sizeof(physx::PxSerializationRegistry) == sizeof(physx_PxSerializationRegistry_Pod), "POD wrapper for physx::PxSerializationRegistry has incorrect size.");
static_assert(sizeof(physx::PxSerializer) == sizeof(physx_PxSerializer_Pod), "POD wrapper for physx::PxSerializer has incorrect size.");
static_assert(sizeof(physx::PxRepXSerializer) == sizeof(physx_PxRepXSerializer_Pod), "POD wrapper for physx::PxRepXSerializer has incorrect size.");
static_assert(sizeof(physx::PxTolerancesScale) == sizeof(physx_PxTolerancesScale_Pod), "POD wrapper for physx::PxTolerancesScale has incorrect size.");
static_assert(sizeof(physx::PxStringTable) == sizeof(physx_PxStringTable_Pod), "POD wrapper for physx::PxStringTable has incorrect size.");
static_assert(sizeof(physx::PxFoundation) == sizeof(physx_PxFoundation_Pod), "POD wrapper for physx::PxFoundation has incorrect size.");
static_assert(sizeof(physx::PxProfilerCallback) == sizeof(physx_PxProfilerCallback_Pod), "POD wrapper for physx::PxProfilerCallback has incorrect size.");
static_assert(sizeof(physx::PxPhysicsInsertionCallback) == sizeof(physx_PxPhysicsInsertionCallback_Pod), "POD wrapper for physx::PxPhysicsInsertionCallback has incorrect size.");
static_assert(sizeof(physx::PxTaskManager) == sizeof(physx_PxTaskManager_Pod), "POD wrapper for physx::PxTaskManager has incorrect size.");
static_assert(sizeof(physx::PxCpuDispatcher) == sizeof(physx_PxCpuDispatcher_Pod), "POD wrapper for physx::PxCpuDispatcher has incorrect size.");
static_assert(sizeof(physx::PxTask) == sizeof(physx_PxTask_Pod), "POD wrapper for physx::PxTask has incorrect size.");
static_assert(sizeof(physx::PxBaseTask) == sizeof(physx_PxBaseTask_Pod), "POD wrapper for physx::PxBaseTask has incorrect size.");
static_assert(sizeof(physx::PxLightCpuTask) == sizeof(physx_PxLightCpuTask_Pod), "POD wrapper for physx::PxLightCpuTask has incorrect size.");
static_assert(sizeof(physx::PxGeometry) == sizeof(physx_PxGeometry_Pod), "POD wrapper for physx::PxGeometry has incorrect size.");
static_assert(sizeof(physx::PxBoxGeometry) == sizeof(physx_PxBoxGeometry_Pod), "POD wrapper for physx::PxBoxGeometry has incorrect size.");
static_assert(sizeof(physx::PxBVHStructure) == sizeof(physx_PxBVHStructure_Pod), "POD wrapper for physx::PxBVHStructure has incorrect size.");
static_assert(sizeof(physx::PxCapsuleGeometry) == sizeof(physx_PxCapsuleGeometry_Pod), "POD wrapper for physx::PxCapsuleGeometry has incorrect size.");
static_assert(sizeof(physx::PxConvexMesh) == sizeof(physx_PxConvexMesh_Pod), "POD wrapper for physx::PxConvexMesh has incorrect size.");
static_assert(sizeof(physx::PxHullPolygon) == sizeof(physx_PxHullPolygon_Pod), "POD wrapper for physx::PxHullPolygon has incorrect size.");
static_assert(sizeof(physx::PxMeshScale) == sizeof(physx_PxMeshScale_Pod), "POD wrapper for physx::PxMeshScale has incorrect size.");
static_assert(sizeof(physx::PxConvexMeshGeometry) == sizeof(physx_PxConvexMeshGeometry_Pod), "POD wrapper for physx::PxConvexMeshGeometry has incorrect size.");
static_assert(sizeof(physx::PxSphereGeometry) == sizeof(physx_PxSphereGeometry_Pod), "POD wrapper for physx::PxSphereGeometry has incorrect size.");
static_assert(sizeof(physx::PxPlaneGeometry) == sizeof(physx_PxPlaneGeometry_Pod), "POD wrapper for physx::PxPlaneGeometry has incorrect size.");
static_assert(sizeof(physx::PxTriangleMesh) == sizeof(physx_PxTriangleMesh_Pod), "POD wrapper for physx::PxTriangleMesh has incorrect size.");
static_assert(sizeof(physx::PxTriangleMeshGeometry) == sizeof(physx_PxTriangleMeshGeometry_Pod), "POD wrapper for physx::PxTriangleMeshGeometry has incorrect size.");
static_assert(sizeof(physx::PxHeightField) == sizeof(physx_PxHeightField_Pod), "POD wrapper for physx::PxHeightField has incorrect size.");
static_assert(sizeof(physx::PxHeightFieldGeometry) == sizeof(physx_PxHeightFieldGeometry_Pod), "POD wrapper for physx::PxHeightFieldGeometry has incorrect size.");
static_assert(sizeof(physx::PxGeometryHolder) == sizeof(physx_PxGeometryHolder_Pod), "POD wrapper for physx::PxGeometryHolder has incorrect size.");
static_assert(sizeof(physx::PxRigidActor) == sizeof(physx_PxRigidActor_Pod), "POD wrapper for physx::PxRigidActor has incorrect size.");
static_assert(sizeof(physx::PxShape) == sizeof(physx_PxShape_Pod), "POD wrapper for physx::PxShape has incorrect size.");
static_assert(sizeof(physx::PxActorShape) == sizeof(physx_PxActorShape_Pod), "POD wrapper for physx::PxActorShape has incorrect size.");
static_assert(sizeof(physx::PxQueryHit) == sizeof(physx_PxQueryHit_Pod), "POD wrapper for physx::PxQueryHit has incorrect size.");
static_assert(sizeof(physx::PxLocationHit) == sizeof(physx_PxLocationHit_Pod), "POD wrapper for physx::PxLocationHit has incorrect size.");
static_assert(sizeof(physx::PxRaycastHit) == sizeof(physx_PxRaycastHit_Pod), "POD wrapper for physx::PxRaycastHit has incorrect size.");
static_assert(sizeof(physx::PxSweepHit) == sizeof(physx_PxSweepHit_Pod), "POD wrapper for physx::PxSweepHit has incorrect size.");
static_assert(sizeof(physx::PxHeightFieldSample) == sizeof(physx_PxHeightFieldSample_Pod), "POD wrapper for physx::PxHeightFieldSample has incorrect size.");
static_assert(sizeof(physx::PxHeightFieldDesc) == sizeof(physx_PxHeightFieldDesc_Pod), "POD wrapper for physx::PxHeightFieldDesc has incorrect size.");
static_assert(sizeof(physx::PxTriangle) == sizeof(physx_PxTriangle_Pod), "POD wrapper for physx::PxTriangle has incorrect size.");
static_assert(sizeof(physx::PxSimpleTriangleMesh) == sizeof(physx_PxSimpleTriangleMesh_Pod), "POD wrapper for physx::PxSimpleTriangleMesh has incorrect size.");
static_assert(sizeof(physx::PxActor) == sizeof(physx_PxActor_Pod), "POD wrapper for physx::PxActor has incorrect size.");
static_assert(sizeof(physx::PxScene) == sizeof(physx_PxScene_Pod), "POD wrapper for physx::PxScene has incorrect size.");
static_assert(sizeof(physx::PxAggregate) == sizeof(physx_PxAggregate_Pod), "POD wrapper for physx::PxAggregate has incorrect size.");
static_assert(sizeof(physx::PxArticulationBase) == sizeof(physx_PxArticulationBase_Pod), "POD wrapper for physx::PxArticulationBase has incorrect size.");
static_assert(sizeof(physx::PxArticulationLink) == sizeof(physx_PxArticulationLink_Pod), "POD wrapper for physx::PxArticulationLink has incorrect size.");
static_assert(sizeof(physx::PxArticulationJointBase) == sizeof(physx_PxArticulationJointBase_Pod), "POD wrapper for physx::PxArticulationJointBase has incorrect size.");
static_assert(sizeof(physx::PxArticulation) == sizeof(physx_PxArticulation_Pod), "POD wrapper for physx::PxArticulation has incorrect size.");
static_assert(sizeof(physx::PxArticulationDriveCache) == sizeof(physx_PxArticulationDriveCache_Pod), "POD wrapper for physx::PxArticulationDriveCache has incorrect size.");
static_assert(sizeof(physx::PxConstraintInvMassScale) == sizeof(physx_PxConstraintInvMassScale_Pod), "POD wrapper for physx::PxConstraintInvMassScale has incorrect size.");
static_assert(sizeof(physx::PxConstraintVisualizer) == sizeof(physx_PxConstraintVisualizer_Pod), "POD wrapper for physx::PxConstraintVisualizer has incorrect size.");
static_assert(sizeof(physx::PxConstraintConnector) == sizeof(physx_PxConstraintConnector_Pod), "POD wrapper for physx::PxConstraintConnector has incorrect size.");
static_assert(sizeof(physx::PxConstraint) == sizeof(physx_PxConstraint_Pod), "POD wrapper for physx::PxConstraint has incorrect size.");
static_assert(sizeof(physx::PxSolverBody) == sizeof(physx_PxSolverBody_Pod), "POD wrapper for physx::PxSolverBody has incorrect size.");
static_assert(sizeof(physx::PxSolverBodyData) == sizeof(physx_PxSolverBodyData_Pod), "POD wrapper for physx::PxSolverBodyData has incorrect size.");
static_assert(sizeof(physx::PxConstraintAllocator) == sizeof(physx_PxConstraintAllocator_Pod), "POD wrapper for physx::PxConstraintAllocator has incorrect size.");
static_assert(sizeof(physx::PxTGSSolverBodyVel) == sizeof(physx_PxTGSSolverBodyVel_Pod), "POD wrapper for physx::PxTGSSolverBodyVel has incorrect size.");
static_assert(sizeof(physx::PxTGSSolverBodyData) == sizeof(physx_PxTGSSolverBodyData_Pod), "POD wrapper for physx::PxTGSSolverBodyData has incorrect size.");
static_assert(sizeof(physx::PxSpatialForce) == sizeof(physx_PxSpatialForce_Pod), "POD wrapper for physx::PxSpatialForce has incorrect size.");
static_assert(sizeof(physx::PxSpatialVelocity) == sizeof(physx_PxSpatialVelocity_Pod), "POD wrapper for physx::PxSpatialVelocity has incorrect size.");
static_assert(sizeof(physx::PxArticulationRootLinkData) == sizeof(physx_PxArticulationRootLinkData_Pod), "POD wrapper for physx::PxArticulationRootLinkData has incorrect size.");
static_assert(sizeof(physx::PxArticulationCache) == sizeof(physx_PxArticulationCache_Pod), "POD wrapper for physx::PxArticulationCache has incorrect size.");
static_assert(sizeof(physx::PxArticulationReducedCoordinate) == sizeof(physx_PxArticulationReducedCoordinate_Pod), "POD wrapper for physx::PxArticulationReducedCoordinate has incorrect size.");
static_assert(sizeof(physx::PxJoint) == sizeof(physx_PxJoint_Pod), "POD wrapper for physx::PxJoint has incorrect size.");
static_assert(sizeof(physx::PxArticulationJoint) == sizeof(physx_PxArticulationJoint_Pod), "POD wrapper for physx::PxArticulationJoint has incorrect size.");
static_assert(sizeof(physx::PxArticulationJointReducedCoordinate) == sizeof(physx_PxArticulationJointReducedCoordinate_Pod), "POD wrapper for physx::PxArticulationJointReducedCoordinate has incorrect size.");
static_assert(sizeof(physx::PxFilterData) == sizeof(physx_PxFilterData_Pod), "POD wrapper for physx::PxFilterData has incorrect size.");
static_assert(sizeof(physx::PxMaterial) == sizeof(physx_PxMaterial_Pod), "POD wrapper for physx::PxMaterial has incorrect size.");
static_assert(sizeof(physx::PxRigidBody) == sizeof(physx_PxRigidBody_Pod), "POD wrapper for physx::PxRigidBody has incorrect size.");
static_assert(sizeof(physx::PxSimulationFilterCallback) == sizeof(physx_PxSimulationFilterCallback_Pod), "POD wrapper for physx::PxSimulationFilterCallback has incorrect size.");
static_assert(sizeof(physx::PxQueryFilterData) == sizeof(physx_PxQueryFilterData_Pod), "POD wrapper for physx::PxQueryFilterData has incorrect size.");
static_assert(sizeof(physx::PxQueryFilterCallback) == sizeof(physx_PxQueryFilterCallback_Pod), "POD wrapper for physx::PxQueryFilterCallback has incorrect size.");
static_assert(sizeof(physx::PxOverlapHit) == sizeof(physx_PxOverlapHit_Pod), "POD wrapper for physx::PxOverlapHit has incorrect size.");
static_assert(sizeof(physx::PxBatchQueryMemory) == sizeof(physx_PxBatchQueryMemory_Pod), "POD wrapper for physx::PxBatchQueryMemory has incorrect size.");
static_assert(sizeof(physx::PxBatchQueryDesc) == sizeof(physx_PxBatchQueryDesc_Pod), "POD wrapper for physx::PxBatchQueryDesc has incorrect size.");
static_assert(sizeof(physx::PxBatchQuery) == sizeof(physx_PxBatchQuery_Pod), "POD wrapper for physx::PxBatchQuery has incorrect size.");
static_assert(sizeof(physx::PxQueryCache) == sizeof(physx_PxQueryCache_Pod), "POD wrapper for physx::PxQueryCache has incorrect size.");
static_assert(sizeof(physx::PxConstraintShaderTable) == sizeof(physx_PxConstraintShaderTable_Pod), "POD wrapper for physx::PxConstraintShaderTable has incorrect size.");
static_assert(sizeof(physx::PxMassModificationProps) == sizeof(physx_PxMassModificationProps_Pod), "POD wrapper for physx::PxMassModificationProps has incorrect size.");
static_assert(sizeof(physx::PxContactPatch) == sizeof(physx_PxContactPatch_Pod), "POD wrapper for physx::PxContactPatch has incorrect size.");
static_assert(sizeof(physx::PxContact) == sizeof(physx_PxContact_Pod), "POD wrapper for physx::PxContact has incorrect size.");
static_assert(sizeof(physx::PxContactStreamIterator) == sizeof(physx_PxContactStreamIterator_Pod), "POD wrapper for physx::PxContactStreamIterator has incorrect size.");
static_assert(sizeof(physx::PxModifiableContact) == sizeof(physx_PxModifiableContact_Pod), "POD wrapper for physx::PxModifiableContact has incorrect size.");
static_assert(sizeof(physx::PxContactSet) == sizeof(physx_PxContactSet_Pod), "POD wrapper for physx::PxContactSet has incorrect size.");
static_assert(sizeof(physx::PxContactModifyCallback) == sizeof(physx_PxContactModifyCallback_Pod), "POD wrapper for physx::PxContactModifyCallback has incorrect size.");
static_assert(sizeof(physx::PxContactModifyPair) == sizeof(physx_PxContactModifyPair_Pod), "POD wrapper for physx::PxContactModifyPair has incorrect size.");
static_assert(sizeof(physx::PxCCDContactModifyCallback) == sizeof(physx_PxCCDContactModifyCallback_Pod), "POD wrapper for physx::PxCCDContactModifyCallback has incorrect size.");
static_assert(sizeof(physx::PxDeletionListener) == sizeof(physx_PxDeletionListener_Pod), "POD wrapper for physx::PxDeletionListener has incorrect size.");
static_assert(sizeof(physx::PxLockedData) == sizeof(physx_PxLockedData_Pod), "POD wrapper for physx::PxLockedData has incorrect size.");
static_assert(sizeof(physx::PxPhysics) == sizeof(physx_PxPhysics_Pod), "POD wrapper for physx::PxPhysics has incorrect size.");
static_assert(sizeof(physx::PxSimulationEventCallback) == sizeof(physx_PxSimulationEventCallback_Pod), "POD wrapper for physx::PxSimulationEventCallback has incorrect size.");
static_assert(sizeof(physx::PxBroadPhaseCallback) == sizeof(physx_PxBroadPhaseCallback_Pod), "POD wrapper for physx::PxBroadPhaseCallback has incorrect size.");
static_assert(sizeof(physx::PxSceneLimits) == sizeof(physx_PxSceneLimits_Pod), "POD wrapper for physx::PxSceneLimits has incorrect size.");
static_assert(sizeof(physx::PxgDynamicsMemoryConfig) == sizeof(physx_PxgDynamicsMemoryConfig_Pod), "POD wrapper for physx::PxgDynamicsMemoryConfig has incorrect size.");
static_assert(sizeof(physx::PxSceneDesc) == sizeof(physx_PxSceneDesc_Pod), "POD wrapper for physx::PxSceneDesc has incorrect size.");
static_assert(sizeof(physx::PxRigidStatic) == sizeof(physx_PxRigidStatic_Pod), "POD wrapper for physx::PxRigidStatic has incorrect size.");
static_assert(sizeof(physx::PxRigidDynamic) == sizeof(physx_PxRigidDynamic_Pod), "POD wrapper for physx::PxRigidDynamic has incorrect size.");
static_assert(sizeof(physx::PxPruningStructure) == sizeof(physx_PxPruningStructure_Pod), "POD wrapper for physx::PxPruningStructure has incorrect size.");
static_assert(sizeof(physx::PxPvd) == sizeof(physx_PxPvd_Pod), "POD wrapper for physx::PxPvd has incorrect size.");
static_assert(sizeof(physx::PxSimulationStatistics) == sizeof(physx_PxSimulationStatistics_Pod), "POD wrapper for physx::PxSimulationStatistics has incorrect size.");
static_assert(sizeof(physx::PxPvdSceneClient) == sizeof(physx_PxPvdSceneClient_Pod), "POD wrapper for physx::PxPvdSceneClient has incorrect size.");
static_assert(sizeof(physx::PxDominanceGroupPair) == sizeof(physx_PxDominanceGroupPair_Pod), "POD wrapper for physx::PxDominanceGroupPair has incorrect size.");
static_assert(sizeof(physx::PxContactPair) == sizeof(physx_PxContactPair_Pod), "POD wrapper for physx::PxContactPair has incorrect size.");
static_assert(sizeof(physx::PxContactPairHeader) == sizeof(physx_PxContactPairHeader_Pod), "POD wrapper for physx::PxContactPairHeader has incorrect size.");
static_assert(sizeof(physx::PxBroadPhaseCaps) == sizeof(physx_PxBroadPhaseCaps_Pod), "POD wrapper for physx::PxBroadPhaseCaps has incorrect size.");
static_assert(sizeof(physx::PxBroadPhaseRegion) == sizeof(physx_PxBroadPhaseRegion_Pod), "POD wrapper for physx::PxBroadPhaseRegion has incorrect size.");
static_assert(sizeof(physx::PxBroadPhaseRegionInfo) == sizeof(physx_PxBroadPhaseRegionInfo_Pod), "POD wrapper for physx::PxBroadPhaseRegionInfo has incorrect size.");
static_assert(sizeof(physx::PxSceneReadLock) == sizeof(physx_PxSceneReadLock_Pod), "POD wrapper for physx::PxSceneReadLock has incorrect size.");
static_assert(sizeof(physx::PxSceneWriteLock) == sizeof(physx_PxSceneWriteLock_Pod), "POD wrapper for physx::PxSceneWriteLock has incorrect size.");
static_assert(sizeof(physx::PxContactPairExtraDataItem) == sizeof(physx_PxContactPairExtraDataItem_Pod), "POD wrapper for physx::PxContactPairExtraDataItem has incorrect size.");
static_assert(sizeof(physx::PxContactPairVelocity) == sizeof(physx_PxContactPairVelocity_Pod), "POD wrapper for physx::PxContactPairVelocity has incorrect size.");
static_assert(sizeof(physx::PxContactPairPose) == sizeof(physx_PxContactPairPose_Pod), "POD wrapper for physx::PxContactPairPose has incorrect size.");
static_assert(sizeof(physx::PxContactPairIndex) == sizeof(physx_PxContactPairIndex_Pod), "POD wrapper for physx::PxContactPairIndex has incorrect size.");
static_assert(sizeof(physx::PxContactPairExtraDataIterator) == sizeof(physx_PxContactPairExtraDataIterator_Pod), "POD wrapper for physx::PxContactPairExtraDataIterator has incorrect size.");
static_assert(sizeof(physx::PxContactPairPoint) == sizeof(physx_PxContactPairPoint_Pod), "POD wrapper for physx::PxContactPairPoint has incorrect size.");
static_assert(sizeof(physx::PxTriggerPair) == sizeof(physx_PxTriggerPair_Pod), "POD wrapper for physx::PxTriggerPair has incorrect size.");
static_assert(sizeof(physx::PxConstraintInfo) == sizeof(physx_PxConstraintInfo_Pod), "POD wrapper for physx::PxConstraintInfo has incorrect size.");
static_assert(sizeof(physx::PxExtendedVec3) == sizeof(physx_PxExtendedVec3_Pod), "POD wrapper for physx::PxExtendedVec3 has incorrect size.");
static_assert(sizeof(physx::PxObstacle) == sizeof(physx_PxObstacle_Pod), "POD wrapper for physx::PxObstacle has incorrect size.");
static_assert(sizeof(physx::PxBoxObstacle) == sizeof(physx_PxBoxObstacle_Pod), "POD wrapper for physx::PxBoxObstacle has incorrect size.");
static_assert(sizeof(physx::PxCapsuleObstacle) == sizeof(physx_PxCapsuleObstacle_Pod), "POD wrapper for physx::PxCapsuleObstacle has incorrect size.");
static_assert(sizeof(physx::PxObstacleContext) == sizeof(physx_PxObstacleContext_Pod), "POD wrapper for physx::PxObstacleContext has incorrect size.");
static_assert(sizeof(physx::PxControllerManager) == sizeof(physx_PxControllerManager_Pod), "POD wrapper for physx::PxControllerManager has incorrect size.");
static_assert(sizeof(physx::PxUserControllerHitReport) == sizeof(physx_PxUserControllerHitReport_Pod), "POD wrapper for physx::PxUserControllerHitReport has incorrect size.");
static_assert(sizeof(physx::PxController) == sizeof(physx_PxController_Pod), "POD wrapper for physx::PxController has incorrect size.");
static_assert(sizeof(physx::PxControllerShapeHit) == sizeof(physx_PxControllerShapeHit_Pod), "POD wrapper for physx::PxControllerShapeHit has incorrect size.");
static_assert(sizeof(physx::PxControllersHit) == sizeof(physx_PxControllersHit_Pod), "POD wrapper for physx::PxControllersHit has incorrect size.");
static_assert(sizeof(physx::PxControllerObstacleHit) == sizeof(physx_PxControllerObstacleHit_Pod), "POD wrapper for physx::PxControllerObstacleHit has incorrect size.");
static_assert(sizeof(physx::PxControllerFilterCallback) == sizeof(physx_PxControllerFilterCallback_Pod), "POD wrapper for physx::PxControllerFilterCallback has incorrect size.");
static_assert(sizeof(physx::PxControllerFilters) == sizeof(physx_PxControllerFilters_Pod), "POD wrapper for physx::PxControllerFilters has incorrect size.");
static_assert(sizeof(physx::PxControllerBehaviorCallback) == sizeof(physx_PxControllerBehaviorCallback_Pod), "POD wrapper for physx::PxControllerBehaviorCallback has incorrect size.");
static_assert(sizeof(physx::PxControllerDesc) == sizeof(physx_PxControllerDesc_Pod), "POD wrapper for physx::PxControllerDesc has incorrect size.");
static_assert(sizeof(physx::PxControllerState) == sizeof(physx_PxControllerState_Pod), "POD wrapper for physx::PxControllerState has incorrect size.");
static_assert(sizeof(physx::PxControllerStats) == sizeof(physx_PxControllerStats_Pod), "POD wrapper for physx::PxControllerStats has incorrect size.");
static_assert(sizeof(physx::PxBoxControllerDesc) == sizeof(physx_PxBoxControllerDesc_Pod), "POD wrapper for physx::PxBoxControllerDesc has incorrect size.");
static_assert(sizeof(physx::PxBoxController) == sizeof(physx_PxBoxController_Pod), "POD wrapper for physx::PxBoxController has incorrect size.");
static_assert(sizeof(physx::PxCapsuleControllerDesc) == sizeof(physx_PxCapsuleControllerDesc_Pod), "POD wrapper for physx::PxCapsuleControllerDesc has incorrect size.");
static_assert(sizeof(physx::PxCapsuleController) == sizeof(physx_PxCapsuleController_Pod), "POD wrapper for physx::PxCapsuleController has incorrect size.");
static_assert(sizeof(physx::PxConvexMeshDesc) == sizeof(physx_PxConvexMeshDesc_Pod), "POD wrapper for physx::PxConvexMeshDesc has incorrect size.");
static_assert(sizeof(physx::PxTriangleMeshDesc) == sizeof(physx_PxTriangleMeshDesc_Pod), "POD wrapper for physx::PxTriangleMeshDesc has incorrect size.");
static_assert(sizeof(physx::PxBVH33MidphaseDesc) == sizeof(physx_PxBVH33MidphaseDesc_Pod), "POD wrapper for physx::PxBVH33MidphaseDesc has incorrect size.");
static_assert(sizeof(physx::PxBVH34MidphaseDesc) == sizeof(physx_PxBVH34MidphaseDesc_Pod), "POD wrapper for physx::PxBVH34MidphaseDesc has incorrect size.");
static_assert(sizeof(physx::PxMidphaseDesc) == sizeof(physx_PxMidphaseDesc_Pod), "POD wrapper for physx::PxMidphaseDesc has incorrect size.");
static_assert(sizeof(physx::PxBVHStructureDesc) == sizeof(physx_PxBVHStructureDesc_Pod), "POD wrapper for physx::PxBVHStructureDesc has incorrect size.");
static_assert(sizeof(physx::PxCookingParams) == sizeof(physx_PxCookingParams_Pod), "POD wrapper for physx::PxCookingParams has incorrect size.");
static_assert(sizeof(physx::PxCooking) == sizeof(physx_PxCooking_Pod), "POD wrapper for physx::PxCooking has incorrect size.");
static_assert(sizeof(physx::PxDefaultMemoryOutputStream) == sizeof(physx_PxDefaultMemoryOutputStream_Pod), "POD wrapper for physx::PxDefaultMemoryOutputStream has incorrect size.");
static_assert(sizeof(physx::PxDefaultMemoryInputData) == sizeof(physx_PxDefaultMemoryInputData_Pod), "POD wrapper for physx::PxDefaultMemoryInputData has incorrect size.");
static_assert(sizeof(physx::PxDefaultFileOutputStream) == sizeof(physx_PxDefaultFileOutputStream_Pod), "POD wrapper for physx::PxDefaultFileOutputStream has incorrect size.");
static_assert(sizeof(physx::PxDefaultFileInputData) == sizeof(physx_PxDefaultFileInputData_Pod), "POD wrapper for physx::PxDefaultFileInputData has incorrect size.");
static_assert(sizeof(physx::PxSpring) == sizeof(physx_PxSpring_Pod), "POD wrapper for physx::PxSpring has incorrect size.");
static_assert(sizeof(physx::PxDistanceJoint) == sizeof(physx_PxDistanceJoint_Pod), "POD wrapper for physx::PxDistanceJoint has incorrect size.");
static_assert(sizeof(physx::PxDefaultAllocator) == sizeof(physx_PxDefaultAllocator_Pod), "POD wrapper for physx::PxDefaultAllocator has incorrect size.");
static_assert(sizeof(physx::PxContactJoint) == sizeof(physx_PxContactJoint_Pod), "POD wrapper for physx::PxContactJoint has incorrect size.");
static_assert(sizeof(physx::PxJacobianRow) == sizeof(physx_PxJacobianRow_Pod), "POD wrapper for physx::PxJacobianRow has incorrect size.");
static_assert(sizeof(physx::PxFixedJoint) == sizeof(physx_PxFixedJoint_Pod), "POD wrapper for physx::PxFixedJoint has incorrect size.");
static_assert(sizeof(physx::PxJointLimitParameters) == sizeof(physx_PxJointLimitParameters_Pod), "POD wrapper for physx::PxJointLimitParameters has incorrect size.");
static_assert(sizeof(physx::PxJointLinearLimit) == sizeof(physx_PxJointLinearLimit_Pod), "POD wrapper for physx::PxJointLinearLimit has incorrect size.");
static_assert(sizeof(physx::PxJointLinearLimitPair) == sizeof(physx_PxJointLinearLimitPair_Pod), "POD wrapper for physx::PxJointLinearLimitPair has incorrect size.");
static_assert(sizeof(physx::PxJointAngularLimitPair) == sizeof(physx_PxJointAngularLimitPair_Pod), "POD wrapper for physx::PxJointAngularLimitPair has incorrect size.");
static_assert(sizeof(physx::PxJointLimitCone) == sizeof(physx_PxJointLimitCone_Pod), "POD wrapper for physx::PxJointLimitCone has incorrect size.");
static_assert(sizeof(physx::PxJointLimitPyramid) == sizeof(physx_PxJointLimitPyramid_Pod), "POD wrapper for physx::PxJointLimitPyramid has incorrect size.");
static_assert(sizeof(physx::PxPrismaticJoint) == sizeof(physx_PxPrismaticJoint_Pod), "POD wrapper for physx::PxPrismaticJoint has incorrect size.");
static_assert(sizeof(physx::PxRevoluteJoint) == sizeof(physx_PxRevoluteJoint_Pod), "POD wrapper for physx::PxRevoluteJoint has incorrect size.");
static_assert(sizeof(physx::PxSphericalJoint) == sizeof(physx_PxSphericalJoint_Pod), "POD wrapper for physx::PxSphericalJoint has incorrect size.");
static_assert(sizeof(physx::PxD6Joint) == sizeof(physx_PxD6Joint_Pod), "POD wrapper for physx::PxD6Joint has incorrect size.");
static_assert(sizeof(physx::PxD6JointDrive) == sizeof(physx_PxD6JointDrive_Pod), "POD wrapper for physx::PxD6JointDrive has incorrect size.");
static_assert(sizeof(physx::PxGroupsMask) == sizeof(physx_PxGroupsMask_Pod), "POD wrapper for physx::PxGroupsMask has incorrect size.");
static_assert(sizeof(physx::PxDefaultErrorCallback) == sizeof(physx_PxDefaultErrorCallback_Pod), "POD wrapper for physx::PxDefaultErrorCallback has incorrect size.");
static_assert(sizeof(physx::PxMassProperties) == sizeof(physx_PxMassProperties_Pod), "POD wrapper for physx::PxMassProperties has incorrect size.");
static_assert(sizeof(physx::PxMeshOverlapUtil) == sizeof(physx_PxMeshOverlapUtil_Pod), "POD wrapper for physx::PxMeshOverlapUtil has incorrect size.");
static_assert(sizeof(physx::PxSerialization::PxXmlMiscParameter) == sizeof(physx_PxSerialization_PxXmlMiscParameter_Pod), "POD wrapper for physx::PxSerialization::PxXmlMiscParameter has incorrect size.");
static_assert(sizeof(physx::PxBinaryConverter) == sizeof(physx_PxBinaryConverter_Pod), "POD wrapper for physx::PxBinaryConverter has incorrect size.");
static_assert(sizeof(physx::PxDefaultCpuDispatcher) == sizeof(physx_PxDefaultCpuDispatcher_Pod), "POD wrapper for physx::PxDefaultCpuDispatcher has incorrect size.");
static_assert(sizeof(physx::PxSceneQueryHit) == sizeof(physx_PxSceneQueryHit_Pod), "POD wrapper for physx::PxSceneQueryHit has incorrect size.");
static_assert(sizeof(physx::PxSceneQueryFilterData) == sizeof(physx_PxSceneQueryFilterData_Pod), "POD wrapper for physx::PxSceneQueryFilterData has incorrect size.");
static_assert(sizeof(physx::PxSceneQueryFilterCallback) == sizeof(physx_PxSceneQueryFilterCallback_Pod), "POD wrapper for physx::PxSceneQueryFilterCallback has incorrect size.");
static_assert(sizeof(physx::PxSceneQueryCache) == sizeof(physx_PxSceneQueryCache_Pod), "POD wrapper for physx::PxSceneQueryCache has incorrect size.");
static_assert(sizeof(physx::PxRepXObject) == sizeof(physx_PxRepXObject_Pod), "POD wrapper for physx::PxRepXObject has incorrect size.");
static_assert(sizeof(physx::PxRepXInstantiationArgs) == sizeof(physx_PxRepXInstantiationArgs_Pod), "POD wrapper for physx::PxRepXInstantiationArgs has incorrect size.");
static_assert(sizeof(physx::PxVehicleChassisData) == sizeof(physx_PxVehicleChassisData_Pod), "POD wrapper for physx::PxVehicleChassisData has incorrect size.");
static_assert(sizeof(physx::PxVehicleEngineData) == sizeof(physx_PxVehicleEngineData_Pod), "POD wrapper for physx::PxVehicleEngineData has incorrect size.");
static_assert(sizeof(physx::PxVehicleGearsData) == sizeof(physx_PxVehicleGearsData_Pod), "POD wrapper for physx::PxVehicleGearsData has incorrect size.");
static_assert(sizeof(physx::PxVehicleAutoBoxData) == sizeof(physx_PxVehicleAutoBoxData_Pod), "POD wrapper for physx::PxVehicleAutoBoxData has incorrect size.");
static_assert(sizeof(physx::PxVehicleDifferential4WData) == sizeof(physx_PxVehicleDifferential4WData_Pod), "POD wrapper for physx::PxVehicleDifferential4WData has incorrect size.");
static_assert(sizeof(physx::PxVehicleDifferentialNWData) == sizeof(physx_PxVehicleDifferentialNWData_Pod), "POD wrapper for physx::PxVehicleDifferentialNWData has incorrect size.");
static_assert(sizeof(physx::PxVehicleAckermannGeometryData) == sizeof(physx_PxVehicleAckermannGeometryData_Pod), "POD wrapper for physx::PxVehicleAckermannGeometryData has incorrect size.");
static_assert(sizeof(physx::PxVehicleClutchData) == sizeof(physx_PxVehicleClutchData_Pod), "POD wrapper for physx::PxVehicleClutchData has incorrect size.");
static_assert(sizeof(physx::PxVehicleTireLoadFilterData) == sizeof(physx_PxVehicleTireLoadFilterData_Pod), "POD wrapper for physx::PxVehicleTireLoadFilterData has incorrect size.");
static_assert(sizeof(physx::PxVehicleWheelData) == sizeof(physx_PxVehicleWheelData_Pod), "POD wrapper for physx::PxVehicleWheelData has incorrect size.");
static_assert(sizeof(physx::PxVehicleSuspensionData) == sizeof(physx_PxVehicleSuspensionData_Pod), "POD wrapper for physx::PxVehicleSuspensionData has incorrect size.");
static_assert(sizeof(physx::PxVehicleAntiRollBarData) == sizeof(physx_PxVehicleAntiRollBarData_Pod), "POD wrapper for physx::PxVehicleAntiRollBarData has incorrect size.");
static_assert(sizeof(physx::PxVehicleTireData) == sizeof(physx_PxVehicleTireData_Pod), "POD wrapper for physx::PxVehicleTireData has incorrect size.");
static_assert(sizeof(physx::PxVehicleWheelsSimData) == sizeof(physx_PxVehicleWheelsSimData_Pod), "POD wrapper for physx::PxVehicleWheelsSimData has incorrect size.");
static_assert(sizeof(physx::PxVehicleWheelsDynData) == sizeof(physx_PxVehicleWheelsDynData_Pod), "POD wrapper for physx::PxVehicleWheelsDynData has incorrect size.");
static_assert(sizeof(physx::PxVehicleWheels) == sizeof(physx_PxVehicleWheels_Pod), "POD wrapper for physx::PxVehicleWheels has incorrect size.");
static_assert(sizeof(physx::PxVehicleDriveSimData) == sizeof(physx_PxVehicleDriveSimData_Pod), "POD wrapper for physx::PxVehicleDriveSimData has incorrect size.");
static_assert(sizeof(physx::PxVehicleDriveDynData) == sizeof(physx_PxVehicleDriveDynData_Pod), "POD wrapper for physx::PxVehicleDriveDynData has incorrect size.");
static_assert(sizeof(physx::PxVehicleDrive) == sizeof(physx_PxVehicleDrive_Pod), "POD wrapper for physx::PxVehicleDrive has incorrect size.");
static_assert(sizeof(physx::PxVehicleDriveSimData4W) == sizeof(physx_PxVehicleDriveSimData4W_Pod), "POD wrapper for physx::PxVehicleDriveSimData4W has incorrect size.");
static_assert(sizeof(physx::PxVehicleDrive4W) == sizeof(physx_PxVehicleDrive4W_Pod), "POD wrapper for physx::PxVehicleDrive4W has incorrect size.");
static_assert(sizeof(physx::PxVehicleDriveTank) == sizeof(physx_PxVehicleDriveTank_Pod), "POD wrapper for physx::PxVehicleDriveTank has incorrect size.");
static_assert(sizeof(physx::PxVehicleDrivableSurfaceType) == sizeof(physx_PxVehicleDrivableSurfaceType_Pod), "POD wrapper for physx::PxVehicleDrivableSurfaceType has incorrect size.");
static_assert(sizeof(physx::PxVehicleDrivableSurfaceToTireFrictionPairs) == sizeof(physx_PxVehicleDrivableSurfaceToTireFrictionPairs_Pod), "POD wrapper for physx::PxVehicleDrivableSurfaceToTireFrictionPairs has incorrect size.");
static_assert(sizeof(physx::PxWheelQueryResult) == sizeof(physx_PxWheelQueryResult_Pod), "POD wrapper for physx::PxWheelQueryResult has incorrect size.");
static_assert(sizeof(physx::PxVehicleWheelConcurrentUpdateData) == sizeof(physx_PxVehicleWheelConcurrentUpdateData_Pod), "POD wrapper for physx::PxVehicleWheelConcurrentUpdateData has incorrect size.");
static_assert(sizeof(physx::PxVehicleConcurrentUpdateData) == sizeof(physx_PxVehicleConcurrentUpdateData_Pod), "POD wrapper for physx::PxVehicleConcurrentUpdateData has incorrect size.");
static_assert(sizeof(physx::PxVehicleWheelQueryResult) == sizeof(physx_PxVehicleWheelQueryResult_Pod), "POD wrapper for physx::PxVehicleWheelQueryResult has incorrect size.");
static_assert(sizeof(physx::PxVehicleGraph) == sizeof(physx_PxVehicleGraph_Pod), "POD wrapper for physx::PxVehicleGraph has incorrect size.");
static_assert(sizeof(physx::PxVehicleTelemetryData) == sizeof(physx_PxVehicleTelemetryData_Pod), "POD wrapper for physx::PxVehicleTelemetryData has incorrect size.");
static_assert(sizeof(physx::PxVehicleDriveSimDataNW) == sizeof(physx_PxVehicleDriveSimDataNW_Pod), "POD wrapper for physx::PxVehicleDriveSimDataNW has incorrect size.");
static_assert(sizeof(physx::PxVehicleDriveNW) == sizeof(physx_PxVehicleDriveNW_Pod), "POD wrapper for physx::PxVehicleDriveNW has incorrect size.");
static_assert(sizeof(physx::PxVehicleDrive4WRawInputData) == sizeof(physx_PxVehicleDrive4WRawInputData_Pod), "POD wrapper for physx::PxVehicleDrive4WRawInputData has incorrect size.");
static_assert(sizeof(physx::PxVehicleKeySmoothingData) == sizeof(physx_PxVehicleKeySmoothingData_Pod), "POD wrapper for physx::PxVehicleKeySmoothingData has incorrect size.");
static_assert(sizeof(physx::PxVehiclePadSmoothingData) == sizeof(physx_PxVehiclePadSmoothingData_Pod), "POD wrapper for physx::PxVehiclePadSmoothingData has incorrect size.");
static_assert(sizeof(physx::PxVehicleDriveNWRawInputData) == sizeof(physx_PxVehicleDriveNWRawInputData_Pod), "POD wrapper for physx::PxVehicleDriveNWRawInputData has incorrect size.");
static_assert(sizeof(physx::PxVehicleDriveTankRawInputData) == sizeof(physx_PxVehicleDriveTankRawInputData_Pod), "POD wrapper for physx::PxVehicleDriveTankRawInputData has incorrect size.");
static_assert(sizeof(physx::PxVehicleCopyDynamicsMap) == sizeof(physx_PxVehicleCopyDynamicsMap_Pod), "POD wrapper for physx::PxVehicleCopyDynamicsMap has incorrect size.");
static_assert(sizeof(physx::PxVehicleGraphChannelDesc) == sizeof(physx_PxVehicleGraphChannelDesc_Pod), "POD wrapper for physx::PxVehicleGraphChannelDesc has incorrect size.");
static_assert(sizeof(physx::PxVehicleGraphDesc) == sizeof(physx_PxVehicleGraphDesc_Pod), "POD wrapper for physx::PxVehicleGraphDesc has incorrect size.");
static_assert(sizeof(physx::PxVehicleNoDrive) == sizeof(physx_PxVehicleNoDrive_Pod), "POD wrapper for physx::PxVehicleNoDrive has incorrect size.");
static_assert(sizeof(physx::PxProfileScoped) == sizeof(physx_PxProfileScoped_Pod), "POD wrapper for physx::PxProfileScoped has incorrect size.");
static_assert(sizeof(physx::PxPvdTransport) == sizeof(physx_PxPvdTransport_Pod), "POD wrapper for physx::PxPvdTransport has incorrect size.");
extern "C" {
void PxAllocatorCallback_delete(physx_PxAllocatorCallback_Pod* self__pod) {
physx::PxAllocatorCallback* self_ = reinterpret_cast<physx::PxAllocatorCallback*>(self__pod);
delete self_;
}

void* PxAllocatorCallback_allocate_mut(physx_PxAllocatorCallback_Pod* self__pod, uint64_t size, char const* typeName, char const* filename, int32_t line) {
physx::PxAllocatorCallback* self_ = reinterpret_cast<physx::PxAllocatorCallback*>(self__pod);
void* returnValue = self_->allocate(size, typeName, filename, line);
return returnValue;
}

void PxAllocatorCallback_deallocate_mut(physx_PxAllocatorCallback_Pod* self__pod, void* ptr) {
physx::PxAllocatorCallback* self_ = reinterpret_cast<physx::PxAllocatorCallback*>(self__pod);
self_->deallocate(ptr);
}

void PxAssertHandler_delete(physx_PxAssertHandler_Pod* self__pod) {
physx::PxAssertHandler* self_ = reinterpret_cast<physx::PxAssertHandler*>(self__pod);
delete self_;
}

physx_PxAssertHandler_Pod* phys_PxGetAssertHandler() {
physx::PxAssertHandler& returnValue = PxGetAssertHandler();
physx_PxAssertHandler_Pod* returnValue_pod = reinterpret_cast<physx_PxAssertHandler_Pod*>(&returnValue);
return returnValue_pod;
}

void phys_PxSetAssertHandler(physx_PxAssertHandler_Pod* handler_pod) {
physx::PxAssertHandler& handler = reinterpret_cast<physx::PxAssertHandler&>(*handler_pod);
PxSetAssertHandler(handler);
}

float phys_PxAbs(float a) {
float returnValue = PxAbs(a);
return returnValue;
}

bool phys_PxEquals(float a, float b, float eps) {
bool returnValue = PxEquals(a, b, eps);
return returnValue;
}

double phys_PxAbs_1(double a) {
double returnValue = PxAbs(a);
return returnValue;
}

int32_t phys_PxAbs_2(int32_t a) {
int32_t returnValue = PxAbs(a);
return returnValue;
}

float phys_PxSqrt(float a) {
float returnValue = PxSqrt(a);
return returnValue;
}

double phys_PxSqrt_1(double a) {
double returnValue = PxSqrt(a);
return returnValue;
}

float phys_PxRecipSqrt(float a) {
float returnValue = PxRecipSqrt(a);
return returnValue;
}

double phys_PxRecipSqrt_1(double a) {
double returnValue = PxRecipSqrt(a);
return returnValue;
}

float phys_PxSin(float a) {
float returnValue = PxSin(a);
return returnValue;
}

double phys_PxSin_1(double a) {
double returnValue = PxSin(a);
return returnValue;
}

float phys_PxCos(float a) {
float returnValue = PxCos(a);
return returnValue;
}

double phys_PxCos_1(double a) {
double returnValue = PxCos(a);
return returnValue;
}

float phys_PxTan(float a) {
float returnValue = PxTan(a);
return returnValue;
}

double phys_PxTan_1(double a) {
double returnValue = PxTan(a);
return returnValue;
}

float phys_PxAsin(float f) {
float returnValue = PxAsin(f);
return returnValue;
}

double phys_PxAsin_1(double f) {
double returnValue = PxAsin(f);
return returnValue;
}

float phys_PxAcos(float f) {
float returnValue = PxAcos(f);
return returnValue;
}

double phys_PxAcos_1(double f) {
double returnValue = PxAcos(f);
return returnValue;
}

float phys_PxAtan(float a) {
float returnValue = PxAtan(a);
return returnValue;
}

double phys_PxAtan_1(double a) {
double returnValue = PxAtan(a);
return returnValue;
}

float phys_PxAtan2(float x, float y) {
float returnValue = PxAtan2(x, y);
return returnValue;
}

double phys_PxAtan2_1(double x, double y) {
double returnValue = PxAtan2(x, y);
return returnValue;
}

bool phys_PxIsFinite(float f) {
bool returnValue = PxIsFinite(f);
return returnValue;
}

bool phys_PxIsFinite_1(double f) {
bool returnValue = PxIsFinite(f);
return returnValue;
}

float phys_PxFloor(float a) {
float returnValue = PxFloor(a);
return returnValue;
}

float phys_PxExp(float a) {
float returnValue = PxExp(a);
return returnValue;
}

float phys_PxCeil(float a) {
float returnValue = PxCeil(a);
return returnValue;
}

float phys_PxSign(float a) {
float returnValue = PxSign(a);
return returnValue;
}

float phys_PxPow(float x, float y) {
float returnValue = PxPow(x, y);
return returnValue;
}

float phys_PxLog(float x) {
float returnValue = PxLog(x);
return returnValue;
}

physx_PxVec3_Pod PxVec3_new() {
physx::PxVec3 returnValue;
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxVec3_new_1(unsigned int r_pod) {
physx::PxZERO r = (physx::PxZERO)r_pod;
physx::PxVec3 returnValue(r);
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxVec3_new_2(float a) {
physx::PxVec3 returnValue(a);
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxVec3_new_3(float nx, float ny, float nz) {
physx::PxVec3 returnValue(nx, ny, nz);
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxVec3_isZero(physx_PxVec3_Pod const* self__pod) {
physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
bool returnValue = self_->isZero();
return returnValue;
}

bool PxVec3_isFinite(physx_PxVec3_Pod const* self__pod) {
physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
bool returnValue = self_->isFinite();
return returnValue;
}

bool PxVec3_isNormalized(physx_PxVec3_Pod const* self__pod) {
physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
bool returnValue = self_->isNormalized();
return returnValue;
}

float PxVec3_magnitudeSquared(physx_PxVec3_Pod const* self__pod) {
physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
float returnValue = self_->magnitudeSquared();
return returnValue;
}

float PxVec3_magnitude(physx_PxVec3_Pod const* self__pod) {
physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
float returnValue = self_->magnitude();
return returnValue;
}

float PxVec3_dot(physx_PxVec3_Pod const* self__pod, physx_PxVec3_Pod const* v_pod) {
physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
physx::PxVec3 const& v = reinterpret_cast<physx::PxVec3 const&>(*v_pod);
float returnValue = self_->dot(v);
return returnValue;
}

physx_PxVec3_Pod PxVec3_cross(physx_PxVec3_Pod const* self__pod, physx_PxVec3_Pod const* v_pod) {
physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
physx::PxVec3 const& v = reinterpret_cast<physx::PxVec3 const&>(*v_pod);
physx::PxVec3 returnValue = self_->cross(v);
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxVec3_getNormalized(physx_PxVec3_Pod const* self__pod) {
physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
physx::PxVec3 returnValue = self_->getNormalized();
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

float PxVec3_normalize_mut(physx_PxVec3_Pod* self__pod) {
physx::PxVec3* self_ = reinterpret_cast<physx::PxVec3*>(self__pod);
float returnValue = self_->normalize();
return returnValue;
}

float PxVec3_normalizeSafe_mut(physx_PxVec3_Pod* self__pod) {
physx::PxVec3* self_ = reinterpret_cast<physx::PxVec3*>(self__pod);
float returnValue = self_->normalizeSafe();
return returnValue;
}

float PxVec3_normalizeFast_mut(physx_PxVec3_Pod* self__pod) {
physx::PxVec3* self_ = reinterpret_cast<physx::PxVec3*>(self__pod);
float returnValue = self_->normalizeFast();
return returnValue;
}

physx_PxVec3_Pod PxVec3_multiply(physx_PxVec3_Pod const* self__pod, physx_PxVec3_Pod const* a_pod) {
physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
physx::PxVec3 const& a = reinterpret_cast<physx::PxVec3 const&>(*a_pod);
physx::PxVec3 returnValue = self_->multiply(a);
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxVec3_minimum(physx_PxVec3_Pod const* self__pod, physx_PxVec3_Pod const* v_pod) {
physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
physx::PxVec3 const& v = reinterpret_cast<physx::PxVec3 const&>(*v_pod);
physx::PxVec3 returnValue = self_->minimum(v);
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

float PxVec3_minElement(physx_PxVec3_Pod const* self__pod) {
physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
float returnValue = self_->minElement();
return returnValue;
}

physx_PxVec3_Pod PxVec3_maximum(physx_PxVec3_Pod const* self__pod, physx_PxVec3_Pod const* v_pod) {
physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
physx::PxVec3 const& v = reinterpret_cast<physx::PxVec3 const&>(*v_pod);
physx::PxVec3 returnValue = self_->maximum(v);
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

float PxVec3_maxElement(physx_PxVec3_Pod const* self__pod) {
physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
float returnValue = self_->maxElement();
return returnValue;
}

physx_PxVec3_Pod PxVec3_abs(physx_PxVec3_Pod const* self__pod) {
physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
physx::PxVec3 returnValue = self_->abs();
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxQuat_Pod PxQuat_new() {
physx::PxQuat returnValue;
physx_PxQuat_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxQuat_Pod PxQuat_new_1(unsigned int r_pod) {
physx::PxIDENTITY r = (physx::PxIDENTITY)r_pod;
physx::PxQuat returnValue(r);
physx_PxQuat_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxQuat_Pod PxQuat_new_2(float r) {
physx::PxQuat returnValue(r);
physx_PxQuat_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxQuat_Pod PxQuat_new_3(float nx, float ny, float nz, float nw) {
physx::PxQuat returnValue(nx, ny, nz, nw);
physx_PxQuat_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxQuat_Pod PxQuat_new_4(float angleRadians, physx_PxVec3_Pod const* unitAxis_pod) {
physx::PxVec3 const& unitAxis = reinterpret_cast<physx::PxVec3 const&>(*unitAxis_pod);
physx::PxQuat returnValue(angleRadians, unitAxis);
physx_PxQuat_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxQuat_Pod PxQuat_new_5(physx_PxMat33_Pod const* m_pod) {
physx::PxMat33 const& m = reinterpret_cast<physx::PxMat33 const&>(*m_pod);
physx::PxQuat returnValue(m);
physx_PxQuat_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxQuat_isIdentity(physx_PxQuat_Pod const* self__pod) {
physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
bool returnValue = self_->isIdentity();
return returnValue;
}

bool PxQuat_isFinite(physx_PxQuat_Pod const* self__pod) {
physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
bool returnValue = self_->isFinite();
return returnValue;
}

bool PxQuat_isUnit(physx_PxQuat_Pod const* self__pod) {
physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
bool returnValue = self_->isUnit();
return returnValue;
}

bool PxQuat_isSane(physx_PxQuat_Pod const* self__pod) {
physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
bool returnValue = self_->isSane();
return returnValue;
}

void PxQuat_toRadiansAndUnitAxis(physx_PxQuat_Pod const* self__pod, float* angle_pod, physx_PxVec3_Pod* axis_pod) {
physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
float& angle = *angle_pod;
physx::PxVec3& axis = reinterpret_cast<physx::PxVec3&>(*axis_pod);
self_->toRadiansAndUnitAxis(angle, axis);
}

float PxQuat_getAngle(physx_PxQuat_Pod const* self__pod) {
physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
float returnValue = self_->getAngle();
return returnValue;
}

float PxQuat_getAngle_1(physx_PxQuat_Pod const* self__pod, physx_PxQuat_Pod const* q_pod) {
physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
physx::PxQuat const& q = reinterpret_cast<physx::PxQuat const&>(*q_pod);
float returnValue = self_->getAngle(q);
return returnValue;
}

float PxQuat_magnitudeSquared(physx_PxQuat_Pod const* self__pod) {
physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
float returnValue = self_->magnitudeSquared();
return returnValue;
}

float PxQuat_dot(physx_PxQuat_Pod const* self__pod, physx_PxQuat_Pod const* v_pod) {
physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
physx::PxQuat const& v = reinterpret_cast<physx::PxQuat const&>(*v_pod);
float returnValue = self_->dot(v);
return returnValue;
}

physx_PxQuat_Pod PxQuat_getNormalized(physx_PxQuat_Pod const* self__pod) {
physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
physx::PxQuat returnValue = self_->getNormalized();
physx_PxQuat_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

float PxQuat_magnitude(physx_PxQuat_Pod const* self__pod) {
physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
float returnValue = self_->magnitude();
return returnValue;
}

float PxQuat_normalize_mut(physx_PxQuat_Pod* self__pod) {
physx::PxQuat* self_ = reinterpret_cast<physx::PxQuat*>(self__pod);
float returnValue = self_->normalize();
return returnValue;
}

physx_PxQuat_Pod PxQuat_getConjugate(physx_PxQuat_Pod const* self__pod) {
physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
physx::PxQuat returnValue = self_->getConjugate();
physx_PxQuat_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxQuat_getImaginaryPart(physx_PxQuat_Pod const* self__pod) {
physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
physx::PxVec3 returnValue = self_->getImaginaryPart();
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxQuat_getBasisVector0(physx_PxQuat_Pod const* self__pod) {
physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
physx::PxVec3 returnValue = self_->getBasisVector0();
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxQuat_getBasisVector1(physx_PxQuat_Pod const* self__pod) {
physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
physx::PxVec3 returnValue = self_->getBasisVector1();
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxQuat_getBasisVector2(physx_PxQuat_Pod const* self__pod) {
physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
physx::PxVec3 returnValue = self_->getBasisVector2();
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxQuat_rotate(physx_PxQuat_Pod const* self__pod, physx_PxVec3_Pod const* v_pod) {
physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
physx::PxVec3 const& v = reinterpret_cast<physx::PxVec3 const&>(*v_pod);
physx::PxVec3 returnValue = self_->rotate(v);
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxQuat_rotateInv(physx_PxQuat_Pod const* self__pod, physx_PxVec3_Pod const* v_pod) {
physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
physx::PxVec3 const& v = reinterpret_cast<physx::PxVec3 const&>(*v_pod);
physx::PxVec3 returnValue = self_->rotateInv(v);
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxPlane_Pod PxPlane_new() {
physx::PxPlane returnValue;
physx_PxPlane_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxPlane_Pod PxPlane_new_1(float nx, float ny, float nz, float distance) {
physx::PxPlane returnValue(nx, ny, nz, distance);
physx_PxPlane_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxPlane_Pod PxPlane_new_2(physx_PxVec3_Pod const* normal_pod, float distance) {
physx::PxVec3 const& normal = reinterpret_cast<physx::PxVec3 const&>(*normal_pod);
physx::PxPlane returnValue(normal, distance);
physx_PxPlane_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxPlane_Pod PxPlane_new_3(physx_PxVec3_Pod const* point_pod, physx_PxVec3_Pod const* normal_pod) {
physx::PxVec3 const& point = reinterpret_cast<physx::PxVec3 const&>(*point_pod);
physx::PxVec3 const& normal = reinterpret_cast<physx::PxVec3 const&>(*normal_pod);
physx::PxPlane returnValue(point, normal);
physx_PxPlane_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxPlane_Pod PxPlane_new_4(physx_PxVec3_Pod const* p0_pod, physx_PxVec3_Pod const* p1_pod, physx_PxVec3_Pod const* p2_pod) {
physx::PxVec3 const& p0 = reinterpret_cast<physx::PxVec3 const&>(*p0_pod);
physx::PxVec3 const& p1 = reinterpret_cast<physx::PxVec3 const&>(*p1_pod);
physx::PxVec3 const& p2 = reinterpret_cast<physx::PxVec3 const&>(*p2_pod);
physx::PxPlane returnValue(p0, p1, p2);
physx_PxPlane_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

float PxPlane_distance(physx_PxPlane_Pod const* self__pod, physx_PxVec3_Pod const* p_pod) {
physx::PxPlane const* self_ = reinterpret_cast<physx::PxPlane const*>(self__pod);
physx::PxVec3 const& p = reinterpret_cast<physx::PxVec3 const&>(*p_pod);
float returnValue = self_->distance(p);
return returnValue;
}

bool PxPlane_contains(physx_PxPlane_Pod const* self__pod, physx_PxVec3_Pod const* p_pod) {
physx::PxPlane const* self_ = reinterpret_cast<physx::PxPlane const*>(self__pod);
physx::PxVec3 const& p = reinterpret_cast<physx::PxVec3 const&>(*p_pod);
bool returnValue = self_->contains(p);
return returnValue;
}

physx_PxVec3_Pod PxPlane_project(physx_PxPlane_Pod const* self__pod, physx_PxVec3_Pod const* p_pod) {
physx::PxPlane const* self_ = reinterpret_cast<physx::PxPlane const*>(self__pod);
physx::PxVec3 const& p = reinterpret_cast<physx::PxVec3 const&>(*p_pod);
physx::PxVec3 returnValue = self_->project(p);
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxPlane_pointInPlane(physx_PxPlane_Pod const* self__pod) {
physx::PxPlane const* self_ = reinterpret_cast<physx::PxPlane const*>(self__pod);
physx::PxVec3 returnValue = self_->pointInPlane();
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxPlane_normalize_mut(physx_PxPlane_Pod* self__pod) {
physx::PxPlane* self_ = reinterpret_cast<physx::PxPlane*>(self__pod);
self_->normalize();
}

physx_PxTransform_Pod PxTransform_new() {
physx::PxTransform returnValue;
physx_PxTransform_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxTransform_Pod PxTransform_new_1(physx_PxVec3_Pod const* position_pod) {
physx::PxVec3 const& position = reinterpret_cast<physx::PxVec3 const&>(*position_pod);
physx::PxTransform returnValue(position);
physx_PxTransform_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxTransform_Pod PxTransform_new_2(unsigned int r_pod) {
physx::PxIDENTITY r = (physx::PxIDENTITY)r_pod;
physx::PxTransform returnValue(r);
physx_PxTransform_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxTransform_Pod PxTransform_new_3(physx_PxQuat_Pod const* orientation_pod) {
physx::PxQuat const& orientation = reinterpret_cast<physx::PxQuat const&>(*orientation_pod);
physx::PxTransform returnValue(orientation);
physx_PxTransform_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxTransform_Pod PxTransform_new_4(float x, float y, float z, physx_PxQuat_Pod aQ_pod) {
physx::PxQuat aQ;
memcpy(&aQ, &aQ_pod, sizeof(aQ));
physx::PxTransform returnValue(x, y, z, aQ);
physx_PxTransform_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxTransform_Pod PxTransform_new_5(physx_PxVec3_Pod const* p0_pod, physx_PxQuat_Pod const* q0_pod) {
physx::PxVec3 const& p0 = reinterpret_cast<physx::PxVec3 const&>(*p0_pod);
physx::PxQuat const& q0 = reinterpret_cast<physx::PxQuat const&>(*q0_pod);
physx::PxTransform returnValue(p0, q0);
physx_PxTransform_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxTransform_Pod PxTransform_new_6(physx_PxMat44_Pod const* m_pod) {
physx::PxMat44 const& m = reinterpret_cast<physx::PxMat44 const&>(*m_pod);
physx::PxTransform returnValue(m);
physx_PxTransform_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxTransform_Pod PxTransform_getInverse(physx_PxTransform_Pod const* self__pod) {
physx::PxTransform const* self_ = reinterpret_cast<physx::PxTransform const*>(self__pod);
physx::PxTransform returnValue = self_->getInverse();
physx_PxTransform_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxTransform_transform(physx_PxTransform_Pod const* self__pod, physx_PxVec3_Pod const* input_pod) {
physx::PxTransform const* self_ = reinterpret_cast<physx::PxTransform const*>(self__pod);
physx::PxVec3 const& input = reinterpret_cast<physx::PxVec3 const&>(*input_pod);
physx::PxVec3 returnValue = self_->transform(input);
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxTransform_transformInv(physx_PxTransform_Pod const* self__pod, physx_PxVec3_Pod const* input_pod) {
physx::PxTransform const* self_ = reinterpret_cast<physx::PxTransform const*>(self__pod);
physx::PxVec3 const& input = reinterpret_cast<physx::PxVec3 const&>(*input_pod);
physx::PxVec3 returnValue = self_->transformInv(input);
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxTransform_rotate(physx_PxTransform_Pod const* self__pod, physx_PxVec3_Pod const* input_pod) {
physx::PxTransform const* self_ = reinterpret_cast<physx::PxTransform const*>(self__pod);
physx::PxVec3 const& input = reinterpret_cast<physx::PxVec3 const&>(*input_pod);
physx::PxVec3 returnValue = self_->rotate(input);
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxTransform_rotateInv(physx_PxTransform_Pod const* self__pod, physx_PxVec3_Pod const* input_pod) {
physx::PxTransform const* self_ = reinterpret_cast<physx::PxTransform const*>(self__pod);
physx::PxVec3 const& input = reinterpret_cast<physx::PxVec3 const&>(*input_pod);
physx::PxVec3 returnValue = self_->rotateInv(input);
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxTransform_Pod PxTransform_transform_1(physx_PxTransform_Pod const* self__pod, physx_PxTransform_Pod const* src_pod) {
physx::PxTransform const* self_ = reinterpret_cast<physx::PxTransform const*>(self__pod);
physx::PxTransform const& src = reinterpret_cast<physx::PxTransform const&>(*src_pod);
physx::PxTransform returnValue = self_->transform(src);
physx_PxTransform_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxTransform_isValid(physx_PxTransform_Pod const* self__pod) {
physx::PxTransform const* self_ = reinterpret_cast<physx::PxTransform const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

bool PxTransform_isSane(physx_PxTransform_Pod const* self__pod) {
physx::PxTransform const* self_ = reinterpret_cast<physx::PxTransform const*>(self__pod);
bool returnValue = self_->isSane();
return returnValue;
}

bool PxTransform_isFinite(physx_PxTransform_Pod const* self__pod) {
physx::PxTransform const* self_ = reinterpret_cast<physx::PxTransform const*>(self__pod);
bool returnValue = self_->isFinite();
return returnValue;
}

physx_PxTransform_Pod PxTransform_transformInv_1(physx_PxTransform_Pod const* self__pod, physx_PxTransform_Pod const* src_pod) {
physx::PxTransform const* self_ = reinterpret_cast<physx::PxTransform const*>(self__pod);
physx::PxTransform const& src = reinterpret_cast<physx::PxTransform const&>(*src_pod);
physx::PxTransform returnValue = self_->transformInv(src);
physx_PxTransform_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxPlane_Pod PxTransform_transform_2(physx_PxTransform_Pod const* self__pod, physx_PxPlane_Pod const* plane_pod) {
physx::PxTransform const* self_ = reinterpret_cast<physx::PxTransform const*>(self__pod);
physx::PxPlane const& plane = reinterpret_cast<physx::PxPlane const&>(*plane_pod);
physx::PxPlane returnValue = self_->transform(plane);
physx_PxPlane_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxPlane_Pod PxTransform_inverseTransform(physx_PxTransform_Pod const* self__pod, physx_PxPlane_Pod const* plane_pod) {
physx::PxTransform const* self_ = reinterpret_cast<physx::PxTransform const*>(self__pod);
physx::PxPlane const& plane = reinterpret_cast<physx::PxPlane const&>(*plane_pod);
physx::PxPlane returnValue = self_->inverseTransform(plane);
physx_PxPlane_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxTransform_Pod PxTransform_getNormalized(physx_PxTransform_Pod const* self__pod) {
physx::PxTransform const* self_ = reinterpret_cast<physx::PxTransform const*>(self__pod);
physx::PxTransform returnValue = self_->getNormalized();
physx_PxTransform_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMat33_Pod PxMat33_new() {
physx::PxMat33 returnValue;
physx_PxMat33_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMat33_Pod PxMat33_new_1(unsigned int r_pod) {
physx::PxIDENTITY r = (physx::PxIDENTITY)r_pod;
physx::PxMat33 returnValue(r);
physx_PxMat33_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMat33_Pod PxMat33_new_2(unsigned int r_pod) {
physx::PxZERO r = (physx::PxZERO)r_pod;
physx::PxMat33 returnValue(r);
physx_PxMat33_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMat33_Pod PxMat33_new_3(physx_PxVec3_Pod const* col0_pod, physx_PxVec3_Pod const* col1_pod, physx_PxVec3_Pod const* col2_pod) {
physx::PxVec3 const& col0 = reinterpret_cast<physx::PxVec3 const&>(*col0_pod);
physx::PxVec3 const& col1 = reinterpret_cast<physx::PxVec3 const&>(*col1_pod);
physx::PxVec3 const& col2 = reinterpret_cast<physx::PxVec3 const&>(*col2_pod);
physx::PxMat33 returnValue(col0, col1, col2);
physx_PxMat33_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMat33_Pod PxMat33_new_4(float r) {
physx::PxMat33 returnValue(r);
physx_PxMat33_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMat33_Pod PxMat33_new_5(float* values) {
physx::PxMat33 returnValue(values);
physx_PxMat33_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMat33_Pod PxMat33_new_6(physx_PxQuat_Pod const* q_pod) {
physx::PxQuat const& q = reinterpret_cast<physx::PxQuat const&>(*q_pod);
physx::PxMat33 returnValue(q);
physx_PxMat33_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMat33_Pod PxMat33_createDiagonal_mut(physx_PxVec3_Pod const* d_pod) {
physx::PxVec3 const& d = reinterpret_cast<physx::PxVec3 const&>(*d_pod);
physx::PxMat33 returnValue = PxMat33::createDiagonal(d);
physx_PxMat33_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMat33_Pod PxMat33_getTranspose(physx_PxMat33_Pod const* self__pod) {
physx::PxMat33 const* self_ = reinterpret_cast<physx::PxMat33 const*>(self__pod);
physx::PxMat33 returnValue = self_->getTranspose();
physx_PxMat33_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMat33_Pod PxMat33_getInverse(physx_PxMat33_Pod const* self__pod) {
physx::PxMat33 const* self_ = reinterpret_cast<physx::PxMat33 const*>(self__pod);
physx::PxMat33 returnValue = self_->getInverse();
physx_PxMat33_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

float PxMat33_getDeterminant(physx_PxMat33_Pod const* self__pod) {
physx::PxMat33 const* self_ = reinterpret_cast<physx::PxMat33 const*>(self__pod);
float returnValue = self_->getDeterminant();
return returnValue;
}

physx_PxVec3_Pod PxMat33_transform(physx_PxMat33_Pod const* self__pod, physx_PxVec3_Pod const* other_pod) {
physx::PxMat33 const* self_ = reinterpret_cast<physx::PxMat33 const*>(self__pod);
physx::PxVec3 const& other = reinterpret_cast<physx::PxVec3 const&>(*other_pod);
physx::PxVec3 returnValue = self_->transform(other);
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxMat33_transformTranspose(physx_PxMat33_Pod const* self__pod, physx_PxVec3_Pod const* other_pod) {
physx::PxMat33 const* self_ = reinterpret_cast<physx::PxMat33 const*>(self__pod);
physx::PxVec3 const& other = reinterpret_cast<physx::PxVec3 const&>(*other_pod);
physx::PxVec3 returnValue = self_->transformTranspose(other);
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

float const* PxMat33_front(physx_PxMat33_Pod const* self__pod) {
physx::PxMat33 const* self_ = reinterpret_cast<physx::PxMat33 const*>(self__pod);
float const* returnValue = self_->front();
return returnValue;
}

physx_PxQuat_Pod PxQuat_new_6(physx_PxMat33_Pod const* m_pod) {
physx::PxMat33 const& m = reinterpret_cast<physx::PxMat33 const&>(*m_pod);
physx::PxQuat returnValue(m);
physx_PxQuat_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxBounds3_Pod PxBounds3_new() {
physx::PxBounds3 returnValue;
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxBounds3_Pod PxBounds3_new_1(physx_PxVec3_Pod const* minimum_pod, physx_PxVec3_Pod const* maximum_pod) {
physx::PxVec3 const& minimum = reinterpret_cast<physx::PxVec3 const&>(*minimum_pod);
physx::PxVec3 const& maximum = reinterpret_cast<physx::PxVec3 const&>(*maximum_pod);
physx::PxBounds3 returnValue(minimum, maximum);
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxBounds3_Pod PxBounds3_empty_mut() {
physx::PxBounds3 returnValue = PxBounds3::empty();
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxBounds3_Pod PxBounds3_boundsOfPoints_mut(physx_PxVec3_Pod const* v0_pod, physx_PxVec3_Pod const* v1_pod) {
physx::PxVec3 const& v0 = reinterpret_cast<physx::PxVec3 const&>(*v0_pod);
physx::PxVec3 const& v1 = reinterpret_cast<physx::PxVec3 const&>(*v1_pod);
physx::PxBounds3 returnValue = PxBounds3::boundsOfPoints(v0, v1);
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxBounds3_Pod PxBounds3_centerExtents_mut(physx_PxVec3_Pod const* center_pod, physx_PxVec3_Pod const* extent_pod) {
physx::PxVec3 const& center = reinterpret_cast<physx::PxVec3 const&>(*center_pod);
physx::PxVec3 const& extent = reinterpret_cast<physx::PxVec3 const&>(*extent_pod);
physx::PxBounds3 returnValue = PxBounds3::centerExtents(center, extent);
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxBounds3_Pod PxBounds3_basisExtent_mut(physx_PxVec3_Pod const* center_pod, physx_PxMat33_Pod const* basis_pod, physx_PxVec3_Pod const* extent_pod) {
physx::PxVec3 const& center = reinterpret_cast<physx::PxVec3 const&>(*center_pod);
physx::PxMat33 const& basis = reinterpret_cast<physx::PxMat33 const&>(*basis_pod);
physx::PxVec3 const& extent = reinterpret_cast<physx::PxVec3 const&>(*extent_pod);
physx::PxBounds3 returnValue = PxBounds3::basisExtent(center, basis, extent);
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxBounds3_Pod PxBounds3_poseExtent_mut(physx_PxTransform_Pod const* pose_pod, physx_PxVec3_Pod const* extent_pod) {
physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
physx::PxVec3 const& extent = reinterpret_cast<physx::PxVec3 const&>(*extent_pod);
physx::PxBounds3 returnValue = PxBounds3::poseExtent(pose, extent);
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxBounds3_Pod PxBounds3_transformSafe_mut(physx_PxMat33_Pod const* matrix_pod, physx_PxBounds3_Pod const* bounds_pod) {
physx::PxMat33 const& matrix = reinterpret_cast<physx::PxMat33 const&>(*matrix_pod);
physx::PxBounds3 const& bounds = reinterpret_cast<physx::PxBounds3 const&>(*bounds_pod);
physx::PxBounds3 returnValue = PxBounds3::transformSafe(matrix, bounds);
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxBounds3_Pod PxBounds3_transformFast_mut(physx_PxMat33_Pod const* matrix_pod, physx_PxBounds3_Pod const* bounds_pod) {
physx::PxMat33 const& matrix = reinterpret_cast<physx::PxMat33 const&>(*matrix_pod);
physx::PxBounds3 const& bounds = reinterpret_cast<physx::PxBounds3 const&>(*bounds_pod);
physx::PxBounds3 returnValue = PxBounds3::transformFast(matrix, bounds);
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxBounds3_Pod PxBounds3_transformSafe_mut_1(physx_PxTransform_Pod const* transform_pod, physx_PxBounds3_Pod const* bounds_pod) {
physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
physx::PxBounds3 const& bounds = reinterpret_cast<physx::PxBounds3 const&>(*bounds_pod);
physx::PxBounds3 returnValue = PxBounds3::transformSafe(transform, bounds);
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxBounds3_Pod PxBounds3_transformFast_mut_1(physx_PxTransform_Pod const* transform_pod, physx_PxBounds3_Pod const* bounds_pod) {
physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
physx::PxBounds3 const& bounds = reinterpret_cast<physx::PxBounds3 const&>(*bounds_pod);
physx::PxBounds3 returnValue = PxBounds3::transformFast(transform, bounds);
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxBounds3_setEmpty_mut(physx_PxBounds3_Pod* self__pod) {
physx::PxBounds3* self_ = reinterpret_cast<physx::PxBounds3*>(self__pod);
self_->setEmpty();
}

void PxBounds3_setMaximal_mut(physx_PxBounds3_Pod* self__pod) {
physx::PxBounds3* self_ = reinterpret_cast<physx::PxBounds3*>(self__pod);
self_->setMaximal();
}

void PxBounds3_include_mut(physx_PxBounds3_Pod* self__pod, physx_PxVec3_Pod const* v_pod) {
physx::PxBounds3* self_ = reinterpret_cast<physx::PxBounds3*>(self__pod);
physx::PxVec3 const& v = reinterpret_cast<physx::PxVec3 const&>(*v_pod);
self_->include(v);
}

void PxBounds3_include_mut_1(physx_PxBounds3_Pod* self__pod, physx_PxBounds3_Pod const* b_pod) {
physx::PxBounds3* self_ = reinterpret_cast<physx::PxBounds3*>(self__pod);
physx::PxBounds3 const& b = reinterpret_cast<physx::PxBounds3 const&>(*b_pod);
self_->include(b);
}

bool PxBounds3_isEmpty(physx_PxBounds3_Pod const* self__pod) {
physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
bool returnValue = self_->isEmpty();
return returnValue;
}

bool PxBounds3_intersects(physx_PxBounds3_Pod const* self__pod, physx_PxBounds3_Pod const* b_pod) {
physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
physx::PxBounds3 const& b = reinterpret_cast<physx::PxBounds3 const&>(*b_pod);
bool returnValue = self_->intersects(b);
return returnValue;
}

bool PxBounds3_intersects1D(physx_PxBounds3_Pod const* self__pod, physx_PxBounds3_Pod const* a_pod, uint32_t axis) {
physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
physx::PxBounds3 const& a = reinterpret_cast<physx::PxBounds3 const&>(*a_pod);
bool returnValue = self_->intersects1D(a, axis);
return returnValue;
}

bool PxBounds3_contains(physx_PxBounds3_Pod const* self__pod, physx_PxVec3_Pod const* v_pod) {
physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
physx::PxVec3 const& v = reinterpret_cast<physx::PxVec3 const&>(*v_pod);
bool returnValue = self_->contains(v);
return returnValue;
}

bool PxBounds3_isInside(physx_PxBounds3_Pod const* self__pod, physx_PxBounds3_Pod const* box_pod) {
physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
physx::PxBounds3 const& box = reinterpret_cast<physx::PxBounds3 const&>(*box_pod);
bool returnValue = self_->isInside(box);
return returnValue;
}

physx_PxVec3_Pod PxBounds3_getCenter(physx_PxBounds3_Pod const* self__pod) {
physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
physx::PxVec3 returnValue = self_->getCenter();
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

float PxBounds3_getCenter_1(physx_PxBounds3_Pod const* self__pod, uint32_t axis) {
physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
float returnValue = self_->getCenter(axis);
return returnValue;
}

float PxBounds3_getExtents(physx_PxBounds3_Pod const* self__pod, uint32_t axis) {
physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
float returnValue = self_->getExtents(axis);
return returnValue;
}

physx_PxVec3_Pod PxBounds3_getDimensions(physx_PxBounds3_Pod const* self__pod) {
physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
physx::PxVec3 returnValue = self_->getDimensions();
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxBounds3_getExtents_1(physx_PxBounds3_Pod const* self__pod) {
physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
physx::PxVec3 returnValue = self_->getExtents();
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxBounds3_scaleSafe_mut(physx_PxBounds3_Pod* self__pod, float scale) {
physx::PxBounds3* self_ = reinterpret_cast<physx::PxBounds3*>(self__pod);
self_->scaleSafe(scale);
}

void PxBounds3_scaleFast_mut(physx_PxBounds3_Pod* self__pod, float scale) {
physx::PxBounds3* self_ = reinterpret_cast<physx::PxBounds3*>(self__pod);
self_->scaleFast(scale);
}

void PxBounds3_fattenSafe_mut(physx_PxBounds3_Pod* self__pod, float distance) {
physx::PxBounds3* self_ = reinterpret_cast<physx::PxBounds3*>(self__pod);
self_->fattenSafe(distance);
}

void PxBounds3_fattenFast_mut(physx_PxBounds3_Pod* self__pod, float distance) {
physx::PxBounds3* self_ = reinterpret_cast<physx::PxBounds3*>(self__pod);
self_->fattenFast(distance);
}

bool PxBounds3_isFinite(physx_PxBounds3_Pod const* self__pod) {
physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
bool returnValue = self_->isFinite();
return returnValue;
}

bool PxBounds3_isValid(physx_PxBounds3_Pod const* self__pod) {
physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

physx_PxBounds3_Pod PxBounds3_new_2(physx_PxVec3_Pod const* minimum__pod, physx_PxVec3_Pod const* maximum__pod) {
physx::PxVec3 const& minimum_ = reinterpret_cast<physx::PxVec3 const&>(*minimum__pod);
physx::PxVec3 const& maximum_ = reinterpret_cast<physx::PxVec3 const&>(*maximum__pod);
physx::PxBounds3 returnValue(minimum_, maximum_);
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxBounds3_Pod PxBounds3_empty_mut_1() {
physx::PxBounds3 returnValue = PxBounds3::empty();
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxBounds3_isFinite_1(physx_PxBounds3_Pod const* self__pod) {
physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
bool returnValue = self_->isFinite();
return returnValue;
}

physx_PxBounds3_Pod PxBounds3_boundsOfPoints_mut_1(physx_PxVec3_Pod const* v0_pod, physx_PxVec3_Pod const* v1_pod) {
physx::PxVec3 const& v0 = reinterpret_cast<physx::PxVec3 const&>(*v0_pod);
physx::PxVec3 const& v1 = reinterpret_cast<physx::PxVec3 const&>(*v1_pod);
physx::PxBounds3 returnValue = PxBounds3::boundsOfPoints(v0, v1);
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxBounds3_Pod PxBounds3_centerExtents_mut_1(physx_PxVec3_Pod const* center_pod, physx_PxVec3_Pod const* extent_pod) {
physx::PxVec3 const& center = reinterpret_cast<physx::PxVec3 const&>(*center_pod);
physx::PxVec3 const& extent = reinterpret_cast<physx::PxVec3 const&>(*extent_pod);
physx::PxBounds3 returnValue = PxBounds3::centerExtents(center, extent);
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxBounds3_Pod PxBounds3_basisExtent_mut_1(physx_PxVec3_Pod const* center_pod, physx_PxMat33_Pod const* basis_pod, physx_PxVec3_Pod const* extent_pod) {
physx::PxVec3 const& center = reinterpret_cast<physx::PxVec3 const&>(*center_pod);
physx::PxMat33 const& basis = reinterpret_cast<physx::PxMat33 const&>(*basis_pod);
physx::PxVec3 const& extent = reinterpret_cast<physx::PxVec3 const&>(*extent_pod);
physx::PxBounds3 returnValue = PxBounds3::basisExtent(center, basis, extent);
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxBounds3_Pod PxBounds3_poseExtent_mut_1(physx_PxTransform_Pod const* pose_pod, physx_PxVec3_Pod const* extent_pod) {
physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
physx::PxVec3 const& extent = reinterpret_cast<physx::PxVec3 const&>(*extent_pod);
physx::PxBounds3 returnValue = PxBounds3::poseExtent(pose, extent);
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxBounds3_setEmpty_mut_1(physx_PxBounds3_Pod* self__pod) {
physx::PxBounds3* self_ = reinterpret_cast<physx::PxBounds3*>(self__pod);
self_->setEmpty();
}

void PxBounds3_setMaximal_mut_1(physx_PxBounds3_Pod* self__pod) {
physx::PxBounds3* self_ = reinterpret_cast<physx::PxBounds3*>(self__pod);
self_->setMaximal();
}

void PxBounds3_include_mut_2(physx_PxBounds3_Pod* self__pod, physx_PxVec3_Pod const* v_pod) {
physx::PxBounds3* self_ = reinterpret_cast<physx::PxBounds3*>(self__pod);
physx::PxVec3 const& v = reinterpret_cast<physx::PxVec3 const&>(*v_pod);
self_->include(v);
}

void PxBounds3_include_mut_3(physx_PxBounds3_Pod* self__pod, physx_PxBounds3_Pod const* b_pod) {
physx::PxBounds3* self_ = reinterpret_cast<physx::PxBounds3*>(self__pod);
physx::PxBounds3 const& b = reinterpret_cast<physx::PxBounds3 const&>(*b_pod);
self_->include(b);
}

bool PxBounds3_isEmpty_1(physx_PxBounds3_Pod const* self__pod) {
physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
bool returnValue = self_->isEmpty();
return returnValue;
}

bool PxBounds3_intersects_1(physx_PxBounds3_Pod const* self__pod, physx_PxBounds3_Pod const* b_pod) {
physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
physx::PxBounds3 const& b = reinterpret_cast<physx::PxBounds3 const&>(*b_pod);
bool returnValue = self_->intersects(b);
return returnValue;
}

bool PxBounds3_intersects1D_1(physx_PxBounds3_Pod const* self__pod, physx_PxBounds3_Pod const* a_pod, uint32_t axis) {
physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
physx::PxBounds3 const& a = reinterpret_cast<physx::PxBounds3 const&>(*a_pod);
bool returnValue = self_->intersects1D(a, axis);
return returnValue;
}

bool PxBounds3_contains_1(physx_PxBounds3_Pod const* self__pod, physx_PxVec3_Pod const* v_pod) {
physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
physx::PxVec3 const& v = reinterpret_cast<physx::PxVec3 const&>(*v_pod);
bool returnValue = self_->contains(v);
return returnValue;
}

bool PxBounds3_isInside_1(physx_PxBounds3_Pod const* self__pod, physx_PxBounds3_Pod const* box_pod) {
physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
physx::PxBounds3 const& box = reinterpret_cast<physx::PxBounds3 const&>(*box_pod);
bool returnValue = self_->isInside(box);
return returnValue;
}

physx_PxVec3_Pod PxBounds3_getCenter_2(physx_PxBounds3_Pod const* self__pod) {
physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
physx::PxVec3 returnValue = self_->getCenter();
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

float PxBounds3_getCenter_3(physx_PxBounds3_Pod const* self__pod, uint32_t axis) {
physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
float returnValue = self_->getCenter(axis);
return returnValue;
}

float PxBounds3_getExtents_2(physx_PxBounds3_Pod const* self__pod, uint32_t axis) {
physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
float returnValue = self_->getExtents(axis);
return returnValue;
}

physx_PxVec3_Pod PxBounds3_getDimensions_1(physx_PxBounds3_Pod const* self__pod) {
physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
physx::PxVec3 returnValue = self_->getDimensions();
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxBounds3_getExtents_3(physx_PxBounds3_Pod const* self__pod) {
physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
physx::PxVec3 returnValue = self_->getExtents();
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxBounds3_scaleSafe_mut_1(physx_PxBounds3_Pod* self__pod, float scale) {
physx::PxBounds3* self_ = reinterpret_cast<physx::PxBounds3*>(self__pod);
self_->scaleSafe(scale);
}

void PxBounds3_scaleFast_mut_1(physx_PxBounds3_Pod* self__pod, float scale) {
physx::PxBounds3* self_ = reinterpret_cast<physx::PxBounds3*>(self__pod);
self_->scaleFast(scale);
}

void PxBounds3_fattenSafe_mut_1(physx_PxBounds3_Pod* self__pod, float distance) {
physx::PxBounds3* self_ = reinterpret_cast<physx::PxBounds3*>(self__pod);
self_->fattenSafe(distance);
}

void PxBounds3_fattenFast_mut_1(physx_PxBounds3_Pod* self__pod, float distance) {
physx::PxBounds3* self_ = reinterpret_cast<physx::PxBounds3*>(self__pod);
self_->fattenFast(distance);
}

physx_PxBounds3_Pod PxBounds3_transformSafe_mut_2(physx_PxMat33_Pod const* matrix_pod, physx_PxBounds3_Pod const* bounds_pod) {
physx::PxMat33 const& matrix = reinterpret_cast<physx::PxMat33 const&>(*matrix_pod);
physx::PxBounds3 const& bounds = reinterpret_cast<physx::PxBounds3 const&>(*bounds_pod);
physx::PxBounds3 returnValue = PxBounds3::transformSafe(matrix, bounds);
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxBounds3_Pod PxBounds3_transformFast_mut_2(physx_PxMat33_Pod const* matrix_pod, physx_PxBounds3_Pod const* bounds_pod) {
physx::PxMat33 const& matrix = reinterpret_cast<physx::PxMat33 const&>(*matrix_pod);
physx::PxBounds3 const& bounds = reinterpret_cast<physx::PxBounds3 const&>(*bounds_pod);
physx::PxBounds3 returnValue = PxBounds3::transformFast(matrix, bounds);
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxBounds3_Pod PxBounds3_transformSafe_mut_3(physx_PxTransform_Pod const* transform_pod, physx_PxBounds3_Pod const* bounds_pod) {
physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
physx::PxBounds3 const& bounds = reinterpret_cast<physx::PxBounds3 const&>(*bounds_pod);
physx::PxBounds3 returnValue = PxBounds3::transformSafe(transform, bounds);
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxBounds3_Pod PxBounds3_transformFast_mut_3(physx_PxTransform_Pod const* transform_pod, physx_PxBounds3_Pod const* bounds_pod) {
physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
physx::PxBounds3 const& bounds = reinterpret_cast<physx::PxBounds3 const&>(*bounds_pod);
physx::PxBounds3 returnValue = PxBounds3::transformFast(transform, bounds);
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxBounds3_isValid_1(physx_PxBounds3_Pod const* self__pod) {
physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

void PxErrorCallback_delete(physx_PxErrorCallback_Pod* self__pod) {
physx::PxErrorCallback* self_ = reinterpret_cast<physx::PxErrorCallback*>(self__pod);
delete self_;
}

void PxErrorCallback_reportError_mut(physx_PxErrorCallback_Pod* self__pod, int code_pod, char const* message, char const* file, int32_t line) {
physx::PxErrorCallback* self_ = reinterpret_cast<physx::PxErrorCallback*>(self__pod);
PxErrorCode::Enum code = (PxErrorCode::Enum)code_pod;
self_->reportError(code, message, file, line);
}

uint32_t PxInputStream_read_mut(physx_PxInputStream_Pod* self__pod, void* dest, uint32_t count) {
physx::PxInputStream* self_ = reinterpret_cast<physx::PxInputStream*>(self__pod);
uint32_t returnValue = self_->read(dest, count);
return returnValue;
}

void PxInputStream_delete(physx_PxInputStream_Pod* self__pod) {
physx::PxInputStream* self_ = reinterpret_cast<physx::PxInputStream*>(self__pod);
delete self_;
}

uint32_t PxInputData_getLength(physx_PxInputData_Pod const* self__pod) {
physx::PxInputData const* self_ = reinterpret_cast<physx::PxInputData const*>(self__pod);
uint32_t returnValue = self_->getLength();
return returnValue;
}

void PxInputData_seek_mut(physx_PxInputData_Pod* self__pod, uint32_t offset) {
physx::PxInputData* self_ = reinterpret_cast<physx::PxInputData*>(self__pod);
self_->seek(offset);
}

uint32_t PxInputData_tell(physx_PxInputData_Pod const* self__pod) {
physx::PxInputData const* self_ = reinterpret_cast<physx::PxInputData const*>(self__pod);
uint32_t returnValue = self_->tell();
return returnValue;
}

void PxInputData_delete(physx_PxInputData_Pod* self__pod) {
physx::PxInputData* self_ = reinterpret_cast<physx::PxInputData*>(self__pod);
delete self_;
}

uint32_t PxOutputStream_write_mut(physx_PxOutputStream_Pod* self__pod, void const* src, uint32_t count) {
physx::PxOutputStream* self_ = reinterpret_cast<physx::PxOutputStream*>(self__pod);
uint32_t returnValue = self_->write(src, count);
return returnValue;
}

void PxOutputStream_delete(physx_PxOutputStream_Pod* self__pod) {
physx::PxOutputStream* self_ = reinterpret_cast<physx::PxOutputStream*>(self__pod);
delete self_;
}

physx_PxVec4_Pod PxVec4_new() {
physx::PxVec4 returnValue;
physx_PxVec4_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec4_Pod PxVec4_new_1(unsigned int r_pod) {
physx::PxZERO r = (physx::PxZERO)r_pod;
physx::PxVec4 returnValue(r);
physx_PxVec4_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec4_Pod PxVec4_new_2(float a) {
physx::PxVec4 returnValue(a);
physx_PxVec4_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec4_Pod PxVec4_new_3(float nx, float ny, float nz, float nw) {
physx::PxVec4 returnValue(nx, ny, nz, nw);
physx_PxVec4_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec4_Pod PxVec4_new_4(physx_PxVec3_Pod const* v_pod, float nw) {
physx::PxVec3 const& v = reinterpret_cast<physx::PxVec3 const&>(*v_pod);
physx::PxVec4 returnValue(v, nw);
physx_PxVec4_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec4_Pod PxVec4_new_5(float const* v) {
physx::PxVec4 returnValue(v);
physx_PxVec4_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxVec4_isZero(physx_PxVec4_Pod const* self__pod) {
physx::PxVec4 const* self_ = reinterpret_cast<physx::PxVec4 const*>(self__pod);
bool returnValue = self_->isZero();
return returnValue;
}

bool PxVec4_isFinite(physx_PxVec4_Pod const* self__pod) {
physx::PxVec4 const* self_ = reinterpret_cast<physx::PxVec4 const*>(self__pod);
bool returnValue = self_->isFinite();
return returnValue;
}

bool PxVec4_isNormalized(physx_PxVec4_Pod const* self__pod) {
physx::PxVec4 const* self_ = reinterpret_cast<physx::PxVec4 const*>(self__pod);
bool returnValue = self_->isNormalized();
return returnValue;
}

float PxVec4_magnitudeSquared(physx_PxVec4_Pod const* self__pod) {
physx::PxVec4 const* self_ = reinterpret_cast<physx::PxVec4 const*>(self__pod);
float returnValue = self_->magnitudeSquared();
return returnValue;
}

float PxVec4_magnitude(physx_PxVec4_Pod const* self__pod) {
physx::PxVec4 const* self_ = reinterpret_cast<physx::PxVec4 const*>(self__pod);
float returnValue = self_->magnitude();
return returnValue;
}

float PxVec4_dot(physx_PxVec4_Pod const* self__pod, physx_PxVec4_Pod const* v_pod) {
physx::PxVec4 const* self_ = reinterpret_cast<physx::PxVec4 const*>(self__pod);
physx::PxVec4 const& v = reinterpret_cast<physx::PxVec4 const&>(*v_pod);
float returnValue = self_->dot(v);
return returnValue;
}

physx_PxVec4_Pod PxVec4_getNormalized(physx_PxVec4_Pod const* self__pod) {
physx::PxVec4 const* self_ = reinterpret_cast<physx::PxVec4 const*>(self__pod);
physx::PxVec4 returnValue = self_->getNormalized();
physx_PxVec4_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

float PxVec4_normalize_mut(physx_PxVec4_Pod* self__pod) {
physx::PxVec4* self_ = reinterpret_cast<physx::PxVec4*>(self__pod);
float returnValue = self_->normalize();
return returnValue;
}

physx_PxVec4_Pod PxVec4_multiply(physx_PxVec4_Pod const* self__pod, physx_PxVec4_Pod const* a_pod) {
physx::PxVec4 const* self_ = reinterpret_cast<physx::PxVec4 const*>(self__pod);
physx::PxVec4 const& a = reinterpret_cast<physx::PxVec4 const&>(*a_pod);
physx::PxVec4 returnValue = self_->multiply(a);
physx_PxVec4_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec4_Pod PxVec4_minimum(physx_PxVec4_Pod const* self__pod, physx_PxVec4_Pod const* v_pod) {
physx::PxVec4 const* self_ = reinterpret_cast<physx::PxVec4 const*>(self__pod);
physx::PxVec4 const& v = reinterpret_cast<physx::PxVec4 const&>(*v_pod);
physx::PxVec4 returnValue = self_->minimum(v);
physx_PxVec4_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec4_Pod PxVec4_maximum(physx_PxVec4_Pod const* self__pod, physx_PxVec4_Pod const* v_pod) {
physx::PxVec4 const* self_ = reinterpret_cast<physx::PxVec4 const*>(self__pod);
physx::PxVec4 const& v = reinterpret_cast<physx::PxVec4 const&>(*v_pod);
physx::PxVec4 returnValue = self_->maximum(v);
physx_PxVec4_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxVec4_getXYZ(physx_PxVec4_Pod const* self__pod) {
physx::PxVec4 const* self_ = reinterpret_cast<physx::PxVec4 const*>(self__pod);
physx::PxVec3 returnValue = self_->getXYZ();
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxVec4_setZero_mut(physx_PxVec4_Pod* self__pod) {
physx::PxVec4* self_ = reinterpret_cast<physx::PxVec4*>(self__pod);
self_->setZero();
}

physx_PxMat44_Pod PxMat44_new() {
physx::PxMat44 returnValue;
physx_PxMat44_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMat44_Pod PxMat44_new_1(unsigned int r_pod) {
physx::PxIDENTITY r = (physx::PxIDENTITY)r_pod;
physx::PxMat44 returnValue(r);
physx_PxMat44_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMat44_Pod PxMat44_new_2(unsigned int r_pod) {
physx::PxZERO r = (physx::PxZERO)r_pod;
physx::PxMat44 returnValue(r);
physx_PxMat44_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMat44_Pod PxMat44_new_3(physx_PxVec4_Pod const* col0_pod, physx_PxVec4_Pod const* col1_pod, physx_PxVec4_Pod const* col2_pod, physx_PxVec4_Pod const* col3_pod) {
physx::PxVec4 const& col0 = reinterpret_cast<physx::PxVec4 const&>(*col0_pod);
physx::PxVec4 const& col1 = reinterpret_cast<physx::PxVec4 const&>(*col1_pod);
physx::PxVec4 const& col2 = reinterpret_cast<physx::PxVec4 const&>(*col2_pod);
physx::PxVec4 const& col3 = reinterpret_cast<physx::PxVec4 const&>(*col3_pod);
physx::PxMat44 returnValue(col0, col1, col2, col3);
physx_PxMat44_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMat44_Pod PxMat44_new_4(float r) {
physx::PxMat44 returnValue(r);
physx_PxMat44_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMat44_Pod PxMat44_new_5(physx_PxVec3_Pod const* col0_pod, physx_PxVec3_Pod const* col1_pod, physx_PxVec3_Pod const* col2_pod, physx_PxVec3_Pod const* col3_pod) {
physx::PxVec3 const& col0 = reinterpret_cast<physx::PxVec3 const&>(*col0_pod);
physx::PxVec3 const& col1 = reinterpret_cast<physx::PxVec3 const&>(*col1_pod);
physx::PxVec3 const& col2 = reinterpret_cast<physx::PxVec3 const&>(*col2_pod);
physx::PxVec3 const& col3 = reinterpret_cast<physx::PxVec3 const&>(*col3_pod);
physx::PxMat44 returnValue(col0, col1, col2, col3);
physx_PxMat44_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMat44_Pod PxMat44_new_6(float* values) {
physx::PxMat44 returnValue(values);
physx_PxMat44_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMat44_Pod PxMat44_new_7(physx_PxQuat_Pod const* q_pod) {
physx::PxQuat const& q = reinterpret_cast<physx::PxQuat const&>(*q_pod);
physx::PxMat44 returnValue(q);
physx_PxMat44_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMat44_Pod PxMat44_new_8(physx_PxVec4_Pod const* diagonal_pod) {
physx::PxVec4 const& diagonal = reinterpret_cast<physx::PxVec4 const&>(*diagonal_pod);
physx::PxMat44 returnValue(diagonal);
physx_PxMat44_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMat44_Pod PxMat44_new_9(physx_PxMat33_Pod const* axes_pod, physx_PxVec3_Pod const* position_pod) {
physx::PxMat33 const& axes = reinterpret_cast<physx::PxMat33 const&>(*axes_pod);
physx::PxVec3 const& position = reinterpret_cast<physx::PxVec3 const&>(*position_pod);
physx::PxMat44 returnValue(axes, position);
physx_PxMat44_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMat44_Pod PxMat44_new_10(physx_PxTransform_Pod const* t_pod) {
physx::PxTransform const& t = reinterpret_cast<physx::PxTransform const&>(*t_pod);
physx::PxMat44 returnValue(t);
physx_PxMat44_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMat44_Pod PxMat44_getTranspose(physx_PxMat44_Pod const* self__pod) {
physx::PxMat44 const* self_ = reinterpret_cast<physx::PxMat44 const*>(self__pod);
physx::PxMat44 returnValue = self_->getTranspose();
physx_PxMat44_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec4_Pod PxMat44_transform(physx_PxMat44_Pod const* self__pod, physx_PxVec4_Pod const* other_pod) {
physx::PxMat44 const* self_ = reinterpret_cast<physx::PxMat44 const*>(self__pod);
physx::PxVec4 const& other = reinterpret_cast<physx::PxVec4 const&>(*other_pod);
physx::PxVec4 returnValue = self_->transform(other);
physx_PxVec4_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxMat44_transform_1(physx_PxMat44_Pod const* self__pod, physx_PxVec3_Pod const* other_pod) {
physx::PxMat44 const* self_ = reinterpret_cast<physx::PxMat44 const*>(self__pod);
physx::PxVec3 const& other = reinterpret_cast<physx::PxVec3 const&>(*other_pod);
physx::PxVec3 returnValue = self_->transform(other);
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec4_Pod PxMat44_rotate(physx_PxMat44_Pod const* self__pod, physx_PxVec4_Pod const* other_pod) {
physx::PxMat44 const* self_ = reinterpret_cast<physx::PxMat44 const*>(self__pod);
physx::PxVec4 const& other = reinterpret_cast<physx::PxVec4 const&>(*other_pod);
physx::PxVec4 returnValue = self_->rotate(other);
physx_PxVec4_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxMat44_rotate_1(physx_PxMat44_Pod const* self__pod, physx_PxVec3_Pod const* other_pod) {
physx::PxMat44 const* self_ = reinterpret_cast<physx::PxMat44 const*>(self__pod);
physx::PxVec3 const& other = reinterpret_cast<physx::PxVec3 const&>(*other_pod);
physx::PxVec3 returnValue = self_->rotate(other);
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxMat44_getBasis(physx_PxMat44_Pod const* self__pod, int32_t num) {
physx::PxMat44 const* self_ = reinterpret_cast<physx::PxMat44 const*>(self__pod);
physx::PxVec3 returnValue = self_->getBasis(num);
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxMat44_getPosition(physx_PxMat44_Pod const* self__pod) {
physx::PxMat44 const* self_ = reinterpret_cast<physx::PxMat44 const*>(self__pod);
physx::PxVec3 returnValue = self_->getPosition();
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxMat44_setPosition_mut(physx_PxMat44_Pod* self__pod, physx_PxVec3_Pod const* position_pod) {
physx::PxMat44* self_ = reinterpret_cast<physx::PxMat44*>(self__pod);
physx::PxVec3 const& position = reinterpret_cast<physx::PxVec3 const&>(*position_pod);
self_->setPosition(position);
}

float const* PxMat44_front(physx_PxMat44_Pod const* self__pod) {
physx::PxMat44 const* self_ = reinterpret_cast<physx::PxMat44 const*>(self__pod);
float const* returnValue = self_->front();
return returnValue;
}

void PxMat44_scale_mut(physx_PxMat44_Pod* self__pod, physx_PxVec4_Pod const* p_pod) {
physx::PxMat44* self_ = reinterpret_cast<physx::PxMat44*>(self__pod);
physx::PxVec4 const& p = reinterpret_cast<physx::PxVec4 const&>(*p_pod);
self_->scale(p);
}

physx_PxMat44_Pod PxMat44_inverseRT(physx_PxMat44_Pod const* self__pod) {
physx::PxMat44 const* self_ = reinterpret_cast<physx::PxMat44 const*>(self__pod);
physx::PxMat44 returnValue = self_->inverseRT();
physx_PxMat44_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxMat44_isFinite(physx_PxMat44_Pod const* self__pod) {
physx::PxMat44 const* self_ = reinterpret_cast<physx::PxMat44 const*>(self__pod);
bool returnValue = self_->isFinite();
return returnValue;
}

physx_PxTransform_Pod PxTransform_new_7(physx_PxMat44_Pod const* m_pod) {
physx::PxMat44 const& m = reinterpret_cast<physx::PxMat44 const&>(*m_pod);
physx::PxTransform returnValue(m);
physx_PxTransform_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxQuat_Pod phys_PxShortestRotation(physx_PxVec3_Pod const* from_pod, physx_PxVec3_Pod const* target_pod) {
physx::PxVec3 const& from = reinterpret_cast<physx::PxVec3 const&>(*from_pod);
physx::PxVec3 const& target = reinterpret_cast<physx::PxVec3 const&>(*target_pod);
physx::PxQuat returnValue = PxShortestRotation(from, target);
physx_PxQuat_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod phys_PxDiagonalize(physx_PxMat33_Pod const* m_pod, physx_PxQuat_Pod* axes_pod) {
physx::PxMat33 const& m = reinterpret_cast<physx::PxMat33 const&>(*m_pod);
physx::PxQuat& axes = reinterpret_cast<physx::PxQuat&>(*axes_pod);
physx::PxVec3 returnValue = PxDiagonalize(m, axes);
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec2_Pod PxVec2_new() {
physx::PxVec2 returnValue;
physx_PxVec2_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec2_Pod PxVec2_new_1(unsigned int r_pod) {
physx::PxZERO r = (physx::PxZERO)r_pod;
physx::PxVec2 returnValue(r);
physx_PxVec2_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec2_Pod PxVec2_new_2(float a) {
physx::PxVec2 returnValue(a);
physx_PxVec2_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec2_Pod PxVec2_new_3(float nx, float ny) {
physx::PxVec2 returnValue(nx, ny);
physx_PxVec2_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxVec2_isZero(physx_PxVec2_Pod const* self__pod) {
physx::PxVec2 const* self_ = reinterpret_cast<physx::PxVec2 const*>(self__pod);
bool returnValue = self_->isZero();
return returnValue;
}

bool PxVec2_isFinite(physx_PxVec2_Pod const* self__pod) {
physx::PxVec2 const* self_ = reinterpret_cast<physx::PxVec2 const*>(self__pod);
bool returnValue = self_->isFinite();
return returnValue;
}

bool PxVec2_isNormalized(physx_PxVec2_Pod const* self__pod) {
physx::PxVec2 const* self_ = reinterpret_cast<physx::PxVec2 const*>(self__pod);
bool returnValue = self_->isNormalized();
return returnValue;
}

float PxVec2_magnitudeSquared(physx_PxVec2_Pod const* self__pod) {
physx::PxVec2 const* self_ = reinterpret_cast<physx::PxVec2 const*>(self__pod);
float returnValue = self_->magnitudeSquared();
return returnValue;
}

float PxVec2_magnitude(physx_PxVec2_Pod const* self__pod) {
physx::PxVec2 const* self_ = reinterpret_cast<physx::PxVec2 const*>(self__pod);
float returnValue = self_->magnitude();
return returnValue;
}

float PxVec2_dot(physx_PxVec2_Pod const* self__pod, physx_PxVec2_Pod const* v_pod) {
physx::PxVec2 const* self_ = reinterpret_cast<physx::PxVec2 const*>(self__pod);
physx::PxVec2 const& v = reinterpret_cast<physx::PxVec2 const&>(*v_pod);
float returnValue = self_->dot(v);
return returnValue;
}

physx_PxVec2_Pod PxVec2_getNormalized(physx_PxVec2_Pod const* self__pod) {
physx::PxVec2 const* self_ = reinterpret_cast<physx::PxVec2 const*>(self__pod);
physx::PxVec2 returnValue = self_->getNormalized();
physx_PxVec2_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

float PxVec2_normalize_mut(physx_PxVec2_Pod* self__pod) {
physx::PxVec2* self_ = reinterpret_cast<physx::PxVec2*>(self__pod);
float returnValue = self_->normalize();
return returnValue;
}

physx_PxVec2_Pod PxVec2_multiply(physx_PxVec2_Pod const* self__pod, physx_PxVec2_Pod const* a_pod) {
physx::PxVec2 const* self_ = reinterpret_cast<physx::PxVec2 const*>(self__pod);
physx::PxVec2 const& a = reinterpret_cast<physx::PxVec2 const&>(*a_pod);
physx::PxVec2 returnValue = self_->multiply(a);
physx_PxVec2_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec2_Pod PxVec2_minimum(physx_PxVec2_Pod const* self__pod, physx_PxVec2_Pod const* v_pod) {
physx::PxVec2 const* self_ = reinterpret_cast<physx::PxVec2 const*>(self__pod);
physx::PxVec2 const& v = reinterpret_cast<physx::PxVec2 const&>(*v_pod);
physx::PxVec2 returnValue = self_->minimum(v);
physx_PxVec2_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

float PxVec2_minElement(physx_PxVec2_Pod const* self__pod) {
physx::PxVec2 const* self_ = reinterpret_cast<physx::PxVec2 const*>(self__pod);
float returnValue = self_->minElement();
return returnValue;
}

physx_PxVec2_Pod PxVec2_maximum(physx_PxVec2_Pod const* self__pod, physx_PxVec2_Pod const* v_pod) {
physx::PxVec2 const* self_ = reinterpret_cast<physx::PxVec2 const*>(self__pod);
physx::PxVec2 const& v = reinterpret_cast<physx::PxVec2 const&>(*v_pod);
physx::PxVec2 returnValue = self_->maximum(v);
physx_PxVec2_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

float PxVec2_maxElement(physx_PxVec2_Pod const* self__pod) {
physx::PxVec2 const* self_ = reinterpret_cast<physx::PxVec2 const*>(self__pod);
float returnValue = self_->maxElement();
return returnValue;
}

void* phys_PxMemZero(void* dest, uint32_t count) {
void* returnValue = PxMemZero(dest, count);
return returnValue;
}

void* phys_PxMemSet(void* dest, int32_t c, uint32_t count) {
void* returnValue = PxMemSet(dest, c, count);
return returnValue;
}

void* phys_PxMemCopy(void* dest, void const* src, uint32_t count) {
void* returnValue = PxMemCopy(dest, src, count);
return returnValue;
}

void* phys_PxMemMove(void* dest, void const* src, uint32_t count) {
void* returnValue = PxMemMove(dest, src, count);
return returnValue;
}

physx_PxStridedData_Pod PxStridedData_new() {
physx::PxStridedData returnValue;
physx_PxStridedData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxBoundedData_Pod PxBoundedData_new() {
physx::PxBoundedData returnValue;
physx_PxBoundedData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxDebugPoint_Pod PxDebugPoint_new(physx_PxVec3_Pod const* p_pod, uint32_t const* c_pod) {
physx::PxVec3 const& p = reinterpret_cast<physx::PxVec3 const&>(*p_pod);
uint32_t const& c = *c_pod;
physx::PxDebugPoint returnValue(p, c);
physx_PxDebugPoint_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxDebugLine_Pod PxDebugLine_new(physx_PxVec3_Pod const* p0_pod, physx_PxVec3_Pod const* p1_pod, uint32_t const* c_pod) {
physx::PxVec3 const& p0 = reinterpret_cast<physx::PxVec3 const&>(*p0_pod);
physx::PxVec3 const& p1 = reinterpret_cast<physx::PxVec3 const&>(*p1_pod);
uint32_t const& c = *c_pod;
physx::PxDebugLine returnValue(p0, p1, c);
physx_PxDebugLine_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxDebugTriangle_Pod PxDebugTriangle_new(physx_PxVec3_Pod const* p0_pod, physx_PxVec3_Pod const* p1_pod, physx_PxVec3_Pod const* p2_pod, uint32_t const* c_pod) {
physx::PxVec3 const& p0 = reinterpret_cast<physx::PxVec3 const&>(*p0_pod);
physx::PxVec3 const& p1 = reinterpret_cast<physx::PxVec3 const&>(*p1_pod);
physx::PxVec3 const& p2 = reinterpret_cast<physx::PxVec3 const&>(*p2_pod);
uint32_t const& c = *c_pod;
physx::PxDebugTriangle returnValue(p0, p1, p2, c);
physx_PxDebugTriangle_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxDebugText_Pod PxDebugText_new() {
physx::PxDebugText returnValue;
physx_PxDebugText_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxDebugText_Pod PxDebugText_new_1(physx_PxVec3_Pod const* p_pod, float const* s_pod, uint32_t const* c_pod, char const* str) {
physx::PxVec3 const& p = reinterpret_cast<physx::PxVec3 const&>(*p_pod);
float const& s = *s_pod;
uint32_t const& c = *c_pod;
physx::PxDebugText returnValue(p, s, c, str);
physx_PxDebugText_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxRenderBuffer_delete(physx_PxRenderBuffer_Pod* self__pod) {
physx::PxRenderBuffer* self_ = reinterpret_cast<physx::PxRenderBuffer*>(self__pod);
delete self_;
}

uint32_t PxRenderBuffer_getNbPoints(physx_PxRenderBuffer_Pod const* self__pod) {
physx::PxRenderBuffer const* self_ = reinterpret_cast<physx::PxRenderBuffer const*>(self__pod);
uint32_t returnValue = self_->getNbPoints();
return returnValue;
}

physx_PxDebugPoint_Pod const* PxRenderBuffer_getPoints(physx_PxRenderBuffer_Pod const* self__pod) {
physx::PxRenderBuffer const* self_ = reinterpret_cast<physx::PxRenderBuffer const*>(self__pod);
physx::PxDebugPoint const* returnValue = self_->getPoints();
physx_PxDebugPoint_Pod const* returnValue_pod = reinterpret_cast<physx_PxDebugPoint_Pod const*>(returnValue);
return returnValue_pod;
}

uint32_t PxRenderBuffer_getNbLines(physx_PxRenderBuffer_Pod const* self__pod) {
physx::PxRenderBuffer const* self_ = reinterpret_cast<physx::PxRenderBuffer const*>(self__pod);
uint32_t returnValue = self_->getNbLines();
return returnValue;
}

physx_PxDebugLine_Pod const* PxRenderBuffer_getLines(physx_PxRenderBuffer_Pod const* self__pod) {
physx::PxRenderBuffer const* self_ = reinterpret_cast<physx::PxRenderBuffer const*>(self__pod);
physx::PxDebugLine const* returnValue = self_->getLines();
physx_PxDebugLine_Pod const* returnValue_pod = reinterpret_cast<physx_PxDebugLine_Pod const*>(returnValue);
return returnValue_pod;
}

uint32_t PxRenderBuffer_getNbTriangles(physx_PxRenderBuffer_Pod const* self__pod) {
physx::PxRenderBuffer const* self_ = reinterpret_cast<physx::PxRenderBuffer const*>(self__pod);
uint32_t returnValue = self_->getNbTriangles();
return returnValue;
}

physx_PxDebugTriangle_Pod const* PxRenderBuffer_getTriangles(physx_PxRenderBuffer_Pod const* self__pod) {
physx::PxRenderBuffer const* self_ = reinterpret_cast<physx::PxRenderBuffer const*>(self__pod);
physx::PxDebugTriangle const* returnValue = self_->getTriangles();
physx_PxDebugTriangle_Pod const* returnValue_pod = reinterpret_cast<physx_PxDebugTriangle_Pod const*>(returnValue);
return returnValue_pod;
}

uint32_t PxRenderBuffer_getNbTexts(physx_PxRenderBuffer_Pod const* self__pod) {
physx::PxRenderBuffer const* self_ = reinterpret_cast<physx::PxRenderBuffer const*>(self__pod);
uint32_t returnValue = self_->getNbTexts();
return returnValue;
}

physx_PxDebugText_Pod const* PxRenderBuffer_getTexts(physx_PxRenderBuffer_Pod const* self__pod) {
physx::PxRenderBuffer const* self_ = reinterpret_cast<physx::PxRenderBuffer const*>(self__pod);
physx::PxDebugText const* returnValue = self_->getTexts();
physx_PxDebugText_Pod const* returnValue_pod = reinterpret_cast<physx_PxDebugText_Pod const*>(returnValue);
return returnValue_pod;
}

void PxRenderBuffer_append_mut(physx_PxRenderBuffer_Pod* self__pod, physx_PxRenderBuffer_Pod const* other_pod) {
physx::PxRenderBuffer* self_ = reinterpret_cast<physx::PxRenderBuffer*>(self__pod);
physx::PxRenderBuffer const& other = reinterpret_cast<physx::PxRenderBuffer const&>(*other_pod);
self_->append(other);
}

void PxRenderBuffer_clear_mut(physx_PxRenderBuffer_Pod* self__pod) {
physx::PxRenderBuffer* self_ = reinterpret_cast<physx::PxRenderBuffer*>(self__pod);
self_->clear();
}

void PxProcessPxBaseCallback_delete(physx_PxProcessPxBaseCallback_Pod* self__pod) {
physx::PxProcessPxBaseCallback* self_ = reinterpret_cast<physx::PxProcessPxBaseCallback*>(self__pod);
delete self_;
}

void PxProcessPxBaseCallback_process_mut(physx_PxProcessPxBaseCallback_Pod* self__pod, physx_PxBase_Pod* anonymous_arg0_pod) {
physx::PxProcessPxBaseCallback* self_ = reinterpret_cast<physx::PxProcessPxBaseCallback*>(self__pod);
physx::PxBase& anonymous_arg0 = reinterpret_cast<physx::PxBase&>(*anonymous_arg0_pod);
self_->process(anonymous_arg0);
}

void PxSerializationContext_registerReference_mut(physx_PxSerializationContext_Pod* self__pod, physx_PxBase_Pod* base_pod, uint32_t kind, uint64_t reference) {
physx::PxSerializationContext* self_ = reinterpret_cast<physx::PxSerializationContext*>(self__pod);
physx::PxBase& base = reinterpret_cast<physx::PxBase&>(*base_pod);
self_->registerReference(base, kind, reference);
}

physx_PxCollection_Pod const* PxSerializationContext_getCollection(physx_PxSerializationContext_Pod const* self__pod) {
physx::PxSerializationContext const* self_ = reinterpret_cast<physx::PxSerializationContext const*>(self__pod);
physx::PxCollection const& returnValue = self_->getCollection();
physx_PxCollection_Pod const* returnValue_pod = reinterpret_cast<physx_PxCollection_Pod const*>(&returnValue);
return returnValue_pod;
}

void PxSerializationContext_writeData_mut(physx_PxSerializationContext_Pod* self__pod, void const* data, uint32_t size) {
physx::PxSerializationContext* self_ = reinterpret_cast<physx::PxSerializationContext*>(self__pod);
self_->writeData(data, size);
}

void PxSerializationContext_alignData_mut(physx_PxSerializationContext_Pod* self__pod, uint32_t alignment) {
physx::PxSerializationContext* self_ = reinterpret_cast<physx::PxSerializationContext*>(self__pod);
self_->alignData(alignment);
}

void PxSerializationContext_writeName_mut(physx_PxSerializationContext_Pod* self__pod, char const* name) {
physx::PxSerializationContext* self_ = reinterpret_cast<physx::PxSerializationContext*>(self__pod);
self_->writeName(name);
}

physx_PxBase_Pod* PxDeserializationContext_resolveReference(physx_PxDeserializationContext_Pod const* self__pod, uint32_t kind, uint64_t reference) {
physx::PxDeserializationContext const* self_ = reinterpret_cast<physx::PxDeserializationContext const*>(self__pod);
physx::PxBase* returnValue = self_->resolveReference(kind, reference);
physx_PxBase_Pod* returnValue_pod = reinterpret_cast<physx_PxBase_Pod*>(returnValue);
return returnValue_pod;
}

void PxDeserializationContext_readName_mut(physx_PxDeserializationContext_Pod* self__pod, char const** name_pod) {
physx::PxDeserializationContext* self_ = reinterpret_cast<physx::PxDeserializationContext*>(self__pod);
char const*& name = *name_pod;
self_->readName(name);
}

void PxDeserializationContext_alignExtraData_mut(physx_PxDeserializationContext_Pod* self__pod, uint32_t alignment) {
physx::PxDeserializationContext* self_ = reinterpret_cast<physx::PxDeserializationContext*>(self__pod);
self_->alignExtraData(alignment);
}

void PxSerializationRegistry_registerSerializer_mut(physx_PxSerializationRegistry_Pod* self__pod, uint16_t type, physx_PxSerializer_Pod* serializer_pod) {
physx::PxSerializationRegistry* self_ = reinterpret_cast<physx::PxSerializationRegistry*>(self__pod);
physx::PxSerializer& serializer = reinterpret_cast<physx::PxSerializer&>(*serializer_pod);
self_->registerSerializer(type, serializer);
}

physx_PxSerializer_Pod* PxSerializationRegistry_unregisterSerializer_mut(physx_PxSerializationRegistry_Pod* self__pod, uint16_t type) {
physx::PxSerializationRegistry* self_ = reinterpret_cast<physx::PxSerializationRegistry*>(self__pod);
physx::PxSerializer* returnValue = self_->unregisterSerializer(type);
physx_PxSerializer_Pod* returnValue_pod = reinterpret_cast<physx_PxSerializer_Pod*>(returnValue);
return returnValue_pod;
}

void PxSerializationRegistry_registerBinaryMetaDataCallback_mut(physx_PxSerializationRegistry_Pod* self__pod, void* callback_pod) {
physx::PxSerializationRegistry* self_ = reinterpret_cast<physx::PxSerializationRegistry*>(self__pod);
physx::PxBinaryMetaDataCallback callback;
memcpy(&callback, &callback_pod, sizeof(callback));
self_->registerBinaryMetaDataCallback(callback);
}

physx_PxSerializer_Pod const* PxSerializationRegistry_getSerializer(physx_PxSerializationRegistry_Pod const* self__pod, uint16_t type) {
physx::PxSerializationRegistry const* self_ = reinterpret_cast<physx::PxSerializationRegistry const*>(self__pod);
physx::PxSerializer const* returnValue = self_->getSerializer(type);
physx_PxSerializer_Pod const* returnValue_pod = reinterpret_cast<physx_PxSerializer_Pod const*>(returnValue);
return returnValue_pod;
}

void PxSerializationRegistry_registerRepXSerializer_mut(physx_PxSerializationRegistry_Pod* self__pod, uint16_t type, physx_PxRepXSerializer_Pod* serializer_pod) {
physx::PxSerializationRegistry* self_ = reinterpret_cast<physx::PxSerializationRegistry*>(self__pod);
physx::PxRepXSerializer& serializer = reinterpret_cast<physx::PxRepXSerializer&>(*serializer_pod);
self_->registerRepXSerializer(type, serializer);
}

physx_PxRepXSerializer_Pod* PxSerializationRegistry_unregisterRepXSerializer_mut(physx_PxSerializationRegistry_Pod* self__pod, uint16_t type) {
physx::PxSerializationRegistry* self_ = reinterpret_cast<physx::PxSerializationRegistry*>(self__pod);
physx::PxRepXSerializer* returnValue = self_->unregisterRepXSerializer(type);
physx_PxRepXSerializer_Pod* returnValue_pod = reinterpret_cast<physx_PxRepXSerializer_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxRepXSerializer_Pod* PxSerializationRegistry_getRepXSerializer(physx_PxSerializationRegistry_Pod const* self__pod, char const* typeName) {
physx::PxSerializationRegistry const* self_ = reinterpret_cast<physx::PxSerializationRegistry const*>(self__pod);
physx::PxRepXSerializer* returnValue = self_->getRepXSerializer(typeName);
physx_PxRepXSerializer_Pod* returnValue_pod = reinterpret_cast<physx_PxRepXSerializer_Pod*>(returnValue);
return returnValue_pod;
}

void PxSerializationRegistry_release_mut(physx_PxSerializationRegistry_Pod* self__pod) {
physx::PxSerializationRegistry* self_ = reinterpret_cast<physx::PxSerializationRegistry*>(self__pod);
self_->release();
}

void PxCollection_add_mut(physx_PxCollection_Pod* self__pod, physx_PxBase_Pod* object_pod, uint64_t id) {
physx::PxCollection* self_ = reinterpret_cast<physx::PxCollection*>(self__pod);
physx::PxBase& object = reinterpret_cast<physx::PxBase&>(*object_pod);
self_->add(object, id);
}

void PxCollection_remove_mut(physx_PxCollection_Pod* self__pod, physx_PxBase_Pod* object_pod) {
physx::PxCollection* self_ = reinterpret_cast<physx::PxCollection*>(self__pod);
physx::PxBase& object = reinterpret_cast<physx::PxBase&>(*object_pod);
self_->remove(object);
}

bool PxCollection_contains(physx_PxCollection_Pod const* self__pod, physx_PxBase_Pod* object_pod) {
physx::PxCollection const* self_ = reinterpret_cast<physx::PxCollection const*>(self__pod);
physx::PxBase& object = reinterpret_cast<physx::PxBase&>(*object_pod);
bool returnValue = self_->contains(object);
return returnValue;
}

void PxCollection_addId_mut(physx_PxCollection_Pod* self__pod, physx_PxBase_Pod* object_pod, uint64_t id) {
physx::PxCollection* self_ = reinterpret_cast<physx::PxCollection*>(self__pod);
physx::PxBase& object = reinterpret_cast<physx::PxBase&>(*object_pod);
self_->addId(object, id);
}

void PxCollection_removeId_mut(physx_PxCollection_Pod* self__pod, uint64_t id) {
physx::PxCollection* self_ = reinterpret_cast<physx::PxCollection*>(self__pod);
self_->removeId(id);
}

void PxCollection_add_mut_1(physx_PxCollection_Pod* self__pod, physx_PxCollection_Pod* collection_pod) {
physx::PxCollection* self_ = reinterpret_cast<physx::PxCollection*>(self__pod);
physx::PxCollection& collection = reinterpret_cast<physx::PxCollection&>(*collection_pod);
self_->add(collection);
}

void PxCollection_remove_mut_1(physx_PxCollection_Pod* self__pod, physx_PxCollection_Pod* collection_pod) {
physx::PxCollection* self_ = reinterpret_cast<physx::PxCollection*>(self__pod);
physx::PxCollection& collection = reinterpret_cast<physx::PxCollection&>(*collection_pod);
self_->remove(collection);
}

uint32_t PxCollection_getNbObjects(physx_PxCollection_Pod const* self__pod) {
physx::PxCollection const* self_ = reinterpret_cast<physx::PxCollection const*>(self__pod);
uint32_t returnValue = self_->getNbObjects();
return returnValue;
}

physx_PxBase_Pod* PxCollection_getObject(physx_PxCollection_Pod const* self__pod, uint32_t index) {
physx::PxCollection const* self_ = reinterpret_cast<physx::PxCollection const*>(self__pod);
physx::PxBase& returnValue = self_->getObject(index);
physx_PxBase_Pod* returnValue_pod = reinterpret_cast<physx_PxBase_Pod*>(&returnValue);
return returnValue_pod;
}

uint32_t PxCollection_getObjects(physx_PxCollection_Pod const* self__pod, physx_PxBase_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
physx::PxCollection const* self_ = reinterpret_cast<physx::PxCollection const*>(self__pod);
physx::PxBase** userBuffer = reinterpret_cast<physx::PxBase**>(userBuffer_pod);
uint32_t returnValue = self_->getObjects(userBuffer, bufferSize, startIndex);
return returnValue;
}

physx_PxBase_Pod* PxCollection_find(physx_PxCollection_Pod const* self__pod, uint64_t id) {
physx::PxCollection const* self_ = reinterpret_cast<physx::PxCollection const*>(self__pod);
physx::PxBase* returnValue = self_->find(id);
physx_PxBase_Pod* returnValue_pod = reinterpret_cast<physx_PxBase_Pod*>(returnValue);
return returnValue_pod;
}

uint32_t PxCollection_getNbIds(physx_PxCollection_Pod const* self__pod) {
physx::PxCollection const* self_ = reinterpret_cast<physx::PxCollection const*>(self__pod);
uint32_t returnValue = self_->getNbIds();
return returnValue;
}

uint32_t PxCollection_getIds(physx_PxCollection_Pod const* self__pod, uint64_t* userBuffer, uint32_t bufferSize, uint32_t startIndex) {
physx::PxCollection const* self_ = reinterpret_cast<physx::PxCollection const*>(self__pod);
uint32_t returnValue = self_->getIds(userBuffer, bufferSize, startIndex);
return returnValue;
}

uint64_t PxCollection_getId(physx_PxCollection_Pod const* self__pod, physx_PxBase_Pod const* object_pod) {
physx::PxCollection const* self_ = reinterpret_cast<physx::PxCollection const*>(self__pod);
physx::PxBase const& object = reinterpret_cast<physx::PxBase const&>(*object_pod);
uint64_t returnValue = self_->getId(object);
return returnValue;
}

void PxCollection_release_mut(physx_PxCollection_Pod* self__pod) {
physx::PxCollection* self_ = reinterpret_cast<physx::PxCollection*>(self__pod);
self_->release();
}

physx_PxCollection_Pod* phys_PxCreateCollection() {
physx::PxCollection* returnValue = PxCreateCollection();
physx_PxCollection_Pod* returnValue_pod = reinterpret_cast<physx_PxCollection_Pod*>(returnValue);
return returnValue_pod;
}

void PxBase_release_mut(physx_PxBase_Pod* self__pod) {
physx::PxBase* self_ = reinterpret_cast<physx::PxBase*>(self__pod);
self_->release();
}

char const* PxBase_getConcreteTypeName(physx_PxBase_Pod const* self__pod) {
physx::PxBase const* self_ = reinterpret_cast<physx::PxBase const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

uint16_t PxBase_getConcreteType(physx_PxBase_Pod const* self__pod) {
physx::PxBase const* self_ = reinterpret_cast<physx::PxBase const*>(self__pod);
uint16_t returnValue = self_->getConcreteType();
return returnValue;
}

void PxBase_setBaseFlag_mut(physx_PxBase_Pod* self__pod, unsigned int flag_pod, bool value) {
physx::PxBase* self_ = reinterpret_cast<physx::PxBase*>(self__pod);
PxBaseFlag::Enum flag = (PxBaseFlag::Enum)flag_pod;
self_->setBaseFlag(flag, value);
}

void PxBase_setBaseFlags_mut(physx_PxBase_Pod* self__pod, physx_PxBaseFlags_Pod inFlags_pod) {
physx::PxBase* self_ = reinterpret_cast<physx::PxBase*>(self__pod);
physx::PxBaseFlags inFlags;
memcpy(&inFlags, &inFlags_pod, sizeof(inFlags));
self_->setBaseFlags(inFlags);
}

physx_PxBaseFlags_Pod PxBase_getBaseFlags(physx_PxBase_Pod const* self__pod) {
physx::PxBase const* self_ = reinterpret_cast<physx::PxBase const*>(self__pod);
physx::PxBaseFlags returnValue = self_->getBaseFlags();
physx_PxBaseFlags_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxBase_isReleasable(physx_PxBase_Pod const* self__pod) {
physx::PxBase const* self_ = reinterpret_cast<physx::PxBase const*>(self__pod);
bool returnValue = self_->isReleasable();
return returnValue;
}

physx_PxTolerancesScale_Pod PxTolerancesScale_new() {
physx::PxTolerancesScale returnValue;
physx_PxTolerancesScale_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxTolerancesScale_isValid(physx_PxTolerancesScale_Pod const* self__pod) {
physx::PxTolerancesScale const* self_ = reinterpret_cast<physx::PxTolerancesScale const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

physx_PxTolerancesScale_Pod PxTolerancesScale_new_1() {
physx::PxTolerancesScale returnValue;
physx_PxTolerancesScale_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxTolerancesScale_isValid_1(physx_PxTolerancesScale_Pod const* self__pod) {
physx::PxTolerancesScale const* self_ = reinterpret_cast<physx::PxTolerancesScale const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

char const* PxStringTable_allocateStr_mut(physx_PxStringTable_Pod* self__pod, char const* inSrc) {
physx::PxStringTable* self_ = reinterpret_cast<physx::PxStringTable*>(self__pod);
char const* returnValue = self_->allocateStr(inSrc);
return returnValue;
}

void PxStringTable_release_mut(physx_PxStringTable_Pod* self__pod) {
physx::PxStringTable* self_ = reinterpret_cast<physx::PxStringTable*>(self__pod);
self_->release();
}

void PxFoundation_release_mut(physx_PxFoundation_Pod* self__pod) {
physx::PxFoundation* self_ = reinterpret_cast<physx::PxFoundation*>(self__pod);
self_->release();
}

physx_PxErrorCallback_Pod* PxFoundation_getErrorCallback_mut(physx_PxFoundation_Pod* self__pod) {
physx::PxFoundation* self_ = reinterpret_cast<physx::PxFoundation*>(self__pod);
physx::PxErrorCallback& returnValue = self_->getErrorCallback();
physx_PxErrorCallback_Pod* returnValue_pod = reinterpret_cast<physx_PxErrorCallback_Pod*>(&returnValue);
return returnValue_pod;
}

void PxFoundation_setErrorLevel_mut(physx_PxFoundation_Pod* self__pod, int mask_pod) {
physx::PxFoundation* self_ = reinterpret_cast<physx::PxFoundation*>(self__pod);
PxErrorCode::Enum mask = (PxErrorCode::Enum)mask_pod;
self_->setErrorLevel(mask);
}

int PxFoundation_getErrorLevel(physx_PxFoundation_Pod const* self__pod) {
physx::PxFoundation const* self_ = reinterpret_cast<physx::PxFoundation const*>(self__pod);
PxErrorCode::Enum returnValue = self_->getErrorLevel();
int returnValue_pod = (int)returnValue;
return returnValue_pod;
}

physx_PxAllocatorCallback_Pod* PxFoundation_getAllocatorCallback_mut(physx_PxFoundation_Pod* self__pod) {
physx::PxFoundation* self_ = reinterpret_cast<physx::PxFoundation*>(self__pod);
physx::PxAllocatorCallback& returnValue = self_->getAllocatorCallback();
physx_PxAllocatorCallback_Pod* returnValue_pod = reinterpret_cast<physx_PxAllocatorCallback_Pod*>(&returnValue);
return returnValue_pod;
}

bool PxFoundation_getReportAllocationNames(physx_PxFoundation_Pod const* self__pod) {
physx::PxFoundation const* self_ = reinterpret_cast<physx::PxFoundation const*>(self__pod);
bool returnValue = self_->getReportAllocationNames();
return returnValue;
}

void PxFoundation_setReportAllocationNames_mut(physx_PxFoundation_Pod* self__pod, bool value) {
physx::PxFoundation* self_ = reinterpret_cast<physx::PxFoundation*>(self__pod);
self_->setReportAllocationNames(value);
}

physx_PxFoundation_Pod* phys_PxCreateFoundation(uint32_t version, physx_PxAllocatorCallback_Pod* allocator_pod, physx_PxErrorCallback_Pod* errorCallback_pod) {
physx::PxAllocatorCallback& allocator = reinterpret_cast<physx::PxAllocatorCallback&>(*allocator_pod);
physx::PxErrorCallback& errorCallback = reinterpret_cast<physx::PxErrorCallback&>(*errorCallback_pod);
physx::PxFoundation* returnValue = PxCreateFoundation(version, allocator, errorCallback);
physx_PxFoundation_Pod* returnValue_pod = reinterpret_cast<physx_PxFoundation_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxFoundation_Pod* phys_PxGetFoundation() {
physx::PxFoundation& returnValue = PxGetFoundation();
physx_PxFoundation_Pod* returnValue_pod = reinterpret_cast<physx_PxFoundation_Pod*>(&returnValue);
return returnValue_pod;
}

physx_PxProfilerCallback_Pod* phys_PxGetProfilerCallback() {
physx::PxProfilerCallback* returnValue = PxGetProfilerCallback();
physx_PxProfilerCallback_Pod* returnValue_pod = reinterpret_cast<physx_PxProfilerCallback_Pod*>(returnValue);
return returnValue_pod;
}

void phys_PxSetProfilerCallback(physx_PxProfilerCallback_Pod* profiler_pod) {
physx::PxProfilerCallback* profiler = reinterpret_cast<physx::PxProfilerCallback*>(profiler_pod);
PxSetProfilerCallback(profiler);
}

char const* PxSerializer_getConcreteTypeName(physx_PxSerializer_Pod const* self__pod) {
physx::PxSerializer const* self_ = reinterpret_cast<physx::PxSerializer const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

void PxSerializer_requiresObjects(physx_PxSerializer_Pod const* self__pod, physx_PxBase_Pod* anonymous_arg0_pod, physx_PxProcessPxBaseCallback_Pod* anonymous_arg1_pod) {
physx::PxSerializer const* self_ = reinterpret_cast<physx::PxSerializer const*>(self__pod);
physx::PxBase& anonymous_arg0 = reinterpret_cast<physx::PxBase&>(*anonymous_arg0_pod);
physx::PxProcessPxBaseCallback& anonymous_arg1 = reinterpret_cast<physx::PxProcessPxBaseCallback&>(*anonymous_arg1_pod);
self_->requiresObjects(anonymous_arg0, anonymous_arg1);
}

bool PxSerializer_isSubordinate(physx_PxSerializer_Pod const* self__pod) {
physx::PxSerializer const* self_ = reinterpret_cast<physx::PxSerializer const*>(self__pod);
bool returnValue = self_->isSubordinate();
return returnValue;
}

void PxSerializer_exportExtraData(physx_PxSerializer_Pod const* self__pod, physx_PxBase_Pod* anonymous_arg0_pod, physx_PxSerializationContext_Pod* anonymous_arg1_pod) {
physx::PxSerializer const* self_ = reinterpret_cast<physx::PxSerializer const*>(self__pod);
physx::PxBase& anonymous_arg0 = reinterpret_cast<physx::PxBase&>(*anonymous_arg0_pod);
physx::PxSerializationContext& anonymous_arg1 = reinterpret_cast<physx::PxSerializationContext&>(*anonymous_arg1_pod);
self_->exportExtraData(anonymous_arg0, anonymous_arg1);
}

void PxSerializer_exportData(physx_PxSerializer_Pod const* self__pod, physx_PxBase_Pod* anonymous_arg0_pod, physx_PxSerializationContext_Pod* anonymous_arg1_pod) {
physx::PxSerializer const* self_ = reinterpret_cast<physx::PxSerializer const*>(self__pod);
physx::PxBase& anonymous_arg0 = reinterpret_cast<physx::PxBase&>(*anonymous_arg0_pod);
physx::PxSerializationContext& anonymous_arg1 = reinterpret_cast<physx::PxSerializationContext&>(*anonymous_arg1_pod);
self_->exportData(anonymous_arg0, anonymous_arg1);
}

void PxSerializer_registerReferences(physx_PxSerializer_Pod const* self__pod, physx_PxBase_Pod* obj_pod, physx_PxSerializationContext_Pod* s_pod) {
physx::PxSerializer const* self_ = reinterpret_cast<physx::PxSerializer const*>(self__pod);
physx::PxBase& obj = reinterpret_cast<physx::PxBase&>(*obj_pod);
physx::PxSerializationContext& s = reinterpret_cast<physx::PxSerializationContext&>(*s_pod);
self_->registerReferences(obj, s);
}

uint64_t PxSerializer_getClassSize(physx_PxSerializer_Pod const* self__pod) {
physx::PxSerializer const* self_ = reinterpret_cast<physx::PxSerializer const*>(self__pod);
uint64_t returnValue = self_->getClassSize();
return returnValue;
}

physx_PxBase_Pod* PxSerializer_createObject(physx_PxSerializer_Pod const* self__pod, unsigned char** address_pod, physx_PxDeserializationContext_Pod* context_pod) {
physx::PxSerializer const* self_ = reinterpret_cast<physx::PxSerializer const*>(self__pod);
unsigned char*& address = *address_pod;
physx::PxDeserializationContext& context = reinterpret_cast<physx::PxDeserializationContext&>(*context_pod);
physx::PxBase* returnValue = self_->createObject(address, context);
physx_PxBase_Pod* returnValue_pod = reinterpret_cast<physx_PxBase_Pod*>(returnValue);
return returnValue_pod;
}

void PxSerializer_delete(physx_PxSerializer_Pod* self__pod) {
physx::PxSerializer* self_ = reinterpret_cast<physx::PxSerializer*>(self__pod);
delete self_;
}

physx_PxBase_Pod* PxPhysicsInsertionCallback_buildObjectFromData_mut(physx_PxPhysicsInsertionCallback_Pod* self__pod, unsigned int type_pod, void* data) {
physx::PxPhysicsInsertionCallback* self_ = reinterpret_cast<physx::PxPhysicsInsertionCallback*>(self__pod);
PxConcreteType::Enum type = (PxConcreteType::Enum)type_pod;
physx::PxBase* returnValue = self_->buildObjectFromData(type, data);
physx_PxBase_Pod* returnValue_pod = reinterpret_cast<physx_PxBase_Pod*>(returnValue);
return returnValue_pod;
}

void PxTaskManager_setCpuDispatcher_mut(physx_PxTaskManager_Pod* self__pod, physx_PxCpuDispatcher_Pod* ref_pod) {
physx::PxTaskManager* self_ = reinterpret_cast<physx::PxTaskManager*>(self__pod);
physx::PxCpuDispatcher& ref = reinterpret_cast<physx::PxCpuDispatcher&>(*ref_pod);
self_->setCpuDispatcher(ref);
}

physx_PxCpuDispatcher_Pod* PxTaskManager_getCpuDispatcher(physx_PxTaskManager_Pod const* self__pod) {
physx::PxTaskManager const* self_ = reinterpret_cast<physx::PxTaskManager const*>(self__pod);
physx::PxCpuDispatcher* returnValue = self_->getCpuDispatcher();
physx_PxCpuDispatcher_Pod* returnValue_pod = reinterpret_cast<physx_PxCpuDispatcher_Pod*>(returnValue);
return returnValue_pod;
}

void PxTaskManager_resetDependencies_mut(physx_PxTaskManager_Pod* self__pod) {
physx::PxTaskManager* self_ = reinterpret_cast<physx::PxTaskManager*>(self__pod);
self_->resetDependencies();
}

void PxTaskManager_startSimulation_mut(physx_PxTaskManager_Pod* self__pod) {
physx::PxTaskManager* self_ = reinterpret_cast<physx::PxTaskManager*>(self__pod);
self_->startSimulation();
}

void PxTaskManager_stopSimulation_mut(physx_PxTaskManager_Pod* self__pod) {
physx::PxTaskManager* self_ = reinterpret_cast<physx::PxTaskManager*>(self__pod);
self_->stopSimulation();
}

void PxTaskManager_taskCompleted_mut(physx_PxTaskManager_Pod* self__pod, physx_PxTask_Pod* task_pod) {
physx::PxTaskManager* self_ = reinterpret_cast<physx::PxTaskManager*>(self__pod);
physx::PxTask& task = reinterpret_cast<physx::PxTask&>(*task_pod);
self_->taskCompleted(task);
}

uint32_t PxTaskManager_getNamedTask_mut(physx_PxTaskManager_Pod* self__pod, char const* name) {
physx::PxTaskManager* self_ = reinterpret_cast<physx::PxTaskManager*>(self__pod);
uint32_t returnValue = self_->getNamedTask(name);
return returnValue;
}

uint32_t PxTaskManager_submitNamedTask_mut(physx_PxTaskManager_Pod* self__pod, physx_PxTask_Pod* task_pod, char const* name, unsigned int type_pod) {
physx::PxTaskManager* self_ = reinterpret_cast<physx::PxTaskManager*>(self__pod);
physx::PxTask* task = reinterpret_cast<physx::PxTask*>(task_pod);
PxTaskType::Enum type = (PxTaskType::Enum)type_pod;
uint32_t returnValue = self_->submitNamedTask(task, name, type);
return returnValue;
}

uint32_t PxTaskManager_submitUnnamedTask_mut(physx_PxTaskManager_Pod* self__pod, physx_PxTask_Pod* task_pod, unsigned int type_pod) {
physx::PxTaskManager* self_ = reinterpret_cast<physx::PxTaskManager*>(self__pod);
physx::PxTask& task = reinterpret_cast<physx::PxTask&>(*task_pod);
PxTaskType::Enum type = (PxTaskType::Enum)type_pod;
uint32_t returnValue = self_->submitUnnamedTask(task, type);
return returnValue;
}

physx_PxTask_Pod* PxTaskManager_getTaskFromID_mut(physx_PxTaskManager_Pod* self__pod, uint32_t id) {
physx::PxTaskManager* self_ = reinterpret_cast<physx::PxTaskManager*>(self__pod);
physx::PxTask* returnValue = self_->getTaskFromID(id);
physx_PxTask_Pod* returnValue_pod = reinterpret_cast<physx_PxTask_Pod*>(returnValue);
return returnValue_pod;
}

void PxTaskManager_release_mut(physx_PxTaskManager_Pod* self__pod) {
physx::PxTaskManager* self_ = reinterpret_cast<physx::PxTaskManager*>(self__pod);
self_->release();
}

physx_PxTaskManager_Pod* PxTaskManager_createTaskManager_mut(physx_PxErrorCallback_Pod* errorCallback_pod, physx_PxCpuDispatcher_Pod* anonymous_arg1_pod) {
physx::PxErrorCallback& errorCallback = reinterpret_cast<physx::PxErrorCallback&>(*errorCallback_pod);
physx::PxCpuDispatcher* anonymous_arg1 = reinterpret_cast<physx::PxCpuDispatcher*>(anonymous_arg1_pod);
physx::PxTaskManager* returnValue = PxTaskManager::createTaskManager(errorCallback, anonymous_arg1);
physx_PxTaskManager_Pod* returnValue_pod = reinterpret_cast<physx_PxTaskManager_Pod*>(returnValue);
return returnValue_pod;
}

void PxCpuDispatcher_submitTask_mut(physx_PxCpuDispatcher_Pod* self__pod, physx_PxBaseTask_Pod* task_pod) {
physx::PxCpuDispatcher* self_ = reinterpret_cast<physx::PxCpuDispatcher*>(self__pod);
physx::PxBaseTask& task = reinterpret_cast<physx::PxBaseTask&>(*task_pod);
self_->submitTask(task);
}

uint32_t PxCpuDispatcher_getWorkerCount(physx_PxCpuDispatcher_Pod const* self__pod) {
physx::PxCpuDispatcher const* self_ = reinterpret_cast<physx::PxCpuDispatcher const*>(self__pod);
uint32_t returnValue = self_->getWorkerCount();
return returnValue;
}

void PxCpuDispatcher_delete(physx_PxCpuDispatcher_Pod* self__pod) {
physx::PxCpuDispatcher* self_ = reinterpret_cast<physx::PxCpuDispatcher*>(self__pod);
delete self_;
}

void PxBaseTask_run_mut(physx_PxBaseTask_Pod* self__pod) {
physx::PxBaseTask* self_ = reinterpret_cast<physx::PxBaseTask*>(self__pod);
self_->run();
}

char const* PxBaseTask_getName(physx_PxBaseTask_Pod const* self__pod) {
physx::PxBaseTask const* self_ = reinterpret_cast<physx::PxBaseTask const*>(self__pod);
char const* returnValue = self_->getName();
return returnValue;
}

void PxBaseTask_addReference_mut(physx_PxBaseTask_Pod* self__pod) {
physx::PxBaseTask* self_ = reinterpret_cast<physx::PxBaseTask*>(self__pod);
self_->addReference();
}

void PxBaseTask_removeReference_mut(physx_PxBaseTask_Pod* self__pod) {
physx::PxBaseTask* self_ = reinterpret_cast<physx::PxBaseTask*>(self__pod);
self_->removeReference();
}

int32_t PxBaseTask_getReference(physx_PxBaseTask_Pod const* self__pod) {
physx::PxBaseTask const* self_ = reinterpret_cast<physx::PxBaseTask const*>(self__pod);
int32_t returnValue = self_->getReference();
return returnValue;
}

void PxBaseTask_release_mut(physx_PxBaseTask_Pod* self__pod) {
physx::PxBaseTask* self_ = reinterpret_cast<physx::PxBaseTask*>(self__pod);
self_->release();
}

physx_PxTaskManager_Pod* PxBaseTask_getTaskManager(physx_PxBaseTask_Pod const* self__pod) {
physx::PxBaseTask const* self_ = reinterpret_cast<physx::PxBaseTask const*>(self__pod);
physx::PxTaskManager* returnValue = self_->getTaskManager();
physx_PxTaskManager_Pod* returnValue_pod = reinterpret_cast<physx_PxTaskManager_Pod*>(returnValue);
return returnValue_pod;
}

void PxBaseTask_setContextId_mut(physx_PxBaseTask_Pod* self__pod, uint64_t id) {
physx::PxBaseTask* self_ = reinterpret_cast<physx::PxBaseTask*>(self__pod);
self_->setContextId(id);
}

uint64_t PxBaseTask_getContextId(physx_PxBaseTask_Pod const* self__pod) {
physx::PxBaseTask const* self_ = reinterpret_cast<physx::PxBaseTask const*>(self__pod);
uint64_t returnValue = self_->getContextId();
return returnValue;
}

void PxTask_release_mut(physx_PxTask_Pod* self__pod) {
physx::PxTask* self_ = reinterpret_cast<physx::PxTask*>(self__pod);
self_->release();
}

void PxTask_finishBefore_mut(physx_PxTask_Pod* self__pod, uint32_t taskID) {
physx::PxTask* self_ = reinterpret_cast<physx::PxTask*>(self__pod);
self_->finishBefore(taskID);
}

void PxTask_startAfter_mut(physx_PxTask_Pod* self__pod, uint32_t taskID) {
physx::PxTask* self_ = reinterpret_cast<physx::PxTask*>(self__pod);
self_->startAfter(taskID);
}

void PxTask_addReference_mut(physx_PxTask_Pod* self__pod) {
physx::PxTask* self_ = reinterpret_cast<physx::PxTask*>(self__pod);
self_->addReference();
}

void PxTask_removeReference_mut(physx_PxTask_Pod* self__pod) {
physx::PxTask* self_ = reinterpret_cast<physx::PxTask*>(self__pod);
self_->removeReference();
}

int32_t PxTask_getReference(physx_PxTask_Pod const* self__pod) {
physx::PxTask const* self_ = reinterpret_cast<physx::PxTask const*>(self__pod);
int32_t returnValue = self_->getReference();
return returnValue;
}

uint32_t PxTask_getTaskID(physx_PxTask_Pod const* self__pod) {
physx::PxTask const* self_ = reinterpret_cast<physx::PxTask const*>(self__pod);
uint32_t returnValue = self_->getTaskID();
return returnValue;
}

void PxTask_submitted_mut(physx_PxTask_Pod* self__pod) {
physx::PxTask* self_ = reinterpret_cast<physx::PxTask*>(self__pod);
self_->submitted();
}

void PxLightCpuTask_setContinuation_mut(physx_PxLightCpuTask_Pod* self__pod, physx_PxTaskManager_Pod* tm_pod, physx_PxBaseTask_Pod* c_pod) {
physx::PxLightCpuTask* self_ = reinterpret_cast<physx::PxLightCpuTask*>(self__pod);
physx::PxTaskManager& tm = reinterpret_cast<physx::PxTaskManager&>(*tm_pod);
physx::PxBaseTask* c = reinterpret_cast<physx::PxBaseTask*>(c_pod);
self_->setContinuation(tm, c);
}

void PxLightCpuTask_setContinuation_mut_1(physx_PxLightCpuTask_Pod* self__pod, physx_PxBaseTask_Pod* c_pod) {
physx::PxLightCpuTask* self_ = reinterpret_cast<physx::PxLightCpuTask*>(self__pod);
physx::PxBaseTask* c = reinterpret_cast<physx::PxBaseTask*>(c_pod);
self_->setContinuation(c);
}

physx_PxBaseTask_Pod* PxLightCpuTask_getContinuation(physx_PxLightCpuTask_Pod const* self__pod) {
physx::PxLightCpuTask const* self_ = reinterpret_cast<physx::PxLightCpuTask const*>(self__pod);
physx::PxBaseTask* returnValue = self_->getContinuation();
physx_PxBaseTask_Pod* returnValue_pod = reinterpret_cast<physx_PxBaseTask_Pod*>(returnValue);
return returnValue_pod;
}

void PxLightCpuTask_removeReference_mut(physx_PxLightCpuTask_Pod* self__pod) {
physx::PxLightCpuTask* self_ = reinterpret_cast<physx::PxLightCpuTask*>(self__pod);
self_->removeReference();
}

int32_t PxLightCpuTask_getReference(physx_PxLightCpuTask_Pod const* self__pod) {
physx::PxLightCpuTask const* self_ = reinterpret_cast<physx::PxLightCpuTask const*>(self__pod);
int32_t returnValue = self_->getReference();
return returnValue;
}

void PxLightCpuTask_addReference_mut(physx_PxLightCpuTask_Pod* self__pod) {
physx::PxLightCpuTask* self_ = reinterpret_cast<physx::PxLightCpuTask*>(self__pod);
self_->addReference();
}

void PxLightCpuTask_release_mut(physx_PxLightCpuTask_Pod* self__pod) {
physx::PxLightCpuTask* self_ = reinterpret_cast<physx::PxLightCpuTask*>(self__pod);
self_->release();
}

int PxGeometry_getType(physx_PxGeometry_Pod const* self__pod) {
physx::PxGeometry const* self_ = reinterpret_cast<physx::PxGeometry const*>(self__pod);
PxGeometryType::Enum returnValue = self_->getType();
int returnValue_pod = (int)returnValue;
return returnValue_pod;
}

physx_PxBoxGeometry_Pod PxBoxGeometry_new() {
physx::PxBoxGeometry returnValue;
physx_PxBoxGeometry_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxBoxGeometry_Pod PxBoxGeometry_new_1(float hx, float hy, float hz) {
physx::PxBoxGeometry returnValue(hx, hy, hz);
physx_PxBoxGeometry_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxBoxGeometry_Pod PxBoxGeometry_new_2(physx_PxVec3_Pod halfExtents__pod) {
physx::PxVec3 halfExtents_;
memcpy(&halfExtents_, &halfExtents__pod, sizeof(halfExtents_));
physx::PxBoxGeometry returnValue(halfExtents_);
physx_PxBoxGeometry_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxBoxGeometry_isValid(physx_PxBoxGeometry_Pod const* self__pod) {
physx::PxBoxGeometry const* self_ = reinterpret_cast<physx::PxBoxGeometry const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

bool PxBoxGeometry_isValid_1(physx_PxBoxGeometry_Pod const* self__pod) {
physx::PxBoxGeometry const* self_ = reinterpret_cast<physx::PxBoxGeometry const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

uint32_t PxBVHStructure_raycast(physx_PxBVHStructure_Pod const* self__pod, physx_PxVec3_Pod const* origin_pod, physx_PxVec3_Pod const* unitDir_pod, float maxDist, uint32_t maxHits, uint32_t* rayHits) {
physx::PxBVHStructure const* self_ = reinterpret_cast<physx::PxBVHStructure const*>(self__pod);
physx::PxVec3 const& origin = reinterpret_cast<physx::PxVec3 const&>(*origin_pod);
physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
uint32_t returnValue = self_->raycast(origin, unitDir, maxDist, maxHits, rayHits);
return returnValue;
}

uint32_t PxBVHStructure_sweep(physx_PxBVHStructure_Pod const* self__pod, physx_PxBounds3_Pod const* aabb_pod, physx_PxVec3_Pod const* unitDir_pod, float maxDist, uint32_t maxHits, uint32_t* sweepHits) {
physx::PxBVHStructure const* self_ = reinterpret_cast<physx::PxBVHStructure const*>(self__pod);
physx::PxBounds3 const& aabb = reinterpret_cast<physx::PxBounds3 const&>(*aabb_pod);
physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
uint32_t returnValue = self_->sweep(aabb, unitDir, maxDist, maxHits, sweepHits);
return returnValue;
}

uint32_t PxBVHStructure_overlap(physx_PxBVHStructure_Pod const* self__pod, physx_PxBounds3_Pod const* aabb_pod, uint32_t maxHits, uint32_t* overlapHits) {
physx::PxBVHStructure const* self_ = reinterpret_cast<physx::PxBVHStructure const*>(self__pod);
physx::PxBounds3 const& aabb = reinterpret_cast<physx::PxBounds3 const&>(*aabb_pod);
uint32_t returnValue = self_->overlap(aabb, maxHits, overlapHits);
return returnValue;
}

physx_PxBounds3_Pod const* PxBVHStructure_getBounds(physx_PxBVHStructure_Pod const* self__pod) {
physx::PxBVHStructure const* self_ = reinterpret_cast<physx::PxBVHStructure const*>(self__pod);
physx::PxBounds3 const* returnValue = self_->getBounds();
physx_PxBounds3_Pod const* returnValue_pod = reinterpret_cast<physx_PxBounds3_Pod const*>(returnValue);
return returnValue_pod;
}

uint32_t PxBVHStructure_getNbBounds(physx_PxBVHStructure_Pod const* self__pod) {
physx::PxBVHStructure const* self_ = reinterpret_cast<physx::PxBVHStructure const*>(self__pod);
uint32_t returnValue = self_->getNbBounds();
return returnValue;
}

char const* PxBVHStructure_getConcreteTypeName(physx_PxBVHStructure_Pod const* self__pod) {
physx::PxBVHStructure const* self_ = reinterpret_cast<physx::PxBVHStructure const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

physx_PxCapsuleGeometry_Pod PxCapsuleGeometry_new() {
physx::PxCapsuleGeometry returnValue;
physx_PxCapsuleGeometry_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxCapsuleGeometry_Pod PxCapsuleGeometry_new_1(float radius_, float halfHeight_) {
physx::PxCapsuleGeometry returnValue(radius_, halfHeight_);
physx_PxCapsuleGeometry_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxCapsuleGeometry_isValid(physx_PxCapsuleGeometry_Pod const* self__pod) {
physx::PxCapsuleGeometry const* self_ = reinterpret_cast<physx::PxCapsuleGeometry const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

bool PxCapsuleGeometry_isValid_1(physx_PxCapsuleGeometry_Pod const* self__pod) {
physx::PxCapsuleGeometry const* self_ = reinterpret_cast<physx::PxCapsuleGeometry const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

physx_PxTransform_Pod phys_PxTransformFromSegment(physx_PxVec3_Pod const* p0_pod, physx_PxVec3_Pod const* p1_pod, float* halfHeight) {
physx::PxVec3 const& p0 = reinterpret_cast<physx::PxVec3 const&>(*p0_pod);
physx::PxVec3 const& p1 = reinterpret_cast<physx::PxVec3 const&>(*p1_pod);
physx::PxTransform returnValue = PxTransformFromSegment(p0, p1, halfHeight);
physx_PxTransform_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

uint32_t PxConvexMesh_getNbVertices(physx_PxConvexMesh_Pod const* self__pod) {
physx::PxConvexMesh const* self_ = reinterpret_cast<physx::PxConvexMesh const*>(self__pod);
uint32_t returnValue = self_->getNbVertices();
return returnValue;
}

physx_PxVec3_Pod const* PxConvexMesh_getVertices(physx_PxConvexMesh_Pod const* self__pod) {
physx::PxConvexMesh const* self_ = reinterpret_cast<physx::PxConvexMesh const*>(self__pod);
physx::PxVec3 const* returnValue = self_->getVertices();
physx_PxVec3_Pod const* returnValue_pod = reinterpret_cast<physx_PxVec3_Pod const*>(returnValue);
return returnValue_pod;
}

unsigned char const* PxConvexMesh_getIndexBuffer(physx_PxConvexMesh_Pod const* self__pod) {
physx::PxConvexMesh const* self_ = reinterpret_cast<physx::PxConvexMesh const*>(self__pod);
unsigned char const* returnValue = self_->getIndexBuffer();
return returnValue;
}

uint32_t PxConvexMesh_getNbPolygons(physx_PxConvexMesh_Pod const* self__pod) {
physx::PxConvexMesh const* self_ = reinterpret_cast<physx::PxConvexMesh const*>(self__pod);
uint32_t returnValue = self_->getNbPolygons();
return returnValue;
}

bool PxConvexMesh_getPolygonData(physx_PxConvexMesh_Pod const* self__pod, uint32_t index, physx_PxHullPolygon_Pod* data_pod) {
physx::PxConvexMesh const* self_ = reinterpret_cast<physx::PxConvexMesh const*>(self__pod);
physx::PxHullPolygon& data = reinterpret_cast<physx::PxHullPolygon&>(*data_pod);
bool returnValue = self_->getPolygonData(index, data);
return returnValue;
}

void PxConvexMesh_release_mut(physx_PxConvexMesh_Pod* self__pod) {
physx::PxConvexMesh* self_ = reinterpret_cast<physx::PxConvexMesh*>(self__pod);
self_->release();
}

uint32_t PxConvexMesh_getReferenceCount(physx_PxConvexMesh_Pod const* self__pod) {
physx::PxConvexMesh const* self_ = reinterpret_cast<physx::PxConvexMesh const*>(self__pod);
uint32_t returnValue = self_->getReferenceCount();
return returnValue;
}

void PxConvexMesh_acquireReference_mut(physx_PxConvexMesh_Pod* self__pod) {
physx::PxConvexMesh* self_ = reinterpret_cast<physx::PxConvexMesh*>(self__pod);
self_->acquireReference();
}

void PxConvexMesh_getMassInformation(physx_PxConvexMesh_Pod const* self__pod, float* mass_pod, physx_PxMat33_Pod* localInertia_pod, physx_PxVec3_Pod* localCenterOfMass_pod) {
physx::PxConvexMesh const* self_ = reinterpret_cast<physx::PxConvexMesh const*>(self__pod);
float& mass = *mass_pod;
physx::PxMat33& localInertia = reinterpret_cast<physx::PxMat33&>(*localInertia_pod);
physx::PxVec3& localCenterOfMass = reinterpret_cast<physx::PxVec3&>(*localCenterOfMass_pod);
self_->getMassInformation(mass, localInertia, localCenterOfMass);
}

physx_PxBounds3_Pod PxConvexMesh_getLocalBounds(physx_PxConvexMesh_Pod const* self__pod) {
physx::PxConvexMesh const* self_ = reinterpret_cast<physx::PxConvexMesh const*>(self__pod);
physx::PxBounds3 returnValue = self_->getLocalBounds();
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

char const* PxConvexMesh_getConcreteTypeName(physx_PxConvexMesh_Pod const* self__pod) {
physx::PxConvexMesh const* self_ = reinterpret_cast<physx::PxConvexMesh const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

bool PxConvexMesh_isGpuCompatible(physx_PxConvexMesh_Pod const* self__pod) {
physx::PxConvexMesh const* self_ = reinterpret_cast<physx::PxConvexMesh const*>(self__pod);
bool returnValue = self_->isGpuCompatible();
return returnValue;
}

physx_PxMeshScale_Pod PxMeshScale_new() {
physx::PxMeshScale returnValue;
physx_PxMeshScale_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMeshScale_Pod PxMeshScale_new_1(float r) {
physx::PxMeshScale returnValue(r);
physx_PxMeshScale_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMeshScale_Pod PxMeshScale_new_2(physx_PxVec3_Pod const* s_pod) {
physx::PxVec3 const& s = reinterpret_cast<physx::PxVec3 const&>(*s_pod);
physx::PxMeshScale returnValue(s);
physx_PxMeshScale_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMeshScale_Pod PxMeshScale_new_3(physx_PxVec3_Pod const* s_pod, physx_PxQuat_Pod const* r_pod) {
physx::PxVec3 const& s = reinterpret_cast<physx::PxVec3 const&>(*s_pod);
physx::PxQuat const& r = reinterpret_cast<physx::PxQuat const&>(*r_pod);
physx::PxMeshScale returnValue(s, r);
physx_PxMeshScale_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxMeshScale_isIdentity(physx_PxMeshScale_Pod const* self__pod) {
physx::PxMeshScale const* self_ = reinterpret_cast<physx::PxMeshScale const*>(self__pod);
bool returnValue = self_->isIdentity();
return returnValue;
}

physx_PxMeshScale_Pod PxMeshScale_getInverse(physx_PxMeshScale_Pod const* self__pod) {
physx::PxMeshScale const* self_ = reinterpret_cast<physx::PxMeshScale const*>(self__pod);
physx::PxMeshScale returnValue = self_->getInverse();
physx_PxMeshScale_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMat33_Pod PxMeshScale_toMat33(physx_PxMeshScale_Pod const* self__pod) {
physx::PxMeshScale const* self_ = reinterpret_cast<physx::PxMeshScale const*>(self__pod);
physx::PxMat33 returnValue = self_->toMat33();
physx_PxMat33_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxMeshScale_hasNegativeDeterminant(physx_PxMeshScale_Pod const* self__pod) {
physx::PxMeshScale const* self_ = reinterpret_cast<physx::PxMeshScale const*>(self__pod);
bool returnValue = self_->hasNegativeDeterminant();
return returnValue;
}

physx_PxVec3_Pod PxMeshScale_transform(physx_PxMeshScale_Pod const* self__pod, physx_PxVec3_Pod const* v_pod) {
physx::PxMeshScale const* self_ = reinterpret_cast<physx::PxMeshScale const*>(self__pod);
physx::PxVec3 const& v = reinterpret_cast<physx::PxVec3 const&>(*v_pod);
physx::PxVec3 returnValue = self_->transform(v);
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxMeshScale_isValidForTriangleMesh(physx_PxMeshScale_Pod const* self__pod) {
physx::PxMeshScale const* self_ = reinterpret_cast<physx::PxMeshScale const*>(self__pod);
bool returnValue = self_->isValidForTriangleMesh();
return returnValue;
}

bool PxMeshScale_isValidForConvexMesh(physx_PxMeshScale_Pod const* self__pod) {
physx::PxMeshScale const* self_ = reinterpret_cast<physx::PxMeshScale const*>(self__pod);
bool returnValue = self_->isValidForConvexMesh();
return returnValue;
}

physx_PxConvexMeshGeometry_Pod PxConvexMeshGeometry_new() {
physx::PxConvexMeshGeometry returnValue;
physx_PxConvexMeshGeometry_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxConvexMeshGeometry_Pod PxConvexMeshGeometry_new_1(physx_PxConvexMesh_Pod* mesh_pod, physx_PxMeshScale_Pod const* scaling_pod, physx_PxConvexMeshGeometryFlags_Pod flags_pod) {
physx::PxConvexMesh* mesh = reinterpret_cast<physx::PxConvexMesh*>(mesh_pod);
physx::PxMeshScale const& scaling = reinterpret_cast<physx::PxMeshScale const&>(*scaling_pod);
physx::PxConvexMeshGeometryFlags flags;
memcpy(&flags, &flags_pod, sizeof(flags));
physx::PxConvexMeshGeometry returnValue(mesh, scaling, flags);
physx_PxConvexMeshGeometry_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxConvexMeshGeometry_isValid(physx_PxConvexMeshGeometry_Pod const* self__pod) {
physx::PxConvexMeshGeometry const* self_ = reinterpret_cast<physx::PxConvexMeshGeometry const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

bool PxConvexMeshGeometry_isValid_1(physx_PxConvexMeshGeometry_Pod const* self__pod) {
physx::PxConvexMeshGeometry const* self_ = reinterpret_cast<physx::PxConvexMeshGeometry const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

physx_PxSphereGeometry_Pod PxSphereGeometry_new() {
physx::PxSphereGeometry returnValue;
physx_PxSphereGeometry_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxSphereGeometry_Pod PxSphereGeometry_new_1(float ir) {
physx::PxSphereGeometry returnValue(ir);
physx_PxSphereGeometry_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxSphereGeometry_isValid(physx_PxSphereGeometry_Pod const* self__pod) {
physx::PxSphereGeometry const* self_ = reinterpret_cast<physx::PxSphereGeometry const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

bool PxSphereGeometry_isValid_1(physx_PxSphereGeometry_Pod const* self__pod) {
physx::PxSphereGeometry const* self_ = reinterpret_cast<physx::PxSphereGeometry const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

physx_PxPlaneGeometry_Pod PxPlaneGeometry_new() {
physx::PxPlaneGeometry returnValue;
physx_PxPlaneGeometry_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxPlaneGeometry_isValid(physx_PxPlaneGeometry_Pod const* self__pod) {
physx::PxPlaneGeometry const* self_ = reinterpret_cast<physx::PxPlaneGeometry const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

bool PxPlaneGeometry_isValid_1(physx_PxPlaneGeometry_Pod const* self__pod) {
physx::PxPlaneGeometry const* self_ = reinterpret_cast<physx::PxPlaneGeometry const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

physx_PxTransform_Pod phys_PxTransformFromPlaneEquation(physx_PxPlane_Pod const* plane_pod) {
physx::PxPlane const& plane = reinterpret_cast<physx::PxPlane const&>(*plane_pod);
physx::PxTransform returnValue = PxTransformFromPlaneEquation(plane);
physx_PxTransform_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxPlane_Pod phys_PxPlaneEquationFromTransform(physx_PxTransform_Pod const* transform_pod) {
physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
physx::PxPlane returnValue = PxPlaneEquationFromTransform(transform);
physx_PxPlane_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxTriangleMeshGeometry_Pod PxTriangleMeshGeometry_new() {
physx::PxTriangleMeshGeometry returnValue;
physx_PxTriangleMeshGeometry_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxTriangleMeshGeometry_Pod PxTriangleMeshGeometry_new_1(physx_PxTriangleMesh_Pod* mesh_pod, physx_PxMeshScale_Pod const* scaling_pod, physx_PxMeshGeometryFlags_Pod flags_pod) {
physx::PxTriangleMesh* mesh = reinterpret_cast<physx::PxTriangleMesh*>(mesh_pod);
physx::PxMeshScale const& scaling = reinterpret_cast<physx::PxMeshScale const&>(*scaling_pod);
physx::PxMeshGeometryFlags flags;
memcpy(&flags, &flags_pod, sizeof(flags));
physx::PxTriangleMeshGeometry returnValue(mesh, scaling, flags);
physx_PxTriangleMeshGeometry_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxTriangleMeshGeometry_isValid(physx_PxTriangleMeshGeometry_Pod const* self__pod) {
physx::PxTriangleMeshGeometry const* self_ = reinterpret_cast<physx::PxTriangleMeshGeometry const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

bool PxTriangleMeshGeometry_isValid_1(physx_PxTriangleMeshGeometry_Pod const* self__pod) {
physx::PxTriangleMeshGeometry const* self_ = reinterpret_cast<physx::PxTriangleMeshGeometry const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

physx_PxHeightFieldGeometry_Pod PxHeightFieldGeometry_new() {
physx::PxHeightFieldGeometry returnValue;
physx_PxHeightFieldGeometry_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxHeightFieldGeometry_Pod PxHeightFieldGeometry_new_1(physx_PxHeightField_Pod* hf_pod, physx_PxMeshGeometryFlags_Pod flags_pod, float heightScale_, float rowScale_, float columnScale_) {
physx::PxHeightField* hf = reinterpret_cast<physx::PxHeightField*>(hf_pod);
physx::PxMeshGeometryFlags flags;
memcpy(&flags, &flags_pod, sizeof(flags));
physx::PxHeightFieldGeometry returnValue(hf, flags, heightScale_, rowScale_, columnScale_);
physx_PxHeightFieldGeometry_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxHeightFieldGeometry_isValid(physx_PxHeightFieldGeometry_Pod const* self__pod) {
physx::PxHeightFieldGeometry const* self_ = reinterpret_cast<physx::PxHeightFieldGeometry const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

bool PxHeightFieldGeometry_isValid_1(physx_PxHeightFieldGeometry_Pod const* self__pod) {
physx::PxHeightFieldGeometry const* self_ = reinterpret_cast<physx::PxHeightFieldGeometry const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

int PxGeometryHolder_getType(physx_PxGeometryHolder_Pod const* self__pod) {
physx::PxGeometryHolder const* self_ = reinterpret_cast<physx::PxGeometryHolder const*>(self__pod);
PxGeometryType::Enum returnValue = self_->getType();
int returnValue_pod = (int)returnValue;
return returnValue_pod;
}

physx_PxGeometry_Pod* PxGeometryHolder_any_mut(physx_PxGeometryHolder_Pod* self__pod) {
physx::PxGeometryHolder* self_ = reinterpret_cast<physx::PxGeometryHolder*>(self__pod);
physx::PxGeometry& returnValue = self_->any();
physx_PxGeometry_Pod* returnValue_pod = reinterpret_cast<physx_PxGeometry_Pod*>(&returnValue);
return returnValue_pod;
}

physx_PxGeometry_Pod const* PxGeometryHolder_any(physx_PxGeometryHolder_Pod const* self__pod) {
physx::PxGeometryHolder const* self_ = reinterpret_cast<physx::PxGeometryHolder const*>(self__pod);
physx::PxGeometry const& returnValue = self_->any();
physx_PxGeometry_Pod const* returnValue_pod = reinterpret_cast<physx_PxGeometry_Pod const*>(&returnValue);
return returnValue_pod;
}

physx_PxSphereGeometry_Pod* PxGeometryHolder_sphere_mut(physx_PxGeometryHolder_Pod* self__pod) {
physx::PxGeometryHolder* self_ = reinterpret_cast<physx::PxGeometryHolder*>(self__pod);
physx::PxSphereGeometry& returnValue = self_->sphere();
physx_PxSphereGeometry_Pod* returnValue_pod = reinterpret_cast<physx_PxSphereGeometry_Pod*>(&returnValue);
return returnValue_pod;
}

physx_PxSphereGeometry_Pod const* PxGeometryHolder_sphere(physx_PxGeometryHolder_Pod const* self__pod) {
physx::PxGeometryHolder const* self_ = reinterpret_cast<physx::PxGeometryHolder const*>(self__pod);
physx::PxSphereGeometry const& returnValue = self_->sphere();
physx_PxSphereGeometry_Pod const* returnValue_pod = reinterpret_cast<physx_PxSphereGeometry_Pod const*>(&returnValue);
return returnValue_pod;
}

physx_PxPlaneGeometry_Pod* PxGeometryHolder_plane_mut(physx_PxGeometryHolder_Pod* self__pod) {
physx::PxGeometryHolder* self_ = reinterpret_cast<physx::PxGeometryHolder*>(self__pod);
physx::PxPlaneGeometry& returnValue = self_->plane();
physx_PxPlaneGeometry_Pod* returnValue_pod = reinterpret_cast<physx_PxPlaneGeometry_Pod*>(&returnValue);
return returnValue_pod;
}

physx_PxPlaneGeometry_Pod const* PxGeometryHolder_plane(physx_PxGeometryHolder_Pod const* self__pod) {
physx::PxGeometryHolder const* self_ = reinterpret_cast<physx::PxGeometryHolder const*>(self__pod);
physx::PxPlaneGeometry const& returnValue = self_->plane();
physx_PxPlaneGeometry_Pod const* returnValue_pod = reinterpret_cast<physx_PxPlaneGeometry_Pod const*>(&returnValue);
return returnValue_pod;
}

physx_PxCapsuleGeometry_Pod* PxGeometryHolder_capsule_mut(physx_PxGeometryHolder_Pod* self__pod) {
physx::PxGeometryHolder* self_ = reinterpret_cast<physx::PxGeometryHolder*>(self__pod);
physx::PxCapsuleGeometry& returnValue = self_->capsule();
physx_PxCapsuleGeometry_Pod* returnValue_pod = reinterpret_cast<physx_PxCapsuleGeometry_Pod*>(&returnValue);
return returnValue_pod;
}

physx_PxCapsuleGeometry_Pod const* PxGeometryHolder_capsule(physx_PxGeometryHolder_Pod const* self__pod) {
physx::PxGeometryHolder const* self_ = reinterpret_cast<physx::PxGeometryHolder const*>(self__pod);
physx::PxCapsuleGeometry const& returnValue = self_->capsule();
physx_PxCapsuleGeometry_Pod const* returnValue_pod = reinterpret_cast<physx_PxCapsuleGeometry_Pod const*>(&returnValue);
return returnValue_pod;
}

physx_PxBoxGeometry_Pod* PxGeometryHolder_box_mut(physx_PxGeometryHolder_Pod* self__pod) {
physx::PxGeometryHolder* self_ = reinterpret_cast<physx::PxGeometryHolder*>(self__pod);
physx::PxBoxGeometry& returnValue = self_->box();
physx_PxBoxGeometry_Pod* returnValue_pod = reinterpret_cast<physx_PxBoxGeometry_Pod*>(&returnValue);
return returnValue_pod;
}

physx_PxBoxGeometry_Pod const* PxGeometryHolder_box(physx_PxGeometryHolder_Pod const* self__pod) {
physx::PxGeometryHolder const* self_ = reinterpret_cast<physx::PxGeometryHolder const*>(self__pod);
physx::PxBoxGeometry const& returnValue = self_->box();
physx_PxBoxGeometry_Pod const* returnValue_pod = reinterpret_cast<physx_PxBoxGeometry_Pod const*>(&returnValue);
return returnValue_pod;
}

physx_PxConvexMeshGeometry_Pod* PxGeometryHolder_convexMesh_mut(physx_PxGeometryHolder_Pod* self__pod) {
physx::PxGeometryHolder* self_ = reinterpret_cast<physx::PxGeometryHolder*>(self__pod);
physx::PxConvexMeshGeometry& returnValue = self_->convexMesh();
physx_PxConvexMeshGeometry_Pod* returnValue_pod = reinterpret_cast<physx_PxConvexMeshGeometry_Pod*>(&returnValue);
return returnValue_pod;
}

physx_PxConvexMeshGeometry_Pod const* PxGeometryHolder_convexMesh(physx_PxGeometryHolder_Pod const* self__pod) {
physx::PxGeometryHolder const* self_ = reinterpret_cast<physx::PxGeometryHolder const*>(self__pod);
physx::PxConvexMeshGeometry const& returnValue = self_->convexMesh();
physx_PxConvexMeshGeometry_Pod const* returnValue_pod = reinterpret_cast<physx_PxConvexMeshGeometry_Pod const*>(&returnValue);
return returnValue_pod;
}

physx_PxTriangleMeshGeometry_Pod* PxGeometryHolder_triangleMesh_mut(physx_PxGeometryHolder_Pod* self__pod) {
physx::PxGeometryHolder* self_ = reinterpret_cast<physx::PxGeometryHolder*>(self__pod);
physx::PxTriangleMeshGeometry& returnValue = self_->triangleMesh();
physx_PxTriangleMeshGeometry_Pod* returnValue_pod = reinterpret_cast<physx_PxTriangleMeshGeometry_Pod*>(&returnValue);
return returnValue_pod;
}

physx_PxTriangleMeshGeometry_Pod const* PxGeometryHolder_triangleMesh(physx_PxGeometryHolder_Pod const* self__pod) {
physx::PxGeometryHolder const* self_ = reinterpret_cast<physx::PxGeometryHolder const*>(self__pod);
physx::PxTriangleMeshGeometry const& returnValue = self_->triangleMesh();
physx_PxTriangleMeshGeometry_Pod const* returnValue_pod = reinterpret_cast<physx_PxTriangleMeshGeometry_Pod const*>(&returnValue);
return returnValue_pod;
}

physx_PxHeightFieldGeometry_Pod* PxGeometryHolder_heightField_mut(physx_PxGeometryHolder_Pod* self__pod) {
physx::PxGeometryHolder* self_ = reinterpret_cast<physx::PxGeometryHolder*>(self__pod);
physx::PxHeightFieldGeometry& returnValue = self_->heightField();
physx_PxHeightFieldGeometry_Pod* returnValue_pod = reinterpret_cast<physx_PxHeightFieldGeometry_Pod*>(&returnValue);
return returnValue_pod;
}

physx_PxHeightFieldGeometry_Pod const* PxGeometryHolder_heightField(physx_PxGeometryHolder_Pod const* self__pod) {
physx::PxGeometryHolder const* self_ = reinterpret_cast<physx::PxGeometryHolder const*>(self__pod);
physx::PxHeightFieldGeometry const& returnValue = self_->heightField();
physx_PxHeightFieldGeometry_Pod const* returnValue_pod = reinterpret_cast<physx_PxHeightFieldGeometry_Pod const*>(&returnValue);
return returnValue_pod;
}

void PxGeometryHolder_storeAny_mut(physx_PxGeometryHolder_Pod* self__pod, physx_PxGeometry_Pod const* geometry_pod) {
physx::PxGeometryHolder* self_ = reinterpret_cast<physx::PxGeometryHolder*>(self__pod);
physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
self_->storeAny(geometry);
}

physx_PxGeometryHolder_Pod PxGeometryHolder_new() {
physx::PxGeometryHolder returnValue;
physx_PxGeometryHolder_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxGeometryHolder_Pod PxGeometryHolder_new_1(physx_PxGeometry_Pod const* geometry_pod) {
physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
physx::PxGeometryHolder returnValue(geometry);
physx_PxGeometryHolder_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxActorShape_Pod PxActorShape_new() {
physx::PxActorShape returnValue;
physx_PxActorShape_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxActorShape_Pod PxActorShape_new_1(physx_PxRigidActor_Pod* a_pod, physx_PxShape_Pod* s_pod) {
physx::PxRigidActor* a = reinterpret_cast<physx::PxRigidActor*>(a_pod);
physx::PxShape* s = reinterpret_cast<physx::PxShape*>(s_pod);
physx::PxActorShape returnValue(a, s);
physx_PxActorShape_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxQueryHit_Pod PxQueryHit_new() {
physx::PxQueryHit returnValue;
physx_PxQueryHit_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxLocationHit_Pod PxLocationHit_new() {
physx::PxLocationHit returnValue;
physx_PxLocationHit_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxLocationHit_hadInitialOverlap(physx_PxLocationHit_Pod const* self__pod) {
physx::PxLocationHit const* self_ = reinterpret_cast<physx::PxLocationHit const*>(self__pod);
bool returnValue = self_->hadInitialOverlap();
return returnValue;
}

physx_PxRaycastHit_Pod PxRaycastHit_new() {
physx::PxRaycastHit returnValue;
physx_PxRaycastHit_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxSweepHit_Pod PxSweepHit_new() {
physx::PxSweepHit returnValue;
physx_PxSweepHit_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxGeometryQuery_sweep_mut(physx_PxVec3_Pod const* unitDir_pod, float maxDist, physx_PxGeometry_Pod const* geom0_pod, physx_PxTransform_Pod const* pose0_pod, physx_PxGeometry_Pod const* geom1_pod, physx_PxTransform_Pod const* pose1_pod, physx_PxSweepHit_Pod* sweepHit_pod, physx_PxHitFlags_Pod hitFlags_pod, float inflation) {
physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
physx::PxGeometry const& geom0 = reinterpret_cast<physx::PxGeometry const&>(*geom0_pod);
physx::PxTransform const& pose0 = reinterpret_cast<physx::PxTransform const&>(*pose0_pod);
physx::PxGeometry const& geom1 = reinterpret_cast<physx::PxGeometry const&>(*geom1_pod);
physx::PxTransform const& pose1 = reinterpret_cast<physx::PxTransform const&>(*pose1_pod);
physx::PxSweepHit& sweepHit = reinterpret_cast<physx::PxSweepHit&>(*sweepHit_pod);
physx::PxHitFlags hitFlags;
memcpy(&hitFlags, &hitFlags_pod, sizeof(hitFlags));
bool returnValue = PxGeometryQuery::sweep(unitDir, maxDist, geom0, pose0, geom1, pose1, sweepHit, hitFlags, inflation);
return returnValue;
}

bool PxGeometryQuery_overlap_mut(physx_PxGeometry_Pod const* geom0_pod, physx_PxTransform_Pod const* pose0_pod, physx_PxGeometry_Pod const* geom1_pod, physx_PxTransform_Pod const* pose1_pod) {
physx::PxGeometry const& geom0 = reinterpret_cast<physx::PxGeometry const&>(*geom0_pod);
physx::PxTransform const& pose0 = reinterpret_cast<physx::PxTransform const&>(*pose0_pod);
physx::PxGeometry const& geom1 = reinterpret_cast<physx::PxGeometry const&>(*geom1_pod);
physx::PxTransform const& pose1 = reinterpret_cast<physx::PxTransform const&>(*pose1_pod);
bool returnValue = PxGeometryQuery::overlap(geom0, pose0, geom1, pose1);
return returnValue;
}

uint32_t PxGeometryQuery_raycast_mut(physx_PxVec3_Pod const* origin_pod, physx_PxVec3_Pod const* unitDir_pod, physx_PxGeometry_Pod const* geom_pod, physx_PxTransform_Pod const* pose_pod, float maxDist, physx_PxHitFlags_Pod hitFlags_pod, uint32_t maxHits, physx_PxRaycastHit_Pod* rayHits_pod) {
physx::PxVec3 const& origin = reinterpret_cast<physx::PxVec3 const&>(*origin_pod);
physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
physx::PxGeometry const& geom = reinterpret_cast<physx::PxGeometry const&>(*geom_pod);
physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
physx::PxHitFlags hitFlags;
memcpy(&hitFlags, &hitFlags_pod, sizeof(hitFlags));
physx::PxRaycastHit* rayHits = reinterpret_cast<physx::PxRaycastHit*>(rayHits_pod);
uint32_t returnValue = PxGeometryQuery::raycast(origin, unitDir, geom, pose, maxDist, hitFlags, maxHits, rayHits);
return returnValue;
}

bool PxGeometryQuery_computePenetration_mut(physx_PxVec3_Pod* direction_pod, float* depth_pod, physx_PxGeometry_Pod const* geom0_pod, physx_PxTransform_Pod const* pose0_pod, physx_PxGeometry_Pod const* geom1_pod, physx_PxTransform_Pod const* pose1_pod) {
physx::PxVec3& direction = reinterpret_cast<physx::PxVec3&>(*direction_pod);
float& depth = *depth_pod;
physx::PxGeometry const& geom0 = reinterpret_cast<physx::PxGeometry const&>(*geom0_pod);
physx::PxTransform const& pose0 = reinterpret_cast<physx::PxTransform const&>(*pose0_pod);
physx::PxGeometry const& geom1 = reinterpret_cast<physx::PxGeometry const&>(*geom1_pod);
physx::PxTransform const& pose1 = reinterpret_cast<physx::PxTransform const&>(*pose1_pod);
bool returnValue = PxGeometryQuery::computePenetration(direction, depth, geom0, pose0, geom1, pose1);
return returnValue;
}

float PxGeometryQuery_pointDistance_mut(physx_PxVec3_Pod const* point_pod, physx_PxGeometry_Pod const* geom_pod, physx_PxTransform_Pod const* pose_pod, physx_PxVec3_Pod* closestPoint_pod) {
physx::PxVec3 const& point = reinterpret_cast<physx::PxVec3 const&>(*point_pod);
physx::PxGeometry const& geom = reinterpret_cast<physx::PxGeometry const&>(*geom_pod);
physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
physx::PxVec3* closestPoint = reinterpret_cast<physx::PxVec3*>(closestPoint_pod);
float returnValue = PxGeometryQuery::pointDistance(point, geom, pose, closestPoint);
return returnValue;
}

physx_PxBounds3_Pod PxGeometryQuery_getWorldBounds_mut(physx_PxGeometry_Pod const* geom_pod, physx_PxTransform_Pod const* pose_pod, float inflation) {
physx::PxGeometry const& geom = reinterpret_cast<physx::PxGeometry const&>(*geom_pod);
physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
physx::PxBounds3 returnValue = PxGeometryQuery::getWorldBounds(geom, pose, inflation);
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxGeometryQuery_isValid_mut(physx_PxGeometry_Pod const* geom_pod) {
physx::PxGeometry const& geom = reinterpret_cast<physx::PxGeometry const&>(*geom_pod);
bool returnValue = PxGeometryQuery::isValid(geom);
return returnValue;
}

unsigned char PxHeightFieldSample_tessFlag(physx_PxHeightFieldSample_Pod const* self__pod) {
physx::PxHeightFieldSample const* self_ = reinterpret_cast<physx::PxHeightFieldSample const*>(self__pod);
unsigned char returnValue = self_->tessFlag();
return returnValue;
}

void PxHeightFieldSample_setTessFlag_mut(physx_PxHeightFieldSample_Pod* self__pod) {
physx::PxHeightFieldSample* self_ = reinterpret_cast<physx::PxHeightFieldSample*>(self__pod);
self_->setTessFlag();
}

void PxHeightFieldSample_clearTessFlag_mut(physx_PxHeightFieldSample_Pod* self__pod) {
physx::PxHeightFieldSample* self_ = reinterpret_cast<physx::PxHeightFieldSample*>(self__pod);
self_->clearTessFlag();
}

void PxHeightField_release_mut(physx_PxHeightField_Pod* self__pod) {
physx::PxHeightField* self_ = reinterpret_cast<physx::PxHeightField*>(self__pod);
self_->release();
}

uint32_t PxHeightField_saveCells(physx_PxHeightField_Pod const* self__pod, void* destBuffer, uint32_t destBufferSize) {
physx::PxHeightField const* self_ = reinterpret_cast<physx::PxHeightField const*>(self__pod);
uint32_t returnValue = self_->saveCells(destBuffer, destBufferSize);
return returnValue;
}

bool PxHeightField_modifySamples_mut(physx_PxHeightField_Pod* self__pod, int32_t startCol, int32_t startRow, physx_PxHeightFieldDesc_Pod const* subfieldDesc_pod, bool shrinkBounds) {
physx::PxHeightField* self_ = reinterpret_cast<physx::PxHeightField*>(self__pod);
physx::PxHeightFieldDesc const& subfieldDesc = reinterpret_cast<physx::PxHeightFieldDesc const&>(*subfieldDesc_pod);
bool returnValue = self_->modifySamples(startCol, startRow, subfieldDesc, shrinkBounds);
return returnValue;
}

uint32_t PxHeightField_getNbRows(physx_PxHeightField_Pod const* self__pod) {
physx::PxHeightField const* self_ = reinterpret_cast<physx::PxHeightField const*>(self__pod);
uint32_t returnValue = self_->getNbRows();
return returnValue;
}

uint32_t PxHeightField_getNbColumns(physx_PxHeightField_Pod const* self__pod) {
physx::PxHeightField const* self_ = reinterpret_cast<physx::PxHeightField const*>(self__pod);
uint32_t returnValue = self_->getNbColumns();
return returnValue;
}

unsigned int PxHeightField_getFormat(physx_PxHeightField_Pod const* self__pod) {
physx::PxHeightField const* self_ = reinterpret_cast<physx::PxHeightField const*>(self__pod);
PxHeightFieldFormat::Enum returnValue = self_->getFormat();
unsigned int returnValue_pod = (unsigned int)returnValue;
return returnValue_pod;
}

uint32_t PxHeightField_getSampleStride(physx_PxHeightField_Pod const* self__pod) {
physx::PxHeightField const* self_ = reinterpret_cast<physx::PxHeightField const*>(self__pod);
uint32_t returnValue = self_->getSampleStride();
return returnValue;
}

float PxHeightField_getConvexEdgeThreshold(physx_PxHeightField_Pod const* self__pod) {
physx::PxHeightField const* self_ = reinterpret_cast<physx::PxHeightField const*>(self__pod);
float returnValue = self_->getConvexEdgeThreshold();
return returnValue;
}

physx_PxHeightFieldFlags_Pod PxHeightField_getFlags(physx_PxHeightField_Pod const* self__pod) {
physx::PxHeightField const* self_ = reinterpret_cast<physx::PxHeightField const*>(self__pod);
physx::PxHeightFieldFlags returnValue = self_->getFlags();
physx_PxHeightFieldFlags_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

float PxHeightField_getHeight(physx_PxHeightField_Pod const* self__pod, float x, float z) {
physx::PxHeightField const* self_ = reinterpret_cast<physx::PxHeightField const*>(self__pod);
float returnValue = self_->getHeight(x, z);
return returnValue;
}

uint32_t PxHeightField_getReferenceCount(physx_PxHeightField_Pod const* self__pod) {
physx::PxHeightField const* self_ = reinterpret_cast<physx::PxHeightField const*>(self__pod);
uint32_t returnValue = self_->getReferenceCount();
return returnValue;
}

void PxHeightField_acquireReference_mut(physx_PxHeightField_Pod* self__pod) {
physx::PxHeightField* self_ = reinterpret_cast<physx::PxHeightField*>(self__pod);
self_->acquireReference();
}

uint16_t PxHeightField_getTriangleMaterialIndex(physx_PxHeightField_Pod const* self__pod, uint32_t triangleIndex) {
physx::PxHeightField const* self_ = reinterpret_cast<physx::PxHeightField const*>(self__pod);
uint16_t returnValue = self_->getTriangleMaterialIndex(triangleIndex);
return returnValue;
}

physx_PxVec3_Pod PxHeightField_getTriangleNormal(physx_PxHeightField_Pod const* self__pod, uint32_t triangleIndex) {
physx::PxHeightField const* self_ = reinterpret_cast<physx::PxHeightField const*>(self__pod);
physx::PxVec3 returnValue = self_->getTriangleNormal(triangleIndex);
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxHeightFieldSample_Pod const* PxHeightField_getSample(physx_PxHeightField_Pod const* self__pod, uint32_t row, uint32_t column) {
physx::PxHeightField const* self_ = reinterpret_cast<physx::PxHeightField const*>(self__pod);
physx::PxHeightFieldSample const& returnValue = self_->getSample(row, column);
physx_PxHeightFieldSample_Pod const* returnValue_pod = reinterpret_cast<physx_PxHeightFieldSample_Pod const*>(&returnValue);
return returnValue_pod;
}

uint32_t PxHeightField_getTimestamp(physx_PxHeightField_Pod const* self__pod) {
physx::PxHeightField const* self_ = reinterpret_cast<physx::PxHeightField const*>(self__pod);
uint32_t returnValue = self_->getTimestamp();
return returnValue;
}

char const* PxHeightField_getConcreteTypeName(physx_PxHeightField_Pod const* self__pod) {
physx::PxHeightField const* self_ = reinterpret_cast<physx::PxHeightField const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

physx_PxHeightFieldDesc_Pod PxHeightFieldDesc_new() {
physx::PxHeightFieldDesc returnValue;
physx_PxHeightFieldDesc_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxHeightFieldDesc_setToDefault_mut(physx_PxHeightFieldDesc_Pod* self__pod) {
physx::PxHeightFieldDesc* self_ = reinterpret_cast<physx::PxHeightFieldDesc*>(self__pod);
self_->setToDefault();
}

bool PxHeightFieldDesc_isValid(physx_PxHeightFieldDesc_Pod const* self__pod) {
physx::PxHeightFieldDesc const* self_ = reinterpret_cast<physx::PxHeightFieldDesc const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

physx_PxHeightFieldDesc_Pod PxHeightFieldDesc_new_1() {
physx::PxHeightFieldDesc returnValue;
physx_PxHeightFieldDesc_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxHeightFieldDesc_setToDefault_mut_1(physx_PxHeightFieldDesc_Pod* self__pod) {
physx::PxHeightFieldDesc* self_ = reinterpret_cast<physx::PxHeightFieldDesc*>(self__pod);
self_->setToDefault();
}

bool PxHeightFieldDesc_isValid_1(physx_PxHeightFieldDesc_Pod const* self__pod) {
physx::PxHeightFieldDesc const* self_ = reinterpret_cast<physx::PxHeightFieldDesc const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

void PxMeshQuery_getTriangle_mut(physx_PxTriangleMeshGeometry_Pod const* triGeom_pod, physx_PxTransform_Pod const* transform_pod, uint32_t triangleIndex, physx_PxTriangle_Pod* triangle_pod, uint32_t* vertexIndices, uint32_t* adjacencyIndices) {
physx::PxTriangleMeshGeometry const& triGeom = reinterpret_cast<physx::PxTriangleMeshGeometry const&>(*triGeom_pod);
physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
physx::PxTriangle& triangle = reinterpret_cast<physx::PxTriangle&>(*triangle_pod);
PxMeshQuery::getTriangle(triGeom, transform, triangleIndex, triangle, vertexIndices, adjacencyIndices);
}

void PxMeshQuery_getTriangle_mut_1(physx_PxHeightFieldGeometry_Pod const* hfGeom_pod, physx_PxTransform_Pod const* transform_pod, uint32_t triangleIndex, physx_PxTriangle_Pod* triangle_pod, uint32_t* vertexIndices, uint32_t* adjacencyIndices) {
physx::PxHeightFieldGeometry const& hfGeom = reinterpret_cast<physx::PxHeightFieldGeometry const&>(*hfGeom_pod);
physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
physx::PxTriangle& triangle = reinterpret_cast<physx::PxTriangle&>(*triangle_pod);
PxMeshQuery::getTriangle(hfGeom, transform, triangleIndex, triangle, vertexIndices, adjacencyIndices);
}

uint32_t PxMeshQuery_findOverlapTriangleMesh_mut(physx_PxGeometry_Pod const* geom_pod, physx_PxTransform_Pod const* geomPose_pod, physx_PxTriangleMeshGeometry_Pod const* meshGeom_pod, physx_PxTransform_Pod const* meshPose_pod, uint32_t* results, uint32_t maxResults, uint32_t startIndex, bool* overflow_pod) {
physx::PxGeometry const& geom = reinterpret_cast<physx::PxGeometry const&>(*geom_pod);
physx::PxTransform const& geomPose = reinterpret_cast<physx::PxTransform const&>(*geomPose_pod);
physx::PxTriangleMeshGeometry const& meshGeom = reinterpret_cast<physx::PxTriangleMeshGeometry const&>(*meshGeom_pod);
physx::PxTransform const& meshPose = reinterpret_cast<physx::PxTransform const&>(*meshPose_pod);
bool& overflow = *overflow_pod;
uint32_t returnValue = PxMeshQuery::findOverlapTriangleMesh(geom, geomPose, meshGeom, meshPose, results, maxResults, startIndex, overflow);
return returnValue;
}

uint32_t PxMeshQuery_findOverlapHeightField_mut(physx_PxGeometry_Pod const* geom_pod, physx_PxTransform_Pod const* geomPose_pod, physx_PxHeightFieldGeometry_Pod const* hfGeom_pod, physx_PxTransform_Pod const* hfPose_pod, uint32_t* results, uint32_t maxResults, uint32_t startIndex, bool* overflow_pod) {
physx::PxGeometry const& geom = reinterpret_cast<physx::PxGeometry const&>(*geom_pod);
physx::PxTransform const& geomPose = reinterpret_cast<physx::PxTransform const&>(*geomPose_pod);
physx::PxHeightFieldGeometry const& hfGeom = reinterpret_cast<physx::PxHeightFieldGeometry const&>(*hfGeom_pod);
physx::PxTransform const& hfPose = reinterpret_cast<physx::PxTransform const&>(*hfPose_pod);
bool& overflow = *overflow_pod;
uint32_t returnValue = PxMeshQuery::findOverlapHeightField(geom, geomPose, hfGeom, hfPose, results, maxResults, startIndex, overflow);
return returnValue;
}

bool PxMeshQuery_sweep_mut(physx_PxVec3_Pod const* unitDir_pod, float distance, physx_PxGeometry_Pod const* geom_pod, physx_PxTransform_Pod const* pose_pod, uint32_t triangleCount, physx_PxTriangle_Pod const* triangles_pod, physx_PxSweepHit_Pod* sweepHit_pod, physx_PxHitFlags_Pod hitFlags_pod, uint32_t const* cachedIndex, float inflation, bool doubleSided) {
physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
physx::PxGeometry const& geom = reinterpret_cast<physx::PxGeometry const&>(*geom_pod);
physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
physx::PxTriangle const* triangles = reinterpret_cast<physx::PxTriangle const*>(triangles_pod);
physx::PxSweepHit& sweepHit = reinterpret_cast<physx::PxSweepHit&>(*sweepHit_pod);
physx::PxHitFlags hitFlags;
memcpy(&hitFlags, &hitFlags_pod, sizeof(hitFlags));
bool returnValue = PxMeshQuery::sweep(unitDir, distance, geom, pose, triangleCount, triangles, sweepHit, hitFlags, cachedIndex, inflation, doubleSided);
return returnValue;
}

physx_PxSimpleTriangleMesh_Pod PxSimpleTriangleMesh_new() {
physx::PxSimpleTriangleMesh returnValue;
physx_PxSimpleTriangleMesh_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxSimpleTriangleMesh_setToDefault_mut(physx_PxSimpleTriangleMesh_Pod* self__pod) {
physx::PxSimpleTriangleMesh* self_ = reinterpret_cast<physx::PxSimpleTriangleMesh*>(self__pod);
self_->setToDefault();
}

bool PxSimpleTriangleMesh_isValid(physx_PxSimpleTriangleMesh_Pod const* self__pod) {
physx::PxSimpleTriangleMesh const* self_ = reinterpret_cast<physx::PxSimpleTriangleMesh const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

physx_PxSimpleTriangleMesh_Pod PxSimpleTriangleMesh_new_1() {
physx::PxSimpleTriangleMesh returnValue;
physx_PxSimpleTriangleMesh_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxSimpleTriangleMesh_setToDefault_mut_1(physx_PxSimpleTriangleMesh_Pod* self__pod) {
physx::PxSimpleTriangleMesh* self_ = reinterpret_cast<physx::PxSimpleTriangleMesh*>(self__pod);
self_->setToDefault();
}

bool PxSimpleTriangleMesh_isValid_1(physx_PxSimpleTriangleMesh_Pod const* self__pod) {
physx::PxSimpleTriangleMesh const* self_ = reinterpret_cast<physx::PxSimpleTriangleMesh const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

physx_PxTriangle_Pod* PxTriangle_new_alloc() {
auto returnValue = new physx::PxTriangle();
physx_PxTriangle_Pod* returnValue_pod = reinterpret_cast<physx_PxTriangle_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxTriangle_Pod* PxTriangle_new_alloc_1(physx_PxVec3_Pod const* p0_pod, physx_PxVec3_Pod const* p1_pod, physx_PxVec3_Pod const* p2_pod) {
physx::PxVec3 const& p0 = reinterpret_cast<physx::PxVec3 const&>(*p0_pod);
physx::PxVec3 const& p1 = reinterpret_cast<physx::PxVec3 const&>(*p1_pod);
physx::PxVec3 const& p2 = reinterpret_cast<physx::PxVec3 const&>(*p2_pod);
auto returnValue = new physx::PxTriangle(p0, p1, p2);
physx_PxTriangle_Pod* returnValue_pod = reinterpret_cast<physx_PxTriangle_Pod*>(returnValue);
return returnValue_pod;
}

void PxTriangle_delete(physx_PxTriangle_Pod* self__pod) {
physx::PxTriangle* self_ = reinterpret_cast<physx::PxTriangle*>(self__pod);
delete self_;
}

void PxTriangle_normal(physx_PxTriangle_Pod const* self__pod, physx_PxVec3_Pod* _normal_pod) {
physx::PxTriangle const* self_ = reinterpret_cast<physx::PxTriangle const*>(self__pod);
physx::PxVec3& _normal = reinterpret_cast<physx::PxVec3&>(*_normal_pod);
self_->normal(_normal);
}

void PxTriangle_denormalizedNormal(physx_PxTriangle_Pod const* self__pod, physx_PxVec3_Pod* _normal_pod) {
physx::PxTriangle const* self_ = reinterpret_cast<physx::PxTriangle const*>(self__pod);
physx::PxVec3& _normal = reinterpret_cast<physx::PxVec3&>(*_normal_pod);
self_->denormalizedNormal(_normal);
}

float PxTriangle_area(physx_PxTriangle_Pod const* self__pod) {
physx::PxTriangle const* self_ = reinterpret_cast<physx::PxTriangle const*>(self__pod);
float returnValue = self_->area();
return returnValue;
}

physx_PxVec3_Pod PxTriangle_pointFromUV(physx_PxTriangle_Pod const* self__pod, float u, float v) {
physx::PxTriangle const* self_ = reinterpret_cast<physx::PxTriangle const*>(self__pod);
physx::PxVec3 returnValue = self_->pointFromUV(u, v);
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

uint32_t PxTriangleMesh_getNbVertices(physx_PxTriangleMesh_Pod const* self__pod) {
physx::PxTriangleMesh const* self_ = reinterpret_cast<physx::PxTriangleMesh const*>(self__pod);
uint32_t returnValue = self_->getNbVertices();
return returnValue;
}

physx_PxVec3_Pod const* PxTriangleMesh_getVertices(physx_PxTriangleMesh_Pod const* self__pod) {
physx::PxTriangleMesh const* self_ = reinterpret_cast<physx::PxTriangleMesh const*>(self__pod);
physx::PxVec3 const* returnValue = self_->getVertices();
physx_PxVec3_Pod const* returnValue_pod = reinterpret_cast<physx_PxVec3_Pod const*>(returnValue);
return returnValue_pod;
}

physx_PxVec3_Pod* PxTriangleMesh_getVerticesForModification_mut(physx_PxTriangleMesh_Pod* self__pod) {
physx::PxTriangleMesh* self_ = reinterpret_cast<physx::PxTriangleMesh*>(self__pod);
physx::PxVec3* returnValue = self_->getVerticesForModification();
physx_PxVec3_Pod* returnValue_pod = reinterpret_cast<physx_PxVec3_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxBounds3_Pod PxTriangleMesh_refitBVH_mut(physx_PxTriangleMesh_Pod* self__pod) {
physx::PxTriangleMesh* self_ = reinterpret_cast<physx::PxTriangleMesh*>(self__pod);
physx::PxBounds3 returnValue = self_->refitBVH();
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

uint32_t PxTriangleMesh_getNbTriangles(physx_PxTriangleMesh_Pod const* self__pod) {
physx::PxTriangleMesh const* self_ = reinterpret_cast<physx::PxTriangleMesh const*>(self__pod);
uint32_t returnValue = self_->getNbTriangles();
return returnValue;
}

void const* PxTriangleMesh_getTriangles(physx_PxTriangleMesh_Pod const* self__pod) {
physx::PxTriangleMesh const* self_ = reinterpret_cast<physx::PxTriangleMesh const*>(self__pod);
void const* returnValue = self_->getTriangles();
return returnValue;
}

physx_PxTriangleMeshFlags_Pod PxTriangleMesh_getTriangleMeshFlags(physx_PxTriangleMesh_Pod const* self__pod) {
physx::PxTriangleMesh const* self_ = reinterpret_cast<physx::PxTriangleMesh const*>(self__pod);
physx::PxTriangleMeshFlags returnValue = self_->getTriangleMeshFlags();
physx_PxTriangleMeshFlags_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

uint32_t const* PxTriangleMesh_getTrianglesRemap(physx_PxTriangleMesh_Pod const* self__pod) {
physx::PxTriangleMesh const* self_ = reinterpret_cast<physx::PxTriangleMesh const*>(self__pod);
uint32_t const* returnValue = self_->getTrianglesRemap();
return returnValue;
}

void PxTriangleMesh_release_mut(physx_PxTriangleMesh_Pod* self__pod) {
physx::PxTriangleMesh* self_ = reinterpret_cast<physx::PxTriangleMesh*>(self__pod);
self_->release();
}

uint16_t PxTriangleMesh_getTriangleMaterialIndex(physx_PxTriangleMesh_Pod const* self__pod, uint32_t triangleIndex) {
physx::PxTriangleMesh const* self_ = reinterpret_cast<physx::PxTriangleMesh const*>(self__pod);
uint16_t returnValue = self_->getTriangleMaterialIndex(triangleIndex);
return returnValue;
}

physx_PxBounds3_Pod PxTriangleMesh_getLocalBounds(physx_PxTriangleMesh_Pod const* self__pod) {
physx::PxTriangleMesh const* self_ = reinterpret_cast<physx::PxTriangleMesh const*>(self__pod);
physx::PxBounds3 returnValue = self_->getLocalBounds();
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

uint32_t PxTriangleMesh_getReferenceCount(physx_PxTriangleMesh_Pod const* self__pod) {
physx::PxTriangleMesh const* self_ = reinterpret_cast<physx::PxTriangleMesh const*>(self__pod);
uint32_t returnValue = self_->getReferenceCount();
return returnValue;
}

void PxTriangleMesh_acquireReference_mut(physx_PxTriangleMesh_Pod* self__pod) {
physx::PxTriangleMesh* self_ = reinterpret_cast<physx::PxTriangleMesh*>(self__pod);
self_->acquireReference();
}

void PxActor_release_mut(physx_PxActor_Pod* self__pod) {
physx::PxActor* self_ = reinterpret_cast<physx::PxActor*>(self__pod);
self_->release();
}

unsigned int PxActor_getType(physx_PxActor_Pod const* self__pod) {
physx::PxActor const* self_ = reinterpret_cast<physx::PxActor const*>(self__pod);
PxActorType::Enum returnValue = self_->getType();
unsigned int returnValue_pod = (unsigned int)returnValue;
return returnValue_pod;
}

physx_PxScene_Pod* PxActor_getScene(physx_PxActor_Pod const* self__pod) {
physx::PxActor const* self_ = reinterpret_cast<physx::PxActor const*>(self__pod);
physx::PxScene* returnValue = self_->getScene();
physx_PxScene_Pod* returnValue_pod = reinterpret_cast<physx_PxScene_Pod*>(returnValue);
return returnValue_pod;
}

void PxActor_setName_mut(physx_PxActor_Pod* self__pod, char const* name) {
physx::PxActor* self_ = reinterpret_cast<physx::PxActor*>(self__pod);
self_->setName(name);
}

char const* PxActor_getName(physx_PxActor_Pod const* self__pod) {
physx::PxActor const* self_ = reinterpret_cast<physx::PxActor const*>(self__pod);
char const* returnValue = self_->getName();
return returnValue;
}

physx_PxBounds3_Pod PxActor_getWorldBounds(physx_PxActor_Pod const* self__pod, float inflation) {
physx::PxActor const* self_ = reinterpret_cast<physx::PxActor const*>(self__pod);
physx::PxBounds3 returnValue = self_->getWorldBounds(inflation);
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxActor_setActorFlag_mut(physx_PxActor_Pod* self__pod, unsigned int flag_pod, bool value) {
physx::PxActor* self_ = reinterpret_cast<physx::PxActor*>(self__pod);
PxActorFlag::Enum flag = (PxActorFlag::Enum)flag_pod;
self_->setActorFlag(flag, value);
}

void PxActor_setActorFlags_mut(physx_PxActor_Pod* self__pod, physx_PxActorFlags_Pod inFlags_pod) {
physx::PxActor* self_ = reinterpret_cast<physx::PxActor*>(self__pod);
physx::PxActorFlags inFlags;
memcpy(&inFlags, &inFlags_pod, sizeof(inFlags));
self_->setActorFlags(inFlags);
}

physx_PxActorFlags_Pod PxActor_getActorFlags(physx_PxActor_Pod const* self__pod) {
physx::PxActor const* self_ = reinterpret_cast<physx::PxActor const*>(self__pod);
physx::PxActorFlags returnValue = self_->getActorFlags();
physx_PxActorFlags_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxActor_setDominanceGroup_mut(physx_PxActor_Pod* self__pod, unsigned char dominanceGroup) {
physx::PxActor* self_ = reinterpret_cast<physx::PxActor*>(self__pod);
self_->setDominanceGroup(dominanceGroup);
}

unsigned char PxActor_getDominanceGroup(physx_PxActor_Pod const* self__pod) {
physx::PxActor const* self_ = reinterpret_cast<physx::PxActor const*>(self__pod);
unsigned char returnValue = self_->getDominanceGroup();
return returnValue;
}

void PxActor_setOwnerClient_mut(physx_PxActor_Pod* self__pod, unsigned char inClient) {
physx::PxActor* self_ = reinterpret_cast<physx::PxActor*>(self__pod);
self_->setOwnerClient(inClient);
}

unsigned char PxActor_getOwnerClient(physx_PxActor_Pod const* self__pod) {
physx::PxActor const* self_ = reinterpret_cast<physx::PxActor const*>(self__pod);
unsigned char returnValue = self_->getOwnerClient();
return returnValue;
}

physx_PxAggregate_Pod* PxActor_getAggregate(physx_PxActor_Pod const* self__pod) {
physx::PxActor const* self_ = reinterpret_cast<physx::PxActor const*>(self__pod);
physx::PxAggregate* returnValue = self_->getAggregate();
physx_PxAggregate_Pod* returnValue_pod = reinterpret_cast<physx_PxAggregate_Pod*>(returnValue);
return returnValue_pod;
}

void PxAggregate_release_mut(physx_PxAggregate_Pod* self__pod) {
physx::PxAggregate* self_ = reinterpret_cast<physx::PxAggregate*>(self__pod);
self_->release();
}

bool PxAggregate_addActor_mut(physx_PxAggregate_Pod* self__pod, physx_PxActor_Pod* actor_pod, physx_PxBVHStructure_Pod const* bvhStructure_pod) {
physx::PxAggregate* self_ = reinterpret_cast<physx::PxAggregate*>(self__pod);
physx::PxActor& actor = reinterpret_cast<physx::PxActor&>(*actor_pod);
physx::PxBVHStructure const* bvhStructure = reinterpret_cast<physx::PxBVHStructure const*>(bvhStructure_pod);
bool returnValue = self_->addActor(actor, bvhStructure);
return returnValue;
}

bool PxAggregate_removeActor_mut(physx_PxAggregate_Pod* self__pod, physx_PxActor_Pod* actor_pod) {
physx::PxAggregate* self_ = reinterpret_cast<physx::PxAggregate*>(self__pod);
physx::PxActor& actor = reinterpret_cast<physx::PxActor&>(*actor_pod);
bool returnValue = self_->removeActor(actor);
return returnValue;
}

bool PxAggregate_addArticulation_mut(physx_PxAggregate_Pod* self__pod, physx_PxArticulationBase_Pod* articulation_pod) {
physx::PxAggregate* self_ = reinterpret_cast<physx::PxAggregate*>(self__pod);
physx::PxArticulationBase& articulation = reinterpret_cast<physx::PxArticulationBase&>(*articulation_pod);
bool returnValue = self_->addArticulation(articulation);
return returnValue;
}

bool PxAggregate_removeArticulation_mut(physx_PxAggregate_Pod* self__pod, physx_PxArticulationBase_Pod* articulation_pod) {
physx::PxAggregate* self_ = reinterpret_cast<physx::PxAggregate*>(self__pod);
physx::PxArticulationBase& articulation = reinterpret_cast<physx::PxArticulationBase&>(*articulation_pod);
bool returnValue = self_->removeArticulation(articulation);
return returnValue;
}

uint32_t PxAggregate_getNbActors(physx_PxAggregate_Pod const* self__pod) {
physx::PxAggregate const* self_ = reinterpret_cast<physx::PxAggregate const*>(self__pod);
uint32_t returnValue = self_->getNbActors();
return returnValue;
}

uint32_t PxAggregate_getMaxNbActors(physx_PxAggregate_Pod const* self__pod) {
physx::PxAggregate const* self_ = reinterpret_cast<physx::PxAggregate const*>(self__pod);
uint32_t returnValue = self_->getMaxNbActors();
return returnValue;
}

uint32_t PxAggregate_getActors(physx_PxAggregate_Pod const* self__pod, physx_PxActor_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
physx::PxAggregate const* self_ = reinterpret_cast<physx::PxAggregate const*>(self__pod);
physx::PxActor** userBuffer = reinterpret_cast<physx::PxActor**>(userBuffer_pod);
uint32_t returnValue = self_->getActors(userBuffer, bufferSize, startIndex);
return returnValue;
}

physx_PxScene_Pod* PxAggregate_getScene_mut(physx_PxAggregate_Pod* self__pod) {
physx::PxAggregate* self_ = reinterpret_cast<physx::PxAggregate*>(self__pod);
physx::PxScene* returnValue = self_->getScene();
physx_PxScene_Pod* returnValue_pod = reinterpret_cast<physx_PxScene_Pod*>(returnValue);
return returnValue_pod;
}

bool PxAggregate_getSelfCollision(physx_PxAggregate_Pod const* self__pod) {
physx::PxAggregate const* self_ = reinterpret_cast<physx::PxAggregate const*>(self__pod);
bool returnValue = self_->getSelfCollision();
return returnValue;
}

char const* PxAggregate_getConcreteTypeName(physx_PxAggregate_Pod const* self__pod) {
physx::PxAggregate const* self_ = reinterpret_cast<physx::PxAggregate const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

physx_PxScene_Pod* PxArticulationBase_getScene(physx_PxArticulationBase_Pod const* self__pod) {
physx::PxArticulationBase const* self_ = reinterpret_cast<physx::PxArticulationBase const*>(self__pod);
physx::PxScene* returnValue = self_->getScene();
physx_PxScene_Pod* returnValue_pod = reinterpret_cast<physx_PxScene_Pod*>(returnValue);
return returnValue_pod;
}

void PxArticulationBase_setSolverIterationCounts_mut(physx_PxArticulationBase_Pod* self__pod, uint32_t minPositionIters, uint32_t minVelocityIters) {
physx::PxArticulationBase* self_ = reinterpret_cast<physx::PxArticulationBase*>(self__pod);
self_->setSolverIterationCounts(minPositionIters, minVelocityIters);
}

void PxArticulationBase_getSolverIterationCounts(physx_PxArticulationBase_Pod const* self__pod, uint32_t* minPositionIters_pod, uint32_t* minVelocityIters_pod) {
physx::PxArticulationBase const* self_ = reinterpret_cast<physx::PxArticulationBase const*>(self__pod);
uint32_t& minPositionIters = *minPositionIters_pod;
uint32_t& minVelocityIters = *minVelocityIters_pod;
self_->getSolverIterationCounts(minPositionIters, minVelocityIters);
}

bool PxArticulationBase_isSleeping(physx_PxArticulationBase_Pod const* self__pod) {
physx::PxArticulationBase const* self_ = reinterpret_cast<physx::PxArticulationBase const*>(self__pod);
bool returnValue = self_->isSleeping();
return returnValue;
}

void PxArticulationBase_setSleepThreshold_mut(physx_PxArticulationBase_Pod* self__pod, float threshold) {
physx::PxArticulationBase* self_ = reinterpret_cast<physx::PxArticulationBase*>(self__pod);
self_->setSleepThreshold(threshold);
}

float PxArticulationBase_getSleepThreshold(physx_PxArticulationBase_Pod const* self__pod) {
physx::PxArticulationBase const* self_ = reinterpret_cast<physx::PxArticulationBase const*>(self__pod);
float returnValue = self_->getSleepThreshold();
return returnValue;
}

void PxArticulationBase_setStabilizationThreshold_mut(physx_PxArticulationBase_Pod* self__pod, float threshold) {
physx::PxArticulationBase* self_ = reinterpret_cast<physx::PxArticulationBase*>(self__pod);
self_->setStabilizationThreshold(threshold);
}

float PxArticulationBase_getStabilizationThreshold(physx_PxArticulationBase_Pod const* self__pod) {
physx::PxArticulationBase const* self_ = reinterpret_cast<physx::PxArticulationBase const*>(self__pod);
float returnValue = self_->getStabilizationThreshold();
return returnValue;
}

void PxArticulationBase_setWakeCounter_mut(physx_PxArticulationBase_Pod* self__pod, float wakeCounterValue) {
physx::PxArticulationBase* self_ = reinterpret_cast<physx::PxArticulationBase*>(self__pod);
self_->setWakeCounter(wakeCounterValue);
}

float PxArticulationBase_getWakeCounter(physx_PxArticulationBase_Pod const* self__pod) {
physx::PxArticulationBase const* self_ = reinterpret_cast<physx::PxArticulationBase const*>(self__pod);
float returnValue = self_->getWakeCounter();
return returnValue;
}

void PxArticulationBase_wakeUp_mut(physx_PxArticulationBase_Pod* self__pod) {
physx::PxArticulationBase* self_ = reinterpret_cast<physx::PxArticulationBase*>(self__pod);
self_->wakeUp();
}

void PxArticulationBase_putToSleep_mut(physx_PxArticulationBase_Pod* self__pod) {
physx::PxArticulationBase* self_ = reinterpret_cast<physx::PxArticulationBase*>(self__pod);
self_->putToSleep();
}

physx_PxArticulationLink_Pod* PxArticulationBase_createLink_mut(physx_PxArticulationBase_Pod* self__pod, physx_PxArticulationLink_Pod* parent_pod, physx_PxTransform_Pod const* pose_pod) {
physx::PxArticulationBase* self_ = reinterpret_cast<physx::PxArticulationBase*>(self__pod);
physx::PxArticulationLink* parent = reinterpret_cast<physx::PxArticulationLink*>(parent_pod);
physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
physx::PxArticulationLink* returnValue = self_->createLink(parent, pose);
physx_PxArticulationLink_Pod* returnValue_pod = reinterpret_cast<physx_PxArticulationLink_Pod*>(returnValue);
return returnValue_pod;
}

uint32_t PxArticulationBase_getNbLinks(physx_PxArticulationBase_Pod const* self__pod) {
physx::PxArticulationBase const* self_ = reinterpret_cast<physx::PxArticulationBase const*>(self__pod);
uint32_t returnValue = self_->getNbLinks();
return returnValue;
}

uint32_t PxArticulationBase_getLinks(physx_PxArticulationBase_Pod const* self__pod, physx_PxArticulationLink_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
physx::PxArticulationBase const* self_ = reinterpret_cast<physx::PxArticulationBase const*>(self__pod);
physx::PxArticulationLink** userBuffer = reinterpret_cast<physx::PxArticulationLink**>(userBuffer_pod);
uint32_t returnValue = self_->getLinks(userBuffer, bufferSize, startIndex);
return returnValue;
}

void PxArticulationBase_setName_mut(physx_PxArticulationBase_Pod* self__pod, char const* name) {
physx::PxArticulationBase* self_ = reinterpret_cast<physx::PxArticulationBase*>(self__pod);
self_->setName(name);
}

char const* PxArticulationBase_getName(physx_PxArticulationBase_Pod const* self__pod) {
physx::PxArticulationBase const* self_ = reinterpret_cast<physx::PxArticulationBase const*>(self__pod);
char const* returnValue = self_->getName();
return returnValue;
}

physx_PxBounds3_Pod PxArticulationBase_getWorldBounds(physx_PxArticulationBase_Pod const* self__pod, float inflation) {
physx::PxArticulationBase const* self_ = reinterpret_cast<physx::PxArticulationBase const*>(self__pod);
physx::PxBounds3 returnValue = self_->getWorldBounds(inflation);
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxAggregate_Pod* PxArticulationBase_getAggregate(physx_PxArticulationBase_Pod const* self__pod) {
physx::PxArticulationBase const* self_ = reinterpret_cast<physx::PxArticulationBase const*>(self__pod);
physx::PxAggregate* returnValue = self_->getAggregate();
physx_PxAggregate_Pod* returnValue_pod = reinterpret_cast<physx_PxAggregate_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxArticulationImpl_Pod* PxArticulationBase_getImpl_mut(physx_PxArticulationBase_Pod* self__pod) {
physx::PxArticulationBase* self_ = reinterpret_cast<physx::PxArticulationBase*>(self__pod);
physx::PxArticulationImpl* returnValue = self_->getImpl();
physx_PxArticulationImpl_Pod* returnValue_pod = reinterpret_cast<physx_PxArticulationImpl_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxArticulationImpl_Pod const* PxArticulationBase_getImpl(physx_PxArticulationBase_Pod const* self__pod) {
physx::PxArticulationBase const* self_ = reinterpret_cast<physx::PxArticulationBase const*>(self__pod);
physx::PxArticulationImpl const* returnValue = self_->getImpl();
physx_PxArticulationImpl_Pod const* returnValue_pod = reinterpret_cast<physx_PxArticulationImpl_Pod const*>(returnValue);
return returnValue_pod;
}

physx_PxArticulationJointBase_Pod* PxArticulationBase_createArticulationJoint_mut(physx_PxArticulationBase_Pod* self__pod, physx_PxArticulationLink_Pod* parent_pod, physx_PxTransform_Pod const* parentFrame_pod, physx_PxArticulationLink_Pod* child_pod, physx_PxTransform_Pod const* childFrame_pod) {
physx::PxArticulationBase* self_ = reinterpret_cast<physx::PxArticulationBase*>(self__pod);
physx::PxArticulationLink& parent = reinterpret_cast<physx::PxArticulationLink&>(*parent_pod);
physx::PxTransform const& parentFrame = reinterpret_cast<physx::PxTransform const&>(*parentFrame_pod);
physx::PxArticulationLink& child = reinterpret_cast<physx::PxArticulationLink&>(*child_pod);
physx::PxTransform const& childFrame = reinterpret_cast<physx::PxTransform const&>(*childFrame_pod);
physx::PxArticulationJointBase* returnValue = self_->createArticulationJoint(parent, parentFrame, child, childFrame);
physx_PxArticulationJointBase_Pod* returnValue_pod = reinterpret_cast<physx_PxArticulationJointBase_Pod*>(returnValue);
return returnValue_pod;
}

void PxArticulationBase_releaseArticulationJoint_mut(physx_PxArticulationBase_Pod* self__pod, physx_PxArticulationJointBase_Pod* joint_pod) {
physx::PxArticulationBase* self_ = reinterpret_cast<physx::PxArticulationBase*>(self__pod);
physx::PxArticulationJointBase* joint = reinterpret_cast<physx::PxArticulationJointBase*>(joint_pod);
self_->releaseArticulationJoint(joint);
}

void PxArticulation_release_mut(physx_PxArticulation_Pod* self__pod) {
physx::PxArticulation* self_ = reinterpret_cast<physx::PxArticulation*>(self__pod);
self_->release();
}

void PxArticulation_setMaxProjectionIterations_mut(physx_PxArticulation_Pod* self__pod, uint32_t iterations) {
physx::PxArticulation* self_ = reinterpret_cast<physx::PxArticulation*>(self__pod);
self_->setMaxProjectionIterations(iterations);
}

uint32_t PxArticulation_getMaxProjectionIterations(physx_PxArticulation_Pod const* self__pod) {
physx::PxArticulation const* self_ = reinterpret_cast<physx::PxArticulation const*>(self__pod);
uint32_t returnValue = self_->getMaxProjectionIterations();
return returnValue;
}

void PxArticulation_setSeparationTolerance_mut(physx_PxArticulation_Pod* self__pod, float tolerance) {
physx::PxArticulation* self_ = reinterpret_cast<physx::PxArticulation*>(self__pod);
self_->setSeparationTolerance(tolerance);
}

float PxArticulation_getSeparationTolerance(physx_PxArticulation_Pod const* self__pod) {
physx::PxArticulation const* self_ = reinterpret_cast<physx::PxArticulation const*>(self__pod);
float returnValue = self_->getSeparationTolerance();
return returnValue;
}

void PxArticulation_setInternalDriveIterations_mut(physx_PxArticulation_Pod* self__pod, uint32_t iterations) {
physx::PxArticulation* self_ = reinterpret_cast<physx::PxArticulation*>(self__pod);
self_->setInternalDriveIterations(iterations);
}

uint32_t PxArticulation_getInternalDriveIterations(physx_PxArticulation_Pod const* self__pod) {
physx::PxArticulation const* self_ = reinterpret_cast<physx::PxArticulation const*>(self__pod);
uint32_t returnValue = self_->getInternalDriveIterations();
return returnValue;
}

void PxArticulation_setExternalDriveIterations_mut(physx_PxArticulation_Pod* self__pod, uint32_t iterations) {
physx::PxArticulation* self_ = reinterpret_cast<physx::PxArticulation*>(self__pod);
self_->setExternalDriveIterations(iterations);
}

uint32_t PxArticulation_getExternalDriveIterations(physx_PxArticulation_Pod const* self__pod) {
physx::PxArticulation const* self_ = reinterpret_cast<physx::PxArticulation const*>(self__pod);
uint32_t returnValue = self_->getExternalDriveIterations();
return returnValue;
}

physx_PxArticulationDriveCache_Pod* PxArticulation_createDriveCache(physx_PxArticulation_Pod const* self__pod, float compliance, uint32_t driveIterations) {
physx::PxArticulation const* self_ = reinterpret_cast<physx::PxArticulation const*>(self__pod);
physx::PxArticulationDriveCache* returnValue = self_->createDriveCache(compliance, driveIterations);
physx_PxArticulationDriveCache_Pod* returnValue_pod = reinterpret_cast<physx_PxArticulationDriveCache_Pod*>(returnValue);
return returnValue_pod;
}

void PxArticulation_updateDriveCache(physx_PxArticulation_Pod const* self__pod, physx_PxArticulationDriveCache_Pod* driveCache_pod, float compliance, uint32_t driveIterations) {
physx::PxArticulation const* self_ = reinterpret_cast<physx::PxArticulation const*>(self__pod);
physx::PxArticulationDriveCache& driveCache = reinterpret_cast<physx::PxArticulationDriveCache&>(*driveCache_pod);
self_->updateDriveCache(driveCache, compliance, driveIterations);
}

void PxArticulation_releaseDriveCache(physx_PxArticulation_Pod const* self__pod, physx_PxArticulationDriveCache_Pod* driveCache_pod) {
physx::PxArticulation const* self_ = reinterpret_cast<physx::PxArticulation const*>(self__pod);
physx::PxArticulationDriveCache& driveCache = reinterpret_cast<physx::PxArticulationDriveCache&>(*driveCache_pod);
self_->releaseDriveCache(driveCache);
}

void PxArticulation_applyImpulse_mut(physx_PxArticulation_Pod* self__pod, physx_PxArticulationLink_Pod* link_pod, physx_PxArticulationDriveCache_Pod const* driveCache_pod, physx_PxVec3_Pod const* linearImpulse_pod, physx_PxVec3_Pod const* angularImpulse_pod) {
physx::PxArticulation* self_ = reinterpret_cast<physx::PxArticulation*>(self__pod);
physx::PxArticulationLink* link = reinterpret_cast<physx::PxArticulationLink*>(link_pod);
physx::PxArticulationDriveCache const& driveCache = reinterpret_cast<physx::PxArticulationDriveCache const&>(*driveCache_pod);
physx::PxVec3 const& linearImpulse = reinterpret_cast<physx::PxVec3 const&>(*linearImpulse_pod);
physx::PxVec3 const& angularImpulse = reinterpret_cast<physx::PxVec3 const&>(*angularImpulse_pod);
self_->applyImpulse(link, driveCache, linearImpulse, angularImpulse);
}

void PxArticulation_computeImpulseResponse(physx_PxArticulation_Pod const* self__pod, physx_PxArticulationLink_Pod* link_pod, physx_PxVec3_Pod* linearResponse_pod, physx_PxVec3_Pod* angularResponse_pod, physx_PxArticulationDriveCache_Pod const* driveCache_pod, physx_PxVec3_Pod const* linearImpulse_pod, physx_PxVec3_Pod const* angularImpulse_pod) {
physx::PxArticulation const* self_ = reinterpret_cast<physx::PxArticulation const*>(self__pod);
physx::PxArticulationLink* link = reinterpret_cast<physx::PxArticulationLink*>(link_pod);
physx::PxVec3& linearResponse = reinterpret_cast<physx::PxVec3&>(*linearResponse_pod);
physx::PxVec3& angularResponse = reinterpret_cast<physx::PxVec3&>(*angularResponse_pod);
physx::PxArticulationDriveCache const& driveCache = reinterpret_cast<physx::PxArticulationDriveCache const&>(*driveCache_pod);
physx::PxVec3 const& linearImpulse = reinterpret_cast<physx::PxVec3 const&>(*linearImpulse_pod);
physx::PxVec3 const& angularImpulse = reinterpret_cast<physx::PxVec3 const&>(*angularImpulse_pod);
self_->computeImpulseResponse(link, linearResponse, angularResponse, driveCache, linearImpulse, angularImpulse);
}

physx_PxConstraintInvMassScale_Pod PxConstraintInvMassScale_new() {
physx::PxConstraintInvMassScale returnValue;
physx_PxConstraintInvMassScale_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxConstraintInvMassScale_Pod PxConstraintInvMassScale_new_1(float lin0, float ang0, float lin1, float ang1) {
physx::PxConstraintInvMassScale returnValue(lin0, ang0, lin1, ang1);
physx_PxConstraintInvMassScale_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxConstraintVisualizer_visualizeJointFrames_mut(physx_PxConstraintVisualizer_Pod* self__pod, physx_PxTransform_Pod const* parent_pod, physx_PxTransform_Pod const* child_pod) {
physx::PxConstraintVisualizer* self_ = reinterpret_cast<physx::PxConstraintVisualizer*>(self__pod);
physx::PxTransform const& parent = reinterpret_cast<physx::PxTransform const&>(*parent_pod);
physx::PxTransform const& child = reinterpret_cast<physx::PxTransform const&>(*child_pod);
self_->visualizeJointFrames(parent, child);
}

void PxConstraintVisualizer_visualizeLinearLimit_mut(physx_PxConstraintVisualizer_Pod* self__pod, physx_PxTransform_Pod const* t0_pod, physx_PxTransform_Pod const* t1_pod, float value, bool active) {
physx::PxConstraintVisualizer* self_ = reinterpret_cast<physx::PxConstraintVisualizer*>(self__pod);
physx::PxTransform const& t0 = reinterpret_cast<physx::PxTransform const&>(*t0_pod);
physx::PxTransform const& t1 = reinterpret_cast<physx::PxTransform const&>(*t1_pod);
self_->visualizeLinearLimit(t0, t1, value, active);
}

void PxConstraintVisualizer_visualizeAngularLimit_mut(physx_PxConstraintVisualizer_Pod* self__pod, physx_PxTransform_Pod const* t0_pod, float lower, float upper, bool active) {
physx::PxConstraintVisualizer* self_ = reinterpret_cast<physx::PxConstraintVisualizer*>(self__pod);
physx::PxTransform const& t0 = reinterpret_cast<physx::PxTransform const&>(*t0_pod);
self_->visualizeAngularLimit(t0, lower, upper, active);
}

void PxConstraintVisualizer_visualizeLimitCone_mut(physx_PxConstraintVisualizer_Pod* self__pod, physx_PxTransform_Pod const* t_pod, float tanQSwingY, float tanQSwingZ, bool active) {
physx::PxConstraintVisualizer* self_ = reinterpret_cast<physx::PxConstraintVisualizer*>(self__pod);
physx::PxTransform const& t = reinterpret_cast<physx::PxTransform const&>(*t_pod);
self_->visualizeLimitCone(t, tanQSwingY, tanQSwingZ, active);
}

void PxConstraintVisualizer_visualizeDoubleCone_mut(physx_PxConstraintVisualizer_Pod* self__pod, physx_PxTransform_Pod const* t_pod, float angle, bool active) {
physx::PxConstraintVisualizer* self_ = reinterpret_cast<physx::PxConstraintVisualizer*>(self__pod);
physx::PxTransform const& t = reinterpret_cast<physx::PxTransform const&>(*t_pod);
self_->visualizeDoubleCone(t, angle, active);
}

void PxConstraintVisualizer_visualizeLine_mut(physx_PxConstraintVisualizer_Pod* self__pod, physx_PxVec3_Pod const* p0_pod, physx_PxVec3_Pod const* p1_pod, uint32_t color) {
physx::PxConstraintVisualizer* self_ = reinterpret_cast<physx::PxConstraintVisualizer*>(self__pod);
physx::PxVec3 const& p0 = reinterpret_cast<physx::PxVec3 const&>(*p0_pod);
physx::PxVec3 const& p1 = reinterpret_cast<physx::PxVec3 const&>(*p1_pod);
self_->visualizeLine(p0, p1, color);
}

void* PxConstraintConnector_prepareData_mut(physx_PxConstraintConnector_Pod* self__pod) {
physx::PxConstraintConnector* self_ = reinterpret_cast<physx::PxConstraintConnector*>(self__pod);
void* returnValue = self_->prepareData();
return returnValue;
}

bool PxConstraintConnector_updatePvdProperties(physx_PxConstraintConnector_Pod const* self__pod, physx_pvdsdk_PvdDataStream_Pod* pvdConnection_pod, physx_PxConstraint_Pod const* c_pod, unsigned int updateType_pod) {
physx::PxConstraintConnector const* self_ = reinterpret_cast<physx::PxConstraintConnector const*>(self__pod);
physx::pvdsdk::PvdDataStream& pvdConnection = reinterpret_cast<physx::pvdsdk::PvdDataStream&>(*pvdConnection_pod);
physx::PxConstraint const* c = reinterpret_cast<physx::PxConstraint const*>(c_pod);
PxPvdUpdateType::Enum updateType = (PxPvdUpdateType::Enum)updateType_pod;
bool returnValue = self_->updatePvdProperties(pvdConnection, c, updateType);
return returnValue;
}

void PxConstraintConnector_onConstraintRelease_mut(physx_PxConstraintConnector_Pod* self__pod) {
physx::PxConstraintConnector* self_ = reinterpret_cast<physx::PxConstraintConnector*>(self__pod);
self_->onConstraintRelease();
}

void PxConstraintConnector_onComShift_mut(physx_PxConstraintConnector_Pod* self__pod, uint32_t actor) {
physx::PxConstraintConnector* self_ = reinterpret_cast<physx::PxConstraintConnector*>(self__pod);
self_->onComShift(actor);
}

void PxConstraintConnector_onOriginShift_mut(physx_PxConstraintConnector_Pod* self__pod, physx_PxVec3_Pod const* shift_pod) {
physx::PxConstraintConnector* self_ = reinterpret_cast<physx::PxConstraintConnector*>(self__pod);
physx::PxVec3 const& shift = reinterpret_cast<physx::PxVec3 const&>(*shift_pod);
self_->onOriginShift(shift);
}

void* PxConstraintConnector_getExternalReference_mut(physx_PxConstraintConnector_Pod* self__pod, uint32_t* typeID_pod) {
physx::PxConstraintConnector* self_ = reinterpret_cast<physx::PxConstraintConnector*>(self__pod);
uint32_t& typeID = *typeID_pod;
void* returnValue = self_->getExternalReference(typeID);
return returnValue;
}

physx_PxBase_Pod* PxConstraintConnector_getSerializable_mut(physx_PxConstraintConnector_Pod* self__pod) {
physx::PxConstraintConnector* self_ = reinterpret_cast<physx::PxConstraintConnector*>(self__pod);
physx::PxBase* returnValue = self_->getSerializable();
physx_PxBase_Pod* returnValue_pod = reinterpret_cast<physx_PxBase_Pod*>(returnValue);
return returnValue_pod;
}

void* PxConstraintConnector_getPrep(physx_PxConstraintConnector_Pod const* self__pod) {
physx::PxConstraintConnector const* self_ = reinterpret_cast<physx::PxConstraintConnector const*>(self__pod);
physx::PxConstraintSolverPrep returnValue = self_->getPrep();
void* returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void const* PxConstraintConnector_getConstantBlock(physx_PxConstraintConnector_Pod const* self__pod) {
physx::PxConstraintConnector const* self_ = reinterpret_cast<physx::PxConstraintConnector const*>(self__pod);
void const* returnValue = self_->getConstantBlock();
return returnValue;
}

void PxConstraintConnector_delete(physx_PxConstraintConnector_Pod* self__pod) {
physx::PxConstraintConnector* self_ = reinterpret_cast<physx::PxConstraintConnector*>(self__pod);
delete self_;
}

physx_PxSolverBody_Pod PxSolverBody_new() {
physx::PxSolverBody returnValue;
physx_PxSolverBody_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

float PxSolverBodyData_projectVelocity(physx_PxSolverBodyData_Pod const* self__pod, physx_PxVec3_Pod const* lin_pod, physx_PxVec3_Pod const* ang_pod) {
physx::PxSolverBodyData const* self_ = reinterpret_cast<physx::PxSolverBodyData const*>(self__pod);
physx::PxVec3 const& lin = reinterpret_cast<physx::PxVec3 const&>(*lin_pod);
physx::PxVec3 const& ang = reinterpret_cast<physx::PxVec3 const&>(*ang_pod);
float returnValue = self_->projectVelocity(lin, ang);
return returnValue;
}

unsigned char* PxConstraintAllocator_reserveConstraintData_mut(physx_PxConstraintAllocator_Pod* self__pod, uint32_t byteSize) {
physx::PxConstraintAllocator* self_ = reinterpret_cast<physx::PxConstraintAllocator*>(self__pod);
unsigned char* returnValue = self_->reserveConstraintData(byteSize);
return returnValue;
}

unsigned char* PxConstraintAllocator_reserveFrictionData_mut(physx_PxConstraintAllocator_Pod* self__pod, uint32_t byteSize) {
physx::PxConstraintAllocator* self_ = reinterpret_cast<physx::PxConstraintAllocator*>(self__pod);
unsigned char* returnValue = self_->reserveFrictionData(byteSize);
return returnValue;
}

void PxConstraintAllocator_delete(physx_PxConstraintAllocator_Pod* self__pod) {
physx::PxConstraintAllocator* self_ = reinterpret_cast<physx::PxConstraintAllocator*>(self__pod);
delete self_;
}

float PxTGSSolverBodyVel_projectVelocity(physx_PxTGSSolverBodyVel_Pod const* self__pod, physx_PxVec3_Pod const* lin_pod, physx_PxVec3_Pod const* ang_pod) {
physx::PxTGSSolverBodyVel const* self_ = reinterpret_cast<physx::PxTGSSolverBodyVel const*>(self__pod);
physx::PxVec3 const& lin = reinterpret_cast<physx::PxVec3 const&>(*lin_pod);
physx::PxVec3 const& ang = reinterpret_cast<physx::PxVec3 const&>(*ang_pod);
float returnValue = self_->projectVelocity(lin, ang);
return returnValue;
}

float PxTGSSolverBodyData_projectVelocity(physx_PxTGSSolverBodyData_Pod const* self__pod, physx_PxVec3_Pod const* linear_pod, physx_PxVec3_Pod const* angular_pod) {
physx::PxTGSSolverBodyData const* self_ = reinterpret_cast<physx::PxTGSSolverBodyData const*>(self__pod);
physx::PxVec3 const& linear = reinterpret_cast<physx::PxVec3 const&>(*linear_pod);
physx::PxVec3 const& angular = reinterpret_cast<physx::PxVec3 const&>(*angular_pod);
float returnValue = self_->projectVelocity(linear, angular);
return returnValue;
}

physx_PxArticulationCache_Pod PxArticulationCache_new() {
physx::PxArticulationCache returnValue;
physx_PxArticulationCache_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxArticulationReducedCoordinate_release_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod) {
physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
self_->release();
}

void PxArticulationReducedCoordinate_setArticulationFlags_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, physx_PxArticulationFlags_Pod flags_pod) {
physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
physx::PxArticulationFlags flags;
memcpy(&flags, &flags_pod, sizeof(flags));
self_->setArticulationFlags(flags);
}

void PxArticulationReducedCoordinate_setArticulationFlag_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, unsigned int flag_pod, bool value) {
physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
PxArticulationFlag::Enum flag = (PxArticulationFlag::Enum)flag_pod;
self_->setArticulationFlag(flag, value);
}

physx_PxArticulationFlags_Pod PxArticulationReducedCoordinate_getArticulationFlags(physx_PxArticulationReducedCoordinate_Pod const* self__pod) {
physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
physx::PxArticulationFlags returnValue = self_->getArticulationFlags();
physx_PxArticulationFlags_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

uint32_t PxArticulationReducedCoordinate_getDofs(physx_PxArticulationReducedCoordinate_Pod const* self__pod) {
physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
uint32_t returnValue = self_->getDofs();
return returnValue;
}

physx_PxArticulationCache_Pod* PxArticulationReducedCoordinate_createCache(physx_PxArticulationReducedCoordinate_Pod const* self__pod) {
physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
physx::PxArticulationCache* returnValue = self_->createCache();
physx_PxArticulationCache_Pod* returnValue_pod = reinterpret_cast<physx_PxArticulationCache_Pod*>(returnValue);
return returnValue_pod;
}

uint32_t PxArticulationReducedCoordinate_getCacheDataSize(physx_PxArticulationReducedCoordinate_Pod const* self__pod) {
physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
uint32_t returnValue = self_->getCacheDataSize();
return returnValue;
}

void PxArticulationReducedCoordinate_zeroCache_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, physx_PxArticulationCache_Pod* cache_pod) {
physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
physx::PxArticulationCache& cache = reinterpret_cast<physx::PxArticulationCache&>(*cache_pod);
self_->zeroCache(cache);
}

void PxArticulationReducedCoordinate_applyCache_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, physx_PxArticulationCache_Pod* cache_pod, physx_PxArticulationCacheFlags_Pod flag_pod, bool autowake) {
physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
physx::PxArticulationCache& cache = reinterpret_cast<physx::PxArticulationCache&>(*cache_pod);
physx::PxArticulationCacheFlags flag;
memcpy(&flag, &flag_pod, sizeof(flag));
self_->applyCache(cache, flag, autowake);
}

void PxArticulationReducedCoordinate_copyInternalStateToCache(physx_PxArticulationReducedCoordinate_Pod const* self__pod, physx_PxArticulationCache_Pod* cache_pod, physx_PxArticulationCacheFlags_Pod flag_pod) {
physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
physx::PxArticulationCache& cache = reinterpret_cast<physx::PxArticulationCache&>(*cache_pod);
physx::PxArticulationCacheFlags flag;
memcpy(&flag, &flag_pod, sizeof(flag));
self_->copyInternalStateToCache(cache, flag);
}

void PxArticulationReducedCoordinate_releaseCache(physx_PxArticulationReducedCoordinate_Pod const* self__pod, physx_PxArticulationCache_Pod* cache_pod) {
physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
physx::PxArticulationCache& cache = reinterpret_cast<physx::PxArticulationCache&>(*cache_pod);
self_->releaseCache(cache);
}

void PxArticulationReducedCoordinate_packJointData(physx_PxArticulationReducedCoordinate_Pod const* self__pod, float const* maximum, float* reduced) {
physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
self_->packJointData(maximum, reduced);
}

void PxArticulationReducedCoordinate_unpackJointData(physx_PxArticulationReducedCoordinate_Pod const* self__pod, float const* reduced, float* maximum) {
physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
self_->unpackJointData(reduced, maximum);
}

void PxArticulationReducedCoordinate_commonInit(physx_PxArticulationReducedCoordinate_Pod const* self__pod) {
physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
self_->commonInit();
}

void PxArticulationReducedCoordinate_computeGeneralizedGravityForce(physx_PxArticulationReducedCoordinate_Pod const* self__pod, physx_PxArticulationCache_Pod* cache_pod) {
physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
physx::PxArticulationCache& cache = reinterpret_cast<physx::PxArticulationCache&>(*cache_pod);
self_->computeGeneralizedGravityForce(cache);
}

void PxArticulationReducedCoordinate_computeCoriolisAndCentrifugalForce(physx_PxArticulationReducedCoordinate_Pod const* self__pod, physx_PxArticulationCache_Pod* cache_pod) {
physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
physx::PxArticulationCache& cache = reinterpret_cast<physx::PxArticulationCache&>(*cache_pod);
self_->computeCoriolisAndCentrifugalForce(cache);
}

void PxArticulationReducedCoordinate_computeGeneralizedExternalForce(physx_PxArticulationReducedCoordinate_Pod const* self__pod, physx_PxArticulationCache_Pod* cache_pod) {
physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
physx::PxArticulationCache& cache = reinterpret_cast<physx::PxArticulationCache&>(*cache_pod);
self_->computeGeneralizedExternalForce(cache);
}

void PxArticulationReducedCoordinate_computeJointAcceleration(physx_PxArticulationReducedCoordinate_Pod const* self__pod, physx_PxArticulationCache_Pod* cache_pod) {
physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
physx::PxArticulationCache& cache = reinterpret_cast<physx::PxArticulationCache&>(*cache_pod);
self_->computeJointAcceleration(cache);
}

void PxArticulationReducedCoordinate_computeJointForce(physx_PxArticulationReducedCoordinate_Pod const* self__pod, physx_PxArticulationCache_Pod* cache_pod) {
physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
physx::PxArticulationCache& cache = reinterpret_cast<physx::PxArticulationCache&>(*cache_pod);
self_->computeJointForce(cache);
}

void PxArticulationReducedCoordinate_computeDenseJacobian(physx_PxArticulationReducedCoordinate_Pod const* self__pod, physx_PxArticulationCache_Pod* cache_pod, uint32_t* nRows_pod, uint32_t* nCols_pod) {
physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
physx::PxArticulationCache& cache = reinterpret_cast<physx::PxArticulationCache&>(*cache_pod);
uint32_t& nRows = *nRows_pod;
uint32_t& nCols = *nCols_pod;
self_->computeDenseJacobian(cache, nRows, nCols);
}

void PxArticulationReducedCoordinate_computeCoefficientMatrix(physx_PxArticulationReducedCoordinate_Pod const* self__pod, physx_PxArticulationCache_Pod* cache_pod) {
physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
physx::PxArticulationCache& cache = reinterpret_cast<physx::PxArticulationCache&>(*cache_pod);
self_->computeCoefficientMatrix(cache);
}

bool PxArticulationReducedCoordinate_computeLambda(physx_PxArticulationReducedCoordinate_Pod const* self__pod, physx_PxArticulationCache_Pod* cache_pod, physx_PxArticulationCache_Pod* initialState_pod, float const* jointTorque, uint32_t maxIter) {
physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
physx::PxArticulationCache& cache = reinterpret_cast<physx::PxArticulationCache&>(*cache_pod);
physx::PxArticulationCache& initialState = reinterpret_cast<physx::PxArticulationCache&>(*initialState_pod);
bool returnValue = self_->computeLambda(cache, initialState, jointTorque, maxIter);
return returnValue;
}

void PxArticulationReducedCoordinate_computeGeneralizedMassMatrix(physx_PxArticulationReducedCoordinate_Pod const* self__pod, physx_PxArticulationCache_Pod* cache_pod) {
physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
physx::PxArticulationCache& cache = reinterpret_cast<physx::PxArticulationCache&>(*cache_pod);
self_->computeGeneralizedMassMatrix(cache);
}

void PxArticulationReducedCoordinate_addLoopJoint_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, physx_PxJoint_Pod* joint_pod) {
physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
physx::PxJoint* joint = reinterpret_cast<physx::PxJoint*>(joint_pod);
self_->addLoopJoint(joint);
}

void PxArticulationReducedCoordinate_removeLoopJoint_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, physx_PxJoint_Pod* joint_pod) {
physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
physx::PxJoint* joint = reinterpret_cast<physx::PxJoint*>(joint_pod);
self_->removeLoopJoint(joint);
}

uint32_t PxArticulationReducedCoordinate_getNbLoopJoints(physx_PxArticulationReducedCoordinate_Pod const* self__pod) {
physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
uint32_t returnValue = self_->getNbLoopJoints();
return returnValue;
}

uint32_t PxArticulationReducedCoordinate_getLoopJoints(physx_PxArticulationReducedCoordinate_Pod const* self__pod, physx_PxJoint_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
physx::PxJoint** userBuffer = reinterpret_cast<physx::PxJoint**>(userBuffer_pod);
uint32_t returnValue = self_->getLoopJoints(userBuffer, bufferSize, startIndex);
return returnValue;
}

uint32_t PxArticulationReducedCoordinate_getCoefficientMatrixSize(physx_PxArticulationReducedCoordinate_Pod const* self__pod) {
physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
uint32_t returnValue = self_->getCoefficientMatrixSize();
return returnValue;
}

void PxArticulationReducedCoordinate_teleportRootLink_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, physx_PxTransform_Pod const* pose_pod, bool autowake) {
physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
self_->teleportRootLink(pose, autowake);
}

physx_PxSpatialVelocity_Pod PxArticulationReducedCoordinate_getLinkVelocity_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, uint32_t linkId) {
physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
physx::PxSpatialVelocity returnValue = self_->getLinkVelocity(linkId);
physx_PxSpatialVelocity_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxSpatialVelocity_Pod PxArticulationReducedCoordinate_getLinkAcceleration_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, uint32_t linkId) {
physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
physx::PxSpatialVelocity returnValue = self_->getLinkAcceleration(linkId);
physx_PxSpatialVelocity_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxArticulationLink_Pod* PxArticulationJointBase_getParentArticulationLink(physx_PxArticulationJointBase_Pod const* self__pod) {
physx::PxArticulationJointBase const* self_ = reinterpret_cast<physx::PxArticulationJointBase const*>(self__pod);
physx::PxArticulationLink& returnValue = self_->getParentArticulationLink();
physx_PxArticulationLink_Pod* returnValue_pod = reinterpret_cast<physx_PxArticulationLink_Pod*>(&returnValue);
return returnValue_pod;
}

void PxArticulationJointBase_setParentPose_mut(physx_PxArticulationJointBase_Pod* self__pod, physx_PxTransform_Pod const* pose_pod) {
physx::PxArticulationJointBase* self_ = reinterpret_cast<physx::PxArticulationJointBase*>(self__pod);
physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
self_->setParentPose(pose);
}

physx_PxTransform_Pod PxArticulationJointBase_getParentPose(physx_PxArticulationJointBase_Pod const* self__pod) {
physx::PxArticulationJointBase const* self_ = reinterpret_cast<physx::PxArticulationJointBase const*>(self__pod);
physx::PxTransform returnValue = self_->getParentPose();
physx_PxTransform_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxArticulationLink_Pod* PxArticulationJointBase_getChildArticulationLink(physx_PxArticulationJointBase_Pod const* self__pod) {
physx::PxArticulationJointBase const* self_ = reinterpret_cast<physx::PxArticulationJointBase const*>(self__pod);
physx::PxArticulationLink& returnValue = self_->getChildArticulationLink();
physx_PxArticulationLink_Pod* returnValue_pod = reinterpret_cast<physx_PxArticulationLink_Pod*>(&returnValue);
return returnValue_pod;
}

void PxArticulationJointBase_setChildPose_mut(physx_PxArticulationJointBase_Pod* self__pod, physx_PxTransform_Pod const* pose_pod) {
physx::PxArticulationJointBase* self_ = reinterpret_cast<physx::PxArticulationJointBase*>(self__pod);
physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
self_->setChildPose(pose);
}

physx_PxTransform_Pod PxArticulationJointBase_getChildPose(physx_PxArticulationJointBase_Pod const* self__pod) {
physx::PxArticulationJointBase const* self_ = reinterpret_cast<physx::PxArticulationJointBase const*>(self__pod);
physx::PxTransform returnValue = self_->getChildPose();
physx_PxTransform_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxArticulationJointImpl_Pod* PxArticulationJointBase_getImpl_mut(physx_PxArticulationJointBase_Pod* self__pod) {
physx::PxArticulationJointBase* self_ = reinterpret_cast<physx::PxArticulationJointBase*>(self__pod);
physx::PxArticulationJointImpl* returnValue = self_->getImpl();
physx_PxArticulationJointImpl_Pod* returnValue_pod = reinterpret_cast<physx_PxArticulationJointImpl_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxArticulationJointImpl_Pod const* PxArticulationJointBase_getImpl(physx_PxArticulationJointBase_Pod const* self__pod) {
physx::PxArticulationJointBase const* self_ = reinterpret_cast<physx::PxArticulationJointBase const*>(self__pod);
physx::PxArticulationJointImpl const* returnValue = self_->getImpl();
physx_PxArticulationJointImpl_Pod const* returnValue_pod = reinterpret_cast<physx_PxArticulationJointImpl_Pod const*>(returnValue);
return returnValue_pod;
}

void PxArticulationJoint_setTargetOrientation_mut(physx_PxArticulationJoint_Pod* self__pod, physx_PxQuat_Pod const* orientation_pod) {
physx::PxArticulationJoint* self_ = reinterpret_cast<physx::PxArticulationJoint*>(self__pod);
physx::PxQuat const& orientation = reinterpret_cast<physx::PxQuat const&>(*orientation_pod);
self_->setTargetOrientation(orientation);
}

physx_PxQuat_Pod PxArticulationJoint_getTargetOrientation(physx_PxArticulationJoint_Pod const* self__pod) {
physx::PxArticulationJoint const* self_ = reinterpret_cast<physx::PxArticulationJoint const*>(self__pod);
physx::PxQuat returnValue = self_->getTargetOrientation();
physx_PxQuat_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxArticulationJoint_setTargetVelocity_mut(physx_PxArticulationJoint_Pod* self__pod, physx_PxVec3_Pod const* velocity_pod) {
physx::PxArticulationJoint* self_ = reinterpret_cast<physx::PxArticulationJoint*>(self__pod);
physx::PxVec3 const& velocity = reinterpret_cast<physx::PxVec3 const&>(*velocity_pod);
self_->setTargetVelocity(velocity);
}

physx_PxVec3_Pod PxArticulationJoint_getTargetVelocity(physx_PxArticulationJoint_Pod const* self__pod) {
physx::PxArticulationJoint const* self_ = reinterpret_cast<physx::PxArticulationJoint const*>(self__pod);
physx::PxVec3 returnValue = self_->getTargetVelocity();
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxArticulationJoint_setDriveType_mut(physx_PxArticulationJoint_Pod* self__pod, unsigned int driveType_pod) {
physx::PxArticulationJoint* self_ = reinterpret_cast<physx::PxArticulationJoint*>(self__pod);
PxArticulationJointDriveType::Enum driveType = (PxArticulationJointDriveType::Enum)driveType_pod;
self_->setDriveType(driveType);
}

unsigned int PxArticulationJoint_getDriveType(physx_PxArticulationJoint_Pod const* self__pod) {
physx::PxArticulationJoint const* self_ = reinterpret_cast<physx::PxArticulationJoint const*>(self__pod);
PxArticulationJointDriveType::Enum returnValue = self_->getDriveType();
unsigned int returnValue_pod = (unsigned int)returnValue;
return returnValue_pod;
}

void PxArticulationJoint_setStiffness_mut(physx_PxArticulationJoint_Pod* self__pod, float spring) {
physx::PxArticulationJoint* self_ = reinterpret_cast<physx::PxArticulationJoint*>(self__pod);
self_->setStiffness(spring);
}

float PxArticulationJoint_getStiffness(physx_PxArticulationJoint_Pod const* self__pod) {
physx::PxArticulationJoint const* self_ = reinterpret_cast<physx::PxArticulationJoint const*>(self__pod);
float returnValue = self_->getStiffness();
return returnValue;
}

void PxArticulationJoint_setDamping_mut(physx_PxArticulationJoint_Pod* self__pod, float damping) {
physx::PxArticulationJoint* self_ = reinterpret_cast<physx::PxArticulationJoint*>(self__pod);
self_->setDamping(damping);
}

float PxArticulationJoint_getDamping(physx_PxArticulationJoint_Pod const* self__pod) {
physx::PxArticulationJoint const* self_ = reinterpret_cast<physx::PxArticulationJoint const*>(self__pod);
float returnValue = self_->getDamping();
return returnValue;
}

void PxArticulationJoint_setInternalCompliance_mut(physx_PxArticulationJoint_Pod* self__pod, float compliance) {
physx::PxArticulationJoint* self_ = reinterpret_cast<physx::PxArticulationJoint*>(self__pod);
self_->setInternalCompliance(compliance);
}

float PxArticulationJoint_getInternalCompliance(physx_PxArticulationJoint_Pod const* self__pod) {
physx::PxArticulationJoint const* self_ = reinterpret_cast<physx::PxArticulationJoint const*>(self__pod);
float returnValue = self_->getInternalCompliance();
return returnValue;
}

void PxArticulationJoint_setExternalCompliance_mut(physx_PxArticulationJoint_Pod* self__pod, float compliance) {
physx::PxArticulationJoint* self_ = reinterpret_cast<physx::PxArticulationJoint*>(self__pod);
self_->setExternalCompliance(compliance);
}

float PxArticulationJoint_getExternalCompliance(physx_PxArticulationJoint_Pod const* self__pod) {
physx::PxArticulationJoint const* self_ = reinterpret_cast<physx::PxArticulationJoint const*>(self__pod);
float returnValue = self_->getExternalCompliance();
return returnValue;
}

void PxArticulationJoint_setSwingLimit_mut(physx_PxArticulationJoint_Pod* self__pod, float zLimit, float yLimit) {
physx::PxArticulationJoint* self_ = reinterpret_cast<physx::PxArticulationJoint*>(self__pod);
self_->setSwingLimit(zLimit, yLimit);
}

void PxArticulationJoint_getSwingLimit(physx_PxArticulationJoint_Pod const* self__pod, float* zLimit_pod, float* yLimit_pod) {
physx::PxArticulationJoint const* self_ = reinterpret_cast<physx::PxArticulationJoint const*>(self__pod);
float& zLimit = *zLimit_pod;
float& yLimit = *yLimit_pod;
self_->getSwingLimit(zLimit, yLimit);
}

void PxArticulationJoint_setTangentialStiffness_mut(physx_PxArticulationJoint_Pod* self__pod, float spring) {
physx::PxArticulationJoint* self_ = reinterpret_cast<physx::PxArticulationJoint*>(self__pod);
self_->setTangentialStiffness(spring);
}

float PxArticulationJoint_getTangentialStiffness(physx_PxArticulationJoint_Pod const* self__pod) {
physx::PxArticulationJoint const* self_ = reinterpret_cast<physx::PxArticulationJoint const*>(self__pod);
float returnValue = self_->getTangentialStiffness();
return returnValue;
}

void PxArticulationJoint_setTangentialDamping_mut(physx_PxArticulationJoint_Pod* self__pod, float damping) {
physx::PxArticulationJoint* self_ = reinterpret_cast<physx::PxArticulationJoint*>(self__pod);
self_->setTangentialDamping(damping);
}

float PxArticulationJoint_getTangentialDamping(physx_PxArticulationJoint_Pod const* self__pod) {
physx::PxArticulationJoint const* self_ = reinterpret_cast<physx::PxArticulationJoint const*>(self__pod);
float returnValue = self_->getTangentialDamping();
return returnValue;
}

void PxArticulationJoint_setSwingLimitContactDistance_mut(physx_PxArticulationJoint_Pod* self__pod, float contactDistance) {
physx::PxArticulationJoint* self_ = reinterpret_cast<physx::PxArticulationJoint*>(self__pod);
self_->setSwingLimitContactDistance(contactDistance);
}

float PxArticulationJoint_getSwingLimitContactDistance(physx_PxArticulationJoint_Pod const* self__pod) {
physx::PxArticulationJoint const* self_ = reinterpret_cast<physx::PxArticulationJoint const*>(self__pod);
float returnValue = self_->getSwingLimitContactDistance();
return returnValue;
}

void PxArticulationJoint_setSwingLimitEnabled_mut(physx_PxArticulationJoint_Pod* self__pod, bool enabled) {
physx::PxArticulationJoint* self_ = reinterpret_cast<physx::PxArticulationJoint*>(self__pod);
self_->setSwingLimitEnabled(enabled);
}

bool PxArticulationJoint_getSwingLimitEnabled(physx_PxArticulationJoint_Pod const* self__pod) {
physx::PxArticulationJoint const* self_ = reinterpret_cast<physx::PxArticulationJoint const*>(self__pod);
bool returnValue = self_->getSwingLimitEnabled();
return returnValue;
}

void PxArticulationJoint_setTwistLimit_mut(physx_PxArticulationJoint_Pod* self__pod, float lower, float upper) {
physx::PxArticulationJoint* self_ = reinterpret_cast<physx::PxArticulationJoint*>(self__pod);
self_->setTwistLimit(lower, upper);
}

void PxArticulationJoint_getTwistLimit(physx_PxArticulationJoint_Pod const* self__pod, float* lower_pod, float* upper_pod) {
physx::PxArticulationJoint const* self_ = reinterpret_cast<physx::PxArticulationJoint const*>(self__pod);
float& lower = *lower_pod;
float& upper = *upper_pod;
self_->getTwistLimit(lower, upper);
}

void PxArticulationJoint_setTwistLimitEnabled_mut(physx_PxArticulationJoint_Pod* self__pod, bool enabled) {
physx::PxArticulationJoint* self_ = reinterpret_cast<physx::PxArticulationJoint*>(self__pod);
self_->setTwistLimitEnabled(enabled);
}

bool PxArticulationJoint_getTwistLimitEnabled(physx_PxArticulationJoint_Pod const* self__pod) {
physx::PxArticulationJoint const* self_ = reinterpret_cast<physx::PxArticulationJoint const*>(self__pod);
bool returnValue = self_->getTwistLimitEnabled();
return returnValue;
}

void PxArticulationJoint_setTwistLimitContactDistance_mut(physx_PxArticulationJoint_Pod* self__pod, float contactDistance) {
physx::PxArticulationJoint* self_ = reinterpret_cast<physx::PxArticulationJoint*>(self__pod);
self_->setTwistLimitContactDistance(contactDistance);
}

float PxArticulationJoint_getTwistLimitContactDistance(physx_PxArticulationJoint_Pod const* self__pod) {
physx::PxArticulationJoint const* self_ = reinterpret_cast<physx::PxArticulationJoint const*>(self__pod);
float returnValue = self_->getTwistLimitContactDistance();
return returnValue;
}

char const* PxArticulationJoint_getConcreteTypeName(physx_PxArticulationJoint_Pod const* self__pod) {
physx::PxArticulationJoint const* self_ = reinterpret_cast<physx::PxArticulationJoint const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

void PxArticulationJointReducedCoordinate_setJointType_mut(physx_PxArticulationJointReducedCoordinate_Pod* self__pod, unsigned int jointType_pod) {
physx::PxArticulationJointReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate*>(self__pod);
PxArticulationJointType::Enum jointType = (PxArticulationJointType::Enum)jointType_pod;
self_->setJointType(jointType);
}

unsigned int PxArticulationJointReducedCoordinate_getJointType(physx_PxArticulationJointReducedCoordinate_Pod const* self__pod) {
physx::PxArticulationJointReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate const*>(self__pod);
PxArticulationJointType::Enum returnValue = self_->getJointType();
unsigned int returnValue_pod = (unsigned int)returnValue;
return returnValue_pod;
}

void PxArticulationJointReducedCoordinate_setMotion_mut(physx_PxArticulationJointReducedCoordinate_Pod* self__pod, unsigned int axis_pod, unsigned int motion_pod) {
physx::PxArticulationJointReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate*>(self__pod);
PxArticulationAxis::Enum axis = (PxArticulationAxis::Enum)axis_pod;
PxArticulationMotion::Enum motion = (PxArticulationMotion::Enum)motion_pod;
self_->setMotion(axis, motion);
}

unsigned int PxArticulationJointReducedCoordinate_getMotion(physx_PxArticulationJointReducedCoordinate_Pod const* self__pod, unsigned int axis_pod) {
physx::PxArticulationJointReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate const*>(self__pod);
PxArticulationAxis::Enum axis = (PxArticulationAxis::Enum)axis_pod;
PxArticulationMotion::Enum returnValue = self_->getMotion(axis);
unsigned int returnValue_pod = (unsigned int)returnValue;
return returnValue_pod;
}

void PxArticulationJointReducedCoordinate_setLimit_mut(physx_PxArticulationJointReducedCoordinate_Pod* self__pod, unsigned int axis_pod, float lowLimit, float highLimit) {
physx::PxArticulationJointReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate*>(self__pod);
PxArticulationAxis::Enum axis = (PxArticulationAxis::Enum)axis_pod;
self_->setLimit(axis, lowLimit, highLimit);
}

void PxArticulationJointReducedCoordinate_getLimit_mut(physx_PxArticulationJointReducedCoordinate_Pod* self__pod, unsigned int axis_pod, float* lowLimit_pod, float* highLimit_pod) {
physx::PxArticulationJointReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate*>(self__pod);
PxArticulationAxis::Enum axis = (PxArticulationAxis::Enum)axis_pod;
float& lowLimit = *lowLimit_pod;
float& highLimit = *highLimit_pod;
self_->getLimit(axis, lowLimit, highLimit);
}

void PxArticulationJointReducedCoordinate_setDrive_mut(physx_PxArticulationJointReducedCoordinate_Pod* self__pod, unsigned int axis_pod, float stiffness, float damping, float maxForce, unsigned int driveType_pod) {
physx::PxArticulationJointReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate*>(self__pod);
PxArticulationAxis::Enum axis = (PxArticulationAxis::Enum)axis_pod;
PxArticulationDriveType::Enum driveType = (PxArticulationDriveType::Enum)driveType_pod;
self_->setDrive(axis, stiffness, damping, maxForce, driveType);
}

void PxArticulationJointReducedCoordinate_getDrive_mut(physx_PxArticulationJointReducedCoordinate_Pod* self__pod, unsigned int axis_pod, float* stiffness_pod, float* damping_pod, float* maxForce_pod, unsigned int* driveType_pod) {
physx::PxArticulationJointReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate*>(self__pod);
PxArticulationAxis::Enum axis = (PxArticulationAxis::Enum)axis_pod;
float& stiffness = *stiffness_pod;
float& damping = *damping_pod;
float& maxForce = *maxForce_pod;
PxArticulationDriveType::Enum& driveType = reinterpret_cast<PxArticulationDriveType::Enum&>(*driveType_pod);
self_->getDrive(axis, stiffness, damping, maxForce, driveType);
}

void PxArticulationJointReducedCoordinate_setDriveTarget_mut(physx_PxArticulationJointReducedCoordinate_Pod* self__pod, unsigned int axis_pod, float target) {
physx::PxArticulationJointReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate*>(self__pod);
PxArticulationAxis::Enum axis = (PxArticulationAxis::Enum)axis_pod;
self_->setDriveTarget(axis, target);
}

void PxArticulationJointReducedCoordinate_setDriveVelocity_mut(physx_PxArticulationJointReducedCoordinate_Pod* self__pod, unsigned int axis_pod, float targetVel) {
physx::PxArticulationJointReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate*>(self__pod);
PxArticulationAxis::Enum axis = (PxArticulationAxis::Enum)axis_pod;
self_->setDriveVelocity(axis, targetVel);
}

float PxArticulationJointReducedCoordinate_getDriveTarget_mut(physx_PxArticulationJointReducedCoordinate_Pod* self__pod, unsigned int axis_pod) {
physx::PxArticulationJointReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate*>(self__pod);
PxArticulationAxis::Enum axis = (PxArticulationAxis::Enum)axis_pod;
float returnValue = self_->getDriveTarget(axis);
return returnValue;
}

float PxArticulationJointReducedCoordinate_getDriveVelocity_mut(physx_PxArticulationJointReducedCoordinate_Pod* self__pod, unsigned int axis_pod) {
physx::PxArticulationJointReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate*>(self__pod);
PxArticulationAxis::Enum axis = (PxArticulationAxis::Enum)axis_pod;
float returnValue = self_->getDriveVelocity(axis);
return returnValue;
}

void PxArticulationJointReducedCoordinate_setFrictionCoefficient_mut(physx_PxArticulationJointReducedCoordinate_Pod* self__pod, float coefficient) {
physx::PxArticulationJointReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate*>(self__pod);
self_->setFrictionCoefficient(coefficient);
}

float PxArticulationJointReducedCoordinate_getFrictionCoefficient(physx_PxArticulationJointReducedCoordinate_Pod const* self__pod) {
physx::PxArticulationJointReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate const*>(self__pod);
float returnValue = self_->getFrictionCoefficient();
return returnValue;
}

char const* PxArticulationJointReducedCoordinate_getConcreteTypeName(physx_PxArticulationJointReducedCoordinate_Pod const* self__pod) {
physx::PxArticulationJointReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

void PxArticulationJointReducedCoordinate_setMaxJointVelocity_mut(physx_PxArticulationJointReducedCoordinate_Pod* self__pod, float maxJointV) {
physx::PxArticulationJointReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate*>(self__pod);
self_->setMaxJointVelocity(maxJointV);
}

float PxArticulationJointReducedCoordinate_getMaxJointVelocity(physx_PxArticulationJointReducedCoordinate_Pod const* self__pod) {
physx::PxArticulationJointReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate const*>(self__pod);
float returnValue = self_->getMaxJointVelocity();
return returnValue;
}

void PxShape_release_mut(physx_PxShape_Pod* self__pod) {
physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
self_->release();
}

uint32_t PxShape_getReferenceCount(physx_PxShape_Pod const* self__pod) {
physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
uint32_t returnValue = self_->getReferenceCount();
return returnValue;
}

void PxShape_acquireReference_mut(physx_PxShape_Pod* self__pod) {
physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
self_->acquireReference();
}

int PxShape_getGeometryType(physx_PxShape_Pod const* self__pod) {
physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
PxGeometryType::Enum returnValue = self_->getGeometryType();
int returnValue_pod = (int)returnValue;
return returnValue_pod;
}

void PxShape_setGeometry_mut(physx_PxShape_Pod* self__pod, physx_PxGeometry_Pod const* geometry_pod) {
physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
self_->setGeometry(geometry);
}

physx_PxGeometryHolder_Pod PxShape_getGeometry(physx_PxShape_Pod const* self__pod) {
physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
physx::PxGeometryHolder returnValue = self_->getGeometry();
physx_PxGeometryHolder_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxShape_getBoxGeometry(physx_PxShape_Pod const* self__pod, physx_PxBoxGeometry_Pod* geometry_pod) {
physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
physx::PxBoxGeometry& geometry = reinterpret_cast<physx::PxBoxGeometry&>(*geometry_pod);
bool returnValue = self_->getBoxGeometry(geometry);
return returnValue;
}

bool PxShape_getSphereGeometry(physx_PxShape_Pod const* self__pod, physx_PxSphereGeometry_Pod* geometry_pod) {
physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
physx::PxSphereGeometry& geometry = reinterpret_cast<physx::PxSphereGeometry&>(*geometry_pod);
bool returnValue = self_->getSphereGeometry(geometry);
return returnValue;
}

bool PxShape_getCapsuleGeometry(physx_PxShape_Pod const* self__pod, physx_PxCapsuleGeometry_Pod* geometry_pod) {
physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
physx::PxCapsuleGeometry& geometry = reinterpret_cast<physx::PxCapsuleGeometry&>(*geometry_pod);
bool returnValue = self_->getCapsuleGeometry(geometry);
return returnValue;
}

bool PxShape_getPlaneGeometry(physx_PxShape_Pod const* self__pod, physx_PxPlaneGeometry_Pod* geometry_pod) {
physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
physx::PxPlaneGeometry& geometry = reinterpret_cast<physx::PxPlaneGeometry&>(*geometry_pod);
bool returnValue = self_->getPlaneGeometry(geometry);
return returnValue;
}

bool PxShape_getConvexMeshGeometry(physx_PxShape_Pod const* self__pod, physx_PxConvexMeshGeometry_Pod* geometry_pod) {
physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
physx::PxConvexMeshGeometry& geometry = reinterpret_cast<physx::PxConvexMeshGeometry&>(*geometry_pod);
bool returnValue = self_->getConvexMeshGeometry(geometry);
return returnValue;
}

bool PxShape_getTriangleMeshGeometry(physx_PxShape_Pod const* self__pod, physx_PxTriangleMeshGeometry_Pod* geometry_pod) {
physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
physx::PxTriangleMeshGeometry& geometry = reinterpret_cast<physx::PxTriangleMeshGeometry&>(*geometry_pod);
bool returnValue = self_->getTriangleMeshGeometry(geometry);
return returnValue;
}

bool PxShape_getHeightFieldGeometry(physx_PxShape_Pod const* self__pod, physx_PxHeightFieldGeometry_Pod* geometry_pod) {
physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
physx::PxHeightFieldGeometry& geometry = reinterpret_cast<physx::PxHeightFieldGeometry&>(*geometry_pod);
bool returnValue = self_->getHeightFieldGeometry(geometry);
return returnValue;
}

physx_PxRigidActor_Pod* PxShape_getActor(physx_PxShape_Pod const* self__pod) {
physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
physx::PxRigidActor* returnValue = self_->getActor();
physx_PxRigidActor_Pod* returnValue_pod = reinterpret_cast<physx_PxRigidActor_Pod*>(returnValue);
return returnValue_pod;
}

void PxShape_setLocalPose_mut(physx_PxShape_Pod* self__pod, physx_PxTransform_Pod const* pose_pod) {
physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
self_->setLocalPose(pose);
}

physx_PxTransform_Pod PxShape_getLocalPose(physx_PxShape_Pod const* self__pod) {
physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
physx::PxTransform returnValue = self_->getLocalPose();
physx_PxTransform_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxShape_setSimulationFilterData_mut(physx_PxShape_Pod* self__pod, physx_PxFilterData_Pod const* data_pod) {
physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
physx::PxFilterData const& data = reinterpret_cast<physx::PxFilterData const&>(*data_pod);
self_->setSimulationFilterData(data);
}

physx_PxFilterData_Pod PxShape_getSimulationFilterData(physx_PxShape_Pod const* self__pod) {
physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
physx::PxFilterData returnValue = self_->getSimulationFilterData();
physx_PxFilterData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxShape_setQueryFilterData_mut(physx_PxShape_Pod* self__pod, physx_PxFilterData_Pod const* data_pod) {
physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
physx::PxFilterData const& data = reinterpret_cast<physx::PxFilterData const&>(*data_pod);
self_->setQueryFilterData(data);
}

physx_PxFilterData_Pod PxShape_getQueryFilterData(physx_PxShape_Pod const* self__pod) {
physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
physx::PxFilterData returnValue = self_->getQueryFilterData();
physx_PxFilterData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxShape_setMaterials_mut(physx_PxShape_Pod* self__pod, physx_PxMaterial_Pod* const* materials_pod, uint16_t materialCount) {
physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
physx::PxMaterial* const* materials = reinterpret_cast<physx::PxMaterial* const*>(materials_pod);
self_->setMaterials(materials, materialCount);
}

uint16_t PxShape_getNbMaterials(physx_PxShape_Pod const* self__pod) {
physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
uint16_t returnValue = self_->getNbMaterials();
return returnValue;
}

uint32_t PxShape_getMaterials(physx_PxShape_Pod const* self__pod, physx_PxMaterial_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
physx::PxMaterial** userBuffer = reinterpret_cast<physx::PxMaterial**>(userBuffer_pod);
uint32_t returnValue = self_->getMaterials(userBuffer, bufferSize, startIndex);
return returnValue;
}

physx_PxMaterial_Pod* PxShape_getMaterialFromInternalFaceIndex(physx_PxShape_Pod const* self__pod, uint32_t faceIndex) {
physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
physx::PxMaterial* returnValue = self_->getMaterialFromInternalFaceIndex(faceIndex);
physx_PxMaterial_Pod* returnValue_pod = reinterpret_cast<physx_PxMaterial_Pod*>(returnValue);
return returnValue_pod;
}

void PxShape_setContactOffset_mut(physx_PxShape_Pod* self__pod, float contactOffset) {
physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
self_->setContactOffset(contactOffset);
}

float PxShape_getContactOffset(physx_PxShape_Pod const* self__pod) {
physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
float returnValue = self_->getContactOffset();
return returnValue;
}

void PxShape_setRestOffset_mut(physx_PxShape_Pod* self__pod, float restOffset) {
physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
self_->setRestOffset(restOffset);
}

float PxShape_getRestOffset(physx_PxShape_Pod const* self__pod) {
physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
float returnValue = self_->getRestOffset();
return returnValue;
}

void PxShape_setTorsionalPatchRadius_mut(physx_PxShape_Pod* self__pod, float radius) {
physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
self_->setTorsionalPatchRadius(radius);
}

float PxShape_getTorsionalPatchRadius(physx_PxShape_Pod const* self__pod) {
physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
float returnValue = self_->getTorsionalPatchRadius();
return returnValue;
}

void PxShape_setMinTorsionalPatchRadius_mut(physx_PxShape_Pod* self__pod, float radius) {
physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
self_->setMinTorsionalPatchRadius(radius);
}

float PxShape_getMinTorsionalPatchRadius(physx_PxShape_Pod const* self__pod) {
physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
float returnValue = self_->getMinTorsionalPatchRadius();
return returnValue;
}

void PxShape_setFlag_mut(physx_PxShape_Pod* self__pod, unsigned int flag_pod, bool value) {
physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
PxShapeFlag::Enum flag = (PxShapeFlag::Enum)flag_pod;
self_->setFlag(flag, value);
}

void PxShape_setFlags_mut(physx_PxShape_Pod* self__pod, physx_PxShapeFlags_Pod inFlags_pod) {
physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
physx::PxShapeFlags inFlags;
memcpy(&inFlags, &inFlags_pod, sizeof(inFlags));
self_->setFlags(inFlags);
}

physx_PxShapeFlags_Pod PxShape_getFlags(physx_PxShape_Pod const* self__pod) {
physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
physx::PxShapeFlags returnValue = self_->getFlags();
physx_PxShapeFlags_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxShape_isExclusive(physx_PxShape_Pod const* self__pod) {
physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
bool returnValue = self_->isExclusive();
return returnValue;
}

void PxShape_setName_mut(physx_PxShape_Pod* self__pod, char const* name) {
physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
self_->setName(name);
}

char const* PxShape_getName(physx_PxShape_Pod const* self__pod) {
physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
char const* returnValue = self_->getName();
return returnValue;
}

char const* PxShape_getConcreteTypeName(physx_PxShape_Pod const* self__pod) {
physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

void PxRigidActor_release_mut(physx_PxRigidActor_Pod* self__pod) {
physx::PxRigidActor* self_ = reinterpret_cast<physx::PxRigidActor*>(self__pod);
self_->release();
}

physx_PxTransform_Pod PxRigidActor_getGlobalPose(physx_PxRigidActor_Pod const* self__pod) {
physx::PxRigidActor const* self_ = reinterpret_cast<physx::PxRigidActor const*>(self__pod);
physx::PxTransform returnValue = self_->getGlobalPose();
physx_PxTransform_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxRigidActor_setGlobalPose_mut(physx_PxRigidActor_Pod* self__pod, physx_PxTransform_Pod const* pose_pod, bool autowake) {
physx::PxRigidActor* self_ = reinterpret_cast<physx::PxRigidActor*>(self__pod);
physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
self_->setGlobalPose(pose, autowake);
}

bool PxRigidActor_attachShape_mut(physx_PxRigidActor_Pod* self__pod, physx_PxShape_Pod* shape_pod) {
physx::PxRigidActor* self_ = reinterpret_cast<physx::PxRigidActor*>(self__pod);
physx::PxShape& shape = reinterpret_cast<physx::PxShape&>(*shape_pod);
bool returnValue = self_->attachShape(shape);
return returnValue;
}

void PxRigidActor_detachShape_mut(physx_PxRigidActor_Pod* self__pod, physx_PxShape_Pod* shape_pod, bool wakeOnLostTouch) {
physx::PxRigidActor* self_ = reinterpret_cast<physx::PxRigidActor*>(self__pod);
physx::PxShape& shape = reinterpret_cast<physx::PxShape&>(*shape_pod);
self_->detachShape(shape, wakeOnLostTouch);
}

uint32_t PxRigidActor_getNbShapes(physx_PxRigidActor_Pod const* self__pod) {
physx::PxRigidActor const* self_ = reinterpret_cast<physx::PxRigidActor const*>(self__pod);
uint32_t returnValue = self_->getNbShapes();
return returnValue;
}

uint32_t PxRigidActor_getShapes(physx_PxRigidActor_Pod const* self__pod, physx_PxShape_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
physx::PxRigidActor const* self_ = reinterpret_cast<physx::PxRigidActor const*>(self__pod);
physx::PxShape** userBuffer = reinterpret_cast<physx::PxShape**>(userBuffer_pod);
uint32_t returnValue = self_->getShapes(userBuffer, bufferSize, startIndex);
return returnValue;
}

uint32_t PxRigidActor_getNbConstraints(physx_PxRigidActor_Pod const* self__pod) {
physx::PxRigidActor const* self_ = reinterpret_cast<physx::PxRigidActor const*>(self__pod);
uint32_t returnValue = self_->getNbConstraints();
return returnValue;
}

uint32_t PxRigidActor_getConstraints(physx_PxRigidActor_Pod const* self__pod, physx_PxConstraint_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
physx::PxRigidActor const* self_ = reinterpret_cast<physx::PxRigidActor const*>(self__pod);
physx::PxConstraint** userBuffer = reinterpret_cast<physx::PxConstraint**>(userBuffer_pod);
uint32_t returnValue = self_->getConstraints(userBuffer, bufferSize, startIndex);
return returnValue;
}

void PxRigidBody_setCMassLocalPose_mut(physx_PxRigidBody_Pod* self__pod, physx_PxTransform_Pod const* pose_pod) {
physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
self_->setCMassLocalPose(pose);
}

physx_PxTransform_Pod PxRigidBody_getCMassLocalPose(physx_PxRigidBody_Pod const* self__pod) {
physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
physx::PxTransform returnValue = self_->getCMassLocalPose();
physx_PxTransform_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxRigidBody_setMass_mut(physx_PxRigidBody_Pod* self__pod, float mass) {
physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
self_->setMass(mass);
}

float PxRigidBody_getMass(physx_PxRigidBody_Pod const* self__pod) {
physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
float returnValue = self_->getMass();
return returnValue;
}

float PxRigidBody_getInvMass(physx_PxRigidBody_Pod const* self__pod) {
physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
float returnValue = self_->getInvMass();
return returnValue;
}

void PxRigidBody_setMassSpaceInertiaTensor_mut(physx_PxRigidBody_Pod* self__pod, physx_PxVec3_Pod const* m_pod) {
physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
physx::PxVec3 const& m = reinterpret_cast<physx::PxVec3 const&>(*m_pod);
self_->setMassSpaceInertiaTensor(m);
}

physx_PxVec3_Pod PxRigidBody_getMassSpaceInertiaTensor(physx_PxRigidBody_Pod const* self__pod) {
physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
physx::PxVec3 returnValue = self_->getMassSpaceInertiaTensor();
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxRigidBody_getMassSpaceInvInertiaTensor(physx_PxRigidBody_Pod const* self__pod) {
physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
physx::PxVec3 returnValue = self_->getMassSpaceInvInertiaTensor();
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxRigidBody_setLinearDamping_mut(physx_PxRigidBody_Pod* self__pod, float linDamp) {
physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
self_->setLinearDamping(linDamp);
}

float PxRigidBody_getLinearDamping(physx_PxRigidBody_Pod const* self__pod) {
physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
float returnValue = self_->getLinearDamping();
return returnValue;
}

void PxRigidBody_setAngularDamping_mut(physx_PxRigidBody_Pod* self__pod, float angDamp) {
physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
self_->setAngularDamping(angDamp);
}

float PxRigidBody_getAngularDamping(physx_PxRigidBody_Pod const* self__pod) {
physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
float returnValue = self_->getAngularDamping();
return returnValue;
}

physx_PxVec3_Pod PxRigidBody_getLinearVelocity(physx_PxRigidBody_Pod const* self__pod) {
physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
physx::PxVec3 returnValue = self_->getLinearVelocity();
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxRigidBody_setLinearVelocity_mut(physx_PxRigidBody_Pod* self__pod, physx_PxVec3_Pod const* linVel_pod, bool autowake) {
physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
physx::PxVec3 const& linVel = reinterpret_cast<physx::PxVec3 const&>(*linVel_pod);
self_->setLinearVelocity(linVel, autowake);
}

physx_PxVec3_Pod PxRigidBody_getAngularVelocity(physx_PxRigidBody_Pod const* self__pod) {
physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
physx::PxVec3 returnValue = self_->getAngularVelocity();
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxRigidBody_setAngularVelocity_mut(physx_PxRigidBody_Pod* self__pod, physx_PxVec3_Pod const* angVel_pod, bool autowake) {
physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
physx::PxVec3 const& angVel = reinterpret_cast<physx::PxVec3 const&>(*angVel_pod);
self_->setAngularVelocity(angVel, autowake);
}

void PxRigidBody_setMaxAngularVelocity_mut(physx_PxRigidBody_Pod* self__pod, float maxAngVel) {
physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
self_->setMaxAngularVelocity(maxAngVel);
}

float PxRigidBody_getMaxAngularVelocity(physx_PxRigidBody_Pod const* self__pod) {
physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
float returnValue = self_->getMaxAngularVelocity();
return returnValue;
}

void PxRigidBody_setMaxLinearVelocity_mut(physx_PxRigidBody_Pod* self__pod, float maxLinVel) {
physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
self_->setMaxLinearVelocity(maxLinVel);
}

float PxRigidBody_getMaxLinearVelocity(physx_PxRigidBody_Pod const* self__pod) {
physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
float returnValue = self_->getMaxLinearVelocity();
return returnValue;
}

void PxRigidBody_addForce_mut(physx_PxRigidBody_Pod* self__pod, physx_PxVec3_Pod const* force_pod, unsigned int mode_pod, bool autowake) {
physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
physx::PxVec3 const& force = reinterpret_cast<physx::PxVec3 const&>(*force_pod);
PxForceMode::Enum mode = (PxForceMode::Enum)mode_pod;
self_->addForce(force, mode, autowake);
}

void PxRigidBody_addTorque_mut(physx_PxRigidBody_Pod* self__pod, physx_PxVec3_Pod const* torque_pod, unsigned int mode_pod, bool autowake) {
physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
physx::PxVec3 const& torque = reinterpret_cast<physx::PxVec3 const&>(*torque_pod);
PxForceMode::Enum mode = (PxForceMode::Enum)mode_pod;
self_->addTorque(torque, mode, autowake);
}

void PxRigidBody_clearForce_mut(physx_PxRigidBody_Pod* self__pod, unsigned int mode_pod) {
physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
PxForceMode::Enum mode = (PxForceMode::Enum)mode_pod;
self_->clearForce(mode);
}

void PxRigidBody_clearTorque_mut(physx_PxRigidBody_Pod* self__pod, unsigned int mode_pod) {
physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
PxForceMode::Enum mode = (PxForceMode::Enum)mode_pod;
self_->clearTorque(mode);
}

void PxRigidBody_setForceAndTorque_mut(physx_PxRigidBody_Pod* self__pod, physx_PxVec3_Pod const* force_pod, physx_PxVec3_Pod const* torque_pod, unsigned int mode_pod) {
physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
physx::PxVec3 const& force = reinterpret_cast<physx::PxVec3 const&>(*force_pod);
physx::PxVec3 const& torque = reinterpret_cast<physx::PxVec3 const&>(*torque_pod);
PxForceMode::Enum mode = (PxForceMode::Enum)mode_pod;
self_->setForceAndTorque(force, torque, mode);
}

void PxRigidBody_setRigidBodyFlag_mut(physx_PxRigidBody_Pod* self__pod, unsigned int flag_pod, bool value) {
physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
PxRigidBodyFlag::Enum flag = (PxRigidBodyFlag::Enum)flag_pod;
self_->setRigidBodyFlag(flag, value);
}

void PxRigidBody_setRigidBodyFlags_mut(physx_PxRigidBody_Pod* self__pod, physx_PxRigidBodyFlags_Pod inFlags_pod) {
physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
physx::PxRigidBodyFlags inFlags;
memcpy(&inFlags, &inFlags_pod, sizeof(inFlags));
self_->setRigidBodyFlags(inFlags);
}

physx_PxRigidBodyFlags_Pod PxRigidBody_getRigidBodyFlags(physx_PxRigidBody_Pod const* self__pod) {
physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
physx::PxRigidBodyFlags returnValue = self_->getRigidBodyFlags();
physx_PxRigidBodyFlags_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxRigidBody_setMinCCDAdvanceCoefficient_mut(physx_PxRigidBody_Pod* self__pod, float advanceCoefficient) {
physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
self_->setMinCCDAdvanceCoefficient(advanceCoefficient);
}

float PxRigidBody_getMinCCDAdvanceCoefficient(physx_PxRigidBody_Pod const* self__pod) {
physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
float returnValue = self_->getMinCCDAdvanceCoefficient();
return returnValue;
}

void PxRigidBody_setMaxDepenetrationVelocity_mut(physx_PxRigidBody_Pod* self__pod, float biasClamp) {
physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
self_->setMaxDepenetrationVelocity(biasClamp);
}

float PxRigidBody_getMaxDepenetrationVelocity(physx_PxRigidBody_Pod const* self__pod) {
physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
float returnValue = self_->getMaxDepenetrationVelocity();
return returnValue;
}

void PxRigidBody_setMaxContactImpulse_mut(physx_PxRigidBody_Pod* self__pod, float maxImpulse) {
physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
self_->setMaxContactImpulse(maxImpulse);
}

float PxRigidBody_getMaxContactImpulse(physx_PxRigidBody_Pod const* self__pod) {
physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
float returnValue = self_->getMaxContactImpulse();
return returnValue;
}

uint32_t PxRigidBody_getInternalIslandNodeIndex(physx_PxRigidBody_Pod const* self__pod) {
physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
uint32_t returnValue = self_->getInternalIslandNodeIndex();
return returnValue;
}

void PxArticulationLink_release_mut(physx_PxArticulationLink_Pod* self__pod) {
physx::PxArticulationLink* self_ = reinterpret_cast<physx::PxArticulationLink*>(self__pod);
self_->release();
}

physx_PxArticulationBase_Pod* PxArticulationLink_getArticulation(physx_PxArticulationLink_Pod const* self__pod) {
physx::PxArticulationLink const* self_ = reinterpret_cast<physx::PxArticulationLink const*>(self__pod);
physx::PxArticulationBase& returnValue = self_->getArticulation();
physx_PxArticulationBase_Pod* returnValue_pod = reinterpret_cast<physx_PxArticulationBase_Pod*>(&returnValue);
return returnValue_pod;
}

physx_PxArticulationJointBase_Pod* PxArticulationLink_getInboundJoint(physx_PxArticulationLink_Pod const* self__pod) {
physx::PxArticulationLink const* self_ = reinterpret_cast<physx::PxArticulationLink const*>(self__pod);
physx::PxArticulationJointBase* returnValue = self_->getInboundJoint();
physx_PxArticulationJointBase_Pod* returnValue_pod = reinterpret_cast<physx_PxArticulationJointBase_Pod*>(returnValue);
return returnValue_pod;
}

uint32_t PxArticulationLink_getInboundJointDof(physx_PxArticulationLink_Pod const* self__pod) {
physx::PxArticulationLink const* self_ = reinterpret_cast<physx::PxArticulationLink const*>(self__pod);
uint32_t returnValue = self_->getInboundJointDof();
return returnValue;
}

uint32_t PxArticulationLink_getNbChildren(physx_PxArticulationLink_Pod const* self__pod) {
physx::PxArticulationLink const* self_ = reinterpret_cast<physx::PxArticulationLink const*>(self__pod);
uint32_t returnValue = self_->getNbChildren();
return returnValue;
}

uint32_t PxArticulationLink_getLinkIndex(physx_PxArticulationLink_Pod const* self__pod) {
physx::PxArticulationLink const* self_ = reinterpret_cast<physx::PxArticulationLink const*>(self__pod);
uint32_t returnValue = self_->getLinkIndex();
return returnValue;
}

uint32_t PxArticulationLink_getChildren(physx_PxArticulationLink_Pod const* self__pod, physx_PxArticulationLink_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
physx::PxArticulationLink const* self_ = reinterpret_cast<physx::PxArticulationLink const*>(self__pod);
physx::PxArticulationLink** userBuffer = reinterpret_cast<physx::PxArticulationLink**>(userBuffer_pod);
uint32_t returnValue = self_->getChildren(userBuffer, bufferSize, startIndex);
return returnValue;
}

char const* PxArticulationLink_getConcreteTypeName(physx_PxArticulationLink_Pod const* self__pod) {
physx::PxArticulationLink const* self_ = reinterpret_cast<physx::PxArticulationLink const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

physx_PxFilterData_Pod PxFilterData_new(unsigned int anonymous_arg0_pod) {
physx::PxEMPTY anonymous_arg0 = (physx::PxEMPTY)anonymous_arg0_pod;
physx::PxFilterData returnValue(anonymous_arg0);
physx_PxFilterData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxFilterData_Pod PxFilterData_new_1() {
physx::PxFilterData returnValue;
physx_PxFilterData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxFilterData_Pod PxFilterData_new_2(uint32_t w0, uint32_t w1, uint32_t w2, uint32_t w3) {
physx::PxFilterData returnValue(w0, w1, w2, w3);
physx_PxFilterData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxFilterData_setToDefault_mut(physx_PxFilterData_Pod* self__pod) {
physx::PxFilterData* self_ = reinterpret_cast<physx::PxFilterData*>(self__pod);
self_->setToDefault();
}

unsigned int phys_PxGetFilterObjectType(uint32_t attr) {
PxFilterObjectType::Enum returnValue = PxGetFilterObjectType(attr);
unsigned int returnValue_pod = (unsigned int)returnValue;
return returnValue_pod;
}

bool phys_PxFilterObjectIsKinematic(uint32_t attr) {
bool returnValue = PxFilterObjectIsKinematic(attr);
return returnValue;
}

bool phys_PxFilterObjectIsTrigger(uint32_t attr) {
bool returnValue = PxFilterObjectIsTrigger(attr);
return returnValue;
}

physx_PxFilterFlags_Pod PxSimulationFilterCallback_pairFound_mut(physx_PxSimulationFilterCallback_Pod* self__pod, uint32_t pairID, uint32_t attributes0, physx_PxFilterData_Pod filterData0_pod, physx_PxActor_Pod const* a0_pod, physx_PxShape_Pod const* s0_pod, uint32_t attributes1, physx_PxFilterData_Pod filterData1_pod, physx_PxActor_Pod const* a1_pod, physx_PxShape_Pod const* s1_pod, physx_PxPairFlags_Pod* pairFlags_pod) {
physx::PxSimulationFilterCallback* self_ = reinterpret_cast<physx::PxSimulationFilterCallback*>(self__pod);
physx::PxFilterData filterData0;
memcpy(&filterData0, &filterData0_pod, sizeof(filterData0));
physx::PxActor const* a0 = reinterpret_cast<physx::PxActor const*>(a0_pod);
physx::PxShape const* s0 = reinterpret_cast<physx::PxShape const*>(s0_pod);
physx::PxFilterData filterData1;
memcpy(&filterData1, &filterData1_pod, sizeof(filterData1));
physx::PxActor const* a1 = reinterpret_cast<physx::PxActor const*>(a1_pod);
physx::PxShape const* s1 = reinterpret_cast<physx::PxShape const*>(s1_pod);
physx::PxPairFlags& pairFlags = reinterpret_cast<physx::PxPairFlags&>(*pairFlags_pod);
physx::PxFilterFlags returnValue = self_->pairFound(pairID, attributes0, filterData0, a0, s0, attributes1, filterData1, a1, s1, pairFlags);
physx_PxFilterFlags_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxSimulationFilterCallback_pairLost_mut(physx_PxSimulationFilterCallback_Pod* self__pod, uint32_t pairID, uint32_t attributes0, physx_PxFilterData_Pod filterData0_pod, uint32_t attributes1, physx_PxFilterData_Pod filterData1_pod, bool objectRemoved) {
physx::PxSimulationFilterCallback* self_ = reinterpret_cast<physx::PxSimulationFilterCallback*>(self__pod);
physx::PxFilterData filterData0;
memcpy(&filterData0, &filterData0_pod, sizeof(filterData0));
physx::PxFilterData filterData1;
memcpy(&filterData1, &filterData1_pod, sizeof(filterData1));
self_->pairLost(pairID, attributes0, filterData0, attributes1, filterData1, objectRemoved);
}

bool PxSimulationFilterCallback_statusChange_mut(physx_PxSimulationFilterCallback_Pod* self__pod, uint32_t* pairID_pod, physx_PxPairFlags_Pod* pairFlags_pod, physx_PxFilterFlags_Pod* filterFlags_pod) {
physx::PxSimulationFilterCallback* self_ = reinterpret_cast<physx::PxSimulationFilterCallback*>(self__pod);
uint32_t& pairID = *pairID_pod;
physx::PxPairFlags& pairFlags = reinterpret_cast<physx::PxPairFlags&>(*pairFlags_pod);
physx::PxFilterFlags& filterFlags = reinterpret_cast<physx::PxFilterFlags&>(*filterFlags_pod);
bool returnValue = self_->statusChange(pairID, pairFlags, filterFlags);
return returnValue;
}

physx_PxQueryFilterData_Pod PxQueryFilterData_new() {
physx::PxQueryFilterData returnValue;
physx_PxQueryFilterData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxQueryFilterData_Pod PxQueryFilterData_new_1(physx_PxFilterData_Pod const* fd_pod, physx_PxQueryFlags_Pod f_pod) {
physx::PxFilterData const& fd = reinterpret_cast<physx::PxFilterData const&>(*fd_pod);
physx::PxQueryFlags f;
memcpy(&f, &f_pod, sizeof(f));
physx::PxQueryFilterData returnValue(fd, f);
physx_PxQueryFilterData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxQueryFilterData_Pod PxQueryFilterData_new_2(physx_PxQueryFlags_Pod f_pod) {
physx::PxQueryFlags f;
memcpy(&f, &f_pod, sizeof(f));
physx::PxQueryFilterData returnValue(f);
physx_PxQueryFilterData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

unsigned int PxQueryFilterCallback_preFilter_mut(physx_PxQueryFilterCallback_Pod* self__pod, physx_PxFilterData_Pod const* filterData_pod, physx_PxShape_Pod const* shape_pod, physx_PxRigidActor_Pod const* actor_pod, physx_PxHitFlags_Pod* queryFlags_pod) {
physx::PxQueryFilterCallback* self_ = reinterpret_cast<physx::PxQueryFilterCallback*>(self__pod);
physx::PxFilterData const& filterData = reinterpret_cast<physx::PxFilterData const&>(*filterData_pod);
physx::PxShape const* shape = reinterpret_cast<physx::PxShape const*>(shape_pod);
physx::PxRigidActor const* actor = reinterpret_cast<physx::PxRigidActor const*>(actor_pod);
physx::PxHitFlags& queryFlags = reinterpret_cast<physx::PxHitFlags&>(*queryFlags_pod);
PxQueryHitType::Enum returnValue = self_->preFilter(filterData, shape, actor, queryFlags);
unsigned int returnValue_pod = (unsigned int)returnValue;
return returnValue_pod;
}

unsigned int PxQueryFilterCallback_postFilter_mut(physx_PxQueryFilterCallback_Pod* self__pod, physx_PxFilterData_Pod const* filterData_pod, physx_PxQueryHit_Pod const* hit_pod) {
physx::PxQueryFilterCallback* self_ = reinterpret_cast<physx::PxQueryFilterCallback*>(self__pod);
physx::PxFilterData const& filterData = reinterpret_cast<physx::PxFilterData const&>(*filterData_pod);
physx::PxQueryHit const& hit = reinterpret_cast<physx::PxQueryHit const&>(*hit_pod);
PxQueryHitType::Enum returnValue = self_->postFilter(filterData, hit);
unsigned int returnValue_pod = (unsigned int)returnValue;
return returnValue_pod;
}

void PxQueryFilterCallback_delete(physx_PxQueryFilterCallback_Pod* self__pod) {
physx::PxQueryFilterCallback* self_ = reinterpret_cast<physx::PxQueryFilterCallback*>(self__pod);
delete self_;
}

uint32_t PxBatchQueryMemory_getMaxRaycastsPerExecute(physx_PxBatchQueryMemory_Pod const* self__pod) {
physx::PxBatchQueryMemory const* self_ = reinterpret_cast<physx::PxBatchQueryMemory const*>(self__pod);
uint32_t returnValue = self_->getMaxRaycastsPerExecute();
return returnValue;
}

uint32_t PxBatchQueryMemory_getMaxSweepsPerExecute(physx_PxBatchQueryMemory_Pod const* self__pod) {
physx::PxBatchQueryMemory const* self_ = reinterpret_cast<physx::PxBatchQueryMemory const*>(self__pod);
uint32_t returnValue = self_->getMaxSweepsPerExecute();
return returnValue;
}

uint32_t PxBatchQueryMemory_getMaxOverlapsPerExecute(physx_PxBatchQueryMemory_Pod const* self__pod) {
physx::PxBatchQueryMemory const* self_ = reinterpret_cast<physx::PxBatchQueryMemory const*>(self__pod);
uint32_t returnValue = self_->getMaxOverlapsPerExecute();
return returnValue;
}

physx_PxBatchQueryMemory_Pod PxBatchQueryMemory_new(uint32_t raycastResultBufferSize_, uint32_t sweepResultBufferSize_, uint32_t overlapResultBufferSize_) {
physx::PxBatchQueryMemory returnValue(raycastResultBufferSize_, sweepResultBufferSize_, overlapResultBufferSize_);
physx_PxBatchQueryMemory_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxBatchQueryDesc_Pod PxBatchQueryDesc_new(uint32_t maxRaycastsPerExecute, uint32_t maxSweepsPerExecute, uint32_t maxOverlapsPerExecute) {
physx::PxBatchQueryDesc returnValue(maxRaycastsPerExecute, maxSweepsPerExecute, maxOverlapsPerExecute);
physx_PxBatchQueryDesc_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxBatchQueryDesc_isValid(physx_PxBatchQueryDesc_Pod const* self__pod) {
physx::PxBatchQueryDesc const* self_ = reinterpret_cast<physx::PxBatchQueryDesc const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

physx_PxBatchQueryDesc_Pod PxBatchQueryDesc_new_1(uint32_t maxRaycastsPerExecute, uint32_t maxSweepsPerExecute, uint32_t maxOverlapsPerExecute) {
physx::PxBatchQueryDesc returnValue(maxRaycastsPerExecute, maxSweepsPerExecute, maxOverlapsPerExecute);
physx_PxBatchQueryDesc_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxBatchQueryDesc_isValid_1(physx_PxBatchQueryDesc_Pod const* self__pod) {
physx::PxBatchQueryDesc const* self_ = reinterpret_cast<physx::PxBatchQueryDesc const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

void PxBatchQuery_execute_mut(physx_PxBatchQuery_Pod* self__pod) {
physx::PxBatchQuery* self_ = reinterpret_cast<physx::PxBatchQuery*>(self__pod);
self_->execute();
}

void* PxBatchQuery_getPreFilterShader(physx_PxBatchQuery_Pod const* self__pod) {
physx::PxBatchQuery const* self_ = reinterpret_cast<physx::PxBatchQuery const*>(self__pod);
physx::PxBatchQueryPreFilterShader returnValue = self_->getPreFilterShader();
void* returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void* PxBatchQuery_getPostFilterShader(physx_PxBatchQuery_Pod const* self__pod) {
physx::PxBatchQuery const* self_ = reinterpret_cast<physx::PxBatchQuery const*>(self__pod);
physx::PxBatchQueryPostFilterShader returnValue = self_->getPostFilterShader();
void* returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void const* PxBatchQuery_getFilterShaderData(physx_PxBatchQuery_Pod const* self__pod) {
physx::PxBatchQuery const* self_ = reinterpret_cast<physx::PxBatchQuery const*>(self__pod);
void const* returnValue = self_->getFilterShaderData();
return returnValue;
}

uint32_t PxBatchQuery_getFilterShaderDataSize(physx_PxBatchQuery_Pod const* self__pod) {
physx::PxBatchQuery const* self_ = reinterpret_cast<physx::PxBatchQuery const*>(self__pod);
uint32_t returnValue = self_->getFilterShaderDataSize();
return returnValue;
}

void PxBatchQuery_setUserMemory_mut(physx_PxBatchQuery_Pod* self__pod, physx_PxBatchQueryMemory_Pod const* anonymous_arg0_pod) {
physx::PxBatchQuery* self_ = reinterpret_cast<physx::PxBatchQuery*>(self__pod);
physx::PxBatchQueryMemory const& anonymous_arg0 = reinterpret_cast<physx::PxBatchQueryMemory const&>(*anonymous_arg0_pod);
self_->setUserMemory(anonymous_arg0);
}

physx_PxBatchQueryMemory_Pod const* PxBatchQuery_getUserMemory_mut(physx_PxBatchQuery_Pod* self__pod) {
physx::PxBatchQuery* self_ = reinterpret_cast<physx::PxBatchQuery*>(self__pod);
physx::PxBatchQueryMemory const& returnValue = self_->getUserMemory();
physx_PxBatchQueryMemory_Pod const* returnValue_pod = reinterpret_cast<physx_PxBatchQueryMemory_Pod const*>(&returnValue);
return returnValue_pod;
}

void PxBatchQuery_release_mut(physx_PxBatchQuery_Pod* self__pod) {
physx::PxBatchQuery* self_ = reinterpret_cast<physx::PxBatchQuery*>(self__pod);
self_->release();
}

void PxBatchQuery_raycast_mut(physx_PxBatchQuery_Pod* self__pod, physx_PxVec3_Pod const* origin_pod, physx_PxVec3_Pod const* unitDir_pod, float distance, uint16_t maxTouchHits, physx_PxHitFlags_Pod hitFlags_pod, physx_PxQueryFilterData_Pod const* filterData_pod, void* userData, physx_PxQueryCache_Pod const* cache_pod) {
physx::PxBatchQuery* self_ = reinterpret_cast<physx::PxBatchQuery*>(self__pod);
physx::PxVec3 const& origin = reinterpret_cast<physx::PxVec3 const&>(*origin_pod);
physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
physx::PxHitFlags hitFlags;
memcpy(&hitFlags, &hitFlags_pod, sizeof(hitFlags));
physx::PxQueryFilterData const& filterData = reinterpret_cast<physx::PxQueryFilterData const&>(*filterData_pod);
physx::PxQueryCache const* cache = reinterpret_cast<physx::PxQueryCache const*>(cache_pod);
self_->raycast(origin, unitDir, distance, maxTouchHits, hitFlags, filterData, userData, cache);
}

void PxBatchQuery_overlap_mut(physx_PxBatchQuery_Pod* self__pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxTransform_Pod const* pose_pod, uint16_t maxTouchHits, physx_PxQueryFilterData_Pod const* filterData_pod, void* userData, physx_PxQueryCache_Pod const* cache_pod) {
physx::PxBatchQuery* self_ = reinterpret_cast<physx::PxBatchQuery*>(self__pod);
physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
physx::PxQueryFilterData const& filterData = reinterpret_cast<physx::PxQueryFilterData const&>(*filterData_pod);
physx::PxQueryCache const* cache = reinterpret_cast<physx::PxQueryCache const*>(cache_pod);
self_->overlap(geometry, pose, maxTouchHits, filterData, userData, cache);
}

void PxBatchQuery_sweep_mut(physx_PxBatchQuery_Pod* self__pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxTransform_Pod const* pose_pod, physx_PxVec3_Pod const* unitDir_pod, float distance, uint16_t maxTouchHits, physx_PxHitFlags_Pod hitFlags_pod, physx_PxQueryFilterData_Pod const* filterData_pod, void* userData, physx_PxQueryCache_Pod const* cache_pod, float inflation) {
physx::PxBatchQuery* self_ = reinterpret_cast<physx::PxBatchQuery*>(self__pod);
physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
physx::PxHitFlags hitFlags;
memcpy(&hitFlags, &hitFlags_pod, sizeof(hitFlags));
physx::PxQueryFilterData const& filterData = reinterpret_cast<physx::PxQueryFilterData const&>(*filterData_pod);
physx::PxQueryCache const* cache = reinterpret_cast<physx::PxQueryCache const*>(cache_pod);
self_->sweep(geometry, pose, unitDir, distance, maxTouchHits, hitFlags, filterData, userData, cache, inflation);
}

void PxConstraint_release_mut(physx_PxConstraint_Pod* self__pod) {
physx::PxConstraint* self_ = reinterpret_cast<physx::PxConstraint*>(self__pod);
self_->release();
}

physx_PxScene_Pod* PxConstraint_getScene(physx_PxConstraint_Pod const* self__pod) {
physx::PxConstraint const* self_ = reinterpret_cast<physx::PxConstraint const*>(self__pod);
physx::PxScene* returnValue = self_->getScene();
physx_PxScene_Pod* returnValue_pod = reinterpret_cast<physx_PxScene_Pod*>(returnValue);
return returnValue_pod;
}

void PxConstraint_getActors(physx_PxConstraint_Pod const* self__pod, physx_PxRigidActor_Pod** actor0_pod, physx_PxRigidActor_Pod** actor1_pod) {
physx::PxConstraint const* self_ = reinterpret_cast<physx::PxConstraint const*>(self__pod);
physx::PxRigidActor*& actor0 = reinterpret_cast<physx::PxRigidActor*&>(*actor0_pod);
physx::PxRigidActor*& actor1 = reinterpret_cast<physx::PxRigidActor*&>(*actor1_pod);
self_->getActors(actor0, actor1);
}

void PxConstraint_setActors_mut(physx_PxConstraint_Pod* self__pod, physx_PxRigidActor_Pod* actor0_pod, physx_PxRigidActor_Pod* actor1_pod) {
physx::PxConstraint* self_ = reinterpret_cast<physx::PxConstraint*>(self__pod);
physx::PxRigidActor* actor0 = reinterpret_cast<physx::PxRigidActor*>(actor0_pod);
physx::PxRigidActor* actor1 = reinterpret_cast<physx::PxRigidActor*>(actor1_pod);
self_->setActors(actor0, actor1);
}

void PxConstraint_markDirty_mut(physx_PxConstraint_Pod* self__pod) {
physx::PxConstraint* self_ = reinterpret_cast<physx::PxConstraint*>(self__pod);
self_->markDirty();
}

void PxConstraint_setFlags_mut(physx_PxConstraint_Pod* self__pod, physx_PxConstraintFlags_Pod flags_pod) {
physx::PxConstraint* self_ = reinterpret_cast<physx::PxConstraint*>(self__pod);
physx::PxConstraintFlags flags;
memcpy(&flags, &flags_pod, sizeof(flags));
self_->setFlags(flags);
}

physx_PxConstraintFlags_Pod PxConstraint_getFlags(physx_PxConstraint_Pod const* self__pod) {
physx::PxConstraint const* self_ = reinterpret_cast<physx::PxConstraint const*>(self__pod);
physx::PxConstraintFlags returnValue = self_->getFlags();
physx_PxConstraintFlags_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxConstraint_setFlag_mut(physx_PxConstraint_Pod* self__pod, unsigned int flag_pod, bool value) {
physx::PxConstraint* self_ = reinterpret_cast<physx::PxConstraint*>(self__pod);
PxConstraintFlag::Enum flag = (PxConstraintFlag::Enum)flag_pod;
self_->setFlag(flag, value);
}

void PxConstraint_getForce(physx_PxConstraint_Pod const* self__pod, physx_PxVec3_Pod* linear_pod, physx_PxVec3_Pod* angular_pod) {
physx::PxConstraint const* self_ = reinterpret_cast<physx::PxConstraint const*>(self__pod);
physx::PxVec3& linear = reinterpret_cast<physx::PxVec3&>(*linear_pod);
physx::PxVec3& angular = reinterpret_cast<physx::PxVec3&>(*angular_pod);
self_->getForce(linear, angular);
}

bool PxConstraint_isValid(physx_PxConstraint_Pod const* self__pod) {
physx::PxConstraint const* self_ = reinterpret_cast<physx::PxConstraint const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

void PxConstraint_setBreakForce_mut(physx_PxConstraint_Pod* self__pod, float linear, float angular) {
physx::PxConstraint* self_ = reinterpret_cast<physx::PxConstraint*>(self__pod);
self_->setBreakForce(linear, angular);
}

void PxConstraint_getBreakForce(physx_PxConstraint_Pod const* self__pod, float* linear_pod, float* angular_pod) {
physx::PxConstraint const* self_ = reinterpret_cast<physx::PxConstraint const*>(self__pod);
float& linear = *linear_pod;
float& angular = *angular_pod;
self_->getBreakForce(linear, angular);
}

void PxConstraint_setMinResponseThreshold_mut(physx_PxConstraint_Pod* self__pod, float threshold) {
physx::PxConstraint* self_ = reinterpret_cast<physx::PxConstraint*>(self__pod);
self_->setMinResponseThreshold(threshold);
}

float PxConstraint_getMinResponseThreshold(physx_PxConstraint_Pod const* self__pod) {
physx::PxConstraint const* self_ = reinterpret_cast<physx::PxConstraint const*>(self__pod);
float returnValue = self_->getMinResponseThreshold();
return returnValue;
}

void* PxConstraint_getExternalReference_mut(physx_PxConstraint_Pod* self__pod, uint32_t* typeID_pod) {
physx::PxConstraint* self_ = reinterpret_cast<physx::PxConstraint*>(self__pod);
uint32_t& typeID = *typeID_pod;
void* returnValue = self_->getExternalReference(typeID);
return returnValue;
}

void PxConstraint_setConstraintFunctions_mut(physx_PxConstraint_Pod* self__pod, physx_PxConstraintConnector_Pod* connector_pod, physx_PxConstraintShaderTable_Pod const* shaders_pod) {
physx::PxConstraint* self_ = reinterpret_cast<physx::PxConstraint*>(self__pod);
physx::PxConstraintConnector& connector = reinterpret_cast<physx::PxConstraintConnector&>(*connector_pod);
physx::PxConstraintShaderTable const& shaders = reinterpret_cast<physx::PxConstraintShaderTable const&>(*shaders_pod);
self_->setConstraintFunctions(connector, shaders);
}

char const* PxConstraint_getConcreteTypeName(physx_PxConstraint_Pod const* self__pod) {
physx::PxConstraint const* self_ = reinterpret_cast<physx::PxConstraint const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

physx_PxContactStreamIterator_Pod PxContactStreamIterator_new(unsigned char const* contactPatches, unsigned char const* contactPoints, uint32_t const* contactFaceIndices, uint32_t nbPatches, uint32_t nbContacts) {
physx::PxContactStreamIterator returnValue(contactPatches, contactPoints, contactFaceIndices, nbPatches, nbContacts);
physx_PxContactStreamIterator_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxContactStreamIterator_hasNextPatch(physx_PxContactStreamIterator_Pod const* self__pod) {
physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
bool returnValue = self_->hasNextPatch();
return returnValue;
}

uint32_t PxContactStreamIterator_getTotalContactCount(physx_PxContactStreamIterator_Pod const* self__pod) {
physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
uint32_t returnValue = self_->getTotalContactCount();
return returnValue;
}

uint32_t PxContactStreamIterator_getTotalPatchCount(physx_PxContactStreamIterator_Pod const* self__pod) {
physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
uint32_t returnValue = self_->getTotalPatchCount();
return returnValue;
}

void PxContactStreamIterator_nextPatch_mut(physx_PxContactStreamIterator_Pod* self__pod) {
physx::PxContactStreamIterator* self_ = reinterpret_cast<physx::PxContactStreamIterator*>(self__pod);
self_->nextPatch();
}

bool PxContactStreamIterator_hasNextContact(physx_PxContactStreamIterator_Pod const* self__pod) {
physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
bool returnValue = self_->hasNextContact();
return returnValue;
}

void PxContactStreamIterator_nextContact_mut(physx_PxContactStreamIterator_Pod* self__pod) {
physx::PxContactStreamIterator* self_ = reinterpret_cast<physx::PxContactStreamIterator*>(self__pod);
self_->nextContact();
}

physx_PxVec3_Pod const* PxContactStreamIterator_getContactNormal(physx_PxContactStreamIterator_Pod const* self__pod) {
physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
physx::PxVec3 const& returnValue = self_->getContactNormal();
physx_PxVec3_Pod const* returnValue_pod = reinterpret_cast<physx_PxVec3_Pod const*>(&returnValue);
return returnValue_pod;
}

float PxContactStreamIterator_getInvMassScale0(physx_PxContactStreamIterator_Pod const* self__pod) {
physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
float returnValue = self_->getInvMassScale0();
return returnValue;
}

float PxContactStreamIterator_getInvMassScale1(physx_PxContactStreamIterator_Pod const* self__pod) {
physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
float returnValue = self_->getInvMassScale1();
return returnValue;
}

float PxContactStreamIterator_getInvInertiaScale0(physx_PxContactStreamIterator_Pod const* self__pod) {
physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
float returnValue = self_->getInvInertiaScale0();
return returnValue;
}

float PxContactStreamIterator_getInvInertiaScale1(physx_PxContactStreamIterator_Pod const* self__pod) {
physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
float returnValue = self_->getInvInertiaScale1();
return returnValue;
}

float PxContactStreamIterator_getMaxImpulse(physx_PxContactStreamIterator_Pod const* self__pod) {
physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
float returnValue = self_->getMaxImpulse();
return returnValue;
}

physx_PxVec3_Pod const* PxContactStreamIterator_getTargetVel(physx_PxContactStreamIterator_Pod const* self__pod) {
physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
physx::PxVec3 const& returnValue = self_->getTargetVel();
physx_PxVec3_Pod const* returnValue_pod = reinterpret_cast<physx_PxVec3_Pod const*>(&returnValue);
return returnValue_pod;
}

physx_PxVec3_Pod const* PxContactStreamIterator_getContactPoint(physx_PxContactStreamIterator_Pod const* self__pod) {
physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
physx::PxVec3 const& returnValue = self_->getContactPoint();
physx_PxVec3_Pod const* returnValue_pod = reinterpret_cast<physx_PxVec3_Pod const*>(&returnValue);
return returnValue_pod;
}

float PxContactStreamIterator_getSeparation(physx_PxContactStreamIterator_Pod const* self__pod) {
physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
float returnValue = self_->getSeparation();
return returnValue;
}

uint32_t PxContactStreamIterator_getFaceIndex0(physx_PxContactStreamIterator_Pod const* self__pod) {
physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
uint32_t returnValue = self_->getFaceIndex0();
return returnValue;
}

uint32_t PxContactStreamIterator_getFaceIndex1(physx_PxContactStreamIterator_Pod const* self__pod) {
physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
uint32_t returnValue = self_->getFaceIndex1();
return returnValue;
}

float PxContactStreamIterator_getStaticFriction(physx_PxContactStreamIterator_Pod const* self__pod) {
physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
float returnValue = self_->getStaticFriction();
return returnValue;
}

float PxContactStreamIterator_getDynamicFriction(physx_PxContactStreamIterator_Pod const* self__pod) {
physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
float returnValue = self_->getDynamicFriction();
return returnValue;
}

float PxContactStreamIterator_getRestitution(physx_PxContactStreamIterator_Pod const* self__pod) {
physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
float returnValue = self_->getRestitution();
return returnValue;
}

uint32_t PxContactStreamIterator_getMaterialFlags(physx_PxContactStreamIterator_Pod const* self__pod) {
physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
uint32_t returnValue = self_->getMaterialFlags();
return returnValue;
}

uint16_t PxContactStreamIterator_getMaterialIndex0(physx_PxContactStreamIterator_Pod const* self__pod) {
physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
uint16_t returnValue = self_->getMaterialIndex0();
return returnValue;
}

uint16_t PxContactStreamIterator_getMaterialIndex1(physx_PxContactStreamIterator_Pod const* self__pod) {
physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
uint16_t returnValue = self_->getMaterialIndex1();
return returnValue;
}

bool PxContactStreamIterator_advanceToIndex_mut(physx_PxContactStreamIterator_Pod* self__pod, uint32_t initialIndex) {
physx::PxContactStreamIterator* self_ = reinterpret_cast<physx::PxContactStreamIterator*>(self__pod);
bool returnValue = self_->advanceToIndex(initialIndex);
return returnValue;
}

physx_PxVec3_Pod const* PxContactSet_getPoint(physx_PxContactSet_Pod const* self__pod, uint32_t i) {
physx::PxContactSet const* self_ = reinterpret_cast<physx::PxContactSet const*>(self__pod);
physx::PxVec3 const& returnValue = self_->getPoint(i);
physx_PxVec3_Pod const* returnValue_pod = reinterpret_cast<physx_PxVec3_Pod const*>(&returnValue);
return returnValue_pod;
}

void PxContactSet_setPoint_mut(physx_PxContactSet_Pod* self__pod, uint32_t i, physx_PxVec3_Pod const* p_pod) {
physx::PxContactSet* self_ = reinterpret_cast<physx::PxContactSet*>(self__pod);
physx::PxVec3 const& p = reinterpret_cast<physx::PxVec3 const&>(*p_pod);
self_->setPoint(i, p);
}

physx_PxVec3_Pod const* PxContactSet_getNormal(physx_PxContactSet_Pod const* self__pod, uint32_t i) {
physx::PxContactSet const* self_ = reinterpret_cast<physx::PxContactSet const*>(self__pod);
physx::PxVec3 const& returnValue = self_->getNormal(i);
physx_PxVec3_Pod const* returnValue_pod = reinterpret_cast<physx_PxVec3_Pod const*>(&returnValue);
return returnValue_pod;
}

void PxContactSet_setNormal_mut(physx_PxContactSet_Pod* self__pod, uint32_t i, physx_PxVec3_Pod const* n_pod) {
physx::PxContactSet* self_ = reinterpret_cast<physx::PxContactSet*>(self__pod);
physx::PxVec3 const& n = reinterpret_cast<physx::PxVec3 const&>(*n_pod);
self_->setNormal(i, n);
}

float PxContactSet_getSeparation(physx_PxContactSet_Pod const* self__pod, uint32_t i) {
physx::PxContactSet const* self_ = reinterpret_cast<physx::PxContactSet const*>(self__pod);
float returnValue = self_->getSeparation(i);
return returnValue;
}

void PxContactSet_setSeparation_mut(physx_PxContactSet_Pod* self__pod, uint32_t i, float s) {
physx::PxContactSet* self_ = reinterpret_cast<physx::PxContactSet*>(self__pod);
self_->setSeparation(i, s);
}

physx_PxVec3_Pod const* PxContactSet_getTargetVelocity(physx_PxContactSet_Pod const* self__pod, uint32_t i) {
physx::PxContactSet const* self_ = reinterpret_cast<physx::PxContactSet const*>(self__pod);
physx::PxVec3 const& returnValue = self_->getTargetVelocity(i);
physx_PxVec3_Pod const* returnValue_pod = reinterpret_cast<physx_PxVec3_Pod const*>(&returnValue);
return returnValue_pod;
}

void PxContactSet_setTargetVelocity_mut(physx_PxContactSet_Pod* self__pod, uint32_t i, physx_PxVec3_Pod const* v_pod) {
physx::PxContactSet* self_ = reinterpret_cast<physx::PxContactSet*>(self__pod);
physx::PxVec3 const& v = reinterpret_cast<physx::PxVec3 const&>(*v_pod);
self_->setTargetVelocity(i, v);
}

uint32_t PxContactSet_getInternalFaceIndex0_mut(physx_PxContactSet_Pod* self__pod, uint32_t i) {
physx::PxContactSet* self_ = reinterpret_cast<physx::PxContactSet*>(self__pod);
uint32_t returnValue = self_->getInternalFaceIndex0(i);
return returnValue;
}

uint32_t PxContactSet_getInternalFaceIndex1_mut(physx_PxContactSet_Pod* self__pod, uint32_t i) {
physx::PxContactSet* self_ = reinterpret_cast<physx::PxContactSet*>(self__pod);
uint32_t returnValue = self_->getInternalFaceIndex1(i);
return returnValue;
}

float PxContactSet_getMaxImpulse(physx_PxContactSet_Pod const* self__pod, uint32_t i) {
physx::PxContactSet const* self_ = reinterpret_cast<physx::PxContactSet const*>(self__pod);
float returnValue = self_->getMaxImpulse(i);
return returnValue;
}

void PxContactSet_setMaxImpulse_mut(physx_PxContactSet_Pod* self__pod, uint32_t i, float s) {
physx::PxContactSet* self_ = reinterpret_cast<physx::PxContactSet*>(self__pod);
self_->setMaxImpulse(i, s);
}

float PxContactSet_getRestitution(physx_PxContactSet_Pod const* self__pod, uint32_t i) {
physx::PxContactSet const* self_ = reinterpret_cast<physx::PxContactSet const*>(self__pod);
float returnValue = self_->getRestitution(i);
return returnValue;
}

void PxContactSet_setRestitution_mut(physx_PxContactSet_Pod* self__pod, uint32_t i, float r) {
physx::PxContactSet* self_ = reinterpret_cast<physx::PxContactSet*>(self__pod);
self_->setRestitution(i, r);
}

float PxContactSet_getStaticFriction(physx_PxContactSet_Pod const* self__pod, uint32_t i) {
physx::PxContactSet const* self_ = reinterpret_cast<physx::PxContactSet const*>(self__pod);
float returnValue = self_->getStaticFriction(i);
return returnValue;
}

void PxContactSet_setStaticFriction_mut(physx_PxContactSet_Pod* self__pod, uint32_t i, float f) {
physx::PxContactSet* self_ = reinterpret_cast<physx::PxContactSet*>(self__pod);
self_->setStaticFriction(i, f);
}

float PxContactSet_getDynamicFriction(physx_PxContactSet_Pod const* self__pod, uint32_t i) {
physx::PxContactSet const* self_ = reinterpret_cast<physx::PxContactSet const*>(self__pod);
float returnValue = self_->getDynamicFriction(i);
return returnValue;
}

void PxContactSet_setDynamicFriction_mut(physx_PxContactSet_Pod* self__pod, uint32_t i, float f) {
physx::PxContactSet* self_ = reinterpret_cast<physx::PxContactSet*>(self__pod);
self_->setDynamicFriction(i, f);
}

void PxContactSet_ignore_mut(physx_PxContactSet_Pod* self__pod, uint32_t i) {
physx::PxContactSet* self_ = reinterpret_cast<physx::PxContactSet*>(self__pod);
self_->ignore(i);
}

uint32_t PxContactSet_size(physx_PxContactSet_Pod const* self__pod) {
physx::PxContactSet const* self_ = reinterpret_cast<physx::PxContactSet const*>(self__pod);
uint32_t returnValue = self_->size();
return returnValue;
}

float PxContactSet_getInvMassScale0(physx_PxContactSet_Pod const* self__pod) {
physx::PxContactSet const* self_ = reinterpret_cast<physx::PxContactSet const*>(self__pod);
float returnValue = self_->getInvMassScale0();
return returnValue;
}

float PxContactSet_getInvMassScale1(physx_PxContactSet_Pod const* self__pod) {
physx::PxContactSet const* self_ = reinterpret_cast<physx::PxContactSet const*>(self__pod);
float returnValue = self_->getInvMassScale1();
return returnValue;
}

float PxContactSet_getInvInertiaScale0(physx_PxContactSet_Pod const* self__pod) {
physx::PxContactSet const* self_ = reinterpret_cast<physx::PxContactSet const*>(self__pod);
float returnValue = self_->getInvInertiaScale0();
return returnValue;
}

float PxContactSet_getInvInertiaScale1(physx_PxContactSet_Pod const* self__pod) {
physx::PxContactSet const* self_ = reinterpret_cast<physx::PxContactSet const*>(self__pod);
float returnValue = self_->getInvInertiaScale1();
return returnValue;
}

void PxContactSet_setInvMassScale0_mut(physx_PxContactSet_Pod* self__pod, float scale) {
physx::PxContactSet* self_ = reinterpret_cast<physx::PxContactSet*>(self__pod);
self_->setInvMassScale0(scale);
}

void PxContactSet_setInvMassScale1_mut(physx_PxContactSet_Pod* self__pod, float scale) {
physx::PxContactSet* self_ = reinterpret_cast<physx::PxContactSet*>(self__pod);
self_->setInvMassScale1(scale);
}

void PxContactSet_setInvInertiaScale0_mut(physx_PxContactSet_Pod* self__pod, float scale) {
physx::PxContactSet* self_ = reinterpret_cast<physx::PxContactSet*>(self__pod);
self_->setInvInertiaScale0(scale);
}

void PxContactSet_setInvInertiaScale1_mut(physx_PxContactSet_Pod* self__pod, float scale) {
physx::PxContactSet* self_ = reinterpret_cast<physx::PxContactSet*>(self__pod);
self_->setInvInertiaScale1(scale);
}

void PxContactModifyCallback_onContactModify_mut(physx_PxContactModifyCallback_Pod* self__pod, physx_PxContactModifyPair_Pod* pairs_pod, uint32_t count) {
physx::PxContactModifyCallback* self_ = reinterpret_cast<physx::PxContactModifyCallback*>(self__pod);
physx::PxContactModifyPair* pairs = reinterpret_cast<physx::PxContactModifyPair*>(pairs_pod);
self_->onContactModify(pairs, count);
}

void PxCCDContactModifyCallback_onCCDContactModify_mut(physx_PxCCDContactModifyCallback_Pod* self__pod, physx_PxContactModifyPair_Pod* pairs_pod, uint32_t count) {
physx::PxCCDContactModifyCallback* self_ = reinterpret_cast<physx::PxCCDContactModifyCallback*>(self__pod);
physx::PxContactModifyPair* pairs = reinterpret_cast<physx::PxContactModifyPair*>(pairs_pod);
self_->onCCDContactModify(pairs, count);
}

void PxDeletionListener_onRelease_mut(physx_PxDeletionListener_Pod* self__pod, physx_PxBase_Pod const* observed_pod, void* userData, unsigned int deletionEvent_pod) {
physx::PxDeletionListener* self_ = reinterpret_cast<physx::PxDeletionListener*>(self__pod);
physx::PxBase const* observed = reinterpret_cast<physx::PxBase const*>(observed_pod);
PxDeletionEventFlag::Enum deletionEvent = (PxDeletionEventFlag::Enum)deletionEvent_pod;
self_->onRelease(observed, userData, deletionEvent);
}

physx_PxDataAccessFlags_Pod PxLockedData_getDataAccessFlags_mut(physx_PxLockedData_Pod* self__pod) {
physx::PxLockedData* self_ = reinterpret_cast<physx::PxLockedData*>(self__pod);
physx::PxDataAccessFlags returnValue = self_->getDataAccessFlags();
physx_PxDataAccessFlags_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxLockedData_unlock_mut(physx_PxLockedData_Pod* self__pod) {
physx::PxLockedData* self_ = reinterpret_cast<physx::PxLockedData*>(self__pod);
self_->unlock();
}

void PxLockedData_delete(physx_PxLockedData_Pod* self__pod) {
physx::PxLockedData* self_ = reinterpret_cast<physx::PxLockedData*>(self__pod);
delete self_;
}

void PxMaterial_release_mut(physx_PxMaterial_Pod* self__pod) {
physx::PxMaterial* self_ = reinterpret_cast<physx::PxMaterial*>(self__pod);
self_->release();
}

uint32_t PxMaterial_getReferenceCount(physx_PxMaterial_Pod const* self__pod) {
physx::PxMaterial const* self_ = reinterpret_cast<physx::PxMaterial const*>(self__pod);
uint32_t returnValue = self_->getReferenceCount();
return returnValue;
}

void PxMaterial_acquireReference_mut(physx_PxMaterial_Pod* self__pod) {
physx::PxMaterial* self_ = reinterpret_cast<physx::PxMaterial*>(self__pod);
self_->acquireReference();
}

void PxMaterial_setDynamicFriction_mut(physx_PxMaterial_Pod* self__pod, float coef) {
physx::PxMaterial* self_ = reinterpret_cast<physx::PxMaterial*>(self__pod);
self_->setDynamicFriction(coef);
}

float PxMaterial_getDynamicFriction(physx_PxMaterial_Pod const* self__pod) {
physx::PxMaterial const* self_ = reinterpret_cast<physx::PxMaterial const*>(self__pod);
float returnValue = self_->getDynamicFriction();
return returnValue;
}

void PxMaterial_setStaticFriction_mut(physx_PxMaterial_Pod* self__pod, float coef) {
physx::PxMaterial* self_ = reinterpret_cast<physx::PxMaterial*>(self__pod);
self_->setStaticFriction(coef);
}

float PxMaterial_getStaticFriction(physx_PxMaterial_Pod const* self__pod) {
physx::PxMaterial const* self_ = reinterpret_cast<physx::PxMaterial const*>(self__pod);
float returnValue = self_->getStaticFriction();
return returnValue;
}

void PxMaterial_setRestitution_mut(physx_PxMaterial_Pod* self__pod, float rest) {
physx::PxMaterial* self_ = reinterpret_cast<physx::PxMaterial*>(self__pod);
self_->setRestitution(rest);
}

float PxMaterial_getRestitution(physx_PxMaterial_Pod const* self__pod) {
physx::PxMaterial const* self_ = reinterpret_cast<physx::PxMaterial const*>(self__pod);
float returnValue = self_->getRestitution();
return returnValue;
}

void PxMaterial_setFlag_mut(physx_PxMaterial_Pod* self__pod, unsigned int flag_pod, bool anonymous_arg1) {
physx::PxMaterial* self_ = reinterpret_cast<physx::PxMaterial*>(self__pod);
PxMaterialFlag::Enum flag = (PxMaterialFlag::Enum)flag_pod;
self_->setFlag(flag, anonymous_arg1);
}

void PxMaterial_setFlags_mut(physx_PxMaterial_Pod* self__pod, physx_PxMaterialFlags_Pod inFlags_pod) {
physx::PxMaterial* self_ = reinterpret_cast<physx::PxMaterial*>(self__pod);
physx::PxMaterialFlags inFlags;
memcpy(&inFlags, &inFlags_pod, sizeof(inFlags));
self_->setFlags(inFlags);
}

physx_PxMaterialFlags_Pod PxMaterial_getFlags(physx_PxMaterial_Pod const* self__pod) {
physx::PxMaterial const* self_ = reinterpret_cast<physx::PxMaterial const*>(self__pod);
physx::PxMaterialFlags returnValue = self_->getFlags();
physx_PxMaterialFlags_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxMaterial_setFrictionCombineMode_mut(physx_PxMaterial_Pod* self__pod, unsigned int combMode_pod) {
physx::PxMaterial* self_ = reinterpret_cast<physx::PxMaterial*>(self__pod);
PxCombineMode::Enum combMode = (PxCombineMode::Enum)combMode_pod;
self_->setFrictionCombineMode(combMode);
}

unsigned int PxMaterial_getFrictionCombineMode(physx_PxMaterial_Pod const* self__pod) {
physx::PxMaterial const* self_ = reinterpret_cast<physx::PxMaterial const*>(self__pod);
PxCombineMode::Enum returnValue = self_->getFrictionCombineMode();
unsigned int returnValue_pod = (unsigned int)returnValue;
return returnValue_pod;
}

void PxMaterial_setRestitutionCombineMode_mut(physx_PxMaterial_Pod* self__pod, unsigned int combMode_pod) {
physx::PxMaterial* self_ = reinterpret_cast<physx::PxMaterial*>(self__pod);
PxCombineMode::Enum combMode = (PxCombineMode::Enum)combMode_pod;
self_->setRestitutionCombineMode(combMode);
}

unsigned int PxMaterial_getRestitutionCombineMode(physx_PxMaterial_Pod const* self__pod) {
physx::PxMaterial const* self_ = reinterpret_cast<physx::PxMaterial const*>(self__pod);
PxCombineMode::Enum returnValue = self_->getRestitutionCombineMode();
unsigned int returnValue_pod = (unsigned int)returnValue;
return returnValue_pod;
}

char const* PxMaterial_getConcreteTypeName(physx_PxMaterial_Pod const* self__pod) {
physx::PxMaterial const* self_ = reinterpret_cast<physx::PxMaterial const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

void PxPhysics_release_mut(physx_PxPhysics_Pod* self__pod) {
physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
self_->release();
}

physx_PxFoundation_Pod* PxPhysics_getFoundation_mut(physx_PxPhysics_Pod* self__pod) {
physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
physx::PxFoundation& returnValue = self_->getFoundation();
physx_PxFoundation_Pod* returnValue_pod = reinterpret_cast<physx_PxFoundation_Pod*>(&returnValue);
return returnValue_pod;
}

physx_PxAggregate_Pod* PxPhysics_createAggregate_mut(physx_PxPhysics_Pod* self__pod, uint32_t maxSize, bool enableSelfCollision) {
physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
physx::PxAggregate* returnValue = self_->createAggregate(maxSize, enableSelfCollision);
physx_PxAggregate_Pod* returnValue_pod = reinterpret_cast<physx_PxAggregate_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxTolerancesScale_Pod const* PxPhysics_getTolerancesScale(physx_PxPhysics_Pod const* self__pod) {
physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
physx::PxTolerancesScale const& returnValue = self_->getTolerancesScale();
physx_PxTolerancesScale_Pod const* returnValue_pod = reinterpret_cast<physx_PxTolerancesScale_Pod const*>(&returnValue);
return returnValue_pod;
}

physx_PxTriangleMesh_Pod* PxPhysics_createTriangleMesh_mut(physx_PxPhysics_Pod* self__pod, physx_PxInputStream_Pod* stream_pod) {
physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
physx::PxInputStream& stream = reinterpret_cast<physx::PxInputStream&>(*stream_pod);
physx::PxTriangleMesh* returnValue = self_->createTriangleMesh(stream);
physx_PxTriangleMesh_Pod* returnValue_pod = reinterpret_cast<physx_PxTriangleMesh_Pod*>(returnValue);
return returnValue_pod;
}

uint32_t PxPhysics_getNbTriangleMeshes(physx_PxPhysics_Pod const* self__pod) {
physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
uint32_t returnValue = self_->getNbTriangleMeshes();
return returnValue;
}

uint32_t PxPhysics_getTriangleMeshes(physx_PxPhysics_Pod const* self__pod, physx_PxTriangleMesh_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
physx::PxTriangleMesh** userBuffer = reinterpret_cast<physx::PxTriangleMesh**>(userBuffer_pod);
uint32_t returnValue = self_->getTriangleMeshes(userBuffer, bufferSize, startIndex);
return returnValue;
}

physx_PxHeightField_Pod* PxPhysics_createHeightField_mut(physx_PxPhysics_Pod* self__pod, physx_PxInputStream_Pod* stream_pod) {
physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
physx::PxInputStream& stream = reinterpret_cast<physx::PxInputStream&>(*stream_pod);
physx::PxHeightField* returnValue = self_->createHeightField(stream);
physx_PxHeightField_Pod* returnValue_pod = reinterpret_cast<physx_PxHeightField_Pod*>(returnValue);
return returnValue_pod;
}

uint32_t PxPhysics_getNbHeightFields(physx_PxPhysics_Pod const* self__pod) {
physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
uint32_t returnValue = self_->getNbHeightFields();
return returnValue;
}

uint32_t PxPhysics_getHeightFields(physx_PxPhysics_Pod const* self__pod, physx_PxHeightField_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
physx::PxHeightField** userBuffer = reinterpret_cast<physx::PxHeightField**>(userBuffer_pod);
uint32_t returnValue = self_->getHeightFields(userBuffer, bufferSize, startIndex);
return returnValue;
}

physx_PxConvexMesh_Pod* PxPhysics_createConvexMesh_mut(physx_PxPhysics_Pod* self__pod, physx_PxInputStream_Pod* stream_pod) {
physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
physx::PxInputStream& stream = reinterpret_cast<physx::PxInputStream&>(*stream_pod);
physx::PxConvexMesh* returnValue = self_->createConvexMesh(stream);
physx_PxConvexMesh_Pod* returnValue_pod = reinterpret_cast<physx_PxConvexMesh_Pod*>(returnValue);
return returnValue_pod;
}

uint32_t PxPhysics_getNbConvexMeshes(physx_PxPhysics_Pod const* self__pod) {
physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
uint32_t returnValue = self_->getNbConvexMeshes();
return returnValue;
}

uint32_t PxPhysics_getConvexMeshes(physx_PxPhysics_Pod const* self__pod, physx_PxConvexMesh_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
physx::PxConvexMesh** userBuffer = reinterpret_cast<physx::PxConvexMesh**>(userBuffer_pod);
uint32_t returnValue = self_->getConvexMeshes(userBuffer, bufferSize, startIndex);
return returnValue;
}

physx_PxBVHStructure_Pod* PxPhysics_createBVHStructure_mut(physx_PxPhysics_Pod* self__pod, physx_PxInputStream_Pod* stream_pod) {
physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
physx::PxInputStream& stream = reinterpret_cast<physx::PxInputStream&>(*stream_pod);
physx::PxBVHStructure* returnValue = self_->createBVHStructure(stream);
physx_PxBVHStructure_Pod* returnValue_pod = reinterpret_cast<physx_PxBVHStructure_Pod*>(returnValue);
return returnValue_pod;
}

uint32_t PxPhysics_getNbBVHStructures(physx_PxPhysics_Pod const* self__pod) {
physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
uint32_t returnValue = self_->getNbBVHStructures();
return returnValue;
}

uint32_t PxPhysics_getBVHStructures(physx_PxPhysics_Pod const* self__pod, physx_PxBVHStructure_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
physx::PxBVHStructure** userBuffer = reinterpret_cast<physx::PxBVHStructure**>(userBuffer_pod);
uint32_t returnValue = self_->getBVHStructures(userBuffer, bufferSize, startIndex);
return returnValue;
}

physx_PxScene_Pod* PxPhysics_createScene_mut(physx_PxPhysics_Pod* self__pod, physx_PxSceneDesc_Pod const* sceneDesc_pod) {
physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
physx::PxSceneDesc const& sceneDesc = reinterpret_cast<physx::PxSceneDesc const&>(*sceneDesc_pod);
physx::PxScene* returnValue = self_->createScene(sceneDesc);
physx_PxScene_Pod* returnValue_pod = reinterpret_cast<physx_PxScene_Pod*>(returnValue);
return returnValue_pod;
}

uint32_t PxPhysics_getNbScenes(physx_PxPhysics_Pod const* self__pod) {
physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
uint32_t returnValue = self_->getNbScenes();
return returnValue;
}

uint32_t PxPhysics_getScenes(physx_PxPhysics_Pod const* self__pod, physx_PxScene_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
physx::PxScene** userBuffer = reinterpret_cast<physx::PxScene**>(userBuffer_pod);
uint32_t returnValue = self_->getScenes(userBuffer, bufferSize, startIndex);
return returnValue;
}

physx_PxRigidStatic_Pod* PxPhysics_createRigidStatic_mut(physx_PxPhysics_Pod* self__pod, physx_PxTransform_Pod const* pose_pod) {
physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
physx::PxRigidStatic* returnValue = self_->createRigidStatic(pose);
physx_PxRigidStatic_Pod* returnValue_pod = reinterpret_cast<physx_PxRigidStatic_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxRigidDynamic_Pod* PxPhysics_createRigidDynamic_mut(physx_PxPhysics_Pod* self__pod, physx_PxTransform_Pod const* pose_pod) {
physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
physx::PxRigidDynamic* returnValue = self_->createRigidDynamic(pose);
physx_PxRigidDynamic_Pod* returnValue_pod = reinterpret_cast<physx_PxRigidDynamic_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxPruningStructure_Pod* PxPhysics_createPruningStructure_mut(physx_PxPhysics_Pod* self__pod, physx_PxRigidActor_Pod* const* actors_pod, uint32_t nbActors) {
physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
physx::PxRigidActor* const* actors = reinterpret_cast<physx::PxRigidActor* const*>(actors_pod);
physx::PxPruningStructure* returnValue = self_->createPruningStructure(actors, nbActors);
physx_PxPruningStructure_Pod* returnValue_pod = reinterpret_cast<physx_PxPruningStructure_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxShape_Pod* PxPhysics_createShape_mut(physx_PxPhysics_Pod* self__pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxMaterial_Pod const* material_pod, bool isExclusive, physx_PxShapeFlags_Pod shapeFlags_pod) {
physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
physx::PxMaterial const& material = reinterpret_cast<physx::PxMaterial const&>(*material_pod);
physx::PxShapeFlags shapeFlags;
memcpy(&shapeFlags, &shapeFlags_pod, sizeof(shapeFlags));
physx::PxShape* returnValue = self_->createShape(geometry, material, isExclusive, shapeFlags);
physx_PxShape_Pod* returnValue_pod = reinterpret_cast<physx_PxShape_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxShape_Pod* PxPhysics_createShape_mut_1(physx_PxPhysics_Pod* self__pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxMaterial_Pod* const* materials_pod, uint16_t materialCount, bool isExclusive, physx_PxShapeFlags_Pod shapeFlags_pod) {
physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
physx::PxMaterial* const* materials = reinterpret_cast<physx::PxMaterial* const*>(materials_pod);
physx::PxShapeFlags shapeFlags;
memcpy(&shapeFlags, &shapeFlags_pod, sizeof(shapeFlags));
physx::PxShape* returnValue = self_->createShape(geometry, materials, materialCount, isExclusive, shapeFlags);
physx_PxShape_Pod* returnValue_pod = reinterpret_cast<physx_PxShape_Pod*>(returnValue);
return returnValue_pod;
}

uint32_t PxPhysics_getNbShapes(physx_PxPhysics_Pod const* self__pod) {
physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
uint32_t returnValue = self_->getNbShapes();
return returnValue;
}

uint32_t PxPhysics_getShapes(physx_PxPhysics_Pod const* self__pod, physx_PxShape_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
physx::PxShape** userBuffer = reinterpret_cast<physx::PxShape**>(userBuffer_pod);
uint32_t returnValue = self_->getShapes(userBuffer, bufferSize, startIndex);
return returnValue;
}

physx_PxConstraint_Pod* PxPhysics_createConstraint_mut(physx_PxPhysics_Pod* self__pod, physx_PxRigidActor_Pod* actor0_pod, physx_PxRigidActor_Pod* actor1_pod, physx_PxConstraintConnector_Pod* connector_pod, physx_PxConstraintShaderTable_Pod const* shaders_pod, uint32_t dataSize) {
physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
physx::PxRigidActor* actor0 = reinterpret_cast<physx::PxRigidActor*>(actor0_pod);
physx::PxRigidActor* actor1 = reinterpret_cast<physx::PxRigidActor*>(actor1_pod);
physx::PxConstraintConnector& connector = reinterpret_cast<physx::PxConstraintConnector&>(*connector_pod);
physx::PxConstraintShaderTable const& shaders = reinterpret_cast<physx::PxConstraintShaderTable const&>(*shaders_pod);
physx::PxConstraint* returnValue = self_->createConstraint(actor0, actor1, connector, shaders, dataSize);
physx_PxConstraint_Pod* returnValue_pod = reinterpret_cast<physx_PxConstraint_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxArticulation_Pod* PxPhysics_createArticulation_mut(physx_PxPhysics_Pod* self__pod) {
physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
physx::PxArticulation* returnValue = self_->createArticulation();
physx_PxArticulation_Pod* returnValue_pod = reinterpret_cast<physx_PxArticulation_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxArticulationReducedCoordinate_Pod* PxPhysics_createArticulationReducedCoordinate_mut(physx_PxPhysics_Pod* self__pod) {
physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
physx::PxArticulationReducedCoordinate* returnValue = self_->createArticulationReducedCoordinate();
physx_PxArticulationReducedCoordinate_Pod* returnValue_pod = reinterpret_cast<physx_PxArticulationReducedCoordinate_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxMaterial_Pod* PxPhysics_createMaterial_mut(physx_PxPhysics_Pod* self__pod, float staticFriction, float dynamicFriction, float restitution) {
physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
physx::PxMaterial* returnValue = self_->createMaterial(staticFriction, dynamicFriction, restitution);
physx_PxMaterial_Pod* returnValue_pod = reinterpret_cast<physx_PxMaterial_Pod*>(returnValue);
return returnValue_pod;
}

uint32_t PxPhysics_getNbMaterials(physx_PxPhysics_Pod const* self__pod) {
physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
uint32_t returnValue = self_->getNbMaterials();
return returnValue;
}

uint32_t PxPhysics_getMaterials(physx_PxPhysics_Pod const* self__pod, physx_PxMaterial_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
physx::PxMaterial** userBuffer = reinterpret_cast<physx::PxMaterial**>(userBuffer_pod);
uint32_t returnValue = self_->getMaterials(userBuffer, bufferSize, startIndex);
return returnValue;
}

void PxPhysics_registerDeletionListener_mut(physx_PxPhysics_Pod* self__pod, physx_PxDeletionListener_Pod* observer_pod, physx_PxDeletionEventFlags_Pod const* deletionEvents_pod, bool restrictedObjectSet) {
physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
physx::PxDeletionListener& observer = reinterpret_cast<physx::PxDeletionListener&>(*observer_pod);
physx::PxDeletionEventFlags const& deletionEvents = reinterpret_cast<physx::PxDeletionEventFlags const&>(*deletionEvents_pod);
self_->registerDeletionListener(observer, deletionEvents, restrictedObjectSet);
}

void PxPhysics_unregisterDeletionListener_mut(physx_PxPhysics_Pod* self__pod, physx_PxDeletionListener_Pod* observer_pod) {
physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
physx::PxDeletionListener& observer = reinterpret_cast<physx::PxDeletionListener&>(*observer_pod);
self_->unregisterDeletionListener(observer);
}

void PxPhysics_registerDeletionListenerObjects_mut(physx_PxPhysics_Pod* self__pod, physx_PxDeletionListener_Pod* observer_pod, physx_PxBase_Pod const* const* observables_pod, uint32_t observableCount) {
physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
physx::PxDeletionListener& observer = reinterpret_cast<physx::PxDeletionListener&>(*observer_pod);
physx::PxBase const* const* observables = reinterpret_cast<physx::PxBase const* const*>(observables_pod);
self_->registerDeletionListenerObjects(observer, observables, observableCount);
}

void PxPhysics_unregisterDeletionListenerObjects_mut(physx_PxPhysics_Pod* self__pod, physx_PxDeletionListener_Pod* observer_pod, physx_PxBase_Pod const* const* observables_pod, uint32_t observableCount) {
physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
physx::PxDeletionListener& observer = reinterpret_cast<physx::PxDeletionListener&>(*observer_pod);
physx::PxBase const* const* observables = reinterpret_cast<physx::PxBase const* const*>(observables_pod);
self_->unregisterDeletionListenerObjects(observer, observables, observableCount);
}

physx_PxPhysicsInsertionCallback_Pod* PxPhysics_getPhysicsInsertionCallback_mut(physx_PxPhysics_Pod* self__pod) {
physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
physx::PxPhysicsInsertionCallback& returnValue = self_->getPhysicsInsertionCallback();
physx_PxPhysicsInsertionCallback_Pod* returnValue_pod = reinterpret_cast<physx_PxPhysicsInsertionCallback_Pod*>(&returnValue);
return returnValue_pod;
}

void phys_PxRegisterArticulations(physx_PxPhysics_Pod* physics_pod) {
physx::PxPhysics& physics = reinterpret_cast<physx::PxPhysics&>(*physics_pod);
PxRegisterArticulations(physics);
}

void phys_PxRegisterArticulationsReducedCoordinate(physx_PxPhysics_Pod* physics_pod) {
physx::PxPhysics& physics = reinterpret_cast<physx::PxPhysics&>(*physics_pod);
PxRegisterArticulationsReducedCoordinate(physics);
}

void phys_PxRegisterHeightFields(physx_PxPhysics_Pod* physics_pod) {
physx::PxPhysics& physics = reinterpret_cast<physx::PxPhysics&>(*physics_pod);
PxRegisterHeightFields(physics);
}

physx_PxPhysics_Pod* phys_PxCreateBasePhysics(uint32_t version, physx_PxFoundation_Pod* foundation_pod, physx_PxTolerancesScale_Pod const* scale_pod, bool trackOutstandingAllocations, physx_PxPvd_Pod* pvd_pod) {
physx::PxFoundation& foundation = reinterpret_cast<physx::PxFoundation&>(*foundation_pod);
physx::PxTolerancesScale const& scale = reinterpret_cast<physx::PxTolerancesScale const&>(*scale_pod);
physx::PxPvd* pvd = reinterpret_cast<physx::PxPvd*>(pvd_pod);
physx::PxPhysics* returnValue = PxCreateBasePhysics(version, foundation, scale, trackOutstandingAllocations, pvd);
physx_PxPhysics_Pod* returnValue_pod = reinterpret_cast<physx_PxPhysics_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxPhysics_Pod* phys_PxCreatePhysics(uint32_t version, physx_PxFoundation_Pod* foundation_pod, physx_PxTolerancesScale_Pod const* scale_pod, bool trackOutstandingAllocations, physx_PxPvd_Pod* pvd_pod) {
physx::PxFoundation& foundation = reinterpret_cast<physx::PxFoundation&>(*foundation_pod);
physx::PxTolerancesScale const& scale = reinterpret_cast<physx::PxTolerancesScale const&>(*scale_pod);
physx::PxPvd* pvd = reinterpret_cast<physx::PxPvd*>(pvd_pod);
physx::PxPhysics* returnValue = PxCreatePhysics(version, foundation, scale, trackOutstandingAllocations, pvd);
physx_PxPhysics_Pod* returnValue_pod = reinterpret_cast<physx_PxPhysics_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxPhysics_Pod* phys_PxGetPhysics() {
physx::PxPhysics& returnValue = PxGetPhysics();
physx_PxPhysics_Pod* returnValue_pod = reinterpret_cast<physx_PxPhysics_Pod*>(&returnValue);
return returnValue_pod;
}

void PxRigidDynamic_setKinematicTarget_mut(physx_PxRigidDynamic_Pod* self__pod, physx_PxTransform_Pod const* destination_pod) {
physx::PxRigidDynamic* self_ = reinterpret_cast<physx::PxRigidDynamic*>(self__pod);
physx::PxTransform const& destination = reinterpret_cast<physx::PxTransform const&>(*destination_pod);
self_->setKinematicTarget(destination);
}

bool PxRigidDynamic_getKinematicTarget(physx_PxRigidDynamic_Pod const* self__pod, physx_PxTransform_Pod* target_pod) {
physx::PxRigidDynamic const* self_ = reinterpret_cast<physx::PxRigidDynamic const*>(self__pod);
physx::PxTransform& target = reinterpret_cast<physx::PxTransform&>(*target_pod);
bool returnValue = self_->getKinematicTarget(target);
return returnValue;
}

bool PxRigidDynamic_isSleeping(physx_PxRigidDynamic_Pod const* self__pod) {
physx::PxRigidDynamic const* self_ = reinterpret_cast<physx::PxRigidDynamic const*>(self__pod);
bool returnValue = self_->isSleeping();
return returnValue;
}

void PxRigidDynamic_setSleepThreshold_mut(physx_PxRigidDynamic_Pod* self__pod, float threshold) {
physx::PxRigidDynamic* self_ = reinterpret_cast<physx::PxRigidDynamic*>(self__pod);
self_->setSleepThreshold(threshold);
}

float PxRigidDynamic_getSleepThreshold(physx_PxRigidDynamic_Pod const* self__pod) {
physx::PxRigidDynamic const* self_ = reinterpret_cast<physx::PxRigidDynamic const*>(self__pod);
float returnValue = self_->getSleepThreshold();
return returnValue;
}

void PxRigidDynamic_setStabilizationThreshold_mut(physx_PxRigidDynamic_Pod* self__pod, float threshold) {
physx::PxRigidDynamic* self_ = reinterpret_cast<physx::PxRigidDynamic*>(self__pod);
self_->setStabilizationThreshold(threshold);
}

float PxRigidDynamic_getStabilizationThreshold(physx_PxRigidDynamic_Pod const* self__pod) {
physx::PxRigidDynamic const* self_ = reinterpret_cast<physx::PxRigidDynamic const*>(self__pod);
float returnValue = self_->getStabilizationThreshold();
return returnValue;
}

physx_PxRigidDynamicLockFlags_Pod PxRigidDynamic_getRigidDynamicLockFlags(physx_PxRigidDynamic_Pod const* self__pod) {
physx::PxRigidDynamic const* self_ = reinterpret_cast<physx::PxRigidDynamic const*>(self__pod);
physx::PxRigidDynamicLockFlags returnValue = self_->getRigidDynamicLockFlags();
physx_PxRigidDynamicLockFlags_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxRigidDynamic_setRigidDynamicLockFlag_mut(physx_PxRigidDynamic_Pod* self__pod, unsigned int flag_pod, bool value) {
physx::PxRigidDynamic* self_ = reinterpret_cast<physx::PxRigidDynamic*>(self__pod);
PxRigidDynamicLockFlag::Enum flag = (PxRigidDynamicLockFlag::Enum)flag_pod;
self_->setRigidDynamicLockFlag(flag, value);
}

void PxRigidDynamic_setRigidDynamicLockFlags_mut(physx_PxRigidDynamic_Pod* self__pod, physx_PxRigidDynamicLockFlags_Pod flags_pod) {
physx::PxRigidDynamic* self_ = reinterpret_cast<physx::PxRigidDynamic*>(self__pod);
physx::PxRigidDynamicLockFlags flags;
memcpy(&flags, &flags_pod, sizeof(flags));
self_->setRigidDynamicLockFlags(flags);
}

void PxRigidDynamic_setWakeCounter_mut(physx_PxRigidDynamic_Pod* self__pod, float wakeCounterValue) {
physx::PxRigidDynamic* self_ = reinterpret_cast<physx::PxRigidDynamic*>(self__pod);
self_->setWakeCounter(wakeCounterValue);
}

float PxRigidDynamic_getWakeCounter(physx_PxRigidDynamic_Pod const* self__pod) {
physx::PxRigidDynamic const* self_ = reinterpret_cast<physx::PxRigidDynamic const*>(self__pod);
float returnValue = self_->getWakeCounter();
return returnValue;
}

void PxRigidDynamic_wakeUp_mut(physx_PxRigidDynamic_Pod* self__pod) {
physx::PxRigidDynamic* self_ = reinterpret_cast<physx::PxRigidDynamic*>(self__pod);
self_->wakeUp();
}

void PxRigidDynamic_putToSleep_mut(physx_PxRigidDynamic_Pod* self__pod) {
physx::PxRigidDynamic* self_ = reinterpret_cast<physx::PxRigidDynamic*>(self__pod);
self_->putToSleep();
}

void PxRigidDynamic_setSolverIterationCounts_mut(physx_PxRigidDynamic_Pod* self__pod, uint32_t minPositionIters, uint32_t minVelocityIters) {
physx::PxRigidDynamic* self_ = reinterpret_cast<physx::PxRigidDynamic*>(self__pod);
self_->setSolverIterationCounts(minPositionIters, minVelocityIters);
}

void PxRigidDynamic_getSolverIterationCounts(physx_PxRigidDynamic_Pod const* self__pod, uint32_t* minPositionIters_pod, uint32_t* minVelocityIters_pod) {
physx::PxRigidDynamic const* self_ = reinterpret_cast<physx::PxRigidDynamic const*>(self__pod);
uint32_t& minPositionIters = *minPositionIters_pod;
uint32_t& minVelocityIters = *minVelocityIters_pod;
self_->getSolverIterationCounts(minPositionIters, minVelocityIters);
}

float PxRigidDynamic_getContactReportThreshold(physx_PxRigidDynamic_Pod const* self__pod) {
physx::PxRigidDynamic const* self_ = reinterpret_cast<physx::PxRigidDynamic const*>(self__pod);
float returnValue = self_->getContactReportThreshold();
return returnValue;
}

void PxRigidDynamic_setContactReportThreshold_mut(physx_PxRigidDynamic_Pod* self__pod, float threshold) {
physx::PxRigidDynamic* self_ = reinterpret_cast<physx::PxRigidDynamic*>(self__pod);
self_->setContactReportThreshold(threshold);
}

char const* PxRigidDynamic_getConcreteTypeName(physx_PxRigidDynamic_Pod const* self__pod) {
physx::PxRigidDynamic const* self_ = reinterpret_cast<physx::PxRigidDynamic const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

char const* PxRigidStatic_getConcreteTypeName(physx_PxRigidStatic_Pod const* self__pod) {
physx::PxRigidStatic const* self_ = reinterpret_cast<physx::PxRigidStatic const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

void PxBroadPhaseCallback_delete(physx_PxBroadPhaseCallback_Pod* self__pod) {
physx::PxBroadPhaseCallback* self_ = reinterpret_cast<physx::PxBroadPhaseCallback*>(self__pod);
delete self_;
}

void PxBroadPhaseCallback_onObjectOutOfBounds_mut(physx_PxBroadPhaseCallback_Pod* self__pod, physx_PxShape_Pod* shape_pod, physx_PxActor_Pod* actor_pod) {
physx::PxBroadPhaseCallback* self_ = reinterpret_cast<physx::PxBroadPhaseCallback*>(self__pod);
physx::PxShape& shape = reinterpret_cast<physx::PxShape&>(*shape_pod);
physx::PxActor& actor = reinterpret_cast<physx::PxActor&>(*actor_pod);
self_->onObjectOutOfBounds(shape, actor);
}

void PxBroadPhaseCallback_onObjectOutOfBounds_mut_1(physx_PxBroadPhaseCallback_Pod* self__pod, physx_PxAggregate_Pod* aggregate_pod) {
physx::PxBroadPhaseCallback* self_ = reinterpret_cast<physx::PxBroadPhaseCallback*>(self__pod);
physx::PxAggregate& aggregate = reinterpret_cast<physx::PxAggregate&>(*aggregate_pod);
self_->onObjectOutOfBounds(aggregate);
}

physx_PxSceneLimits_Pod PxSceneLimits_new() {
physx::PxSceneLimits returnValue;
physx_PxSceneLimits_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxSceneLimits_setToDefault_mut(physx_PxSceneLimits_Pod* self__pod) {
physx::PxSceneLimits* self_ = reinterpret_cast<physx::PxSceneLimits*>(self__pod);
self_->setToDefault();
}

bool PxSceneLimits_isValid(physx_PxSceneLimits_Pod const* self__pod) {
physx::PxSceneLimits const* self_ = reinterpret_cast<physx::PxSceneLimits const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

physx_PxSceneLimits_Pod PxSceneLimits_new_1() {
physx::PxSceneLimits returnValue;
physx_PxSceneLimits_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxSceneLimits_setToDefault_mut_1(physx_PxSceneLimits_Pod* self__pod) {
physx::PxSceneLimits* self_ = reinterpret_cast<physx::PxSceneLimits*>(self__pod);
self_->setToDefault();
}

bool PxSceneLimits_isValid_1(physx_PxSceneLimits_Pod const* self__pod) {
physx::PxSceneLimits const* self_ = reinterpret_cast<physx::PxSceneLimits const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

physx_PxgDynamicsMemoryConfig_Pod PxgDynamicsMemoryConfig_new() {
physx::PxgDynamicsMemoryConfig returnValue;
physx_PxgDynamicsMemoryConfig_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxSceneDesc_Pod PxSceneDesc_new(physx_PxTolerancesScale_Pod const* scale_pod) {
physx::PxTolerancesScale const& scale = reinterpret_cast<physx::PxTolerancesScale const&>(*scale_pod);
physx::PxSceneDesc returnValue(scale);
physx_PxSceneDesc_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxSceneDesc_setToDefault_mut(physx_PxSceneDesc_Pod* self__pod, physx_PxTolerancesScale_Pod const* scale_pod) {
physx::PxSceneDesc* self_ = reinterpret_cast<physx::PxSceneDesc*>(self__pod);
physx::PxTolerancesScale const& scale = reinterpret_cast<physx::PxTolerancesScale const&>(*scale_pod);
self_->setToDefault(scale);
}

bool PxSceneDesc_isValid(physx_PxSceneDesc_Pod const* self__pod) {
physx::PxSceneDesc const* self_ = reinterpret_cast<physx::PxSceneDesc const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

physx_PxTolerancesScale_Pod const* PxSceneDesc_getTolerancesScale(physx_PxSceneDesc_Pod const* self__pod) {
physx::PxSceneDesc const* self_ = reinterpret_cast<physx::PxSceneDesc const*>(self__pod);
physx::PxTolerancesScale const& returnValue = self_->getTolerancesScale();
physx_PxTolerancesScale_Pod const* returnValue_pod = reinterpret_cast<physx_PxTolerancesScale_Pod const*>(&returnValue);
return returnValue_pod;
}

physx_PxSceneDesc_Pod PxSceneDesc_new_1(physx_PxTolerancesScale_Pod const* scale_pod) {
physx::PxTolerancesScale const& scale = reinterpret_cast<physx::PxTolerancesScale const&>(*scale_pod);
physx::PxSceneDesc returnValue(scale);
physx_PxSceneDesc_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxSceneDesc_setToDefault_mut_1(physx_PxSceneDesc_Pod* self__pod, physx_PxTolerancesScale_Pod const* scale_pod) {
physx::PxSceneDesc* self_ = reinterpret_cast<physx::PxSceneDesc*>(self__pod);
physx::PxTolerancesScale const& scale = reinterpret_cast<physx::PxTolerancesScale const&>(*scale_pod);
self_->setToDefault(scale);
}

bool PxSceneDesc_isValid_1(physx_PxSceneDesc_Pod const* self__pod) {
physx::PxSceneDesc const* self_ = reinterpret_cast<physx::PxSceneDesc const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

uint32_t PxSimulationStatistics_getNbBroadPhaseAdds(physx_PxSimulationStatistics_Pod const* self__pod) {
physx::PxSimulationStatistics const* self_ = reinterpret_cast<physx::PxSimulationStatistics const*>(self__pod);
uint32_t returnValue = self_->getNbBroadPhaseAdds();
return returnValue;
}

uint32_t PxSimulationStatistics_getNbBroadPhaseRemoves(physx_PxSimulationStatistics_Pod const* self__pod) {
physx::PxSimulationStatistics const* self_ = reinterpret_cast<physx::PxSimulationStatistics const*>(self__pod);
uint32_t returnValue = self_->getNbBroadPhaseRemoves();
return returnValue;
}

uint32_t PxSimulationStatistics_getRbPairStats(physx_PxSimulationStatistics_Pod const* self__pod, unsigned int pairType_pod, int g0_pod, int g1_pod) {
physx::PxSimulationStatistics const* self_ = reinterpret_cast<physx::PxSimulationStatistics const*>(self__pod);
physx::PxSimulationStatistics::RbPairStatsType pairType = (physx::PxSimulationStatistics::RbPairStatsType)pairType_pod;
PxGeometryType::Enum g0 = (PxGeometryType::Enum)g0_pod;
PxGeometryType::Enum g1 = (PxGeometryType::Enum)g1_pod;
uint32_t returnValue = self_->getRbPairStats(pairType, g0, g1);
return returnValue;
}

physx_PxSimulationStatistics_Pod PxSimulationStatistics_new() {
physx::PxSimulationStatistics returnValue;
physx_PxSimulationStatistics_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxPvdSceneClient_setScenePvdFlag_mut(physx_PxPvdSceneClient_Pod* self__pod, unsigned int flag_pod, bool value) {
physx::PxPvdSceneClient* self_ = reinterpret_cast<physx::PxPvdSceneClient*>(self__pod);
PxPvdSceneFlag::Enum flag = (PxPvdSceneFlag::Enum)flag_pod;
self_->setScenePvdFlag(flag, value);
}

void PxPvdSceneClient_setScenePvdFlags_mut(physx_PxPvdSceneClient_Pod* self__pod, physx_PxPvdSceneFlags_Pod flags_pod) {
physx::PxPvdSceneClient* self_ = reinterpret_cast<physx::PxPvdSceneClient*>(self__pod);
physx::PxPvdSceneFlags flags;
memcpy(&flags, &flags_pod, sizeof(flags));
self_->setScenePvdFlags(flags);
}

physx_PxPvdSceneFlags_Pod PxPvdSceneClient_getScenePvdFlags(physx_PxPvdSceneClient_Pod const* self__pod) {
physx::PxPvdSceneClient const* self_ = reinterpret_cast<physx::PxPvdSceneClient const*>(self__pod);
physx::PxPvdSceneFlags returnValue = self_->getScenePvdFlags();
physx_PxPvdSceneFlags_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxPvdSceneClient_updateCamera_mut(physx_PxPvdSceneClient_Pod* self__pod, char const* name, physx_PxVec3_Pod const* origin_pod, physx_PxVec3_Pod const* up_pod, physx_PxVec3_Pod const* target_pod) {
physx::PxPvdSceneClient* self_ = reinterpret_cast<physx::PxPvdSceneClient*>(self__pod);
physx::PxVec3 const& origin = reinterpret_cast<physx::PxVec3 const&>(*origin_pod);
physx::PxVec3 const& up = reinterpret_cast<physx::PxVec3 const&>(*up_pod);
physx::PxVec3 const& target = reinterpret_cast<physx::PxVec3 const&>(*target_pod);
self_->updateCamera(name, origin, up, target);
}

void PxPvdSceneClient_drawPoints_mut(physx_PxPvdSceneClient_Pod* self__pod, physx_pvdsdk_PvdDebugPoint_Pod const* points_pod, uint32_t count) {
physx::PxPvdSceneClient* self_ = reinterpret_cast<physx::PxPvdSceneClient*>(self__pod);
physx::pvdsdk::PvdDebugPoint const* points = reinterpret_cast<physx::pvdsdk::PvdDebugPoint const*>(points_pod);
self_->drawPoints(points, count);
}

void PxPvdSceneClient_drawLines_mut(physx_PxPvdSceneClient_Pod* self__pod, physx_pvdsdk_PvdDebugLine_Pod const* lines_pod, uint32_t count) {
physx::PxPvdSceneClient* self_ = reinterpret_cast<physx::PxPvdSceneClient*>(self__pod);
physx::pvdsdk::PvdDebugLine const* lines = reinterpret_cast<physx::pvdsdk::PvdDebugLine const*>(lines_pod);
self_->drawLines(lines, count);
}

void PxPvdSceneClient_drawTriangles_mut(physx_PxPvdSceneClient_Pod* self__pod, physx_pvdsdk_PvdDebugTriangle_Pod const* triangles_pod, uint32_t count) {
physx::PxPvdSceneClient* self_ = reinterpret_cast<physx::PxPvdSceneClient*>(self__pod);
physx::pvdsdk::PvdDebugTriangle const* triangles = reinterpret_cast<physx::pvdsdk::PvdDebugTriangle const*>(triangles_pod);
self_->drawTriangles(triangles, count);
}

void PxPvdSceneClient_drawText_mut(physx_PxPvdSceneClient_Pod* self__pod, physx_pvdsdk_PvdDebugText_Pod const* text_pod) {
physx::PxPvdSceneClient* self_ = reinterpret_cast<physx::PxPvdSceneClient*>(self__pod);
physx::pvdsdk::PvdDebugText const& text = reinterpret_cast<physx::pvdsdk::PvdDebugText const&>(*text_pod);
self_->drawText(text);
}

physx_pvdsdk_PvdClient_Pod* PxPvdSceneClient_getClientInternal_mut(physx_PxPvdSceneClient_Pod* self__pod) {
physx::PxPvdSceneClient* self_ = reinterpret_cast<physx::PxPvdSceneClient*>(self__pod);
physx::pvdsdk::PvdClient* returnValue = self_->getClientInternal();
physx_pvdsdk_PvdClient_Pod* returnValue_pod = reinterpret_cast<physx_pvdsdk_PvdClient_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxDominanceGroupPair_Pod PxDominanceGroupPair_new(unsigned char a, unsigned char b) {
physx::PxDominanceGroupPair returnValue(a, b);
physx_PxDominanceGroupPair_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxQueryCache_Pod PxQueryCache_new() {
physx::PxQueryCache returnValue;
physx_PxQueryCache_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxQueryCache_Pod PxQueryCache_new_1(physx_PxShape_Pod* s_pod, uint32_t findex) {
physx::PxShape* s = reinterpret_cast<physx::PxShape*>(s_pod);
physx::PxQueryCache returnValue(s, findex);
physx_PxQueryCache_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxScene_release_mut(physx_PxScene_Pod* self__pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
self_->release();
}

void PxScene_setFlag_mut(physx_PxScene_Pod* self__pod, unsigned int flag_pod, bool value) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
PxSceneFlag::Enum flag = (PxSceneFlag::Enum)flag_pod;
self_->setFlag(flag, value);
}

physx_PxSceneFlags_Pod PxScene_getFlags(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
physx::PxSceneFlags returnValue = self_->getFlags();
physx_PxSceneFlags_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxScene_setLimits_mut(physx_PxScene_Pod* self__pod, physx_PxSceneLimits_Pod const* limits_pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxSceneLimits const& limits = reinterpret_cast<physx::PxSceneLimits const&>(*limits_pod);
self_->setLimits(limits);
}

physx_PxSceneLimits_Pod PxScene_getLimits(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
physx::PxSceneLimits returnValue = self_->getLimits();
physx_PxSceneLimits_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxPhysics_Pod* PxScene_getPhysics_mut(physx_PxScene_Pod* self__pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxPhysics& returnValue = self_->getPhysics();
physx_PxPhysics_Pod* returnValue_pod = reinterpret_cast<physx_PxPhysics_Pod*>(&returnValue);
return returnValue_pod;
}

uint32_t PxScene_getTimestamp(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
uint32_t returnValue = self_->getTimestamp();
return returnValue;
}

void PxScene_addArticulation_mut(physx_PxScene_Pod* self__pod, physx_PxArticulationBase_Pod* articulation_pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxArticulationBase& articulation = reinterpret_cast<physx::PxArticulationBase&>(*articulation_pod);
self_->addArticulation(articulation);
}

void PxScene_removeArticulation_mut(physx_PxScene_Pod* self__pod, physx_PxArticulationBase_Pod* articulation_pod, bool wakeOnLostTouch) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxArticulationBase& articulation = reinterpret_cast<physx::PxArticulationBase&>(*articulation_pod);
self_->removeArticulation(articulation, wakeOnLostTouch);
}

void PxScene_addActor_mut(physx_PxScene_Pod* self__pod, physx_PxActor_Pod* actor_pod, physx_PxBVHStructure_Pod const* bvhStructure_pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxActor& actor = reinterpret_cast<physx::PxActor&>(*actor_pod);
physx::PxBVHStructure const* bvhStructure = reinterpret_cast<physx::PxBVHStructure const*>(bvhStructure_pod);
self_->addActor(actor, bvhStructure);
}

void PxScene_addActors_mut(physx_PxScene_Pod* self__pod, physx_PxActor_Pod* const* actors_pod, uint32_t nbActors) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxActor* const* actors = reinterpret_cast<physx::PxActor* const*>(actors_pod);
self_->addActors(actors, nbActors);
}

void PxScene_addActors_mut_1(physx_PxScene_Pod* self__pod, physx_PxPruningStructure_Pod const* pruningStructure_pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxPruningStructure const& pruningStructure = reinterpret_cast<physx::PxPruningStructure const&>(*pruningStructure_pod);
self_->addActors(pruningStructure);
}

void PxScene_removeActor_mut(physx_PxScene_Pod* self__pod, physx_PxActor_Pod* actor_pod, bool wakeOnLostTouch) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxActor& actor = reinterpret_cast<physx::PxActor&>(*actor_pod);
self_->removeActor(actor, wakeOnLostTouch);
}

void PxScene_removeActors_mut(physx_PxScene_Pod* self__pod, physx_PxActor_Pod* const* actors_pod, uint32_t nbActors, bool wakeOnLostTouch) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxActor* const* actors = reinterpret_cast<physx::PxActor* const*>(actors_pod);
self_->removeActors(actors, nbActors, wakeOnLostTouch);
}

void PxScene_addAggregate_mut(physx_PxScene_Pod* self__pod, physx_PxAggregate_Pod* aggregate_pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxAggregate& aggregate = reinterpret_cast<physx::PxAggregate&>(*aggregate_pod);
self_->addAggregate(aggregate);
}

void PxScene_removeAggregate_mut(physx_PxScene_Pod* self__pod, physx_PxAggregate_Pod* aggregate_pod, bool wakeOnLostTouch) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxAggregate& aggregate = reinterpret_cast<physx::PxAggregate&>(*aggregate_pod);
self_->removeAggregate(aggregate, wakeOnLostTouch);
}

void PxScene_addCollection_mut(physx_PxScene_Pod* self__pod, physx_PxCollection_Pod const* collection_pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxCollection const& collection = reinterpret_cast<physx::PxCollection const&>(*collection_pod);
self_->addCollection(collection);
}

uint32_t PxScene_getNbActors(physx_PxScene_Pod const* self__pod, physx_PxActorTypeFlags_Pod types_pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
physx::PxActorTypeFlags types;
memcpy(&types, &types_pod, sizeof(types));
uint32_t returnValue = self_->getNbActors(types);
return returnValue;
}

uint32_t PxScene_getActors(physx_PxScene_Pod const* self__pod, physx_PxActorTypeFlags_Pod types_pod, physx_PxActor_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
physx::PxActorTypeFlags types;
memcpy(&types, &types_pod, sizeof(types));
physx::PxActor** userBuffer = reinterpret_cast<physx::PxActor**>(userBuffer_pod);
uint32_t returnValue = self_->getActors(types, userBuffer, bufferSize, startIndex);
return returnValue;
}

physx_PxActor_Pod** PxScene_getActiveActors_mut(physx_PxScene_Pod* self__pod, uint32_t* nbActorsOut_pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
uint32_t& nbActorsOut = *nbActorsOut_pod;
physx::PxActor** returnValue = self_->getActiveActors(nbActorsOut);
physx_PxActor_Pod** returnValue_pod = reinterpret_cast<physx_PxActor_Pod**>(returnValue);
return returnValue_pod;
}

uint32_t PxScene_getNbArticulations(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
uint32_t returnValue = self_->getNbArticulations();
return returnValue;
}

uint32_t PxScene_getArticulations(physx_PxScene_Pod const* self__pod, physx_PxArticulationBase_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
physx::PxArticulationBase** userBuffer = reinterpret_cast<physx::PxArticulationBase**>(userBuffer_pod);
uint32_t returnValue = self_->getArticulations(userBuffer, bufferSize, startIndex);
return returnValue;
}

uint32_t PxScene_getNbConstraints(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
uint32_t returnValue = self_->getNbConstraints();
return returnValue;
}

uint32_t PxScene_getConstraints(physx_PxScene_Pod const* self__pod, physx_PxConstraint_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
physx::PxConstraint** userBuffer = reinterpret_cast<physx::PxConstraint**>(userBuffer_pod);
uint32_t returnValue = self_->getConstraints(userBuffer, bufferSize, startIndex);
return returnValue;
}

uint32_t PxScene_getNbAggregates(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
uint32_t returnValue = self_->getNbAggregates();
return returnValue;
}

uint32_t PxScene_getAggregates(physx_PxScene_Pod const* self__pod, physx_PxAggregate_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
physx::PxAggregate** userBuffer = reinterpret_cast<physx::PxAggregate**>(userBuffer_pod);
uint32_t returnValue = self_->getAggregates(userBuffer, bufferSize, startIndex);
return returnValue;
}

void PxScene_setDominanceGroupPair_mut(physx_PxScene_Pod* self__pod, unsigned char group1, unsigned char group2, physx_PxDominanceGroupPair_Pod const* dominance_pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxDominanceGroupPair const& dominance = reinterpret_cast<physx::PxDominanceGroupPair const&>(*dominance_pod);
self_->setDominanceGroupPair(group1, group2, dominance);
}

physx_PxDominanceGroupPair_Pod PxScene_getDominanceGroupPair(physx_PxScene_Pod const* self__pod, unsigned char group1, unsigned char group2) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
physx::PxDominanceGroupPair returnValue = self_->getDominanceGroupPair(group1, group2);
physx_PxDominanceGroupPair_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxCpuDispatcher_Pod* PxScene_getCpuDispatcher(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
physx::PxCpuDispatcher* returnValue = self_->getCpuDispatcher();
physx_PxCpuDispatcher_Pod* returnValue_pod = reinterpret_cast<physx_PxCpuDispatcher_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxCudaContextManager_Pod* PxScene_getCudaContextManager(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
physx::PxCudaContextManager* returnValue = self_->getCudaContextManager();
physx_PxCudaContextManager_Pod* returnValue_pod = reinterpret_cast<physx_PxCudaContextManager_Pod*>(returnValue);
return returnValue_pod;
}

unsigned char PxScene_createClient_mut(physx_PxScene_Pod* self__pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
unsigned char returnValue = self_->createClient();
return returnValue;
}

void PxScene_setSimulationEventCallback_mut(physx_PxScene_Pod* self__pod, physx_PxSimulationEventCallback_Pod* callback_pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxSimulationEventCallback* callback = reinterpret_cast<physx::PxSimulationEventCallback*>(callback_pod);
self_->setSimulationEventCallback(callback);
}

physx_PxSimulationEventCallback_Pod* PxScene_getSimulationEventCallback(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
physx::PxSimulationEventCallback* returnValue = self_->getSimulationEventCallback();
physx_PxSimulationEventCallback_Pod* returnValue_pod = reinterpret_cast<physx_PxSimulationEventCallback_Pod*>(returnValue);
return returnValue_pod;
}

void PxScene_setContactModifyCallback_mut(physx_PxScene_Pod* self__pod, physx_PxContactModifyCallback_Pod* callback_pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxContactModifyCallback* callback = reinterpret_cast<physx::PxContactModifyCallback*>(callback_pod);
self_->setContactModifyCallback(callback);
}

void PxScene_setCCDContactModifyCallback_mut(physx_PxScene_Pod* self__pod, physx_PxCCDContactModifyCallback_Pod* callback_pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxCCDContactModifyCallback* callback = reinterpret_cast<physx::PxCCDContactModifyCallback*>(callback_pod);
self_->setCCDContactModifyCallback(callback);
}

physx_PxContactModifyCallback_Pod* PxScene_getContactModifyCallback(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
physx::PxContactModifyCallback* returnValue = self_->getContactModifyCallback();
physx_PxContactModifyCallback_Pod* returnValue_pod = reinterpret_cast<physx_PxContactModifyCallback_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxCCDContactModifyCallback_Pod* PxScene_getCCDContactModifyCallback(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
physx::PxCCDContactModifyCallback* returnValue = self_->getCCDContactModifyCallback();
physx_PxCCDContactModifyCallback_Pod* returnValue_pod = reinterpret_cast<physx_PxCCDContactModifyCallback_Pod*>(returnValue);
return returnValue_pod;
}

void PxScene_setBroadPhaseCallback_mut(physx_PxScene_Pod* self__pod, physx_PxBroadPhaseCallback_Pod* callback_pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxBroadPhaseCallback* callback = reinterpret_cast<physx::PxBroadPhaseCallback*>(callback_pod);
self_->setBroadPhaseCallback(callback);
}

physx_PxBroadPhaseCallback_Pod* PxScene_getBroadPhaseCallback(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
physx::PxBroadPhaseCallback* returnValue = self_->getBroadPhaseCallback();
physx_PxBroadPhaseCallback_Pod* returnValue_pod = reinterpret_cast<physx_PxBroadPhaseCallback_Pod*>(returnValue);
return returnValue_pod;
}

void PxScene_setFilterShaderData_mut(physx_PxScene_Pod* self__pod, void const* data, uint32_t dataSize) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
self_->setFilterShaderData(data, dataSize);
}

void const* PxScene_getFilterShaderData(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
void const* returnValue = self_->getFilterShaderData();
return returnValue;
}

uint32_t PxScene_getFilterShaderDataSize(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
uint32_t returnValue = self_->getFilterShaderDataSize();
return returnValue;
}

void* PxScene_getFilterShader(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
physx::PxSimulationFilterShader returnValue = self_->getFilterShader();
void* returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxSimulationFilterCallback_Pod* PxScene_getFilterCallback(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
physx::PxSimulationFilterCallback* returnValue = self_->getFilterCallback();
physx_PxSimulationFilterCallback_Pod* returnValue_pod = reinterpret_cast<physx_PxSimulationFilterCallback_Pod*>(returnValue);
return returnValue_pod;
}

void PxScene_resetFiltering_mut(physx_PxScene_Pod* self__pod, physx_PxActor_Pod* actor_pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxActor& actor = reinterpret_cast<physx::PxActor&>(*actor_pod);
self_->resetFiltering(actor);
}

void PxScene_resetFiltering_mut_1(physx_PxScene_Pod* self__pod, physx_PxRigidActor_Pod* actor_pod, physx_PxShape_Pod* const* shapes_pod, uint32_t shapeCount) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxRigidActor& actor = reinterpret_cast<physx::PxRigidActor&>(*actor_pod);
physx::PxShape* const* shapes = reinterpret_cast<physx::PxShape* const*>(shapes_pod);
self_->resetFiltering(actor, shapes, shapeCount);
}

unsigned int PxScene_getKinematicKinematicFilteringMode(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
PxPairFilteringMode::Enum returnValue = self_->getKinematicKinematicFilteringMode();
unsigned int returnValue_pod = (unsigned int)returnValue;
return returnValue_pod;
}

unsigned int PxScene_getStaticKinematicFilteringMode(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
PxPairFilteringMode::Enum returnValue = self_->getStaticKinematicFilteringMode();
unsigned int returnValue_pod = (unsigned int)returnValue;
return returnValue_pod;
}

void PxScene_simulate_mut(physx_PxScene_Pod* self__pod, float elapsedTime, physx_PxBaseTask_Pod* completionTask_pod, void* scratchMemBlock, uint32_t scratchMemBlockSize, bool controlSimulation) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxBaseTask* completionTask = reinterpret_cast<physx::PxBaseTask*>(completionTask_pod);
self_->simulate(elapsedTime, completionTask, scratchMemBlock, scratchMemBlockSize, controlSimulation);
}

void PxScene_advance_mut(physx_PxScene_Pod* self__pod, physx_PxBaseTask_Pod* completionTask_pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxBaseTask* completionTask = reinterpret_cast<physx::PxBaseTask*>(completionTask_pod);
self_->advance(completionTask);
}

void PxScene_collide_mut(physx_PxScene_Pod* self__pod, float elapsedTime, physx_PxBaseTask_Pod* completionTask_pod, void* scratchMemBlock, uint32_t scratchMemBlockSize, bool controlSimulation) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxBaseTask* completionTask = reinterpret_cast<physx::PxBaseTask*>(completionTask_pod);
self_->collide(elapsedTime, completionTask, scratchMemBlock, scratchMemBlockSize, controlSimulation);
}

bool PxScene_checkResults_mut(physx_PxScene_Pod* self__pod, bool block) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
bool returnValue = self_->checkResults(block);
return returnValue;
}

bool PxScene_fetchCollision_mut(physx_PxScene_Pod* self__pod, bool block) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
bool returnValue = self_->fetchCollision(block);
return returnValue;
}

bool PxScene_fetchResults_mut(physx_PxScene_Pod* self__pod, bool block, uint32_t* errorState) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
bool returnValue = self_->fetchResults(block, errorState);
return returnValue;
}

bool PxScene_fetchResultsStart_mut(physx_PxScene_Pod* self__pod, physx_PxContactPairHeader_Pod const** contactPairs_pod, uint32_t* nbContactPairs_pod, bool block) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxContactPairHeader const*& contactPairs = reinterpret_cast<physx::PxContactPairHeader const*&>(*contactPairs_pod);
uint32_t& nbContactPairs = *nbContactPairs_pod;
bool returnValue = self_->fetchResultsStart(contactPairs, nbContactPairs, block);
return returnValue;
}

void PxScene_processCallbacks_mut(physx_PxScene_Pod* self__pod, physx_PxBaseTask_Pod* continuation_pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxBaseTask* continuation = reinterpret_cast<physx::PxBaseTask*>(continuation_pod);
self_->processCallbacks(continuation);
}

void PxScene_fetchResultsFinish_mut(physx_PxScene_Pod* self__pod, uint32_t* errorState) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
self_->fetchResultsFinish(errorState);
}

void PxScene_flushSimulation_mut(physx_PxScene_Pod* self__pod, bool sendPendingReports) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
self_->flushSimulation(sendPendingReports);
}

void PxScene_setGravity_mut(physx_PxScene_Pod* self__pod, physx_PxVec3_Pod const* vec_pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxVec3 const& vec = reinterpret_cast<physx::PxVec3 const&>(*vec_pod);
self_->setGravity(vec);
}

physx_PxVec3_Pod PxScene_getGravity(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
physx::PxVec3 returnValue = self_->getGravity();
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxScene_setBounceThresholdVelocity_mut(physx_PxScene_Pod* self__pod, float t) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
self_->setBounceThresholdVelocity(t);
}

float PxScene_getBounceThresholdVelocity(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
float returnValue = self_->getBounceThresholdVelocity();
return returnValue;
}

void PxScene_setCCDMaxPasses_mut(physx_PxScene_Pod* self__pod, uint32_t ccdMaxPasses) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
self_->setCCDMaxPasses(ccdMaxPasses);
}

uint32_t PxScene_getCCDMaxPasses(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
uint32_t returnValue = self_->getCCDMaxPasses();
return returnValue;
}

float PxScene_getFrictionOffsetThreshold(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
float returnValue = self_->getFrictionOffsetThreshold();
return returnValue;
}

void PxScene_setFrictionType_mut(physx_PxScene_Pod* self__pod, unsigned int frictionType_pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
PxFrictionType::Enum frictionType = (PxFrictionType::Enum)frictionType_pod;
self_->setFrictionType(frictionType);
}

unsigned int PxScene_getFrictionType(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
PxFrictionType::Enum returnValue = self_->getFrictionType();
unsigned int returnValue_pod = (unsigned int)returnValue;
return returnValue_pod;
}

bool PxScene_setVisualizationParameter_mut(physx_PxScene_Pod* self__pod, unsigned int param_pod, float value) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
PxVisualizationParameter::Enum param = (PxVisualizationParameter::Enum)param_pod;
bool returnValue = self_->setVisualizationParameter(param, value);
return returnValue;
}

float PxScene_getVisualizationParameter(physx_PxScene_Pod const* self__pod, unsigned int paramEnum_pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
PxVisualizationParameter::Enum paramEnum = (PxVisualizationParameter::Enum)paramEnum_pod;
float returnValue = self_->getVisualizationParameter(paramEnum);
return returnValue;
}

void PxScene_setVisualizationCullingBox_mut(physx_PxScene_Pod* self__pod, physx_PxBounds3_Pod const* box_pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxBounds3 const& box = reinterpret_cast<physx::PxBounds3 const&>(*box_pod);
self_->setVisualizationCullingBox(box);
}

physx_PxBounds3_Pod PxScene_getVisualizationCullingBox(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
physx::PxBounds3 returnValue = self_->getVisualizationCullingBox();
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxRenderBuffer_Pod const* PxScene_getRenderBuffer_mut(physx_PxScene_Pod* self__pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxRenderBuffer const& returnValue = self_->getRenderBuffer();
physx_PxRenderBuffer_Pod const* returnValue_pod = reinterpret_cast<physx_PxRenderBuffer_Pod const*>(&returnValue);
return returnValue_pod;
}

void PxScene_getSimulationStatistics(physx_PxScene_Pod const* self__pod, physx_PxSimulationStatistics_Pod* stats_pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
physx::PxSimulationStatistics& stats = reinterpret_cast<physx::PxSimulationStatistics&>(*stats_pod);
self_->getSimulationStatistics(stats);
}

unsigned int PxScene_getStaticStructure(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
PxPruningStructureType::Enum returnValue = self_->getStaticStructure();
unsigned int returnValue_pod = (unsigned int)returnValue;
return returnValue_pod;
}

unsigned int PxScene_getDynamicStructure(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
PxPruningStructureType::Enum returnValue = self_->getDynamicStructure();
unsigned int returnValue_pod = (unsigned int)returnValue;
return returnValue_pod;
}

void PxScene_flushQueryUpdates_mut(physx_PxScene_Pod* self__pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
self_->flushQueryUpdates();
}

physx_PxBatchQuery_Pod* PxScene_createBatchQuery_mut(physx_PxScene_Pod* self__pod, physx_PxBatchQueryDesc_Pod const* desc_pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxBatchQueryDesc const& desc = reinterpret_cast<physx::PxBatchQueryDesc const&>(*desc_pod);
physx::PxBatchQuery* returnValue = self_->createBatchQuery(desc);
physx_PxBatchQuery_Pod* returnValue_pod = reinterpret_cast<physx_PxBatchQuery_Pod*>(returnValue);
return returnValue_pod;
}

void PxScene_setDynamicTreeRebuildRateHint_mut(physx_PxScene_Pod* self__pod, uint32_t dynamicTreeRebuildRateHint) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
self_->setDynamicTreeRebuildRateHint(dynamicTreeRebuildRateHint);
}

uint32_t PxScene_getDynamicTreeRebuildRateHint(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
uint32_t returnValue = self_->getDynamicTreeRebuildRateHint();
return returnValue;
}

void PxScene_forceDynamicTreeRebuild_mut(physx_PxScene_Pod* self__pod, bool rebuildStaticStructure, bool rebuildDynamicStructure) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
self_->forceDynamicTreeRebuild(rebuildStaticStructure, rebuildDynamicStructure);
}

void PxScene_setSceneQueryUpdateMode_mut(physx_PxScene_Pod* self__pod, unsigned int updateMode_pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
PxSceneQueryUpdateMode::Enum updateMode = (PxSceneQueryUpdateMode::Enum)updateMode_pod;
self_->setSceneQueryUpdateMode(updateMode);
}

unsigned int PxScene_getSceneQueryUpdateMode(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
PxSceneQueryUpdateMode::Enum returnValue = self_->getSceneQueryUpdateMode();
unsigned int returnValue_pod = (unsigned int)returnValue;
return returnValue_pod;
}

void PxScene_sceneQueriesUpdate_mut(physx_PxScene_Pod* self__pod, physx_PxBaseTask_Pod* completionTask_pod, bool controlSimulation) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxBaseTask* completionTask = reinterpret_cast<physx::PxBaseTask*>(completionTask_pod);
self_->sceneQueriesUpdate(completionTask, controlSimulation);
}

bool PxScene_checkQueries_mut(physx_PxScene_Pod* self__pod, bool block) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
bool returnValue = self_->checkQueries(block);
return returnValue;
}

bool PxScene_fetchQueries_mut(physx_PxScene_Pod* self__pod, bool block) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
bool returnValue = self_->fetchQueries(block);
return returnValue;
}

bool PxScene_raycast(physx_PxScene_Pod const* self__pod, physx_PxVec3_Pod const* origin_pod, physx_PxVec3_Pod const* unitDir_pod, float distance, physx_PxRaycastCallback_Pod* hitCall_pod, physx_PxHitFlags_Pod hitFlags_pod, physx_PxQueryFilterData_Pod const* filterData_pod, physx_PxQueryFilterCallback_Pod* filterCall_pod, physx_PxQueryCache_Pod const* cache_pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
physx::PxVec3 const& origin = reinterpret_cast<physx::PxVec3 const&>(*origin_pod);
physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
physx::PxRaycastCallback& hitCall = reinterpret_cast<physx::PxRaycastCallback&>(*hitCall_pod);
physx::PxHitFlags hitFlags;
memcpy(&hitFlags, &hitFlags_pod, sizeof(hitFlags));
physx::PxQueryFilterData const& filterData = reinterpret_cast<physx::PxQueryFilterData const&>(*filterData_pod);
physx::PxQueryFilterCallback* filterCall = reinterpret_cast<physx::PxQueryFilterCallback*>(filterCall_pod);
physx::PxQueryCache const* cache = reinterpret_cast<physx::PxQueryCache const*>(cache_pod);
bool returnValue = self_->raycast(origin, unitDir, distance, hitCall, hitFlags, filterData, filterCall, cache);
return returnValue;
}

bool PxScene_sweep(physx_PxScene_Pod const* self__pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxTransform_Pod const* pose_pod, physx_PxVec3_Pod const* unitDir_pod, float distance, physx_PxSweepCallback_Pod* hitCall_pod, physx_PxHitFlags_Pod hitFlags_pod, physx_PxQueryFilterData_Pod const* filterData_pod, physx_PxQueryFilterCallback_Pod* filterCall_pod, physx_PxQueryCache_Pod const* cache_pod, float inflation) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
physx::PxSweepCallback& hitCall = reinterpret_cast<physx::PxSweepCallback&>(*hitCall_pod);
physx::PxHitFlags hitFlags;
memcpy(&hitFlags, &hitFlags_pod, sizeof(hitFlags));
physx::PxQueryFilterData const& filterData = reinterpret_cast<physx::PxQueryFilterData const&>(*filterData_pod);
physx::PxQueryFilterCallback* filterCall = reinterpret_cast<physx::PxQueryFilterCallback*>(filterCall_pod);
physx::PxQueryCache const* cache = reinterpret_cast<physx::PxQueryCache const*>(cache_pod);
bool returnValue = self_->sweep(geometry, pose, unitDir, distance, hitCall, hitFlags, filterData, filterCall, cache, inflation);
return returnValue;
}

bool PxScene_overlap(physx_PxScene_Pod const* self__pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxTransform_Pod const* pose_pod, physx_PxOverlapCallback_Pod* hitCall_pod, physx_PxQueryFilterData_Pod const* filterData_pod, physx_PxQueryFilterCallback_Pod* filterCall_pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
physx::PxOverlapCallback& hitCall = reinterpret_cast<physx::PxOverlapCallback&>(*hitCall_pod);
physx::PxQueryFilterData const& filterData = reinterpret_cast<physx::PxQueryFilterData const&>(*filterData_pod);
physx::PxQueryFilterCallback* filterCall = reinterpret_cast<physx::PxQueryFilterCallback*>(filterCall_pod);
bool returnValue = self_->overlap(geometry, pose, hitCall, filterData, filterCall);
return returnValue;
}

uint32_t PxScene_getSceneQueryStaticTimestamp(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
uint32_t returnValue = self_->getSceneQueryStaticTimestamp();
return returnValue;
}

unsigned int PxScene_getBroadPhaseType(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
PxBroadPhaseType::Enum returnValue = self_->getBroadPhaseType();
unsigned int returnValue_pod = (unsigned int)returnValue;
return returnValue_pod;
}

bool PxScene_getBroadPhaseCaps(physx_PxScene_Pod const* self__pod, physx_PxBroadPhaseCaps_Pod* caps_pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
physx::PxBroadPhaseCaps& caps = reinterpret_cast<physx::PxBroadPhaseCaps&>(*caps_pod);
bool returnValue = self_->getBroadPhaseCaps(caps);
return returnValue;
}

uint32_t PxScene_getNbBroadPhaseRegions(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
uint32_t returnValue = self_->getNbBroadPhaseRegions();
return returnValue;
}

uint32_t PxScene_getBroadPhaseRegions(physx_PxScene_Pod const* self__pod, physx_PxBroadPhaseRegionInfo_Pod* userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
physx::PxBroadPhaseRegionInfo* userBuffer = reinterpret_cast<physx::PxBroadPhaseRegionInfo*>(userBuffer_pod);
uint32_t returnValue = self_->getBroadPhaseRegions(userBuffer, bufferSize, startIndex);
return returnValue;
}

uint32_t PxScene_addBroadPhaseRegion_mut(physx_PxScene_Pod* self__pod, physx_PxBroadPhaseRegion_Pod const* region_pod, bool populateRegion) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxBroadPhaseRegion const& region = reinterpret_cast<physx::PxBroadPhaseRegion const&>(*region_pod);
uint32_t returnValue = self_->addBroadPhaseRegion(region, populateRegion);
return returnValue;
}

bool PxScene_removeBroadPhaseRegion_mut(physx_PxScene_Pod* self__pod, uint32_t handle) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
bool returnValue = self_->removeBroadPhaseRegion(handle);
return returnValue;
}

physx_PxTaskManager_Pod* PxScene_getTaskManager(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
physx::PxTaskManager* returnValue = self_->getTaskManager();
physx_PxTaskManager_Pod* returnValue_pod = reinterpret_cast<physx_PxTaskManager_Pod*>(returnValue);
return returnValue_pod;
}

void PxScene_lockRead_mut(physx_PxScene_Pod* self__pod, char const* file, uint32_t line) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
self_->lockRead(file, line);
}

void PxScene_unlockRead_mut(physx_PxScene_Pod* self__pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
self_->unlockRead();
}

void PxScene_lockWrite_mut(physx_PxScene_Pod* self__pod, char const* file, uint32_t line) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
self_->lockWrite(file, line);
}

void PxScene_unlockWrite_mut(physx_PxScene_Pod* self__pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
self_->unlockWrite();
}

void PxScene_setNbContactDataBlocks_mut(physx_PxScene_Pod* self__pod, uint32_t numBlocks) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
self_->setNbContactDataBlocks(numBlocks);
}

uint32_t PxScene_getNbContactDataBlocksUsed(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
uint32_t returnValue = self_->getNbContactDataBlocksUsed();
return returnValue;
}

uint32_t PxScene_getMaxNbContactDataBlocksUsed(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
uint32_t returnValue = self_->getMaxNbContactDataBlocksUsed();
return returnValue;
}

uint32_t PxScene_getContactReportStreamBufferSize(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
uint32_t returnValue = self_->getContactReportStreamBufferSize();
return returnValue;
}

void PxScene_setSolverBatchSize_mut(physx_PxScene_Pod* self__pod, uint32_t solverBatchSize) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
self_->setSolverBatchSize(solverBatchSize);
}

uint32_t PxScene_getSolverBatchSize(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
uint32_t returnValue = self_->getSolverBatchSize();
return returnValue;
}

void PxScene_setSolverArticulationBatchSize_mut(physx_PxScene_Pod* self__pod, uint32_t solverBatchSize) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
self_->setSolverArticulationBatchSize(solverBatchSize);
}

uint32_t PxScene_getSolverArticulationBatchSize(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
uint32_t returnValue = self_->getSolverArticulationBatchSize();
return returnValue;
}

float PxScene_getWakeCounterResetValue(physx_PxScene_Pod const* self__pod) {
physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
float returnValue = self_->getWakeCounterResetValue();
return returnValue;
}

void PxScene_shiftOrigin_mut(physx_PxScene_Pod* self__pod, physx_PxVec3_Pod const* shift_pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxVec3 const& shift = reinterpret_cast<physx::PxVec3 const&>(*shift_pod);
self_->shiftOrigin(shift);
}

physx_PxPvdSceneClient_Pod* PxScene_getScenePvdClient_mut(physx_PxScene_Pod* self__pod) {
physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
physx::PxPvdSceneClient* returnValue = self_->getScenePvdClient();
physx_PxPvdSceneClient_Pod* returnValue_pod = reinterpret_cast<physx_PxPvdSceneClient_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxSceneReadLock_Pod* PxSceneReadLock_new_alloc(physx_PxScene_Pod* scene_pod, char const* file, uint32_t line) {
physx::PxScene& scene = reinterpret_cast<physx::PxScene&>(*scene_pod);
auto returnValue = new physx::PxSceneReadLock(scene, file, line);
physx_PxSceneReadLock_Pod* returnValue_pod = reinterpret_cast<physx_PxSceneReadLock_Pod*>(returnValue);
return returnValue_pod;
}

void PxSceneReadLock_delete(physx_PxSceneReadLock_Pod* self__pod) {
physx::PxSceneReadLock* self_ = reinterpret_cast<physx::PxSceneReadLock*>(self__pod);
delete self_;
}

physx_PxSceneWriteLock_Pod* PxSceneWriteLock_new_alloc(physx_PxScene_Pod* scene_pod, char const* file, uint32_t line) {
physx::PxScene& scene = reinterpret_cast<physx::PxScene&>(*scene_pod);
auto returnValue = new physx::PxSceneWriteLock(scene, file, line);
physx_PxSceneWriteLock_Pod* returnValue_pod = reinterpret_cast<physx_PxSceneWriteLock_Pod*>(returnValue);
return returnValue_pod;
}

void PxSceneWriteLock_delete(physx_PxSceneWriteLock_Pod* self__pod) {
physx::PxSceneWriteLock* self_ = reinterpret_cast<physx::PxSceneWriteLock*>(self__pod);
delete self_;
}

physx_PxContactPairExtraDataItem_Pod PxContactPairExtraDataItem_new() {
physx::PxContactPairExtraDataItem returnValue;
physx_PxContactPairExtraDataItem_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxContactPairVelocity_Pod PxContactPairVelocity_new() {
physx::PxContactPairVelocity returnValue;
physx_PxContactPairVelocity_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxContactPairPose_Pod PxContactPairPose_new() {
physx::PxContactPairPose returnValue;
physx_PxContactPairPose_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxContactPairIndex_Pod PxContactPairIndex_new() {
physx::PxContactPairIndex returnValue;
physx_PxContactPairIndex_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxContactPairExtraDataIterator_Pod PxContactPairExtraDataIterator_new(unsigned char const* stream, uint32_t size) {
physx::PxContactPairExtraDataIterator returnValue(stream, size);
physx_PxContactPairExtraDataIterator_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxContactPairExtraDataIterator_nextItemSet_mut(physx_PxContactPairExtraDataIterator_Pod* self__pod) {
physx::PxContactPairExtraDataIterator* self_ = reinterpret_cast<physx::PxContactPairExtraDataIterator*>(self__pod);
bool returnValue = self_->nextItemSet();
return returnValue;
}

physx_PxContactPairHeader_Pod PxContactPairHeader_new() {
physx::PxContactPairHeader returnValue;
physx_PxContactPairHeader_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxContactPair_Pod PxContactPair_new() {
physx::PxContactPair returnValue;
physx_PxContactPair_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

uint32_t PxContactPair_extractContacts(physx_PxContactPair_Pod const* self__pod, physx_PxContactPairPoint_Pod* userBuffer_pod, uint32_t bufferSize) {
physx::PxContactPair const* self_ = reinterpret_cast<physx::PxContactPair const*>(self__pod);
physx::PxContactPairPoint* userBuffer = reinterpret_cast<physx::PxContactPairPoint*>(userBuffer_pod);
uint32_t returnValue = self_->extractContacts(userBuffer, bufferSize);
return returnValue;
}

void PxContactPair_bufferContacts(physx_PxContactPair_Pod const* self__pod, physx_PxContactPair_Pod* newPair_pod, unsigned char* bufferMemory) {
physx::PxContactPair const* self_ = reinterpret_cast<physx::PxContactPair const*>(self__pod);
physx::PxContactPair* newPair = reinterpret_cast<physx::PxContactPair*>(newPair_pod);
self_->bufferContacts(newPair, bufferMemory);
}

uint32_t const* PxContactPair_getInternalFaceIndices(physx_PxContactPair_Pod const* self__pod) {
physx::PxContactPair const* self_ = reinterpret_cast<physx::PxContactPair const*>(self__pod);
uint32_t const* returnValue = self_->getInternalFaceIndices();
return returnValue;
}

uint32_t PxContactPair_extractContacts_1(physx_PxContactPair_Pod const* self__pod, physx_PxContactPairPoint_Pod* userBuffer_pod, uint32_t bufferSize) {
physx::PxContactPair const* self_ = reinterpret_cast<physx::PxContactPair const*>(self__pod);
physx::PxContactPairPoint* userBuffer = reinterpret_cast<physx::PxContactPairPoint*>(userBuffer_pod);
uint32_t returnValue = self_->extractContacts(userBuffer, bufferSize);
return returnValue;
}

void PxContactPair_bufferContacts_1(physx_PxContactPair_Pod const* self__pod, physx_PxContactPair_Pod* newPair_pod, unsigned char* bufferMemory) {
physx::PxContactPair const* self_ = reinterpret_cast<physx::PxContactPair const*>(self__pod);
physx::PxContactPair* newPair = reinterpret_cast<physx::PxContactPair*>(newPair_pod);
self_->bufferContacts(newPair, bufferMemory);
}

uint32_t const* PxContactPair_getInternalFaceIndices_1(physx_PxContactPair_Pod const* self__pod) {
physx::PxContactPair const* self_ = reinterpret_cast<physx::PxContactPair const*>(self__pod);
uint32_t const* returnValue = self_->getInternalFaceIndices();
return returnValue;
}

physx_PxTriggerPair_Pod PxTriggerPair_new() {
physx::PxTriggerPair returnValue;
physx_PxTriggerPair_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxConstraintInfo_Pod PxConstraintInfo_new() {
physx::PxConstraintInfo returnValue;
physx_PxConstraintInfo_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxConstraintInfo_Pod PxConstraintInfo_new_1(physx_PxConstraint_Pod* c_pod, void* extRef, uint32_t t) {
physx::PxConstraint* c = reinterpret_cast<physx::PxConstraint*>(c_pod);
physx::PxConstraintInfo returnValue(c, extRef, t);
physx_PxConstraintInfo_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxSimulationEventCallback_onConstraintBreak_mut(physx_PxSimulationEventCallback_Pod* self__pod, physx_PxConstraintInfo_Pod* constraints_pod, uint32_t count) {
physx::PxSimulationEventCallback* self_ = reinterpret_cast<physx::PxSimulationEventCallback*>(self__pod);
physx::PxConstraintInfo* constraints = reinterpret_cast<physx::PxConstraintInfo*>(constraints_pod);
self_->onConstraintBreak(constraints, count);
}

void PxSimulationEventCallback_onWake_mut(physx_PxSimulationEventCallback_Pod* self__pod, physx_PxActor_Pod** actors_pod, uint32_t count) {
physx::PxSimulationEventCallback* self_ = reinterpret_cast<physx::PxSimulationEventCallback*>(self__pod);
physx::PxActor** actors = reinterpret_cast<physx::PxActor**>(actors_pod);
self_->onWake(actors, count);
}

void PxSimulationEventCallback_onSleep_mut(physx_PxSimulationEventCallback_Pod* self__pod, physx_PxActor_Pod** actors_pod, uint32_t count) {
physx::PxSimulationEventCallback* self_ = reinterpret_cast<physx::PxSimulationEventCallback*>(self__pod);
physx::PxActor** actors = reinterpret_cast<physx::PxActor**>(actors_pod);
self_->onSleep(actors, count);
}

void PxSimulationEventCallback_onContact_mut(physx_PxSimulationEventCallback_Pod* self__pod, physx_PxContactPairHeader_Pod const* pairHeader_pod, physx_PxContactPair_Pod const* pairs_pod, uint32_t nbPairs) {
physx::PxSimulationEventCallback* self_ = reinterpret_cast<physx::PxSimulationEventCallback*>(self__pod);
physx::PxContactPairHeader const& pairHeader = reinterpret_cast<physx::PxContactPairHeader const&>(*pairHeader_pod);
physx::PxContactPair const* pairs = reinterpret_cast<physx::PxContactPair const*>(pairs_pod);
self_->onContact(pairHeader, pairs, nbPairs);
}

void PxSimulationEventCallback_onTrigger_mut(physx_PxSimulationEventCallback_Pod* self__pod, physx_PxTriggerPair_Pod* pairs_pod, uint32_t count) {
physx::PxSimulationEventCallback* self_ = reinterpret_cast<physx::PxSimulationEventCallback*>(self__pod);
physx::PxTriggerPair* pairs = reinterpret_cast<physx::PxTriggerPair*>(pairs_pod);
self_->onTrigger(pairs, count);
}

void PxSimulationEventCallback_onAdvance_mut(physx_PxSimulationEventCallback_Pod* self__pod, physx_PxRigidBody_Pod const* const* bodyBuffer_pod, physx_PxTransform_Pod const* poseBuffer_pod, uint32_t count) {
physx::PxSimulationEventCallback* self_ = reinterpret_cast<physx::PxSimulationEventCallback*>(self__pod);
physx::PxRigidBody const* const* bodyBuffer = reinterpret_cast<physx::PxRigidBody const* const*>(bodyBuffer_pod);
physx::PxTransform const* poseBuffer = reinterpret_cast<physx::PxTransform const*>(poseBuffer_pod);
self_->onAdvance(bodyBuffer, poseBuffer, count);
}

void PxSimulationEventCallback_delete(physx_PxSimulationEventCallback_Pod* self__pod) {
physx::PxSimulationEventCallback* self_ = reinterpret_cast<physx::PxSimulationEventCallback*>(self__pod);
delete self_;
}

void PxPruningStructure_release_mut(physx_PxPruningStructure_Pod* self__pod) {
physx::PxPruningStructure* self_ = reinterpret_cast<physx::PxPruningStructure*>(self__pod);
self_->release();
}

uint32_t PxPruningStructure_getRigidActors(physx_PxPruningStructure_Pod const* self__pod, physx_PxRigidActor_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
physx::PxPruningStructure const* self_ = reinterpret_cast<physx::PxPruningStructure const*>(self__pod);
physx::PxRigidActor** userBuffer = reinterpret_cast<physx::PxRigidActor**>(userBuffer_pod);
uint32_t returnValue = self_->getRigidActors(userBuffer, bufferSize, startIndex);
return returnValue;
}

uint32_t PxPruningStructure_getNbRigidActors(physx_PxPruningStructure_Pod const* self__pod) {
physx::PxPruningStructure const* self_ = reinterpret_cast<physx::PxPruningStructure const*>(self__pod);
uint32_t returnValue = self_->getNbRigidActors();
return returnValue;
}

char const* PxPruningStructure_getConcreteTypeName(physx_PxPruningStructure_Pod const* self__pod) {
physx::PxPruningStructure const* self_ = reinterpret_cast<physx::PxPruningStructure const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

physx_PxExtendedVec3_Pod PxExtendedVec3_new() {
physx::PxExtendedVec3 returnValue;
physx_PxExtendedVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxExtendedVec3_Pod PxExtendedVec3_new_1(double _x, double _y, double _z) {
physx::PxExtendedVec3 returnValue(_x, _y, _z);
physx_PxExtendedVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxExtendedVec3_isZero(physx_PxExtendedVec3_Pod const* self__pod) {
physx::PxExtendedVec3 const* self_ = reinterpret_cast<physx::PxExtendedVec3 const*>(self__pod);
bool returnValue = self_->isZero();
return returnValue;
}

double PxExtendedVec3_dot(physx_PxExtendedVec3_Pod const* self__pod, physx_PxVec3_Pod const* v_pod) {
physx::PxExtendedVec3 const* self_ = reinterpret_cast<physx::PxExtendedVec3 const*>(self__pod);
physx::PxVec3 const& v = reinterpret_cast<physx::PxVec3 const&>(*v_pod);
double returnValue = self_->dot(v);
return returnValue;
}

double PxExtendedVec3_distanceSquared(physx_PxExtendedVec3_Pod const* self__pod, physx_PxExtendedVec3_Pod const* v_pod) {
physx::PxExtendedVec3 const* self_ = reinterpret_cast<physx::PxExtendedVec3 const*>(self__pod);
physx::PxExtendedVec3 const& v = reinterpret_cast<physx::PxExtendedVec3 const&>(*v_pod);
double returnValue = self_->distanceSquared(v);
return returnValue;
}

double PxExtendedVec3_magnitudeSquared(physx_PxExtendedVec3_Pod const* self__pod) {
physx::PxExtendedVec3 const* self_ = reinterpret_cast<physx::PxExtendedVec3 const*>(self__pod);
double returnValue = self_->magnitudeSquared();
return returnValue;
}

double PxExtendedVec3_magnitude(physx_PxExtendedVec3_Pod const* self__pod) {
physx::PxExtendedVec3 const* self_ = reinterpret_cast<physx::PxExtendedVec3 const*>(self__pod);
double returnValue = self_->magnitude();
return returnValue;
}

double PxExtendedVec3_normalize_mut(physx_PxExtendedVec3_Pod* self__pod) {
physx::PxExtendedVec3* self_ = reinterpret_cast<physx::PxExtendedVec3*>(self__pod);
double returnValue = self_->normalize();
return returnValue;
}

bool PxExtendedVec3_isFinite(physx_PxExtendedVec3_Pod const* self__pod) {
physx::PxExtendedVec3 const* self_ = reinterpret_cast<physx::PxExtendedVec3 const*>(self__pod);
bool returnValue = self_->isFinite();
return returnValue;
}

void PxExtendedVec3_maximum_mut(physx_PxExtendedVec3_Pod* self__pod, physx_PxExtendedVec3_Pod const* v_pod) {
physx::PxExtendedVec3* self_ = reinterpret_cast<physx::PxExtendedVec3*>(self__pod);
physx::PxExtendedVec3 const& v = reinterpret_cast<physx::PxExtendedVec3 const&>(*v_pod);
self_->maximum(v);
}

void PxExtendedVec3_minimum_mut(physx_PxExtendedVec3_Pod* self__pod, physx_PxExtendedVec3_Pod const* v_pod) {
physx::PxExtendedVec3* self_ = reinterpret_cast<physx::PxExtendedVec3*>(self__pod);
physx::PxExtendedVec3 const& v = reinterpret_cast<physx::PxExtendedVec3 const&>(*v_pod);
self_->minimum(v);
}

void PxExtendedVec3_set_mut(physx_PxExtendedVec3_Pod* self__pod, double x_, double y_, double z_) {
physx::PxExtendedVec3* self_ = reinterpret_cast<physx::PxExtendedVec3*>(self__pod);
self_->set(x_, y_, z_);
}

void PxExtendedVec3_setPlusInfinity_mut(physx_PxExtendedVec3_Pod* self__pod) {
physx::PxExtendedVec3* self_ = reinterpret_cast<physx::PxExtendedVec3*>(self__pod);
self_->setPlusInfinity();
}

void PxExtendedVec3_setMinusInfinity_mut(physx_PxExtendedVec3_Pod* self__pod) {
physx::PxExtendedVec3* self_ = reinterpret_cast<physx::PxExtendedVec3*>(self__pod);
self_->setMinusInfinity();
}

void PxExtendedVec3_cross_mut(physx_PxExtendedVec3_Pod* self__pod, physx_PxExtendedVec3_Pod const* left_pod, physx_PxVec3_Pod const* right_pod) {
physx::PxExtendedVec3* self_ = reinterpret_cast<physx::PxExtendedVec3*>(self__pod);
physx::PxExtendedVec3 const& left = reinterpret_cast<physx::PxExtendedVec3 const&>(*left_pod);
physx::PxVec3 const& right = reinterpret_cast<physx::PxVec3 const&>(*right_pod);
self_->cross(left, right);
}

void PxExtendedVec3_cross_mut_1(physx_PxExtendedVec3_Pod* self__pod, physx_PxExtendedVec3_Pod const* left_pod, physx_PxExtendedVec3_Pod const* right_pod) {
physx::PxExtendedVec3* self_ = reinterpret_cast<physx::PxExtendedVec3*>(self__pod);
physx::PxExtendedVec3 const& left = reinterpret_cast<physx::PxExtendedVec3 const&>(*left_pod);
physx::PxExtendedVec3 const& right = reinterpret_cast<physx::PxExtendedVec3 const&>(*right_pod);
self_->cross(left, right);
}

physx_PxExtendedVec3_Pod PxExtendedVec3_cross(physx_PxExtendedVec3_Pod const* self__pod, physx_PxExtendedVec3_Pod const* v_pod) {
physx::PxExtendedVec3 const* self_ = reinterpret_cast<physx::PxExtendedVec3 const*>(self__pod);
physx::PxExtendedVec3 const& v = reinterpret_cast<physx::PxExtendedVec3 const&>(*v_pod);
physx::PxExtendedVec3 returnValue = self_->cross(v);
physx_PxExtendedVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxExtendedVec3_cross_mut_2(physx_PxExtendedVec3_Pod* self__pod, physx_PxVec3_Pod const* left_pod, physx_PxExtendedVec3_Pod const* right_pod) {
physx::PxExtendedVec3* self_ = reinterpret_cast<physx::PxExtendedVec3*>(self__pod);
physx::PxVec3 const& left = reinterpret_cast<physx::PxVec3 const&>(*left_pod);
physx::PxExtendedVec3 const& right = reinterpret_cast<physx::PxExtendedVec3 const&>(*right_pod);
self_->cross(left, right);
}

int PxObstacle_getType(physx_PxObstacle_Pod const* self__pod) {
physx::PxObstacle const* self_ = reinterpret_cast<physx::PxObstacle const*>(self__pod);
PxGeometryType::Enum returnValue = self_->getType();
int returnValue_pod = (int)returnValue;
return returnValue_pod;
}

physx_PxBoxObstacle_Pod PxBoxObstacle_new() {
physx::PxBoxObstacle returnValue;
physx_PxBoxObstacle_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxCapsuleObstacle_Pod PxCapsuleObstacle_new() {
physx::PxCapsuleObstacle returnValue;
physx_PxCapsuleObstacle_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxObstacleContext_release_mut(physx_PxObstacleContext_Pod* self__pod) {
physx::PxObstacleContext* self_ = reinterpret_cast<physx::PxObstacleContext*>(self__pod);
self_->release();
}

physx_PxControllerManager_Pod* PxObstacleContext_getControllerManager(physx_PxObstacleContext_Pod const* self__pod) {
physx::PxObstacleContext const* self_ = reinterpret_cast<physx::PxObstacleContext const*>(self__pod);
physx::PxControllerManager& returnValue = self_->getControllerManager();
physx_PxControllerManager_Pod* returnValue_pod = reinterpret_cast<physx_PxControllerManager_Pod*>(&returnValue);
return returnValue_pod;
}

uint32_t PxObstacleContext_addObstacle_mut(physx_PxObstacleContext_Pod* self__pod, physx_PxObstacle_Pod const* obstacle_pod) {
physx::PxObstacleContext* self_ = reinterpret_cast<physx::PxObstacleContext*>(self__pod);
physx::PxObstacle const& obstacle = reinterpret_cast<physx::PxObstacle const&>(*obstacle_pod);
uint32_t returnValue = self_->addObstacle(obstacle);
return returnValue;
}

bool PxObstacleContext_removeObstacle_mut(physx_PxObstacleContext_Pod* self__pod, uint32_t handle) {
physx::PxObstacleContext* self_ = reinterpret_cast<physx::PxObstacleContext*>(self__pod);
bool returnValue = self_->removeObstacle(handle);
return returnValue;
}

bool PxObstacleContext_updateObstacle_mut(physx_PxObstacleContext_Pod* self__pod, uint32_t handle, physx_PxObstacle_Pod const* obstacle_pod) {
physx::PxObstacleContext* self_ = reinterpret_cast<physx::PxObstacleContext*>(self__pod);
physx::PxObstacle const& obstacle = reinterpret_cast<physx::PxObstacle const&>(*obstacle_pod);
bool returnValue = self_->updateObstacle(handle, obstacle);
return returnValue;
}

uint32_t PxObstacleContext_getNbObstacles(physx_PxObstacleContext_Pod const* self__pod) {
physx::PxObstacleContext const* self_ = reinterpret_cast<physx::PxObstacleContext const*>(self__pod);
uint32_t returnValue = self_->getNbObstacles();
return returnValue;
}

physx_PxObstacle_Pod const* PxObstacleContext_getObstacle(physx_PxObstacleContext_Pod const* self__pod, uint32_t i) {
physx::PxObstacleContext const* self_ = reinterpret_cast<physx::PxObstacleContext const*>(self__pod);
physx::PxObstacle const* returnValue = self_->getObstacle(i);
physx_PxObstacle_Pod const* returnValue_pod = reinterpret_cast<physx_PxObstacle_Pod const*>(returnValue);
return returnValue_pod;
}

physx_PxObstacle_Pod const* PxObstacleContext_getObstacleByHandle(physx_PxObstacleContext_Pod const* self__pod, uint32_t handle) {
physx::PxObstacleContext const* self_ = reinterpret_cast<physx::PxObstacleContext const*>(self__pod);
physx::PxObstacle const* returnValue = self_->getObstacleByHandle(handle);
physx_PxObstacle_Pod const* returnValue_pod = reinterpret_cast<physx_PxObstacle_Pod const*>(returnValue);
return returnValue_pod;
}

void PxUserControllerHitReport_onShapeHit_mut(physx_PxUserControllerHitReport_Pod* self__pod, physx_PxControllerShapeHit_Pod const* hit_pod) {
physx::PxUserControllerHitReport* self_ = reinterpret_cast<physx::PxUserControllerHitReport*>(self__pod);
physx::PxControllerShapeHit const& hit = reinterpret_cast<physx::PxControllerShapeHit const&>(*hit_pod);
self_->onShapeHit(hit);
}

void PxUserControllerHitReport_onControllerHit_mut(physx_PxUserControllerHitReport_Pod* self__pod, physx_PxControllersHit_Pod const* hit_pod) {
physx::PxUserControllerHitReport* self_ = reinterpret_cast<physx::PxUserControllerHitReport*>(self__pod);
physx::PxControllersHit const& hit = reinterpret_cast<physx::PxControllersHit const&>(*hit_pod);
self_->onControllerHit(hit);
}

void PxUserControllerHitReport_onObstacleHit_mut(physx_PxUserControllerHitReport_Pod* self__pod, physx_PxControllerObstacleHit_Pod const* hit_pod) {
physx::PxUserControllerHitReport* self_ = reinterpret_cast<physx::PxUserControllerHitReport*>(self__pod);
physx::PxControllerObstacleHit const& hit = reinterpret_cast<physx::PxControllerObstacleHit const&>(*hit_pod);
self_->onObstacleHit(hit);
}

void PxControllerFilterCallback_delete(physx_PxControllerFilterCallback_Pod* self__pod) {
physx::PxControllerFilterCallback* self_ = reinterpret_cast<physx::PxControllerFilterCallback*>(self__pod);
delete self_;
}

bool PxControllerFilterCallback_filter_mut(physx_PxControllerFilterCallback_Pod* self__pod, physx_PxController_Pod const* a_pod, physx_PxController_Pod const* b_pod) {
physx::PxControllerFilterCallback* self_ = reinterpret_cast<physx::PxControllerFilterCallback*>(self__pod);
physx::PxController const& a = reinterpret_cast<physx::PxController const&>(*a_pod);
physx::PxController const& b = reinterpret_cast<physx::PxController const&>(*b_pod);
bool returnValue = self_->filter(a, b);
return returnValue;
}

physx_PxControllerFilters_Pod PxControllerFilters_new(physx_PxFilterData_Pod const* filterData_pod, physx_PxQueryFilterCallback_Pod* cb_pod, physx_PxControllerFilterCallback_Pod* cctFilterCb_pod) {
physx::PxFilterData const* filterData = reinterpret_cast<physx::PxFilterData const*>(filterData_pod);
physx::PxQueryFilterCallback* cb = reinterpret_cast<physx::PxQueryFilterCallback*>(cb_pod);
physx::PxControllerFilterCallback* cctFilterCb = reinterpret_cast<physx::PxControllerFilterCallback*>(cctFilterCb_pod);
physx::PxControllerFilters returnValue(filterData, cb, cctFilterCb);
physx_PxControllerFilters_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxControllerDesc_isValid(physx_PxControllerDesc_Pod const* self__pod) {
physx::PxControllerDesc const* self_ = reinterpret_cast<physx::PxControllerDesc const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

unsigned int PxControllerDesc_getType(physx_PxControllerDesc_Pod const* self__pod) {
physx::PxControllerDesc const* self_ = reinterpret_cast<physx::PxControllerDesc const*>(self__pod);
PxControllerShapeType::Enum returnValue = self_->getType();
unsigned int returnValue_pod = (unsigned int)returnValue;
return returnValue_pod;
}

bool PxControllerDesc_isValid_1(physx_PxControllerDesc_Pod const* self__pod) {
physx::PxControllerDesc const* self_ = reinterpret_cast<physx::PxControllerDesc const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

unsigned int PxController_getType(physx_PxController_Pod const* self__pod) {
physx::PxController const* self_ = reinterpret_cast<physx::PxController const*>(self__pod);
PxControllerShapeType::Enum returnValue = self_->getType();
unsigned int returnValue_pod = (unsigned int)returnValue;
return returnValue_pod;
}

void PxController_release_mut(physx_PxController_Pod* self__pod) {
physx::PxController* self_ = reinterpret_cast<physx::PxController*>(self__pod);
self_->release();
}

physx_PxControllerCollisionFlags_Pod PxController_move_mut(physx_PxController_Pod* self__pod, physx_PxVec3_Pod const* disp_pod, float minDist, float elapsedTime, physx_PxControllerFilters_Pod const* filters_pod, physx_PxObstacleContext_Pod const* obstacles_pod) {
physx::PxController* self_ = reinterpret_cast<physx::PxController*>(self__pod);
physx::PxVec3 const& disp = reinterpret_cast<physx::PxVec3 const&>(*disp_pod);
physx::PxControllerFilters const& filters = reinterpret_cast<physx::PxControllerFilters const&>(*filters_pod);
physx::PxObstacleContext const* obstacles = reinterpret_cast<physx::PxObstacleContext const*>(obstacles_pod);
physx::PxControllerCollisionFlags returnValue = self_->move(disp, minDist, elapsedTime, filters, obstacles);
physx_PxControllerCollisionFlags_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxController_setPosition_mut(physx_PxController_Pod* self__pod, physx_PxExtendedVec3_Pod const* position_pod) {
physx::PxController* self_ = reinterpret_cast<physx::PxController*>(self__pod);
physx::PxExtendedVec3 const& position = reinterpret_cast<physx::PxExtendedVec3 const&>(*position_pod);
bool returnValue = self_->setPosition(position);
return returnValue;
}

physx_PxExtendedVec3_Pod const* PxController_getPosition(physx_PxController_Pod const* self__pod) {
physx::PxController const* self_ = reinterpret_cast<physx::PxController const*>(self__pod);
physx::PxExtendedVec3 const& returnValue = self_->getPosition();
physx_PxExtendedVec3_Pod const* returnValue_pod = reinterpret_cast<physx_PxExtendedVec3_Pod const*>(&returnValue);
return returnValue_pod;
}

bool PxController_setFootPosition_mut(physx_PxController_Pod* self__pod, physx_PxExtendedVec3_Pod const* position_pod) {
physx::PxController* self_ = reinterpret_cast<physx::PxController*>(self__pod);
physx::PxExtendedVec3 const& position = reinterpret_cast<physx::PxExtendedVec3 const&>(*position_pod);
bool returnValue = self_->setFootPosition(position);
return returnValue;
}

physx_PxExtendedVec3_Pod PxController_getFootPosition(physx_PxController_Pod const* self__pod) {
physx::PxController const* self_ = reinterpret_cast<physx::PxController const*>(self__pod);
physx::PxExtendedVec3 returnValue = self_->getFootPosition();
physx_PxExtendedVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxRigidDynamic_Pod* PxController_getActor(physx_PxController_Pod const* self__pod) {
physx::PxController const* self_ = reinterpret_cast<physx::PxController const*>(self__pod);
physx::PxRigidDynamic* returnValue = self_->getActor();
physx_PxRigidDynamic_Pod* returnValue_pod = reinterpret_cast<physx_PxRigidDynamic_Pod*>(returnValue);
return returnValue_pod;
}

void PxController_setStepOffset_mut(physx_PxController_Pod* self__pod, float offset) {
physx::PxController* self_ = reinterpret_cast<physx::PxController*>(self__pod);
self_->setStepOffset(offset);
}

float PxController_getStepOffset(physx_PxController_Pod const* self__pod) {
physx::PxController const* self_ = reinterpret_cast<physx::PxController const*>(self__pod);
float returnValue = self_->getStepOffset();
return returnValue;
}

void PxController_setNonWalkableMode_mut(physx_PxController_Pod* self__pod, unsigned int flag_pod) {
physx::PxController* self_ = reinterpret_cast<physx::PxController*>(self__pod);
PxControllerNonWalkableMode::Enum flag = (PxControllerNonWalkableMode::Enum)flag_pod;
self_->setNonWalkableMode(flag);
}

unsigned int PxController_getNonWalkableMode(physx_PxController_Pod const* self__pod) {
physx::PxController const* self_ = reinterpret_cast<physx::PxController const*>(self__pod);
PxControllerNonWalkableMode::Enum returnValue = self_->getNonWalkableMode();
unsigned int returnValue_pod = (unsigned int)returnValue;
return returnValue_pod;
}

float PxController_getContactOffset(physx_PxController_Pod const* self__pod) {
physx::PxController const* self_ = reinterpret_cast<physx::PxController const*>(self__pod);
float returnValue = self_->getContactOffset();
return returnValue;
}

void PxController_setContactOffset_mut(physx_PxController_Pod* self__pod, float offset) {
physx::PxController* self_ = reinterpret_cast<physx::PxController*>(self__pod);
self_->setContactOffset(offset);
}

physx_PxVec3_Pod PxController_getUpDirection(physx_PxController_Pod const* self__pod) {
physx::PxController const* self_ = reinterpret_cast<physx::PxController const*>(self__pod);
physx::PxVec3 returnValue = self_->getUpDirection();
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxController_setUpDirection_mut(physx_PxController_Pod* self__pod, physx_PxVec3_Pod const* up_pod) {
physx::PxController* self_ = reinterpret_cast<physx::PxController*>(self__pod);
physx::PxVec3 const& up = reinterpret_cast<physx::PxVec3 const&>(*up_pod);
self_->setUpDirection(up);
}

float PxController_getSlopeLimit(physx_PxController_Pod const* self__pod) {
physx::PxController const* self_ = reinterpret_cast<physx::PxController const*>(self__pod);
float returnValue = self_->getSlopeLimit();
return returnValue;
}

void PxController_setSlopeLimit_mut(physx_PxController_Pod* self__pod, float slopeLimit) {
physx::PxController* self_ = reinterpret_cast<physx::PxController*>(self__pod);
self_->setSlopeLimit(slopeLimit);
}

void PxController_invalidateCache_mut(physx_PxController_Pod* self__pod) {
physx::PxController* self_ = reinterpret_cast<physx::PxController*>(self__pod);
self_->invalidateCache();
}

physx_PxScene_Pod* PxController_getScene_mut(physx_PxController_Pod* self__pod) {
physx::PxController* self_ = reinterpret_cast<physx::PxController*>(self__pod);
physx::PxScene* returnValue = self_->getScene();
physx_PxScene_Pod* returnValue_pod = reinterpret_cast<physx_PxScene_Pod*>(returnValue);
return returnValue_pod;
}

void* PxController_getUserData(physx_PxController_Pod const* self__pod) {
physx::PxController const* self_ = reinterpret_cast<physx::PxController const*>(self__pod);
void* returnValue = self_->getUserData();
return returnValue;
}

void PxController_setUserData_mut(physx_PxController_Pod* self__pod, void* userData) {
physx::PxController* self_ = reinterpret_cast<physx::PxController*>(self__pod);
self_->setUserData(userData);
}

void PxController_getState(physx_PxController_Pod const* self__pod, physx_PxControllerState_Pod* state_pod) {
physx::PxController const* self_ = reinterpret_cast<physx::PxController const*>(self__pod);
physx::PxControllerState& state = reinterpret_cast<physx::PxControllerState&>(*state_pod);
self_->getState(state);
}

void PxController_getStats(physx_PxController_Pod const* self__pod, physx_PxControllerStats_Pod* stats_pod) {
physx::PxController const* self_ = reinterpret_cast<physx::PxController const*>(self__pod);
physx::PxControllerStats& stats = reinterpret_cast<physx::PxControllerStats&>(*stats_pod);
self_->getStats(stats);
}

void PxController_resize_mut(physx_PxController_Pod* self__pod, float height) {
physx::PxController* self_ = reinterpret_cast<physx::PxController*>(self__pod);
self_->resize(height);
}

physx_PxBoxControllerDesc_Pod* PxBoxControllerDesc_new_alloc() {
auto returnValue = new physx::PxBoxControllerDesc();
physx_PxBoxControllerDesc_Pod* returnValue_pod = reinterpret_cast<physx_PxBoxControllerDesc_Pod*>(returnValue);
return returnValue_pod;
}

void PxBoxControllerDesc_delete(physx_PxBoxControllerDesc_Pod* self__pod) {
physx::PxBoxControllerDesc* self_ = reinterpret_cast<physx::PxBoxControllerDesc*>(self__pod);
delete self_;
}

void PxBoxControllerDesc_setToDefault_mut(physx_PxBoxControllerDesc_Pod* self__pod) {
physx::PxBoxControllerDesc* self_ = reinterpret_cast<physx::PxBoxControllerDesc*>(self__pod);
self_->setToDefault();
}

bool PxBoxControllerDesc_isValid(physx_PxBoxControllerDesc_Pod const* self__pod) {
physx::PxBoxControllerDesc const* self_ = reinterpret_cast<physx::PxBoxControllerDesc const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

physx_PxBoxControllerDesc_Pod* PxBoxControllerDesc_new_alloc_1() {
auto returnValue = new physx::PxBoxControllerDesc();
physx_PxBoxControllerDesc_Pod* returnValue_pod = reinterpret_cast<physx_PxBoxControllerDesc_Pod*>(returnValue);
return returnValue_pod;
}

void PxBoxControllerDesc_setToDefault_mut_1(physx_PxBoxControllerDesc_Pod* self__pod) {
physx::PxBoxControllerDesc* self_ = reinterpret_cast<physx::PxBoxControllerDesc*>(self__pod);
self_->setToDefault();
}

bool PxBoxControllerDesc_isValid_1(physx_PxBoxControllerDesc_Pod const* self__pod) {
physx::PxBoxControllerDesc const* self_ = reinterpret_cast<physx::PxBoxControllerDesc const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

float PxBoxController_getHalfHeight(physx_PxBoxController_Pod const* self__pod) {
physx::PxBoxController const* self_ = reinterpret_cast<physx::PxBoxController const*>(self__pod);
float returnValue = self_->getHalfHeight();
return returnValue;
}

float PxBoxController_getHalfSideExtent(physx_PxBoxController_Pod const* self__pod) {
physx::PxBoxController const* self_ = reinterpret_cast<physx::PxBoxController const*>(self__pod);
float returnValue = self_->getHalfSideExtent();
return returnValue;
}

float PxBoxController_getHalfForwardExtent(physx_PxBoxController_Pod const* self__pod) {
physx::PxBoxController const* self_ = reinterpret_cast<physx::PxBoxController const*>(self__pod);
float returnValue = self_->getHalfForwardExtent();
return returnValue;
}

bool PxBoxController_setHalfHeight_mut(physx_PxBoxController_Pod* self__pod, float halfHeight) {
physx::PxBoxController* self_ = reinterpret_cast<physx::PxBoxController*>(self__pod);
bool returnValue = self_->setHalfHeight(halfHeight);
return returnValue;
}

bool PxBoxController_setHalfSideExtent_mut(physx_PxBoxController_Pod* self__pod, float halfSideExtent) {
physx::PxBoxController* self_ = reinterpret_cast<physx::PxBoxController*>(self__pod);
bool returnValue = self_->setHalfSideExtent(halfSideExtent);
return returnValue;
}

bool PxBoxController_setHalfForwardExtent_mut(physx_PxBoxController_Pod* self__pod, float halfForwardExtent) {
physx::PxBoxController* self_ = reinterpret_cast<physx::PxBoxController*>(self__pod);
bool returnValue = self_->setHalfForwardExtent(halfForwardExtent);
return returnValue;
}

physx_PxCapsuleControllerDesc_Pod* PxCapsuleControllerDesc_new_alloc() {
auto returnValue = new physx::PxCapsuleControllerDesc();
physx_PxCapsuleControllerDesc_Pod* returnValue_pod = reinterpret_cast<physx_PxCapsuleControllerDesc_Pod*>(returnValue);
return returnValue_pod;
}

void PxCapsuleControllerDesc_delete(physx_PxCapsuleControllerDesc_Pod* self__pod) {
physx::PxCapsuleControllerDesc* self_ = reinterpret_cast<physx::PxCapsuleControllerDesc*>(self__pod);
delete self_;
}

void PxCapsuleControllerDesc_setToDefault_mut(physx_PxCapsuleControllerDesc_Pod* self__pod) {
physx::PxCapsuleControllerDesc* self_ = reinterpret_cast<physx::PxCapsuleControllerDesc*>(self__pod);
self_->setToDefault();
}

bool PxCapsuleControllerDesc_isValid(physx_PxCapsuleControllerDesc_Pod const* self__pod) {
physx::PxCapsuleControllerDesc const* self_ = reinterpret_cast<physx::PxCapsuleControllerDesc const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

physx_PxCapsuleControllerDesc_Pod* PxCapsuleControllerDesc_new_alloc_1() {
auto returnValue = new physx::PxCapsuleControllerDesc();
physx_PxCapsuleControllerDesc_Pod* returnValue_pod = reinterpret_cast<physx_PxCapsuleControllerDesc_Pod*>(returnValue);
return returnValue_pod;
}

void PxCapsuleControllerDesc_setToDefault_mut_1(physx_PxCapsuleControllerDesc_Pod* self__pod) {
physx::PxCapsuleControllerDesc* self_ = reinterpret_cast<physx::PxCapsuleControllerDesc*>(self__pod);
self_->setToDefault();
}

bool PxCapsuleControllerDesc_isValid_1(physx_PxCapsuleControllerDesc_Pod const* self__pod) {
physx::PxCapsuleControllerDesc const* self_ = reinterpret_cast<physx::PxCapsuleControllerDesc const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

float PxCapsuleController_getRadius(physx_PxCapsuleController_Pod const* self__pod) {
physx::PxCapsuleController const* self_ = reinterpret_cast<physx::PxCapsuleController const*>(self__pod);
float returnValue = self_->getRadius();
return returnValue;
}

bool PxCapsuleController_setRadius_mut(physx_PxCapsuleController_Pod* self__pod, float radius) {
physx::PxCapsuleController* self_ = reinterpret_cast<physx::PxCapsuleController*>(self__pod);
bool returnValue = self_->setRadius(radius);
return returnValue;
}

float PxCapsuleController_getHeight(physx_PxCapsuleController_Pod const* self__pod) {
physx::PxCapsuleController const* self_ = reinterpret_cast<physx::PxCapsuleController const*>(self__pod);
float returnValue = self_->getHeight();
return returnValue;
}

bool PxCapsuleController_setHeight_mut(physx_PxCapsuleController_Pod* self__pod, float height) {
physx::PxCapsuleController* self_ = reinterpret_cast<physx::PxCapsuleController*>(self__pod);
bool returnValue = self_->setHeight(height);
return returnValue;
}

unsigned int PxCapsuleController_getClimbingMode(physx_PxCapsuleController_Pod const* self__pod) {
physx::PxCapsuleController const* self_ = reinterpret_cast<physx::PxCapsuleController const*>(self__pod);
PxCapsuleClimbingMode::Enum returnValue = self_->getClimbingMode();
unsigned int returnValue_pod = (unsigned int)returnValue;
return returnValue_pod;
}

bool PxCapsuleController_setClimbingMode_mut(physx_PxCapsuleController_Pod* self__pod, unsigned int mode_pod) {
physx::PxCapsuleController* self_ = reinterpret_cast<physx::PxCapsuleController*>(self__pod);
PxCapsuleClimbingMode::Enum mode = (PxCapsuleClimbingMode::Enum)mode_pod;
bool returnValue = self_->setClimbingMode(mode);
return returnValue;
}

physx_PxControllerBehaviorFlags_Pod PxControllerBehaviorCallback_getBehaviorFlags_mut(physx_PxControllerBehaviorCallback_Pod* self__pod, physx_PxShape_Pod const* shape_pod, physx_PxActor_Pod const* actor_pod) {
physx::PxControllerBehaviorCallback* self_ = reinterpret_cast<physx::PxControllerBehaviorCallback*>(self__pod);
physx::PxShape const& shape = reinterpret_cast<physx::PxShape const&>(*shape_pod);
physx::PxActor const& actor = reinterpret_cast<physx::PxActor const&>(*actor_pod);
physx::PxControllerBehaviorFlags returnValue = self_->getBehaviorFlags(shape, actor);
physx_PxControllerBehaviorFlags_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxControllerBehaviorFlags_Pod PxControllerBehaviorCallback_getBehaviorFlags_mut_1(physx_PxControllerBehaviorCallback_Pod* self__pod, physx_PxController_Pod const* controller_pod) {
physx::PxControllerBehaviorCallback* self_ = reinterpret_cast<physx::PxControllerBehaviorCallback*>(self__pod);
physx::PxController const& controller = reinterpret_cast<physx::PxController const&>(*controller_pod);
physx::PxControllerBehaviorFlags returnValue = self_->getBehaviorFlags(controller);
physx_PxControllerBehaviorFlags_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxControllerBehaviorFlags_Pod PxControllerBehaviorCallback_getBehaviorFlags_mut_2(physx_PxControllerBehaviorCallback_Pod* self__pod, physx_PxObstacle_Pod const* obstacle_pod) {
physx::PxControllerBehaviorCallback* self_ = reinterpret_cast<physx::PxControllerBehaviorCallback*>(self__pod);
physx::PxObstacle const& obstacle = reinterpret_cast<physx::PxObstacle const&>(*obstacle_pod);
physx::PxControllerBehaviorFlags returnValue = self_->getBehaviorFlags(obstacle);
physx_PxControllerBehaviorFlags_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxControllerManager_release_mut(physx_PxControllerManager_Pod* self__pod) {
physx::PxControllerManager* self_ = reinterpret_cast<physx::PxControllerManager*>(self__pod);
self_->release();
}

physx_PxScene_Pod* PxControllerManager_getScene(physx_PxControllerManager_Pod const* self__pod) {
physx::PxControllerManager const* self_ = reinterpret_cast<physx::PxControllerManager const*>(self__pod);
physx::PxScene& returnValue = self_->getScene();
physx_PxScene_Pod* returnValue_pod = reinterpret_cast<physx_PxScene_Pod*>(&returnValue);
return returnValue_pod;
}

uint32_t PxControllerManager_getNbControllers(physx_PxControllerManager_Pod const* self__pod) {
physx::PxControllerManager const* self_ = reinterpret_cast<physx::PxControllerManager const*>(self__pod);
uint32_t returnValue = self_->getNbControllers();
return returnValue;
}

physx_PxController_Pod* PxControllerManager_getController_mut(physx_PxControllerManager_Pod* self__pod, uint32_t index) {
physx::PxControllerManager* self_ = reinterpret_cast<physx::PxControllerManager*>(self__pod);
physx::PxController* returnValue = self_->getController(index);
physx_PxController_Pod* returnValue_pod = reinterpret_cast<physx_PxController_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxController_Pod* PxControllerManager_createController_mut(physx_PxControllerManager_Pod* self__pod, physx_PxControllerDesc_Pod const* desc_pod) {
physx::PxControllerManager* self_ = reinterpret_cast<physx::PxControllerManager*>(self__pod);
physx::PxControllerDesc const& desc = reinterpret_cast<physx::PxControllerDesc const&>(*desc_pod);
physx::PxController* returnValue = self_->createController(desc);
physx_PxController_Pod* returnValue_pod = reinterpret_cast<physx_PxController_Pod*>(returnValue);
return returnValue_pod;
}

void PxControllerManager_purgeControllers_mut(physx_PxControllerManager_Pod* self__pod) {
physx::PxControllerManager* self_ = reinterpret_cast<physx::PxControllerManager*>(self__pod);
self_->purgeControllers();
}

physx_PxRenderBuffer_Pod* PxControllerManager_getRenderBuffer_mut(physx_PxControllerManager_Pod* self__pod) {
physx::PxControllerManager* self_ = reinterpret_cast<physx::PxControllerManager*>(self__pod);
physx::PxRenderBuffer& returnValue = self_->getRenderBuffer();
physx_PxRenderBuffer_Pod* returnValue_pod = reinterpret_cast<physx_PxRenderBuffer_Pod*>(&returnValue);
return returnValue_pod;
}

void PxControllerManager_setDebugRenderingFlags_mut(physx_PxControllerManager_Pod* self__pod, physx_PxControllerDebugRenderFlags_Pod flags_pod) {
physx::PxControllerManager* self_ = reinterpret_cast<physx::PxControllerManager*>(self__pod);
physx::PxControllerDebugRenderFlags flags;
memcpy(&flags, &flags_pod, sizeof(flags));
self_->setDebugRenderingFlags(flags);
}

uint32_t PxControllerManager_getNbObstacleContexts(physx_PxControllerManager_Pod const* self__pod) {
physx::PxControllerManager const* self_ = reinterpret_cast<physx::PxControllerManager const*>(self__pod);
uint32_t returnValue = self_->getNbObstacleContexts();
return returnValue;
}

physx_PxObstacleContext_Pod* PxControllerManager_getObstacleContext_mut(physx_PxControllerManager_Pod* self__pod, uint32_t index) {
physx::PxControllerManager* self_ = reinterpret_cast<physx::PxControllerManager*>(self__pod);
physx::PxObstacleContext* returnValue = self_->getObstacleContext(index);
physx_PxObstacleContext_Pod* returnValue_pod = reinterpret_cast<physx_PxObstacleContext_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxObstacleContext_Pod* PxControllerManager_createObstacleContext_mut(physx_PxControllerManager_Pod* self__pod) {
physx::PxControllerManager* self_ = reinterpret_cast<physx::PxControllerManager*>(self__pod);
physx::PxObstacleContext* returnValue = self_->createObstacleContext();
physx_PxObstacleContext_Pod* returnValue_pod = reinterpret_cast<physx_PxObstacleContext_Pod*>(returnValue);
return returnValue_pod;
}

void PxControllerManager_computeInteractions_mut(physx_PxControllerManager_Pod* self__pod, float elapsedTime, physx_PxControllerFilterCallback_Pod* cctFilterCb_pod) {
physx::PxControllerManager* self_ = reinterpret_cast<physx::PxControllerManager*>(self__pod);
physx::PxControllerFilterCallback* cctFilterCb = reinterpret_cast<physx::PxControllerFilterCallback*>(cctFilterCb_pod);
self_->computeInteractions(elapsedTime, cctFilterCb);
}

void PxControllerManager_setTessellation_mut(physx_PxControllerManager_Pod* self__pod, bool flag, float maxEdgeLength) {
physx::PxControllerManager* self_ = reinterpret_cast<physx::PxControllerManager*>(self__pod);
self_->setTessellation(flag, maxEdgeLength);
}

void PxControllerManager_setOverlapRecoveryModule_mut(physx_PxControllerManager_Pod* self__pod, bool flag) {
physx::PxControllerManager* self_ = reinterpret_cast<physx::PxControllerManager*>(self__pod);
self_->setOverlapRecoveryModule(flag);
}

void PxControllerManager_setPreciseSweeps_mut(physx_PxControllerManager_Pod* self__pod, bool flag) {
physx::PxControllerManager* self_ = reinterpret_cast<physx::PxControllerManager*>(self__pod);
self_->setPreciseSweeps(flag);
}

void PxControllerManager_setPreventVerticalSlidingAgainstCeiling_mut(physx_PxControllerManager_Pod* self__pod, bool flag) {
physx::PxControllerManager* self_ = reinterpret_cast<physx::PxControllerManager*>(self__pod);
self_->setPreventVerticalSlidingAgainstCeiling(flag);
}

void PxControllerManager_shiftOrigin_mut(physx_PxControllerManager_Pod* self__pod, physx_PxVec3_Pod const* shift_pod) {
physx::PxControllerManager* self_ = reinterpret_cast<physx::PxControllerManager*>(self__pod);
physx::PxVec3 const& shift = reinterpret_cast<physx::PxVec3 const&>(*shift_pod);
self_->shiftOrigin(shift);
}

physx_PxControllerManager_Pod* phys_PxCreateControllerManager(physx_PxScene_Pod* scene_pod, bool lockingEnabled) {
physx::PxScene& scene = reinterpret_cast<physx::PxScene&>(*scene_pod);
physx::PxControllerManager* returnValue = PxCreateControllerManager(scene, lockingEnabled);
physx_PxControllerManager_Pod* returnValue_pod = reinterpret_cast<physx_PxControllerManager_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxConvexMeshDesc_Pod PxConvexMeshDesc_new() {
physx::PxConvexMeshDesc returnValue;
physx_PxConvexMeshDesc_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxConvexMeshDesc_setToDefault_mut(physx_PxConvexMeshDesc_Pod* self__pod) {
physx::PxConvexMeshDesc* self_ = reinterpret_cast<physx::PxConvexMeshDesc*>(self__pod);
self_->setToDefault();
}

bool PxConvexMeshDesc_isValid(physx_PxConvexMeshDesc_Pod const* self__pod) {
physx::PxConvexMeshDesc const* self_ = reinterpret_cast<physx::PxConvexMeshDesc const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

physx_PxConvexMeshDesc_Pod PxConvexMeshDesc_new_1() {
physx::PxConvexMeshDesc returnValue;
physx_PxConvexMeshDesc_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxConvexMeshDesc_setToDefault_mut_1(physx_PxConvexMeshDesc_Pod* self__pod) {
physx::PxConvexMeshDesc* self_ = reinterpret_cast<physx::PxConvexMeshDesc*>(self__pod);
self_->setToDefault();
}

bool PxConvexMeshDesc_isValid_1(physx_PxConvexMeshDesc_Pod const* self__pod) {
physx::PxConvexMeshDesc const* self_ = reinterpret_cast<physx::PxConvexMeshDesc const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

physx_PxTriangleMeshDesc_Pod PxTriangleMeshDesc_new() {
physx::PxTriangleMeshDesc returnValue;
physx_PxTriangleMeshDesc_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxTriangleMeshDesc_setToDefault_mut(physx_PxTriangleMeshDesc_Pod* self__pod) {
physx::PxTriangleMeshDesc* self_ = reinterpret_cast<physx::PxTriangleMeshDesc*>(self__pod);
self_->setToDefault();
}

bool PxTriangleMeshDesc_isValid(physx_PxTriangleMeshDesc_Pod const* self__pod) {
physx::PxTriangleMeshDesc const* self_ = reinterpret_cast<physx::PxTriangleMeshDesc const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

physx_PxTriangleMeshDesc_Pod PxTriangleMeshDesc_new_1() {
physx::PxTriangleMeshDesc returnValue;
physx_PxTriangleMeshDesc_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxTriangleMeshDesc_setToDefault_mut_1(physx_PxTriangleMeshDesc_Pod* self__pod) {
physx::PxTriangleMeshDesc* self_ = reinterpret_cast<physx::PxTriangleMeshDesc*>(self__pod);
self_->setToDefault();
}

bool PxTriangleMeshDesc_isValid_1(physx_PxTriangleMeshDesc_Pod const* self__pod) {
physx::PxTriangleMeshDesc const* self_ = reinterpret_cast<physx::PxTriangleMeshDesc const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

void PxBVH33MidphaseDesc_setToDefault_mut(physx_PxBVH33MidphaseDesc_Pod* self__pod) {
physx::PxBVH33MidphaseDesc* self_ = reinterpret_cast<physx::PxBVH33MidphaseDesc*>(self__pod);
self_->setToDefault();
}

bool PxBVH33MidphaseDesc_isValid(physx_PxBVH33MidphaseDesc_Pod const* self__pod) {
physx::PxBVH33MidphaseDesc const* self_ = reinterpret_cast<physx::PxBVH33MidphaseDesc const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

void PxBVH34MidphaseDesc_setToDefault_mut(physx_PxBVH34MidphaseDesc_Pod* self__pod) {
physx::PxBVH34MidphaseDesc* self_ = reinterpret_cast<physx::PxBVH34MidphaseDesc*>(self__pod);
self_->setToDefault();
}

bool PxBVH34MidphaseDesc_isValid(physx_PxBVH34MidphaseDesc_Pod const* self__pod) {
physx::PxBVH34MidphaseDesc const* self_ = reinterpret_cast<physx::PxBVH34MidphaseDesc const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

physx_PxMidphaseDesc_Pod PxMidphaseDesc_new() {
physx::PxMidphaseDesc returnValue;
physx_PxMidphaseDesc_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

unsigned int PxMidphaseDesc_getType(physx_PxMidphaseDesc_Pod const* self__pod) {
physx::PxMidphaseDesc const* self_ = reinterpret_cast<physx::PxMidphaseDesc const*>(self__pod);
PxMeshMidPhase::Enum returnValue = self_->getType();
unsigned int returnValue_pod = (unsigned int)returnValue;
return returnValue_pod;
}

void PxMidphaseDesc_setToDefault_mut(physx_PxMidphaseDesc_Pod* self__pod, unsigned int type_pod) {
physx::PxMidphaseDesc* self_ = reinterpret_cast<physx::PxMidphaseDesc*>(self__pod);
PxMeshMidPhase::Enum type = (PxMeshMidPhase::Enum)type_pod;
self_->setToDefault(type);
}

bool PxMidphaseDesc_isValid(physx_PxMidphaseDesc_Pod const* self__pod) {
physx::PxMidphaseDesc const* self_ = reinterpret_cast<physx::PxMidphaseDesc const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

physx_PxBVHStructureDesc_Pod PxBVHStructureDesc_new() {
physx::PxBVHStructureDesc returnValue;
physx_PxBVHStructureDesc_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxBVHStructureDesc_setToDefault_mut(physx_PxBVHStructureDesc_Pod* self__pod) {
physx::PxBVHStructureDesc* self_ = reinterpret_cast<physx::PxBVHStructureDesc*>(self__pod);
self_->setToDefault();
}

bool PxBVHStructureDesc_isValid(physx_PxBVHStructureDesc_Pod const* self__pod) {
physx::PxBVHStructureDesc const* self_ = reinterpret_cast<physx::PxBVHStructureDesc const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

physx_PxBVHStructureDesc_Pod PxBVHStructureDesc_new_1() {
physx::PxBVHStructureDesc returnValue;
physx_PxBVHStructureDesc_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxBVHStructureDesc_setToDefault_mut_1(physx_PxBVHStructureDesc_Pod* self__pod) {
physx::PxBVHStructureDesc* self_ = reinterpret_cast<physx::PxBVHStructureDesc*>(self__pod);
self_->setToDefault();
}

bool PxBVHStructureDesc_isValid_1(physx_PxBVHStructureDesc_Pod const* self__pod) {
physx::PxBVHStructureDesc const* self_ = reinterpret_cast<physx::PxBVHStructureDesc const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

physx_PxCookingParams_Pod PxCookingParams_new(physx_PxTolerancesScale_Pod const* sc_pod) {
physx::PxTolerancesScale const& sc = reinterpret_cast<physx::PxTolerancesScale const&>(*sc_pod);
physx::PxCookingParams returnValue(sc);
physx_PxCookingParams_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxCooking_release_mut(physx_PxCooking_Pod* self__pod) {
physx::PxCooking* self_ = reinterpret_cast<physx::PxCooking*>(self__pod);
self_->release();
}

void PxCooking_setParams_mut(physx_PxCooking_Pod* self__pod, physx_PxCookingParams_Pod const* params_pod) {
physx::PxCooking* self_ = reinterpret_cast<physx::PxCooking*>(self__pod);
physx::PxCookingParams const& params = reinterpret_cast<physx::PxCookingParams const&>(*params_pod);
self_->setParams(params);
}

physx_PxCookingParams_Pod const* PxCooking_getParams(physx_PxCooking_Pod const* self__pod) {
physx::PxCooking const* self_ = reinterpret_cast<physx::PxCooking const*>(self__pod);
physx::PxCookingParams const& returnValue = self_->getParams();
physx_PxCookingParams_Pod const* returnValue_pod = reinterpret_cast<physx_PxCookingParams_Pod const*>(&returnValue);
return returnValue_pod;
}

bool PxCooking_platformMismatch(physx_PxCooking_Pod const* self__pod) {
physx::PxCooking const* self_ = reinterpret_cast<physx::PxCooking const*>(self__pod);
bool returnValue = self_->platformMismatch();
return returnValue;
}

bool PxCooking_cookTriangleMesh(physx_PxCooking_Pod const* self__pod, physx_PxTriangleMeshDesc_Pod const* desc_pod, physx_PxOutputStream_Pod* stream_pod, unsigned int* condition_pod) {
physx::PxCooking const* self_ = reinterpret_cast<physx::PxCooking const*>(self__pod);
physx::PxTriangleMeshDesc const& desc = reinterpret_cast<physx::PxTriangleMeshDesc const&>(*desc_pod);
physx::PxOutputStream& stream = reinterpret_cast<physx::PxOutputStream&>(*stream_pod);
PxTriangleMeshCookingResult::Enum* condition = reinterpret_cast<PxTriangleMeshCookingResult::Enum*>(condition_pod);
bool returnValue = self_->cookTriangleMesh(desc, stream, condition);
return returnValue;
}

physx_PxTriangleMesh_Pod* PxCooking_createTriangleMesh(physx_PxCooking_Pod const* self__pod, physx_PxTriangleMeshDesc_Pod const* desc_pod, physx_PxPhysicsInsertionCallback_Pod* insertionCallback_pod, unsigned int* condition_pod) {
physx::PxCooking const* self_ = reinterpret_cast<physx::PxCooking const*>(self__pod);
physx::PxTriangleMeshDesc const& desc = reinterpret_cast<physx::PxTriangleMeshDesc const&>(*desc_pod);
physx::PxPhysicsInsertionCallback& insertionCallback = reinterpret_cast<physx::PxPhysicsInsertionCallback&>(*insertionCallback_pod);
PxTriangleMeshCookingResult::Enum* condition = reinterpret_cast<PxTriangleMeshCookingResult::Enum*>(condition_pod);
physx::PxTriangleMesh* returnValue = self_->createTriangleMesh(desc, insertionCallback, condition);
physx_PxTriangleMesh_Pod* returnValue_pod = reinterpret_cast<physx_PxTriangleMesh_Pod*>(returnValue);
return returnValue_pod;
}

bool PxCooking_validateTriangleMesh(physx_PxCooking_Pod const* self__pod, physx_PxTriangleMeshDesc_Pod const* desc_pod) {
physx::PxCooking const* self_ = reinterpret_cast<physx::PxCooking const*>(self__pod);
physx::PxTriangleMeshDesc const& desc = reinterpret_cast<physx::PxTriangleMeshDesc const&>(*desc_pod);
bool returnValue = self_->validateTriangleMesh(desc);
return returnValue;
}

bool PxCooking_cookConvexMesh(physx_PxCooking_Pod const* self__pod, physx_PxConvexMeshDesc_Pod const* desc_pod, physx_PxOutputStream_Pod* stream_pod, unsigned int* condition_pod) {
physx::PxCooking const* self_ = reinterpret_cast<physx::PxCooking const*>(self__pod);
physx::PxConvexMeshDesc const& desc = reinterpret_cast<physx::PxConvexMeshDesc const&>(*desc_pod);
physx::PxOutputStream& stream = reinterpret_cast<physx::PxOutputStream&>(*stream_pod);
PxConvexMeshCookingResult::Enum* condition = reinterpret_cast<PxConvexMeshCookingResult::Enum*>(condition_pod);
bool returnValue = self_->cookConvexMesh(desc, stream, condition);
return returnValue;
}

physx_PxConvexMesh_Pod* PxCooking_createConvexMesh(physx_PxCooking_Pod const* self__pod, physx_PxConvexMeshDesc_Pod const* desc_pod, physx_PxPhysicsInsertionCallback_Pod* insertionCallback_pod, unsigned int* condition_pod) {
physx::PxCooking const* self_ = reinterpret_cast<physx::PxCooking const*>(self__pod);
physx::PxConvexMeshDesc const& desc = reinterpret_cast<physx::PxConvexMeshDesc const&>(*desc_pod);
physx::PxPhysicsInsertionCallback& insertionCallback = reinterpret_cast<physx::PxPhysicsInsertionCallback&>(*insertionCallback_pod);
PxConvexMeshCookingResult::Enum* condition = reinterpret_cast<PxConvexMeshCookingResult::Enum*>(condition_pod);
physx::PxConvexMesh* returnValue = self_->createConvexMesh(desc, insertionCallback, condition);
physx_PxConvexMesh_Pod* returnValue_pod = reinterpret_cast<physx_PxConvexMesh_Pod*>(returnValue);
return returnValue_pod;
}

bool PxCooking_validateConvexMesh(physx_PxCooking_Pod const* self__pod, physx_PxConvexMeshDesc_Pod const* desc_pod) {
physx::PxCooking const* self_ = reinterpret_cast<physx::PxCooking const*>(self__pod);
physx::PxConvexMeshDesc const& desc = reinterpret_cast<physx::PxConvexMeshDesc const&>(*desc_pod);
bool returnValue = self_->validateConvexMesh(desc);
return returnValue;
}

bool PxCooking_computeHullPolygons(physx_PxCooking_Pod const* self__pod, physx_PxSimpleTriangleMesh_Pod const* mesh_pod, physx_PxAllocatorCallback_Pod* inCallback_pod, uint32_t* nbVerts_pod, physx_PxVec3_Pod** vertices_pod, uint32_t* nbIndices_pod, uint32_t** indices_pod, uint32_t* nbPolygons_pod, physx_PxHullPolygon_Pod** hullPolygons_pod) {
physx::PxCooking const* self_ = reinterpret_cast<physx::PxCooking const*>(self__pod);
physx::PxSimpleTriangleMesh const& mesh = reinterpret_cast<physx::PxSimpleTriangleMesh const&>(*mesh_pod);
physx::PxAllocatorCallback& inCallback = reinterpret_cast<physx::PxAllocatorCallback&>(*inCallback_pod);
uint32_t& nbVerts = *nbVerts_pod;
physx::PxVec3*& vertices = reinterpret_cast<physx::PxVec3*&>(*vertices_pod);
uint32_t& nbIndices = *nbIndices_pod;
uint32_t*& indices = *indices_pod;
uint32_t& nbPolygons = *nbPolygons_pod;
physx::PxHullPolygon*& hullPolygons = reinterpret_cast<physx::PxHullPolygon*&>(*hullPolygons_pod);
bool returnValue = self_->computeHullPolygons(mesh, inCallback, nbVerts, vertices, nbIndices, indices, nbPolygons, hullPolygons);
return returnValue;
}

bool PxCooking_cookHeightField(physx_PxCooking_Pod const* self__pod, physx_PxHeightFieldDesc_Pod const* desc_pod, physx_PxOutputStream_Pod* stream_pod) {
physx::PxCooking const* self_ = reinterpret_cast<physx::PxCooking const*>(self__pod);
physx::PxHeightFieldDesc const& desc = reinterpret_cast<physx::PxHeightFieldDesc const&>(*desc_pod);
physx::PxOutputStream& stream = reinterpret_cast<physx::PxOutputStream&>(*stream_pod);
bool returnValue = self_->cookHeightField(desc, stream);
return returnValue;
}

physx_PxHeightField_Pod* PxCooking_createHeightField(physx_PxCooking_Pod const* self__pod, physx_PxHeightFieldDesc_Pod const* desc_pod, physx_PxPhysicsInsertionCallback_Pod* insertionCallback_pod) {
physx::PxCooking const* self_ = reinterpret_cast<physx::PxCooking const*>(self__pod);
physx::PxHeightFieldDesc const& desc = reinterpret_cast<physx::PxHeightFieldDesc const&>(*desc_pod);
physx::PxPhysicsInsertionCallback& insertionCallback = reinterpret_cast<physx::PxPhysicsInsertionCallback&>(*insertionCallback_pod);
physx::PxHeightField* returnValue = self_->createHeightField(desc, insertionCallback);
physx_PxHeightField_Pod* returnValue_pod = reinterpret_cast<physx_PxHeightField_Pod*>(returnValue);
return returnValue_pod;
}

bool PxCooking_cookBVHStructure(physx_PxCooking_Pod const* self__pod, physx_PxBVHStructureDesc_Pod const* desc_pod, physx_PxOutputStream_Pod* stream_pod) {
physx::PxCooking const* self_ = reinterpret_cast<physx::PxCooking const*>(self__pod);
physx::PxBVHStructureDesc const& desc = reinterpret_cast<physx::PxBVHStructureDesc const&>(*desc_pod);
physx::PxOutputStream& stream = reinterpret_cast<physx::PxOutputStream&>(*stream_pod);
bool returnValue = self_->cookBVHStructure(desc, stream);
return returnValue;
}

physx_PxBVHStructure_Pod* PxCooking_createBVHStructure(physx_PxCooking_Pod const* self__pod, physx_PxBVHStructureDesc_Pod const* desc_pod, physx_PxPhysicsInsertionCallback_Pod* insertionCallback_pod) {
physx::PxCooking const* self_ = reinterpret_cast<physx::PxCooking const*>(self__pod);
physx::PxBVHStructureDesc const& desc = reinterpret_cast<physx::PxBVHStructureDesc const&>(*desc_pod);
physx::PxPhysicsInsertionCallback& insertionCallback = reinterpret_cast<physx::PxPhysicsInsertionCallback&>(*insertionCallback_pod);
physx::PxBVHStructure* returnValue = self_->createBVHStructure(desc, insertionCallback);
physx_PxBVHStructure_Pod* returnValue_pod = reinterpret_cast<physx_PxBVHStructure_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxCooking_Pod* phys_PxCreateCooking(uint32_t version, physx_PxFoundation_Pod* foundation_pod, physx_PxCookingParams_Pod const* params_pod) {
physx::PxFoundation& foundation = reinterpret_cast<physx::PxFoundation&>(*foundation_pod);
physx::PxCookingParams const& params = reinterpret_cast<physx::PxCookingParams const&>(*params_pod);
physx::PxCooking* returnValue = PxCreateCooking(version, foundation, params);
physx_PxCooking_Pod* returnValue_pod = reinterpret_cast<physx_PxCooking_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxDefaultMemoryOutputStream_Pod* PxDefaultMemoryOutputStream_new_alloc(physx_PxAllocatorCallback_Pod* allocator_pod) {
physx::PxAllocatorCallback& allocator = reinterpret_cast<physx::PxAllocatorCallback&>(*allocator_pod);
auto returnValue = new physx::PxDefaultMemoryOutputStream(allocator);
physx_PxDefaultMemoryOutputStream_Pod* returnValue_pod = reinterpret_cast<physx_PxDefaultMemoryOutputStream_Pod*>(returnValue);
return returnValue_pod;
}

void PxDefaultMemoryOutputStream_delete(physx_PxDefaultMemoryOutputStream_Pod* self__pod) {
physx::PxDefaultMemoryOutputStream* self_ = reinterpret_cast<physx::PxDefaultMemoryOutputStream*>(self__pod);
delete self_;
}

uint32_t PxDefaultMemoryOutputStream_write_mut(physx_PxDefaultMemoryOutputStream_Pod* self__pod, void const* src, uint32_t count) {
physx::PxDefaultMemoryOutputStream* self_ = reinterpret_cast<physx::PxDefaultMemoryOutputStream*>(self__pod);
uint32_t returnValue = self_->write(src, count);
return returnValue;
}

uint32_t PxDefaultMemoryOutputStream_getSize(physx_PxDefaultMemoryOutputStream_Pod const* self__pod) {
physx::PxDefaultMemoryOutputStream const* self_ = reinterpret_cast<physx::PxDefaultMemoryOutputStream const*>(self__pod);
uint32_t returnValue = self_->getSize();
return returnValue;
}

unsigned char* PxDefaultMemoryOutputStream_getData(physx_PxDefaultMemoryOutputStream_Pod const* self__pod) {
physx::PxDefaultMemoryOutputStream const* self_ = reinterpret_cast<physx::PxDefaultMemoryOutputStream const*>(self__pod);
unsigned char* returnValue = self_->getData();
return returnValue;
}

physx_PxDefaultMemoryInputData_Pod* PxDefaultMemoryInputData_new_alloc(unsigned char* data, uint32_t length) {
auto returnValue = new physx::PxDefaultMemoryInputData(data, length);
physx_PxDefaultMemoryInputData_Pod* returnValue_pod = reinterpret_cast<physx_PxDefaultMemoryInputData_Pod*>(returnValue);
return returnValue_pod;
}

uint32_t PxDefaultMemoryInputData_read_mut(physx_PxDefaultMemoryInputData_Pod* self__pod, void* dest, uint32_t count) {
physx::PxDefaultMemoryInputData* self_ = reinterpret_cast<physx::PxDefaultMemoryInputData*>(self__pod);
uint32_t returnValue = self_->read(dest, count);
return returnValue;
}

uint32_t PxDefaultMemoryInputData_getLength(physx_PxDefaultMemoryInputData_Pod const* self__pod) {
physx::PxDefaultMemoryInputData const* self_ = reinterpret_cast<physx::PxDefaultMemoryInputData const*>(self__pod);
uint32_t returnValue = self_->getLength();
return returnValue;
}

void PxDefaultMemoryInputData_seek_mut(physx_PxDefaultMemoryInputData_Pod* self__pod, uint32_t pos) {
physx::PxDefaultMemoryInputData* self_ = reinterpret_cast<physx::PxDefaultMemoryInputData*>(self__pod);
self_->seek(pos);
}

uint32_t PxDefaultMemoryInputData_tell(physx_PxDefaultMemoryInputData_Pod const* self__pod) {
physx::PxDefaultMemoryInputData const* self_ = reinterpret_cast<physx::PxDefaultMemoryInputData const*>(self__pod);
uint32_t returnValue = self_->tell();
return returnValue;
}

void PxDefaultMemoryInputData_delete(physx_PxDefaultMemoryInputData_Pod* self__pod) {
physx::PxDefaultMemoryInputData* self_ = reinterpret_cast<physx::PxDefaultMemoryInputData*>(self__pod);
delete self_;
}

physx_PxDefaultFileOutputStream_Pod* PxDefaultFileOutputStream_new_alloc(char const* name) {
auto returnValue = new physx::PxDefaultFileOutputStream(name);
physx_PxDefaultFileOutputStream_Pod* returnValue_pod = reinterpret_cast<physx_PxDefaultFileOutputStream_Pod*>(returnValue);
return returnValue_pod;
}

void PxDefaultFileOutputStream_delete(physx_PxDefaultFileOutputStream_Pod* self__pod) {
physx::PxDefaultFileOutputStream* self_ = reinterpret_cast<physx::PxDefaultFileOutputStream*>(self__pod);
delete self_;
}

uint32_t PxDefaultFileOutputStream_write_mut(physx_PxDefaultFileOutputStream_Pod* self__pod, void const* src, uint32_t count) {
physx::PxDefaultFileOutputStream* self_ = reinterpret_cast<physx::PxDefaultFileOutputStream*>(self__pod);
uint32_t returnValue = self_->write(src, count);
return returnValue;
}

bool PxDefaultFileOutputStream_isValid_mut(physx_PxDefaultFileOutputStream_Pod* self__pod) {
physx::PxDefaultFileOutputStream* self_ = reinterpret_cast<physx::PxDefaultFileOutputStream*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

physx_PxDefaultFileInputData_Pod* PxDefaultFileInputData_new_alloc(char const* name) {
auto returnValue = new physx::PxDefaultFileInputData(name);
physx_PxDefaultFileInputData_Pod* returnValue_pod = reinterpret_cast<physx_PxDefaultFileInputData_Pod*>(returnValue);
return returnValue_pod;
}

void PxDefaultFileInputData_delete(physx_PxDefaultFileInputData_Pod* self__pod) {
physx::PxDefaultFileInputData* self_ = reinterpret_cast<physx::PxDefaultFileInputData*>(self__pod);
delete self_;
}

uint32_t PxDefaultFileInputData_read_mut(physx_PxDefaultFileInputData_Pod* self__pod, void* dest, uint32_t count) {
physx::PxDefaultFileInputData* self_ = reinterpret_cast<physx::PxDefaultFileInputData*>(self__pod);
uint32_t returnValue = self_->read(dest, count);
return returnValue;
}

void PxDefaultFileInputData_seek_mut(physx_PxDefaultFileInputData_Pod* self__pod, uint32_t pos) {
physx::PxDefaultFileInputData* self_ = reinterpret_cast<physx::PxDefaultFileInputData*>(self__pod);
self_->seek(pos);
}

uint32_t PxDefaultFileInputData_tell(physx_PxDefaultFileInputData_Pod const* self__pod) {
physx::PxDefaultFileInputData const* self_ = reinterpret_cast<physx::PxDefaultFileInputData const*>(self__pod);
uint32_t returnValue = self_->tell();
return returnValue;
}

uint32_t PxDefaultFileInputData_getLength(physx_PxDefaultFileInputData_Pod const* self__pod) {
physx::PxDefaultFileInputData const* self_ = reinterpret_cast<physx::PxDefaultFileInputData const*>(self__pod);
uint32_t returnValue = self_->getLength();
return returnValue;
}

bool PxDefaultFileInputData_isValid(physx_PxDefaultFileInputData_Pod const* self__pod) {
physx::PxDefaultFileInputData const* self_ = reinterpret_cast<physx::PxDefaultFileInputData const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

void PxJoint_setActors_mut(physx_PxJoint_Pod* self__pod, physx_PxRigidActor_Pod* actor0_pod, physx_PxRigidActor_Pod* actor1_pod) {
physx::PxJoint* self_ = reinterpret_cast<physx::PxJoint*>(self__pod);
physx::PxRigidActor* actor0 = reinterpret_cast<physx::PxRigidActor*>(actor0_pod);
physx::PxRigidActor* actor1 = reinterpret_cast<physx::PxRigidActor*>(actor1_pod);
self_->setActors(actor0, actor1);
}

void PxJoint_getActors(physx_PxJoint_Pod const* self__pod, physx_PxRigidActor_Pod** actor0_pod, physx_PxRigidActor_Pod** actor1_pod) {
physx::PxJoint const* self_ = reinterpret_cast<physx::PxJoint const*>(self__pod);
physx::PxRigidActor*& actor0 = reinterpret_cast<physx::PxRigidActor*&>(*actor0_pod);
physx::PxRigidActor*& actor1 = reinterpret_cast<physx::PxRigidActor*&>(*actor1_pod);
self_->getActors(actor0, actor1);
}

void PxJoint_setLocalPose_mut(physx_PxJoint_Pod* self__pod, unsigned int actor_pod, physx_PxTransform_Pod const* localPose_pod) {
physx::PxJoint* self_ = reinterpret_cast<physx::PxJoint*>(self__pod);
PxJointActorIndex::Enum actor = (PxJointActorIndex::Enum)actor_pod;
physx::PxTransform const& localPose = reinterpret_cast<physx::PxTransform const&>(*localPose_pod);
self_->setLocalPose(actor, localPose);
}

physx_PxTransform_Pod PxJoint_getLocalPose(physx_PxJoint_Pod const* self__pod, unsigned int actor_pod) {
physx::PxJoint const* self_ = reinterpret_cast<physx::PxJoint const*>(self__pod);
PxJointActorIndex::Enum actor = (PxJointActorIndex::Enum)actor_pod;
physx::PxTransform returnValue = self_->getLocalPose(actor);
physx_PxTransform_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxTransform_Pod PxJoint_getRelativeTransform(physx_PxJoint_Pod const* self__pod) {
physx::PxJoint const* self_ = reinterpret_cast<physx::PxJoint const*>(self__pod);
physx::PxTransform returnValue = self_->getRelativeTransform();
physx_PxTransform_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxJoint_getRelativeLinearVelocity(physx_PxJoint_Pod const* self__pod) {
physx::PxJoint const* self_ = reinterpret_cast<physx::PxJoint const*>(self__pod);
physx::PxVec3 returnValue = self_->getRelativeLinearVelocity();
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxJoint_getRelativeAngularVelocity(physx_PxJoint_Pod const* self__pod) {
physx::PxJoint const* self_ = reinterpret_cast<physx::PxJoint const*>(self__pod);
physx::PxVec3 returnValue = self_->getRelativeAngularVelocity();
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxJoint_setBreakForce_mut(physx_PxJoint_Pod* self__pod, float force, float torque) {
physx::PxJoint* self_ = reinterpret_cast<physx::PxJoint*>(self__pod);
self_->setBreakForce(force, torque);
}

void PxJoint_getBreakForce(physx_PxJoint_Pod const* self__pod, float* force_pod, float* torque_pod) {
physx::PxJoint const* self_ = reinterpret_cast<physx::PxJoint const*>(self__pod);
float& force = *force_pod;
float& torque = *torque_pod;
self_->getBreakForce(force, torque);
}

void PxJoint_setConstraintFlags_mut(physx_PxJoint_Pod* self__pod, physx_PxConstraintFlags_Pod flags_pod) {
physx::PxJoint* self_ = reinterpret_cast<physx::PxJoint*>(self__pod);
physx::PxConstraintFlags flags;
memcpy(&flags, &flags_pod, sizeof(flags));
self_->setConstraintFlags(flags);
}

void PxJoint_setConstraintFlag_mut(physx_PxJoint_Pod* self__pod, unsigned int flag_pod, bool value) {
physx::PxJoint* self_ = reinterpret_cast<physx::PxJoint*>(self__pod);
PxConstraintFlag::Enum flag = (PxConstraintFlag::Enum)flag_pod;
self_->setConstraintFlag(flag, value);
}

physx_PxConstraintFlags_Pod PxJoint_getConstraintFlags(physx_PxJoint_Pod const* self__pod) {
physx::PxJoint const* self_ = reinterpret_cast<physx::PxJoint const*>(self__pod);
physx::PxConstraintFlags returnValue = self_->getConstraintFlags();
physx_PxConstraintFlags_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxJoint_setInvMassScale0_mut(physx_PxJoint_Pod* self__pod, float invMassScale) {
physx::PxJoint* self_ = reinterpret_cast<physx::PxJoint*>(self__pod);
self_->setInvMassScale0(invMassScale);
}

float PxJoint_getInvMassScale0(physx_PxJoint_Pod const* self__pod) {
physx::PxJoint const* self_ = reinterpret_cast<physx::PxJoint const*>(self__pod);
float returnValue = self_->getInvMassScale0();
return returnValue;
}

void PxJoint_setInvInertiaScale0_mut(physx_PxJoint_Pod* self__pod, float invInertiaScale) {
physx::PxJoint* self_ = reinterpret_cast<physx::PxJoint*>(self__pod);
self_->setInvInertiaScale0(invInertiaScale);
}

float PxJoint_getInvInertiaScale0(physx_PxJoint_Pod const* self__pod) {
physx::PxJoint const* self_ = reinterpret_cast<physx::PxJoint const*>(self__pod);
float returnValue = self_->getInvInertiaScale0();
return returnValue;
}

void PxJoint_setInvMassScale1_mut(physx_PxJoint_Pod* self__pod, float invMassScale) {
physx::PxJoint* self_ = reinterpret_cast<physx::PxJoint*>(self__pod);
self_->setInvMassScale1(invMassScale);
}

float PxJoint_getInvMassScale1(physx_PxJoint_Pod const* self__pod) {
physx::PxJoint const* self_ = reinterpret_cast<physx::PxJoint const*>(self__pod);
float returnValue = self_->getInvMassScale1();
return returnValue;
}

void PxJoint_setInvInertiaScale1_mut(physx_PxJoint_Pod* self__pod, float invInertiaScale) {
physx::PxJoint* self_ = reinterpret_cast<physx::PxJoint*>(self__pod);
self_->setInvInertiaScale1(invInertiaScale);
}

float PxJoint_getInvInertiaScale1(physx_PxJoint_Pod const* self__pod) {
physx::PxJoint const* self_ = reinterpret_cast<physx::PxJoint const*>(self__pod);
float returnValue = self_->getInvInertiaScale1();
return returnValue;
}

physx_PxConstraint_Pod* PxJoint_getConstraint(physx_PxJoint_Pod const* self__pod) {
physx::PxJoint const* self_ = reinterpret_cast<physx::PxJoint const*>(self__pod);
physx::PxConstraint* returnValue = self_->getConstraint();
physx_PxConstraint_Pod* returnValue_pod = reinterpret_cast<physx_PxConstraint_Pod*>(returnValue);
return returnValue_pod;
}

void PxJoint_setName_mut(physx_PxJoint_Pod* self__pod, char const* name) {
physx::PxJoint* self_ = reinterpret_cast<physx::PxJoint*>(self__pod);
self_->setName(name);
}

char const* PxJoint_getName(physx_PxJoint_Pod const* self__pod) {
physx::PxJoint const* self_ = reinterpret_cast<physx::PxJoint const*>(self__pod);
char const* returnValue = self_->getName();
return returnValue;
}

void PxJoint_release_mut(physx_PxJoint_Pod* self__pod) {
physx::PxJoint* self_ = reinterpret_cast<physx::PxJoint*>(self__pod);
self_->release();
}

physx_PxScene_Pod* PxJoint_getScene(physx_PxJoint_Pod const* self__pod) {
physx::PxJoint const* self_ = reinterpret_cast<physx::PxJoint const*>(self__pod);
physx::PxScene* returnValue = self_->getScene();
physx_PxScene_Pod* returnValue_pod = reinterpret_cast<physx_PxScene_Pod*>(returnValue);
return returnValue_pod;
}

void PxJoint_getBinaryMetaData_mut(physx_PxOutputStream_Pod* stream_pod) {
physx::PxOutputStream& stream = reinterpret_cast<physx::PxOutputStream&>(*stream_pod);
PxJoint::getBinaryMetaData(stream);
}

physx_PxSpring_Pod PxSpring_new(float stiffness_, float damping_) {
physx::PxSpring returnValue(stiffness_, damping_);
physx_PxSpring_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void phys_PxSetJointGlobalFrame(physx_PxJoint_Pod* joint_pod, physx_PxVec3_Pod const* wsAnchor_pod, physx_PxVec3_Pod const* wsAxis_pod) {
physx::PxJoint& joint = reinterpret_cast<physx::PxJoint&>(*joint_pod);
physx::PxVec3 const* wsAnchor = reinterpret_cast<physx::PxVec3 const*>(wsAnchor_pod);
physx::PxVec3 const* wsAxis = reinterpret_cast<physx::PxVec3 const*>(wsAxis_pod);
PxSetJointGlobalFrame(joint, wsAnchor, wsAxis);
}

physx_PxDistanceJoint_Pod* phys_PxDistanceJointCreate(physx_PxPhysics_Pod* physics_pod, physx_PxRigidActor_Pod* actor0_pod, physx_PxTransform_Pod const* localFrame0_pod, physx_PxRigidActor_Pod* actor1_pod, physx_PxTransform_Pod const* localFrame1_pod) {
physx::PxPhysics& physics = reinterpret_cast<physx::PxPhysics&>(*physics_pod);
physx::PxRigidActor* actor0 = reinterpret_cast<physx::PxRigidActor*>(actor0_pod);
physx::PxTransform const& localFrame0 = reinterpret_cast<physx::PxTransform const&>(*localFrame0_pod);
physx::PxRigidActor* actor1 = reinterpret_cast<physx::PxRigidActor*>(actor1_pod);
physx::PxTransform const& localFrame1 = reinterpret_cast<physx::PxTransform const&>(*localFrame1_pod);
physx::PxDistanceJoint* returnValue = PxDistanceJointCreate(physics, actor0, localFrame0, actor1, localFrame1);
physx_PxDistanceJoint_Pod* returnValue_pod = reinterpret_cast<physx_PxDistanceJoint_Pod*>(returnValue);
return returnValue_pod;
}

float PxDistanceJoint_getDistance(physx_PxDistanceJoint_Pod const* self__pod) {
physx::PxDistanceJoint const* self_ = reinterpret_cast<physx::PxDistanceJoint const*>(self__pod);
float returnValue = self_->getDistance();
return returnValue;
}

void PxDistanceJoint_setMinDistance_mut(physx_PxDistanceJoint_Pod* self__pod, float distance) {
physx::PxDistanceJoint* self_ = reinterpret_cast<physx::PxDistanceJoint*>(self__pod);
self_->setMinDistance(distance);
}

float PxDistanceJoint_getMinDistance(physx_PxDistanceJoint_Pod const* self__pod) {
physx::PxDistanceJoint const* self_ = reinterpret_cast<physx::PxDistanceJoint const*>(self__pod);
float returnValue = self_->getMinDistance();
return returnValue;
}

void PxDistanceJoint_setMaxDistance_mut(physx_PxDistanceJoint_Pod* self__pod, float distance) {
physx::PxDistanceJoint* self_ = reinterpret_cast<physx::PxDistanceJoint*>(self__pod);
self_->setMaxDistance(distance);
}

float PxDistanceJoint_getMaxDistance(physx_PxDistanceJoint_Pod const* self__pod) {
physx::PxDistanceJoint const* self_ = reinterpret_cast<physx::PxDistanceJoint const*>(self__pod);
float returnValue = self_->getMaxDistance();
return returnValue;
}

void PxDistanceJoint_setTolerance_mut(physx_PxDistanceJoint_Pod* self__pod, float tolerance) {
physx::PxDistanceJoint* self_ = reinterpret_cast<physx::PxDistanceJoint*>(self__pod);
self_->setTolerance(tolerance);
}

float PxDistanceJoint_getTolerance(physx_PxDistanceJoint_Pod const* self__pod) {
physx::PxDistanceJoint const* self_ = reinterpret_cast<physx::PxDistanceJoint const*>(self__pod);
float returnValue = self_->getTolerance();
return returnValue;
}

void PxDistanceJoint_setStiffness_mut(physx_PxDistanceJoint_Pod* self__pod, float stiffness) {
physx::PxDistanceJoint* self_ = reinterpret_cast<physx::PxDistanceJoint*>(self__pod);
self_->setStiffness(stiffness);
}

float PxDistanceJoint_getStiffness(physx_PxDistanceJoint_Pod const* self__pod) {
physx::PxDistanceJoint const* self_ = reinterpret_cast<physx::PxDistanceJoint const*>(self__pod);
float returnValue = self_->getStiffness();
return returnValue;
}

void PxDistanceJoint_setDamping_mut(physx_PxDistanceJoint_Pod* self__pod, float damping) {
physx::PxDistanceJoint* self_ = reinterpret_cast<physx::PxDistanceJoint*>(self__pod);
self_->setDamping(damping);
}

float PxDistanceJoint_getDamping(physx_PxDistanceJoint_Pod const* self__pod) {
physx::PxDistanceJoint const* self_ = reinterpret_cast<physx::PxDistanceJoint const*>(self__pod);
float returnValue = self_->getDamping();
return returnValue;
}

void PxDistanceJoint_setDistanceJointFlags_mut(physx_PxDistanceJoint_Pod* self__pod, physx_PxDistanceJointFlags_Pod flags_pod) {
physx::PxDistanceJoint* self_ = reinterpret_cast<physx::PxDistanceJoint*>(self__pod);
physx::PxDistanceJointFlags flags;
memcpy(&flags, &flags_pod, sizeof(flags));
self_->setDistanceJointFlags(flags);
}

void PxDistanceJoint_setDistanceJointFlag_mut(physx_PxDistanceJoint_Pod* self__pod, unsigned int flag_pod, bool value) {
physx::PxDistanceJoint* self_ = reinterpret_cast<physx::PxDistanceJoint*>(self__pod);
PxDistanceJointFlag::Enum flag = (PxDistanceJointFlag::Enum)flag_pod;
self_->setDistanceJointFlag(flag, value);
}

physx_PxDistanceJointFlags_Pod PxDistanceJoint_getDistanceJointFlags(physx_PxDistanceJoint_Pod const* self__pod) {
physx::PxDistanceJoint const* self_ = reinterpret_cast<physx::PxDistanceJoint const*>(self__pod);
physx::PxDistanceJointFlags returnValue = self_->getDistanceJointFlags();
physx_PxDistanceJointFlags_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

char const* PxDistanceJoint_getConcreteTypeName(physx_PxDistanceJoint_Pod const* self__pod) {
physx::PxDistanceJoint const* self_ = reinterpret_cast<physx::PxDistanceJoint const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

void* PxDefaultAllocator_allocate_mut(physx_PxDefaultAllocator_Pod* self__pod, uint64_t size, char const* anonymous_arg1, char const* anonymous_arg2, int32_t anonymous_arg3) {
physx::PxDefaultAllocator* self_ = reinterpret_cast<physx::PxDefaultAllocator*>(self__pod);
void* returnValue = self_->allocate(size, anonymous_arg1, anonymous_arg2, anonymous_arg3);
return returnValue;
}

void PxDefaultAllocator_deallocate_mut(physx_PxDefaultAllocator_Pod* self__pod, void* ptr) {
physx::PxDefaultAllocator* self_ = reinterpret_cast<physx::PxDefaultAllocator*>(self__pod);
self_->deallocate(ptr);
}

void PxDefaultAllocator_delete(physx_PxDefaultAllocator_Pod* self__pod) {
physx::PxDefaultAllocator* self_ = reinterpret_cast<physx::PxDefaultAllocator*>(self__pod);
delete self_;
}

physx_PxContactJoint_Pod* phys_PxContactJointCreate(physx_PxPhysics_Pod* physics_pod, physx_PxRigidActor_Pod* actor0_pod, physx_PxTransform_Pod const* localFrame0_pod, physx_PxRigidActor_Pod* actor1_pod, physx_PxTransform_Pod const* localFrame1_pod) {
physx::PxPhysics& physics = reinterpret_cast<physx::PxPhysics&>(*physics_pod);
physx::PxRigidActor* actor0 = reinterpret_cast<physx::PxRigidActor*>(actor0_pod);
physx::PxTransform const& localFrame0 = reinterpret_cast<physx::PxTransform const&>(*localFrame0_pod);
physx::PxRigidActor* actor1 = reinterpret_cast<physx::PxRigidActor*>(actor1_pod);
physx::PxTransform const& localFrame1 = reinterpret_cast<physx::PxTransform const&>(*localFrame1_pod);
physx::PxContactJoint* returnValue = PxContactJointCreate(physics, actor0, localFrame0, actor1, localFrame1);
physx_PxContactJoint_Pod* returnValue_pod = reinterpret_cast<physx_PxContactJoint_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxJacobianRow_Pod PxJacobianRow_new() {
physx::PxJacobianRow returnValue;
physx_PxJacobianRow_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxJacobianRow_Pod PxJacobianRow_new_1(physx_PxVec3_Pod const* lin0_pod, physx_PxVec3_Pod const* lin1_pod, physx_PxVec3_Pod const* ang0_pod, physx_PxVec3_Pod const* ang1_pod) {
physx::PxVec3 const& lin0 = reinterpret_cast<physx::PxVec3 const&>(*lin0_pod);
physx::PxVec3 const& lin1 = reinterpret_cast<physx::PxVec3 const&>(*lin1_pod);
physx::PxVec3 const& ang0 = reinterpret_cast<physx::PxVec3 const&>(*ang0_pod);
physx::PxVec3 const& ang1 = reinterpret_cast<physx::PxVec3 const&>(*ang1_pod);
physx::PxJacobianRow returnValue(lin0, lin1, ang0, ang1);
physx_PxJacobianRow_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxContactJoint_setContact_mut(physx_PxContactJoint_Pod* self__pod, physx_PxVec3_Pod const* contact_pod) {
physx::PxContactJoint* self_ = reinterpret_cast<physx::PxContactJoint*>(self__pod);
physx::PxVec3 const& contact = reinterpret_cast<physx::PxVec3 const&>(*contact_pod);
self_->setContact(contact);
}

void PxContactJoint_setContactNormal_mut(physx_PxContactJoint_Pod* self__pod, physx_PxVec3_Pod const* contactNormal_pod) {
physx::PxContactJoint* self_ = reinterpret_cast<physx::PxContactJoint*>(self__pod);
physx::PxVec3 const& contactNormal = reinterpret_cast<physx::PxVec3 const&>(*contactNormal_pod);
self_->setContactNormal(contactNormal);
}

void PxContactJoint_setPenetration_mut(physx_PxContactJoint_Pod* self__pod, float penetration) {
physx::PxContactJoint* self_ = reinterpret_cast<physx::PxContactJoint*>(self__pod);
self_->setPenetration(penetration);
}

physx_PxVec3_Pod PxContactJoint_getContact(physx_PxContactJoint_Pod const* self__pod) {
physx::PxContactJoint const* self_ = reinterpret_cast<physx::PxContactJoint const*>(self__pod);
physx::PxVec3 returnValue = self_->getContact();
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxContactJoint_getContactNormal(physx_PxContactJoint_Pod const* self__pod) {
physx::PxContactJoint const* self_ = reinterpret_cast<physx::PxContactJoint const*>(self__pod);
physx::PxVec3 returnValue = self_->getContactNormal();
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

float PxContactJoint_getPenetration(physx_PxContactJoint_Pod const* self__pod) {
physx::PxContactJoint const* self_ = reinterpret_cast<physx::PxContactJoint const*>(self__pod);
float returnValue = self_->getPenetration();
return returnValue;
}

float PxContactJoint_getResititution(physx_PxContactJoint_Pod const* self__pod) {
physx::PxContactJoint const* self_ = reinterpret_cast<physx::PxContactJoint const*>(self__pod);
float returnValue = self_->getResititution();
return returnValue;
}

void PxContactJoint_setResititution_mut(physx_PxContactJoint_Pod* self__pod, float resititution) {
physx::PxContactJoint* self_ = reinterpret_cast<physx::PxContactJoint*>(self__pod);
self_->setResititution(resititution);
}

float PxContactJoint_getBounceThreshold(physx_PxContactJoint_Pod const* self__pod) {
physx::PxContactJoint const* self_ = reinterpret_cast<physx::PxContactJoint const*>(self__pod);
float returnValue = self_->getBounceThreshold();
return returnValue;
}

void PxContactJoint_setBounceThreshold_mut(physx_PxContactJoint_Pod* self__pod, float bounceThreshold) {
physx::PxContactJoint* self_ = reinterpret_cast<physx::PxContactJoint*>(self__pod);
self_->setBounceThreshold(bounceThreshold);
}

char const* PxContactJoint_getConcreteTypeName(physx_PxContactJoint_Pod const* self__pod) {
physx::PxContactJoint const* self_ = reinterpret_cast<physx::PxContactJoint const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

void PxContactJoint_computeJacobians(physx_PxContactJoint_Pod const* self__pod, physx_PxJacobianRow_Pod* jacobian_pod) {
physx::PxContactJoint const* self_ = reinterpret_cast<physx::PxContactJoint const*>(self__pod);
physx::PxJacobianRow* jacobian = reinterpret_cast<physx::PxJacobianRow*>(jacobian_pod);
self_->computeJacobians(jacobian);
}

uint32_t PxContactJoint_getNbJacobianRows(physx_PxContactJoint_Pod const* self__pod) {
physx::PxContactJoint const* self_ = reinterpret_cast<physx::PxContactJoint const*>(self__pod);
uint32_t returnValue = self_->getNbJacobianRows();
return returnValue;
}

physx_PxFixedJoint_Pod* phys_PxFixedJointCreate(physx_PxPhysics_Pod* physics_pod, physx_PxRigidActor_Pod* actor0_pod, physx_PxTransform_Pod const* localFrame0_pod, physx_PxRigidActor_Pod* actor1_pod, physx_PxTransform_Pod const* localFrame1_pod) {
physx::PxPhysics& physics = reinterpret_cast<physx::PxPhysics&>(*physics_pod);
physx::PxRigidActor* actor0 = reinterpret_cast<physx::PxRigidActor*>(actor0_pod);
physx::PxTransform const& localFrame0 = reinterpret_cast<physx::PxTransform const&>(*localFrame0_pod);
physx::PxRigidActor* actor1 = reinterpret_cast<physx::PxRigidActor*>(actor1_pod);
physx::PxTransform const& localFrame1 = reinterpret_cast<physx::PxTransform const&>(*localFrame1_pod);
physx::PxFixedJoint* returnValue = PxFixedJointCreate(physics, actor0, localFrame0, actor1, localFrame1);
physx_PxFixedJoint_Pod* returnValue_pod = reinterpret_cast<physx_PxFixedJoint_Pod*>(returnValue);
return returnValue_pod;
}

void PxFixedJoint_setProjectionLinearTolerance_mut(physx_PxFixedJoint_Pod* self__pod, float tolerance) {
physx::PxFixedJoint* self_ = reinterpret_cast<physx::PxFixedJoint*>(self__pod);
self_->setProjectionLinearTolerance(tolerance);
}

float PxFixedJoint_getProjectionLinearTolerance(physx_PxFixedJoint_Pod const* self__pod) {
physx::PxFixedJoint const* self_ = reinterpret_cast<physx::PxFixedJoint const*>(self__pod);
float returnValue = self_->getProjectionLinearTolerance();
return returnValue;
}

void PxFixedJoint_setProjectionAngularTolerance_mut(physx_PxFixedJoint_Pod* self__pod, float tolerance) {
physx::PxFixedJoint* self_ = reinterpret_cast<physx::PxFixedJoint*>(self__pod);
self_->setProjectionAngularTolerance(tolerance);
}

float PxFixedJoint_getProjectionAngularTolerance(physx_PxFixedJoint_Pod const* self__pod) {
physx::PxFixedJoint const* self_ = reinterpret_cast<physx::PxFixedJoint const*>(self__pod);
float returnValue = self_->getProjectionAngularTolerance();
return returnValue;
}

char const* PxFixedJoint_getConcreteTypeName(physx_PxFixedJoint_Pod const* self__pod) {
physx::PxFixedJoint const* self_ = reinterpret_cast<physx::PxFixedJoint const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

physx_PxJointLimitParameters_Pod* PxJointLimitParameters_new_alloc() {
auto returnValue = new physx::PxJointLimitParameters();
physx_PxJointLimitParameters_Pod* returnValue_pod = reinterpret_cast<physx_PxJointLimitParameters_Pod*>(returnValue);
return returnValue_pod;
}

bool PxJointLimitParameters_isValid(physx_PxJointLimitParameters_Pod const* self__pod) {
physx::PxJointLimitParameters const* self_ = reinterpret_cast<physx::PxJointLimitParameters const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

bool PxJointLimitParameters_isSoft(physx_PxJointLimitParameters_Pod const* self__pod) {
physx::PxJointLimitParameters const* self_ = reinterpret_cast<physx::PxJointLimitParameters const*>(self__pod);
bool returnValue = self_->isSoft();
return returnValue;
}

physx_PxJointLinearLimit_Pod PxJointLinearLimit_new(physx_PxTolerancesScale_Pod const* scale_pod, float extent, float contactDist) {
physx::PxTolerancesScale const& scale = reinterpret_cast<physx::PxTolerancesScale const&>(*scale_pod);
physx::PxJointLinearLimit returnValue(scale, extent, contactDist);
physx_PxJointLinearLimit_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxJointLinearLimit_Pod PxJointLinearLimit_new_1(float extent, physx_PxSpring_Pod const* spring_pod) {
physx::PxSpring const& spring = reinterpret_cast<physx::PxSpring const&>(*spring_pod);
physx::PxJointLinearLimit returnValue(extent, spring);
physx_PxJointLinearLimit_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxJointLinearLimit_isValid(physx_PxJointLinearLimit_Pod const* self__pod) {
physx::PxJointLinearLimit const* self_ = reinterpret_cast<physx::PxJointLinearLimit const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

void PxJointLinearLimit_delete(physx_PxJointLinearLimit_Pod* self__pod) {
physx::PxJointLinearLimit* self_ = reinterpret_cast<physx::PxJointLinearLimit*>(self__pod);
delete self_;
}

physx_PxJointLinearLimitPair_Pod PxJointLinearLimitPair_new(physx_PxTolerancesScale_Pod const* scale_pod, float lowerLimit, float upperLimit, float contactDist) {
physx::PxTolerancesScale const& scale = reinterpret_cast<physx::PxTolerancesScale const&>(*scale_pod);
physx::PxJointLinearLimitPair returnValue(scale, lowerLimit, upperLimit, contactDist);
physx_PxJointLinearLimitPair_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxJointLinearLimitPair_Pod PxJointLinearLimitPair_new_1(float lowerLimit, float upperLimit, physx_PxSpring_Pod const* spring_pod) {
physx::PxSpring const& spring = reinterpret_cast<physx::PxSpring const&>(*spring_pod);
physx::PxJointLinearLimitPair returnValue(lowerLimit, upperLimit, spring);
physx_PxJointLinearLimitPair_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxJointLinearLimitPair_isValid(physx_PxJointLinearLimitPair_Pod const* self__pod) {
physx::PxJointLinearLimitPair const* self_ = reinterpret_cast<physx::PxJointLinearLimitPair const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

void PxJointLinearLimitPair_delete(physx_PxJointLinearLimitPair_Pod* self__pod) {
physx::PxJointLinearLimitPair* self_ = reinterpret_cast<physx::PxJointLinearLimitPair*>(self__pod);
delete self_;
}

physx_PxJointAngularLimitPair_Pod PxJointAngularLimitPair_new(float lowerLimit, float upperLimit, float contactDist) {
physx::PxJointAngularLimitPair returnValue(lowerLimit, upperLimit, contactDist);
physx_PxJointAngularLimitPair_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxJointAngularLimitPair_Pod PxJointAngularLimitPair_new_1(float lowerLimit, float upperLimit, physx_PxSpring_Pod const* spring_pod) {
physx::PxSpring const& spring = reinterpret_cast<physx::PxSpring const&>(*spring_pod);
physx::PxJointAngularLimitPair returnValue(lowerLimit, upperLimit, spring);
physx_PxJointAngularLimitPair_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxJointAngularLimitPair_isValid(physx_PxJointAngularLimitPair_Pod const* self__pod) {
physx::PxJointAngularLimitPair const* self_ = reinterpret_cast<physx::PxJointAngularLimitPair const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

void PxJointAngularLimitPair_delete(physx_PxJointAngularLimitPair_Pod* self__pod) {
physx::PxJointAngularLimitPair* self_ = reinterpret_cast<physx::PxJointAngularLimitPair*>(self__pod);
delete self_;
}

physx_PxJointLimitCone_Pod PxJointLimitCone_new(float yLimitAngle, float zLimitAngle, float contactDist) {
physx::PxJointLimitCone returnValue(yLimitAngle, zLimitAngle, contactDist);
physx_PxJointLimitCone_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxJointLimitCone_Pod PxJointLimitCone_new_1(float yLimitAngle, float zLimitAngle, physx_PxSpring_Pod const* spring_pod) {
physx::PxSpring const& spring = reinterpret_cast<physx::PxSpring const&>(*spring_pod);
physx::PxJointLimitCone returnValue(yLimitAngle, zLimitAngle, spring);
physx_PxJointLimitCone_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxJointLimitCone_isValid(physx_PxJointLimitCone_Pod const* self__pod) {
physx::PxJointLimitCone const* self_ = reinterpret_cast<physx::PxJointLimitCone const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

void PxJointLimitCone_delete(physx_PxJointLimitCone_Pod* self__pod) {
physx::PxJointLimitCone* self_ = reinterpret_cast<physx::PxJointLimitCone*>(self__pod);
delete self_;
}

physx_PxJointLimitPyramid_Pod PxJointLimitPyramid_new(float yLimitAngleMin, float yLimitAngleMax, float zLimitAngleMin, float zLimitAngleMax, float contactDist) {
physx::PxJointLimitPyramid returnValue(yLimitAngleMin, yLimitAngleMax, zLimitAngleMin, zLimitAngleMax, contactDist);
physx_PxJointLimitPyramid_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxJointLimitPyramid_Pod PxJointLimitPyramid_new_1(float yLimitAngleMin, float yLimitAngleMax, float zLimitAngleMin, float zLimitAngleMax, physx_PxSpring_Pod const* spring_pod) {
physx::PxSpring const& spring = reinterpret_cast<physx::PxSpring const&>(*spring_pod);
physx::PxJointLimitPyramid returnValue(yLimitAngleMin, yLimitAngleMax, zLimitAngleMin, zLimitAngleMax, spring);
physx_PxJointLimitPyramid_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxJointLimitPyramid_isValid(physx_PxJointLimitPyramid_Pod const* self__pod) {
physx::PxJointLimitPyramid const* self_ = reinterpret_cast<physx::PxJointLimitPyramid const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

void PxJointLimitPyramid_delete(physx_PxJointLimitPyramid_Pod* self__pod) {
physx::PxJointLimitPyramid* self_ = reinterpret_cast<physx::PxJointLimitPyramid*>(self__pod);
delete self_;
}

physx_PxPrismaticJoint_Pod* phys_PxPrismaticJointCreate(physx_PxPhysics_Pod* physics_pod, physx_PxRigidActor_Pod* actor0_pod, physx_PxTransform_Pod const* localFrame0_pod, physx_PxRigidActor_Pod* actor1_pod, physx_PxTransform_Pod const* localFrame1_pod) {
physx::PxPhysics& physics = reinterpret_cast<physx::PxPhysics&>(*physics_pod);
physx::PxRigidActor* actor0 = reinterpret_cast<physx::PxRigidActor*>(actor0_pod);
physx::PxTransform const& localFrame0 = reinterpret_cast<physx::PxTransform const&>(*localFrame0_pod);
physx::PxRigidActor* actor1 = reinterpret_cast<physx::PxRigidActor*>(actor1_pod);
physx::PxTransform const& localFrame1 = reinterpret_cast<physx::PxTransform const&>(*localFrame1_pod);
physx::PxPrismaticJoint* returnValue = PxPrismaticJointCreate(physics, actor0, localFrame0, actor1, localFrame1);
physx_PxPrismaticJoint_Pod* returnValue_pod = reinterpret_cast<physx_PxPrismaticJoint_Pod*>(returnValue);
return returnValue_pod;
}

float PxPrismaticJoint_getPosition(physx_PxPrismaticJoint_Pod const* self__pod) {
physx::PxPrismaticJoint const* self_ = reinterpret_cast<physx::PxPrismaticJoint const*>(self__pod);
float returnValue = self_->getPosition();
return returnValue;
}

float PxPrismaticJoint_getVelocity(physx_PxPrismaticJoint_Pod const* self__pod) {
physx::PxPrismaticJoint const* self_ = reinterpret_cast<physx::PxPrismaticJoint const*>(self__pod);
float returnValue = self_->getVelocity();
return returnValue;
}

void PxPrismaticJoint_setLimit_mut(physx_PxPrismaticJoint_Pod* self__pod, physx_PxJointLinearLimitPair_Pod const* anonymous_arg0_pod) {
physx::PxPrismaticJoint* self_ = reinterpret_cast<physx::PxPrismaticJoint*>(self__pod);
physx::PxJointLinearLimitPair const& anonymous_arg0 = reinterpret_cast<physx::PxJointLinearLimitPair const&>(*anonymous_arg0_pod);
self_->setLimit(anonymous_arg0);
}

physx_PxJointLinearLimitPair_Pod PxPrismaticJoint_getLimit(physx_PxPrismaticJoint_Pod const* self__pod) {
physx::PxPrismaticJoint const* self_ = reinterpret_cast<physx::PxPrismaticJoint const*>(self__pod);
physx::PxJointLinearLimitPair returnValue = self_->getLimit();
physx_PxJointLinearLimitPair_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxPrismaticJoint_setPrismaticJointFlags_mut(physx_PxPrismaticJoint_Pod* self__pod, physx_PxPrismaticJointFlags_Pod flags_pod) {
physx::PxPrismaticJoint* self_ = reinterpret_cast<physx::PxPrismaticJoint*>(self__pod);
physx::PxPrismaticJointFlags flags;
memcpy(&flags, &flags_pod, sizeof(flags));
self_->setPrismaticJointFlags(flags);
}

void PxPrismaticJoint_setPrismaticJointFlag_mut(physx_PxPrismaticJoint_Pod* self__pod, unsigned int flag_pod, bool value) {
physx::PxPrismaticJoint* self_ = reinterpret_cast<physx::PxPrismaticJoint*>(self__pod);
PxPrismaticJointFlag::Enum flag = (PxPrismaticJointFlag::Enum)flag_pod;
self_->setPrismaticJointFlag(flag, value);
}

physx_PxPrismaticJointFlags_Pod PxPrismaticJoint_getPrismaticJointFlags(physx_PxPrismaticJoint_Pod const* self__pod) {
physx::PxPrismaticJoint const* self_ = reinterpret_cast<physx::PxPrismaticJoint const*>(self__pod);
physx::PxPrismaticJointFlags returnValue = self_->getPrismaticJointFlags();
physx_PxPrismaticJointFlags_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxPrismaticJoint_setProjectionLinearTolerance_mut(physx_PxPrismaticJoint_Pod* self__pod, float tolerance) {
physx::PxPrismaticJoint* self_ = reinterpret_cast<physx::PxPrismaticJoint*>(self__pod);
self_->setProjectionLinearTolerance(tolerance);
}

float PxPrismaticJoint_getProjectionLinearTolerance(physx_PxPrismaticJoint_Pod const* self__pod) {
physx::PxPrismaticJoint const* self_ = reinterpret_cast<physx::PxPrismaticJoint const*>(self__pod);
float returnValue = self_->getProjectionLinearTolerance();
return returnValue;
}

void PxPrismaticJoint_setProjectionAngularTolerance_mut(physx_PxPrismaticJoint_Pod* self__pod, float tolerance) {
physx::PxPrismaticJoint* self_ = reinterpret_cast<physx::PxPrismaticJoint*>(self__pod);
self_->setProjectionAngularTolerance(tolerance);
}

float PxPrismaticJoint_getProjectionAngularTolerance(physx_PxPrismaticJoint_Pod const* self__pod) {
physx::PxPrismaticJoint const* self_ = reinterpret_cast<physx::PxPrismaticJoint const*>(self__pod);
float returnValue = self_->getProjectionAngularTolerance();
return returnValue;
}

char const* PxPrismaticJoint_getConcreteTypeName(physx_PxPrismaticJoint_Pod const* self__pod) {
physx::PxPrismaticJoint const* self_ = reinterpret_cast<physx::PxPrismaticJoint const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

physx_PxRevoluteJoint_Pod* phys_PxRevoluteJointCreate(physx_PxPhysics_Pod* physics_pod, physx_PxRigidActor_Pod* actor0_pod, physx_PxTransform_Pod const* localFrame0_pod, physx_PxRigidActor_Pod* actor1_pod, physx_PxTransform_Pod const* localFrame1_pod) {
physx::PxPhysics& physics = reinterpret_cast<physx::PxPhysics&>(*physics_pod);
physx::PxRigidActor* actor0 = reinterpret_cast<physx::PxRigidActor*>(actor0_pod);
physx::PxTransform const& localFrame0 = reinterpret_cast<physx::PxTransform const&>(*localFrame0_pod);
physx::PxRigidActor* actor1 = reinterpret_cast<physx::PxRigidActor*>(actor1_pod);
physx::PxTransform const& localFrame1 = reinterpret_cast<physx::PxTransform const&>(*localFrame1_pod);
physx::PxRevoluteJoint* returnValue = PxRevoluteJointCreate(physics, actor0, localFrame0, actor1, localFrame1);
physx_PxRevoluteJoint_Pod* returnValue_pod = reinterpret_cast<physx_PxRevoluteJoint_Pod*>(returnValue);
return returnValue_pod;
}

float PxRevoluteJoint_getAngle(physx_PxRevoluteJoint_Pod const* self__pod) {
physx::PxRevoluteJoint const* self_ = reinterpret_cast<physx::PxRevoluteJoint const*>(self__pod);
float returnValue = self_->getAngle();
return returnValue;
}

float PxRevoluteJoint_getVelocity(physx_PxRevoluteJoint_Pod const* self__pod) {
physx::PxRevoluteJoint const* self_ = reinterpret_cast<physx::PxRevoluteJoint const*>(self__pod);
float returnValue = self_->getVelocity();
return returnValue;
}

void PxRevoluteJoint_setLimit_mut(physx_PxRevoluteJoint_Pod* self__pod, physx_PxJointAngularLimitPair_Pod const* limits_pod) {
physx::PxRevoluteJoint* self_ = reinterpret_cast<physx::PxRevoluteJoint*>(self__pod);
physx::PxJointAngularLimitPair const& limits = reinterpret_cast<physx::PxJointAngularLimitPair const&>(*limits_pod);
self_->setLimit(limits);
}

physx_PxJointAngularLimitPair_Pod PxRevoluteJoint_getLimit(physx_PxRevoluteJoint_Pod const* self__pod) {
physx::PxRevoluteJoint const* self_ = reinterpret_cast<physx::PxRevoluteJoint const*>(self__pod);
physx::PxJointAngularLimitPair returnValue = self_->getLimit();
physx_PxJointAngularLimitPair_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxRevoluteJoint_setDriveVelocity_mut(physx_PxRevoluteJoint_Pod* self__pod, float velocity, bool autowake) {
physx::PxRevoluteJoint* self_ = reinterpret_cast<physx::PxRevoluteJoint*>(self__pod);
self_->setDriveVelocity(velocity, autowake);
}

float PxRevoluteJoint_getDriveVelocity(physx_PxRevoluteJoint_Pod const* self__pod) {
physx::PxRevoluteJoint const* self_ = reinterpret_cast<physx::PxRevoluteJoint const*>(self__pod);
float returnValue = self_->getDriveVelocity();
return returnValue;
}

void PxRevoluteJoint_setDriveForceLimit_mut(physx_PxRevoluteJoint_Pod* self__pod, float limit) {
physx::PxRevoluteJoint* self_ = reinterpret_cast<physx::PxRevoluteJoint*>(self__pod);
self_->setDriveForceLimit(limit);
}

float PxRevoluteJoint_getDriveForceLimit(physx_PxRevoluteJoint_Pod const* self__pod) {
physx::PxRevoluteJoint const* self_ = reinterpret_cast<physx::PxRevoluteJoint const*>(self__pod);
float returnValue = self_->getDriveForceLimit();
return returnValue;
}

void PxRevoluteJoint_setDriveGearRatio_mut(physx_PxRevoluteJoint_Pod* self__pod, float ratio) {
physx::PxRevoluteJoint* self_ = reinterpret_cast<physx::PxRevoluteJoint*>(self__pod);
self_->setDriveGearRatio(ratio);
}

float PxRevoluteJoint_getDriveGearRatio(physx_PxRevoluteJoint_Pod const* self__pod) {
physx::PxRevoluteJoint const* self_ = reinterpret_cast<physx::PxRevoluteJoint const*>(self__pod);
float returnValue = self_->getDriveGearRatio();
return returnValue;
}

void PxRevoluteJoint_setRevoluteJointFlags_mut(physx_PxRevoluteJoint_Pod* self__pod, physx_PxRevoluteJointFlags_Pod flags_pod) {
physx::PxRevoluteJoint* self_ = reinterpret_cast<physx::PxRevoluteJoint*>(self__pod);
physx::PxRevoluteJointFlags flags;
memcpy(&flags, &flags_pod, sizeof(flags));
self_->setRevoluteJointFlags(flags);
}

void PxRevoluteJoint_setRevoluteJointFlag_mut(physx_PxRevoluteJoint_Pod* self__pod, unsigned int flag_pod, bool value) {
physx::PxRevoluteJoint* self_ = reinterpret_cast<physx::PxRevoluteJoint*>(self__pod);
PxRevoluteJointFlag::Enum flag = (PxRevoluteJointFlag::Enum)flag_pod;
self_->setRevoluteJointFlag(flag, value);
}

physx_PxRevoluteJointFlags_Pod PxRevoluteJoint_getRevoluteJointFlags(physx_PxRevoluteJoint_Pod const* self__pod) {
physx::PxRevoluteJoint const* self_ = reinterpret_cast<physx::PxRevoluteJoint const*>(self__pod);
physx::PxRevoluteJointFlags returnValue = self_->getRevoluteJointFlags();
physx_PxRevoluteJointFlags_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxRevoluteJoint_setProjectionLinearTolerance_mut(physx_PxRevoluteJoint_Pod* self__pod, float tolerance) {
physx::PxRevoluteJoint* self_ = reinterpret_cast<physx::PxRevoluteJoint*>(self__pod);
self_->setProjectionLinearTolerance(tolerance);
}

float PxRevoluteJoint_getProjectionLinearTolerance(physx_PxRevoluteJoint_Pod const* self__pod) {
physx::PxRevoluteJoint const* self_ = reinterpret_cast<physx::PxRevoluteJoint const*>(self__pod);
float returnValue = self_->getProjectionLinearTolerance();
return returnValue;
}

void PxRevoluteJoint_setProjectionAngularTolerance_mut(physx_PxRevoluteJoint_Pod* self__pod, float tolerance) {
physx::PxRevoluteJoint* self_ = reinterpret_cast<physx::PxRevoluteJoint*>(self__pod);
self_->setProjectionAngularTolerance(tolerance);
}

float PxRevoluteJoint_getProjectionAngularTolerance(physx_PxRevoluteJoint_Pod const* self__pod) {
physx::PxRevoluteJoint const* self_ = reinterpret_cast<physx::PxRevoluteJoint const*>(self__pod);
float returnValue = self_->getProjectionAngularTolerance();
return returnValue;
}

char const* PxRevoluteJoint_getConcreteTypeName(physx_PxRevoluteJoint_Pod const* self__pod) {
physx::PxRevoluteJoint const* self_ = reinterpret_cast<physx::PxRevoluteJoint const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

physx_PxSphericalJoint_Pod* phys_PxSphericalJointCreate(physx_PxPhysics_Pod* physics_pod, physx_PxRigidActor_Pod* actor0_pod, physx_PxTransform_Pod const* localFrame0_pod, physx_PxRigidActor_Pod* actor1_pod, physx_PxTransform_Pod const* localFrame1_pod) {
physx::PxPhysics& physics = reinterpret_cast<physx::PxPhysics&>(*physics_pod);
physx::PxRigidActor* actor0 = reinterpret_cast<physx::PxRigidActor*>(actor0_pod);
physx::PxTransform const& localFrame0 = reinterpret_cast<physx::PxTransform const&>(*localFrame0_pod);
physx::PxRigidActor* actor1 = reinterpret_cast<physx::PxRigidActor*>(actor1_pod);
physx::PxTransform const& localFrame1 = reinterpret_cast<physx::PxTransform const&>(*localFrame1_pod);
physx::PxSphericalJoint* returnValue = PxSphericalJointCreate(physics, actor0, localFrame0, actor1, localFrame1);
physx_PxSphericalJoint_Pod* returnValue_pod = reinterpret_cast<physx_PxSphericalJoint_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxJointLimitCone_Pod PxSphericalJoint_getLimitCone(physx_PxSphericalJoint_Pod const* self__pod) {
physx::PxSphericalJoint const* self_ = reinterpret_cast<physx::PxSphericalJoint const*>(self__pod);
physx::PxJointLimitCone returnValue = self_->getLimitCone();
physx_PxJointLimitCone_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxSphericalJoint_setLimitCone_mut(physx_PxSphericalJoint_Pod* self__pod, physx_PxJointLimitCone_Pod const* limit_pod) {
physx::PxSphericalJoint* self_ = reinterpret_cast<physx::PxSphericalJoint*>(self__pod);
physx::PxJointLimitCone const& limit = reinterpret_cast<physx::PxJointLimitCone const&>(*limit_pod);
self_->setLimitCone(limit);
}

float PxSphericalJoint_getSwingYAngle(physx_PxSphericalJoint_Pod const* self__pod) {
physx::PxSphericalJoint const* self_ = reinterpret_cast<physx::PxSphericalJoint const*>(self__pod);
float returnValue = self_->getSwingYAngle();
return returnValue;
}

float PxSphericalJoint_getSwingZAngle(physx_PxSphericalJoint_Pod const* self__pod) {
physx::PxSphericalJoint const* self_ = reinterpret_cast<physx::PxSphericalJoint const*>(self__pod);
float returnValue = self_->getSwingZAngle();
return returnValue;
}

void PxSphericalJoint_setSphericalJointFlags_mut(physx_PxSphericalJoint_Pod* self__pod, physx_PxSphericalJointFlags_Pod flags_pod) {
physx::PxSphericalJoint* self_ = reinterpret_cast<physx::PxSphericalJoint*>(self__pod);
physx::PxSphericalJointFlags flags;
memcpy(&flags, &flags_pod, sizeof(flags));
self_->setSphericalJointFlags(flags);
}

void PxSphericalJoint_setSphericalJointFlag_mut(physx_PxSphericalJoint_Pod* self__pod, unsigned int flag_pod, bool value) {
physx::PxSphericalJoint* self_ = reinterpret_cast<physx::PxSphericalJoint*>(self__pod);
PxSphericalJointFlag::Enum flag = (PxSphericalJointFlag::Enum)flag_pod;
self_->setSphericalJointFlag(flag, value);
}

physx_PxSphericalJointFlags_Pod PxSphericalJoint_getSphericalJointFlags(physx_PxSphericalJoint_Pod const* self__pod) {
physx::PxSphericalJoint const* self_ = reinterpret_cast<physx::PxSphericalJoint const*>(self__pod);
physx::PxSphericalJointFlags returnValue = self_->getSphericalJointFlags();
physx_PxSphericalJointFlags_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxSphericalJoint_setProjectionLinearTolerance_mut(physx_PxSphericalJoint_Pod* self__pod, float tolerance) {
physx::PxSphericalJoint* self_ = reinterpret_cast<physx::PxSphericalJoint*>(self__pod);
self_->setProjectionLinearTolerance(tolerance);
}

float PxSphericalJoint_getProjectionLinearTolerance(physx_PxSphericalJoint_Pod const* self__pod) {
physx::PxSphericalJoint const* self_ = reinterpret_cast<physx::PxSphericalJoint const*>(self__pod);
float returnValue = self_->getProjectionLinearTolerance();
return returnValue;
}

char const* PxSphericalJoint_getConcreteTypeName(physx_PxSphericalJoint_Pod const* self__pod) {
physx::PxSphericalJoint const* self_ = reinterpret_cast<physx::PxSphericalJoint const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

physx_PxD6Joint_Pod* phys_PxD6JointCreate(physx_PxPhysics_Pod* physics_pod, physx_PxRigidActor_Pod* actor0_pod, physx_PxTransform_Pod const* localFrame0_pod, physx_PxRigidActor_Pod* actor1_pod, physx_PxTransform_Pod const* localFrame1_pod) {
physx::PxPhysics& physics = reinterpret_cast<physx::PxPhysics&>(*physics_pod);
physx::PxRigidActor* actor0 = reinterpret_cast<physx::PxRigidActor*>(actor0_pod);
physx::PxTransform const& localFrame0 = reinterpret_cast<physx::PxTransform const&>(*localFrame0_pod);
physx::PxRigidActor* actor1 = reinterpret_cast<physx::PxRigidActor*>(actor1_pod);
physx::PxTransform const& localFrame1 = reinterpret_cast<physx::PxTransform const&>(*localFrame1_pod);
physx::PxD6Joint* returnValue = PxD6JointCreate(physics, actor0, localFrame0, actor1, localFrame1);
physx_PxD6Joint_Pod* returnValue_pod = reinterpret_cast<physx_PxD6Joint_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxD6JointDrive_Pod PxD6JointDrive_new() {
physx::PxD6JointDrive returnValue;
physx_PxD6JointDrive_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxD6JointDrive_Pod PxD6JointDrive_new_1(float driveStiffness, float driveDamping, float driveForceLimit, bool isAcceleration) {
physx::PxD6JointDrive returnValue(driveStiffness, driveDamping, driveForceLimit, isAcceleration);
physx_PxD6JointDrive_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxD6JointDrive_isValid(physx_PxD6JointDrive_Pod const* self__pod) {
physx::PxD6JointDrive const* self_ = reinterpret_cast<physx::PxD6JointDrive const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

void PxD6Joint_setMotion_mut(physx_PxD6Joint_Pod* self__pod, unsigned int axis_pod, unsigned int type_pod) {
physx::PxD6Joint* self_ = reinterpret_cast<physx::PxD6Joint*>(self__pod);
PxD6Axis::Enum axis = (PxD6Axis::Enum)axis_pod;
PxD6Motion::Enum type = (PxD6Motion::Enum)type_pod;
self_->setMotion(axis, type);
}

unsigned int PxD6Joint_getMotion(physx_PxD6Joint_Pod const* self__pod, unsigned int axis_pod) {
physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
PxD6Axis::Enum axis = (PxD6Axis::Enum)axis_pod;
PxD6Motion::Enum returnValue = self_->getMotion(axis);
unsigned int returnValue_pod = (unsigned int)returnValue;
return returnValue_pod;
}

float PxD6Joint_getTwistAngle(physx_PxD6Joint_Pod const* self__pod) {
physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
float returnValue = self_->getTwistAngle();
return returnValue;
}

float PxD6Joint_getTwist(physx_PxD6Joint_Pod const* self__pod) {
physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
float returnValue = self_->getTwist();
return returnValue;
}

float PxD6Joint_getSwingYAngle(physx_PxD6Joint_Pod const* self__pod) {
physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
float returnValue = self_->getSwingYAngle();
return returnValue;
}

float PxD6Joint_getSwingZAngle(physx_PxD6Joint_Pod const* self__pod) {
physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
float returnValue = self_->getSwingZAngle();
return returnValue;
}

void PxD6Joint_setDistanceLimit_mut(physx_PxD6Joint_Pod* self__pod, physx_PxJointLinearLimit_Pod const* limit_pod) {
physx::PxD6Joint* self_ = reinterpret_cast<physx::PxD6Joint*>(self__pod);
physx::PxJointLinearLimit const& limit = reinterpret_cast<physx::PxJointLinearLimit const&>(*limit_pod);
self_->setDistanceLimit(limit);
}

physx_PxJointLinearLimit_Pod PxD6Joint_getDistanceLimit(physx_PxD6Joint_Pod const* self__pod) {
physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
physx::PxJointLinearLimit returnValue = self_->getDistanceLimit();
physx_PxJointLinearLimit_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxD6Joint_setLinearLimit_mut(physx_PxD6Joint_Pod* self__pod, physx_PxJointLinearLimit_Pod const* limit_pod) {
physx::PxD6Joint* self_ = reinterpret_cast<physx::PxD6Joint*>(self__pod);
physx::PxJointLinearLimit const& limit = reinterpret_cast<physx::PxJointLinearLimit const&>(*limit_pod);
self_->setLinearLimit(limit);
}

physx_PxJointLinearLimit_Pod PxD6Joint_getLinearLimit(physx_PxD6Joint_Pod const* self__pod) {
physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
physx::PxJointLinearLimit returnValue = self_->getLinearLimit();
physx_PxJointLinearLimit_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxD6Joint_setLinearLimit_mut_1(physx_PxD6Joint_Pod* self__pod, unsigned int axis_pod, physx_PxJointLinearLimitPair_Pod const* limit_pod) {
physx::PxD6Joint* self_ = reinterpret_cast<physx::PxD6Joint*>(self__pod);
PxD6Axis::Enum axis = (PxD6Axis::Enum)axis_pod;
physx::PxJointLinearLimitPair const& limit = reinterpret_cast<physx::PxJointLinearLimitPair const&>(*limit_pod);
self_->setLinearLimit(axis, limit);
}

physx_PxJointLinearLimitPair_Pod PxD6Joint_getLinearLimit_1(physx_PxD6Joint_Pod const* self__pod, unsigned int axis_pod) {
physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
PxD6Axis::Enum axis = (PxD6Axis::Enum)axis_pod;
physx::PxJointLinearLimitPair returnValue = self_->getLinearLimit(axis);
physx_PxJointLinearLimitPair_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxD6Joint_setTwistLimit_mut(physx_PxD6Joint_Pod* self__pod, physx_PxJointAngularLimitPair_Pod const* limit_pod) {
physx::PxD6Joint* self_ = reinterpret_cast<physx::PxD6Joint*>(self__pod);
physx::PxJointAngularLimitPair const& limit = reinterpret_cast<physx::PxJointAngularLimitPair const&>(*limit_pod);
self_->setTwistLimit(limit);
}

physx_PxJointAngularLimitPair_Pod PxD6Joint_getTwistLimit(physx_PxD6Joint_Pod const* self__pod) {
physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
physx::PxJointAngularLimitPair returnValue = self_->getTwistLimit();
physx_PxJointAngularLimitPair_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxD6Joint_setSwingLimit_mut(physx_PxD6Joint_Pod* self__pod, physx_PxJointLimitCone_Pod const* limit_pod) {
physx::PxD6Joint* self_ = reinterpret_cast<physx::PxD6Joint*>(self__pod);
physx::PxJointLimitCone const& limit = reinterpret_cast<physx::PxJointLimitCone const&>(*limit_pod);
self_->setSwingLimit(limit);
}

physx_PxJointLimitCone_Pod PxD6Joint_getSwingLimit(physx_PxD6Joint_Pod const* self__pod) {
physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
physx::PxJointLimitCone returnValue = self_->getSwingLimit();
physx_PxJointLimitCone_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxD6Joint_setPyramidSwingLimit_mut(physx_PxD6Joint_Pod* self__pod, physx_PxJointLimitPyramid_Pod const* limit_pod) {
physx::PxD6Joint* self_ = reinterpret_cast<physx::PxD6Joint*>(self__pod);
physx::PxJointLimitPyramid const& limit = reinterpret_cast<physx::PxJointLimitPyramid const&>(*limit_pod);
self_->setPyramidSwingLimit(limit);
}

physx_PxJointLimitPyramid_Pod PxD6Joint_getPyramidSwingLimit(physx_PxD6Joint_Pod const* self__pod) {
physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
physx::PxJointLimitPyramid returnValue = self_->getPyramidSwingLimit();
physx_PxJointLimitPyramid_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxD6Joint_setDrive_mut(physx_PxD6Joint_Pod* self__pod, unsigned int index_pod, physx_PxD6JointDrive_Pod const* drive_pod) {
physx::PxD6Joint* self_ = reinterpret_cast<physx::PxD6Joint*>(self__pod);
PxD6Drive::Enum index = (PxD6Drive::Enum)index_pod;
physx::PxD6JointDrive const& drive = reinterpret_cast<physx::PxD6JointDrive const&>(*drive_pod);
self_->setDrive(index, drive);
}

physx_PxD6JointDrive_Pod PxD6Joint_getDrive(physx_PxD6Joint_Pod const* self__pod, unsigned int index_pod) {
physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
PxD6Drive::Enum index = (PxD6Drive::Enum)index_pod;
physx::PxD6JointDrive returnValue = self_->getDrive(index);
physx_PxD6JointDrive_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxD6Joint_setDrivePosition_mut(physx_PxD6Joint_Pod* self__pod, physx_PxTransform_Pod const* pose_pod, bool autowake) {
physx::PxD6Joint* self_ = reinterpret_cast<physx::PxD6Joint*>(self__pod);
physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
self_->setDrivePosition(pose, autowake);
}

physx_PxTransform_Pod PxD6Joint_getDrivePosition(physx_PxD6Joint_Pod const* self__pod) {
physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
physx::PxTransform returnValue = self_->getDrivePosition();
physx_PxTransform_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxD6Joint_setDriveVelocity_mut(physx_PxD6Joint_Pod* self__pod, physx_PxVec3_Pod const* linear_pod, physx_PxVec3_Pod const* angular_pod, bool autowake) {
physx::PxD6Joint* self_ = reinterpret_cast<physx::PxD6Joint*>(self__pod);
physx::PxVec3 const& linear = reinterpret_cast<physx::PxVec3 const&>(*linear_pod);
physx::PxVec3 const& angular = reinterpret_cast<physx::PxVec3 const&>(*angular_pod);
self_->setDriveVelocity(linear, angular, autowake);
}

void PxD6Joint_getDriveVelocity(physx_PxD6Joint_Pod const* self__pod, physx_PxVec3_Pod* linear_pod, physx_PxVec3_Pod* angular_pod) {
physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
physx::PxVec3& linear = reinterpret_cast<physx::PxVec3&>(*linear_pod);
physx::PxVec3& angular = reinterpret_cast<physx::PxVec3&>(*angular_pod);
self_->getDriveVelocity(linear, angular);
}

void PxD6Joint_setProjectionLinearTolerance_mut(physx_PxD6Joint_Pod* self__pod, float tolerance) {
physx::PxD6Joint* self_ = reinterpret_cast<physx::PxD6Joint*>(self__pod);
self_->setProjectionLinearTolerance(tolerance);
}

float PxD6Joint_getProjectionLinearTolerance(physx_PxD6Joint_Pod const* self__pod) {
physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
float returnValue = self_->getProjectionLinearTolerance();
return returnValue;
}

void PxD6Joint_setProjectionAngularTolerance_mut(physx_PxD6Joint_Pod* self__pod, float tolerance) {
physx::PxD6Joint* self_ = reinterpret_cast<physx::PxD6Joint*>(self__pod);
self_->setProjectionAngularTolerance(tolerance);
}

float PxD6Joint_getProjectionAngularTolerance(physx_PxD6Joint_Pod const* self__pod) {
physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
float returnValue = self_->getProjectionAngularTolerance();
return returnValue;
}

char const* PxD6Joint_getConcreteTypeName(physx_PxD6Joint_Pod const* self__pod) {
physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

physx_PxGroupsMask_Pod* PxGroupsMask_new_alloc() {
auto returnValue = new physx::PxGroupsMask();
physx_PxGroupsMask_Pod* returnValue_pod = reinterpret_cast<physx_PxGroupsMask_Pod*>(returnValue);
return returnValue_pod;
}

void PxGroupsMask_delete(physx_PxGroupsMask_Pod* self__pod) {
physx::PxGroupsMask* self_ = reinterpret_cast<physx::PxGroupsMask*>(self__pod);
delete self_;
}

physx_PxFilterFlags_Pod phys_PxDefaultSimulationFilterShader(uint32_t attributes0, physx_PxFilterData_Pod filterData0_pod, uint32_t attributes1, physx_PxFilterData_Pod filterData1_pod, physx_PxPairFlags_Pod* pairFlags_pod, void const* constantBlock, uint32_t constantBlockSize) {
physx::PxFilterData filterData0;
memcpy(&filterData0, &filterData0_pod, sizeof(filterData0));
physx::PxFilterData filterData1;
memcpy(&filterData1, &filterData1_pod, sizeof(filterData1));
physx::PxPairFlags& pairFlags = reinterpret_cast<physx::PxPairFlags&>(*pairFlags_pod);
physx::PxFilterFlags returnValue = PxDefaultSimulationFilterShader(attributes0, filterData0, attributes1, filterData1, pairFlags, constantBlock, constantBlockSize);
physx_PxFilterFlags_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool phys_PxGetGroupCollisionFlag(uint16_t group1, uint16_t group2) {
bool returnValue = PxGetGroupCollisionFlag(group1, group2);
return returnValue;
}

void phys_PxSetGroupCollisionFlag(uint16_t group1, uint16_t group2, bool enable) {
PxSetGroupCollisionFlag(group1, group2, enable);
}

uint16_t phys_PxGetGroup(physx_PxActor_Pod const* actor_pod) {
physx::PxActor const& actor = reinterpret_cast<physx::PxActor const&>(*actor_pod);
uint16_t returnValue = PxGetGroup(actor);
return returnValue;
}

void phys_PxSetGroup(physx_PxActor_Pod* actor_pod, uint16_t collisionGroup) {
physx::PxActor& actor = reinterpret_cast<physx::PxActor&>(*actor_pod);
PxSetGroup(actor, collisionGroup);
}

void phys_PxGetFilterOps(unsigned int* op0_pod, unsigned int* op1_pod, unsigned int* op2_pod) {
PxFilterOp::Enum& op0 = reinterpret_cast<PxFilterOp::Enum&>(*op0_pod);
PxFilterOp::Enum& op1 = reinterpret_cast<PxFilterOp::Enum&>(*op1_pod);
PxFilterOp::Enum& op2 = reinterpret_cast<PxFilterOp::Enum&>(*op2_pod);
PxGetFilterOps(op0, op1, op2);
}

void phys_PxSetFilterOps(unsigned int const* op0_pod, unsigned int const* op1_pod, unsigned int const* op2_pod) {
PxFilterOp::Enum const& op0 = reinterpret_cast<PxFilterOp::Enum const&>(*op0_pod);
PxFilterOp::Enum const& op1 = reinterpret_cast<PxFilterOp::Enum const&>(*op1_pod);
PxFilterOp::Enum const& op2 = reinterpret_cast<PxFilterOp::Enum const&>(*op2_pod);
PxSetFilterOps(op0, op1, op2);
}

bool phys_PxGetFilterBool() {
bool returnValue = PxGetFilterBool();
return returnValue;
}

void phys_PxSetFilterBool(bool enable) {
PxSetFilterBool(enable);
}

void phys_PxGetFilterConstants(physx_PxGroupsMask_Pod* c0_pod, physx_PxGroupsMask_Pod* c1_pod) {
physx::PxGroupsMask& c0 = reinterpret_cast<physx::PxGroupsMask&>(*c0_pod);
physx::PxGroupsMask& c1 = reinterpret_cast<physx::PxGroupsMask&>(*c1_pod);
PxGetFilterConstants(c0, c1);
}

void phys_PxSetFilterConstants(physx_PxGroupsMask_Pod const* c0_pod, physx_PxGroupsMask_Pod const* c1_pod) {
physx::PxGroupsMask const& c0 = reinterpret_cast<physx::PxGroupsMask const&>(*c0_pod);
physx::PxGroupsMask const& c1 = reinterpret_cast<physx::PxGroupsMask const&>(*c1_pod);
PxSetFilterConstants(c0, c1);
}

physx_PxGroupsMask_Pod phys_PxGetGroupsMask(physx_PxActor_Pod const* actor_pod) {
physx::PxActor const& actor = reinterpret_cast<physx::PxActor const&>(*actor_pod);
physx::PxGroupsMask returnValue = PxGetGroupsMask(actor);
physx_PxGroupsMask_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void phys_PxSetGroupsMask(physx_PxActor_Pod* actor_pod, physx_PxGroupsMask_Pod const* mask_pod) {
physx::PxActor& actor = reinterpret_cast<physx::PxActor&>(*actor_pod);
physx::PxGroupsMask const& mask = reinterpret_cast<physx::PxGroupsMask const&>(*mask_pod);
PxSetGroupsMask(actor, mask);
}

physx_PxDefaultErrorCallback_Pod* PxDefaultErrorCallback_new_alloc() {
auto returnValue = new physx::PxDefaultErrorCallback();
physx_PxDefaultErrorCallback_Pod* returnValue_pod = reinterpret_cast<physx_PxDefaultErrorCallback_Pod*>(returnValue);
return returnValue_pod;
}

void PxDefaultErrorCallback_delete(physx_PxDefaultErrorCallback_Pod* self__pod) {
physx::PxDefaultErrorCallback* self_ = reinterpret_cast<physx::PxDefaultErrorCallback*>(self__pod);
delete self_;
}

void PxDefaultErrorCallback_reportError_mut(physx_PxDefaultErrorCallback_Pod* self__pod, int code_pod, char const* message, char const* file, int32_t line) {
physx::PxDefaultErrorCallback* self_ = reinterpret_cast<physx::PxDefaultErrorCallback*>(self__pod);
PxErrorCode::Enum code = (PxErrorCode::Enum)code_pod;
self_->reportError(code, message, file, line);
}

physx_PxShape_Pod* PxRigidActorExt_createExclusiveShape_mut(physx_PxRigidActor_Pod* actor_pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxMaterial_Pod* const* materials_pod, uint16_t materialCount, physx_PxShapeFlags_Pod shapeFlags_pod) {
physx::PxRigidActor& actor = reinterpret_cast<physx::PxRigidActor&>(*actor_pod);
physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
physx::PxMaterial* const* materials = reinterpret_cast<physx::PxMaterial* const*>(materials_pod);
physx::PxShapeFlags shapeFlags;
memcpy(&shapeFlags, &shapeFlags_pod, sizeof(shapeFlags));
physx::PxShape* returnValue = PxRigidActorExt::createExclusiveShape(actor, geometry, materials, materialCount, shapeFlags);
physx_PxShape_Pod* returnValue_pod = reinterpret_cast<physx_PxShape_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxShape_Pod* PxRigidActorExt_createExclusiveShape_mut_1(physx_PxRigidActor_Pod* actor_pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxMaterial_Pod const* material_pod, physx_PxShapeFlags_Pod shapeFlags_pod) {
physx::PxRigidActor& actor = reinterpret_cast<physx::PxRigidActor&>(*actor_pod);
physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
physx::PxMaterial const& material = reinterpret_cast<physx::PxMaterial const&>(*material_pod);
physx::PxShapeFlags shapeFlags;
memcpy(&shapeFlags, &shapeFlags_pod, sizeof(shapeFlags));
physx::PxShape* returnValue = PxRigidActorExt::createExclusiveShape(actor, geometry, material, shapeFlags);
physx_PxShape_Pod* returnValue_pod = reinterpret_cast<physx_PxShape_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxBounds3_Pod* PxRigidActorExt_getRigidActorShapeLocalBoundsList_mut(physx_PxRigidActor_Pod const* actor_pod, uint32_t* numBounds_pod) {
physx::PxRigidActor const& actor = reinterpret_cast<physx::PxRigidActor const&>(*actor_pod);
uint32_t& numBounds = *numBounds_pod;
physx::PxBounds3* returnValue = PxRigidActorExt::getRigidActorShapeLocalBoundsList(actor, numBounds);
physx_PxBounds3_Pod* returnValue_pod = reinterpret_cast<physx_PxBounds3_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxMassProperties_Pod PxMassProperties_new() {
physx::PxMassProperties returnValue;
physx_PxMassProperties_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMassProperties_Pod PxMassProperties_new_1(float m, physx_PxMat33_Pod const* inertiaT_pod, physx_PxVec3_Pod const* com_pod) {
physx::PxMat33 const& inertiaT = reinterpret_cast<physx::PxMat33 const&>(*inertiaT_pod);
physx::PxVec3 const& com = reinterpret_cast<physx::PxVec3 const&>(*com_pod);
physx::PxMassProperties returnValue(m, inertiaT, com);
physx_PxMassProperties_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMassProperties_Pod PxMassProperties_new_2(physx_PxGeometry_Pod const* geometry_pod) {
physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
physx::PxMassProperties returnValue(geometry);
physx_PxMassProperties_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxMassProperties_translate_mut(physx_PxMassProperties_Pod* self__pod, physx_PxVec3_Pod const* t_pod) {
physx::PxMassProperties* self_ = reinterpret_cast<physx::PxMassProperties*>(self__pod);
physx::PxVec3 const& t = reinterpret_cast<physx::PxVec3 const&>(*t_pod);
self_->translate(t);
}

physx_PxVec3_Pod PxMassProperties_getMassSpaceInertia_mut(physx_PxMat33_Pod const* inertia_pod, physx_PxQuat_Pod* massFrame_pod) {
physx::PxMat33 const& inertia = reinterpret_cast<physx::PxMat33 const&>(*inertia_pod);
physx::PxQuat& massFrame = reinterpret_cast<physx::PxQuat&>(*massFrame_pod);
physx::PxVec3 returnValue = PxMassProperties::getMassSpaceInertia(inertia, massFrame);
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMat33_Pod PxMassProperties_translateInertia_mut(physx_PxMat33_Pod const* inertia_pod, float mass, physx_PxVec3_Pod const* t_pod) {
physx::PxMat33 const& inertia = reinterpret_cast<physx::PxMat33 const&>(*inertia_pod);
physx::PxVec3 const& t = reinterpret_cast<physx::PxVec3 const&>(*t_pod);
physx::PxMat33 returnValue = PxMassProperties::translateInertia(inertia, mass, t);
physx_PxMat33_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMat33_Pod PxMassProperties_rotateInertia_mut(physx_PxMat33_Pod const* inertia_pod, physx_PxQuat_Pod const* q_pod) {
physx::PxMat33 const& inertia = reinterpret_cast<physx::PxMat33 const&>(*inertia_pod);
physx::PxQuat const& q = reinterpret_cast<physx::PxQuat const&>(*q_pod);
physx::PxMat33 returnValue = PxMassProperties::rotateInertia(inertia, q);
physx_PxMat33_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMat33_Pod PxMassProperties_scaleInertia_mut(physx_PxMat33_Pod const* inertia_pod, physx_PxQuat_Pod const* scaleRotation_pod, physx_PxVec3_Pod const* scale_pod) {
physx::PxMat33 const& inertia = reinterpret_cast<physx::PxMat33 const&>(*inertia_pod);
physx::PxQuat const& scaleRotation = reinterpret_cast<physx::PxQuat const&>(*scaleRotation_pod);
physx::PxVec3 const& scale = reinterpret_cast<physx::PxVec3 const&>(*scale_pod);
physx::PxMat33 returnValue = PxMassProperties::scaleInertia(inertia, scaleRotation, scale);
physx_PxMat33_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMassProperties_Pod PxMassProperties_sum_mut(physx_PxMassProperties_Pod const* props_pod, physx_PxTransform_Pod const* transforms_pod, uint32_t count) {
physx::PxMassProperties const* props = reinterpret_cast<physx::PxMassProperties const*>(props_pod);
physx::PxTransform const* transforms = reinterpret_cast<physx::PxTransform const*>(transforms_pod);
physx::PxMassProperties returnValue = PxMassProperties::sum(props, transforms, count);
physx_PxMassProperties_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxRigidBodyExt_updateMassAndInertia_mut(physx_PxRigidBody_Pod* body_pod, float const* shapeDensities, uint32_t shapeDensityCount, physx_PxVec3_Pod const* massLocalPose_pod, bool includeNonSimShapes) {
physx::PxRigidBody& body = reinterpret_cast<physx::PxRigidBody&>(*body_pod);
physx::PxVec3 const* massLocalPose = reinterpret_cast<physx::PxVec3 const*>(massLocalPose_pod);
bool returnValue = PxRigidBodyExt::updateMassAndInertia(body, shapeDensities, shapeDensityCount, massLocalPose, includeNonSimShapes);
return returnValue;
}

bool PxRigidBodyExt_updateMassAndInertia_mut_1(physx_PxRigidBody_Pod* body_pod, float density, physx_PxVec3_Pod const* massLocalPose_pod, bool includeNonSimShapes) {
physx::PxRigidBody& body = reinterpret_cast<physx::PxRigidBody&>(*body_pod);
physx::PxVec3 const* massLocalPose = reinterpret_cast<physx::PxVec3 const*>(massLocalPose_pod);
bool returnValue = PxRigidBodyExt::updateMassAndInertia(body, density, massLocalPose, includeNonSimShapes);
return returnValue;
}

bool PxRigidBodyExt_setMassAndUpdateInertia_mut(physx_PxRigidBody_Pod* body_pod, float const* shapeMasses, uint32_t shapeMassCount, physx_PxVec3_Pod const* massLocalPose_pod, bool includeNonSimShapes) {
physx::PxRigidBody& body = reinterpret_cast<physx::PxRigidBody&>(*body_pod);
physx::PxVec3 const* massLocalPose = reinterpret_cast<physx::PxVec3 const*>(massLocalPose_pod);
bool returnValue = PxRigidBodyExt::setMassAndUpdateInertia(body, shapeMasses, shapeMassCount, massLocalPose, includeNonSimShapes);
return returnValue;
}

bool PxRigidBodyExt_setMassAndUpdateInertia_mut_1(physx_PxRigidBody_Pod* body_pod, float mass, physx_PxVec3_Pod const* massLocalPose_pod, bool includeNonSimShapes) {
physx::PxRigidBody& body = reinterpret_cast<physx::PxRigidBody&>(*body_pod);
physx::PxVec3 const* massLocalPose = reinterpret_cast<physx::PxVec3 const*>(massLocalPose_pod);
bool returnValue = PxRigidBodyExt::setMassAndUpdateInertia(body, mass, massLocalPose, includeNonSimShapes);
return returnValue;
}

physx_PxMassProperties_Pod PxRigidBodyExt_computeMassPropertiesFromShapes_mut(physx_PxShape_Pod const* const* shapes_pod, uint32_t shapeCount) {
physx::PxShape const* const* shapes = reinterpret_cast<physx::PxShape const* const*>(shapes_pod);
physx::PxMassProperties returnValue = PxRigidBodyExt::computeMassPropertiesFromShapes(shapes, shapeCount);
physx_PxMassProperties_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxRigidBodyExt_addForceAtPos_mut(physx_PxRigidBody_Pod* body_pod, physx_PxVec3_Pod const* force_pod, physx_PxVec3_Pod const* pos_pod, unsigned int mode_pod, bool wakeup) {
physx::PxRigidBody& body = reinterpret_cast<physx::PxRigidBody&>(*body_pod);
physx::PxVec3 const& force = reinterpret_cast<physx::PxVec3 const&>(*force_pod);
physx::PxVec3 const& pos = reinterpret_cast<physx::PxVec3 const&>(*pos_pod);
PxForceMode::Enum mode = (PxForceMode::Enum)mode_pod;
PxRigidBodyExt::addForceAtPos(body, force, pos, mode, wakeup);
}

void PxRigidBodyExt_addForceAtLocalPos_mut(physx_PxRigidBody_Pod* body_pod, physx_PxVec3_Pod const* force_pod, physx_PxVec3_Pod const* pos_pod, unsigned int mode_pod, bool wakeup) {
physx::PxRigidBody& body = reinterpret_cast<physx::PxRigidBody&>(*body_pod);
physx::PxVec3 const& force = reinterpret_cast<physx::PxVec3 const&>(*force_pod);
physx::PxVec3 const& pos = reinterpret_cast<physx::PxVec3 const&>(*pos_pod);
PxForceMode::Enum mode = (PxForceMode::Enum)mode_pod;
PxRigidBodyExt::addForceAtLocalPos(body, force, pos, mode, wakeup);
}

void PxRigidBodyExt_addLocalForceAtPos_mut(physx_PxRigidBody_Pod* body_pod, physx_PxVec3_Pod const* force_pod, physx_PxVec3_Pod const* pos_pod, unsigned int mode_pod, bool wakeup) {
physx::PxRigidBody& body = reinterpret_cast<physx::PxRigidBody&>(*body_pod);
physx::PxVec3 const& force = reinterpret_cast<physx::PxVec3 const&>(*force_pod);
physx::PxVec3 const& pos = reinterpret_cast<physx::PxVec3 const&>(*pos_pod);
PxForceMode::Enum mode = (PxForceMode::Enum)mode_pod;
PxRigidBodyExt::addLocalForceAtPos(body, force, pos, mode, wakeup);
}

void PxRigidBodyExt_addLocalForceAtLocalPos_mut(physx_PxRigidBody_Pod* body_pod, physx_PxVec3_Pod const* force_pod, physx_PxVec3_Pod const* pos_pod, unsigned int mode_pod, bool wakeup) {
physx::PxRigidBody& body = reinterpret_cast<physx::PxRigidBody&>(*body_pod);
physx::PxVec3 const& force = reinterpret_cast<physx::PxVec3 const&>(*force_pod);
physx::PxVec3 const& pos = reinterpret_cast<physx::PxVec3 const&>(*pos_pod);
PxForceMode::Enum mode = (PxForceMode::Enum)mode_pod;
PxRigidBodyExt::addLocalForceAtLocalPos(body, force, pos, mode, wakeup);
}

physx_PxVec3_Pod PxRigidBodyExt_getVelocityAtPos_mut(physx_PxRigidBody_Pod const* body_pod, physx_PxVec3_Pod const* pos_pod) {
physx::PxRigidBody const& body = reinterpret_cast<physx::PxRigidBody const&>(*body_pod);
physx::PxVec3 const& pos = reinterpret_cast<physx::PxVec3 const&>(*pos_pod);
physx::PxVec3 returnValue = PxRigidBodyExt::getVelocityAtPos(body, pos);
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxRigidBodyExt_getLocalVelocityAtLocalPos_mut(physx_PxRigidBody_Pod const* body_pod, physx_PxVec3_Pod const* pos_pod) {
physx::PxRigidBody const& body = reinterpret_cast<physx::PxRigidBody const&>(*body_pod);
physx::PxVec3 const& pos = reinterpret_cast<physx::PxVec3 const&>(*pos_pod);
physx::PxVec3 returnValue = PxRigidBodyExt::getLocalVelocityAtLocalPos(body, pos);
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVec3_Pod PxRigidBodyExt_getVelocityAtOffset_mut(physx_PxRigidBody_Pod const* body_pod, physx_PxVec3_Pod const* pos_pod) {
physx::PxRigidBody const& body = reinterpret_cast<physx::PxRigidBody const&>(*body_pod);
physx::PxVec3 const& pos = reinterpret_cast<physx::PxVec3 const&>(*pos_pod);
physx::PxVec3 returnValue = PxRigidBodyExt::getVelocityAtOffset(body, pos);
physx_PxVec3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxRigidBodyExt_linearSweepSingle_mut(physx_PxRigidBody_Pod* body_pod, physx_PxScene_Pod* scene_pod, physx_PxVec3_Pod const* unitDir_pod, float distance, physx_PxHitFlags_Pod outputFlags_pod, physx_PxSweepHit_Pod* closestHit_pod, uint32_t* shapeIndex_pod, physx_PxQueryFilterData_Pod const* filterData_pod, physx_PxQueryFilterCallback_Pod* filterCall_pod, physx_PxQueryCache_Pod const* cache_pod, float inflation) {
physx::PxRigidBody& body = reinterpret_cast<physx::PxRigidBody&>(*body_pod);
physx::PxScene& scene = reinterpret_cast<physx::PxScene&>(*scene_pod);
physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
physx::PxHitFlags outputFlags;
memcpy(&outputFlags, &outputFlags_pod, sizeof(outputFlags));
physx::PxSweepHit& closestHit = reinterpret_cast<physx::PxSweepHit&>(*closestHit_pod);
uint32_t& shapeIndex = *shapeIndex_pod;
physx::PxQueryFilterData const& filterData = reinterpret_cast<physx::PxQueryFilterData const&>(*filterData_pod);
physx::PxQueryFilterCallback* filterCall = reinterpret_cast<physx::PxQueryFilterCallback*>(filterCall_pod);
physx::PxQueryCache const* cache = reinterpret_cast<physx::PxQueryCache const*>(cache_pod);
bool returnValue = PxRigidBodyExt::linearSweepSingle(body, scene, unitDir, distance, outputFlags, closestHit, shapeIndex, filterData, filterCall, cache, inflation);
return returnValue;
}

uint32_t PxRigidBodyExt_linearSweepMultiple_mut(physx_PxRigidBody_Pod* body_pod, physx_PxScene_Pod* scene_pod, physx_PxVec3_Pod const* unitDir_pod, float distance, physx_PxHitFlags_Pod outputFlags_pod, physx_PxSweepHit_Pod* touchHitBuffer_pod, uint32_t* touchHitShapeIndices, uint32_t touchHitBufferSize, physx_PxSweepHit_Pod* block_pod, int32_t* blockingShapeIndex_pod, bool* overflow_pod, physx_PxQueryFilterData_Pod const* filterData_pod, physx_PxQueryFilterCallback_Pod* filterCall_pod, physx_PxQueryCache_Pod const* cache_pod, float inflation) {
physx::PxRigidBody& body = reinterpret_cast<physx::PxRigidBody&>(*body_pod);
physx::PxScene& scene = reinterpret_cast<physx::PxScene&>(*scene_pod);
physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
physx::PxHitFlags outputFlags;
memcpy(&outputFlags, &outputFlags_pod, sizeof(outputFlags));
physx::PxSweepHit* touchHitBuffer = reinterpret_cast<physx::PxSweepHit*>(touchHitBuffer_pod);
physx::PxSweepHit& block = reinterpret_cast<physx::PxSweepHit&>(*block_pod);
int32_t& blockingShapeIndex = *blockingShapeIndex_pod;
bool& overflow = *overflow_pod;
physx::PxQueryFilterData const& filterData = reinterpret_cast<physx::PxQueryFilterData const&>(*filterData_pod);
physx::PxQueryFilterCallback* filterCall = reinterpret_cast<physx::PxQueryFilterCallback*>(filterCall_pod);
physx::PxQueryCache const* cache = reinterpret_cast<physx::PxQueryCache const*>(cache_pod);
uint32_t returnValue = PxRigidBodyExt::linearSweepMultiple(body, scene, unitDir, distance, outputFlags, touchHitBuffer, touchHitShapeIndices, touchHitBufferSize, block, blockingShapeIndex, overflow, filterData, filterCall, cache, inflation);
return returnValue;
}

void PxRigidBodyExt_computeVelocityDeltaFromImpulse_mut(physx_PxRigidBody_Pod const* body_pod, physx_PxVec3_Pod const* impulsiveForce_pod, physx_PxVec3_Pod const* impulsiveTorque_pod, physx_PxVec3_Pod* deltaLinearVelocity_pod, physx_PxVec3_Pod* deltaAngularVelocity_pod) {
physx::PxRigidBody const& body = reinterpret_cast<physx::PxRigidBody const&>(*body_pod);
physx::PxVec3 const& impulsiveForce = reinterpret_cast<physx::PxVec3 const&>(*impulsiveForce_pod);
physx::PxVec3 const& impulsiveTorque = reinterpret_cast<physx::PxVec3 const&>(*impulsiveTorque_pod);
physx::PxVec3& deltaLinearVelocity = reinterpret_cast<physx::PxVec3&>(*deltaLinearVelocity_pod);
physx::PxVec3& deltaAngularVelocity = reinterpret_cast<physx::PxVec3&>(*deltaAngularVelocity_pod);
PxRigidBodyExt::computeVelocityDeltaFromImpulse(body, impulsiveForce, impulsiveTorque, deltaLinearVelocity, deltaAngularVelocity);
}

void PxRigidBodyExt_computeVelocityDeltaFromImpulse_mut_1(physx_PxRigidBody_Pod const* body_pod, physx_PxTransform_Pod const* globalPose_pod, physx_PxVec3_Pod const* point_pod, physx_PxVec3_Pod const* impulse_pod, float invMassScale, float invInertiaScale, physx_PxVec3_Pod* deltaLinearVelocity_pod, physx_PxVec3_Pod* deltaAngularVelocity_pod) {
physx::PxRigidBody const& body = reinterpret_cast<physx::PxRigidBody const&>(*body_pod);
physx::PxTransform const& globalPose = reinterpret_cast<physx::PxTransform const&>(*globalPose_pod);
physx::PxVec3 const& point = reinterpret_cast<physx::PxVec3 const&>(*point_pod);
physx::PxVec3 const& impulse = reinterpret_cast<physx::PxVec3 const&>(*impulse_pod);
physx::PxVec3& deltaLinearVelocity = reinterpret_cast<physx::PxVec3&>(*deltaLinearVelocity_pod);
physx::PxVec3& deltaAngularVelocity = reinterpret_cast<physx::PxVec3&>(*deltaAngularVelocity_pod);
PxRigidBodyExt::computeVelocityDeltaFromImpulse(body, globalPose, point, impulse, invMassScale, invInertiaScale, deltaLinearVelocity, deltaAngularVelocity);
}

void PxRigidBodyExt_computeLinearAngularImpulse_mut(physx_PxRigidBody_Pod const* body_pod, physx_PxTransform_Pod const* globalPose_pod, physx_PxVec3_Pod const* point_pod, physx_PxVec3_Pod const* impulse_pod, float invMassScale, float invInertiaScale, physx_PxVec3_Pod* linearImpulse_pod, physx_PxVec3_Pod* angularImpulse_pod) {
physx::PxRigidBody const& body = reinterpret_cast<physx::PxRigidBody const&>(*body_pod);
physx::PxTransform const& globalPose = reinterpret_cast<physx::PxTransform const&>(*globalPose_pod);
physx::PxVec3 const& point = reinterpret_cast<physx::PxVec3 const&>(*point_pod);
physx::PxVec3 const& impulse = reinterpret_cast<physx::PxVec3 const&>(*impulse_pod);
physx::PxVec3& linearImpulse = reinterpret_cast<physx::PxVec3&>(*linearImpulse_pod);
physx::PxVec3& angularImpulse = reinterpret_cast<physx::PxVec3&>(*angularImpulse_pod);
PxRigidBodyExt::computeLinearAngularImpulse(body, globalPose, point, impulse, invMassScale, invInertiaScale, linearImpulse, angularImpulse);
}

physx_PxTransform_Pod PxShapeExt_getGlobalPose_mut(physx_PxShape_Pod const* shape_pod, physx_PxRigidActor_Pod const* actor_pod) {
physx::PxShape const& shape = reinterpret_cast<physx::PxShape const&>(*shape_pod);
physx::PxRigidActor const& actor = reinterpret_cast<physx::PxRigidActor const&>(*actor_pod);
physx::PxTransform returnValue = PxShapeExt::getGlobalPose(shape, actor);
physx_PxTransform_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

uint32_t PxShapeExt_raycast_mut(physx_PxShape_Pod const* shape_pod, physx_PxRigidActor_Pod const* actor_pod, physx_PxVec3_Pod const* rayOrigin_pod, physx_PxVec3_Pod const* rayDir_pod, float maxDist, physx_PxHitFlags_Pod hitFlags_pod, uint32_t maxHits, physx_PxRaycastHit_Pod* rayHits_pod) {
physx::PxShape const& shape = reinterpret_cast<physx::PxShape const&>(*shape_pod);
physx::PxRigidActor const& actor = reinterpret_cast<physx::PxRigidActor const&>(*actor_pod);
physx::PxVec3 const& rayOrigin = reinterpret_cast<physx::PxVec3 const&>(*rayOrigin_pod);
physx::PxVec3 const& rayDir = reinterpret_cast<physx::PxVec3 const&>(*rayDir_pod);
physx::PxHitFlags hitFlags;
memcpy(&hitFlags, &hitFlags_pod, sizeof(hitFlags));
physx::PxRaycastHit* rayHits = reinterpret_cast<physx::PxRaycastHit*>(rayHits_pod);
uint32_t returnValue = PxShapeExt::raycast(shape, actor, rayOrigin, rayDir, maxDist, hitFlags, maxHits, rayHits);
return returnValue;
}

bool PxShapeExt_overlap_mut(physx_PxShape_Pod const* shape_pod, physx_PxRigidActor_Pod const* actor_pod, physx_PxGeometry_Pod const* otherGeom_pod, physx_PxTransform_Pod const* otherGeomPose_pod) {
physx::PxShape const& shape = reinterpret_cast<physx::PxShape const&>(*shape_pod);
physx::PxRigidActor const& actor = reinterpret_cast<physx::PxRigidActor const&>(*actor_pod);
physx::PxGeometry const& otherGeom = reinterpret_cast<physx::PxGeometry const&>(*otherGeom_pod);
physx::PxTransform const& otherGeomPose = reinterpret_cast<physx::PxTransform const&>(*otherGeomPose_pod);
bool returnValue = PxShapeExt::overlap(shape, actor, otherGeom, otherGeomPose);
return returnValue;
}

bool PxShapeExt_sweep_mut(physx_PxShape_Pod const* shape_pod, physx_PxRigidActor_Pod const* actor_pod, physx_PxVec3_Pod const* unitDir_pod, float distance, physx_PxGeometry_Pod const* otherGeom_pod, physx_PxTransform_Pod const* otherGeomPose_pod, physx_PxSweepHit_Pod* sweepHit_pod, physx_PxHitFlags_Pod hitFlags_pod) {
physx::PxShape const& shape = reinterpret_cast<physx::PxShape const&>(*shape_pod);
physx::PxRigidActor const& actor = reinterpret_cast<physx::PxRigidActor const&>(*actor_pod);
physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
physx::PxGeometry const& otherGeom = reinterpret_cast<physx::PxGeometry const&>(*otherGeom_pod);
physx::PxTransform const& otherGeomPose = reinterpret_cast<physx::PxTransform const&>(*otherGeomPose_pod);
physx::PxSweepHit& sweepHit = reinterpret_cast<physx::PxSweepHit&>(*sweepHit_pod);
physx::PxHitFlags hitFlags;
memcpy(&hitFlags, &hitFlags_pod, sizeof(hitFlags));
bool returnValue = PxShapeExt::sweep(shape, actor, unitDir, distance, otherGeom, otherGeomPose, sweepHit, hitFlags);
return returnValue;
}

physx_PxBounds3_Pod PxShapeExt_getWorldBounds_mut(physx_PxShape_Pod const* shape_pod, physx_PxRigidActor_Pod const* actor_pod, float inflation) {
physx::PxShape const& shape = reinterpret_cast<physx::PxShape const&>(*shape_pod);
physx::PxRigidActor const& actor = reinterpret_cast<physx::PxRigidActor const&>(*actor_pod);
physx::PxBounds3 returnValue = PxShapeExt::getWorldBounds(shape, actor, inflation);
physx_PxBounds3_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxMeshOverlapUtil_Pod* PxMeshOverlapUtil_new_alloc() {
auto returnValue = new physx::PxMeshOverlapUtil();
physx_PxMeshOverlapUtil_Pod* returnValue_pod = reinterpret_cast<physx_PxMeshOverlapUtil_Pod*>(returnValue);
return returnValue_pod;
}

void PxMeshOverlapUtil_delete(physx_PxMeshOverlapUtil_Pod* self__pod) {
physx::PxMeshOverlapUtil* self_ = reinterpret_cast<physx::PxMeshOverlapUtil*>(self__pod);
delete self_;
}

uint32_t PxMeshOverlapUtil_findOverlap_mut(physx_PxMeshOverlapUtil_Pod* self__pod, physx_PxGeometry_Pod const* geom_pod, physx_PxTransform_Pod const* geomPose_pod, physx_PxTriangleMeshGeometry_Pod const* meshGeom_pod, physx_PxTransform_Pod const* meshPose_pod) {
physx::PxMeshOverlapUtil* self_ = reinterpret_cast<physx::PxMeshOverlapUtil*>(self__pod);
physx::PxGeometry const& geom = reinterpret_cast<physx::PxGeometry const&>(*geom_pod);
physx::PxTransform const& geomPose = reinterpret_cast<physx::PxTransform const&>(*geomPose_pod);
physx::PxTriangleMeshGeometry const& meshGeom = reinterpret_cast<physx::PxTriangleMeshGeometry const&>(*meshGeom_pod);
physx::PxTransform const& meshPose = reinterpret_cast<physx::PxTransform const&>(*meshPose_pod);
uint32_t returnValue = self_->findOverlap(geom, geomPose, meshGeom, meshPose);
return returnValue;
}

uint32_t PxMeshOverlapUtil_findOverlap_mut_1(physx_PxMeshOverlapUtil_Pod* self__pod, physx_PxGeometry_Pod const* geom_pod, physx_PxTransform_Pod const* geomPose_pod, physx_PxHeightFieldGeometry_Pod const* hfGeom_pod, physx_PxTransform_Pod const* hfPose_pod) {
physx::PxMeshOverlapUtil* self_ = reinterpret_cast<physx::PxMeshOverlapUtil*>(self__pod);
physx::PxGeometry const& geom = reinterpret_cast<physx::PxGeometry const&>(*geom_pod);
physx::PxTransform const& geomPose = reinterpret_cast<physx::PxTransform const&>(*geomPose_pod);
physx::PxHeightFieldGeometry const& hfGeom = reinterpret_cast<physx::PxHeightFieldGeometry const&>(*hfGeom_pod);
physx::PxTransform const& hfPose = reinterpret_cast<physx::PxTransform const&>(*hfPose_pod);
uint32_t returnValue = self_->findOverlap(geom, geomPose, hfGeom, hfPose);
return returnValue;
}

uint32_t const* PxMeshOverlapUtil_getResults(physx_PxMeshOverlapUtil_Pod const* self__pod) {
physx::PxMeshOverlapUtil const* self_ = reinterpret_cast<physx::PxMeshOverlapUtil const*>(self__pod);
uint32_t const* returnValue = self_->getResults();
return returnValue;
}

uint32_t PxMeshOverlapUtil_getNbResults(physx_PxMeshOverlapUtil_Pod const* self__pod) {
physx::PxMeshOverlapUtil const* self_ = reinterpret_cast<physx::PxMeshOverlapUtil const*>(self__pod);
uint32_t returnValue = self_->getNbResults();
return returnValue;
}

bool phys_PxComputeTriangleMeshPenetration(physx_PxVec3_Pod* direction_pod, float* depth_pod, physx_PxGeometry_Pod const* geom_pod, physx_PxTransform_Pod const* geomPose_pod, physx_PxTriangleMeshGeometry_Pod const* meshGeom_pod, physx_PxTransform_Pod const* meshPose_pod, uint32_t maxIter, uint32_t* usedIter) {
physx::PxVec3& direction = reinterpret_cast<physx::PxVec3&>(*direction_pod);
float& depth = *depth_pod;
physx::PxGeometry const& geom = reinterpret_cast<physx::PxGeometry const&>(*geom_pod);
physx::PxTransform const& geomPose = reinterpret_cast<physx::PxTransform const&>(*geomPose_pod);
physx::PxTriangleMeshGeometry const& meshGeom = reinterpret_cast<physx::PxTriangleMeshGeometry const&>(*meshGeom_pod);
physx::PxTransform const& meshPose = reinterpret_cast<physx::PxTransform const&>(*meshPose_pod);
bool returnValue = PxComputeTriangleMeshPenetration(direction, depth, geom, geomPose, meshGeom, meshPose, maxIter, usedIter);
return returnValue;
}

bool phys_PxComputeHeightFieldPenetration(physx_PxVec3_Pod* direction_pod, float* depth_pod, physx_PxGeometry_Pod const* geom_pod, physx_PxTransform_Pod const* geomPose_pod, physx_PxHeightFieldGeometry_Pod const* heightFieldGeom_pod, physx_PxTransform_Pod const* heightFieldPose_pod, uint32_t maxIter, uint32_t* usedIter) {
physx::PxVec3& direction = reinterpret_cast<physx::PxVec3&>(*direction_pod);
float& depth = *depth_pod;
physx::PxGeometry const& geom = reinterpret_cast<physx::PxGeometry const&>(*geom_pod);
physx::PxTransform const& geomPose = reinterpret_cast<physx::PxTransform const&>(*geomPose_pod);
physx::PxHeightFieldGeometry const& heightFieldGeom = reinterpret_cast<physx::PxHeightFieldGeometry const&>(*heightFieldGeom_pod);
physx::PxTransform const& heightFieldPose = reinterpret_cast<physx::PxTransform const&>(*heightFieldPose_pod);
bool returnValue = PxComputeHeightFieldPenetration(direction, depth, geom, geomPose, heightFieldGeom, heightFieldPose, maxIter, usedIter);
return returnValue;
}

physx_PxSerialization_PxXmlMiscParameter_Pod PxXmlMiscParameter_new() {
physx::PxSerialization::PxXmlMiscParameter returnValue;
physx_PxSerialization_PxXmlMiscParameter_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxSerialization_PxXmlMiscParameter_Pod PxXmlMiscParameter_new_1(physx_PxVec3_Pod* inUpVector_pod, physx_PxTolerancesScale_Pod inScale_pod) {
physx::PxVec3& inUpVector = reinterpret_cast<physx::PxVec3&>(*inUpVector_pod);
physx::PxTolerancesScale inScale;
memcpy(&inScale, &inScale_pod, sizeof(inScale));
physx::PxSerialization::PxXmlMiscParameter returnValue(inUpVector, inScale);
physx_PxSerialization_PxXmlMiscParameter_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxSerialization_isSerializable_mut(physx_PxCollection_Pod* collection_pod, physx_PxSerializationRegistry_Pod* sr_pod, physx_PxCollection_Pod const* externalReferences_pod) {
physx::PxCollection& collection = reinterpret_cast<physx::PxCollection&>(*collection_pod);
physx::PxSerializationRegistry& sr = reinterpret_cast<physx::PxSerializationRegistry&>(*sr_pod);
physx::PxCollection const* externalReferences = reinterpret_cast<physx::PxCollection const*>(externalReferences_pod);
bool returnValue = PxSerialization::isSerializable(collection, sr, externalReferences);
return returnValue;
}

void PxSerialization_complete_mut(physx_PxCollection_Pod* collection_pod, physx_PxSerializationRegistry_Pod* sr_pod, physx_PxCollection_Pod const* exceptFor_pod, bool followJoints) {
physx::PxCollection& collection = reinterpret_cast<physx::PxCollection&>(*collection_pod);
physx::PxSerializationRegistry& sr = reinterpret_cast<physx::PxSerializationRegistry&>(*sr_pod);
physx::PxCollection const* exceptFor = reinterpret_cast<physx::PxCollection const*>(exceptFor_pod);
PxSerialization::complete(collection, sr, exceptFor, followJoints);
}

void PxSerialization_createSerialObjectIds_mut(physx_PxCollection_Pod* collection_pod, uint64_t base) {
physx::PxCollection& collection = reinterpret_cast<physx::PxCollection&>(*collection_pod);
PxSerialization::createSerialObjectIds(collection, base);
}

physx_PxCollection_Pod* PxSerialization_createCollectionFromXml_mut(physx_PxInputData_Pod* inputData_pod, physx_PxCooking_Pod* cooking_pod, physx_PxSerializationRegistry_Pod* sr_pod, physx_PxCollection_Pod const* externalRefs_pod, physx_PxStringTable_Pod* stringTable_pod, physx_PxSerialization_PxXmlMiscParameter_Pod* outArgs_pod) {
physx::PxInputData& inputData = reinterpret_cast<physx::PxInputData&>(*inputData_pod);
physx::PxCooking& cooking = reinterpret_cast<physx::PxCooking&>(*cooking_pod);
physx::PxSerializationRegistry& sr = reinterpret_cast<physx::PxSerializationRegistry&>(*sr_pod);
physx::PxCollection const* externalRefs = reinterpret_cast<physx::PxCollection const*>(externalRefs_pod);
physx::PxStringTable* stringTable = reinterpret_cast<physx::PxStringTable*>(stringTable_pod);
physx::PxSerialization::PxXmlMiscParameter* outArgs = reinterpret_cast<physx::PxSerialization::PxXmlMiscParameter*>(outArgs_pod);
physx::PxCollection* returnValue = PxSerialization::createCollectionFromXml(inputData, cooking, sr, externalRefs, stringTable, outArgs);
physx_PxCollection_Pod* returnValue_pod = reinterpret_cast<physx_PxCollection_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxCollection_Pod* PxSerialization_createCollectionFromBinary_mut(void* memBlock, physx_PxSerializationRegistry_Pod* sr_pod, physx_PxCollection_Pod const* externalRefs_pod) {
physx::PxSerializationRegistry& sr = reinterpret_cast<physx::PxSerializationRegistry&>(*sr_pod);
physx::PxCollection const* externalRefs = reinterpret_cast<physx::PxCollection const*>(externalRefs_pod);
physx::PxCollection* returnValue = PxSerialization::createCollectionFromBinary(memBlock, sr, externalRefs);
physx_PxCollection_Pod* returnValue_pod = reinterpret_cast<physx_PxCollection_Pod*>(returnValue);
return returnValue_pod;
}

bool PxSerialization_serializeCollectionToXml_mut(physx_PxOutputStream_Pod* outputStream_pod, physx_PxCollection_Pod* collection_pod, physx_PxSerializationRegistry_Pod* sr_pod, physx_PxCooking_Pod* cooking_pod, physx_PxCollection_Pod const* externalRefs_pod, physx_PxSerialization_PxXmlMiscParameter_Pod* inArgs_pod) {
physx::PxOutputStream& outputStream = reinterpret_cast<physx::PxOutputStream&>(*outputStream_pod);
physx::PxCollection& collection = reinterpret_cast<physx::PxCollection&>(*collection_pod);
physx::PxSerializationRegistry& sr = reinterpret_cast<physx::PxSerializationRegistry&>(*sr_pod);
physx::PxCooking* cooking = reinterpret_cast<physx::PxCooking*>(cooking_pod);
physx::PxCollection const* externalRefs = reinterpret_cast<physx::PxCollection const*>(externalRefs_pod);
physx::PxSerialization::PxXmlMiscParameter* inArgs = reinterpret_cast<physx::PxSerialization::PxXmlMiscParameter*>(inArgs_pod);
bool returnValue = PxSerialization::serializeCollectionToXml(outputStream, collection, sr, cooking, externalRefs, inArgs);
return returnValue;
}

bool PxSerialization_serializeCollectionToBinary_mut(physx_PxOutputStream_Pod* outputStream_pod, physx_PxCollection_Pod* collection_pod, physx_PxSerializationRegistry_Pod* sr_pod, physx_PxCollection_Pod const* externalRefs_pod, bool exportNames) {
physx::PxOutputStream& outputStream = reinterpret_cast<physx::PxOutputStream&>(*outputStream_pod);
physx::PxCollection& collection = reinterpret_cast<physx::PxCollection&>(*collection_pod);
physx::PxSerializationRegistry& sr = reinterpret_cast<physx::PxSerializationRegistry&>(*sr_pod);
physx::PxCollection const* externalRefs = reinterpret_cast<physx::PxCollection const*>(externalRefs_pod);
bool returnValue = PxSerialization::serializeCollectionToBinary(outputStream, collection, sr, externalRefs, exportNames);
return returnValue;
}

bool PxSerialization_serializeCollectionToBinaryDeterministic_mut(physx_PxOutputStream_Pod* outputStream_pod, physx_PxCollection_Pod* collection_pod, physx_PxSerializationRegistry_Pod* sr_pod, physx_PxCollection_Pod const* externalRefs_pod, bool exportNames) {
physx::PxOutputStream& outputStream = reinterpret_cast<physx::PxOutputStream&>(*outputStream_pod);
physx::PxCollection& collection = reinterpret_cast<physx::PxCollection&>(*collection_pod);
physx::PxSerializationRegistry& sr = reinterpret_cast<physx::PxSerializationRegistry&>(*sr_pod);
physx::PxCollection const* externalRefs = reinterpret_cast<physx::PxCollection const*>(externalRefs_pod);
bool returnValue = PxSerialization::serializeCollectionToBinaryDeterministic(outputStream, collection, sr, externalRefs, exportNames);
return returnValue;
}

void PxSerialization_dumpBinaryMetaData_mut(physx_PxOutputStream_Pod* outputStream_pod, physx_PxSerializationRegistry_Pod* sr_pod) {
physx::PxOutputStream& outputStream = reinterpret_cast<physx::PxOutputStream&>(*outputStream_pod);
physx::PxSerializationRegistry& sr = reinterpret_cast<physx::PxSerializationRegistry&>(*sr_pod);
PxSerialization::dumpBinaryMetaData(outputStream, sr);
}

physx_PxBinaryConverter_Pod* PxSerialization_createBinaryConverter_mut() {
physx::PxBinaryConverter* returnValue = PxSerialization::createBinaryConverter();
physx_PxBinaryConverter_Pod* returnValue_pod = reinterpret_cast<physx_PxBinaryConverter_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxSerializationRegistry_Pod* PxSerialization_createSerializationRegistry_mut(physx_PxPhysics_Pod* physics_pod) {
physx::PxPhysics& physics = reinterpret_cast<physx::PxPhysics&>(*physics_pod);
physx::PxSerializationRegistry* returnValue = PxSerialization::createSerializationRegistry(physics);
physx_PxSerializationRegistry_Pod* returnValue_pod = reinterpret_cast<physx_PxSerializationRegistry_Pod*>(returnValue);
return returnValue_pod;
}

void PxDefaultCpuDispatcher_release_mut(physx_PxDefaultCpuDispatcher_Pod* self__pod) {
physx::PxDefaultCpuDispatcher* self_ = reinterpret_cast<physx::PxDefaultCpuDispatcher*>(self__pod);
self_->release();
}

void PxDefaultCpuDispatcher_setRunProfiled_mut(physx_PxDefaultCpuDispatcher_Pod* self__pod, bool runProfiled) {
physx::PxDefaultCpuDispatcher* self_ = reinterpret_cast<physx::PxDefaultCpuDispatcher*>(self__pod);
self_->setRunProfiled(runProfiled);
}

bool PxDefaultCpuDispatcher_getRunProfiled(physx_PxDefaultCpuDispatcher_Pod const* self__pod) {
physx::PxDefaultCpuDispatcher const* self_ = reinterpret_cast<physx::PxDefaultCpuDispatcher const*>(self__pod);
bool returnValue = self_->getRunProfiled();
return returnValue;
}

physx_PxDefaultCpuDispatcher_Pod* phys_PxDefaultCpuDispatcherCreate(uint32_t numThreads, uint32_t* affinityMasks) {
physx::PxDefaultCpuDispatcher* returnValue = PxDefaultCpuDispatcherCreate(numThreads, affinityMasks);
physx_PxDefaultCpuDispatcher_Pod* returnValue_pod = reinterpret_cast<physx_PxDefaultCpuDispatcher_Pod*>(returnValue);
return returnValue_pod;
}

bool phys_PxBuildSmoothNormals(uint32_t nbTris, uint32_t nbVerts, physx_PxVec3_Pod const* verts_pod, uint32_t const* dFaces, uint16_t const* wFaces, physx_PxVec3_Pod* normals_pod, bool flip) {
physx::PxVec3 const* verts = reinterpret_cast<physx::PxVec3 const*>(verts_pod);
physx::PxVec3* normals = reinterpret_cast<physx::PxVec3*>(normals_pod);
bool returnValue = PxBuildSmoothNormals(nbTris, nbVerts, verts, dFaces, wFaces, normals, flip);
return returnValue;
}

physx_PxRigidDynamic_Pod* phys_PxCreateDynamic(physx_PxPhysics_Pod* sdk_pod, physx_PxTransform_Pod const* transform_pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxMaterial_Pod* material_pod, float density, physx_PxTransform_Pod const* shapeOffset_pod) {
physx::PxPhysics& sdk = reinterpret_cast<physx::PxPhysics&>(*sdk_pod);
physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
physx::PxMaterial& material = reinterpret_cast<physx::PxMaterial&>(*material_pod);
physx::PxTransform const& shapeOffset = reinterpret_cast<physx::PxTransform const&>(*shapeOffset_pod);
physx::PxRigidDynamic* returnValue = PxCreateDynamic(sdk, transform, geometry, material, density, shapeOffset);
physx_PxRigidDynamic_Pod* returnValue_pod = reinterpret_cast<physx_PxRigidDynamic_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxRigidDynamic_Pod* phys_PxCreateDynamic_1(physx_PxPhysics_Pod* sdk_pod, physx_PxTransform_Pod const* transform_pod, physx_PxShape_Pod* shape_pod, float density) {
physx::PxPhysics& sdk = reinterpret_cast<physx::PxPhysics&>(*sdk_pod);
physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
physx::PxShape& shape = reinterpret_cast<physx::PxShape&>(*shape_pod);
physx::PxRigidDynamic* returnValue = PxCreateDynamic(sdk, transform, shape, density);
physx_PxRigidDynamic_Pod* returnValue_pod = reinterpret_cast<physx_PxRigidDynamic_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxRigidDynamic_Pod* phys_PxCreateKinematic(physx_PxPhysics_Pod* sdk_pod, physx_PxTransform_Pod const* transform_pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxMaterial_Pod* material_pod, float density, physx_PxTransform_Pod const* shapeOffset_pod) {
physx::PxPhysics& sdk = reinterpret_cast<physx::PxPhysics&>(*sdk_pod);
physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
physx::PxMaterial& material = reinterpret_cast<physx::PxMaterial&>(*material_pod);
physx::PxTransform const& shapeOffset = reinterpret_cast<physx::PxTransform const&>(*shapeOffset_pod);
physx::PxRigidDynamic* returnValue = PxCreateKinematic(sdk, transform, geometry, material, density, shapeOffset);
physx_PxRigidDynamic_Pod* returnValue_pod = reinterpret_cast<physx_PxRigidDynamic_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxRigidDynamic_Pod* phys_PxCreateKinematic_1(physx_PxPhysics_Pod* sdk_pod, physx_PxTransform_Pod const* transform_pod, physx_PxShape_Pod* shape_pod, float density) {
physx::PxPhysics& sdk = reinterpret_cast<physx::PxPhysics&>(*sdk_pod);
physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
physx::PxShape& shape = reinterpret_cast<physx::PxShape&>(*shape_pod);
physx::PxRigidDynamic* returnValue = PxCreateKinematic(sdk, transform, shape, density);
physx_PxRigidDynamic_Pod* returnValue_pod = reinterpret_cast<physx_PxRigidDynamic_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxRigidStatic_Pod* phys_PxCreateStatic(physx_PxPhysics_Pod* sdk_pod, physx_PxTransform_Pod const* transform_pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxMaterial_Pod* material_pod, physx_PxTransform_Pod const* shapeOffset_pod) {
physx::PxPhysics& sdk = reinterpret_cast<physx::PxPhysics&>(*sdk_pod);
physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
physx::PxMaterial& material = reinterpret_cast<physx::PxMaterial&>(*material_pod);
physx::PxTransform const& shapeOffset = reinterpret_cast<physx::PxTransform const&>(*shapeOffset_pod);
physx::PxRigidStatic* returnValue = PxCreateStatic(sdk, transform, geometry, material, shapeOffset);
physx_PxRigidStatic_Pod* returnValue_pod = reinterpret_cast<physx_PxRigidStatic_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxRigidStatic_Pod* phys_PxCreateStatic_1(physx_PxPhysics_Pod* sdk_pod, physx_PxTransform_Pod const* transform_pod, physx_PxShape_Pod* shape_pod) {
physx::PxPhysics& sdk = reinterpret_cast<physx::PxPhysics&>(*sdk_pod);
physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
physx::PxShape& shape = reinterpret_cast<physx::PxShape&>(*shape_pod);
physx::PxRigidStatic* returnValue = PxCreateStatic(sdk, transform, shape);
physx_PxRigidStatic_Pod* returnValue_pod = reinterpret_cast<physx_PxRigidStatic_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxRigidStatic_Pod* phys_PxCreateStatic_2(physx_PxPhysics_Pod* sdk_pod, physx_PxTransform_Pod const* transform_pod, physx_PxShape_Pod* shape_pod) {
physx::PxPhysics& sdk = reinterpret_cast<physx::PxPhysics&>(*sdk_pod);
physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
physx::PxShape& shape = reinterpret_cast<physx::PxShape&>(*shape_pod);
physx::PxRigidStatic* returnValue = PxCreateStatic(sdk, transform, shape);
physx_PxRigidStatic_Pod* returnValue_pod = reinterpret_cast<physx_PxRigidStatic_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxShape_Pod* phys_PxCloneShape(physx_PxPhysics_Pod* physicsSDK_pod, physx_PxShape_Pod const* shape_pod, bool isExclusive) {
physx::PxPhysics& physicsSDK = reinterpret_cast<physx::PxPhysics&>(*physicsSDK_pod);
physx::PxShape const& shape = reinterpret_cast<physx::PxShape const&>(*shape_pod);
physx::PxShape* returnValue = PxCloneShape(physicsSDK, shape, isExclusive);
physx_PxShape_Pod* returnValue_pod = reinterpret_cast<physx_PxShape_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxRigidStatic_Pod* phys_PxCloneStatic(physx_PxPhysics_Pod* physicsSDK_pod, physx_PxTransform_Pod const* transform_pod, physx_PxRigidActor_Pod const* actor_pod) {
physx::PxPhysics& physicsSDK = reinterpret_cast<physx::PxPhysics&>(*physicsSDK_pod);
physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
physx::PxRigidActor const& actor = reinterpret_cast<physx::PxRigidActor const&>(*actor_pod);
physx::PxRigidStatic* returnValue = PxCloneStatic(physicsSDK, transform, actor);
physx_PxRigidStatic_Pod* returnValue_pod = reinterpret_cast<physx_PxRigidStatic_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxRigidDynamic_Pod* phys_PxCloneDynamic(physx_PxPhysics_Pod* physicsSDK_pod, physx_PxTransform_Pod const* transform_pod, physx_PxRigidDynamic_Pod const* body_pod) {
physx::PxPhysics& physicsSDK = reinterpret_cast<physx::PxPhysics&>(*physicsSDK_pod);
physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
physx::PxRigidDynamic const& body = reinterpret_cast<physx::PxRigidDynamic const&>(*body_pod);
physx::PxRigidDynamic* returnValue = PxCloneDynamic(physicsSDK, transform, body);
physx_PxRigidDynamic_Pod* returnValue_pod = reinterpret_cast<physx_PxRigidDynamic_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxRigidStatic_Pod* phys_PxCreatePlane(physx_PxPhysics_Pod* sdk_pod, physx_PxPlane_Pod const* plane_pod, physx_PxMaterial_Pod* material_pod) {
physx::PxPhysics& sdk = reinterpret_cast<physx::PxPhysics&>(*sdk_pod);
physx::PxPlane const& plane = reinterpret_cast<physx::PxPlane const&>(*plane_pod);
physx::PxMaterial& material = reinterpret_cast<physx::PxMaterial&>(*material_pod);
physx::PxRigidStatic* returnValue = PxCreatePlane(sdk, plane, material);
physx_PxRigidStatic_Pod* returnValue_pod = reinterpret_cast<physx_PxRigidStatic_Pod*>(returnValue);
return returnValue_pod;
}

void phys_PxScaleRigidActor(physx_PxRigidActor_Pod* actor_pod, float scale, bool scaleMassProps) {
physx::PxRigidActor& actor = reinterpret_cast<physx::PxRigidActor&>(*actor_pod);
PxScaleRigidActor(actor, scale, scaleMassProps);
}

physx_PxStringTable_Pod* PxStringTableExt_createStringTable_mut(physx_PxAllocatorCallback_Pod* inAllocator_pod) {
physx::PxAllocatorCallback& inAllocator = reinterpret_cast<physx::PxAllocatorCallback&>(*inAllocator_pod);
physx::PxStringTable& returnValue = PxStringTableExt::createStringTable(inAllocator);
physx_PxStringTable_Pod* returnValue_pod = reinterpret_cast<physx_PxStringTable_Pod*>(&returnValue);
return returnValue_pod;
}

uint32_t PxBroadPhaseExt_createRegionsFromWorldBounds_mut(physx_PxBounds3_Pod* regions_pod, physx_PxBounds3_Pod const* globalBounds_pod, uint32_t nbSubdiv, uint32_t upAxis) {
physx::PxBounds3* regions = reinterpret_cast<physx::PxBounds3*>(regions_pod);
physx::PxBounds3 const& globalBounds = reinterpret_cast<physx::PxBounds3 const&>(*globalBounds_pod);
uint32_t returnValue = PxBroadPhaseExt::createRegionsFromWorldBounds(regions, globalBounds, nbSubdiv, upAxis);
return returnValue;
}

bool PxSceneQueryExt_raycastAny_mut(physx_PxScene_Pod const* scene_pod, physx_PxVec3_Pod const* origin_pod, physx_PxVec3_Pod const* unitDir_pod, float distance, physx_PxSceneQueryHit_Pod* hit_pod, physx_PxSceneQueryFilterData_Pod const* filterData_pod, physx_PxSceneQueryFilterCallback_Pod* filterCall_pod, physx_PxSceneQueryCache_Pod const* cache_pod) {
physx::PxScene const& scene = reinterpret_cast<physx::PxScene const&>(*scene_pod);
physx::PxVec3 const& origin = reinterpret_cast<physx::PxVec3 const&>(*origin_pod);
physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
physx::PxSceneQueryHit& hit = reinterpret_cast<physx::PxSceneQueryHit&>(*hit_pod);
physx::PxSceneQueryFilterData const& filterData = reinterpret_cast<physx::PxSceneQueryFilterData const&>(*filterData_pod);
physx::PxSceneQueryFilterCallback* filterCall = reinterpret_cast<physx::PxSceneQueryFilterCallback*>(filterCall_pod);
physx::PxSceneQueryCache const* cache = reinterpret_cast<physx::PxSceneQueryCache const*>(cache_pod);
bool returnValue = PxSceneQueryExt::raycastAny(scene, origin, unitDir, distance, hit, filterData, filterCall, cache);
return returnValue;
}

bool PxSceneQueryExt_raycastSingle_mut(physx_PxScene_Pod const* scene_pod, physx_PxVec3_Pod const* origin_pod, physx_PxVec3_Pod const* unitDir_pod, float distance, physx_PxSceneQueryFlags_Pod outputFlags_pod, physx_PxRaycastHit_Pod* hit_pod, physx_PxSceneQueryFilterData_Pod const* filterData_pod, physx_PxSceneQueryFilterCallback_Pod* filterCall_pod, physx_PxSceneQueryCache_Pod const* cache_pod) {
physx::PxScene const& scene = reinterpret_cast<physx::PxScene const&>(*scene_pod);
physx::PxVec3 const& origin = reinterpret_cast<physx::PxVec3 const&>(*origin_pod);
physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
physx::PxSceneQueryFlags outputFlags;
memcpy(&outputFlags, &outputFlags_pod, sizeof(outputFlags));
physx::PxRaycastHit& hit = reinterpret_cast<physx::PxRaycastHit&>(*hit_pod);
physx::PxSceneQueryFilterData const& filterData = reinterpret_cast<physx::PxSceneQueryFilterData const&>(*filterData_pod);
physx::PxSceneQueryFilterCallback* filterCall = reinterpret_cast<physx::PxSceneQueryFilterCallback*>(filterCall_pod);
physx::PxSceneQueryCache const* cache = reinterpret_cast<physx::PxSceneQueryCache const*>(cache_pod);
bool returnValue = PxSceneQueryExt::raycastSingle(scene, origin, unitDir, distance, outputFlags, hit, filterData, filterCall, cache);
return returnValue;
}

int32_t PxSceneQueryExt_raycastMultiple_mut(physx_PxScene_Pod const* scene_pod, physx_PxVec3_Pod const* origin_pod, physx_PxVec3_Pod const* unitDir_pod, float distance, physx_PxSceneQueryFlags_Pod outputFlags_pod, physx_PxRaycastHit_Pod* hitBuffer_pod, uint32_t hitBufferSize, bool* blockingHit_pod, physx_PxSceneQueryFilterData_Pod const* filterData_pod, physx_PxSceneQueryFilterCallback_Pod* filterCall_pod, physx_PxSceneQueryCache_Pod const* cache_pod) {
physx::PxScene const& scene = reinterpret_cast<physx::PxScene const&>(*scene_pod);
physx::PxVec3 const& origin = reinterpret_cast<physx::PxVec3 const&>(*origin_pod);
physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
physx::PxSceneQueryFlags outputFlags;
memcpy(&outputFlags, &outputFlags_pod, sizeof(outputFlags));
physx::PxRaycastHit* hitBuffer = reinterpret_cast<physx::PxRaycastHit*>(hitBuffer_pod);
bool& blockingHit = *blockingHit_pod;
physx::PxSceneQueryFilterData const& filterData = reinterpret_cast<physx::PxSceneQueryFilterData const&>(*filterData_pod);
physx::PxSceneQueryFilterCallback* filterCall = reinterpret_cast<physx::PxSceneQueryFilterCallback*>(filterCall_pod);
physx::PxSceneQueryCache const* cache = reinterpret_cast<physx::PxSceneQueryCache const*>(cache_pod);
int32_t returnValue = PxSceneQueryExt::raycastMultiple(scene, origin, unitDir, distance, outputFlags, hitBuffer, hitBufferSize, blockingHit, filterData, filterCall, cache);
return returnValue;
}

bool PxSceneQueryExt_sweepAny_mut(physx_PxScene_Pod const* scene_pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxTransform_Pod const* pose_pod, physx_PxVec3_Pod const* unitDir_pod, float distance, physx_PxSceneQueryFlags_Pod queryFlags_pod, physx_PxSceneQueryHit_Pod* hit_pod, physx_PxSceneQueryFilterData_Pod const* filterData_pod, physx_PxSceneQueryFilterCallback_Pod* filterCall_pod, physx_PxSceneQueryCache_Pod const* cache_pod, float inflation) {
physx::PxScene const& scene = reinterpret_cast<physx::PxScene const&>(*scene_pod);
physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
physx::PxSceneQueryFlags queryFlags;
memcpy(&queryFlags, &queryFlags_pod, sizeof(queryFlags));
physx::PxSceneQueryHit& hit = reinterpret_cast<physx::PxSceneQueryHit&>(*hit_pod);
physx::PxSceneQueryFilterData const& filterData = reinterpret_cast<physx::PxSceneQueryFilterData const&>(*filterData_pod);
physx::PxSceneQueryFilterCallback* filterCall = reinterpret_cast<physx::PxSceneQueryFilterCallback*>(filterCall_pod);
physx::PxSceneQueryCache const* cache = reinterpret_cast<physx::PxSceneQueryCache const*>(cache_pod);
bool returnValue = PxSceneQueryExt::sweepAny(scene, geometry, pose, unitDir, distance, queryFlags, hit, filterData, filterCall, cache, inflation);
return returnValue;
}

bool PxSceneQueryExt_sweepSingle_mut(physx_PxScene_Pod const* scene_pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxTransform_Pod const* pose_pod, physx_PxVec3_Pod const* unitDir_pod, float distance, physx_PxSceneQueryFlags_Pod outputFlags_pod, physx_PxSweepHit_Pod* hit_pod, physx_PxSceneQueryFilterData_Pod const* filterData_pod, physx_PxSceneQueryFilterCallback_Pod* filterCall_pod, physx_PxSceneQueryCache_Pod const* cache_pod, float inflation) {
physx::PxScene const& scene = reinterpret_cast<physx::PxScene const&>(*scene_pod);
physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
physx::PxSceneQueryFlags outputFlags;
memcpy(&outputFlags, &outputFlags_pod, sizeof(outputFlags));
physx::PxSweepHit& hit = reinterpret_cast<physx::PxSweepHit&>(*hit_pod);
physx::PxSceneQueryFilterData const& filterData = reinterpret_cast<physx::PxSceneQueryFilterData const&>(*filterData_pod);
physx::PxSceneQueryFilterCallback* filterCall = reinterpret_cast<physx::PxSceneQueryFilterCallback*>(filterCall_pod);
physx::PxSceneQueryCache const* cache = reinterpret_cast<physx::PxSceneQueryCache const*>(cache_pod);
bool returnValue = PxSceneQueryExt::sweepSingle(scene, geometry, pose, unitDir, distance, outputFlags, hit, filterData, filterCall, cache, inflation);
return returnValue;
}

int32_t PxSceneQueryExt_sweepMultiple_mut(physx_PxScene_Pod const* scene_pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxTransform_Pod const* pose_pod, physx_PxVec3_Pod const* unitDir_pod, float distance, physx_PxSceneQueryFlags_Pod outputFlags_pod, physx_PxSweepHit_Pod* hitBuffer_pod, uint32_t hitBufferSize, bool* blockingHit_pod, physx_PxSceneQueryFilterData_Pod const* filterData_pod, physx_PxSceneQueryFilterCallback_Pod* filterCall_pod, physx_PxSceneQueryCache_Pod const* cache_pod, float inflation) {
physx::PxScene const& scene = reinterpret_cast<physx::PxScene const&>(*scene_pod);
physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
physx::PxSceneQueryFlags outputFlags;
memcpy(&outputFlags, &outputFlags_pod, sizeof(outputFlags));
physx::PxSweepHit* hitBuffer = reinterpret_cast<physx::PxSweepHit*>(hitBuffer_pod);
bool& blockingHit = *blockingHit_pod;
physx::PxSceneQueryFilterData const& filterData = reinterpret_cast<physx::PxSceneQueryFilterData const&>(*filterData_pod);
physx::PxSceneQueryFilterCallback* filterCall = reinterpret_cast<physx::PxSceneQueryFilterCallback*>(filterCall_pod);
physx::PxSceneQueryCache const* cache = reinterpret_cast<physx::PxSceneQueryCache const*>(cache_pod);
int32_t returnValue = PxSceneQueryExt::sweepMultiple(scene, geometry, pose, unitDir, distance, outputFlags, hitBuffer, hitBufferSize, blockingHit, filterData, filterCall, cache, inflation);
return returnValue;
}

int32_t PxSceneQueryExt_overlapMultiple_mut(physx_PxScene_Pod const* scene_pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxTransform_Pod const* pose_pod, physx_PxOverlapHit_Pod* hitBuffer_pod, uint32_t hitBufferSize, physx_PxSceneQueryFilterData_Pod const* filterData_pod, physx_PxSceneQueryFilterCallback_Pod* filterCall_pod) {
physx::PxScene const& scene = reinterpret_cast<physx::PxScene const&>(*scene_pod);
physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
physx::PxOverlapHit* hitBuffer = reinterpret_cast<physx::PxOverlapHit*>(hitBuffer_pod);
physx::PxSceneQueryFilterData const& filterData = reinterpret_cast<physx::PxSceneQueryFilterData const&>(*filterData_pod);
physx::PxSceneQueryFilterCallback* filterCall = reinterpret_cast<physx::PxSceneQueryFilterCallback*>(filterCall_pod);
int32_t returnValue = PxSceneQueryExt::overlapMultiple(scene, geometry, pose, hitBuffer, hitBufferSize, filterData, filterCall);
return returnValue;
}

bool PxSceneQueryExt_overlapAny_mut(physx_PxScene_Pod const* scene_pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxTransform_Pod const* pose_pod, physx_PxOverlapHit_Pod* hit_pod, physx_PxSceneQueryFilterData_Pod const* filterData_pod, physx_PxSceneQueryFilterCallback_Pod* filterCall_pod) {
physx::PxScene const& scene = reinterpret_cast<physx::PxScene const&>(*scene_pod);
physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
physx::PxOverlapHit& hit = reinterpret_cast<physx::PxOverlapHit&>(*hit_pod);
physx::PxSceneQueryFilterData const& filterData = reinterpret_cast<physx::PxSceneQueryFilterData const&>(*filterData_pod);
physx::PxSceneQueryFilterCallback* filterCall = reinterpret_cast<physx::PxSceneQueryFilterCallback*>(filterCall_pod);
bool returnValue = PxSceneQueryExt::overlapAny(scene, geometry, pose, hit, filterData, filterCall);
return returnValue;
}

bool phys_PxInitExtensions(physx_PxPhysics_Pod* physics_pod, physx_PxPvd_Pod* pvd_pod) {
physx::PxPhysics& physics = reinterpret_cast<physx::PxPhysics&>(*physics_pod);
physx::PxPvd* pvd = reinterpret_cast<physx::PxPvd*>(pvd_pod);
bool returnValue = PxInitExtensions(physics, pvd);
return returnValue;
}

void phys_PxCloseExtensions() {
PxCloseExtensions();
}

uint32_t phys_PxFindFaceIndex(physx_PxConvexMeshGeometry_Pod const* convexGeom_pod, physx_PxTransform_Pod const* geomPose_pod, physx_PxVec3_Pod const* impactPos_pod, physx_PxVec3_Pod const* unitDir_pod) {
physx::PxConvexMeshGeometry const& convexGeom = reinterpret_cast<physx::PxConvexMeshGeometry const&>(*convexGeom_pod);
physx::PxTransform const& geomPose = reinterpret_cast<physx::PxTransform const&>(*geomPose_pod);
physx::PxVec3 const& impactPos = reinterpret_cast<physx::PxVec3 const&>(*impactPos_pod);
physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
uint32_t returnValue = PxFindFaceIndex(convexGeom, geomPose, impactPos, unitDir);
return returnValue;
}

void PxBinaryConverter_release_mut(physx_PxBinaryConverter_Pod* self__pod) {
physx::PxBinaryConverter* self_ = reinterpret_cast<physx::PxBinaryConverter*>(self__pod);
self_->release();
}

void PxBinaryConverter_setReportMode_mut(physx_PxBinaryConverter_Pod* self__pod, unsigned int mode_pod) {
physx::PxBinaryConverter* self_ = reinterpret_cast<physx::PxBinaryConverter*>(self__pod);
PxConverterReportMode::Enum mode = (PxConverterReportMode::Enum)mode_pod;
self_->setReportMode(mode);
}

bool PxBinaryConverter_setMetaData_mut(physx_PxBinaryConverter_Pod* self__pod, physx_PxInputStream_Pod* srcMetaData_pod, physx_PxInputStream_Pod* dstMetaData_pod) {
physx::PxBinaryConverter* self_ = reinterpret_cast<physx::PxBinaryConverter*>(self__pod);
physx::PxInputStream& srcMetaData = reinterpret_cast<physx::PxInputStream&>(*srcMetaData_pod);
physx::PxInputStream& dstMetaData = reinterpret_cast<physx::PxInputStream&>(*dstMetaData_pod);
bool returnValue = self_->setMetaData(srcMetaData, dstMetaData);
return returnValue;
}

bool PxBinaryConverter_compareMetaData(physx_PxBinaryConverter_Pod const* self__pod) {
physx::PxBinaryConverter const* self_ = reinterpret_cast<physx::PxBinaryConverter const*>(self__pod);
bool returnValue = self_->compareMetaData();
return returnValue;
}

bool PxBinaryConverter_convert_mut(physx_PxBinaryConverter_Pod* self__pod, physx_PxInputStream_Pod* srcStream_pod, uint32_t srcSize, physx_PxOutputStream_Pod* targetStream_pod) {
physx::PxBinaryConverter* self_ = reinterpret_cast<physx::PxBinaryConverter*>(self__pod);
physx::PxInputStream& srcStream = reinterpret_cast<physx::PxInputStream&>(*srcStream_pod);
physx::PxOutputStream& targetStream = reinterpret_cast<physx::PxOutputStream&>(*targetStream_pod);
bool returnValue = self_->convert(srcStream, srcSize, targetStream);
return returnValue;
}

physx_PxRepXObject_Pod PxRepXObject_new(char const* inTypeName, void const* inSerializable, uint64_t inId) {
physx::PxRepXObject returnValue(inTypeName, inSerializable, inId);
physx_PxRepXObject_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool PxRepXObject_isValid(physx_PxRepXObject_Pod const* self__pod) {
physx::PxRepXObject const* self_ = reinterpret_cast<physx::PxRepXObject const*>(self__pod);
bool returnValue = self_->isValid();
return returnValue;
}

physx_PxRepXInstantiationArgs_Pod PxRepXInstantiationArgs_new(physx_PxPhysics_Pod* inPhysics_pod, physx_PxCooking_Pod* inCooking_pod, physx_PxStringTable_Pod* inStringTable_pod) {
physx::PxPhysics& inPhysics = reinterpret_cast<physx::PxPhysics&>(*inPhysics_pod);
physx::PxCooking* inCooking = reinterpret_cast<physx::PxCooking*>(inCooking_pod);
physx::PxStringTable* inStringTable = reinterpret_cast<physx::PxStringTable*>(inStringTable_pod);
physx::PxRepXInstantiationArgs returnValue(inPhysics, inCooking, inStringTable);
physx_PxRepXInstantiationArgs_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

char const* PxRepXSerializer_getTypeName_mut(physx_PxRepXSerializer_Pod* self__pod) {
physx::PxRepXSerializer* self_ = reinterpret_cast<physx::PxRepXSerializer*>(self__pod);
char const* returnValue = self_->getTypeName();
return returnValue;
}

void PxRepXSerializer_objectToFile_mut(physx_PxRepXSerializer_Pod* self__pod, physx_PxRepXObject_Pod const* inLiveObject_pod, physx_PxCollection_Pod* inCollection_pod, physx_XmlWriter_Pod* inWriter_pod, physx_MemoryBuffer_Pod* inTempBuffer_pod, physx_PxRepXInstantiationArgs_Pod* inArgs_pod) {
physx::PxRepXSerializer* self_ = reinterpret_cast<physx::PxRepXSerializer*>(self__pod);
physx::PxRepXObject const& inLiveObject = reinterpret_cast<physx::PxRepXObject const&>(*inLiveObject_pod);
physx::PxCollection* inCollection = reinterpret_cast<physx::PxCollection*>(inCollection_pod);
physx::XmlWriter& inWriter = reinterpret_cast<physx::XmlWriter&>(*inWriter_pod);
physx::MemoryBuffer& inTempBuffer = reinterpret_cast<physx::MemoryBuffer&>(*inTempBuffer_pod);
physx::PxRepXInstantiationArgs& inArgs = reinterpret_cast<physx::PxRepXInstantiationArgs&>(*inArgs_pod);
self_->objectToFile(inLiveObject, inCollection, inWriter, inTempBuffer, inArgs);
}

physx_PxRepXObject_Pod PxRepXSerializer_fileToObject_mut(physx_PxRepXSerializer_Pod* self__pod, physx_XmlReader_Pod* inReader_pod, physx_XmlMemoryAllocator_Pod* inAllocator_pod, physx_PxRepXInstantiationArgs_Pod* inArgs_pod, physx_PxCollection_Pod* inCollection_pod) {
physx::PxRepXSerializer* self_ = reinterpret_cast<physx::PxRepXSerializer*>(self__pod);
physx::XmlReader& inReader = reinterpret_cast<physx::XmlReader&>(*inReader_pod);
physx::XmlMemoryAllocator& inAllocator = reinterpret_cast<physx::XmlMemoryAllocator&>(*inAllocator_pod);
physx::PxRepXInstantiationArgs& inArgs = reinterpret_cast<physx::PxRepXInstantiationArgs&>(*inArgs_pod);
physx::PxCollection* inCollection = reinterpret_cast<physx::PxCollection*>(inCollection_pod);
physx::PxRepXObject returnValue = self_->fileToObject(inReader, inAllocator, inArgs, inCollection);
physx_PxRepXObject_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxRepXObject_Pod phys_PxCreateRepXObject(physx_PxBase_Pod const* inType_pod, uint64_t inId) {
physx::PxBase const* inType = reinterpret_cast<physx::PxBase const*>(inType_pod);
physx::PxRepXObject returnValue = PxCreateRepXObject(inType, inId);
physx_PxRepXObject_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

bool phys_PxInitVehicleSDK(physx_PxPhysics_Pod* physics_pod, physx_PxSerializationRegistry_Pod* serializationRegistry_pod) {
physx::PxPhysics& physics = reinterpret_cast<physx::PxPhysics&>(*physics_pod);
physx::PxSerializationRegistry* serializationRegistry = reinterpret_cast<physx::PxSerializationRegistry*>(serializationRegistry_pod);
bool returnValue = PxInitVehicleSDK(physics, serializationRegistry);
return returnValue;
}

void phys_PxCloseVehicleSDK(physx_PxSerializationRegistry_Pod* serializationRegistry_pod) {
physx::PxSerializationRegistry* serializationRegistry = reinterpret_cast<physx::PxSerializationRegistry*>(serializationRegistry_pod);
PxCloseVehicleSDK(serializationRegistry);
}

void phys_PxVehicleSetBasisVectors(physx_PxVec3_Pod const* up_pod, physx_PxVec3_Pod const* forward_pod) {
physx::PxVec3 const& up = reinterpret_cast<physx::PxVec3 const&>(*up_pod);
physx::PxVec3 const& forward = reinterpret_cast<physx::PxVec3 const&>(*forward_pod);
PxVehicleSetBasisVectors(up, forward);
}

void phys_PxVehicleSetUpdateMode(unsigned int vehicleUpdateMode_pod) {
PxVehicleUpdateMode::Enum vehicleUpdateMode = (PxVehicleUpdateMode::Enum)vehicleUpdateMode_pod;
PxVehicleSetUpdateMode(vehicleUpdateMode);
}

void phys_PxVehicleSetSweepHitRejectionAngles(float pointRejectAngle, float normalRejectAngle) {
PxVehicleSetSweepHitRejectionAngles(pointRejectAngle, normalRejectAngle);
}

void phys_PxVehicleSetMaxHitActorAcceleration(float maxHitActorAcceleration) {
PxVehicleSetMaxHitActorAcceleration(maxHitActorAcceleration);
}

physx_PxVehicleChassisData_Pod PxVehicleChassisData_new() {
physx::PxVehicleChassisData returnValue;
physx_PxVehicleChassisData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVehicleEngineData_Pod PxVehicleEngineData_new() {
physx::PxVehicleEngineData returnValue;
physx_PxVehicleEngineData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

float PxVehicleEngineData_getRecipMOI(physx_PxVehicleEngineData_Pod const* self__pod) {
physx::PxVehicleEngineData const* self_ = reinterpret_cast<physx::PxVehicleEngineData const*>(self__pod);
float returnValue = self_->getRecipMOI();
return returnValue;
}

float PxVehicleEngineData_getRecipMaxOmega(physx_PxVehicleEngineData_Pod const* self__pod) {
physx::PxVehicleEngineData const* self_ = reinterpret_cast<physx::PxVehicleEngineData const*>(self__pod);
float returnValue = self_->getRecipMaxOmega();
return returnValue;
}

physx_PxVehicleEngineData_Pod PxVehicleEngineData_new_1(unsigned int anonymous_arg0_pod) {
physx::PxEMPTY anonymous_arg0 = (physx::PxEMPTY)anonymous_arg0_pod;
physx::PxVehicleEngineData returnValue(anonymous_arg0);
physx_PxVehicleEngineData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxVehicleEngineData_delete(physx_PxVehicleEngineData_Pod* self__pod) {
physx::PxVehicleEngineData* self_ = reinterpret_cast<physx::PxVehicleEngineData*>(self__pod);
delete self_;
}

physx_PxVehicleGearsData_Pod PxVehicleGearsData_new() {
physx::PxVehicleGearsData returnValue;
physx_PxVehicleGearsData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVehicleGearsData_Pod PxVehicleGearsData_new_1(unsigned int anonymous_arg0_pod) {
physx::PxEMPTY anonymous_arg0 = (physx::PxEMPTY)anonymous_arg0_pod;
physx::PxVehicleGearsData returnValue(anonymous_arg0);
physx_PxVehicleGearsData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

float PxVehicleGearsData_getGearRatio(physx_PxVehicleGearsData_Pod const* self__pod, unsigned int a_pod) {
physx::PxVehicleGearsData const* self_ = reinterpret_cast<physx::PxVehicleGearsData const*>(self__pod);
PxVehicleGearsData::Enum a = (PxVehicleGearsData::Enum)a_pod;
float returnValue = self_->getGearRatio(a);
return returnValue;
}

void PxVehicleGearsData_setGearRatio_mut(physx_PxVehicleGearsData_Pod* self__pod, unsigned int a_pod, float ratio) {
physx::PxVehicleGearsData* self_ = reinterpret_cast<physx::PxVehicleGearsData*>(self__pod);
PxVehicleGearsData::Enum a = (PxVehicleGearsData::Enum)a_pod;
self_->setGearRatio(a, ratio);
}

physx_PxVehicleAutoBoxData_Pod PxVehicleAutoBoxData_new() {
physx::PxVehicleAutoBoxData returnValue;
physx_PxVehicleAutoBoxData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxVehicleAutoBoxData_setLatency_mut(physx_PxVehicleAutoBoxData_Pod* self__pod, float latency) {
physx::PxVehicleAutoBoxData* self_ = reinterpret_cast<physx::PxVehicleAutoBoxData*>(self__pod);
self_->setLatency(latency);
}

float PxVehicleAutoBoxData_getLatency(physx_PxVehicleAutoBoxData_Pod const* self__pod) {
physx::PxVehicleAutoBoxData const* self_ = reinterpret_cast<physx::PxVehicleAutoBoxData const*>(self__pod);
float returnValue = self_->getLatency();
return returnValue;
}

physx_PxVehicleAutoBoxData_Pod PxVehicleAutoBoxData_new_1(unsigned int anonymous_arg0_pod) {
physx::PxEMPTY anonymous_arg0 = (physx::PxEMPTY)anonymous_arg0_pod;
physx::PxVehicleAutoBoxData returnValue(anonymous_arg0);
physx_PxVehicleAutoBoxData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

float PxVehicleAutoBoxData_getUpRatios(physx_PxVehicleAutoBoxData_Pod const* self__pod, unsigned int a_pod) {
physx::PxVehicleAutoBoxData const* self_ = reinterpret_cast<physx::PxVehicleAutoBoxData const*>(self__pod);
PxVehicleGearsData::Enum a = (PxVehicleGearsData::Enum)a_pod;
float returnValue = self_->getUpRatios(a);
return returnValue;
}

void PxVehicleAutoBoxData_setUpRatios_mut(physx_PxVehicleAutoBoxData_Pod* self__pod, unsigned int a_pod, float ratio) {
physx::PxVehicleAutoBoxData* self_ = reinterpret_cast<physx::PxVehicleAutoBoxData*>(self__pod);
PxVehicleGearsData::Enum a = (PxVehicleGearsData::Enum)a_pod;
self_->setUpRatios(a, ratio);
}

float PxVehicleAutoBoxData_getDownRatios(physx_PxVehicleAutoBoxData_Pod const* self__pod, unsigned int a_pod) {
physx::PxVehicleAutoBoxData const* self_ = reinterpret_cast<physx::PxVehicleAutoBoxData const*>(self__pod);
PxVehicleGearsData::Enum a = (PxVehicleGearsData::Enum)a_pod;
float returnValue = self_->getDownRatios(a);
return returnValue;
}

void PxVehicleAutoBoxData_setDownRatios_mut(physx_PxVehicleAutoBoxData_Pod* self__pod, unsigned int a_pod, float ratio) {
physx::PxVehicleAutoBoxData* self_ = reinterpret_cast<physx::PxVehicleAutoBoxData*>(self__pod);
PxVehicleGearsData::Enum a = (PxVehicleGearsData::Enum)a_pod;
self_->setDownRatios(a, ratio);
}

physx_PxVehicleDifferential4WData_Pod PxVehicleDifferential4WData_new() {
physx::PxVehicleDifferential4WData returnValue;
physx_PxVehicleDifferential4WData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVehicleDifferential4WData_Pod PxVehicleDifferential4WData_new_1(unsigned int anonymous_arg0_pod) {
physx::PxEMPTY anonymous_arg0 = (physx::PxEMPTY)anonymous_arg0_pod;
physx::PxVehicleDifferential4WData returnValue(anonymous_arg0);
physx_PxVehicleDifferential4WData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVehicleDifferentialNWData_Pod PxVehicleDifferentialNWData_new() {
physx::PxVehicleDifferentialNWData returnValue;
physx_PxVehicleDifferentialNWData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxVehicleDifferentialNWData_setDrivenWheel_mut(physx_PxVehicleDifferentialNWData_Pod* self__pod, uint32_t wheelId, bool drivenState) {
physx::PxVehicleDifferentialNWData* self_ = reinterpret_cast<physx::PxVehicleDifferentialNWData*>(self__pod);
self_->setDrivenWheel(wheelId, drivenState);
}

bool PxVehicleDifferentialNWData_getIsDrivenWheel(physx_PxVehicleDifferentialNWData_Pod const* self__pod, uint32_t wheelId) {
physx::PxVehicleDifferentialNWData const* self_ = reinterpret_cast<physx::PxVehicleDifferentialNWData const*>(self__pod);
bool returnValue = self_->getIsDrivenWheel(wheelId);
return returnValue;
}

physx_PxVehicleDifferentialNWData_Pod PxVehicleDifferentialNWData_new_1(unsigned int anonymous_arg0_pod) {
physx::PxEMPTY anonymous_arg0 = (physx::PxEMPTY)anonymous_arg0_pod;
physx::PxVehicleDifferentialNWData returnValue(anonymous_arg0);
physx_PxVehicleDifferentialNWData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

uint32_t PxVehicleDifferentialNWData_getDrivenWheelStatus(physx_PxVehicleDifferentialNWData_Pod const* self__pod) {
physx::PxVehicleDifferentialNWData const* self_ = reinterpret_cast<physx::PxVehicleDifferentialNWData const*>(self__pod);
uint32_t returnValue = self_->getDrivenWheelStatus();
return returnValue;
}

void PxVehicleDifferentialNWData_setDrivenWheelStatus_mut(physx_PxVehicleDifferentialNWData_Pod* self__pod, uint32_t status) {
physx::PxVehicleDifferentialNWData* self_ = reinterpret_cast<physx::PxVehicleDifferentialNWData*>(self__pod);
self_->setDrivenWheelStatus(status);
}

physx_PxVehicleAckermannGeometryData_Pod PxVehicleAckermannGeometryData_new() {
physx::PxVehicleAckermannGeometryData returnValue;
physx_PxVehicleAckermannGeometryData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVehicleAckermannGeometryData_Pod PxVehicleAckermannGeometryData_new_1(unsigned int anonymous_arg0_pod) {
physx::PxEMPTY anonymous_arg0 = (physx::PxEMPTY)anonymous_arg0_pod;
physx::PxVehicleAckermannGeometryData returnValue(anonymous_arg0);
physx_PxVehicleAckermannGeometryData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVehicleClutchData_Pod PxVehicleClutchData_new() {
physx::PxVehicleClutchData returnValue;
physx_PxVehicleClutchData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVehicleClutchData_Pod PxVehicleClutchData_new_1(unsigned int anonymous_arg0_pod) {
physx::PxEMPTY anonymous_arg0 = (physx::PxEMPTY)anonymous_arg0_pod;
physx::PxVehicleClutchData returnValue(anonymous_arg0);
physx_PxVehicleClutchData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVehicleTireLoadFilterData_Pod PxVehicleTireLoadFilterData_new() {
physx::PxVehicleTireLoadFilterData returnValue;
physx_PxVehicleTireLoadFilterData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

float PxVehicleTireLoadFilterData_getDenominator(physx_PxVehicleTireLoadFilterData_Pod const* self__pod) {
physx::PxVehicleTireLoadFilterData const* self_ = reinterpret_cast<physx::PxVehicleTireLoadFilterData const*>(self__pod);
float returnValue = self_->getDenominator();
return returnValue;
}

physx_PxVehicleTireLoadFilterData_Pod PxVehicleTireLoadFilterData_new_1(unsigned int anonymous_arg0_pod) {
physx::PxEMPTY anonymous_arg0 = (physx::PxEMPTY)anonymous_arg0_pod;
physx::PxVehicleTireLoadFilterData returnValue(anonymous_arg0);
physx_PxVehicleTireLoadFilterData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVehicleWheelData_Pod PxVehicleWheelData_new() {
physx::PxVehicleWheelData returnValue;
physx_PxVehicleWheelData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

float PxVehicleWheelData_getRecipRadius(physx_PxVehicleWheelData_Pod const* self__pod) {
physx::PxVehicleWheelData const* self_ = reinterpret_cast<physx::PxVehicleWheelData const*>(self__pod);
float returnValue = self_->getRecipRadius();
return returnValue;
}

float PxVehicleWheelData_getRecipMOI(physx_PxVehicleWheelData_Pod const* self__pod) {
physx::PxVehicleWheelData const* self_ = reinterpret_cast<physx::PxVehicleWheelData const*>(self__pod);
float returnValue = self_->getRecipMOI();
return returnValue;
}

physx_PxVehicleSuspensionData_Pod PxVehicleSuspensionData_new() {
physx::PxVehicleSuspensionData returnValue;
physx_PxVehicleSuspensionData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

float PxVehicleSuspensionData_getRecipMaxCompression(physx_PxVehicleSuspensionData_Pod const* self__pod) {
physx::PxVehicleSuspensionData const* self_ = reinterpret_cast<physx::PxVehicleSuspensionData const*>(self__pod);
float returnValue = self_->getRecipMaxCompression();
return returnValue;
}

float PxVehicleSuspensionData_getRecipMaxDroop(physx_PxVehicleSuspensionData_Pod const* self__pod) {
physx::PxVehicleSuspensionData const* self_ = reinterpret_cast<physx::PxVehicleSuspensionData const*>(self__pod);
float returnValue = self_->getRecipMaxDroop();
return returnValue;
}

void PxVehicleSuspensionData_setMassAndPreserveNaturalFrequency_mut(physx_PxVehicleSuspensionData_Pod* self__pod, float newSprungMass) {
physx::PxVehicleSuspensionData* self_ = reinterpret_cast<physx::PxVehicleSuspensionData*>(self__pod);
self_->setMassAndPreserveNaturalFrequency(newSprungMass);
}

physx_PxVehicleAntiRollBarData_Pod PxVehicleAntiRollBarData_new() {
physx::PxVehicleAntiRollBarData returnValue;
physx_PxVehicleAntiRollBarData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVehicleTireData_Pod PxVehicleTireData_new() {
physx::PxVehicleTireData returnValue;
physx_PxVehicleTireData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

float PxVehicleTireData_getRecipLongitudinalStiffnessPerUnitGravity(physx_PxVehicleTireData_Pod const* self__pod) {
physx::PxVehicleTireData const* self_ = reinterpret_cast<physx::PxVehicleTireData const*>(self__pod);
float returnValue = self_->getRecipLongitudinalStiffnessPerUnitGravity();
return returnValue;
}

float PxVehicleTireData_getFrictionVsSlipGraphRecipx1Minusx0(physx_PxVehicleTireData_Pod const* self__pod) {
physx::PxVehicleTireData const* self_ = reinterpret_cast<physx::PxVehicleTireData const*>(self__pod);
float returnValue = self_->getFrictionVsSlipGraphRecipx1Minusx0();
return returnValue;
}

float PxVehicleTireData_getFrictionVsSlipGraphRecipx2Minusx1(physx_PxVehicleTireData_Pod const* self__pod) {
physx::PxVehicleTireData const* self_ = reinterpret_cast<physx::PxVehicleTireData const*>(self__pod);
float returnValue = self_->getFrictionVsSlipGraphRecipx2Minusx1();
return returnValue;
}

physx_PxVehicleWheelsSimData_Pod* PxVehicleWheelsSimData_allocate_mut(uint32_t nbWheels) {
physx::PxVehicleWheelsSimData* returnValue = PxVehicleWheelsSimData::allocate(nbWheels);
physx_PxVehicleWheelsSimData_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleWheelsSimData_Pod*>(returnValue);
return returnValue_pod;
}

void PxVehicleWheelsSimData_setChassisMass_mut(physx_PxVehicleWheelsSimData_Pod* self__pod, float chassisMass) {
physx::PxVehicleWheelsSimData* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData*>(self__pod);
self_->setChassisMass(chassisMass);
}

void PxVehicleWheelsSimData_free_mut(physx_PxVehicleWheelsSimData_Pod* self__pod) {
physx::PxVehicleWheelsSimData* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData*>(self__pod);
self_->free();
}

void PxVehicleWheelsSimData_copy_mut(physx_PxVehicleWheelsSimData_Pod* self__pod, physx_PxVehicleWheelsSimData_Pod const* src_pod, uint32_t srcWheel, uint32_t trgWheel) {
physx::PxVehicleWheelsSimData* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData*>(self__pod);
physx::PxVehicleWheelsSimData const& src = reinterpret_cast<physx::PxVehicleWheelsSimData const&>(*src_pod);
self_->copy(src, srcWheel, trgWheel);
}

uint32_t PxVehicleWheelsSimData_getNbWheels(physx_PxVehicleWheelsSimData_Pod const* self__pod) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
uint32_t returnValue = self_->getNbWheels();
return returnValue;
}

physx_PxVehicleSuspensionData_Pod const* PxVehicleWheelsSimData_getSuspensionData(physx_PxVehicleWheelsSimData_Pod const* self__pod, uint32_t id) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
physx::PxVehicleSuspensionData const& returnValue = self_->getSuspensionData(id);
physx_PxVehicleSuspensionData_Pod const* returnValue_pod = reinterpret_cast<physx_PxVehicleSuspensionData_Pod const*>(&returnValue);
return returnValue_pod;
}

physx_PxVehicleWheelData_Pod const* PxVehicleWheelsSimData_getWheelData(physx_PxVehicleWheelsSimData_Pod const* self__pod, uint32_t id) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
physx::PxVehicleWheelData const& returnValue = self_->getWheelData(id);
physx_PxVehicleWheelData_Pod const* returnValue_pod = reinterpret_cast<physx_PxVehicleWheelData_Pod const*>(&returnValue);
return returnValue_pod;
}

physx_PxVehicleTireData_Pod const* PxVehicleWheelsSimData_getTireData(physx_PxVehicleWheelsSimData_Pod const* self__pod, uint32_t id) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
physx::PxVehicleTireData const& returnValue = self_->getTireData(id);
physx_PxVehicleTireData_Pod const* returnValue_pod = reinterpret_cast<physx_PxVehicleTireData_Pod const*>(&returnValue);
return returnValue_pod;
}

physx_PxVec3_Pod const* PxVehicleWheelsSimData_getSuspTravelDirection(physx_PxVehicleWheelsSimData_Pod const* self__pod, uint32_t id) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
physx::PxVec3 const& returnValue = self_->getSuspTravelDirection(id);
physx_PxVec3_Pod const* returnValue_pod = reinterpret_cast<physx_PxVec3_Pod const*>(&returnValue);
return returnValue_pod;
}

physx_PxVec3_Pod const* PxVehicleWheelsSimData_getSuspForceAppPointOffset(physx_PxVehicleWheelsSimData_Pod const* self__pod, uint32_t id) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
physx::PxVec3 const& returnValue = self_->getSuspForceAppPointOffset(id);
physx_PxVec3_Pod const* returnValue_pod = reinterpret_cast<physx_PxVec3_Pod const*>(&returnValue);
return returnValue_pod;
}

physx_PxVec3_Pod const* PxVehicleWheelsSimData_getTireForceAppPointOffset(physx_PxVehicleWheelsSimData_Pod const* self__pod, uint32_t id) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
physx::PxVec3 const& returnValue = self_->getTireForceAppPointOffset(id);
physx_PxVec3_Pod const* returnValue_pod = reinterpret_cast<physx_PxVec3_Pod const*>(&returnValue);
return returnValue_pod;
}

physx_PxVec3_Pod const* PxVehicleWheelsSimData_getWheelCentreOffset(physx_PxVehicleWheelsSimData_Pod const* self__pod, uint32_t id) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
physx::PxVec3 const& returnValue = self_->getWheelCentreOffset(id);
physx_PxVec3_Pod const* returnValue_pod = reinterpret_cast<physx_PxVec3_Pod const*>(&returnValue);
return returnValue_pod;
}

int32_t PxVehicleWheelsSimData_getWheelShapeMapping(physx_PxVehicleWheelsSimData_Pod const* self__pod, uint32_t wheelId) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
int32_t returnValue = self_->getWheelShapeMapping(wheelId);
return returnValue;
}

physx_PxFilterData_Pod const* PxVehicleWheelsSimData_getSceneQueryFilterData(physx_PxVehicleWheelsSimData_Pod const* self__pod, uint32_t suspId) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
physx::PxFilterData const& returnValue = self_->getSceneQueryFilterData(suspId);
physx_PxFilterData_Pod const* returnValue_pod = reinterpret_cast<physx_PxFilterData_Pod const*>(&returnValue);
return returnValue_pod;
}

uint32_t PxVehicleWheelsSimData_getNbAntiRollBars(physx_PxVehicleWheelsSimData_Pod const* self__pod) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
uint32_t returnValue = self_->getNbAntiRollBars();
return returnValue;
}

physx_PxVehicleAntiRollBarData_Pod const* PxVehicleWheelsSimData_getAntiRollBarData(physx_PxVehicleWheelsSimData_Pod const* self__pod, uint32_t antiRollId) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
physx::PxVehicleAntiRollBarData const& returnValue = self_->getAntiRollBarData(antiRollId);
physx_PxVehicleAntiRollBarData_Pod const* returnValue_pod = reinterpret_cast<physx_PxVehicleAntiRollBarData_Pod const*>(&returnValue);
return returnValue_pod;
}

physx_PxVehicleTireLoadFilterData_Pod const* PxVehicleWheelsSimData_getTireLoadFilterData(physx_PxVehicleWheelsSimData_Pod const* self__pod) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
physx::PxVehicleTireLoadFilterData const& returnValue = self_->getTireLoadFilterData();
physx_PxVehicleTireLoadFilterData_Pod const* returnValue_pod = reinterpret_cast<physx_PxVehicleTireLoadFilterData_Pod const*>(&returnValue);
return returnValue_pod;
}

void PxVehicleWheelsSimData_setSuspensionData_mut(physx_PxVehicleWheelsSimData_Pod* self__pod, uint32_t id, physx_PxVehicleSuspensionData_Pod const* susp_pod) {
physx::PxVehicleWheelsSimData* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData*>(self__pod);
physx::PxVehicleSuspensionData const& susp = reinterpret_cast<physx::PxVehicleSuspensionData const&>(*susp_pod);
self_->setSuspensionData(id, susp);
}

void PxVehicleWheelsSimData_setWheelData_mut(physx_PxVehicleWheelsSimData_Pod* self__pod, uint32_t id, physx_PxVehicleWheelData_Pod const* wheel_pod) {
physx::PxVehicleWheelsSimData* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData*>(self__pod);
physx::PxVehicleWheelData const& wheel = reinterpret_cast<physx::PxVehicleWheelData const&>(*wheel_pod);
self_->setWheelData(id, wheel);
}

void PxVehicleWheelsSimData_setTireData_mut(physx_PxVehicleWheelsSimData_Pod* self__pod, uint32_t id, physx_PxVehicleTireData_Pod const* tire_pod) {
physx::PxVehicleWheelsSimData* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData*>(self__pod);
physx::PxVehicleTireData const& tire = reinterpret_cast<physx::PxVehicleTireData const&>(*tire_pod);
self_->setTireData(id, tire);
}

void PxVehicleWheelsSimData_setSuspTravelDirection_mut(physx_PxVehicleWheelsSimData_Pod* self__pod, uint32_t id, physx_PxVec3_Pod const* dir_pod) {
physx::PxVehicleWheelsSimData* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData*>(self__pod);
physx::PxVec3 const& dir = reinterpret_cast<physx::PxVec3 const&>(*dir_pod);
self_->setSuspTravelDirection(id, dir);
}

void PxVehicleWheelsSimData_setSuspForceAppPointOffset_mut(physx_PxVehicleWheelsSimData_Pod* self__pod, uint32_t id, physx_PxVec3_Pod const* offset_pod) {
physx::PxVehicleWheelsSimData* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData*>(self__pod);
physx::PxVec3 const& offset = reinterpret_cast<physx::PxVec3 const&>(*offset_pod);
self_->setSuspForceAppPointOffset(id, offset);
}

void PxVehicleWheelsSimData_setTireForceAppPointOffset_mut(physx_PxVehicleWheelsSimData_Pod* self__pod, uint32_t id, physx_PxVec3_Pod const* offset_pod) {
physx::PxVehicleWheelsSimData* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData*>(self__pod);
physx::PxVec3 const& offset = reinterpret_cast<physx::PxVec3 const&>(*offset_pod);
self_->setTireForceAppPointOffset(id, offset);
}

void PxVehicleWheelsSimData_setWheelCentreOffset_mut(physx_PxVehicleWheelsSimData_Pod* self__pod, uint32_t id, physx_PxVec3_Pod const* offset_pod) {
physx::PxVehicleWheelsSimData* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData*>(self__pod);
physx::PxVec3 const& offset = reinterpret_cast<physx::PxVec3 const&>(*offset_pod);
self_->setWheelCentreOffset(id, offset);
}

void PxVehicleWheelsSimData_setWheelShapeMapping_mut(physx_PxVehicleWheelsSimData_Pod* self__pod, uint32_t wheelId, int32_t shapeId) {
physx::PxVehicleWheelsSimData* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData*>(self__pod);
self_->setWheelShapeMapping(wheelId, shapeId);
}

void PxVehicleWheelsSimData_setSceneQueryFilterData_mut(physx_PxVehicleWheelsSimData_Pod* self__pod, uint32_t suspId, physx_PxFilterData_Pod const* sqFilterData_pod) {
physx::PxVehicleWheelsSimData* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData*>(self__pod);
physx::PxFilterData const& sqFilterData = reinterpret_cast<physx::PxFilterData const&>(*sqFilterData_pod);
self_->setSceneQueryFilterData(suspId, sqFilterData);
}

void PxVehicleWheelsSimData_setTireLoadFilterData_mut(physx_PxVehicleWheelsSimData_Pod* self__pod, physx_PxVehicleTireLoadFilterData_Pod const* tireLoadFilter_pod) {
physx::PxVehicleWheelsSimData* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData*>(self__pod);
physx::PxVehicleTireLoadFilterData const& tireLoadFilter = reinterpret_cast<physx::PxVehicleTireLoadFilterData const&>(*tireLoadFilter_pod);
self_->setTireLoadFilterData(tireLoadFilter);
}

uint32_t PxVehicleWheelsSimData_addAntiRollBarData_mut(physx_PxVehicleWheelsSimData_Pod* self__pod, physx_PxVehicleAntiRollBarData_Pod const* antiRoll_pod) {
physx::PxVehicleWheelsSimData* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData*>(self__pod);
physx::PxVehicleAntiRollBarData const& antiRoll = reinterpret_cast<physx::PxVehicleAntiRollBarData const&>(*antiRoll_pod);
uint32_t returnValue = self_->addAntiRollBarData(antiRoll);
return returnValue;
}

void PxVehicleWheelsSimData_disableWheel_mut(physx_PxVehicleWheelsSimData_Pod* self__pod, uint32_t wheel) {
physx::PxVehicleWheelsSimData* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData*>(self__pod);
self_->disableWheel(wheel);
}

void PxVehicleWheelsSimData_enableWheel_mut(physx_PxVehicleWheelsSimData_Pod* self__pod, uint32_t wheel) {
physx::PxVehicleWheelsSimData* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData*>(self__pod);
self_->enableWheel(wheel);
}

bool PxVehicleWheelsSimData_getIsWheelDisabled(physx_PxVehicleWheelsSimData_Pod const* self__pod, uint32_t wheel) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
bool returnValue = self_->getIsWheelDisabled(wheel);
return returnValue;
}

void PxVehicleWheelsSimData_setSubStepCount_mut(physx_PxVehicleWheelsSimData_Pod* self__pod, float thresholdLongitudinalSpeed, uint32_t lowForwardSpeedSubStepCount, uint32_t highForwardSpeedSubStepCount) {
physx::PxVehicleWheelsSimData* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData*>(self__pod);
self_->setSubStepCount(thresholdLongitudinalSpeed, lowForwardSpeedSubStepCount, highForwardSpeedSubStepCount);
}

void PxVehicleWheelsSimData_setMinLongSlipDenominator_mut(physx_PxVehicleWheelsSimData_Pod* self__pod, float minLongSlipDenominator) {
physx::PxVehicleWheelsSimData* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData*>(self__pod);
self_->setMinLongSlipDenominator(minLongSlipDenominator);
}

void PxVehicleWheelsSimData_setFlags_mut(physx_PxVehicleWheelsSimData_Pod* self__pod, physx_PxVehicleWheelsSimFlags_Pod flags_pod) {
physx::PxVehicleWheelsSimData* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData*>(self__pod);
physx::PxVehicleWheelsSimFlags flags;
memcpy(&flags, &flags_pod, sizeof(flags));
self_->setFlags(flags);
}

physx_PxVehicleWheelsSimFlags_Pod PxVehicleWheelsSimData_getFlags(physx_PxVehicleWheelsSimData_Pod const* self__pod) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
physx::PxVehicleWheelsSimFlags returnValue = self_->getFlags();
physx_PxVehicleWheelsSimFlags_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVehicleWheelsSimData_Pod* PxVehicleWheelsSimData_new_alloc(unsigned int anonymous_arg0_pod) {
physx::PxEMPTY anonymous_arg0 = (physx::PxEMPTY)anonymous_arg0_pod;
auto returnValue = new physx::PxVehicleWheelsSimData(anonymous_arg0);
physx_PxVehicleWheelsSimData_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleWheelsSimData_Pod*>(returnValue);
return returnValue_pod;
}

void PxVehicleWheelsSimData_getBinaryMetaData_mut(physx_PxOutputStream_Pod* stream_pod) {
physx::PxOutputStream& stream = reinterpret_cast<physx::PxOutputStream&>(*stream_pod);
PxVehicleWheelsSimData::getBinaryMetaData(stream);
}

uint32_t PxVehicleWheelsSimData_getNbWheels4(physx_PxVehicleWheelsSimData_Pod const* self__pod) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
uint32_t returnValue = self_->getNbWheels4();
return returnValue;
}

uint32_t PxVehicleWheelsSimData_getNbSuspensionData(physx_PxVehicleWheelsSimData_Pod const* self__pod) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
uint32_t returnValue = self_->getNbSuspensionData();
return returnValue;
}

uint32_t PxVehicleWheelsSimData_getNbWheelData(physx_PxVehicleWheelsSimData_Pod const* self__pod) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
uint32_t returnValue = self_->getNbWheelData();
return returnValue;
}

uint32_t PxVehicleWheelsSimData_getNbSuspTravelDirection(physx_PxVehicleWheelsSimData_Pod const* self__pod) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
uint32_t returnValue = self_->getNbSuspTravelDirection();
return returnValue;
}

uint32_t PxVehicleWheelsSimData_getNbTireData(physx_PxVehicleWheelsSimData_Pod const* self__pod) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
uint32_t returnValue = self_->getNbTireData();
return returnValue;
}

uint32_t PxVehicleWheelsSimData_getNbSuspForceAppPointOffset(physx_PxVehicleWheelsSimData_Pod const* self__pod) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
uint32_t returnValue = self_->getNbSuspForceAppPointOffset();
return returnValue;
}

uint32_t PxVehicleWheelsSimData_getNbTireForceAppPointOffset(physx_PxVehicleWheelsSimData_Pod const* self__pod) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
uint32_t returnValue = self_->getNbTireForceAppPointOffset();
return returnValue;
}

uint32_t PxVehicleWheelsSimData_getNbWheelCentreOffset(physx_PxVehicleWheelsSimData_Pod const* self__pod) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
uint32_t returnValue = self_->getNbWheelCentreOffset();
return returnValue;
}

uint32_t PxVehicleWheelsSimData_getNbWheelShapeMapping(physx_PxVehicleWheelsSimData_Pod const* self__pod) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
uint32_t returnValue = self_->getNbWheelShapeMapping();
return returnValue;
}

uint32_t PxVehicleWheelsSimData_getNbSceneQueryFilterData(physx_PxVehicleWheelsSimData_Pod const* self__pod) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
uint32_t returnValue = self_->getNbSceneQueryFilterData();
return returnValue;
}

float PxVehicleWheelsSimData_getMinLongSlipDenominator(physx_PxVehicleWheelsSimData_Pod const* self__pod) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
float returnValue = self_->getMinLongSlipDenominator();
return returnValue;
}

void PxVehicleWheelsSimData_setThresholdLongSpeed_mut(physx_PxVehicleWheelsSimData_Pod* self__pod, float f) {
physx::PxVehicleWheelsSimData* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData*>(self__pod);
self_->setThresholdLongSpeed(f);
}

float PxVehicleWheelsSimData_getThresholdLongSpeed(physx_PxVehicleWheelsSimData_Pod const* self__pod) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
float returnValue = self_->getThresholdLongSpeed();
return returnValue;
}

void PxVehicleWheelsSimData_setLowForwardSpeedSubStepCount_mut(physx_PxVehicleWheelsSimData_Pod* self__pod, uint32_t f) {
physx::PxVehicleWheelsSimData* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData*>(self__pod);
self_->setLowForwardSpeedSubStepCount(f);
}

uint32_t PxVehicleWheelsSimData_getLowForwardSpeedSubStepCount(physx_PxVehicleWheelsSimData_Pod const* self__pod) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
uint32_t returnValue = self_->getLowForwardSpeedSubStepCount();
return returnValue;
}

void PxVehicleWheelsSimData_setHighForwardSpeedSubStepCount_mut(physx_PxVehicleWheelsSimData_Pod* self__pod, uint32_t f) {
physx::PxVehicleWheelsSimData* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData*>(self__pod);
self_->setHighForwardSpeedSubStepCount(f);
}

uint32_t PxVehicleWheelsSimData_getHighForwardSpeedSubStepCount(physx_PxVehicleWheelsSimData_Pod const* self__pod) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
uint32_t returnValue = self_->getHighForwardSpeedSubStepCount();
return returnValue;
}

void PxVehicleWheelsSimData_setWheelEnabledState_mut(physx_PxVehicleWheelsSimData_Pod* self__pod, uint32_t wheel, bool state) {
physx::PxVehicleWheelsSimData* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData*>(self__pod);
self_->setWheelEnabledState(wheel, state);
}

bool PxVehicleWheelsSimData_getWheelEnabledState(physx_PxVehicleWheelsSimData_Pod const* self__pod, uint32_t wheel) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
bool returnValue = self_->getWheelEnabledState(wheel);
return returnValue;
}

uint32_t PxVehicleWheelsSimData_getNbWheelEnabledState(physx_PxVehicleWheelsSimData_Pod const* self__pod) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
uint32_t returnValue = self_->getNbWheelEnabledState();
return returnValue;
}

uint32_t PxVehicleWheelsSimData_getNbAntiRollBars4(physx_PxVehicleWheelsSimData_Pod const* self__pod) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
uint32_t returnValue = self_->getNbAntiRollBars4();
return returnValue;
}

uint32_t PxVehicleWheelsSimData_getNbAntiRollBarData(physx_PxVehicleWheelsSimData_Pod const* self__pod) {
physx::PxVehicleWheelsSimData const* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData const*>(self__pod);
uint32_t returnValue = self_->getNbAntiRollBarData();
return returnValue;
}

void PxVehicleWheelsSimData_setAntiRollBarData_mut(physx_PxVehicleWheelsSimData_Pod* self__pod, uint32_t id, physx_PxVehicleAntiRollBarData_Pod const* antiRoll_pod) {
physx::PxVehicleWheelsSimData* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData*>(self__pod);
physx::PxVehicleAntiRollBarData const& antiRoll = reinterpret_cast<physx::PxVehicleAntiRollBarData const&>(*antiRoll_pod);
self_->setAntiRollBarData(id, antiRoll);
}

physx_PxVehicleWheelsSimData_Pod* PxVehicleWheelsSimData_new_alloc_1() {
auto returnValue = new physx::PxVehicleWheelsSimData();
physx_PxVehicleWheelsSimData_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleWheelsSimData_Pod*>(returnValue);
return returnValue_pod;
}

void PxVehicleWheelsSimData_delete(physx_PxVehicleWheelsSimData_Pod* self__pod) {
physx::PxVehicleWheelsSimData* self_ = reinterpret_cast<physx::PxVehicleWheelsSimData*>(self__pod);
delete self_;
}

physx_PxVehicleWheelsDynData_Pod* PxVehicleWheelsDynData_new_alloc() {
auto returnValue = new physx::PxVehicleWheelsDynData();
physx_PxVehicleWheelsDynData_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleWheelsDynData_Pod*>(returnValue);
return returnValue_pod;
}

void PxVehicleWheelsDynData_delete(physx_PxVehicleWheelsDynData_Pod* self__pod) {
physx::PxVehicleWheelsDynData* self_ = reinterpret_cast<physx::PxVehicleWheelsDynData*>(self__pod);
delete self_;
}

void PxVehicleWheelsDynData_setToRestState_mut(physx_PxVehicleWheelsDynData_Pod* self__pod) {
physx::PxVehicleWheelsDynData* self_ = reinterpret_cast<physx::PxVehicleWheelsDynData*>(self__pod);
self_->setToRestState();
}

void PxVehicleWheelsDynData_setTireForceShaderFunction_mut(physx_PxVehicleWheelsDynData_Pod* self__pod, void* tireForceShaderFn_pod) {
physx::PxVehicleWheelsDynData* self_ = reinterpret_cast<physx::PxVehicleWheelsDynData*>(self__pod);
physx::PxVehicleComputeTireForce tireForceShaderFn;
memcpy(&tireForceShaderFn, &tireForceShaderFn_pod, sizeof(tireForceShaderFn));
self_->setTireForceShaderFunction(tireForceShaderFn);
}

void PxVehicleWheelsDynData_setTireForceShaderData_mut(physx_PxVehicleWheelsDynData_Pod* self__pod, uint32_t tireId, void const* tireForceShaderData) {
physx::PxVehicleWheelsDynData* self_ = reinterpret_cast<physx::PxVehicleWheelsDynData*>(self__pod);
self_->setTireForceShaderData(tireId, tireForceShaderData);
}

void const* PxVehicleWheelsDynData_getTireForceShaderData(physx_PxVehicleWheelsDynData_Pod const* self__pod, uint32_t tireId) {
physx::PxVehicleWheelsDynData const* self_ = reinterpret_cast<physx::PxVehicleWheelsDynData const*>(self__pod);
void const* returnValue = self_->getTireForceShaderData(tireId);
return returnValue;
}

void PxVehicleWheelsDynData_setWheelRotationSpeed_mut(physx_PxVehicleWheelsDynData_Pod* self__pod, uint32_t wheelIdx, float speed) {
physx::PxVehicleWheelsDynData* self_ = reinterpret_cast<physx::PxVehicleWheelsDynData*>(self__pod);
self_->setWheelRotationSpeed(wheelIdx, speed);
}

float PxVehicleWheelsDynData_getWheelRotationSpeed(physx_PxVehicleWheelsDynData_Pod const* self__pod, uint32_t wheelIdx) {
physx::PxVehicleWheelsDynData const* self_ = reinterpret_cast<physx::PxVehicleWheelsDynData const*>(self__pod);
float returnValue = self_->getWheelRotationSpeed(wheelIdx);
return returnValue;
}

void PxVehicleWheelsDynData_setWheelRotationAngle_mut(physx_PxVehicleWheelsDynData_Pod* self__pod, uint32_t wheelIdx, float angle) {
physx::PxVehicleWheelsDynData* self_ = reinterpret_cast<physx::PxVehicleWheelsDynData*>(self__pod);
self_->setWheelRotationAngle(wheelIdx, angle);
}

float PxVehicleWheelsDynData_getWheelRotationAngle(physx_PxVehicleWheelsDynData_Pod const* self__pod, uint32_t wheelIdx) {
physx::PxVehicleWheelsDynData const* self_ = reinterpret_cast<physx::PxVehicleWheelsDynData const*>(self__pod);
float returnValue = self_->getWheelRotationAngle(wheelIdx);
return returnValue;
}

void PxVehicleWheelsDynData_setUserData_mut(physx_PxVehicleWheelsDynData_Pod* self__pod, uint32_t tireIdx, void* userData) {
physx::PxVehicleWheelsDynData* self_ = reinterpret_cast<physx::PxVehicleWheelsDynData*>(self__pod);
self_->setUserData(tireIdx, userData);
}

void* PxVehicleWheelsDynData_getUserData(physx_PxVehicleWheelsDynData_Pod const* self__pod, uint32_t tireIdx) {
physx::PxVehicleWheelsDynData const* self_ = reinterpret_cast<physx::PxVehicleWheelsDynData const*>(self__pod);
void* returnValue = self_->getUserData(tireIdx);
return returnValue;
}

void PxVehicleWheelsDynData_copy_mut(physx_PxVehicleWheelsDynData_Pod* self__pod, physx_PxVehicleWheelsDynData_Pod const* src_pod, uint32_t srcWheel, uint32_t trgWheel) {
physx::PxVehicleWheelsDynData* self_ = reinterpret_cast<physx::PxVehicleWheelsDynData*>(self__pod);
physx::PxVehicleWheelsDynData const& src = reinterpret_cast<physx::PxVehicleWheelsDynData const&>(*src_pod);
self_->copy(src, srcWheel, trgWheel);
}

void PxVehicleWheelsDynData_getBinaryMetaData_mut(physx_PxOutputStream_Pod* stream_pod) {
physx::PxOutputStream& stream = reinterpret_cast<physx::PxOutputStream&>(*stream_pod);
PxVehicleWheelsDynData::getBinaryMetaData(stream);
}

uint32_t PxVehicleWheelsDynData_getNbWheelRotationSpeed(physx_PxVehicleWheelsDynData_Pod const* self__pod) {
physx::PxVehicleWheelsDynData const* self_ = reinterpret_cast<physx::PxVehicleWheelsDynData const*>(self__pod);
uint32_t returnValue = self_->getNbWheelRotationSpeed();
return returnValue;
}

uint32_t PxVehicleWheelsDynData_getNbWheelRotationAngle(physx_PxVehicleWheelsDynData_Pod const* self__pod) {
physx::PxVehicleWheelsDynData const* self_ = reinterpret_cast<physx::PxVehicleWheelsDynData const*>(self__pod);
uint32_t returnValue = self_->getNbWheelRotationAngle();
return returnValue;
}

physx_PxVehicleWheels4DynData_Pod* PxVehicleWheelsDynData_getWheel4DynData(physx_PxVehicleWheelsDynData_Pod const* self__pod) {
physx::PxVehicleWheelsDynData const* self_ = reinterpret_cast<physx::PxVehicleWheelsDynData const*>(self__pod);
physx::PxVehicleWheels4DynData* returnValue = self_->getWheel4DynData();
physx_PxVehicleWheels4DynData_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleWheels4DynData_Pod*>(returnValue);
return returnValue_pod;
}

uint32_t PxVehicleWheels_getVehicleType(physx_PxVehicleWheels_Pod const* self__pod) {
physx::PxVehicleWheels const* self_ = reinterpret_cast<physx::PxVehicleWheels const*>(self__pod);
uint32_t returnValue = self_->getVehicleType();
return returnValue;
}

physx_PxRigidDynamic_Pod* PxVehicleWheels_getRigidDynamicActor_mut(physx_PxVehicleWheels_Pod* self__pod) {
physx::PxVehicleWheels* self_ = reinterpret_cast<physx::PxVehicleWheels*>(self__pod);
physx::PxRigidDynamic* returnValue = self_->getRigidDynamicActor();
physx_PxRigidDynamic_Pod* returnValue_pod = reinterpret_cast<physx_PxRigidDynamic_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxRigidDynamic_Pod const* PxVehicleWheels_getRigidDynamicActor(physx_PxVehicleWheels_Pod const* self__pod) {
physx::PxVehicleWheels const* self_ = reinterpret_cast<physx::PxVehicleWheels const*>(self__pod);
physx::PxRigidDynamic const* returnValue = self_->getRigidDynamicActor();
physx_PxRigidDynamic_Pod const* returnValue_pod = reinterpret_cast<physx_PxRigidDynamic_Pod const*>(returnValue);
return returnValue_pod;
}

float PxVehicleWheels_computeForwardSpeed(physx_PxVehicleWheels_Pod const* self__pod) {
physx::PxVehicleWheels const* self_ = reinterpret_cast<physx::PxVehicleWheels const*>(self__pod);
float returnValue = self_->computeForwardSpeed();
return returnValue;
}

float PxVehicleWheels_computeSidewaysSpeed(physx_PxVehicleWheels_Pod const* self__pod) {
physx::PxVehicleWheels const* self_ = reinterpret_cast<physx::PxVehicleWheels const*>(self__pod);
float returnValue = self_->computeSidewaysSpeed();
return returnValue;
}

void PxVehicleWheels_requiresObjects_mut(physx_PxVehicleWheels_Pod* self__pod, physx_PxProcessPxBaseCallback_Pod* c_pod) {
physx::PxVehicleWheels* self_ = reinterpret_cast<physx::PxVehicleWheels*>(self__pod);
physx::PxProcessPxBaseCallback& c = reinterpret_cast<physx::PxProcessPxBaseCallback&>(*c_pod);
self_->requiresObjects(c);
}

char const* PxVehicleWheels_getConcreteTypeName(physx_PxVehicleWheels_Pod const* self__pod) {
physx::PxVehicleWheels const* self_ = reinterpret_cast<physx::PxVehicleWheels const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

bool PxVehicleWheels_isKindOf(physx_PxVehicleWheels_Pod const* self__pod, char const* name) {
physx::PxVehicleWheels const* self_ = reinterpret_cast<physx::PxVehicleWheels const*>(self__pod);
bool returnValue = self_->isKindOf(name);
return returnValue;
}

void PxVehicleWheels_preExportDataReset_mut(physx_PxVehicleWheels_Pod* self__pod) {
physx::PxVehicleWheels* self_ = reinterpret_cast<physx::PxVehicleWheels*>(self__pod);
self_->preExportDataReset();
}

void PxVehicleWheels_exportExtraData_mut(physx_PxVehicleWheels_Pod* self__pod, physx_PxSerializationContext_Pod* anonymous_arg0_pod) {
physx::PxVehicleWheels* self_ = reinterpret_cast<physx::PxVehicleWheels*>(self__pod);
physx::PxSerializationContext& anonymous_arg0 = reinterpret_cast<physx::PxSerializationContext&>(*anonymous_arg0_pod);
self_->exportExtraData(anonymous_arg0);
}

void PxVehicleWheels_importExtraData_mut(physx_PxVehicleWheels_Pod* self__pod, physx_PxDeserializationContext_Pod* anonymous_arg0_pod) {
physx::PxVehicleWheels* self_ = reinterpret_cast<physx::PxVehicleWheels*>(self__pod);
physx::PxDeserializationContext& anonymous_arg0 = reinterpret_cast<physx::PxDeserializationContext&>(*anonymous_arg0_pod);
self_->importExtraData(anonymous_arg0);
}

void PxVehicleWheels_resolveReferences_mut(physx_PxVehicleWheels_Pod* self__pod, physx_PxDeserializationContext_Pod* anonymous_arg0_pod) {
physx::PxVehicleWheels* self_ = reinterpret_cast<physx::PxVehicleWheels*>(self__pod);
physx::PxDeserializationContext& anonymous_arg0 = reinterpret_cast<physx::PxDeserializationContext&>(*anonymous_arg0_pod);
self_->resolveReferences(anonymous_arg0);
}

void PxVehicleWheels_getBinaryMetaData_mut(physx_PxOutputStream_Pod* stream_pod) {
physx::PxOutputStream& stream = reinterpret_cast<physx::PxOutputStream&>(*stream_pod);
PxVehicleWheels::getBinaryMetaData(stream);
}

uint32_t PxVehicleWheels_getNbNonDrivenWheels(physx_PxVehicleWheels_Pod const* self__pod) {
physx::PxVehicleWheels const* self_ = reinterpret_cast<physx::PxVehicleWheels const*>(self__pod);
uint32_t returnValue = self_->getNbNonDrivenWheels();
return returnValue;
}

physx_PxVehicleWheels_Pod* PxVehicleWheels_new_alloc(uint16_t concreteType, physx_PxBaseFlags_Pod baseFlags_pod) {
physx::PxBaseFlags baseFlags;
memcpy(&baseFlags, &baseFlags_pod, sizeof(baseFlags));
auto returnValue = new physx::PxVehicleWheels(concreteType, baseFlags);
physx_PxVehicleWheels_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleWheels_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxVehicleWheels_Pod* PxVehicleWheels_new_alloc_1(physx_PxBaseFlags_Pod baseFlags_pod) {
physx::PxBaseFlags baseFlags;
memcpy(&baseFlags, &baseFlags_pod, sizeof(baseFlags));
auto returnValue = new physx::PxVehicleWheels(baseFlags);
physx_PxVehicleWheels_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleWheels_Pod*>(returnValue);
return returnValue_pod;
}

void PxVehicleWheels_release_mut(physx_PxVehicleWheels_Pod* self__pod) {
physx::PxVehicleWheels* self_ = reinterpret_cast<physx::PxVehicleWheels*>(self__pod);
self_->release();
}

physx_PxVehicleEngineData_Pod const* PxVehicleDriveSimData_getEngineData(physx_PxVehicleDriveSimData_Pod const* self__pod) {
physx::PxVehicleDriveSimData const* self_ = reinterpret_cast<physx::PxVehicleDriveSimData const*>(self__pod);
physx::PxVehicleEngineData const& returnValue = self_->getEngineData();
physx_PxVehicleEngineData_Pod const* returnValue_pod = reinterpret_cast<physx_PxVehicleEngineData_Pod const*>(&returnValue);
return returnValue_pod;
}

void PxVehicleDriveSimData_setEngineData_mut(physx_PxVehicleDriveSimData_Pod* self__pod, physx_PxVehicleEngineData_Pod const* engine_pod) {
physx::PxVehicleDriveSimData* self_ = reinterpret_cast<physx::PxVehicleDriveSimData*>(self__pod);
physx::PxVehicleEngineData const& engine = reinterpret_cast<physx::PxVehicleEngineData const&>(*engine_pod);
self_->setEngineData(engine);
}

physx_PxVehicleGearsData_Pod const* PxVehicleDriveSimData_getGearsData(physx_PxVehicleDriveSimData_Pod const* self__pod) {
physx::PxVehicleDriveSimData const* self_ = reinterpret_cast<physx::PxVehicleDriveSimData const*>(self__pod);
physx::PxVehicleGearsData const& returnValue = self_->getGearsData();
physx_PxVehicleGearsData_Pod const* returnValue_pod = reinterpret_cast<physx_PxVehicleGearsData_Pod const*>(&returnValue);
return returnValue_pod;
}

void PxVehicleDriveSimData_setGearsData_mut(physx_PxVehicleDriveSimData_Pod* self__pod, physx_PxVehicleGearsData_Pod const* gears_pod) {
physx::PxVehicleDriveSimData* self_ = reinterpret_cast<physx::PxVehicleDriveSimData*>(self__pod);
physx::PxVehicleGearsData const& gears = reinterpret_cast<physx::PxVehicleGearsData const&>(*gears_pod);
self_->setGearsData(gears);
}

physx_PxVehicleClutchData_Pod const* PxVehicleDriveSimData_getClutchData(physx_PxVehicleDriveSimData_Pod const* self__pod) {
physx::PxVehicleDriveSimData const* self_ = reinterpret_cast<physx::PxVehicleDriveSimData const*>(self__pod);
physx::PxVehicleClutchData const& returnValue = self_->getClutchData();
physx_PxVehicleClutchData_Pod const* returnValue_pod = reinterpret_cast<physx_PxVehicleClutchData_Pod const*>(&returnValue);
return returnValue_pod;
}

void PxVehicleDriveSimData_setClutchData_mut(physx_PxVehicleDriveSimData_Pod* self__pod, physx_PxVehicleClutchData_Pod const* clutch_pod) {
physx::PxVehicleDriveSimData* self_ = reinterpret_cast<physx::PxVehicleDriveSimData*>(self__pod);
physx::PxVehicleClutchData const& clutch = reinterpret_cast<physx::PxVehicleClutchData const&>(*clutch_pod);
self_->setClutchData(clutch);
}

physx_PxVehicleAutoBoxData_Pod const* PxVehicleDriveSimData_getAutoBoxData(physx_PxVehicleDriveSimData_Pod const* self__pod) {
physx::PxVehicleDriveSimData const* self_ = reinterpret_cast<physx::PxVehicleDriveSimData const*>(self__pod);
physx::PxVehicleAutoBoxData const& returnValue = self_->getAutoBoxData();
physx_PxVehicleAutoBoxData_Pod const* returnValue_pod = reinterpret_cast<physx_PxVehicleAutoBoxData_Pod const*>(&returnValue);
return returnValue_pod;
}

void PxVehicleDriveSimData_setAutoBoxData_mut(physx_PxVehicleDriveSimData_Pod* self__pod, physx_PxVehicleAutoBoxData_Pod const* autobox_pod) {
physx::PxVehicleDriveSimData* self_ = reinterpret_cast<physx::PxVehicleDriveSimData*>(self__pod);
physx::PxVehicleAutoBoxData const& autobox = reinterpret_cast<physx::PxVehicleAutoBoxData const&>(*autobox_pod);
self_->setAutoBoxData(autobox);
}

physx_PxVehicleDriveSimData_Pod PxVehicleDriveSimData_new() {
physx::PxVehicleDriveSimData returnValue;
physx_PxVehicleDriveSimData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVehicleDriveSimData_Pod PxVehicleDriveSimData_new_1(unsigned int anonymous_arg0_pod) {
physx::PxEMPTY anonymous_arg0 = (physx::PxEMPTY)anonymous_arg0_pod;
physx::PxVehicleDriveSimData returnValue(anonymous_arg0);
physx_PxVehicleDriveSimData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxVehicleDriveSimData_getBinaryMetaData_mut(physx_PxOutputStream_Pod* stream_pod) {
physx::PxOutputStream& stream = reinterpret_cast<physx::PxOutputStream&>(*stream_pod);
PxVehicleDriveSimData::getBinaryMetaData(stream);
}

void PxVehicleDriveSimData_delete(physx_PxVehicleDriveSimData_Pod* self__pod) {
physx::PxVehicleDriveSimData* self_ = reinterpret_cast<physx::PxVehicleDriveSimData*>(self__pod);
delete self_;
}

void PxVehicleDriveDynData_setToRestState_mut(physx_PxVehicleDriveDynData_Pod* self__pod) {
physx::PxVehicleDriveDynData* self_ = reinterpret_cast<physx::PxVehicleDriveDynData*>(self__pod);
self_->setToRestState();
}

void PxVehicleDriveDynData_setAnalogInput_mut(physx_PxVehicleDriveDynData_Pod* self__pod, uint32_t type, float analogVal) {
physx::PxVehicleDriveDynData* self_ = reinterpret_cast<physx::PxVehicleDriveDynData*>(self__pod);
self_->setAnalogInput(type, analogVal);
}

float PxVehicleDriveDynData_getAnalogInput(physx_PxVehicleDriveDynData_Pod const* self__pod, uint32_t type) {
physx::PxVehicleDriveDynData const* self_ = reinterpret_cast<physx::PxVehicleDriveDynData const*>(self__pod);
float returnValue = self_->getAnalogInput(type);
return returnValue;
}

void PxVehicleDriveDynData_setGearUp_mut(physx_PxVehicleDriveDynData_Pod* self__pod, bool digitalVal) {
physx::PxVehicleDriveDynData* self_ = reinterpret_cast<physx::PxVehicleDriveDynData*>(self__pod);
self_->setGearUp(digitalVal);
}

void PxVehicleDriveDynData_setGearDown_mut(physx_PxVehicleDriveDynData_Pod* self__pod, bool digitalVal) {
physx::PxVehicleDriveDynData* self_ = reinterpret_cast<physx::PxVehicleDriveDynData*>(self__pod);
self_->setGearDown(digitalVal);
}

bool PxVehicleDriveDynData_getGearUp(physx_PxVehicleDriveDynData_Pod const* self__pod) {
physx::PxVehicleDriveDynData const* self_ = reinterpret_cast<physx::PxVehicleDriveDynData const*>(self__pod);
bool returnValue = self_->getGearUp();
return returnValue;
}

bool PxVehicleDriveDynData_getGearDown(physx_PxVehicleDriveDynData_Pod const* self__pod) {
physx::PxVehicleDriveDynData const* self_ = reinterpret_cast<physx::PxVehicleDriveDynData const*>(self__pod);
bool returnValue = self_->getGearDown();
return returnValue;
}

void PxVehicleDriveDynData_setUseAutoGears_mut(physx_PxVehicleDriveDynData_Pod* self__pod, bool useAutoGears) {
physx::PxVehicleDriveDynData* self_ = reinterpret_cast<physx::PxVehicleDriveDynData*>(self__pod);
self_->setUseAutoGears(useAutoGears);
}

bool PxVehicleDriveDynData_getUseAutoGears(physx_PxVehicleDriveDynData_Pod const* self__pod) {
physx::PxVehicleDriveDynData const* self_ = reinterpret_cast<physx::PxVehicleDriveDynData const*>(self__pod);
bool returnValue = self_->getUseAutoGears();
return returnValue;
}

void PxVehicleDriveDynData_toggleAutoGears_mut(physx_PxVehicleDriveDynData_Pod* self__pod) {
physx::PxVehicleDriveDynData* self_ = reinterpret_cast<physx::PxVehicleDriveDynData*>(self__pod);
self_->toggleAutoGears();
}

void PxVehicleDriveDynData_setCurrentGear_mut(physx_PxVehicleDriveDynData_Pod* self__pod, uint32_t currentGear) {
physx::PxVehicleDriveDynData* self_ = reinterpret_cast<physx::PxVehicleDriveDynData*>(self__pod);
self_->setCurrentGear(currentGear);
}

uint32_t PxVehicleDriveDynData_getCurrentGear(physx_PxVehicleDriveDynData_Pod const* self__pod) {
physx::PxVehicleDriveDynData const* self_ = reinterpret_cast<physx::PxVehicleDriveDynData const*>(self__pod);
uint32_t returnValue = self_->getCurrentGear();
return returnValue;
}

void PxVehicleDriveDynData_setTargetGear_mut(physx_PxVehicleDriveDynData_Pod* self__pod, uint32_t targetGear) {
physx::PxVehicleDriveDynData* self_ = reinterpret_cast<physx::PxVehicleDriveDynData*>(self__pod);
self_->setTargetGear(targetGear);
}

uint32_t PxVehicleDriveDynData_getTargetGear(physx_PxVehicleDriveDynData_Pod const* self__pod) {
physx::PxVehicleDriveDynData const* self_ = reinterpret_cast<physx::PxVehicleDriveDynData const*>(self__pod);
uint32_t returnValue = self_->getTargetGear();
return returnValue;
}

void PxVehicleDriveDynData_startGearChange_mut(physx_PxVehicleDriveDynData_Pod* self__pod, uint32_t targetGear) {
physx::PxVehicleDriveDynData* self_ = reinterpret_cast<physx::PxVehicleDriveDynData*>(self__pod);
self_->startGearChange(targetGear);
}

void PxVehicleDriveDynData_forceGearChange_mut(physx_PxVehicleDriveDynData_Pod* self__pod, uint32_t targetGear) {
physx::PxVehicleDriveDynData* self_ = reinterpret_cast<physx::PxVehicleDriveDynData*>(self__pod);
self_->forceGearChange(targetGear);
}

void PxVehicleDriveDynData_setEngineRotationSpeed_mut(physx_PxVehicleDriveDynData_Pod* self__pod, float speed) {
physx::PxVehicleDriveDynData* self_ = reinterpret_cast<physx::PxVehicleDriveDynData*>(self__pod);
self_->setEngineRotationSpeed(speed);
}

float PxVehicleDriveDynData_getEngineRotationSpeed(physx_PxVehicleDriveDynData_Pod const* self__pod) {
physx::PxVehicleDriveDynData const* self_ = reinterpret_cast<physx::PxVehicleDriveDynData const*>(self__pod);
float returnValue = self_->getEngineRotationSpeed();
return returnValue;
}

float PxVehicleDriveDynData_getGearSwitchTime(physx_PxVehicleDriveDynData_Pod const* self__pod) {
physx::PxVehicleDriveDynData const* self_ = reinterpret_cast<physx::PxVehicleDriveDynData const*>(self__pod);
float returnValue = self_->getGearSwitchTime();
return returnValue;
}

float PxVehicleDriveDynData_getAutoBoxSwitchTime(physx_PxVehicleDriveDynData_Pod const* self__pod) {
physx::PxVehicleDriveDynData const* self_ = reinterpret_cast<physx::PxVehicleDriveDynData const*>(self__pod);
float returnValue = self_->getAutoBoxSwitchTime();
return returnValue;
}

physx_PxVehicleDriveDynData_Pod PxVehicleDriveDynData_new() {
physx::PxVehicleDriveDynData returnValue;
physx_PxVehicleDriveDynData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVehicleDriveDynData_Pod PxVehicleDriveDynData_new_1(unsigned int anonymous_arg0_pod) {
physx::PxEMPTY anonymous_arg0 = (physx::PxEMPTY)anonymous_arg0_pod;
physx::PxVehicleDriveDynData returnValue(anonymous_arg0);
physx_PxVehicleDriveDynData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

uint32_t PxVehicleDriveDynData_getNbAnalogInput(physx_PxVehicleDriveDynData_Pod const* self__pod) {
physx::PxVehicleDriveDynData const* self_ = reinterpret_cast<physx::PxVehicleDriveDynData const*>(self__pod);
uint32_t returnValue = self_->getNbAnalogInput();
return returnValue;
}

void PxVehicleDriveDynData_setGearChange_mut(physx_PxVehicleDriveDynData_Pod* self__pod, uint32_t gearChange) {
physx::PxVehicleDriveDynData* self_ = reinterpret_cast<physx::PxVehicleDriveDynData*>(self__pod);
self_->setGearChange(gearChange);
}

uint32_t PxVehicleDriveDynData_getGearChange(physx_PxVehicleDriveDynData_Pod const* self__pod) {
physx::PxVehicleDriveDynData const* self_ = reinterpret_cast<physx::PxVehicleDriveDynData const*>(self__pod);
uint32_t returnValue = self_->getGearChange();
return returnValue;
}

void PxVehicleDriveDynData_setGearSwitchTime_mut(physx_PxVehicleDriveDynData_Pod* self__pod, float switchTime) {
physx::PxVehicleDriveDynData* self_ = reinterpret_cast<physx::PxVehicleDriveDynData*>(self__pod);
self_->setGearSwitchTime(switchTime);
}

void PxVehicleDriveDynData_setAutoBoxSwitchTime_mut(physx_PxVehicleDriveDynData_Pod* self__pod, float autoBoxSwitchTime) {
physx::PxVehicleDriveDynData* self_ = reinterpret_cast<physx::PxVehicleDriveDynData*>(self__pod);
self_->setAutoBoxSwitchTime(autoBoxSwitchTime);
}

void PxVehicleDrive_getBinaryMetaData_mut(physx_PxOutputStream_Pod* stream_pod) {
physx::PxOutputStream& stream = reinterpret_cast<physx::PxOutputStream&>(*stream_pod);
PxVehicleDrive::getBinaryMetaData(stream);
}

physx_PxVehicleDrive_Pod* PxVehicleDrive_new_alloc(physx_PxBaseFlags_Pod baseFlags_pod) {
physx::PxBaseFlags baseFlags;
memcpy(&baseFlags, &baseFlags_pod, sizeof(baseFlags));
auto returnValue = new physx::PxVehicleDrive(baseFlags);
physx_PxVehicleDrive_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleDrive_Pod*>(returnValue);
return returnValue_pod;
}

char const* PxVehicleDrive_getConcreteTypeName(physx_PxVehicleDrive_Pod const* self__pod) {
physx::PxVehicleDrive const* self_ = reinterpret_cast<physx::PxVehicleDrive const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

physx_PxVehicleDriveSimData4W_Pod PxVehicleDriveSimData4W_new() {
physx::PxVehicleDriveSimData4W returnValue;
physx_PxVehicleDriveSimData4W_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVehicleDifferential4WData_Pod const* PxVehicleDriveSimData4W_getDiffData(physx_PxVehicleDriveSimData4W_Pod const* self__pod) {
physx::PxVehicleDriveSimData4W const* self_ = reinterpret_cast<physx::PxVehicleDriveSimData4W const*>(self__pod);
physx::PxVehicleDifferential4WData const& returnValue = self_->getDiffData();
physx_PxVehicleDifferential4WData_Pod const* returnValue_pod = reinterpret_cast<physx_PxVehicleDifferential4WData_Pod const*>(&returnValue);
return returnValue_pod;
}

physx_PxVehicleAckermannGeometryData_Pod const* PxVehicleDriveSimData4W_getAckermannGeometryData(physx_PxVehicleDriveSimData4W_Pod const* self__pod) {
physx::PxVehicleDriveSimData4W const* self_ = reinterpret_cast<physx::PxVehicleDriveSimData4W const*>(self__pod);
physx::PxVehicleAckermannGeometryData const& returnValue = self_->getAckermannGeometryData();
physx_PxVehicleAckermannGeometryData_Pod const* returnValue_pod = reinterpret_cast<physx_PxVehicleAckermannGeometryData_Pod const*>(&returnValue);
return returnValue_pod;
}

void PxVehicleDriveSimData4W_setDiffData_mut(physx_PxVehicleDriveSimData4W_Pod* self__pod, physx_PxVehicleDifferential4WData_Pod const* diff_pod) {
physx::PxVehicleDriveSimData4W* self_ = reinterpret_cast<physx::PxVehicleDriveSimData4W*>(self__pod);
physx::PxVehicleDifferential4WData const& diff = reinterpret_cast<physx::PxVehicleDifferential4WData const&>(*diff_pod);
self_->setDiffData(diff);
}

void PxVehicleDriveSimData4W_setAckermannGeometryData_mut(physx_PxVehicleDriveSimData4W_Pod* self__pod, physx_PxVehicleAckermannGeometryData_Pod const* ackermannData_pod) {
physx::PxVehicleDriveSimData4W* self_ = reinterpret_cast<physx::PxVehicleDriveSimData4W*>(self__pod);
physx::PxVehicleAckermannGeometryData const& ackermannData = reinterpret_cast<physx::PxVehicleAckermannGeometryData const&>(*ackermannData_pod);
self_->setAckermannGeometryData(ackermannData);
}

physx_PxVehicleDriveSimData4W_Pod PxVehicleDriveSimData4W_new_1(unsigned int anonymous_arg0_pod) {
physx::PxEMPTY anonymous_arg0 = (physx::PxEMPTY)anonymous_arg0_pod;
physx::PxVehicleDriveSimData4W returnValue(anonymous_arg0);
physx_PxVehicleDriveSimData4W_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxVehicleDriveSimData4W_getBinaryMetaData_mut(physx_PxOutputStream_Pod* stream_pod) {
physx::PxOutputStream& stream = reinterpret_cast<physx::PxOutputStream&>(*stream_pod);
PxVehicleDriveSimData4W::getBinaryMetaData(stream);
}

void PxVehicleDriveSimData4W_delete(physx_PxVehicleDriveSimData4W_Pod* self__pod) {
physx::PxVehicleDriveSimData4W* self_ = reinterpret_cast<physx::PxVehicleDriveSimData4W*>(self__pod);
delete self_;
}

physx_PxVehicleDrive4W_Pod* PxVehicleDrive4W_allocate_mut(uint32_t nbWheels) {
physx::PxVehicleDrive4W* returnValue = PxVehicleDrive4W::allocate(nbWheels);
physx_PxVehicleDrive4W_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleDrive4W_Pod*>(returnValue);
return returnValue_pod;
}

void PxVehicleDrive4W_free_mut(physx_PxVehicleDrive4W_Pod* self__pod) {
physx::PxVehicleDrive4W* self_ = reinterpret_cast<physx::PxVehicleDrive4W*>(self__pod);
self_->free();
}

void PxVehicleDrive4W_setup_mut(physx_PxVehicleDrive4W_Pod* self__pod, physx_PxPhysics_Pod* physics_pod, physx_PxRigidDynamic_Pod* vehActor_pod, physx_PxVehicleWheelsSimData_Pod const* wheelsData_pod, physx_PxVehicleDriveSimData4W_Pod const* driveData_pod, uint32_t nbNonDrivenWheels) {
physx::PxVehicleDrive4W* self_ = reinterpret_cast<physx::PxVehicleDrive4W*>(self__pod);
physx::PxPhysics* physics = reinterpret_cast<physx::PxPhysics*>(physics_pod);
physx::PxRigidDynamic* vehActor = reinterpret_cast<physx::PxRigidDynamic*>(vehActor_pod);
physx::PxVehicleWheelsSimData const& wheelsData = reinterpret_cast<physx::PxVehicleWheelsSimData const&>(*wheelsData_pod);
physx::PxVehicleDriveSimData4W const& driveData = reinterpret_cast<physx::PxVehicleDriveSimData4W const&>(*driveData_pod);
self_->setup(physics, vehActor, wheelsData, driveData, nbNonDrivenWheels);
}

physx_PxVehicleDrive4W_Pod* PxVehicleDrive4W_create_mut(physx_PxPhysics_Pod* physics_pod, physx_PxRigidDynamic_Pod* vehActor_pod, physx_PxVehicleWheelsSimData_Pod const* wheelsData_pod, physx_PxVehicleDriveSimData4W_Pod const* driveData_pod, uint32_t nbNonDrivenWheels) {
physx::PxPhysics* physics = reinterpret_cast<physx::PxPhysics*>(physics_pod);
physx::PxRigidDynamic* vehActor = reinterpret_cast<physx::PxRigidDynamic*>(vehActor_pod);
physx::PxVehicleWheelsSimData const& wheelsData = reinterpret_cast<physx::PxVehicleWheelsSimData const&>(*wheelsData_pod);
physx::PxVehicleDriveSimData4W const& driveData = reinterpret_cast<physx::PxVehicleDriveSimData4W const&>(*driveData_pod);
physx::PxVehicleDrive4W* returnValue = PxVehicleDrive4W::create(physics, vehActor, wheelsData, driveData, nbNonDrivenWheels);
physx_PxVehicleDrive4W_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleDrive4W_Pod*>(returnValue);
return returnValue_pod;
}

void PxVehicleDrive4W_setToRestState_mut(physx_PxVehicleDrive4W_Pod* self__pod) {
physx::PxVehicleDrive4W* self_ = reinterpret_cast<physx::PxVehicleDrive4W*>(self__pod);
self_->setToRestState();
}

physx_PxVehicleDrive4W_Pod* PxVehicleDrive4W_createObject_mut(unsigned char** address_pod, physx_PxDeserializationContext_Pod* context_pod) {
unsigned char*& address = *address_pod;
physx::PxDeserializationContext& context = reinterpret_cast<physx::PxDeserializationContext&>(*context_pod);
physx::PxVehicleDrive4W* returnValue = PxVehicleDrive4W::createObject(address, context);
physx_PxVehicleDrive4W_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleDrive4W_Pod*>(returnValue);
return returnValue_pod;
}

void PxVehicleDrive4W_getBinaryMetaData_mut(physx_PxOutputStream_Pod* stream_pod) {
physx::PxOutputStream& stream = reinterpret_cast<physx::PxOutputStream&>(*stream_pod);
PxVehicleDrive4W::getBinaryMetaData(stream);
}

physx_PxVehicleDrive4W_Pod* PxVehicleDrive4W_new_alloc(physx_PxBaseFlags_Pod baseFlags_pod) {
physx::PxBaseFlags baseFlags;
memcpy(&baseFlags, &baseFlags_pod, sizeof(baseFlags));
auto returnValue = new physx::PxVehicleDrive4W(baseFlags);
physx_PxVehicleDrive4W_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleDrive4W_Pod*>(returnValue);
return returnValue_pod;
}

char const* PxVehicleDrive4W_getConcreteTypeName(physx_PxVehicleDrive4W_Pod const* self__pod) {
physx::PxVehicleDrive4W const* self_ = reinterpret_cast<physx::PxVehicleDrive4W const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

physx_PxVehicleDriveTank_Pod* PxVehicleDriveTank_allocate_mut(uint32_t nbWheels) {
physx::PxVehicleDriveTank* returnValue = PxVehicleDriveTank::allocate(nbWheels);
physx_PxVehicleDriveTank_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleDriveTank_Pod*>(returnValue);
return returnValue_pod;
}

void PxVehicleDriveTank_free_mut(physx_PxVehicleDriveTank_Pod* self__pod) {
physx::PxVehicleDriveTank* self_ = reinterpret_cast<physx::PxVehicleDriveTank*>(self__pod);
self_->free();
}

void PxVehicleDriveTank_setup_mut(physx_PxVehicleDriveTank_Pod* self__pod, physx_PxPhysics_Pod* physics_pod, physx_PxRigidDynamic_Pod* vehActor_pod, physx_PxVehicleWheelsSimData_Pod const* wheelsData_pod, physx_PxVehicleDriveSimData_Pod const* driveData_pod, uint32_t nbDrivenWheels) {
physx::PxVehicleDriveTank* self_ = reinterpret_cast<physx::PxVehicleDriveTank*>(self__pod);
physx::PxPhysics* physics = reinterpret_cast<physx::PxPhysics*>(physics_pod);
physx::PxRigidDynamic* vehActor = reinterpret_cast<physx::PxRigidDynamic*>(vehActor_pod);
physx::PxVehicleWheelsSimData const& wheelsData = reinterpret_cast<physx::PxVehicleWheelsSimData const&>(*wheelsData_pod);
physx::PxVehicleDriveSimData const& driveData = reinterpret_cast<physx::PxVehicleDriveSimData const&>(*driveData_pod);
self_->setup(physics, vehActor, wheelsData, driveData, nbDrivenWheels);
}

physx_PxVehicleDriveTank_Pod* PxVehicleDriveTank_create_mut(physx_PxPhysics_Pod* physics_pod, physx_PxRigidDynamic_Pod* vehActor_pod, physx_PxVehicleWheelsSimData_Pod const* wheelsData_pod, physx_PxVehicleDriveSimData_Pod const* driveData_pod, uint32_t nbDrivenWheels) {
physx::PxPhysics* physics = reinterpret_cast<physx::PxPhysics*>(physics_pod);
physx::PxRigidDynamic* vehActor = reinterpret_cast<physx::PxRigidDynamic*>(vehActor_pod);
physx::PxVehicleWheelsSimData const& wheelsData = reinterpret_cast<physx::PxVehicleWheelsSimData const&>(*wheelsData_pod);
physx::PxVehicleDriveSimData const& driveData = reinterpret_cast<physx::PxVehicleDriveSimData const&>(*driveData_pod);
physx::PxVehicleDriveTank* returnValue = PxVehicleDriveTank::create(physics, vehActor, wheelsData, driveData, nbDrivenWheels);
physx_PxVehicleDriveTank_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleDriveTank_Pod*>(returnValue);
return returnValue_pod;
}

void PxVehicleDriveTank_setDriveModel_mut(physx_PxVehicleDriveTank_Pod* self__pod, unsigned int driveModel_pod) {
physx::PxVehicleDriveTank* self_ = reinterpret_cast<physx::PxVehicleDriveTank*>(self__pod);
PxVehicleDriveTankControlModel::Enum driveModel = (PxVehicleDriveTankControlModel::Enum)driveModel_pod;
self_->setDriveModel(driveModel);
}

unsigned int PxVehicleDriveTank_getDriveModel(physx_PxVehicleDriveTank_Pod const* self__pod) {
physx::PxVehicleDriveTank const* self_ = reinterpret_cast<physx::PxVehicleDriveTank const*>(self__pod);
PxVehicleDriveTankControlModel::Enum returnValue = self_->getDriveModel();
unsigned int returnValue_pod = (unsigned int)returnValue;
return returnValue_pod;
}

void PxVehicleDriveTank_setToRestState_mut(physx_PxVehicleDriveTank_Pod* self__pod) {
physx::PxVehicleDriveTank* self_ = reinterpret_cast<physx::PxVehicleDriveTank*>(self__pod);
self_->setToRestState();
}

physx_PxVehicleDriveTank_Pod* PxVehicleDriveTank_new_alloc(physx_PxBaseFlags_Pod baseFlags_pod) {
physx::PxBaseFlags baseFlags;
memcpy(&baseFlags, &baseFlags_pod, sizeof(baseFlags));
auto returnValue = new physx::PxVehicleDriveTank(baseFlags);
physx_PxVehicleDriveTank_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleDriveTank_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxVehicleDriveTank_Pod* PxVehicleDriveTank_createObject_mut(unsigned char** address_pod, physx_PxDeserializationContext_Pod* context_pod) {
unsigned char*& address = *address_pod;
physx::PxDeserializationContext& context = reinterpret_cast<physx::PxDeserializationContext&>(*context_pod);
physx::PxVehicleDriveTank* returnValue = PxVehicleDriveTank::createObject(address, context);
physx_PxVehicleDriveTank_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleDriveTank_Pod*>(returnValue);
return returnValue_pod;
}

void PxVehicleDriveTank_getBinaryMetaData_mut(physx_PxOutputStream_Pod* stream_pod) {
physx::PxOutputStream& stream = reinterpret_cast<physx::PxOutputStream&>(*stream_pod);
PxVehicleDriveTank::getBinaryMetaData(stream);
}

char const* PxVehicleDriveTank_getConcreteTypeName(physx_PxVehicleDriveTank_Pod const* self__pod) {
physx::PxVehicleDriveTank const* self_ = reinterpret_cast<physx::PxVehicleDriveTank const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

bool PxVehicleDriveTank_isKindOf(physx_PxVehicleDriveTank_Pod const* self__pod, char const* name) {
physx::PxVehicleDriveTank const* self_ = reinterpret_cast<physx::PxVehicleDriveTank const*>(self__pod);
bool returnValue = self_->isKindOf(name);
return returnValue;
}

physx_PxVehicleDrivableSurfaceToTireFrictionPairs_Pod* PxVehicleDrivableSurfaceToTireFrictionPairs_allocate_mut(uint32_t maxNbTireTypes, uint32_t maxNbSurfaceTypes) {
physx::PxVehicleDrivableSurfaceToTireFrictionPairs* returnValue = PxVehicleDrivableSurfaceToTireFrictionPairs::allocate(maxNbTireTypes, maxNbSurfaceTypes);
physx_PxVehicleDrivableSurfaceToTireFrictionPairs_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleDrivableSurfaceToTireFrictionPairs_Pod*>(returnValue);
return returnValue_pod;
}

void PxVehicleDrivableSurfaceToTireFrictionPairs_setup_mut(physx_PxVehicleDrivableSurfaceToTireFrictionPairs_Pod* self__pod, uint32_t nbTireTypes, uint32_t nbSurfaceTypes, physx_PxMaterial_Pod const** drivableSurfaceMaterials_pod, physx_PxVehicleDrivableSurfaceType_Pod const* drivableSurfaceTypes_pod) {
physx::PxVehicleDrivableSurfaceToTireFrictionPairs* self_ = reinterpret_cast<physx::PxVehicleDrivableSurfaceToTireFrictionPairs*>(self__pod);
physx::PxMaterial const** drivableSurfaceMaterials = reinterpret_cast<physx::PxMaterial const**>(drivableSurfaceMaterials_pod);
physx::PxVehicleDrivableSurfaceType const* drivableSurfaceTypes = reinterpret_cast<physx::PxVehicleDrivableSurfaceType const*>(drivableSurfaceTypes_pod);
self_->setup(nbTireTypes, nbSurfaceTypes, drivableSurfaceMaterials, drivableSurfaceTypes);
}

void PxVehicleDrivableSurfaceToTireFrictionPairs_release_mut(physx_PxVehicleDrivableSurfaceToTireFrictionPairs_Pod* self__pod) {
physx::PxVehicleDrivableSurfaceToTireFrictionPairs* self_ = reinterpret_cast<physx::PxVehicleDrivableSurfaceToTireFrictionPairs*>(self__pod);
self_->release();
}

void PxVehicleDrivableSurfaceToTireFrictionPairs_setTypePairFriction_mut(physx_PxVehicleDrivableSurfaceToTireFrictionPairs_Pod* self__pod, uint32_t surfaceType, uint32_t tireType, float value) {
physx::PxVehicleDrivableSurfaceToTireFrictionPairs* self_ = reinterpret_cast<physx::PxVehicleDrivableSurfaceToTireFrictionPairs*>(self__pod);
self_->setTypePairFriction(surfaceType, tireType, value);
}

float PxVehicleDrivableSurfaceToTireFrictionPairs_getTypePairFriction(physx_PxVehicleDrivableSurfaceToTireFrictionPairs_Pod const* self__pod, uint32_t surfaceType, uint32_t tireType) {
physx::PxVehicleDrivableSurfaceToTireFrictionPairs const* self_ = reinterpret_cast<physx::PxVehicleDrivableSurfaceToTireFrictionPairs const*>(self__pod);
float returnValue = self_->getTypePairFriction(surfaceType, tireType);
return returnValue;
}

uint32_t PxVehicleDrivableSurfaceToTireFrictionPairs_getMaxNbSurfaceTypes(physx_PxVehicleDrivableSurfaceToTireFrictionPairs_Pod const* self__pod) {
physx::PxVehicleDrivableSurfaceToTireFrictionPairs const* self_ = reinterpret_cast<physx::PxVehicleDrivableSurfaceToTireFrictionPairs const*>(self__pod);
uint32_t returnValue = self_->getMaxNbSurfaceTypes();
return returnValue;
}

uint32_t PxVehicleDrivableSurfaceToTireFrictionPairs_getMaxNbTireTypes(physx_PxVehicleDrivableSurfaceToTireFrictionPairs_Pod const* self__pod) {
physx::PxVehicleDrivableSurfaceToTireFrictionPairs const* self_ = reinterpret_cast<physx::PxVehicleDrivableSurfaceToTireFrictionPairs const*>(self__pod);
uint32_t returnValue = self_->getMaxNbTireTypes();
return returnValue;
}

physx_PxWheelQueryResult_Pod PxWheelQueryResult_new() {
physx::PxWheelQueryResult returnValue;
physx_PxWheelQueryResult_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVehicleWheelConcurrentUpdateData_Pod PxVehicleWheelConcurrentUpdateData_new() {
physx::PxVehicleWheelConcurrentUpdateData returnValue;
physx_PxVehicleWheelConcurrentUpdateData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVehicleConcurrentUpdateData_Pod PxVehicleConcurrentUpdateData_new() {
physx::PxVehicleConcurrentUpdateData returnValue;
physx_PxVehicleConcurrentUpdateData_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void phys_PxVehicleSuspensionRaycasts(physx_PxBatchQuery_Pod* batchQuery_pod, uint32_t nbVehicles, physx_PxVehicleWheels_Pod** vehicles_pod, uint32_t nbSceneQueryResults, physx_PxRaycastQueryResult_Pod* sceneQueryResults_pod, bool const* vehiclesToRaycast) {
physx::PxBatchQuery* batchQuery = reinterpret_cast<physx::PxBatchQuery*>(batchQuery_pod);
physx::PxVehicleWheels** vehicles = reinterpret_cast<physx::PxVehicleWheels**>(vehicles_pod);
physx::PxRaycastQueryResult* sceneQueryResults = reinterpret_cast<physx::PxRaycastQueryResult*>(sceneQueryResults_pod);
PxVehicleSuspensionRaycasts(batchQuery, nbVehicles, vehicles, nbSceneQueryResults, sceneQueryResults, vehiclesToRaycast);
}

void phys_PxVehicleSuspensionSweeps(physx_PxBatchQuery_Pod* batchQuery_pod, uint32_t nbVehicles, physx_PxVehicleWheels_Pod** vehicles_pod, uint32_t nbSceneQueryResults, physx_PxSweepQueryResult_Pod* sceneQueryResults_pod, uint16_t nbHitsPerQuery, bool const* vehiclesToSweep, float sweepWidthScale, float sweepRadiusScale) {
physx::PxBatchQuery* batchQuery = reinterpret_cast<physx::PxBatchQuery*>(batchQuery_pod);
physx::PxVehicleWheels** vehicles = reinterpret_cast<physx::PxVehicleWheels**>(vehicles_pod);
physx::PxSweepQueryResult* sceneQueryResults = reinterpret_cast<physx::PxSweepQueryResult*>(sceneQueryResults_pod);
PxVehicleSuspensionSweeps(batchQuery, nbVehicles, vehicles, nbSceneQueryResults, sceneQueryResults, nbHitsPerQuery, vehiclesToSweep, sweepWidthScale, sweepRadiusScale);
}

uint32_t phys_PxVehicleModifyWheelContacts(physx_PxVehicleWheels_Pod const* vehicle_pod, uint32_t wheelId, float wheelTangentVelocityMultiplier, float maxImpulse, physx_PxContactModifyPair_Pod* contactModifyPair_pod) {
physx::PxVehicleWheels const& vehicle = reinterpret_cast<physx::PxVehicleWheels const&>(*vehicle_pod);
physx::PxContactModifyPair& contactModifyPair = reinterpret_cast<physx::PxContactModifyPair&>(*contactModifyPair_pod);
uint32_t returnValue = PxVehicleModifyWheelContacts(vehicle, wheelId, wheelTangentVelocityMultiplier, maxImpulse, contactModifyPair);
return returnValue;
}

void phys_PxVehicleUpdates(float timestep, physx_PxVec3_Pod const* gravity_pod, physx_PxVehicleDrivableSurfaceToTireFrictionPairs_Pod const* vehicleDrivableSurfaceToTireFrictionPairs_pod, uint32_t nbVehicles, physx_PxVehicleWheels_Pod** vehicles_pod, physx_PxVehicleWheelQueryResult_Pod* vehicleWheelQueryResults_pod, physx_PxVehicleConcurrentUpdateData_Pod* vehicleConcurrentUpdates_pod) {
physx::PxVec3 const& gravity = reinterpret_cast<physx::PxVec3 const&>(*gravity_pod);
physx::PxVehicleDrivableSurfaceToTireFrictionPairs const& vehicleDrivableSurfaceToTireFrictionPairs = reinterpret_cast<physx::PxVehicleDrivableSurfaceToTireFrictionPairs const&>(*vehicleDrivableSurfaceToTireFrictionPairs_pod);
physx::PxVehicleWheels** vehicles = reinterpret_cast<physx::PxVehicleWheels**>(vehicles_pod);
physx::PxVehicleWheelQueryResult* vehicleWheelQueryResults = reinterpret_cast<physx::PxVehicleWheelQueryResult*>(vehicleWheelQueryResults_pod);
physx::PxVehicleConcurrentUpdateData* vehicleConcurrentUpdates = reinterpret_cast<physx::PxVehicleConcurrentUpdateData*>(vehicleConcurrentUpdates_pod);
PxVehicleUpdates(timestep, gravity, vehicleDrivableSurfaceToTireFrictionPairs, nbVehicles, vehicles, vehicleWheelQueryResults, vehicleConcurrentUpdates);
}

void phys_PxVehiclePostUpdates(physx_PxVehicleConcurrentUpdateData_Pod const* vehicleConcurrentUpdates_pod, uint32_t nbVehicles, physx_PxVehicleWheels_Pod** vehicles_pod) {
physx::PxVehicleConcurrentUpdateData const* vehicleConcurrentUpdates = reinterpret_cast<physx::PxVehicleConcurrentUpdateData const*>(vehicleConcurrentUpdates_pod);
physx::PxVehicleWheels** vehicles = reinterpret_cast<physx::PxVehicleWheels**>(vehicles_pod);
PxVehiclePostUpdates(vehicleConcurrentUpdates, nbVehicles, vehicles);
}

void phys_PxVehicleShiftOrigin(physx_PxVec3_Pod const* shift_pod, uint32_t nbVehicles, physx_PxVehicleWheels_Pod** vehicles_pod) {
physx::PxVec3 const& shift = reinterpret_cast<physx::PxVec3 const&>(*shift_pod);
physx::PxVehicleWheels** vehicles = reinterpret_cast<physx::PxVehicleWheels**>(vehicles_pod);
PxVehicleShiftOrigin(shift, nbVehicles, vehicles);
}

void phys_PxVehicleUpdateSingleVehicleAndStoreTelemetryData(float timestep, physx_PxVec3_Pod const* gravity_pod, physx_PxVehicleDrivableSurfaceToTireFrictionPairs_Pod const* vehicleDrivableSurfaceToTireFrictionPairs_pod, physx_PxVehicleWheels_Pod* focusVehicle_pod, physx_PxVehicleWheelQueryResult_Pod* vehicleWheelQueryResults_pod, physx_PxVehicleTelemetryData_Pod* telemetryData_pod) {
physx::PxVec3 const& gravity = reinterpret_cast<physx::PxVec3 const&>(*gravity_pod);
physx::PxVehicleDrivableSurfaceToTireFrictionPairs const& vehicleDrivableSurfaceToTireFrictionPairs = reinterpret_cast<physx::PxVehicleDrivableSurfaceToTireFrictionPairs const&>(*vehicleDrivableSurfaceToTireFrictionPairs_pod);
physx::PxVehicleWheels* focusVehicle = reinterpret_cast<physx::PxVehicleWheels*>(focusVehicle_pod);
physx::PxVehicleWheelQueryResult* vehicleWheelQueryResults = reinterpret_cast<physx::PxVehicleWheelQueryResult*>(vehicleWheelQueryResults_pod);
physx::PxVehicleTelemetryData& telemetryData = reinterpret_cast<physx::PxVehicleTelemetryData&>(*telemetryData_pod);
PxVehicleUpdateSingleVehicleAndStoreTelemetryData(timestep, gravity, vehicleDrivableSurfaceToTireFrictionPairs, focusVehicle, vehicleWheelQueryResults, telemetryData);
}

physx_PxVehicleDriveSimDataNW_Pod PxVehicleDriveSimDataNW_new() {
physx::PxVehicleDriveSimDataNW returnValue;
physx_PxVehicleDriveSimDataNW_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

physx_PxVehicleDifferentialNWData_Pod const* PxVehicleDriveSimDataNW_getDiffData(physx_PxVehicleDriveSimDataNW_Pod const* self__pod) {
physx::PxVehicleDriveSimDataNW const* self_ = reinterpret_cast<physx::PxVehicleDriveSimDataNW const*>(self__pod);
physx::PxVehicleDifferentialNWData const& returnValue = self_->getDiffData();
physx_PxVehicleDifferentialNWData_Pod const* returnValue_pod = reinterpret_cast<physx_PxVehicleDifferentialNWData_Pod const*>(&returnValue);
return returnValue_pod;
}

void PxVehicleDriveSimDataNW_setDiffData_mut(physx_PxVehicleDriveSimDataNW_Pod* self__pod, physx_PxVehicleDifferentialNWData_Pod const* diff_pod) {
physx::PxVehicleDriveSimDataNW* self_ = reinterpret_cast<physx::PxVehicleDriveSimDataNW*>(self__pod);
physx::PxVehicleDifferentialNWData const& diff = reinterpret_cast<physx::PxVehicleDifferentialNWData const&>(*diff_pod);
self_->setDiffData(diff);
}

physx_PxVehicleDriveSimDataNW_Pod PxVehicleDriveSimDataNW_new_1(unsigned int anonymous_arg0_pod) {
physx::PxEMPTY anonymous_arg0 = (physx::PxEMPTY)anonymous_arg0_pod;
physx::PxVehicleDriveSimDataNW returnValue(anonymous_arg0);
physx_PxVehicleDriveSimDataNW_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxVehicleDriveSimDataNW_getBinaryMetaData_mut(physx_PxOutputStream_Pod* stream_pod) {
physx::PxOutputStream& stream = reinterpret_cast<physx::PxOutputStream&>(*stream_pod);
PxVehicleDriveSimDataNW::getBinaryMetaData(stream);
}

void PxVehicleDriveSimDataNW_delete(physx_PxVehicleDriveSimDataNW_Pod* self__pod) {
physx::PxVehicleDriveSimDataNW* self_ = reinterpret_cast<physx::PxVehicleDriveSimDataNW*>(self__pod);
delete self_;
}

physx_PxVehicleDriveNW_Pod* PxVehicleDriveNW_allocate_mut(uint32_t nbWheels) {
physx::PxVehicleDriveNW* returnValue = PxVehicleDriveNW::allocate(nbWheels);
physx_PxVehicleDriveNW_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleDriveNW_Pod*>(returnValue);
return returnValue_pod;
}

void PxVehicleDriveNW_free_mut(physx_PxVehicleDriveNW_Pod* self__pod) {
physx::PxVehicleDriveNW* self_ = reinterpret_cast<physx::PxVehicleDriveNW*>(self__pod);
self_->free();
}

void PxVehicleDriveNW_setup_mut(physx_PxVehicleDriveNW_Pod* self__pod, physx_PxPhysics_Pod* physics_pod, physx_PxRigidDynamic_Pod* vehActor_pod, physx_PxVehicleWheelsSimData_Pod const* wheelsData_pod, physx_PxVehicleDriveSimDataNW_Pod const* driveData_pod, uint32_t nbWheels) {
physx::PxVehicleDriveNW* self_ = reinterpret_cast<physx::PxVehicleDriveNW*>(self__pod);
physx::PxPhysics* physics = reinterpret_cast<physx::PxPhysics*>(physics_pod);
physx::PxRigidDynamic* vehActor = reinterpret_cast<physx::PxRigidDynamic*>(vehActor_pod);
physx::PxVehicleWheelsSimData const& wheelsData = reinterpret_cast<physx::PxVehicleWheelsSimData const&>(*wheelsData_pod);
physx::PxVehicleDriveSimDataNW const& driveData = reinterpret_cast<physx::PxVehicleDriveSimDataNW const&>(*driveData_pod);
self_->setup(physics, vehActor, wheelsData, driveData, nbWheels);
}

physx_PxVehicleDriveNW_Pod* PxVehicleDriveNW_create_mut(physx_PxPhysics_Pod* physics_pod, physx_PxRigidDynamic_Pod* vehActor_pod, physx_PxVehicleWheelsSimData_Pod const* wheelsData_pod, physx_PxVehicleDriveSimDataNW_Pod const* driveData_pod, uint32_t nbWheels) {
physx::PxPhysics* physics = reinterpret_cast<physx::PxPhysics*>(physics_pod);
physx::PxRigidDynamic* vehActor = reinterpret_cast<physx::PxRigidDynamic*>(vehActor_pod);
physx::PxVehicleWheelsSimData const& wheelsData = reinterpret_cast<physx::PxVehicleWheelsSimData const&>(*wheelsData_pod);
physx::PxVehicleDriveSimDataNW const& driveData = reinterpret_cast<physx::PxVehicleDriveSimDataNW const&>(*driveData_pod);
physx::PxVehicleDriveNW* returnValue = PxVehicleDriveNW::create(physics, vehActor, wheelsData, driveData, nbWheels);
physx_PxVehicleDriveNW_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleDriveNW_Pod*>(returnValue);
return returnValue_pod;
}

void PxVehicleDriveNW_setToRestState_mut(physx_PxVehicleDriveNW_Pod* self__pod) {
physx::PxVehicleDriveNW* self_ = reinterpret_cast<physx::PxVehicleDriveNW*>(self__pod);
self_->setToRestState();
}

physx_PxVehicleDriveNW_Pod* PxVehicleDriveNW_new_alloc(physx_PxBaseFlags_Pod baseFlags_pod) {
physx::PxBaseFlags baseFlags;
memcpy(&baseFlags, &baseFlags_pod, sizeof(baseFlags));
auto returnValue = new physx::PxVehicleDriveNW(baseFlags);
physx_PxVehicleDriveNW_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleDriveNW_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxVehicleDriveNW_Pod* PxVehicleDriveNW_new_alloc_1() {
auto returnValue = new physx::PxVehicleDriveNW();
physx_PxVehicleDriveNW_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleDriveNW_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxVehicleDriveNW_Pod* PxVehicleDriveNW_createObject_mut(unsigned char** address_pod, physx_PxDeserializationContext_Pod* context_pod) {
unsigned char*& address = *address_pod;
physx::PxDeserializationContext& context = reinterpret_cast<physx::PxDeserializationContext&>(*context_pod);
physx::PxVehicleDriveNW* returnValue = PxVehicleDriveNW::createObject(address, context);
physx_PxVehicleDriveNW_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleDriveNW_Pod*>(returnValue);
return returnValue_pod;
}

void PxVehicleDriveNW_getBinaryMetaData_mut(physx_PxOutputStream_Pod* stream_pod) {
physx::PxOutputStream& stream = reinterpret_cast<physx::PxOutputStream&>(*stream_pod);
PxVehicleDriveNW::getBinaryMetaData(stream);
}

char const* PxVehicleDriveNW_getConcreteTypeName(physx_PxVehicleDriveNW_Pod const* self__pod) {
physx::PxVehicleDriveNW const* self_ = reinterpret_cast<physx::PxVehicleDriveNW const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

bool PxVehicleDriveNW_isKindOf(physx_PxVehicleDriveNW_Pod const* self__pod, char const* name) {
physx::PxVehicleDriveNW const* self_ = reinterpret_cast<physx::PxVehicleDriveNW const*>(self__pod);
bool returnValue = self_->isKindOf(name);
return returnValue;
}

physx_PxVehicleDrive4WRawInputData_Pod* PxVehicleDrive4WRawInputData_new_alloc() {
auto returnValue = new physx::PxVehicleDrive4WRawInputData();
physx_PxVehicleDrive4WRawInputData_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleDrive4WRawInputData_Pod*>(returnValue);
return returnValue_pod;
}

void PxVehicleDrive4WRawInputData_delete(physx_PxVehicleDrive4WRawInputData_Pod* self__pod) {
physx::PxVehicleDrive4WRawInputData* self_ = reinterpret_cast<physx::PxVehicleDrive4WRawInputData*>(self__pod);
delete self_;
}

void PxVehicleDrive4WRawInputData_setDigitalAccel_mut(physx_PxVehicleDrive4WRawInputData_Pod* self__pod, bool accelKeyPressed) {
physx::PxVehicleDrive4WRawInputData* self_ = reinterpret_cast<physx::PxVehicleDrive4WRawInputData*>(self__pod);
self_->setDigitalAccel(accelKeyPressed);
}

void PxVehicleDrive4WRawInputData_setDigitalBrake_mut(physx_PxVehicleDrive4WRawInputData_Pod* self__pod, bool brakeKeyPressed) {
physx::PxVehicleDrive4WRawInputData* self_ = reinterpret_cast<physx::PxVehicleDrive4WRawInputData*>(self__pod);
self_->setDigitalBrake(brakeKeyPressed);
}

void PxVehicleDrive4WRawInputData_setDigitalHandbrake_mut(physx_PxVehicleDrive4WRawInputData_Pod* self__pod, bool handbrakeKeyPressed) {
physx::PxVehicleDrive4WRawInputData* self_ = reinterpret_cast<physx::PxVehicleDrive4WRawInputData*>(self__pod);
self_->setDigitalHandbrake(handbrakeKeyPressed);
}

void PxVehicleDrive4WRawInputData_setDigitalSteerLeft_mut(physx_PxVehicleDrive4WRawInputData_Pod* self__pod, bool steerLeftKeyPressed) {
physx::PxVehicleDrive4WRawInputData* self_ = reinterpret_cast<physx::PxVehicleDrive4WRawInputData*>(self__pod);
self_->setDigitalSteerLeft(steerLeftKeyPressed);
}

void PxVehicleDrive4WRawInputData_setDigitalSteerRight_mut(physx_PxVehicleDrive4WRawInputData_Pod* self__pod, bool steerRightKeyPressed) {
physx::PxVehicleDrive4WRawInputData* self_ = reinterpret_cast<physx::PxVehicleDrive4WRawInputData*>(self__pod);
self_->setDigitalSteerRight(steerRightKeyPressed);
}

bool PxVehicleDrive4WRawInputData_getDigitalAccel(physx_PxVehicleDrive4WRawInputData_Pod const* self__pod) {
physx::PxVehicleDrive4WRawInputData const* self_ = reinterpret_cast<physx::PxVehicleDrive4WRawInputData const*>(self__pod);
bool returnValue = self_->getDigitalAccel();
return returnValue;
}

bool PxVehicleDrive4WRawInputData_getDigitalBrake(physx_PxVehicleDrive4WRawInputData_Pod const* self__pod) {
physx::PxVehicleDrive4WRawInputData const* self_ = reinterpret_cast<physx::PxVehicleDrive4WRawInputData const*>(self__pod);
bool returnValue = self_->getDigitalBrake();
return returnValue;
}

bool PxVehicleDrive4WRawInputData_getDigitalHandbrake(physx_PxVehicleDrive4WRawInputData_Pod const* self__pod) {
physx::PxVehicleDrive4WRawInputData const* self_ = reinterpret_cast<physx::PxVehicleDrive4WRawInputData const*>(self__pod);
bool returnValue = self_->getDigitalHandbrake();
return returnValue;
}

bool PxVehicleDrive4WRawInputData_getDigitalSteerLeft(physx_PxVehicleDrive4WRawInputData_Pod const* self__pod) {
physx::PxVehicleDrive4WRawInputData const* self_ = reinterpret_cast<physx::PxVehicleDrive4WRawInputData const*>(self__pod);
bool returnValue = self_->getDigitalSteerLeft();
return returnValue;
}

bool PxVehicleDrive4WRawInputData_getDigitalSteerRight(physx_PxVehicleDrive4WRawInputData_Pod const* self__pod) {
physx::PxVehicleDrive4WRawInputData const* self_ = reinterpret_cast<physx::PxVehicleDrive4WRawInputData const*>(self__pod);
bool returnValue = self_->getDigitalSteerRight();
return returnValue;
}

void PxVehicleDrive4WRawInputData_setAnalogAccel_mut(physx_PxVehicleDrive4WRawInputData_Pod* self__pod, float accel) {
physx::PxVehicleDrive4WRawInputData* self_ = reinterpret_cast<physx::PxVehicleDrive4WRawInputData*>(self__pod);
self_->setAnalogAccel(accel);
}

void PxVehicleDrive4WRawInputData_setAnalogBrake_mut(physx_PxVehicleDrive4WRawInputData_Pod* self__pod, float brake) {
physx::PxVehicleDrive4WRawInputData* self_ = reinterpret_cast<physx::PxVehicleDrive4WRawInputData*>(self__pod);
self_->setAnalogBrake(brake);
}

void PxVehicleDrive4WRawInputData_setAnalogHandbrake_mut(physx_PxVehicleDrive4WRawInputData_Pod* self__pod, float handbrake) {
physx::PxVehicleDrive4WRawInputData* self_ = reinterpret_cast<physx::PxVehicleDrive4WRawInputData*>(self__pod);
self_->setAnalogHandbrake(handbrake);
}

void PxVehicleDrive4WRawInputData_setAnalogSteer_mut(physx_PxVehicleDrive4WRawInputData_Pod* self__pod, float steer) {
physx::PxVehicleDrive4WRawInputData* self_ = reinterpret_cast<physx::PxVehicleDrive4WRawInputData*>(self__pod);
self_->setAnalogSteer(steer);
}

float PxVehicleDrive4WRawInputData_getAnalogAccel(physx_PxVehicleDrive4WRawInputData_Pod const* self__pod) {
physx::PxVehicleDrive4WRawInputData const* self_ = reinterpret_cast<physx::PxVehicleDrive4WRawInputData const*>(self__pod);
float returnValue = self_->getAnalogAccel();
return returnValue;
}

float PxVehicleDrive4WRawInputData_getAnalogBrake(physx_PxVehicleDrive4WRawInputData_Pod const* self__pod) {
physx::PxVehicleDrive4WRawInputData const* self_ = reinterpret_cast<physx::PxVehicleDrive4WRawInputData const*>(self__pod);
float returnValue = self_->getAnalogBrake();
return returnValue;
}

float PxVehicleDrive4WRawInputData_getAnalogHandbrake(physx_PxVehicleDrive4WRawInputData_Pod const* self__pod) {
physx::PxVehicleDrive4WRawInputData const* self_ = reinterpret_cast<physx::PxVehicleDrive4WRawInputData const*>(self__pod);
float returnValue = self_->getAnalogHandbrake();
return returnValue;
}

float PxVehicleDrive4WRawInputData_getAnalogSteer(physx_PxVehicleDrive4WRawInputData_Pod const* self__pod) {
physx::PxVehicleDrive4WRawInputData const* self_ = reinterpret_cast<physx::PxVehicleDrive4WRawInputData const*>(self__pod);
float returnValue = self_->getAnalogSteer();
return returnValue;
}

void PxVehicleDrive4WRawInputData_setGearUp_mut(physx_PxVehicleDrive4WRawInputData_Pod* self__pod, bool gearUpKeyPressed) {
physx::PxVehicleDrive4WRawInputData* self_ = reinterpret_cast<physx::PxVehicleDrive4WRawInputData*>(self__pod);
self_->setGearUp(gearUpKeyPressed);
}

void PxVehicleDrive4WRawInputData_setGearDown_mut(physx_PxVehicleDrive4WRawInputData_Pod* self__pod, bool gearDownKeyPressed) {
physx::PxVehicleDrive4WRawInputData* self_ = reinterpret_cast<physx::PxVehicleDrive4WRawInputData*>(self__pod);
self_->setGearDown(gearDownKeyPressed);
}

bool PxVehicleDrive4WRawInputData_getGearUp(physx_PxVehicleDrive4WRawInputData_Pod const* self__pod) {
physx::PxVehicleDrive4WRawInputData const* self_ = reinterpret_cast<physx::PxVehicleDrive4WRawInputData const*>(self__pod);
bool returnValue = self_->getGearUp();
return returnValue;
}

bool PxVehicleDrive4WRawInputData_getGearDown(physx_PxVehicleDrive4WRawInputData_Pod const* self__pod) {
physx::PxVehicleDrive4WRawInputData const* self_ = reinterpret_cast<physx::PxVehicleDrive4WRawInputData const*>(self__pod);
bool returnValue = self_->getGearDown();
return returnValue;
}

void phys_PxVehicleDrive4WSmoothDigitalRawInputsAndSetAnalogInputs(physx_PxVehicleKeySmoothingData_Pod const* keySmoothing_pod, PxFixedSizeLookupTable_8__Pod const* steerVsForwardSpeedTable_pod, physx_PxVehicleDrive4WRawInputData_Pod const* rawInputData_pod, float timestep, bool isVehicleInAir, physx_PxVehicleDrive4W_Pod* focusVehicle_pod) {
physx::PxVehicleKeySmoothingData const& keySmoothing = reinterpret_cast<physx::PxVehicleKeySmoothingData const&>(*keySmoothing_pod);
PxFixedSizeLookupTable<8> const& steerVsForwardSpeedTable = reinterpret_cast<PxFixedSizeLookupTable<8> const&>(*steerVsForwardSpeedTable_pod);
physx::PxVehicleDrive4WRawInputData const& rawInputData = reinterpret_cast<physx::PxVehicleDrive4WRawInputData const&>(*rawInputData_pod);
physx::PxVehicleDrive4W& focusVehicle = reinterpret_cast<physx::PxVehicleDrive4W&>(*focusVehicle_pod);
PxVehicleDrive4WSmoothDigitalRawInputsAndSetAnalogInputs(keySmoothing, steerVsForwardSpeedTable, rawInputData, timestep, isVehicleInAir, focusVehicle);
}

void phys_PxVehicleDrive4WSmoothAnalogRawInputsAndSetAnalogInputs(physx_PxVehiclePadSmoothingData_Pod const* padSmoothing_pod, PxFixedSizeLookupTable_8__Pod const* steerVsForwardSpeedTable_pod, physx_PxVehicleDrive4WRawInputData_Pod const* rawInputData_pod, float timestep, bool isVehicleInAir, physx_PxVehicleDrive4W_Pod* focusVehicle_pod) {
physx::PxVehiclePadSmoothingData const& padSmoothing = reinterpret_cast<physx::PxVehiclePadSmoothingData const&>(*padSmoothing_pod);
PxFixedSizeLookupTable<8> const& steerVsForwardSpeedTable = reinterpret_cast<PxFixedSizeLookupTable<8> const&>(*steerVsForwardSpeedTable_pod);
physx::PxVehicleDrive4WRawInputData const& rawInputData = reinterpret_cast<physx::PxVehicleDrive4WRawInputData const&>(*rawInputData_pod);
physx::PxVehicleDrive4W& focusVehicle = reinterpret_cast<physx::PxVehicleDrive4W&>(*focusVehicle_pod);
PxVehicleDrive4WSmoothAnalogRawInputsAndSetAnalogInputs(padSmoothing, steerVsForwardSpeedTable, rawInputData, timestep, isVehicleInAir, focusVehicle);
}

physx_PxVehicleDriveNWRawInputData_Pod* PxVehicleDriveNWRawInputData_new_alloc() {
auto returnValue = new physx::PxVehicleDriveNWRawInputData();
physx_PxVehicleDriveNWRawInputData_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleDriveNWRawInputData_Pod*>(returnValue);
return returnValue_pod;
}

void PxVehicleDriveNWRawInputData_delete(physx_PxVehicleDriveNWRawInputData_Pod* self__pod) {
physx::PxVehicleDriveNWRawInputData* self_ = reinterpret_cast<physx::PxVehicleDriveNWRawInputData*>(self__pod);
delete self_;
}

void phys_PxVehicleDriveNWSmoothDigitalRawInputsAndSetAnalogInputs(physx_PxVehicleKeySmoothingData_Pod const* keySmoothing_pod, PxFixedSizeLookupTable_8__Pod const* steerVsForwardSpeedTable_pod, physx_PxVehicleDriveNWRawInputData_Pod const* rawInputData_pod, float timestep, bool isVehicleInAir, physx_PxVehicleDriveNW_Pod* focusVehicle_pod) {
physx::PxVehicleKeySmoothingData const& keySmoothing = reinterpret_cast<physx::PxVehicleKeySmoothingData const&>(*keySmoothing_pod);
PxFixedSizeLookupTable<8> const& steerVsForwardSpeedTable = reinterpret_cast<PxFixedSizeLookupTable<8> const&>(*steerVsForwardSpeedTable_pod);
physx::PxVehicleDriveNWRawInputData const& rawInputData = reinterpret_cast<physx::PxVehicleDriveNWRawInputData const&>(*rawInputData_pod);
physx::PxVehicleDriveNW& focusVehicle = reinterpret_cast<physx::PxVehicleDriveNW&>(*focusVehicle_pod);
PxVehicleDriveNWSmoothDigitalRawInputsAndSetAnalogInputs(keySmoothing, steerVsForwardSpeedTable, rawInputData, timestep, isVehicleInAir, focusVehicle);
}

void phys_PxVehicleDriveNWSmoothAnalogRawInputsAndSetAnalogInputs(physx_PxVehiclePadSmoothingData_Pod const* padSmoothing_pod, PxFixedSizeLookupTable_8__Pod const* steerVsForwardSpeedTable_pod, physx_PxVehicleDriveNWRawInputData_Pod const* rawInputData_pod, float timestep, bool isVehicleInAir, physx_PxVehicleDriveNW_Pod* focusVehicle_pod) {
physx::PxVehiclePadSmoothingData const& padSmoothing = reinterpret_cast<physx::PxVehiclePadSmoothingData const&>(*padSmoothing_pod);
PxFixedSizeLookupTable<8> const& steerVsForwardSpeedTable = reinterpret_cast<PxFixedSizeLookupTable<8> const&>(*steerVsForwardSpeedTable_pod);
physx::PxVehicleDriveNWRawInputData const& rawInputData = reinterpret_cast<physx::PxVehicleDriveNWRawInputData const&>(*rawInputData_pod);
physx::PxVehicleDriveNW& focusVehicle = reinterpret_cast<physx::PxVehicleDriveNW&>(*focusVehicle_pod);
PxVehicleDriveNWSmoothAnalogRawInputsAndSetAnalogInputs(padSmoothing, steerVsForwardSpeedTable, rawInputData, timestep, isVehicleInAir, focusVehicle);
}

physx_PxVehicleDriveTankRawInputData_Pod* PxVehicleDriveTankRawInputData_new_alloc(unsigned int mode_pod) {
PxVehicleDriveTankControlModel::Enum mode = (PxVehicleDriveTankControlModel::Enum)mode_pod;
auto returnValue = new physx::PxVehicleDriveTankRawInputData(mode);
physx_PxVehicleDriveTankRawInputData_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleDriveTankRawInputData_Pod*>(returnValue);
return returnValue_pod;
}

void PxVehicleDriveTankRawInputData_delete(physx_PxVehicleDriveTankRawInputData_Pod* self__pod) {
physx::PxVehicleDriveTankRawInputData* self_ = reinterpret_cast<physx::PxVehicleDriveTankRawInputData*>(self__pod);
delete self_;
}

unsigned int PxVehicleDriveTankRawInputData_getDriveModel(physx_PxVehicleDriveTankRawInputData_Pod const* self__pod) {
physx::PxVehicleDriveTankRawInputData const* self_ = reinterpret_cast<physx::PxVehicleDriveTankRawInputData const*>(self__pod);
PxVehicleDriveTankControlModel::Enum returnValue = self_->getDriveModel();
unsigned int returnValue_pod = (unsigned int)returnValue;
return returnValue_pod;
}

void PxVehicleDriveTankRawInputData_setDigitalAccel_mut(physx_PxVehicleDriveTankRawInputData_Pod* self__pod, bool b) {
physx::PxVehicleDriveTankRawInputData* self_ = reinterpret_cast<physx::PxVehicleDriveTankRawInputData*>(self__pod);
self_->setDigitalAccel(b);
}

void PxVehicleDriveTankRawInputData_setDigitalLeftThrust_mut(physx_PxVehicleDriveTankRawInputData_Pod* self__pod, bool b) {
physx::PxVehicleDriveTankRawInputData* self_ = reinterpret_cast<physx::PxVehicleDriveTankRawInputData*>(self__pod);
self_->setDigitalLeftThrust(b);
}

void PxVehicleDriveTankRawInputData_setDigitalRightThrust_mut(physx_PxVehicleDriveTankRawInputData_Pod* self__pod, bool b) {
physx::PxVehicleDriveTankRawInputData* self_ = reinterpret_cast<physx::PxVehicleDriveTankRawInputData*>(self__pod);
self_->setDigitalRightThrust(b);
}

void PxVehicleDriveTankRawInputData_setDigitalLeftBrake_mut(physx_PxVehicleDriveTankRawInputData_Pod* self__pod, bool b) {
physx::PxVehicleDriveTankRawInputData* self_ = reinterpret_cast<physx::PxVehicleDriveTankRawInputData*>(self__pod);
self_->setDigitalLeftBrake(b);
}

void PxVehicleDriveTankRawInputData_setDigitalRightBrake_mut(physx_PxVehicleDriveTankRawInputData_Pod* self__pod, bool b) {
physx::PxVehicleDriveTankRawInputData* self_ = reinterpret_cast<physx::PxVehicleDriveTankRawInputData*>(self__pod);
self_->setDigitalRightBrake(b);
}

bool PxVehicleDriveTankRawInputData_getDigitalAccel(physx_PxVehicleDriveTankRawInputData_Pod const* self__pod) {
physx::PxVehicleDriveTankRawInputData const* self_ = reinterpret_cast<physx::PxVehicleDriveTankRawInputData const*>(self__pod);
bool returnValue = self_->getDigitalAccel();
return returnValue;
}

bool PxVehicleDriveTankRawInputData_getDigitalLeftThrust(physx_PxVehicleDriveTankRawInputData_Pod const* self__pod) {
physx::PxVehicleDriveTankRawInputData const* self_ = reinterpret_cast<physx::PxVehicleDriveTankRawInputData const*>(self__pod);
bool returnValue = self_->getDigitalLeftThrust();
return returnValue;
}

bool PxVehicleDriveTankRawInputData_getDigitalRightThrust(physx_PxVehicleDriveTankRawInputData_Pod const* self__pod) {
physx::PxVehicleDriveTankRawInputData const* self_ = reinterpret_cast<physx::PxVehicleDriveTankRawInputData const*>(self__pod);
bool returnValue = self_->getDigitalRightThrust();
return returnValue;
}

bool PxVehicleDriveTankRawInputData_getDigitalLeftBrake(physx_PxVehicleDriveTankRawInputData_Pod const* self__pod) {
physx::PxVehicleDriveTankRawInputData const* self_ = reinterpret_cast<physx::PxVehicleDriveTankRawInputData const*>(self__pod);
bool returnValue = self_->getDigitalLeftBrake();
return returnValue;
}

bool PxVehicleDriveTankRawInputData_getDigitalRightBrake(physx_PxVehicleDriveTankRawInputData_Pod const* self__pod) {
physx::PxVehicleDriveTankRawInputData const* self_ = reinterpret_cast<physx::PxVehicleDriveTankRawInputData const*>(self__pod);
bool returnValue = self_->getDigitalRightBrake();
return returnValue;
}

void PxVehicleDriveTankRawInputData_setAnalogAccel_mut(physx_PxVehicleDriveTankRawInputData_Pod* self__pod, float accel) {
physx::PxVehicleDriveTankRawInputData* self_ = reinterpret_cast<physx::PxVehicleDriveTankRawInputData*>(self__pod);
self_->setAnalogAccel(accel);
}

void PxVehicleDriveTankRawInputData_setAnalogLeftThrust_mut(physx_PxVehicleDriveTankRawInputData_Pod* self__pod, float leftThrust) {
physx::PxVehicleDriveTankRawInputData* self_ = reinterpret_cast<physx::PxVehicleDriveTankRawInputData*>(self__pod);
self_->setAnalogLeftThrust(leftThrust);
}

void PxVehicleDriveTankRawInputData_setAnalogRightThrust_mut(physx_PxVehicleDriveTankRawInputData_Pod* self__pod, float rightThrust) {
physx::PxVehicleDriveTankRawInputData* self_ = reinterpret_cast<physx::PxVehicleDriveTankRawInputData*>(self__pod);
self_->setAnalogRightThrust(rightThrust);
}

void PxVehicleDriveTankRawInputData_setAnalogLeftBrake_mut(physx_PxVehicleDriveTankRawInputData_Pod* self__pod, float leftBrake) {
physx::PxVehicleDriveTankRawInputData* self_ = reinterpret_cast<physx::PxVehicleDriveTankRawInputData*>(self__pod);
self_->setAnalogLeftBrake(leftBrake);
}

void PxVehicleDriveTankRawInputData_setAnalogRightBrake_mut(physx_PxVehicleDriveTankRawInputData_Pod* self__pod, float rightBrake) {
physx::PxVehicleDriveTankRawInputData* self_ = reinterpret_cast<physx::PxVehicleDriveTankRawInputData*>(self__pod);
self_->setAnalogRightBrake(rightBrake);
}

float PxVehicleDriveTankRawInputData_getAnalogAccel(physx_PxVehicleDriveTankRawInputData_Pod const* self__pod) {
physx::PxVehicleDriveTankRawInputData const* self_ = reinterpret_cast<physx::PxVehicleDriveTankRawInputData const*>(self__pod);
float returnValue = self_->getAnalogAccel();
return returnValue;
}

float PxVehicleDriveTankRawInputData_getAnalogLeftThrust(physx_PxVehicleDriveTankRawInputData_Pod const* self__pod) {
physx::PxVehicleDriveTankRawInputData const* self_ = reinterpret_cast<physx::PxVehicleDriveTankRawInputData const*>(self__pod);
float returnValue = self_->getAnalogLeftThrust();
return returnValue;
}

float PxVehicleDriveTankRawInputData_getAnalogRightThrust(physx_PxVehicleDriveTankRawInputData_Pod const* self__pod) {
physx::PxVehicleDriveTankRawInputData const* self_ = reinterpret_cast<physx::PxVehicleDriveTankRawInputData const*>(self__pod);
float returnValue = self_->getAnalogRightThrust();
return returnValue;
}

float PxVehicleDriveTankRawInputData_getAnalogLeftBrake(physx_PxVehicleDriveTankRawInputData_Pod const* self__pod) {
physx::PxVehicleDriveTankRawInputData const* self_ = reinterpret_cast<physx::PxVehicleDriveTankRawInputData const*>(self__pod);
float returnValue = self_->getAnalogLeftBrake();
return returnValue;
}

float PxVehicleDriveTankRawInputData_getAnalogRightBrake(physx_PxVehicleDriveTankRawInputData_Pod const* self__pod) {
physx::PxVehicleDriveTankRawInputData const* self_ = reinterpret_cast<physx::PxVehicleDriveTankRawInputData const*>(self__pod);
float returnValue = self_->getAnalogRightBrake();
return returnValue;
}

void PxVehicleDriveTankRawInputData_setGearUp_mut(physx_PxVehicleDriveTankRawInputData_Pod* self__pod, bool gearUp) {
physx::PxVehicleDriveTankRawInputData* self_ = reinterpret_cast<physx::PxVehicleDriveTankRawInputData*>(self__pod);
self_->setGearUp(gearUp);
}

void PxVehicleDriveTankRawInputData_setGearDown_mut(physx_PxVehicleDriveTankRawInputData_Pod* self__pod, bool gearDown) {
physx::PxVehicleDriveTankRawInputData* self_ = reinterpret_cast<physx::PxVehicleDriveTankRawInputData*>(self__pod);
self_->setGearDown(gearDown);
}

bool PxVehicleDriveTankRawInputData_getGearUp(physx_PxVehicleDriveTankRawInputData_Pod const* self__pod) {
physx::PxVehicleDriveTankRawInputData const* self_ = reinterpret_cast<physx::PxVehicleDriveTankRawInputData const*>(self__pod);
bool returnValue = self_->getGearUp();
return returnValue;
}

bool PxVehicleDriveTankRawInputData_getGearDown(physx_PxVehicleDriveTankRawInputData_Pod const* self__pod) {
physx::PxVehicleDriveTankRawInputData const* self_ = reinterpret_cast<physx::PxVehicleDriveTankRawInputData const*>(self__pod);
bool returnValue = self_->getGearDown();
return returnValue;
}

void phys_PxVehicleDriveTankSmoothDigitalRawInputsAndSetAnalogInputs(physx_PxVehicleKeySmoothingData_Pod const* keySmoothing_pod, physx_PxVehicleDriveTankRawInputData_Pod const* rawInputData_pod, float timestep, physx_PxVehicleDriveTank_Pod* focusVehicle_pod) {
physx::PxVehicleKeySmoothingData const& keySmoothing = reinterpret_cast<physx::PxVehicleKeySmoothingData const&>(*keySmoothing_pod);
physx::PxVehicleDriveTankRawInputData const& rawInputData = reinterpret_cast<physx::PxVehicleDriveTankRawInputData const&>(*rawInputData_pod);
physx::PxVehicleDriveTank& focusVehicle = reinterpret_cast<physx::PxVehicleDriveTank&>(*focusVehicle_pod);
PxVehicleDriveTankSmoothDigitalRawInputsAndSetAnalogInputs(keySmoothing, rawInputData, timestep, focusVehicle);
}

void phys_PxVehicleDriveTankSmoothAnalogRawInputsAndSetAnalogInputs(physx_PxVehiclePadSmoothingData_Pod const* padSmoothing_pod, physx_PxVehicleDriveTankRawInputData_Pod const* rawInputData_pod, float timestep, physx_PxVehicleDriveTank_Pod* focusVehicle_pod) {
physx::PxVehiclePadSmoothingData const& padSmoothing = reinterpret_cast<physx::PxVehiclePadSmoothingData const&>(*padSmoothing_pod);
physx::PxVehicleDriveTankRawInputData const& rawInputData = reinterpret_cast<physx::PxVehicleDriveTankRawInputData const&>(*rawInputData_pod);
physx::PxVehicleDriveTank& focusVehicle = reinterpret_cast<physx::PxVehicleDriveTank&>(*focusVehicle_pod);
PxVehicleDriveTankSmoothAnalogRawInputsAndSetAnalogInputs(padSmoothing, rawInputData, timestep, focusVehicle);
}

void phys_PxVehicle4WEnable3WTadpoleMode(physx_PxVehicleWheelsSimData_Pod* wheelsSimData_pod, physx_PxVehicleWheelsDynData_Pod* wheelsDynData_pod, physx_PxVehicleDriveSimData4W_Pod* driveSimData_pod) {
physx::PxVehicleWheelsSimData& wheelsSimData = reinterpret_cast<physx::PxVehicleWheelsSimData&>(*wheelsSimData_pod);
physx::PxVehicleWheelsDynData& wheelsDynData = reinterpret_cast<physx::PxVehicleWheelsDynData&>(*wheelsDynData_pod);
physx::PxVehicleDriveSimData4W& driveSimData = reinterpret_cast<physx::PxVehicleDriveSimData4W&>(*driveSimData_pod);
PxVehicle4WEnable3WTadpoleMode(wheelsSimData, wheelsDynData, driveSimData);
}

void phys_PxVehicle4WEnable3WDeltaMode(physx_PxVehicleWheelsSimData_Pod* wheelsSimData_pod, physx_PxVehicleWheelsDynData_Pod* wheelsDynData_pod, physx_PxVehicleDriveSimData4W_Pod* driveSimData_pod) {
physx::PxVehicleWheelsSimData& wheelsSimData = reinterpret_cast<physx::PxVehicleWheelsSimData&>(*wheelsSimData_pod);
physx::PxVehicleWheelsDynData& wheelsDynData = reinterpret_cast<physx::PxVehicleWheelsDynData&>(*wheelsDynData_pod);
physx::PxVehicleDriveSimData4W& driveSimData = reinterpret_cast<physx::PxVehicleDriveSimData4W&>(*driveSimData_pod);
PxVehicle4WEnable3WDeltaMode(wheelsSimData, wheelsDynData, driveSimData);
}

void phys_PxVehicleComputeSprungMasses(uint32_t nbSprungMasses, physx_PxVec3_Pod const* sprungMassCoordinates_pod, physx_PxVec3_Pod const* centreOfMass_pod, float totalMass, uint32_t gravityDirection, float* sprungMasses) {
physx::PxVec3 const* sprungMassCoordinates = reinterpret_cast<physx::PxVec3 const*>(sprungMassCoordinates_pod);
physx::PxVec3 const& centreOfMass = reinterpret_cast<physx::PxVec3 const&>(*centreOfMass_pod);
PxVehicleComputeSprungMasses(nbSprungMasses, sprungMassCoordinates, centreOfMass, totalMass, gravityDirection, sprungMasses);
}

void phys_PxVehicleUpdateCMassLocalPose(physx_PxTransform_Pod const* oldCMassLocalPose_pod, physx_PxTransform_Pod const* newCMassLocalPose_pod, uint32_t gravityDirection, physx_PxVehicleWheels_Pod* vehicle_pod) {
physx::PxTransform const& oldCMassLocalPose = reinterpret_cast<physx::PxTransform const&>(*oldCMassLocalPose_pod);
physx::PxTransform const& newCMassLocalPose = reinterpret_cast<physx::PxTransform const&>(*newCMassLocalPose_pod);
physx::PxVehicleWheels* vehicle = reinterpret_cast<physx::PxVehicleWheels*>(vehicle_pod);
PxVehicleUpdateCMassLocalPose(oldCMassLocalPose, newCMassLocalPose, gravityDirection, vehicle);
}

physx_PxVehicleCopyDynamicsMap_Pod PxVehicleCopyDynamicsMap_new() {
physx::PxVehicleCopyDynamicsMap returnValue;
physx_PxVehicleCopyDynamicsMap_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void phys_PxVehicleCopyDynamicsData(physx_PxVehicleCopyDynamicsMap_Pod const* wheelMap_pod, physx_PxVehicleWheels_Pod const* src_pod, physx_PxVehicleWheels_Pod* trg_pod) {
physx::PxVehicleCopyDynamicsMap const& wheelMap = reinterpret_cast<physx::PxVehicleCopyDynamicsMap const&>(*wheelMap_pod);
physx::PxVehicleWheels const& src = reinterpret_cast<physx::PxVehicleWheels const&>(*src_pod);
physx::PxVehicleWheels* trg = reinterpret_cast<physx::PxVehicleWheels*>(trg_pod);
PxVehicleCopyDynamicsData(wheelMap, src, trg);
}

physx_PxVehicleGraphChannelDesc_Pod PxVehicleGraphChannelDesc_new() {
physx::PxVehicleGraphChannelDesc returnValue;
physx_PxVehicleGraphChannelDesc_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxVehicleGraph_setup_mut(physx_PxVehicleGraph_Pod* self__pod, physx_PxVehicleGraphDesc_Pod const* desc_pod, unsigned int graphType_pod) {
physx::PxVehicleGraph* self_ = reinterpret_cast<physx::PxVehicleGraph*>(self__pod);
physx::PxVehicleGraphDesc const& desc = reinterpret_cast<physx::PxVehicleGraphDesc const&>(*desc_pod);
PxVehicleGraphType::Enum graphType = (PxVehicleGraphType::Enum)graphType_pod;
self_->setup(desc, graphType);
}

void PxVehicleGraph_clearRecordedChannelData_mut(physx_PxVehicleGraph_Pod* self__pod) {
physx::PxVehicleGraph* self_ = reinterpret_cast<physx::PxVehicleGraph*>(self__pod);
self_->clearRecordedChannelData();
}

physx_PxVec3_Pod const* PxVehicleGraph_getBackgroundColor(physx_PxVehicleGraph_Pod const* self__pod) {
physx::PxVehicleGraph const* self_ = reinterpret_cast<physx::PxVehicleGraph const*>(self__pod);
physx::PxVec3 const& returnValue = self_->getBackgroundColor();
physx_PxVec3_Pod const* returnValue_pod = reinterpret_cast<physx_PxVec3_Pod const*>(&returnValue);
return returnValue_pod;
}

float PxVehicleGraph_getBackgroundAlpha(physx_PxVehicleGraph_Pod const* self__pod) {
physx::PxVehicleGraph const* self_ = reinterpret_cast<physx::PxVehicleGraph const*>(self__pod);
float returnValue = self_->getBackgroundAlpha();
return returnValue;
}

void PxVehicleGraph_getBackgroundCoords(physx_PxVehicleGraph_Pod const* self__pod, float* xMin_pod, float* yMin_pod, float* xMax_pod, float* yMax_pod) {
physx::PxVehicleGraph const* self_ = reinterpret_cast<physx::PxVehicleGraph const*>(self__pod);
float& xMin = *xMin_pod;
float& yMin = *yMin_pod;
float& xMax = *xMax_pod;
float& yMax = *yMax_pod;
self_->getBackgroundCoords(xMin, yMin, xMax, yMax);
}

void PxVehicleGraph_computeGraphChannel(physx_PxVehicleGraph_Pod const* self__pod, uint32_t channel, float* xy, physx_PxVec3_Pod* colors_pod, char* title) {
physx::PxVehicleGraph const* self_ = reinterpret_cast<physx::PxVehicleGraph const*>(self__pod);
physx::PxVec3* colors = reinterpret_cast<physx::PxVec3*>(colors_pod);
self_->computeGraphChannel(channel, xy, colors, title);
}

float PxVehicleGraph_getLatestValue(physx_PxVehicleGraph_Pod const* self__pod, uint32_t channel) {
physx::PxVehicleGraph const* self_ = reinterpret_cast<physx::PxVehicleGraph const*>(self__pod);
float returnValue = self_->getLatestValue(channel);
return returnValue;
}

physx_PxVehicleTelemetryData_Pod* PxVehicleTelemetryData_allocate_mut(uint32_t nbWheels) {
physx::PxVehicleTelemetryData* returnValue = PxVehicleTelemetryData::allocate(nbWheels);
physx_PxVehicleTelemetryData_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleTelemetryData_Pod*>(returnValue);
return returnValue_pod;
}

void PxVehicleTelemetryData_free_mut(physx_PxVehicleTelemetryData_Pod* self__pod) {
physx::PxVehicleTelemetryData* self_ = reinterpret_cast<physx::PxVehicleTelemetryData*>(self__pod);
self_->free();
}

void PxVehicleTelemetryData_setup_mut(physx_PxVehicleTelemetryData_Pod* self__pod, float graphSizeX, float graphSizeY, float engineGraphPosX, float engineGraphPosY, float const* wheelGraphPosX, float const* wheelGraphPosY, physx_PxVec3_Pod const* backGroundColor_pod, physx_PxVec3_Pod const* lineColorHigh_pod, physx_PxVec3_Pod const* lineColorLow_pod) {
physx::PxVehicleTelemetryData* self_ = reinterpret_cast<physx::PxVehicleTelemetryData*>(self__pod);
physx::PxVec3 const& backGroundColor = reinterpret_cast<physx::PxVec3 const&>(*backGroundColor_pod);
physx::PxVec3 const& lineColorHigh = reinterpret_cast<physx::PxVec3 const&>(*lineColorHigh_pod);
physx::PxVec3 const& lineColorLow = reinterpret_cast<physx::PxVec3 const&>(*lineColorLow_pod);
self_->setup(graphSizeX, graphSizeY, engineGraphPosX, engineGraphPosY, wheelGraphPosX, wheelGraphPosY, backGroundColor, lineColorHigh, lineColorLow);
}

void PxVehicleTelemetryData_clear_mut(physx_PxVehicleTelemetryData_Pod* self__pod) {
physx::PxVehicleTelemetryData* self_ = reinterpret_cast<physx::PxVehicleTelemetryData*>(self__pod);
self_->clear();
}

physx_PxVehicleGraph_Pod const* PxVehicleTelemetryData_getEngineGraph(physx_PxVehicleTelemetryData_Pod const* self__pod) {
physx::PxVehicleTelemetryData const* self_ = reinterpret_cast<physx::PxVehicleTelemetryData const*>(self__pod);
physx::PxVehicleGraph const& returnValue = self_->getEngineGraph();
physx_PxVehicleGraph_Pod const* returnValue_pod = reinterpret_cast<physx_PxVehicleGraph_Pod const*>(&returnValue);
return returnValue_pod;
}

uint32_t PxVehicleTelemetryData_getNbWheelGraphs(physx_PxVehicleTelemetryData_Pod const* self__pod) {
physx::PxVehicleTelemetryData const* self_ = reinterpret_cast<physx::PxVehicleTelemetryData const*>(self__pod);
uint32_t returnValue = self_->getNbWheelGraphs();
return returnValue;
}

physx_PxVehicleGraph_Pod const* PxVehicleTelemetryData_getWheelGraph(physx_PxVehicleTelemetryData_Pod const* self__pod, uint32_t k) {
physx::PxVehicleTelemetryData const* self_ = reinterpret_cast<physx::PxVehicleTelemetryData const*>(self__pod);
physx::PxVehicleGraph const& returnValue = self_->getWheelGraph(k);
physx_PxVehicleGraph_Pod const* returnValue_pod = reinterpret_cast<physx_PxVehicleGraph_Pod const*>(&returnValue);
return returnValue_pod;
}

physx_PxVec3_Pod const* PxVehicleTelemetryData_getTireforceAppPoints(physx_PxVehicleTelemetryData_Pod const* self__pod) {
physx::PxVehicleTelemetryData const* self_ = reinterpret_cast<physx::PxVehicleTelemetryData const*>(self__pod);
physx::PxVec3 const* returnValue = self_->getTireforceAppPoints();
physx_PxVec3_Pod const* returnValue_pod = reinterpret_cast<physx_PxVec3_Pod const*>(returnValue);
return returnValue_pod;
}

physx_PxVec3_Pod const* PxVehicleTelemetryData_getSuspforceAppPoints(physx_PxVehicleTelemetryData_Pod const* self__pod) {
physx::PxVehicleTelemetryData const* self_ = reinterpret_cast<physx::PxVehicleTelemetryData const*>(self__pod);
physx::PxVec3 const* returnValue = self_->getSuspforceAppPoints();
physx_PxVec3_Pod const* returnValue_pod = reinterpret_cast<physx_PxVec3_Pod const*>(returnValue);
return returnValue_pod;
}

physx_PxVehicleNoDrive_Pod* PxVehicleNoDrive_allocate_mut(uint32_t nbWheels) {
physx::PxVehicleNoDrive* returnValue = PxVehicleNoDrive::allocate(nbWheels);
physx_PxVehicleNoDrive_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleNoDrive_Pod*>(returnValue);
return returnValue_pod;
}

void PxVehicleNoDrive_free_mut(physx_PxVehicleNoDrive_Pod* self__pod) {
physx::PxVehicleNoDrive* self_ = reinterpret_cast<physx::PxVehicleNoDrive*>(self__pod);
self_->free();
}

void PxVehicleNoDrive_setup_mut(physx_PxVehicleNoDrive_Pod* self__pod, physx_PxPhysics_Pod* physics_pod, physx_PxRigidDynamic_Pod* vehActor_pod, physx_PxVehicleWheelsSimData_Pod const* wheelsData_pod) {
physx::PxVehicleNoDrive* self_ = reinterpret_cast<physx::PxVehicleNoDrive*>(self__pod);
physx::PxPhysics* physics = reinterpret_cast<physx::PxPhysics*>(physics_pod);
physx::PxRigidDynamic* vehActor = reinterpret_cast<physx::PxRigidDynamic*>(vehActor_pod);
physx::PxVehicleWheelsSimData const& wheelsData = reinterpret_cast<physx::PxVehicleWheelsSimData const&>(*wheelsData_pod);
self_->setup(physics, vehActor, wheelsData);
}

physx_PxVehicleNoDrive_Pod* PxVehicleNoDrive_create_mut(physx_PxPhysics_Pod* physics_pod, physx_PxRigidDynamic_Pod* vehActor_pod, physx_PxVehicleWheelsSimData_Pod const* wheelsData_pod) {
physx::PxPhysics* physics = reinterpret_cast<physx::PxPhysics*>(physics_pod);
physx::PxRigidDynamic* vehActor = reinterpret_cast<physx::PxRigidDynamic*>(vehActor_pod);
physx::PxVehicleWheelsSimData const& wheelsData = reinterpret_cast<physx::PxVehicleWheelsSimData const&>(*wheelsData_pod);
physx::PxVehicleNoDrive* returnValue = PxVehicleNoDrive::create(physics, vehActor, wheelsData);
physx_PxVehicleNoDrive_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleNoDrive_Pod*>(returnValue);
return returnValue_pod;
}

void PxVehicleNoDrive_setToRestState_mut(physx_PxVehicleNoDrive_Pod* self__pod) {
physx::PxVehicleNoDrive* self_ = reinterpret_cast<physx::PxVehicleNoDrive*>(self__pod);
self_->setToRestState();
}

void PxVehicleNoDrive_setBrakeTorque_mut(physx_PxVehicleNoDrive_Pod* self__pod, uint32_t id, float brakeTorque) {
physx::PxVehicleNoDrive* self_ = reinterpret_cast<physx::PxVehicleNoDrive*>(self__pod);
self_->setBrakeTorque(id, brakeTorque);
}

void PxVehicleNoDrive_setDriveTorque_mut(physx_PxVehicleNoDrive_Pod* self__pod, uint32_t id, float driveTorque) {
physx::PxVehicleNoDrive* self_ = reinterpret_cast<physx::PxVehicleNoDrive*>(self__pod);
self_->setDriveTorque(id, driveTorque);
}

void PxVehicleNoDrive_setSteerAngle_mut(physx_PxVehicleNoDrive_Pod* self__pod, uint32_t id, float steerAngle) {
physx::PxVehicleNoDrive* self_ = reinterpret_cast<physx::PxVehicleNoDrive*>(self__pod);
self_->setSteerAngle(id, steerAngle);
}

float PxVehicleNoDrive_getBrakeTorque(physx_PxVehicleNoDrive_Pod const* self__pod, uint32_t id) {
physx::PxVehicleNoDrive const* self_ = reinterpret_cast<physx::PxVehicleNoDrive const*>(self__pod);
float returnValue = self_->getBrakeTorque(id);
return returnValue;
}

float PxVehicleNoDrive_getDriveTorque(physx_PxVehicleNoDrive_Pod const* self__pod, uint32_t id) {
physx::PxVehicleNoDrive const* self_ = reinterpret_cast<physx::PxVehicleNoDrive const*>(self__pod);
float returnValue = self_->getDriveTorque(id);
return returnValue;
}

float PxVehicleNoDrive_getSteerAngle(physx_PxVehicleNoDrive_Pod const* self__pod, uint32_t id) {
physx::PxVehicleNoDrive const* self_ = reinterpret_cast<physx::PxVehicleNoDrive const*>(self__pod);
float returnValue = self_->getSteerAngle(id);
return returnValue;
}

physx_PxVehicleNoDrive_Pod* PxVehicleNoDrive_new_alloc(physx_PxBaseFlags_Pod baseFlags_pod) {
physx::PxBaseFlags baseFlags;
memcpy(&baseFlags, &baseFlags_pod, sizeof(baseFlags));
auto returnValue = new physx::PxVehicleNoDrive(baseFlags);
physx_PxVehicleNoDrive_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleNoDrive_Pod*>(returnValue);
return returnValue_pod;
}

void PxVehicleNoDrive_exportExtraData_mut(physx_PxVehicleNoDrive_Pod* self__pod, physx_PxSerializationContext_Pod* anonymous_arg0_pod) {
physx::PxVehicleNoDrive* self_ = reinterpret_cast<physx::PxVehicleNoDrive*>(self__pod);
physx::PxSerializationContext& anonymous_arg0 = reinterpret_cast<physx::PxSerializationContext&>(*anonymous_arg0_pod);
self_->exportExtraData(anonymous_arg0);
}

void PxVehicleNoDrive_importExtraData_mut(physx_PxVehicleNoDrive_Pod* self__pod, physx_PxDeserializationContext_Pod* anonymous_arg0_pod) {
physx::PxVehicleNoDrive* self_ = reinterpret_cast<physx::PxVehicleNoDrive*>(self__pod);
physx::PxDeserializationContext& anonymous_arg0 = reinterpret_cast<physx::PxDeserializationContext&>(*anonymous_arg0_pod);
self_->importExtraData(anonymous_arg0);
}

physx_PxVehicleNoDrive_Pod* PxVehicleNoDrive_createObject_mut(unsigned char** address_pod, physx_PxDeserializationContext_Pod* context_pod) {
unsigned char*& address = *address_pod;
physx::PxDeserializationContext& context = reinterpret_cast<physx::PxDeserializationContext&>(*context_pod);
physx::PxVehicleNoDrive* returnValue = PxVehicleNoDrive::createObject(address, context);
physx_PxVehicleNoDrive_Pod* returnValue_pod = reinterpret_cast<physx_PxVehicleNoDrive_Pod*>(returnValue);
return returnValue_pod;
}

void PxVehicleNoDrive_getBinaryMetaData_mut(physx_PxOutputStream_Pod* stream_pod) {
physx::PxOutputStream& stream = reinterpret_cast<physx::PxOutputStream&>(*stream_pod);
PxVehicleNoDrive::getBinaryMetaData(stream);
}

char const* PxVehicleNoDrive_getConcreteTypeName(physx_PxVehicleNoDrive_Pod const* self__pod) {
physx::PxVehicleNoDrive const* self_ = reinterpret_cast<physx::PxVehicleNoDrive const*>(self__pod);
char const* returnValue = self_->getConcreteTypeName();
return returnValue;
}

bool PxVehicleNoDrive_isKindOf(physx_PxVehicleNoDrive_Pod const* self__pod, char const* name) {
physx::PxVehicleNoDrive const* self_ = reinterpret_cast<physx::PxVehicleNoDrive const*>(self__pod);
bool returnValue = self_->isKindOf(name);
return returnValue;
}

uint32_t PxVehicleNoDrive_getNbSteerAngle(physx_PxVehicleNoDrive_Pod const* self__pod) {
physx::PxVehicleNoDrive const* self_ = reinterpret_cast<physx::PxVehicleNoDrive const*>(self__pod);
uint32_t returnValue = self_->getNbSteerAngle();
return returnValue;
}

uint32_t PxVehicleNoDrive_getNbDriveTorque(physx_PxVehicleNoDrive_Pod const* self__pod) {
physx::PxVehicleNoDrive const* self_ = reinterpret_cast<physx::PxVehicleNoDrive const*>(self__pod);
uint32_t returnValue = self_->getNbDriveTorque();
return returnValue;
}

uint32_t PxVehicleNoDrive_getNbBrakeTorque(physx_PxVehicleNoDrive_Pod const* self__pod) {
physx::PxVehicleNoDrive const* self_ = reinterpret_cast<physx::PxVehicleNoDrive const*>(self__pod);
uint32_t returnValue = self_->getNbBrakeTorque();
return returnValue;
}

void* PxProfilerCallback_zoneStart_mut(physx_PxProfilerCallback_Pod* self__pod, char const* eventName, bool detached, uint64_t contextId) {
physx::PxProfilerCallback* self_ = reinterpret_cast<physx::PxProfilerCallback*>(self__pod);
void* returnValue = self_->zoneStart(eventName, detached, contextId);
return returnValue;
}

void PxProfilerCallback_zoneEnd_mut(physx_PxProfilerCallback_Pod* self__pod, void* profilerData, char const* eventName, bool detached, uint64_t contextId) {
physx::PxProfilerCallback* self_ = reinterpret_cast<physx::PxProfilerCallback*>(self__pod);
self_->zoneEnd(profilerData, eventName, detached, contextId);
}

physx_PxProfileScoped_Pod* PxProfileScoped_new_alloc(physx_PxProfilerCallback_Pod* callback_pod, char const* eventName, bool detached, uint64_t contextId) {
physx::PxProfilerCallback* callback = reinterpret_cast<physx::PxProfilerCallback*>(callback_pod);
auto returnValue = new physx::PxProfileScoped(callback, eventName, detached, contextId);
physx_PxProfileScoped_Pod* returnValue_pod = reinterpret_cast<physx_PxProfileScoped_Pod*>(returnValue);
return returnValue_pod;
}

void PxProfileScoped_delete(physx_PxProfileScoped_Pod* self__pod) {
physx::PxProfileScoped* self_ = reinterpret_cast<physx::PxProfileScoped*>(self__pod);
delete self_;
}

bool PxPvd_connect_mut(physx_PxPvd_Pod* self__pod, physx_PxPvdTransport_Pod* transport_pod, physx_PxPvdInstrumentationFlags_Pod flags_pod) {
physx::PxPvd* self_ = reinterpret_cast<physx::PxPvd*>(self__pod);
physx::PxPvdTransport& transport = reinterpret_cast<physx::PxPvdTransport&>(*transport_pod);
physx::PxPvdInstrumentationFlags flags;
memcpy(&flags, &flags_pod, sizeof(flags));
bool returnValue = self_->connect(transport, flags);
return returnValue;
}

void PxPvd_disconnect_mut(physx_PxPvd_Pod* self__pod) {
physx::PxPvd* self_ = reinterpret_cast<physx::PxPvd*>(self__pod);
self_->disconnect();
}

bool PxPvd_isConnected_mut(physx_PxPvd_Pod* self__pod, bool useCachedStatus) {
physx::PxPvd* self_ = reinterpret_cast<physx::PxPvd*>(self__pod);
bool returnValue = self_->isConnected(useCachedStatus);
return returnValue;
}

physx_PxPvdTransport_Pod* PxPvd_getTransport_mut(physx_PxPvd_Pod* self__pod) {
physx::PxPvd* self_ = reinterpret_cast<physx::PxPvd*>(self__pod);
physx::PxPvdTransport* returnValue = self_->getTransport();
physx_PxPvdTransport_Pod* returnValue_pod = reinterpret_cast<physx_PxPvdTransport_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxPvdInstrumentationFlags_Pod PxPvd_getInstrumentationFlags_mut(physx_PxPvd_Pod* self__pod) {
physx::PxPvd* self_ = reinterpret_cast<physx::PxPvd*>(self__pod);
physx::PxPvdInstrumentationFlags returnValue = self_->getInstrumentationFlags();
physx_PxPvdInstrumentationFlags_Pod returnValue_pod;
memcpy(&returnValue_pod, &returnValue, sizeof(returnValue_pod));
return returnValue_pod;
}

void PxPvd_release_mut(physx_PxPvd_Pod* self__pod) {
physx::PxPvd* self_ = reinterpret_cast<physx::PxPvd*>(self__pod);
self_->release();
}

physx_PxPvd_Pod* phys_PxCreatePvd(physx_PxFoundation_Pod* foundation_pod) {
physx::PxFoundation& foundation = reinterpret_cast<physx::PxFoundation&>(*foundation_pod);
physx::PxPvd* returnValue = PxCreatePvd(foundation);
physx_PxPvd_Pod* returnValue_pod = reinterpret_cast<physx_PxPvd_Pod*>(returnValue);
return returnValue_pod;
}

bool PxPvdTransport_connect_mut(physx_PxPvdTransport_Pod* self__pod) {
physx::PxPvdTransport* self_ = reinterpret_cast<physx::PxPvdTransport*>(self__pod);
bool returnValue = self_->connect();
return returnValue;
}

void PxPvdTransport_disconnect_mut(physx_PxPvdTransport_Pod* self__pod) {
physx::PxPvdTransport* self_ = reinterpret_cast<physx::PxPvdTransport*>(self__pod);
self_->disconnect();
}

bool PxPvdTransport_isConnected_mut(physx_PxPvdTransport_Pod* self__pod) {
physx::PxPvdTransport* self_ = reinterpret_cast<physx::PxPvdTransport*>(self__pod);
bool returnValue = self_->isConnected();
return returnValue;
}

bool PxPvdTransport_write_mut(physx_PxPvdTransport_Pod* self__pod, unsigned char const* inBytes, uint32_t inLength) {
physx::PxPvdTransport* self_ = reinterpret_cast<physx::PxPvdTransport*>(self__pod);
bool returnValue = self_->write(inBytes, inLength);
return returnValue;
}

physx_PxPvdTransport_Pod* PxPvdTransport_lock_mut(physx_PxPvdTransport_Pod* self__pod) {
physx::PxPvdTransport* self_ = reinterpret_cast<physx::PxPvdTransport*>(self__pod);
physx::PxPvdTransport& returnValue = self_->lock();
physx_PxPvdTransport_Pod* returnValue_pod = reinterpret_cast<physx_PxPvdTransport_Pod*>(&returnValue);
return returnValue_pod;
}

void PxPvdTransport_unlock_mut(physx_PxPvdTransport_Pod* self__pod) {
physx::PxPvdTransport* self_ = reinterpret_cast<physx::PxPvdTransport*>(self__pod);
self_->unlock();
}

void PxPvdTransport_flush_mut(physx_PxPvdTransport_Pod* self__pod) {
physx::PxPvdTransport* self_ = reinterpret_cast<physx::PxPvdTransport*>(self__pod);
self_->flush();
}

uint64_t PxPvdTransport_getWrittenDataSize_mut(physx_PxPvdTransport_Pod* self__pod) {
physx::PxPvdTransport* self_ = reinterpret_cast<physx::PxPvdTransport*>(self__pod);
uint64_t returnValue = self_->getWrittenDataSize();
return returnValue;
}

void PxPvdTransport_release_mut(physx_PxPvdTransport_Pod* self__pod) {
physx::PxPvdTransport* self_ = reinterpret_cast<physx::PxPvdTransport*>(self__pod);
self_->release();
}

physx_PxPvdTransport_Pod* phys_PxDefaultPvdSocketTransportCreate(char const* host, int32_t port, uint32_t timeoutInMilliseconds) {
physx::PxPvdTransport* returnValue = PxDefaultPvdSocketTransportCreate(host, port, timeoutInMilliseconds);
physx_PxPvdTransport_Pod* returnValue_pod = reinterpret_cast<physx_PxPvdTransport_Pod*>(returnValue);
return returnValue_pod;
}

physx_PxPvdTransport_Pod* phys_PxDefaultPvdFileTransportCreate(char const* name) {
physx::PxPvdTransport* returnValue = PxDefaultPvdFileTransportCreate(name);
physx_PxPvdTransport_Pod* returnValue_pod = reinterpret_cast<physx_PxPvdTransport_Pod*>(returnValue);
return returnValue_pod;
}

}
