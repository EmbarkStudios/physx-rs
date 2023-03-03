using namespace physx;
#include "structgen_out.hpp"

static_assert(sizeof(physx::PxAllocatorCallback) == sizeof(physx_PxAllocatorCallback_Pod), "POD wrapper for `physx::PxAllocatorCallback` has incorrect size");
static_assert(sizeof(physx::PxAssertHandler) == sizeof(physx_PxAssertHandler_Pod), "POD wrapper for `physx::PxAssertHandler` has incorrect size");
static_assert(sizeof(physx::PxFoundation) == sizeof(physx_PxFoundation_Pod), "POD wrapper for `physx::PxFoundation` has incorrect size");
static_assert(sizeof(physx::PxAllocator) == sizeof(physx_PxAllocator_Pod), "POD wrapper for `physx::PxAllocator` has incorrect size");
static_assert(sizeof(physx::PxRawAllocator) == sizeof(physx_PxRawAllocator_Pod), "POD wrapper for `physx::PxRawAllocator` has incorrect size");
static_assert(sizeof(physx::PxVirtualAllocatorCallback) == sizeof(physx_PxVirtualAllocatorCallback_Pod), "POD wrapper for `physx::PxVirtualAllocatorCallback` has incorrect size");
static_assert(sizeof(physx::PxVirtualAllocator) == sizeof(physx_PxVirtualAllocator_Pod), "POD wrapper for `physx::PxVirtualAllocator` has incorrect size");
static_assert(sizeof(physx::PxUserAllocated) == sizeof(physx_PxUserAllocated_Pod), "POD wrapper for `physx::PxUserAllocated` has incorrect size");
static_assert(sizeof(physx::PxTempAllocatorChunk) == sizeof(physx_PxTempAllocatorChunk_Pod), "POD wrapper for `physx::PxTempAllocatorChunk` has incorrect size");
static_assert(sizeof(physx::PxTempAllocator) == sizeof(physx_PxTempAllocator_Pod), "POD wrapper for `physx::PxTempAllocator` has incorrect size");
static_assert(sizeof(physx::PxBitAndByte) == sizeof(physx_PxBitAndByte_Pod), "POD wrapper for `physx::PxBitAndByte` has incorrect size");
static_assert(sizeof(physx::PxBitMap) == sizeof(physx_PxBitMap_Pod), "POD wrapper for `physx::PxBitMap` has incorrect size");
static_assert(sizeof(physx::PxVec3) == sizeof(physx_PxVec3_Pod), "POD wrapper for `physx::PxVec3` has incorrect size");
static_assert(sizeof(physx::PxVec3Padded) == sizeof(physx_PxVec3Padded_Pod), "POD wrapper for `physx::PxVec3Padded` has incorrect size");
static_assert(sizeof(physx::PxQuat) == sizeof(physx_PxQuat_Pod), "POD wrapper for `physx::PxQuat` has incorrect size");
static_assert(sizeof(physx::PxTransform) == sizeof(physx_PxTransform_Pod), "POD wrapper for `physx::PxTransform` has incorrect size");
static_assert(sizeof(physx::PxTransformPadded) == sizeof(physx_PxTransformPadded_Pod), "POD wrapper for `physx::PxTransformPadded` has incorrect size");
static_assert(sizeof(physx::PxMat33) == sizeof(physx_PxMat33_Pod), "POD wrapper for `physx::PxMat33` has incorrect size");
static_assert(sizeof(physx::PxBounds3) == sizeof(physx_PxBounds3_Pod), "POD wrapper for `physx::PxBounds3` has incorrect size");
static_assert(sizeof(physx::PxErrorCallback) == sizeof(physx_PxErrorCallback_Pod), "POD wrapper for `physx::PxErrorCallback` has incorrect size");
static_assert(sizeof(physx::PxAllocationListener) == sizeof(physx_PxAllocationListener_Pod), "POD wrapper for `physx::PxAllocationListener` has incorrect size");
static_assert(sizeof(physx::PxBroadcastingAllocator) == sizeof(physx_PxBroadcastingAllocator_Pod), "POD wrapper for `physx::PxBroadcastingAllocator` has incorrect size");
static_assert(sizeof(physx::PxBroadcastingErrorCallback) == sizeof(physx_PxBroadcastingErrorCallback_Pod), "POD wrapper for `physx::PxBroadcastingErrorCallback` has incorrect size");
static_assert(sizeof(physx::PxInputStream) == sizeof(physx_PxInputStream_Pod), "POD wrapper for `physx::PxInputStream` has incorrect size");
static_assert(sizeof(physx::PxInputData) == sizeof(physx_PxInputData_Pod), "POD wrapper for `physx::PxInputData` has incorrect size");
static_assert(sizeof(physx::PxOutputStream) == sizeof(physx_PxOutputStream_Pod), "POD wrapper for `physx::PxOutputStream` has incorrect size");
static_assert(sizeof(physx::PxVec4) == sizeof(physx_PxVec4_Pod), "POD wrapper for `physx::PxVec4` has incorrect size");
static_assert(sizeof(physx::PxMat44) == sizeof(physx_PxMat44_Pod), "POD wrapper for `physx::PxMat44` has incorrect size");
static_assert(sizeof(physx::PxPlane) == sizeof(physx_PxPlane_Pod), "POD wrapper for `physx::PxPlane` has incorrect size");
static_assert(sizeof(physx::Interpolation) == sizeof(physx_Interpolation_Pod), "POD wrapper for `physx::Interpolation` has incorrect size");
static_assert(sizeof(physx::PxMutexImpl) == sizeof(physx_PxMutexImpl_Pod), "POD wrapper for `physx::PxMutexImpl` has incorrect size");
static_assert(sizeof(physx::PxReadWriteLock) == sizeof(physx_PxReadWriteLock_Pod), "POD wrapper for `physx::PxReadWriteLock` has incorrect size");
static_assert(sizeof(physx::PxProfilerCallback) == sizeof(physx_PxProfilerCallback_Pod), "POD wrapper for `physx::PxProfilerCallback` has incorrect size");
static_assert(sizeof(physx::PxProfileScoped) == sizeof(physx_PxProfileScoped_Pod), "POD wrapper for `physx::PxProfileScoped` has incorrect size");
static_assert(sizeof(physx::PxSListEntry) == sizeof(physx_PxSListEntry_Pod), "POD wrapper for `physx::PxSListEntry` has incorrect size");
static_assert(sizeof(physx::PxSListImpl) == sizeof(physx_PxSListImpl_Pod), "POD wrapper for `physx::PxSListImpl` has incorrect size");
static_assert(sizeof(physx::PxSyncImpl) == sizeof(physx_PxSyncImpl_Pod), "POD wrapper for `physx::PxSyncImpl` has incorrect size");
static_assert(sizeof(physx::PxRunnable) == sizeof(physx_PxRunnable_Pod), "POD wrapper for `physx::PxRunnable` has incorrect size");
static_assert(sizeof(physx::PxCounterFrequencyToTensOfNanos) == sizeof(physx_PxCounterFrequencyToTensOfNanos_Pod), "POD wrapper for `physx::PxCounterFrequencyToTensOfNanos` has incorrect size");
static_assert(sizeof(physx::PxTime) == sizeof(physx_PxTime_Pod), "POD wrapper for `physx::PxTime` has incorrect size");
static_assert(sizeof(physx::PxVec2) == sizeof(physx_PxVec2_Pod), "POD wrapper for `physx::PxVec2` has incorrect size");
static_assert(sizeof(physx::PxStridedData) == sizeof(physx_PxStridedData_Pod), "POD wrapper for `physx::PxStridedData` has incorrect size");
static_assert(sizeof(physx::PxBoundedData) == sizeof(physx_PxBoundedData_Pod), "POD wrapper for `physx::PxBoundedData` has incorrect size");
static_assert(sizeof(physx::PxDebugPoint) == sizeof(physx_PxDebugPoint_Pod), "POD wrapper for `physx::PxDebugPoint` has incorrect size");
static_assert(sizeof(physx::PxDebugLine) == sizeof(physx_PxDebugLine_Pod), "POD wrapper for `physx::PxDebugLine` has incorrect size");
static_assert(sizeof(physx::PxDebugTriangle) == sizeof(physx_PxDebugTriangle_Pod), "POD wrapper for `physx::PxDebugTriangle` has incorrect size");
static_assert(sizeof(physx::PxDebugText) == sizeof(physx_PxDebugText_Pod), "POD wrapper for `physx::PxDebugText` has incorrect size");
static_assert(sizeof(physx::PxRenderBuffer) == sizeof(physx_PxRenderBuffer_Pod), "POD wrapper for `physx::PxRenderBuffer` has incorrect size");
static_assert(sizeof(physx::PxProcessPxBaseCallback) == sizeof(physx_PxProcessPxBaseCallback_Pod), "POD wrapper for `physx::PxProcessPxBaseCallback` has incorrect size");
static_assert(sizeof(physx::PxSerializationContext) == sizeof(physx_PxSerializationContext_Pod), "POD wrapper for `physx::PxSerializationContext` has incorrect size");
static_assert(sizeof(physx::PxDeserializationContext) == sizeof(physx_PxDeserializationContext_Pod), "POD wrapper for `physx::PxDeserializationContext` has incorrect size");
static_assert(sizeof(physx::PxSerializationRegistry) == sizeof(physx_PxSerializationRegistry_Pod), "POD wrapper for `physx::PxSerializationRegistry` has incorrect size");
static_assert(sizeof(physx::PxCollection) == sizeof(physx_PxCollection_Pod), "POD wrapper for `physx::PxCollection` has incorrect size");
static_assert(sizeof(physx::PxBase) == sizeof(physx_PxBase_Pod), "POD wrapper for `physx::PxBase` has incorrect size");
static_assert(sizeof(physx::PxRefCounted) == sizeof(physx_PxRefCounted_Pod), "POD wrapper for `physx::PxRefCounted` has incorrect size");
static_assert(sizeof(physx::PxTolerancesScale) == sizeof(physx_PxTolerancesScale_Pod), "POD wrapper for `physx::PxTolerancesScale` has incorrect size");
static_assert(sizeof(physx::PxStringTable) == sizeof(physx_PxStringTable_Pod), "POD wrapper for `physx::PxStringTable` has incorrect size");
static_assert(sizeof(physx::PxSerializer) == sizeof(physx_PxSerializer_Pod), "POD wrapper for `physx::PxSerializer` has incorrect size");
static_assert(sizeof(physx::PxMetaDataEntry) == sizeof(physx_PxMetaDataEntry_Pod), "POD wrapper for `physx::PxMetaDataEntry` has incorrect size");
static_assert(sizeof(physx::PxInsertionCallback) == sizeof(physx_PxInsertionCallback_Pod), "POD wrapper for `physx::PxInsertionCallback` has incorrect size");
static_assert(sizeof(physx::PxTaskManager) == sizeof(physx_PxTaskManager_Pod), "POD wrapper for `physx::PxTaskManager` has incorrect size");
static_assert(sizeof(physx::PxCpuDispatcher) == sizeof(physx_PxCpuDispatcher_Pod), "POD wrapper for `physx::PxCpuDispatcher` has incorrect size");
static_assert(sizeof(physx::PxBaseTask) == sizeof(physx_PxBaseTask_Pod), "POD wrapper for `physx::PxBaseTask` has incorrect size");
static_assert(sizeof(physx::PxTask) == sizeof(physx_PxTask_Pod), "POD wrapper for `physx::PxTask` has incorrect size");
static_assert(sizeof(physx::PxLightCpuTask) == sizeof(physx_PxLightCpuTask_Pod), "POD wrapper for `physx::PxLightCpuTask` has incorrect size");
static_assert(sizeof(physx::PxGeometry) == sizeof(physx_PxGeometry_Pod), "POD wrapper for `physx::PxGeometry` has incorrect size");
static_assert(sizeof(physx::PxBoxGeometry) == sizeof(physx_PxBoxGeometry_Pod), "POD wrapper for `physx::PxBoxGeometry` has incorrect size");
static_assert(sizeof(physx::PxBVHRaycastCallback) == sizeof(physx_PxBVHRaycastCallback_Pod), "POD wrapper for `physx::PxBVHRaycastCallback` has incorrect size");
static_assert(sizeof(physx::PxBVHOverlapCallback) == sizeof(physx_PxBVHOverlapCallback_Pod), "POD wrapper for `physx::PxBVHOverlapCallback` has incorrect size");
static_assert(sizeof(physx::PxBVHTraversalCallback) == sizeof(physx_PxBVHTraversalCallback_Pod), "POD wrapper for `physx::PxBVHTraversalCallback` has incorrect size");
static_assert(sizeof(physx::PxBVH) == sizeof(physx_PxBVH_Pod), "POD wrapper for `physx::PxBVH` has incorrect size");
static_assert(sizeof(physx::PxCapsuleGeometry) == sizeof(physx_PxCapsuleGeometry_Pod), "POD wrapper for `physx::PxCapsuleGeometry` has incorrect size");
static_assert(sizeof(physx::PxHullPolygon) == sizeof(physx_PxHullPolygon_Pod), "POD wrapper for `physx::PxHullPolygon` has incorrect size");
static_assert(sizeof(physx::PxConvexMesh) == sizeof(physx_PxConvexMesh_Pod), "POD wrapper for `physx::PxConvexMesh` has incorrect size");
static_assert(sizeof(physx::PxMeshScale) == sizeof(physx_PxMeshScale_Pod), "POD wrapper for `physx::PxMeshScale` has incorrect size");
static_assert(sizeof(physx::PxConvexMeshGeometry) == sizeof(physx_PxConvexMeshGeometry_Pod), "POD wrapper for `physx::PxConvexMeshGeometry` has incorrect size");
static_assert(sizeof(physx::PxSphereGeometry) == sizeof(physx_PxSphereGeometry_Pod), "POD wrapper for `physx::PxSphereGeometry` has incorrect size");
static_assert(sizeof(physx::PxPlaneGeometry) == sizeof(physx_PxPlaneGeometry_Pod), "POD wrapper for `physx::PxPlaneGeometry` has incorrect size");
static_assert(sizeof(physx::PxTriangleMeshGeometry) == sizeof(physx_PxTriangleMeshGeometry_Pod), "POD wrapper for `physx::PxTriangleMeshGeometry` has incorrect size");
static_assert(sizeof(physx::PxHeightFieldGeometry) == sizeof(physx_PxHeightFieldGeometry_Pod), "POD wrapper for `physx::PxHeightFieldGeometry` has incorrect size");
static_assert(sizeof(physx::PxParticleSystemGeometry) == sizeof(physx_PxParticleSystemGeometry_Pod), "POD wrapper for `physx::PxParticleSystemGeometry` has incorrect size");
static_assert(sizeof(physx::PxHairSystemGeometry) == sizeof(physx_PxHairSystemGeometry_Pod), "POD wrapper for `physx::PxHairSystemGeometry` has incorrect size");
static_assert(sizeof(physx::PxTetrahedronMeshGeometry) == sizeof(physx_PxTetrahedronMeshGeometry_Pod), "POD wrapper for `physx::PxTetrahedronMeshGeometry` has incorrect size");
static_assert(sizeof(physx::PxQueryHit) == sizeof(physx_PxQueryHit_Pod), "POD wrapper for `physx::PxQueryHit` has incorrect size");
static_assert(sizeof(physx::PxLocationHit) == sizeof(physx_PxLocationHit_Pod), "POD wrapper for `physx::PxLocationHit` has incorrect size");
static_assert(sizeof(physx::PxGeomRaycastHit) == sizeof(physx_PxGeomRaycastHit_Pod), "POD wrapper for `physx::PxGeomRaycastHit` has incorrect size");
static_assert(sizeof(physx::PxGeomOverlapHit) == sizeof(physx_PxGeomOverlapHit_Pod), "POD wrapper for `physx::PxGeomOverlapHit` has incorrect size");
static_assert(sizeof(physx::PxGeomSweepHit) == sizeof(physx_PxGeomSweepHit_Pod), "POD wrapper for `physx::PxGeomSweepHit` has incorrect size");
static_assert(sizeof(physx::PxGeomIndexPair) == sizeof(physx_PxGeomIndexPair_Pod), "POD wrapper for `physx::PxGeomIndexPair` has incorrect size");
static_assert(sizeof(physx::PxQueryThreadContext) == sizeof(physx_PxQueryThreadContext_Pod), "POD wrapper for `physx::PxQueryThreadContext` has incorrect size");
static_assert(sizeof(physx::PxCustomGeometryType) == sizeof(physx_PxCustomGeometryType_Pod), "POD wrapper for `physx::PxCustomGeometryType` has incorrect size");
static_assert(sizeof(physx::PxCustomGeometryCallbacks) == sizeof(physx_PxCustomGeometryCallbacks_Pod), "POD wrapper for `physx::PxCustomGeometryCallbacks` has incorrect size");
static_assert(sizeof(physx::PxCustomGeometry) == sizeof(physx_PxCustomGeometry_Pod), "POD wrapper for `physx::PxCustomGeometry` has incorrect size");
static_assert(sizeof(physx::PxGeometryHolder) == sizeof(physx_PxGeometryHolder_Pod), "POD wrapper for `physx::PxGeometryHolder` has incorrect size");
static_assert(sizeof(physx::PxGeometryQuery) == sizeof(physx_PxGeometryQuery_Pod), "POD wrapper for `physx::PxGeometryQuery` has incorrect size");
static_assert(sizeof(physx::PxHeightFieldSample) == sizeof(physx_PxHeightFieldSample_Pod), "POD wrapper for `physx::PxHeightFieldSample` has incorrect size");
static_assert(sizeof(physx::PxHeightField) == sizeof(physx_PxHeightField_Pod), "POD wrapper for `physx::PxHeightField` has incorrect size");
static_assert(sizeof(physx::PxHeightFieldDesc) == sizeof(physx_PxHeightFieldDesc_Pod), "POD wrapper for `physx::PxHeightFieldDesc` has incorrect size");
static_assert(sizeof(physx::PxMeshQuery) == sizeof(physx_PxMeshQuery_Pod), "POD wrapper for `physx::PxMeshQuery` has incorrect size");
static_assert(sizeof(physx::PxSimpleTriangleMesh) == sizeof(physx_PxSimpleTriangleMesh_Pod), "POD wrapper for `physx::PxSimpleTriangleMesh` has incorrect size");
static_assert(sizeof(physx::PxTriangle) == sizeof(physx_PxTriangle_Pod), "POD wrapper for `physx::PxTriangle` has incorrect size");
static_assert(sizeof(physx::PxTrianglePadded) == sizeof(physx_PxTrianglePadded_Pod), "POD wrapper for `physx::PxTrianglePadded` has incorrect size");
static_assert(sizeof(physx::PxTriangleMesh) == sizeof(physx_PxTriangleMesh_Pod), "POD wrapper for `physx::PxTriangleMesh` has incorrect size");
static_assert(sizeof(physx::PxBVH34TriangleMesh) == sizeof(physx_PxBVH34TriangleMesh_Pod), "POD wrapper for `physx::PxBVH34TriangleMesh` has incorrect size");
static_assert(sizeof(physx::PxTetrahedron) == sizeof(physx_PxTetrahedron_Pod), "POD wrapper for `physx::PxTetrahedron` has incorrect size");
static_assert(sizeof(physx::PxSoftBodyAuxData) == sizeof(physx_PxSoftBodyAuxData_Pod), "POD wrapper for `physx::PxSoftBodyAuxData` has incorrect size");
static_assert(sizeof(physx::PxTetrahedronMesh) == sizeof(physx_PxTetrahedronMesh_Pod), "POD wrapper for `physx::PxTetrahedronMesh` has incorrect size");
static_assert(sizeof(physx::PxSoftBodyMesh) == sizeof(physx_PxSoftBodyMesh_Pod), "POD wrapper for `physx::PxSoftBodyMesh` has incorrect size");
static_assert(sizeof(physx::PxCollisionMeshMappingData) == sizeof(physx_PxCollisionMeshMappingData_Pod), "POD wrapper for `physx::PxCollisionMeshMappingData` has incorrect size");
static_assert(sizeof(physx::PxSoftBodyCollisionData) == sizeof(physx_PxSoftBodyCollisionData_Pod), "POD wrapper for `physx::PxSoftBodyCollisionData` has incorrect size");
static_assert(sizeof(physx::PxTetrahedronMeshData) == sizeof(physx_PxTetrahedronMeshData_Pod), "POD wrapper for `physx::PxTetrahedronMeshData` has incorrect size");
static_assert(sizeof(physx::PxSoftBodySimulationData) == sizeof(physx_PxSoftBodySimulationData_Pod), "POD wrapper for `physx::PxSoftBodySimulationData` has incorrect size");
static_assert(sizeof(physx::PxCollisionTetrahedronMeshData) == sizeof(physx_PxCollisionTetrahedronMeshData_Pod), "POD wrapper for `physx::PxCollisionTetrahedronMeshData` has incorrect size");
static_assert(sizeof(physx::PxSimulationTetrahedronMeshData) == sizeof(physx_PxSimulationTetrahedronMeshData_Pod), "POD wrapper for `physx::PxSimulationTetrahedronMeshData` has incorrect size");
static_assert(sizeof(physx::PxActor) == sizeof(physx_PxActor_Pod), "POD wrapper for `physx::PxActor` has incorrect size");
static_assert(sizeof(physx::PxAggregate) == sizeof(physx_PxAggregate_Pod), "POD wrapper for `physx::PxAggregate` has incorrect size");
static_assert(sizeof(physx::PxSpringModifiers) == sizeof(physx_PxSpringModifiers_Pod), "POD wrapper for `physx::PxSpringModifiers` has incorrect size");
static_assert(sizeof(physx::PxRestitutionModifiers) == sizeof(physx_PxRestitutionModifiers_Pod), "POD wrapper for `physx::PxRestitutionModifiers` has incorrect size");
static_assert(sizeof(physx::Px1DConstraintMods) == sizeof(physx_Px1DConstraintMods_Pod), "POD wrapper for `physx::Px1DConstraintMods` has incorrect size");
static_assert(sizeof(physx::Px1DConstraint) == sizeof(physx_Px1DConstraint_Pod), "POD wrapper for `physx::Px1DConstraint` has incorrect size");
static_assert(sizeof(physx::PxConstraintInvMassScale) == sizeof(physx_PxConstraintInvMassScale_Pod), "POD wrapper for `physx::PxConstraintInvMassScale` has incorrect size");
static_assert(sizeof(physx::PxConstraintVisualizer) == sizeof(physx_PxConstraintVisualizer_Pod), "POD wrapper for `physx::PxConstraintVisualizer` has incorrect size");
static_assert(sizeof(physx::PxConstraintConnector) == sizeof(physx_PxConstraintConnector_Pod), "POD wrapper for `physx::PxConstraintConnector` has incorrect size");
static_assert(sizeof(physx::PxContactPoint) == sizeof(physx_PxContactPoint_Pod), "POD wrapper for `physx::PxContactPoint` has incorrect size");
static_assert(sizeof(physx::PxSolverBody) == sizeof(physx_PxSolverBody_Pod), "POD wrapper for `physx::PxSolverBody` has incorrect size");
static_assert(sizeof(physx::PxSolverBodyData) == sizeof(physx_PxSolverBodyData_Pod), "POD wrapper for `physx::PxSolverBodyData` has incorrect size");
static_assert(sizeof(physx::PxConstraintBatchHeader) == sizeof(physx_PxConstraintBatchHeader_Pod), "POD wrapper for `physx::PxConstraintBatchHeader` has incorrect size");
static_assert(sizeof(physx::PxSolverConstraintDesc) == sizeof(physx_PxSolverConstraintDesc_Pod), "POD wrapper for `physx::PxSolverConstraintDesc` has incorrect size");
static_assert(sizeof(physx::PxSolverConstraintPrepDescBase) == sizeof(physx_PxSolverConstraintPrepDescBase_Pod), "POD wrapper for `physx::PxSolverConstraintPrepDescBase` has incorrect size");
static_assert(sizeof(physx::PxSolverConstraintPrepDesc) == sizeof(physx_PxSolverConstraintPrepDesc_Pod), "POD wrapper for `physx::PxSolverConstraintPrepDesc` has incorrect size");
static_assert(sizeof(physx::PxSolverContactDesc) == sizeof(physx_PxSolverContactDesc_Pod), "POD wrapper for `physx::PxSolverContactDesc` has incorrect size");
static_assert(sizeof(physx::PxConstraintAllocator) == sizeof(physx_PxConstraintAllocator_Pod), "POD wrapper for `physx::PxConstraintAllocator` has incorrect size");
static_assert(sizeof(physx::PxArticulationLimit) == sizeof(physx_PxArticulationLimit_Pod), "POD wrapper for `physx::PxArticulationLimit` has incorrect size");
static_assert(sizeof(physx::PxArticulationDrive) == sizeof(physx_PxArticulationDrive_Pod), "POD wrapper for `physx::PxArticulationDrive` has incorrect size");
static_assert(sizeof(physx::PxTGSSolverBodyVel) == sizeof(physx_PxTGSSolverBodyVel_Pod), "POD wrapper for `physx::PxTGSSolverBodyVel` has incorrect size");
static_assert(sizeof(physx::PxTGSSolverBodyTxInertia) == sizeof(physx_PxTGSSolverBodyTxInertia_Pod), "POD wrapper for `physx::PxTGSSolverBodyTxInertia` has incorrect size");
static_assert(sizeof(physx::PxTGSSolverBodyData) == sizeof(physx_PxTGSSolverBodyData_Pod), "POD wrapper for `physx::PxTGSSolverBodyData` has incorrect size");
static_assert(sizeof(physx::PxTGSSolverConstraintPrepDescBase) == sizeof(physx_PxTGSSolverConstraintPrepDescBase_Pod), "POD wrapper for `physx::PxTGSSolverConstraintPrepDescBase` has incorrect size");
static_assert(sizeof(physx::PxTGSSolverConstraintPrepDesc) == sizeof(physx_PxTGSSolverConstraintPrepDesc_Pod), "POD wrapper for `physx::PxTGSSolverConstraintPrepDesc` has incorrect size");
static_assert(sizeof(physx::PxTGSSolverContactDesc) == sizeof(physx_PxTGSSolverContactDesc_Pod), "POD wrapper for `physx::PxTGSSolverContactDesc` has incorrect size");
static_assert(sizeof(physx::PxArticulationTendonLimit) == sizeof(physx_PxArticulationTendonLimit_Pod), "POD wrapper for `physx::PxArticulationTendonLimit` has incorrect size");
static_assert(sizeof(physx::PxArticulationAttachment) == sizeof(physx_PxArticulationAttachment_Pod), "POD wrapper for `physx::PxArticulationAttachment` has incorrect size");
static_assert(sizeof(physx::PxArticulationTendonJoint) == sizeof(physx_PxArticulationTendonJoint_Pod), "POD wrapper for `physx::PxArticulationTendonJoint` has incorrect size");
static_assert(sizeof(physx::PxArticulationTendon) == sizeof(physx_PxArticulationTendon_Pod), "POD wrapper for `physx::PxArticulationTendon` has incorrect size");
static_assert(sizeof(physx::PxArticulationSpatialTendon) == sizeof(physx_PxArticulationSpatialTendon_Pod), "POD wrapper for `physx::PxArticulationSpatialTendon` has incorrect size");
static_assert(sizeof(physx::PxArticulationFixedTendon) == sizeof(physx_PxArticulationFixedTendon_Pod), "POD wrapper for `physx::PxArticulationFixedTendon` has incorrect size");
static_assert(sizeof(physx::PxSpatialForce) == sizeof(physx_PxSpatialForce_Pod), "POD wrapper for `physx::PxSpatialForce` has incorrect size");
static_assert(sizeof(physx::PxSpatialVelocity) == sizeof(physx_PxSpatialVelocity_Pod), "POD wrapper for `physx::PxSpatialVelocity` has incorrect size");
static_assert(sizeof(physx::PxArticulationRootLinkData) == sizeof(physx_PxArticulationRootLinkData_Pod), "POD wrapper for `physx::PxArticulationRootLinkData` has incorrect size");
static_assert(sizeof(physx::PxArticulationCache) == sizeof(physx_PxArticulationCache_Pod), "POD wrapper for `physx::PxArticulationCache` has incorrect size");
static_assert(sizeof(physx::PxArticulationSensor) == sizeof(physx_PxArticulationSensor_Pod), "POD wrapper for `physx::PxArticulationSensor` has incorrect size");
static_assert(sizeof(physx::PxArticulationReducedCoordinate) == sizeof(physx_PxArticulationReducedCoordinate_Pod), "POD wrapper for `physx::PxArticulationReducedCoordinate` has incorrect size");
static_assert(sizeof(physx::PxArticulationJointReducedCoordinate) == sizeof(physx_PxArticulationJointReducedCoordinate_Pod), "POD wrapper for `physx::PxArticulationJointReducedCoordinate` has incorrect size");
static_assert(sizeof(physx::PxShape) == sizeof(physx_PxShape_Pod), "POD wrapper for `physx::PxShape` has incorrect size");
static_assert(sizeof(physx::PxRigidActor) == sizeof(physx_PxRigidActor_Pod), "POD wrapper for `physx::PxRigidActor` has incorrect size");
static_assert(sizeof(physx::PxNodeIndex) == sizeof(physx_PxNodeIndex_Pod), "POD wrapper for `physx::PxNodeIndex` has incorrect size");
static_assert(sizeof(physx::PxRigidBody) == sizeof(physx_PxRigidBody_Pod), "POD wrapper for `physx::PxRigidBody` has incorrect size");
static_assert(sizeof(physx::PxArticulationLink) == sizeof(physx_PxArticulationLink_Pod), "POD wrapper for `physx::PxArticulationLink` has incorrect size");
static_assert(sizeof(physx::PxConeLimitedConstraint) == sizeof(physx_PxConeLimitedConstraint_Pod), "POD wrapper for `physx::PxConeLimitedConstraint` has incorrect size");
static_assert(sizeof(physx::PxConeLimitParams) == sizeof(physx_PxConeLimitParams_Pod), "POD wrapper for `physx::PxConeLimitParams` has incorrect size");
static_assert(sizeof(physx::PxConstraintShaderTable) == sizeof(physx_PxConstraintShaderTable_Pod), "POD wrapper for `physx::PxConstraintShaderTable` has incorrect size");
static_assert(sizeof(physx::PxConstraint) == sizeof(physx_PxConstraint_Pod), "POD wrapper for `physx::PxConstraint` has incorrect size");
static_assert(sizeof(physx::PxMassModificationProps) == sizeof(physx_PxMassModificationProps_Pod), "POD wrapper for `physx::PxMassModificationProps` has incorrect size");
static_assert(sizeof(physx::PxContactPatch) == sizeof(physx_PxContactPatch_Pod), "POD wrapper for `physx::PxContactPatch` has incorrect size");
static_assert(sizeof(physx::PxContact) == sizeof(physx_PxContact_Pod), "POD wrapper for `physx::PxContact` has incorrect size");
static_assert(sizeof(physx::PxExtendedContact) == sizeof(physx_PxExtendedContact_Pod), "POD wrapper for `physx::PxExtendedContact` has incorrect size");
static_assert(sizeof(physx::PxModifiableContact) == sizeof(physx_PxModifiableContact_Pod), "POD wrapper for `physx::PxModifiableContact` has incorrect size");
static_assert(sizeof(physx::PxContactStreamIterator) == sizeof(physx_PxContactStreamIterator_Pod), "POD wrapper for `physx::PxContactStreamIterator` has incorrect size");
static_assert(sizeof(physx::PxGpuContactPair) == sizeof(physx_PxGpuContactPair_Pod), "POD wrapper for `physx::PxGpuContactPair` has incorrect size");
static_assert(sizeof(physx::PxContactSet) == sizeof(physx_PxContactSet_Pod), "POD wrapper for `physx::PxContactSet` has incorrect size");
static_assert(sizeof(physx::PxContactModifyPair) == sizeof(physx_PxContactModifyPair_Pod), "POD wrapper for `physx::PxContactModifyPair` has incorrect size");
static_assert(sizeof(physx::PxContactModifyCallback) == sizeof(physx_PxContactModifyCallback_Pod), "POD wrapper for `physx::PxContactModifyCallback` has incorrect size");
static_assert(sizeof(physx::PxCCDContactModifyCallback) == sizeof(physx_PxCCDContactModifyCallback_Pod), "POD wrapper for `physx::PxCCDContactModifyCallback` has incorrect size");
static_assert(sizeof(physx::PxDeletionListener) == sizeof(physx_PxDeletionListener_Pod), "POD wrapper for `physx::PxDeletionListener` has incorrect size");
static_assert(sizeof(physx::PxBaseMaterial) == sizeof(physx_PxBaseMaterial_Pod), "POD wrapper for `physx::PxBaseMaterial` has incorrect size");
static_assert(sizeof(physx::PxFEMMaterial) == sizeof(physx_PxFEMMaterial_Pod), "POD wrapper for `physx::PxFEMMaterial` has incorrect size");
static_assert(sizeof(physx::PxFilterData) == sizeof(physx_PxFilterData_Pod), "POD wrapper for `physx::PxFilterData` has incorrect size");
static_assert(sizeof(physx::PxSimulationFilterCallback) == sizeof(physx_PxSimulationFilterCallback_Pod), "POD wrapper for `physx::PxSimulationFilterCallback` has incorrect size");
static_assert(sizeof(physx::PxParticleRigidFilterPair) == sizeof(physx_PxParticleRigidFilterPair_Pod), "POD wrapper for `physx::PxParticleRigidFilterPair` has incorrect size");
static_assert(sizeof(physx::PxLockedData) == sizeof(physx_PxLockedData_Pod), "POD wrapper for `physx::PxLockedData` has incorrect size");
static_assert(sizeof(physx::PxMaterial) == sizeof(physx_PxMaterial_Pod), "POD wrapper for `physx::PxMaterial` has incorrect size");
static_assert(sizeof(physx::PxGpuParticleBufferIndexPair) == sizeof(physx_PxGpuParticleBufferIndexPair_Pod), "POD wrapper for `physx::PxGpuParticleBufferIndexPair` has incorrect size");
static_assert(sizeof(physx::PxParticleVolume) == sizeof(physx_PxParticleVolume_Pod), "POD wrapper for `physx::PxParticleVolume` has incorrect size");
static_assert(sizeof(physx::PxDiffuseParticleParams) == sizeof(physx_PxDiffuseParticleParams_Pod), "POD wrapper for `physx::PxDiffuseParticleParams` has incorrect size");
static_assert(sizeof(physx::PxParticleSpring) == sizeof(physx_PxParticleSpring_Pod), "POD wrapper for `physx::PxParticleSpring` has incorrect size");
static_assert(sizeof(physx::PxParticleMaterial) == sizeof(physx_PxParticleMaterial_Pod), "POD wrapper for `physx::PxParticleMaterial` has incorrect size");
static_assert(sizeof(physx::PxPhysics) == sizeof(physx_PxPhysics_Pod), "POD wrapper for `physx::PxPhysics` has incorrect size");
static_assert(sizeof(physx::PxActorShape) == sizeof(physx_PxActorShape_Pod), "POD wrapper for `physx::PxActorShape` has incorrect size");
static_assert(sizeof(physx::PxRaycastHit) == sizeof(physx_PxRaycastHit_Pod), "POD wrapper for `physx::PxRaycastHit` has incorrect size");
static_assert(sizeof(physx::PxOverlapHit) == sizeof(physx_PxOverlapHit_Pod), "POD wrapper for `physx::PxOverlapHit` has incorrect size");
static_assert(sizeof(physx::PxSweepHit) == sizeof(physx_PxSweepHit_Pod), "POD wrapper for `physx::PxSweepHit` has incorrect size");
static_assert(sizeof(physx::PxRaycastCallback) == sizeof(physx_PxRaycastCallback_Pod), "POD wrapper for `physx::PxRaycastCallback` has incorrect size");
static_assert(sizeof(physx::PxOverlapCallback) == sizeof(physx_PxOverlapCallback_Pod), "POD wrapper for `physx::PxOverlapCallback` has incorrect size");
static_assert(sizeof(physx::PxSweepCallback) == sizeof(physx_PxSweepCallback_Pod), "POD wrapper for `physx::PxSweepCallback` has incorrect size");
static_assert(sizeof(physx::PxRaycastBuffer) == sizeof(physx_PxRaycastBuffer_Pod), "POD wrapper for `physx::PxRaycastBuffer` has incorrect size");
static_assert(sizeof(physx::PxOverlapBuffer) == sizeof(physx_PxOverlapBuffer_Pod), "POD wrapper for `physx::PxOverlapBuffer` has incorrect size");
static_assert(sizeof(physx::PxSweepBuffer) == sizeof(physx_PxSweepBuffer_Pod), "POD wrapper for `physx::PxSweepBuffer` has incorrect size");
static_assert(sizeof(physx::PxQueryCache) == sizeof(physx_PxQueryCache_Pod), "POD wrapper for `physx::PxQueryCache` has incorrect size");
static_assert(sizeof(physx::PxQueryFilterData) == sizeof(physx_PxQueryFilterData_Pod), "POD wrapper for `physx::PxQueryFilterData` has incorrect size");
static_assert(sizeof(physx::PxQueryFilterCallback) == sizeof(physx_PxQueryFilterCallback_Pod), "POD wrapper for `physx::PxQueryFilterCallback` has incorrect size");
static_assert(sizeof(physx::PxRigidDynamic) == sizeof(physx_PxRigidDynamic_Pod), "POD wrapper for `physx::PxRigidDynamic` has incorrect size");
static_assert(sizeof(physx::PxRigidStatic) == sizeof(physx_PxRigidStatic_Pod), "POD wrapper for `physx::PxRigidStatic` has incorrect size");
static_assert(sizeof(physx::PxSceneQueryDesc) == sizeof(physx_PxSceneQueryDesc_Pod), "POD wrapper for `physx::PxSceneQueryDesc` has incorrect size");
static_assert(sizeof(physx::PxSceneQuerySystemBase) == sizeof(physx_PxSceneQuerySystemBase_Pod), "POD wrapper for `physx::PxSceneQuerySystemBase` has incorrect size");
static_assert(sizeof(physx::PxSceneSQSystem) == sizeof(physx_PxSceneSQSystem_Pod), "POD wrapper for `physx::PxSceneSQSystem` has incorrect size");
static_assert(sizeof(physx::PxSceneQuerySystem) == sizeof(physx_PxSceneQuerySystem_Pod), "POD wrapper for `physx::PxSceneQuerySystem` has incorrect size");
static_assert(sizeof(physx::PxBroadPhaseRegion) == sizeof(physx_PxBroadPhaseRegion_Pod), "POD wrapper for `physx::PxBroadPhaseRegion` has incorrect size");
static_assert(sizeof(physx::PxBroadPhaseRegionInfo) == sizeof(physx_PxBroadPhaseRegionInfo_Pod), "POD wrapper for `physx::PxBroadPhaseRegionInfo` has incorrect size");
static_assert(sizeof(physx::PxBroadPhaseCaps) == sizeof(physx_PxBroadPhaseCaps_Pod), "POD wrapper for `physx::PxBroadPhaseCaps` has incorrect size");
static_assert(sizeof(physx::PxBroadPhaseDesc) == sizeof(physx_PxBroadPhaseDesc_Pod), "POD wrapper for `physx::PxBroadPhaseDesc` has incorrect size");
static_assert(sizeof(physx::PxBroadPhaseUpdateData) == sizeof(physx_PxBroadPhaseUpdateData_Pod), "POD wrapper for `physx::PxBroadPhaseUpdateData` has incorrect size");
static_assert(sizeof(physx::PxBroadPhasePair) == sizeof(physx_PxBroadPhasePair_Pod), "POD wrapper for `physx::PxBroadPhasePair` has incorrect size");
static_assert(sizeof(physx::PxBroadPhaseResults) == sizeof(physx_PxBroadPhaseResults_Pod), "POD wrapper for `physx::PxBroadPhaseResults` has incorrect size");
static_assert(sizeof(physx::PxBroadPhaseRegions) == sizeof(physx_PxBroadPhaseRegions_Pod), "POD wrapper for `physx::PxBroadPhaseRegions` has incorrect size");
static_assert(sizeof(physx::PxBroadPhase) == sizeof(physx_PxBroadPhase_Pod), "POD wrapper for `physx::PxBroadPhase` has incorrect size");
static_assert(sizeof(physx::PxAABBManager) == sizeof(physx_PxAABBManager_Pod), "POD wrapper for `physx::PxAABBManager` has incorrect size");
static_assert(sizeof(physx::PxSceneLimits) == sizeof(physx_PxSceneLimits_Pod), "POD wrapper for `physx::PxSceneLimits` has incorrect size");
static_assert(sizeof(physx::PxgDynamicsMemoryConfig) == sizeof(physx_PxgDynamicsMemoryConfig_Pod), "POD wrapper for `physx::PxgDynamicsMemoryConfig` has incorrect size");
static_assert(sizeof(physx::PxSceneDesc) == sizeof(physx_PxSceneDesc_Pod), "POD wrapper for `physx::PxSceneDesc` has incorrect size");
static_assert(sizeof(physx::PxSimulationStatistics) == sizeof(physx_PxSimulationStatistics_Pod), "POD wrapper for `physx::PxSimulationStatistics` has incorrect size");
static_assert(sizeof(physx::PxGpuBodyData) == sizeof(physx_PxGpuBodyData_Pod), "POD wrapper for `physx::PxGpuBodyData` has incorrect size");
static_assert(sizeof(physx::PxGpuActorPair) == sizeof(physx_PxGpuActorPair_Pod), "POD wrapper for `physx::PxGpuActorPair` has incorrect size");
static_assert(sizeof(physx::PxIndexDataPair) == sizeof(physx_PxIndexDataPair_Pod), "POD wrapper for `physx::PxIndexDataPair` has incorrect size");
static_assert(sizeof(physx::PxPvdSceneClient) == sizeof(physx_PxPvdSceneClient_Pod), "POD wrapper for `physx::PxPvdSceneClient` has incorrect size");
static_assert(sizeof(physx::PxDominanceGroupPair) == sizeof(physx_PxDominanceGroupPair_Pod), "POD wrapper for `physx::PxDominanceGroupPair` has incorrect size");
static_assert(sizeof(physx::PxBroadPhaseCallback) == sizeof(physx_PxBroadPhaseCallback_Pod), "POD wrapper for `physx::PxBroadPhaseCallback` has incorrect size");
static_assert(sizeof(physx::PxScene) == sizeof(physx_PxScene_Pod), "POD wrapper for `physx::PxScene` has incorrect size");
static_assert(sizeof(physx::PxSceneReadLock) == sizeof(physx_PxSceneReadLock_Pod), "POD wrapper for `physx::PxSceneReadLock` has incorrect size");
static_assert(sizeof(physx::PxSceneWriteLock) == sizeof(physx_PxSceneWriteLock_Pod), "POD wrapper for `physx::PxSceneWriteLock` has incorrect size");
static_assert(sizeof(physx::PxContactPairExtraDataItem) == sizeof(physx_PxContactPairExtraDataItem_Pod), "POD wrapper for `physx::PxContactPairExtraDataItem` has incorrect size");
static_assert(sizeof(physx::PxContactPairVelocity) == sizeof(physx_PxContactPairVelocity_Pod), "POD wrapper for `physx::PxContactPairVelocity` has incorrect size");
static_assert(sizeof(physx::PxContactPairPose) == sizeof(physx_PxContactPairPose_Pod), "POD wrapper for `physx::PxContactPairPose` has incorrect size");
static_assert(sizeof(physx::PxContactPairIndex) == sizeof(physx_PxContactPairIndex_Pod), "POD wrapper for `physx::PxContactPairIndex` has incorrect size");
static_assert(sizeof(physx::PxContactPairExtraDataIterator) == sizeof(physx_PxContactPairExtraDataIterator_Pod), "POD wrapper for `physx::PxContactPairExtraDataIterator` has incorrect size");
static_assert(sizeof(physx::PxContactPairHeader) == sizeof(physx_PxContactPairHeader_Pod), "POD wrapper for `physx::PxContactPairHeader` has incorrect size");
static_assert(sizeof(physx::PxContactPairPoint) == sizeof(physx_PxContactPairPoint_Pod), "POD wrapper for `physx::PxContactPairPoint` has incorrect size");
static_assert(sizeof(physx::PxContactPair) == sizeof(physx_PxContactPair_Pod), "POD wrapper for `physx::PxContactPair` has incorrect size");
static_assert(sizeof(physx::PxTriggerPair) == sizeof(physx_PxTriggerPair_Pod), "POD wrapper for `physx::PxTriggerPair` has incorrect size");
static_assert(sizeof(physx::PxConstraintInfo) == sizeof(physx_PxConstraintInfo_Pod), "POD wrapper for `physx::PxConstraintInfo` has incorrect size");
static_assert(sizeof(physx::PxSimulationEventCallback) == sizeof(physx_PxSimulationEventCallback_Pod), "POD wrapper for `physx::PxSimulationEventCallback` has incorrect size");
static_assert(sizeof(physx::PxFEMParameters) == sizeof(physx_PxFEMParameters_Pod), "POD wrapper for `physx::PxFEMParameters` has incorrect size");
static_assert(sizeof(physx::PxPruningStructure) == sizeof(physx_PxPruningStructure_Pod), "POD wrapper for `physx::PxPruningStructure` has incorrect size");
static_assert(sizeof(physx::PxExtendedVec3) == sizeof(physx_PxExtendedVec3_Pod), "POD wrapper for `physx::PxExtendedVec3` has incorrect size");
static_assert(sizeof(physx::PxObstacle) == sizeof(physx_PxObstacle_Pod), "POD wrapper for `physx::PxObstacle` has incorrect size");
static_assert(sizeof(physx::PxBoxObstacle) == sizeof(physx_PxBoxObstacle_Pod), "POD wrapper for `physx::PxBoxObstacle` has incorrect size");
static_assert(sizeof(physx::PxCapsuleObstacle) == sizeof(physx_PxCapsuleObstacle_Pod), "POD wrapper for `physx::PxCapsuleObstacle` has incorrect size");
static_assert(sizeof(physx::PxObstacleContext) == sizeof(physx_PxObstacleContext_Pod), "POD wrapper for `physx::PxObstacleContext` has incorrect size");
static_assert(sizeof(physx::PxControllerState) == sizeof(physx_PxControllerState_Pod), "POD wrapper for `physx::PxControllerState` has incorrect size");
static_assert(sizeof(physx::PxControllerStats) == sizeof(physx_PxControllerStats_Pod), "POD wrapper for `physx::PxControllerStats` has incorrect size");
static_assert(sizeof(physx::PxControllerHit) == sizeof(physx_PxControllerHit_Pod), "POD wrapper for `physx::PxControllerHit` has incorrect size");
static_assert(sizeof(physx::PxControllerShapeHit) == sizeof(physx_PxControllerShapeHit_Pod), "POD wrapper for `physx::PxControllerShapeHit` has incorrect size");
static_assert(sizeof(physx::PxControllersHit) == sizeof(physx_PxControllersHit_Pod), "POD wrapper for `physx::PxControllersHit` has incorrect size");
static_assert(sizeof(physx::PxControllerObstacleHit) == sizeof(physx_PxControllerObstacleHit_Pod), "POD wrapper for `physx::PxControllerObstacleHit` has incorrect size");
static_assert(sizeof(physx::PxUserControllerHitReport) == sizeof(physx_PxUserControllerHitReport_Pod), "POD wrapper for `physx::PxUserControllerHitReport` has incorrect size");
static_assert(sizeof(physx::PxControllerFilterCallback) == sizeof(physx_PxControllerFilterCallback_Pod), "POD wrapper for `physx::PxControllerFilterCallback` has incorrect size");
static_assert(sizeof(physx::PxControllerFilters) == sizeof(physx_PxControllerFilters_Pod), "POD wrapper for `physx::PxControllerFilters` has incorrect size");
static_assert(sizeof(physx::PxControllerDesc) == sizeof(physx_PxControllerDesc_Pod), "POD wrapper for `physx::PxControllerDesc` has incorrect size");
static_assert(sizeof(physx::PxController) == sizeof(physx_PxController_Pod), "POD wrapper for `physx::PxController` has incorrect size");
static_assert(sizeof(physx::PxBoxControllerDesc) == sizeof(physx_PxBoxControllerDesc_Pod), "POD wrapper for `physx::PxBoxControllerDesc` has incorrect size");
static_assert(sizeof(physx::PxBoxController) == sizeof(physx_PxBoxController_Pod), "POD wrapper for `physx::PxBoxController` has incorrect size");
static_assert(sizeof(physx::PxCapsuleControllerDesc) == sizeof(physx_PxCapsuleControllerDesc_Pod), "POD wrapper for `physx::PxCapsuleControllerDesc` has incorrect size");
static_assert(sizeof(physx::PxCapsuleController) == sizeof(physx_PxCapsuleController_Pod), "POD wrapper for `physx::PxCapsuleController` has incorrect size");
static_assert(sizeof(physx::PxControllerBehaviorCallback) == sizeof(physx_PxControllerBehaviorCallback_Pod), "POD wrapper for `physx::PxControllerBehaviorCallback` has incorrect size");
static_assert(sizeof(physx::PxControllerManager) == sizeof(physx_PxControllerManager_Pod), "POD wrapper for `physx::PxControllerManager` has incorrect size");
static_assert(sizeof(physx::PxDim3) == sizeof(physx_PxDim3_Pod), "POD wrapper for `physx::PxDim3` has incorrect size");
static_assert(sizeof(physx::PxSDFDesc) == sizeof(physx_PxSDFDesc_Pod), "POD wrapper for `physx::PxSDFDesc` has incorrect size");
static_assert(sizeof(physx::PxConvexMeshDesc) == sizeof(physx_PxConvexMeshDesc_Pod), "POD wrapper for `physx::PxConvexMeshDesc` has incorrect size");
static_assert(sizeof(physx::PxTriangleMeshDesc) == sizeof(physx_PxTriangleMeshDesc_Pod), "POD wrapper for `physx::PxTriangleMeshDesc` has incorrect size");
static_assert(sizeof(physx::PxTetrahedronMeshDesc) == sizeof(physx_PxTetrahedronMeshDesc_Pod), "POD wrapper for `physx::PxTetrahedronMeshDesc` has incorrect size");
static_assert(sizeof(physx::PxSoftBodySimulationDataDesc) == sizeof(physx_PxSoftBodySimulationDataDesc_Pod), "POD wrapper for `physx::PxSoftBodySimulationDataDesc` has incorrect size");
static_assert(sizeof(physx::PxBVH34MidphaseDesc) == sizeof(physx_PxBVH34MidphaseDesc_Pod), "POD wrapper for `physx::PxBVH34MidphaseDesc` has incorrect size");
static_assert(sizeof(physx::PxMidphaseDesc) == sizeof(physx_PxMidphaseDesc_Pod), "POD wrapper for `physx::PxMidphaseDesc` has incorrect size");
static_assert(sizeof(physx::PxBVHDesc) == sizeof(physx_PxBVHDesc_Pod), "POD wrapper for `physx::PxBVHDesc` has incorrect size");
static_assert(sizeof(physx::PxCookingParams) == sizeof(physx_PxCookingParams_Pod), "POD wrapper for `physx::PxCookingParams` has incorrect size");
static_assert(sizeof(physx::PxDefaultMemoryOutputStream) == sizeof(physx_PxDefaultMemoryOutputStream_Pod), "POD wrapper for `physx::PxDefaultMemoryOutputStream` has incorrect size");
static_assert(sizeof(physx::PxDefaultMemoryInputData) == sizeof(physx_PxDefaultMemoryInputData_Pod), "POD wrapper for `physx::PxDefaultMemoryInputData` has incorrect size");
static_assert(sizeof(physx::PxDefaultFileOutputStream) == sizeof(physx_PxDefaultFileOutputStream_Pod), "POD wrapper for `physx::PxDefaultFileOutputStream` has incorrect size");
static_assert(sizeof(physx::PxDefaultFileInputData) == sizeof(physx_PxDefaultFileInputData_Pod), "POD wrapper for `physx::PxDefaultFileInputData` has incorrect size");
static_assert(sizeof(physx::PxDefaultAllocator) == sizeof(physx_PxDefaultAllocator_Pod), "POD wrapper for `physx::PxDefaultAllocator` has incorrect size");
static_assert(sizeof(physx::PxJoint) == sizeof(physx_PxJoint_Pod), "POD wrapper for `physx::PxJoint` has incorrect size");
static_assert(sizeof(physx::PxSpring) == sizeof(physx_PxSpring_Pod), "POD wrapper for `physx::PxSpring` has incorrect size");
static_assert(sizeof(physx::PxDistanceJoint) == sizeof(physx_PxDistanceJoint_Pod), "POD wrapper for `physx::PxDistanceJoint` has incorrect size");
static_assert(sizeof(physx::PxJacobianRow) == sizeof(physx_PxJacobianRow_Pod), "POD wrapper for `physx::PxJacobianRow` has incorrect size");
static_assert(sizeof(physx::PxContactJoint) == sizeof(physx_PxContactJoint_Pod), "POD wrapper for `physx::PxContactJoint` has incorrect size");
static_assert(sizeof(physx::PxFixedJoint) == sizeof(physx_PxFixedJoint_Pod), "POD wrapper for `physx::PxFixedJoint` has incorrect size");
static_assert(sizeof(physx::PxJointLimitParameters) == sizeof(physx_PxJointLimitParameters_Pod), "POD wrapper for `physx::PxJointLimitParameters` has incorrect size");
static_assert(sizeof(physx::PxJointLinearLimit) == sizeof(physx_PxJointLinearLimit_Pod), "POD wrapper for `physx::PxJointLinearLimit` has incorrect size");
static_assert(sizeof(physx::PxJointLinearLimitPair) == sizeof(physx_PxJointLinearLimitPair_Pod), "POD wrapper for `physx::PxJointLinearLimitPair` has incorrect size");
static_assert(sizeof(physx::PxJointAngularLimitPair) == sizeof(physx_PxJointAngularLimitPair_Pod), "POD wrapper for `physx::PxJointAngularLimitPair` has incorrect size");
static_assert(sizeof(physx::PxJointLimitCone) == sizeof(physx_PxJointLimitCone_Pod), "POD wrapper for `physx::PxJointLimitCone` has incorrect size");
static_assert(sizeof(physx::PxJointLimitPyramid) == sizeof(physx_PxJointLimitPyramid_Pod), "POD wrapper for `physx::PxJointLimitPyramid` has incorrect size");
static_assert(sizeof(physx::PxPrismaticJoint) == sizeof(physx_PxPrismaticJoint_Pod), "POD wrapper for `physx::PxPrismaticJoint` has incorrect size");
static_assert(sizeof(physx::PxRevoluteJoint) == sizeof(physx_PxRevoluteJoint_Pod), "POD wrapper for `physx::PxRevoluteJoint` has incorrect size");
static_assert(sizeof(physx::PxSphericalJoint) == sizeof(physx_PxSphericalJoint_Pod), "POD wrapper for `physx::PxSphericalJoint` has incorrect size");
static_assert(sizeof(physx::PxD6JointDrive) == sizeof(physx_PxD6JointDrive_Pod), "POD wrapper for `physx::PxD6JointDrive` has incorrect size");
static_assert(sizeof(physx::PxD6Joint) == sizeof(physx_PxD6Joint_Pod), "POD wrapper for `physx::PxD6Joint` has incorrect size");
static_assert(sizeof(physx::PxGearJoint) == sizeof(physx_PxGearJoint_Pod), "POD wrapper for `physx::PxGearJoint` has incorrect size");
static_assert(sizeof(physx::PxRackAndPinionJoint) == sizeof(physx_PxRackAndPinionJoint_Pod), "POD wrapper for `physx::PxRackAndPinionJoint` has incorrect size");
static_assert(sizeof(physx::PxGroupsMask) == sizeof(physx_PxGroupsMask_Pod), "POD wrapper for `physx::PxGroupsMask` has incorrect size");
static_assert(sizeof(physx::PxDefaultErrorCallback) == sizeof(physx_PxDefaultErrorCallback_Pod), "POD wrapper for `physx::PxDefaultErrorCallback` has incorrect size");
static_assert(sizeof(physx::PxRigidActorExt) == sizeof(physx_PxRigidActorExt_Pod), "POD wrapper for `physx::PxRigidActorExt` has incorrect size");
static_assert(sizeof(physx::PxMassProperties) == sizeof(physx_PxMassProperties_Pod), "POD wrapper for `physx::PxMassProperties` has incorrect size");
static_assert(sizeof(physx::PxRigidBodyExt) == sizeof(physx_PxRigidBodyExt_Pod), "POD wrapper for `physx::PxRigidBodyExt` has incorrect size");
static_assert(sizeof(physx::PxShapeExt) == sizeof(physx_PxShapeExt_Pod), "POD wrapper for `physx::PxShapeExt` has incorrect size");
static_assert(sizeof(physx::PxMeshOverlapUtil) == sizeof(physx_PxMeshOverlapUtil_Pod), "POD wrapper for `physx::PxMeshOverlapUtil` has incorrect size");
static_assert(sizeof(physx::PxXmlMiscParameter) == sizeof(physx_PxXmlMiscParameter_Pod), "POD wrapper for `physx::PxXmlMiscParameter` has incorrect size");
static_assert(sizeof(physx::PxSerialization) == sizeof(physx_PxSerialization_Pod), "POD wrapper for `physx::PxSerialization` has incorrect size");
static_assert(sizeof(physx::PxDefaultCpuDispatcher) == sizeof(physx_PxDefaultCpuDispatcher_Pod), "POD wrapper for `physx::PxDefaultCpuDispatcher` has incorrect size");
static_assert(sizeof(physx::PxStringTableExt) == sizeof(physx_PxStringTableExt_Pod), "POD wrapper for `physx::PxStringTableExt` has incorrect size");
static_assert(sizeof(physx::PxBroadPhaseExt) == sizeof(physx_PxBroadPhaseExt_Pod), "POD wrapper for `physx::PxBroadPhaseExt` has incorrect size");
static_assert(sizeof(physx::PxSceneQueryExt) == sizeof(physx_PxSceneQueryExt_Pod), "POD wrapper for `physx::PxSceneQueryExt` has incorrect size");
static_assert(sizeof(physx::PxBatchQueryExt) == sizeof(physx_PxBatchQueryExt_Pod), "POD wrapper for `physx::PxBatchQueryExt` has incorrect size");
static_assert(sizeof(physx::PxCustomSceneQuerySystem) == sizeof(physx_PxCustomSceneQuerySystem_Pod), "POD wrapper for `physx::PxCustomSceneQuerySystem` has incorrect size");
static_assert(sizeof(physx::PxCustomSceneQuerySystemAdapter) == sizeof(physx_PxCustomSceneQuerySystemAdapter_Pod), "POD wrapper for `physx::PxCustomSceneQuerySystemAdapter` has incorrect size");
static_assert(sizeof(physx::PxSamplingExt) == sizeof(physx_PxSamplingExt_Pod), "POD wrapper for `physx::PxSamplingExt` has incorrect size");
static_assert(sizeof(physx::PxPoissonSampler) == sizeof(physx_PxPoissonSampler_Pod), "POD wrapper for `physx::PxPoissonSampler` has incorrect size");
static_assert(sizeof(physx::PxTriangleMeshPoissonSampler) == sizeof(physx_PxTriangleMeshPoissonSampler_Pod), "POD wrapper for `physx::PxTriangleMeshPoissonSampler` has incorrect size");
static_assert(sizeof(physx::PxTetrahedronMeshExt) == sizeof(physx_PxTetrahedronMeshExt_Pod), "POD wrapper for `physx::PxTetrahedronMeshExt` has incorrect size");
static_assert(sizeof(physx::PxRepXObject) == sizeof(physx_PxRepXObject_Pod), "POD wrapper for `physx::PxRepXObject` has incorrect size");
static_assert(sizeof(physx::PxRepXInstantiationArgs) == sizeof(physx_PxRepXInstantiationArgs_Pod), "POD wrapper for `physx::PxRepXInstantiationArgs` has incorrect size");
static_assert(sizeof(physx::PxRepXSerializer) == sizeof(physx_PxRepXSerializer_Pod), "POD wrapper for `physx::PxRepXSerializer` has incorrect size");
static_assert(sizeof(physx::PxPvd) == sizeof(physx_PxPvd_Pod), "POD wrapper for `physx::PxPvd` has incorrect size");
static_assert(sizeof(physx::PxPvdTransport) == sizeof(physx_PxPvdTransport_Pod), "POD wrapper for `physx::PxPvdTransport` has incorrect size");

extern "C" {
    void PxAllocatorCallback_delete(physx_PxAllocatorCallback_Pod* self__pod) {
        physx::PxAllocatorCallback* self_ = reinterpret_cast<physx::PxAllocatorCallback*>(self__pod);
        delete self_;
    }

    void* PxAllocatorCallback_allocate_mut(physx_PxAllocatorCallback_Pod* self__pod, size_t size_pod, char const* typeName, char const* filename, int32_t line) {
        physx::PxAllocatorCallback* self_ = reinterpret_cast<physx::PxAllocatorCallback*>(self__pod);
        size_t size;
        memcpy(&size, &size_pod, sizeof(size));
        void* return_val = self_->allocate(size, typeName, filename, line);
        return return_val;
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
        physx::PxAssertHandler& return_val = PxGetAssertHandler();
        auto return_val_pod = reinterpret_cast<physx_PxAssertHandler_Pod*>(&return_val);
        return return_val_pod;
    }

    void phys_PxSetAssertHandler(physx_PxAssertHandler_Pod* handler_pod) {
        physx::PxAssertHandler& handler = reinterpret_cast<physx::PxAssertHandler&>(*handler_pod);
        PxSetAssertHandler(handler);
    }

    void PxFoundation_release_mut(physx_PxFoundation_Pod* self__pod) {
        physx::PxFoundation* self_ = reinterpret_cast<physx::PxFoundation*>(self__pod);
        self_->release();
    }

    physx_PxErrorCallback_Pod* PxFoundation_getErrorCallback_mut(physx_PxFoundation_Pod* self__pod) {
        physx::PxFoundation* self_ = reinterpret_cast<physx::PxFoundation*>(self__pod);
        physx::PxErrorCallback& return_val = self_->getErrorCallback();
        auto return_val_pod = reinterpret_cast<physx_PxErrorCallback_Pod*>(&return_val);
        return return_val_pod;
    }

    void PxFoundation_setErrorLevel_mut(physx_PxFoundation_Pod* self__pod, uint32_t mask) {
        physx::PxFoundation* self_ = reinterpret_cast<physx::PxFoundation*>(self__pod);
        self_->setErrorLevel(mask);
    }

    uint32_t PxFoundation_getErrorLevel(physx_PxFoundation_Pod const* self__pod) {
        physx::PxFoundation const* self_ = reinterpret_cast<physx::PxFoundation const*>(self__pod);
        uint32_t return_val = self_->getErrorLevel();
        return return_val;
    }

    physx_PxAllocatorCallback_Pod* PxFoundation_getAllocatorCallback_mut(physx_PxFoundation_Pod* self__pod) {
        physx::PxFoundation* self_ = reinterpret_cast<physx::PxFoundation*>(self__pod);
        physx::PxAllocatorCallback& return_val = self_->getAllocatorCallback();
        auto return_val_pod = reinterpret_cast<physx_PxAllocatorCallback_Pod*>(&return_val);
        return return_val_pod;
    }

    bool PxFoundation_getReportAllocationNames(physx_PxFoundation_Pod const* self__pod) {
        physx::PxFoundation const* self_ = reinterpret_cast<physx::PxFoundation const*>(self__pod);
        bool return_val = self_->getReportAllocationNames();
        return return_val;
    }

    void PxFoundation_setReportAllocationNames_mut(physx_PxFoundation_Pod* self__pod, bool value) {
        physx::PxFoundation* self_ = reinterpret_cast<physx::PxFoundation*>(self__pod);
        self_->setReportAllocationNames(value);
    }

    void PxFoundation_registerAllocationListener_mut(physx_PxFoundation_Pod* self__pod, physx_PxAllocationListener_Pod* listener_pod) {
        physx::PxFoundation* self_ = reinterpret_cast<physx::PxFoundation*>(self__pod);
        physx::PxAllocationListener& listener = reinterpret_cast<physx::PxAllocationListener&>(*listener_pod);
        self_->registerAllocationListener(listener);
    }

    void PxFoundation_deregisterAllocationListener_mut(physx_PxFoundation_Pod* self__pod, physx_PxAllocationListener_Pod* listener_pod) {
        physx::PxFoundation* self_ = reinterpret_cast<physx::PxFoundation*>(self__pod);
        physx::PxAllocationListener& listener = reinterpret_cast<physx::PxAllocationListener&>(*listener_pod);
        self_->deregisterAllocationListener(listener);
    }

    void PxFoundation_registerErrorCallback_mut(physx_PxFoundation_Pod* self__pod, physx_PxErrorCallback_Pod* callback_pod) {
        physx::PxFoundation* self_ = reinterpret_cast<physx::PxFoundation*>(self__pod);
        physx::PxErrorCallback& callback = reinterpret_cast<physx::PxErrorCallback&>(*callback_pod);
        self_->registerErrorCallback(callback);
    }

    void PxFoundation_deregisterErrorCallback_mut(physx_PxFoundation_Pod* self__pod, physx_PxErrorCallback_Pod* callback_pod) {
        physx::PxFoundation* self_ = reinterpret_cast<physx::PxFoundation*>(self__pod);
        physx::PxErrorCallback& callback = reinterpret_cast<physx::PxErrorCallback&>(*callback_pod);
        self_->deregisterErrorCallback(callback);
    }

    physx_PxFoundation_Pod* phys_PxCreateFoundation(uint32_t version, physx_PxAllocatorCallback_Pod* allocator_pod, physx_PxErrorCallback_Pod* errorCallback_pod) {
        physx::PxAllocatorCallback& allocator = reinterpret_cast<physx::PxAllocatorCallback&>(*allocator_pod);
        physx::PxErrorCallback& errorCallback = reinterpret_cast<physx::PxErrorCallback&>(*errorCallback_pod);
        physx::PxFoundation* return_val = PxCreateFoundation(version, allocator, errorCallback);
        auto return_val_pod = reinterpret_cast<physx_PxFoundation_Pod*>(return_val);
        return return_val_pod;
    }

    void phys_PxSetFoundationInstance(physx_PxFoundation_Pod* foundation_pod) {
        physx::PxFoundation& foundation = reinterpret_cast<physx::PxFoundation&>(*foundation_pod);
        PxSetFoundationInstance(foundation);
    }

    physx_PxFoundation_Pod* phys_PxGetFoundation() {
        physx::PxFoundation& return_val = PxGetFoundation();
        auto return_val_pod = reinterpret_cast<physx_PxFoundation_Pod*>(&return_val);
        return return_val_pod;
    }

    physx_PxProfilerCallback_Pod* phys_PxGetProfilerCallback() {
        physx::PxProfilerCallback* return_val = PxGetProfilerCallback();
        auto return_val_pod = reinterpret_cast<physx_PxProfilerCallback_Pod*>(return_val);
        return return_val_pod;
    }

    void phys_PxSetProfilerCallback(physx_PxProfilerCallback_Pod* profiler_pod) {
        physx::PxProfilerCallback* profiler = reinterpret_cast<physx::PxProfilerCallback*>(profiler_pod);
        PxSetProfilerCallback(profiler);
    }

    physx_PxAllocatorCallback_Pod* phys_PxGetAllocatorCallback() {
        physx::PxAllocatorCallback* return_val = PxGetAllocatorCallback();
        auto return_val_pod = reinterpret_cast<physx_PxAllocatorCallback_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxAllocatorCallback_Pod* phys_PxGetBroadcastAllocator() {
        physx::PxAllocatorCallback* return_val = PxGetBroadcastAllocator();
        auto return_val_pod = reinterpret_cast<physx_PxAllocatorCallback_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxErrorCallback_Pod* phys_PxGetErrorCallback() {
        physx::PxErrorCallback* return_val = PxGetErrorCallback();
        auto return_val_pod = reinterpret_cast<physx_PxErrorCallback_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxErrorCallback_Pod* phys_PxGetBroadcastError() {
        physx::PxErrorCallback* return_val = PxGetBroadcastError();
        auto return_val_pod = reinterpret_cast<physx_PxErrorCallback_Pod*>(return_val);
        return return_val_pod;
    }

    uint32_t phys_PxGetWarnOnceTimeStamp() {
        uint32_t return_val = PxGetWarnOnceTimeStamp();
        return return_val;
    }

    void phys_PxDecFoundationRefCount() {
        PxDecFoundationRefCount();
    }

    void phys_PxIncFoundationRefCount() {
        PxIncFoundationRefCount();
    }

    physx_PxAllocator_Pod PxAllocator_new(char const* anon_param0) {
        PxAllocator return_val(anon_param0);
        physx_PxAllocator_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void* PxAllocator_allocate_mut(physx_PxAllocator_Pod* self__pod, size_t size_pod, char const* file, int32_t line) {
        physx::PxAllocator* self_ = reinterpret_cast<physx::PxAllocator*>(self__pod);
        size_t size;
        memcpy(&size, &size_pod, sizeof(size));
        void* return_val = self_->allocate(size, file, line);
        return return_val;
    }

    void PxAllocator_deallocate_mut(physx_PxAllocator_Pod* self__pod, void* ptr) {
        physx::PxAllocator* self_ = reinterpret_cast<physx::PxAllocator*>(self__pod);
        self_->deallocate(ptr);
    }

    physx_PxRawAllocator_Pod PxRawAllocator_new(char const* anon_param0) {
        PxRawAllocator return_val(anon_param0);
        physx_PxRawAllocator_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void* PxRawAllocator_allocate_mut(physx_PxRawAllocator_Pod* self__pod, size_t size_pod, char const* anon_param1, int32_t anon_param2) {
        physx::PxRawAllocator* self_ = reinterpret_cast<physx::PxRawAllocator*>(self__pod);
        size_t size;
        memcpy(&size, &size_pod, sizeof(size));
        void* return_val = self_->allocate(size, anon_param1, anon_param2);
        return return_val;
    }

    void PxRawAllocator_deallocate_mut(physx_PxRawAllocator_Pod* self__pod, void* ptr) {
        physx::PxRawAllocator* self_ = reinterpret_cast<physx::PxRawAllocator*>(self__pod);
        self_->deallocate(ptr);
    }

    void PxVirtualAllocatorCallback_delete(physx_PxVirtualAllocatorCallback_Pod* self__pod) {
        physx::PxVirtualAllocatorCallback* self_ = reinterpret_cast<physx::PxVirtualAllocatorCallback*>(self__pod);
        delete self_;
    }

    void* PxVirtualAllocatorCallback_allocate_mut(physx_PxVirtualAllocatorCallback_Pod* self__pod, size_t size_pod, int32_t group, char const* file, int32_t line) {
        physx::PxVirtualAllocatorCallback* self_ = reinterpret_cast<physx::PxVirtualAllocatorCallback*>(self__pod);
        size_t size;
        memcpy(&size, &size_pod, sizeof(size));
        void* return_val = self_->allocate(size, group, file, line);
        return return_val;
    }

    void PxVirtualAllocatorCallback_deallocate_mut(physx_PxVirtualAllocatorCallback_Pod* self__pod, void* ptr) {
        physx::PxVirtualAllocatorCallback* self_ = reinterpret_cast<physx::PxVirtualAllocatorCallback*>(self__pod);
        self_->deallocate(ptr);
    }

    physx_PxVirtualAllocator_Pod PxVirtualAllocator_new(physx_PxVirtualAllocatorCallback_Pod* callback_pod, int32_t group) {
        physx::PxVirtualAllocatorCallback* callback = reinterpret_cast<physx::PxVirtualAllocatorCallback*>(callback_pod);
        PxVirtualAllocator return_val(callback, group);
        physx_PxVirtualAllocator_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void* PxVirtualAllocator_allocate_mut(physx_PxVirtualAllocator_Pod* self__pod, size_t size_pod, char const* file, int32_t line) {
        physx::PxVirtualAllocator* self_ = reinterpret_cast<physx::PxVirtualAllocator*>(self__pod);
        size_t size;
        memcpy(&size, &size_pod, sizeof(size));
        void* return_val = self_->allocate(size, file, line);
        return return_val;
    }

    void PxVirtualAllocator_deallocate_mut(physx_PxVirtualAllocator_Pod* self__pod, void* ptr) {
        physx::PxVirtualAllocator* self_ = reinterpret_cast<physx::PxVirtualAllocator*>(self__pod);
        self_->deallocate(ptr);
    }

    physx_PxTempAllocatorChunk_Pod PxTempAllocatorChunk_new() {
        PxTempAllocatorChunk return_val;
        physx_PxTempAllocatorChunk_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxTempAllocator_Pod PxTempAllocator_new(char const* anon_param0) {
        PxTempAllocator return_val(anon_param0);
        physx_PxTempAllocator_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void* PxTempAllocator_allocate_mut(physx_PxTempAllocator_Pod* self__pod, size_t size_pod, char const* file, int32_t line) {
        physx::PxTempAllocator* self_ = reinterpret_cast<physx::PxTempAllocator*>(self__pod);
        size_t size;
        memcpy(&size, &size_pod, sizeof(size));
        void* return_val = self_->allocate(size, file, line);
        return return_val;
    }

    void PxTempAllocator_deallocate_mut(physx_PxTempAllocator_Pod* self__pod, void* ptr) {
        physx::PxTempAllocator* self_ = reinterpret_cast<physx::PxTempAllocator*>(self__pod);
        self_->deallocate(ptr);
    }

    void* phys_PxMemZero(void* dest, uint32_t count) {
        void* return_val = PxMemZero(dest, count);
        return return_val;
    }

    void* phys_PxMemSet(void* dest, int32_t c, uint32_t count) {
        void* return_val = PxMemSet(dest, c, count);
        return return_val;
    }

    void* phys_PxMemCopy(void* dest, void const* src, uint32_t count) {
        void* return_val = PxMemCopy(dest, src, count);
        return return_val;
    }

    void* phys_PxMemMove(void* dest, void const* src, uint32_t count) {
        void* return_val = PxMemMove(dest, src, count);
        return return_val;
    }

    void phys_PxMarkSerializedMemory(void* ptr, uint32_t byteSize) {
        PxMarkSerializedMemory(ptr, byteSize);
    }

    void phys_PxMemoryBarrier() {
        PxMemoryBarrier();
    }

    uint32_t phys_PxHighestSetBitUnsafe(uint32_t v) {
        uint32_t return_val = PxHighestSetBitUnsafe(v);
        return return_val;
    }

    uint32_t phys_PxLowestSetBitUnsafe(uint32_t v) {
        uint32_t return_val = PxLowestSetBitUnsafe(v);
        return return_val;
    }

    uint32_t phys_PxCountLeadingZeros(uint32_t v) {
        uint32_t return_val = PxCountLeadingZeros(v);
        return return_val;
    }

    void phys_PxPrefetchLine(void const* ptr, uint32_t offset) {
        PxPrefetchLine(ptr, offset);
    }

    void phys_PxPrefetch(void const* ptr, uint32_t count) {
        PxPrefetch(ptr, count);
    }

    uint32_t phys_PxBitCount(uint32_t v) {
        uint32_t return_val = PxBitCount(v);
        return return_val;
    }

    bool phys_PxIsPowerOfTwo(uint32_t x) {
        bool return_val = PxIsPowerOfTwo(x);
        return return_val;
    }

    uint32_t phys_PxNextPowerOfTwo(uint32_t x) {
        uint32_t return_val = PxNextPowerOfTwo(x);
        return return_val;
    }

    uint32_t phys_PxLowestSetBit(uint32_t x) {
        uint32_t return_val = PxLowestSetBit(x);
        return return_val;
    }

    uint32_t phys_PxHighestSetBit(uint32_t x) {
        uint32_t return_val = PxHighestSetBit(x);
        return return_val;
    }

    uint32_t phys_PxILog2(uint32_t num) {
        uint32_t return_val = PxILog2(num);
        return return_val;
    }

    physx_PxVec3_Pod PxVec3_new() {
        PxVec3 return_val;
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxVec3_new_1(int32_t anon_param0_pod) {
        auto anon_param0 = static_cast<physx::PxZERO>(anon_param0_pod);
        PxVec3 return_val(anon_param0);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxVec3_new_2(float a) {
        PxVec3 return_val(a);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxVec3_new_3(float nx, float ny, float nz) {
        PxVec3 return_val(nx, ny, nz);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxVec3_isZero(physx_PxVec3_Pod const* self__pod) {
        physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
        bool return_val = self_->isZero();
        return return_val;
    }

    bool PxVec3_isFinite(physx_PxVec3_Pod const* self__pod) {
        physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
        bool return_val = self_->isFinite();
        return return_val;
    }

    bool PxVec3_isNormalized(physx_PxVec3_Pod const* self__pod) {
        physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
        bool return_val = self_->isNormalized();
        return return_val;
    }

    float PxVec3_magnitudeSquared(physx_PxVec3_Pod const* self__pod) {
        physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
        float return_val = self_->magnitudeSquared();
        return return_val;
    }

    float PxVec3_magnitude(physx_PxVec3_Pod const* self__pod) {
        physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
        float return_val = self_->magnitude();
        return return_val;
    }

    float PxVec3_dot(physx_PxVec3_Pod const* self__pod, physx_PxVec3_Pod const* v_pod) {
        physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
        physx::PxVec3 const& v = reinterpret_cast<physx::PxVec3 const&>(*v_pod);
        float return_val = self_->dot(v);
        return return_val;
    }

    physx_PxVec3_Pod PxVec3_cross(physx_PxVec3_Pod const* self__pod, physx_PxVec3_Pod const* v_pod) {
        physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
        physx::PxVec3 const& v = reinterpret_cast<physx::PxVec3 const&>(*v_pod);
        physx::PxVec3 return_val = self_->cross(v);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxVec3_getNormalized(physx_PxVec3_Pod const* self__pod) {
        physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
        physx::PxVec3 return_val = self_->getNormalized();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    float PxVec3_normalize_mut(physx_PxVec3_Pod* self__pod) {
        physx::PxVec3* self_ = reinterpret_cast<physx::PxVec3*>(self__pod);
        float return_val = self_->normalize();
        return return_val;
    }

    float PxVec3_normalizeSafe_mut(physx_PxVec3_Pod* self__pod) {
        physx::PxVec3* self_ = reinterpret_cast<physx::PxVec3*>(self__pod);
        float return_val = self_->normalizeSafe();
        return return_val;
    }

    float PxVec3_normalizeFast_mut(physx_PxVec3_Pod* self__pod) {
        physx::PxVec3* self_ = reinterpret_cast<physx::PxVec3*>(self__pod);
        float return_val = self_->normalizeFast();
        return return_val;
    }

    physx_PxVec3_Pod PxVec3_multiply(physx_PxVec3_Pod const* self__pod, physx_PxVec3_Pod const* a_pod) {
        physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
        physx::PxVec3 const& a = reinterpret_cast<physx::PxVec3 const&>(*a_pod);
        physx::PxVec3 return_val = self_->multiply(a);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxVec3_minimum(physx_PxVec3_Pod const* self__pod, physx_PxVec3_Pod const* v_pod) {
        physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
        physx::PxVec3 const& v = reinterpret_cast<physx::PxVec3 const&>(*v_pod);
        physx::PxVec3 return_val = self_->minimum(v);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    float PxVec3_minElement(physx_PxVec3_Pod const* self__pod) {
        physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
        float return_val = self_->minElement();
        return return_val;
    }

    physx_PxVec3_Pod PxVec3_maximum(physx_PxVec3_Pod const* self__pod, physx_PxVec3_Pod const* v_pod) {
        physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
        physx::PxVec3 const& v = reinterpret_cast<physx::PxVec3 const&>(*v_pod);
        physx::PxVec3 return_val = self_->maximum(v);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    float PxVec3_maxElement(physx_PxVec3_Pod const* self__pod) {
        physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
        float return_val = self_->maxElement();
        return return_val;
    }

    physx_PxVec3_Pod PxVec3_abs(physx_PxVec3_Pod const* self__pod) {
        physx::PxVec3 const* self_ = reinterpret_cast<physx::PxVec3 const*>(self__pod);
        physx::PxVec3 return_val = self_->abs();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3Padded_Pod* PxVec3Padded_new_alloc() {
        auto return_val = new physx::PxVec3Padded();
        auto return_val_pod = reinterpret_cast<physx_PxVec3Padded_Pod*>(return_val);
        return return_val_pod;
    }

    void PxVec3Padded_delete(physx_PxVec3Padded_Pod* self__pod) {
        physx::PxVec3Padded* self_ = reinterpret_cast<physx::PxVec3Padded*>(self__pod);
        delete self_;
    }

    physx_PxVec3Padded_Pod* PxVec3Padded_new_alloc_1(physx_PxVec3_Pod const* p_pod) {
        physx::PxVec3 const& p = reinterpret_cast<physx::PxVec3 const&>(*p_pod);
        auto return_val = new physx::PxVec3Padded(p);
        auto return_val_pod = reinterpret_cast<physx_PxVec3Padded_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxVec3Padded_Pod* PxVec3Padded_new_alloc_2(float f) {
        auto return_val = new physx::PxVec3Padded(f);
        auto return_val_pod = reinterpret_cast<physx_PxVec3Padded_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxQuat_Pod PxQuat_new() {
        PxQuat return_val;
        physx_PxQuat_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxQuat_Pod PxQuat_new_1(int32_t anon_param0_pod) {
        auto anon_param0 = static_cast<physx::PxIDENTITY>(anon_param0_pod);
        PxQuat return_val(anon_param0);
        physx_PxQuat_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxQuat_Pod PxQuat_new_2(float r) {
        PxQuat return_val(r);
        physx_PxQuat_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxQuat_Pod PxQuat_new_3(float nx, float ny, float nz, float nw) {
        PxQuat return_val(nx, ny, nz, nw);
        physx_PxQuat_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxQuat_Pod PxQuat_new_4(float angleRadians, physx_PxVec3_Pod const* unitAxis_pod) {
        physx::PxVec3 const& unitAxis = reinterpret_cast<physx::PxVec3 const&>(*unitAxis_pod);
        PxQuat return_val(angleRadians, unitAxis);
        physx_PxQuat_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxQuat_Pod PxQuat_new_5(physx_PxMat33_Pod const* m_pod) {
        physx::PxMat33 const& m = reinterpret_cast<physx::PxMat33 const&>(*m_pod);
        PxQuat return_val(m);
        physx_PxQuat_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxQuat_isIdentity(physx_PxQuat_Pod const* self__pod) {
        physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
        bool return_val = self_->isIdentity();
        return return_val;
    }

    bool PxQuat_isFinite(physx_PxQuat_Pod const* self__pod) {
        physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
        bool return_val = self_->isFinite();
        return return_val;
    }

    bool PxQuat_isUnit(physx_PxQuat_Pod const* self__pod) {
        physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
        bool return_val = self_->isUnit();
        return return_val;
    }

    bool PxQuat_isSane(physx_PxQuat_Pod const* self__pod) {
        physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
        bool return_val = self_->isSane();
        return return_val;
    }

    void PxQuat_toRadiansAndUnitAxis(physx_PxQuat_Pod const* self__pod, float* angle_pod, physx_PxVec3_Pod* axis_pod) {
        physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
        float& angle = *angle_pod;
        physx::PxVec3& axis = reinterpret_cast<physx::PxVec3&>(*axis_pod);
        self_->toRadiansAndUnitAxis(angle, axis);
    }

    float PxQuat_getAngle(physx_PxQuat_Pod const* self__pod) {
        physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
        float return_val = self_->getAngle();
        return return_val;
    }

    float PxQuat_getAngle_1(physx_PxQuat_Pod const* self__pod, physx_PxQuat_Pod const* q_pod) {
        physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
        physx::PxQuat const& q = reinterpret_cast<physx::PxQuat const&>(*q_pod);
        float return_val = self_->getAngle(q);
        return return_val;
    }

    float PxQuat_magnitudeSquared(physx_PxQuat_Pod const* self__pod) {
        physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
        float return_val = self_->magnitudeSquared();
        return return_val;
    }

    float PxQuat_dot(physx_PxQuat_Pod const* self__pod, physx_PxQuat_Pod const* v_pod) {
        physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
        physx::PxQuat const& v = reinterpret_cast<physx::PxQuat const&>(*v_pod);
        float return_val = self_->dot(v);
        return return_val;
    }

    physx_PxQuat_Pod PxQuat_getNormalized(physx_PxQuat_Pod const* self__pod) {
        physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
        physx::PxQuat return_val = self_->getNormalized();
        physx_PxQuat_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    float PxQuat_magnitude(physx_PxQuat_Pod const* self__pod) {
        physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
        float return_val = self_->magnitude();
        return return_val;
    }

    float PxQuat_normalize_mut(physx_PxQuat_Pod* self__pod) {
        physx::PxQuat* self_ = reinterpret_cast<physx::PxQuat*>(self__pod);
        float return_val = self_->normalize();
        return return_val;
    }

    physx_PxQuat_Pod PxQuat_getConjugate(physx_PxQuat_Pod const* self__pod) {
        physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
        physx::PxQuat return_val = self_->getConjugate();
        physx_PxQuat_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxQuat_getImaginaryPart(physx_PxQuat_Pod const* self__pod) {
        physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
        physx::PxVec3 return_val = self_->getImaginaryPart();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxQuat_getBasisVector0(physx_PxQuat_Pod const* self__pod) {
        physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
        physx::PxVec3 return_val = self_->getBasisVector0();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxQuat_getBasisVector1(physx_PxQuat_Pod const* self__pod) {
        physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
        physx::PxVec3 return_val = self_->getBasisVector1();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxQuat_getBasisVector2(physx_PxQuat_Pod const* self__pod) {
        physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
        physx::PxVec3 return_val = self_->getBasisVector2();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxQuat_rotate(physx_PxQuat_Pod const* self__pod, physx_PxVec3_Pod const* v_pod) {
        physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
        physx::PxVec3 const& v = reinterpret_cast<physx::PxVec3 const&>(*v_pod);
        physx::PxVec3 return_val = self_->rotate(v);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxQuat_rotateInv(physx_PxQuat_Pod const* self__pod, physx_PxVec3_Pod const* v_pod) {
        physx::PxQuat const* self_ = reinterpret_cast<physx::PxQuat const*>(self__pod);
        physx::PxVec3 const& v = reinterpret_cast<physx::PxVec3 const&>(*v_pod);
        physx::PxVec3 return_val = self_->rotateInv(v);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxTransform_Pod PxTransform_new() {
        PxTransform return_val;
        physx_PxTransform_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxTransform_Pod PxTransform_new_1(physx_PxVec3_Pod const* position_pod) {
        physx::PxVec3 const& position = reinterpret_cast<physx::PxVec3 const&>(*position_pod);
        PxTransform return_val(position);
        physx_PxTransform_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxTransform_Pod PxTransform_new_2(int32_t anon_param0_pod) {
        auto anon_param0 = static_cast<physx::PxIDENTITY>(anon_param0_pod);
        PxTransform return_val(anon_param0);
        physx_PxTransform_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxTransform_Pod PxTransform_new_3(physx_PxQuat_Pod const* orientation_pod) {
        physx::PxQuat const& orientation = reinterpret_cast<physx::PxQuat const&>(*orientation_pod);
        PxTransform return_val(orientation);
        physx_PxTransform_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxTransform_Pod PxTransform_new_4(float x, float y, float z, physx_PxQuat_Pod aQ_pod) {
        physx::PxQuat aQ;
        memcpy(&aQ, &aQ_pod, sizeof(aQ));
        PxTransform return_val(x, y, z, aQ);
        physx_PxTransform_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxTransform_Pod PxTransform_new_5(physx_PxVec3_Pod const* p0_pod, physx_PxQuat_Pod const* q0_pod) {
        physx::PxVec3 const& p0 = reinterpret_cast<physx::PxVec3 const&>(*p0_pod);
        physx::PxQuat const& q0 = reinterpret_cast<physx::PxQuat const&>(*q0_pod);
        PxTransform return_val(p0, q0);
        physx_PxTransform_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxTransform_Pod PxTransform_new_6(physx_PxMat44_Pod const* m_pod) {
        physx::PxMat44 const& m = reinterpret_cast<physx::PxMat44 const&>(*m_pod);
        PxTransform return_val(m);
        physx_PxTransform_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxTransform_Pod PxTransform_getInverse(physx_PxTransform_Pod const* self__pod) {
        physx::PxTransform const* self_ = reinterpret_cast<physx::PxTransform const*>(self__pod);
        physx::PxTransform return_val = self_->getInverse();
        physx_PxTransform_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxTransform_transform(physx_PxTransform_Pod const* self__pod, physx_PxVec3_Pod const* input_pod) {
        physx::PxTransform const* self_ = reinterpret_cast<physx::PxTransform const*>(self__pod);
        physx::PxVec3 const& input = reinterpret_cast<physx::PxVec3 const&>(*input_pod);
        physx::PxVec3 return_val = self_->transform(input);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxTransform_transformInv(physx_PxTransform_Pod const* self__pod, physx_PxVec3_Pod const* input_pod) {
        physx::PxTransform const* self_ = reinterpret_cast<physx::PxTransform const*>(self__pod);
        physx::PxVec3 const& input = reinterpret_cast<physx::PxVec3 const&>(*input_pod);
        physx::PxVec3 return_val = self_->transformInv(input);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxTransform_rotate(physx_PxTransform_Pod const* self__pod, physx_PxVec3_Pod const* input_pod) {
        physx::PxTransform const* self_ = reinterpret_cast<physx::PxTransform const*>(self__pod);
        physx::PxVec3 const& input = reinterpret_cast<physx::PxVec3 const&>(*input_pod);
        physx::PxVec3 return_val = self_->rotate(input);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxTransform_rotateInv(physx_PxTransform_Pod const* self__pod, physx_PxVec3_Pod const* input_pod) {
        physx::PxTransform const* self_ = reinterpret_cast<physx::PxTransform const*>(self__pod);
        physx::PxVec3 const& input = reinterpret_cast<physx::PxVec3 const&>(*input_pod);
        physx::PxVec3 return_val = self_->rotateInv(input);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxTransform_Pod PxTransform_transform_1(physx_PxTransform_Pod const* self__pod, physx_PxTransform_Pod const* src_pod) {
        physx::PxTransform const* self_ = reinterpret_cast<physx::PxTransform const*>(self__pod);
        physx::PxTransform const& src = reinterpret_cast<physx::PxTransform const&>(*src_pod);
        physx::PxTransform return_val = self_->transform(src);
        physx_PxTransform_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxTransform_isValid(physx_PxTransform_Pod const* self__pod) {
        physx::PxTransform const* self_ = reinterpret_cast<physx::PxTransform const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    bool PxTransform_isSane(physx_PxTransform_Pod const* self__pod) {
        physx::PxTransform const* self_ = reinterpret_cast<physx::PxTransform const*>(self__pod);
        bool return_val = self_->isSane();
        return return_val;
    }

    bool PxTransform_isFinite(physx_PxTransform_Pod const* self__pod) {
        physx::PxTransform const* self_ = reinterpret_cast<physx::PxTransform const*>(self__pod);
        bool return_val = self_->isFinite();
        return return_val;
    }

    physx_PxTransform_Pod PxTransform_transformInv_1(physx_PxTransform_Pod const* self__pod, physx_PxTransform_Pod const* src_pod) {
        physx::PxTransform const* self_ = reinterpret_cast<physx::PxTransform const*>(self__pod);
        physx::PxTransform const& src = reinterpret_cast<physx::PxTransform const&>(*src_pod);
        physx::PxTransform return_val = self_->transformInv(src);
        physx_PxTransform_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxTransform_Pod PxTransform_getNormalized(physx_PxTransform_Pod const* self__pod) {
        physx::PxTransform const* self_ = reinterpret_cast<physx::PxTransform const*>(self__pod);
        physx::PxTransform return_val = self_->getNormalized();
        physx_PxTransform_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMat33_Pod PxMat33_new() {
        PxMat33 return_val;
        physx_PxMat33_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMat33_Pod PxMat33_new_1(int32_t anon_param0_pod) {
        auto anon_param0 = static_cast<physx::PxIDENTITY>(anon_param0_pod);
        PxMat33 return_val(anon_param0);
        physx_PxMat33_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMat33_Pod PxMat33_new_2(int32_t anon_param0_pod) {
        auto anon_param0 = static_cast<physx::PxZERO>(anon_param0_pod);
        PxMat33 return_val(anon_param0);
        physx_PxMat33_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMat33_Pod PxMat33_new_3(physx_PxVec3_Pod const* col0_pod, physx_PxVec3_Pod const* col1_pod, physx_PxVec3_Pod const* col2_pod) {
        physx::PxVec3 const& col0 = reinterpret_cast<physx::PxVec3 const&>(*col0_pod);
        physx::PxVec3 const& col1 = reinterpret_cast<physx::PxVec3 const&>(*col1_pod);
        physx::PxVec3 const& col2 = reinterpret_cast<physx::PxVec3 const&>(*col2_pod);
        PxMat33 return_val(col0, col1, col2);
        physx_PxMat33_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMat33_Pod PxMat33_new_4(float r) {
        PxMat33 return_val(r);
        physx_PxMat33_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMat33_Pod PxMat33_new_5(float* values) {
        PxMat33 return_val(values);
        physx_PxMat33_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMat33_Pod PxMat33_new_6(physx_PxQuat_Pod const* q_pod) {
        physx::PxQuat const& q = reinterpret_cast<physx::PxQuat const&>(*q_pod);
        PxMat33 return_val(q);
        physx_PxMat33_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMat33_Pod PxMat33_createDiagonal(physx_PxVec3_Pod const* d_pod) {
        physx::PxVec3 const& d = reinterpret_cast<physx::PxVec3 const&>(*d_pod);
        physx::PxMat33 return_val = PxMat33::createDiagonal(d);
        physx_PxMat33_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMat33_Pod PxMat33_outer(physx_PxVec3_Pod const* a_pod, physx_PxVec3_Pod const* b_pod) {
        physx::PxVec3 const& a = reinterpret_cast<physx::PxVec3 const&>(*a_pod);
        physx::PxVec3 const& b = reinterpret_cast<physx::PxVec3 const&>(*b_pod);
        physx::PxMat33 return_val = PxMat33::outer(a, b);
        physx_PxMat33_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMat33_Pod PxMat33_getTranspose(physx_PxMat33_Pod const* self__pod) {
        physx::PxMat33 const* self_ = reinterpret_cast<physx::PxMat33 const*>(self__pod);
        physx::PxMat33 return_val = self_->getTranspose();
        physx_PxMat33_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMat33_Pod PxMat33_getInverse(physx_PxMat33_Pod const* self__pod) {
        physx::PxMat33 const* self_ = reinterpret_cast<physx::PxMat33 const*>(self__pod);
        physx::PxMat33 return_val = self_->getInverse();
        physx_PxMat33_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    float PxMat33_getDeterminant(physx_PxMat33_Pod const* self__pod) {
        physx::PxMat33 const* self_ = reinterpret_cast<physx::PxMat33 const*>(self__pod);
        float return_val = self_->getDeterminant();
        return return_val;
    }

    physx_PxVec3_Pod PxMat33_transform(physx_PxMat33_Pod const* self__pod, physx_PxVec3_Pod const* other_pod) {
        physx::PxMat33 const* self_ = reinterpret_cast<physx::PxMat33 const*>(self__pod);
        physx::PxVec3 const& other = reinterpret_cast<physx::PxVec3 const&>(*other_pod);
        physx::PxVec3 return_val = self_->transform(other);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxMat33_transformTranspose(physx_PxMat33_Pod const* self__pod, physx_PxVec3_Pod const* other_pod) {
        physx::PxMat33 const* self_ = reinterpret_cast<physx::PxMat33 const*>(self__pod);
        physx::PxVec3 const& other = reinterpret_cast<physx::PxVec3 const&>(*other_pod);
        physx::PxVec3 return_val = self_->transformTranspose(other);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    float const* PxMat33_front(physx_PxMat33_Pod const* self__pod) {
        physx::PxMat33 const* self_ = reinterpret_cast<physx::PxMat33 const*>(self__pod);
        float const* return_val = self_->front();
        return return_val;
    }

    physx_PxBounds3_Pod PxBounds3_new() {
        PxBounds3 return_val;
        physx_PxBounds3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxBounds3_Pod PxBounds3_new_1(physx_PxVec3_Pod const* minimum_pod, physx_PxVec3_Pod const* maximum_pod) {
        physx::PxVec3 const& minimum = reinterpret_cast<physx::PxVec3 const&>(*minimum_pod);
        physx::PxVec3 const& maximum = reinterpret_cast<physx::PxVec3 const&>(*maximum_pod);
        PxBounds3 return_val(minimum, maximum);
        physx_PxBounds3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxBounds3_Pod PxBounds3_empty() {
        physx::PxBounds3 return_val = PxBounds3::empty();
        physx_PxBounds3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxBounds3_Pod PxBounds3_boundsOfPoints(physx_PxVec3_Pod const* v0_pod, physx_PxVec3_Pod const* v1_pod) {
        physx::PxVec3 const& v0 = reinterpret_cast<physx::PxVec3 const&>(*v0_pod);
        physx::PxVec3 const& v1 = reinterpret_cast<physx::PxVec3 const&>(*v1_pod);
        physx::PxBounds3 return_val = PxBounds3::boundsOfPoints(v0, v1);
        physx_PxBounds3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxBounds3_Pod PxBounds3_centerExtents(physx_PxVec3_Pod const* center_pod, physx_PxVec3_Pod const* extent_pod) {
        physx::PxVec3 const& center = reinterpret_cast<physx::PxVec3 const&>(*center_pod);
        physx::PxVec3 const& extent = reinterpret_cast<physx::PxVec3 const&>(*extent_pod);
        physx::PxBounds3 return_val = PxBounds3::centerExtents(center, extent);
        physx_PxBounds3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxBounds3_Pod PxBounds3_basisExtent(physx_PxVec3_Pod const* center_pod, physx_PxMat33_Pod const* basis_pod, physx_PxVec3_Pod const* extent_pod) {
        physx::PxVec3 const& center = reinterpret_cast<physx::PxVec3 const&>(*center_pod);
        physx::PxMat33 const& basis = reinterpret_cast<physx::PxMat33 const&>(*basis_pod);
        physx::PxVec3 const& extent = reinterpret_cast<physx::PxVec3 const&>(*extent_pod);
        physx::PxBounds3 return_val = PxBounds3::basisExtent(center, basis, extent);
        physx_PxBounds3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxBounds3_Pod PxBounds3_poseExtent(physx_PxTransform_Pod const* pose_pod, physx_PxVec3_Pod const* extent_pod) {
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        physx::PxVec3 const& extent = reinterpret_cast<physx::PxVec3 const&>(*extent_pod);
        physx::PxBounds3 return_val = PxBounds3::poseExtent(pose, extent);
        physx_PxBounds3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxBounds3_Pod PxBounds3_transformSafe(physx_PxMat33_Pod const* matrix_pod, physx_PxBounds3_Pod const* bounds_pod) {
        physx::PxMat33 const& matrix = reinterpret_cast<physx::PxMat33 const&>(*matrix_pod);
        physx::PxBounds3 const& bounds = reinterpret_cast<physx::PxBounds3 const&>(*bounds_pod);
        physx::PxBounds3 return_val = PxBounds3::transformSafe(matrix, bounds);
        physx_PxBounds3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxBounds3_Pod PxBounds3_transformFast(physx_PxMat33_Pod const* matrix_pod, physx_PxBounds3_Pod const* bounds_pod) {
        physx::PxMat33 const& matrix = reinterpret_cast<physx::PxMat33 const&>(*matrix_pod);
        physx::PxBounds3 const& bounds = reinterpret_cast<physx::PxBounds3 const&>(*bounds_pod);
        physx::PxBounds3 return_val = PxBounds3::transformFast(matrix, bounds);
        physx_PxBounds3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxBounds3_Pod PxBounds3_transformSafe_1(physx_PxTransform_Pod const* transform_pod, physx_PxBounds3_Pod const* bounds_pod) {
        physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
        physx::PxBounds3 const& bounds = reinterpret_cast<physx::PxBounds3 const&>(*bounds_pod);
        physx::PxBounds3 return_val = PxBounds3::transformSafe(transform, bounds);
        physx_PxBounds3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxBounds3_Pod PxBounds3_transformFast_1(physx_PxTransform_Pod const* transform_pod, physx_PxBounds3_Pod const* bounds_pod) {
        physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
        physx::PxBounds3 const& bounds = reinterpret_cast<physx::PxBounds3 const&>(*bounds_pod);
        physx::PxBounds3 return_val = PxBounds3::transformFast(transform, bounds);
        physx_PxBounds3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
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
        bool return_val = self_->isEmpty();
        return return_val;
    }

    bool PxBounds3_intersects(physx_PxBounds3_Pod const* self__pod, physx_PxBounds3_Pod const* b_pod) {
        physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
        physx::PxBounds3 const& b = reinterpret_cast<physx::PxBounds3 const&>(*b_pod);
        bool return_val = self_->intersects(b);
        return return_val;
    }

    bool PxBounds3_intersects1D(physx_PxBounds3_Pod const* self__pod, physx_PxBounds3_Pod const* a_pod, uint32_t axis) {
        physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
        physx::PxBounds3 const& a = reinterpret_cast<physx::PxBounds3 const&>(*a_pod);
        bool return_val = self_->intersects1D(a, axis);
        return return_val;
    }

    bool PxBounds3_contains(physx_PxBounds3_Pod const* self__pod, physx_PxVec3_Pod const* v_pod) {
        physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
        physx::PxVec3 const& v = reinterpret_cast<physx::PxVec3 const&>(*v_pod);
        bool return_val = self_->contains(v);
        return return_val;
    }

    bool PxBounds3_isInside(physx_PxBounds3_Pod const* self__pod, physx_PxBounds3_Pod const* box_pod) {
        physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
        physx::PxBounds3 const& box = reinterpret_cast<physx::PxBounds3 const&>(*box_pod);
        bool return_val = self_->isInside(box);
        return return_val;
    }

    physx_PxVec3_Pod PxBounds3_getCenter(physx_PxBounds3_Pod const* self__pod) {
        physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
        physx::PxVec3 return_val = self_->getCenter();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    float PxBounds3_getCenter_1(physx_PxBounds3_Pod const* self__pod, uint32_t axis) {
        physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
        float return_val = self_->getCenter(axis);
        return return_val;
    }

    float PxBounds3_getExtents(physx_PxBounds3_Pod const* self__pod, uint32_t axis) {
        physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
        float return_val = self_->getExtents(axis);
        return return_val;
    }

    physx_PxVec3_Pod PxBounds3_getDimensions(physx_PxBounds3_Pod const* self__pod) {
        physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
        physx::PxVec3 return_val = self_->getDimensions();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxBounds3_getExtents_1(physx_PxBounds3_Pod const* self__pod) {
        physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
        physx::PxVec3 return_val = self_->getExtents();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
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
        bool return_val = self_->isFinite();
        return return_val;
    }

    bool PxBounds3_isValid(physx_PxBounds3_Pod const* self__pod) {
        physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    physx_PxVec3_Pod PxBounds3_closestPoint(physx_PxBounds3_Pod const* self__pod, physx_PxVec3_Pod const* p_pod) {
        physx::PxBounds3 const* self_ = reinterpret_cast<physx::PxBounds3 const*>(self__pod);
        physx::PxVec3 const& p = reinterpret_cast<physx::PxVec3 const&>(*p_pod);
        physx::PxVec3 return_val = self_->closestPoint(p);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxErrorCallback_delete(physx_PxErrorCallback_Pod* self__pod) {
        physx::PxErrorCallback* self_ = reinterpret_cast<physx::PxErrorCallback*>(self__pod);
        delete self_;
    }

    void PxErrorCallback_reportError_mut(physx_PxErrorCallback_Pod* self__pod, int32_t code_pod, char const* message, char const* file, int32_t line) {
        physx::PxErrorCallback* self_ = reinterpret_cast<physx::PxErrorCallback*>(self__pod);
        auto code = static_cast<physx::PxErrorCode::Enum>(code_pod);
        self_->reportError(code, message, file, line);
    }

    void PxAllocationListener_onAllocation_mut(physx_PxAllocationListener_Pod* self__pod, size_t size_pod, char const* typeName, char const* filename, int32_t line, void* allocatedMemory) {
        physx::PxAllocationListener* self_ = reinterpret_cast<physx::PxAllocationListener*>(self__pod);
        size_t size;
        memcpy(&size, &size_pod, sizeof(size));
        self_->onAllocation(size, typeName, filename, line, allocatedMemory);
    }

    void PxAllocationListener_onDeallocation_mut(physx_PxAllocationListener_Pod* self__pod, void* allocatedMemory) {
        physx::PxAllocationListener* self_ = reinterpret_cast<physx::PxAllocationListener*>(self__pod);
        self_->onDeallocation(allocatedMemory);
    }

    physx_PxBroadcastingAllocator_Pod* PxBroadcastingAllocator_new_alloc(physx_PxAllocatorCallback_Pod* allocator_pod, physx_PxErrorCallback_Pod* error_pod) {
        physx::PxAllocatorCallback& allocator = reinterpret_cast<physx::PxAllocatorCallback&>(*allocator_pod);
        physx::PxErrorCallback& error = reinterpret_cast<physx::PxErrorCallback&>(*error_pod);
        auto return_val = new physx::PxBroadcastingAllocator(allocator, error);
        auto return_val_pod = reinterpret_cast<physx_PxBroadcastingAllocator_Pod*>(return_val);
        return return_val_pod;
    }

    void PxBroadcastingAllocator_delete(physx_PxBroadcastingAllocator_Pod* self__pod) {
        physx::PxBroadcastingAllocator* self_ = reinterpret_cast<physx::PxBroadcastingAllocator*>(self__pod);
        delete self_;
    }

    void* PxBroadcastingAllocator_allocate_mut(physx_PxBroadcastingAllocator_Pod* self__pod, size_t size_pod, char const* typeName, char const* filename, int32_t line) {
        physx::PxBroadcastingAllocator* self_ = reinterpret_cast<physx::PxBroadcastingAllocator*>(self__pod);
        size_t size;
        memcpy(&size, &size_pod, sizeof(size));
        void* return_val = self_->allocate(size, typeName, filename, line);
        return return_val;
    }

    void PxBroadcastingAllocator_deallocate_mut(physx_PxBroadcastingAllocator_Pod* self__pod, void* ptr) {
        physx::PxBroadcastingAllocator* self_ = reinterpret_cast<physx::PxBroadcastingAllocator*>(self__pod);
        self_->deallocate(ptr);
    }

    physx_PxBroadcastingErrorCallback_Pod* PxBroadcastingErrorCallback_new_alloc(physx_PxErrorCallback_Pod* errorCallback_pod) {
        physx::PxErrorCallback& errorCallback = reinterpret_cast<physx::PxErrorCallback&>(*errorCallback_pod);
        auto return_val = new physx::PxBroadcastingErrorCallback(errorCallback);
        auto return_val_pod = reinterpret_cast<physx_PxBroadcastingErrorCallback_Pod*>(return_val);
        return return_val_pod;
    }

    void PxBroadcastingErrorCallback_delete(physx_PxBroadcastingErrorCallback_Pod* self__pod) {
        physx::PxBroadcastingErrorCallback* self_ = reinterpret_cast<physx::PxBroadcastingErrorCallback*>(self__pod);
        delete self_;
    }

    void PxBroadcastingErrorCallback_reportError_mut(physx_PxBroadcastingErrorCallback_Pod* self__pod, int32_t code_pod, char const* message, char const* file, int32_t line) {
        physx::PxBroadcastingErrorCallback* self_ = reinterpret_cast<physx::PxBroadcastingErrorCallback*>(self__pod);
        auto code = static_cast<physx::PxErrorCode::Enum>(code_pod);
        self_->reportError(code, message, file, line);
    }

    void phys_PxEnableFPExceptions() {
        PxEnableFPExceptions();
    }

    void phys_PxDisableFPExceptions() {
        PxDisableFPExceptions();
    }

    uint32_t PxInputStream_read_mut(physx_PxInputStream_Pod* self__pod, void* dest, uint32_t count) {
        physx::PxInputStream* self_ = reinterpret_cast<physx::PxInputStream*>(self__pod);
        uint32_t return_val = self_->read(dest, count);
        return return_val;
    }

    void PxInputStream_delete(physx_PxInputStream_Pod* self__pod) {
        physx::PxInputStream* self_ = reinterpret_cast<physx::PxInputStream*>(self__pod);
        delete self_;
    }

    uint32_t PxInputData_getLength(physx_PxInputData_Pod const* self__pod) {
        physx::PxInputData const* self_ = reinterpret_cast<physx::PxInputData const*>(self__pod);
        uint32_t return_val = self_->getLength();
        return return_val;
    }

    void PxInputData_seek_mut(physx_PxInputData_Pod* self__pod, uint32_t offset) {
        physx::PxInputData* self_ = reinterpret_cast<physx::PxInputData*>(self__pod);
        self_->seek(offset);
    }

    uint32_t PxInputData_tell(physx_PxInputData_Pod const* self__pod) {
        physx::PxInputData const* self_ = reinterpret_cast<physx::PxInputData const*>(self__pod);
        uint32_t return_val = self_->tell();
        return return_val;
    }

    void PxInputData_delete(physx_PxInputData_Pod* self__pod) {
        physx::PxInputData* self_ = reinterpret_cast<physx::PxInputData*>(self__pod);
        delete self_;
    }

    uint32_t PxOutputStream_write_mut(physx_PxOutputStream_Pod* self__pod, void const* src, uint32_t count) {
        physx::PxOutputStream* self_ = reinterpret_cast<physx::PxOutputStream*>(self__pod);
        uint32_t return_val = self_->write(src, count);
        return return_val;
    }

    void PxOutputStream_delete(physx_PxOutputStream_Pod* self__pod) {
        physx::PxOutputStream* self_ = reinterpret_cast<physx::PxOutputStream*>(self__pod);
        delete self_;
    }

    physx_PxVec4_Pod PxVec4_new() {
        PxVec4 return_val;
        physx_PxVec4_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec4_Pod PxVec4_new_1(int32_t anon_param0_pod) {
        auto anon_param0 = static_cast<physx::PxZERO>(anon_param0_pod);
        PxVec4 return_val(anon_param0);
        physx_PxVec4_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec4_Pod PxVec4_new_2(float a) {
        PxVec4 return_val(a);
        physx_PxVec4_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec4_Pod PxVec4_new_3(float nx, float ny, float nz, float nw) {
        PxVec4 return_val(nx, ny, nz, nw);
        physx_PxVec4_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec4_Pod PxVec4_new_4(physx_PxVec3_Pod const* v_pod, float nw) {
        physx::PxVec3 const& v = reinterpret_cast<physx::PxVec3 const&>(*v_pod);
        PxVec4 return_val(v, nw);
        physx_PxVec4_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec4_Pod PxVec4_new_5(float const* v) {
        PxVec4 return_val(v);
        physx_PxVec4_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxVec4_isZero(physx_PxVec4_Pod const* self__pod) {
        physx::PxVec4 const* self_ = reinterpret_cast<physx::PxVec4 const*>(self__pod);
        bool return_val = self_->isZero();
        return return_val;
    }

    bool PxVec4_isFinite(physx_PxVec4_Pod const* self__pod) {
        physx::PxVec4 const* self_ = reinterpret_cast<physx::PxVec4 const*>(self__pod);
        bool return_val = self_->isFinite();
        return return_val;
    }

    bool PxVec4_isNormalized(physx_PxVec4_Pod const* self__pod) {
        physx::PxVec4 const* self_ = reinterpret_cast<physx::PxVec4 const*>(self__pod);
        bool return_val = self_->isNormalized();
        return return_val;
    }

    float PxVec4_magnitudeSquared(physx_PxVec4_Pod const* self__pod) {
        physx::PxVec4 const* self_ = reinterpret_cast<physx::PxVec4 const*>(self__pod);
        float return_val = self_->magnitudeSquared();
        return return_val;
    }

    float PxVec4_magnitude(physx_PxVec4_Pod const* self__pod) {
        physx::PxVec4 const* self_ = reinterpret_cast<physx::PxVec4 const*>(self__pod);
        float return_val = self_->magnitude();
        return return_val;
    }

    float PxVec4_dot(physx_PxVec4_Pod const* self__pod, physx_PxVec4_Pod const* v_pod) {
        physx::PxVec4 const* self_ = reinterpret_cast<physx::PxVec4 const*>(self__pod);
        physx::PxVec4 const& v = reinterpret_cast<physx::PxVec4 const&>(*v_pod);
        float return_val = self_->dot(v);
        return return_val;
    }

    physx_PxVec4_Pod PxVec4_getNormalized(physx_PxVec4_Pod const* self__pod) {
        physx::PxVec4 const* self_ = reinterpret_cast<physx::PxVec4 const*>(self__pod);
        physx::PxVec4 return_val = self_->getNormalized();
        physx_PxVec4_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    float PxVec4_normalize_mut(physx_PxVec4_Pod* self__pod) {
        physx::PxVec4* self_ = reinterpret_cast<physx::PxVec4*>(self__pod);
        float return_val = self_->normalize();
        return return_val;
    }

    physx_PxVec4_Pod PxVec4_multiply(physx_PxVec4_Pod const* self__pod, physx_PxVec4_Pod const* a_pod) {
        physx::PxVec4 const* self_ = reinterpret_cast<physx::PxVec4 const*>(self__pod);
        physx::PxVec4 const& a = reinterpret_cast<physx::PxVec4 const&>(*a_pod);
        physx::PxVec4 return_val = self_->multiply(a);
        physx_PxVec4_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec4_Pod PxVec4_minimum(physx_PxVec4_Pod const* self__pod, physx_PxVec4_Pod const* v_pod) {
        physx::PxVec4 const* self_ = reinterpret_cast<physx::PxVec4 const*>(self__pod);
        physx::PxVec4 const& v = reinterpret_cast<physx::PxVec4 const&>(*v_pod);
        physx::PxVec4 return_val = self_->minimum(v);
        physx_PxVec4_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec4_Pod PxVec4_maximum(physx_PxVec4_Pod const* self__pod, physx_PxVec4_Pod const* v_pod) {
        physx::PxVec4 const* self_ = reinterpret_cast<physx::PxVec4 const*>(self__pod);
        physx::PxVec4 const& v = reinterpret_cast<physx::PxVec4 const&>(*v_pod);
        physx::PxVec4 return_val = self_->maximum(v);
        physx_PxVec4_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxVec4_getXYZ(physx_PxVec4_Pod const* self__pod) {
        physx::PxVec4 const* self_ = reinterpret_cast<physx::PxVec4 const*>(self__pod);
        physx::PxVec3 return_val = self_->getXYZ();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMat44_Pod PxMat44_new() {
        PxMat44 return_val;
        physx_PxMat44_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMat44_Pod PxMat44_new_1(int32_t anon_param0_pod) {
        auto anon_param0 = static_cast<physx::PxIDENTITY>(anon_param0_pod);
        PxMat44 return_val(anon_param0);
        physx_PxMat44_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMat44_Pod PxMat44_new_2(int32_t anon_param0_pod) {
        auto anon_param0 = static_cast<physx::PxZERO>(anon_param0_pod);
        PxMat44 return_val(anon_param0);
        physx_PxMat44_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMat44_Pod PxMat44_new_3(physx_PxVec4_Pod const* col0_pod, physx_PxVec4_Pod const* col1_pod, physx_PxVec4_Pod const* col2_pod, physx_PxVec4_Pod const* col3_pod) {
        physx::PxVec4 const& col0 = reinterpret_cast<physx::PxVec4 const&>(*col0_pod);
        physx::PxVec4 const& col1 = reinterpret_cast<physx::PxVec4 const&>(*col1_pod);
        physx::PxVec4 const& col2 = reinterpret_cast<physx::PxVec4 const&>(*col2_pod);
        physx::PxVec4 const& col3 = reinterpret_cast<physx::PxVec4 const&>(*col3_pod);
        PxMat44 return_val(col0, col1, col2, col3);
        physx_PxMat44_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMat44_Pod PxMat44_new_4(float r) {
        PxMat44 return_val(r);
        physx_PxMat44_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMat44_Pod PxMat44_new_5(physx_PxVec3_Pod const* col0_pod, physx_PxVec3_Pod const* col1_pod, physx_PxVec3_Pod const* col2_pod, physx_PxVec3_Pod const* col3_pod) {
        physx::PxVec3 const& col0 = reinterpret_cast<physx::PxVec3 const&>(*col0_pod);
        physx::PxVec3 const& col1 = reinterpret_cast<physx::PxVec3 const&>(*col1_pod);
        physx::PxVec3 const& col2 = reinterpret_cast<physx::PxVec3 const&>(*col2_pod);
        physx::PxVec3 const& col3 = reinterpret_cast<physx::PxVec3 const&>(*col3_pod);
        PxMat44 return_val(col0, col1, col2, col3);
        physx_PxMat44_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMat44_Pod PxMat44_new_6(float* values) {
        PxMat44 return_val(values);
        physx_PxMat44_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMat44_Pod PxMat44_new_7(physx_PxQuat_Pod const* q_pod) {
        physx::PxQuat const& q = reinterpret_cast<physx::PxQuat const&>(*q_pod);
        PxMat44 return_val(q);
        physx_PxMat44_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMat44_Pod PxMat44_new_8(physx_PxVec4_Pod const* diagonal_pod) {
        physx::PxVec4 const& diagonal = reinterpret_cast<physx::PxVec4 const&>(*diagonal_pod);
        PxMat44 return_val(diagonal);
        physx_PxMat44_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMat44_Pod PxMat44_new_9(physx_PxMat33_Pod const* axes_pod, physx_PxVec3_Pod const* position_pod) {
        physx::PxMat33 const& axes = reinterpret_cast<physx::PxMat33 const&>(*axes_pod);
        physx::PxVec3 const& position = reinterpret_cast<physx::PxVec3 const&>(*position_pod);
        PxMat44 return_val(axes, position);
        physx_PxMat44_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMat44_Pod PxMat44_new_10(physx_PxTransform_Pod const* t_pod) {
        physx::PxTransform const& t = reinterpret_cast<physx::PxTransform const&>(*t_pod);
        PxMat44 return_val(t);
        physx_PxMat44_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMat44_Pod PxMat44_getTranspose(physx_PxMat44_Pod const* self__pod) {
        physx::PxMat44 const* self_ = reinterpret_cast<physx::PxMat44 const*>(self__pod);
        physx::PxMat44 return_val = self_->getTranspose();
        physx_PxMat44_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec4_Pod PxMat44_transform(physx_PxMat44_Pod const* self__pod, physx_PxVec4_Pod const* other_pod) {
        physx::PxMat44 const* self_ = reinterpret_cast<physx::PxMat44 const*>(self__pod);
        physx::PxVec4 const& other = reinterpret_cast<physx::PxVec4 const&>(*other_pod);
        physx::PxVec4 return_val = self_->transform(other);
        physx_PxVec4_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxMat44_transform_1(physx_PxMat44_Pod const* self__pod, physx_PxVec3_Pod const* other_pod) {
        physx::PxMat44 const* self_ = reinterpret_cast<physx::PxMat44 const*>(self__pod);
        physx::PxVec3 const& other = reinterpret_cast<physx::PxVec3 const&>(*other_pod);
        physx::PxVec3 return_val = self_->transform(other);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec4_Pod PxMat44_rotate(physx_PxMat44_Pod const* self__pod, physx_PxVec4_Pod const* other_pod) {
        physx::PxMat44 const* self_ = reinterpret_cast<physx::PxMat44 const*>(self__pod);
        physx::PxVec4 const& other = reinterpret_cast<physx::PxVec4 const&>(*other_pod);
        physx::PxVec4 return_val = self_->rotate(other);
        physx_PxVec4_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxMat44_rotate_1(physx_PxMat44_Pod const* self__pod, physx_PxVec3_Pod const* other_pod) {
        physx::PxMat44 const* self_ = reinterpret_cast<physx::PxMat44 const*>(self__pod);
        physx::PxVec3 const& other = reinterpret_cast<physx::PxVec3 const&>(*other_pod);
        physx::PxVec3 return_val = self_->rotate(other);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxMat44_getBasis(physx_PxMat44_Pod const* self__pod, uint32_t num) {
        physx::PxMat44 const* self_ = reinterpret_cast<physx::PxMat44 const*>(self__pod);
        physx::PxVec3 return_val = self_->getBasis(num);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxMat44_getPosition(physx_PxMat44_Pod const* self__pod) {
        physx::PxMat44 const* self_ = reinterpret_cast<physx::PxMat44 const*>(self__pod);
        physx::PxVec3 return_val = self_->getPosition();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxMat44_setPosition_mut(physx_PxMat44_Pod* self__pod, physx_PxVec3_Pod const* position_pod) {
        physx::PxMat44* self_ = reinterpret_cast<physx::PxMat44*>(self__pod);
        physx::PxVec3 const& position = reinterpret_cast<physx::PxVec3 const&>(*position_pod);
        self_->setPosition(position);
    }

    float const* PxMat44_front(physx_PxMat44_Pod const* self__pod) {
        physx::PxMat44 const* self_ = reinterpret_cast<physx::PxMat44 const*>(self__pod);
        float const* return_val = self_->front();
        return return_val;
    }

    void PxMat44_scale_mut(physx_PxMat44_Pod* self__pod, physx_PxVec4_Pod const* p_pod) {
        physx::PxMat44* self_ = reinterpret_cast<physx::PxMat44*>(self__pod);
        physx::PxVec4 const& p = reinterpret_cast<physx::PxVec4 const&>(*p_pod);
        self_->scale(p);
    }

    physx_PxMat44_Pod PxMat44_inverseRT(physx_PxMat44_Pod const* self__pod) {
        physx::PxMat44 const* self_ = reinterpret_cast<physx::PxMat44 const*>(self__pod);
        physx::PxMat44 return_val = self_->inverseRT();
        physx_PxMat44_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxMat44_isFinite(physx_PxMat44_Pod const* self__pod) {
        physx::PxMat44 const* self_ = reinterpret_cast<physx::PxMat44 const*>(self__pod);
        bool return_val = self_->isFinite();
        return return_val;
    }

    physx_PxPlane_Pod PxPlane_new() {
        PxPlane return_val;
        physx_PxPlane_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxPlane_Pod PxPlane_new_1(float nx, float ny, float nz, float distance) {
        PxPlane return_val(nx, ny, nz, distance);
        physx_PxPlane_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxPlane_Pod PxPlane_new_2(physx_PxVec3_Pod const* normal_pod, float distance) {
        physx::PxVec3 const& normal = reinterpret_cast<physx::PxVec3 const&>(*normal_pod);
        PxPlane return_val(normal, distance);
        physx_PxPlane_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxPlane_Pod PxPlane_new_3(physx_PxVec3_Pod const* point_pod, physx_PxVec3_Pod const* normal_pod) {
        physx::PxVec3 const& point = reinterpret_cast<physx::PxVec3 const&>(*point_pod);
        physx::PxVec3 const& normal = reinterpret_cast<physx::PxVec3 const&>(*normal_pod);
        PxPlane return_val(point, normal);
        physx_PxPlane_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxPlane_Pod PxPlane_new_4(physx_PxVec3_Pod const* p0_pod, physx_PxVec3_Pod const* p1_pod, physx_PxVec3_Pod const* p2_pod) {
        physx::PxVec3 const& p0 = reinterpret_cast<physx::PxVec3 const&>(*p0_pod);
        physx::PxVec3 const& p1 = reinterpret_cast<physx::PxVec3 const&>(*p1_pod);
        physx::PxVec3 const& p2 = reinterpret_cast<physx::PxVec3 const&>(*p2_pod);
        PxPlane return_val(p0, p1, p2);
        physx_PxPlane_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    float PxPlane_distance(physx_PxPlane_Pod const* self__pod, physx_PxVec3_Pod const* p_pod) {
        physx::PxPlane const* self_ = reinterpret_cast<physx::PxPlane const*>(self__pod);
        physx::PxVec3 const& p = reinterpret_cast<physx::PxVec3 const&>(*p_pod);
        float return_val = self_->distance(p);
        return return_val;
    }

    bool PxPlane_contains(physx_PxPlane_Pod const* self__pod, physx_PxVec3_Pod const* p_pod) {
        physx::PxPlane const* self_ = reinterpret_cast<physx::PxPlane const*>(self__pod);
        physx::PxVec3 const& p = reinterpret_cast<physx::PxVec3 const&>(*p_pod);
        bool return_val = self_->contains(p);
        return return_val;
    }

    physx_PxVec3_Pod PxPlane_project(physx_PxPlane_Pod const* self__pod, physx_PxVec3_Pod const* p_pod) {
        physx::PxPlane const* self_ = reinterpret_cast<physx::PxPlane const*>(self__pod);
        physx::PxVec3 const& p = reinterpret_cast<physx::PxVec3 const&>(*p_pod);
        physx::PxVec3 return_val = self_->project(p);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxPlane_pointInPlane(physx_PxPlane_Pod const* self__pod) {
        physx::PxPlane const* self_ = reinterpret_cast<physx::PxPlane const*>(self__pod);
        physx::PxVec3 return_val = self_->pointInPlane();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxPlane_normalize_mut(physx_PxPlane_Pod* self__pod) {
        physx::PxPlane* self_ = reinterpret_cast<physx::PxPlane*>(self__pod);
        self_->normalize();
    }

    physx_PxPlane_Pod PxPlane_transform(physx_PxPlane_Pod const* self__pod, physx_PxTransform_Pod const* pose_pod) {
        physx::PxPlane const* self_ = reinterpret_cast<physx::PxPlane const*>(self__pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        physx::PxPlane return_val = self_->transform(pose);
        physx_PxPlane_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxPlane_Pod PxPlane_inverseTransform(physx_PxPlane_Pod const* self__pod, physx_PxTransform_Pod const* pose_pod) {
        physx::PxPlane const* self_ = reinterpret_cast<physx::PxPlane const*>(self__pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        physx::PxPlane return_val = self_->inverseTransform(pose);
        physx_PxPlane_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxQuat_Pod phys_PxShortestRotation(physx_PxVec3_Pod const* from_pod, physx_PxVec3_Pod const* target_pod) {
        physx::PxVec3 const& from = reinterpret_cast<physx::PxVec3 const&>(*from_pod);
        physx::PxVec3 const& target = reinterpret_cast<physx::PxVec3 const&>(*target_pod);
        physx::PxQuat return_val = PxShortestRotation(from, target);
        physx_PxQuat_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod phys_PxDiagonalize(physx_PxMat33_Pod const* m_pod, physx_PxQuat_Pod* axes_pod) {
        physx::PxMat33 const& m = reinterpret_cast<physx::PxMat33 const&>(*m_pod);
        physx::PxQuat& axes = reinterpret_cast<physx::PxQuat&>(*axes_pod);
        physx::PxVec3 return_val = PxDiagonalize(m, axes);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxTransform_Pod phys_PxTransformFromSegment(physx_PxVec3_Pod const* p0_pod, physx_PxVec3_Pod const* p1_pod, float* halfHeight) {
        physx::PxVec3 const& p0 = reinterpret_cast<physx::PxVec3 const&>(*p0_pod);
        physx::PxVec3 const& p1 = reinterpret_cast<physx::PxVec3 const&>(*p1_pod);
        physx::PxTransform return_val = PxTransformFromSegment(p0, p1, halfHeight);
        physx_PxTransform_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxTransform_Pod phys_PxTransformFromPlaneEquation(physx_PxPlane_Pod const* plane_pod) {
        physx::PxPlane const& plane = reinterpret_cast<physx::PxPlane const&>(*plane_pod);
        physx::PxTransform return_val = PxTransformFromPlaneEquation(plane);
        physx_PxTransform_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxPlane_Pod phys_PxPlaneEquationFromTransform(physx_PxTransform_Pod const* pose_pod) {
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        physx::PxPlane return_val = PxPlaneEquationFromTransform(pose);
        physx_PxPlane_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxQuat_Pod phys_PxSlerp(float t, physx_PxQuat_Pod const* left_pod, physx_PxQuat_Pod const* right_pod) {
        physx::PxQuat const& left = reinterpret_cast<physx::PxQuat const&>(*left_pod);
        physx::PxQuat const& right = reinterpret_cast<physx::PxQuat const&>(*right_pod);
        physx::PxQuat return_val = PxSlerp(t, left, right);
        physx_PxQuat_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void phys_PxIntegrateTransform(physx_PxTransform_Pod const* curTrans_pod, physx_PxVec3_Pod const* linvel_pod, physx_PxVec3_Pod const* angvel_pod, float timeStep, physx_PxTransform_Pod* result_pod) {
        physx::PxTransform const& curTrans = reinterpret_cast<physx::PxTransform const&>(*curTrans_pod);
        physx::PxVec3 const& linvel = reinterpret_cast<physx::PxVec3 const&>(*linvel_pod);
        physx::PxVec3 const& angvel = reinterpret_cast<physx::PxVec3 const&>(*angvel_pod);
        physx::PxTransform& result = reinterpret_cast<physx::PxTransform&>(*result_pod);
        PxIntegrateTransform(curTrans, linvel, angvel, timeStep, result);
    }

    physx_PxQuat_Pod phys_PxExp(physx_PxVec3_Pod const* v_pod) {
        physx::PxVec3 const& v = reinterpret_cast<physx::PxVec3 const&>(*v_pod);
        physx::PxQuat return_val = PxExp(v);
        physx_PxQuat_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod phys_PxOptimizeBoundingBox(physx_PxMat33_Pod* basis_pod) {
        physx::PxMat33& basis = reinterpret_cast<physx::PxMat33&>(*basis_pod);
        physx::PxVec3 return_val = PxOptimizeBoundingBox(basis);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod phys_PxLog(physx_PxQuat_Pod const* q_pod) {
        physx::PxQuat const& q = reinterpret_cast<physx::PxQuat const&>(*q_pod);
        physx::PxVec3 return_val = PxLog(q);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    uint32_t phys_PxLargestAxis(physx_PxVec3_Pod const* v_pod) {
        physx::PxVec3 const& v = reinterpret_cast<physx::PxVec3 const&>(*v_pod);
        uint32_t return_val = PxLargestAxis(v);
        return return_val;
    }

    float phys_PxTanHalf(float sin, float cos) {
        float return_val = PxTanHalf(sin, cos);
        return return_val;
    }

    physx_PxVec3_Pod phys_PxEllipseClamp(physx_PxVec3_Pod const* point_pod, physx_PxVec3_Pod const* radii_pod) {
        physx::PxVec3 const& point = reinterpret_cast<physx::PxVec3 const&>(*point_pod);
        physx::PxVec3 const& radii = reinterpret_cast<physx::PxVec3 const&>(*radii_pod);
        physx::PxVec3 return_val = PxEllipseClamp(point, radii);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void phys_PxSeparateSwingTwist(physx_PxQuat_Pod const* q_pod, physx_PxQuat_Pod* swing_pod, physx_PxQuat_Pod* twist_pod) {
        physx::PxQuat const& q = reinterpret_cast<physx::PxQuat const&>(*q_pod);
        physx::PxQuat& swing = reinterpret_cast<physx::PxQuat&>(*swing_pod);
        physx::PxQuat& twist = reinterpret_cast<physx::PxQuat&>(*twist_pod);
        PxSeparateSwingTwist(q, swing, twist);
    }

    float phys_PxComputeAngle(physx_PxVec3_Pod const* v0_pod, physx_PxVec3_Pod const* v1_pod) {
        physx::PxVec3 const& v0 = reinterpret_cast<physx::PxVec3 const&>(*v0_pod);
        physx::PxVec3 const& v1 = reinterpret_cast<physx::PxVec3 const&>(*v1_pod);
        float return_val = PxComputeAngle(v0, v1);
        return return_val;
    }

    void phys_PxComputeBasisVectors(physx_PxVec3_Pod const* dir_pod, physx_PxVec3_Pod* right_pod, physx_PxVec3_Pod* up_pod) {
        physx::PxVec3 const& dir = reinterpret_cast<physx::PxVec3 const&>(*dir_pod);
        physx::PxVec3& right = reinterpret_cast<physx::PxVec3&>(*right_pod);
        physx::PxVec3& up = reinterpret_cast<physx::PxVec3&>(*up_pod);
        PxComputeBasisVectors(dir, right, up);
    }

    void phys_PxComputeBasisVectors_1(physx_PxVec3_Pod const* p0_pod, physx_PxVec3_Pod const* p1_pod, physx_PxVec3_Pod* dir_pod, physx_PxVec3_Pod* right_pod, physx_PxVec3_Pod* up_pod) {
        physx::PxVec3 const& p0 = reinterpret_cast<physx::PxVec3 const&>(*p0_pod);
        physx::PxVec3 const& p1 = reinterpret_cast<physx::PxVec3 const&>(*p1_pod);
        physx::PxVec3& dir = reinterpret_cast<physx::PxVec3&>(*dir_pod);
        physx::PxVec3& right = reinterpret_cast<physx::PxVec3&>(*right_pod);
        physx::PxVec3& up = reinterpret_cast<physx::PxVec3&>(*up_pod);
        PxComputeBasisVectors(p0, p1, dir, right, up);
    }

    uint32_t phys_PxGetNextIndex3(uint32_t i) {
        uint32_t return_val = PxGetNextIndex3(i);
        return return_val;
    }

    void phys_computeBarycentric(physx_PxVec3_Pod const* a_pod, physx_PxVec3_Pod const* b_pod, physx_PxVec3_Pod const* c_pod, physx_PxVec3_Pod const* d_pod, physx_PxVec3_Pod const* p_pod, physx_PxVec4_Pod* bary_pod) {
        physx::PxVec3 const& a = reinterpret_cast<physx::PxVec3 const&>(*a_pod);
        physx::PxVec3 const& b = reinterpret_cast<physx::PxVec3 const&>(*b_pod);
        physx::PxVec3 const& c = reinterpret_cast<physx::PxVec3 const&>(*c_pod);
        physx::PxVec3 const& d = reinterpret_cast<physx::PxVec3 const&>(*d_pod);
        physx::PxVec3 const& p = reinterpret_cast<physx::PxVec3 const&>(*p_pod);
        physx::PxVec4& bary = reinterpret_cast<physx::PxVec4&>(*bary_pod);
        computeBarycentric(a, b, c, d, p, bary);
    }

    void phys_computeBarycentric_1(physx_PxVec3_Pod const* a_pod, physx_PxVec3_Pod const* b_pod, physx_PxVec3_Pod const* c_pod, physx_PxVec3_Pod const* p_pod, physx_PxVec4_Pod* bary_pod) {
        physx::PxVec3 const& a = reinterpret_cast<physx::PxVec3 const&>(*a_pod);
        physx::PxVec3 const& b = reinterpret_cast<physx::PxVec3 const&>(*b_pod);
        physx::PxVec3 const& c = reinterpret_cast<physx::PxVec3 const&>(*c_pod);
        physx::PxVec3 const& p = reinterpret_cast<physx::PxVec3 const&>(*p_pod);
        physx::PxVec4& bary = reinterpret_cast<physx::PxVec4&>(*bary_pod);
        computeBarycentric(a, b, c, p, bary);
    }

    float Interpolation_PxLerp(float a, float b, float t) {
        float return_val = Interpolation::PxLerp(a, b, t);
        return return_val;
    }

    float Interpolation_PxBiLerp(float f00, float f10, float f01, float f11, float tx, float ty) {
        float return_val = Interpolation::PxBiLerp(f00, f10, f01, f11, tx, ty);
        return return_val;
    }

    float Interpolation_PxTriLerp(float f000, float f100, float f010, float f110, float f001, float f101, float f011, float f111, float tx, float ty, float tz) {
        float return_val = Interpolation::PxTriLerp(f000, f100, f010, f110, f001, f101, f011, f111, tx, ty, tz);
        return return_val;
    }

    uint32_t Interpolation_PxSDFIdx(uint32_t i, uint32_t j, uint32_t k, uint32_t nbX, uint32_t nbY) {
        uint32_t return_val = Interpolation::PxSDFIdx(i, j, k, nbX, nbY);
        return return_val;
    }

    float Interpolation_PxSDFSampleImpl(float const* sdf, physx_PxVec3_Pod const* localPos_pod, physx_PxVec3_Pod const* sdfBoxLower_pod, physx_PxVec3_Pod const* sdfBoxHigher_pod, float sdfDx, float invSdfDx, uint32_t dimX, uint32_t dimY, uint32_t dimZ, float tolerance) {
        physx::PxVec3 const& localPos = reinterpret_cast<physx::PxVec3 const&>(*localPos_pod);
        physx::PxVec3 const& sdfBoxLower = reinterpret_cast<physx::PxVec3 const&>(*sdfBoxLower_pod);
        physx::PxVec3 const& sdfBoxHigher = reinterpret_cast<physx::PxVec3 const&>(*sdfBoxHigher_pod);
        float return_val = Interpolation::PxSDFSampleImpl(sdf, localPos, sdfBoxLower, sdfBoxHigher, sdfDx, invSdfDx, dimX, dimY, dimZ, tolerance);
        return return_val;
    }

    float phys_PxSdfSample(float const* sdf, physx_PxVec3_Pod const* localPos_pod, physx_PxVec3_Pod const* sdfBoxLower_pod, physx_PxVec3_Pod const* sdfBoxHigher_pod, float sdfDx, float invSdfDx, uint32_t dimX, uint32_t dimY, uint32_t dimZ, physx_PxVec3_Pod* gradient_pod, float tolerance) {
        physx::PxVec3 const& localPos = reinterpret_cast<physx::PxVec3 const&>(*localPos_pod);
        physx::PxVec3 const& sdfBoxLower = reinterpret_cast<physx::PxVec3 const&>(*sdfBoxLower_pod);
        physx::PxVec3 const& sdfBoxHigher = reinterpret_cast<physx::PxVec3 const&>(*sdfBoxHigher_pod);
        physx::PxVec3& gradient = reinterpret_cast<physx::PxVec3&>(*gradient_pod);
        float return_val = PxSdfSample(sdf, localPos, sdfBoxLower, sdfBoxHigher, sdfDx, invSdfDx, dimX, dimY, dimZ, gradient, tolerance);
        return return_val;
    }

    physx_PxMutexImpl_Pod* PxMutexImpl_new_alloc() {
        auto return_val = new physx::PxMutexImpl();
        auto return_val_pod = reinterpret_cast<physx_PxMutexImpl_Pod*>(return_val);
        return return_val_pod;
    }

    void PxMutexImpl_delete(physx_PxMutexImpl_Pod* self__pod) {
        physx::PxMutexImpl* self_ = reinterpret_cast<physx::PxMutexImpl*>(self__pod);
        delete self_;
    }

    void PxMutexImpl_lock_mut(physx_PxMutexImpl_Pod* self__pod) {
        physx::PxMutexImpl* self_ = reinterpret_cast<physx::PxMutexImpl*>(self__pod);
        self_->lock();
    }

    bool PxMutexImpl_trylock_mut(physx_PxMutexImpl_Pod* self__pod) {
        physx::PxMutexImpl* self_ = reinterpret_cast<physx::PxMutexImpl*>(self__pod);
        bool return_val = self_->trylock();
        return return_val;
    }

    void PxMutexImpl_unlock_mut(physx_PxMutexImpl_Pod* self__pod) {
        physx::PxMutexImpl* self_ = reinterpret_cast<physx::PxMutexImpl*>(self__pod);
        self_->unlock();
    }

    uint32_t PxMutexImpl_getSize() {
        uint32_t return_val = PxMutexImpl::getSize();
        return return_val;
    }

    physx_PxReadWriteLock_Pod* PxReadWriteLock_new_alloc() {
        auto return_val = new physx::PxReadWriteLock();
        auto return_val_pod = reinterpret_cast<physx_PxReadWriteLock_Pod*>(return_val);
        return return_val_pod;
    }

    void PxReadWriteLock_delete(physx_PxReadWriteLock_Pod* self__pod) {
        physx::PxReadWriteLock* self_ = reinterpret_cast<physx::PxReadWriteLock*>(self__pod);
        delete self_;
    }

    void PxReadWriteLock_lockReader_mut(physx_PxReadWriteLock_Pod* self__pod, bool takeLock) {
        physx::PxReadWriteLock* self_ = reinterpret_cast<physx::PxReadWriteLock*>(self__pod);
        self_->lockReader(takeLock);
    }

    void PxReadWriteLock_lockWriter_mut(physx_PxReadWriteLock_Pod* self__pod) {
        physx::PxReadWriteLock* self_ = reinterpret_cast<physx::PxReadWriteLock*>(self__pod);
        self_->lockWriter();
    }

    void PxReadWriteLock_unlockReader_mut(physx_PxReadWriteLock_Pod* self__pod) {
        physx::PxReadWriteLock* self_ = reinterpret_cast<physx::PxReadWriteLock*>(self__pod);
        self_->unlockReader();
    }

    void PxReadWriteLock_unlockWriter_mut(physx_PxReadWriteLock_Pod* self__pod) {
        physx::PxReadWriteLock* self_ = reinterpret_cast<physx::PxReadWriteLock*>(self__pod);
        self_->unlockWriter();
    }

    void* PxProfilerCallback_zoneStart_mut(physx_PxProfilerCallback_Pod* self__pod, char const* eventName, bool detached, uint64_t contextId) {
        physx::PxProfilerCallback* self_ = reinterpret_cast<physx::PxProfilerCallback*>(self__pod);
        void* return_val = self_->zoneStart(eventName, detached, contextId);
        return return_val;
    }

    void PxProfilerCallback_zoneEnd_mut(physx_PxProfilerCallback_Pod* self__pod, void* profilerData, char const* eventName, bool detached, uint64_t contextId) {
        physx::PxProfilerCallback* self_ = reinterpret_cast<physx::PxProfilerCallback*>(self__pod);
        self_->zoneEnd(profilerData, eventName, detached, contextId);
    }

    physx_PxProfileScoped_Pod* PxProfileScoped_new_alloc(physx_PxProfilerCallback_Pod* callback_pod, char const* eventName, bool detached, uint64_t contextId) {
        physx::PxProfilerCallback* callback = reinterpret_cast<physx::PxProfilerCallback*>(callback_pod);
        auto return_val = new physx::PxProfileScoped(callback, eventName, detached, contextId);
        auto return_val_pod = reinterpret_cast<physx_PxProfileScoped_Pod*>(return_val);
        return return_val_pod;
    }

    void PxProfileScoped_delete(physx_PxProfileScoped_Pod* self__pod) {
        physx::PxProfileScoped* self_ = reinterpret_cast<physx::PxProfileScoped*>(self__pod);
        delete self_;
    }

    physx_PxSListEntry_Pod PxSListEntry_new() {
        PxSListEntry return_val;
        physx_PxSListEntry_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxSListEntry_Pod* PxSListEntry_next_mut(physx_PxSListEntry_Pod* self__pod) {
        physx::PxSListEntry* self_ = reinterpret_cast<physx::PxSListEntry*>(self__pod);
        physx::PxSListEntry* return_val = self_->next();
        auto return_val_pod = reinterpret_cast<physx_PxSListEntry_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxSListImpl_Pod* PxSListImpl_new_alloc() {
        auto return_val = new physx::PxSListImpl();
        auto return_val_pod = reinterpret_cast<physx_PxSListImpl_Pod*>(return_val);
        return return_val_pod;
    }

    void PxSListImpl_delete(physx_PxSListImpl_Pod* self__pod) {
        physx::PxSListImpl* self_ = reinterpret_cast<physx::PxSListImpl*>(self__pod);
        delete self_;
    }

    void PxSListImpl_push_mut(physx_PxSListImpl_Pod* self__pod, physx_PxSListEntry_Pod* entry_pod) {
        physx::PxSListImpl* self_ = reinterpret_cast<physx::PxSListImpl*>(self__pod);
        physx::PxSListEntry* entry = reinterpret_cast<physx::PxSListEntry*>(entry_pod);
        self_->push(entry);
    }

    physx_PxSListEntry_Pod* PxSListImpl_pop_mut(physx_PxSListImpl_Pod* self__pod) {
        physx::PxSListImpl* self_ = reinterpret_cast<physx::PxSListImpl*>(self__pod);
        physx::PxSListEntry* return_val = self_->pop();
        auto return_val_pod = reinterpret_cast<physx_PxSListEntry_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxSListEntry_Pod* PxSListImpl_flush_mut(physx_PxSListImpl_Pod* self__pod) {
        physx::PxSListImpl* self_ = reinterpret_cast<physx::PxSListImpl*>(self__pod);
        physx::PxSListEntry* return_val = self_->flush();
        auto return_val_pod = reinterpret_cast<physx_PxSListEntry_Pod*>(return_val);
        return return_val_pod;
    }

    uint32_t PxSListImpl_getSize() {
        uint32_t return_val = PxSListImpl::getSize();
        return return_val;
    }

    physx_PxSyncImpl_Pod* PxSyncImpl_new_alloc() {
        auto return_val = new physx::PxSyncImpl();
        auto return_val_pod = reinterpret_cast<physx_PxSyncImpl_Pod*>(return_val);
        return return_val_pod;
    }

    void PxSyncImpl_delete(physx_PxSyncImpl_Pod* self__pod) {
        physx::PxSyncImpl* self_ = reinterpret_cast<physx::PxSyncImpl*>(self__pod);
        delete self_;
    }

    bool PxSyncImpl_wait_mut(physx_PxSyncImpl_Pod* self__pod, uint32_t milliseconds) {
        physx::PxSyncImpl* self_ = reinterpret_cast<physx::PxSyncImpl*>(self__pod);
        bool return_val = self_->wait(milliseconds);
        return return_val;
    }

    void PxSyncImpl_set_mut(physx_PxSyncImpl_Pod* self__pod) {
        physx::PxSyncImpl* self_ = reinterpret_cast<physx::PxSyncImpl*>(self__pod);
        self_->set();
    }

    void PxSyncImpl_reset_mut(physx_PxSyncImpl_Pod* self__pod) {
        physx::PxSyncImpl* self_ = reinterpret_cast<physx::PxSyncImpl*>(self__pod);
        self_->reset();
    }

    uint32_t PxSyncImpl_getSize() {
        uint32_t return_val = PxSyncImpl::getSize();
        return return_val;
    }

    physx_PxRunnable_Pod* PxRunnable_new_alloc() {
        auto return_val = new physx::PxRunnable();
        auto return_val_pod = reinterpret_cast<physx_PxRunnable_Pod*>(return_val);
        return return_val_pod;
    }

    void PxRunnable_delete(physx_PxRunnable_Pod* self__pod) {
        physx::PxRunnable* self_ = reinterpret_cast<physx::PxRunnable*>(self__pod);
        delete self_;
    }

    void PxRunnable_execute_mut(physx_PxRunnable_Pod* self__pod) {
        physx::PxRunnable* self_ = reinterpret_cast<physx::PxRunnable*>(self__pod);
        self_->execute();
    }

    uint32_t phys_PxTlsAlloc() {
        uint32_t return_val = PxTlsAlloc();
        return return_val;
    }

    void phys_PxTlsFree(uint32_t index) {
        PxTlsFree(index);
    }

    void* phys_PxTlsGet(uint32_t index) {
        void* return_val = PxTlsGet(index);
        return return_val;
    }

    size_t phys_PxTlsGetValue(uint32_t index) {
        size_t return_val = PxTlsGetValue(index);
        size_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    uint32_t phys_PxTlsSet(uint32_t index, void* value) {
        uint32_t return_val = PxTlsSet(index, value);
        return return_val;
    }

    uint32_t phys_PxTlsSetValue(uint32_t index, size_t value_pod) {
        size_t value;
        memcpy(&value, &value_pod, sizeof(value));
        uint32_t return_val = PxTlsSetValue(index, value);
        return return_val;
    }

    physx_PxCounterFrequencyToTensOfNanos_Pod PxCounterFrequencyToTensOfNanos_new(uint64_t inNum, uint64_t inDenom) {
        PxCounterFrequencyToTensOfNanos return_val(inNum, inDenom);
        physx_PxCounterFrequencyToTensOfNanos_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    uint64_t PxCounterFrequencyToTensOfNanos_toTensOfNanos(physx_PxCounterFrequencyToTensOfNanos_Pod const* self__pod, uint64_t inCounter) {
        physx::PxCounterFrequencyToTensOfNanos const* self_ = reinterpret_cast<physx::PxCounterFrequencyToTensOfNanos const*>(self__pod);
        uint64_t return_val = self_->toTensOfNanos(inCounter);
        return return_val;
    }

    physx_PxCounterFrequencyToTensOfNanos_Pod const* PxTime_getBootCounterFrequency() {
        physx::PxCounterFrequencyToTensOfNanos const& return_val = PxTime::getBootCounterFrequency();
        auto return_val_pod = reinterpret_cast<physx_PxCounterFrequencyToTensOfNanos_Pod const*>(&return_val);
        return return_val_pod;
    }

    physx_PxCounterFrequencyToTensOfNanos_Pod PxTime_getCounterFrequency() {
        physx::PxCounterFrequencyToTensOfNanos return_val = PxTime::getCounterFrequency();
        physx_PxCounterFrequencyToTensOfNanos_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    uint64_t PxTime_getCurrentCounterValue() {
        uint64_t return_val = PxTime::getCurrentCounterValue();
        return return_val;
    }

    uint64_t PxTime_getCurrentTimeInTensOfNanoSeconds() {
        uint64_t return_val = PxTime::getCurrentTimeInTensOfNanoSeconds();
        return return_val;
    }

    physx_PxTime_Pod PxTime_new() {
        PxTime return_val;
        physx_PxTime_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    double PxTime_getElapsedSeconds_mut(physx_PxTime_Pod* self__pod) {
        physx::PxTime* self_ = reinterpret_cast<physx::PxTime*>(self__pod);
        double return_val = self_->getElapsedSeconds();
        return return_val;
    }

    double PxTime_peekElapsedSeconds_mut(physx_PxTime_Pod* self__pod) {
        physx::PxTime* self_ = reinterpret_cast<physx::PxTime*>(self__pod);
        double return_val = self_->peekElapsedSeconds();
        return return_val;
    }

    double PxTime_getLastTime(physx_PxTime_Pod const* self__pod) {
        physx::PxTime const* self_ = reinterpret_cast<physx::PxTime const*>(self__pod);
        double return_val = self_->getLastTime();
        return return_val;
    }

    physx_PxVec2_Pod PxVec2_new() {
        PxVec2 return_val;
        physx_PxVec2_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec2_Pod PxVec2_new_1(int32_t anon_param0_pod) {
        auto anon_param0 = static_cast<physx::PxZERO>(anon_param0_pod);
        PxVec2 return_val(anon_param0);
        physx_PxVec2_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec2_Pod PxVec2_new_2(float a) {
        PxVec2 return_val(a);
        physx_PxVec2_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec2_Pod PxVec2_new_3(float nx, float ny) {
        PxVec2 return_val(nx, ny);
        physx_PxVec2_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxVec2_isZero(physx_PxVec2_Pod const* self__pod) {
        physx::PxVec2 const* self_ = reinterpret_cast<physx::PxVec2 const*>(self__pod);
        bool return_val = self_->isZero();
        return return_val;
    }

    bool PxVec2_isFinite(physx_PxVec2_Pod const* self__pod) {
        physx::PxVec2 const* self_ = reinterpret_cast<physx::PxVec2 const*>(self__pod);
        bool return_val = self_->isFinite();
        return return_val;
    }

    bool PxVec2_isNormalized(physx_PxVec2_Pod const* self__pod) {
        physx::PxVec2 const* self_ = reinterpret_cast<physx::PxVec2 const*>(self__pod);
        bool return_val = self_->isNormalized();
        return return_val;
    }

    float PxVec2_magnitudeSquared(physx_PxVec2_Pod const* self__pod) {
        physx::PxVec2 const* self_ = reinterpret_cast<physx::PxVec2 const*>(self__pod);
        float return_val = self_->magnitudeSquared();
        return return_val;
    }

    float PxVec2_magnitude(physx_PxVec2_Pod const* self__pod) {
        physx::PxVec2 const* self_ = reinterpret_cast<physx::PxVec2 const*>(self__pod);
        float return_val = self_->magnitude();
        return return_val;
    }

    float PxVec2_dot(physx_PxVec2_Pod const* self__pod, physx_PxVec2_Pod const* v_pod) {
        physx::PxVec2 const* self_ = reinterpret_cast<physx::PxVec2 const*>(self__pod);
        physx::PxVec2 const& v = reinterpret_cast<physx::PxVec2 const&>(*v_pod);
        float return_val = self_->dot(v);
        return return_val;
    }

    physx_PxVec2_Pod PxVec2_getNormalized(physx_PxVec2_Pod const* self__pod) {
        physx::PxVec2 const* self_ = reinterpret_cast<physx::PxVec2 const*>(self__pod);
        physx::PxVec2 return_val = self_->getNormalized();
        physx_PxVec2_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    float PxVec2_normalize_mut(physx_PxVec2_Pod* self__pod) {
        physx::PxVec2* self_ = reinterpret_cast<physx::PxVec2*>(self__pod);
        float return_val = self_->normalize();
        return return_val;
    }

    physx_PxVec2_Pod PxVec2_multiply(physx_PxVec2_Pod const* self__pod, physx_PxVec2_Pod const* a_pod) {
        physx::PxVec2 const* self_ = reinterpret_cast<physx::PxVec2 const*>(self__pod);
        physx::PxVec2 const& a = reinterpret_cast<physx::PxVec2 const&>(*a_pod);
        physx::PxVec2 return_val = self_->multiply(a);
        physx_PxVec2_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec2_Pod PxVec2_minimum(physx_PxVec2_Pod const* self__pod, physx_PxVec2_Pod const* v_pod) {
        physx::PxVec2 const* self_ = reinterpret_cast<physx::PxVec2 const*>(self__pod);
        physx::PxVec2 const& v = reinterpret_cast<physx::PxVec2 const&>(*v_pod);
        physx::PxVec2 return_val = self_->minimum(v);
        physx_PxVec2_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    float PxVec2_minElement(physx_PxVec2_Pod const* self__pod) {
        physx::PxVec2 const* self_ = reinterpret_cast<physx::PxVec2 const*>(self__pod);
        float return_val = self_->minElement();
        return return_val;
    }

    physx_PxVec2_Pod PxVec2_maximum(physx_PxVec2_Pod const* self__pod, physx_PxVec2_Pod const* v_pod) {
        physx::PxVec2 const* self_ = reinterpret_cast<physx::PxVec2 const*>(self__pod);
        physx::PxVec2 const& v = reinterpret_cast<physx::PxVec2 const&>(*v_pod);
        physx::PxVec2 return_val = self_->maximum(v);
        physx_PxVec2_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    float PxVec2_maxElement(physx_PxVec2_Pod const* self__pod) {
        physx::PxVec2 const* self_ = reinterpret_cast<physx::PxVec2 const*>(self__pod);
        float return_val = self_->maxElement();
        return return_val;
    }

    physx_PxStridedData_Pod PxStridedData_new() {
        PxStridedData return_val;
        physx_PxStridedData_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxBoundedData_Pod PxBoundedData_new() {
        PxBoundedData return_val;
        physx_PxBoundedData_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxDebugPoint_Pod PxDebugPoint_new(physx_PxVec3_Pod const* p_pod, uint32_t const* c_pod) {
        physx::PxVec3 const& p = reinterpret_cast<physx::PxVec3 const&>(*p_pod);
        uint32_t const& c = *c_pod;
        PxDebugPoint return_val(p, c);
        physx_PxDebugPoint_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxDebugLine_Pod PxDebugLine_new(physx_PxVec3_Pod const* p0_pod, physx_PxVec3_Pod const* p1_pod, uint32_t const* c_pod) {
        physx::PxVec3 const& p0 = reinterpret_cast<physx::PxVec3 const&>(*p0_pod);
        physx::PxVec3 const& p1 = reinterpret_cast<physx::PxVec3 const&>(*p1_pod);
        uint32_t const& c = *c_pod;
        PxDebugLine return_val(p0, p1, c);
        physx_PxDebugLine_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxDebugTriangle_Pod PxDebugTriangle_new(physx_PxVec3_Pod const* p0_pod, physx_PxVec3_Pod const* p1_pod, physx_PxVec3_Pod const* p2_pod, uint32_t const* c_pod) {
        physx::PxVec3 const& p0 = reinterpret_cast<physx::PxVec3 const&>(*p0_pod);
        physx::PxVec3 const& p1 = reinterpret_cast<physx::PxVec3 const&>(*p1_pod);
        physx::PxVec3 const& p2 = reinterpret_cast<physx::PxVec3 const&>(*p2_pod);
        uint32_t const& c = *c_pod;
        PxDebugTriangle return_val(p0, p1, p2, c);
        physx_PxDebugTriangle_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxDebugText_Pod PxDebugText_new() {
        PxDebugText return_val;
        physx_PxDebugText_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxDebugText_Pod PxDebugText_new_1(physx_PxVec3_Pod const* pos_pod, float const* sz_pod, uint32_t const* clr_pod, char const* str) {
        physx::PxVec3 const& pos = reinterpret_cast<physx::PxVec3 const&>(*pos_pod);
        float const& sz = *sz_pod;
        uint32_t const& clr = *clr_pod;
        PxDebugText return_val(pos, sz, clr, str);
        physx_PxDebugText_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxRenderBuffer_delete(physx_PxRenderBuffer_Pod* self__pod) {
        physx::PxRenderBuffer* self_ = reinterpret_cast<physx::PxRenderBuffer*>(self__pod);
        delete self_;
    }

    uint32_t PxRenderBuffer_getNbPoints(physx_PxRenderBuffer_Pod const* self__pod) {
        physx::PxRenderBuffer const* self_ = reinterpret_cast<physx::PxRenderBuffer const*>(self__pod);
        uint32_t return_val = self_->getNbPoints();
        return return_val;
    }

    physx_PxDebugPoint_Pod const* PxRenderBuffer_getPoints(physx_PxRenderBuffer_Pod const* self__pod) {
        physx::PxRenderBuffer const* self_ = reinterpret_cast<physx::PxRenderBuffer const*>(self__pod);
        physx::PxDebugPoint const* return_val = self_->getPoints();
        auto return_val_pod = reinterpret_cast<physx_PxDebugPoint_Pod const*>(return_val);
        return return_val_pod;
    }

    void PxRenderBuffer_addPoint_mut(physx_PxRenderBuffer_Pod* self__pod, physx_PxDebugPoint_Pod const* point_pod) {
        physx::PxRenderBuffer* self_ = reinterpret_cast<physx::PxRenderBuffer*>(self__pod);
        physx::PxDebugPoint const& point = reinterpret_cast<physx::PxDebugPoint const&>(*point_pod);
        self_->addPoint(point);
    }

    uint32_t PxRenderBuffer_getNbLines(physx_PxRenderBuffer_Pod const* self__pod) {
        physx::PxRenderBuffer const* self_ = reinterpret_cast<physx::PxRenderBuffer const*>(self__pod);
        uint32_t return_val = self_->getNbLines();
        return return_val;
    }

    physx_PxDebugLine_Pod const* PxRenderBuffer_getLines(physx_PxRenderBuffer_Pod const* self__pod) {
        physx::PxRenderBuffer const* self_ = reinterpret_cast<physx::PxRenderBuffer const*>(self__pod);
        physx::PxDebugLine const* return_val = self_->getLines();
        auto return_val_pod = reinterpret_cast<physx_PxDebugLine_Pod const*>(return_val);
        return return_val_pod;
    }

    void PxRenderBuffer_addLine_mut(physx_PxRenderBuffer_Pod* self__pod, physx_PxDebugLine_Pod const* line_pod) {
        physx::PxRenderBuffer* self_ = reinterpret_cast<physx::PxRenderBuffer*>(self__pod);
        physx::PxDebugLine const& line = reinterpret_cast<physx::PxDebugLine const&>(*line_pod);
        self_->addLine(line);
    }

    physx_PxDebugLine_Pod* PxRenderBuffer_reserveLines_mut(physx_PxRenderBuffer_Pod* self__pod, uint32_t nbLines) {
        physx::PxRenderBuffer* self_ = reinterpret_cast<physx::PxRenderBuffer*>(self__pod);
        physx::PxDebugLine* return_val = self_->reserveLines(nbLines);
        auto return_val_pod = reinterpret_cast<physx_PxDebugLine_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxDebugPoint_Pod* PxRenderBuffer_reservePoints_mut(physx_PxRenderBuffer_Pod* self__pod, uint32_t nbLines) {
        physx::PxRenderBuffer* self_ = reinterpret_cast<physx::PxRenderBuffer*>(self__pod);
        physx::PxDebugPoint* return_val = self_->reservePoints(nbLines);
        auto return_val_pod = reinterpret_cast<physx_PxDebugPoint_Pod*>(return_val);
        return return_val_pod;
    }

    uint32_t PxRenderBuffer_getNbTriangles(physx_PxRenderBuffer_Pod const* self__pod) {
        physx::PxRenderBuffer const* self_ = reinterpret_cast<physx::PxRenderBuffer const*>(self__pod);
        uint32_t return_val = self_->getNbTriangles();
        return return_val;
    }

    physx_PxDebugTriangle_Pod const* PxRenderBuffer_getTriangles(physx_PxRenderBuffer_Pod const* self__pod) {
        physx::PxRenderBuffer const* self_ = reinterpret_cast<physx::PxRenderBuffer const*>(self__pod);
        physx::PxDebugTriangle const* return_val = self_->getTriangles();
        auto return_val_pod = reinterpret_cast<physx_PxDebugTriangle_Pod const*>(return_val);
        return return_val_pod;
    }

    void PxRenderBuffer_addTriangle_mut(physx_PxRenderBuffer_Pod* self__pod, physx_PxDebugTriangle_Pod const* triangle_pod) {
        physx::PxRenderBuffer* self_ = reinterpret_cast<physx::PxRenderBuffer*>(self__pod);
        physx::PxDebugTriangle const& triangle = reinterpret_cast<physx::PxDebugTriangle const&>(*triangle_pod);
        self_->addTriangle(triangle);
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

    void PxRenderBuffer_shift_mut(physx_PxRenderBuffer_Pod* self__pod, physx_PxVec3_Pod const* delta_pod) {
        physx::PxRenderBuffer* self_ = reinterpret_cast<physx::PxRenderBuffer*>(self__pod);
        physx::PxVec3 const& delta = reinterpret_cast<physx::PxVec3 const&>(*delta_pod);
        self_->shift(delta);
    }

    bool PxRenderBuffer_empty(physx_PxRenderBuffer_Pod const* self__pod) {
        physx::PxRenderBuffer const* self_ = reinterpret_cast<physx::PxRenderBuffer const*>(self__pod);
        bool return_val = self_->empty();
        return return_val;
    }

    void PxProcessPxBaseCallback_delete(physx_PxProcessPxBaseCallback_Pod* self__pod) {
        physx::PxProcessPxBaseCallback* self_ = reinterpret_cast<physx::PxProcessPxBaseCallback*>(self__pod);
        delete self_;
    }

    void PxProcessPxBaseCallback_process_mut(physx_PxProcessPxBaseCallback_Pod* self__pod, physx_PxBase_Pod* anon_param0_pod) {
        physx::PxProcessPxBaseCallback* self_ = reinterpret_cast<physx::PxProcessPxBaseCallback*>(self__pod);
        physx::PxBase& anon_param0 = reinterpret_cast<physx::PxBase&>(*anon_param0_pod);
        self_->process(anon_param0);
    }

    void PxSerializationContext_registerReference_mut(physx_PxSerializationContext_Pod* self__pod, physx_PxBase_Pod* base_pod, uint32_t kind, size_t reference_pod) {
        physx::PxSerializationContext* self_ = reinterpret_cast<physx::PxSerializationContext*>(self__pod);
        physx::PxBase& base = reinterpret_cast<physx::PxBase&>(*base_pod);
        size_t reference;
        memcpy(&reference, &reference_pod, sizeof(reference));
        self_->registerReference(base, kind, reference);
    }

    physx_PxCollection_Pod const* PxSerializationContext_getCollection(physx_PxSerializationContext_Pod const* self__pod) {
        physx::PxSerializationContext const* self_ = reinterpret_cast<physx::PxSerializationContext const*>(self__pod);
        physx::PxCollection const& return_val = self_->getCollection();
        auto return_val_pod = reinterpret_cast<physx_PxCollection_Pod const*>(&return_val);
        return return_val_pod;
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

    physx_PxBase_Pod* PxDeserializationContext_resolveReference(physx_PxDeserializationContext_Pod const* self__pod, uint32_t kind, size_t reference_pod) {
        physx::PxDeserializationContext const* self_ = reinterpret_cast<physx::PxDeserializationContext const*>(self__pod);
        size_t reference;
        memcpy(&reference, &reference_pod, sizeof(reference));
        physx::PxBase* return_val = self_->resolveReference(kind, reference);
        auto return_val_pod = reinterpret_cast<physx_PxBase_Pod*>(return_val);
        return return_val_pod;
    }

    void PxDeserializationContext_readName_mut(physx_PxDeserializationContext_Pod* self__pod, char const** name_pod) {
        physx::PxDeserializationContext* self_ = reinterpret_cast<physx::PxDeserializationContext*>(self__pod);
        char const*& name = reinterpret_cast<char const*&>(*name_pod);
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
        physx::PxSerializer* return_val = self_->unregisterSerializer(type);
        auto return_val_pod = reinterpret_cast<physx_PxSerializer_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxSerializer_Pod const* PxSerializationRegistry_getSerializer(physx_PxSerializationRegistry_Pod const* self__pod, uint16_t type) {
        physx::PxSerializationRegistry const* self_ = reinterpret_cast<physx::PxSerializationRegistry const*>(self__pod);
        physx::PxSerializer const* return_val = self_->getSerializer(type);
        auto return_val_pod = reinterpret_cast<physx_PxSerializer_Pod const*>(return_val);
        return return_val_pod;
    }

    void PxSerializationRegistry_registerRepXSerializer_mut(physx_PxSerializationRegistry_Pod* self__pod, uint16_t type, physx_PxRepXSerializer_Pod* serializer_pod) {
        physx::PxSerializationRegistry* self_ = reinterpret_cast<physx::PxSerializationRegistry*>(self__pod);
        physx::PxRepXSerializer& serializer = reinterpret_cast<physx::PxRepXSerializer&>(*serializer_pod);
        self_->registerRepXSerializer(type, serializer);
    }

    physx_PxRepXSerializer_Pod* PxSerializationRegistry_unregisterRepXSerializer_mut(physx_PxSerializationRegistry_Pod* self__pod, uint16_t type) {
        physx::PxSerializationRegistry* self_ = reinterpret_cast<physx::PxSerializationRegistry*>(self__pod);
        physx::PxRepXSerializer* return_val = self_->unregisterRepXSerializer(type);
        auto return_val_pod = reinterpret_cast<physx_PxRepXSerializer_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxRepXSerializer_Pod* PxSerializationRegistry_getRepXSerializer(physx_PxSerializationRegistry_Pod const* self__pod, char const* typeName) {
        physx::PxSerializationRegistry const* self_ = reinterpret_cast<physx::PxSerializationRegistry const*>(self__pod);
        physx::PxRepXSerializer* return_val = self_->getRepXSerializer(typeName);
        auto return_val_pod = reinterpret_cast<physx_PxRepXSerializer_Pod*>(return_val);
        return return_val_pod;
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
        bool return_val = self_->contains(object);
        return return_val;
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
        uint32_t return_val = self_->getNbObjects();
        return return_val;
    }

    physx_PxBase_Pod* PxCollection_getObject(physx_PxCollection_Pod const* self__pod, uint32_t index) {
        physx::PxCollection const* self_ = reinterpret_cast<physx::PxCollection const*>(self__pod);
        physx::PxBase& return_val = self_->getObject(index);
        auto return_val_pod = reinterpret_cast<physx_PxBase_Pod*>(&return_val);
        return return_val_pod;
    }

    uint32_t PxCollection_getObjects(physx_PxCollection_Pod const* self__pod, physx_PxBase_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxCollection const* self_ = reinterpret_cast<physx::PxCollection const*>(self__pod);
        physx::PxBase** userBuffer = reinterpret_cast<physx::PxBase**>(userBuffer_pod);
        uint32_t return_val = self_->getObjects(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    physx_PxBase_Pod* PxCollection_find(physx_PxCollection_Pod const* self__pod, uint64_t id) {
        physx::PxCollection const* self_ = reinterpret_cast<physx::PxCollection const*>(self__pod);
        physx::PxBase* return_val = self_->find(id);
        auto return_val_pod = reinterpret_cast<physx_PxBase_Pod*>(return_val);
        return return_val_pod;
    }

    uint32_t PxCollection_getNbIds(physx_PxCollection_Pod const* self__pod) {
        physx::PxCollection const* self_ = reinterpret_cast<physx::PxCollection const*>(self__pod);
        uint32_t return_val = self_->getNbIds();
        return return_val;
    }

    uint32_t PxCollection_getIds(physx_PxCollection_Pod const* self__pod, uint64_t* userBuffer, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxCollection const* self_ = reinterpret_cast<physx::PxCollection const*>(self__pod);
        uint32_t return_val = self_->getIds(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    uint64_t PxCollection_getId(physx_PxCollection_Pod const* self__pod, physx_PxBase_Pod const* object_pod) {
        physx::PxCollection const* self_ = reinterpret_cast<physx::PxCollection const*>(self__pod);
        physx::PxBase const& object = reinterpret_cast<physx::PxBase const&>(*object_pod);
        uint64_t return_val = self_->getId(object);
        return return_val;
    }

    void PxCollection_release_mut(physx_PxCollection_Pod* self__pod) {
        physx::PxCollection* self_ = reinterpret_cast<physx::PxCollection*>(self__pod);
        self_->release();
    }

    physx_PxCollection_Pod* phys_PxCreateCollection() {
        physx::PxCollection* return_val = PxCreateCollection();
        auto return_val_pod = reinterpret_cast<physx_PxCollection_Pod*>(return_val);
        return return_val_pod;
    }

    void PxBase_release_mut(physx_PxBase_Pod* self__pod) {
        physx::PxBase* self_ = reinterpret_cast<physx::PxBase*>(self__pod);
        self_->release();
    }

    char const* PxBase_getConcreteTypeName(physx_PxBase_Pod const* self__pod) {
        physx::PxBase const* self_ = reinterpret_cast<physx::PxBase const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    uint16_t PxBase_getConcreteType(physx_PxBase_Pod const* self__pod) {
        physx::PxBase const* self_ = reinterpret_cast<physx::PxBase const*>(self__pod);
        uint16_t return_val = self_->getConcreteType();
        return return_val;
    }

    void PxBase_setBaseFlag_mut(physx_PxBase_Pod* self__pod, int32_t flag_pod, bool value) {
        physx::PxBase* self_ = reinterpret_cast<physx::PxBase*>(self__pod);
        auto flag = static_cast<physx::PxBaseFlag::Enum>(flag_pod);
        self_->setBaseFlag(flag, value);
    }

    void PxBase_setBaseFlags_mut(physx_PxBase_Pod* self__pod, uint16_t inFlags_pod) {
        physx::PxBase* self_ = reinterpret_cast<physx::PxBase*>(self__pod);
        auto inFlags = physx::PxBaseFlags(inFlags_pod);
        self_->setBaseFlags(inFlags);
    }

    uint16_t PxBase_getBaseFlags(physx_PxBase_Pod const* self__pod) {
        physx::PxBase const* self_ = reinterpret_cast<physx::PxBase const*>(self__pod);
        physx::PxBaseFlags return_val = self_->getBaseFlags();
        uint16_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxBase_isReleasable(physx_PxBase_Pod const* self__pod) {
        physx::PxBase const* self_ = reinterpret_cast<physx::PxBase const*>(self__pod);
        bool return_val = self_->isReleasable();
        return return_val;
    }

    void PxRefCounted_release_mut(physx_PxRefCounted_Pod* self__pod) {
        physx::PxRefCounted* self_ = reinterpret_cast<physx::PxRefCounted*>(self__pod);
        self_->release();
    }

    uint32_t PxRefCounted_getReferenceCount(physx_PxRefCounted_Pod const* self__pod) {
        physx::PxRefCounted const* self_ = reinterpret_cast<physx::PxRefCounted const*>(self__pod);
        uint32_t return_val = self_->getReferenceCount();
        return return_val;
    }

    void PxRefCounted_acquireReference_mut(physx_PxRefCounted_Pod* self__pod) {
        physx::PxRefCounted* self_ = reinterpret_cast<physx::PxRefCounted*>(self__pod);
        self_->acquireReference();
    }

    physx_PxTolerancesScale_Pod PxTolerancesScale_new(float defaultLength, float defaultSpeed) {
        PxTolerancesScale return_val(defaultLength, defaultSpeed);
        physx_PxTolerancesScale_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxTolerancesScale_isValid(physx_PxTolerancesScale_Pod const* self__pod) {
        physx::PxTolerancesScale const* self_ = reinterpret_cast<physx::PxTolerancesScale const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    char const* PxStringTable_allocateStr_mut(physx_PxStringTable_Pod* self__pod, char const* inSrc) {
        physx::PxStringTable* self_ = reinterpret_cast<physx::PxStringTable*>(self__pod);
        char const* return_val = self_->allocateStr(inSrc);
        return return_val;
    }

    void PxStringTable_release_mut(physx_PxStringTable_Pod* self__pod) {
        physx::PxStringTable* self_ = reinterpret_cast<physx::PxStringTable*>(self__pod);
        self_->release();
    }

    char const* PxSerializer_getConcreteTypeName(physx_PxSerializer_Pod const* self__pod) {
        physx::PxSerializer const* self_ = reinterpret_cast<physx::PxSerializer const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    void PxSerializer_requiresObjects(physx_PxSerializer_Pod const* self__pod, physx_PxBase_Pod* anon_param0_pod, physx_PxProcessPxBaseCallback_Pod* anon_param1_pod) {
        physx::PxSerializer const* self_ = reinterpret_cast<physx::PxSerializer const*>(self__pod);
        physx::PxBase& anon_param0 = reinterpret_cast<physx::PxBase&>(*anon_param0_pod);
        physx::PxProcessPxBaseCallback& anon_param1 = reinterpret_cast<physx::PxProcessPxBaseCallback&>(*anon_param1_pod);
        self_->requiresObjects(anon_param0, anon_param1);
    }

    bool PxSerializer_isSubordinate(physx_PxSerializer_Pod const* self__pod) {
        physx::PxSerializer const* self_ = reinterpret_cast<physx::PxSerializer const*>(self__pod);
        bool return_val = self_->isSubordinate();
        return return_val;
    }

    void PxSerializer_exportExtraData(physx_PxSerializer_Pod const* self__pod, physx_PxBase_Pod* anon_param0_pod, physx_PxSerializationContext_Pod* anon_param1_pod) {
        physx::PxSerializer const* self_ = reinterpret_cast<physx::PxSerializer const*>(self__pod);
        physx::PxBase& anon_param0 = reinterpret_cast<physx::PxBase&>(*anon_param0_pod);
        physx::PxSerializationContext& anon_param1 = reinterpret_cast<physx::PxSerializationContext&>(*anon_param1_pod);
        self_->exportExtraData(anon_param0, anon_param1);
    }

    void PxSerializer_exportData(physx_PxSerializer_Pod const* self__pod, physx_PxBase_Pod* anon_param0_pod, physx_PxSerializationContext_Pod* anon_param1_pod) {
        physx::PxSerializer const* self_ = reinterpret_cast<physx::PxSerializer const*>(self__pod);
        physx::PxBase& anon_param0 = reinterpret_cast<physx::PxBase&>(*anon_param0_pod);
        physx::PxSerializationContext& anon_param1 = reinterpret_cast<physx::PxSerializationContext&>(*anon_param1_pod);
        self_->exportData(anon_param0, anon_param1);
    }

    void PxSerializer_registerReferences(physx_PxSerializer_Pod const* self__pod, physx_PxBase_Pod* obj_pod, physx_PxSerializationContext_Pod* s_pod) {
        physx::PxSerializer const* self_ = reinterpret_cast<physx::PxSerializer const*>(self__pod);
        physx::PxBase& obj = reinterpret_cast<physx::PxBase&>(*obj_pod);
        physx::PxSerializationContext& s = reinterpret_cast<physx::PxSerializationContext&>(*s_pod);
        self_->registerReferences(obj, s);
    }

    size_t PxSerializer_getClassSize(physx_PxSerializer_Pod const* self__pod) {
        physx::PxSerializer const* self_ = reinterpret_cast<physx::PxSerializer const*>(self__pod);
        size_t return_val = self_->getClassSize();
        size_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxBase_Pod* PxSerializer_createObject(physx_PxSerializer_Pod const* self__pod, uint8_t** address_pod, physx_PxDeserializationContext_Pod* context_pod) {
        physx::PxSerializer const* self_ = reinterpret_cast<physx::PxSerializer const*>(self__pod);
        uint8_t*& address = reinterpret_cast<uint8_t*&>(*address_pod);
        physx::PxDeserializationContext& context = reinterpret_cast<physx::PxDeserializationContext&>(*context_pod);
        physx::PxBase* return_val = self_->createObject(address, context);
        auto return_val_pod = reinterpret_cast<physx_PxBase_Pod*>(return_val);
        return return_val_pod;
    }

    void PxSerializer_delete(physx_PxSerializer_Pod* self__pod) {
        physx::PxSerializer* self_ = reinterpret_cast<physx::PxSerializer*>(self__pod);
        delete self_;
    }

    physx_PxBase_Pod* PxInsertionCallback_buildObjectFromData_mut(physx_PxInsertionCallback_Pod* self__pod, int32_t type_pod, void* data) {
        physx::PxInsertionCallback* self_ = reinterpret_cast<physx::PxInsertionCallback*>(self__pod);
        auto type = static_cast<physx::PxConcreteType::Enum>(type_pod);
        physx::PxBase* return_val = self_->buildObjectFromData(type, data);
        auto return_val_pod = reinterpret_cast<physx_PxBase_Pod*>(return_val);
        return return_val_pod;
    }

    void PxTaskManager_setCpuDispatcher_mut(physx_PxTaskManager_Pod* self__pod, physx_PxCpuDispatcher_Pod* ref_pod) {
        physx::PxTaskManager* self_ = reinterpret_cast<physx::PxTaskManager*>(self__pod);
        physx::PxCpuDispatcher& ref = reinterpret_cast<physx::PxCpuDispatcher&>(*ref_pod);
        self_->setCpuDispatcher(ref);
    }

    physx_PxCpuDispatcher_Pod* PxTaskManager_getCpuDispatcher(physx_PxTaskManager_Pod const* self__pod) {
        physx::PxTaskManager const* self_ = reinterpret_cast<physx::PxTaskManager const*>(self__pod);
        physx::PxCpuDispatcher* return_val = self_->getCpuDispatcher();
        auto return_val_pod = reinterpret_cast<physx_PxCpuDispatcher_Pod*>(return_val);
        return return_val_pod;
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
        uint32_t return_val = self_->getNamedTask(name);
        return return_val;
    }

    uint32_t PxTaskManager_submitNamedTask_mut(physx_PxTaskManager_Pod* self__pod, physx_PxTask_Pod* task_pod, char const* name, int32_t type_pod) {
        physx::PxTaskManager* self_ = reinterpret_cast<physx::PxTaskManager*>(self__pod);
        physx::PxTask* task = reinterpret_cast<physx::PxTask*>(task_pod);
        auto type = static_cast<physx::PxTaskType::Enum>(type_pod);
        uint32_t return_val = self_->submitNamedTask(task, name, type);
        return return_val;
    }

    uint32_t PxTaskManager_submitUnnamedTask_mut(physx_PxTaskManager_Pod* self__pod, physx_PxTask_Pod* task_pod, int32_t type_pod) {
        physx::PxTaskManager* self_ = reinterpret_cast<physx::PxTaskManager*>(self__pod);
        physx::PxTask& task = reinterpret_cast<physx::PxTask&>(*task_pod);
        auto type = static_cast<physx::PxTaskType::Enum>(type_pod);
        uint32_t return_val = self_->submitUnnamedTask(task, type);
        return return_val;
    }

    physx_PxTask_Pod* PxTaskManager_getTaskFromID_mut(physx_PxTaskManager_Pod* self__pod, uint32_t id) {
        physx::PxTaskManager* self_ = reinterpret_cast<physx::PxTaskManager*>(self__pod);
        physx::PxTask* return_val = self_->getTaskFromID(id);
        auto return_val_pod = reinterpret_cast<physx_PxTask_Pod*>(return_val);
        return return_val_pod;
    }

    void PxTaskManager_release_mut(physx_PxTaskManager_Pod* self__pod) {
        physx::PxTaskManager* self_ = reinterpret_cast<physx::PxTaskManager*>(self__pod);
        self_->release();
    }

    physx_PxTaskManager_Pod* PxTaskManager_createTaskManager(physx_PxErrorCallback_Pod* errorCallback_pod, physx_PxCpuDispatcher_Pod* anon_param1_pod) {
        physx::PxErrorCallback& errorCallback = reinterpret_cast<physx::PxErrorCallback&>(*errorCallback_pod);
        physx::PxCpuDispatcher* anon_param1 = reinterpret_cast<physx::PxCpuDispatcher*>(anon_param1_pod);
        physx::PxTaskManager* return_val = PxTaskManager::createTaskManager(errorCallback, anon_param1);
        auto return_val_pod = reinterpret_cast<physx_PxTaskManager_Pod*>(return_val);
        return return_val_pod;
    }

    void PxCpuDispatcher_submitTask_mut(physx_PxCpuDispatcher_Pod* self__pod, physx_PxBaseTask_Pod* task_pod) {
        physx::PxCpuDispatcher* self_ = reinterpret_cast<physx::PxCpuDispatcher*>(self__pod);
        physx::PxBaseTask& task = reinterpret_cast<physx::PxBaseTask&>(*task_pod);
        self_->submitTask(task);
    }

    uint32_t PxCpuDispatcher_getWorkerCount(physx_PxCpuDispatcher_Pod const* self__pod) {
        physx::PxCpuDispatcher const* self_ = reinterpret_cast<physx::PxCpuDispatcher const*>(self__pod);
        uint32_t return_val = self_->getWorkerCount();
        return return_val;
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
        char const* return_val = self_->getName();
        return return_val;
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
        int32_t return_val = self_->getReference();
        return return_val;
    }

    void PxBaseTask_release_mut(physx_PxBaseTask_Pod* self__pod) {
        physx::PxBaseTask* self_ = reinterpret_cast<physx::PxBaseTask*>(self__pod);
        self_->release();
    }

    physx_PxTaskManager_Pod* PxBaseTask_getTaskManager(physx_PxBaseTask_Pod const* self__pod) {
        physx::PxBaseTask const* self_ = reinterpret_cast<physx::PxBaseTask const*>(self__pod);
        physx::PxTaskManager* return_val = self_->getTaskManager();
        auto return_val_pod = reinterpret_cast<physx_PxTaskManager_Pod*>(return_val);
        return return_val_pod;
    }

    void PxBaseTask_setContextId_mut(physx_PxBaseTask_Pod* self__pod, uint64_t id) {
        physx::PxBaseTask* self_ = reinterpret_cast<physx::PxBaseTask*>(self__pod);
        self_->setContextId(id);
    }

    uint64_t PxBaseTask_getContextId(physx_PxBaseTask_Pod const* self__pod) {
        physx::PxBaseTask const* self_ = reinterpret_cast<physx::PxBaseTask const*>(self__pod);
        uint64_t return_val = self_->getContextId();
        return return_val;
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
        int32_t return_val = self_->getReference();
        return return_val;
    }

    uint32_t PxTask_getTaskID(physx_PxTask_Pod const* self__pod) {
        physx::PxTask const* self_ = reinterpret_cast<physx::PxTask const*>(self__pod);
        uint32_t return_val = self_->getTaskID();
        return return_val;
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
        physx::PxBaseTask* return_val = self_->getContinuation();
        auto return_val_pod = reinterpret_cast<physx_PxBaseTask_Pod*>(return_val);
        return return_val_pod;
    }

    void PxLightCpuTask_removeReference_mut(physx_PxLightCpuTask_Pod* self__pod) {
        physx::PxLightCpuTask* self_ = reinterpret_cast<physx::PxLightCpuTask*>(self__pod);
        self_->removeReference();
    }

    int32_t PxLightCpuTask_getReference(physx_PxLightCpuTask_Pod const* self__pod) {
        physx::PxLightCpuTask const* self_ = reinterpret_cast<physx::PxLightCpuTask const*>(self__pod);
        int32_t return_val = self_->getReference();
        return return_val;
    }

    void PxLightCpuTask_addReference_mut(physx_PxLightCpuTask_Pod* self__pod) {
        physx::PxLightCpuTask* self_ = reinterpret_cast<physx::PxLightCpuTask*>(self__pod);
        self_->addReference();
    }

    void PxLightCpuTask_release_mut(physx_PxLightCpuTask_Pod* self__pod) {
        physx::PxLightCpuTask* self_ = reinterpret_cast<physx::PxLightCpuTask*>(self__pod);
        self_->release();
    }

    int32_t PxGeometry_getType(physx_PxGeometry_Pod const* self__pod) {
        physx::PxGeometry const* self_ = reinterpret_cast<physx::PxGeometry const*>(self__pod);
        physx::PxGeometryType::Enum return_val = self_->getType();
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxBoxGeometry_Pod PxBoxGeometry_new(float hx, float hy, float hz) {
        PxBoxGeometry return_val(hx, hy, hz);
        physx_PxBoxGeometry_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxBoxGeometry_Pod PxBoxGeometry_new_1(physx_PxVec3_Pod halfExtents__pod) {
        physx::PxVec3 halfExtents_;
        memcpy(&halfExtents_, &halfExtents__pod, sizeof(halfExtents_));
        PxBoxGeometry return_val(halfExtents_);
        physx_PxBoxGeometry_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxBoxGeometry_isValid(physx_PxBoxGeometry_Pod const* self__pod) {
        physx::PxBoxGeometry const* self_ = reinterpret_cast<physx::PxBoxGeometry const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    void PxBVHRaycastCallback_delete(physx_PxBVHRaycastCallback_Pod* self__pod) {
        physx::PxBVHRaycastCallback* self_ = reinterpret_cast<physx::PxBVHRaycastCallback*>(self__pod);
        delete self_;
    }

    bool PxBVHRaycastCallback_reportHit_mut(physx_PxBVHRaycastCallback_Pod* self__pod, uint32_t boundsIndex, float* distance_pod) {
        physx::PxBVHRaycastCallback* self_ = reinterpret_cast<physx::PxBVHRaycastCallback*>(self__pod);
        float& distance = *distance_pod;
        bool return_val = self_->reportHit(boundsIndex, distance);
        return return_val;
    }

    void PxBVHOverlapCallback_delete(physx_PxBVHOverlapCallback_Pod* self__pod) {
        physx::PxBVHOverlapCallback* self_ = reinterpret_cast<physx::PxBVHOverlapCallback*>(self__pod);
        delete self_;
    }

    bool PxBVHOverlapCallback_reportHit_mut(physx_PxBVHOverlapCallback_Pod* self__pod, uint32_t boundsIndex) {
        physx::PxBVHOverlapCallback* self_ = reinterpret_cast<physx::PxBVHOverlapCallback*>(self__pod);
        bool return_val = self_->reportHit(boundsIndex);
        return return_val;
    }

    void PxBVHTraversalCallback_delete(physx_PxBVHTraversalCallback_Pod* self__pod) {
        physx::PxBVHTraversalCallback* self_ = reinterpret_cast<physx::PxBVHTraversalCallback*>(self__pod);
        delete self_;
    }

    bool PxBVHTraversalCallback_visitNode_mut(physx_PxBVHTraversalCallback_Pod* self__pod, physx_PxBounds3_Pod const* bounds_pod) {
        physx::PxBVHTraversalCallback* self_ = reinterpret_cast<physx::PxBVHTraversalCallback*>(self__pod);
        physx::PxBounds3 const& bounds = reinterpret_cast<physx::PxBounds3 const&>(*bounds_pod);
        bool return_val = self_->visitNode(bounds);
        return return_val;
    }

    bool PxBVHTraversalCallback_reportLeaf_mut(physx_PxBVHTraversalCallback_Pod* self__pod, uint32_t nbPrims, uint32_t const* prims) {
        physx::PxBVHTraversalCallback* self_ = reinterpret_cast<physx::PxBVHTraversalCallback*>(self__pod);
        bool return_val = self_->reportLeaf(nbPrims, prims);
        return return_val;
    }

    bool PxBVH_raycast(physx_PxBVH_Pod const* self__pod, physx_PxVec3_Pod const* origin_pod, physx_PxVec3_Pod const* unitDir_pod, float maxDist, physx_PxBVHRaycastCallback_Pod* cb_pod, uint32_t queryFlags_pod) {
        physx::PxBVH const* self_ = reinterpret_cast<physx::PxBVH const*>(self__pod);
        physx::PxVec3 const& origin = reinterpret_cast<physx::PxVec3 const&>(*origin_pod);
        physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
        physx::PxBVHRaycastCallback& cb = reinterpret_cast<physx::PxBVHRaycastCallback&>(*cb_pod);
        auto queryFlags = physx::PxGeometryQueryFlags(queryFlags_pod);
        bool return_val = self_->raycast(origin, unitDir, maxDist, cb, queryFlags);
        return return_val;
    }

    bool PxBVH_sweep(physx_PxBVH_Pod const* self__pod, physx_PxGeometry_Pod const* geom_pod, physx_PxTransform_Pod const* pose_pod, physx_PxVec3_Pod const* unitDir_pod, float maxDist, physx_PxBVHRaycastCallback_Pod* cb_pod, uint32_t queryFlags_pod) {
        physx::PxBVH const* self_ = reinterpret_cast<physx::PxBVH const*>(self__pod);
        physx::PxGeometry const& geom = reinterpret_cast<physx::PxGeometry const&>(*geom_pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
        physx::PxBVHRaycastCallback& cb = reinterpret_cast<physx::PxBVHRaycastCallback&>(*cb_pod);
        auto queryFlags = physx::PxGeometryQueryFlags(queryFlags_pod);
        bool return_val = self_->sweep(geom, pose, unitDir, maxDist, cb, queryFlags);
        return return_val;
    }

    bool PxBVH_overlap(physx_PxBVH_Pod const* self__pod, physx_PxGeometry_Pod const* geom_pod, physx_PxTransform_Pod const* pose_pod, physx_PxBVHOverlapCallback_Pod* cb_pod, uint32_t queryFlags_pod) {
        physx::PxBVH const* self_ = reinterpret_cast<physx::PxBVH const*>(self__pod);
        physx::PxGeometry const& geom = reinterpret_cast<physx::PxGeometry const&>(*geom_pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        physx::PxBVHOverlapCallback& cb = reinterpret_cast<physx::PxBVHOverlapCallback&>(*cb_pod);
        auto queryFlags = physx::PxGeometryQueryFlags(queryFlags_pod);
        bool return_val = self_->overlap(geom, pose, cb, queryFlags);
        return return_val;
    }

    bool PxBVH_cull(physx_PxBVH_Pod const* self__pod, uint32_t nbPlanes, physx_PxPlane_Pod const* planes_pod, physx_PxBVHOverlapCallback_Pod* cb_pod, uint32_t queryFlags_pod) {
        physx::PxBVH const* self_ = reinterpret_cast<physx::PxBVH const*>(self__pod);
        physx::PxPlane const* planes = reinterpret_cast<physx::PxPlane const*>(planes_pod);
        physx::PxBVHOverlapCallback& cb = reinterpret_cast<physx::PxBVHOverlapCallback&>(*cb_pod);
        auto queryFlags = physx::PxGeometryQueryFlags(queryFlags_pod);
        bool return_val = self_->cull(nbPlanes, planes, cb, queryFlags);
        return return_val;
    }

    uint32_t PxBVH_getNbBounds(physx_PxBVH_Pod const* self__pod) {
        physx::PxBVH const* self_ = reinterpret_cast<physx::PxBVH const*>(self__pod);
        uint32_t return_val = self_->getNbBounds();
        return return_val;
    }

    physx_PxBounds3_Pod const* PxBVH_getBounds(physx_PxBVH_Pod const* self__pod) {
        physx::PxBVH const* self_ = reinterpret_cast<physx::PxBVH const*>(self__pod);
        physx::PxBounds3 const* return_val = self_->getBounds();
        auto return_val_pod = reinterpret_cast<physx_PxBounds3_Pod const*>(return_val);
        return return_val_pod;
    }

    physx_PxBounds3_Pod* PxBVH_getBoundsForModification_mut(physx_PxBVH_Pod* self__pod) {
        physx::PxBVH* self_ = reinterpret_cast<physx::PxBVH*>(self__pod);
        physx::PxBounds3* return_val = self_->getBoundsForModification();
        auto return_val_pod = reinterpret_cast<physx_PxBounds3_Pod*>(return_val);
        return return_val_pod;
    }

    void PxBVH_refit_mut(physx_PxBVH_Pod* self__pod) {
        physx::PxBVH* self_ = reinterpret_cast<physx::PxBVH*>(self__pod);
        self_->refit();
    }

    bool PxBVH_updateBounds_mut(physx_PxBVH_Pod* self__pod, uint32_t boundsIndex, physx_PxBounds3_Pod const* newBounds_pod) {
        physx::PxBVH* self_ = reinterpret_cast<physx::PxBVH*>(self__pod);
        physx::PxBounds3 const& newBounds = reinterpret_cast<physx::PxBounds3 const&>(*newBounds_pod);
        bool return_val = self_->updateBounds(boundsIndex, newBounds);
        return return_val;
    }

    void PxBVH_partialRefit_mut(physx_PxBVH_Pod* self__pod) {
        physx::PxBVH* self_ = reinterpret_cast<physx::PxBVH*>(self__pod);
        self_->partialRefit();
    }

    bool PxBVH_traverse(physx_PxBVH_Pod const* self__pod, physx_PxBVHTraversalCallback_Pod* cb_pod) {
        physx::PxBVH const* self_ = reinterpret_cast<physx::PxBVH const*>(self__pod);
        physx::PxBVHTraversalCallback& cb = reinterpret_cast<physx::PxBVHTraversalCallback&>(*cb_pod);
        bool return_val = self_->traverse(cb);
        return return_val;
    }

    char const* PxBVH_getConcreteTypeName(physx_PxBVH_Pod const* self__pod) {
        physx::PxBVH const* self_ = reinterpret_cast<physx::PxBVH const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    physx_PxCapsuleGeometry_Pod PxCapsuleGeometry_new(float radius_, float halfHeight_) {
        PxCapsuleGeometry return_val(radius_, halfHeight_);
        physx_PxCapsuleGeometry_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxCapsuleGeometry_isValid(physx_PxCapsuleGeometry_Pod const* self__pod) {
        physx::PxCapsuleGeometry const* self_ = reinterpret_cast<physx::PxCapsuleGeometry const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    uint32_t PxConvexMesh_getNbVertices(physx_PxConvexMesh_Pod const* self__pod) {
        physx::PxConvexMesh const* self_ = reinterpret_cast<physx::PxConvexMesh const*>(self__pod);
        uint32_t return_val = self_->getNbVertices();
        return return_val;
    }

    physx_PxVec3_Pod const* PxConvexMesh_getVertices(physx_PxConvexMesh_Pod const* self__pod) {
        physx::PxConvexMesh const* self_ = reinterpret_cast<physx::PxConvexMesh const*>(self__pod);
        physx::PxVec3 const* return_val = self_->getVertices();
        auto return_val_pod = reinterpret_cast<physx_PxVec3_Pod const*>(return_val);
        return return_val_pod;
    }

    uint8_t const* PxConvexMesh_getIndexBuffer(physx_PxConvexMesh_Pod const* self__pod) {
        physx::PxConvexMesh const* self_ = reinterpret_cast<physx::PxConvexMesh const*>(self__pod);
        uint8_t const* return_val = self_->getIndexBuffer();
        return return_val;
    }

    uint32_t PxConvexMesh_getNbPolygons(physx_PxConvexMesh_Pod const* self__pod) {
        physx::PxConvexMesh const* self_ = reinterpret_cast<physx::PxConvexMesh const*>(self__pod);
        uint32_t return_val = self_->getNbPolygons();
        return return_val;
    }

    bool PxConvexMesh_getPolygonData(physx_PxConvexMesh_Pod const* self__pod, uint32_t index, physx_PxHullPolygon_Pod* data_pod) {
        physx::PxConvexMesh const* self_ = reinterpret_cast<physx::PxConvexMesh const*>(self__pod);
        physx::PxHullPolygon& data = reinterpret_cast<physx::PxHullPolygon&>(*data_pod);
        bool return_val = self_->getPolygonData(index, data);
        return return_val;
    }

    void PxConvexMesh_release_mut(physx_PxConvexMesh_Pod* self__pod) {
        physx::PxConvexMesh* self_ = reinterpret_cast<physx::PxConvexMesh*>(self__pod);
        self_->release();
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
        physx::PxBounds3 return_val = self_->getLocalBounds();
        physx_PxBounds3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    float const* PxConvexMesh_getSDF(physx_PxConvexMesh_Pod const* self__pod) {
        physx::PxConvexMesh const* self_ = reinterpret_cast<physx::PxConvexMesh const*>(self__pod);
        float const* return_val = self_->getSDF();
        return return_val;
    }

    char const* PxConvexMesh_getConcreteTypeName(physx_PxConvexMesh_Pod const* self__pod) {
        physx::PxConvexMesh const* self_ = reinterpret_cast<physx::PxConvexMesh const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    bool PxConvexMesh_isGpuCompatible(physx_PxConvexMesh_Pod const* self__pod) {
        physx::PxConvexMesh const* self_ = reinterpret_cast<physx::PxConvexMesh const*>(self__pod);
        bool return_val = self_->isGpuCompatible();
        return return_val;
    }

    physx_PxMeshScale_Pod PxMeshScale_new() {
        PxMeshScale return_val;
        physx_PxMeshScale_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMeshScale_Pod PxMeshScale_new_1(float r) {
        PxMeshScale return_val(r);
        physx_PxMeshScale_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMeshScale_Pod PxMeshScale_new_2(physx_PxVec3_Pod const* s_pod) {
        physx::PxVec3 const& s = reinterpret_cast<physx::PxVec3 const&>(*s_pod);
        PxMeshScale return_val(s);
        physx_PxMeshScale_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMeshScale_Pod PxMeshScale_new_3(physx_PxVec3_Pod const* s_pod, physx_PxQuat_Pod const* r_pod) {
        physx::PxVec3 const& s = reinterpret_cast<physx::PxVec3 const&>(*s_pod);
        physx::PxQuat const& r = reinterpret_cast<physx::PxQuat const&>(*r_pod);
        PxMeshScale return_val(s, r);
        physx_PxMeshScale_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxMeshScale_isIdentity(physx_PxMeshScale_Pod const* self__pod) {
        physx::PxMeshScale const* self_ = reinterpret_cast<physx::PxMeshScale const*>(self__pod);
        bool return_val = self_->isIdentity();
        return return_val;
    }

    physx_PxMeshScale_Pod PxMeshScale_getInverse(physx_PxMeshScale_Pod const* self__pod) {
        physx::PxMeshScale const* self_ = reinterpret_cast<physx::PxMeshScale const*>(self__pod);
        physx::PxMeshScale return_val = self_->getInverse();
        physx_PxMeshScale_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMat33_Pod PxMeshScale_toMat33(physx_PxMeshScale_Pod const* self__pod) {
        physx::PxMeshScale const* self_ = reinterpret_cast<physx::PxMeshScale const*>(self__pod);
        physx::PxMat33 return_val = self_->toMat33();
        physx_PxMat33_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxMeshScale_hasNegativeDeterminant(physx_PxMeshScale_Pod const* self__pod) {
        physx::PxMeshScale const* self_ = reinterpret_cast<physx::PxMeshScale const*>(self__pod);
        bool return_val = self_->hasNegativeDeterminant();
        return return_val;
    }

    physx_PxVec3_Pod PxMeshScale_transform(physx_PxMeshScale_Pod const* self__pod, physx_PxVec3_Pod const* v_pod) {
        physx::PxMeshScale const* self_ = reinterpret_cast<physx::PxMeshScale const*>(self__pod);
        physx::PxVec3 const& v = reinterpret_cast<physx::PxVec3 const&>(*v_pod);
        physx::PxVec3 return_val = self_->transform(v);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxMeshScale_isValidForTriangleMesh(physx_PxMeshScale_Pod const* self__pod) {
        physx::PxMeshScale const* self_ = reinterpret_cast<physx::PxMeshScale const*>(self__pod);
        bool return_val = self_->isValidForTriangleMesh();
        return return_val;
    }

    bool PxMeshScale_isValidForConvexMesh(physx_PxMeshScale_Pod const* self__pod) {
        physx::PxMeshScale const* self_ = reinterpret_cast<physx::PxMeshScale const*>(self__pod);
        bool return_val = self_->isValidForConvexMesh();
        return return_val;
    }

    physx_PxConvexMeshGeometry_Pod PxConvexMeshGeometry_new(physx_PxConvexMesh_Pod* mesh_pod, physx_PxMeshScale_Pod const* scaling_pod, uint8_t flags_pod) {
        physx::PxConvexMesh* mesh = reinterpret_cast<physx::PxConvexMesh*>(mesh_pod);
        physx::PxMeshScale const& scaling = reinterpret_cast<physx::PxMeshScale const&>(*scaling_pod);
        auto flags = physx::PxConvexMeshGeometryFlags(flags_pod);
        PxConvexMeshGeometry return_val(mesh, scaling, flags);
        physx_PxConvexMeshGeometry_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxConvexMeshGeometry_isValid(physx_PxConvexMeshGeometry_Pod const* self__pod) {
        physx::PxConvexMeshGeometry const* self_ = reinterpret_cast<physx::PxConvexMeshGeometry const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    physx_PxSphereGeometry_Pod PxSphereGeometry_new(float ir) {
        PxSphereGeometry return_val(ir);
        physx_PxSphereGeometry_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxSphereGeometry_isValid(physx_PxSphereGeometry_Pod const* self__pod) {
        physx::PxSphereGeometry const* self_ = reinterpret_cast<physx::PxSphereGeometry const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    physx_PxPlaneGeometry_Pod PxPlaneGeometry_new() {
        PxPlaneGeometry return_val;
        physx_PxPlaneGeometry_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxPlaneGeometry_isValid(physx_PxPlaneGeometry_Pod const* self__pod) {
        physx::PxPlaneGeometry const* self_ = reinterpret_cast<physx::PxPlaneGeometry const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    physx_PxTriangleMeshGeometry_Pod PxTriangleMeshGeometry_new(physx_PxTriangleMesh_Pod* mesh_pod, physx_PxMeshScale_Pod const* scaling_pod, uint8_t flags_pod) {
        physx::PxTriangleMesh* mesh = reinterpret_cast<physx::PxTriangleMesh*>(mesh_pod);
        physx::PxMeshScale const& scaling = reinterpret_cast<physx::PxMeshScale const&>(*scaling_pod);
        auto flags = physx::PxMeshGeometryFlags(flags_pod);
        PxTriangleMeshGeometry return_val(mesh, scaling, flags);
        physx_PxTriangleMeshGeometry_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxTriangleMeshGeometry_isValid(physx_PxTriangleMeshGeometry_Pod const* self__pod) {
        physx::PxTriangleMeshGeometry const* self_ = reinterpret_cast<physx::PxTriangleMeshGeometry const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    physx_PxHeightFieldGeometry_Pod PxHeightFieldGeometry_new(physx_PxHeightField_Pod* hf_pod, uint8_t flags_pod, float heightScale_, float rowScale_, float columnScale_) {
        physx::PxHeightField* hf = reinterpret_cast<physx::PxHeightField*>(hf_pod);
        auto flags = physx::PxMeshGeometryFlags(flags_pod);
        PxHeightFieldGeometry return_val(hf, flags, heightScale_, rowScale_, columnScale_);
        physx_PxHeightFieldGeometry_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxHeightFieldGeometry_isValid(physx_PxHeightFieldGeometry_Pod const* self__pod) {
        physx::PxHeightFieldGeometry const* self_ = reinterpret_cast<physx::PxHeightFieldGeometry const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    physx_PxParticleSystemGeometry_Pod PxParticleSystemGeometry_new() {
        PxParticleSystemGeometry return_val;
        physx_PxParticleSystemGeometry_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxParticleSystemGeometry_isValid(physx_PxParticleSystemGeometry_Pod const* self__pod) {
        physx::PxParticleSystemGeometry const* self_ = reinterpret_cast<physx::PxParticleSystemGeometry const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    physx_PxHairSystemGeometry_Pod PxHairSystemGeometry_new() {
        PxHairSystemGeometry return_val;
        physx_PxHairSystemGeometry_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxHairSystemGeometry_isValid(physx_PxHairSystemGeometry_Pod const* self__pod) {
        physx::PxHairSystemGeometry const* self_ = reinterpret_cast<physx::PxHairSystemGeometry const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    physx_PxTetrahedronMeshGeometry_Pod PxTetrahedronMeshGeometry_new(physx_PxTetrahedronMesh_Pod* mesh_pod) {
        physx::PxTetrahedronMesh* mesh = reinterpret_cast<physx::PxTetrahedronMesh*>(mesh_pod);
        PxTetrahedronMeshGeometry return_val(mesh);
        physx_PxTetrahedronMeshGeometry_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxTetrahedronMeshGeometry_isValid(physx_PxTetrahedronMeshGeometry_Pod const* self__pod) {
        physx::PxTetrahedronMeshGeometry const* self_ = reinterpret_cast<physx::PxTetrahedronMeshGeometry const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    physx_PxQueryHit_Pod PxQueryHit_new() {
        PxQueryHit return_val;
        physx_PxQueryHit_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxLocationHit_Pod PxLocationHit_new() {
        PxLocationHit return_val;
        physx_PxLocationHit_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxLocationHit_hadInitialOverlap(physx_PxLocationHit_Pod const* self__pod) {
        physx::PxLocationHit const* self_ = reinterpret_cast<physx::PxLocationHit const*>(self__pod);
        bool return_val = self_->hadInitialOverlap();
        return return_val;
    }

    physx_PxGeomRaycastHit_Pod PxGeomRaycastHit_new() {
        PxGeomRaycastHit return_val;
        physx_PxGeomRaycastHit_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxGeomOverlapHit_Pod PxGeomOverlapHit_new() {
        PxGeomOverlapHit return_val;
        physx_PxGeomOverlapHit_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxGeomSweepHit_Pod PxGeomSweepHit_new() {
        PxGeomSweepHit return_val;
        physx_PxGeomSweepHit_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxGeomIndexPair_Pod PxGeomIndexPair_new() {
        PxGeomIndexPair return_val;
        physx_PxGeomIndexPair_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxGeomIndexPair_Pod PxGeomIndexPair_new_1(uint32_t _id0, uint32_t _id1) {
        PxGeomIndexPair return_val(_id0, _id1);
        physx_PxGeomIndexPair_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    uint32_t phys_PxCustomGeometry_getUniqueID() {
        uint32_t return_val = PxCustomGeometry_getUniqueID();
        return return_val;
    }

    physx_PxCustomGeometryType_Pod PxCustomGeometryType_new() {
        PxCustomGeometryType return_val;
        physx_PxCustomGeometryType_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxCustomGeometryType_Pod PxCustomGeometryType_INVALID() {
        physx::PxCustomGeometryType return_val = PxCustomGeometryType::INVALID();
        physx_PxCustomGeometryType_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxCustomGeometryType_Pod PxCustomGeometryCallbacks_getCustomType(physx_PxCustomGeometryCallbacks_Pod const* self__pod) {
        physx::PxCustomGeometryCallbacks const* self_ = reinterpret_cast<physx::PxCustomGeometryCallbacks const*>(self__pod);
        physx::PxCustomGeometryType return_val = self_->getCustomType();
        physx_PxCustomGeometryType_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxBounds3_Pod PxCustomGeometryCallbacks_getLocalBounds(physx_PxCustomGeometryCallbacks_Pod const* self__pod, physx_PxGeometry_Pod const* geometry_pod) {
        physx::PxCustomGeometryCallbacks const* self_ = reinterpret_cast<physx::PxCustomGeometryCallbacks const*>(self__pod);
        physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
        physx::PxBounds3 return_val = self_->getLocalBounds(geometry);
        physx_PxBounds3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    uint32_t PxCustomGeometryCallbacks_raycast(physx_PxCustomGeometryCallbacks_Pod const* self__pod, physx_PxVec3_Pod const* origin_pod, physx_PxVec3_Pod const* unitDir_pod, physx_PxGeometry_Pod const* geom_pod, physx_PxTransform_Pod const* pose_pod, float maxDist, uint16_t hitFlags_pod, uint32_t maxHits, physx_PxGeomRaycastHit_Pod* rayHits_pod, uint32_t stride, physx_PxQueryThreadContext_Pod* threadContext_pod) {
        physx::PxCustomGeometryCallbacks const* self_ = reinterpret_cast<physx::PxCustomGeometryCallbacks const*>(self__pod);
        physx::PxVec3 const& origin = reinterpret_cast<physx::PxVec3 const&>(*origin_pod);
        physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
        physx::PxGeometry const& geom = reinterpret_cast<physx::PxGeometry const&>(*geom_pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        auto hitFlags = physx::PxHitFlags(hitFlags_pod);
        physx::PxGeomRaycastHit* rayHits = reinterpret_cast<physx::PxGeomRaycastHit*>(rayHits_pod);
        physx::PxQueryThreadContext* threadContext = reinterpret_cast<physx::PxQueryThreadContext*>(threadContext_pod);
        uint32_t return_val = self_->raycast(origin, unitDir, geom, pose, maxDist, hitFlags, maxHits, rayHits, stride, threadContext);
        return return_val;
    }

    bool PxCustomGeometryCallbacks_overlap(physx_PxCustomGeometryCallbacks_Pod const* self__pod, physx_PxGeometry_Pod const* geom0_pod, physx_PxTransform_Pod const* pose0_pod, physx_PxGeometry_Pod const* geom1_pod, physx_PxTransform_Pod const* pose1_pod, physx_PxQueryThreadContext_Pod* threadContext_pod) {
        physx::PxCustomGeometryCallbacks const* self_ = reinterpret_cast<physx::PxCustomGeometryCallbacks const*>(self__pod);
        physx::PxGeometry const& geom0 = reinterpret_cast<physx::PxGeometry const&>(*geom0_pod);
        physx::PxTransform const& pose0 = reinterpret_cast<physx::PxTransform const&>(*pose0_pod);
        physx::PxGeometry const& geom1 = reinterpret_cast<physx::PxGeometry const&>(*geom1_pod);
        physx::PxTransform const& pose1 = reinterpret_cast<physx::PxTransform const&>(*pose1_pod);
        physx::PxQueryThreadContext* threadContext = reinterpret_cast<physx::PxQueryThreadContext*>(threadContext_pod);
        bool return_val = self_->overlap(geom0, pose0, geom1, pose1, threadContext);
        return return_val;
    }

    bool PxCustomGeometryCallbacks_sweep(physx_PxCustomGeometryCallbacks_Pod const* self__pod, physx_PxVec3_Pod const* unitDir_pod, float maxDist, physx_PxGeometry_Pod const* geom0_pod, physx_PxTransform_Pod const* pose0_pod, physx_PxGeometry_Pod const* geom1_pod, physx_PxTransform_Pod const* pose1_pod, physx_PxGeomSweepHit_Pod* sweepHit_pod, uint16_t hitFlags_pod, float inflation, physx_PxQueryThreadContext_Pod* threadContext_pod) {
        physx::PxCustomGeometryCallbacks const* self_ = reinterpret_cast<physx::PxCustomGeometryCallbacks const*>(self__pod);
        physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
        physx::PxGeometry const& geom0 = reinterpret_cast<physx::PxGeometry const&>(*geom0_pod);
        physx::PxTransform const& pose0 = reinterpret_cast<physx::PxTransform const&>(*pose0_pod);
        physx::PxGeometry const& geom1 = reinterpret_cast<physx::PxGeometry const&>(*geom1_pod);
        physx::PxTransform const& pose1 = reinterpret_cast<physx::PxTransform const&>(*pose1_pod);
        physx::PxGeomSweepHit& sweepHit = reinterpret_cast<physx::PxGeomSweepHit&>(*sweepHit_pod);
        auto hitFlags = physx::PxHitFlags(hitFlags_pod);
        physx::PxQueryThreadContext* threadContext = reinterpret_cast<physx::PxQueryThreadContext*>(threadContext_pod);
        bool return_val = self_->sweep(unitDir, maxDist, geom0, pose0, geom1, pose1, sweepHit, hitFlags, inflation, threadContext);
        return return_val;
    }

    void PxCustomGeometryCallbacks_computeMassProperties(physx_PxCustomGeometryCallbacks_Pod const* self__pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxMassProperties_Pod* massProperties_pod) {
        physx::PxCustomGeometryCallbacks const* self_ = reinterpret_cast<physx::PxCustomGeometryCallbacks const*>(self__pod);
        physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
        physx::PxMassProperties& massProperties = reinterpret_cast<physx::PxMassProperties&>(*massProperties_pod);
        self_->computeMassProperties(geometry, massProperties);
    }

    bool PxCustomGeometryCallbacks_usePersistentContactManifold(physx_PxCustomGeometryCallbacks_Pod const* self__pod, physx_PxGeometry_Pod const* geometry_pod, float* breakingThreshold_pod) {
        physx::PxCustomGeometryCallbacks const* self_ = reinterpret_cast<physx::PxCustomGeometryCallbacks const*>(self__pod);
        physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
        float& breakingThreshold = *breakingThreshold_pod;
        bool return_val = self_->usePersistentContactManifold(geometry, breakingThreshold);
        return return_val;
    }

    void PxCustomGeometryCallbacks_delete(physx_PxCustomGeometryCallbacks_Pod* self__pod) {
        physx::PxCustomGeometryCallbacks* self_ = reinterpret_cast<physx::PxCustomGeometryCallbacks*>(self__pod);
        delete self_;
    }

    physx_PxCustomGeometry_Pod PxCustomGeometry_new() {
        PxCustomGeometry return_val;
        physx_PxCustomGeometry_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxCustomGeometry_Pod PxCustomGeometry_new_1(physx_PxCustomGeometryCallbacks_Pod* _callbacks_pod) {
        physx::PxCustomGeometryCallbacks& _callbacks = reinterpret_cast<physx::PxCustomGeometryCallbacks&>(*_callbacks_pod);
        PxCustomGeometry return_val(_callbacks);
        physx_PxCustomGeometry_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxCustomGeometry_isValid(physx_PxCustomGeometry_Pod const* self__pod) {
        physx::PxCustomGeometry const* self_ = reinterpret_cast<physx::PxCustomGeometry const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    physx_PxCustomGeometryType_Pod PxCustomGeometry_getCustomType(physx_PxCustomGeometry_Pod const* self__pod) {
        physx::PxCustomGeometry const* self_ = reinterpret_cast<physx::PxCustomGeometry const*>(self__pod);
        physx::PxCustomGeometryType return_val = self_->getCustomType();
        physx_PxCustomGeometryType_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    int32_t PxGeometryHolder_getType(physx_PxGeometryHolder_Pod const* self__pod) {
        physx::PxGeometryHolder const* self_ = reinterpret_cast<physx::PxGeometryHolder const*>(self__pod);
        physx::PxGeometryType::Enum return_val = self_->getType();
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxGeometry_Pod* PxGeometryHolder_any_mut(physx_PxGeometryHolder_Pod* self__pod) {
        physx::PxGeometryHolder* self_ = reinterpret_cast<physx::PxGeometryHolder*>(self__pod);
        physx::PxGeometry& return_val = self_->any();
        auto return_val_pod = reinterpret_cast<physx_PxGeometry_Pod*>(&return_val);
        return return_val_pod;
    }

    physx_PxGeometry_Pod const* PxGeometryHolder_any(physx_PxGeometryHolder_Pod const* self__pod) {
        physx::PxGeometryHolder const* self_ = reinterpret_cast<physx::PxGeometryHolder const*>(self__pod);
        physx::PxGeometry const& return_val = self_->any();
        auto return_val_pod = reinterpret_cast<physx_PxGeometry_Pod const*>(&return_val);
        return return_val_pod;
    }

    physx_PxSphereGeometry_Pod* PxGeometryHolder_sphere_mut(physx_PxGeometryHolder_Pod* self__pod) {
        physx::PxGeometryHolder* self_ = reinterpret_cast<physx::PxGeometryHolder*>(self__pod);
        physx::PxSphereGeometry& return_val = self_->sphere();
        auto return_val_pod = reinterpret_cast<physx_PxSphereGeometry_Pod*>(&return_val);
        return return_val_pod;
    }

    physx_PxSphereGeometry_Pod const* PxGeometryHolder_sphere(physx_PxGeometryHolder_Pod const* self__pod) {
        physx::PxGeometryHolder const* self_ = reinterpret_cast<physx::PxGeometryHolder const*>(self__pod);
        physx::PxSphereGeometry const& return_val = self_->sphere();
        auto return_val_pod = reinterpret_cast<physx_PxSphereGeometry_Pod const*>(&return_val);
        return return_val_pod;
    }

    physx_PxPlaneGeometry_Pod* PxGeometryHolder_plane_mut(physx_PxGeometryHolder_Pod* self__pod) {
        physx::PxGeometryHolder* self_ = reinterpret_cast<physx::PxGeometryHolder*>(self__pod);
        physx::PxPlaneGeometry& return_val = self_->plane();
        auto return_val_pod = reinterpret_cast<physx_PxPlaneGeometry_Pod*>(&return_val);
        return return_val_pod;
    }

    physx_PxPlaneGeometry_Pod const* PxGeometryHolder_plane(physx_PxGeometryHolder_Pod const* self__pod) {
        physx::PxGeometryHolder const* self_ = reinterpret_cast<physx::PxGeometryHolder const*>(self__pod);
        physx::PxPlaneGeometry const& return_val = self_->plane();
        auto return_val_pod = reinterpret_cast<physx_PxPlaneGeometry_Pod const*>(&return_val);
        return return_val_pod;
    }

    physx_PxCapsuleGeometry_Pod* PxGeometryHolder_capsule_mut(physx_PxGeometryHolder_Pod* self__pod) {
        physx::PxGeometryHolder* self_ = reinterpret_cast<physx::PxGeometryHolder*>(self__pod);
        physx::PxCapsuleGeometry& return_val = self_->capsule();
        auto return_val_pod = reinterpret_cast<physx_PxCapsuleGeometry_Pod*>(&return_val);
        return return_val_pod;
    }

    physx_PxCapsuleGeometry_Pod const* PxGeometryHolder_capsule(physx_PxGeometryHolder_Pod const* self__pod) {
        physx::PxGeometryHolder const* self_ = reinterpret_cast<physx::PxGeometryHolder const*>(self__pod);
        physx::PxCapsuleGeometry const& return_val = self_->capsule();
        auto return_val_pod = reinterpret_cast<physx_PxCapsuleGeometry_Pod const*>(&return_val);
        return return_val_pod;
    }

    physx_PxBoxGeometry_Pod* PxGeometryHolder_box_mut(physx_PxGeometryHolder_Pod* self__pod) {
        physx::PxGeometryHolder* self_ = reinterpret_cast<physx::PxGeometryHolder*>(self__pod);
        physx::PxBoxGeometry& return_val = self_->box();
        auto return_val_pod = reinterpret_cast<physx_PxBoxGeometry_Pod*>(&return_val);
        return return_val_pod;
    }

    physx_PxBoxGeometry_Pod const* PxGeometryHolder_box(physx_PxGeometryHolder_Pod const* self__pod) {
        physx::PxGeometryHolder const* self_ = reinterpret_cast<physx::PxGeometryHolder const*>(self__pod);
        physx::PxBoxGeometry const& return_val = self_->box();
        auto return_val_pod = reinterpret_cast<physx_PxBoxGeometry_Pod const*>(&return_val);
        return return_val_pod;
    }

    physx_PxConvexMeshGeometry_Pod* PxGeometryHolder_convexMesh_mut(physx_PxGeometryHolder_Pod* self__pod) {
        physx::PxGeometryHolder* self_ = reinterpret_cast<physx::PxGeometryHolder*>(self__pod);
        physx::PxConvexMeshGeometry& return_val = self_->convexMesh();
        auto return_val_pod = reinterpret_cast<physx_PxConvexMeshGeometry_Pod*>(&return_val);
        return return_val_pod;
    }

    physx_PxConvexMeshGeometry_Pod const* PxGeometryHolder_convexMesh(physx_PxGeometryHolder_Pod const* self__pod) {
        physx::PxGeometryHolder const* self_ = reinterpret_cast<physx::PxGeometryHolder const*>(self__pod);
        physx::PxConvexMeshGeometry const& return_val = self_->convexMesh();
        auto return_val_pod = reinterpret_cast<physx_PxConvexMeshGeometry_Pod const*>(&return_val);
        return return_val_pod;
    }

    physx_PxTetrahedronMeshGeometry_Pod* PxGeometryHolder_tetMesh_mut(physx_PxGeometryHolder_Pod* self__pod) {
        physx::PxGeometryHolder* self_ = reinterpret_cast<physx::PxGeometryHolder*>(self__pod);
        physx::PxTetrahedronMeshGeometry& return_val = self_->tetMesh();
        auto return_val_pod = reinterpret_cast<physx_PxTetrahedronMeshGeometry_Pod*>(&return_val);
        return return_val_pod;
    }

    physx_PxTetrahedronMeshGeometry_Pod const* PxGeometryHolder_tetMesh(physx_PxGeometryHolder_Pod const* self__pod) {
        physx::PxGeometryHolder const* self_ = reinterpret_cast<physx::PxGeometryHolder const*>(self__pod);
        physx::PxTetrahedronMeshGeometry const& return_val = self_->tetMesh();
        auto return_val_pod = reinterpret_cast<physx_PxTetrahedronMeshGeometry_Pod const*>(&return_val);
        return return_val_pod;
    }

    physx_PxTriangleMeshGeometry_Pod* PxGeometryHolder_triangleMesh_mut(physx_PxGeometryHolder_Pod* self__pod) {
        physx::PxGeometryHolder* self_ = reinterpret_cast<physx::PxGeometryHolder*>(self__pod);
        physx::PxTriangleMeshGeometry& return_val = self_->triangleMesh();
        auto return_val_pod = reinterpret_cast<physx_PxTriangleMeshGeometry_Pod*>(&return_val);
        return return_val_pod;
    }

    physx_PxTriangleMeshGeometry_Pod const* PxGeometryHolder_triangleMesh(physx_PxGeometryHolder_Pod const* self__pod) {
        physx::PxGeometryHolder const* self_ = reinterpret_cast<physx::PxGeometryHolder const*>(self__pod);
        physx::PxTriangleMeshGeometry const& return_val = self_->triangleMesh();
        auto return_val_pod = reinterpret_cast<physx_PxTriangleMeshGeometry_Pod const*>(&return_val);
        return return_val_pod;
    }

    physx_PxHeightFieldGeometry_Pod* PxGeometryHolder_heightField_mut(physx_PxGeometryHolder_Pod* self__pod) {
        physx::PxGeometryHolder* self_ = reinterpret_cast<physx::PxGeometryHolder*>(self__pod);
        physx::PxHeightFieldGeometry& return_val = self_->heightField();
        auto return_val_pod = reinterpret_cast<physx_PxHeightFieldGeometry_Pod*>(&return_val);
        return return_val_pod;
    }

    physx_PxHeightFieldGeometry_Pod const* PxGeometryHolder_heightField(physx_PxGeometryHolder_Pod const* self__pod) {
        physx::PxGeometryHolder const* self_ = reinterpret_cast<physx::PxGeometryHolder const*>(self__pod);
        physx::PxHeightFieldGeometry const& return_val = self_->heightField();
        auto return_val_pod = reinterpret_cast<physx_PxHeightFieldGeometry_Pod const*>(&return_val);
        return return_val_pod;
    }

    physx_PxParticleSystemGeometry_Pod* PxGeometryHolder_particleSystem_mut(physx_PxGeometryHolder_Pod* self__pod) {
        physx::PxGeometryHolder* self_ = reinterpret_cast<physx::PxGeometryHolder*>(self__pod);
        physx::PxParticleSystemGeometry& return_val = self_->particleSystem();
        auto return_val_pod = reinterpret_cast<physx_PxParticleSystemGeometry_Pod*>(&return_val);
        return return_val_pod;
    }

    physx_PxParticleSystemGeometry_Pod const* PxGeometryHolder_particleSystem(physx_PxGeometryHolder_Pod const* self__pod) {
        physx::PxGeometryHolder const* self_ = reinterpret_cast<physx::PxGeometryHolder const*>(self__pod);
        physx::PxParticleSystemGeometry const& return_val = self_->particleSystem();
        auto return_val_pod = reinterpret_cast<physx_PxParticleSystemGeometry_Pod const*>(&return_val);
        return return_val_pod;
    }

    physx_PxHairSystemGeometry_Pod* PxGeometryHolder_hairSystem_mut(physx_PxGeometryHolder_Pod* self__pod) {
        physx::PxGeometryHolder* self_ = reinterpret_cast<physx::PxGeometryHolder*>(self__pod);
        physx::PxHairSystemGeometry& return_val = self_->hairSystem();
        auto return_val_pod = reinterpret_cast<physx_PxHairSystemGeometry_Pod*>(&return_val);
        return return_val_pod;
    }

    physx_PxHairSystemGeometry_Pod const* PxGeometryHolder_hairSystem(physx_PxGeometryHolder_Pod const* self__pod) {
        physx::PxGeometryHolder const* self_ = reinterpret_cast<physx::PxGeometryHolder const*>(self__pod);
        physx::PxHairSystemGeometry const& return_val = self_->hairSystem();
        auto return_val_pod = reinterpret_cast<physx_PxHairSystemGeometry_Pod const*>(&return_val);
        return return_val_pod;
    }

    physx_PxCustomGeometry_Pod* PxGeometryHolder_custom_mut(physx_PxGeometryHolder_Pod* self__pod) {
        physx::PxGeometryHolder* self_ = reinterpret_cast<physx::PxGeometryHolder*>(self__pod);
        physx::PxCustomGeometry& return_val = self_->custom();
        auto return_val_pod = reinterpret_cast<physx_PxCustomGeometry_Pod*>(&return_val);
        return return_val_pod;
    }

    physx_PxCustomGeometry_Pod const* PxGeometryHolder_custom(physx_PxGeometryHolder_Pod const* self__pod) {
        physx::PxGeometryHolder const* self_ = reinterpret_cast<physx::PxGeometryHolder const*>(self__pod);
        physx::PxCustomGeometry const& return_val = self_->custom();
        auto return_val_pod = reinterpret_cast<physx_PxCustomGeometry_Pod const*>(&return_val);
        return return_val_pod;
    }

    void PxGeometryHolder_storeAny_mut(physx_PxGeometryHolder_Pod* self__pod, physx_PxGeometry_Pod const* geometry_pod) {
        physx::PxGeometryHolder* self_ = reinterpret_cast<physx::PxGeometryHolder*>(self__pod);
        physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
        self_->storeAny(geometry);
    }

    physx_PxGeometryHolder_Pod PxGeometryHolder_new() {
        PxGeometryHolder return_val;
        physx_PxGeometryHolder_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxGeometryHolder_Pod PxGeometryHolder_new_1(physx_PxGeometry_Pod const* geometry_pod) {
        physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
        PxGeometryHolder return_val(geometry);
        physx_PxGeometryHolder_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    uint32_t PxGeometryQuery_raycast(physx_PxVec3_Pod const* origin_pod, physx_PxVec3_Pod const* unitDir_pod, physx_PxGeometry_Pod const* geom_pod, physx_PxTransform_Pod const* pose_pod, float maxDist, uint16_t hitFlags_pod, uint32_t maxHits, physx_PxGeomRaycastHit_Pod* rayHits_pod, uint32_t stride, uint32_t queryFlags_pod, physx_PxQueryThreadContext_Pod* threadContext_pod) {
        physx::PxVec3 const& origin = reinterpret_cast<physx::PxVec3 const&>(*origin_pod);
        physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
        physx::PxGeometry const& geom = reinterpret_cast<physx::PxGeometry const&>(*geom_pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        auto hitFlags = physx::PxHitFlags(hitFlags_pod);
        physx::PxGeomRaycastHit* rayHits = reinterpret_cast<physx::PxGeomRaycastHit*>(rayHits_pod);
        auto queryFlags = physx::PxGeometryQueryFlags(queryFlags_pod);
        physx::PxQueryThreadContext* threadContext = reinterpret_cast<physx::PxQueryThreadContext*>(threadContext_pod);
        uint32_t return_val = PxGeometryQuery::raycast(origin, unitDir, geom, pose, maxDist, hitFlags, maxHits, rayHits, stride, queryFlags, threadContext);
        return return_val;
    }

    bool PxGeometryQuery_overlap(physx_PxGeometry_Pod const* geom0_pod, physx_PxTransform_Pod const* pose0_pod, physx_PxGeometry_Pod const* geom1_pod, physx_PxTransform_Pod const* pose1_pod, uint32_t queryFlags_pod, physx_PxQueryThreadContext_Pod* threadContext_pod) {
        physx::PxGeometry const& geom0 = reinterpret_cast<physx::PxGeometry const&>(*geom0_pod);
        physx::PxTransform const& pose0 = reinterpret_cast<physx::PxTransform const&>(*pose0_pod);
        physx::PxGeometry const& geom1 = reinterpret_cast<physx::PxGeometry const&>(*geom1_pod);
        physx::PxTransform const& pose1 = reinterpret_cast<physx::PxTransform const&>(*pose1_pod);
        auto queryFlags = physx::PxGeometryQueryFlags(queryFlags_pod);
        physx::PxQueryThreadContext* threadContext = reinterpret_cast<physx::PxQueryThreadContext*>(threadContext_pod);
        bool return_val = PxGeometryQuery::overlap(geom0, pose0, geom1, pose1, queryFlags, threadContext);
        return return_val;
    }

    bool PxGeometryQuery_sweep(physx_PxVec3_Pod const* unitDir_pod, float maxDist, physx_PxGeometry_Pod const* geom0_pod, physx_PxTransform_Pod const* pose0_pod, physx_PxGeometry_Pod const* geom1_pod, physx_PxTransform_Pod const* pose1_pod, physx_PxGeomSweepHit_Pod* sweepHit_pod, uint16_t hitFlags_pod, float inflation, uint32_t queryFlags_pod, physx_PxQueryThreadContext_Pod* threadContext_pod) {
        physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
        physx::PxGeometry const& geom0 = reinterpret_cast<physx::PxGeometry const&>(*geom0_pod);
        physx::PxTransform const& pose0 = reinterpret_cast<physx::PxTransform const&>(*pose0_pod);
        physx::PxGeometry const& geom1 = reinterpret_cast<physx::PxGeometry const&>(*geom1_pod);
        physx::PxTransform const& pose1 = reinterpret_cast<physx::PxTransform const&>(*pose1_pod);
        physx::PxGeomSweepHit& sweepHit = reinterpret_cast<physx::PxGeomSweepHit&>(*sweepHit_pod);
        auto hitFlags = physx::PxHitFlags(hitFlags_pod);
        auto queryFlags = physx::PxGeometryQueryFlags(queryFlags_pod);
        physx::PxQueryThreadContext* threadContext = reinterpret_cast<physx::PxQueryThreadContext*>(threadContext_pod);
        bool return_val = PxGeometryQuery::sweep(unitDir, maxDist, geom0, pose0, geom1, pose1, sweepHit, hitFlags, inflation, queryFlags, threadContext);
        return return_val;
    }

    bool PxGeometryQuery_computePenetration(physx_PxVec3_Pod* direction_pod, float* depth_pod, physx_PxGeometry_Pod const* geom0_pod, physx_PxTransform_Pod const* pose0_pod, physx_PxGeometry_Pod const* geom1_pod, physx_PxTransform_Pod const* pose1_pod, uint32_t queryFlags_pod) {
        physx::PxVec3& direction = reinterpret_cast<physx::PxVec3&>(*direction_pod);
        float& depth = *depth_pod;
        physx::PxGeometry const& geom0 = reinterpret_cast<physx::PxGeometry const&>(*geom0_pod);
        physx::PxTransform const& pose0 = reinterpret_cast<physx::PxTransform const&>(*pose0_pod);
        physx::PxGeometry const& geom1 = reinterpret_cast<physx::PxGeometry const&>(*geom1_pod);
        physx::PxTransform const& pose1 = reinterpret_cast<physx::PxTransform const&>(*pose1_pod);
        auto queryFlags = physx::PxGeometryQueryFlags(queryFlags_pod);
        bool return_val = PxGeometryQuery::computePenetration(direction, depth, geom0, pose0, geom1, pose1, queryFlags);
        return return_val;
    }

    float PxGeometryQuery_pointDistance(physx_PxVec3_Pod const* point_pod, physx_PxGeometry_Pod const* geom_pod, physx_PxTransform_Pod const* pose_pod, physx_PxVec3_Pod* closestPoint_pod, uint32_t* closestIndex, uint32_t queryFlags_pod) {
        physx::PxVec3 const& point = reinterpret_cast<physx::PxVec3 const&>(*point_pod);
        physx::PxGeometry const& geom = reinterpret_cast<physx::PxGeometry const&>(*geom_pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        physx::PxVec3* closestPoint = reinterpret_cast<physx::PxVec3*>(closestPoint_pod);
        auto queryFlags = physx::PxGeometryQueryFlags(queryFlags_pod);
        float return_val = PxGeometryQuery::pointDistance(point, geom, pose, closestPoint, closestIndex, queryFlags);
        return return_val;
    }

    void PxGeometryQuery_computeGeomBounds(physx_PxBounds3_Pod* bounds_pod, physx_PxGeometry_Pod const* geom_pod, physx_PxTransform_Pod const* pose_pod, float offset, float inflation, uint32_t queryFlags_pod) {
        physx::PxBounds3& bounds = reinterpret_cast<physx::PxBounds3&>(*bounds_pod);
        physx::PxGeometry const& geom = reinterpret_cast<physx::PxGeometry const&>(*geom_pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        auto queryFlags = physx::PxGeometryQueryFlags(queryFlags_pod);
        PxGeometryQuery::computeGeomBounds(bounds, geom, pose, offset, inflation, queryFlags);
    }

    bool PxGeometryQuery_isValid(physx_PxGeometry_Pod const* geom_pod) {
        physx::PxGeometry const& geom = reinterpret_cast<physx::PxGeometry const&>(*geom_pod);
        bool return_val = PxGeometryQuery::isValid(geom);
        return return_val;
    }

    uint8_t PxHeightFieldSample_tessFlag(physx_PxHeightFieldSample_Pod const* self__pod) {
        physx::PxHeightFieldSample const* self_ = reinterpret_cast<physx::PxHeightFieldSample const*>(self__pod);
        uint8_t return_val = self_->tessFlag();
        return return_val;
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
        uint32_t return_val = self_->saveCells(destBuffer, destBufferSize);
        return return_val;
    }

    bool PxHeightField_modifySamples_mut(physx_PxHeightField_Pod* self__pod, int32_t startCol, int32_t startRow, physx_PxHeightFieldDesc_Pod const* subfieldDesc_pod, bool shrinkBounds) {
        physx::PxHeightField* self_ = reinterpret_cast<physx::PxHeightField*>(self__pod);
        physx::PxHeightFieldDesc const& subfieldDesc = reinterpret_cast<physx::PxHeightFieldDesc const&>(*subfieldDesc_pod);
        bool return_val = self_->modifySamples(startCol, startRow, subfieldDesc, shrinkBounds);
        return return_val;
    }

    uint32_t PxHeightField_getNbRows(physx_PxHeightField_Pod const* self__pod) {
        physx::PxHeightField const* self_ = reinterpret_cast<physx::PxHeightField const*>(self__pod);
        uint32_t return_val = self_->getNbRows();
        return return_val;
    }

    uint32_t PxHeightField_getNbColumns(physx_PxHeightField_Pod const* self__pod) {
        physx::PxHeightField const* self_ = reinterpret_cast<physx::PxHeightField const*>(self__pod);
        uint32_t return_val = self_->getNbColumns();
        return return_val;
    }

    int32_t PxHeightField_getFormat(physx_PxHeightField_Pod const* self__pod) {
        physx::PxHeightField const* self_ = reinterpret_cast<physx::PxHeightField const*>(self__pod);
        physx::PxHeightFieldFormat::Enum return_val = self_->getFormat();
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    uint32_t PxHeightField_getSampleStride(physx_PxHeightField_Pod const* self__pod) {
        physx::PxHeightField const* self_ = reinterpret_cast<physx::PxHeightField const*>(self__pod);
        uint32_t return_val = self_->getSampleStride();
        return return_val;
    }

    float PxHeightField_getConvexEdgeThreshold(physx_PxHeightField_Pod const* self__pod) {
        physx::PxHeightField const* self_ = reinterpret_cast<physx::PxHeightField const*>(self__pod);
        float return_val = self_->getConvexEdgeThreshold();
        return return_val;
    }

    uint16_t PxHeightField_getFlags(physx_PxHeightField_Pod const* self__pod) {
        physx::PxHeightField const* self_ = reinterpret_cast<physx::PxHeightField const*>(self__pod);
        physx::PxHeightFieldFlags return_val = self_->getFlags();
        uint16_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    float PxHeightField_getHeight(physx_PxHeightField_Pod const* self__pod, float x, float z) {
        physx::PxHeightField const* self_ = reinterpret_cast<physx::PxHeightField const*>(self__pod);
        float return_val = self_->getHeight(x, z);
        return return_val;
    }

    uint16_t PxHeightField_getTriangleMaterialIndex(physx_PxHeightField_Pod const* self__pod, uint32_t triangleIndex) {
        physx::PxHeightField const* self_ = reinterpret_cast<physx::PxHeightField const*>(self__pod);
        uint16_t return_val = self_->getTriangleMaterialIndex(triangleIndex);
        return return_val;
    }

    physx_PxVec3_Pod PxHeightField_getTriangleNormal(physx_PxHeightField_Pod const* self__pod, uint32_t triangleIndex) {
        physx::PxHeightField const* self_ = reinterpret_cast<physx::PxHeightField const*>(self__pod);
        physx::PxVec3 return_val = self_->getTriangleNormal(triangleIndex);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxHeightFieldSample_Pod const* PxHeightField_getSample(physx_PxHeightField_Pod const* self__pod, uint32_t row, uint32_t column) {
        physx::PxHeightField const* self_ = reinterpret_cast<physx::PxHeightField const*>(self__pod);
        physx::PxHeightFieldSample const& return_val = self_->getSample(row, column);
        auto return_val_pod = reinterpret_cast<physx_PxHeightFieldSample_Pod const*>(&return_val);
        return return_val_pod;
    }

    uint32_t PxHeightField_getTimestamp(physx_PxHeightField_Pod const* self__pod) {
        physx::PxHeightField const* self_ = reinterpret_cast<physx::PxHeightField const*>(self__pod);
        uint32_t return_val = self_->getTimestamp();
        return return_val;
    }

    char const* PxHeightField_getConcreteTypeName(physx_PxHeightField_Pod const* self__pod) {
        physx::PxHeightField const* self_ = reinterpret_cast<physx::PxHeightField const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    physx_PxHeightFieldDesc_Pod PxHeightFieldDesc_new() {
        PxHeightFieldDesc return_val;
        physx_PxHeightFieldDesc_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxHeightFieldDesc_setToDefault_mut(physx_PxHeightFieldDesc_Pod* self__pod) {
        physx::PxHeightFieldDesc* self_ = reinterpret_cast<physx::PxHeightFieldDesc*>(self__pod);
        self_->setToDefault();
    }

    bool PxHeightFieldDesc_isValid(physx_PxHeightFieldDesc_Pod const* self__pod) {
        physx::PxHeightFieldDesc const* self_ = reinterpret_cast<physx::PxHeightFieldDesc const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    void PxMeshQuery_getTriangle(physx_PxTriangleMeshGeometry_Pod const* triGeom_pod, physx_PxTransform_Pod const* transform_pod, uint32_t triangleIndex, physx_PxTriangle_Pod* triangle_pod, uint32_t* vertexIndices, uint32_t* adjacencyIndices) {
        physx::PxTriangleMeshGeometry const& triGeom = reinterpret_cast<physx::PxTriangleMeshGeometry const&>(*triGeom_pod);
        physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
        physx::PxTriangle& triangle = reinterpret_cast<physx::PxTriangle&>(*triangle_pod);
        PxMeshQuery::getTriangle(triGeom, transform, triangleIndex, triangle, vertexIndices, adjacencyIndices);
    }

    void PxMeshQuery_getTriangle_1(physx_PxHeightFieldGeometry_Pod const* hfGeom_pod, physx_PxTransform_Pod const* transform_pod, uint32_t triangleIndex, physx_PxTriangle_Pod* triangle_pod, uint32_t* vertexIndices, uint32_t* adjacencyIndices) {
        physx::PxHeightFieldGeometry const& hfGeom = reinterpret_cast<physx::PxHeightFieldGeometry const&>(*hfGeom_pod);
        physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
        physx::PxTriangle& triangle = reinterpret_cast<physx::PxTriangle&>(*triangle_pod);
        PxMeshQuery::getTriangle(hfGeom, transform, triangleIndex, triangle, vertexIndices, adjacencyIndices);
    }

    uint32_t PxMeshQuery_findOverlapTriangleMesh(physx_PxGeometry_Pod const* geom_pod, physx_PxTransform_Pod const* geomPose_pod, physx_PxTriangleMeshGeometry_Pod const* meshGeom_pod, physx_PxTransform_Pod const* meshPose_pod, uint32_t* results, uint32_t maxResults, uint32_t startIndex, bool* overflow_pod, uint32_t queryFlags_pod) {
        physx::PxGeometry const& geom = reinterpret_cast<physx::PxGeometry const&>(*geom_pod);
        physx::PxTransform const& geomPose = reinterpret_cast<physx::PxTransform const&>(*geomPose_pod);
        physx::PxTriangleMeshGeometry const& meshGeom = reinterpret_cast<physx::PxTriangleMeshGeometry const&>(*meshGeom_pod);
        physx::PxTransform const& meshPose = reinterpret_cast<physx::PxTransform const&>(*meshPose_pod);
        bool& overflow = *overflow_pod;
        auto queryFlags = physx::PxGeometryQueryFlags(queryFlags_pod);
        uint32_t return_val = PxMeshQuery::findOverlapTriangleMesh(geom, geomPose, meshGeom, meshPose, results, maxResults, startIndex, overflow, queryFlags);
        return return_val;
    }

    uint32_t PxMeshQuery_findOverlapHeightField(physx_PxGeometry_Pod const* geom_pod, physx_PxTransform_Pod const* geomPose_pod, physx_PxHeightFieldGeometry_Pod const* hfGeom_pod, physx_PxTransform_Pod const* hfPose_pod, uint32_t* results, uint32_t maxResults, uint32_t startIndex, bool* overflow_pod, uint32_t queryFlags_pod) {
        physx::PxGeometry const& geom = reinterpret_cast<physx::PxGeometry const&>(*geom_pod);
        physx::PxTransform const& geomPose = reinterpret_cast<physx::PxTransform const&>(*geomPose_pod);
        physx::PxHeightFieldGeometry const& hfGeom = reinterpret_cast<physx::PxHeightFieldGeometry const&>(*hfGeom_pod);
        physx::PxTransform const& hfPose = reinterpret_cast<physx::PxTransform const&>(*hfPose_pod);
        bool& overflow = *overflow_pod;
        auto queryFlags = physx::PxGeometryQueryFlags(queryFlags_pod);
        uint32_t return_val = PxMeshQuery::findOverlapHeightField(geom, geomPose, hfGeom, hfPose, results, maxResults, startIndex, overflow, queryFlags);
        return return_val;
    }

    bool PxMeshQuery_sweep(physx_PxVec3_Pod const* unitDir_pod, float distance, physx_PxGeometry_Pod const* geom_pod, physx_PxTransform_Pod const* pose_pod, uint32_t triangleCount, physx_PxTriangle_Pod const* triangles_pod, physx_PxGeomSweepHit_Pod* sweepHit_pod, uint16_t hitFlags_pod, uint32_t const* cachedIndex, float inflation, bool doubleSided, uint32_t queryFlags_pod) {
        physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
        physx::PxGeometry const& geom = reinterpret_cast<physx::PxGeometry const&>(*geom_pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        physx::PxTriangle const* triangles = reinterpret_cast<physx::PxTriangle const*>(triangles_pod);
        physx::PxGeomSweepHit& sweepHit = reinterpret_cast<physx::PxGeomSweepHit&>(*sweepHit_pod);
        auto hitFlags = physx::PxHitFlags(hitFlags_pod);
        auto queryFlags = physx::PxGeometryQueryFlags(queryFlags_pod);
        bool return_val = PxMeshQuery::sweep(unitDir, distance, geom, pose, triangleCount, triangles, sweepHit, hitFlags, cachedIndex, inflation, doubleSided, queryFlags);
        return return_val;
    }

    physx_PxSimpleTriangleMesh_Pod PxSimpleTriangleMesh_new() {
        PxSimpleTriangleMesh return_val;
        physx_PxSimpleTriangleMesh_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxSimpleTriangleMesh_setToDefault_mut(physx_PxSimpleTriangleMesh_Pod* self__pod) {
        physx::PxSimpleTriangleMesh* self_ = reinterpret_cast<physx::PxSimpleTriangleMesh*>(self__pod);
        self_->setToDefault();
    }

    bool PxSimpleTriangleMesh_isValid(physx_PxSimpleTriangleMesh_Pod const* self__pod) {
        physx::PxSimpleTriangleMesh const* self_ = reinterpret_cast<physx::PxSimpleTriangleMesh const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    physx_PxTriangle_Pod* PxTriangle_new_alloc() {
        auto return_val = new physx::PxTriangle();
        auto return_val_pod = reinterpret_cast<physx_PxTriangle_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxTriangle_Pod* PxTriangle_new_alloc_1(physx_PxVec3_Pod const* p0_pod, physx_PxVec3_Pod const* p1_pod, physx_PxVec3_Pod const* p2_pod) {
        physx::PxVec3 const& p0 = reinterpret_cast<physx::PxVec3 const&>(*p0_pod);
        physx::PxVec3 const& p1 = reinterpret_cast<physx::PxVec3 const&>(*p1_pod);
        physx::PxVec3 const& p2 = reinterpret_cast<physx::PxVec3 const&>(*p2_pod);
        auto return_val = new physx::PxTriangle(p0, p1, p2);
        auto return_val_pod = reinterpret_cast<physx_PxTriangle_Pod*>(return_val);
        return return_val_pod;
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
        float return_val = self_->area();
        return return_val;
    }

    physx_PxVec3_Pod PxTriangle_pointFromUV(physx_PxTriangle_Pod const* self__pod, float u, float v) {
        physx::PxTriangle const* self_ = reinterpret_cast<physx::PxTriangle const*>(self__pod);
        physx::PxVec3 return_val = self_->pointFromUV(u, v);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxTrianglePadded_Pod* PxTrianglePadded_new_alloc() {
        auto return_val = new physx::PxTrianglePadded();
        auto return_val_pod = reinterpret_cast<physx_PxTrianglePadded_Pod*>(return_val);
        return return_val_pod;
    }

    void PxTrianglePadded_delete(physx_PxTrianglePadded_Pod* self__pod) {
        physx::PxTrianglePadded* self_ = reinterpret_cast<physx::PxTrianglePadded*>(self__pod);
        delete self_;
    }

    uint32_t PxTriangleMesh_getNbVertices(physx_PxTriangleMesh_Pod const* self__pod) {
        physx::PxTriangleMesh const* self_ = reinterpret_cast<physx::PxTriangleMesh const*>(self__pod);
        uint32_t return_val = self_->getNbVertices();
        return return_val;
    }

    physx_PxVec3_Pod const* PxTriangleMesh_getVertices(physx_PxTriangleMesh_Pod const* self__pod) {
        physx::PxTriangleMesh const* self_ = reinterpret_cast<physx::PxTriangleMesh const*>(self__pod);
        physx::PxVec3 const* return_val = self_->getVertices();
        auto return_val_pod = reinterpret_cast<physx_PxVec3_Pod const*>(return_val);
        return return_val_pod;
    }

    physx_PxVec3_Pod* PxTriangleMesh_getVerticesForModification_mut(physx_PxTriangleMesh_Pod* self__pod) {
        physx::PxTriangleMesh* self_ = reinterpret_cast<physx::PxTriangleMesh*>(self__pod);
        physx::PxVec3* return_val = self_->getVerticesForModification();
        auto return_val_pod = reinterpret_cast<physx_PxVec3_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxBounds3_Pod PxTriangleMesh_refitBVH_mut(physx_PxTriangleMesh_Pod* self__pod) {
        physx::PxTriangleMesh* self_ = reinterpret_cast<physx::PxTriangleMesh*>(self__pod);
        physx::PxBounds3 return_val = self_->refitBVH();
        physx_PxBounds3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    uint32_t PxTriangleMesh_getNbTriangles(physx_PxTriangleMesh_Pod const* self__pod) {
        physx::PxTriangleMesh const* self_ = reinterpret_cast<physx::PxTriangleMesh const*>(self__pod);
        uint32_t return_val = self_->getNbTriangles();
        return return_val;
    }

    void const* PxTriangleMesh_getTriangles(physx_PxTriangleMesh_Pod const* self__pod) {
        physx::PxTriangleMesh const* self_ = reinterpret_cast<physx::PxTriangleMesh const*>(self__pod);
        void const* return_val = self_->getTriangles();
        return return_val;
    }

    uint8_t PxTriangleMesh_getTriangleMeshFlags(physx_PxTriangleMesh_Pod const* self__pod) {
        physx::PxTriangleMesh const* self_ = reinterpret_cast<physx::PxTriangleMesh const*>(self__pod);
        physx::PxTriangleMeshFlags return_val = self_->getTriangleMeshFlags();
        uint8_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    uint32_t const* PxTriangleMesh_getTrianglesRemap(physx_PxTriangleMesh_Pod const* self__pod) {
        physx::PxTriangleMesh const* self_ = reinterpret_cast<physx::PxTriangleMesh const*>(self__pod);
        uint32_t const* return_val = self_->getTrianglesRemap();
        return return_val;
    }

    void PxTriangleMesh_release_mut(physx_PxTriangleMesh_Pod* self__pod) {
        physx::PxTriangleMesh* self_ = reinterpret_cast<physx::PxTriangleMesh*>(self__pod);
        self_->release();
    }

    uint16_t PxTriangleMesh_getTriangleMaterialIndex(physx_PxTriangleMesh_Pod const* self__pod, uint32_t triangleIndex) {
        physx::PxTriangleMesh const* self_ = reinterpret_cast<physx::PxTriangleMesh const*>(self__pod);
        uint16_t return_val = self_->getTriangleMaterialIndex(triangleIndex);
        return return_val;
    }

    physx_PxBounds3_Pod PxTriangleMesh_getLocalBounds(physx_PxTriangleMesh_Pod const* self__pod) {
        physx::PxTriangleMesh const* self_ = reinterpret_cast<physx::PxTriangleMesh const*>(self__pod);
        physx::PxBounds3 return_val = self_->getLocalBounds();
        physx_PxBounds3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    float const* PxTriangleMesh_getSDF(physx_PxTriangleMesh_Pod const* self__pod) {
        physx::PxTriangleMesh const* self_ = reinterpret_cast<physx::PxTriangleMesh const*>(self__pod);
        float const* return_val = self_->getSDF();
        return return_val;
    }

    void PxTriangleMesh_getSDFDimensions(physx_PxTriangleMesh_Pod const* self__pod, uint32_t* numX_pod, uint32_t* numY_pod, uint32_t* numZ_pod) {
        physx::PxTriangleMesh const* self_ = reinterpret_cast<physx::PxTriangleMesh const*>(self__pod);
        uint32_t& numX = *numX_pod;
        uint32_t& numY = *numY_pod;
        uint32_t& numZ = *numZ_pod;
        self_->getSDFDimensions(numX, numY, numZ);
    }

    void PxTriangleMesh_setPreferSDFProjection_mut(physx_PxTriangleMesh_Pod* self__pod, bool preferProjection) {
        physx::PxTriangleMesh* self_ = reinterpret_cast<physx::PxTriangleMesh*>(self__pod);
        self_->setPreferSDFProjection(preferProjection);
    }

    bool PxTriangleMesh_getPreferSDFProjection(physx_PxTriangleMesh_Pod const* self__pod) {
        physx::PxTriangleMesh const* self_ = reinterpret_cast<physx::PxTriangleMesh const*>(self__pod);
        bool return_val = self_->getPreferSDFProjection();
        return return_val;
    }

    void PxTriangleMesh_getMassInformation(physx_PxTriangleMesh_Pod const* self__pod, float* mass_pod, physx_PxMat33_Pod* localInertia_pod, physx_PxVec3_Pod* localCenterOfMass_pod) {
        physx::PxTriangleMesh const* self_ = reinterpret_cast<physx::PxTriangleMesh const*>(self__pod);
        float& mass = *mass_pod;
        physx::PxMat33& localInertia = reinterpret_cast<physx::PxMat33&>(*localInertia_pod);
        physx::PxVec3& localCenterOfMass = reinterpret_cast<physx::PxVec3&>(*localCenterOfMass_pod);
        self_->getMassInformation(mass, localInertia, localCenterOfMass);
    }

    physx_PxTetrahedron_Pod* PxTetrahedron_new_alloc() {
        auto return_val = new physx::PxTetrahedron();
        auto return_val_pod = reinterpret_cast<physx_PxTetrahedron_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxTetrahedron_Pod* PxTetrahedron_new_alloc_1(physx_PxVec3_Pod const* p0_pod, physx_PxVec3_Pod const* p1_pod, physx_PxVec3_Pod const* p2_pod, physx_PxVec3_Pod const* p3_pod) {
        physx::PxVec3 const& p0 = reinterpret_cast<physx::PxVec3 const&>(*p0_pod);
        physx::PxVec3 const& p1 = reinterpret_cast<physx::PxVec3 const&>(*p1_pod);
        physx::PxVec3 const& p2 = reinterpret_cast<physx::PxVec3 const&>(*p2_pod);
        physx::PxVec3 const& p3 = reinterpret_cast<physx::PxVec3 const&>(*p3_pod);
        auto return_val = new physx::PxTetrahedron(p0, p1, p2, p3);
        auto return_val_pod = reinterpret_cast<physx_PxTetrahedron_Pod*>(return_val);
        return return_val_pod;
    }

    void PxTetrahedron_delete(physx_PxTetrahedron_Pod* self__pod) {
        physx::PxTetrahedron* self_ = reinterpret_cast<physx::PxTetrahedron*>(self__pod);
        delete self_;
    }

    void PxSoftBodyAuxData_release_mut(physx_PxSoftBodyAuxData_Pod* self__pod) {
        physx::PxSoftBodyAuxData* self_ = reinterpret_cast<physx::PxSoftBodyAuxData*>(self__pod);
        self_->release();
    }

    uint32_t PxTetrahedronMesh_getNbVertices(physx_PxTetrahedronMesh_Pod const* self__pod) {
        physx::PxTetrahedronMesh const* self_ = reinterpret_cast<physx::PxTetrahedronMesh const*>(self__pod);
        uint32_t return_val = self_->getNbVertices();
        return return_val;
    }

    physx_PxVec3_Pod const* PxTetrahedronMesh_getVertices(physx_PxTetrahedronMesh_Pod const* self__pod) {
        physx::PxTetrahedronMesh const* self_ = reinterpret_cast<physx::PxTetrahedronMesh const*>(self__pod);
        physx::PxVec3 const* return_val = self_->getVertices();
        auto return_val_pod = reinterpret_cast<physx_PxVec3_Pod const*>(return_val);
        return return_val_pod;
    }

    uint32_t PxTetrahedronMesh_getNbTetrahedrons(physx_PxTetrahedronMesh_Pod const* self__pod) {
        physx::PxTetrahedronMesh const* self_ = reinterpret_cast<physx::PxTetrahedronMesh const*>(self__pod);
        uint32_t return_val = self_->getNbTetrahedrons();
        return return_val;
    }

    void const* PxTetrahedronMesh_getTetrahedrons(physx_PxTetrahedronMesh_Pod const* self__pod) {
        physx::PxTetrahedronMesh const* self_ = reinterpret_cast<physx::PxTetrahedronMesh const*>(self__pod);
        void const* return_val = self_->getTetrahedrons();
        return return_val;
    }

    uint8_t PxTetrahedronMesh_getTetrahedronMeshFlags(physx_PxTetrahedronMesh_Pod const* self__pod) {
        physx::PxTetrahedronMesh const* self_ = reinterpret_cast<physx::PxTetrahedronMesh const*>(self__pod);
        physx::PxTetrahedronMeshFlags return_val = self_->getTetrahedronMeshFlags();
        uint8_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    uint32_t const* PxTetrahedronMesh_getTetrahedraRemap(physx_PxTetrahedronMesh_Pod const* self__pod) {
        physx::PxTetrahedronMesh const* self_ = reinterpret_cast<physx::PxTetrahedronMesh const*>(self__pod);
        uint32_t const* return_val = self_->getTetrahedraRemap();
        return return_val;
    }

    physx_PxBounds3_Pod PxTetrahedronMesh_getLocalBounds(physx_PxTetrahedronMesh_Pod const* self__pod) {
        physx::PxTetrahedronMesh const* self_ = reinterpret_cast<physx::PxTetrahedronMesh const*>(self__pod);
        physx::PxBounds3 return_val = self_->getLocalBounds();
        physx_PxBounds3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxTetrahedronMesh_release_mut(physx_PxTetrahedronMesh_Pod* self__pod) {
        physx::PxTetrahedronMesh* self_ = reinterpret_cast<physx::PxTetrahedronMesh*>(self__pod);
        self_->release();
    }

    physx_PxTetrahedronMesh_Pod const* PxSoftBodyMesh_getCollisionMesh(physx_PxSoftBodyMesh_Pod const* self__pod) {
        physx::PxSoftBodyMesh const* self_ = reinterpret_cast<physx::PxSoftBodyMesh const*>(self__pod);
        physx::PxTetrahedronMesh const* return_val = self_->getCollisionMesh();
        auto return_val_pod = reinterpret_cast<physx_PxTetrahedronMesh_Pod const*>(return_val);
        return return_val_pod;
    }

    physx_PxTetrahedronMesh_Pod* PxSoftBodyMesh_getCollisionMesh_mut(physx_PxSoftBodyMesh_Pod* self__pod) {
        physx::PxSoftBodyMesh* self_ = reinterpret_cast<physx::PxSoftBodyMesh*>(self__pod);
        physx::PxTetrahedronMesh* return_val = self_->getCollisionMesh();
        auto return_val_pod = reinterpret_cast<physx_PxTetrahedronMesh_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxTetrahedronMesh_Pod const* PxSoftBodyMesh_getSimulationMesh(physx_PxSoftBodyMesh_Pod const* self__pod) {
        physx::PxSoftBodyMesh const* self_ = reinterpret_cast<physx::PxSoftBodyMesh const*>(self__pod);
        physx::PxTetrahedronMesh const* return_val = self_->getSimulationMesh();
        auto return_val_pod = reinterpret_cast<physx_PxTetrahedronMesh_Pod const*>(return_val);
        return return_val_pod;
    }

    physx_PxTetrahedronMesh_Pod* PxSoftBodyMesh_getSimulationMesh_mut(physx_PxSoftBodyMesh_Pod* self__pod) {
        physx::PxSoftBodyMesh* self_ = reinterpret_cast<physx::PxSoftBodyMesh*>(self__pod);
        physx::PxTetrahedronMesh* return_val = self_->getSimulationMesh();
        auto return_val_pod = reinterpret_cast<physx_PxTetrahedronMesh_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxSoftBodyAuxData_Pod const* PxSoftBodyMesh_getSoftBodyAuxData(physx_PxSoftBodyMesh_Pod const* self__pod) {
        physx::PxSoftBodyMesh const* self_ = reinterpret_cast<physx::PxSoftBodyMesh const*>(self__pod);
        physx::PxSoftBodyAuxData const* return_val = self_->getSoftBodyAuxData();
        auto return_val_pod = reinterpret_cast<physx_PxSoftBodyAuxData_Pod const*>(return_val);
        return return_val_pod;
    }

    physx_PxSoftBodyAuxData_Pod* PxSoftBodyMesh_getSoftBodyAuxData_mut(physx_PxSoftBodyMesh_Pod* self__pod) {
        physx::PxSoftBodyMesh* self_ = reinterpret_cast<physx::PxSoftBodyMesh*>(self__pod);
        physx::PxSoftBodyAuxData* return_val = self_->getSoftBodyAuxData();
        auto return_val_pod = reinterpret_cast<physx_PxSoftBodyAuxData_Pod*>(return_val);
        return return_val_pod;
    }

    void PxSoftBodyMesh_release_mut(physx_PxSoftBodyMesh_Pod* self__pod) {
        physx::PxSoftBodyMesh* self_ = reinterpret_cast<physx::PxSoftBodyMesh*>(self__pod);
        self_->release();
    }

    void PxCollisionMeshMappingData_release_mut(physx_PxCollisionMeshMappingData_Pod* self__pod) {
        physx::PxCollisionMeshMappingData* self_ = reinterpret_cast<physx::PxCollisionMeshMappingData*>(self__pod);
        self_->release();
    }

    physx_PxTetrahedronMeshData_Pod const* PxCollisionTetrahedronMeshData_getMesh(physx_PxCollisionTetrahedronMeshData_Pod const* self__pod) {
        physx::PxCollisionTetrahedronMeshData const* self_ = reinterpret_cast<physx::PxCollisionTetrahedronMeshData const*>(self__pod);
        physx::PxTetrahedronMeshData const* return_val = self_->getMesh();
        auto return_val_pod = reinterpret_cast<physx_PxTetrahedronMeshData_Pod const*>(return_val);
        return return_val_pod;
    }

    physx_PxTetrahedronMeshData_Pod* PxCollisionTetrahedronMeshData_getMesh_mut(physx_PxCollisionTetrahedronMeshData_Pod* self__pod) {
        physx::PxCollisionTetrahedronMeshData* self_ = reinterpret_cast<physx::PxCollisionTetrahedronMeshData*>(self__pod);
        physx::PxTetrahedronMeshData* return_val = self_->getMesh();
        auto return_val_pod = reinterpret_cast<physx_PxTetrahedronMeshData_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxSoftBodyCollisionData_Pod const* PxCollisionTetrahedronMeshData_getData(physx_PxCollisionTetrahedronMeshData_Pod const* self__pod) {
        physx::PxCollisionTetrahedronMeshData const* self_ = reinterpret_cast<physx::PxCollisionTetrahedronMeshData const*>(self__pod);
        physx::PxSoftBodyCollisionData const* return_val = self_->getData();
        auto return_val_pod = reinterpret_cast<physx_PxSoftBodyCollisionData_Pod const*>(return_val);
        return return_val_pod;
    }

    physx_PxSoftBodyCollisionData_Pod* PxCollisionTetrahedronMeshData_getData_mut(physx_PxCollisionTetrahedronMeshData_Pod* self__pod) {
        physx::PxCollisionTetrahedronMeshData* self_ = reinterpret_cast<physx::PxCollisionTetrahedronMeshData*>(self__pod);
        physx::PxSoftBodyCollisionData* return_val = self_->getData();
        auto return_val_pod = reinterpret_cast<physx_PxSoftBodyCollisionData_Pod*>(return_val);
        return return_val_pod;
    }

    void PxCollisionTetrahedronMeshData_release_mut(physx_PxCollisionTetrahedronMeshData_Pod* self__pod) {
        physx::PxCollisionTetrahedronMeshData* self_ = reinterpret_cast<physx::PxCollisionTetrahedronMeshData*>(self__pod);
        self_->release();
    }

    physx_PxTetrahedronMeshData_Pod* PxSimulationTetrahedronMeshData_getMesh_mut(physx_PxSimulationTetrahedronMeshData_Pod* self__pod) {
        physx::PxSimulationTetrahedronMeshData* self_ = reinterpret_cast<physx::PxSimulationTetrahedronMeshData*>(self__pod);
        physx::PxTetrahedronMeshData* return_val = self_->getMesh();
        auto return_val_pod = reinterpret_cast<physx_PxTetrahedronMeshData_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxSoftBodySimulationData_Pod* PxSimulationTetrahedronMeshData_getData_mut(physx_PxSimulationTetrahedronMeshData_Pod* self__pod) {
        physx::PxSimulationTetrahedronMeshData* self_ = reinterpret_cast<physx::PxSimulationTetrahedronMeshData*>(self__pod);
        physx::PxSoftBodySimulationData* return_val = self_->getData();
        auto return_val_pod = reinterpret_cast<physx_PxSoftBodySimulationData_Pod*>(return_val);
        return return_val_pod;
    }

    void PxSimulationTetrahedronMeshData_release_mut(physx_PxSimulationTetrahedronMeshData_Pod* self__pod) {
        physx::PxSimulationTetrahedronMeshData* self_ = reinterpret_cast<physx::PxSimulationTetrahedronMeshData*>(self__pod);
        self_->release();
    }

    void PxActor_release_mut(physx_PxActor_Pod* self__pod) {
        physx::PxActor* self_ = reinterpret_cast<physx::PxActor*>(self__pod);
        self_->release();
    }

    int32_t PxActor_getType(physx_PxActor_Pod const* self__pod) {
        physx::PxActor const* self_ = reinterpret_cast<physx::PxActor const*>(self__pod);
        physx::PxActorType::Enum return_val = self_->getType();
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxScene_Pod* PxActor_getScene(physx_PxActor_Pod const* self__pod) {
        physx::PxActor const* self_ = reinterpret_cast<physx::PxActor const*>(self__pod);
        physx::PxScene* return_val = self_->getScene();
        auto return_val_pod = reinterpret_cast<physx_PxScene_Pod*>(return_val);
        return return_val_pod;
    }

    void PxActor_setName_mut(physx_PxActor_Pod* self__pod, char const* name) {
        physx::PxActor* self_ = reinterpret_cast<physx::PxActor*>(self__pod);
        self_->setName(name);
    }

    char const* PxActor_getName(physx_PxActor_Pod const* self__pod) {
        physx::PxActor const* self_ = reinterpret_cast<physx::PxActor const*>(self__pod);
        char const* return_val = self_->getName();
        return return_val;
    }

    physx_PxBounds3_Pod PxActor_getWorldBounds(physx_PxActor_Pod const* self__pod, float inflation) {
        physx::PxActor const* self_ = reinterpret_cast<physx::PxActor const*>(self__pod);
        physx::PxBounds3 return_val = self_->getWorldBounds(inflation);
        physx_PxBounds3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxActor_setActorFlag_mut(physx_PxActor_Pod* self__pod, int32_t flag_pod, bool value) {
        physx::PxActor* self_ = reinterpret_cast<physx::PxActor*>(self__pod);
        auto flag = static_cast<physx::PxActorFlag::Enum>(flag_pod);
        self_->setActorFlag(flag, value);
    }

    void PxActor_setActorFlags_mut(physx_PxActor_Pod* self__pod, uint8_t inFlags_pod) {
        physx::PxActor* self_ = reinterpret_cast<physx::PxActor*>(self__pod);
        auto inFlags = physx::PxActorFlags(inFlags_pod);
        self_->setActorFlags(inFlags);
    }

    uint8_t PxActor_getActorFlags(physx_PxActor_Pod const* self__pod) {
        physx::PxActor const* self_ = reinterpret_cast<physx::PxActor const*>(self__pod);
        physx::PxActorFlags return_val = self_->getActorFlags();
        uint8_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxActor_setDominanceGroup_mut(physx_PxActor_Pod* self__pod, uint8_t dominanceGroup) {
        physx::PxActor* self_ = reinterpret_cast<physx::PxActor*>(self__pod);
        self_->setDominanceGroup(dominanceGroup);
    }

    uint8_t PxActor_getDominanceGroup(physx_PxActor_Pod const* self__pod) {
        physx::PxActor const* self_ = reinterpret_cast<physx::PxActor const*>(self__pod);
        uint8_t return_val = self_->getDominanceGroup();
        return return_val;
    }

    void PxActor_setOwnerClient_mut(physx_PxActor_Pod* self__pod, uint8_t inClient) {
        physx::PxActor* self_ = reinterpret_cast<physx::PxActor*>(self__pod);
        self_->setOwnerClient(inClient);
    }

    uint8_t PxActor_getOwnerClient(physx_PxActor_Pod const* self__pod) {
        physx::PxActor const* self_ = reinterpret_cast<physx::PxActor const*>(self__pod);
        uint8_t return_val = self_->getOwnerClient();
        return return_val;
    }

    physx_PxAggregate_Pod* PxActor_getAggregate(physx_PxActor_Pod const* self__pod) {
        physx::PxActor const* self_ = reinterpret_cast<physx::PxActor const*>(self__pod);
        physx::PxAggregate* return_val = self_->getAggregate();
        auto return_val_pod = reinterpret_cast<physx_PxAggregate_Pod*>(return_val);
        return return_val_pod;
    }

    uint32_t phys_PxGetAggregateFilterHint(int32_t type_pod, bool enableSelfCollision) {
        auto type = static_cast<physx::PxAggregateType::Enum>(type_pod);
        uint32_t return_val = PxGetAggregateFilterHint(type, enableSelfCollision);
        return return_val;
    }

    uint32_t phys_PxGetAggregateSelfCollisionBit(uint32_t hint) {
        uint32_t return_val = PxGetAggregateSelfCollisionBit(hint);
        return return_val;
    }

    int32_t phys_PxGetAggregateType(uint32_t hint) {
        physx::PxAggregateType::Enum return_val = PxGetAggregateType(hint);
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxAggregate_release_mut(physx_PxAggregate_Pod* self__pod) {
        physx::PxAggregate* self_ = reinterpret_cast<physx::PxAggregate*>(self__pod);
        self_->release();
    }

    bool PxAggregate_addActor_mut(physx_PxAggregate_Pod* self__pod, physx_PxActor_Pod* actor_pod, physx_PxBVH_Pod const* bvh_pod) {
        physx::PxAggregate* self_ = reinterpret_cast<physx::PxAggregate*>(self__pod);
        physx::PxActor& actor = reinterpret_cast<physx::PxActor&>(*actor_pod);
        physx::PxBVH const* bvh = reinterpret_cast<physx::PxBVH const*>(bvh_pod);
        bool return_val = self_->addActor(actor, bvh);
        return return_val;
    }

    bool PxAggregate_removeActor_mut(physx_PxAggregate_Pod* self__pod, physx_PxActor_Pod* actor_pod) {
        physx::PxAggregate* self_ = reinterpret_cast<physx::PxAggregate*>(self__pod);
        physx::PxActor& actor = reinterpret_cast<physx::PxActor&>(*actor_pod);
        bool return_val = self_->removeActor(actor);
        return return_val;
    }

    bool PxAggregate_addArticulation_mut(physx_PxAggregate_Pod* self__pod, physx_PxArticulationReducedCoordinate_Pod* articulation_pod) {
        physx::PxAggregate* self_ = reinterpret_cast<physx::PxAggregate*>(self__pod);
        physx::PxArticulationReducedCoordinate& articulation = reinterpret_cast<physx::PxArticulationReducedCoordinate&>(*articulation_pod);
        bool return_val = self_->addArticulation(articulation);
        return return_val;
    }

    bool PxAggregate_removeArticulation_mut(physx_PxAggregate_Pod* self__pod, physx_PxArticulationReducedCoordinate_Pod* articulation_pod) {
        physx::PxAggregate* self_ = reinterpret_cast<physx::PxAggregate*>(self__pod);
        physx::PxArticulationReducedCoordinate& articulation = reinterpret_cast<physx::PxArticulationReducedCoordinate&>(*articulation_pod);
        bool return_val = self_->removeArticulation(articulation);
        return return_val;
    }

    uint32_t PxAggregate_getNbActors(physx_PxAggregate_Pod const* self__pod) {
        physx::PxAggregate const* self_ = reinterpret_cast<physx::PxAggregate const*>(self__pod);
        uint32_t return_val = self_->getNbActors();
        return return_val;
    }

    uint32_t PxAggregate_getMaxNbShapes(physx_PxAggregate_Pod const* self__pod) {
        physx::PxAggregate const* self_ = reinterpret_cast<physx::PxAggregate const*>(self__pod);
        uint32_t return_val = self_->getMaxNbShapes();
        return return_val;
    }

    uint32_t PxAggregate_getActors(physx_PxAggregate_Pod const* self__pod, physx_PxActor_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxAggregate const* self_ = reinterpret_cast<physx::PxAggregate const*>(self__pod);
        physx::PxActor** userBuffer = reinterpret_cast<physx::PxActor**>(userBuffer_pod);
        uint32_t return_val = self_->getActors(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    physx_PxScene_Pod* PxAggregate_getScene_mut(physx_PxAggregate_Pod* self__pod) {
        physx::PxAggregate* self_ = reinterpret_cast<physx::PxAggregate*>(self__pod);
        physx::PxScene* return_val = self_->getScene();
        auto return_val_pod = reinterpret_cast<physx_PxScene_Pod*>(return_val);
        return return_val_pod;
    }

    bool PxAggregate_getSelfCollision(physx_PxAggregate_Pod const* self__pod) {
        physx::PxAggregate const* self_ = reinterpret_cast<physx::PxAggregate const*>(self__pod);
        bool return_val = self_->getSelfCollision();
        return return_val;
    }

    char const* PxAggregate_getConcreteTypeName(physx_PxAggregate_Pod const* self__pod) {
        physx::PxAggregate const* self_ = reinterpret_cast<physx::PxAggregate const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    physx_PxConstraintInvMassScale_Pod PxConstraintInvMassScale_new() {
        PxConstraintInvMassScale return_val;
        physx_PxConstraintInvMassScale_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxConstraintInvMassScale_Pod PxConstraintInvMassScale_new_1(float lin0, float ang0, float lin1, float ang1) {
        PxConstraintInvMassScale return_val(lin0, ang0, lin1, ang1);
        physx_PxConstraintInvMassScale_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
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
        void* return_val = self_->prepareData();
        return return_val;
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

    physx_PxBase_Pod* PxConstraintConnector_getSerializable_mut(physx_PxConstraintConnector_Pod* self__pod) {
        physx::PxConstraintConnector* self_ = reinterpret_cast<physx::PxConstraintConnector*>(self__pod);
        physx::PxBase* return_val = self_->getSerializable();
        auto return_val_pod = reinterpret_cast<physx_PxBase_Pod*>(return_val);
        return return_val_pod;
    }

    void const* PxConstraintConnector_getConstantBlock(physx_PxConstraintConnector_Pod const* self__pod) {
        physx::PxConstraintConnector const* self_ = reinterpret_cast<physx::PxConstraintConnector const*>(self__pod);
        void const* return_val = self_->getConstantBlock();
        return return_val;
    }

    void PxConstraintConnector_connectToConstraint_mut(physx_PxConstraintConnector_Pod* self__pod, physx_PxConstraint_Pod* anon_param0_pod) {
        physx::PxConstraintConnector* self_ = reinterpret_cast<physx::PxConstraintConnector*>(self__pod);
        physx::PxConstraint* anon_param0 = reinterpret_cast<physx::PxConstraint*>(anon_param0_pod);
        self_->connectToConstraint(anon_param0);
    }

    void PxConstraintConnector_delete(physx_PxConstraintConnector_Pod* self__pod) {
        physx::PxConstraintConnector* self_ = reinterpret_cast<physx::PxConstraintConnector*>(self__pod);
        delete self_;
    }

    physx_PxSolverBody_Pod PxSolverBody_new() {
        PxSolverBody return_val;
        physx_PxSolverBody_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    float PxSolverBodyData_projectVelocity(physx_PxSolverBodyData_Pod const* self__pod, physx_PxVec3_Pod const* lin_pod, physx_PxVec3_Pod const* ang_pod) {
        physx::PxSolverBodyData const* self_ = reinterpret_cast<physx::PxSolverBodyData const*>(self__pod);
        physx::PxVec3 const& lin = reinterpret_cast<physx::PxVec3 const&>(*lin_pod);
        physx::PxVec3 const& ang = reinterpret_cast<physx::PxVec3 const&>(*ang_pod);
        float return_val = self_->projectVelocity(lin, ang);
        return return_val;
    }

    void PxSolverConstraintPrepDesc_delete(physx_PxSolverConstraintPrepDesc_Pod* self__pod) {
        physx::PxSolverConstraintPrepDesc* self_ = reinterpret_cast<physx::PxSolverConstraintPrepDesc*>(self__pod);
        delete self_;
    }

    uint8_t* PxConstraintAllocator_reserveConstraintData_mut(physx_PxConstraintAllocator_Pod* self__pod, uint32_t byteSize) {
        physx::PxConstraintAllocator* self_ = reinterpret_cast<physx::PxConstraintAllocator*>(self__pod);
        uint8_t* return_val = self_->reserveConstraintData(byteSize);
        return return_val;
    }

    uint8_t* PxConstraintAllocator_reserveFrictionData_mut(physx_PxConstraintAllocator_Pod* self__pod, uint32_t byteSize) {
        physx::PxConstraintAllocator* self_ = reinterpret_cast<physx::PxConstraintAllocator*>(self__pod);
        uint8_t* return_val = self_->reserveFrictionData(byteSize);
        return return_val;
    }

    void PxConstraintAllocator_delete(physx_PxConstraintAllocator_Pod* self__pod) {
        physx::PxConstraintAllocator* self_ = reinterpret_cast<physx::PxConstraintAllocator*>(self__pod);
        delete self_;
    }

    physx_PxArticulationLimit_Pod PxArticulationLimit_new() {
        PxArticulationLimit return_val;
        physx_PxArticulationLimit_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxArticulationLimit_Pod PxArticulationLimit_new_1(float low_, float high_) {
        PxArticulationLimit return_val(low_, high_);
        physx_PxArticulationLimit_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxArticulationDrive_Pod PxArticulationDrive_new() {
        PxArticulationDrive return_val;
        physx_PxArticulationDrive_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxArticulationDrive_Pod PxArticulationDrive_new_1(float stiffness_, float damping_, float maxForce_, int32_t driveType__pod) {
        auto driveType_ = static_cast<physx::PxArticulationDriveType::Enum>(driveType__pod);
        PxArticulationDrive return_val(stiffness_, damping_, maxForce_, driveType_);
        physx_PxArticulationDrive_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    float PxTGSSolverBodyVel_projectVelocity(physx_PxTGSSolverBodyVel_Pod const* self__pod, physx_PxVec3_Pod const* lin_pod, physx_PxVec3_Pod const* ang_pod) {
        physx::PxTGSSolverBodyVel const* self_ = reinterpret_cast<physx::PxTGSSolverBodyVel const*>(self__pod);
        physx::PxVec3 const& lin = reinterpret_cast<physx::PxVec3 const&>(*lin_pod);
        physx::PxVec3 const& ang = reinterpret_cast<physx::PxVec3 const&>(*ang_pod);
        float return_val = self_->projectVelocity(lin, ang);
        return return_val;
    }

    float PxTGSSolverBodyData_projectVelocity(physx_PxTGSSolverBodyData_Pod const* self__pod, physx_PxVec3_Pod const* linear_pod, physx_PxVec3_Pod const* angular_pod) {
        physx::PxTGSSolverBodyData const* self_ = reinterpret_cast<physx::PxTGSSolverBodyData const*>(self__pod);
        physx::PxVec3 const& linear = reinterpret_cast<physx::PxVec3 const&>(*linear_pod);
        physx::PxVec3 const& angular = reinterpret_cast<physx::PxVec3 const&>(*angular_pod);
        float return_val = self_->projectVelocity(linear, angular);
        return return_val;
    }

    void PxTGSSolverConstraintPrepDesc_delete(physx_PxTGSSolverConstraintPrepDesc_Pod* self__pod) {
        physx::PxTGSSolverConstraintPrepDesc* self_ = reinterpret_cast<physx::PxTGSSolverConstraintPrepDesc*>(self__pod);
        delete self_;
    }

    void PxArticulationAttachment_setRestLength_mut(physx_PxArticulationAttachment_Pod* self__pod, float restLength) {
        physx::PxArticulationAttachment* self_ = reinterpret_cast<physx::PxArticulationAttachment*>(self__pod);
        self_->setRestLength(restLength);
    }

    float PxArticulationAttachment_getRestLength(physx_PxArticulationAttachment_Pod const* self__pod) {
        physx::PxArticulationAttachment const* self_ = reinterpret_cast<physx::PxArticulationAttachment const*>(self__pod);
        float return_val = self_->getRestLength();
        return return_val;
    }

    void PxArticulationAttachment_setLimitParameters_mut(physx_PxArticulationAttachment_Pod* self__pod, physx_PxArticulationTendonLimit_Pod const* parameters_pod) {
        physx::PxArticulationAttachment* self_ = reinterpret_cast<physx::PxArticulationAttachment*>(self__pod);
        physx::PxArticulationTendonLimit const& parameters = reinterpret_cast<physx::PxArticulationTendonLimit const&>(*parameters_pod);
        self_->setLimitParameters(parameters);
    }

    physx_PxArticulationTendonLimit_Pod PxArticulationAttachment_getLimitParameters(physx_PxArticulationAttachment_Pod const* self__pod) {
        physx::PxArticulationAttachment const* self_ = reinterpret_cast<physx::PxArticulationAttachment const*>(self__pod);
        physx::PxArticulationTendonLimit return_val = self_->getLimitParameters();
        physx_PxArticulationTendonLimit_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxArticulationAttachment_setRelativeOffset_mut(physx_PxArticulationAttachment_Pod* self__pod, physx_PxVec3_Pod const* offset_pod) {
        physx::PxArticulationAttachment* self_ = reinterpret_cast<physx::PxArticulationAttachment*>(self__pod);
        physx::PxVec3 const& offset = reinterpret_cast<physx::PxVec3 const&>(*offset_pod);
        self_->setRelativeOffset(offset);
    }

    physx_PxVec3_Pod PxArticulationAttachment_getRelativeOffset(physx_PxArticulationAttachment_Pod const* self__pod) {
        physx::PxArticulationAttachment const* self_ = reinterpret_cast<physx::PxArticulationAttachment const*>(self__pod);
        physx::PxVec3 return_val = self_->getRelativeOffset();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxArticulationAttachment_setCoefficient_mut(physx_PxArticulationAttachment_Pod* self__pod, float coefficient) {
        physx::PxArticulationAttachment* self_ = reinterpret_cast<physx::PxArticulationAttachment*>(self__pod);
        self_->setCoefficient(coefficient);
    }

    float PxArticulationAttachment_getCoefficient(physx_PxArticulationAttachment_Pod const* self__pod) {
        physx::PxArticulationAttachment const* self_ = reinterpret_cast<physx::PxArticulationAttachment const*>(self__pod);
        float return_val = self_->getCoefficient();
        return return_val;
    }

    physx_PxArticulationLink_Pod* PxArticulationAttachment_getLink(physx_PxArticulationAttachment_Pod const* self__pod) {
        physx::PxArticulationAttachment const* self_ = reinterpret_cast<physx::PxArticulationAttachment const*>(self__pod);
        physx::PxArticulationLink* return_val = self_->getLink();
        auto return_val_pod = reinterpret_cast<physx_PxArticulationLink_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxArticulationAttachment_Pod* PxArticulationAttachment_getParent(physx_PxArticulationAttachment_Pod const* self__pod) {
        physx::PxArticulationAttachment const* self_ = reinterpret_cast<physx::PxArticulationAttachment const*>(self__pod);
        physx::PxArticulationAttachment* return_val = self_->getParent();
        auto return_val_pod = reinterpret_cast<physx_PxArticulationAttachment_Pod*>(return_val);
        return return_val_pod;
    }

    bool PxArticulationAttachment_isLeaf(physx_PxArticulationAttachment_Pod const* self__pod) {
        physx::PxArticulationAttachment const* self_ = reinterpret_cast<physx::PxArticulationAttachment const*>(self__pod);
        bool return_val = self_->isLeaf();
        return return_val;
    }

    physx_PxArticulationSpatialTendon_Pod* PxArticulationAttachment_getTendon(physx_PxArticulationAttachment_Pod const* self__pod) {
        physx::PxArticulationAttachment const* self_ = reinterpret_cast<physx::PxArticulationAttachment const*>(self__pod);
        physx::PxArticulationSpatialTendon* return_val = self_->getTendon();
        auto return_val_pod = reinterpret_cast<physx_PxArticulationSpatialTendon_Pod*>(return_val);
        return return_val_pod;
    }

    void PxArticulationAttachment_release_mut(physx_PxArticulationAttachment_Pod* self__pod) {
        physx::PxArticulationAttachment* self_ = reinterpret_cast<physx::PxArticulationAttachment*>(self__pod);
        self_->release();
    }

    char const* PxArticulationAttachment_getConcreteTypeName(physx_PxArticulationAttachment_Pod const* self__pod) {
        physx::PxArticulationAttachment const* self_ = reinterpret_cast<physx::PxArticulationAttachment const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    void PxArticulationTendonJoint_setCoefficient_mut(physx_PxArticulationTendonJoint_Pod* self__pod, int32_t axis_pod, float coefficient, float recipCoefficient) {
        physx::PxArticulationTendonJoint* self_ = reinterpret_cast<physx::PxArticulationTendonJoint*>(self__pod);
        auto axis = static_cast<physx::PxArticulationAxis::Enum>(axis_pod);
        self_->setCoefficient(axis, coefficient, recipCoefficient);
    }

    void PxArticulationTendonJoint_getCoefficient(physx_PxArticulationTendonJoint_Pod const* self__pod, int32_t* axis_pod, float* coefficient_pod, float* recipCoefficient_pod) {
        physx::PxArticulationTendonJoint const* self_ = reinterpret_cast<physx::PxArticulationTendonJoint const*>(self__pod);
        physx::PxArticulationAxis::Enum& axis = reinterpret_cast<physx::PxArticulationAxis::Enum&>(*axis_pod);
        float& coefficient = *coefficient_pod;
        float& recipCoefficient = *recipCoefficient_pod;
        self_->getCoefficient(axis, coefficient, recipCoefficient);
    }

    physx_PxArticulationLink_Pod* PxArticulationTendonJoint_getLink(physx_PxArticulationTendonJoint_Pod const* self__pod) {
        physx::PxArticulationTendonJoint const* self_ = reinterpret_cast<physx::PxArticulationTendonJoint const*>(self__pod);
        physx::PxArticulationLink* return_val = self_->getLink();
        auto return_val_pod = reinterpret_cast<physx_PxArticulationLink_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxArticulationTendonJoint_Pod* PxArticulationTendonJoint_getParent(physx_PxArticulationTendonJoint_Pod const* self__pod) {
        physx::PxArticulationTendonJoint const* self_ = reinterpret_cast<physx::PxArticulationTendonJoint const*>(self__pod);
        physx::PxArticulationTendonJoint* return_val = self_->getParent();
        auto return_val_pod = reinterpret_cast<physx_PxArticulationTendonJoint_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxArticulationFixedTendon_Pod* PxArticulationTendonJoint_getTendon(physx_PxArticulationTendonJoint_Pod const* self__pod) {
        physx::PxArticulationTendonJoint const* self_ = reinterpret_cast<physx::PxArticulationTendonJoint const*>(self__pod);
        physx::PxArticulationFixedTendon* return_val = self_->getTendon();
        auto return_val_pod = reinterpret_cast<physx_PxArticulationFixedTendon_Pod*>(return_val);
        return return_val_pod;
    }

    void PxArticulationTendonJoint_release_mut(physx_PxArticulationTendonJoint_Pod* self__pod) {
        physx::PxArticulationTendonJoint* self_ = reinterpret_cast<physx::PxArticulationTendonJoint*>(self__pod);
        self_->release();
    }

    char const* PxArticulationTendonJoint_getConcreteTypeName(physx_PxArticulationTendonJoint_Pod const* self__pod) {
        physx::PxArticulationTendonJoint const* self_ = reinterpret_cast<physx::PxArticulationTendonJoint const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    void PxArticulationTendon_setStiffness_mut(physx_PxArticulationTendon_Pod* self__pod, float stiffness) {
        physx::PxArticulationTendon* self_ = reinterpret_cast<physx::PxArticulationTendon*>(self__pod);
        self_->setStiffness(stiffness);
    }

    float PxArticulationTendon_getStiffness(physx_PxArticulationTendon_Pod const* self__pod) {
        physx::PxArticulationTendon const* self_ = reinterpret_cast<physx::PxArticulationTendon const*>(self__pod);
        float return_val = self_->getStiffness();
        return return_val;
    }

    void PxArticulationTendon_setDamping_mut(physx_PxArticulationTendon_Pod* self__pod, float damping) {
        physx::PxArticulationTendon* self_ = reinterpret_cast<physx::PxArticulationTendon*>(self__pod);
        self_->setDamping(damping);
    }

    float PxArticulationTendon_getDamping(physx_PxArticulationTendon_Pod const* self__pod) {
        physx::PxArticulationTendon const* self_ = reinterpret_cast<physx::PxArticulationTendon const*>(self__pod);
        float return_val = self_->getDamping();
        return return_val;
    }

    void PxArticulationTendon_setLimitStiffness_mut(physx_PxArticulationTendon_Pod* self__pod, float stiffness) {
        physx::PxArticulationTendon* self_ = reinterpret_cast<physx::PxArticulationTendon*>(self__pod);
        self_->setLimitStiffness(stiffness);
    }

    float PxArticulationTendon_getLimitStiffness(physx_PxArticulationTendon_Pod const* self__pod) {
        physx::PxArticulationTendon const* self_ = reinterpret_cast<physx::PxArticulationTendon const*>(self__pod);
        float return_val = self_->getLimitStiffness();
        return return_val;
    }

    void PxArticulationTendon_setOffset_mut(physx_PxArticulationTendon_Pod* self__pod, float offset, bool autowake) {
        physx::PxArticulationTendon* self_ = reinterpret_cast<physx::PxArticulationTendon*>(self__pod);
        self_->setOffset(offset, autowake);
    }

    float PxArticulationTendon_getOffset(physx_PxArticulationTendon_Pod const* self__pod) {
        physx::PxArticulationTendon const* self_ = reinterpret_cast<physx::PxArticulationTendon const*>(self__pod);
        float return_val = self_->getOffset();
        return return_val;
    }

    physx_PxArticulationReducedCoordinate_Pod* PxArticulationTendon_getArticulation(physx_PxArticulationTendon_Pod const* self__pod) {
        physx::PxArticulationTendon const* self_ = reinterpret_cast<physx::PxArticulationTendon const*>(self__pod);
        physx::PxArticulationReducedCoordinate* return_val = self_->getArticulation();
        auto return_val_pod = reinterpret_cast<physx_PxArticulationReducedCoordinate_Pod*>(return_val);
        return return_val_pod;
    }

    void PxArticulationTendon_release_mut(physx_PxArticulationTendon_Pod* self__pod) {
        physx::PxArticulationTendon* self_ = reinterpret_cast<physx::PxArticulationTendon*>(self__pod);
        self_->release();
    }

    physx_PxArticulationAttachment_Pod* PxArticulationSpatialTendon_createAttachment_mut(physx_PxArticulationSpatialTendon_Pod* self__pod, physx_PxArticulationAttachment_Pod* parent_pod, float coefficient, physx_PxVec3_Pod relativeOffset_pod, physx_PxArticulationLink_Pod* link_pod) {
        physx::PxArticulationSpatialTendon* self_ = reinterpret_cast<physx::PxArticulationSpatialTendon*>(self__pod);
        physx::PxArticulationAttachment* parent = reinterpret_cast<physx::PxArticulationAttachment*>(parent_pod);
        physx::PxVec3 relativeOffset;
        memcpy(&relativeOffset, &relativeOffset_pod, sizeof(relativeOffset));
        physx::PxArticulationLink* link = reinterpret_cast<physx::PxArticulationLink*>(link_pod);
        physx::PxArticulationAttachment* return_val = self_->createAttachment(parent, coefficient, relativeOffset, link);
        auto return_val_pod = reinterpret_cast<physx_PxArticulationAttachment_Pod*>(return_val);
        return return_val_pod;
    }

    uint32_t PxArticulationSpatialTendon_getAttachments(physx_PxArticulationSpatialTendon_Pod const* self__pod, physx_PxArticulationAttachment_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxArticulationSpatialTendon const* self_ = reinterpret_cast<physx::PxArticulationSpatialTendon const*>(self__pod);
        physx::PxArticulationAttachment** userBuffer = reinterpret_cast<physx::PxArticulationAttachment**>(userBuffer_pod);
        uint32_t return_val = self_->getAttachments(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    uint32_t PxArticulationSpatialTendon_getNbAttachments(physx_PxArticulationSpatialTendon_Pod const* self__pod) {
        physx::PxArticulationSpatialTendon const* self_ = reinterpret_cast<physx::PxArticulationSpatialTendon const*>(self__pod);
        uint32_t return_val = self_->getNbAttachments();
        return return_val;
    }

    char const* PxArticulationSpatialTendon_getConcreteTypeName(physx_PxArticulationSpatialTendon_Pod const* self__pod) {
        physx::PxArticulationSpatialTendon const* self_ = reinterpret_cast<physx::PxArticulationSpatialTendon const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    physx_PxArticulationTendonJoint_Pod* PxArticulationFixedTendon_createTendonJoint_mut(physx_PxArticulationFixedTendon_Pod* self__pod, physx_PxArticulationTendonJoint_Pod* parent_pod, int32_t axis_pod, float coefficient, float recipCoefficient, physx_PxArticulationLink_Pod* link_pod) {
        physx::PxArticulationFixedTendon* self_ = reinterpret_cast<physx::PxArticulationFixedTendon*>(self__pod);
        physx::PxArticulationTendonJoint* parent = reinterpret_cast<physx::PxArticulationTendonJoint*>(parent_pod);
        auto axis = static_cast<physx::PxArticulationAxis::Enum>(axis_pod);
        physx::PxArticulationLink* link = reinterpret_cast<physx::PxArticulationLink*>(link_pod);
        physx::PxArticulationTendonJoint* return_val = self_->createTendonJoint(parent, axis, coefficient, recipCoefficient, link);
        auto return_val_pod = reinterpret_cast<physx_PxArticulationTendonJoint_Pod*>(return_val);
        return return_val_pod;
    }

    uint32_t PxArticulationFixedTendon_getTendonJoints(physx_PxArticulationFixedTendon_Pod const* self__pod, physx_PxArticulationTendonJoint_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxArticulationFixedTendon const* self_ = reinterpret_cast<physx::PxArticulationFixedTendon const*>(self__pod);
        physx::PxArticulationTendonJoint** userBuffer = reinterpret_cast<physx::PxArticulationTendonJoint**>(userBuffer_pod);
        uint32_t return_val = self_->getTendonJoints(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    uint32_t PxArticulationFixedTendon_getNbTendonJoints(physx_PxArticulationFixedTendon_Pod const* self__pod) {
        physx::PxArticulationFixedTendon const* self_ = reinterpret_cast<physx::PxArticulationFixedTendon const*>(self__pod);
        uint32_t return_val = self_->getNbTendonJoints();
        return return_val;
    }

    void PxArticulationFixedTendon_setRestLength_mut(physx_PxArticulationFixedTendon_Pod* self__pod, float restLength) {
        physx::PxArticulationFixedTendon* self_ = reinterpret_cast<physx::PxArticulationFixedTendon*>(self__pod);
        self_->setRestLength(restLength);
    }

    float PxArticulationFixedTendon_getRestLength(physx_PxArticulationFixedTendon_Pod const* self__pod) {
        physx::PxArticulationFixedTendon const* self_ = reinterpret_cast<physx::PxArticulationFixedTendon const*>(self__pod);
        float return_val = self_->getRestLength();
        return return_val;
    }

    void PxArticulationFixedTendon_setLimitParameters_mut(physx_PxArticulationFixedTendon_Pod* self__pod, physx_PxArticulationTendonLimit_Pod const* parameter_pod) {
        physx::PxArticulationFixedTendon* self_ = reinterpret_cast<physx::PxArticulationFixedTendon*>(self__pod);
        physx::PxArticulationTendonLimit const& parameter = reinterpret_cast<physx::PxArticulationTendonLimit const&>(*parameter_pod);
        self_->setLimitParameters(parameter);
    }

    physx_PxArticulationTendonLimit_Pod PxArticulationFixedTendon_getLimitParameters(physx_PxArticulationFixedTendon_Pod const* self__pod) {
        physx::PxArticulationFixedTendon const* self_ = reinterpret_cast<physx::PxArticulationFixedTendon const*>(self__pod);
        physx::PxArticulationTendonLimit return_val = self_->getLimitParameters();
        physx_PxArticulationTendonLimit_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    char const* PxArticulationFixedTendon_getConcreteTypeName(physx_PxArticulationFixedTendon_Pod const* self__pod) {
        physx::PxArticulationFixedTendon const* self_ = reinterpret_cast<physx::PxArticulationFixedTendon const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    physx_PxArticulationCache_Pod PxArticulationCache_new() {
        PxArticulationCache return_val;
        physx_PxArticulationCache_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxArticulationCache_release_mut(physx_PxArticulationCache_Pod* self__pod) {
        physx::PxArticulationCache* self_ = reinterpret_cast<physx::PxArticulationCache*>(self__pod);
        self_->release();
    }

    void PxArticulationSensor_release_mut(physx_PxArticulationSensor_Pod* self__pod) {
        physx::PxArticulationSensor* self_ = reinterpret_cast<physx::PxArticulationSensor*>(self__pod);
        self_->release();
    }

    physx_PxSpatialForce_Pod PxArticulationSensor_getForces(physx_PxArticulationSensor_Pod const* self__pod) {
        physx::PxArticulationSensor const* self_ = reinterpret_cast<physx::PxArticulationSensor const*>(self__pod);
        physx::PxSpatialForce return_val = self_->getForces();
        physx_PxSpatialForce_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxTransform_Pod PxArticulationSensor_getRelativePose(physx_PxArticulationSensor_Pod const* self__pod) {
        physx::PxArticulationSensor const* self_ = reinterpret_cast<physx::PxArticulationSensor const*>(self__pod);
        physx::PxTransform return_val = self_->getRelativePose();
        physx_PxTransform_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxArticulationSensor_setRelativePose_mut(physx_PxArticulationSensor_Pod* self__pod, physx_PxTransform_Pod const* pose_pod) {
        physx::PxArticulationSensor* self_ = reinterpret_cast<physx::PxArticulationSensor*>(self__pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        self_->setRelativePose(pose);
    }

    physx_PxArticulationLink_Pod* PxArticulationSensor_getLink(physx_PxArticulationSensor_Pod const* self__pod) {
        physx::PxArticulationSensor const* self_ = reinterpret_cast<physx::PxArticulationSensor const*>(self__pod);
        physx::PxArticulationLink* return_val = self_->getLink();
        auto return_val_pod = reinterpret_cast<physx_PxArticulationLink_Pod*>(return_val);
        return return_val_pod;
    }

    uint32_t PxArticulationSensor_getIndex(physx_PxArticulationSensor_Pod const* self__pod) {
        physx::PxArticulationSensor const* self_ = reinterpret_cast<physx::PxArticulationSensor const*>(self__pod);
        uint32_t return_val = self_->getIndex();
        return return_val;
    }

    physx_PxArticulationReducedCoordinate_Pod* PxArticulationSensor_getArticulation(physx_PxArticulationSensor_Pod const* self__pod) {
        physx::PxArticulationSensor const* self_ = reinterpret_cast<physx::PxArticulationSensor const*>(self__pod);
        physx::PxArticulationReducedCoordinate* return_val = self_->getArticulation();
        auto return_val_pod = reinterpret_cast<physx_PxArticulationReducedCoordinate_Pod*>(return_val);
        return return_val_pod;
    }

    uint8_t PxArticulationSensor_getFlags(physx_PxArticulationSensor_Pod const* self__pod) {
        physx::PxArticulationSensor const* self_ = reinterpret_cast<physx::PxArticulationSensor const*>(self__pod);
        physx::PxArticulationSensorFlags return_val = self_->getFlags();
        uint8_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxArticulationSensor_setFlag_mut(physx_PxArticulationSensor_Pod* self__pod, int32_t flag_pod, bool enabled) {
        physx::PxArticulationSensor* self_ = reinterpret_cast<physx::PxArticulationSensor*>(self__pod);
        auto flag = static_cast<physx::PxArticulationSensorFlag::Enum>(flag_pod);
        self_->setFlag(flag, enabled);
    }

    char const* PxArticulationSensor_getConcreteTypeName(physx_PxArticulationSensor_Pod const* self__pod) {
        physx::PxArticulationSensor const* self_ = reinterpret_cast<physx::PxArticulationSensor const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    physx_PxScene_Pod* PxArticulationReducedCoordinate_getScene(physx_PxArticulationReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        physx::PxScene* return_val = self_->getScene();
        auto return_val_pod = reinterpret_cast<physx_PxScene_Pod*>(return_val);
        return return_val_pod;
    }

    void PxArticulationReducedCoordinate_setSolverIterationCounts_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, uint32_t minPositionIters, uint32_t minVelocityIters) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        self_->setSolverIterationCounts(minPositionIters, minVelocityIters);
    }

    void PxArticulationReducedCoordinate_getSolverIterationCounts(physx_PxArticulationReducedCoordinate_Pod const* self__pod, uint32_t* minPositionIters_pod, uint32_t* minVelocityIters_pod) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        uint32_t& minPositionIters = *minPositionIters_pod;
        uint32_t& minVelocityIters = *minVelocityIters_pod;
        self_->getSolverIterationCounts(minPositionIters, minVelocityIters);
    }

    bool PxArticulationReducedCoordinate_isSleeping(physx_PxArticulationReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        bool return_val = self_->isSleeping();
        return return_val;
    }

    void PxArticulationReducedCoordinate_setSleepThreshold_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, float threshold) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        self_->setSleepThreshold(threshold);
    }

    float PxArticulationReducedCoordinate_getSleepThreshold(physx_PxArticulationReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        float return_val = self_->getSleepThreshold();
        return return_val;
    }

    void PxArticulationReducedCoordinate_setStabilizationThreshold_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, float threshold) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        self_->setStabilizationThreshold(threshold);
    }

    float PxArticulationReducedCoordinate_getStabilizationThreshold(physx_PxArticulationReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        float return_val = self_->getStabilizationThreshold();
        return return_val;
    }

    void PxArticulationReducedCoordinate_setWakeCounter_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, float wakeCounterValue) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        self_->setWakeCounter(wakeCounterValue);
    }

    float PxArticulationReducedCoordinate_getWakeCounter(physx_PxArticulationReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        float return_val = self_->getWakeCounter();
        return return_val;
    }

    void PxArticulationReducedCoordinate_wakeUp_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        self_->wakeUp();
    }

    void PxArticulationReducedCoordinate_putToSleep_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        self_->putToSleep();
    }

    void PxArticulationReducedCoordinate_setMaxCOMLinearVelocity_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, float maxLinearVelocity) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        self_->setMaxCOMLinearVelocity(maxLinearVelocity);
    }

    float PxArticulationReducedCoordinate_getMaxCOMLinearVelocity(physx_PxArticulationReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        float return_val = self_->getMaxCOMLinearVelocity();
        return return_val;
    }

    void PxArticulationReducedCoordinate_setMaxCOMAngularVelocity_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, float maxAngularVelocity) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        self_->setMaxCOMAngularVelocity(maxAngularVelocity);
    }

    float PxArticulationReducedCoordinate_getMaxCOMAngularVelocity(physx_PxArticulationReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        float return_val = self_->getMaxCOMAngularVelocity();
        return return_val;
    }

    physx_PxArticulationLink_Pod* PxArticulationReducedCoordinate_createLink_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, physx_PxArticulationLink_Pod* parent_pod, physx_PxTransform_Pod const* pose_pod) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        physx::PxArticulationLink* parent = reinterpret_cast<physx::PxArticulationLink*>(parent_pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        physx::PxArticulationLink* return_val = self_->createLink(parent, pose);
        auto return_val_pod = reinterpret_cast<physx_PxArticulationLink_Pod*>(return_val);
        return return_val_pod;
    }

    void PxArticulationReducedCoordinate_release_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        self_->release();
    }

    uint32_t PxArticulationReducedCoordinate_getNbLinks(physx_PxArticulationReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        uint32_t return_val = self_->getNbLinks();
        return return_val;
    }

    uint32_t PxArticulationReducedCoordinate_getLinks(physx_PxArticulationReducedCoordinate_Pod const* self__pod, physx_PxArticulationLink_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        physx::PxArticulationLink** userBuffer = reinterpret_cast<physx::PxArticulationLink**>(userBuffer_pod);
        uint32_t return_val = self_->getLinks(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    uint32_t PxArticulationReducedCoordinate_getNbShapes(physx_PxArticulationReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        uint32_t return_val = self_->getNbShapes();
        return return_val;
    }

    void PxArticulationReducedCoordinate_setName_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, char const* name) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        self_->setName(name);
    }

    char const* PxArticulationReducedCoordinate_getName(physx_PxArticulationReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        char const* return_val = self_->getName();
        return return_val;
    }

    physx_PxBounds3_Pod PxArticulationReducedCoordinate_getWorldBounds(physx_PxArticulationReducedCoordinate_Pod const* self__pod, float inflation) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        physx::PxBounds3 return_val = self_->getWorldBounds(inflation);
        physx_PxBounds3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxAggregate_Pod* PxArticulationReducedCoordinate_getAggregate(physx_PxArticulationReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        physx::PxAggregate* return_val = self_->getAggregate();
        auto return_val_pod = reinterpret_cast<physx_PxAggregate_Pod*>(return_val);
        return return_val_pod;
    }

    void PxArticulationReducedCoordinate_setArticulationFlags_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, uint8_t flags_pod) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        auto flags = physx::PxArticulationFlags(flags_pod);
        self_->setArticulationFlags(flags);
    }

    void PxArticulationReducedCoordinate_setArticulationFlag_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, int32_t flag_pod, bool value) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        auto flag = static_cast<physx::PxArticulationFlag::Enum>(flag_pod);
        self_->setArticulationFlag(flag, value);
    }

    uint8_t PxArticulationReducedCoordinate_getArticulationFlags(physx_PxArticulationReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        physx::PxArticulationFlags return_val = self_->getArticulationFlags();
        uint8_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    uint32_t PxArticulationReducedCoordinate_getDofs(physx_PxArticulationReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        uint32_t return_val = self_->getDofs();
        return return_val;
    }

    physx_PxArticulationCache_Pod* PxArticulationReducedCoordinate_createCache(physx_PxArticulationReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        physx::PxArticulationCache* return_val = self_->createCache();
        auto return_val_pod = reinterpret_cast<physx_PxArticulationCache_Pod*>(return_val);
        return return_val_pod;
    }

    uint32_t PxArticulationReducedCoordinate_getCacheDataSize(physx_PxArticulationReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        uint32_t return_val = self_->getCacheDataSize();
        return return_val;
    }

    void PxArticulationReducedCoordinate_zeroCache(physx_PxArticulationReducedCoordinate_Pod const* self__pod, physx_PxArticulationCache_Pod* cache_pod) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        physx::PxArticulationCache& cache = reinterpret_cast<physx::PxArticulationCache&>(*cache_pod);
        self_->zeroCache(cache);
    }

    void PxArticulationReducedCoordinate_applyCache_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, physx_PxArticulationCache_Pod* cache_pod, uint32_t flags_pod, bool autowake) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        physx::PxArticulationCache& cache = reinterpret_cast<physx::PxArticulationCache&>(*cache_pod);
        auto flags = physx::PxArticulationCacheFlags(flags_pod);
        self_->applyCache(cache, flags, autowake);
    }

    void PxArticulationReducedCoordinate_copyInternalStateToCache(physx_PxArticulationReducedCoordinate_Pod const* self__pod, physx_PxArticulationCache_Pod* cache_pod, uint32_t flags_pod) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        physx::PxArticulationCache& cache = reinterpret_cast<physx::PxArticulationCache&>(*cache_pod);
        auto flags = physx::PxArticulationCacheFlags(flags_pod);
        self_->copyInternalStateToCache(cache, flags);
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

    bool PxArticulationReducedCoordinate_computeLambda(physx_PxArticulationReducedCoordinate_Pod const* self__pod, physx_PxArticulationCache_Pod* cache_pod, physx_PxArticulationCache_Pod* initialState_pod, float const*const jointTorque, uint32_t maxIter) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        physx::PxArticulationCache& cache = reinterpret_cast<physx::PxArticulationCache&>(*cache_pod);
        physx::PxArticulationCache& initialState = reinterpret_cast<physx::PxArticulationCache&>(*initialState_pod);
        bool return_val = self_->computeLambda(cache, initialState, jointTorque, maxIter);
        return return_val;
    }

    void PxArticulationReducedCoordinate_computeGeneralizedMassMatrix(physx_PxArticulationReducedCoordinate_Pod const* self__pod, physx_PxArticulationCache_Pod* cache_pod) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        physx::PxArticulationCache& cache = reinterpret_cast<physx::PxArticulationCache&>(*cache_pod);
        self_->computeGeneralizedMassMatrix(cache);
    }

    void PxArticulationReducedCoordinate_addLoopJoint_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, physx_PxConstraint_Pod* joint_pod) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        physx::PxConstraint* joint = reinterpret_cast<physx::PxConstraint*>(joint_pod);
        self_->addLoopJoint(joint);
    }

    void PxArticulationReducedCoordinate_removeLoopJoint_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, physx_PxConstraint_Pod* joint_pod) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        physx::PxConstraint* joint = reinterpret_cast<physx::PxConstraint*>(joint_pod);
        self_->removeLoopJoint(joint);
    }

    uint32_t PxArticulationReducedCoordinate_getNbLoopJoints(physx_PxArticulationReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        uint32_t return_val = self_->getNbLoopJoints();
        return return_val;
    }

    uint32_t PxArticulationReducedCoordinate_getLoopJoints(physx_PxArticulationReducedCoordinate_Pod const* self__pod, physx_PxConstraint_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        physx::PxConstraint** userBuffer = reinterpret_cast<physx::PxConstraint**>(userBuffer_pod);
        uint32_t return_val = self_->getLoopJoints(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    uint32_t PxArticulationReducedCoordinate_getCoefficientMatrixSize(physx_PxArticulationReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        uint32_t return_val = self_->getCoefficientMatrixSize();
        return return_val;
    }

    void PxArticulationReducedCoordinate_setRootGlobalPose_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, physx_PxTransform_Pod const* pose_pod, bool autowake) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        self_->setRootGlobalPose(pose, autowake);
    }

    physx_PxTransform_Pod PxArticulationReducedCoordinate_getRootGlobalPose(physx_PxArticulationReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        physx::PxTransform return_val = self_->getRootGlobalPose();
        physx_PxTransform_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxArticulationReducedCoordinate_setRootLinearVelocity_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, physx_PxVec3_Pod const* linearVelocity_pod, bool autowake) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        physx::PxVec3 const& linearVelocity = reinterpret_cast<physx::PxVec3 const&>(*linearVelocity_pod);
        self_->setRootLinearVelocity(linearVelocity, autowake);
    }

    physx_PxVec3_Pod PxArticulationReducedCoordinate_getRootLinearVelocity(physx_PxArticulationReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        physx::PxVec3 return_val = self_->getRootLinearVelocity();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxArticulationReducedCoordinate_setRootAngularVelocity_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, physx_PxVec3_Pod const* angularVelocity_pod, bool autowake) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        physx::PxVec3 const& angularVelocity = reinterpret_cast<physx::PxVec3 const&>(*angularVelocity_pod);
        self_->setRootAngularVelocity(angularVelocity, autowake);
    }

    physx_PxVec3_Pod PxArticulationReducedCoordinate_getRootAngularVelocity(physx_PxArticulationReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        physx::PxVec3 return_val = self_->getRootAngularVelocity();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxSpatialVelocity_Pod PxArticulationReducedCoordinate_getLinkAcceleration_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, uint32_t linkId) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        physx::PxSpatialVelocity return_val = self_->getLinkAcceleration(linkId);
        physx_PxSpatialVelocity_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    uint32_t PxArticulationReducedCoordinate_getGpuArticulationIndex_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        uint32_t return_val = self_->getGpuArticulationIndex();
        return return_val;
    }

    physx_PxArticulationSpatialTendon_Pod* PxArticulationReducedCoordinate_createSpatialTendon_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        physx::PxArticulationSpatialTendon* return_val = self_->createSpatialTendon();
        auto return_val_pod = reinterpret_cast<physx_PxArticulationSpatialTendon_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxArticulationFixedTendon_Pod* PxArticulationReducedCoordinate_createFixedTendon_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        physx::PxArticulationFixedTendon* return_val = self_->createFixedTendon();
        auto return_val_pod = reinterpret_cast<physx_PxArticulationFixedTendon_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxArticulationSensor_Pod* PxArticulationReducedCoordinate_createSensor_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, physx_PxArticulationLink_Pod* link_pod, physx_PxTransform_Pod const* relativePose_pod) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        physx::PxArticulationLink* link = reinterpret_cast<physx::PxArticulationLink*>(link_pod);
        physx::PxTransform const& relativePose = reinterpret_cast<physx::PxTransform const&>(*relativePose_pod);
        physx::PxArticulationSensor* return_val = self_->createSensor(link, relativePose);
        auto return_val_pod = reinterpret_cast<physx_PxArticulationSensor_Pod*>(return_val);
        return return_val_pod;
    }

    uint32_t PxArticulationReducedCoordinate_getSpatialTendons(physx_PxArticulationReducedCoordinate_Pod const* self__pod, physx_PxArticulationSpatialTendon_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        physx::PxArticulationSpatialTendon** userBuffer = reinterpret_cast<physx::PxArticulationSpatialTendon**>(userBuffer_pod);
        uint32_t return_val = self_->getSpatialTendons(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    uint32_t PxArticulationReducedCoordinate_getNbSpatialTendons_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        uint32_t return_val = self_->getNbSpatialTendons();
        return return_val;
    }

    uint32_t PxArticulationReducedCoordinate_getFixedTendons(physx_PxArticulationReducedCoordinate_Pod const* self__pod, physx_PxArticulationFixedTendon_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        physx::PxArticulationFixedTendon** userBuffer = reinterpret_cast<physx::PxArticulationFixedTendon**>(userBuffer_pod);
        uint32_t return_val = self_->getFixedTendons(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    uint32_t PxArticulationReducedCoordinate_getNbFixedTendons_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        uint32_t return_val = self_->getNbFixedTendons();
        return return_val;
    }

    uint32_t PxArticulationReducedCoordinate_getSensors(physx_PxArticulationReducedCoordinate_Pod const* self__pod, physx_PxArticulationSensor_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxArticulationReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate const*>(self__pod);
        physx::PxArticulationSensor** userBuffer = reinterpret_cast<physx::PxArticulationSensor**>(userBuffer_pod);
        uint32_t return_val = self_->getSensors(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    uint32_t PxArticulationReducedCoordinate_getNbSensors_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        uint32_t return_val = self_->getNbSensors();
        return return_val;
    }

    void PxArticulationReducedCoordinate_updateKinematic_mut(physx_PxArticulationReducedCoordinate_Pod* self__pod, uint8_t flags_pod) {
        physx::PxArticulationReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationReducedCoordinate*>(self__pod);
        auto flags = physx::PxArticulationKinematicFlags(flags_pod);
        self_->updateKinematic(flags);
    }

    physx_PxArticulationLink_Pod* PxArticulationJointReducedCoordinate_getParentArticulationLink(physx_PxArticulationJointReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationJointReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate const*>(self__pod);
        physx::PxArticulationLink& return_val = self_->getParentArticulationLink();
        auto return_val_pod = reinterpret_cast<physx_PxArticulationLink_Pod*>(&return_val);
        return return_val_pod;
    }

    void PxArticulationJointReducedCoordinate_setParentPose_mut(physx_PxArticulationJointReducedCoordinate_Pod* self__pod, physx_PxTransform_Pod const* pose_pod) {
        physx::PxArticulationJointReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate*>(self__pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        self_->setParentPose(pose);
    }

    physx_PxTransform_Pod PxArticulationJointReducedCoordinate_getParentPose(physx_PxArticulationJointReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationJointReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate const*>(self__pod);
        physx::PxTransform return_val = self_->getParentPose();
        physx_PxTransform_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxArticulationLink_Pod* PxArticulationJointReducedCoordinate_getChildArticulationLink(physx_PxArticulationJointReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationJointReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate const*>(self__pod);
        physx::PxArticulationLink& return_val = self_->getChildArticulationLink();
        auto return_val_pod = reinterpret_cast<physx_PxArticulationLink_Pod*>(&return_val);
        return return_val_pod;
    }

    void PxArticulationJointReducedCoordinate_setChildPose_mut(physx_PxArticulationJointReducedCoordinate_Pod* self__pod, physx_PxTransform_Pod const* pose_pod) {
        physx::PxArticulationJointReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate*>(self__pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        self_->setChildPose(pose);
    }

    physx_PxTransform_Pod PxArticulationJointReducedCoordinate_getChildPose(physx_PxArticulationJointReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationJointReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate const*>(self__pod);
        physx::PxTransform return_val = self_->getChildPose();
        physx_PxTransform_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxArticulationJointReducedCoordinate_setJointType_mut(physx_PxArticulationJointReducedCoordinate_Pod* self__pod, int32_t jointType_pod) {
        physx::PxArticulationJointReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate*>(self__pod);
        auto jointType = static_cast<physx::PxArticulationJointType::Enum>(jointType_pod);
        self_->setJointType(jointType);
    }

    int32_t PxArticulationJointReducedCoordinate_getJointType(physx_PxArticulationJointReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationJointReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate const*>(self__pod);
        physx::PxArticulationJointType::Enum return_val = self_->getJointType();
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxArticulationJointReducedCoordinate_setMotion_mut(physx_PxArticulationJointReducedCoordinate_Pod* self__pod, int32_t axis_pod, int32_t motion_pod) {
        physx::PxArticulationJointReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate*>(self__pod);
        auto axis = static_cast<physx::PxArticulationAxis::Enum>(axis_pod);
        auto motion = static_cast<physx::PxArticulationMotion::Enum>(motion_pod);
        self_->setMotion(axis, motion);
    }

    int32_t PxArticulationJointReducedCoordinate_getMotion(physx_PxArticulationJointReducedCoordinate_Pod const* self__pod, int32_t axis_pod) {
        physx::PxArticulationJointReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate const*>(self__pod);
        auto axis = static_cast<physx::PxArticulationAxis::Enum>(axis_pod);
        physx::PxArticulationMotion::Enum return_val = self_->getMotion(axis);
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxArticulationJointReducedCoordinate_setLimitParams_mut(physx_PxArticulationJointReducedCoordinate_Pod* self__pod, int32_t axis_pod, physx_PxArticulationLimit_Pod const* limit_pod) {
        physx::PxArticulationJointReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate*>(self__pod);
        auto axis = static_cast<physx::PxArticulationAxis::Enum>(axis_pod);
        physx::PxArticulationLimit const& limit = reinterpret_cast<physx::PxArticulationLimit const&>(*limit_pod);
        self_->setLimitParams(axis, limit);
    }

    physx_PxArticulationLimit_Pod PxArticulationJointReducedCoordinate_getLimitParams(physx_PxArticulationJointReducedCoordinate_Pod const* self__pod, int32_t axis_pod) {
        physx::PxArticulationJointReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate const*>(self__pod);
        auto axis = static_cast<physx::PxArticulationAxis::Enum>(axis_pod);
        physx::PxArticulationLimit return_val = self_->getLimitParams(axis);
        physx_PxArticulationLimit_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxArticulationJointReducedCoordinate_setDriveParams_mut(physx_PxArticulationJointReducedCoordinate_Pod* self__pod, int32_t axis_pod, physx_PxArticulationDrive_Pod const* drive_pod) {
        physx::PxArticulationJointReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate*>(self__pod);
        auto axis = static_cast<physx::PxArticulationAxis::Enum>(axis_pod);
        physx::PxArticulationDrive const& drive = reinterpret_cast<physx::PxArticulationDrive const&>(*drive_pod);
        self_->setDriveParams(axis, drive);
    }

    physx_PxArticulationDrive_Pod PxArticulationJointReducedCoordinate_getDriveParams(physx_PxArticulationJointReducedCoordinate_Pod const* self__pod, int32_t axis_pod) {
        physx::PxArticulationJointReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate const*>(self__pod);
        auto axis = static_cast<physx::PxArticulationAxis::Enum>(axis_pod);
        physx::PxArticulationDrive return_val = self_->getDriveParams(axis);
        physx_PxArticulationDrive_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxArticulationJointReducedCoordinate_setDriveTarget_mut(physx_PxArticulationJointReducedCoordinate_Pod* self__pod, int32_t axis_pod, float target, bool autowake) {
        physx::PxArticulationJointReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate*>(self__pod);
        auto axis = static_cast<physx::PxArticulationAxis::Enum>(axis_pod);
        self_->setDriveTarget(axis, target, autowake);
    }

    float PxArticulationJointReducedCoordinate_getDriveTarget(physx_PxArticulationJointReducedCoordinate_Pod const* self__pod, int32_t axis_pod) {
        physx::PxArticulationJointReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate const*>(self__pod);
        auto axis = static_cast<physx::PxArticulationAxis::Enum>(axis_pod);
        float return_val = self_->getDriveTarget(axis);
        return return_val;
    }

    void PxArticulationJointReducedCoordinate_setDriveVelocity_mut(physx_PxArticulationJointReducedCoordinate_Pod* self__pod, int32_t axis_pod, float targetVel, bool autowake) {
        physx::PxArticulationJointReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate*>(self__pod);
        auto axis = static_cast<physx::PxArticulationAxis::Enum>(axis_pod);
        self_->setDriveVelocity(axis, targetVel, autowake);
    }

    float PxArticulationJointReducedCoordinate_getDriveVelocity(physx_PxArticulationJointReducedCoordinate_Pod const* self__pod, int32_t axis_pod) {
        physx::PxArticulationJointReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate const*>(self__pod);
        auto axis = static_cast<physx::PxArticulationAxis::Enum>(axis_pod);
        float return_val = self_->getDriveVelocity(axis);
        return return_val;
    }

    void PxArticulationJointReducedCoordinate_setArmature_mut(physx_PxArticulationJointReducedCoordinate_Pod* self__pod, int32_t axis_pod, float armature) {
        physx::PxArticulationJointReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate*>(self__pod);
        auto axis = static_cast<physx::PxArticulationAxis::Enum>(axis_pod);
        self_->setArmature(axis, armature);
    }

    float PxArticulationJointReducedCoordinate_getArmature(physx_PxArticulationJointReducedCoordinate_Pod const* self__pod, int32_t axis_pod) {
        physx::PxArticulationJointReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate const*>(self__pod);
        auto axis = static_cast<physx::PxArticulationAxis::Enum>(axis_pod);
        float return_val = self_->getArmature(axis);
        return return_val;
    }

    void PxArticulationJointReducedCoordinate_setFrictionCoefficient_mut(physx_PxArticulationJointReducedCoordinate_Pod* self__pod, float coefficient) {
        physx::PxArticulationJointReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate*>(self__pod);
        self_->setFrictionCoefficient(coefficient);
    }

    float PxArticulationJointReducedCoordinate_getFrictionCoefficient(physx_PxArticulationJointReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationJointReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate const*>(self__pod);
        float return_val = self_->getFrictionCoefficient();
        return return_val;
    }

    void PxArticulationJointReducedCoordinate_setMaxJointVelocity_mut(physx_PxArticulationJointReducedCoordinate_Pod* self__pod, float maxJointV) {
        physx::PxArticulationJointReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate*>(self__pod);
        self_->setMaxJointVelocity(maxJointV);
    }

    float PxArticulationJointReducedCoordinate_getMaxJointVelocity(physx_PxArticulationJointReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationJointReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate const*>(self__pod);
        float return_val = self_->getMaxJointVelocity();
        return return_val;
    }

    void PxArticulationJointReducedCoordinate_setJointPosition_mut(physx_PxArticulationJointReducedCoordinate_Pod* self__pod, int32_t axis_pod, float jointPos) {
        physx::PxArticulationJointReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate*>(self__pod);
        auto axis = static_cast<physx::PxArticulationAxis::Enum>(axis_pod);
        self_->setJointPosition(axis, jointPos);
    }

    float PxArticulationJointReducedCoordinate_getJointPosition(physx_PxArticulationJointReducedCoordinate_Pod const* self__pod, int32_t axis_pod) {
        physx::PxArticulationJointReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate const*>(self__pod);
        auto axis = static_cast<physx::PxArticulationAxis::Enum>(axis_pod);
        float return_val = self_->getJointPosition(axis);
        return return_val;
    }

    void PxArticulationJointReducedCoordinate_setJointVelocity_mut(physx_PxArticulationJointReducedCoordinate_Pod* self__pod, int32_t axis_pod, float jointVel) {
        physx::PxArticulationJointReducedCoordinate* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate*>(self__pod);
        auto axis = static_cast<physx::PxArticulationAxis::Enum>(axis_pod);
        self_->setJointVelocity(axis, jointVel);
    }

    float PxArticulationJointReducedCoordinate_getJointVelocity(physx_PxArticulationJointReducedCoordinate_Pod const* self__pod, int32_t axis_pod) {
        physx::PxArticulationJointReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate const*>(self__pod);
        auto axis = static_cast<physx::PxArticulationAxis::Enum>(axis_pod);
        float return_val = self_->getJointVelocity(axis);
        return return_val;
    }

    char const* PxArticulationJointReducedCoordinate_getConcreteTypeName(physx_PxArticulationJointReducedCoordinate_Pod const* self__pod) {
        physx::PxArticulationJointReducedCoordinate const* self_ = reinterpret_cast<physx::PxArticulationJointReducedCoordinate const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    void PxShape_release_mut(physx_PxShape_Pod* self__pod) {
        physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
        self_->release();
    }

    void PxShape_setGeometry_mut(physx_PxShape_Pod* self__pod, physx_PxGeometry_Pod const* geometry_pod) {
        physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
        physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
        self_->setGeometry(geometry);
    }

    physx_PxGeometry_Pod const* PxShape_getGeometry(physx_PxShape_Pod const* self__pod) {
        physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
        physx::PxGeometry const& return_val = self_->getGeometry();
        auto return_val_pod = reinterpret_cast<physx_PxGeometry_Pod const*>(&return_val);
        return return_val_pod;
    }

    physx_PxRigidActor_Pod* PxShape_getActor(physx_PxShape_Pod const* self__pod) {
        physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
        physx::PxRigidActor* return_val = self_->getActor();
        auto return_val_pod = reinterpret_cast<physx_PxRigidActor_Pod*>(return_val);
        return return_val_pod;
    }

    void PxShape_setLocalPose_mut(physx_PxShape_Pod* self__pod, physx_PxTransform_Pod const* pose_pod) {
        physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        self_->setLocalPose(pose);
    }

    physx_PxTransform_Pod PxShape_getLocalPose(physx_PxShape_Pod const* self__pod) {
        physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
        physx::PxTransform return_val = self_->getLocalPose();
        physx_PxTransform_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxShape_setSimulationFilterData_mut(physx_PxShape_Pod* self__pod, physx_PxFilterData_Pod const* data_pod) {
        physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
        physx::PxFilterData const& data = reinterpret_cast<physx::PxFilterData const&>(*data_pod);
        self_->setSimulationFilterData(data);
    }

    physx_PxFilterData_Pod PxShape_getSimulationFilterData(physx_PxShape_Pod const* self__pod) {
        physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
        physx::PxFilterData return_val = self_->getSimulationFilterData();
        physx_PxFilterData_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxShape_setQueryFilterData_mut(physx_PxShape_Pod* self__pod, physx_PxFilterData_Pod const* data_pod) {
        physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
        physx::PxFilterData const& data = reinterpret_cast<physx::PxFilterData const&>(*data_pod);
        self_->setQueryFilterData(data);
    }

    physx_PxFilterData_Pod PxShape_getQueryFilterData(physx_PxShape_Pod const* self__pod) {
        physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
        physx::PxFilterData return_val = self_->getQueryFilterData();
        physx_PxFilterData_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxShape_setMaterials_mut(physx_PxShape_Pod* self__pod, physx_PxMaterial_Pod* const* materials_pod, uint16_t materialCount) {
        physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
        physx::PxMaterial* const* materials = reinterpret_cast<physx::PxMaterial* const*>(materials_pod);
        self_->setMaterials(materials, materialCount);
    }

    uint16_t PxShape_getNbMaterials(physx_PxShape_Pod const* self__pod) {
        physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
        uint16_t return_val = self_->getNbMaterials();
        return return_val;
    }

    uint32_t PxShape_getMaterials(physx_PxShape_Pod const* self__pod, physx_PxMaterial_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
        physx::PxMaterial** userBuffer = reinterpret_cast<physx::PxMaterial**>(userBuffer_pod);
        uint32_t return_val = self_->getMaterials(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    physx_PxBaseMaterial_Pod* PxShape_getMaterialFromInternalFaceIndex(physx_PxShape_Pod const* self__pod, uint32_t faceIndex) {
        physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
        physx::PxBaseMaterial* return_val = self_->getMaterialFromInternalFaceIndex(faceIndex);
        auto return_val_pod = reinterpret_cast<physx_PxBaseMaterial_Pod*>(return_val);
        return return_val_pod;
    }

    void PxShape_setContactOffset_mut(physx_PxShape_Pod* self__pod, float contactOffset) {
        physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
        self_->setContactOffset(contactOffset);
    }

    float PxShape_getContactOffset(physx_PxShape_Pod const* self__pod) {
        physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
        float return_val = self_->getContactOffset();
        return return_val;
    }

    void PxShape_setRestOffset_mut(physx_PxShape_Pod* self__pod, float restOffset) {
        physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
        self_->setRestOffset(restOffset);
    }

    float PxShape_getRestOffset(physx_PxShape_Pod const* self__pod) {
        physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
        float return_val = self_->getRestOffset();
        return return_val;
    }

    void PxShape_setDensityForFluid_mut(physx_PxShape_Pod* self__pod, float densityForFluid) {
        physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
        self_->setDensityForFluid(densityForFluid);
    }

    float PxShape_getDensityForFluid(physx_PxShape_Pod const* self__pod) {
        physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
        float return_val = self_->getDensityForFluid();
        return return_val;
    }

    void PxShape_setTorsionalPatchRadius_mut(physx_PxShape_Pod* self__pod, float radius) {
        physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
        self_->setTorsionalPatchRadius(radius);
    }

    float PxShape_getTorsionalPatchRadius(physx_PxShape_Pod const* self__pod) {
        physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
        float return_val = self_->getTorsionalPatchRadius();
        return return_val;
    }

    void PxShape_setMinTorsionalPatchRadius_mut(physx_PxShape_Pod* self__pod, float radius) {
        physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
        self_->setMinTorsionalPatchRadius(radius);
    }

    float PxShape_getMinTorsionalPatchRadius(physx_PxShape_Pod const* self__pod) {
        physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
        float return_val = self_->getMinTorsionalPatchRadius();
        return return_val;
    }

    void PxShape_setFlag_mut(physx_PxShape_Pod* self__pod, int32_t flag_pod, bool value) {
        physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
        auto flag = static_cast<physx::PxShapeFlag::Enum>(flag_pod);
        self_->setFlag(flag, value);
    }

    void PxShape_setFlags_mut(physx_PxShape_Pod* self__pod, uint8_t inFlags_pod) {
        physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
        auto inFlags = physx::PxShapeFlags(inFlags_pod);
        self_->setFlags(inFlags);
    }

    uint8_t PxShape_getFlags(physx_PxShape_Pod const* self__pod) {
        physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
        physx::PxShapeFlags return_val = self_->getFlags();
        uint8_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxShape_isExclusive(physx_PxShape_Pod const* self__pod) {
        physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
        bool return_val = self_->isExclusive();
        return return_val;
    }

    void PxShape_setName_mut(physx_PxShape_Pod* self__pod, char const* name) {
        physx::PxShape* self_ = reinterpret_cast<physx::PxShape*>(self__pod);
        self_->setName(name);
    }

    char const* PxShape_getName(physx_PxShape_Pod const* self__pod) {
        physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
        char const* return_val = self_->getName();
        return return_val;
    }

    char const* PxShape_getConcreteTypeName(physx_PxShape_Pod const* self__pod) {
        physx::PxShape const* self_ = reinterpret_cast<physx::PxShape const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    void PxRigidActor_release_mut(physx_PxRigidActor_Pod* self__pod) {
        physx::PxRigidActor* self_ = reinterpret_cast<physx::PxRigidActor*>(self__pod);
        self_->release();
    }

    uint32_t PxRigidActor_getInternalActorIndex(physx_PxRigidActor_Pod const* self__pod) {
        physx::PxRigidActor const* self_ = reinterpret_cast<physx::PxRigidActor const*>(self__pod);
        uint32_t return_val = self_->getInternalActorIndex();
        return return_val;
    }

    physx_PxTransform_Pod PxRigidActor_getGlobalPose(physx_PxRigidActor_Pod const* self__pod) {
        physx::PxRigidActor const* self_ = reinterpret_cast<physx::PxRigidActor const*>(self__pod);
        physx::PxTransform return_val = self_->getGlobalPose();
        physx_PxTransform_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxRigidActor_setGlobalPose_mut(physx_PxRigidActor_Pod* self__pod, physx_PxTransform_Pod const* pose_pod, bool autowake) {
        physx::PxRigidActor* self_ = reinterpret_cast<physx::PxRigidActor*>(self__pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        self_->setGlobalPose(pose, autowake);
    }

    bool PxRigidActor_attachShape_mut(physx_PxRigidActor_Pod* self__pod, physx_PxShape_Pod* shape_pod) {
        physx::PxRigidActor* self_ = reinterpret_cast<physx::PxRigidActor*>(self__pod);
        physx::PxShape& shape = reinterpret_cast<physx::PxShape&>(*shape_pod);
        bool return_val = self_->attachShape(shape);
        return return_val;
    }

    void PxRigidActor_detachShape_mut(physx_PxRigidActor_Pod* self__pod, physx_PxShape_Pod* shape_pod, bool wakeOnLostTouch) {
        physx::PxRigidActor* self_ = reinterpret_cast<physx::PxRigidActor*>(self__pod);
        physx::PxShape& shape = reinterpret_cast<physx::PxShape&>(*shape_pod);
        self_->detachShape(shape, wakeOnLostTouch);
    }

    uint32_t PxRigidActor_getNbShapes(physx_PxRigidActor_Pod const* self__pod) {
        physx::PxRigidActor const* self_ = reinterpret_cast<physx::PxRigidActor const*>(self__pod);
        uint32_t return_val = self_->getNbShapes();
        return return_val;
    }

    uint32_t PxRigidActor_getShapes(physx_PxRigidActor_Pod const* self__pod, physx_PxShape_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxRigidActor const* self_ = reinterpret_cast<physx::PxRigidActor const*>(self__pod);
        physx::PxShape** userBuffer = reinterpret_cast<physx::PxShape**>(userBuffer_pod);
        uint32_t return_val = self_->getShapes(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    uint32_t PxRigidActor_getNbConstraints(physx_PxRigidActor_Pod const* self__pod) {
        physx::PxRigidActor const* self_ = reinterpret_cast<physx::PxRigidActor const*>(self__pod);
        uint32_t return_val = self_->getNbConstraints();
        return return_val;
    }

    uint32_t PxRigidActor_getConstraints(physx_PxRigidActor_Pod const* self__pod, physx_PxConstraint_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxRigidActor const* self_ = reinterpret_cast<physx::PxRigidActor const*>(self__pod);
        physx::PxConstraint** userBuffer = reinterpret_cast<physx::PxConstraint**>(userBuffer_pod);
        uint32_t return_val = self_->getConstraints(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    physx_PxNodeIndex_Pod PxNodeIndex_new(uint32_t id, uint32_t articLinkId) {
        PxNodeIndex return_val(id, articLinkId);
        physx_PxNodeIndex_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxNodeIndex_Pod PxNodeIndex_new_1(uint32_t id) {
        PxNodeIndex return_val(id);
        physx_PxNodeIndex_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    uint32_t PxNodeIndex_index(physx_PxNodeIndex_Pod const* self__pod) {
        physx::PxNodeIndex const* self_ = reinterpret_cast<physx::PxNodeIndex const*>(self__pod);
        uint32_t return_val = self_->index();
        return return_val;
    }

    uint32_t PxNodeIndex_articulationLinkId(physx_PxNodeIndex_Pod const* self__pod) {
        physx::PxNodeIndex const* self_ = reinterpret_cast<physx::PxNodeIndex const*>(self__pod);
        uint32_t return_val = self_->articulationLinkId();
        return return_val;
    }

    uint32_t PxNodeIndex_isArticulation(physx_PxNodeIndex_Pod const* self__pod) {
        physx::PxNodeIndex const* self_ = reinterpret_cast<physx::PxNodeIndex const*>(self__pod);
        uint32_t return_val = self_->isArticulation();
        return return_val;
    }

    bool PxNodeIndex_isStaticBody(physx_PxNodeIndex_Pod const* self__pod) {
        physx::PxNodeIndex const* self_ = reinterpret_cast<physx::PxNodeIndex const*>(self__pod);
        bool return_val = self_->isStaticBody();
        return return_val;
    }

    bool PxNodeIndex_isValid(physx_PxNodeIndex_Pod const* self__pod) {
        physx::PxNodeIndex const* self_ = reinterpret_cast<physx::PxNodeIndex const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    void PxNodeIndex_setIndices_mut(physx_PxNodeIndex_Pod* self__pod, uint32_t index, uint32_t articLinkId) {
        physx::PxNodeIndex* self_ = reinterpret_cast<physx::PxNodeIndex*>(self__pod);
        self_->setIndices(index, articLinkId);
    }

    void PxNodeIndex_setIndices_mut_1(physx_PxNodeIndex_Pod* self__pod, uint32_t index) {
        physx::PxNodeIndex* self_ = reinterpret_cast<physx::PxNodeIndex*>(self__pod);
        self_->setIndices(index);
    }

    uint64_t PxNodeIndex_getInd(physx_PxNodeIndex_Pod const* self__pod) {
        physx::PxNodeIndex const* self_ = reinterpret_cast<physx::PxNodeIndex const*>(self__pod);
        uint64_t return_val = self_->getInd();
        return return_val;
    }

    void PxRigidBody_setCMassLocalPose_mut(physx_PxRigidBody_Pod* self__pod, physx_PxTransform_Pod const* pose_pod) {
        physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        self_->setCMassLocalPose(pose);
    }

    physx_PxTransform_Pod PxRigidBody_getCMassLocalPose(physx_PxRigidBody_Pod const* self__pod) {
        physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
        physx::PxTransform return_val = self_->getCMassLocalPose();
        physx_PxTransform_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxRigidBody_setMass_mut(physx_PxRigidBody_Pod* self__pod, float mass) {
        physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
        self_->setMass(mass);
    }

    float PxRigidBody_getMass(physx_PxRigidBody_Pod const* self__pod) {
        physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
        float return_val = self_->getMass();
        return return_val;
    }

    float PxRigidBody_getInvMass(physx_PxRigidBody_Pod const* self__pod) {
        physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
        float return_val = self_->getInvMass();
        return return_val;
    }

    void PxRigidBody_setMassSpaceInertiaTensor_mut(physx_PxRigidBody_Pod* self__pod, physx_PxVec3_Pod const* m_pod) {
        physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
        physx::PxVec3 const& m = reinterpret_cast<physx::PxVec3 const&>(*m_pod);
        self_->setMassSpaceInertiaTensor(m);
    }

    physx_PxVec3_Pod PxRigidBody_getMassSpaceInertiaTensor(physx_PxRigidBody_Pod const* self__pod) {
        physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
        physx::PxVec3 return_val = self_->getMassSpaceInertiaTensor();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxRigidBody_getMassSpaceInvInertiaTensor(physx_PxRigidBody_Pod const* self__pod) {
        physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
        physx::PxVec3 return_val = self_->getMassSpaceInvInertiaTensor();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxRigidBody_setLinearDamping_mut(physx_PxRigidBody_Pod* self__pod, float linDamp) {
        physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
        self_->setLinearDamping(linDamp);
    }

    float PxRigidBody_getLinearDamping(physx_PxRigidBody_Pod const* self__pod) {
        physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
        float return_val = self_->getLinearDamping();
        return return_val;
    }

    void PxRigidBody_setAngularDamping_mut(physx_PxRigidBody_Pod* self__pod, float angDamp) {
        physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
        self_->setAngularDamping(angDamp);
    }

    float PxRigidBody_getAngularDamping(physx_PxRigidBody_Pod const* self__pod) {
        physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
        float return_val = self_->getAngularDamping();
        return return_val;
    }

    physx_PxVec3_Pod PxRigidBody_getLinearVelocity(physx_PxRigidBody_Pod const* self__pod) {
        physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
        physx::PxVec3 return_val = self_->getLinearVelocity();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxRigidBody_getAngularVelocity(physx_PxRigidBody_Pod const* self__pod) {
        physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
        physx::PxVec3 return_val = self_->getAngularVelocity();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxRigidBody_setMaxLinearVelocity_mut(physx_PxRigidBody_Pod* self__pod, float maxLinVel) {
        physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
        self_->setMaxLinearVelocity(maxLinVel);
    }

    float PxRigidBody_getMaxLinearVelocity(physx_PxRigidBody_Pod const* self__pod) {
        physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
        float return_val = self_->getMaxLinearVelocity();
        return return_val;
    }

    void PxRigidBody_setMaxAngularVelocity_mut(physx_PxRigidBody_Pod* self__pod, float maxAngVel) {
        physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
        self_->setMaxAngularVelocity(maxAngVel);
    }

    float PxRigidBody_getMaxAngularVelocity(physx_PxRigidBody_Pod const* self__pod) {
        physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
        float return_val = self_->getMaxAngularVelocity();
        return return_val;
    }

    void PxRigidBody_addForce_mut(physx_PxRigidBody_Pod* self__pod, physx_PxVec3_Pod const* force_pod, int32_t mode_pod, bool autowake) {
        physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
        physx::PxVec3 const& force = reinterpret_cast<physx::PxVec3 const&>(*force_pod);
        auto mode = static_cast<physx::PxForceMode::Enum>(mode_pod);
        self_->addForce(force, mode, autowake);
    }

    void PxRigidBody_addTorque_mut(physx_PxRigidBody_Pod* self__pod, physx_PxVec3_Pod const* torque_pod, int32_t mode_pod, bool autowake) {
        physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
        physx::PxVec3 const& torque = reinterpret_cast<physx::PxVec3 const&>(*torque_pod);
        auto mode = static_cast<physx::PxForceMode::Enum>(mode_pod);
        self_->addTorque(torque, mode, autowake);
    }

    void PxRigidBody_clearForce_mut(physx_PxRigidBody_Pod* self__pod, int32_t mode_pod) {
        physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
        auto mode = static_cast<physx::PxForceMode::Enum>(mode_pod);
        self_->clearForce(mode);
    }

    void PxRigidBody_clearTorque_mut(physx_PxRigidBody_Pod* self__pod, int32_t mode_pod) {
        physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
        auto mode = static_cast<physx::PxForceMode::Enum>(mode_pod);
        self_->clearTorque(mode);
    }

    void PxRigidBody_setForceAndTorque_mut(physx_PxRigidBody_Pod* self__pod, physx_PxVec3_Pod const* force_pod, physx_PxVec3_Pod const* torque_pod, int32_t mode_pod) {
        physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
        physx::PxVec3 const& force = reinterpret_cast<physx::PxVec3 const&>(*force_pod);
        physx::PxVec3 const& torque = reinterpret_cast<physx::PxVec3 const&>(*torque_pod);
        auto mode = static_cast<physx::PxForceMode::Enum>(mode_pod);
        self_->setForceAndTorque(force, torque, mode);
    }

    void PxRigidBody_setRigidBodyFlag_mut(physx_PxRigidBody_Pod* self__pod, int32_t flag_pod, bool value) {
        physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
        auto flag = static_cast<physx::PxRigidBodyFlag::Enum>(flag_pod);
        self_->setRigidBodyFlag(flag, value);
    }

    void PxRigidBody_setRigidBodyFlags_mut(physx_PxRigidBody_Pod* self__pod, uint16_t inFlags_pod) {
        physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
        auto inFlags = physx::PxRigidBodyFlags(inFlags_pod);
        self_->setRigidBodyFlags(inFlags);
    }

    uint16_t PxRigidBody_getRigidBodyFlags(physx_PxRigidBody_Pod const* self__pod) {
        physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
        physx::PxRigidBodyFlags return_val = self_->getRigidBodyFlags();
        uint16_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxRigidBody_setMinCCDAdvanceCoefficient_mut(physx_PxRigidBody_Pod* self__pod, float advanceCoefficient) {
        physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
        self_->setMinCCDAdvanceCoefficient(advanceCoefficient);
    }

    float PxRigidBody_getMinCCDAdvanceCoefficient(physx_PxRigidBody_Pod const* self__pod) {
        physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
        float return_val = self_->getMinCCDAdvanceCoefficient();
        return return_val;
    }

    void PxRigidBody_setMaxDepenetrationVelocity_mut(physx_PxRigidBody_Pod* self__pod, float biasClamp) {
        physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
        self_->setMaxDepenetrationVelocity(biasClamp);
    }

    float PxRigidBody_getMaxDepenetrationVelocity(physx_PxRigidBody_Pod const* self__pod) {
        physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
        float return_val = self_->getMaxDepenetrationVelocity();
        return return_val;
    }

    void PxRigidBody_setMaxContactImpulse_mut(physx_PxRigidBody_Pod* self__pod, float maxImpulse) {
        physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
        self_->setMaxContactImpulse(maxImpulse);
    }

    float PxRigidBody_getMaxContactImpulse(physx_PxRigidBody_Pod const* self__pod) {
        physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
        float return_val = self_->getMaxContactImpulse();
        return return_val;
    }

    void PxRigidBody_setContactSlopCoefficient_mut(physx_PxRigidBody_Pod* self__pod, float slopCoefficient) {
        physx::PxRigidBody* self_ = reinterpret_cast<physx::PxRigidBody*>(self__pod);
        self_->setContactSlopCoefficient(slopCoefficient);
    }

    float PxRigidBody_getContactSlopCoefficient(physx_PxRigidBody_Pod const* self__pod) {
        physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
        float return_val = self_->getContactSlopCoefficient();
        return return_val;
    }

    physx_PxNodeIndex_Pod PxRigidBody_getInternalIslandNodeIndex(physx_PxRigidBody_Pod const* self__pod) {
        physx::PxRigidBody const* self_ = reinterpret_cast<physx::PxRigidBody const*>(self__pod);
        physx::PxNodeIndex return_val = self_->getInternalIslandNodeIndex();
        physx_PxNodeIndex_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxArticulationLink_release_mut(physx_PxArticulationLink_Pod* self__pod) {
        physx::PxArticulationLink* self_ = reinterpret_cast<physx::PxArticulationLink*>(self__pod);
        self_->release();
    }

    physx_PxArticulationReducedCoordinate_Pod* PxArticulationLink_getArticulation(physx_PxArticulationLink_Pod const* self__pod) {
        physx::PxArticulationLink const* self_ = reinterpret_cast<physx::PxArticulationLink const*>(self__pod);
        physx::PxArticulationReducedCoordinate& return_val = self_->getArticulation();
        auto return_val_pod = reinterpret_cast<physx_PxArticulationReducedCoordinate_Pod*>(&return_val);
        return return_val_pod;
    }

    physx_PxArticulationJointReducedCoordinate_Pod* PxArticulationLink_getInboundJoint(physx_PxArticulationLink_Pod const* self__pod) {
        physx::PxArticulationLink const* self_ = reinterpret_cast<physx::PxArticulationLink const*>(self__pod);
        physx::PxArticulationJointReducedCoordinate* return_val = self_->getInboundJoint();
        auto return_val_pod = reinterpret_cast<physx_PxArticulationJointReducedCoordinate_Pod*>(return_val);
        return return_val_pod;
    }

    uint32_t PxArticulationLink_getInboundJointDof(physx_PxArticulationLink_Pod const* self__pod) {
        physx::PxArticulationLink const* self_ = reinterpret_cast<physx::PxArticulationLink const*>(self__pod);
        uint32_t return_val = self_->getInboundJointDof();
        return return_val;
    }

    uint32_t PxArticulationLink_getNbChildren(physx_PxArticulationLink_Pod const* self__pod) {
        physx::PxArticulationLink const* self_ = reinterpret_cast<physx::PxArticulationLink const*>(self__pod);
        uint32_t return_val = self_->getNbChildren();
        return return_val;
    }

    uint32_t PxArticulationLink_getLinkIndex(physx_PxArticulationLink_Pod const* self__pod) {
        physx::PxArticulationLink const* self_ = reinterpret_cast<physx::PxArticulationLink const*>(self__pod);
        uint32_t return_val = self_->getLinkIndex();
        return return_val;
    }

    uint32_t PxArticulationLink_getChildren(physx_PxArticulationLink_Pod const* self__pod, physx_PxArticulationLink_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxArticulationLink const* self_ = reinterpret_cast<physx::PxArticulationLink const*>(self__pod);
        physx::PxArticulationLink** userBuffer = reinterpret_cast<physx::PxArticulationLink**>(userBuffer_pod);
        uint32_t return_val = self_->getChildren(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    void PxArticulationLink_setCfmScale_mut(physx_PxArticulationLink_Pod* self__pod, float cfm) {
        physx::PxArticulationLink* self_ = reinterpret_cast<physx::PxArticulationLink*>(self__pod);
        self_->setCfmScale(cfm);
    }

    float PxArticulationLink_getCfmScale(physx_PxArticulationLink_Pod const* self__pod) {
        physx::PxArticulationLink const* self_ = reinterpret_cast<physx::PxArticulationLink const*>(self__pod);
        float return_val = self_->getCfmScale();
        return return_val;
    }

    physx_PxVec3_Pod PxArticulationLink_getLinearVelocity(physx_PxArticulationLink_Pod const* self__pod) {
        physx::PxArticulationLink const* self_ = reinterpret_cast<physx::PxArticulationLink const*>(self__pod);
        physx::PxVec3 return_val = self_->getLinearVelocity();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxArticulationLink_getAngularVelocity(physx_PxArticulationLink_Pod const* self__pod) {
        physx::PxArticulationLink const* self_ = reinterpret_cast<physx::PxArticulationLink const*>(self__pod);
        physx::PxVec3 return_val = self_->getAngularVelocity();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    char const* PxArticulationLink_getConcreteTypeName(physx_PxArticulationLink_Pod const* self__pod) {
        physx::PxArticulationLink const* self_ = reinterpret_cast<physx::PxArticulationLink const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    physx_PxConeLimitedConstraint_Pod PxConeLimitedConstraint_new() {
        PxConeLimitedConstraint return_val;
        physx_PxConeLimitedConstraint_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxConstraint_release_mut(physx_PxConstraint_Pod* self__pod) {
        physx::PxConstraint* self_ = reinterpret_cast<physx::PxConstraint*>(self__pod);
        self_->release();
    }

    physx_PxScene_Pod* PxConstraint_getScene(physx_PxConstraint_Pod const* self__pod) {
        physx::PxConstraint const* self_ = reinterpret_cast<physx::PxConstraint const*>(self__pod);
        physx::PxScene* return_val = self_->getScene();
        auto return_val_pod = reinterpret_cast<physx_PxScene_Pod*>(return_val);
        return return_val_pod;
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

    uint16_t PxConstraint_getFlags(physx_PxConstraint_Pod const* self__pod) {
        physx::PxConstraint const* self_ = reinterpret_cast<physx::PxConstraint const*>(self__pod);
        physx::PxConstraintFlags return_val = self_->getFlags();
        uint16_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxConstraint_setFlags_mut(physx_PxConstraint_Pod* self__pod, uint16_t flags_pod) {
        physx::PxConstraint* self_ = reinterpret_cast<physx::PxConstraint*>(self__pod);
        auto flags = physx::PxConstraintFlags(flags_pod);
        self_->setFlags(flags);
    }

    void PxConstraint_setFlag_mut(physx_PxConstraint_Pod* self__pod, int32_t flag_pod, bool value) {
        physx::PxConstraint* self_ = reinterpret_cast<physx::PxConstraint*>(self__pod);
        auto flag = static_cast<physx::PxConstraintFlag::Enum>(flag_pod);
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
        bool return_val = self_->isValid();
        return return_val;
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
        float return_val = self_->getMinResponseThreshold();
        return return_val;
    }

    void* PxConstraint_getExternalReference_mut(physx_PxConstraint_Pod* self__pod, uint32_t* typeID_pod) {
        physx::PxConstraint* self_ = reinterpret_cast<physx::PxConstraint*>(self__pod);
        uint32_t& typeID = *typeID_pod;
        void* return_val = self_->getExternalReference(typeID);
        return return_val;
    }

    void PxConstraint_setConstraintFunctions_mut(physx_PxConstraint_Pod* self__pod, physx_PxConstraintConnector_Pod* connector_pod, physx_PxConstraintShaderTable_Pod const* shaders_pod) {
        physx::PxConstraint* self_ = reinterpret_cast<physx::PxConstraint*>(self__pod);
        physx::PxConstraintConnector& connector = reinterpret_cast<physx::PxConstraintConnector&>(*connector_pod);
        physx::PxConstraintShaderTable const& shaders = reinterpret_cast<physx::PxConstraintShaderTable const&>(*shaders_pod);
        self_->setConstraintFunctions(connector, shaders);
    }

    char const* PxConstraint_getConcreteTypeName(physx_PxConstraint_Pod const* self__pod) {
        physx::PxConstraint const* self_ = reinterpret_cast<physx::PxConstraint const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    physx_PxContactStreamIterator_Pod PxContactStreamIterator_new(uint8_t const* contactPatches, uint8_t const* contactPoints, uint32_t const* contactFaceIndices, uint32_t nbPatches, uint32_t nbContacts) {
        PxContactStreamIterator return_val(contactPatches, contactPoints, contactFaceIndices, nbPatches, nbContacts);
        physx_PxContactStreamIterator_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxContactStreamIterator_hasNextPatch(physx_PxContactStreamIterator_Pod const* self__pod) {
        physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
        bool return_val = self_->hasNextPatch();
        return return_val;
    }

    uint32_t PxContactStreamIterator_getTotalContactCount(physx_PxContactStreamIterator_Pod const* self__pod) {
        physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
        uint32_t return_val = self_->getTotalContactCount();
        return return_val;
    }

    uint32_t PxContactStreamIterator_getTotalPatchCount(physx_PxContactStreamIterator_Pod const* self__pod) {
        physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
        uint32_t return_val = self_->getTotalPatchCount();
        return return_val;
    }

    void PxContactStreamIterator_nextPatch_mut(physx_PxContactStreamIterator_Pod* self__pod) {
        physx::PxContactStreamIterator* self_ = reinterpret_cast<physx::PxContactStreamIterator*>(self__pod);
        self_->nextPatch();
    }

    bool PxContactStreamIterator_hasNextContact(physx_PxContactStreamIterator_Pod const* self__pod) {
        physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
        bool return_val = self_->hasNextContact();
        return return_val;
    }

    void PxContactStreamIterator_nextContact_mut(physx_PxContactStreamIterator_Pod* self__pod) {
        physx::PxContactStreamIterator* self_ = reinterpret_cast<physx::PxContactStreamIterator*>(self__pod);
        self_->nextContact();
    }

    physx_PxVec3_Pod const* PxContactStreamIterator_getContactNormal(physx_PxContactStreamIterator_Pod const* self__pod) {
        physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
        physx::PxVec3 const& return_val = self_->getContactNormal();
        auto return_val_pod = reinterpret_cast<physx_PxVec3_Pod const*>(&return_val);
        return return_val_pod;
    }

    float PxContactStreamIterator_getInvMassScale0(physx_PxContactStreamIterator_Pod const* self__pod) {
        physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
        float return_val = self_->getInvMassScale0();
        return return_val;
    }

    float PxContactStreamIterator_getInvMassScale1(physx_PxContactStreamIterator_Pod const* self__pod) {
        physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
        float return_val = self_->getInvMassScale1();
        return return_val;
    }

    float PxContactStreamIterator_getInvInertiaScale0(physx_PxContactStreamIterator_Pod const* self__pod) {
        physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
        float return_val = self_->getInvInertiaScale0();
        return return_val;
    }

    float PxContactStreamIterator_getInvInertiaScale1(physx_PxContactStreamIterator_Pod const* self__pod) {
        physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
        float return_val = self_->getInvInertiaScale1();
        return return_val;
    }

    float PxContactStreamIterator_getMaxImpulse(physx_PxContactStreamIterator_Pod const* self__pod) {
        physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
        float return_val = self_->getMaxImpulse();
        return return_val;
    }

    physx_PxVec3_Pod const* PxContactStreamIterator_getTargetVel(physx_PxContactStreamIterator_Pod const* self__pod) {
        physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
        physx::PxVec3 const& return_val = self_->getTargetVel();
        auto return_val_pod = reinterpret_cast<physx_PxVec3_Pod const*>(&return_val);
        return return_val_pod;
    }

    physx_PxVec3_Pod const* PxContactStreamIterator_getContactPoint(physx_PxContactStreamIterator_Pod const* self__pod) {
        physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
        physx::PxVec3 const& return_val = self_->getContactPoint();
        auto return_val_pod = reinterpret_cast<physx_PxVec3_Pod const*>(&return_val);
        return return_val_pod;
    }

    float PxContactStreamIterator_getSeparation(physx_PxContactStreamIterator_Pod const* self__pod) {
        physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
        float return_val = self_->getSeparation();
        return return_val;
    }

    uint32_t PxContactStreamIterator_getFaceIndex0(physx_PxContactStreamIterator_Pod const* self__pod) {
        physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
        uint32_t return_val = self_->getFaceIndex0();
        return return_val;
    }

    uint32_t PxContactStreamIterator_getFaceIndex1(physx_PxContactStreamIterator_Pod const* self__pod) {
        physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
        uint32_t return_val = self_->getFaceIndex1();
        return return_val;
    }

    float PxContactStreamIterator_getStaticFriction(physx_PxContactStreamIterator_Pod const* self__pod) {
        physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
        float return_val = self_->getStaticFriction();
        return return_val;
    }

    float PxContactStreamIterator_getDynamicFriction(physx_PxContactStreamIterator_Pod const* self__pod) {
        physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
        float return_val = self_->getDynamicFriction();
        return return_val;
    }

    float PxContactStreamIterator_getRestitution(physx_PxContactStreamIterator_Pod const* self__pod) {
        physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
        float return_val = self_->getRestitution();
        return return_val;
    }

    float PxContactStreamIterator_getDamping(physx_PxContactStreamIterator_Pod const* self__pod) {
        physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
        float return_val = self_->getDamping();
        return return_val;
    }

    uint32_t PxContactStreamIterator_getMaterialFlags(physx_PxContactStreamIterator_Pod const* self__pod) {
        physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
        uint32_t return_val = self_->getMaterialFlags();
        return return_val;
    }

    uint16_t PxContactStreamIterator_getMaterialIndex0(physx_PxContactStreamIterator_Pod const* self__pod) {
        physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
        uint16_t return_val = self_->getMaterialIndex0();
        return return_val;
    }

    uint16_t PxContactStreamIterator_getMaterialIndex1(physx_PxContactStreamIterator_Pod const* self__pod) {
        physx::PxContactStreamIterator const* self_ = reinterpret_cast<physx::PxContactStreamIterator const*>(self__pod);
        uint16_t return_val = self_->getMaterialIndex1();
        return return_val;
    }

    bool PxContactStreamIterator_advanceToIndex_mut(physx_PxContactStreamIterator_Pod* self__pod, uint32_t initialIndex) {
        physx::PxContactStreamIterator* self_ = reinterpret_cast<physx::PxContactStreamIterator*>(self__pod);
        bool return_val = self_->advanceToIndex(initialIndex);
        return return_val;
    }

    physx_PxVec3_Pod const* PxContactSet_getPoint(physx_PxContactSet_Pod const* self__pod, uint32_t i) {
        physx::PxContactSet const* self_ = reinterpret_cast<physx::PxContactSet const*>(self__pod);
        physx::PxVec3 const& return_val = self_->getPoint(i);
        auto return_val_pod = reinterpret_cast<physx_PxVec3_Pod const*>(&return_val);
        return return_val_pod;
    }

    void PxContactSet_setPoint_mut(physx_PxContactSet_Pod* self__pod, uint32_t i, physx_PxVec3_Pod const* p_pod) {
        physx::PxContactSet* self_ = reinterpret_cast<physx::PxContactSet*>(self__pod);
        physx::PxVec3 const& p = reinterpret_cast<physx::PxVec3 const&>(*p_pod);
        self_->setPoint(i, p);
    }

    physx_PxVec3_Pod const* PxContactSet_getNormal(physx_PxContactSet_Pod const* self__pod, uint32_t i) {
        physx::PxContactSet const* self_ = reinterpret_cast<physx::PxContactSet const*>(self__pod);
        physx::PxVec3 const& return_val = self_->getNormal(i);
        auto return_val_pod = reinterpret_cast<physx_PxVec3_Pod const*>(&return_val);
        return return_val_pod;
    }

    void PxContactSet_setNormal_mut(physx_PxContactSet_Pod* self__pod, uint32_t i, physx_PxVec3_Pod const* n_pod) {
        physx::PxContactSet* self_ = reinterpret_cast<physx::PxContactSet*>(self__pod);
        physx::PxVec3 const& n = reinterpret_cast<physx::PxVec3 const&>(*n_pod);
        self_->setNormal(i, n);
    }

    float PxContactSet_getSeparation(physx_PxContactSet_Pod const* self__pod, uint32_t i) {
        physx::PxContactSet const* self_ = reinterpret_cast<physx::PxContactSet const*>(self__pod);
        float return_val = self_->getSeparation(i);
        return return_val;
    }

    void PxContactSet_setSeparation_mut(physx_PxContactSet_Pod* self__pod, uint32_t i, float s) {
        physx::PxContactSet* self_ = reinterpret_cast<physx::PxContactSet*>(self__pod);
        self_->setSeparation(i, s);
    }

    physx_PxVec3_Pod const* PxContactSet_getTargetVelocity(physx_PxContactSet_Pod const* self__pod, uint32_t i) {
        physx::PxContactSet const* self_ = reinterpret_cast<physx::PxContactSet const*>(self__pod);
        physx::PxVec3 const& return_val = self_->getTargetVelocity(i);
        auto return_val_pod = reinterpret_cast<physx_PxVec3_Pod const*>(&return_val);
        return return_val_pod;
    }

    void PxContactSet_setTargetVelocity_mut(physx_PxContactSet_Pod* self__pod, uint32_t i, physx_PxVec3_Pod const* v_pod) {
        physx::PxContactSet* self_ = reinterpret_cast<physx::PxContactSet*>(self__pod);
        physx::PxVec3 const& v = reinterpret_cast<physx::PxVec3 const&>(*v_pod);
        self_->setTargetVelocity(i, v);
    }

    uint32_t PxContactSet_getInternalFaceIndex0(physx_PxContactSet_Pod const* self__pod, uint32_t i) {
        physx::PxContactSet const* self_ = reinterpret_cast<physx::PxContactSet const*>(self__pod);
        uint32_t return_val = self_->getInternalFaceIndex0(i);
        return return_val;
    }

    uint32_t PxContactSet_getInternalFaceIndex1(physx_PxContactSet_Pod const* self__pod, uint32_t i) {
        physx::PxContactSet const* self_ = reinterpret_cast<physx::PxContactSet const*>(self__pod);
        uint32_t return_val = self_->getInternalFaceIndex1(i);
        return return_val;
    }

    float PxContactSet_getMaxImpulse(physx_PxContactSet_Pod const* self__pod, uint32_t i) {
        physx::PxContactSet const* self_ = reinterpret_cast<physx::PxContactSet const*>(self__pod);
        float return_val = self_->getMaxImpulse(i);
        return return_val;
    }

    void PxContactSet_setMaxImpulse_mut(physx_PxContactSet_Pod* self__pod, uint32_t i, float s) {
        physx::PxContactSet* self_ = reinterpret_cast<physx::PxContactSet*>(self__pod);
        self_->setMaxImpulse(i, s);
    }

    float PxContactSet_getRestitution(physx_PxContactSet_Pod const* self__pod, uint32_t i) {
        physx::PxContactSet const* self_ = reinterpret_cast<physx::PxContactSet const*>(self__pod);
        float return_val = self_->getRestitution(i);
        return return_val;
    }

    void PxContactSet_setRestitution_mut(physx_PxContactSet_Pod* self__pod, uint32_t i, float r) {
        physx::PxContactSet* self_ = reinterpret_cast<physx::PxContactSet*>(self__pod);
        self_->setRestitution(i, r);
    }

    float PxContactSet_getStaticFriction(physx_PxContactSet_Pod const* self__pod, uint32_t i) {
        physx::PxContactSet const* self_ = reinterpret_cast<physx::PxContactSet const*>(self__pod);
        float return_val = self_->getStaticFriction(i);
        return return_val;
    }

    void PxContactSet_setStaticFriction_mut(physx_PxContactSet_Pod* self__pod, uint32_t i, float f) {
        physx::PxContactSet* self_ = reinterpret_cast<physx::PxContactSet*>(self__pod);
        self_->setStaticFriction(i, f);
    }

    float PxContactSet_getDynamicFriction(physx_PxContactSet_Pod const* self__pod, uint32_t i) {
        physx::PxContactSet const* self_ = reinterpret_cast<physx::PxContactSet const*>(self__pod);
        float return_val = self_->getDynamicFriction(i);
        return return_val;
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
        uint32_t return_val = self_->size();
        return return_val;
    }

    float PxContactSet_getInvMassScale0(physx_PxContactSet_Pod const* self__pod) {
        physx::PxContactSet const* self_ = reinterpret_cast<physx::PxContactSet const*>(self__pod);
        float return_val = self_->getInvMassScale0();
        return return_val;
    }

    float PxContactSet_getInvMassScale1(physx_PxContactSet_Pod const* self__pod) {
        physx::PxContactSet const* self_ = reinterpret_cast<physx::PxContactSet const*>(self__pod);
        float return_val = self_->getInvMassScale1();
        return return_val;
    }

    float PxContactSet_getInvInertiaScale0(physx_PxContactSet_Pod const* self__pod) {
        physx::PxContactSet const* self_ = reinterpret_cast<physx::PxContactSet const*>(self__pod);
        float return_val = self_->getInvInertiaScale0();
        return return_val;
    }

    float PxContactSet_getInvInertiaScale1(physx_PxContactSet_Pod const* self__pod) {
        physx::PxContactSet const* self_ = reinterpret_cast<physx::PxContactSet const*>(self__pod);
        float return_val = self_->getInvInertiaScale1();
        return return_val;
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

    void PxContactModifyCallback_onContactModify_mut(physx_PxContactModifyCallback_Pod* self__pod, physx_PxContactModifyPair_Pod*const pairs_pod, uint32_t count) {
        physx::PxContactModifyCallback* self_ = reinterpret_cast<physx::PxContactModifyCallback*>(self__pod);
        physx::PxContactModifyPair*const pairs = reinterpret_cast<physx::PxContactModifyPair*const>(pairs_pod);
        self_->onContactModify(pairs, count);
    }

    void PxCCDContactModifyCallback_onCCDContactModify_mut(physx_PxCCDContactModifyCallback_Pod* self__pod, physx_PxContactModifyPair_Pod*const pairs_pod, uint32_t count) {
        physx::PxCCDContactModifyCallback* self_ = reinterpret_cast<physx::PxCCDContactModifyCallback*>(self__pod);
        physx::PxContactModifyPair*const pairs = reinterpret_cast<physx::PxContactModifyPair*const>(pairs_pod);
        self_->onCCDContactModify(pairs, count);
    }

    void PxDeletionListener_onRelease_mut(physx_PxDeletionListener_Pod* self__pod, physx_PxBase_Pod const* observed_pod, void* userData, int32_t deletionEvent_pod) {
        physx::PxDeletionListener* self_ = reinterpret_cast<physx::PxDeletionListener*>(self__pod);
        physx::PxBase const* observed = reinterpret_cast<physx::PxBase const*>(observed_pod);
        auto deletionEvent = static_cast<physx::PxDeletionEventFlag::Enum>(deletionEvent_pod);
        self_->onRelease(observed, userData, deletionEvent);
    }

    bool PxBaseMaterial_isKindOf(physx_PxBaseMaterial_Pod const* self__pod, char const* name) {
        physx::PxBaseMaterial const* self_ = reinterpret_cast<physx::PxBaseMaterial const*>(self__pod);
        bool return_val = self_->isKindOf(name);
        return return_val;
    }

    void PxFEMMaterial_setYoungsModulus_mut(physx_PxFEMMaterial_Pod* self__pod, float young) {
        physx::PxFEMMaterial* self_ = reinterpret_cast<physx::PxFEMMaterial*>(self__pod);
        self_->setYoungsModulus(young);
    }

    float PxFEMMaterial_getYoungsModulus(physx_PxFEMMaterial_Pod const* self__pod) {
        physx::PxFEMMaterial const* self_ = reinterpret_cast<physx::PxFEMMaterial const*>(self__pod);
        float return_val = self_->getYoungsModulus();
        return return_val;
    }

    void PxFEMMaterial_setPoissons_mut(physx_PxFEMMaterial_Pod* self__pod, float poisson) {
        physx::PxFEMMaterial* self_ = reinterpret_cast<physx::PxFEMMaterial*>(self__pod);
        self_->setPoissons(poisson);
    }

    float PxFEMMaterial_getPoissons(physx_PxFEMMaterial_Pod const* self__pod) {
        physx::PxFEMMaterial const* self_ = reinterpret_cast<physx::PxFEMMaterial const*>(self__pod);
        float return_val = self_->getPoissons();
        return return_val;
    }

    void PxFEMMaterial_setDynamicFriction_mut(physx_PxFEMMaterial_Pod* self__pod, float dynamicFriction) {
        physx::PxFEMMaterial* self_ = reinterpret_cast<physx::PxFEMMaterial*>(self__pod);
        self_->setDynamicFriction(dynamicFriction);
    }

    float PxFEMMaterial_getDynamicFriction(physx_PxFEMMaterial_Pod const* self__pod) {
        physx::PxFEMMaterial const* self_ = reinterpret_cast<physx::PxFEMMaterial const*>(self__pod);
        float return_val = self_->getDynamicFriction();
        return return_val;
    }

    physx_PxFilterData_Pod PxFilterData_new(int32_t anon_param0_pod) {
        auto anon_param0 = static_cast<physx::PxEMPTY>(anon_param0_pod);
        PxFilterData return_val(anon_param0);
        physx_PxFilterData_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxFilterData_Pod PxFilterData_new_1() {
        PxFilterData return_val;
        physx_PxFilterData_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxFilterData_Pod PxFilterData_new_2(uint32_t w0, uint32_t w1, uint32_t w2, uint32_t w3) {
        PxFilterData return_val(w0, w1, w2, w3);
        physx_PxFilterData_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxFilterData_setToDefault_mut(physx_PxFilterData_Pod* self__pod) {
        physx::PxFilterData* self_ = reinterpret_cast<physx::PxFilterData*>(self__pod);
        self_->setToDefault();
    }

    int32_t phys_PxGetFilterObjectType(uint32_t attr) {
        physx::PxFilterObjectType::Enum return_val = PxGetFilterObjectType(attr);
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool phys_PxFilterObjectIsKinematic(uint32_t attr) {
        bool return_val = PxFilterObjectIsKinematic(attr);
        return return_val;
    }

    bool phys_PxFilterObjectIsTrigger(uint32_t attr) {
        bool return_val = PxFilterObjectIsTrigger(attr);
        return return_val;
    }

    uint16_t PxSimulationFilterCallback_pairFound_mut(physx_PxSimulationFilterCallback_Pod* self__pod, uint32_t pairID, uint32_t attributes0, physx_PxFilterData_Pod filterData0_pod, physx_PxActor_Pod const* a0_pod, physx_PxShape_Pod const* s0_pod, uint32_t attributes1, physx_PxFilterData_Pod filterData1_pod, physx_PxActor_Pod const* a1_pod, physx_PxShape_Pod const* s1_pod, uint16_t* pairFlags_pod) {
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
        physx::PxFilterFlags return_val = self_->pairFound(pairID, attributes0, filterData0, a0, s0, attributes1, filterData1, a1, s1, pairFlags);
        uint16_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxSimulationFilterCallback_pairLost_mut(physx_PxSimulationFilterCallback_Pod* self__pod, uint32_t pairID, uint32_t attributes0, physx_PxFilterData_Pod filterData0_pod, uint32_t attributes1, physx_PxFilterData_Pod filterData1_pod, bool objectRemoved) {
        physx::PxSimulationFilterCallback* self_ = reinterpret_cast<physx::PxSimulationFilterCallback*>(self__pod);
        physx::PxFilterData filterData0;
        memcpy(&filterData0, &filterData0_pod, sizeof(filterData0));
        physx::PxFilterData filterData1;
        memcpy(&filterData1, &filterData1_pod, sizeof(filterData1));
        self_->pairLost(pairID, attributes0, filterData0, attributes1, filterData1, objectRemoved);
    }

    bool PxSimulationFilterCallback_statusChange_mut(physx_PxSimulationFilterCallback_Pod* self__pod, uint32_t* pairID_pod, uint16_t* pairFlags_pod, uint16_t* filterFlags_pod) {
        physx::PxSimulationFilterCallback* self_ = reinterpret_cast<physx::PxSimulationFilterCallback*>(self__pod);
        uint32_t& pairID = *pairID_pod;
        physx::PxPairFlags& pairFlags = reinterpret_cast<physx::PxPairFlags&>(*pairFlags_pod);
        physx::PxFilterFlags& filterFlags = reinterpret_cast<physx::PxFilterFlags&>(*filterFlags_pod);
        bool return_val = self_->statusChange(pairID, pairFlags, filterFlags);
        return return_val;
    }

    uint8_t PxLockedData_getDataAccessFlags_mut(physx_PxLockedData_Pod* self__pod) {
        physx::PxLockedData* self_ = reinterpret_cast<physx::PxLockedData*>(self__pod);
        physx::PxDataAccessFlags return_val = self_->getDataAccessFlags();
        uint8_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxLockedData_unlock_mut(physx_PxLockedData_Pod* self__pod) {
        physx::PxLockedData* self_ = reinterpret_cast<physx::PxLockedData*>(self__pod);
        self_->unlock();
    }

    void PxLockedData_delete(physx_PxLockedData_Pod* self__pod) {
        physx::PxLockedData* self_ = reinterpret_cast<physx::PxLockedData*>(self__pod);
        delete self_;
    }

    void PxMaterial_setDynamicFriction_mut(physx_PxMaterial_Pod* self__pod, float coef) {
        physx::PxMaterial* self_ = reinterpret_cast<physx::PxMaterial*>(self__pod);
        self_->setDynamicFriction(coef);
    }

    float PxMaterial_getDynamicFriction(physx_PxMaterial_Pod const* self__pod) {
        physx::PxMaterial const* self_ = reinterpret_cast<physx::PxMaterial const*>(self__pod);
        float return_val = self_->getDynamicFriction();
        return return_val;
    }

    void PxMaterial_setStaticFriction_mut(physx_PxMaterial_Pod* self__pod, float coef) {
        physx::PxMaterial* self_ = reinterpret_cast<physx::PxMaterial*>(self__pod);
        self_->setStaticFriction(coef);
    }

    float PxMaterial_getStaticFriction(physx_PxMaterial_Pod const* self__pod) {
        physx::PxMaterial const* self_ = reinterpret_cast<physx::PxMaterial const*>(self__pod);
        float return_val = self_->getStaticFriction();
        return return_val;
    }

    void PxMaterial_setRestitution_mut(physx_PxMaterial_Pod* self__pod, float rest) {
        physx::PxMaterial* self_ = reinterpret_cast<physx::PxMaterial*>(self__pod);
        self_->setRestitution(rest);
    }

    float PxMaterial_getRestitution(physx_PxMaterial_Pod const* self__pod) {
        physx::PxMaterial const* self_ = reinterpret_cast<physx::PxMaterial const*>(self__pod);
        float return_val = self_->getRestitution();
        return return_val;
    }

    void PxMaterial_setDamping_mut(physx_PxMaterial_Pod* self__pod, float damping) {
        physx::PxMaterial* self_ = reinterpret_cast<physx::PxMaterial*>(self__pod);
        self_->setDamping(damping);
    }

    float PxMaterial_getDamping(physx_PxMaterial_Pod const* self__pod) {
        physx::PxMaterial const* self_ = reinterpret_cast<physx::PxMaterial const*>(self__pod);
        float return_val = self_->getDamping();
        return return_val;
    }

    void PxMaterial_setFlag_mut(physx_PxMaterial_Pod* self__pod, int32_t flag_pod, bool b) {
        physx::PxMaterial* self_ = reinterpret_cast<physx::PxMaterial*>(self__pod);
        auto flag = static_cast<physx::PxMaterialFlag::Enum>(flag_pod);
        self_->setFlag(flag, b);
    }

    void PxMaterial_setFlags_mut(physx_PxMaterial_Pod* self__pod, uint16_t flags_pod) {
        physx::PxMaterial* self_ = reinterpret_cast<physx::PxMaterial*>(self__pod);
        auto flags = physx::PxMaterialFlags(flags_pod);
        self_->setFlags(flags);
    }

    uint16_t PxMaterial_getFlags(physx_PxMaterial_Pod const* self__pod) {
        physx::PxMaterial const* self_ = reinterpret_cast<physx::PxMaterial const*>(self__pod);
        physx::PxMaterialFlags return_val = self_->getFlags();
        uint16_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxMaterial_setFrictionCombineMode_mut(physx_PxMaterial_Pod* self__pod, int32_t combMode_pod) {
        physx::PxMaterial* self_ = reinterpret_cast<physx::PxMaterial*>(self__pod);
        auto combMode = static_cast<physx::PxCombineMode::Enum>(combMode_pod);
        self_->setFrictionCombineMode(combMode);
    }

    int32_t PxMaterial_getFrictionCombineMode(physx_PxMaterial_Pod const* self__pod) {
        physx::PxMaterial const* self_ = reinterpret_cast<physx::PxMaterial const*>(self__pod);
        physx::PxCombineMode::Enum return_val = self_->getFrictionCombineMode();
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxMaterial_setRestitutionCombineMode_mut(physx_PxMaterial_Pod* self__pod, int32_t combMode_pod) {
        physx::PxMaterial* self_ = reinterpret_cast<physx::PxMaterial*>(self__pod);
        auto combMode = static_cast<physx::PxCombineMode::Enum>(combMode_pod);
        self_->setRestitutionCombineMode(combMode);
    }

    int32_t PxMaterial_getRestitutionCombineMode(physx_PxMaterial_Pod const* self__pod) {
        physx::PxMaterial const* self_ = reinterpret_cast<physx::PxMaterial const*>(self__pod);
        physx::PxCombineMode::Enum return_val = self_->getRestitutionCombineMode();
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    char const* PxMaterial_getConcreteTypeName(physx_PxMaterial_Pod const* self__pod) {
        physx::PxMaterial const* self_ = reinterpret_cast<physx::PxMaterial const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    physx_PxDiffuseParticleParams_Pod PxDiffuseParticleParams_new() {
        PxDiffuseParticleParams return_val;
        physx_PxDiffuseParticleParams_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxDiffuseParticleParams_setToDefault_mut(physx_PxDiffuseParticleParams_Pod* self__pod) {
        physx::PxDiffuseParticleParams* self_ = reinterpret_cast<physx::PxDiffuseParticleParams*>(self__pod);
        self_->setToDefault();
    }

    void PxParticleMaterial_setFriction_mut(physx_PxParticleMaterial_Pod* self__pod, float friction) {
        physx::PxParticleMaterial* self_ = reinterpret_cast<physx::PxParticleMaterial*>(self__pod);
        self_->setFriction(friction);
    }

    float PxParticleMaterial_getFriction(physx_PxParticleMaterial_Pod const* self__pod) {
        physx::PxParticleMaterial const* self_ = reinterpret_cast<physx::PxParticleMaterial const*>(self__pod);
        float return_val = self_->getFriction();
        return return_val;
    }

    void PxParticleMaterial_setDamping_mut(physx_PxParticleMaterial_Pod* self__pod, float damping) {
        physx::PxParticleMaterial* self_ = reinterpret_cast<physx::PxParticleMaterial*>(self__pod);
        self_->setDamping(damping);
    }

    float PxParticleMaterial_getDamping(physx_PxParticleMaterial_Pod const* self__pod) {
        physx::PxParticleMaterial const* self_ = reinterpret_cast<physx::PxParticleMaterial const*>(self__pod);
        float return_val = self_->getDamping();
        return return_val;
    }

    void PxParticleMaterial_setAdhesion_mut(physx_PxParticleMaterial_Pod* self__pod, float adhesion) {
        physx::PxParticleMaterial* self_ = reinterpret_cast<physx::PxParticleMaterial*>(self__pod);
        self_->setAdhesion(adhesion);
    }

    float PxParticleMaterial_getAdhesion(physx_PxParticleMaterial_Pod const* self__pod) {
        physx::PxParticleMaterial const* self_ = reinterpret_cast<physx::PxParticleMaterial const*>(self__pod);
        float return_val = self_->getAdhesion();
        return return_val;
    }

    void PxParticleMaterial_setGravityScale_mut(physx_PxParticleMaterial_Pod* self__pod, float scale) {
        physx::PxParticleMaterial* self_ = reinterpret_cast<physx::PxParticleMaterial*>(self__pod);
        self_->setGravityScale(scale);
    }

    float PxParticleMaterial_getGravityScale(physx_PxParticleMaterial_Pod const* self__pod) {
        physx::PxParticleMaterial const* self_ = reinterpret_cast<physx::PxParticleMaterial const*>(self__pod);
        float return_val = self_->getGravityScale();
        return return_val;
    }

    void PxParticleMaterial_setAdhesionRadiusScale_mut(physx_PxParticleMaterial_Pod* self__pod, float scale) {
        physx::PxParticleMaterial* self_ = reinterpret_cast<physx::PxParticleMaterial*>(self__pod);
        self_->setAdhesionRadiusScale(scale);
    }

    float PxParticleMaterial_getAdhesionRadiusScale(physx_PxParticleMaterial_Pod const* self__pod) {
        physx::PxParticleMaterial const* self_ = reinterpret_cast<physx::PxParticleMaterial const*>(self__pod);
        float return_val = self_->getAdhesionRadiusScale();
        return return_val;
    }

    void PxPhysics_release_mut(physx_PxPhysics_Pod* self__pod) {
        physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
        self_->release();
    }

    physx_PxFoundation_Pod* PxPhysics_getFoundation_mut(physx_PxPhysics_Pod* self__pod) {
        physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
        physx::PxFoundation& return_val = self_->getFoundation();
        auto return_val_pod = reinterpret_cast<physx_PxFoundation_Pod*>(&return_val);
        return return_val_pod;
    }

    physx_PxAggregate_Pod* PxPhysics_createAggregate_mut(physx_PxPhysics_Pod* self__pod, uint32_t maxActor, uint32_t maxShape, uint32_t filterHint) {
        physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
        physx::PxAggregate* return_val = self_->createAggregate(maxActor, maxShape, filterHint);
        auto return_val_pod = reinterpret_cast<physx_PxAggregate_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxTolerancesScale_Pod const* PxPhysics_getTolerancesScale(physx_PxPhysics_Pod const* self__pod) {
        physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
        physx::PxTolerancesScale const& return_val = self_->getTolerancesScale();
        auto return_val_pod = reinterpret_cast<physx_PxTolerancesScale_Pod const*>(&return_val);
        return return_val_pod;
    }

    physx_PxTriangleMesh_Pod* PxPhysics_createTriangleMesh_mut(physx_PxPhysics_Pod* self__pod, physx_PxInputStream_Pod* stream_pod) {
        physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
        physx::PxInputStream& stream = reinterpret_cast<physx::PxInputStream&>(*stream_pod);
        physx::PxTriangleMesh* return_val = self_->createTriangleMesh(stream);
        auto return_val_pod = reinterpret_cast<physx_PxTriangleMesh_Pod*>(return_val);
        return return_val_pod;
    }

    uint32_t PxPhysics_getNbTriangleMeshes(physx_PxPhysics_Pod const* self__pod) {
        physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
        uint32_t return_val = self_->getNbTriangleMeshes();
        return return_val;
    }

    uint32_t PxPhysics_getTriangleMeshes(physx_PxPhysics_Pod const* self__pod, physx_PxTriangleMesh_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
        physx::PxTriangleMesh** userBuffer = reinterpret_cast<physx::PxTriangleMesh**>(userBuffer_pod);
        uint32_t return_val = self_->getTriangleMeshes(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    physx_PxTetrahedronMesh_Pod* PxPhysics_createTetrahedronMesh_mut(physx_PxPhysics_Pod* self__pod, physx_PxInputStream_Pod* stream_pod) {
        physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
        physx::PxInputStream& stream = reinterpret_cast<physx::PxInputStream&>(*stream_pod);
        physx::PxTetrahedronMesh* return_val = self_->createTetrahedronMesh(stream);
        auto return_val_pod = reinterpret_cast<physx_PxTetrahedronMesh_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxSoftBodyMesh_Pod* PxPhysics_createSoftBodyMesh_mut(physx_PxPhysics_Pod* self__pod, physx_PxInputStream_Pod* stream_pod) {
        physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
        physx::PxInputStream& stream = reinterpret_cast<physx::PxInputStream&>(*stream_pod);
        physx::PxSoftBodyMesh* return_val = self_->createSoftBodyMesh(stream);
        auto return_val_pod = reinterpret_cast<physx_PxSoftBodyMesh_Pod*>(return_val);
        return return_val_pod;
    }

    uint32_t PxPhysics_getNbTetrahedronMeshes(physx_PxPhysics_Pod const* self__pod) {
        physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
        uint32_t return_val = self_->getNbTetrahedronMeshes();
        return return_val;
    }

    uint32_t PxPhysics_getTetrahedronMeshes(physx_PxPhysics_Pod const* self__pod, physx_PxTetrahedronMesh_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
        physx::PxTetrahedronMesh** userBuffer = reinterpret_cast<physx::PxTetrahedronMesh**>(userBuffer_pod);
        uint32_t return_val = self_->getTetrahedronMeshes(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    physx_PxHeightField_Pod* PxPhysics_createHeightField_mut(physx_PxPhysics_Pod* self__pod, physx_PxInputStream_Pod* stream_pod) {
        physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
        physx::PxInputStream& stream = reinterpret_cast<physx::PxInputStream&>(*stream_pod);
        physx::PxHeightField* return_val = self_->createHeightField(stream);
        auto return_val_pod = reinterpret_cast<physx_PxHeightField_Pod*>(return_val);
        return return_val_pod;
    }

    uint32_t PxPhysics_getNbHeightFields(physx_PxPhysics_Pod const* self__pod) {
        physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
        uint32_t return_val = self_->getNbHeightFields();
        return return_val;
    }

    uint32_t PxPhysics_getHeightFields(physx_PxPhysics_Pod const* self__pod, physx_PxHeightField_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
        physx::PxHeightField** userBuffer = reinterpret_cast<physx::PxHeightField**>(userBuffer_pod);
        uint32_t return_val = self_->getHeightFields(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    physx_PxConvexMesh_Pod* PxPhysics_createConvexMesh_mut(physx_PxPhysics_Pod* self__pod, physx_PxInputStream_Pod* stream_pod) {
        physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
        physx::PxInputStream& stream = reinterpret_cast<physx::PxInputStream&>(*stream_pod);
        physx::PxConvexMesh* return_val = self_->createConvexMesh(stream);
        auto return_val_pod = reinterpret_cast<physx_PxConvexMesh_Pod*>(return_val);
        return return_val_pod;
    }

    uint32_t PxPhysics_getNbConvexMeshes(physx_PxPhysics_Pod const* self__pod) {
        physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
        uint32_t return_val = self_->getNbConvexMeshes();
        return return_val;
    }

    uint32_t PxPhysics_getConvexMeshes(physx_PxPhysics_Pod const* self__pod, physx_PxConvexMesh_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
        physx::PxConvexMesh** userBuffer = reinterpret_cast<physx::PxConvexMesh**>(userBuffer_pod);
        uint32_t return_val = self_->getConvexMeshes(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    physx_PxBVH_Pod* PxPhysics_createBVH_mut(physx_PxPhysics_Pod* self__pod, physx_PxInputStream_Pod* stream_pod) {
        physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
        physx::PxInputStream& stream = reinterpret_cast<physx::PxInputStream&>(*stream_pod);
        physx::PxBVH* return_val = self_->createBVH(stream);
        auto return_val_pod = reinterpret_cast<physx_PxBVH_Pod*>(return_val);
        return return_val_pod;
    }

    uint32_t PxPhysics_getNbBVHs(physx_PxPhysics_Pod const* self__pod) {
        physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
        uint32_t return_val = self_->getNbBVHs();
        return return_val;
    }

    uint32_t PxPhysics_getBVHs(physx_PxPhysics_Pod const* self__pod, physx_PxBVH_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
        physx::PxBVH** userBuffer = reinterpret_cast<physx::PxBVH**>(userBuffer_pod);
        uint32_t return_val = self_->getBVHs(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    physx_PxScene_Pod* PxPhysics_createScene_mut(physx_PxPhysics_Pod* self__pod, physx_PxSceneDesc_Pod const* sceneDesc_pod) {
        physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
        physx::PxSceneDesc const& sceneDesc = reinterpret_cast<physx::PxSceneDesc const&>(*sceneDesc_pod);
        physx::PxScene* return_val = self_->createScene(sceneDesc);
        auto return_val_pod = reinterpret_cast<physx_PxScene_Pod*>(return_val);
        return return_val_pod;
    }

    uint32_t PxPhysics_getNbScenes(physx_PxPhysics_Pod const* self__pod) {
        physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
        uint32_t return_val = self_->getNbScenes();
        return return_val;
    }

    uint32_t PxPhysics_getScenes(physx_PxPhysics_Pod const* self__pod, physx_PxScene_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
        physx::PxScene** userBuffer = reinterpret_cast<physx::PxScene**>(userBuffer_pod);
        uint32_t return_val = self_->getScenes(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    physx_PxRigidStatic_Pod* PxPhysics_createRigidStatic_mut(physx_PxPhysics_Pod* self__pod, physx_PxTransform_Pod const* pose_pod) {
        physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        physx::PxRigidStatic* return_val = self_->createRigidStatic(pose);
        auto return_val_pod = reinterpret_cast<physx_PxRigidStatic_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxRigidDynamic_Pod* PxPhysics_createRigidDynamic_mut(physx_PxPhysics_Pod* self__pod, physx_PxTransform_Pod const* pose_pod) {
        physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        physx::PxRigidDynamic* return_val = self_->createRigidDynamic(pose);
        auto return_val_pod = reinterpret_cast<physx_PxRigidDynamic_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxPruningStructure_Pod* PxPhysics_createPruningStructure_mut(physx_PxPhysics_Pod* self__pod, physx_PxRigidActor_Pod* const* actors_pod, uint32_t nbActors) {
        physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
        physx::PxRigidActor* const* actors = reinterpret_cast<physx::PxRigidActor* const*>(actors_pod);
        physx::PxPruningStructure* return_val = self_->createPruningStructure(actors, nbActors);
        auto return_val_pod = reinterpret_cast<physx_PxPruningStructure_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxShape_Pod* PxPhysics_createShape_mut(physx_PxPhysics_Pod* self__pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxMaterial_Pod const* material_pod, bool isExclusive, uint8_t shapeFlags_pod) {
        physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
        physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
        physx::PxMaterial const& material = reinterpret_cast<physx::PxMaterial const&>(*material_pod);
        auto shapeFlags = physx::PxShapeFlags(shapeFlags_pod);
        physx::PxShape* return_val = self_->createShape(geometry, material, isExclusive, shapeFlags);
        auto return_val_pod = reinterpret_cast<physx_PxShape_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxShape_Pod* PxPhysics_createShape_mut_1(physx_PxPhysics_Pod* self__pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxMaterial_Pod* const* materials_pod, uint16_t materialCount, bool isExclusive, uint8_t shapeFlags_pod) {
        physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
        physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
        physx::PxMaterial* const* materials = reinterpret_cast<physx::PxMaterial* const*>(materials_pod);
        auto shapeFlags = physx::PxShapeFlags(shapeFlags_pod);
        physx::PxShape* return_val = self_->createShape(geometry, materials, materialCount, isExclusive, shapeFlags);
        auto return_val_pod = reinterpret_cast<physx_PxShape_Pod*>(return_val);
        return return_val_pod;
    }

    uint32_t PxPhysics_getNbShapes(physx_PxPhysics_Pod const* self__pod) {
        physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
        uint32_t return_val = self_->getNbShapes();
        return return_val;
    }

    uint32_t PxPhysics_getShapes(physx_PxPhysics_Pod const* self__pod, physx_PxShape_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
        physx::PxShape** userBuffer = reinterpret_cast<physx::PxShape**>(userBuffer_pod);
        uint32_t return_val = self_->getShapes(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    physx_PxConstraint_Pod* PxPhysics_createConstraint_mut(physx_PxPhysics_Pod* self__pod, physx_PxRigidActor_Pod* actor0_pod, physx_PxRigidActor_Pod* actor1_pod, physx_PxConstraintConnector_Pod* connector_pod, physx_PxConstraintShaderTable_Pod const* shaders_pod, uint32_t dataSize) {
        physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
        physx::PxRigidActor* actor0 = reinterpret_cast<physx::PxRigidActor*>(actor0_pod);
        physx::PxRigidActor* actor1 = reinterpret_cast<physx::PxRigidActor*>(actor1_pod);
        physx::PxConstraintConnector& connector = reinterpret_cast<physx::PxConstraintConnector&>(*connector_pod);
        physx::PxConstraintShaderTable const& shaders = reinterpret_cast<physx::PxConstraintShaderTable const&>(*shaders_pod);
        physx::PxConstraint* return_val = self_->createConstraint(actor0, actor1, connector, shaders, dataSize);
        auto return_val_pod = reinterpret_cast<physx_PxConstraint_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxArticulationReducedCoordinate_Pod* PxPhysics_createArticulationReducedCoordinate_mut(physx_PxPhysics_Pod* self__pod) {
        physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
        physx::PxArticulationReducedCoordinate* return_val = self_->createArticulationReducedCoordinate();
        auto return_val_pod = reinterpret_cast<physx_PxArticulationReducedCoordinate_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxMaterial_Pod* PxPhysics_createMaterial_mut(physx_PxPhysics_Pod* self__pod, float staticFriction, float dynamicFriction, float restitution) {
        physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
        physx::PxMaterial* return_val = self_->createMaterial(staticFriction, dynamicFriction, restitution);
        auto return_val_pod = reinterpret_cast<physx_PxMaterial_Pod*>(return_val);
        return return_val_pod;
    }

    uint32_t PxPhysics_getNbMaterials(physx_PxPhysics_Pod const* self__pod) {
        physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
        uint32_t return_val = self_->getNbMaterials();
        return return_val;
    }

    uint32_t PxPhysics_getMaterials(physx_PxPhysics_Pod const* self__pod, physx_PxMaterial_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxPhysics const* self_ = reinterpret_cast<physx::PxPhysics const*>(self__pod);
        physx::PxMaterial** userBuffer = reinterpret_cast<physx::PxMaterial**>(userBuffer_pod);
        uint32_t return_val = self_->getMaterials(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    void PxPhysics_registerDeletionListener_mut(physx_PxPhysics_Pod* self__pod, physx_PxDeletionListener_Pod* observer_pod, uint8_t const* deletionEvents_pod, bool restrictedObjectSet) {
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

    physx_PxInsertionCallback_Pod* PxPhysics_getPhysicsInsertionCallback_mut(physx_PxPhysics_Pod* self__pod) {
        physx::PxPhysics* self_ = reinterpret_cast<physx::PxPhysics*>(self__pod);
        physx::PxInsertionCallback& return_val = self_->getPhysicsInsertionCallback();
        auto return_val_pod = reinterpret_cast<physx_PxInsertionCallback_Pod*>(&return_val);
        return return_val_pod;
    }

    physx_PxPhysics_Pod* phys_PxCreatePhysics(uint32_t version, physx_PxFoundation_Pod* foundation_pod, physx_PxTolerancesScale_Pod const* scale_pod, bool trackOutstandingAllocations, physx_PxPvd_Pod* pvd_pod, physx_PxOmniPvd_Pod* omniPvd_pod) {
        physx::PxFoundation& foundation = reinterpret_cast<physx::PxFoundation&>(*foundation_pod);
        physx::PxTolerancesScale const& scale = reinterpret_cast<physx::PxTolerancesScale const&>(*scale_pod);
        physx::PxPvd* pvd = reinterpret_cast<physx::PxPvd*>(pvd_pod);
        physx::PxOmniPvd* omniPvd = reinterpret_cast<physx::PxOmniPvd*>(omniPvd_pod);
        physx::PxPhysics* return_val = PxCreatePhysics(version, foundation, scale, trackOutstandingAllocations, pvd, omniPvd);
        auto return_val_pod = reinterpret_cast<physx_PxPhysics_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxPhysics_Pod* phys_PxGetPhysics() {
        physx::PxPhysics& return_val = PxGetPhysics();
        auto return_val_pod = reinterpret_cast<physx_PxPhysics_Pod*>(&return_val);
        return return_val_pod;
    }

    physx_PxActorShape_Pod PxActorShape_new() {
        PxActorShape return_val;
        physx_PxActorShape_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxActorShape_Pod PxActorShape_new_1(physx_PxRigidActor_Pod* a_pod, physx_PxShape_Pod* s_pod) {
        physx::PxRigidActor* a = reinterpret_cast<physx::PxRigidActor*>(a_pod);
        physx::PxShape* s = reinterpret_cast<physx::PxShape*>(s_pod);
        PxActorShape return_val(a, s);
        physx_PxActorShape_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxQueryCache_Pod PxQueryCache_new() {
        PxQueryCache return_val;
        physx_PxQueryCache_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxQueryCache_Pod PxQueryCache_new_1(physx_PxShape_Pod* s_pod, uint32_t findex) {
        physx::PxShape* s = reinterpret_cast<physx::PxShape*>(s_pod);
        PxQueryCache return_val(s, findex);
        physx_PxQueryCache_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxQueryFilterData_Pod PxQueryFilterData_new() {
        PxQueryFilterData return_val;
        physx_PxQueryFilterData_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxQueryFilterData_Pod PxQueryFilterData_new_1(physx_PxFilterData_Pod const* fd_pod, uint16_t f_pod) {
        physx::PxFilterData const& fd = reinterpret_cast<physx::PxFilterData const&>(*fd_pod);
        auto f = physx::PxQueryFlags(f_pod);
        PxQueryFilterData return_val(fd, f);
        physx_PxQueryFilterData_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxQueryFilterData_Pod PxQueryFilterData_new_2(uint16_t f_pod) {
        auto f = physx::PxQueryFlags(f_pod);
        PxQueryFilterData return_val(f);
        physx_PxQueryFilterData_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    int32_t PxQueryFilterCallback_preFilter_mut(physx_PxQueryFilterCallback_Pod* self__pod, physx_PxFilterData_Pod const* filterData_pod, physx_PxShape_Pod const* shape_pod, physx_PxRigidActor_Pod const* actor_pod, uint16_t* queryFlags_pod) {
        physx::PxQueryFilterCallback* self_ = reinterpret_cast<physx::PxQueryFilterCallback*>(self__pod);
        physx::PxFilterData const& filterData = reinterpret_cast<physx::PxFilterData const&>(*filterData_pod);
        physx::PxShape const* shape = reinterpret_cast<physx::PxShape const*>(shape_pod);
        physx::PxRigidActor const* actor = reinterpret_cast<physx::PxRigidActor const*>(actor_pod);
        physx::PxHitFlags& queryFlags = reinterpret_cast<physx::PxHitFlags&>(*queryFlags_pod);
        physx::PxQueryHitType::Enum return_val = self_->preFilter(filterData, shape, actor, queryFlags);
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    int32_t PxQueryFilterCallback_postFilter_mut(physx_PxQueryFilterCallback_Pod* self__pod, physx_PxFilterData_Pod const* filterData_pod, physx_PxQueryHit_Pod const* hit_pod, physx_PxShape_Pod const* shape_pod, physx_PxRigidActor_Pod const* actor_pod) {
        physx::PxQueryFilterCallback* self_ = reinterpret_cast<physx::PxQueryFilterCallback*>(self__pod);
        physx::PxFilterData const& filterData = reinterpret_cast<physx::PxFilterData const&>(*filterData_pod);
        physx::PxQueryHit const& hit = reinterpret_cast<physx::PxQueryHit const&>(*hit_pod);
        physx::PxShape const* shape = reinterpret_cast<physx::PxShape const*>(shape_pod);
        physx::PxRigidActor const* actor = reinterpret_cast<physx::PxRigidActor const*>(actor_pod);
        physx::PxQueryHitType::Enum return_val = self_->postFilter(filterData, hit, shape, actor);
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxQueryFilterCallback_delete(physx_PxQueryFilterCallback_Pod* self__pod) {
        physx::PxQueryFilterCallback* self_ = reinterpret_cast<physx::PxQueryFilterCallback*>(self__pod);
        delete self_;
    }

    void PxRigidDynamic_setKinematicTarget_mut(physx_PxRigidDynamic_Pod* self__pod, physx_PxTransform_Pod const* destination_pod) {
        physx::PxRigidDynamic* self_ = reinterpret_cast<physx::PxRigidDynamic*>(self__pod);
        physx::PxTransform const& destination = reinterpret_cast<physx::PxTransform const&>(*destination_pod);
        self_->setKinematicTarget(destination);
    }

    bool PxRigidDynamic_getKinematicTarget(physx_PxRigidDynamic_Pod const* self__pod, physx_PxTransform_Pod* target_pod) {
        physx::PxRigidDynamic const* self_ = reinterpret_cast<physx::PxRigidDynamic const*>(self__pod);
        physx::PxTransform& target = reinterpret_cast<physx::PxTransform&>(*target_pod);
        bool return_val = self_->getKinematicTarget(target);
        return return_val;
    }

    bool PxRigidDynamic_isSleeping(physx_PxRigidDynamic_Pod const* self__pod) {
        physx::PxRigidDynamic const* self_ = reinterpret_cast<physx::PxRigidDynamic const*>(self__pod);
        bool return_val = self_->isSleeping();
        return return_val;
    }

    void PxRigidDynamic_setSleepThreshold_mut(physx_PxRigidDynamic_Pod* self__pod, float threshold) {
        physx::PxRigidDynamic* self_ = reinterpret_cast<physx::PxRigidDynamic*>(self__pod);
        self_->setSleepThreshold(threshold);
    }

    float PxRigidDynamic_getSleepThreshold(physx_PxRigidDynamic_Pod const* self__pod) {
        physx::PxRigidDynamic const* self_ = reinterpret_cast<physx::PxRigidDynamic const*>(self__pod);
        float return_val = self_->getSleepThreshold();
        return return_val;
    }

    void PxRigidDynamic_setStabilizationThreshold_mut(physx_PxRigidDynamic_Pod* self__pod, float threshold) {
        physx::PxRigidDynamic* self_ = reinterpret_cast<physx::PxRigidDynamic*>(self__pod);
        self_->setStabilizationThreshold(threshold);
    }

    float PxRigidDynamic_getStabilizationThreshold(physx_PxRigidDynamic_Pod const* self__pod) {
        physx::PxRigidDynamic const* self_ = reinterpret_cast<physx::PxRigidDynamic const*>(self__pod);
        float return_val = self_->getStabilizationThreshold();
        return return_val;
    }

    uint8_t PxRigidDynamic_getRigidDynamicLockFlags(physx_PxRigidDynamic_Pod const* self__pod) {
        physx::PxRigidDynamic const* self_ = reinterpret_cast<physx::PxRigidDynamic const*>(self__pod);
        physx::PxRigidDynamicLockFlags return_val = self_->getRigidDynamicLockFlags();
        uint8_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxRigidDynamic_setRigidDynamicLockFlag_mut(physx_PxRigidDynamic_Pod* self__pod, int32_t flag_pod, bool value) {
        physx::PxRigidDynamic* self_ = reinterpret_cast<physx::PxRigidDynamic*>(self__pod);
        auto flag = static_cast<physx::PxRigidDynamicLockFlag::Enum>(flag_pod);
        self_->setRigidDynamicLockFlag(flag, value);
    }

    void PxRigidDynamic_setRigidDynamicLockFlags_mut(physx_PxRigidDynamic_Pod* self__pod, uint8_t flags_pod) {
        physx::PxRigidDynamic* self_ = reinterpret_cast<physx::PxRigidDynamic*>(self__pod);
        auto flags = physx::PxRigidDynamicLockFlags(flags_pod);
        self_->setRigidDynamicLockFlags(flags);
    }

    physx_PxVec3_Pod PxRigidDynamic_getLinearVelocity(physx_PxRigidDynamic_Pod const* self__pod) {
        physx::PxRigidDynamic const* self_ = reinterpret_cast<physx::PxRigidDynamic const*>(self__pod);
        physx::PxVec3 return_val = self_->getLinearVelocity();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxRigidDynamic_setLinearVelocity_mut(physx_PxRigidDynamic_Pod* self__pod, physx_PxVec3_Pod const* linVel_pod, bool autowake) {
        physx::PxRigidDynamic* self_ = reinterpret_cast<physx::PxRigidDynamic*>(self__pod);
        physx::PxVec3 const& linVel = reinterpret_cast<physx::PxVec3 const&>(*linVel_pod);
        self_->setLinearVelocity(linVel, autowake);
    }

    physx_PxVec3_Pod PxRigidDynamic_getAngularVelocity(physx_PxRigidDynamic_Pod const* self__pod) {
        physx::PxRigidDynamic const* self_ = reinterpret_cast<physx::PxRigidDynamic const*>(self__pod);
        physx::PxVec3 return_val = self_->getAngularVelocity();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxRigidDynamic_setAngularVelocity_mut(physx_PxRigidDynamic_Pod* self__pod, physx_PxVec3_Pod const* angVel_pod, bool autowake) {
        physx::PxRigidDynamic* self_ = reinterpret_cast<physx::PxRigidDynamic*>(self__pod);
        physx::PxVec3 const& angVel = reinterpret_cast<physx::PxVec3 const&>(*angVel_pod);
        self_->setAngularVelocity(angVel, autowake);
    }

    void PxRigidDynamic_setWakeCounter_mut(physx_PxRigidDynamic_Pod* self__pod, float wakeCounterValue) {
        physx::PxRigidDynamic* self_ = reinterpret_cast<physx::PxRigidDynamic*>(self__pod);
        self_->setWakeCounter(wakeCounterValue);
    }

    float PxRigidDynamic_getWakeCounter(physx_PxRigidDynamic_Pod const* self__pod) {
        physx::PxRigidDynamic const* self_ = reinterpret_cast<physx::PxRigidDynamic const*>(self__pod);
        float return_val = self_->getWakeCounter();
        return return_val;
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
        float return_val = self_->getContactReportThreshold();
        return return_val;
    }

    void PxRigidDynamic_setContactReportThreshold_mut(physx_PxRigidDynamic_Pod* self__pod, float threshold) {
        physx::PxRigidDynamic* self_ = reinterpret_cast<physx::PxRigidDynamic*>(self__pod);
        self_->setContactReportThreshold(threshold);
    }

    char const* PxRigidDynamic_getConcreteTypeName(physx_PxRigidDynamic_Pod const* self__pod) {
        physx::PxRigidDynamic const* self_ = reinterpret_cast<physx::PxRigidDynamic const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    char const* PxRigidStatic_getConcreteTypeName(physx_PxRigidStatic_Pod const* self__pod) {
        physx::PxRigidStatic const* self_ = reinterpret_cast<physx::PxRigidStatic const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    physx_PxSceneQueryDesc_Pod PxSceneQueryDesc_new() {
        PxSceneQueryDesc return_val;
        physx_PxSceneQueryDesc_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxSceneQueryDesc_setToDefault_mut(physx_PxSceneQueryDesc_Pod* self__pod) {
        physx::PxSceneQueryDesc* self_ = reinterpret_cast<physx::PxSceneQueryDesc*>(self__pod);
        self_->setToDefault();
    }

    bool PxSceneQueryDesc_isValid(physx_PxSceneQueryDesc_Pod const* self__pod) {
        physx::PxSceneQueryDesc const* self_ = reinterpret_cast<physx::PxSceneQueryDesc const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    void PxSceneQuerySystemBase_setDynamicTreeRebuildRateHint_mut(physx_PxSceneQuerySystemBase_Pod* self__pod, uint32_t dynamicTreeRebuildRateHint) {
        physx::PxSceneQuerySystemBase* self_ = reinterpret_cast<physx::PxSceneQuerySystemBase*>(self__pod);
        self_->setDynamicTreeRebuildRateHint(dynamicTreeRebuildRateHint);
    }

    uint32_t PxSceneQuerySystemBase_getDynamicTreeRebuildRateHint(physx_PxSceneQuerySystemBase_Pod const* self__pod) {
        physx::PxSceneQuerySystemBase const* self_ = reinterpret_cast<physx::PxSceneQuerySystemBase const*>(self__pod);
        uint32_t return_val = self_->getDynamicTreeRebuildRateHint();
        return return_val;
    }

    void PxSceneQuerySystemBase_forceRebuildDynamicTree_mut(physx_PxSceneQuerySystemBase_Pod* self__pod, uint32_t prunerIndex) {
        physx::PxSceneQuerySystemBase* self_ = reinterpret_cast<physx::PxSceneQuerySystemBase*>(self__pod);
        self_->forceRebuildDynamicTree(prunerIndex);
    }

    void PxSceneQuerySystemBase_setUpdateMode_mut(physx_PxSceneQuerySystemBase_Pod* self__pod, int32_t updateMode_pod) {
        physx::PxSceneQuerySystemBase* self_ = reinterpret_cast<physx::PxSceneQuerySystemBase*>(self__pod);
        auto updateMode = static_cast<physx::PxSceneQueryUpdateMode::Enum>(updateMode_pod);
        self_->setUpdateMode(updateMode);
    }

    int32_t PxSceneQuerySystemBase_getUpdateMode(physx_PxSceneQuerySystemBase_Pod const* self__pod) {
        physx::PxSceneQuerySystemBase const* self_ = reinterpret_cast<physx::PxSceneQuerySystemBase const*>(self__pod);
        physx::PxSceneQueryUpdateMode::Enum return_val = self_->getUpdateMode();
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    uint32_t PxSceneQuerySystemBase_getStaticTimestamp(physx_PxSceneQuerySystemBase_Pod const* self__pod) {
        physx::PxSceneQuerySystemBase const* self_ = reinterpret_cast<physx::PxSceneQuerySystemBase const*>(self__pod);
        uint32_t return_val = self_->getStaticTimestamp();
        return return_val;
    }

    void PxSceneQuerySystemBase_flushUpdates_mut(physx_PxSceneQuerySystemBase_Pod* self__pod) {
        physx::PxSceneQuerySystemBase* self_ = reinterpret_cast<physx::PxSceneQuerySystemBase*>(self__pod);
        self_->flushUpdates();
    }

    bool PxSceneQuerySystemBase_raycast(physx_PxSceneQuerySystemBase_Pod const* self__pod, physx_PxVec3_Pod const* origin_pod, physx_PxVec3_Pod const* unitDir_pod, float distance, physx_PxRaycastCallback_Pod* hitCall_pod, uint16_t hitFlags_pod, physx_PxQueryFilterData_Pod const* filterData_pod, physx_PxQueryFilterCallback_Pod* filterCall_pod, physx_PxQueryCache_Pod const* cache_pod, uint32_t queryFlags_pod) {
        physx::PxSceneQuerySystemBase const* self_ = reinterpret_cast<physx::PxSceneQuerySystemBase const*>(self__pod);
        physx::PxVec3 const& origin = reinterpret_cast<physx::PxVec3 const&>(*origin_pod);
        physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
        physx::PxRaycastCallback& hitCall = reinterpret_cast<physx::PxRaycastCallback&>(*hitCall_pod);
        auto hitFlags = physx::PxHitFlags(hitFlags_pod);
        physx::PxQueryFilterData const& filterData = reinterpret_cast<physx::PxQueryFilterData const&>(*filterData_pod);
        physx::PxQueryFilterCallback* filterCall = reinterpret_cast<physx::PxQueryFilterCallback*>(filterCall_pod);
        physx::PxQueryCache const* cache = reinterpret_cast<physx::PxQueryCache const*>(cache_pod);
        auto queryFlags = physx::PxGeometryQueryFlags(queryFlags_pod);
        bool return_val = self_->raycast(origin, unitDir, distance, hitCall, hitFlags, filterData, filterCall, cache, queryFlags);
        return return_val;
    }

    bool PxSceneQuerySystemBase_sweep(physx_PxSceneQuerySystemBase_Pod const* self__pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxTransform_Pod const* pose_pod, physx_PxVec3_Pod const* unitDir_pod, float distance, physx_PxSweepCallback_Pod* hitCall_pod, uint16_t hitFlags_pod, physx_PxQueryFilterData_Pod const* filterData_pod, physx_PxQueryFilterCallback_Pod* filterCall_pod, physx_PxQueryCache_Pod const* cache_pod, float inflation, uint32_t queryFlags_pod) {
        physx::PxSceneQuerySystemBase const* self_ = reinterpret_cast<physx::PxSceneQuerySystemBase const*>(self__pod);
        physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
        physx::PxSweepCallback& hitCall = reinterpret_cast<physx::PxSweepCallback&>(*hitCall_pod);
        auto hitFlags = physx::PxHitFlags(hitFlags_pod);
        physx::PxQueryFilterData const& filterData = reinterpret_cast<physx::PxQueryFilterData const&>(*filterData_pod);
        physx::PxQueryFilterCallback* filterCall = reinterpret_cast<physx::PxQueryFilterCallback*>(filterCall_pod);
        physx::PxQueryCache const* cache = reinterpret_cast<physx::PxQueryCache const*>(cache_pod);
        auto queryFlags = physx::PxGeometryQueryFlags(queryFlags_pod);
        bool return_val = self_->sweep(geometry, pose, unitDir, distance, hitCall, hitFlags, filterData, filterCall, cache, inflation, queryFlags);
        return return_val;
    }

    bool PxSceneQuerySystemBase_overlap(physx_PxSceneQuerySystemBase_Pod const* self__pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxTransform_Pod const* pose_pod, physx_PxOverlapCallback_Pod* hitCall_pod, physx_PxQueryFilterData_Pod const* filterData_pod, physx_PxQueryFilterCallback_Pod* filterCall_pod, physx_PxQueryCache_Pod const* cache_pod, uint32_t queryFlags_pod) {
        physx::PxSceneQuerySystemBase const* self_ = reinterpret_cast<physx::PxSceneQuerySystemBase const*>(self__pod);
        physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        physx::PxOverlapCallback& hitCall = reinterpret_cast<physx::PxOverlapCallback&>(*hitCall_pod);
        physx::PxQueryFilterData const& filterData = reinterpret_cast<physx::PxQueryFilterData const&>(*filterData_pod);
        physx::PxQueryFilterCallback* filterCall = reinterpret_cast<physx::PxQueryFilterCallback*>(filterCall_pod);
        physx::PxQueryCache const* cache = reinterpret_cast<physx::PxQueryCache const*>(cache_pod);
        auto queryFlags = physx::PxGeometryQueryFlags(queryFlags_pod);
        bool return_val = self_->overlap(geometry, pose, hitCall, filterData, filterCall, cache, queryFlags);
        return return_val;
    }

    void PxSceneSQSystem_setSceneQueryUpdateMode_mut(physx_PxSceneSQSystem_Pod* self__pod, int32_t updateMode_pod) {
        physx::PxSceneSQSystem* self_ = reinterpret_cast<physx::PxSceneSQSystem*>(self__pod);
        auto updateMode = static_cast<physx::PxSceneQueryUpdateMode::Enum>(updateMode_pod);
        self_->setSceneQueryUpdateMode(updateMode);
    }

    int32_t PxSceneSQSystem_getSceneQueryUpdateMode(physx_PxSceneSQSystem_Pod const* self__pod) {
        physx::PxSceneSQSystem const* self_ = reinterpret_cast<physx::PxSceneSQSystem const*>(self__pod);
        physx::PxSceneQueryUpdateMode::Enum return_val = self_->getSceneQueryUpdateMode();
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    uint32_t PxSceneSQSystem_getSceneQueryStaticTimestamp(physx_PxSceneSQSystem_Pod const* self__pod) {
        physx::PxSceneSQSystem const* self_ = reinterpret_cast<physx::PxSceneSQSystem const*>(self__pod);
        uint32_t return_val = self_->getSceneQueryStaticTimestamp();
        return return_val;
    }

    void PxSceneSQSystem_flushQueryUpdates_mut(physx_PxSceneSQSystem_Pod* self__pod) {
        physx::PxSceneSQSystem* self_ = reinterpret_cast<physx::PxSceneSQSystem*>(self__pod);
        self_->flushQueryUpdates();
    }

    void PxSceneSQSystem_forceDynamicTreeRebuild_mut(physx_PxSceneSQSystem_Pod* self__pod, bool rebuildStaticStructure, bool rebuildDynamicStructure) {
        physx::PxSceneSQSystem* self_ = reinterpret_cast<physx::PxSceneSQSystem*>(self__pod);
        self_->forceDynamicTreeRebuild(rebuildStaticStructure, rebuildDynamicStructure);
    }

    int32_t PxSceneSQSystem_getStaticStructure(physx_PxSceneSQSystem_Pod const* self__pod) {
        physx::PxSceneSQSystem const* self_ = reinterpret_cast<physx::PxSceneSQSystem const*>(self__pod);
        physx::PxPruningStructureType::Enum return_val = self_->getStaticStructure();
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    int32_t PxSceneSQSystem_getDynamicStructure(physx_PxSceneSQSystem_Pod const* self__pod) {
        physx::PxSceneSQSystem const* self_ = reinterpret_cast<physx::PxSceneSQSystem const*>(self__pod);
        physx::PxPruningStructureType::Enum return_val = self_->getDynamicStructure();
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxSceneSQSystem_sceneQueriesUpdate_mut(physx_PxSceneSQSystem_Pod* self__pod, physx_PxBaseTask_Pod* completionTask_pod, bool controlSimulation) {
        physx::PxSceneSQSystem* self_ = reinterpret_cast<physx::PxSceneSQSystem*>(self__pod);
        physx::PxBaseTask* completionTask = reinterpret_cast<physx::PxBaseTask*>(completionTask_pod);
        self_->sceneQueriesUpdate(completionTask, controlSimulation);
    }

    bool PxSceneSQSystem_checkQueries_mut(physx_PxSceneSQSystem_Pod* self__pod, bool block) {
        physx::PxSceneSQSystem* self_ = reinterpret_cast<physx::PxSceneSQSystem*>(self__pod);
        bool return_val = self_->checkQueries(block);
        return return_val;
    }

    bool PxSceneSQSystem_fetchQueries_mut(physx_PxSceneSQSystem_Pod* self__pod, bool block) {
        physx::PxSceneSQSystem* self_ = reinterpret_cast<physx::PxSceneSQSystem*>(self__pod);
        bool return_val = self_->fetchQueries(block);
        return return_val;
    }

    void PxSceneQuerySystem_release_mut(physx_PxSceneQuerySystem_Pod* self__pod) {
        physx::PxSceneQuerySystem* self_ = reinterpret_cast<physx::PxSceneQuerySystem*>(self__pod);
        self_->release();
    }

    void PxSceneQuerySystem_acquireReference_mut(physx_PxSceneQuerySystem_Pod* self__pod) {
        physx::PxSceneQuerySystem* self_ = reinterpret_cast<physx::PxSceneQuerySystem*>(self__pod);
        self_->acquireReference();
    }

    void PxSceneQuerySystem_preallocate_mut(physx_PxSceneQuerySystem_Pod* self__pod, uint32_t prunerIndex, uint32_t nbShapes) {
        physx::PxSceneQuerySystem* self_ = reinterpret_cast<physx::PxSceneQuerySystem*>(self__pod);
        self_->preallocate(prunerIndex, nbShapes);
    }

    void PxSceneQuerySystem_flushMemory_mut(physx_PxSceneQuerySystem_Pod* self__pod) {
        physx::PxSceneQuerySystem* self_ = reinterpret_cast<physx::PxSceneQuerySystem*>(self__pod);
        self_->flushMemory();
    }

    void PxSceneQuerySystem_addSQShape_mut(physx_PxSceneQuerySystem_Pod* self__pod, physx_PxRigidActor_Pod const* actor_pod, physx_PxShape_Pod const* shape_pod, physx_PxBounds3_Pod const* bounds_pod, physx_PxTransform_Pod const* transform_pod, uint32_t const* compoundHandle, bool hasPruningStructure) {
        physx::PxSceneQuerySystem* self_ = reinterpret_cast<physx::PxSceneQuerySystem*>(self__pod);
        physx::PxRigidActor const& actor = reinterpret_cast<physx::PxRigidActor const&>(*actor_pod);
        physx::PxShape const& shape = reinterpret_cast<physx::PxShape const&>(*shape_pod);
        physx::PxBounds3 const& bounds = reinterpret_cast<physx::PxBounds3 const&>(*bounds_pod);
        physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
        self_->addSQShape(actor, shape, bounds, transform, compoundHandle, hasPruningStructure);
    }

    void PxSceneQuerySystem_removeSQShape_mut(physx_PxSceneQuerySystem_Pod* self__pod, physx_PxRigidActor_Pod const* actor_pod, physx_PxShape_Pod const* shape_pod) {
        physx::PxSceneQuerySystem* self_ = reinterpret_cast<physx::PxSceneQuerySystem*>(self__pod);
        physx::PxRigidActor const& actor = reinterpret_cast<physx::PxRigidActor const&>(*actor_pod);
        physx::PxShape const& shape = reinterpret_cast<physx::PxShape const&>(*shape_pod);
        self_->removeSQShape(actor, shape);
    }

    void PxSceneQuerySystem_updateSQShape_mut(physx_PxSceneQuerySystem_Pod* self__pod, physx_PxRigidActor_Pod const* actor_pod, physx_PxShape_Pod const* shape_pod, physx_PxTransform_Pod const* transform_pod) {
        physx::PxSceneQuerySystem* self_ = reinterpret_cast<physx::PxSceneQuerySystem*>(self__pod);
        physx::PxRigidActor const& actor = reinterpret_cast<physx::PxRigidActor const&>(*actor_pod);
        physx::PxShape const& shape = reinterpret_cast<physx::PxShape const&>(*shape_pod);
        physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
        self_->updateSQShape(actor, shape, transform);
    }

    uint32_t PxSceneQuerySystem_addSQCompound_mut(physx_PxSceneQuerySystem_Pod* self__pod, physx_PxRigidActor_Pod const* actor_pod, physx_PxShape_Pod const** shapes_pod, physx_PxBVH_Pod const* bvh_pod, physx_PxTransform_Pod const* transforms_pod) {
        physx::PxSceneQuerySystem* self_ = reinterpret_cast<physx::PxSceneQuerySystem*>(self__pod);
        physx::PxRigidActor const& actor = reinterpret_cast<physx::PxRigidActor const&>(*actor_pod);
        physx::PxShape const** shapes = reinterpret_cast<physx::PxShape const**>(shapes_pod);
        physx::PxBVH const& bvh = reinterpret_cast<physx::PxBVH const&>(*bvh_pod);
        physx::PxTransform const* transforms = reinterpret_cast<physx::PxTransform const*>(transforms_pod);
        uint32_t return_val = self_->addSQCompound(actor, shapes, bvh, transforms);
        return return_val;
    }

    void PxSceneQuerySystem_removeSQCompound_mut(physx_PxSceneQuerySystem_Pod* self__pod, uint32_t compoundHandle) {
        physx::PxSceneQuerySystem* self_ = reinterpret_cast<physx::PxSceneQuerySystem*>(self__pod);
        self_->removeSQCompound(compoundHandle);
    }

    void PxSceneQuerySystem_updateSQCompound_mut(physx_PxSceneQuerySystem_Pod* self__pod, uint32_t compoundHandle, physx_PxTransform_Pod const* compoundTransform_pod) {
        physx::PxSceneQuerySystem* self_ = reinterpret_cast<physx::PxSceneQuerySystem*>(self__pod);
        physx::PxTransform const& compoundTransform = reinterpret_cast<physx::PxTransform const&>(*compoundTransform_pod);
        self_->updateSQCompound(compoundHandle, compoundTransform);
    }

    void PxSceneQuerySystem_shiftOrigin_mut(physx_PxSceneQuerySystem_Pod* self__pod, physx_PxVec3_Pod const* shift_pod) {
        physx::PxSceneQuerySystem* self_ = reinterpret_cast<physx::PxSceneQuerySystem*>(self__pod);
        physx::PxVec3 const& shift = reinterpret_cast<physx::PxVec3 const&>(*shift_pod);
        self_->shiftOrigin(shift);
    }

    void PxSceneQuerySystem_merge_mut(physx_PxSceneQuerySystem_Pod* self__pod, physx_PxPruningStructure_Pod const* pruningStructure_pod) {
        physx::PxSceneQuerySystem* self_ = reinterpret_cast<physx::PxSceneQuerySystem*>(self__pod);
        physx::PxPruningStructure const& pruningStructure = reinterpret_cast<physx::PxPruningStructure const&>(*pruningStructure_pod);
        self_->merge(pruningStructure);
    }

    uint32_t PxSceneQuerySystem_getHandle(physx_PxSceneQuerySystem_Pod const* self__pod, physx_PxRigidActor_Pod const* actor_pod, physx_PxShape_Pod const* shape_pod, uint32_t* prunerIndex_pod) {
        physx::PxSceneQuerySystem const* self_ = reinterpret_cast<physx::PxSceneQuerySystem const*>(self__pod);
        physx::PxRigidActor const& actor = reinterpret_cast<physx::PxRigidActor const&>(*actor_pod);
        physx::PxShape const& shape = reinterpret_cast<physx::PxShape const&>(*shape_pod);
        uint32_t& prunerIndex = *prunerIndex_pod;
        uint32_t return_val = self_->getHandle(actor, shape, prunerIndex);
        return return_val;
    }

    void PxSceneQuerySystem_sync_mut(physx_PxSceneQuerySystem_Pod* self__pod, uint32_t prunerIndex, uint32_t const* handles, uint32_t const* indices, physx_PxBounds3_Pod const* bounds_pod, physx_PxTransformPadded_Pod const* transforms_pod, uint32_t count, physx_PxBitMap_Pod const* ignoredIndices_pod) {
        physx::PxSceneQuerySystem* self_ = reinterpret_cast<physx::PxSceneQuerySystem*>(self__pod);
        physx::PxBounds3 const* bounds = reinterpret_cast<physx::PxBounds3 const*>(bounds_pod);
        physx::PxTransformPadded const* transforms = reinterpret_cast<physx::PxTransformPadded const*>(transforms_pod);
        physx::PxBitMap const& ignoredIndices = reinterpret_cast<physx::PxBitMap const&>(*ignoredIndices_pod);
        self_->sync(prunerIndex, handles, indices, bounds, transforms, count, ignoredIndices);
    }

    void PxSceneQuerySystem_finalizeUpdates_mut(physx_PxSceneQuerySystem_Pod* self__pod) {
        physx::PxSceneQuerySystem* self_ = reinterpret_cast<physx::PxSceneQuerySystem*>(self__pod);
        self_->finalizeUpdates();
    }

    void* PxSceneQuerySystem_prepareSceneQueryBuildStep_mut(physx_PxSceneQuerySystem_Pod* self__pod, uint32_t prunerIndex) {
        physx::PxSceneQuerySystem* self_ = reinterpret_cast<physx::PxSceneQuerySystem*>(self__pod);
        void* return_val = self_->prepareSceneQueryBuildStep(prunerIndex);
        return return_val;
    }

    void PxSceneQuerySystem_sceneQueryBuildStep_mut(physx_PxSceneQuerySystem_Pod* self__pod, void* handle) {
        physx::PxSceneQuerySystem* self_ = reinterpret_cast<physx::PxSceneQuerySystem*>(self__pod);
        self_->sceneQueryBuildStep(handle);
    }

    physx_PxBroadPhaseDesc_Pod PxBroadPhaseDesc_new(int32_t type_pod) {
        auto type = static_cast<physx::PxBroadPhaseType::Enum>(type_pod);
        PxBroadPhaseDesc return_val(type);
        physx_PxBroadPhaseDesc_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxBroadPhaseDesc_isValid(physx_PxBroadPhaseDesc_Pod const* self__pod) {
        physx::PxBroadPhaseDesc const* self_ = reinterpret_cast<physx::PxBroadPhaseDesc const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    uint32_t phys_PxGetBroadPhaseStaticFilterGroup() {
        uint32_t return_val = PxGetBroadPhaseStaticFilterGroup();
        return return_val;
    }

    uint32_t phys_PxGetBroadPhaseDynamicFilterGroup(uint32_t id) {
        uint32_t return_val = PxGetBroadPhaseDynamicFilterGroup(id);
        return return_val;
    }

    uint32_t phys_PxGetBroadPhaseKinematicFilterGroup(uint32_t id) {
        uint32_t return_val = PxGetBroadPhaseKinematicFilterGroup(id);
        return return_val;
    }

    physx_PxBroadPhaseUpdateData_Pod PxBroadPhaseUpdateData_new(uint32_t const* created, uint32_t nbCreated, uint32_t const* updated, uint32_t nbUpdated, uint32_t const* removed, uint32_t nbRemoved, physx_PxBounds3_Pod const* bounds_pod, uint32_t const* groups, float const* distances, uint32_t capacity) {
        physx::PxBounds3 const* bounds = reinterpret_cast<physx::PxBounds3 const*>(bounds_pod);
        PxBroadPhaseUpdateData return_val(created, nbCreated, updated, nbUpdated, removed, nbRemoved, bounds, groups, distances, capacity);
        physx_PxBroadPhaseUpdateData_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxBroadPhaseResults_Pod PxBroadPhaseResults_new() {
        PxBroadPhaseResults return_val;
        physx_PxBroadPhaseResults_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    uint32_t PxBroadPhaseRegions_getNbRegions(physx_PxBroadPhaseRegions_Pod const* self__pod) {
        physx::PxBroadPhaseRegions const* self_ = reinterpret_cast<physx::PxBroadPhaseRegions const*>(self__pod);
        uint32_t return_val = self_->getNbRegions();
        return return_val;
    }

    uint32_t PxBroadPhaseRegions_getRegions(physx_PxBroadPhaseRegions_Pod const* self__pod, physx_PxBroadPhaseRegionInfo_Pod* userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxBroadPhaseRegions const* self_ = reinterpret_cast<physx::PxBroadPhaseRegions const*>(self__pod);
        physx::PxBroadPhaseRegionInfo* userBuffer = reinterpret_cast<physx::PxBroadPhaseRegionInfo*>(userBuffer_pod);
        uint32_t return_val = self_->getRegions(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    uint32_t PxBroadPhaseRegions_addRegion_mut(physx_PxBroadPhaseRegions_Pod* self__pod, physx_PxBroadPhaseRegion_Pod const* region_pod, bool populateRegion, physx_PxBounds3_Pod const* bounds_pod, float const* distances) {
        physx::PxBroadPhaseRegions* self_ = reinterpret_cast<physx::PxBroadPhaseRegions*>(self__pod);
        physx::PxBroadPhaseRegion const& region = reinterpret_cast<physx::PxBroadPhaseRegion const&>(*region_pod);
        physx::PxBounds3 const* bounds = reinterpret_cast<physx::PxBounds3 const*>(bounds_pod);
        uint32_t return_val = self_->addRegion(region, populateRegion, bounds, distances);
        return return_val;
    }

    bool PxBroadPhaseRegions_removeRegion_mut(physx_PxBroadPhaseRegions_Pod* self__pod, uint32_t handle) {
        physx::PxBroadPhaseRegions* self_ = reinterpret_cast<physx::PxBroadPhaseRegions*>(self__pod);
        bool return_val = self_->removeRegion(handle);
        return return_val;
    }

    uint32_t PxBroadPhaseRegions_getNbOutOfBoundsObjects(physx_PxBroadPhaseRegions_Pod const* self__pod) {
        physx::PxBroadPhaseRegions const* self_ = reinterpret_cast<physx::PxBroadPhaseRegions const*>(self__pod);
        uint32_t return_val = self_->getNbOutOfBoundsObjects();
        return return_val;
    }

    uint32_t const* PxBroadPhaseRegions_getOutOfBoundsObjects(physx_PxBroadPhaseRegions_Pod const* self__pod) {
        physx::PxBroadPhaseRegions const* self_ = reinterpret_cast<physx::PxBroadPhaseRegions const*>(self__pod);
        uint32_t const* return_val = self_->getOutOfBoundsObjects();
        return return_val;
    }

    void PxBroadPhase_release_mut(physx_PxBroadPhase_Pod* self__pod) {
        physx::PxBroadPhase* self_ = reinterpret_cast<physx::PxBroadPhase*>(self__pod);
        self_->release();
    }

    int32_t PxBroadPhase_getType(physx_PxBroadPhase_Pod const* self__pod) {
        physx::PxBroadPhase const* self_ = reinterpret_cast<physx::PxBroadPhase const*>(self__pod);
        physx::PxBroadPhaseType::Enum return_val = self_->getType();
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxBroadPhase_getCaps(physx_PxBroadPhase_Pod const* self__pod, physx_PxBroadPhaseCaps_Pod* caps_pod) {
        physx::PxBroadPhase const* self_ = reinterpret_cast<physx::PxBroadPhase const*>(self__pod);
        physx::PxBroadPhaseCaps& caps = reinterpret_cast<physx::PxBroadPhaseCaps&>(*caps_pod);
        self_->getCaps(caps);
    }

    physx_PxBroadPhaseRegions_Pod* PxBroadPhase_getRegions_mut(physx_PxBroadPhase_Pod* self__pod) {
        physx::PxBroadPhase* self_ = reinterpret_cast<physx::PxBroadPhase*>(self__pod);
        physx::PxBroadPhaseRegions* return_val = self_->getRegions();
        auto return_val_pod = reinterpret_cast<physx_PxBroadPhaseRegions_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxAllocatorCallback_Pod* PxBroadPhase_getAllocator_mut(physx_PxBroadPhase_Pod* self__pod) {
        physx::PxBroadPhase* self_ = reinterpret_cast<physx::PxBroadPhase*>(self__pod);
        physx::PxAllocatorCallback* return_val = self_->getAllocator();
        auto return_val_pod = reinterpret_cast<physx_PxAllocatorCallback_Pod*>(return_val);
        return return_val_pod;
    }

    uint64_t PxBroadPhase_getContextID(physx_PxBroadPhase_Pod const* self__pod) {
        physx::PxBroadPhase const* self_ = reinterpret_cast<physx::PxBroadPhase const*>(self__pod);
        uint64_t return_val = self_->getContextID();
        return return_val;
    }

    void PxBroadPhase_setScratchBlock_mut(physx_PxBroadPhase_Pod* self__pod, void* scratchBlock, uint32_t size) {
        physx::PxBroadPhase* self_ = reinterpret_cast<physx::PxBroadPhase*>(self__pod);
        self_->setScratchBlock(scratchBlock, size);
    }

    void PxBroadPhase_update_mut(physx_PxBroadPhase_Pod* self__pod, physx_PxBroadPhaseUpdateData_Pod const* updateData_pod, physx_PxBaseTask_Pod* continuation_pod) {
        physx::PxBroadPhase* self_ = reinterpret_cast<physx::PxBroadPhase*>(self__pod);
        physx::PxBroadPhaseUpdateData const& updateData = reinterpret_cast<physx::PxBroadPhaseUpdateData const&>(*updateData_pod);
        physx::PxBaseTask* continuation = reinterpret_cast<physx::PxBaseTask*>(continuation_pod);
        self_->update(updateData, continuation);
    }

    void PxBroadPhase_fetchResults_mut(physx_PxBroadPhase_Pod* self__pod, physx_PxBroadPhaseResults_Pod* results_pod) {
        physx::PxBroadPhase* self_ = reinterpret_cast<physx::PxBroadPhase*>(self__pod);
        physx::PxBroadPhaseResults& results = reinterpret_cast<physx::PxBroadPhaseResults&>(*results_pod);
        self_->fetchResults(results);
    }

    void PxBroadPhase_update_mut_1(physx_PxBroadPhase_Pod* self__pod, physx_PxBroadPhaseResults_Pod* results_pod, physx_PxBroadPhaseUpdateData_Pod const* updateData_pod) {
        physx::PxBroadPhase* self_ = reinterpret_cast<physx::PxBroadPhase*>(self__pod);
        physx::PxBroadPhaseResults& results = reinterpret_cast<physx::PxBroadPhaseResults&>(*results_pod);
        physx::PxBroadPhaseUpdateData const& updateData = reinterpret_cast<physx::PxBroadPhaseUpdateData const&>(*updateData_pod);
        self_->update(results, updateData);
    }

    physx_PxBroadPhase_Pod* phys_PxCreateBroadPhase(physx_PxBroadPhaseDesc_Pod const* desc_pod) {
        physx::PxBroadPhaseDesc const& desc = reinterpret_cast<physx::PxBroadPhaseDesc const&>(*desc_pod);
        physx::PxBroadPhase* return_val = PxCreateBroadPhase(desc);
        auto return_val_pod = reinterpret_cast<physx_PxBroadPhase_Pod*>(return_val);
        return return_val_pod;
    }

    void PxAABBManager_release_mut(physx_PxAABBManager_Pod* self__pod) {
        physx::PxAABBManager* self_ = reinterpret_cast<physx::PxAABBManager*>(self__pod);
        self_->release();
    }

    physx_PxBroadPhase_Pod* PxAABBManager_getBroadPhase_mut(physx_PxAABBManager_Pod* self__pod) {
        physx::PxAABBManager* self_ = reinterpret_cast<physx::PxAABBManager*>(self__pod);
        physx::PxBroadPhase& return_val = self_->getBroadPhase();
        auto return_val_pod = reinterpret_cast<physx_PxBroadPhase_Pod*>(&return_val);
        return return_val_pod;
    }

    physx_PxBounds3_Pod const* PxAABBManager_getBounds(physx_PxAABBManager_Pod const* self__pod) {
        physx::PxAABBManager const* self_ = reinterpret_cast<physx::PxAABBManager const*>(self__pod);
        physx::PxBounds3 const* return_val = self_->getBounds();
        auto return_val_pod = reinterpret_cast<physx_PxBounds3_Pod const*>(return_val);
        return return_val_pod;
    }

    float const* PxAABBManager_getDistances(physx_PxAABBManager_Pod const* self__pod) {
        physx::PxAABBManager const* self_ = reinterpret_cast<physx::PxAABBManager const*>(self__pod);
        float const* return_val = self_->getDistances();
        return return_val;
    }

    uint32_t const* PxAABBManager_getGroups(physx_PxAABBManager_Pod const* self__pod) {
        physx::PxAABBManager const* self_ = reinterpret_cast<physx::PxAABBManager const*>(self__pod);
        uint32_t const* return_val = self_->getGroups();
        return return_val;
    }

    uint32_t PxAABBManager_getCapacity(physx_PxAABBManager_Pod const* self__pod) {
        physx::PxAABBManager const* self_ = reinterpret_cast<physx::PxAABBManager const*>(self__pod);
        uint32_t return_val = self_->getCapacity();
        return return_val;
    }

    void PxAABBManager_addObject_mut(physx_PxAABBManager_Pod* self__pod, uint32_t index, physx_PxBounds3_Pod const* bounds_pod, uint32_t group, float distance) {
        physx::PxAABBManager* self_ = reinterpret_cast<physx::PxAABBManager*>(self__pod);
        physx::PxBounds3 const& bounds = reinterpret_cast<physx::PxBounds3 const&>(*bounds_pod);
        self_->addObject(index, bounds, group, distance);
    }

    void PxAABBManager_removeObject_mut(physx_PxAABBManager_Pod* self__pod, uint32_t index) {
        physx::PxAABBManager* self_ = reinterpret_cast<physx::PxAABBManager*>(self__pod);
        self_->removeObject(index);
    }

    void PxAABBManager_updateObject_mut(physx_PxAABBManager_Pod* self__pod, uint32_t index, physx_PxBounds3_Pod const* bounds_pod, float const* distance) {
        physx::PxAABBManager* self_ = reinterpret_cast<physx::PxAABBManager*>(self__pod);
        physx::PxBounds3 const* bounds = reinterpret_cast<physx::PxBounds3 const*>(bounds_pod);
        self_->updateObject(index, bounds, distance);
    }

    void PxAABBManager_update_mut(physx_PxAABBManager_Pod* self__pod, physx_PxBaseTask_Pod* continuation_pod) {
        physx::PxAABBManager* self_ = reinterpret_cast<physx::PxAABBManager*>(self__pod);
        physx::PxBaseTask* continuation = reinterpret_cast<physx::PxBaseTask*>(continuation_pod);
        self_->update(continuation);
    }

    void PxAABBManager_fetchResults_mut(physx_PxAABBManager_Pod* self__pod, physx_PxBroadPhaseResults_Pod* results_pod) {
        physx::PxAABBManager* self_ = reinterpret_cast<physx::PxAABBManager*>(self__pod);
        physx::PxBroadPhaseResults& results = reinterpret_cast<physx::PxBroadPhaseResults&>(*results_pod);
        self_->fetchResults(results);
    }

    void PxAABBManager_update_mut_1(physx_PxAABBManager_Pod* self__pod, physx_PxBroadPhaseResults_Pod* results_pod) {
        physx::PxAABBManager* self_ = reinterpret_cast<physx::PxAABBManager*>(self__pod);
        physx::PxBroadPhaseResults& results = reinterpret_cast<physx::PxBroadPhaseResults&>(*results_pod);
        self_->update(results);
    }

    physx_PxAABBManager_Pod* phys_PxCreateAABBManager(physx_PxBroadPhase_Pod* broadphase_pod) {
        physx::PxBroadPhase& broadphase = reinterpret_cast<physx::PxBroadPhase&>(*broadphase_pod);
        physx::PxAABBManager* return_val = PxCreateAABBManager(broadphase);
        auto return_val_pod = reinterpret_cast<physx_PxAABBManager_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxSceneLimits_Pod PxSceneLimits_new() {
        PxSceneLimits return_val;
        physx_PxSceneLimits_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxSceneLimits_setToDefault_mut(physx_PxSceneLimits_Pod* self__pod) {
        physx::PxSceneLimits* self_ = reinterpret_cast<physx::PxSceneLimits*>(self__pod);
        self_->setToDefault();
    }

    bool PxSceneLimits_isValid(physx_PxSceneLimits_Pod const* self__pod) {
        physx::PxSceneLimits const* self_ = reinterpret_cast<physx::PxSceneLimits const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    physx_PxgDynamicsMemoryConfig_Pod PxgDynamicsMemoryConfig_new() {
        PxgDynamicsMemoryConfig return_val;
        physx_PxgDynamicsMemoryConfig_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxgDynamicsMemoryConfig_isValid(physx_PxgDynamicsMemoryConfig_Pod const* self__pod) {
        physx::PxgDynamicsMemoryConfig const* self_ = reinterpret_cast<physx::PxgDynamicsMemoryConfig const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    physx_PxSceneDesc_Pod PxSceneDesc_new(physx_PxTolerancesScale_Pod const* scale_pod) {
        physx::PxTolerancesScale const& scale = reinterpret_cast<physx::PxTolerancesScale const&>(*scale_pod);
        PxSceneDesc return_val(scale);
        physx_PxSceneDesc_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxSceneDesc_setToDefault_mut(physx_PxSceneDesc_Pod* self__pod, physx_PxTolerancesScale_Pod const* scale_pod) {
        physx::PxSceneDesc* self_ = reinterpret_cast<physx::PxSceneDesc*>(self__pod);
        physx::PxTolerancesScale const& scale = reinterpret_cast<physx::PxTolerancesScale const&>(*scale_pod);
        self_->setToDefault(scale);
    }

    bool PxSceneDesc_isValid(physx_PxSceneDesc_Pod const* self__pod) {
        physx::PxSceneDesc const* self_ = reinterpret_cast<physx::PxSceneDesc const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    physx_PxTolerancesScale_Pod const* PxSceneDesc_getTolerancesScale(physx_PxSceneDesc_Pod const* self__pod) {
        physx::PxSceneDesc const* self_ = reinterpret_cast<physx::PxSceneDesc const*>(self__pod);
        physx::PxTolerancesScale const& return_val = self_->getTolerancesScale();
        auto return_val_pod = reinterpret_cast<physx_PxTolerancesScale_Pod const*>(&return_val);
        return return_val_pod;
    }

    uint32_t PxSimulationStatistics_getNbBroadPhaseAdds(physx_PxSimulationStatistics_Pod const* self__pod) {
        physx::PxSimulationStatistics const* self_ = reinterpret_cast<physx::PxSimulationStatistics const*>(self__pod);
        uint32_t return_val = self_->getNbBroadPhaseAdds();
        return return_val;
    }

    uint32_t PxSimulationStatistics_getNbBroadPhaseRemoves(physx_PxSimulationStatistics_Pod const* self__pod) {
        physx::PxSimulationStatistics const* self_ = reinterpret_cast<physx::PxSimulationStatistics const*>(self__pod);
        uint32_t return_val = self_->getNbBroadPhaseRemoves();
        return return_val;
    }

    uint32_t PxSimulationStatistics_getRbPairStats(physx_PxSimulationStatistics_Pod const* self__pod, int32_t pairType_pod, int32_t g0_pod, int32_t g1_pod) {
        physx::PxSimulationStatistics const* self_ = reinterpret_cast<physx::PxSimulationStatistics const*>(self__pod);
        auto pairType = static_cast<physx::PxSimulationStatistics::RbPairStatsType>(pairType_pod);
        auto g0 = static_cast<physx::PxGeometryType::Enum>(g0_pod);
        auto g1 = static_cast<physx::PxGeometryType::Enum>(g1_pod);
        uint32_t return_val = self_->getRbPairStats(pairType, g0, g1);
        return return_val;
    }

    physx_PxSimulationStatistics_Pod PxSimulationStatistics_new() {
        PxSimulationStatistics return_val;
        physx_PxSimulationStatistics_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxPvdSceneClient_setScenePvdFlag_mut(physx_PxPvdSceneClient_Pod* self__pod, int32_t flag_pod, bool value) {
        physx::PxPvdSceneClient* self_ = reinterpret_cast<physx::PxPvdSceneClient*>(self__pod);
        auto flag = static_cast<physx::PxPvdSceneFlag::Enum>(flag_pod);
        self_->setScenePvdFlag(flag, value);
    }

    void PxPvdSceneClient_setScenePvdFlags_mut(physx_PxPvdSceneClient_Pod* self__pod, uint8_t flags_pod) {
        physx::PxPvdSceneClient* self_ = reinterpret_cast<physx::PxPvdSceneClient*>(self__pod);
        auto flags = physx::PxPvdSceneFlags(flags_pod);
        self_->setScenePvdFlags(flags);
    }

    uint8_t PxPvdSceneClient_getScenePvdFlags(physx_PxPvdSceneClient_Pod const* self__pod) {
        physx::PxPvdSceneClient const* self_ = reinterpret_cast<physx::PxPvdSceneClient const*>(self__pod);
        physx::PxPvdSceneFlags return_val = self_->getScenePvdFlags();
        uint8_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxPvdSceneClient_updateCamera_mut(physx_PxPvdSceneClient_Pod* self__pod, char const* name, physx_PxVec3_Pod const* origin_pod, physx_PxVec3_Pod const* up_pod, physx_PxVec3_Pod const* target_pod) {
        physx::PxPvdSceneClient* self_ = reinterpret_cast<physx::PxPvdSceneClient*>(self__pod);
        physx::PxVec3 const& origin = reinterpret_cast<physx::PxVec3 const&>(*origin_pod);
        physx::PxVec3 const& up = reinterpret_cast<physx::PxVec3 const&>(*up_pod);
        physx::PxVec3 const& target = reinterpret_cast<physx::PxVec3 const&>(*target_pod);
        self_->updateCamera(name, origin, up, target);
    }

    void PxPvdSceneClient_drawPoints_mut(physx_PxPvdSceneClient_Pod* self__pod, physx_PxDebugPoint_Pod const* points_pod, uint32_t count) {
        physx::PxPvdSceneClient* self_ = reinterpret_cast<physx::PxPvdSceneClient*>(self__pod);
        physx::PxDebugPoint const* points = reinterpret_cast<physx::PxDebugPoint const*>(points_pod);
        self_->drawPoints(points, count);
    }

    void PxPvdSceneClient_drawLines_mut(physx_PxPvdSceneClient_Pod* self__pod, physx_PxDebugLine_Pod const* lines_pod, uint32_t count) {
        physx::PxPvdSceneClient* self_ = reinterpret_cast<physx::PxPvdSceneClient*>(self__pod);
        physx::PxDebugLine const* lines = reinterpret_cast<physx::PxDebugLine const*>(lines_pod);
        self_->drawLines(lines, count);
    }

    void PxPvdSceneClient_drawTriangles_mut(physx_PxPvdSceneClient_Pod* self__pod, physx_PxDebugTriangle_Pod const* triangles_pod, uint32_t count) {
        physx::PxPvdSceneClient* self_ = reinterpret_cast<physx::PxPvdSceneClient*>(self__pod);
        physx::PxDebugTriangle const* triangles = reinterpret_cast<physx::PxDebugTriangle const*>(triangles_pod);
        self_->drawTriangles(triangles, count);
    }

    void PxPvdSceneClient_drawText_mut(physx_PxPvdSceneClient_Pod* self__pod, physx_PxDebugText_Pod const* text_pod) {
        physx::PxPvdSceneClient* self_ = reinterpret_cast<physx::PxPvdSceneClient*>(self__pod);
        physx::PxDebugText const& text = reinterpret_cast<physx::PxDebugText const&>(*text_pod);
        self_->drawText(text);
    }

    physx_PxDominanceGroupPair_Pod PxDominanceGroupPair_new(uint8_t a, uint8_t b) {
        PxDominanceGroupPair return_val(a, b);
        physx_PxDominanceGroupPair_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
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

    void PxScene_release_mut(physx_PxScene_Pod* self__pod) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        self_->release();
    }

    void PxScene_setFlag_mut(physx_PxScene_Pod* self__pod, int32_t flag_pod, bool value) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        auto flag = static_cast<physx::PxSceneFlag::Enum>(flag_pod);
        self_->setFlag(flag, value);
    }

    uint32_t PxScene_getFlags(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        physx::PxSceneFlags return_val = self_->getFlags();
        uint32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxScene_setLimits_mut(physx_PxScene_Pod* self__pod, physx_PxSceneLimits_Pod const* limits_pod) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxSceneLimits const& limits = reinterpret_cast<physx::PxSceneLimits const&>(*limits_pod);
        self_->setLimits(limits);
    }

    physx_PxSceneLimits_Pod PxScene_getLimits(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        physx::PxSceneLimits return_val = self_->getLimits();
        physx_PxSceneLimits_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxPhysics_Pod* PxScene_getPhysics_mut(physx_PxScene_Pod* self__pod) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxPhysics& return_val = self_->getPhysics();
        auto return_val_pod = reinterpret_cast<physx_PxPhysics_Pod*>(&return_val);
        return return_val_pod;
    }

    uint32_t PxScene_getTimestamp(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        uint32_t return_val = self_->getTimestamp();
        return return_val;
    }

    bool PxScene_addArticulation_mut(physx_PxScene_Pod* self__pod, physx_PxArticulationReducedCoordinate_Pod* articulation_pod) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxArticulationReducedCoordinate& articulation = reinterpret_cast<physx::PxArticulationReducedCoordinate&>(*articulation_pod);
        bool return_val = self_->addArticulation(articulation);
        return return_val;
    }

    void PxScene_removeArticulation_mut(physx_PxScene_Pod* self__pod, physx_PxArticulationReducedCoordinate_Pod* articulation_pod, bool wakeOnLostTouch) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxArticulationReducedCoordinate& articulation = reinterpret_cast<physx::PxArticulationReducedCoordinate&>(*articulation_pod);
        self_->removeArticulation(articulation, wakeOnLostTouch);
    }

    bool PxScene_addActor_mut(physx_PxScene_Pod* self__pod, physx_PxActor_Pod* actor_pod, physx_PxBVH_Pod const* bvh_pod) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxActor& actor = reinterpret_cast<physx::PxActor&>(*actor_pod);
        physx::PxBVH const* bvh = reinterpret_cast<physx::PxBVH const*>(bvh_pod);
        bool return_val = self_->addActor(actor, bvh);
        return return_val;
    }

    bool PxScene_addActors_mut(physx_PxScene_Pod* self__pod, physx_PxActor_Pod* const* actors_pod, uint32_t nbActors) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxActor* const* actors = reinterpret_cast<physx::PxActor* const*>(actors_pod);
        bool return_val = self_->addActors(actors, nbActors);
        return return_val;
    }

    bool PxScene_addActors_mut_1(physx_PxScene_Pod* self__pod, physx_PxPruningStructure_Pod const* pruningStructure_pod) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxPruningStructure const& pruningStructure = reinterpret_cast<physx::PxPruningStructure const&>(*pruningStructure_pod);
        bool return_val = self_->addActors(pruningStructure);
        return return_val;
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

    bool PxScene_addAggregate_mut(physx_PxScene_Pod* self__pod, physx_PxAggregate_Pod* aggregate_pod) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxAggregate& aggregate = reinterpret_cast<physx::PxAggregate&>(*aggregate_pod);
        bool return_val = self_->addAggregate(aggregate);
        return return_val;
    }

    void PxScene_removeAggregate_mut(physx_PxScene_Pod* self__pod, physx_PxAggregate_Pod* aggregate_pod, bool wakeOnLostTouch) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxAggregate& aggregate = reinterpret_cast<physx::PxAggregate&>(*aggregate_pod);
        self_->removeAggregate(aggregate, wakeOnLostTouch);
    }

    bool PxScene_addCollection_mut(physx_PxScene_Pod* self__pod, physx_PxCollection_Pod const* collection_pod) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxCollection const& collection = reinterpret_cast<physx::PxCollection const&>(*collection_pod);
        bool return_val = self_->addCollection(collection);
        return return_val;
    }

    uint32_t PxScene_getNbActors(physx_PxScene_Pod const* self__pod, uint16_t types_pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        auto types = physx::PxActorTypeFlags(types_pod);
        uint32_t return_val = self_->getNbActors(types);
        return return_val;
    }

    uint32_t PxScene_getActors(physx_PxScene_Pod const* self__pod, uint16_t types_pod, physx_PxActor_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        auto types = physx::PxActorTypeFlags(types_pod);
        physx::PxActor** userBuffer = reinterpret_cast<physx::PxActor**>(userBuffer_pod);
        uint32_t return_val = self_->getActors(types, userBuffer, bufferSize, startIndex);
        return return_val;
    }

    physx_PxActor_Pod** PxScene_getActiveActors_mut(physx_PxScene_Pod* self__pod, uint32_t* nbActorsOut_pod) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        uint32_t& nbActorsOut = *nbActorsOut_pod;
        physx::PxActor** return_val = self_->getActiveActors(nbActorsOut);
        auto return_val_pod = reinterpret_cast<physx_PxActor_Pod**>(return_val);
        return return_val_pod;
    }

    uint32_t PxScene_getNbArticulations(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        uint32_t return_val = self_->getNbArticulations();
        return return_val;
    }

    uint32_t PxScene_getArticulations(physx_PxScene_Pod const* self__pod, physx_PxArticulationReducedCoordinate_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        physx::PxArticulationReducedCoordinate** userBuffer = reinterpret_cast<physx::PxArticulationReducedCoordinate**>(userBuffer_pod);
        uint32_t return_val = self_->getArticulations(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    uint32_t PxScene_getNbConstraints(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        uint32_t return_val = self_->getNbConstraints();
        return return_val;
    }

    uint32_t PxScene_getConstraints(physx_PxScene_Pod const* self__pod, physx_PxConstraint_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        physx::PxConstraint** userBuffer = reinterpret_cast<physx::PxConstraint**>(userBuffer_pod);
        uint32_t return_val = self_->getConstraints(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    uint32_t PxScene_getNbAggregates(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        uint32_t return_val = self_->getNbAggregates();
        return return_val;
    }

    uint32_t PxScene_getAggregates(physx_PxScene_Pod const* self__pod, physx_PxAggregate_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        physx::PxAggregate** userBuffer = reinterpret_cast<physx::PxAggregate**>(userBuffer_pod);
        uint32_t return_val = self_->getAggregates(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    void PxScene_setDominanceGroupPair_mut(physx_PxScene_Pod* self__pod, uint8_t group1, uint8_t group2, physx_PxDominanceGroupPair_Pod const* dominance_pod) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxDominanceGroupPair const& dominance = reinterpret_cast<physx::PxDominanceGroupPair const&>(*dominance_pod);
        self_->setDominanceGroupPair(group1, group2, dominance);
    }

    physx_PxDominanceGroupPair_Pod PxScene_getDominanceGroupPair(physx_PxScene_Pod const* self__pod, uint8_t group1, uint8_t group2) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        physx::PxDominanceGroupPair return_val = self_->getDominanceGroupPair(group1, group2);
        physx_PxDominanceGroupPair_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxCpuDispatcher_Pod* PxScene_getCpuDispatcher(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        physx::PxCpuDispatcher* return_val = self_->getCpuDispatcher();
        auto return_val_pod = reinterpret_cast<physx_PxCpuDispatcher_Pod*>(return_val);
        return return_val_pod;
    }

    uint8_t PxScene_createClient_mut(physx_PxScene_Pod* self__pod) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        uint8_t return_val = self_->createClient();
        return return_val;
    }

    void PxScene_setSimulationEventCallback_mut(physx_PxScene_Pod* self__pod, physx_PxSimulationEventCallback_Pod* callback_pod) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxSimulationEventCallback* callback = reinterpret_cast<physx::PxSimulationEventCallback*>(callback_pod);
        self_->setSimulationEventCallback(callback);
    }

    physx_PxSimulationEventCallback_Pod* PxScene_getSimulationEventCallback(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        physx::PxSimulationEventCallback* return_val = self_->getSimulationEventCallback();
        auto return_val_pod = reinterpret_cast<physx_PxSimulationEventCallback_Pod*>(return_val);
        return return_val_pod;
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
        physx::PxContactModifyCallback* return_val = self_->getContactModifyCallback();
        auto return_val_pod = reinterpret_cast<physx_PxContactModifyCallback_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxCCDContactModifyCallback_Pod* PxScene_getCCDContactModifyCallback(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        physx::PxCCDContactModifyCallback* return_val = self_->getCCDContactModifyCallback();
        auto return_val_pod = reinterpret_cast<physx_PxCCDContactModifyCallback_Pod*>(return_val);
        return return_val_pod;
    }

    void PxScene_setBroadPhaseCallback_mut(physx_PxScene_Pod* self__pod, physx_PxBroadPhaseCallback_Pod* callback_pod) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxBroadPhaseCallback* callback = reinterpret_cast<physx::PxBroadPhaseCallback*>(callback_pod);
        self_->setBroadPhaseCallback(callback);
    }

    physx_PxBroadPhaseCallback_Pod* PxScene_getBroadPhaseCallback(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        physx::PxBroadPhaseCallback* return_val = self_->getBroadPhaseCallback();
        auto return_val_pod = reinterpret_cast<physx_PxBroadPhaseCallback_Pod*>(return_val);
        return return_val_pod;
    }

    void PxScene_setFilterShaderData_mut(physx_PxScene_Pod* self__pod, void const* data, uint32_t dataSize) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        self_->setFilterShaderData(data, dataSize);
    }

    void const* PxScene_getFilterShaderData(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        void const* return_val = self_->getFilterShaderData();
        return return_val;
    }

    uint32_t PxScene_getFilterShaderDataSize(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        uint32_t return_val = self_->getFilterShaderDataSize();
        return return_val;
    }

    bool PxScene_resetFiltering_mut(physx_PxScene_Pod* self__pod, physx_PxActor_Pod* actor_pod) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxActor& actor = reinterpret_cast<physx::PxActor&>(*actor_pod);
        bool return_val = self_->resetFiltering(actor);
        return return_val;
    }

    bool PxScene_resetFiltering_mut_1(physx_PxScene_Pod* self__pod, physx_PxRigidActor_Pod* actor_pod, physx_PxShape_Pod* const* shapes_pod, uint32_t shapeCount) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxRigidActor& actor = reinterpret_cast<physx::PxRigidActor&>(*actor_pod);
        physx::PxShape* const* shapes = reinterpret_cast<physx::PxShape* const*>(shapes_pod);
        bool return_val = self_->resetFiltering(actor, shapes, shapeCount);
        return return_val;
    }

    int32_t PxScene_getKinematicKinematicFilteringMode(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        physx::PxPairFilteringMode::Enum return_val = self_->getKinematicKinematicFilteringMode();
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    int32_t PxScene_getStaticKinematicFilteringMode(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        physx::PxPairFilteringMode::Enum return_val = self_->getStaticKinematicFilteringMode();
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxScene_simulate_mut(physx_PxScene_Pod* self__pod, float elapsedTime, physx_PxBaseTask_Pod* completionTask_pod, void* scratchMemBlock, uint32_t scratchMemBlockSize, bool controlSimulation) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxBaseTask* completionTask = reinterpret_cast<physx::PxBaseTask*>(completionTask_pod);
        bool return_val = self_->simulate(elapsedTime, completionTask, scratchMemBlock, scratchMemBlockSize, controlSimulation);
        return return_val;
    }

    bool PxScene_advance_mut(physx_PxScene_Pod* self__pod, physx_PxBaseTask_Pod* completionTask_pod) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxBaseTask* completionTask = reinterpret_cast<physx::PxBaseTask*>(completionTask_pod);
        bool return_val = self_->advance(completionTask);
        return return_val;
    }

    bool PxScene_collide_mut(physx_PxScene_Pod* self__pod, float elapsedTime, physx_PxBaseTask_Pod* completionTask_pod, void* scratchMemBlock, uint32_t scratchMemBlockSize, bool controlSimulation) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxBaseTask* completionTask = reinterpret_cast<physx::PxBaseTask*>(completionTask_pod);
        bool return_val = self_->collide(elapsedTime, completionTask, scratchMemBlock, scratchMemBlockSize, controlSimulation);
        return return_val;
    }

    bool PxScene_checkResults_mut(physx_PxScene_Pod* self__pod, bool block) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        bool return_val = self_->checkResults(block);
        return return_val;
    }

    bool PxScene_fetchCollision_mut(physx_PxScene_Pod* self__pod, bool block) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        bool return_val = self_->fetchCollision(block);
        return return_val;
    }

    bool PxScene_fetchResults_mut(physx_PxScene_Pod* self__pod, bool block, uint32_t* errorState) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        bool return_val = self_->fetchResults(block, errorState);
        return return_val;
    }

    bool PxScene_fetchResultsStart_mut(physx_PxScene_Pod* self__pod, physx_PxContactPairHeader_Pod const** contactPairs_pod, uint32_t* nbContactPairs_pod, bool block) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxContactPairHeader const*& contactPairs = reinterpret_cast<physx::PxContactPairHeader const*&>(*contactPairs_pod);
        uint32_t& nbContactPairs = *nbContactPairs_pod;
        bool return_val = self_->fetchResultsStart(contactPairs, nbContactPairs, block);
        return return_val;
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

    void PxScene_fetchResultsParticleSystem_mut(physx_PxScene_Pod* self__pod) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        self_->fetchResultsParticleSystem();
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
        physx::PxVec3 return_val = self_->getGravity();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxScene_setBounceThresholdVelocity_mut(physx_PxScene_Pod* self__pod, float t) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        self_->setBounceThresholdVelocity(t);
    }

    float PxScene_getBounceThresholdVelocity(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        float return_val = self_->getBounceThresholdVelocity();
        return return_val;
    }

    void PxScene_setCCDMaxPasses_mut(physx_PxScene_Pod* self__pod, uint32_t ccdMaxPasses) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        self_->setCCDMaxPasses(ccdMaxPasses);
    }

    uint32_t PxScene_getCCDMaxPasses(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        uint32_t return_val = self_->getCCDMaxPasses();
        return return_val;
    }

    void PxScene_setCCDMaxSeparation_mut(physx_PxScene_Pod* self__pod, float t) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        self_->setCCDMaxSeparation(t);
    }

    float PxScene_getCCDMaxSeparation(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        float return_val = self_->getCCDMaxSeparation();
        return return_val;
    }

    void PxScene_setCCDThreshold_mut(physx_PxScene_Pod* self__pod, float t) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        self_->setCCDThreshold(t);
    }

    float PxScene_getCCDThreshold(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        float return_val = self_->getCCDThreshold();
        return return_val;
    }

    void PxScene_setMaxBiasCoefficient_mut(physx_PxScene_Pod* self__pod, float t) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        self_->setMaxBiasCoefficient(t);
    }

    float PxScene_getMaxBiasCoefficient(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        float return_val = self_->getMaxBiasCoefficient();
        return return_val;
    }

    void PxScene_setFrictionOffsetThreshold_mut(physx_PxScene_Pod* self__pod, float t) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        self_->setFrictionOffsetThreshold(t);
    }

    float PxScene_getFrictionOffsetThreshold(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        float return_val = self_->getFrictionOffsetThreshold();
        return return_val;
    }

    void PxScene_setFrictionCorrelationDistance_mut(physx_PxScene_Pod* self__pod, float t) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        self_->setFrictionCorrelationDistance(t);
    }

    float PxScene_getFrictionCorrelationDistance(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        float return_val = self_->getFrictionCorrelationDistance();
        return return_val;
    }

    int32_t PxScene_getFrictionType(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        physx::PxFrictionType::Enum return_val = self_->getFrictionType();
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    int32_t PxScene_getSolverType(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        physx::PxSolverType::Enum return_val = self_->getSolverType();
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxScene_setVisualizationParameter_mut(physx_PxScene_Pod* self__pod, int32_t param_pod, float value) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        auto param = static_cast<physx::PxVisualizationParameter::Enum>(param_pod);
        bool return_val = self_->setVisualizationParameter(param, value);
        return return_val;
    }

    float PxScene_getVisualizationParameter(physx_PxScene_Pod const* self__pod, int32_t paramEnum_pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        auto paramEnum = static_cast<physx::PxVisualizationParameter::Enum>(paramEnum_pod);
        float return_val = self_->getVisualizationParameter(paramEnum);
        return return_val;
    }

    void PxScene_setVisualizationCullingBox_mut(physx_PxScene_Pod* self__pod, physx_PxBounds3_Pod const* box_pod) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxBounds3 const& box = reinterpret_cast<physx::PxBounds3 const&>(*box_pod);
        self_->setVisualizationCullingBox(box);
    }

    physx_PxBounds3_Pod PxScene_getVisualizationCullingBox(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        physx::PxBounds3 return_val = self_->getVisualizationCullingBox();
        physx_PxBounds3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxRenderBuffer_Pod const* PxScene_getRenderBuffer_mut(physx_PxScene_Pod* self__pod) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxRenderBuffer const& return_val = self_->getRenderBuffer();
        auto return_val_pod = reinterpret_cast<physx_PxRenderBuffer_Pod const*>(&return_val);
        return return_val_pod;
    }

    void PxScene_getSimulationStatistics(physx_PxScene_Pod const* self__pod, physx_PxSimulationStatistics_Pod* stats_pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        physx::PxSimulationStatistics& stats = reinterpret_cast<physx::PxSimulationStatistics&>(*stats_pod);
        self_->getSimulationStatistics(stats);
    }

    int32_t PxScene_getBroadPhaseType(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        physx::PxBroadPhaseType::Enum return_val = self_->getBroadPhaseType();
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxScene_getBroadPhaseCaps(physx_PxScene_Pod const* self__pod, physx_PxBroadPhaseCaps_Pod* caps_pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        physx::PxBroadPhaseCaps& caps = reinterpret_cast<physx::PxBroadPhaseCaps&>(*caps_pod);
        bool return_val = self_->getBroadPhaseCaps(caps);
        return return_val;
    }

    uint32_t PxScene_getNbBroadPhaseRegions(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        uint32_t return_val = self_->getNbBroadPhaseRegions();
        return return_val;
    }

    uint32_t PxScene_getBroadPhaseRegions(physx_PxScene_Pod const* self__pod, physx_PxBroadPhaseRegionInfo_Pod* userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        physx::PxBroadPhaseRegionInfo* userBuffer = reinterpret_cast<physx::PxBroadPhaseRegionInfo*>(userBuffer_pod);
        uint32_t return_val = self_->getBroadPhaseRegions(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    uint32_t PxScene_addBroadPhaseRegion_mut(physx_PxScene_Pod* self__pod, physx_PxBroadPhaseRegion_Pod const* region_pod, bool populateRegion) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxBroadPhaseRegion const& region = reinterpret_cast<physx::PxBroadPhaseRegion const&>(*region_pod);
        uint32_t return_val = self_->addBroadPhaseRegion(region, populateRegion);
        return return_val;
    }

    bool PxScene_removeBroadPhaseRegion_mut(physx_PxScene_Pod* self__pod, uint32_t handle) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        bool return_val = self_->removeBroadPhaseRegion(handle);
        return return_val;
    }

    physx_PxTaskManager_Pod* PxScene_getTaskManager(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        physx::PxTaskManager* return_val = self_->getTaskManager();
        auto return_val_pod = reinterpret_cast<physx_PxTaskManager_Pod*>(return_val);
        return return_val_pod;
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
        uint32_t return_val = self_->getNbContactDataBlocksUsed();
        return return_val;
    }

    uint32_t PxScene_getMaxNbContactDataBlocksUsed(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        uint32_t return_val = self_->getMaxNbContactDataBlocksUsed();
        return return_val;
    }

    uint32_t PxScene_getContactReportStreamBufferSize(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        uint32_t return_val = self_->getContactReportStreamBufferSize();
        return return_val;
    }

    void PxScene_setSolverBatchSize_mut(physx_PxScene_Pod* self__pod, uint32_t solverBatchSize) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        self_->setSolverBatchSize(solverBatchSize);
    }

    uint32_t PxScene_getSolverBatchSize(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        uint32_t return_val = self_->getSolverBatchSize();
        return return_val;
    }

    void PxScene_setSolverArticulationBatchSize_mut(physx_PxScene_Pod* self__pod, uint32_t solverBatchSize) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        self_->setSolverArticulationBatchSize(solverBatchSize);
    }

    uint32_t PxScene_getSolverArticulationBatchSize(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        uint32_t return_val = self_->getSolverArticulationBatchSize();
        return return_val;
    }

    float PxScene_getWakeCounterResetValue(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        float return_val = self_->getWakeCounterResetValue();
        return return_val;
    }

    void PxScene_shiftOrigin_mut(physx_PxScene_Pod* self__pod, physx_PxVec3_Pod const* shift_pod) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxVec3 const& shift = reinterpret_cast<physx::PxVec3 const&>(*shift_pod);
        self_->shiftOrigin(shift);
    }

    physx_PxPvdSceneClient_Pod* PxScene_getScenePvdClient_mut(physx_PxScene_Pod* self__pod) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxPvdSceneClient* return_val = self_->getScenePvdClient();
        auto return_val_pod = reinterpret_cast<physx_PxPvdSceneClient_Pod*>(return_val);
        return return_val_pod;
    }

    void PxScene_copyArticulationData_mut(physx_PxScene_Pod* self__pod, void* data, void* index, int32_t dataType_pod, uint32_t nbCopyArticulations, void* copyEvent) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        auto dataType = static_cast<physx::PxArticulationGpuDataType::Enum>(dataType_pod);
        self_->copyArticulationData(data, index, dataType, nbCopyArticulations, copyEvent);
    }

    void PxScene_applyArticulationData_mut(physx_PxScene_Pod* self__pod, void* data, void* index, int32_t dataType_pod, uint32_t nbUpdatedArticulations, void* waitEvent, void* signalEvent) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        auto dataType = static_cast<physx::PxArticulationGpuDataType::Enum>(dataType_pod);
        self_->applyArticulationData(data, index, dataType, nbUpdatedArticulations, waitEvent, signalEvent);
    }

    void PxScene_copySoftBodyData_mut(physx_PxScene_Pod* self__pod, void** data, void* dataSizes, void* softBodyIndices, int32_t flag_pod, uint32_t nbCopySoftBodies, uint32_t maxSize, void* copyEvent) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        auto flag = static_cast<physx::PxSoftBodyDataFlag::Enum>(flag_pod);
        self_->copySoftBodyData(data, dataSizes, softBodyIndices, flag, nbCopySoftBodies, maxSize, copyEvent);
    }

    void PxScene_applySoftBodyData_mut(physx_PxScene_Pod* self__pod, void** data, void* dataSizes, void* softBodyIndices, int32_t flag_pod, uint32_t nbUpdatedSoftBodies, uint32_t maxSize, void* applyEvent) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        auto flag = static_cast<physx::PxSoftBodyDataFlag::Enum>(flag_pod);
        self_->applySoftBodyData(data, dataSizes, softBodyIndices, flag, nbUpdatedSoftBodies, maxSize, applyEvent);
    }

    void PxScene_copyContactData_mut(physx_PxScene_Pod* self__pod, void* data, uint32_t maxContactPairs, void* numContactPairs, void* copyEvent) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        self_->copyContactData(data, maxContactPairs, numContactPairs, copyEvent);
    }

    void PxScene_copyBodyData_mut(physx_PxScene_Pod* self__pod, physx_PxGpuBodyData_Pod* data_pod, physx_PxGpuActorPair_Pod* index_pod, uint32_t nbCopyActors, void* copyEvent) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxGpuBodyData* data = reinterpret_cast<physx::PxGpuBodyData*>(data_pod);
        physx::PxGpuActorPair* index = reinterpret_cast<physx::PxGpuActorPair*>(index_pod);
        self_->copyBodyData(data, index, nbCopyActors, copyEvent);
    }

    void PxScene_applyActorData_mut(physx_PxScene_Pod* self__pod, void* data, physx_PxGpuActorPair_Pod* index_pod, int32_t flag_pod, uint32_t nbUpdatedActors, void* waitEvent, void* signalEvent) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxGpuActorPair* index = reinterpret_cast<physx::PxGpuActorPair*>(index_pod);
        auto flag = static_cast<physx::PxActorCacheFlag::Enum>(flag_pod);
        self_->applyActorData(data, index, flag, nbUpdatedActors, waitEvent, signalEvent);
    }

    void PxScene_computeDenseJacobians_mut(physx_PxScene_Pod* self__pod, physx_PxIndexDataPair_Pod const* indices_pod, uint32_t nbIndices, void* computeEvent) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxIndexDataPair const* indices = reinterpret_cast<physx::PxIndexDataPair const*>(indices_pod);
        self_->computeDenseJacobians(indices, nbIndices, computeEvent);
    }

    void PxScene_computeGeneralizedMassMatrices_mut(physx_PxScene_Pod* self__pod, physx_PxIndexDataPair_Pod const* indices_pod, uint32_t nbIndices, void* computeEvent) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxIndexDataPair const* indices = reinterpret_cast<physx::PxIndexDataPair const*>(indices_pod);
        self_->computeGeneralizedMassMatrices(indices, nbIndices, computeEvent);
    }

    void PxScene_computeGeneralizedGravityForces_mut(physx_PxScene_Pod* self__pod, physx_PxIndexDataPair_Pod const* indices_pod, uint32_t nbIndices, void* computeEvent) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxIndexDataPair const* indices = reinterpret_cast<physx::PxIndexDataPair const*>(indices_pod);
        self_->computeGeneralizedGravityForces(indices, nbIndices, computeEvent);
    }

    void PxScene_computeCoriolisAndCentrifugalForces_mut(physx_PxScene_Pod* self__pod, physx_PxIndexDataPair_Pod const* indices_pod, uint32_t nbIndices, void* computeEvent) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxIndexDataPair const* indices = reinterpret_cast<physx::PxIndexDataPair const*>(indices_pod);
        self_->computeCoriolisAndCentrifugalForces(indices, nbIndices, computeEvent);
    }

    physx_PxgDynamicsMemoryConfig_Pod PxScene_getGpuDynamicsConfig(physx_PxScene_Pod const* self__pod) {
        physx::PxScene const* self_ = reinterpret_cast<physx::PxScene const*>(self__pod);
        physx::PxgDynamicsMemoryConfig return_val = self_->getGpuDynamicsConfig();
        physx_PxgDynamicsMemoryConfig_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxScene_applyParticleBufferData_mut(physx_PxScene_Pod* self__pod, uint32_t const* indices, physx_PxGpuParticleBufferIndexPair_Pod const* bufferIndexPair_pod, uint32_t const* flags_pod, uint32_t nbUpdatedBuffers, void* waitEvent, void* signalEvent) {
        physx::PxScene* self_ = reinterpret_cast<physx::PxScene*>(self__pod);
        physx::PxGpuParticleBufferIndexPair const* bufferIndexPair = reinterpret_cast<physx::PxGpuParticleBufferIndexPair const*>(bufferIndexPair_pod);
        physx::PxParticleBufferFlags const* flags = reinterpret_cast<physx::PxParticleBufferFlags const*>(flags_pod);
        self_->applyParticleBufferData(indices, bufferIndexPair, flags, nbUpdatedBuffers, waitEvent, signalEvent);
    }

    physx_PxSceneReadLock_Pod* PxSceneReadLock_new_alloc(physx_PxScene_Pod* scene_pod, char const* file, uint32_t line) {
        physx::PxScene& scene = reinterpret_cast<physx::PxScene&>(*scene_pod);
        auto return_val = new physx::PxSceneReadLock(scene, file, line);
        auto return_val_pod = reinterpret_cast<physx_PxSceneReadLock_Pod*>(return_val);
        return return_val_pod;
    }

    void PxSceneReadLock_delete(physx_PxSceneReadLock_Pod* self__pod) {
        physx::PxSceneReadLock* self_ = reinterpret_cast<physx::PxSceneReadLock*>(self__pod);
        delete self_;
    }

    physx_PxSceneWriteLock_Pod* PxSceneWriteLock_new_alloc(physx_PxScene_Pod* scene_pod, char const* file, uint32_t line) {
        physx::PxScene& scene = reinterpret_cast<physx::PxScene&>(*scene_pod);
        auto return_val = new physx::PxSceneWriteLock(scene, file, line);
        auto return_val_pod = reinterpret_cast<physx_PxSceneWriteLock_Pod*>(return_val);
        return return_val_pod;
    }

    void PxSceneWriteLock_delete(physx_PxSceneWriteLock_Pod* self__pod) {
        physx::PxSceneWriteLock* self_ = reinterpret_cast<physx::PxSceneWriteLock*>(self__pod);
        delete self_;
    }

    physx_PxContactPairExtraDataItem_Pod PxContactPairExtraDataItem_new() {
        PxContactPairExtraDataItem return_val;
        physx_PxContactPairExtraDataItem_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxContactPairVelocity_Pod PxContactPairVelocity_new() {
        PxContactPairVelocity return_val;
        physx_PxContactPairVelocity_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxContactPairPose_Pod PxContactPairPose_new() {
        PxContactPairPose return_val;
        physx_PxContactPairPose_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxContactPairIndex_Pod PxContactPairIndex_new() {
        PxContactPairIndex return_val;
        physx_PxContactPairIndex_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxContactPairExtraDataIterator_Pod PxContactPairExtraDataIterator_new(uint8_t const* stream, uint32_t size) {
        PxContactPairExtraDataIterator return_val(stream, size);
        physx_PxContactPairExtraDataIterator_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxContactPairExtraDataIterator_nextItemSet_mut(physx_PxContactPairExtraDataIterator_Pod* self__pod) {
        physx::PxContactPairExtraDataIterator* self_ = reinterpret_cast<physx::PxContactPairExtraDataIterator*>(self__pod);
        bool return_val = self_->nextItemSet();
        return return_val;
    }

    physx_PxContactPairHeader_Pod PxContactPairHeader_new() {
        PxContactPairHeader return_val;
        physx_PxContactPairHeader_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxContactPair_Pod PxContactPair_new() {
        PxContactPair return_val;
        physx_PxContactPair_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    uint32_t PxContactPair_extractContacts(physx_PxContactPair_Pod const* self__pod, physx_PxContactPairPoint_Pod* userBuffer_pod, uint32_t bufferSize) {
        physx::PxContactPair const* self_ = reinterpret_cast<physx::PxContactPair const*>(self__pod);
        physx::PxContactPairPoint* userBuffer = reinterpret_cast<physx::PxContactPairPoint*>(userBuffer_pod);
        uint32_t return_val = self_->extractContacts(userBuffer, bufferSize);
        return return_val;
    }

    void PxContactPair_bufferContacts(physx_PxContactPair_Pod const* self__pod, physx_PxContactPair_Pod* newPair_pod, uint8_t* bufferMemory) {
        physx::PxContactPair const* self_ = reinterpret_cast<physx::PxContactPair const*>(self__pod);
        physx::PxContactPair* newPair = reinterpret_cast<physx::PxContactPair*>(newPair_pod);
        self_->bufferContacts(newPair, bufferMemory);
    }

    uint32_t const* PxContactPair_getInternalFaceIndices(physx_PxContactPair_Pod const* self__pod) {
        physx::PxContactPair const* self_ = reinterpret_cast<physx::PxContactPair const*>(self__pod);
        uint32_t const* return_val = self_->getInternalFaceIndices();
        return return_val;
    }

    physx_PxTriggerPair_Pod PxTriggerPair_new() {
        PxTriggerPair return_val;
        physx_PxTriggerPair_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxConstraintInfo_Pod PxConstraintInfo_new() {
        PxConstraintInfo return_val;
        physx_PxConstraintInfo_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxConstraintInfo_Pod PxConstraintInfo_new_1(physx_PxConstraint_Pod* c_pod, void* extRef, uint32_t t) {
        physx::PxConstraint* c = reinterpret_cast<physx::PxConstraint*>(c_pod);
        PxConstraintInfo return_val(c, extRef, t);
        physx_PxConstraintInfo_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
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

    physx_PxFEMParameters_Pod PxFEMParameters_new() {
        PxFEMParameters return_val;
        physx_PxFEMParameters_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxPruningStructure_release_mut(physx_PxPruningStructure_Pod* self__pod) {
        physx::PxPruningStructure* self_ = reinterpret_cast<physx::PxPruningStructure*>(self__pod);
        self_->release();
    }

    uint32_t PxPruningStructure_getRigidActors(physx_PxPruningStructure_Pod const* self__pod, physx_PxRigidActor_Pod** userBuffer_pod, uint32_t bufferSize, uint32_t startIndex) {
        physx::PxPruningStructure const* self_ = reinterpret_cast<physx::PxPruningStructure const*>(self__pod);
        physx::PxRigidActor** userBuffer = reinterpret_cast<physx::PxRigidActor**>(userBuffer_pod);
        uint32_t return_val = self_->getRigidActors(userBuffer, bufferSize, startIndex);
        return return_val;
    }

    uint32_t PxPruningStructure_getNbRigidActors(physx_PxPruningStructure_Pod const* self__pod) {
        physx::PxPruningStructure const* self_ = reinterpret_cast<physx::PxPruningStructure const*>(self__pod);
        uint32_t return_val = self_->getNbRigidActors();
        return return_val;
    }

    void const* PxPruningStructure_getStaticMergeData(physx_PxPruningStructure_Pod const* self__pod) {
        physx::PxPruningStructure const* self_ = reinterpret_cast<physx::PxPruningStructure const*>(self__pod);
        void const* return_val = self_->getStaticMergeData();
        return return_val;
    }

    void const* PxPruningStructure_getDynamicMergeData(physx_PxPruningStructure_Pod const* self__pod) {
        physx::PxPruningStructure const* self_ = reinterpret_cast<physx::PxPruningStructure const*>(self__pod);
        void const* return_val = self_->getDynamicMergeData();
        return return_val;
    }

    char const* PxPruningStructure_getConcreteTypeName(physx_PxPruningStructure_Pod const* self__pod) {
        physx::PxPruningStructure const* self_ = reinterpret_cast<physx::PxPruningStructure const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    physx_PxExtendedVec3_Pod PxExtendedVec3_new() {
        PxExtendedVec3 return_val;
        physx_PxExtendedVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxExtendedVec3_Pod PxExtendedVec3_new_1(double _x, double _y, double _z) {
        PxExtendedVec3 return_val(_x, _y, _z);
        physx_PxExtendedVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxExtendedVec3_isZero(physx_PxExtendedVec3_Pod const* self__pod) {
        physx::PxExtendedVec3 const* self_ = reinterpret_cast<physx::PxExtendedVec3 const*>(self__pod);
        bool return_val = self_->isZero();
        return return_val;
    }

    double PxExtendedVec3_dot(physx_PxExtendedVec3_Pod const* self__pod, physx_PxVec3_Pod const* v_pod) {
        physx::PxExtendedVec3 const* self_ = reinterpret_cast<physx::PxExtendedVec3 const*>(self__pod);
        physx::PxVec3 const& v = reinterpret_cast<physx::PxVec3 const&>(*v_pod);
        double return_val = self_->dot(v);
        return return_val;
    }

    double PxExtendedVec3_distanceSquared(physx_PxExtendedVec3_Pod const* self__pod, physx_PxExtendedVec3_Pod const* v_pod) {
        physx::PxExtendedVec3 const* self_ = reinterpret_cast<physx::PxExtendedVec3 const*>(self__pod);
        physx::PxExtendedVec3 const& v = reinterpret_cast<physx::PxExtendedVec3 const&>(*v_pod);
        double return_val = self_->distanceSquared(v);
        return return_val;
    }

    double PxExtendedVec3_magnitudeSquared(physx_PxExtendedVec3_Pod const* self__pod) {
        physx::PxExtendedVec3 const* self_ = reinterpret_cast<physx::PxExtendedVec3 const*>(self__pod);
        double return_val = self_->magnitudeSquared();
        return return_val;
    }

    double PxExtendedVec3_magnitude(physx_PxExtendedVec3_Pod const* self__pod) {
        physx::PxExtendedVec3 const* self_ = reinterpret_cast<physx::PxExtendedVec3 const*>(self__pod);
        double return_val = self_->magnitude();
        return return_val;
    }

    double PxExtendedVec3_normalize_mut(physx_PxExtendedVec3_Pod* self__pod) {
        physx::PxExtendedVec3* self_ = reinterpret_cast<physx::PxExtendedVec3*>(self__pod);
        double return_val = self_->normalize();
        return return_val;
    }

    bool PxExtendedVec3_isFinite(physx_PxExtendedVec3_Pod const* self__pod) {
        physx::PxExtendedVec3 const* self_ = reinterpret_cast<physx::PxExtendedVec3 const*>(self__pod);
        bool return_val = self_->isFinite();
        return return_val;
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
        physx::PxExtendedVec3 return_val = self_->cross(v);
        physx_PxExtendedVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxExtendedVec3_cross_mut_2(physx_PxExtendedVec3_Pod* self__pod, physx_PxVec3_Pod const* left_pod, physx_PxExtendedVec3_Pod const* right_pod) {
        physx::PxExtendedVec3* self_ = reinterpret_cast<physx::PxExtendedVec3*>(self__pod);
        physx::PxVec3 const& left = reinterpret_cast<physx::PxVec3 const&>(*left_pod);
        physx::PxExtendedVec3 const& right = reinterpret_cast<physx::PxExtendedVec3 const&>(*right_pod);
        self_->cross(left, right);
    }

    physx_PxVec3_Pod phys_toVec3(physx_PxExtendedVec3_Pod const* v_pod) {
        physx::PxExtendedVec3 const& v = reinterpret_cast<physx::PxExtendedVec3 const&>(*v_pod);
        physx::PxVec3 return_val = toVec3(v);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    int32_t PxObstacle_getType(physx_PxObstacle_Pod const* self__pod) {
        physx::PxObstacle const* self_ = reinterpret_cast<physx::PxObstacle const*>(self__pod);
        physx::PxGeometryType::Enum return_val = self_->getType();
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxBoxObstacle_Pod PxBoxObstacle_new() {
        PxBoxObstacle return_val;
        physx_PxBoxObstacle_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxCapsuleObstacle_Pod PxCapsuleObstacle_new() {
        PxCapsuleObstacle return_val;
        physx_PxCapsuleObstacle_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxObstacleContext_release_mut(physx_PxObstacleContext_Pod* self__pod) {
        physx::PxObstacleContext* self_ = reinterpret_cast<physx::PxObstacleContext*>(self__pod);
        self_->release();
    }

    physx_PxControllerManager_Pod* PxObstacleContext_getControllerManager(physx_PxObstacleContext_Pod const* self__pod) {
        physx::PxObstacleContext const* self_ = reinterpret_cast<physx::PxObstacleContext const*>(self__pod);
        physx::PxControllerManager& return_val = self_->getControllerManager();
        auto return_val_pod = reinterpret_cast<physx_PxControllerManager_Pod*>(&return_val);
        return return_val_pod;
    }

    uint32_t PxObstacleContext_addObstacle_mut(physx_PxObstacleContext_Pod* self__pod, physx_PxObstacle_Pod const* obstacle_pod) {
        physx::PxObstacleContext* self_ = reinterpret_cast<physx::PxObstacleContext*>(self__pod);
        physx::PxObstacle const& obstacle = reinterpret_cast<physx::PxObstacle const&>(*obstacle_pod);
        uint32_t return_val = self_->addObstacle(obstacle);
        return return_val;
    }

    bool PxObstacleContext_removeObstacle_mut(physx_PxObstacleContext_Pod* self__pod, uint32_t handle) {
        physx::PxObstacleContext* self_ = reinterpret_cast<physx::PxObstacleContext*>(self__pod);
        bool return_val = self_->removeObstacle(handle);
        return return_val;
    }

    bool PxObstacleContext_updateObstacle_mut(physx_PxObstacleContext_Pod* self__pod, uint32_t handle, physx_PxObstacle_Pod const* obstacle_pod) {
        physx::PxObstacleContext* self_ = reinterpret_cast<physx::PxObstacleContext*>(self__pod);
        physx::PxObstacle const& obstacle = reinterpret_cast<physx::PxObstacle const&>(*obstacle_pod);
        bool return_val = self_->updateObstacle(handle, obstacle);
        return return_val;
    }

    uint32_t PxObstacleContext_getNbObstacles(physx_PxObstacleContext_Pod const* self__pod) {
        physx::PxObstacleContext const* self_ = reinterpret_cast<physx::PxObstacleContext const*>(self__pod);
        uint32_t return_val = self_->getNbObstacles();
        return return_val;
    }

    physx_PxObstacle_Pod const* PxObstacleContext_getObstacle(physx_PxObstacleContext_Pod const* self__pod, uint32_t i) {
        physx::PxObstacleContext const* self_ = reinterpret_cast<physx::PxObstacleContext const*>(self__pod);
        physx::PxObstacle const* return_val = self_->getObstacle(i);
        auto return_val_pod = reinterpret_cast<physx_PxObstacle_Pod const*>(return_val);
        return return_val_pod;
    }

    physx_PxObstacle_Pod const* PxObstacleContext_getObstacleByHandle(physx_PxObstacleContext_Pod const* self__pod, uint32_t handle) {
        physx::PxObstacleContext const* self_ = reinterpret_cast<physx::PxObstacleContext const*>(self__pod);
        physx::PxObstacle const* return_val = self_->getObstacleByHandle(handle);
        auto return_val_pod = reinterpret_cast<physx_PxObstacle_Pod const*>(return_val);
        return return_val_pod;
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
        bool return_val = self_->filter(a, b);
        return return_val;
    }

    physx_PxControllerFilters_Pod PxControllerFilters_new(physx_PxFilterData_Pod const* filterData_pod, physx_PxQueryFilterCallback_Pod* cb_pod, physx_PxControllerFilterCallback_Pod* cctFilterCb_pod) {
        physx::PxFilterData const* filterData = reinterpret_cast<physx::PxFilterData const*>(filterData_pod);
        physx::PxQueryFilterCallback* cb = reinterpret_cast<physx::PxQueryFilterCallback*>(cb_pod);
        physx::PxControllerFilterCallback* cctFilterCb = reinterpret_cast<physx::PxControllerFilterCallback*>(cctFilterCb_pod);
        PxControllerFilters return_val(filterData, cb, cctFilterCb);
        physx_PxControllerFilters_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxControllerDesc_isValid(physx_PxControllerDesc_Pod const* self__pod) {
        physx::PxControllerDesc const* self_ = reinterpret_cast<physx::PxControllerDesc const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    int32_t PxControllerDesc_getType(physx_PxControllerDesc_Pod const* self__pod) {
        physx::PxControllerDesc const* self_ = reinterpret_cast<physx::PxControllerDesc const*>(self__pod);
        physx::PxControllerShapeType::Enum return_val = self_->getType();
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    int32_t PxController_getType(physx_PxController_Pod const* self__pod) {
        physx::PxController const* self_ = reinterpret_cast<physx::PxController const*>(self__pod);
        physx::PxControllerShapeType::Enum return_val = self_->getType();
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxController_release_mut(physx_PxController_Pod* self__pod) {
        physx::PxController* self_ = reinterpret_cast<physx::PxController*>(self__pod);
        self_->release();
    }

    uint8_t PxController_move_mut(physx_PxController_Pod* self__pod, physx_PxVec3_Pod const* disp_pod, float minDist, float elapsedTime, physx_PxControllerFilters_Pod const* filters_pod, physx_PxObstacleContext_Pod const* obstacles_pod) {
        physx::PxController* self_ = reinterpret_cast<physx::PxController*>(self__pod);
        physx::PxVec3 const& disp = reinterpret_cast<physx::PxVec3 const&>(*disp_pod);
        physx::PxControllerFilters const& filters = reinterpret_cast<physx::PxControllerFilters const&>(*filters_pod);
        physx::PxObstacleContext const* obstacles = reinterpret_cast<physx::PxObstacleContext const*>(obstacles_pod);
        physx::PxControllerCollisionFlags return_val = self_->move(disp, minDist, elapsedTime, filters, obstacles);
        uint8_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxController_setPosition_mut(physx_PxController_Pod* self__pod, physx_PxExtendedVec3_Pod const* position_pod) {
        physx::PxController* self_ = reinterpret_cast<physx::PxController*>(self__pod);
        physx::PxExtendedVec3 const& position = reinterpret_cast<physx::PxExtendedVec3 const&>(*position_pod);
        bool return_val = self_->setPosition(position);
        return return_val;
    }

    physx_PxExtendedVec3_Pod const* PxController_getPosition(physx_PxController_Pod const* self__pod) {
        physx::PxController const* self_ = reinterpret_cast<physx::PxController const*>(self__pod);
        physx::PxExtendedVec3 const& return_val = self_->getPosition();
        auto return_val_pod = reinterpret_cast<physx_PxExtendedVec3_Pod const*>(&return_val);
        return return_val_pod;
    }

    bool PxController_setFootPosition_mut(physx_PxController_Pod* self__pod, physx_PxExtendedVec3_Pod const* position_pod) {
        physx::PxController* self_ = reinterpret_cast<physx::PxController*>(self__pod);
        physx::PxExtendedVec3 const& position = reinterpret_cast<physx::PxExtendedVec3 const&>(*position_pod);
        bool return_val = self_->setFootPosition(position);
        return return_val;
    }

    physx_PxExtendedVec3_Pod PxController_getFootPosition(physx_PxController_Pod const* self__pod) {
        physx::PxController const* self_ = reinterpret_cast<physx::PxController const*>(self__pod);
        physx::PxExtendedVec3 return_val = self_->getFootPosition();
        physx_PxExtendedVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxRigidDynamic_Pod* PxController_getActor(physx_PxController_Pod const* self__pod) {
        physx::PxController const* self_ = reinterpret_cast<physx::PxController const*>(self__pod);
        physx::PxRigidDynamic* return_val = self_->getActor();
        auto return_val_pod = reinterpret_cast<physx_PxRigidDynamic_Pod*>(return_val);
        return return_val_pod;
    }

    void PxController_setStepOffset_mut(physx_PxController_Pod* self__pod, float offset) {
        physx::PxController* self_ = reinterpret_cast<physx::PxController*>(self__pod);
        self_->setStepOffset(offset);
    }

    float PxController_getStepOffset(physx_PxController_Pod const* self__pod) {
        physx::PxController const* self_ = reinterpret_cast<physx::PxController const*>(self__pod);
        float return_val = self_->getStepOffset();
        return return_val;
    }

    void PxController_setNonWalkableMode_mut(physx_PxController_Pod* self__pod, int32_t flag_pod) {
        physx::PxController* self_ = reinterpret_cast<physx::PxController*>(self__pod);
        auto flag = static_cast<physx::PxControllerNonWalkableMode::Enum>(flag_pod);
        self_->setNonWalkableMode(flag);
    }

    int32_t PxController_getNonWalkableMode(physx_PxController_Pod const* self__pod) {
        physx::PxController const* self_ = reinterpret_cast<physx::PxController const*>(self__pod);
        physx::PxControllerNonWalkableMode::Enum return_val = self_->getNonWalkableMode();
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    float PxController_getContactOffset(physx_PxController_Pod const* self__pod) {
        physx::PxController const* self_ = reinterpret_cast<physx::PxController const*>(self__pod);
        float return_val = self_->getContactOffset();
        return return_val;
    }

    void PxController_setContactOffset_mut(physx_PxController_Pod* self__pod, float offset) {
        physx::PxController* self_ = reinterpret_cast<physx::PxController*>(self__pod);
        self_->setContactOffset(offset);
    }

    physx_PxVec3_Pod PxController_getUpDirection(physx_PxController_Pod const* self__pod) {
        physx::PxController const* self_ = reinterpret_cast<physx::PxController const*>(self__pod);
        physx::PxVec3 return_val = self_->getUpDirection();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxController_setUpDirection_mut(physx_PxController_Pod* self__pod, physx_PxVec3_Pod const* up_pod) {
        physx::PxController* self_ = reinterpret_cast<physx::PxController*>(self__pod);
        physx::PxVec3 const& up = reinterpret_cast<physx::PxVec3 const&>(*up_pod);
        self_->setUpDirection(up);
    }

    float PxController_getSlopeLimit(physx_PxController_Pod const* self__pod) {
        physx::PxController const* self_ = reinterpret_cast<physx::PxController const*>(self__pod);
        float return_val = self_->getSlopeLimit();
        return return_val;
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
        physx::PxScene* return_val = self_->getScene();
        auto return_val_pod = reinterpret_cast<physx_PxScene_Pod*>(return_val);
        return return_val_pod;
    }

    void* PxController_getUserData(physx_PxController_Pod const* self__pod) {
        physx::PxController const* self_ = reinterpret_cast<physx::PxController const*>(self__pod);
        void* return_val = self_->getUserData();
        return return_val;
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
        auto return_val = new physx::PxBoxControllerDesc();
        auto return_val_pod = reinterpret_cast<physx_PxBoxControllerDesc_Pod*>(return_val);
        return return_val_pod;
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
        bool return_val = self_->isValid();
        return return_val;
    }

    float PxBoxController_getHalfHeight(physx_PxBoxController_Pod const* self__pod) {
        physx::PxBoxController const* self_ = reinterpret_cast<physx::PxBoxController const*>(self__pod);
        float return_val = self_->getHalfHeight();
        return return_val;
    }

    float PxBoxController_getHalfSideExtent(physx_PxBoxController_Pod const* self__pod) {
        physx::PxBoxController const* self_ = reinterpret_cast<physx::PxBoxController const*>(self__pod);
        float return_val = self_->getHalfSideExtent();
        return return_val;
    }

    float PxBoxController_getHalfForwardExtent(physx_PxBoxController_Pod const* self__pod) {
        physx::PxBoxController const* self_ = reinterpret_cast<physx::PxBoxController const*>(self__pod);
        float return_val = self_->getHalfForwardExtent();
        return return_val;
    }

    bool PxBoxController_setHalfHeight_mut(physx_PxBoxController_Pod* self__pod, float halfHeight) {
        physx::PxBoxController* self_ = reinterpret_cast<physx::PxBoxController*>(self__pod);
        bool return_val = self_->setHalfHeight(halfHeight);
        return return_val;
    }

    bool PxBoxController_setHalfSideExtent_mut(physx_PxBoxController_Pod* self__pod, float halfSideExtent) {
        physx::PxBoxController* self_ = reinterpret_cast<physx::PxBoxController*>(self__pod);
        bool return_val = self_->setHalfSideExtent(halfSideExtent);
        return return_val;
    }

    bool PxBoxController_setHalfForwardExtent_mut(physx_PxBoxController_Pod* self__pod, float halfForwardExtent) {
        physx::PxBoxController* self_ = reinterpret_cast<physx::PxBoxController*>(self__pod);
        bool return_val = self_->setHalfForwardExtent(halfForwardExtent);
        return return_val;
    }

    physx_PxCapsuleControllerDesc_Pod* PxCapsuleControllerDesc_new_alloc() {
        auto return_val = new physx::PxCapsuleControllerDesc();
        auto return_val_pod = reinterpret_cast<physx_PxCapsuleControllerDesc_Pod*>(return_val);
        return return_val_pod;
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
        bool return_val = self_->isValid();
        return return_val;
    }

    float PxCapsuleController_getRadius(physx_PxCapsuleController_Pod const* self__pod) {
        physx::PxCapsuleController const* self_ = reinterpret_cast<physx::PxCapsuleController const*>(self__pod);
        float return_val = self_->getRadius();
        return return_val;
    }

    bool PxCapsuleController_setRadius_mut(physx_PxCapsuleController_Pod* self__pod, float radius) {
        physx::PxCapsuleController* self_ = reinterpret_cast<physx::PxCapsuleController*>(self__pod);
        bool return_val = self_->setRadius(radius);
        return return_val;
    }

    float PxCapsuleController_getHeight(physx_PxCapsuleController_Pod const* self__pod) {
        physx::PxCapsuleController const* self_ = reinterpret_cast<physx::PxCapsuleController const*>(self__pod);
        float return_val = self_->getHeight();
        return return_val;
    }

    bool PxCapsuleController_setHeight_mut(physx_PxCapsuleController_Pod* self__pod, float height) {
        physx::PxCapsuleController* self_ = reinterpret_cast<physx::PxCapsuleController*>(self__pod);
        bool return_val = self_->setHeight(height);
        return return_val;
    }

    int32_t PxCapsuleController_getClimbingMode(physx_PxCapsuleController_Pod const* self__pod) {
        physx::PxCapsuleController const* self_ = reinterpret_cast<physx::PxCapsuleController const*>(self__pod);
        physx::PxCapsuleClimbingMode::Enum return_val = self_->getClimbingMode();
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxCapsuleController_setClimbingMode_mut(physx_PxCapsuleController_Pod* self__pod, int32_t mode_pod) {
        physx::PxCapsuleController* self_ = reinterpret_cast<physx::PxCapsuleController*>(self__pod);
        auto mode = static_cast<physx::PxCapsuleClimbingMode::Enum>(mode_pod);
        bool return_val = self_->setClimbingMode(mode);
        return return_val;
    }

    uint8_t PxControllerBehaviorCallback_getBehaviorFlags_mut(physx_PxControllerBehaviorCallback_Pod* self__pod, physx_PxShape_Pod const* shape_pod, physx_PxActor_Pod const* actor_pod) {
        physx::PxControllerBehaviorCallback* self_ = reinterpret_cast<physx::PxControllerBehaviorCallback*>(self__pod);
        physx::PxShape const& shape = reinterpret_cast<physx::PxShape const&>(*shape_pod);
        physx::PxActor const& actor = reinterpret_cast<physx::PxActor const&>(*actor_pod);
        physx::PxControllerBehaviorFlags return_val = self_->getBehaviorFlags(shape, actor);
        uint8_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    uint8_t PxControllerBehaviorCallback_getBehaviorFlags_mut_1(physx_PxControllerBehaviorCallback_Pod* self__pod, physx_PxController_Pod const* controller_pod) {
        physx::PxControllerBehaviorCallback* self_ = reinterpret_cast<physx::PxControllerBehaviorCallback*>(self__pod);
        physx::PxController const& controller = reinterpret_cast<physx::PxController const&>(*controller_pod);
        physx::PxControllerBehaviorFlags return_val = self_->getBehaviorFlags(controller);
        uint8_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    uint8_t PxControllerBehaviorCallback_getBehaviorFlags_mut_2(physx_PxControllerBehaviorCallback_Pod* self__pod, physx_PxObstacle_Pod const* obstacle_pod) {
        physx::PxControllerBehaviorCallback* self_ = reinterpret_cast<physx::PxControllerBehaviorCallback*>(self__pod);
        physx::PxObstacle const& obstacle = reinterpret_cast<physx::PxObstacle const&>(*obstacle_pod);
        physx::PxControllerBehaviorFlags return_val = self_->getBehaviorFlags(obstacle);
        uint8_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxControllerManager_release_mut(physx_PxControllerManager_Pod* self__pod) {
        physx::PxControllerManager* self_ = reinterpret_cast<physx::PxControllerManager*>(self__pod);
        self_->release();
    }

    physx_PxScene_Pod* PxControllerManager_getScene(physx_PxControllerManager_Pod const* self__pod) {
        physx::PxControllerManager const* self_ = reinterpret_cast<physx::PxControllerManager const*>(self__pod);
        physx::PxScene& return_val = self_->getScene();
        auto return_val_pod = reinterpret_cast<physx_PxScene_Pod*>(&return_val);
        return return_val_pod;
    }

    uint32_t PxControllerManager_getNbControllers(physx_PxControllerManager_Pod const* self__pod) {
        physx::PxControllerManager const* self_ = reinterpret_cast<physx::PxControllerManager const*>(self__pod);
        uint32_t return_val = self_->getNbControllers();
        return return_val;
    }

    physx_PxController_Pod* PxControllerManager_getController_mut(physx_PxControllerManager_Pod* self__pod, uint32_t index) {
        physx::PxControllerManager* self_ = reinterpret_cast<physx::PxControllerManager*>(self__pod);
        physx::PxController* return_val = self_->getController(index);
        auto return_val_pod = reinterpret_cast<physx_PxController_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxController_Pod* PxControllerManager_createController_mut(physx_PxControllerManager_Pod* self__pod, physx_PxControllerDesc_Pod const* desc_pod) {
        physx::PxControllerManager* self_ = reinterpret_cast<physx::PxControllerManager*>(self__pod);
        physx::PxControllerDesc const& desc = reinterpret_cast<physx::PxControllerDesc const&>(*desc_pod);
        physx::PxController* return_val = self_->createController(desc);
        auto return_val_pod = reinterpret_cast<physx_PxController_Pod*>(return_val);
        return return_val_pod;
    }

    void PxControllerManager_purgeControllers_mut(physx_PxControllerManager_Pod* self__pod) {
        physx::PxControllerManager* self_ = reinterpret_cast<physx::PxControllerManager*>(self__pod);
        self_->purgeControllers();
    }

    physx_PxRenderBuffer_Pod* PxControllerManager_getRenderBuffer_mut(physx_PxControllerManager_Pod* self__pod) {
        physx::PxControllerManager* self_ = reinterpret_cast<physx::PxControllerManager*>(self__pod);
        physx::PxRenderBuffer& return_val = self_->getRenderBuffer();
        auto return_val_pod = reinterpret_cast<physx_PxRenderBuffer_Pod*>(&return_val);
        return return_val_pod;
    }

    void PxControllerManager_setDebugRenderingFlags_mut(physx_PxControllerManager_Pod* self__pod, uint32_t flags_pod) {
        physx::PxControllerManager* self_ = reinterpret_cast<physx::PxControllerManager*>(self__pod);
        auto flags = physx::PxControllerDebugRenderFlags(flags_pod);
        self_->setDebugRenderingFlags(flags);
    }

    uint32_t PxControllerManager_getNbObstacleContexts(physx_PxControllerManager_Pod const* self__pod) {
        physx::PxControllerManager const* self_ = reinterpret_cast<physx::PxControllerManager const*>(self__pod);
        uint32_t return_val = self_->getNbObstacleContexts();
        return return_val;
    }

    physx_PxObstacleContext_Pod* PxControllerManager_getObstacleContext_mut(physx_PxControllerManager_Pod* self__pod, uint32_t index) {
        physx::PxControllerManager* self_ = reinterpret_cast<physx::PxControllerManager*>(self__pod);
        physx::PxObstacleContext* return_val = self_->getObstacleContext(index);
        auto return_val_pod = reinterpret_cast<physx_PxObstacleContext_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxObstacleContext_Pod* PxControllerManager_createObstacleContext_mut(physx_PxControllerManager_Pod* self__pod) {
        physx::PxControllerManager* self_ = reinterpret_cast<physx::PxControllerManager*>(self__pod);
        physx::PxObstacleContext* return_val = self_->createObstacleContext();
        auto return_val_pod = reinterpret_cast<physx_PxObstacleContext_Pod*>(return_val);
        return return_val_pod;
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
        physx::PxControllerManager* return_val = PxCreateControllerManager(scene, lockingEnabled);
        auto return_val_pod = reinterpret_cast<physx_PxControllerManager_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxDim3_Pod PxDim3_new() {
        PxDim3 return_val;
        physx_PxDim3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxSDFDesc_Pod PxSDFDesc_new() {
        PxSDFDesc return_val;
        physx_PxSDFDesc_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxSDFDesc_isValid(physx_PxSDFDesc_Pod const* self__pod) {
        physx::PxSDFDesc const* self_ = reinterpret_cast<physx::PxSDFDesc const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    physx_PxConvexMeshDesc_Pod PxConvexMeshDesc_new() {
        PxConvexMeshDesc return_val;
        physx_PxConvexMeshDesc_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxConvexMeshDesc_setToDefault_mut(physx_PxConvexMeshDesc_Pod* self__pod) {
        physx::PxConvexMeshDesc* self_ = reinterpret_cast<physx::PxConvexMeshDesc*>(self__pod);
        self_->setToDefault();
    }

    bool PxConvexMeshDesc_isValid(physx_PxConvexMeshDesc_Pod const* self__pod) {
        physx::PxConvexMeshDesc const* self_ = reinterpret_cast<physx::PxConvexMeshDesc const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    physx_PxTriangleMeshDesc_Pod PxTriangleMeshDesc_new() {
        PxTriangleMeshDesc return_val;
        physx_PxTriangleMeshDesc_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxTriangleMeshDesc_setToDefault_mut(physx_PxTriangleMeshDesc_Pod* self__pod) {
        physx::PxTriangleMeshDesc* self_ = reinterpret_cast<physx::PxTriangleMeshDesc*>(self__pod);
        self_->setToDefault();
    }

    bool PxTriangleMeshDesc_isValid(physx_PxTriangleMeshDesc_Pod const* self__pod) {
        physx::PxTriangleMeshDesc const* self_ = reinterpret_cast<physx::PxTriangleMeshDesc const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    physx_PxTetrahedronMeshDesc_Pod PxTetrahedronMeshDesc_new() {
        PxTetrahedronMeshDesc return_val;
        physx_PxTetrahedronMeshDesc_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxTetrahedronMeshDesc_isValid(physx_PxTetrahedronMeshDesc_Pod const* self__pod) {
        physx::PxTetrahedronMeshDesc const* self_ = reinterpret_cast<physx::PxTetrahedronMeshDesc const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    physx_PxSoftBodySimulationDataDesc_Pod PxSoftBodySimulationDataDesc_new() {
        PxSoftBodySimulationDataDesc return_val;
        physx_PxSoftBodySimulationDataDesc_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxSoftBodySimulationDataDesc_isValid(physx_PxSoftBodySimulationDataDesc_Pod const* self__pod) {
        physx::PxSoftBodySimulationDataDesc const* self_ = reinterpret_cast<physx::PxSoftBodySimulationDataDesc const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    void PxBVH34MidphaseDesc_setToDefault_mut(physx_PxBVH34MidphaseDesc_Pod* self__pod) {
        physx::PxBVH34MidphaseDesc* self_ = reinterpret_cast<physx::PxBVH34MidphaseDesc*>(self__pod);
        self_->setToDefault();
    }

    bool PxBVH34MidphaseDesc_isValid(physx_PxBVH34MidphaseDesc_Pod const* self__pod) {
        physx::PxBVH34MidphaseDesc const* self_ = reinterpret_cast<physx::PxBVH34MidphaseDesc const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    physx_PxMidphaseDesc_Pod PxMidphaseDesc_new() {
        PxMidphaseDesc return_val;
        physx_PxMidphaseDesc_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    int32_t PxMidphaseDesc_getType(physx_PxMidphaseDesc_Pod const* self__pod) {
        physx::PxMidphaseDesc const* self_ = reinterpret_cast<physx::PxMidphaseDesc const*>(self__pod);
        physx::PxMeshMidPhase::Enum return_val = self_->getType();
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxMidphaseDesc_setToDefault_mut(physx_PxMidphaseDesc_Pod* self__pod, int32_t type_pod) {
        physx::PxMidphaseDesc* self_ = reinterpret_cast<physx::PxMidphaseDesc*>(self__pod);
        auto type = static_cast<physx::PxMeshMidPhase::Enum>(type_pod);
        self_->setToDefault(type);
    }

    bool PxMidphaseDesc_isValid(physx_PxMidphaseDesc_Pod const* self__pod) {
        physx::PxMidphaseDesc const* self_ = reinterpret_cast<physx::PxMidphaseDesc const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    physx_PxBVHDesc_Pod PxBVHDesc_new() {
        PxBVHDesc return_val;
        physx_PxBVHDesc_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxBVHDesc_setToDefault_mut(physx_PxBVHDesc_Pod* self__pod) {
        physx::PxBVHDesc* self_ = reinterpret_cast<physx::PxBVHDesc*>(self__pod);
        self_->setToDefault();
    }

    bool PxBVHDesc_isValid(physx_PxBVHDesc_Pod const* self__pod) {
        physx::PxBVHDesc const* self_ = reinterpret_cast<physx::PxBVHDesc const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    physx_PxCookingParams_Pod PxCookingParams_new(physx_PxTolerancesScale_Pod const* sc_pod) {
        physx::PxTolerancesScale const& sc = reinterpret_cast<physx::PxTolerancesScale const&>(*sc_pod);
        PxCookingParams return_val(sc);
        physx_PxCookingParams_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxInsertionCallback_Pod* phys_PxGetStandaloneInsertionCallback() {
        physx::PxInsertionCallback* return_val = PxGetStandaloneInsertionCallback();
        auto return_val_pod = reinterpret_cast<physx_PxInsertionCallback_Pod*>(return_val);
        return return_val_pod;
    }

    bool phys_PxCookBVH(physx_PxBVHDesc_Pod const* desc_pod, physx_PxOutputStream_Pod* stream_pod) {
        physx::PxBVHDesc const& desc = reinterpret_cast<physx::PxBVHDesc const&>(*desc_pod);
        physx::PxOutputStream& stream = reinterpret_cast<physx::PxOutputStream&>(*stream_pod);
        bool return_val = PxCookBVH(desc, stream);
        return return_val;
    }

    physx_PxBVH_Pod* phys_PxCreateBVH(physx_PxBVHDesc_Pod const* desc_pod, physx_PxInsertionCallback_Pod* insertionCallback_pod) {
        physx::PxBVHDesc const& desc = reinterpret_cast<physx::PxBVHDesc const&>(*desc_pod);
        physx::PxInsertionCallback& insertionCallback = reinterpret_cast<physx::PxInsertionCallback&>(*insertionCallback_pod);
        physx::PxBVH* return_val = PxCreateBVH(desc, insertionCallback);
        auto return_val_pod = reinterpret_cast<physx_PxBVH_Pod*>(return_val);
        return return_val_pod;
    }

    bool phys_PxCookHeightField(physx_PxHeightFieldDesc_Pod const* desc_pod, physx_PxOutputStream_Pod* stream_pod) {
        physx::PxHeightFieldDesc const& desc = reinterpret_cast<physx::PxHeightFieldDesc const&>(*desc_pod);
        physx::PxOutputStream& stream = reinterpret_cast<physx::PxOutputStream&>(*stream_pod);
        bool return_val = PxCookHeightField(desc, stream);
        return return_val;
    }

    physx_PxHeightField_Pod* phys_PxCreateHeightField(physx_PxHeightFieldDesc_Pod const* desc_pod, physx_PxInsertionCallback_Pod* insertionCallback_pod) {
        physx::PxHeightFieldDesc const& desc = reinterpret_cast<physx::PxHeightFieldDesc const&>(*desc_pod);
        physx::PxInsertionCallback& insertionCallback = reinterpret_cast<physx::PxInsertionCallback&>(*insertionCallback_pod);
        physx::PxHeightField* return_val = PxCreateHeightField(desc, insertionCallback);
        auto return_val_pod = reinterpret_cast<physx_PxHeightField_Pod*>(return_val);
        return return_val_pod;
    }

    bool phys_PxCookConvexMesh(physx_PxCookingParams_Pod const* params_pod, physx_PxConvexMeshDesc_Pod const* desc_pod, physx_PxOutputStream_Pod* stream_pod, int32_t* condition_pod) {
        physx::PxCookingParams const& params = reinterpret_cast<physx::PxCookingParams const&>(*params_pod);
        physx::PxConvexMeshDesc const& desc = reinterpret_cast<physx::PxConvexMeshDesc const&>(*desc_pod);
        physx::PxOutputStream& stream = reinterpret_cast<physx::PxOutputStream&>(*stream_pod);
        physx::PxConvexMeshCookingResult::Enum* condition = reinterpret_cast<physx::PxConvexMeshCookingResult::Enum*>(condition_pod);
        bool return_val = PxCookConvexMesh(params, desc, stream, condition);
        return return_val;
    }

    physx_PxConvexMesh_Pod* phys_PxCreateConvexMesh(physx_PxCookingParams_Pod const* params_pod, physx_PxConvexMeshDesc_Pod const* desc_pod, physx_PxInsertionCallback_Pod* insertionCallback_pod, int32_t* condition_pod) {
        physx::PxCookingParams const& params = reinterpret_cast<physx::PxCookingParams const&>(*params_pod);
        physx::PxConvexMeshDesc const& desc = reinterpret_cast<physx::PxConvexMeshDesc const&>(*desc_pod);
        physx::PxInsertionCallback& insertionCallback = reinterpret_cast<physx::PxInsertionCallback&>(*insertionCallback_pod);
        physx::PxConvexMeshCookingResult::Enum* condition = reinterpret_cast<physx::PxConvexMeshCookingResult::Enum*>(condition_pod);
        physx::PxConvexMesh* return_val = PxCreateConvexMesh(params, desc, insertionCallback, condition);
        auto return_val_pod = reinterpret_cast<physx_PxConvexMesh_Pod*>(return_val);
        return return_val_pod;
    }

    bool phys_PxValidateConvexMesh(physx_PxCookingParams_Pod const* params_pod, physx_PxConvexMeshDesc_Pod const* desc_pod) {
        physx::PxCookingParams const& params = reinterpret_cast<physx::PxCookingParams const&>(*params_pod);
        physx::PxConvexMeshDesc const& desc = reinterpret_cast<physx::PxConvexMeshDesc const&>(*desc_pod);
        bool return_val = PxValidateConvexMesh(params, desc);
        return return_val;
    }

    bool phys_PxComputeHullPolygons(physx_PxCookingParams_Pod const* params_pod, physx_PxSimpleTriangleMesh_Pod const* mesh_pod, physx_PxAllocatorCallback_Pod* inCallback_pod, uint32_t* nbVerts_pod, physx_PxVec3_Pod** vertices_pod, uint32_t* nbIndices_pod, uint32_t** indices_pod, uint32_t* nbPolygons_pod, physx_PxHullPolygon_Pod** hullPolygons_pod) {
        physx::PxCookingParams const& params = reinterpret_cast<physx::PxCookingParams const&>(*params_pod);
        physx::PxSimpleTriangleMesh const& mesh = reinterpret_cast<physx::PxSimpleTriangleMesh const&>(*mesh_pod);
        physx::PxAllocatorCallback& inCallback = reinterpret_cast<physx::PxAllocatorCallback&>(*inCallback_pod);
        uint32_t& nbVerts = *nbVerts_pod;
        physx::PxVec3*& vertices = reinterpret_cast<physx::PxVec3*&>(*vertices_pod);
        uint32_t& nbIndices = *nbIndices_pod;
        uint32_t*& indices = reinterpret_cast<uint32_t*&>(*indices_pod);
        uint32_t& nbPolygons = *nbPolygons_pod;
        physx::PxHullPolygon*& hullPolygons = reinterpret_cast<physx::PxHullPolygon*&>(*hullPolygons_pod);
        bool return_val = PxComputeHullPolygons(params, mesh, inCallback, nbVerts, vertices, nbIndices, indices, nbPolygons, hullPolygons);
        return return_val;
    }

    bool phys_PxValidateTriangleMesh(physx_PxCookingParams_Pod const* params_pod, physx_PxTriangleMeshDesc_Pod const* desc_pod) {
        physx::PxCookingParams const& params = reinterpret_cast<physx::PxCookingParams const&>(*params_pod);
        physx::PxTriangleMeshDesc const& desc = reinterpret_cast<physx::PxTriangleMeshDesc const&>(*desc_pod);
        bool return_val = PxValidateTriangleMesh(params, desc);
        return return_val;
    }

    physx_PxTriangleMesh_Pod* phys_PxCreateTriangleMesh(physx_PxCookingParams_Pod const* params_pod, physx_PxTriangleMeshDesc_Pod const* desc_pod, physx_PxInsertionCallback_Pod* insertionCallback_pod, int32_t* condition_pod) {
        physx::PxCookingParams const& params = reinterpret_cast<physx::PxCookingParams const&>(*params_pod);
        physx::PxTriangleMeshDesc const& desc = reinterpret_cast<physx::PxTriangleMeshDesc const&>(*desc_pod);
        physx::PxInsertionCallback& insertionCallback = reinterpret_cast<physx::PxInsertionCallback&>(*insertionCallback_pod);
        physx::PxTriangleMeshCookingResult::Enum* condition = reinterpret_cast<physx::PxTriangleMeshCookingResult::Enum*>(condition_pod);
        physx::PxTriangleMesh* return_val = PxCreateTriangleMesh(params, desc, insertionCallback, condition);
        auto return_val_pod = reinterpret_cast<physx_PxTriangleMesh_Pod*>(return_val);
        return return_val_pod;
    }

    bool phys_PxCookTriangleMesh(physx_PxCookingParams_Pod const* params_pod, physx_PxTriangleMeshDesc_Pod const* desc_pod, physx_PxOutputStream_Pod* stream_pod, int32_t* condition_pod) {
        physx::PxCookingParams const& params = reinterpret_cast<physx::PxCookingParams const&>(*params_pod);
        physx::PxTriangleMeshDesc const& desc = reinterpret_cast<physx::PxTriangleMeshDesc const&>(*desc_pod);
        physx::PxOutputStream& stream = reinterpret_cast<physx::PxOutputStream&>(*stream_pod);
        physx::PxTriangleMeshCookingResult::Enum* condition = reinterpret_cast<physx::PxTriangleMeshCookingResult::Enum*>(condition_pod);
        bool return_val = PxCookTriangleMesh(params, desc, stream, condition);
        return return_val;
    }

    physx_PxDefaultMemoryOutputStream_Pod* PxDefaultMemoryOutputStream_new_alloc(physx_PxAllocatorCallback_Pod* allocator_pod) {
        physx::PxAllocatorCallback& allocator = reinterpret_cast<physx::PxAllocatorCallback&>(*allocator_pod);
        auto return_val = new physx::PxDefaultMemoryOutputStream(allocator);
        auto return_val_pod = reinterpret_cast<physx_PxDefaultMemoryOutputStream_Pod*>(return_val);
        return return_val_pod;
    }

    void PxDefaultMemoryOutputStream_delete(physx_PxDefaultMemoryOutputStream_Pod* self__pod) {
        physx::PxDefaultMemoryOutputStream* self_ = reinterpret_cast<physx::PxDefaultMemoryOutputStream*>(self__pod);
        delete self_;
    }

    uint32_t PxDefaultMemoryOutputStream_write_mut(physx_PxDefaultMemoryOutputStream_Pod* self__pod, void const* src, uint32_t count) {
        physx::PxDefaultMemoryOutputStream* self_ = reinterpret_cast<physx::PxDefaultMemoryOutputStream*>(self__pod);
        uint32_t return_val = self_->write(src, count);
        return return_val;
    }

    uint32_t PxDefaultMemoryOutputStream_getSize(physx_PxDefaultMemoryOutputStream_Pod const* self__pod) {
        physx::PxDefaultMemoryOutputStream const* self_ = reinterpret_cast<physx::PxDefaultMemoryOutputStream const*>(self__pod);
        uint32_t return_val = self_->getSize();
        return return_val;
    }

    uint8_t* PxDefaultMemoryOutputStream_getData(physx_PxDefaultMemoryOutputStream_Pod const* self__pod) {
        physx::PxDefaultMemoryOutputStream const* self_ = reinterpret_cast<physx::PxDefaultMemoryOutputStream const*>(self__pod);
        uint8_t* return_val = self_->getData();
        return return_val;
    }

    physx_PxDefaultMemoryInputData_Pod* PxDefaultMemoryInputData_new_alloc(uint8_t* data, uint32_t length) {
        auto return_val = new physx::PxDefaultMemoryInputData(data, length);
        auto return_val_pod = reinterpret_cast<physx_PxDefaultMemoryInputData_Pod*>(return_val);
        return return_val_pod;
    }

    uint32_t PxDefaultMemoryInputData_read_mut(physx_PxDefaultMemoryInputData_Pod* self__pod, void* dest, uint32_t count) {
        physx::PxDefaultMemoryInputData* self_ = reinterpret_cast<physx::PxDefaultMemoryInputData*>(self__pod);
        uint32_t return_val = self_->read(dest, count);
        return return_val;
    }

    uint32_t PxDefaultMemoryInputData_getLength(physx_PxDefaultMemoryInputData_Pod const* self__pod) {
        physx::PxDefaultMemoryInputData const* self_ = reinterpret_cast<physx::PxDefaultMemoryInputData const*>(self__pod);
        uint32_t return_val = self_->getLength();
        return return_val;
    }

    void PxDefaultMemoryInputData_seek_mut(physx_PxDefaultMemoryInputData_Pod* self__pod, uint32_t pos) {
        physx::PxDefaultMemoryInputData* self_ = reinterpret_cast<physx::PxDefaultMemoryInputData*>(self__pod);
        self_->seek(pos);
    }

    uint32_t PxDefaultMemoryInputData_tell(physx_PxDefaultMemoryInputData_Pod const* self__pod) {
        physx::PxDefaultMemoryInputData const* self_ = reinterpret_cast<physx::PxDefaultMemoryInputData const*>(self__pod);
        uint32_t return_val = self_->tell();
        return return_val;
    }

    physx_PxDefaultFileOutputStream_Pod* PxDefaultFileOutputStream_new_alloc(char const* name) {
        auto return_val = new physx::PxDefaultFileOutputStream(name);
        auto return_val_pod = reinterpret_cast<physx_PxDefaultFileOutputStream_Pod*>(return_val);
        return return_val_pod;
    }

    void PxDefaultFileOutputStream_delete(physx_PxDefaultFileOutputStream_Pod* self__pod) {
        physx::PxDefaultFileOutputStream* self_ = reinterpret_cast<physx::PxDefaultFileOutputStream*>(self__pod);
        delete self_;
    }

    uint32_t PxDefaultFileOutputStream_write_mut(physx_PxDefaultFileOutputStream_Pod* self__pod, void const* src, uint32_t count) {
        physx::PxDefaultFileOutputStream* self_ = reinterpret_cast<physx::PxDefaultFileOutputStream*>(self__pod);
        uint32_t return_val = self_->write(src, count);
        return return_val;
    }

    bool PxDefaultFileOutputStream_isValid_mut(physx_PxDefaultFileOutputStream_Pod* self__pod) {
        physx::PxDefaultFileOutputStream* self_ = reinterpret_cast<physx::PxDefaultFileOutputStream*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    physx_PxDefaultFileInputData_Pod* PxDefaultFileInputData_new_alloc(char const* name) {
        auto return_val = new physx::PxDefaultFileInputData(name);
        auto return_val_pod = reinterpret_cast<physx_PxDefaultFileInputData_Pod*>(return_val);
        return return_val_pod;
    }

    void PxDefaultFileInputData_delete(physx_PxDefaultFileInputData_Pod* self__pod) {
        physx::PxDefaultFileInputData* self_ = reinterpret_cast<physx::PxDefaultFileInputData*>(self__pod);
        delete self_;
    }

    uint32_t PxDefaultFileInputData_read_mut(physx_PxDefaultFileInputData_Pod* self__pod, void* dest, uint32_t count) {
        physx::PxDefaultFileInputData* self_ = reinterpret_cast<physx::PxDefaultFileInputData*>(self__pod);
        uint32_t return_val = self_->read(dest, count);
        return return_val;
    }

    void PxDefaultFileInputData_seek_mut(physx_PxDefaultFileInputData_Pod* self__pod, uint32_t pos) {
        physx::PxDefaultFileInputData* self_ = reinterpret_cast<physx::PxDefaultFileInputData*>(self__pod);
        self_->seek(pos);
    }

    uint32_t PxDefaultFileInputData_tell(physx_PxDefaultFileInputData_Pod const* self__pod) {
        physx::PxDefaultFileInputData const* self_ = reinterpret_cast<physx::PxDefaultFileInputData const*>(self__pod);
        uint32_t return_val = self_->tell();
        return return_val;
    }

    uint32_t PxDefaultFileInputData_getLength(physx_PxDefaultFileInputData_Pod const* self__pod) {
        physx::PxDefaultFileInputData const* self_ = reinterpret_cast<physx::PxDefaultFileInputData const*>(self__pod);
        uint32_t return_val = self_->getLength();
        return return_val;
    }

    bool PxDefaultFileInputData_isValid(physx_PxDefaultFileInputData_Pod const* self__pod) {
        physx::PxDefaultFileInputData const* self_ = reinterpret_cast<physx::PxDefaultFileInputData const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    void* phys_platformAlignedAlloc(size_t size_pod) {
        size_t size;
        memcpy(&size, &size_pod, sizeof(size));
        void* return_val = platformAlignedAlloc(size);
        return return_val;
    }

    void phys_platformAlignedFree(void* ptr) {
        platformAlignedFree(ptr);
    }

    void* PxDefaultAllocator_allocate_mut(physx_PxDefaultAllocator_Pod* self__pod, size_t size_pod, char const* anon_param1, char const* anon_param2, int32_t anon_param3) {
        physx::PxDefaultAllocator* self_ = reinterpret_cast<physx::PxDefaultAllocator*>(self__pod);
        size_t size;
        memcpy(&size, &size_pod, sizeof(size));
        void* return_val = self_->allocate(size, anon_param1, anon_param2, anon_param3);
        return return_val;
    }

    void PxDefaultAllocator_deallocate_mut(physx_PxDefaultAllocator_Pod* self__pod, void* ptr) {
        physx::PxDefaultAllocator* self_ = reinterpret_cast<physx::PxDefaultAllocator*>(self__pod);
        self_->deallocate(ptr);
    }

    void PxDefaultAllocator_delete(physx_PxDefaultAllocator_Pod* self__pod) {
        physx::PxDefaultAllocator* self_ = reinterpret_cast<physx::PxDefaultAllocator*>(self__pod);
        delete self_;
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

    void PxJoint_setLocalPose_mut(physx_PxJoint_Pod* self__pod, int32_t actor_pod, physx_PxTransform_Pod const* localPose_pod) {
        physx::PxJoint* self_ = reinterpret_cast<physx::PxJoint*>(self__pod);
        auto actor = static_cast<physx::PxJointActorIndex::Enum>(actor_pod);
        physx::PxTransform const& localPose = reinterpret_cast<physx::PxTransform const&>(*localPose_pod);
        self_->setLocalPose(actor, localPose);
    }

    physx_PxTransform_Pod PxJoint_getLocalPose(physx_PxJoint_Pod const* self__pod, int32_t actor_pod) {
        physx::PxJoint const* self_ = reinterpret_cast<physx::PxJoint const*>(self__pod);
        auto actor = static_cast<physx::PxJointActorIndex::Enum>(actor_pod);
        physx::PxTransform return_val = self_->getLocalPose(actor);
        physx_PxTransform_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxTransform_Pod PxJoint_getRelativeTransform(physx_PxJoint_Pod const* self__pod) {
        physx::PxJoint const* self_ = reinterpret_cast<physx::PxJoint const*>(self__pod);
        physx::PxTransform return_val = self_->getRelativeTransform();
        physx_PxTransform_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxJoint_getRelativeLinearVelocity(physx_PxJoint_Pod const* self__pod) {
        physx::PxJoint const* self_ = reinterpret_cast<physx::PxJoint const*>(self__pod);
        physx::PxVec3 return_val = self_->getRelativeLinearVelocity();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxJoint_getRelativeAngularVelocity(physx_PxJoint_Pod const* self__pod) {
        physx::PxJoint const* self_ = reinterpret_cast<physx::PxJoint const*>(self__pod);
        physx::PxVec3 return_val = self_->getRelativeAngularVelocity();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
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

    void PxJoint_setConstraintFlags_mut(physx_PxJoint_Pod* self__pod, uint16_t flags_pod) {
        physx::PxJoint* self_ = reinterpret_cast<physx::PxJoint*>(self__pod);
        auto flags = physx::PxConstraintFlags(flags_pod);
        self_->setConstraintFlags(flags);
    }

    void PxJoint_setConstraintFlag_mut(physx_PxJoint_Pod* self__pod, int32_t flag_pod, bool value) {
        physx::PxJoint* self_ = reinterpret_cast<physx::PxJoint*>(self__pod);
        auto flag = static_cast<physx::PxConstraintFlag::Enum>(flag_pod);
        self_->setConstraintFlag(flag, value);
    }

    uint16_t PxJoint_getConstraintFlags(physx_PxJoint_Pod const* self__pod) {
        physx::PxJoint const* self_ = reinterpret_cast<physx::PxJoint const*>(self__pod);
        physx::PxConstraintFlags return_val = self_->getConstraintFlags();
        uint16_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxJoint_setInvMassScale0_mut(physx_PxJoint_Pod* self__pod, float invMassScale) {
        physx::PxJoint* self_ = reinterpret_cast<physx::PxJoint*>(self__pod);
        self_->setInvMassScale0(invMassScale);
    }

    float PxJoint_getInvMassScale0(physx_PxJoint_Pod const* self__pod) {
        physx::PxJoint const* self_ = reinterpret_cast<physx::PxJoint const*>(self__pod);
        float return_val = self_->getInvMassScale0();
        return return_val;
    }

    void PxJoint_setInvInertiaScale0_mut(physx_PxJoint_Pod* self__pod, float invInertiaScale) {
        physx::PxJoint* self_ = reinterpret_cast<physx::PxJoint*>(self__pod);
        self_->setInvInertiaScale0(invInertiaScale);
    }

    float PxJoint_getInvInertiaScale0(physx_PxJoint_Pod const* self__pod) {
        physx::PxJoint const* self_ = reinterpret_cast<physx::PxJoint const*>(self__pod);
        float return_val = self_->getInvInertiaScale0();
        return return_val;
    }

    void PxJoint_setInvMassScale1_mut(physx_PxJoint_Pod* self__pod, float invMassScale) {
        physx::PxJoint* self_ = reinterpret_cast<physx::PxJoint*>(self__pod);
        self_->setInvMassScale1(invMassScale);
    }

    float PxJoint_getInvMassScale1(physx_PxJoint_Pod const* self__pod) {
        physx::PxJoint const* self_ = reinterpret_cast<physx::PxJoint const*>(self__pod);
        float return_val = self_->getInvMassScale1();
        return return_val;
    }

    void PxJoint_setInvInertiaScale1_mut(physx_PxJoint_Pod* self__pod, float invInertiaScale) {
        physx::PxJoint* self_ = reinterpret_cast<physx::PxJoint*>(self__pod);
        self_->setInvInertiaScale1(invInertiaScale);
    }

    float PxJoint_getInvInertiaScale1(physx_PxJoint_Pod const* self__pod) {
        physx::PxJoint const* self_ = reinterpret_cast<physx::PxJoint const*>(self__pod);
        float return_val = self_->getInvInertiaScale1();
        return return_val;
    }

    physx_PxConstraint_Pod* PxJoint_getConstraint(physx_PxJoint_Pod const* self__pod) {
        physx::PxJoint const* self_ = reinterpret_cast<physx::PxJoint const*>(self__pod);
        physx::PxConstraint* return_val = self_->getConstraint();
        auto return_val_pod = reinterpret_cast<physx_PxConstraint_Pod*>(return_val);
        return return_val_pod;
    }

    void PxJoint_setName_mut(physx_PxJoint_Pod* self__pod, char const* name) {
        physx::PxJoint* self_ = reinterpret_cast<physx::PxJoint*>(self__pod);
        self_->setName(name);
    }

    char const* PxJoint_getName(physx_PxJoint_Pod const* self__pod) {
        physx::PxJoint const* self_ = reinterpret_cast<physx::PxJoint const*>(self__pod);
        char const* return_val = self_->getName();
        return return_val;
    }

    void PxJoint_release_mut(physx_PxJoint_Pod* self__pod) {
        physx::PxJoint* self_ = reinterpret_cast<physx::PxJoint*>(self__pod);
        self_->release();
    }

    physx_PxScene_Pod* PxJoint_getScene(physx_PxJoint_Pod const* self__pod) {
        physx::PxJoint const* self_ = reinterpret_cast<physx::PxJoint const*>(self__pod);
        physx::PxScene* return_val = self_->getScene();
        auto return_val_pod = reinterpret_cast<physx_PxScene_Pod*>(return_val);
        return return_val_pod;
    }

    void PxJoint_getBinaryMetaData(physx_PxOutputStream_Pod* stream_pod) {
        physx::PxOutputStream& stream = reinterpret_cast<physx::PxOutputStream&>(*stream_pod);
        PxJoint::getBinaryMetaData(stream);
    }

    physx_PxSpring_Pod PxSpring_new(float stiffness_, float damping_) {
        PxSpring return_val(stiffness_, damping_);
        physx_PxSpring_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
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
        physx::PxDistanceJoint* return_val = PxDistanceJointCreate(physics, actor0, localFrame0, actor1, localFrame1);
        auto return_val_pod = reinterpret_cast<physx_PxDistanceJoint_Pod*>(return_val);
        return return_val_pod;
    }

    float PxDistanceJoint_getDistance(physx_PxDistanceJoint_Pod const* self__pod) {
        physx::PxDistanceJoint const* self_ = reinterpret_cast<physx::PxDistanceJoint const*>(self__pod);
        float return_val = self_->getDistance();
        return return_val;
    }

    void PxDistanceJoint_setMinDistance_mut(physx_PxDistanceJoint_Pod* self__pod, float distance) {
        physx::PxDistanceJoint* self_ = reinterpret_cast<physx::PxDistanceJoint*>(self__pod);
        self_->setMinDistance(distance);
    }

    float PxDistanceJoint_getMinDistance(physx_PxDistanceJoint_Pod const* self__pod) {
        physx::PxDistanceJoint const* self_ = reinterpret_cast<physx::PxDistanceJoint const*>(self__pod);
        float return_val = self_->getMinDistance();
        return return_val;
    }

    void PxDistanceJoint_setMaxDistance_mut(physx_PxDistanceJoint_Pod* self__pod, float distance) {
        physx::PxDistanceJoint* self_ = reinterpret_cast<physx::PxDistanceJoint*>(self__pod);
        self_->setMaxDistance(distance);
    }

    float PxDistanceJoint_getMaxDistance(physx_PxDistanceJoint_Pod const* self__pod) {
        physx::PxDistanceJoint const* self_ = reinterpret_cast<physx::PxDistanceJoint const*>(self__pod);
        float return_val = self_->getMaxDistance();
        return return_val;
    }

    void PxDistanceJoint_setTolerance_mut(physx_PxDistanceJoint_Pod* self__pod, float tolerance) {
        physx::PxDistanceJoint* self_ = reinterpret_cast<physx::PxDistanceJoint*>(self__pod);
        self_->setTolerance(tolerance);
    }

    float PxDistanceJoint_getTolerance(physx_PxDistanceJoint_Pod const* self__pod) {
        physx::PxDistanceJoint const* self_ = reinterpret_cast<physx::PxDistanceJoint const*>(self__pod);
        float return_val = self_->getTolerance();
        return return_val;
    }

    void PxDistanceJoint_setStiffness_mut(physx_PxDistanceJoint_Pod* self__pod, float stiffness) {
        physx::PxDistanceJoint* self_ = reinterpret_cast<physx::PxDistanceJoint*>(self__pod);
        self_->setStiffness(stiffness);
    }

    float PxDistanceJoint_getStiffness(physx_PxDistanceJoint_Pod const* self__pod) {
        physx::PxDistanceJoint const* self_ = reinterpret_cast<physx::PxDistanceJoint const*>(self__pod);
        float return_val = self_->getStiffness();
        return return_val;
    }

    void PxDistanceJoint_setDamping_mut(physx_PxDistanceJoint_Pod* self__pod, float damping) {
        physx::PxDistanceJoint* self_ = reinterpret_cast<physx::PxDistanceJoint*>(self__pod);
        self_->setDamping(damping);
    }

    float PxDistanceJoint_getDamping(physx_PxDistanceJoint_Pod const* self__pod) {
        physx::PxDistanceJoint const* self_ = reinterpret_cast<physx::PxDistanceJoint const*>(self__pod);
        float return_val = self_->getDamping();
        return return_val;
    }

    void PxDistanceJoint_setContactDistance_mut(physx_PxDistanceJoint_Pod* self__pod, float contactDistance) {
        physx::PxDistanceJoint* self_ = reinterpret_cast<physx::PxDistanceJoint*>(self__pod);
        self_->setContactDistance(contactDistance);
    }

    float PxDistanceJoint_getContactDistance(physx_PxDistanceJoint_Pod const* self__pod) {
        physx::PxDistanceJoint const* self_ = reinterpret_cast<physx::PxDistanceJoint const*>(self__pod);
        float return_val = self_->getContactDistance();
        return return_val;
    }

    void PxDistanceJoint_setDistanceJointFlags_mut(physx_PxDistanceJoint_Pod* self__pod, uint16_t flags_pod) {
        physx::PxDistanceJoint* self_ = reinterpret_cast<physx::PxDistanceJoint*>(self__pod);
        auto flags = physx::PxDistanceJointFlags(flags_pod);
        self_->setDistanceJointFlags(flags);
    }

    void PxDistanceJoint_setDistanceJointFlag_mut(physx_PxDistanceJoint_Pod* self__pod, int32_t flag_pod, bool value) {
        physx::PxDistanceJoint* self_ = reinterpret_cast<physx::PxDistanceJoint*>(self__pod);
        auto flag = static_cast<physx::PxDistanceJointFlag::Enum>(flag_pod);
        self_->setDistanceJointFlag(flag, value);
    }

    uint16_t PxDistanceJoint_getDistanceJointFlags(physx_PxDistanceJoint_Pod const* self__pod) {
        physx::PxDistanceJoint const* self_ = reinterpret_cast<physx::PxDistanceJoint const*>(self__pod);
        physx::PxDistanceJointFlags return_val = self_->getDistanceJointFlags();
        uint16_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    char const* PxDistanceJoint_getConcreteTypeName(physx_PxDistanceJoint_Pod const* self__pod) {
        physx::PxDistanceJoint const* self_ = reinterpret_cast<physx::PxDistanceJoint const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    physx_PxContactJoint_Pod* phys_PxContactJointCreate(physx_PxPhysics_Pod* physics_pod, physx_PxRigidActor_Pod* actor0_pod, physx_PxTransform_Pod const* localFrame0_pod, physx_PxRigidActor_Pod* actor1_pod, physx_PxTransform_Pod const* localFrame1_pod) {
        physx::PxPhysics& physics = reinterpret_cast<physx::PxPhysics&>(*physics_pod);
        physx::PxRigidActor* actor0 = reinterpret_cast<physx::PxRigidActor*>(actor0_pod);
        physx::PxTransform const& localFrame0 = reinterpret_cast<physx::PxTransform const&>(*localFrame0_pod);
        physx::PxRigidActor* actor1 = reinterpret_cast<physx::PxRigidActor*>(actor1_pod);
        physx::PxTransform const& localFrame1 = reinterpret_cast<physx::PxTransform const&>(*localFrame1_pod);
        physx::PxContactJoint* return_val = PxContactJointCreate(physics, actor0, localFrame0, actor1, localFrame1);
        auto return_val_pod = reinterpret_cast<physx_PxContactJoint_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxJacobianRow_Pod PxJacobianRow_new() {
        PxJacobianRow return_val;
        physx_PxJacobianRow_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxJacobianRow_Pod PxJacobianRow_new_1(physx_PxVec3_Pod const* lin0_pod, physx_PxVec3_Pod const* lin1_pod, physx_PxVec3_Pod const* ang0_pod, physx_PxVec3_Pod const* ang1_pod) {
        physx::PxVec3 const& lin0 = reinterpret_cast<physx::PxVec3 const&>(*lin0_pod);
        physx::PxVec3 const& lin1 = reinterpret_cast<physx::PxVec3 const&>(*lin1_pod);
        physx::PxVec3 const& ang0 = reinterpret_cast<physx::PxVec3 const&>(*ang0_pod);
        physx::PxVec3 const& ang1 = reinterpret_cast<physx::PxVec3 const&>(*ang1_pod);
        PxJacobianRow return_val(lin0, lin1, ang0, ang1);
        physx_PxJacobianRow_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
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
        physx::PxVec3 return_val = self_->getContact();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxContactJoint_getContactNormal(physx_PxContactJoint_Pod const* self__pod) {
        physx::PxContactJoint const* self_ = reinterpret_cast<physx::PxContactJoint const*>(self__pod);
        physx::PxVec3 return_val = self_->getContactNormal();
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    float PxContactJoint_getPenetration(physx_PxContactJoint_Pod const* self__pod) {
        physx::PxContactJoint const* self_ = reinterpret_cast<physx::PxContactJoint const*>(self__pod);
        float return_val = self_->getPenetration();
        return return_val;
    }

    float PxContactJoint_getRestitution(physx_PxContactJoint_Pod const* self__pod) {
        physx::PxContactJoint const* self_ = reinterpret_cast<physx::PxContactJoint const*>(self__pod);
        float return_val = self_->getRestitution();
        return return_val;
    }

    void PxContactJoint_setRestitution_mut(physx_PxContactJoint_Pod* self__pod, float restitution) {
        physx::PxContactJoint* self_ = reinterpret_cast<physx::PxContactJoint*>(self__pod);
        self_->setRestitution(restitution);
    }

    float PxContactJoint_getBounceThreshold(physx_PxContactJoint_Pod const* self__pod) {
        physx::PxContactJoint const* self_ = reinterpret_cast<physx::PxContactJoint const*>(self__pod);
        float return_val = self_->getBounceThreshold();
        return return_val;
    }

    void PxContactJoint_setBounceThreshold_mut(physx_PxContactJoint_Pod* self__pod, float bounceThreshold) {
        physx::PxContactJoint* self_ = reinterpret_cast<physx::PxContactJoint*>(self__pod);
        self_->setBounceThreshold(bounceThreshold);
    }

    char const* PxContactJoint_getConcreteTypeName(physx_PxContactJoint_Pod const* self__pod) {
        physx::PxContactJoint const* self_ = reinterpret_cast<physx::PxContactJoint const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    void PxContactJoint_computeJacobians(physx_PxContactJoint_Pod const* self__pod, physx_PxJacobianRow_Pod* jacobian_pod) {
        physx::PxContactJoint const* self_ = reinterpret_cast<physx::PxContactJoint const*>(self__pod);
        physx::PxJacobianRow* jacobian = reinterpret_cast<physx::PxJacobianRow*>(jacobian_pod);
        self_->computeJacobians(jacobian);
    }

    uint32_t PxContactJoint_getNbJacobianRows(physx_PxContactJoint_Pod const* self__pod) {
        physx::PxContactJoint const* self_ = reinterpret_cast<physx::PxContactJoint const*>(self__pod);
        uint32_t return_val = self_->getNbJacobianRows();
        return return_val;
    }

    physx_PxFixedJoint_Pod* phys_PxFixedJointCreate(physx_PxPhysics_Pod* physics_pod, physx_PxRigidActor_Pod* actor0_pod, physx_PxTransform_Pod const* localFrame0_pod, physx_PxRigidActor_Pod* actor1_pod, physx_PxTransform_Pod const* localFrame1_pod) {
        physx::PxPhysics& physics = reinterpret_cast<physx::PxPhysics&>(*physics_pod);
        physx::PxRigidActor* actor0 = reinterpret_cast<physx::PxRigidActor*>(actor0_pod);
        physx::PxTransform const& localFrame0 = reinterpret_cast<physx::PxTransform const&>(*localFrame0_pod);
        physx::PxRigidActor* actor1 = reinterpret_cast<physx::PxRigidActor*>(actor1_pod);
        physx::PxTransform const& localFrame1 = reinterpret_cast<physx::PxTransform const&>(*localFrame1_pod);
        physx::PxFixedJoint* return_val = PxFixedJointCreate(physics, actor0, localFrame0, actor1, localFrame1);
        auto return_val_pod = reinterpret_cast<physx_PxFixedJoint_Pod*>(return_val);
        return return_val_pod;
    }

    char const* PxFixedJoint_getConcreteTypeName(physx_PxFixedJoint_Pod const* self__pod) {
        physx::PxFixedJoint const* self_ = reinterpret_cast<physx::PxFixedJoint const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    physx_PxJointLimitParameters_Pod* PxJointLimitParameters_new_alloc() {
        auto return_val = new physx::PxJointLimitParameters();
        auto return_val_pod = reinterpret_cast<physx_PxJointLimitParameters_Pod*>(return_val);
        return return_val_pod;
    }

    bool PxJointLimitParameters_isValid(physx_PxJointLimitParameters_Pod const* self__pod) {
        physx::PxJointLimitParameters const* self_ = reinterpret_cast<physx::PxJointLimitParameters const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    bool PxJointLimitParameters_isSoft(physx_PxJointLimitParameters_Pod const* self__pod) {
        physx::PxJointLimitParameters const* self_ = reinterpret_cast<physx::PxJointLimitParameters const*>(self__pod);
        bool return_val = self_->isSoft();
        return return_val;
    }

    physx_PxJointLinearLimit_Pod PxJointLinearLimit_new(physx_PxTolerancesScale_Pod const* scale_pod, float extent, float contactDist_deprecated) {
        physx::PxTolerancesScale const& scale = reinterpret_cast<physx::PxTolerancesScale const&>(*scale_pod);
        PxJointLinearLimit return_val(scale, extent, contactDist_deprecated);
        physx_PxJointLinearLimit_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxJointLinearLimit_Pod PxJointLinearLimit_new_1(float extent, physx_PxSpring_Pod const* spring_pod) {
        physx::PxSpring const& spring = reinterpret_cast<physx::PxSpring const&>(*spring_pod);
        PxJointLinearLimit return_val(extent, spring);
        physx_PxJointLinearLimit_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxJointLinearLimit_isValid(physx_PxJointLinearLimit_Pod const* self__pod) {
        physx::PxJointLinearLimit const* self_ = reinterpret_cast<physx::PxJointLinearLimit const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    void PxJointLinearLimit_delete(physx_PxJointLinearLimit_Pod* self__pod) {
        physx::PxJointLinearLimit* self_ = reinterpret_cast<physx::PxJointLinearLimit*>(self__pod);
        delete self_;
    }

    physx_PxJointLinearLimitPair_Pod PxJointLinearLimitPair_new(physx_PxTolerancesScale_Pod const* scale_pod, float lowerLimit, float upperLimit, float contactDist_deprecated) {
        physx::PxTolerancesScale const& scale = reinterpret_cast<physx::PxTolerancesScale const&>(*scale_pod);
        PxJointLinearLimitPair return_val(scale, lowerLimit, upperLimit, contactDist_deprecated);
        physx_PxJointLinearLimitPair_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxJointLinearLimitPair_Pod PxJointLinearLimitPair_new_1(float lowerLimit, float upperLimit, physx_PxSpring_Pod const* spring_pod) {
        physx::PxSpring const& spring = reinterpret_cast<physx::PxSpring const&>(*spring_pod);
        PxJointLinearLimitPair return_val(lowerLimit, upperLimit, spring);
        physx_PxJointLinearLimitPair_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxJointLinearLimitPair_isValid(physx_PxJointLinearLimitPair_Pod const* self__pod) {
        physx::PxJointLinearLimitPair const* self_ = reinterpret_cast<physx::PxJointLinearLimitPair const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    void PxJointLinearLimitPair_delete(physx_PxJointLinearLimitPair_Pod* self__pod) {
        physx::PxJointLinearLimitPair* self_ = reinterpret_cast<physx::PxJointLinearLimitPair*>(self__pod);
        delete self_;
    }

    physx_PxJointAngularLimitPair_Pod PxJointAngularLimitPair_new(float lowerLimit, float upperLimit, float contactDist_deprecated) {
        PxJointAngularLimitPair return_val(lowerLimit, upperLimit, contactDist_deprecated);
        physx_PxJointAngularLimitPair_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxJointAngularLimitPair_Pod PxJointAngularLimitPair_new_1(float lowerLimit, float upperLimit, physx_PxSpring_Pod const* spring_pod) {
        physx::PxSpring const& spring = reinterpret_cast<physx::PxSpring const&>(*spring_pod);
        PxJointAngularLimitPair return_val(lowerLimit, upperLimit, spring);
        physx_PxJointAngularLimitPair_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxJointAngularLimitPair_isValid(physx_PxJointAngularLimitPair_Pod const* self__pod) {
        physx::PxJointAngularLimitPair const* self_ = reinterpret_cast<physx::PxJointAngularLimitPair const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    void PxJointAngularLimitPair_delete(physx_PxJointAngularLimitPair_Pod* self__pod) {
        physx::PxJointAngularLimitPair* self_ = reinterpret_cast<physx::PxJointAngularLimitPair*>(self__pod);
        delete self_;
    }

    physx_PxJointLimitCone_Pod PxJointLimitCone_new(float yLimitAngle, float zLimitAngle, float contactDist_deprecated) {
        PxJointLimitCone return_val(yLimitAngle, zLimitAngle, contactDist_deprecated);
        physx_PxJointLimitCone_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxJointLimitCone_Pod PxJointLimitCone_new_1(float yLimitAngle, float zLimitAngle, physx_PxSpring_Pod const* spring_pod) {
        physx::PxSpring const& spring = reinterpret_cast<physx::PxSpring const&>(*spring_pod);
        PxJointLimitCone return_val(yLimitAngle, zLimitAngle, spring);
        physx_PxJointLimitCone_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxJointLimitCone_isValid(physx_PxJointLimitCone_Pod const* self__pod) {
        physx::PxJointLimitCone const* self_ = reinterpret_cast<physx::PxJointLimitCone const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    void PxJointLimitCone_delete(physx_PxJointLimitCone_Pod* self__pod) {
        physx::PxJointLimitCone* self_ = reinterpret_cast<physx::PxJointLimitCone*>(self__pod);
        delete self_;
    }

    physx_PxJointLimitPyramid_Pod PxJointLimitPyramid_new(float yLimitAngleMin, float yLimitAngleMax, float zLimitAngleMin, float zLimitAngleMax, float contactDist_deprecated) {
        PxJointLimitPyramid return_val(yLimitAngleMin, yLimitAngleMax, zLimitAngleMin, zLimitAngleMax, contactDist_deprecated);
        physx_PxJointLimitPyramid_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxJointLimitPyramid_Pod PxJointLimitPyramid_new_1(float yLimitAngleMin, float yLimitAngleMax, float zLimitAngleMin, float zLimitAngleMax, physx_PxSpring_Pod const* spring_pod) {
        physx::PxSpring const& spring = reinterpret_cast<physx::PxSpring const&>(*spring_pod);
        PxJointLimitPyramid return_val(yLimitAngleMin, yLimitAngleMax, zLimitAngleMin, zLimitAngleMax, spring);
        physx_PxJointLimitPyramid_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxJointLimitPyramid_isValid(physx_PxJointLimitPyramid_Pod const* self__pod) {
        physx::PxJointLimitPyramid const* self_ = reinterpret_cast<physx::PxJointLimitPyramid const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
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
        physx::PxPrismaticJoint* return_val = PxPrismaticJointCreate(physics, actor0, localFrame0, actor1, localFrame1);
        auto return_val_pod = reinterpret_cast<physx_PxPrismaticJoint_Pod*>(return_val);
        return return_val_pod;
    }

    float PxPrismaticJoint_getPosition(physx_PxPrismaticJoint_Pod const* self__pod) {
        physx::PxPrismaticJoint const* self_ = reinterpret_cast<physx::PxPrismaticJoint const*>(self__pod);
        float return_val = self_->getPosition();
        return return_val;
    }

    float PxPrismaticJoint_getVelocity(physx_PxPrismaticJoint_Pod const* self__pod) {
        physx::PxPrismaticJoint const* self_ = reinterpret_cast<physx::PxPrismaticJoint const*>(self__pod);
        float return_val = self_->getVelocity();
        return return_val;
    }

    void PxPrismaticJoint_setLimit_mut(physx_PxPrismaticJoint_Pod* self__pod, physx_PxJointLinearLimitPair_Pod const* anon_param0_pod) {
        physx::PxPrismaticJoint* self_ = reinterpret_cast<physx::PxPrismaticJoint*>(self__pod);
        physx::PxJointLinearLimitPair const& anon_param0 = reinterpret_cast<physx::PxJointLinearLimitPair const&>(*anon_param0_pod);
        self_->setLimit(anon_param0);
    }

    physx_PxJointLinearLimitPair_Pod PxPrismaticJoint_getLimit(physx_PxPrismaticJoint_Pod const* self__pod) {
        physx::PxPrismaticJoint const* self_ = reinterpret_cast<physx::PxPrismaticJoint const*>(self__pod);
        physx::PxJointLinearLimitPair return_val = self_->getLimit();
        physx_PxJointLinearLimitPair_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxPrismaticJoint_setPrismaticJointFlags_mut(physx_PxPrismaticJoint_Pod* self__pod, uint16_t flags_pod) {
        physx::PxPrismaticJoint* self_ = reinterpret_cast<physx::PxPrismaticJoint*>(self__pod);
        auto flags = physx::PxPrismaticJointFlags(flags_pod);
        self_->setPrismaticJointFlags(flags);
    }

    void PxPrismaticJoint_setPrismaticJointFlag_mut(physx_PxPrismaticJoint_Pod* self__pod, int32_t flag_pod, bool value) {
        physx::PxPrismaticJoint* self_ = reinterpret_cast<physx::PxPrismaticJoint*>(self__pod);
        auto flag = static_cast<physx::PxPrismaticJointFlag::Enum>(flag_pod);
        self_->setPrismaticJointFlag(flag, value);
    }

    uint16_t PxPrismaticJoint_getPrismaticJointFlags(physx_PxPrismaticJoint_Pod const* self__pod) {
        physx::PxPrismaticJoint const* self_ = reinterpret_cast<physx::PxPrismaticJoint const*>(self__pod);
        physx::PxPrismaticJointFlags return_val = self_->getPrismaticJointFlags();
        uint16_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    char const* PxPrismaticJoint_getConcreteTypeName(physx_PxPrismaticJoint_Pod const* self__pod) {
        physx::PxPrismaticJoint const* self_ = reinterpret_cast<physx::PxPrismaticJoint const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    physx_PxRevoluteJoint_Pod* phys_PxRevoluteJointCreate(physx_PxPhysics_Pod* physics_pod, physx_PxRigidActor_Pod* actor0_pod, physx_PxTransform_Pod const* localFrame0_pod, physx_PxRigidActor_Pod* actor1_pod, physx_PxTransform_Pod const* localFrame1_pod) {
        physx::PxPhysics& physics = reinterpret_cast<physx::PxPhysics&>(*physics_pod);
        physx::PxRigidActor* actor0 = reinterpret_cast<physx::PxRigidActor*>(actor0_pod);
        physx::PxTransform const& localFrame0 = reinterpret_cast<physx::PxTransform const&>(*localFrame0_pod);
        physx::PxRigidActor* actor1 = reinterpret_cast<physx::PxRigidActor*>(actor1_pod);
        physx::PxTransform const& localFrame1 = reinterpret_cast<physx::PxTransform const&>(*localFrame1_pod);
        physx::PxRevoluteJoint* return_val = PxRevoluteJointCreate(physics, actor0, localFrame0, actor1, localFrame1);
        auto return_val_pod = reinterpret_cast<physx_PxRevoluteJoint_Pod*>(return_val);
        return return_val_pod;
    }

    float PxRevoluteJoint_getAngle(physx_PxRevoluteJoint_Pod const* self__pod) {
        physx::PxRevoluteJoint const* self_ = reinterpret_cast<physx::PxRevoluteJoint const*>(self__pod);
        float return_val = self_->getAngle();
        return return_val;
    }

    float PxRevoluteJoint_getVelocity(physx_PxRevoluteJoint_Pod const* self__pod) {
        physx::PxRevoluteJoint const* self_ = reinterpret_cast<physx::PxRevoluteJoint const*>(self__pod);
        float return_val = self_->getVelocity();
        return return_val;
    }

    void PxRevoluteJoint_setLimit_mut(physx_PxRevoluteJoint_Pod* self__pod, physx_PxJointAngularLimitPair_Pod const* limits_pod) {
        physx::PxRevoluteJoint* self_ = reinterpret_cast<physx::PxRevoluteJoint*>(self__pod);
        physx::PxJointAngularLimitPair const& limits = reinterpret_cast<physx::PxJointAngularLimitPair const&>(*limits_pod);
        self_->setLimit(limits);
    }

    physx_PxJointAngularLimitPair_Pod PxRevoluteJoint_getLimit(physx_PxRevoluteJoint_Pod const* self__pod) {
        physx::PxRevoluteJoint const* self_ = reinterpret_cast<physx::PxRevoluteJoint const*>(self__pod);
        physx::PxJointAngularLimitPair return_val = self_->getLimit();
        physx_PxJointAngularLimitPair_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxRevoluteJoint_setDriveVelocity_mut(physx_PxRevoluteJoint_Pod* self__pod, float velocity, bool autowake) {
        physx::PxRevoluteJoint* self_ = reinterpret_cast<physx::PxRevoluteJoint*>(self__pod);
        self_->setDriveVelocity(velocity, autowake);
    }

    float PxRevoluteJoint_getDriveVelocity(physx_PxRevoluteJoint_Pod const* self__pod) {
        physx::PxRevoluteJoint const* self_ = reinterpret_cast<physx::PxRevoluteJoint const*>(self__pod);
        float return_val = self_->getDriveVelocity();
        return return_val;
    }

    void PxRevoluteJoint_setDriveForceLimit_mut(physx_PxRevoluteJoint_Pod* self__pod, float limit) {
        physx::PxRevoluteJoint* self_ = reinterpret_cast<physx::PxRevoluteJoint*>(self__pod);
        self_->setDriveForceLimit(limit);
    }

    float PxRevoluteJoint_getDriveForceLimit(physx_PxRevoluteJoint_Pod const* self__pod) {
        physx::PxRevoluteJoint const* self_ = reinterpret_cast<physx::PxRevoluteJoint const*>(self__pod);
        float return_val = self_->getDriveForceLimit();
        return return_val;
    }

    void PxRevoluteJoint_setDriveGearRatio_mut(physx_PxRevoluteJoint_Pod* self__pod, float ratio) {
        physx::PxRevoluteJoint* self_ = reinterpret_cast<physx::PxRevoluteJoint*>(self__pod);
        self_->setDriveGearRatio(ratio);
    }

    float PxRevoluteJoint_getDriveGearRatio(physx_PxRevoluteJoint_Pod const* self__pod) {
        physx::PxRevoluteJoint const* self_ = reinterpret_cast<physx::PxRevoluteJoint const*>(self__pod);
        float return_val = self_->getDriveGearRatio();
        return return_val;
    }

    void PxRevoluteJoint_setRevoluteJointFlags_mut(physx_PxRevoluteJoint_Pod* self__pod, uint16_t flags_pod) {
        physx::PxRevoluteJoint* self_ = reinterpret_cast<physx::PxRevoluteJoint*>(self__pod);
        auto flags = physx::PxRevoluteJointFlags(flags_pod);
        self_->setRevoluteJointFlags(flags);
    }

    void PxRevoluteJoint_setRevoluteJointFlag_mut(physx_PxRevoluteJoint_Pod* self__pod, int32_t flag_pod, bool value) {
        physx::PxRevoluteJoint* self_ = reinterpret_cast<physx::PxRevoluteJoint*>(self__pod);
        auto flag = static_cast<physx::PxRevoluteJointFlag::Enum>(flag_pod);
        self_->setRevoluteJointFlag(flag, value);
    }

    uint16_t PxRevoluteJoint_getRevoluteJointFlags(physx_PxRevoluteJoint_Pod const* self__pod) {
        physx::PxRevoluteJoint const* self_ = reinterpret_cast<physx::PxRevoluteJoint const*>(self__pod);
        physx::PxRevoluteJointFlags return_val = self_->getRevoluteJointFlags();
        uint16_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    char const* PxRevoluteJoint_getConcreteTypeName(physx_PxRevoluteJoint_Pod const* self__pod) {
        physx::PxRevoluteJoint const* self_ = reinterpret_cast<physx::PxRevoluteJoint const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    physx_PxSphericalJoint_Pod* phys_PxSphericalJointCreate(physx_PxPhysics_Pod* physics_pod, physx_PxRigidActor_Pod* actor0_pod, physx_PxTransform_Pod const* localFrame0_pod, physx_PxRigidActor_Pod* actor1_pod, physx_PxTransform_Pod const* localFrame1_pod) {
        physx::PxPhysics& physics = reinterpret_cast<physx::PxPhysics&>(*physics_pod);
        physx::PxRigidActor* actor0 = reinterpret_cast<physx::PxRigidActor*>(actor0_pod);
        physx::PxTransform const& localFrame0 = reinterpret_cast<physx::PxTransform const&>(*localFrame0_pod);
        physx::PxRigidActor* actor1 = reinterpret_cast<physx::PxRigidActor*>(actor1_pod);
        physx::PxTransform const& localFrame1 = reinterpret_cast<physx::PxTransform const&>(*localFrame1_pod);
        physx::PxSphericalJoint* return_val = PxSphericalJointCreate(physics, actor0, localFrame0, actor1, localFrame1);
        auto return_val_pod = reinterpret_cast<physx_PxSphericalJoint_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxJointLimitCone_Pod PxSphericalJoint_getLimitCone(physx_PxSphericalJoint_Pod const* self__pod) {
        physx::PxSphericalJoint const* self_ = reinterpret_cast<physx::PxSphericalJoint const*>(self__pod);
        physx::PxJointLimitCone return_val = self_->getLimitCone();
        physx_PxJointLimitCone_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxSphericalJoint_setLimitCone_mut(physx_PxSphericalJoint_Pod* self__pod, physx_PxJointLimitCone_Pod const* limit_pod) {
        physx::PxSphericalJoint* self_ = reinterpret_cast<physx::PxSphericalJoint*>(self__pod);
        physx::PxJointLimitCone const& limit = reinterpret_cast<physx::PxJointLimitCone const&>(*limit_pod);
        self_->setLimitCone(limit);
    }

    float PxSphericalJoint_getSwingYAngle(physx_PxSphericalJoint_Pod const* self__pod) {
        physx::PxSphericalJoint const* self_ = reinterpret_cast<physx::PxSphericalJoint const*>(self__pod);
        float return_val = self_->getSwingYAngle();
        return return_val;
    }

    float PxSphericalJoint_getSwingZAngle(physx_PxSphericalJoint_Pod const* self__pod) {
        physx::PxSphericalJoint const* self_ = reinterpret_cast<physx::PxSphericalJoint const*>(self__pod);
        float return_val = self_->getSwingZAngle();
        return return_val;
    }

    void PxSphericalJoint_setSphericalJointFlags_mut(physx_PxSphericalJoint_Pod* self__pod, uint16_t flags_pod) {
        physx::PxSphericalJoint* self_ = reinterpret_cast<physx::PxSphericalJoint*>(self__pod);
        auto flags = physx::PxSphericalJointFlags(flags_pod);
        self_->setSphericalJointFlags(flags);
    }

    void PxSphericalJoint_setSphericalJointFlag_mut(physx_PxSphericalJoint_Pod* self__pod, int32_t flag_pod, bool value) {
        physx::PxSphericalJoint* self_ = reinterpret_cast<physx::PxSphericalJoint*>(self__pod);
        auto flag = static_cast<physx::PxSphericalJointFlag::Enum>(flag_pod);
        self_->setSphericalJointFlag(flag, value);
    }

    uint16_t PxSphericalJoint_getSphericalJointFlags(physx_PxSphericalJoint_Pod const* self__pod) {
        physx::PxSphericalJoint const* self_ = reinterpret_cast<physx::PxSphericalJoint const*>(self__pod);
        physx::PxSphericalJointFlags return_val = self_->getSphericalJointFlags();
        uint16_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    char const* PxSphericalJoint_getConcreteTypeName(physx_PxSphericalJoint_Pod const* self__pod) {
        physx::PxSphericalJoint const* self_ = reinterpret_cast<physx::PxSphericalJoint const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    physx_PxD6Joint_Pod* phys_PxD6JointCreate(physx_PxPhysics_Pod* physics_pod, physx_PxRigidActor_Pod* actor0_pod, physx_PxTransform_Pod const* localFrame0_pod, physx_PxRigidActor_Pod* actor1_pod, physx_PxTransform_Pod const* localFrame1_pod) {
        physx::PxPhysics& physics = reinterpret_cast<physx::PxPhysics&>(*physics_pod);
        physx::PxRigidActor* actor0 = reinterpret_cast<physx::PxRigidActor*>(actor0_pod);
        physx::PxTransform const& localFrame0 = reinterpret_cast<physx::PxTransform const&>(*localFrame0_pod);
        physx::PxRigidActor* actor1 = reinterpret_cast<physx::PxRigidActor*>(actor1_pod);
        physx::PxTransform const& localFrame1 = reinterpret_cast<physx::PxTransform const&>(*localFrame1_pod);
        physx::PxD6Joint* return_val = PxD6JointCreate(physics, actor0, localFrame0, actor1, localFrame1);
        auto return_val_pod = reinterpret_cast<physx_PxD6Joint_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxD6JointDrive_Pod PxD6JointDrive_new() {
        PxD6JointDrive return_val;
        physx_PxD6JointDrive_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxD6JointDrive_Pod PxD6JointDrive_new_1(float driveStiffness, float driveDamping, float driveForceLimit, bool isAcceleration) {
        PxD6JointDrive return_val(driveStiffness, driveDamping, driveForceLimit, isAcceleration);
        physx_PxD6JointDrive_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxD6JointDrive_isValid(physx_PxD6JointDrive_Pod const* self__pod) {
        physx::PxD6JointDrive const* self_ = reinterpret_cast<physx::PxD6JointDrive const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    void PxD6Joint_setMotion_mut(physx_PxD6Joint_Pod* self__pod, int32_t axis_pod, int32_t type_pod) {
        physx::PxD6Joint* self_ = reinterpret_cast<physx::PxD6Joint*>(self__pod);
        auto axis = static_cast<physx::PxD6Axis::Enum>(axis_pod);
        auto type = static_cast<physx::PxD6Motion::Enum>(type_pod);
        self_->setMotion(axis, type);
    }

    int32_t PxD6Joint_getMotion(physx_PxD6Joint_Pod const* self__pod, int32_t axis_pod) {
        physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
        auto axis = static_cast<physx::PxD6Axis::Enum>(axis_pod);
        physx::PxD6Motion::Enum return_val = self_->getMotion(axis);
        int32_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    float PxD6Joint_getTwistAngle(physx_PxD6Joint_Pod const* self__pod) {
        physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
        float return_val = self_->getTwistAngle();
        return return_val;
    }

    float PxD6Joint_getSwingYAngle(physx_PxD6Joint_Pod const* self__pod) {
        physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
        float return_val = self_->getSwingYAngle();
        return return_val;
    }

    float PxD6Joint_getSwingZAngle(physx_PxD6Joint_Pod const* self__pod) {
        physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
        float return_val = self_->getSwingZAngle();
        return return_val;
    }

    void PxD6Joint_setDistanceLimit_mut(physx_PxD6Joint_Pod* self__pod, physx_PxJointLinearLimit_Pod const* limit_pod) {
        physx::PxD6Joint* self_ = reinterpret_cast<physx::PxD6Joint*>(self__pod);
        physx::PxJointLinearLimit const& limit = reinterpret_cast<physx::PxJointLinearLimit const&>(*limit_pod);
        self_->setDistanceLimit(limit);
    }

    physx_PxJointLinearLimit_Pod PxD6Joint_getDistanceLimit(physx_PxD6Joint_Pod const* self__pod) {
        physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
        physx::PxJointLinearLimit return_val = self_->getDistanceLimit();
        physx_PxJointLinearLimit_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxD6Joint_setLinearLimit_mut(physx_PxD6Joint_Pod* self__pod, int32_t axis_pod, physx_PxJointLinearLimitPair_Pod const* limit_pod) {
        physx::PxD6Joint* self_ = reinterpret_cast<physx::PxD6Joint*>(self__pod);
        auto axis = static_cast<physx::PxD6Axis::Enum>(axis_pod);
        physx::PxJointLinearLimitPair const& limit = reinterpret_cast<physx::PxJointLinearLimitPair const&>(*limit_pod);
        self_->setLinearLimit(axis, limit);
    }

    physx_PxJointLinearLimitPair_Pod PxD6Joint_getLinearLimit(physx_PxD6Joint_Pod const* self__pod, int32_t axis_pod) {
        physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
        auto axis = static_cast<physx::PxD6Axis::Enum>(axis_pod);
        physx::PxJointLinearLimitPair return_val = self_->getLinearLimit(axis);
        physx_PxJointLinearLimitPair_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxD6Joint_setTwistLimit_mut(physx_PxD6Joint_Pod* self__pod, physx_PxJointAngularLimitPair_Pod const* limit_pod) {
        physx::PxD6Joint* self_ = reinterpret_cast<physx::PxD6Joint*>(self__pod);
        physx::PxJointAngularLimitPair const& limit = reinterpret_cast<physx::PxJointAngularLimitPair const&>(*limit_pod);
        self_->setTwistLimit(limit);
    }

    physx_PxJointAngularLimitPair_Pod PxD6Joint_getTwistLimit(physx_PxD6Joint_Pod const* self__pod) {
        physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
        physx::PxJointAngularLimitPair return_val = self_->getTwistLimit();
        physx_PxJointAngularLimitPair_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxD6Joint_setSwingLimit_mut(physx_PxD6Joint_Pod* self__pod, physx_PxJointLimitCone_Pod const* limit_pod) {
        physx::PxD6Joint* self_ = reinterpret_cast<physx::PxD6Joint*>(self__pod);
        physx::PxJointLimitCone const& limit = reinterpret_cast<physx::PxJointLimitCone const&>(*limit_pod);
        self_->setSwingLimit(limit);
    }

    physx_PxJointLimitCone_Pod PxD6Joint_getSwingLimit(physx_PxD6Joint_Pod const* self__pod) {
        physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
        physx::PxJointLimitCone return_val = self_->getSwingLimit();
        physx_PxJointLimitCone_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxD6Joint_setPyramidSwingLimit_mut(physx_PxD6Joint_Pod* self__pod, physx_PxJointLimitPyramid_Pod const* limit_pod) {
        physx::PxD6Joint* self_ = reinterpret_cast<physx::PxD6Joint*>(self__pod);
        physx::PxJointLimitPyramid const& limit = reinterpret_cast<physx::PxJointLimitPyramid const&>(*limit_pod);
        self_->setPyramidSwingLimit(limit);
    }

    physx_PxJointLimitPyramid_Pod PxD6Joint_getPyramidSwingLimit(physx_PxD6Joint_Pod const* self__pod) {
        physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
        physx::PxJointLimitPyramid return_val = self_->getPyramidSwingLimit();
        physx_PxJointLimitPyramid_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxD6Joint_setDrive_mut(physx_PxD6Joint_Pod* self__pod, int32_t index_pod, physx_PxD6JointDrive_Pod const* drive_pod) {
        physx::PxD6Joint* self_ = reinterpret_cast<physx::PxD6Joint*>(self__pod);
        auto index = static_cast<physx::PxD6Drive::Enum>(index_pod);
        physx::PxD6JointDrive const& drive = reinterpret_cast<physx::PxD6JointDrive const&>(*drive_pod);
        self_->setDrive(index, drive);
    }

    physx_PxD6JointDrive_Pod PxD6Joint_getDrive(physx_PxD6Joint_Pod const* self__pod, int32_t index_pod) {
        physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
        auto index = static_cast<physx::PxD6Drive::Enum>(index_pod);
        physx::PxD6JointDrive return_val = self_->getDrive(index);
        physx_PxD6JointDrive_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxD6Joint_setDrivePosition_mut(physx_PxD6Joint_Pod* self__pod, physx_PxTransform_Pod const* pose_pod, bool autowake) {
        physx::PxD6Joint* self_ = reinterpret_cast<physx::PxD6Joint*>(self__pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        self_->setDrivePosition(pose, autowake);
    }

    physx_PxTransform_Pod PxD6Joint_getDrivePosition(physx_PxD6Joint_Pod const* self__pod) {
        physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
        physx::PxTransform return_val = self_->getDrivePosition();
        physx_PxTransform_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
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
        float return_val = self_->getProjectionLinearTolerance();
        return return_val;
    }

    void PxD6Joint_setProjectionAngularTolerance_mut(physx_PxD6Joint_Pod* self__pod, float tolerance) {
        physx::PxD6Joint* self_ = reinterpret_cast<physx::PxD6Joint*>(self__pod);
        self_->setProjectionAngularTolerance(tolerance);
    }

    float PxD6Joint_getProjectionAngularTolerance(physx_PxD6Joint_Pod const* self__pod) {
        physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
        float return_val = self_->getProjectionAngularTolerance();
        return return_val;
    }

    char const* PxD6Joint_getConcreteTypeName(physx_PxD6Joint_Pod const* self__pod) {
        physx::PxD6Joint const* self_ = reinterpret_cast<physx::PxD6Joint const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    physx_PxGearJoint_Pod* phys_PxGearJointCreate(physx_PxPhysics_Pod* physics_pod, physx_PxRigidActor_Pod* actor0_pod, physx_PxTransform_Pod const* localFrame0_pod, physx_PxRigidActor_Pod* actor1_pod, physx_PxTransform_Pod const* localFrame1_pod) {
        physx::PxPhysics& physics = reinterpret_cast<physx::PxPhysics&>(*physics_pod);
        physx::PxRigidActor* actor0 = reinterpret_cast<physx::PxRigidActor*>(actor0_pod);
        physx::PxTransform const& localFrame0 = reinterpret_cast<physx::PxTransform const&>(*localFrame0_pod);
        physx::PxRigidActor* actor1 = reinterpret_cast<physx::PxRigidActor*>(actor1_pod);
        physx::PxTransform const& localFrame1 = reinterpret_cast<physx::PxTransform const&>(*localFrame1_pod);
        physx::PxGearJoint* return_val = PxGearJointCreate(physics, actor0, localFrame0, actor1, localFrame1);
        auto return_val_pod = reinterpret_cast<physx_PxGearJoint_Pod*>(return_val);
        return return_val_pod;
    }

    bool PxGearJoint_setHinges_mut(physx_PxGearJoint_Pod* self__pod, physx_PxBase_Pod const* hinge0_pod, physx_PxBase_Pod const* hinge1_pod) {
        physx::PxGearJoint* self_ = reinterpret_cast<physx::PxGearJoint*>(self__pod);
        physx::PxBase const* hinge0 = reinterpret_cast<physx::PxBase const*>(hinge0_pod);
        physx::PxBase const* hinge1 = reinterpret_cast<physx::PxBase const*>(hinge1_pod);
        bool return_val = self_->setHinges(hinge0, hinge1);
        return return_val;
    }

    void PxGearJoint_setGearRatio_mut(physx_PxGearJoint_Pod* self__pod, float ratio) {
        physx::PxGearJoint* self_ = reinterpret_cast<physx::PxGearJoint*>(self__pod);
        self_->setGearRatio(ratio);
    }

    float PxGearJoint_getGearRatio(physx_PxGearJoint_Pod const* self__pod) {
        physx::PxGearJoint const* self_ = reinterpret_cast<physx::PxGearJoint const*>(self__pod);
        float return_val = self_->getGearRatio();
        return return_val;
    }

    char const* PxGearJoint_getConcreteTypeName(physx_PxGearJoint_Pod const* self__pod) {
        physx::PxGearJoint const* self_ = reinterpret_cast<physx::PxGearJoint const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    physx_PxRackAndPinionJoint_Pod* phys_PxRackAndPinionJointCreate(physx_PxPhysics_Pod* physics_pod, physx_PxRigidActor_Pod* actor0_pod, physx_PxTransform_Pod const* localFrame0_pod, physx_PxRigidActor_Pod* actor1_pod, physx_PxTransform_Pod const* localFrame1_pod) {
        physx::PxPhysics& physics = reinterpret_cast<physx::PxPhysics&>(*physics_pod);
        physx::PxRigidActor* actor0 = reinterpret_cast<physx::PxRigidActor*>(actor0_pod);
        physx::PxTransform const& localFrame0 = reinterpret_cast<physx::PxTransform const&>(*localFrame0_pod);
        physx::PxRigidActor* actor1 = reinterpret_cast<physx::PxRigidActor*>(actor1_pod);
        physx::PxTransform const& localFrame1 = reinterpret_cast<physx::PxTransform const&>(*localFrame1_pod);
        physx::PxRackAndPinionJoint* return_val = PxRackAndPinionJointCreate(physics, actor0, localFrame0, actor1, localFrame1);
        auto return_val_pod = reinterpret_cast<physx_PxRackAndPinionJoint_Pod*>(return_val);
        return return_val_pod;
    }

    bool PxRackAndPinionJoint_setJoints_mut(physx_PxRackAndPinionJoint_Pod* self__pod, physx_PxBase_Pod const* hinge_pod, physx_PxBase_Pod const* prismatic_pod) {
        physx::PxRackAndPinionJoint* self_ = reinterpret_cast<physx::PxRackAndPinionJoint*>(self__pod);
        physx::PxBase const* hinge = reinterpret_cast<physx::PxBase const*>(hinge_pod);
        physx::PxBase const* prismatic = reinterpret_cast<physx::PxBase const*>(prismatic_pod);
        bool return_val = self_->setJoints(hinge, prismatic);
        return return_val;
    }

    void PxRackAndPinionJoint_setRatio_mut(physx_PxRackAndPinionJoint_Pod* self__pod, float ratio) {
        physx::PxRackAndPinionJoint* self_ = reinterpret_cast<physx::PxRackAndPinionJoint*>(self__pod);
        self_->setRatio(ratio);
    }

    float PxRackAndPinionJoint_getRatio(physx_PxRackAndPinionJoint_Pod const* self__pod) {
        physx::PxRackAndPinionJoint const* self_ = reinterpret_cast<physx::PxRackAndPinionJoint const*>(self__pod);
        float return_val = self_->getRatio();
        return return_val;
    }

    bool PxRackAndPinionJoint_setData_mut(physx_PxRackAndPinionJoint_Pod* self__pod, uint32_t nbRackTeeth, uint32_t nbPinionTeeth, float rackLength) {
        physx::PxRackAndPinionJoint* self_ = reinterpret_cast<physx::PxRackAndPinionJoint*>(self__pod);
        bool return_val = self_->setData(nbRackTeeth, nbPinionTeeth, rackLength);
        return return_val;
    }

    char const* PxRackAndPinionJoint_getConcreteTypeName(physx_PxRackAndPinionJoint_Pod const* self__pod) {
        physx::PxRackAndPinionJoint const* self_ = reinterpret_cast<physx::PxRackAndPinionJoint const*>(self__pod);
        char const* return_val = self_->getConcreteTypeName();
        return return_val;
    }

    physx_PxGroupsMask_Pod* PxGroupsMask_new_alloc() {
        auto return_val = new physx::PxGroupsMask();
        auto return_val_pod = reinterpret_cast<physx_PxGroupsMask_Pod*>(return_val);
        return return_val_pod;
    }

    void PxGroupsMask_delete(physx_PxGroupsMask_Pod* self__pod) {
        physx::PxGroupsMask* self_ = reinterpret_cast<physx::PxGroupsMask*>(self__pod);
        delete self_;
    }

    uint16_t phys_PxDefaultSimulationFilterShader(uint32_t attributes0, physx_PxFilterData_Pod filterData0_pod, uint32_t attributes1, physx_PxFilterData_Pod filterData1_pod, uint16_t* pairFlags_pod, void const* constantBlock, uint32_t constantBlockSize) {
        physx::PxFilterData filterData0;
        memcpy(&filterData0, &filterData0_pod, sizeof(filterData0));
        physx::PxFilterData filterData1;
        memcpy(&filterData1, &filterData1_pod, sizeof(filterData1));
        physx::PxPairFlags& pairFlags = reinterpret_cast<physx::PxPairFlags&>(*pairFlags_pod);
        physx::PxFilterFlags return_val = PxDefaultSimulationFilterShader(attributes0, filterData0, attributes1, filterData1, pairFlags, constantBlock, constantBlockSize);
        uint16_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool phys_PxGetGroupCollisionFlag(uint16_t group1, uint16_t group2) {
        bool return_val = PxGetGroupCollisionFlag(group1, group2);
        return return_val;
    }

    void phys_PxSetGroupCollisionFlag(uint16_t group1, uint16_t group2, bool enable) {
        PxSetGroupCollisionFlag(group1, group2, enable);
    }

    uint16_t phys_PxGetGroup(physx_PxActor_Pod const* actor_pod) {
        physx::PxActor const& actor = reinterpret_cast<physx::PxActor const&>(*actor_pod);
        uint16_t return_val = PxGetGroup(actor);
        return return_val;
    }

    void phys_PxSetGroup(physx_PxActor_Pod* actor_pod, uint16_t collisionGroup) {
        physx::PxActor& actor = reinterpret_cast<physx::PxActor&>(*actor_pod);
        PxSetGroup(actor, collisionGroup);
    }

    void phys_PxGetFilterOps(int32_t* op0_pod, int32_t* op1_pod, int32_t* op2_pod) {
        physx::PxFilterOp::Enum& op0 = reinterpret_cast<physx::PxFilterOp::Enum&>(*op0_pod);
        physx::PxFilterOp::Enum& op1 = reinterpret_cast<physx::PxFilterOp::Enum&>(*op1_pod);
        physx::PxFilterOp::Enum& op2 = reinterpret_cast<physx::PxFilterOp::Enum&>(*op2_pod);
        PxGetFilterOps(op0, op1, op2);
    }

    void phys_PxSetFilterOps(int32_t const* op0_pod, int32_t const* op1_pod, int32_t const* op2_pod) {
        physx::PxFilterOp::Enum const& op0 = reinterpret_cast<physx::PxFilterOp::Enum const&>(*op0_pod);
        physx::PxFilterOp::Enum const& op1 = reinterpret_cast<physx::PxFilterOp::Enum const&>(*op1_pod);
        physx::PxFilterOp::Enum const& op2 = reinterpret_cast<physx::PxFilterOp::Enum const&>(*op2_pod);
        PxSetFilterOps(op0, op1, op2);
    }

    bool phys_PxGetFilterBool() {
        bool return_val = PxGetFilterBool();
        return return_val;
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
        physx::PxGroupsMask return_val = PxGetGroupsMask(actor);
        physx_PxGroupsMask_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void phys_PxSetGroupsMask(physx_PxActor_Pod* actor_pod, physx_PxGroupsMask_Pod const* mask_pod) {
        physx::PxActor& actor = reinterpret_cast<physx::PxActor&>(*actor_pod);
        physx::PxGroupsMask const& mask = reinterpret_cast<physx::PxGroupsMask const&>(*mask_pod);
        PxSetGroupsMask(actor, mask);
    }

    physx_PxDefaultErrorCallback_Pod* PxDefaultErrorCallback_new_alloc() {
        auto return_val = new physx::PxDefaultErrorCallback();
        auto return_val_pod = reinterpret_cast<physx_PxDefaultErrorCallback_Pod*>(return_val);
        return return_val_pod;
    }

    void PxDefaultErrorCallback_delete(physx_PxDefaultErrorCallback_Pod* self__pod) {
        physx::PxDefaultErrorCallback* self_ = reinterpret_cast<physx::PxDefaultErrorCallback*>(self__pod);
        delete self_;
    }

    void PxDefaultErrorCallback_reportError_mut(physx_PxDefaultErrorCallback_Pod* self__pod, int32_t code_pod, char const* message, char const* file, int32_t line) {
        physx::PxDefaultErrorCallback* self_ = reinterpret_cast<physx::PxDefaultErrorCallback*>(self__pod);
        auto code = static_cast<physx::PxErrorCode::Enum>(code_pod);
        self_->reportError(code, message, file, line);
    }

    physx_PxShape_Pod* PxRigidActorExt_createExclusiveShape(physx_PxRigidActor_Pod* actor_pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxMaterial_Pod* const* materials_pod, uint16_t materialCount, uint8_t shapeFlags_pod) {
        physx::PxRigidActor& actor = reinterpret_cast<physx::PxRigidActor&>(*actor_pod);
        physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
        physx::PxMaterial* const* materials = reinterpret_cast<physx::PxMaterial* const*>(materials_pod);
        auto shapeFlags = physx::PxShapeFlags(shapeFlags_pod);
        physx::PxShape* return_val = PxRigidActorExt::createExclusiveShape(actor, geometry, materials, materialCount, shapeFlags);
        auto return_val_pod = reinterpret_cast<physx_PxShape_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxShape_Pod* PxRigidActorExt_createExclusiveShape_1(physx_PxRigidActor_Pod* actor_pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxMaterial_Pod const* material_pod, uint8_t shapeFlags_pod) {
        physx::PxRigidActor& actor = reinterpret_cast<physx::PxRigidActor&>(*actor_pod);
        physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
        physx::PxMaterial const& material = reinterpret_cast<physx::PxMaterial const&>(*material_pod);
        auto shapeFlags = physx::PxShapeFlags(shapeFlags_pod);
        physx::PxShape* return_val = PxRigidActorExt::createExclusiveShape(actor, geometry, material, shapeFlags);
        auto return_val_pod = reinterpret_cast<physx_PxShape_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxBounds3_Pod* PxRigidActorExt_getRigidActorShapeLocalBoundsList(physx_PxRigidActor_Pod const* actor_pod, uint32_t* numBounds_pod) {
        physx::PxRigidActor const& actor = reinterpret_cast<physx::PxRigidActor const&>(*actor_pod);
        uint32_t& numBounds = *numBounds_pod;
        physx::PxBounds3* return_val = PxRigidActorExt::getRigidActorShapeLocalBoundsList(actor, numBounds);
        auto return_val_pod = reinterpret_cast<physx_PxBounds3_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxBVH_Pod* PxRigidActorExt_createBVHFromActor(physx_PxPhysics_Pod* physics_pod, physx_PxRigidActor_Pod const* actor_pod) {
        physx::PxPhysics& physics = reinterpret_cast<physx::PxPhysics&>(*physics_pod);
        physx::PxRigidActor const& actor = reinterpret_cast<physx::PxRigidActor const&>(*actor_pod);
        physx::PxBVH* return_val = PxRigidActorExt::createBVHFromActor(physics, actor);
        auto return_val_pod = reinterpret_cast<physx_PxBVH_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxMassProperties_Pod PxMassProperties_new() {
        PxMassProperties return_val;
        physx_PxMassProperties_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMassProperties_Pod PxMassProperties_new_1(float m, physx_PxMat33_Pod const* inertiaT_pod, physx_PxVec3_Pod const* com_pod) {
        physx::PxMat33 const& inertiaT = reinterpret_cast<physx::PxMat33 const&>(*inertiaT_pod);
        physx::PxVec3 const& com = reinterpret_cast<physx::PxVec3 const&>(*com_pod);
        PxMassProperties return_val(m, inertiaT, com);
        physx_PxMassProperties_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMassProperties_Pod PxMassProperties_new_2(physx_PxGeometry_Pod const* geometry_pod) {
        physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
        PxMassProperties return_val(geometry);
        physx_PxMassProperties_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxMassProperties_translate_mut(physx_PxMassProperties_Pod* self__pod, physx_PxVec3_Pod const* t_pod) {
        physx::PxMassProperties* self_ = reinterpret_cast<physx::PxMassProperties*>(self__pod);
        physx::PxVec3 const& t = reinterpret_cast<physx::PxVec3 const&>(*t_pod);
        self_->translate(t);
    }

    physx_PxVec3_Pod PxMassProperties_getMassSpaceInertia(physx_PxMat33_Pod const* inertia_pod, physx_PxQuat_Pod* massFrame_pod) {
        physx::PxMat33 const& inertia = reinterpret_cast<physx::PxMat33 const&>(*inertia_pod);
        physx::PxQuat& massFrame = reinterpret_cast<physx::PxQuat&>(*massFrame_pod);
        physx::PxVec3 return_val = PxMassProperties::getMassSpaceInertia(inertia, massFrame);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMat33_Pod PxMassProperties_translateInertia(physx_PxMat33_Pod const* inertia_pod, float mass, physx_PxVec3_Pod const* t_pod) {
        physx::PxMat33 const& inertia = reinterpret_cast<physx::PxMat33 const&>(*inertia_pod);
        physx::PxVec3 const& t = reinterpret_cast<physx::PxVec3 const&>(*t_pod);
        physx::PxMat33 return_val = PxMassProperties::translateInertia(inertia, mass, t);
        physx_PxMat33_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMat33_Pod PxMassProperties_rotateInertia(physx_PxMat33_Pod const* inertia_pod, physx_PxQuat_Pod const* q_pod) {
        physx::PxMat33 const& inertia = reinterpret_cast<physx::PxMat33 const&>(*inertia_pod);
        physx::PxQuat const& q = reinterpret_cast<physx::PxQuat const&>(*q_pod);
        physx::PxMat33 return_val = PxMassProperties::rotateInertia(inertia, q);
        physx_PxMat33_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMat33_Pod PxMassProperties_scaleInertia(physx_PxMat33_Pod const* inertia_pod, physx_PxQuat_Pod const* scaleRotation_pod, physx_PxVec3_Pod const* scale_pod) {
        physx::PxMat33 const& inertia = reinterpret_cast<physx::PxMat33 const&>(*inertia_pod);
        physx::PxQuat const& scaleRotation = reinterpret_cast<physx::PxQuat const&>(*scaleRotation_pod);
        physx::PxVec3 const& scale = reinterpret_cast<physx::PxVec3 const&>(*scale_pod);
        physx::PxMat33 return_val = PxMassProperties::scaleInertia(inertia, scaleRotation, scale);
        physx_PxMat33_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMassProperties_Pod PxMassProperties_sum(physx_PxMassProperties_Pod const* props_pod, physx_PxTransform_Pod const* transforms_pod, uint32_t count) {
        physx::PxMassProperties const* props = reinterpret_cast<physx::PxMassProperties const*>(props_pod);
        physx::PxTransform const* transforms = reinterpret_cast<physx::PxTransform const*>(transforms_pod);
        physx::PxMassProperties return_val = PxMassProperties::sum(props, transforms, count);
        physx_PxMassProperties_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxRigidBodyExt_updateMassAndInertia(physx_PxRigidBody_Pod* body_pod, float const* shapeDensities, uint32_t shapeDensityCount, physx_PxVec3_Pod const* massLocalPose_pod, bool includeNonSimShapes) {
        physx::PxRigidBody& body = reinterpret_cast<physx::PxRigidBody&>(*body_pod);
        physx::PxVec3 const* massLocalPose = reinterpret_cast<physx::PxVec3 const*>(massLocalPose_pod);
        bool return_val = PxRigidBodyExt::updateMassAndInertia(body, shapeDensities, shapeDensityCount, massLocalPose, includeNonSimShapes);
        return return_val;
    }

    bool PxRigidBodyExt_updateMassAndInertia_1(physx_PxRigidBody_Pod* body_pod, float density, physx_PxVec3_Pod const* massLocalPose_pod, bool includeNonSimShapes) {
        physx::PxRigidBody& body = reinterpret_cast<physx::PxRigidBody&>(*body_pod);
        physx::PxVec3 const* massLocalPose = reinterpret_cast<physx::PxVec3 const*>(massLocalPose_pod);
        bool return_val = PxRigidBodyExt::updateMassAndInertia(body, density, massLocalPose, includeNonSimShapes);
        return return_val;
    }

    bool PxRigidBodyExt_setMassAndUpdateInertia(physx_PxRigidBody_Pod* body_pod, float const* shapeMasses, uint32_t shapeMassCount, physx_PxVec3_Pod const* massLocalPose_pod, bool includeNonSimShapes) {
        physx::PxRigidBody& body = reinterpret_cast<physx::PxRigidBody&>(*body_pod);
        physx::PxVec3 const* massLocalPose = reinterpret_cast<physx::PxVec3 const*>(massLocalPose_pod);
        bool return_val = PxRigidBodyExt::setMassAndUpdateInertia(body, shapeMasses, shapeMassCount, massLocalPose, includeNonSimShapes);
        return return_val;
    }

    bool PxRigidBodyExt_setMassAndUpdateInertia_1(physx_PxRigidBody_Pod* body_pod, float mass, physx_PxVec3_Pod const* massLocalPose_pod, bool includeNonSimShapes) {
        physx::PxRigidBody& body = reinterpret_cast<physx::PxRigidBody&>(*body_pod);
        physx::PxVec3 const* massLocalPose = reinterpret_cast<physx::PxVec3 const*>(massLocalPose_pod);
        bool return_val = PxRigidBodyExt::setMassAndUpdateInertia(body, mass, massLocalPose, includeNonSimShapes);
        return return_val;
    }

    physx_PxMassProperties_Pod PxRigidBodyExt_computeMassPropertiesFromShapes(physx_PxShape_Pod const* const* shapes_pod, uint32_t shapeCount) {
        physx::PxShape const* const* shapes = reinterpret_cast<physx::PxShape const* const*>(shapes_pod);
        physx::PxMassProperties return_val = PxRigidBodyExt::computeMassPropertiesFromShapes(shapes, shapeCount);
        physx_PxMassProperties_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxRigidBodyExt_addForceAtPos(physx_PxRigidBody_Pod* body_pod, physx_PxVec3_Pod const* force_pod, physx_PxVec3_Pod const* pos_pod, int32_t mode_pod, bool wakeup) {
        physx::PxRigidBody& body = reinterpret_cast<physx::PxRigidBody&>(*body_pod);
        physx::PxVec3 const& force = reinterpret_cast<physx::PxVec3 const&>(*force_pod);
        physx::PxVec3 const& pos = reinterpret_cast<physx::PxVec3 const&>(*pos_pod);
        auto mode = static_cast<physx::PxForceMode::Enum>(mode_pod);
        PxRigidBodyExt::addForceAtPos(body, force, pos, mode, wakeup);
    }

    void PxRigidBodyExt_addForceAtLocalPos(physx_PxRigidBody_Pod* body_pod, physx_PxVec3_Pod const* force_pod, physx_PxVec3_Pod const* pos_pod, int32_t mode_pod, bool wakeup) {
        physx::PxRigidBody& body = reinterpret_cast<physx::PxRigidBody&>(*body_pod);
        physx::PxVec3 const& force = reinterpret_cast<physx::PxVec3 const&>(*force_pod);
        physx::PxVec3 const& pos = reinterpret_cast<physx::PxVec3 const&>(*pos_pod);
        auto mode = static_cast<physx::PxForceMode::Enum>(mode_pod);
        PxRigidBodyExt::addForceAtLocalPos(body, force, pos, mode, wakeup);
    }

    void PxRigidBodyExt_addLocalForceAtPos(physx_PxRigidBody_Pod* body_pod, physx_PxVec3_Pod const* force_pod, physx_PxVec3_Pod const* pos_pod, int32_t mode_pod, bool wakeup) {
        physx::PxRigidBody& body = reinterpret_cast<physx::PxRigidBody&>(*body_pod);
        physx::PxVec3 const& force = reinterpret_cast<physx::PxVec3 const&>(*force_pod);
        physx::PxVec3 const& pos = reinterpret_cast<physx::PxVec3 const&>(*pos_pod);
        auto mode = static_cast<physx::PxForceMode::Enum>(mode_pod);
        PxRigidBodyExt::addLocalForceAtPos(body, force, pos, mode, wakeup);
    }

    void PxRigidBodyExt_addLocalForceAtLocalPos(physx_PxRigidBody_Pod* body_pod, physx_PxVec3_Pod const* force_pod, physx_PxVec3_Pod const* pos_pod, int32_t mode_pod, bool wakeup) {
        physx::PxRigidBody& body = reinterpret_cast<physx::PxRigidBody&>(*body_pod);
        physx::PxVec3 const& force = reinterpret_cast<physx::PxVec3 const&>(*force_pod);
        physx::PxVec3 const& pos = reinterpret_cast<physx::PxVec3 const&>(*pos_pod);
        auto mode = static_cast<physx::PxForceMode::Enum>(mode_pod);
        PxRigidBodyExt::addLocalForceAtLocalPos(body, force, pos, mode, wakeup);
    }

    physx_PxVec3_Pod PxRigidBodyExt_getVelocityAtPos(physx_PxRigidBody_Pod const* body_pod, physx_PxVec3_Pod const* pos_pod) {
        physx::PxRigidBody const& body = reinterpret_cast<physx::PxRigidBody const&>(*body_pod);
        physx::PxVec3 const& pos = reinterpret_cast<physx::PxVec3 const&>(*pos_pod);
        physx::PxVec3 return_val = PxRigidBodyExt::getVelocityAtPos(body, pos);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxRigidBodyExt_getLocalVelocityAtLocalPos(physx_PxRigidBody_Pod const* body_pod, physx_PxVec3_Pod const* pos_pod) {
        physx::PxRigidBody const& body = reinterpret_cast<physx::PxRigidBody const&>(*body_pod);
        physx::PxVec3 const& pos = reinterpret_cast<physx::PxVec3 const&>(*pos_pod);
        physx::PxVec3 return_val = PxRigidBodyExt::getLocalVelocityAtLocalPos(body, pos);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxVec3_Pod PxRigidBodyExt_getVelocityAtOffset(physx_PxRigidBody_Pod const* body_pod, physx_PxVec3_Pod const* pos_pod) {
        physx::PxRigidBody const& body = reinterpret_cast<physx::PxRigidBody const&>(*body_pod);
        physx::PxVec3 const& pos = reinterpret_cast<physx::PxVec3 const&>(*pos_pod);
        physx::PxVec3 return_val = PxRigidBodyExt::getVelocityAtOffset(body, pos);
        physx_PxVec3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxRigidBodyExt_computeVelocityDeltaFromImpulse(physx_PxRigidBody_Pod const* body_pod, physx_PxVec3_Pod const* impulsiveForce_pod, physx_PxVec3_Pod const* impulsiveTorque_pod, physx_PxVec3_Pod* deltaLinearVelocity_pod, physx_PxVec3_Pod* deltaAngularVelocity_pod) {
        physx::PxRigidBody const& body = reinterpret_cast<physx::PxRigidBody const&>(*body_pod);
        physx::PxVec3 const& impulsiveForce = reinterpret_cast<physx::PxVec3 const&>(*impulsiveForce_pod);
        physx::PxVec3 const& impulsiveTorque = reinterpret_cast<physx::PxVec3 const&>(*impulsiveTorque_pod);
        physx::PxVec3& deltaLinearVelocity = reinterpret_cast<physx::PxVec3&>(*deltaLinearVelocity_pod);
        physx::PxVec3& deltaAngularVelocity = reinterpret_cast<physx::PxVec3&>(*deltaAngularVelocity_pod);
        PxRigidBodyExt::computeVelocityDeltaFromImpulse(body, impulsiveForce, impulsiveTorque, deltaLinearVelocity, deltaAngularVelocity);
    }

    void PxRigidBodyExt_computeVelocityDeltaFromImpulse_1(physx_PxRigidBody_Pod const* body_pod, physx_PxTransform_Pod const* globalPose_pod, physx_PxVec3_Pod const* point_pod, physx_PxVec3_Pod const* impulse_pod, float invMassScale, float invInertiaScale, physx_PxVec3_Pod* deltaLinearVelocity_pod, physx_PxVec3_Pod* deltaAngularVelocity_pod) {
        physx::PxRigidBody const& body = reinterpret_cast<physx::PxRigidBody const&>(*body_pod);
        physx::PxTransform const& globalPose = reinterpret_cast<physx::PxTransform const&>(*globalPose_pod);
        physx::PxVec3 const& point = reinterpret_cast<physx::PxVec3 const&>(*point_pod);
        physx::PxVec3 const& impulse = reinterpret_cast<physx::PxVec3 const&>(*impulse_pod);
        physx::PxVec3& deltaLinearVelocity = reinterpret_cast<physx::PxVec3&>(*deltaLinearVelocity_pod);
        physx::PxVec3& deltaAngularVelocity = reinterpret_cast<physx::PxVec3&>(*deltaAngularVelocity_pod);
        PxRigidBodyExt::computeVelocityDeltaFromImpulse(body, globalPose, point, impulse, invMassScale, invInertiaScale, deltaLinearVelocity, deltaAngularVelocity);
    }

    void PxRigidBodyExt_computeLinearAngularImpulse(physx_PxRigidBody_Pod const* body_pod, physx_PxTransform_Pod const* globalPose_pod, physx_PxVec3_Pod const* point_pod, physx_PxVec3_Pod const* impulse_pod, float invMassScale, float invInertiaScale, physx_PxVec3_Pod* linearImpulse_pod, physx_PxVec3_Pod* angularImpulse_pod) {
        physx::PxRigidBody const& body = reinterpret_cast<physx::PxRigidBody const&>(*body_pod);
        physx::PxTransform const& globalPose = reinterpret_cast<physx::PxTransform const&>(*globalPose_pod);
        physx::PxVec3 const& point = reinterpret_cast<physx::PxVec3 const&>(*point_pod);
        physx::PxVec3 const& impulse = reinterpret_cast<physx::PxVec3 const&>(*impulse_pod);
        physx::PxVec3& linearImpulse = reinterpret_cast<physx::PxVec3&>(*linearImpulse_pod);
        physx::PxVec3& angularImpulse = reinterpret_cast<physx::PxVec3&>(*angularImpulse_pod);
        PxRigidBodyExt::computeLinearAngularImpulse(body, globalPose, point, impulse, invMassScale, invInertiaScale, linearImpulse, angularImpulse);
    }

    bool PxRigidBodyExt_linearSweepSingle(physx_PxRigidBody_Pod* body_pod, physx_PxScene_Pod* scene_pod, physx_PxVec3_Pod const* unitDir_pod, float distance, uint16_t outputFlags_pod, physx_PxSweepHit_Pod* closestHit_pod, uint32_t* shapeIndex_pod, physx_PxQueryFilterData_Pod const* filterData_pod, physx_PxQueryFilterCallback_Pod* filterCall_pod, physx_PxQueryCache_Pod const* cache_pod, float inflation) {
        physx::PxRigidBody& body = reinterpret_cast<physx::PxRigidBody&>(*body_pod);
        physx::PxScene& scene = reinterpret_cast<physx::PxScene&>(*scene_pod);
        physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
        auto outputFlags = physx::PxHitFlags(outputFlags_pod);
        physx::PxSweepHit& closestHit = reinterpret_cast<physx::PxSweepHit&>(*closestHit_pod);
        uint32_t& shapeIndex = *shapeIndex_pod;
        physx::PxQueryFilterData const& filterData = reinterpret_cast<physx::PxQueryFilterData const&>(*filterData_pod);
        physx::PxQueryFilterCallback* filterCall = reinterpret_cast<physx::PxQueryFilterCallback*>(filterCall_pod);
        physx::PxQueryCache const* cache = reinterpret_cast<physx::PxQueryCache const*>(cache_pod);
        bool return_val = PxRigidBodyExt::linearSweepSingle(body, scene, unitDir, distance, outputFlags, closestHit, shapeIndex, filterData, filterCall, cache, inflation);
        return return_val;
    }

    uint32_t PxRigidBodyExt_linearSweepMultiple(physx_PxRigidBody_Pod* body_pod, physx_PxScene_Pod* scene_pod, physx_PxVec3_Pod const* unitDir_pod, float distance, uint16_t outputFlags_pod, physx_PxSweepHit_Pod* touchHitBuffer_pod, uint32_t* touchHitShapeIndices, uint32_t touchHitBufferSize, physx_PxSweepHit_Pod* block_pod, int32_t* blockingShapeIndex_pod, bool* overflow_pod, physx_PxQueryFilterData_Pod const* filterData_pod, physx_PxQueryFilterCallback_Pod* filterCall_pod, physx_PxQueryCache_Pod const* cache_pod, float inflation) {
        physx::PxRigidBody& body = reinterpret_cast<physx::PxRigidBody&>(*body_pod);
        physx::PxScene& scene = reinterpret_cast<physx::PxScene&>(*scene_pod);
        physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
        auto outputFlags = physx::PxHitFlags(outputFlags_pod);
        physx::PxSweepHit* touchHitBuffer = reinterpret_cast<physx::PxSweepHit*>(touchHitBuffer_pod);
        physx::PxSweepHit& block = reinterpret_cast<physx::PxSweepHit&>(*block_pod);
        int32_t& blockingShapeIndex = *blockingShapeIndex_pod;
        bool& overflow = *overflow_pod;
        physx::PxQueryFilterData const& filterData = reinterpret_cast<physx::PxQueryFilterData const&>(*filterData_pod);
        physx::PxQueryFilterCallback* filterCall = reinterpret_cast<physx::PxQueryFilterCallback*>(filterCall_pod);
        physx::PxQueryCache const* cache = reinterpret_cast<physx::PxQueryCache const*>(cache_pod);
        uint32_t return_val = PxRigidBodyExt::linearSweepMultiple(body, scene, unitDir, distance, outputFlags, touchHitBuffer, touchHitShapeIndices, touchHitBufferSize, block, blockingShapeIndex, overflow, filterData, filterCall, cache, inflation);
        return return_val;
    }

    physx_PxTransform_Pod PxShapeExt_getGlobalPose(physx_PxShape_Pod const* shape_pod, physx_PxRigidActor_Pod const* actor_pod) {
        physx::PxShape const& shape = reinterpret_cast<physx::PxShape const&>(*shape_pod);
        physx::PxRigidActor const& actor = reinterpret_cast<physx::PxRigidActor const&>(*actor_pod);
        physx::PxTransform return_val = PxShapeExt::getGlobalPose(shape, actor);
        physx_PxTransform_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    uint32_t PxShapeExt_raycast(physx_PxShape_Pod const* shape_pod, physx_PxRigidActor_Pod const* actor_pod, physx_PxVec3_Pod const* rayOrigin_pod, physx_PxVec3_Pod const* rayDir_pod, float maxDist, uint16_t hitFlags_pod, uint32_t maxHits, physx_PxRaycastHit_Pod* rayHits_pod) {
        physx::PxShape const& shape = reinterpret_cast<physx::PxShape const&>(*shape_pod);
        physx::PxRigidActor const& actor = reinterpret_cast<physx::PxRigidActor const&>(*actor_pod);
        physx::PxVec3 const& rayOrigin = reinterpret_cast<physx::PxVec3 const&>(*rayOrigin_pod);
        physx::PxVec3 const& rayDir = reinterpret_cast<physx::PxVec3 const&>(*rayDir_pod);
        auto hitFlags = physx::PxHitFlags(hitFlags_pod);
        physx::PxRaycastHit* rayHits = reinterpret_cast<physx::PxRaycastHit*>(rayHits_pod);
        uint32_t return_val = PxShapeExt::raycast(shape, actor, rayOrigin, rayDir, maxDist, hitFlags, maxHits, rayHits);
        return return_val;
    }

    bool PxShapeExt_overlap(physx_PxShape_Pod const* shape_pod, physx_PxRigidActor_Pod const* actor_pod, physx_PxGeometry_Pod const* otherGeom_pod, physx_PxTransform_Pod const* otherGeomPose_pod) {
        physx::PxShape const& shape = reinterpret_cast<physx::PxShape const&>(*shape_pod);
        physx::PxRigidActor const& actor = reinterpret_cast<physx::PxRigidActor const&>(*actor_pod);
        physx::PxGeometry const& otherGeom = reinterpret_cast<physx::PxGeometry const&>(*otherGeom_pod);
        physx::PxTransform const& otherGeomPose = reinterpret_cast<physx::PxTransform const&>(*otherGeomPose_pod);
        bool return_val = PxShapeExt::overlap(shape, actor, otherGeom, otherGeomPose);
        return return_val;
    }

    bool PxShapeExt_sweep(physx_PxShape_Pod const* shape_pod, physx_PxRigidActor_Pod const* actor_pod, physx_PxVec3_Pod const* unitDir_pod, float distance, physx_PxGeometry_Pod const* otherGeom_pod, physx_PxTransform_Pod const* otherGeomPose_pod, physx_PxSweepHit_Pod* sweepHit_pod, uint16_t hitFlags_pod) {
        physx::PxShape const& shape = reinterpret_cast<physx::PxShape const&>(*shape_pod);
        physx::PxRigidActor const& actor = reinterpret_cast<physx::PxRigidActor const&>(*actor_pod);
        physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
        physx::PxGeometry const& otherGeom = reinterpret_cast<physx::PxGeometry const&>(*otherGeom_pod);
        physx::PxTransform const& otherGeomPose = reinterpret_cast<physx::PxTransform const&>(*otherGeomPose_pod);
        physx::PxSweepHit& sweepHit = reinterpret_cast<physx::PxSweepHit&>(*sweepHit_pod);
        auto hitFlags = physx::PxHitFlags(hitFlags_pod);
        bool return_val = PxShapeExt::sweep(shape, actor, unitDir, distance, otherGeom, otherGeomPose, sweepHit, hitFlags);
        return return_val;
    }

    physx_PxBounds3_Pod PxShapeExt_getWorldBounds(physx_PxShape_Pod const* shape_pod, physx_PxRigidActor_Pod const* actor_pod, float inflation) {
        physx::PxShape const& shape = reinterpret_cast<physx::PxShape const&>(*shape_pod);
        physx::PxRigidActor const& actor = reinterpret_cast<physx::PxRigidActor const&>(*actor_pod);
        physx::PxBounds3 return_val = PxShapeExt::getWorldBounds(shape, actor, inflation);
        physx_PxBounds3_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxMeshOverlapUtil_Pod* PxMeshOverlapUtil_new_alloc() {
        auto return_val = new physx::PxMeshOverlapUtil();
        auto return_val_pod = reinterpret_cast<physx_PxMeshOverlapUtil_Pod*>(return_val);
        return return_val_pod;
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
        uint32_t return_val = self_->findOverlap(geom, geomPose, meshGeom, meshPose);
        return return_val;
    }

    uint32_t PxMeshOverlapUtil_findOverlap_mut_1(physx_PxMeshOverlapUtil_Pod* self__pod, physx_PxGeometry_Pod const* geom_pod, physx_PxTransform_Pod const* geomPose_pod, physx_PxHeightFieldGeometry_Pod const* hfGeom_pod, physx_PxTransform_Pod const* hfPose_pod) {
        physx::PxMeshOverlapUtil* self_ = reinterpret_cast<physx::PxMeshOverlapUtil*>(self__pod);
        physx::PxGeometry const& geom = reinterpret_cast<physx::PxGeometry const&>(*geom_pod);
        physx::PxTransform const& geomPose = reinterpret_cast<physx::PxTransform const&>(*geomPose_pod);
        physx::PxHeightFieldGeometry const& hfGeom = reinterpret_cast<physx::PxHeightFieldGeometry const&>(*hfGeom_pod);
        physx::PxTransform const& hfPose = reinterpret_cast<physx::PxTransform const&>(*hfPose_pod);
        uint32_t return_val = self_->findOverlap(geom, geomPose, hfGeom, hfPose);
        return return_val;
    }

    uint32_t const* PxMeshOverlapUtil_getResults(physx_PxMeshOverlapUtil_Pod const* self__pod) {
        physx::PxMeshOverlapUtil const* self_ = reinterpret_cast<physx::PxMeshOverlapUtil const*>(self__pod);
        uint32_t const* return_val = self_->getResults();
        return return_val;
    }

    uint32_t PxMeshOverlapUtil_getNbResults(physx_PxMeshOverlapUtil_Pod const* self__pod) {
        physx::PxMeshOverlapUtil const* self_ = reinterpret_cast<physx::PxMeshOverlapUtil const*>(self__pod);
        uint32_t return_val = self_->getNbResults();
        return return_val;
    }

    bool phys_PxComputeTriangleMeshPenetration(physx_PxVec3_Pod* direction_pod, float* depth_pod, physx_PxGeometry_Pod const* geom_pod, physx_PxTransform_Pod const* geomPose_pod, physx_PxTriangleMeshGeometry_Pod const* meshGeom_pod, physx_PxTransform_Pod const* meshPose_pod, uint32_t maxIter, uint32_t* usedIter) {
        physx::PxVec3& direction = reinterpret_cast<physx::PxVec3&>(*direction_pod);
        float& depth = *depth_pod;
        physx::PxGeometry const& geom = reinterpret_cast<physx::PxGeometry const&>(*geom_pod);
        physx::PxTransform const& geomPose = reinterpret_cast<physx::PxTransform const&>(*geomPose_pod);
        physx::PxTriangleMeshGeometry const& meshGeom = reinterpret_cast<physx::PxTriangleMeshGeometry const&>(*meshGeom_pod);
        physx::PxTransform const& meshPose = reinterpret_cast<physx::PxTransform const&>(*meshPose_pod);
        bool return_val = PxComputeTriangleMeshPenetration(direction, depth, geom, geomPose, meshGeom, meshPose, maxIter, usedIter);
        return return_val;
    }

    bool phys_PxComputeHeightFieldPenetration(physx_PxVec3_Pod* direction_pod, float* depth_pod, physx_PxGeometry_Pod const* geom_pod, physx_PxTransform_Pod const* geomPose_pod, physx_PxHeightFieldGeometry_Pod const* heightFieldGeom_pod, physx_PxTransform_Pod const* heightFieldPose_pod, uint32_t maxIter, uint32_t* usedIter) {
        physx::PxVec3& direction = reinterpret_cast<physx::PxVec3&>(*direction_pod);
        float& depth = *depth_pod;
        physx::PxGeometry const& geom = reinterpret_cast<physx::PxGeometry const&>(*geom_pod);
        physx::PxTransform const& geomPose = reinterpret_cast<physx::PxTransform const&>(*geomPose_pod);
        physx::PxHeightFieldGeometry const& heightFieldGeom = reinterpret_cast<physx::PxHeightFieldGeometry const&>(*heightFieldGeom_pod);
        physx::PxTransform const& heightFieldPose = reinterpret_cast<physx::PxTransform const&>(*heightFieldPose_pod);
        bool return_val = PxComputeHeightFieldPenetration(direction, depth, geom, geomPose, heightFieldGeom, heightFieldPose, maxIter, usedIter);
        return return_val;
    }

    physx_PxXmlMiscParameter_Pod PxXmlMiscParameter_new() {
        PxXmlMiscParameter return_val;
        physx_PxXmlMiscParameter_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    physx_PxXmlMiscParameter_Pod PxXmlMiscParameter_new_1(physx_PxVec3_Pod* inUpVector_pod, physx_PxTolerancesScale_Pod inScale_pod) {
        physx::PxVec3& inUpVector = reinterpret_cast<physx::PxVec3&>(*inUpVector_pod);
        physx::PxTolerancesScale inScale;
        memcpy(&inScale, &inScale_pod, sizeof(inScale));
        PxXmlMiscParameter return_val(inUpVector, inScale);
        physx_PxXmlMiscParameter_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxSerialization_isSerializable(physx_PxCollection_Pod* collection_pod, physx_PxSerializationRegistry_Pod* sr_pod, physx_PxCollection_Pod const* externalReferences_pod) {
        physx::PxCollection& collection = reinterpret_cast<physx::PxCollection&>(*collection_pod);
        physx::PxSerializationRegistry& sr = reinterpret_cast<physx::PxSerializationRegistry&>(*sr_pod);
        physx::PxCollection const* externalReferences = reinterpret_cast<physx::PxCollection const*>(externalReferences_pod);
        bool return_val = PxSerialization::isSerializable(collection, sr, externalReferences);
        return return_val;
    }

    void PxSerialization_complete(physx_PxCollection_Pod* collection_pod, physx_PxSerializationRegistry_Pod* sr_pod, physx_PxCollection_Pod const* exceptFor_pod, bool followJoints) {
        physx::PxCollection& collection = reinterpret_cast<physx::PxCollection&>(*collection_pod);
        physx::PxSerializationRegistry& sr = reinterpret_cast<physx::PxSerializationRegistry&>(*sr_pod);
        physx::PxCollection const* exceptFor = reinterpret_cast<physx::PxCollection const*>(exceptFor_pod);
        PxSerialization::complete(collection, sr, exceptFor, followJoints);
    }

    void PxSerialization_createSerialObjectIds(physx_PxCollection_Pod* collection_pod, uint64_t base) {
        physx::PxCollection& collection = reinterpret_cast<physx::PxCollection&>(*collection_pod);
        PxSerialization::createSerialObjectIds(collection, base);
    }

    physx_PxCollection_Pod* PxSerialization_createCollectionFromXml(physx_PxInputData_Pod* inputData_pod, physx_PxCooking_Pod* cooking_pod, physx_PxSerializationRegistry_Pod* sr_pod, physx_PxCollection_Pod const* externalRefs_pod, physx_PxStringTable_Pod* stringTable_pod, physx_PxXmlMiscParameter_Pod* outArgs_pod) {
        physx::PxInputData& inputData = reinterpret_cast<physx::PxInputData&>(*inputData_pod);
        physx::PxCooking& cooking = reinterpret_cast<physx::PxCooking&>(*cooking_pod);
        physx::PxSerializationRegistry& sr = reinterpret_cast<physx::PxSerializationRegistry&>(*sr_pod);
        physx::PxCollection const* externalRefs = reinterpret_cast<physx::PxCollection const*>(externalRefs_pod);
        physx::PxStringTable* stringTable = reinterpret_cast<physx::PxStringTable*>(stringTable_pod);
        physx::PxXmlMiscParameter* outArgs = reinterpret_cast<physx::PxXmlMiscParameter*>(outArgs_pod);
        physx::PxCollection* return_val = PxSerialization::createCollectionFromXml(inputData, cooking, sr, externalRefs, stringTable, outArgs);
        auto return_val_pod = reinterpret_cast<physx_PxCollection_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxCollection_Pod* PxSerialization_createCollectionFromBinary(void* memBlock, physx_PxSerializationRegistry_Pod* sr_pod, physx_PxCollection_Pod const* externalRefs_pod) {
        physx::PxSerializationRegistry& sr = reinterpret_cast<physx::PxSerializationRegistry&>(*sr_pod);
        physx::PxCollection const* externalRefs = reinterpret_cast<physx::PxCollection const*>(externalRefs_pod);
        physx::PxCollection* return_val = PxSerialization::createCollectionFromBinary(memBlock, sr, externalRefs);
        auto return_val_pod = reinterpret_cast<physx_PxCollection_Pod*>(return_val);
        return return_val_pod;
    }

    bool PxSerialization_serializeCollectionToXml(physx_PxOutputStream_Pod* outputStream_pod, physx_PxCollection_Pod* collection_pod, physx_PxSerializationRegistry_Pod* sr_pod, physx_PxCooking_Pod* cooking_pod, physx_PxCollection_Pod const* externalRefs_pod, physx_PxXmlMiscParameter_Pod* inArgs_pod) {
        physx::PxOutputStream& outputStream = reinterpret_cast<physx::PxOutputStream&>(*outputStream_pod);
        physx::PxCollection& collection = reinterpret_cast<physx::PxCollection&>(*collection_pod);
        physx::PxSerializationRegistry& sr = reinterpret_cast<physx::PxSerializationRegistry&>(*sr_pod);
        physx::PxCooking* cooking = reinterpret_cast<physx::PxCooking*>(cooking_pod);
        physx::PxCollection const* externalRefs = reinterpret_cast<physx::PxCollection const*>(externalRefs_pod);
        physx::PxXmlMiscParameter* inArgs = reinterpret_cast<physx::PxXmlMiscParameter*>(inArgs_pod);
        bool return_val = PxSerialization::serializeCollectionToXml(outputStream, collection, sr, cooking, externalRefs, inArgs);
        return return_val;
    }

    bool PxSerialization_serializeCollectionToBinary(physx_PxOutputStream_Pod* outputStream_pod, physx_PxCollection_Pod* collection_pod, physx_PxSerializationRegistry_Pod* sr_pod, physx_PxCollection_Pod const* externalRefs_pod, bool exportNames) {
        physx::PxOutputStream& outputStream = reinterpret_cast<physx::PxOutputStream&>(*outputStream_pod);
        physx::PxCollection& collection = reinterpret_cast<physx::PxCollection&>(*collection_pod);
        physx::PxSerializationRegistry& sr = reinterpret_cast<physx::PxSerializationRegistry&>(*sr_pod);
        physx::PxCollection const* externalRefs = reinterpret_cast<physx::PxCollection const*>(externalRefs_pod);
        bool return_val = PxSerialization::serializeCollectionToBinary(outputStream, collection, sr, externalRefs, exportNames);
        return return_val;
    }

    physx_PxSerializationRegistry_Pod* PxSerialization_createSerializationRegistry(physx_PxPhysics_Pod* physics_pod) {
        physx::PxPhysics& physics = reinterpret_cast<physx::PxPhysics&>(*physics_pod);
        physx::PxSerializationRegistry* return_val = PxSerialization::createSerializationRegistry(physics);
        auto return_val_pod = reinterpret_cast<physx_PxSerializationRegistry_Pod*>(return_val);
        return return_val_pod;
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
        bool return_val = self_->getRunProfiled();
        return return_val;
    }

    physx_PxDefaultCpuDispatcher_Pod* phys_PxDefaultCpuDispatcherCreate(uint32_t numThreads, uint32_t* affinityMasks, int32_t mode_pod, uint32_t yieldProcessorCount) {
        auto mode = static_cast<physx::PxDefaultCpuDispatcherWaitForWorkMode::Enum>(mode_pod);
        physx::PxDefaultCpuDispatcher* return_val = PxDefaultCpuDispatcherCreate(numThreads, affinityMasks, mode, yieldProcessorCount);
        auto return_val_pod = reinterpret_cast<physx_PxDefaultCpuDispatcher_Pod*>(return_val);
        return return_val_pod;
    }

    bool phys_PxBuildSmoothNormals(uint32_t nbTris, uint32_t nbVerts, physx_PxVec3_Pod const* verts_pod, uint32_t const* dFaces, uint16_t const* wFaces, physx_PxVec3_Pod* normals_pod, bool flip) {
        physx::PxVec3 const* verts = reinterpret_cast<physx::PxVec3 const*>(verts_pod);
        physx::PxVec3* normals = reinterpret_cast<physx::PxVec3*>(normals_pod);
        bool return_val = PxBuildSmoothNormals(nbTris, nbVerts, verts, dFaces, wFaces, normals, flip);
        return return_val;
    }

    physx_PxRigidDynamic_Pod* phys_PxCreateDynamic(physx_PxPhysics_Pod* sdk_pod, physx_PxTransform_Pod const* transform_pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxMaterial_Pod* material_pod, float density, physx_PxTransform_Pod const* shapeOffset_pod) {
        physx::PxPhysics& sdk = reinterpret_cast<physx::PxPhysics&>(*sdk_pod);
        physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
        physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
        physx::PxMaterial& material = reinterpret_cast<physx::PxMaterial&>(*material_pod);
        physx::PxTransform const& shapeOffset = reinterpret_cast<physx::PxTransform const&>(*shapeOffset_pod);
        physx::PxRigidDynamic* return_val = PxCreateDynamic(sdk, transform, geometry, material, density, shapeOffset);
        auto return_val_pod = reinterpret_cast<physx_PxRigidDynamic_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxRigidDynamic_Pod* phys_PxCreateDynamic_1(physx_PxPhysics_Pod* sdk_pod, physx_PxTransform_Pod const* transform_pod, physx_PxShape_Pod* shape_pod, float density) {
        physx::PxPhysics& sdk = reinterpret_cast<physx::PxPhysics&>(*sdk_pod);
        physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
        physx::PxShape& shape = reinterpret_cast<physx::PxShape&>(*shape_pod);
        physx::PxRigidDynamic* return_val = PxCreateDynamic(sdk, transform, shape, density);
        auto return_val_pod = reinterpret_cast<physx_PxRigidDynamic_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxRigidDynamic_Pod* phys_PxCreateKinematic(physx_PxPhysics_Pod* sdk_pod, physx_PxTransform_Pod const* transform_pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxMaterial_Pod* material_pod, float density, physx_PxTransform_Pod const* shapeOffset_pod) {
        physx::PxPhysics& sdk = reinterpret_cast<physx::PxPhysics&>(*sdk_pod);
        physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
        physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
        physx::PxMaterial& material = reinterpret_cast<physx::PxMaterial&>(*material_pod);
        physx::PxTransform const& shapeOffset = reinterpret_cast<physx::PxTransform const&>(*shapeOffset_pod);
        physx::PxRigidDynamic* return_val = PxCreateKinematic(sdk, transform, geometry, material, density, shapeOffset);
        auto return_val_pod = reinterpret_cast<physx_PxRigidDynamic_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxRigidDynamic_Pod* phys_PxCreateKinematic_1(physx_PxPhysics_Pod* sdk_pod, physx_PxTransform_Pod const* transform_pod, physx_PxShape_Pod* shape_pod, float density) {
        physx::PxPhysics& sdk = reinterpret_cast<physx::PxPhysics&>(*sdk_pod);
        physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
        physx::PxShape& shape = reinterpret_cast<physx::PxShape&>(*shape_pod);
        physx::PxRigidDynamic* return_val = PxCreateKinematic(sdk, transform, shape, density);
        auto return_val_pod = reinterpret_cast<physx_PxRigidDynamic_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxRigidStatic_Pod* phys_PxCreateStatic(physx_PxPhysics_Pod* sdk_pod, physx_PxTransform_Pod const* transform_pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxMaterial_Pod* material_pod, physx_PxTransform_Pod const* shapeOffset_pod) {
        physx::PxPhysics& sdk = reinterpret_cast<physx::PxPhysics&>(*sdk_pod);
        physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
        physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
        physx::PxMaterial& material = reinterpret_cast<physx::PxMaterial&>(*material_pod);
        physx::PxTransform const& shapeOffset = reinterpret_cast<physx::PxTransform const&>(*shapeOffset_pod);
        physx::PxRigidStatic* return_val = PxCreateStatic(sdk, transform, geometry, material, shapeOffset);
        auto return_val_pod = reinterpret_cast<physx_PxRigidStatic_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxRigidStatic_Pod* phys_PxCreateStatic_1(physx_PxPhysics_Pod* sdk_pod, physx_PxTransform_Pod const* transform_pod, physx_PxShape_Pod* shape_pod) {
        physx::PxPhysics& sdk = reinterpret_cast<physx::PxPhysics&>(*sdk_pod);
        physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
        physx::PxShape& shape = reinterpret_cast<physx::PxShape&>(*shape_pod);
        physx::PxRigidStatic* return_val = PxCreateStatic(sdk, transform, shape);
        auto return_val_pod = reinterpret_cast<physx_PxRigidStatic_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxShape_Pod* phys_PxCloneShape(physx_PxPhysics_Pod* physicsSDK_pod, physx_PxShape_Pod const* shape_pod, bool isExclusive) {
        physx::PxPhysics& physicsSDK = reinterpret_cast<physx::PxPhysics&>(*physicsSDK_pod);
        physx::PxShape const& shape = reinterpret_cast<physx::PxShape const&>(*shape_pod);
        physx::PxShape* return_val = PxCloneShape(physicsSDK, shape, isExclusive);
        auto return_val_pod = reinterpret_cast<physx_PxShape_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxRigidStatic_Pod* phys_PxCloneStatic(physx_PxPhysics_Pod* physicsSDK_pod, physx_PxTransform_Pod const* transform_pod, physx_PxRigidActor_Pod const* actor_pod) {
        physx::PxPhysics& physicsSDK = reinterpret_cast<physx::PxPhysics&>(*physicsSDK_pod);
        physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
        physx::PxRigidActor const& actor = reinterpret_cast<physx::PxRigidActor const&>(*actor_pod);
        physx::PxRigidStatic* return_val = PxCloneStatic(physicsSDK, transform, actor);
        auto return_val_pod = reinterpret_cast<physx_PxRigidStatic_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxRigidDynamic_Pod* phys_PxCloneDynamic(physx_PxPhysics_Pod* physicsSDK_pod, physx_PxTransform_Pod const* transform_pod, physx_PxRigidDynamic_Pod const* body_pod) {
        physx::PxPhysics& physicsSDK = reinterpret_cast<physx::PxPhysics&>(*physicsSDK_pod);
        physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
        physx::PxRigidDynamic const& body = reinterpret_cast<physx::PxRigidDynamic const&>(*body_pod);
        physx::PxRigidDynamic* return_val = PxCloneDynamic(physicsSDK, transform, body);
        auto return_val_pod = reinterpret_cast<physx_PxRigidDynamic_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxRigidStatic_Pod* phys_PxCreatePlane(physx_PxPhysics_Pod* sdk_pod, physx_PxPlane_Pod const* plane_pod, physx_PxMaterial_Pod* material_pod) {
        physx::PxPhysics& sdk = reinterpret_cast<physx::PxPhysics&>(*sdk_pod);
        physx::PxPlane const& plane = reinterpret_cast<physx::PxPlane const&>(*plane_pod);
        physx::PxMaterial& material = reinterpret_cast<physx::PxMaterial&>(*material_pod);
        physx::PxRigidStatic* return_val = PxCreatePlane(sdk, plane, material);
        auto return_val_pod = reinterpret_cast<physx_PxRigidStatic_Pod*>(return_val);
        return return_val_pod;
    }

    void phys_PxScaleRigidActor(physx_PxRigidActor_Pod* actor_pod, float scale, bool scaleMassProps) {
        physx::PxRigidActor& actor = reinterpret_cast<physx::PxRigidActor&>(*actor_pod);
        PxScaleRigidActor(actor, scale, scaleMassProps);
    }

    physx_PxStringTable_Pod* PxStringTableExt_createStringTable(physx_PxAllocatorCallback_Pod* inAllocator_pod) {
        physx::PxAllocatorCallback& inAllocator = reinterpret_cast<physx::PxAllocatorCallback&>(*inAllocator_pod);
        physx::PxStringTable& return_val = PxStringTableExt::createStringTable(inAllocator);
        auto return_val_pod = reinterpret_cast<physx_PxStringTable_Pod*>(&return_val);
        return return_val_pod;
    }

    uint32_t PxBroadPhaseExt_createRegionsFromWorldBounds(physx_PxBounds3_Pod* regions_pod, physx_PxBounds3_Pod const* globalBounds_pod, uint32_t nbSubdiv, uint32_t upAxis) {
        physx::PxBounds3* regions = reinterpret_cast<physx::PxBounds3*>(regions_pod);
        physx::PxBounds3 const& globalBounds = reinterpret_cast<physx::PxBounds3 const&>(*globalBounds_pod);
        uint32_t return_val = PxBroadPhaseExt::createRegionsFromWorldBounds(regions, globalBounds, nbSubdiv, upAxis);
        return return_val;
    }

    bool PxSceneQueryExt_raycastAny(physx_PxScene_Pod const* scene_pod, physx_PxVec3_Pod const* origin_pod, physx_PxVec3_Pod const* unitDir_pod, float distance, physx_PxQueryHit_Pod* hit_pod, physx_PxQueryFilterData_Pod const* filterData_pod, physx_PxQueryFilterCallback_Pod* filterCall_pod, physx_PxQueryCache_Pod const* cache_pod) {
        physx::PxScene const& scene = reinterpret_cast<physx::PxScene const&>(*scene_pod);
        physx::PxVec3 const& origin = reinterpret_cast<physx::PxVec3 const&>(*origin_pod);
        physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
        physx::PxQueryHit& hit = reinterpret_cast<physx::PxQueryHit&>(*hit_pod);
        physx::PxQueryFilterData const& filterData = reinterpret_cast<physx::PxQueryFilterData const&>(*filterData_pod);
        physx::PxQueryFilterCallback* filterCall = reinterpret_cast<physx::PxQueryFilterCallback*>(filterCall_pod);
        physx::PxQueryCache const* cache = reinterpret_cast<physx::PxQueryCache const*>(cache_pod);
        bool return_val = PxSceneQueryExt::raycastAny(scene, origin, unitDir, distance, hit, filterData, filterCall, cache);
        return return_val;
    }

    bool PxSceneQueryExt_raycastSingle(physx_PxScene_Pod const* scene_pod, physx_PxVec3_Pod const* origin_pod, physx_PxVec3_Pod const* unitDir_pod, float distance, uint16_t outputFlags_pod, physx_PxRaycastHit_Pod* hit_pod, physx_PxQueryFilterData_Pod const* filterData_pod, physx_PxQueryFilterCallback_Pod* filterCall_pod, physx_PxQueryCache_Pod const* cache_pod) {
        physx::PxScene const& scene = reinterpret_cast<physx::PxScene const&>(*scene_pod);
        physx::PxVec3 const& origin = reinterpret_cast<physx::PxVec3 const&>(*origin_pod);
        physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
        auto outputFlags = physx::PxHitFlags(outputFlags_pod);
        physx::PxRaycastHit& hit = reinterpret_cast<physx::PxRaycastHit&>(*hit_pod);
        physx::PxQueryFilterData const& filterData = reinterpret_cast<physx::PxQueryFilterData const&>(*filterData_pod);
        physx::PxQueryFilterCallback* filterCall = reinterpret_cast<physx::PxQueryFilterCallback*>(filterCall_pod);
        physx::PxQueryCache const* cache = reinterpret_cast<physx::PxQueryCache const*>(cache_pod);
        bool return_val = PxSceneQueryExt::raycastSingle(scene, origin, unitDir, distance, outputFlags, hit, filterData, filterCall, cache);
        return return_val;
    }

    int32_t PxSceneQueryExt_raycastMultiple(physx_PxScene_Pod const* scene_pod, physx_PxVec3_Pod const* origin_pod, physx_PxVec3_Pod const* unitDir_pod, float distance, uint16_t outputFlags_pod, physx_PxRaycastHit_Pod* hitBuffer_pod, uint32_t hitBufferSize, bool* blockingHit_pod, physx_PxQueryFilterData_Pod const* filterData_pod, physx_PxQueryFilterCallback_Pod* filterCall_pod, physx_PxQueryCache_Pod const* cache_pod) {
        physx::PxScene const& scene = reinterpret_cast<physx::PxScene const&>(*scene_pod);
        physx::PxVec3 const& origin = reinterpret_cast<physx::PxVec3 const&>(*origin_pod);
        physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
        auto outputFlags = physx::PxHitFlags(outputFlags_pod);
        physx::PxRaycastHit* hitBuffer = reinterpret_cast<physx::PxRaycastHit*>(hitBuffer_pod);
        bool& blockingHit = *blockingHit_pod;
        physx::PxQueryFilterData const& filterData = reinterpret_cast<physx::PxQueryFilterData const&>(*filterData_pod);
        physx::PxQueryFilterCallback* filterCall = reinterpret_cast<physx::PxQueryFilterCallback*>(filterCall_pod);
        physx::PxQueryCache const* cache = reinterpret_cast<physx::PxQueryCache const*>(cache_pod);
        int32_t return_val = PxSceneQueryExt::raycastMultiple(scene, origin, unitDir, distance, outputFlags, hitBuffer, hitBufferSize, blockingHit, filterData, filterCall, cache);
        return return_val;
    }

    bool PxSceneQueryExt_sweepAny(physx_PxScene_Pod const* scene_pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxTransform_Pod const* pose_pod, physx_PxVec3_Pod const* unitDir_pod, float distance, uint16_t queryFlags_pod, physx_PxQueryHit_Pod* hit_pod, physx_PxQueryFilterData_Pod const* filterData_pod, physx_PxQueryFilterCallback_Pod* filterCall_pod, physx_PxQueryCache_Pod const* cache_pod, float inflation) {
        physx::PxScene const& scene = reinterpret_cast<physx::PxScene const&>(*scene_pod);
        physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
        auto queryFlags = physx::PxHitFlags(queryFlags_pod);
        physx::PxQueryHit& hit = reinterpret_cast<physx::PxQueryHit&>(*hit_pod);
        physx::PxQueryFilterData const& filterData = reinterpret_cast<physx::PxQueryFilterData const&>(*filterData_pod);
        physx::PxQueryFilterCallback* filterCall = reinterpret_cast<physx::PxQueryFilterCallback*>(filterCall_pod);
        physx::PxQueryCache const* cache = reinterpret_cast<physx::PxQueryCache const*>(cache_pod);
        bool return_val = PxSceneQueryExt::sweepAny(scene, geometry, pose, unitDir, distance, queryFlags, hit, filterData, filterCall, cache, inflation);
        return return_val;
    }

    bool PxSceneQueryExt_sweepSingle(physx_PxScene_Pod const* scene_pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxTransform_Pod const* pose_pod, physx_PxVec3_Pod const* unitDir_pod, float distance, uint16_t outputFlags_pod, physx_PxSweepHit_Pod* hit_pod, physx_PxQueryFilterData_Pod const* filterData_pod, physx_PxQueryFilterCallback_Pod* filterCall_pod, physx_PxQueryCache_Pod const* cache_pod, float inflation) {
        physx::PxScene const& scene = reinterpret_cast<physx::PxScene const&>(*scene_pod);
        physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
        auto outputFlags = physx::PxHitFlags(outputFlags_pod);
        physx::PxSweepHit& hit = reinterpret_cast<physx::PxSweepHit&>(*hit_pod);
        physx::PxQueryFilterData const& filterData = reinterpret_cast<physx::PxQueryFilterData const&>(*filterData_pod);
        physx::PxQueryFilterCallback* filterCall = reinterpret_cast<physx::PxQueryFilterCallback*>(filterCall_pod);
        physx::PxQueryCache const* cache = reinterpret_cast<physx::PxQueryCache const*>(cache_pod);
        bool return_val = PxSceneQueryExt::sweepSingle(scene, geometry, pose, unitDir, distance, outputFlags, hit, filterData, filterCall, cache, inflation);
        return return_val;
    }

    int32_t PxSceneQueryExt_sweepMultiple(physx_PxScene_Pod const* scene_pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxTransform_Pod const* pose_pod, physx_PxVec3_Pod const* unitDir_pod, float distance, uint16_t outputFlags_pod, physx_PxSweepHit_Pod* hitBuffer_pod, uint32_t hitBufferSize, bool* blockingHit_pod, physx_PxQueryFilterData_Pod const* filterData_pod, physx_PxQueryFilterCallback_Pod* filterCall_pod, physx_PxQueryCache_Pod const* cache_pod, float inflation) {
        physx::PxScene const& scene = reinterpret_cast<physx::PxScene const&>(*scene_pod);
        physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
        auto outputFlags = physx::PxHitFlags(outputFlags_pod);
        physx::PxSweepHit* hitBuffer = reinterpret_cast<physx::PxSweepHit*>(hitBuffer_pod);
        bool& blockingHit = *blockingHit_pod;
        physx::PxQueryFilterData const& filterData = reinterpret_cast<physx::PxQueryFilterData const&>(*filterData_pod);
        physx::PxQueryFilterCallback* filterCall = reinterpret_cast<physx::PxQueryFilterCallback*>(filterCall_pod);
        physx::PxQueryCache const* cache = reinterpret_cast<physx::PxQueryCache const*>(cache_pod);
        int32_t return_val = PxSceneQueryExt::sweepMultiple(scene, geometry, pose, unitDir, distance, outputFlags, hitBuffer, hitBufferSize, blockingHit, filterData, filterCall, cache, inflation);
        return return_val;
    }

    int32_t PxSceneQueryExt_overlapMultiple(physx_PxScene_Pod const* scene_pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxTransform_Pod const* pose_pod, physx_PxOverlapHit_Pod* hitBuffer_pod, uint32_t hitBufferSize, physx_PxQueryFilterData_Pod const* filterData_pod, physx_PxQueryFilterCallback_Pod* filterCall_pod) {
        physx::PxScene const& scene = reinterpret_cast<physx::PxScene const&>(*scene_pod);
        physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        physx::PxOverlapHit* hitBuffer = reinterpret_cast<physx::PxOverlapHit*>(hitBuffer_pod);
        physx::PxQueryFilterData const& filterData = reinterpret_cast<physx::PxQueryFilterData const&>(*filterData_pod);
        physx::PxQueryFilterCallback* filterCall = reinterpret_cast<physx::PxQueryFilterCallback*>(filterCall_pod);
        int32_t return_val = PxSceneQueryExt::overlapMultiple(scene, geometry, pose, hitBuffer, hitBufferSize, filterData, filterCall);
        return return_val;
    }

    bool PxSceneQueryExt_overlapAny(physx_PxScene_Pod const* scene_pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxTransform_Pod const* pose_pod, physx_PxOverlapHit_Pod* hit_pod, physx_PxQueryFilterData_Pod const* filterData_pod, physx_PxQueryFilterCallback_Pod* filterCall_pod) {
        physx::PxScene const& scene = reinterpret_cast<physx::PxScene const&>(*scene_pod);
        physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        physx::PxOverlapHit& hit = reinterpret_cast<physx::PxOverlapHit&>(*hit_pod);
        physx::PxQueryFilterData const& filterData = reinterpret_cast<physx::PxQueryFilterData const&>(*filterData_pod);
        physx::PxQueryFilterCallback* filterCall = reinterpret_cast<physx::PxQueryFilterCallback*>(filterCall_pod);
        bool return_val = PxSceneQueryExt::overlapAny(scene, geometry, pose, hit, filterData, filterCall);
        return return_val;
    }

    void PxBatchQueryExt_release_mut(physx_PxBatchQueryExt_Pod* self__pod) {
        physx::PxBatchQueryExt* self_ = reinterpret_cast<physx::PxBatchQueryExt*>(self__pod);
        self_->release();
    }

    physx_PxRaycastBuffer_Pod* PxBatchQueryExt_raycast_mut(physx_PxBatchQueryExt_Pod* self__pod, physx_PxVec3_Pod const* origin_pod, physx_PxVec3_Pod const* unitDir_pod, float distance, uint16_t maxNbTouches, uint16_t hitFlags_pod, physx_PxQueryFilterData_Pod const* filterData_pod, physx_PxQueryCache_Pod const* cache_pod) {
        physx::PxBatchQueryExt* self_ = reinterpret_cast<physx::PxBatchQueryExt*>(self__pod);
        physx::PxVec3 const& origin = reinterpret_cast<physx::PxVec3 const&>(*origin_pod);
        physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
        auto hitFlags = physx::PxHitFlags(hitFlags_pod);
        physx::PxQueryFilterData const& filterData = reinterpret_cast<physx::PxQueryFilterData const&>(*filterData_pod);
        physx::PxQueryCache const* cache = reinterpret_cast<physx::PxQueryCache const*>(cache_pod);
        physx::PxRaycastBuffer* return_val = self_->raycast(origin, unitDir, distance, maxNbTouches, hitFlags, filterData, cache);
        auto return_val_pod = reinterpret_cast<physx_PxRaycastBuffer_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxSweepBuffer_Pod* PxBatchQueryExt_sweep_mut(physx_PxBatchQueryExt_Pod* self__pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxTransform_Pod const* pose_pod, physx_PxVec3_Pod const* unitDir_pod, float distance, uint16_t maxNbTouches, uint16_t hitFlags_pod, physx_PxQueryFilterData_Pod const* filterData_pod, physx_PxQueryCache_Pod const* cache_pod, float inflation) {
        physx::PxBatchQueryExt* self_ = reinterpret_cast<physx::PxBatchQueryExt*>(self__pod);
        physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
        auto hitFlags = physx::PxHitFlags(hitFlags_pod);
        physx::PxQueryFilterData const& filterData = reinterpret_cast<physx::PxQueryFilterData const&>(*filterData_pod);
        physx::PxQueryCache const* cache = reinterpret_cast<physx::PxQueryCache const*>(cache_pod);
        physx::PxSweepBuffer* return_val = self_->sweep(geometry, pose, unitDir, distance, maxNbTouches, hitFlags, filterData, cache, inflation);
        auto return_val_pod = reinterpret_cast<physx_PxSweepBuffer_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxOverlapBuffer_Pod* PxBatchQueryExt_overlap_mut(physx_PxBatchQueryExt_Pod* self__pod, physx_PxGeometry_Pod const* geometry_pod, physx_PxTransform_Pod const* pose_pod, uint16_t maxNbTouches, physx_PxQueryFilterData_Pod const* filterData_pod, physx_PxQueryCache_Pod const* cache_pod) {
        physx::PxBatchQueryExt* self_ = reinterpret_cast<physx::PxBatchQueryExt*>(self__pod);
        physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
        physx::PxTransform const& pose = reinterpret_cast<physx::PxTransform const&>(*pose_pod);
        physx::PxQueryFilterData const& filterData = reinterpret_cast<physx::PxQueryFilterData const&>(*filterData_pod);
        physx::PxQueryCache const* cache = reinterpret_cast<physx::PxQueryCache const*>(cache_pod);
        physx::PxOverlapBuffer* return_val = self_->overlap(geometry, pose, maxNbTouches, filterData, cache);
        auto return_val_pod = reinterpret_cast<physx_PxOverlapBuffer_Pod*>(return_val);
        return return_val_pod;
    }

    void PxBatchQueryExt_execute_mut(physx_PxBatchQueryExt_Pod* self__pod) {
        physx::PxBatchQueryExt* self_ = reinterpret_cast<physx::PxBatchQueryExt*>(self__pod);
        self_->execute();
    }

    physx_PxBatchQueryExt_Pod* phys_PxCreateBatchQueryExt(physx_PxScene_Pod const* scene_pod, physx_PxQueryFilterCallback_Pod* queryFilterCallback_pod, uint32_t maxNbRaycasts, uint32_t maxNbRaycastTouches, uint32_t maxNbSweeps, uint32_t maxNbSweepTouches, uint32_t maxNbOverlaps, uint32_t maxNbOverlapTouches) {
        physx::PxScene const& scene = reinterpret_cast<physx::PxScene const&>(*scene_pod);
        physx::PxQueryFilterCallback* queryFilterCallback = reinterpret_cast<physx::PxQueryFilterCallback*>(queryFilterCallback_pod);
        physx::PxBatchQueryExt* return_val = PxCreateBatchQueryExt(scene, queryFilterCallback, maxNbRaycasts, maxNbRaycastTouches, maxNbSweeps, maxNbSweepTouches, maxNbOverlaps, maxNbOverlapTouches);
        auto return_val_pod = reinterpret_cast<physx_PxBatchQueryExt_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxBatchQueryExt_Pod* phys_PxCreateBatchQueryExt_1(physx_PxScene_Pod const* scene_pod, physx_PxQueryFilterCallback_Pod* queryFilterCallback_pod, physx_PxRaycastBuffer_Pod* raycastBuffers_pod, uint32_t maxNbRaycasts, physx_PxRaycastHit_Pod* raycastTouches_pod, uint32_t maxNbRaycastTouches, physx_PxSweepBuffer_Pod* sweepBuffers_pod, uint32_t maxNbSweeps, physx_PxSweepHit_Pod* sweepTouches_pod, uint32_t maxNbSweepTouches, physx_PxOverlapBuffer_Pod* overlapBuffers_pod, uint32_t maxNbOverlaps, physx_PxOverlapHit_Pod* overlapTouches_pod, uint32_t maxNbOverlapTouches) {
        physx::PxScene const& scene = reinterpret_cast<physx::PxScene const&>(*scene_pod);
        physx::PxQueryFilterCallback* queryFilterCallback = reinterpret_cast<physx::PxQueryFilterCallback*>(queryFilterCallback_pod);
        physx::PxRaycastBuffer* raycastBuffers = reinterpret_cast<physx::PxRaycastBuffer*>(raycastBuffers_pod);
        physx::PxRaycastHit* raycastTouches = reinterpret_cast<physx::PxRaycastHit*>(raycastTouches_pod);
        physx::PxSweepBuffer* sweepBuffers = reinterpret_cast<physx::PxSweepBuffer*>(sweepBuffers_pod);
        physx::PxSweepHit* sweepTouches = reinterpret_cast<physx::PxSweepHit*>(sweepTouches_pod);
        physx::PxOverlapBuffer* overlapBuffers = reinterpret_cast<physx::PxOverlapBuffer*>(overlapBuffers_pod);
        physx::PxOverlapHit* overlapTouches = reinterpret_cast<physx::PxOverlapHit*>(overlapTouches_pod);
        physx::PxBatchQueryExt* return_val = PxCreateBatchQueryExt(scene, queryFilterCallback, raycastBuffers, maxNbRaycasts, raycastTouches, maxNbRaycastTouches, sweepBuffers, maxNbSweeps, sweepTouches, maxNbSweepTouches, overlapBuffers, maxNbOverlaps, overlapTouches, maxNbOverlapTouches);
        auto return_val_pod = reinterpret_cast<physx_PxBatchQueryExt_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxSceneQuerySystem_Pod* phys_PxCreateExternalSceneQuerySystem(physx_PxSceneQueryDesc_Pod const* desc_pod, uint64_t contextID) {
        physx::PxSceneQueryDesc const& desc = reinterpret_cast<physx::PxSceneQueryDesc const&>(*desc_pod);
        physx::PxSceneQuerySystem* return_val = PxCreateExternalSceneQuerySystem(desc, contextID);
        auto return_val_pod = reinterpret_cast<physx_PxSceneQuerySystem_Pod*>(return_val);
        return return_val_pod;
    }

    uint32_t PxCustomSceneQuerySystem_addPruner_mut(physx_PxCustomSceneQuerySystem_Pod* self__pod, int32_t primaryType_pod, int32_t secondaryType_pod, uint32_t preallocated) {
        physx::PxCustomSceneQuerySystem* self_ = reinterpret_cast<physx::PxCustomSceneQuerySystem*>(self__pod);
        auto primaryType = static_cast<physx::PxPruningStructureType::Enum>(primaryType_pod);
        auto secondaryType = static_cast<physx::PxDynamicTreeSecondaryPruner::Enum>(secondaryType_pod);
        uint32_t return_val = self_->addPruner(primaryType, secondaryType, preallocated);
        return return_val;
    }

    uint32_t PxCustomSceneQuerySystem_startCustomBuildstep_mut(physx_PxCustomSceneQuerySystem_Pod* self__pod) {
        physx::PxCustomSceneQuerySystem* self_ = reinterpret_cast<physx::PxCustomSceneQuerySystem*>(self__pod);
        uint32_t return_val = self_->startCustomBuildstep();
        return return_val;
    }

    void PxCustomSceneQuerySystem_customBuildstep_mut(physx_PxCustomSceneQuerySystem_Pod* self__pod, uint32_t index) {
        physx::PxCustomSceneQuerySystem* self_ = reinterpret_cast<physx::PxCustomSceneQuerySystem*>(self__pod);
        self_->customBuildstep(index);
    }

    void PxCustomSceneQuerySystem_finishCustomBuildstep_mut(physx_PxCustomSceneQuerySystem_Pod* self__pod) {
        physx::PxCustomSceneQuerySystem* self_ = reinterpret_cast<physx::PxCustomSceneQuerySystem*>(self__pod);
        self_->finishCustomBuildstep();
    }

    void PxCustomSceneQuerySystemAdapter_delete(physx_PxCustomSceneQuerySystemAdapter_Pod* self__pod) {
        physx::PxCustomSceneQuerySystemAdapter* self_ = reinterpret_cast<physx::PxCustomSceneQuerySystemAdapter*>(self__pod);
        delete self_;
    }

    uint32_t PxCustomSceneQuerySystemAdapter_getPrunerIndex(physx_PxCustomSceneQuerySystemAdapter_Pod const* self__pod, physx_PxRigidActor_Pod const* actor_pod, physx_PxShape_Pod const* shape_pod) {
        physx::PxCustomSceneQuerySystemAdapter const* self_ = reinterpret_cast<physx::PxCustomSceneQuerySystemAdapter const*>(self__pod);
        physx::PxRigidActor const& actor = reinterpret_cast<physx::PxRigidActor const&>(*actor_pod);
        physx::PxShape const& shape = reinterpret_cast<physx::PxShape const&>(*shape_pod);
        uint32_t return_val = self_->getPrunerIndex(actor, shape);
        return return_val;
    }

    bool PxCustomSceneQuerySystemAdapter_processPruner(physx_PxCustomSceneQuerySystemAdapter_Pod const* self__pod, uint32_t prunerIndex, physx_PxQueryThreadContext_Pod const* context_pod, physx_PxQueryFilterData_Pod const* filterData_pod, physx_PxQueryFilterCallback_Pod* filterCall_pod) {
        physx::PxCustomSceneQuerySystemAdapter const* self_ = reinterpret_cast<physx::PxCustomSceneQuerySystemAdapter const*>(self__pod);
        physx::PxQueryThreadContext const* context = reinterpret_cast<physx::PxQueryThreadContext const*>(context_pod);
        physx::PxQueryFilterData const& filterData = reinterpret_cast<physx::PxQueryFilterData const&>(*filterData_pod);
        physx::PxQueryFilterCallback* filterCall = reinterpret_cast<physx::PxQueryFilterCallback*>(filterCall_pod);
        bool return_val = self_->processPruner(prunerIndex, context, filterData, filterCall);
        return return_val;
    }

    physx_PxCustomSceneQuerySystem_Pod* phys_PxCreateCustomSceneQuerySystem(int32_t sceneQueryUpdateMode_pod, uint64_t contextID, physx_PxCustomSceneQuerySystemAdapter_Pod const* adapter_pod, bool usesTreeOfPruners) {
        auto sceneQueryUpdateMode = static_cast<physx::PxSceneQueryUpdateMode::Enum>(sceneQueryUpdateMode_pod);
        physx::PxCustomSceneQuerySystemAdapter const& adapter = reinterpret_cast<physx::PxCustomSceneQuerySystemAdapter const&>(*adapter_pod);
        physx::PxCustomSceneQuerySystem* return_val = PxCreateCustomSceneQuerySystem(sceneQueryUpdateMode, contextID, adapter, usesTreeOfPruners);
        auto return_val_pod = reinterpret_cast<physx_PxCustomSceneQuerySystem_Pod*>(return_val);
        return return_val_pod;
    }

    uint32_t phys_PxFindFaceIndex(physx_PxConvexMeshGeometry_Pod const* convexGeom_pod, physx_PxTransform_Pod const* geomPose_pod, physx_PxVec3_Pod const* impactPos_pod, physx_PxVec3_Pod const* unitDir_pod) {
        physx::PxConvexMeshGeometry const& convexGeom = reinterpret_cast<physx::PxConvexMeshGeometry const&>(*convexGeom_pod);
        physx::PxTransform const& geomPose = reinterpret_cast<physx::PxTransform const&>(*geomPose_pod);
        physx::PxVec3 const& impactPos = reinterpret_cast<physx::PxVec3 const&>(*impactPos_pod);
        physx::PxVec3 const& unitDir = reinterpret_cast<physx::PxVec3 const&>(*unitDir_pod);
        uint32_t return_val = PxFindFaceIndex(convexGeom, geomPose, impactPos, unitDir);
        return return_val;
    }

    bool PxPoissonSampler_setSamplingRadius_mut(physx_PxPoissonSampler_Pod* self__pod, float samplingRadius) {
        physx::PxPoissonSampler* self_ = reinterpret_cast<physx::PxPoissonSampler*>(self__pod);
        bool return_val = self_->setSamplingRadius(samplingRadius);
        return return_val;
    }

    void PxPoissonSampler_addSamplesInSphere_mut(physx_PxPoissonSampler_Pod* self__pod, physx_PxVec3_Pod const* sphereCenter_pod, float sphereRadius, bool createVolumeSamples) {
        physx::PxPoissonSampler* self_ = reinterpret_cast<physx::PxPoissonSampler*>(self__pod);
        physx::PxVec3 const& sphereCenter = reinterpret_cast<physx::PxVec3 const&>(*sphereCenter_pod);
        self_->addSamplesInSphere(sphereCenter, sphereRadius, createVolumeSamples);
    }

    void PxPoissonSampler_addSamplesInBox_mut(physx_PxPoissonSampler_Pod* self__pod, physx_PxBounds3_Pod const* axisAlignedBox_pod, physx_PxQuat_Pod const* boxOrientation_pod, bool createVolumeSamples) {
        physx::PxPoissonSampler* self_ = reinterpret_cast<physx::PxPoissonSampler*>(self__pod);
        physx::PxBounds3 const& axisAlignedBox = reinterpret_cast<physx::PxBounds3 const&>(*axisAlignedBox_pod);
        physx::PxQuat const& boxOrientation = reinterpret_cast<physx::PxQuat const&>(*boxOrientation_pod);
        self_->addSamplesInBox(axisAlignedBox, boxOrientation, createVolumeSamples);
    }

    void PxPoissonSampler_delete(physx_PxPoissonSampler_Pod* self__pod) {
        physx::PxPoissonSampler* self_ = reinterpret_cast<physx::PxPoissonSampler*>(self__pod);
        delete self_;
    }

    physx_PxPoissonSampler_Pod* phys_PxCreateShapeSampler(physx_PxGeometry_Pod const* geometry_pod, physx_PxTransform_Pod const* transform_pod, physx_PxBounds3_Pod const* worldBounds_pod, float initialSamplingRadius, int32_t numSampleAttemptsAroundPoint) {
        physx::PxGeometry const& geometry = reinterpret_cast<physx::PxGeometry const&>(*geometry_pod);
        physx::PxTransform const& transform = reinterpret_cast<physx::PxTransform const&>(*transform_pod);
        physx::PxBounds3 const& worldBounds = reinterpret_cast<physx::PxBounds3 const&>(*worldBounds_pod);
        physx::PxPoissonSampler* return_val = PxCreateShapeSampler(geometry, transform, worldBounds, initialSamplingRadius, numSampleAttemptsAroundPoint);
        auto return_val_pod = reinterpret_cast<physx_PxPoissonSampler_Pod*>(return_val);
        return return_val_pod;
    }

    bool PxTriangleMeshPoissonSampler_isPointInTriangleMesh_mut(physx_PxTriangleMeshPoissonSampler_Pod* self__pod, physx_PxVec3_Pod const* p_pod) {
        physx::PxTriangleMeshPoissonSampler* self_ = reinterpret_cast<physx::PxTriangleMeshPoissonSampler*>(self__pod);
        physx::PxVec3 const& p = reinterpret_cast<physx::PxVec3 const&>(*p_pod);
        bool return_val = self_->isPointInTriangleMesh(p);
        return return_val;
    }

    void PxTriangleMeshPoissonSampler_delete(physx_PxTriangleMeshPoissonSampler_Pod* self__pod) {
        physx::PxTriangleMeshPoissonSampler* self_ = reinterpret_cast<physx::PxTriangleMeshPoissonSampler*>(self__pod);
        delete self_;
    }

    physx_PxTriangleMeshPoissonSampler_Pod* phys_PxCreateTriangleMeshSampler(uint32_t const* triangles, uint32_t numTriangles, physx_PxVec3_Pod const* vertices_pod, uint32_t numVertices, float initialSamplingRadius, int32_t numSampleAttemptsAroundPoint) {
        physx::PxVec3 const* vertices = reinterpret_cast<physx::PxVec3 const*>(vertices_pod);
        physx::PxTriangleMeshPoissonSampler* return_val = PxCreateTriangleMeshSampler(triangles, numTriangles, vertices, numVertices, initialSamplingRadius, numSampleAttemptsAroundPoint);
        auto return_val_pod = reinterpret_cast<physx_PxTriangleMeshPoissonSampler_Pod*>(return_val);
        return return_val_pod;
    }

    int32_t PxTetrahedronMeshExt_findTetrahedronContainingPoint(physx_PxTetrahedronMesh_Pod const* mesh_pod, physx_PxVec3_Pod const* point_pod, physx_PxVec4_Pod* bary_pod, float tolerance) {
        physx::PxTetrahedronMesh const* mesh = reinterpret_cast<physx::PxTetrahedronMesh const*>(mesh_pod);
        physx::PxVec3 const& point = reinterpret_cast<physx::PxVec3 const&>(*point_pod);
        physx::PxVec4& bary = reinterpret_cast<physx::PxVec4&>(*bary_pod);
        int32_t return_val = PxTetrahedronMeshExt::findTetrahedronContainingPoint(mesh, point, bary, tolerance);
        return return_val;
    }

    int32_t PxTetrahedronMeshExt_findTetrahedronClosestToPoint(physx_PxTetrahedronMesh_Pod const* mesh_pod, physx_PxVec3_Pod const* point_pod, physx_PxVec4_Pod* bary_pod) {
        physx::PxTetrahedronMesh const* mesh = reinterpret_cast<physx::PxTetrahedronMesh const*>(mesh_pod);
        physx::PxVec3 const& point = reinterpret_cast<physx::PxVec3 const&>(*point_pod);
        physx::PxVec4& bary = reinterpret_cast<physx::PxVec4&>(*bary_pod);
        int32_t return_val = PxTetrahedronMeshExt::findTetrahedronClosestToPoint(mesh, point, bary);
        return return_val;
    }

    bool phys_PxInitExtensions(physx_PxPhysics_Pod* physics_pod, physx_PxPvd_Pod* pvd_pod) {
        physx::PxPhysics& physics = reinterpret_cast<physx::PxPhysics&>(*physics_pod);
        physx::PxPvd* pvd = reinterpret_cast<physx::PxPvd*>(pvd_pod);
        bool return_val = PxInitExtensions(physics, pvd);
        return return_val;
    }

    void phys_PxCloseExtensions() {
        PxCloseExtensions();
    }

    physx_PxRepXObject_Pod PxRepXObject_new(char const* inTypeName, void const* inSerializable, uint64_t inId) {
        PxRepXObject return_val(inTypeName, inSerializable, inId);
        physx_PxRepXObject_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxRepXObject_isValid(physx_PxRepXObject_Pod const* self__pod) {
        physx::PxRepXObject const* self_ = reinterpret_cast<physx::PxRepXObject const*>(self__pod);
        bool return_val = self_->isValid();
        return return_val;
    }

    physx_PxRepXInstantiationArgs_Pod PxRepXInstantiationArgs_new(physx_PxPhysics_Pod* inPhysics_pod, physx_PxCooking_Pod* inCooking_pod, physx_PxStringTable_Pod* inStringTable_pod) {
        physx::PxPhysics& inPhysics = reinterpret_cast<physx::PxPhysics&>(*inPhysics_pod);
        physx::PxCooking* inCooking = reinterpret_cast<physx::PxCooking*>(inCooking_pod);
        physx::PxStringTable* inStringTable = reinterpret_cast<physx::PxStringTable*>(inStringTable_pod);
        PxRepXInstantiationArgs return_val(inPhysics, inCooking, inStringTable);
        physx_PxRepXInstantiationArgs_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    char const* PxRepXSerializer_getTypeName_mut(physx_PxRepXSerializer_Pod* self__pod) {
        physx::PxRepXSerializer* self_ = reinterpret_cast<physx::PxRepXSerializer*>(self__pod);
        char const* return_val = self_->getTypeName();
        return return_val;
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
        physx::PxRepXObject return_val = self_->fileToObject(inReader, inAllocator, inArgs, inCollection);
        physx_PxRepXObject_Pod return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    bool PxPvd_connect_mut(physx_PxPvd_Pod* self__pod, physx_PxPvdTransport_Pod* transport_pod, uint8_t flags_pod) {
        physx::PxPvd* self_ = reinterpret_cast<physx::PxPvd*>(self__pod);
        physx::PxPvdTransport& transport = reinterpret_cast<physx::PxPvdTransport&>(*transport_pod);
        auto flags = physx::PxPvdInstrumentationFlags(flags_pod);
        bool return_val = self_->connect(transport, flags);
        return return_val;
    }

    void PxPvd_disconnect_mut(physx_PxPvd_Pod* self__pod) {
        physx::PxPvd* self_ = reinterpret_cast<physx::PxPvd*>(self__pod);
        self_->disconnect();
    }

    bool PxPvd_isConnected_mut(physx_PxPvd_Pod* self__pod, bool useCachedStatus) {
        physx::PxPvd* self_ = reinterpret_cast<physx::PxPvd*>(self__pod);
        bool return_val = self_->isConnected(useCachedStatus);
        return return_val;
    }

    physx_PxPvdTransport_Pod* PxPvd_getTransport_mut(physx_PxPvd_Pod* self__pod) {
        physx::PxPvd* self_ = reinterpret_cast<physx::PxPvd*>(self__pod);
        physx::PxPvdTransport* return_val = self_->getTransport();
        auto return_val_pod = reinterpret_cast<physx_PxPvdTransport_Pod*>(return_val);
        return return_val_pod;
    }

    uint8_t PxPvd_getInstrumentationFlags_mut(physx_PxPvd_Pod* self__pod) {
        physx::PxPvd* self_ = reinterpret_cast<physx::PxPvd*>(self__pod);
        physx::PxPvdInstrumentationFlags return_val = self_->getInstrumentationFlags();
        uint8_t return_val_pod;
        memcpy(&return_val_pod, &return_val, sizeof(return_val_pod));
        return return_val_pod;
    }

    void PxPvd_release_mut(physx_PxPvd_Pod* self__pod) {
        physx::PxPvd* self_ = reinterpret_cast<physx::PxPvd*>(self__pod);
        self_->release();
    }

    physx_PxPvd_Pod* phys_PxCreatePvd(physx_PxFoundation_Pod* foundation_pod) {
        physx::PxFoundation& foundation = reinterpret_cast<physx::PxFoundation&>(*foundation_pod);
        physx::PxPvd* return_val = PxCreatePvd(foundation);
        auto return_val_pod = reinterpret_cast<physx_PxPvd_Pod*>(return_val);
        return return_val_pod;
    }

    bool PxPvdTransport_connect_mut(physx_PxPvdTransport_Pod* self__pod) {
        physx::PxPvdTransport* self_ = reinterpret_cast<physx::PxPvdTransport*>(self__pod);
        bool return_val = self_->connect();
        return return_val;
    }

    void PxPvdTransport_disconnect_mut(physx_PxPvdTransport_Pod* self__pod) {
        physx::PxPvdTransport* self_ = reinterpret_cast<physx::PxPvdTransport*>(self__pod);
        self_->disconnect();
    }

    bool PxPvdTransport_isConnected_mut(physx_PxPvdTransport_Pod* self__pod) {
        physx::PxPvdTransport* self_ = reinterpret_cast<physx::PxPvdTransport*>(self__pod);
        bool return_val = self_->isConnected();
        return return_val;
    }

    bool PxPvdTransport_write_mut(physx_PxPvdTransport_Pod* self__pod, uint8_t const* inBytes, uint32_t inLength) {
        physx::PxPvdTransport* self_ = reinterpret_cast<physx::PxPvdTransport*>(self__pod);
        bool return_val = self_->write(inBytes, inLength);
        return return_val;
    }

    physx_PxPvdTransport_Pod* PxPvdTransport_lock_mut(physx_PxPvdTransport_Pod* self__pod) {
        physx::PxPvdTransport* self_ = reinterpret_cast<physx::PxPvdTransport*>(self__pod);
        physx::PxPvdTransport& return_val = self_->lock();
        auto return_val_pod = reinterpret_cast<physx_PxPvdTransport_Pod*>(&return_val);
        return return_val_pod;
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
        uint64_t return_val = self_->getWrittenDataSize();
        return return_val;
    }

    void PxPvdTransport_release_mut(physx_PxPvdTransport_Pod* self__pod) {
        physx::PxPvdTransport* self_ = reinterpret_cast<physx::PxPvdTransport*>(self__pod);
        self_->release();
    }

    physx_PxPvdTransport_Pod* phys_PxDefaultPvdSocketTransportCreate(char const* host, int32_t port, uint32_t timeoutInMilliseconds) {
        physx::PxPvdTransport* return_val = PxDefaultPvdSocketTransportCreate(host, port, timeoutInMilliseconds);
        auto return_val_pod = reinterpret_cast<physx_PxPvdTransport_Pod*>(return_val);
        return return_val_pod;
    }

    physx_PxPvdTransport_Pod* phys_PxDefaultPvdFileTransportCreate(char const* name) {
        physx::PxPvdTransport* return_val = PxDefaultPvdFileTransportCreate(name);
        auto return_val_pod = reinterpret_cast<physx_PxPvdTransport_Pod*>(return_val);
        return return_val_pod;
    }

}
