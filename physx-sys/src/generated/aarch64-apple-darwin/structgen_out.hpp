struct physx_PxAllocatorCallback_Pod {
    void* vtable_;
};
struct physx_PxAssertHandler_Pod {
    void* vtable_;
};
struct physx_PxVec3_Pod {
    float x;
    float y;
    float z;
};
struct physx_PxQuat_Pod {
    float x;
    float y;
    float z;
    float w;
};
struct physx_PxMat33_Pod {
    physx_PxVec3_Pod column0;
    physx_PxVec3_Pod column1;
    physx_PxVec3_Pod column2;
};
struct physx_PxPlane_Pod {
    physx_PxVec3_Pod n;
    float d;
};
struct physx_PxTransform_Pod {
    physx_PxQuat_Pod q;
    physx_PxVec3_Pod p;
};
struct physx_PxVec4_Pod {
    float x;
    float y;
    float z;
    float w;
};
struct physx_PxMat44_Pod {
    physx_PxVec4_Pod column0;
    physx_PxVec4_Pod column1;
    physx_PxVec4_Pod column2;
    physx_PxVec4_Pod column3;
};
struct physx_PxBounds3_Pod {
    physx_PxVec3_Pod minimum;
    physx_PxVec3_Pod maximum;
};
struct physx_PxErrorCallback_Pod {
    void* vtable_;
};
struct physx_PxInputStream_Pod {
    void* vtable_;
};
struct physx_PxInputData_Pod {
    void* vtable_;
};
struct physx_PxOutputStream_Pod {
    void* vtable_;
};
struct physx_PxVec2_Pod {
    float x;
    float y;
};
struct physx_PxStridedData_Pod {
    uint32_t stride;
    char structgen_pad0[4];
    void* data;
};
struct physx_PxBoundedData_Pod {
    uint32_t stride;
    char structgen_pad0[4];
    void* data;
    uint32_t count;
    char structgen_pad1[4];
};
struct physx_PxDebugPoint_Pod {
    physx_PxVec3_Pod pos;
    uint32_t color;
};
struct physx_PxDebugLine_Pod {
    physx_PxVec3_Pod pos0;
    uint32_t color0;
    physx_PxVec3_Pod pos1;
    uint32_t color1;
};
struct physx_PxDebugTriangle_Pod {
    physx_PxVec3_Pod pos0;
    uint32_t color0;
    physx_PxVec3_Pod pos1;
    uint32_t color1;
    physx_PxVec3_Pod pos2;
    uint32_t color2;
};
struct physx_PxDebugText_Pod {
    physx_PxVec3_Pod position;
    float size;
    uint32_t color;
    char structgen_pad0[4];
    char* string;
};
struct physx_PxRenderBuffer_Pod {
    void* vtable_;
};
struct physx_PxProcessPxBaseCallback_Pod {
    void* vtable_;
};
struct physx_PxBaseFlags_Pod {
    uint16_t mBits;
};
struct physx_PxBase_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
};
struct physx_PxSerializationContext_Pod {
    void* vtable_;
};
struct physx_PxCollection_Pod {
    void* vtable_;
};
struct physx_PxDeserializationContext_Pod {
    char structgen_pad0[8];
    unsigned char* mExtraDataAddress;
};
struct physx_PxSerializationRegistry_Pod {
    void* vtable_;
};
struct physx_PxSerializer_Pod {
    void* vtable_;
};
struct physx_PxRepXSerializer_Pod {
    void* vtable_;
};
struct physx_PxTolerancesScale_Pod {
    float length;
    float speed;
};
struct physx_PxStringTable_Pod {
    void* vtable_;
};
struct physx_PxFoundation_Pod {
    void* vtable_;
};
struct physx_PxProfilerCallback_Pod {
    void* vtable_;
};
struct physx_PxPhysicsInsertionCallback_Pod {
    void* vtable_;
};
struct physx_PxTaskManager_Pod {
    void* vtable_;
};
struct physx_PxCpuDispatcher_Pod {
    void* vtable_;
};
struct physx_PxTask_Pod {
    char structgen_pad0[8];
    uint64_t mContextID;
    physx_PxTaskManager_Pod* mTm;
    uint32_t mTaskID;
    char structgen_pad1[4];
};
struct physx_PxBaseTask_Pod {
    char structgen_pad0[8];
    uint64_t mContextID;
    physx_PxTaskManager_Pod* mTm;
};
struct physx_PxLightCpuTask_Pod {
    char structgen_pad0[8];
    uint64_t mContextID;
    physx_PxTaskManager_Pod* mTm;
    physx_PxBaseTask_Pod* mCont;
    int32_t mRefCount;
    char structgen_pad1[4];
};
struct physx_PxGeometry_Pod {
    int mType;
};
struct physx_PxBoxGeometry_Pod {
    int mType;
    physx_PxVec3_Pod halfExtents;
};
struct physx_PxBVHStructure_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
};
struct physx_PxCapsuleGeometry_Pod {
    int mType;
    float radius;
    float halfHeight;
};
struct physx_PxConvexMesh_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
};
struct physx_PxHullPolygon_Pod {
    float mPlane[4];
    uint16_t mNbVerts;
    uint16_t mIndexBase;
};
struct physx_PxMeshScale_Pod {
    physx_PxVec3_Pod scale;
    physx_PxQuat_Pod rotation;
};
struct physx_PxConvexMeshGeometryFlags_Pod {
    unsigned char mBits;
};
struct PxPadding_3__Pod {
    unsigned char mPadding[3];
};
struct physx_PxConvexMeshGeometry_Pod {
    int mType;
    physx_PxMeshScale_Pod scale;
    physx_PxConvexMesh_Pod* convexMesh;
    physx_PxConvexMeshGeometryFlags_Pod meshFlags;
    PxPadding_3__Pod paddingFromFlags;
    char structgen_pad0[4];
};
struct physx_PxSphereGeometry_Pod {
    int mType;
    float radius;
};
struct physx_PxPlaneGeometry_Pod {
    int mType;
};
struct physx_PxMeshGeometryFlags_Pod {
    unsigned char mBits;
};
struct physx_PxTriangleMesh_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
};
struct physx_PxTriangleMeshGeometry_Pod {
    int mType;
    physx_PxMeshScale_Pod scale;
    physx_PxMeshGeometryFlags_Pod meshFlags;
    PxPadding_3__Pod paddingFromFlags;
    char structgen_pad0[4];
    physx_PxTriangleMesh_Pod* triangleMesh;
};
struct physx_PxHeightField_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
};
struct physx_PxHeightFieldGeometry_Pod {
    int mType;
    char structgen_pad0[4];
    physx_PxHeightField_Pod* heightField;
    float heightScale;
    float rowScale;
    float columnScale;
    physx_PxMeshGeometryFlags_Pod heightFieldFlags;
    PxPadding_3__Pod paddingFromFlags;
};
struct Anonymous59_Pod {
    unsigned char geometry[4];
    unsigned char box[16];
    unsigned char sphere[8];
    unsigned char capsule[12];
    unsigned char plane[4];
    unsigned char convex[48];
    unsigned char mesh[48];
    unsigned char heightfield[32];
};
struct physx_PxGeometryHolder_Pod {
    char structgen_pad0[48];
};
struct physx_PxRigidActor_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
    void* userData;
};
struct physx_PxShape_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
    void* userData;
};
struct physx_PxActorShape_Pod {
    physx_PxRigidActor_Pod* actor;
    physx_PxShape_Pod* shape;
};
struct physx_PxQueryHit_Pod {
    physx_PxRigidActor_Pod* actor;
    physx_PxShape_Pod* shape;
    uint32_t faceIndex;
    char structgen_pad0[4];
};
struct physx_PxHitFlags_Pod {
    uint16_t mBits;
};
struct physx_PxLocationHit_Pod {
    physx_PxRigidActor_Pod* actor;
    physx_PxShape_Pod* shape;
    uint32_t faceIndex;
    physx_PxHitFlags_Pod flags;
    char structgen_pad0[2];
    physx_PxVec3_Pod position;
    physx_PxVec3_Pod normal;
    float distance;
    char structgen_pad1[4];
};
struct physx_PxRaycastHit_Pod {
    physx_PxRigidActor_Pod* actor;
    physx_PxShape_Pod* shape;
    uint32_t faceIndex;
    physx_PxHitFlags_Pod flags;
    char structgen_pad0[2];
    physx_PxVec3_Pod position;
    physx_PxVec3_Pod normal;
    float distance;
    float u;
    float v;
    char structgen_pad1[4];
};
struct physx_PxSweepHit_Pod {
    physx_PxRigidActor_Pod* actor;
    physx_PxShape_Pod* shape;
    uint32_t faceIndex;
    physx_PxHitFlags_Pod flags;
    char structgen_pad0[2];
    physx_PxVec3_Pod position;
    physx_PxVec3_Pod normal;
    float distance;
    uint32_t padTo16Bytes;
};
struct physx_PxBitAndByte_Pod {
    unsigned char mData;
};
struct physx_PxHeightFieldSample_Pod {
    int16_t height;
    physx_PxBitAndByte_Pod materialIndex0;
    physx_PxBitAndByte_Pod materialIndex1;
};
struct physx_PxHeightFieldFlags_Pod {
    uint16_t mBits;
};
struct physx_PxHeightFieldDesc_Pod {
    uint32_t nbRows;
    uint32_t nbColumns;
    unsigned int format;
    char structgen_pad0[4];
    physx_PxStridedData_Pod samples;
    float convexEdgeThreshold;
    physx_PxHeightFieldFlags_Pod flags;
    char structgen_pad1[2];
};
struct physx_PxTriangle_Pod {
    physx_PxVec3_Pod verts[3];
};
struct physx_PxMeshFlags_Pod {
    uint16_t mBits;
};
struct physx_PxSimpleTriangleMesh_Pod {
    physx_PxBoundedData_Pod points;
    physx_PxBoundedData_Pod triangles;
    physx_PxMeshFlags_Pod flags;
    char structgen_pad0[6];
};
struct physx_PxTriangleMeshFlags_Pod {
    unsigned char mBits;
};
struct physx_PxActor_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
    void* userData;
};
struct physx_PxScene_Pod {
    char structgen_pad0[8];
    void* userData;
};
struct physx_PxActorFlags_Pod {
    unsigned char mBits;
};
struct physx_PxAggregate_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
};
struct physx_PxArticulationBase_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
    void* userData;
};
struct physx_PxArticulationLink_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
    void* userData;
};
struct physx_PxArticulationImpl_Pod;
struct physx_PxArticulationJointBase_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
};
struct physx_PxArticulation_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
    void* userData;
};
struct physx_PxArticulationDriveCache_Pod {
    char structgen_pad0[1];
};
struct physx_PxConstraintInvMassScale_Pod {
    float linear0;
    float angular0;
    float linear1;
    float angular1;
};
struct physx_PxConstraintVisualizer_Pod {
    void* vtable_;
};
struct physx_PxConstraintConnector_Pod {
    void* vtable_;
};
struct physx_pvdsdk_PvdDataStream_Pod;
struct physx_PxConstraint_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
};
struct physx_PxSolverBody_Pod {
    physx_PxVec3_Pod linearVelocity;
    uint16_t maxSolverNormalProgress;
    uint16_t maxSolverFrictionProgress;
    physx_PxVec3_Pod angularState;
    uint32_t solverProgress;
};
struct physx_PxSolverBodyData_Pod {
    physx_PxVec3_Pod linearVelocity;
    float invMass;
    physx_PxVec3_Pod angularVelocity;
    float reportThreshold;
    physx_PxMat33_Pod sqrtInvInertia;
    float penBiasClamp;
    uint32_t nodeIndex;
    float maxContactImpulse;
    physx_PxTransform_Pod body2World;
    uint16_t lockFlags;
    uint16_t pad;
};
struct physx_PxConstraintAllocator_Pod {
    void* vtable_;
};
struct physx_PxTGSSolverBodyVel_Pod {
    physx_PxVec3_Pod linearVelocity;
    uint16_t nbStaticInteractions;
    uint16_t maxDynamicPartition;
    physx_PxVec3_Pod angularVelocity;
    uint32_t partitionMask;
    physx_PxVec3_Pod deltaAngDt;
    float maxAngVel;
    physx_PxVec3_Pod deltaLinDt;
    uint16_t lockFlags;
    bool isKinematic;
    unsigned char pad;
};
struct physx_PxTGSSolverBodyData_Pod {
    physx_PxVec3_Pod originalLinearVelocity;
    float maxContactImpulse;
    physx_PxVec3_Pod originalAngularVelocity;
    float penBiasClamp;
    float invMass;
    uint32_t nodeIndex;
    float reportThreshold;
    uint32_t pad;
};
struct physx_PxSpatialForce_Pod {
    physx_PxVec3_Pod force;
    float pad0;
    physx_PxVec3_Pod torque;
    float pad1;
};
struct physx_PxArticulationRootLinkData_Pod {
    physx_PxTransform_Pod transform;
    physx_PxVec3_Pod worldLinVel;
    physx_PxVec3_Pod worldAngVel;
    physx_PxVec3_Pod worldLinAccel;
    physx_PxVec3_Pod worldAngAccel;
};
struct physx_PxArticulationCache_Pod {
    physx_PxSpatialForce_Pod* externalForces;
    float* denseJacobian;
    float* massMatrix;
    float* jointVelocity;
    float* jointAcceleration;
    float* jointPosition;
    float* jointForce;
    char structgen_pad0[16];
    physx_PxArticulationRootLinkData_Pod* rootLinkData;
    float* coefficientMatrix;
    float* lambda;
    void* scratchMemory;
    void* scratchAllocator;
    uint32_t version;
    char structgen_pad1[4];
};
struct physx_PxArticulationReducedCoordinate_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
    void* userData;
};
struct physx_PxArticulationFlags_Pod {
    unsigned char mBits;
};
struct physx_PxArticulationCacheFlags_Pod {
    unsigned char mBits;
};
struct physx_PxJoint_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
    void* userData;
};
struct physx_PxArticulationJointImpl_Pod;
struct physx_PxArticulationJoint_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
};
struct physx_PxArticulationJointReducedCoordinate_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
};
struct physx_PxFilterData_Pod {
    uint32_t word0;
    uint32_t word1;
    uint32_t word2;
    uint32_t word3;
};
struct physx_PxMaterial_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
    void* userData;
};
struct physx_PxShapeFlags_Pod {
    unsigned char mBits;
};
struct physx_PxRigidBody_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
    void* userData;
};
struct physx_PxRigidBodyFlags_Pod {
    unsigned char mBits;
};
struct physx_PxFilterFlags_Pod {
    uint16_t mBits;
};
struct physx_PxSimulationFilterCallback_Pod {
    void* vtable_;
};
struct physx_PxPairFlags_Pod {
    uint16_t mBits;
};
struct physx_PxQueryFlags_Pod {
    uint16_t mBits;
};
struct physx_PxQueryFilterData_Pod {
    physx_PxFilterData_Pod data;
    physx_PxQueryFlags_Pod flags;
    char structgen_pad0[2];
};
struct physx_PxQueryFilterCallback_Pod {
    void* vtable_;
};
struct physx_PxRaycastQueryResult_Pod;
struct physx_PxSweepQueryResult_Pod;
struct physx_PxOverlapQueryResult_Pod;
struct physx_PxOverlapHit_Pod {
    physx_PxRigidActor_Pod* actor;
    physx_PxShape_Pod* shape;
    uint32_t faceIndex;
    uint32_t padTo16Bytes;
};
struct physx_PxBatchQueryMemory_Pod {
    physx_PxRaycastQueryResult_Pod* userRaycastResultBuffer;
    physx_PxRaycastHit_Pod* userRaycastTouchBuffer;
    physx_PxSweepQueryResult_Pod* userSweepResultBuffer;
    physx_PxSweepHit_Pod* userSweepTouchBuffer;
    physx_PxOverlapQueryResult_Pod* userOverlapResultBuffer;
    physx_PxOverlapHit_Pod* userOverlapTouchBuffer;
    uint32_t raycastTouchBufferSize;
    uint32_t sweepTouchBufferSize;
    uint32_t overlapTouchBufferSize;
    uint32_t raycastResultBufferSize;
    uint32_t sweepResultBufferSize;
    uint32_t overlapResultBufferSize;
};
struct physx_PxBatchQueryDesc_Pod {
    void* filterShaderData;
    uint32_t filterShaderDataSize;
    char structgen_pad0[4];
    void* preFilterShader;
    void* postFilterShader;
    physx_PxBatchQueryMemory_Pod queryMemory;
};
struct physx_PxBatchQuery_Pod {
    void* vtable_;
};
struct physx_PxQueryCache_Pod {
    physx_PxShape_Pod* shape;
    physx_PxRigidActor_Pod* actor;
    uint32_t faceIndex;
    char structgen_pad0[4];
};
struct physx_PxConstraintFlags_Pod {
    uint16_t mBits;
};
struct physx_PxConstraintShaderTable_Pod {
    void* solverPrep;
    void* project;
    void* visualize;
    unsigned int flag;
    char structgen_pad0[4];
};
struct physx_PxMassModificationProps_Pod {
    float mInvMassScale0;
    float mInvInertiaScale0;
    float mInvMassScale1;
    float mInvInertiaScale1;
};
struct physx_PxContactPatch_Pod {
    physx_PxMassModificationProps_Pod mMassModification;
    physx_PxVec3_Pod normal;
    float restitution;
    float dynamicFriction;
    float staticFriction;
    unsigned char startContactIndex;
    unsigned char nbContacts;
    unsigned char materialFlags;
    unsigned char internalFlags;
    uint16_t materialIndex0;
    uint16_t materialIndex1;
};
struct physx_PxContact_Pod {
    physx_PxVec3_Pod contact;
    float separation;
};
struct physx_PxContactStreamIterator_Pod {
    physx_PxVec3_Pod zero;
    char structgen_pad0[4];
    physx_PxContactPatch_Pod* patch;
    physx_PxContact_Pod* contact;
    uint32_t* faceIndice;
    uint32_t totalPatches;
    uint32_t totalContacts;
    uint32_t nextContactIndex;
    uint32_t nextPatchIndex;
    uint32_t contactPatchHeaderSize;
    uint32_t contactPointSize;
    unsigned int mStreamFormat;
    uint32_t forceNoResponse;
    bool pointStepped;
    char structgen_pad1[3];
    uint32_t hasFaceIndices;
};
struct physx_PxModifiableContact_Pod {
    physx_PxVec3_Pod contact;
    float separation;
    physx_PxVec3_Pod targetVelocity;
    float maxImpulse;
    physx_PxVec3_Pod normal;
    float restitution;
    uint32_t materialFlags;
    uint16_t materialIndex0;
    uint16_t materialIndex1;
    float staticFriction;
    float dynamicFriction;
};
struct physx_PxContactSet_Pod {
    uint32_t mCount;
    char structgen_pad0[4];
    physx_PxModifiableContact_Pod* mContacts;
};
struct physx_PxContactModifyCallback_Pod {
    void* vtable_;
};
struct physx_PxContactModifyPair_Pod {
    physx_PxRigidActor_Pod* actor[2];
    physx_PxShape_Pod* shape[2];
    physx_PxTransform_Pod transform[2];
    physx_PxContactSet_Pod contacts;
};
struct physx_PxCCDContactModifyCallback_Pod {
    void* vtable_;
};
struct physx_PxDeletionListener_Pod {
    void* vtable_;
};
struct physx_PxDataAccessFlags_Pod {
    unsigned char mBits;
};
struct physx_PxLockedData_Pod {
    void* vtable_;
};
struct physx_PxMaterialFlags_Pod {
    uint16_t mBits;
};
struct physx_PxPhysics_Pod {
    void* vtable_;
};
struct physx_PxSimulationEventCallback_Pod {
    void* vtable_;
};
struct physx_PxBroadPhaseCallback_Pod {
    void* vtable_;
};
struct physx_PxSceneLimits_Pod {
    uint32_t maxNbActors;
    uint32_t maxNbBodies;
    uint32_t maxNbStaticShapes;
    uint32_t maxNbDynamicShapes;
    uint32_t maxNbAggregates;
    uint32_t maxNbConstraints;
    uint32_t maxNbRegions;
    uint32_t maxNbBroadPhaseOverlaps;
};
struct physx_PxSceneFlags_Pod {
    uint32_t mBits;
};
struct physx_PxCudaContextManager_Pod;
struct physx_PxgDynamicsMemoryConfig_Pod {
    uint32_t constraintBufferCapacity;
    uint32_t contactBufferCapacity;
    uint32_t tempBufferCapacity;
    uint32_t contactStreamSize;
    uint32_t patchStreamSize;
    uint32_t forceStreamCapacity;
    uint32_t heapCapacity;
    uint32_t foundLostPairsCapacity;
};
struct physx_PxSceneDesc_Pod {
    physx_PxVec3_Pod gravity;
    char structgen_pad0[4];
    physx_PxSimulationEventCallback_Pod* simulationEventCallback;
    physx_PxContactModifyCallback_Pod* contactModifyCallback;
    physx_PxCCDContactModifyCallback_Pod* ccdContactModifyCallback;
    void* filterShaderData;
    uint32_t filterShaderDataSize;
    char structgen_pad1[4];
    void* filterShader;
    physx_PxSimulationFilterCallback_Pod* filterCallback;
    unsigned int kineKineFilteringMode;
    unsigned int staticKineFilteringMode;
    unsigned int broadPhaseType;
    char structgen_pad2[4];
    physx_PxBroadPhaseCallback_Pod* broadPhaseCallback;
    physx_PxSceneLimits_Pod limits;
    unsigned int frictionType;
    unsigned int solverType;
    float bounceThresholdVelocity;
    float frictionOffsetThreshold;
    float ccdMaxSeparation;
    float solverOffsetSlop;
    physx_PxSceneFlags_Pod flags;
    char structgen_pad3[4];
    physx_PxCpuDispatcher_Pod* cpuDispatcher;
    physx_PxCudaContextManager_Pod* cudaContextManager;
    unsigned int staticStructure;
    unsigned int dynamicStructure;
    uint32_t dynamicTreeRebuildRateHint;
    unsigned int sceneQueryUpdateMode;
    void* userData;
    uint32_t solverBatchSize;
    uint32_t solverArticulationBatchSize;
    uint32_t nbContactDataBlocks;
    uint32_t maxNbContactDataBlocks;
    float maxBiasCoefficient;
    uint32_t contactReportStreamBufferSize;
    uint32_t ccdMaxPasses;
    float ccdThreshold;
    float wakeCounterResetValue;
    physx_PxBounds3_Pod sanityBounds;
    physx_PxgDynamicsMemoryConfig_Pod gpuDynamicsConfig;
    uint32_t gpuMaxNumPartitions;
    uint32_t gpuComputeVersion;
    char structgen_pad4[12];
};
struct physx_PxRigidStatic_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
    void* userData;
};
struct physx_PxRigidDynamic_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
    void* userData;
};
struct physx_PxPruningStructure_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
};
struct physx_PxDeletionEventFlags_Pod {
    unsigned char mBits;
};
struct physx_PxPvd_Pod {
    void* vtable_;
};
struct physx_PxRigidDynamicLockFlags_Pod {
    uint16_t mBits;
};
struct physx_PxSimulationStatistics_Pod {
    uint32_t nbActiveConstraints;
    uint32_t nbActiveDynamicBodies;
    uint32_t nbActiveKinematicBodies;
    uint32_t nbStaticBodies;
    uint32_t nbDynamicBodies;
    uint32_t nbKinematicBodies;
    uint32_t nbShapes[7];
    uint32_t nbAggregates;
    uint32_t nbArticulations;
    uint32_t nbAxisSolverConstraints;
    uint32_t compressedContactSize;
    uint32_t requiredContactConstraintMemory;
    uint32_t peakConstraintMemory;
    uint32_t nbDiscreteContactPairsTotal;
    uint32_t nbDiscreteContactPairsWithCacheHits;
    uint32_t nbDiscreteContactPairsWithContacts;
    uint32_t nbNewPairs;
    uint32_t nbLostPairs;
    uint32_t nbNewTouches;
    uint32_t nbLostTouches;
    uint32_t nbPartitions;
    uint32_t nbBroadPhaseAdds;
    uint32_t nbBroadPhaseRemoves;
    uint32_t nbDiscreteContactPairs[7][7];
    uint32_t nbCCDPairs[7][7];
    uint32_t nbModifiedContactPairs[7][7];
    uint32_t nbTriggerPairs[7][7];
};
struct physx_PxPvdSceneClient_Pod {
    void* vtable_;
};
struct physx_PxPvdSceneFlags_Pod {
    unsigned char mBits;
};
struct physx_pvdsdk_PvdDebugPoint_Pod;
struct physx_pvdsdk_PvdDebugLine_Pod;
struct physx_pvdsdk_PvdDebugTriangle_Pod;
struct physx_pvdsdk_PvdDebugText_Pod;
struct physx_pvdsdk_PvdClient_Pod;
struct physx_PxDominanceGroupPair_Pod {
    unsigned char dominance0;
    unsigned char dominance1;
};
struct physx_PxActorTypeFlags_Pod {
    uint16_t mBits;
};
struct physx_PxContactPairHeaderFlags_Pod {
    uint16_t mBits;
};
struct physx_PxContactPairFlags_Pod {
    uint16_t mBits;
};
struct physx_PxContactPair_Pod {
    physx_PxShape_Pod* shapes[2];
    unsigned char* contactPatches;
    unsigned char* contactPoints;
    float* contactImpulses;
    uint32_t requiredBufferSize;
    unsigned char contactCount;
    unsigned char patchCount;
    uint16_t contactStreamSize;
    physx_PxContactPairFlags_Pod flags;
    physx_PxPairFlags_Pod events;
    uint32_t internalData[2];
    char structgen_pad0[4];
};
struct physx_PxContactPairHeader_Pod {
    physx_PxRigidActor_Pod* actors[2];
    unsigned char* extraDataStream;
    uint16_t extraDataStreamSize;
    physx_PxContactPairHeaderFlags_Pod flags;
    char structgen_pad0[4];
    physx_PxContactPair_Pod* pairs;
    uint32_t nbPairs;
    char structgen_pad1[4];
};
struct physx_PxRaycastCallback_Pod {
    void* vtable_;
    physx_PxRaycastHit_Pod block;
    bool hasBlock;
    physx_PxRaycastHit_Pod* touches;
    uint32_t maxNbTouches;
    uint32_t nbTouches;
};
struct physx_PxSweepCallback_Pod {
    void* vtable_;
    physx_PxSweepHit_Pod block;
    bool hasBlock;
    physx_PxSweepHit_Pod* touches;
    uint32_t maxNbTouches;
    uint32_t nbTouches;
};
struct physx_PxOverlapCallback_Pod {
    void* vtable_;
    physx_PxOverlapHit_Pod block;
    bool hasBlock;
    physx_PxOverlapHit_Pod* touches;
    uint32_t maxNbTouches;
    uint32_t nbTouches;
};
struct physx_PxBroadPhaseCaps_Pod {
    uint32_t maxNbRegions;
    uint32_t maxNbObjects;
    bool needsPredefinedBounds;
    char structgen_pad0[3];
};
struct physx_PxBroadPhaseRegion_Pod {
    physx_PxBounds3_Pod bounds;
    void* userData;
};
struct physx_PxBroadPhaseRegionInfo_Pod {
    physx_PxBroadPhaseRegion_Pod region;
    uint32_t nbStaticObjects;
    uint32_t nbDynamicObjects;
    bool active;
    bool overlap;
    char structgen_pad0[6];
};
struct physx_PxSceneReadLock_Pod {
    char structgen_pad0[8];
};
struct physx_PxSceneWriteLock_Pod {
    char structgen_pad0[8];
};
struct physx_PxContactPairExtraDataItem_Pod {
    unsigned char type;
};
struct physx_PxContactPairVelocity_Pod {
    unsigned char type;
    char structgen_pad0[3];
    physx_PxVec3_Pod linearVelocity[2];
    physx_PxVec3_Pod angularVelocity[2];
};
struct physx_PxContactPairPose_Pod {
    unsigned char type;
    char structgen_pad0[3];
    physx_PxTransform_Pod globalPose[2];
};
struct physx_PxContactPairIndex_Pod {
    unsigned char type;
    char structgen_pad0[1];
    uint16_t index;
};
struct physx_PxContactPairExtraDataIterator_Pod {
    unsigned char* currPtr;
    unsigned char* endPtr;
    physx_PxContactPairVelocity_Pod* preSolverVelocity;
    physx_PxContactPairVelocity_Pod* postSolverVelocity;
    physx_PxContactPairPose_Pod* eventPose;
    uint32_t contactPairIndex;
    char structgen_pad0[4];
};
struct physx_PxContactPairPoint_Pod {
    physx_PxVec3_Pod position;
    float separation;
    physx_PxVec3_Pod normal;
    uint32_t internalFaceIndex0;
    physx_PxVec3_Pod impulse;
    uint32_t internalFaceIndex1;
};
struct physx_PxTriggerPairFlags_Pod {
    unsigned char mBits;
};
struct physx_PxTriggerPair_Pod {
    physx_PxShape_Pod* triggerShape;
    physx_PxRigidActor_Pod* triggerActor;
    physx_PxShape_Pod* otherShape;
    physx_PxRigidActor_Pod* otherActor;
    unsigned int status;
    physx_PxTriggerPairFlags_Pod flags;
    char structgen_pad0[3];
};
struct physx_PxConstraintInfo_Pod {
    physx_PxConstraint_Pod* constraint;
    void* externalReference;
    uint32_t type;
    char structgen_pad0[4];
};
struct physx_PxExtendedVec3_Pod {
    double x;
    double y;
    double z;
};
struct physx_PxObstacle_Pod {
    int mType;
    char structgen_pad0[4];
    void* mUserData;
    physx_PxExtendedVec3_Pod mPos;
    physx_PxQuat_Pod mRot;
};
struct physx_PxBoxObstacle_Pod {
    int mType;
    char structgen_pad0[4];
    void* mUserData;
    physx_PxExtendedVec3_Pod mPos;
    physx_PxQuat_Pod mRot;
    physx_PxVec3_Pod mHalfExtents;
    char structgen_pad1[4];
};
struct physx_PxCapsuleObstacle_Pod {
    int mType;
    char structgen_pad0[4];
    void* mUserData;
    physx_PxExtendedVec3_Pod mPos;
    physx_PxQuat_Pod mRot;
    float mHalfHeight;
    float mRadius;
};
struct physx_PxObstacleContext_Pod {
    void* vtable_;
};
struct physx_PxControllerManager_Pod {
    void* vtable_;
};
struct physx_PxUserControllerHitReport_Pod {
    void* vtable_;
};
struct physx_PxController_Pod {
    void* vtable_;
};
struct physx_PxControllerShapeHit_Pod {
    physx_PxController_Pod* controller;
    physx_PxExtendedVec3_Pod worldPos;
    physx_PxVec3_Pod worldNormal;
    physx_PxVec3_Pod dir;
    float length;
    char structgen_pad0[4];
    physx_PxShape_Pod* shape;
    physx_PxRigidActor_Pod* actor;
    uint32_t triangleIndex;
    char structgen_pad1[4];
};
struct physx_PxControllersHit_Pod {
    physx_PxController_Pod* controller;
    physx_PxExtendedVec3_Pod worldPos;
    physx_PxVec3_Pod worldNormal;
    physx_PxVec3_Pod dir;
    float length;
    char structgen_pad0[4];
    physx_PxController_Pod* other;
};
struct physx_PxControllerObstacleHit_Pod {
    physx_PxController_Pod* controller;
    physx_PxExtendedVec3_Pod worldPos;
    physx_PxVec3_Pod worldNormal;
    physx_PxVec3_Pod dir;
    float length;
    char structgen_pad0[4];
    void* userData;
};
struct physx_PxControllerFilterCallback_Pod {
    void* vtable_;
};
struct physx_PxControllerFilters_Pod {
    physx_PxFilterData_Pod* mFilterData;
    physx_PxQueryFilterCallback_Pod* mFilterCallback;
    physx_PxQueryFlags_Pod mFilterFlags;
    char structgen_pad0[6];
    physx_PxControllerFilterCallback_Pod* mCCTFilterCallback;
};
struct physx_PxControllerBehaviorCallback_Pod {
    void* vtable_;
};
struct physx_PxControllerDesc_Pod {
    char structgen_pad0[8];
    physx_PxExtendedVec3_Pod position;
    physx_PxVec3_Pod upDirection;
    float slopeLimit;
    float invisibleWallHeight;
    float maxJumpHeight;
    float contactOffset;
    float stepOffset;
    float density;
    float scaleCoeff;
    float volumeGrowth;
    char structgen_pad1[4];
    physx_PxUserControllerHitReport_Pod* reportCallback;
    physx_PxControllerBehaviorCallback_Pod* behaviorCallback;
    unsigned int nonWalkableMode;
    char structgen_pad2[4];
    physx_PxMaterial_Pod* material;
    bool registerDeletionListener;
    char structgen_pad3[7];
    void* userData;
    unsigned int mType;
    char structgen_pad4[4];
};
struct physx_PxControllerCollisionFlags_Pod {
    unsigned char mBits;
};
struct physx_PxControllerState_Pod {
    physx_PxVec3_Pod deltaXP;
    char structgen_pad0[4];
    physx_PxShape_Pod* touchedShape;
    physx_PxRigidActor_Pod* touchedActor;
    uint32_t touchedObstacleHandle;
    uint32_t collisionFlags;
    bool standOnAnotherCCT;
    bool standOnObstacle;
    bool isMovingUp;
    char structgen_pad1[5];
};
struct physx_PxControllerStats_Pod {
    uint16_t nbIterations;
    uint16_t nbFullUpdates;
    uint16_t nbPartialUpdates;
    uint16_t nbTessellation;
};
struct physx_PxBoxControllerDesc_Pod {
    char structgen_pad0[8];
    physx_PxExtendedVec3_Pod position;
    physx_PxVec3_Pod upDirection;
    float slopeLimit;
    float invisibleWallHeight;
    float maxJumpHeight;
    float contactOffset;
    float stepOffset;
    float density;
    float scaleCoeff;
    float volumeGrowth;
    char structgen_pad1[4];
    physx_PxUserControllerHitReport_Pod* reportCallback;
    physx_PxControllerBehaviorCallback_Pod* behaviorCallback;
    unsigned int nonWalkableMode;
    char structgen_pad2[4];
    physx_PxMaterial_Pod* material;
    bool registerDeletionListener;
    char structgen_pad3[7];
    void* userData;
    unsigned int mType;
    float halfHeight;
    float halfSideExtent;
    float halfForwardExtent;
};
struct physx_PxBoxController_Pod {
    void* vtable_;
};
struct physx_PxCapsuleControllerDesc_Pod {
    char structgen_pad0[8];
    physx_PxExtendedVec3_Pod position;
    physx_PxVec3_Pod upDirection;
    float slopeLimit;
    float invisibleWallHeight;
    float maxJumpHeight;
    float contactOffset;
    float stepOffset;
    float density;
    float scaleCoeff;
    float volumeGrowth;
    char structgen_pad1[4];
    physx_PxUserControllerHitReport_Pod* reportCallback;
    physx_PxControllerBehaviorCallback_Pod* behaviorCallback;
    unsigned int nonWalkableMode;
    char structgen_pad2[4];
    physx_PxMaterial_Pod* material;
    bool registerDeletionListener;
    char structgen_pad3[7];
    void* userData;
    unsigned int mType;
    float radius;
    float height;
    unsigned int climbingMode;
};
struct physx_PxCapsuleController_Pod {
    void* vtable_;
};
struct physx_PxControllerBehaviorFlags_Pod {
    unsigned char mBits;
};
struct physx_PxControllerDebugRenderFlags_Pod {
    uint32_t mBits;
};
struct physx_PxConvexFlags_Pod {
    uint16_t mBits;
};
struct physx_PxConvexMeshDesc_Pod {
    physx_PxBoundedData_Pod points;
    physx_PxBoundedData_Pod polygons;
    physx_PxBoundedData_Pod indices;
    physx_PxConvexFlags_Pod flags;
    uint16_t vertexLimit;
    uint16_t quantizedCount;
    char structgen_pad0[2];
};
struct PxTypedStridedData_physx_PxMaterialTableIndex__Pod {
    uint32_t stride;
    uint16_t* data;
};
struct physx_PxTriangleMeshDesc_Pod {
    physx_PxBoundedData_Pod points;
    physx_PxBoundedData_Pod triangles;
    physx_PxMeshFlags_Pod flags;
    char structgen_pad0[6];
    PxTypedStridedData_physx_PxMaterialTableIndex__Pod materialIndices;
};
struct physx_PxBVH33MidphaseDesc_Pod {
    float meshSizePerformanceTradeOff;
    unsigned int meshCookingHint;
};
struct physx_PxBVH34MidphaseDesc_Pod {
    uint32_t numPrimsPerLeaf;
};
struct Anonymous216_Pod {
    physx_PxBVH33MidphaseDesc_Pod mBVH33Desc;
    physx_PxBVH34MidphaseDesc_Pod mBVH34Desc;
};
struct physx_PxMidphaseDesc_Pod {
    char structgen_pad0[8];
    unsigned int mType;
};
struct physx_PxBVHStructureDesc_Pod {
    physx_PxBoundedData_Pod bounds;
};
struct physx_PxMeshPreprocessingFlags_Pod {
    uint32_t mBits;
};
struct physx_PxCookingParams_Pod {
    float areaTestEpsilon;
    float planeTolerance;
    unsigned int convexMeshCookingType;
    bool suppressTriangleMeshRemapTable;
    bool buildTriangleAdjacencies;
    bool buildGPUData;
    char structgen_pad0[1];
    physx_PxTolerancesScale_Pod scale;
    physx_PxMeshPreprocessingFlags_Pod meshPreprocessParams;
    float meshWeldTolerance;
    physx_PxMidphaseDesc_Pod midphaseDesc;
    uint32_t gaussMapLimit;
};
struct physx_PxCooking_Pod {
    void* vtable_;
};
struct physx_PxDefaultMemoryOutputStream_Pod {
    char structgen_pad0[32];
};
struct physx_PxDefaultMemoryInputData_Pod {
    char structgen_pad0[32];
};
struct physx_PxDefaultFileOutputStream_Pod {
    char structgen_pad0[16];
};
struct physx_PxDefaultFileInputData_Pod {
    char structgen_pad0[24];
};
struct physx_PxSpring_Pod {
    float stiffness;
    float damping;
};
struct physx_PxDistanceJoint_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
    void* userData;
};
struct physx_PxDistanceJointFlags_Pod {
    uint16_t mBits;
};
struct physx_PxDefaultAllocator_Pod {
    void* vtable_;
};
struct physx_PxContactJoint_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
    void* userData;
};
struct physx_PxJacobianRow_Pod {
    physx_PxVec3_Pod linear0;
    physx_PxVec3_Pod linear1;
    physx_PxVec3_Pod angular0;
    physx_PxVec3_Pod angular1;
};
struct physx_PxFixedJoint_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
    void* userData;
};
struct physx_PxJointLimitParameters_Pod {
    float restitution;
    float bounceThreshold;
    float stiffness;
    float damping;
    float contactDistance;
};
struct physx_PxJointLinearLimit_Pod {
    float restitution;
    float bounceThreshold;
    float stiffness;
    float damping;
    float contactDistance;
    float value;
};
struct physx_PxJointLinearLimitPair_Pod {
    float restitution;
    float bounceThreshold;
    float stiffness;
    float damping;
    float contactDistance;
    float upper;
    float lower;
};
struct physx_PxJointAngularLimitPair_Pod {
    float restitution;
    float bounceThreshold;
    float stiffness;
    float damping;
    float contactDistance;
    float upper;
    float lower;
};
struct physx_PxJointLimitCone_Pod {
    float restitution;
    float bounceThreshold;
    float stiffness;
    float damping;
    float contactDistance;
    float yAngle;
    float zAngle;
};
struct physx_PxJointLimitPyramid_Pod {
    float restitution;
    float bounceThreshold;
    float stiffness;
    float damping;
    float contactDistance;
    float yAngleMin;
    float yAngleMax;
    float zAngleMin;
    float zAngleMax;
};
struct physx_PxPrismaticJoint_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
    void* userData;
};
struct physx_PxPrismaticJointFlags_Pod {
    uint16_t mBits;
};
struct physx_PxRevoluteJoint_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
    void* userData;
};
struct physx_PxRevoluteJointFlags_Pod {
    uint16_t mBits;
};
struct physx_PxSphericalJoint_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
    void* userData;
};
struct physx_PxSphericalJointFlags_Pod {
    uint16_t mBits;
};
struct physx_PxD6Joint_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
    void* userData;
};
struct physx_PxD6JointDriveFlags_Pod {
    uint32_t mBits;
};
struct physx_PxD6JointDrive_Pod {
    float stiffness;
    float damping;
    float forceLimit;
    physx_PxD6JointDriveFlags_Pod flags;
};
struct physx_PxGroupsMask_Pod {
    uint16_t bits0;
    uint16_t bits1;
    uint16_t bits2;
    uint16_t bits3;
};
struct physx_PxDefaultErrorCallback_Pod {
    void* vtable_;
};
struct physx_PxMassProperties_Pod {
    physx_PxMat33_Pod inertiaTensor;
    physx_PxVec3_Pod centerOfMass;
    float mass;
};
struct physx_PxMeshOverlapUtil_Pod {
    char structgen_pad0[1040];
};
struct physx_PxSerialization_PxXmlMiscParameter_Pod {
    physx_PxVec3_Pod upVector;
    physx_PxTolerancesScale_Pod scale;
};
struct physx_PxBinaryConverter_Pod {
    void* vtable_;
};
struct physx_PxDefaultCpuDispatcher_Pod {
    void* vtable_;
};
struct physx_PxSceneQueryHit_Pod {
    physx_PxRigidActor_Pod* actor;
    physx_PxShape_Pod* shape;
    uint32_t faceIndex;
    char structgen_pad0[4];
};
struct physx_PxSceneQueryFilterData_Pod {
    physx_PxFilterData_Pod data;
    physx_PxQueryFlags_Pod flags;
    char structgen_pad0[2];
};
struct physx_PxSceneQueryFilterCallback_Pod {
    void* vtable_;
};
struct physx_PxSceneQueryCache_Pod {
    physx_PxShape_Pod* shape;
    physx_PxRigidActor_Pod* actor;
    uint32_t faceIndex;
    char structgen_pad0[4];
};
struct physx_PxSceneQueryFlags_Pod {
    uint16_t mBits;
};
struct physx_PxRepXObject_Pod {
    char* typeName;
    void* serializable;
    uint64_t id;
};
struct physx_PxRepXInstantiationArgs_Pod {
    char structgen_pad0[8];
    physx_PxCooking_Pod* cooker;
    physx_PxStringTable_Pod* stringTable;
};
struct physx_XmlWriter_Pod;
struct physx_MemoryBuffer_Pod;
struct physx_XmlReader_Pod;
struct physx_XmlMemoryAllocator_Pod;
struct physx_PxVehicleChassisData_Pod {
    physx_PxVec3_Pod mMOI;
    float mMass;
    physx_PxVec3_Pod mCMOffset;
    char structgen_pad0[4];
};
struct PxFixedSizeLookupTable_eMAX_NB_ENGINE_TORQUE_CURVE_ENTRIES__Pod {
    float mDataPairs[16];
    uint32_t mNbDataPairs;
    uint32_t mPad[3];
};
struct physx_PxVehicleEngineData_Pod {
    PxFixedSizeLookupTable_eMAX_NB_ENGINE_TORQUE_CURVE_ENTRIES__Pod mTorqueCurve;
    float mMOI;
    float mPeakTorque;
    float mMaxOmega;
    float mDampingRateFullThrottle;
    float mDampingRateZeroThrottleClutchEngaged;
    float mDampingRateZeroThrottleClutchDisengaged;
    char structgen_pad0[8];
};
struct physx_PxVehicleGearsData_Pod {
    float mRatios[32];
    float mFinalRatio;
    uint32_t mNbRatios;
    float mSwitchTime;
    char structgen_pad0[4];
};
struct physx_PxVehicleAutoBoxData_Pod {
    float mUpRatios[32];
    float mDownRatios[32];
};
struct physx_PxVehicleDifferential4WData_Pod {
    float mFrontRearSplit;
    float mFrontLeftRightSplit;
    float mRearLeftRightSplit;
    float mCentreBias;
    float mFrontBias;
    float mRearBias;
    unsigned int mType;
    char structgen_pad0[4];
};
struct physx_PxVehicleDifferentialNWData_Pod {
    char structgen_pad0[16];
};
struct physx_PxVehicleAckermannGeometryData_Pod {
    float mAccuracy;
    float mFrontWidth;
    float mRearWidth;
    float mAxleSeparation;
};
struct physx_PxVehicleClutchData_Pod {
    float mStrength;
    unsigned int mAccuracyMode;
    uint32_t mEstimateIterations;
    char structgen_pad0[4];
};
struct physx_PxVehicleTireLoadFilterData_Pod {
    float mMinNormalisedLoad;
    float mMinFilteredNormalisedLoad;
    float mMaxNormalisedLoad;
    float mMaxFilteredNormalisedLoad;
    char structgen_pad0[16];
};
struct physx_PxVehicleWheelData_Pod {
    float mRadius;
    float mWidth;
    float mMass;
    float mMOI;
    float mDampingRate;
    float mMaxBrakeTorque;
    float mMaxHandBrakeTorque;
    float mMaxSteer;
    float mToeAngle;
    char structgen_pad0[12];
};
struct physx_PxVehicleSuspensionData_Pod {
    float mSpringStrength;
    float mSpringDamperRate;
    float mMaxCompression;
    float mMaxDroop;
    float mSprungMass;
    float mCamberAtRest;
    float mCamberAtMaxCompression;
    float mCamberAtMaxDroop;
    char structgen_pad0[16];
};
struct physx_PxVehicleAntiRollBarData_Pod {
    uint32_t mWheel0;
    uint32_t mWheel1;
    float mStiffness;
    char structgen_pad0[4];
};
struct physx_PxVehicleTireData_Pod {
    float mLatStiffX;
    float mLatStiffY;
    float mLongitudinalStiffnessPerUnitGravity;
    float mCamberStiffnessPerUnitGravity;
    float mFrictionVsSlipGraph[3][2];
    uint32_t mType;
    char structgen_pad0[20];
};
struct physx_PxVehicleWheels4SimData_Pod;
struct physx_PxVehicleWheelsSimData_Pod {
    char structgen_pad0[96];
};
struct physx_PxVehicleWheels4DynData_Pod;
struct physx_PxVehicleTireForceCalculator_Pod;
struct physx_PxVehicleWheelsDynData_Pod {
    char structgen_pad0[48];
};
struct physx_PxVehicleWheels_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
    physx_PxVehicleWheelsSimData_Pod mWheelsSimData;
    physx_PxVehicleWheelsDynData_Pod mWheelsDynData;
    physx_PxRigidDynamic_Pod* mActor;
    char structgen_pad2[5];
    unsigned char mType;
    unsigned char mPad0[14];
    char structgen_pad3[4];
};
struct physx_PxVehicleDriveSimData_Pod {
    physx_PxVehicleEngineData_Pod mEngine;
    physx_PxVehicleGearsData_Pod mGears;
    physx_PxVehicleClutchData_Pod mClutch;
    physx_PxVehicleAutoBoxData_Pod mAutoBox;
};
struct physx_PxVehicleDriveDynData_Pod {
    float mControlAnalogVals[16];
    bool mUseAutoGears;
    bool mGearUpPressed;
    bool mGearDownPressed;
    char structgen_pad0[1];
    uint32_t mCurrentGear;
    uint32_t mTargetGear;
    float mEnginespeed;
    float mGearSwitchTime;
    float mAutoBoxSwitchTime;
    char structgen_pad1[8];
};
struct physx_PxVehicleDrive_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
    physx_PxVehicleWheelsSimData_Pod mWheelsSimData;
    physx_PxVehicleWheelsDynData_Pod mWheelsDynData;
    physx_PxRigidDynamic_Pod* mActor;
    char structgen_pad2[5];
    unsigned char mType;
    unsigned char mPad0[14];
    physx_PxVehicleDriveDynData_Pod mDriveDynData;
    char structgen_pad3[4];
};
struct physx_PxVehicleDriveSimData4W_Pod {
    physx_PxVehicleEngineData_Pod mEngine;
    physx_PxVehicleGearsData_Pod mGears;
    physx_PxVehicleClutchData_Pod mClutch;
    physx_PxVehicleAutoBoxData_Pod mAutoBox;
    char structgen_pad0[48];
};
struct physx_PxVehicleDrive4W_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
    physx_PxVehicleWheelsSimData_Pod mWheelsSimData;
    physx_PxVehicleWheelsDynData_Pod mWheelsDynData;
    physx_PxRigidDynamic_Pod* mActor;
    char structgen_pad2[5];
    unsigned char mType;
    unsigned char mPad0[14];
    physx_PxVehicleDriveDynData_Pod mDriveDynData;
    physx_PxVehicleDriveSimData4W_Pod mDriveSimData;
    char structgen_pad3[4];
};
struct physx_PxVehicleDriveTank_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
    physx_PxVehicleWheelsSimData_Pod mWheelsSimData;
    physx_PxVehicleWheelsDynData_Pod mWheelsDynData;
    physx_PxRigidDynamic_Pod* mActor;
    char structgen_pad2[5];
    unsigned char mType;
    unsigned char mPad0[14];
    physx_PxVehicleDriveDynData_Pod mDriveDynData;
    physx_PxVehicleDriveSimData_Pod mDriveSimData;
    char structgen_pad3[20];
};
struct physx_PxVehicleDrivableSurfaceType_Pod {
    uint32_t mType;
};
struct physx_PxVehicleDrivableSurfaceToTireFrictionPairs_Pod {
    char structgen_pad0[48];
};
struct physx_PxWheelQueryResult_Pod {
    physx_PxVec3_Pod suspLineStart;
    physx_PxVec3_Pod suspLineDir;
    float suspLineLength;
    bool isInAir;
    char structgen_pad0[3];
    physx_PxActor_Pod* tireContactActor;
    physx_PxShape_Pod* tireContactShape;
    physx_PxMaterial_Pod* tireSurfaceMaterial;
    uint32_t tireSurfaceType;
    physx_PxVec3_Pod tireContactPoint;
    physx_PxVec3_Pod tireContactNormal;
    float tireFriction;
    float suspJounce;
    float suspSpringForce;
    physx_PxVec3_Pod tireLongitudinalDir;
    physx_PxVec3_Pod tireLateralDir;
    float longitudinalSlip;
    float lateralSlip;
    float steerAngle;
    physx_PxTransform_Pod localPose;
};
struct physx_PxVehicleWheelConcurrentUpdateData_Pod {
    char structgen_pad0[64];
};
struct physx_PxVehicleConcurrentUpdateData_Pod {
    physx_PxVehicleWheelConcurrentUpdateData_Pod* concurrentWheelUpdates;
    uint32_t nbConcurrentWheelUpdates;
    char structgen_pad0[28];
};
struct physx_PxVehicleWheelQueryResult_Pod {
    physx_PxWheelQueryResult_Pod* wheelQueryResults;
    uint32_t nbWheelQueryResults;
    char structgen_pad0[4];
};
struct physx_PxVehicleGraph_Pod {
    char structgen_pad0[15840];
};
struct physx_PxVehicleTelemetryData_Pod {
    char structgen_pad0[48];
};
struct physx_PxVehicleDriveSimDataNW_Pod {
    physx_PxVehicleEngineData_Pod mEngine;
    physx_PxVehicleGearsData_Pod mGears;
    physx_PxVehicleClutchData_Pod mClutch;
    physx_PxVehicleAutoBoxData_Pod mAutoBox;
    char structgen_pad0[16];
};
struct physx_PxVehicleDriveNW_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
    physx_PxVehicleWheelsSimData_Pod mWheelsSimData;
    physx_PxVehicleWheelsDynData_Pod mWheelsDynData;
    physx_PxRigidDynamic_Pod* mActor;
    char structgen_pad2[5];
    unsigned char mType;
    unsigned char mPad0[14];
    physx_PxVehicleDriveDynData_Pod mDriveDynData;
    physx_PxVehicleDriveSimDataNW_Pod mDriveSimData;
    char structgen_pad3[4];
};
struct physx_PxVehicleDrive4WRawInputData_Pod {
    char structgen_pad0[40];
};
struct physx_PxVehicleKeySmoothingData_Pod {
    float mRiseRates[16];
    float mFallRates[16];
};
struct PxFixedSizeLookupTable_8__Pod {
    float mDataPairs[16];
    uint32_t mNbDataPairs;
    uint32_t mPad[3];
};
struct physx_PxVehiclePadSmoothingData_Pod {
    float mRiseRates[16];
    float mFallRates[16];
};
struct physx_PxVehicleDriveNWRawInputData_Pod {
    char structgen_pad0[40];
};
struct physx_PxVehicleDriveTankRawInputData_Pod {
    char structgen_pad0[32];
};
struct physx_PxVehicleCopyDynamicsMap_Pod {
    unsigned char sourceWheelIds[20];
    unsigned char targetWheelIds[20];
};
struct physx_PxVehicleGraphChannelDesc_Pod {
    float mMinY;
    float mMaxY;
    float mMidY;
    physx_PxVec3_Pod mColorLow;
    physx_PxVec3_Pod mColorHigh;
    char structgen_pad0[4];
    char* mTitle;
};
struct physx_PxVehicleGraphDesc_Pod {
    char structgen_pad0[32];
};
struct physx_PxVehicleNoDrive_Pod {
    char structgen_pad0[8];
    uint16_t mConcreteType;
    physx_PxBaseFlags_Pod mBaseFlags;
    char structgen_pad1[4];
    physx_PxVehicleWheelsSimData_Pod mWheelsSimData;
    physx_PxVehicleWheelsDynData_Pod mWheelsDynData;
    physx_PxRigidDynamic_Pod* mActor;
    char structgen_pad2[5];
    unsigned char mType;
    unsigned char mPad0[14];
    char structgen_pad3[36];
};
struct physx_PxProfileScoped_Pod {
    physx_PxProfilerCallback_Pod* mCallback;
    char* mEventName;
    void* mProfilerData;
    uint64_t mContextId;
    bool mDetached;
    char structgen_pad0[7];
};
struct physx_PxPvdTransport_Pod {
    void* vtable_;
};
struct physx_PxPvdInstrumentationFlags_Pod {
    unsigned char mBits;
};
