#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVec3 {
    pub x: f32,
    pub y: f32,
    pub z: f32,
}
#[test] fn check_size_PxVec3() { assert_eq!(std::mem::size_of::<PxVec3>(), 12); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxQuat {
    pub x: f32,
    pub y: f32,
    pub z: f32,
    pub w: f32,
}
#[test] fn check_size_PxQuat() { assert_eq!(std::mem::size_of::<PxQuat>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxMat33 {
    pub column0: PxVec3,
    pub column1: PxVec3,
    pub column2: PxVec3,
}
#[test] fn check_size_PxMat33() { assert_eq!(std::mem::size_of::<PxMat33>(), 36); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxPlane {
    pub n: PxVec3,
    pub d: f32,
}
#[test] fn check_size_PxPlane() { assert_eq!(std::mem::size_of::<PxPlane>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxTransform {
    pub q: PxQuat,
    pub p: PxVec3,
}
#[test] fn check_size_PxTransform() { assert_eq!(std::mem::size_of::<PxTransform>(), 28); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVec4 {
    pub x: f32,
    pub y: f32,
    pub z: f32,
    pub w: f32,
}
#[test] fn check_size_PxVec4() { assert_eq!(std::mem::size_of::<PxVec4>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxMat44 {
    pub column0: PxVec4,
    pub column1: PxVec4,
    pub column2: PxVec4,
    pub column3: PxVec4,
}
#[test] fn check_size_PxMat44() { assert_eq!(std::mem::size_of::<PxMat44>(), 64); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxBounds3 {
    pub minimum: PxVec3,
    pub maximum: PxVec3,
}
#[test] fn check_size_PxBounds3() { assert_eq!(std::mem::size_of::<PxBounds3>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVec2 {
    pub x: f32,
    pub y: f32,
}
#[test] fn check_size_PxVec2() { assert_eq!(std::mem::size_of::<PxVec2>(), 8); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxStridedData {
    pub stride: u32,
    pub structgen_pad0: [u8; 4],
    pub data: *const std::ffi::c_void,
}
#[test] fn check_size_PxStridedData() { assert_eq!(std::mem::size_of::<PxStridedData>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxBoundedData {
    pub stride: u32,
    pub structgen_pad0: [u8; 4],
    pub data: *const std::ffi::c_void,
    pub count: u32,
    pub structgen_pad1: [u8; 4],
}
#[test] fn check_size_PxBoundedData() { assert_eq!(std::mem::size_of::<PxBoundedData>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxDebugPoint {
    pub pos: PxVec3,
    pub color: u32,
}
#[test] fn check_size_PxDebugPoint() { assert_eq!(std::mem::size_of::<PxDebugPoint>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxDebugLine {
    pub pos0: PxVec3,
    pub color0: u32,
    pub pos1: PxVec3,
    pub color1: u32,
}
#[test] fn check_size_PxDebugLine() { assert_eq!(std::mem::size_of::<PxDebugLine>(), 32); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxDebugTriangle {
    pub pos0: PxVec3,
    pub color0: u32,
    pub pos1: PxVec3,
    pub color1: u32,
    pub pos2: PxVec3,
    pub color2: u32,
}
#[test] fn check_size_PxDebugTriangle() { assert_eq!(std::mem::size_of::<PxDebugTriangle>(), 48); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxDebugText {
    pub position: PxVec3,
    pub size: f32,
    pub color: u32,
    pub structgen_pad0: [u8; 4],
    pub string: *const i8,
}
#[test] fn check_size_PxDebugText() { assert_eq!(std::mem::size_of::<PxDebugText>(), 32); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxBase {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
}
#[test] fn check_size_PxBase() { assert_eq!(std::mem::size_of::<PxBase>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxDeserializationContext {
    pub structgen_pad0: [u8; 8],
    pub mExtraDataAddress: *mut u8,
}
#[test] fn check_size_PxDeserializationContext() { assert_eq!(std::mem::size_of::<PxDeserializationContext>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxTolerancesScale {
    pub length: f32,
    pub speed: f32,
}
#[test] fn check_size_PxTolerancesScale() { assert_eq!(std::mem::size_of::<PxTolerancesScale>(), 8); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxTask {
    pub structgen_pad0: [u8; 8],
    pub mContextID: usize,
    pub mTm: *mut PxTaskManager,
    pub mTaskID: u32,
    pub structgen_pad1: [u8; 4],
}
#[test] fn check_size_PxTask() { assert_eq!(std::mem::size_of::<PxTask>(), 32); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxBaseTask {
    pub structgen_pad0: [u8; 8],
    pub mContextID: usize,
    pub mTm: *mut PxTaskManager,
}
#[test] fn check_size_PxBaseTask() { assert_eq!(std::mem::size_of::<PxBaseTask>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxLightCpuTask {
    pub structgen_pad0: [u8; 8],
    pub mContextID: usize,
    pub mTm: *mut PxTaskManager,
    pub mCont: *mut PxBaseTask,
    pub mRefCount: i32,
    pub structgen_pad1: [u8; 4],
}
#[test] fn check_size_PxLightCpuTask() { assert_eq!(std::mem::size_of::<PxLightCpuTask>(), 40); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxGeometry {
    pub mType: i32,
}
#[test] fn check_size_PxGeometry() { assert_eq!(std::mem::size_of::<PxGeometry>(), 4); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxBoxGeometry {
    pub mType: i32,
    pub halfExtents: PxVec3,
}
#[test] fn check_size_PxBoxGeometry() { assert_eq!(std::mem::size_of::<PxBoxGeometry>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxBVHStructure {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
}
#[test] fn check_size_PxBVHStructure() { assert_eq!(std::mem::size_of::<PxBVHStructure>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxCapsuleGeometry {
    pub mType: i32,
    pub radius: f32,
    pub halfHeight: f32,
}
#[test] fn check_size_PxCapsuleGeometry() { assert_eq!(std::mem::size_of::<PxCapsuleGeometry>(), 12); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxConvexMesh {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
}
#[test] fn check_size_PxConvexMesh() { assert_eq!(std::mem::size_of::<PxConvexMesh>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxHullPolygon {
    pub mPlane: [f32; 4],
    pub mNbVerts: u16,
    pub mIndexBase: u16,
}
#[test] fn check_size_PxHullPolygon() { assert_eq!(std::mem::size_of::<PxHullPolygon>(), 20); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxMeshScale {
    pub scale: PxVec3,
    pub rotation: PxQuat,
}
#[test] fn check_size_PxMeshScale() { assert_eq!(std::mem::size_of::<PxMeshScale>(), 28); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxConvexMeshGeometry {
    pub mType: i32,
    pub scale: PxMeshScale,
    pub convexMesh: *mut PxConvexMesh,
    pub meshFlags: PxConvexMeshGeometryFlags,
    pub paddingFromFlags: PxPadding_3_,
    pub structgen_pad0: [u8; 4],
}
#[test] fn check_size_PxConvexMeshGeometry() { assert_eq!(std::mem::size_of::<PxConvexMeshGeometry>(), 48); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSphereGeometry {
    pub mType: i32,
    pub radius: f32,
}
#[test] fn check_size_PxSphereGeometry() { assert_eq!(std::mem::size_of::<PxSphereGeometry>(), 8); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxPlaneGeometry {
    pub mType: i32,
}
#[test] fn check_size_PxPlaneGeometry() { assert_eq!(std::mem::size_of::<PxPlaneGeometry>(), 4); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxTriangleMesh {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
}
#[test] fn check_size_PxTriangleMesh() { assert_eq!(std::mem::size_of::<PxTriangleMesh>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxTriangleMeshGeometry {
    pub mType: i32,
    pub scale: PxMeshScale,
    pub meshFlags: PxMeshGeometryFlags,
    pub paddingFromFlags: PxPadding_3_,
    pub structgen_pad0: [u8; 4],
    pub triangleMesh: *mut PxTriangleMesh,
}
#[test] fn check_size_PxTriangleMeshGeometry() { assert_eq!(std::mem::size_of::<PxTriangleMeshGeometry>(), 48); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxHeightField {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
}
#[test] fn check_size_PxHeightField() { assert_eq!(std::mem::size_of::<PxHeightField>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxHeightFieldGeometry {
    pub mType: i32,
    pub structgen_pad0: [u8; 4],
    pub heightField: *mut PxHeightField,
    pub heightScale: f32,
    pub rowScale: f32,
    pub columnScale: f32,
    pub heightFieldFlags: PxMeshGeometryFlags,
    pub paddingFromFlags: PxPadding_3_,
}
#[test] fn check_size_PxHeightFieldGeometry() { assert_eq!(std::mem::size_of::<PxHeightFieldGeometry>(), 32); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxGeometryHolder {
    pub structgen_pad0: [u8; 48],
}
#[test] fn check_size_PxGeometryHolder() { assert_eq!(std::mem::size_of::<PxGeometryHolder>(), 48); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxRigidActor {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
    pub userData: *mut std::ffi::c_void,
}
#[test] fn check_size_PxRigidActor() { assert_eq!(std::mem::size_of::<PxRigidActor>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxShape {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
    pub userData: *mut std::ffi::c_void,
}
#[test] fn check_size_PxShape() { assert_eq!(std::mem::size_of::<PxShape>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxActorShape {
    pub actor: *mut PxRigidActor,
    pub shape: *mut PxShape,
}
#[test] fn check_size_PxActorShape() { assert_eq!(std::mem::size_of::<PxActorShape>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxQueryHit {
    pub actor: *mut PxRigidActor,
    pub shape: *mut PxShape,
    pub faceIndex: u32,
    pub structgen_pad0: [u8; 4],
}
#[test] fn check_size_PxQueryHit() { assert_eq!(std::mem::size_of::<PxQueryHit>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxLocationHit {
    pub actor: *mut PxRigidActor,
    pub shape: *mut PxShape,
    pub faceIndex: u32,
    pub flags: PxHitFlags,
    pub structgen_pad0: [u8; 2],
    pub position: PxVec3,
    pub normal: PxVec3,
    pub distance: f32,
    pub structgen_pad1: [u8; 4],
}
#[test] fn check_size_PxLocationHit() { assert_eq!(std::mem::size_of::<PxLocationHit>(), 56); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxRaycastHit {
    pub actor: *mut PxRigidActor,
    pub shape: *mut PxShape,
    pub faceIndex: u32,
    pub flags: PxHitFlags,
    pub structgen_pad0: [u8; 2],
    pub position: PxVec3,
    pub normal: PxVec3,
    pub distance: f32,
    pub u: f32,
    pub v: f32,
    pub structgen_pad1: [u8; 4],
}
#[test] fn check_size_PxRaycastHit() { assert_eq!(std::mem::size_of::<PxRaycastHit>(), 64); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSweepHit {
    pub actor: *mut PxRigidActor,
    pub shape: *mut PxShape,
    pub faceIndex: u32,
    pub flags: PxHitFlags,
    pub structgen_pad0: [u8; 2],
    pub position: PxVec3,
    pub normal: PxVec3,
    pub distance: f32,
    pub padTo16Bytes: u32,
}
#[test] fn check_size_PxSweepHit() { assert_eq!(std::mem::size_of::<PxSweepHit>(), 56); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxHeightFieldSample {
    pub height: i16,
    pub materialIndex0: PxBitAndByte,
    pub materialIndex1: PxBitAndByte,
}
#[test] fn check_size_PxHeightFieldSample() { assert_eq!(std::mem::size_of::<PxHeightFieldSample>(), 4); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxHeightFieldDesc {
    pub nbRows: u32,
    pub nbColumns: u32,
    pub format: u32,
    pub structgen_pad0: [u8; 4],
    pub samples: PxStridedData,
    pub convexEdgeThreshold: f32,
    pub flags: PxHeightFieldFlags,
    pub structgen_pad1: [u8; 2],
}
#[test] fn check_size_PxHeightFieldDesc() { assert_eq!(std::mem::size_of::<PxHeightFieldDesc>(), 40); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxTriangle {
    pub verts: [PxVec3; 3],
}
#[test] fn check_size_PxTriangle() { assert_eq!(std::mem::size_of::<PxTriangle>(), 36); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSimpleTriangleMesh {
    pub points: PxBoundedData,
    pub triangles: PxBoundedData,
    pub flags: PxMeshFlags,
    pub structgen_pad0: [u8; 6],
}
#[test] fn check_size_PxSimpleTriangleMesh() { assert_eq!(std::mem::size_of::<PxSimpleTriangleMesh>(), 56); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxActor {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
    pub userData: *mut std::ffi::c_void,
}
#[test] fn check_size_PxActor() { assert_eq!(std::mem::size_of::<PxActor>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxScene {
    pub structgen_pad0: [u8; 8],
    pub userData: *mut std::ffi::c_void,
}
#[test] fn check_size_PxScene() { assert_eq!(std::mem::size_of::<PxScene>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxAggregate {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
}
#[test] fn check_size_PxAggregate() { assert_eq!(std::mem::size_of::<PxAggregate>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxArticulationBase {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
    pub userData: *mut std::ffi::c_void,
}
#[test] fn check_size_PxArticulationBase() { assert_eq!(std::mem::size_of::<PxArticulationBase>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxArticulationLink {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
    pub userData: *mut std::ffi::c_void,
}
#[test] fn check_size_PxArticulationLink() { assert_eq!(std::mem::size_of::<PxArticulationLink>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxArticulationJointBase {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
}
#[test] fn check_size_PxArticulationJointBase() { assert_eq!(std::mem::size_of::<PxArticulationJointBase>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxArticulation {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
    pub userData: *mut std::ffi::c_void,
}
#[test] fn check_size_PxArticulation() { assert_eq!(std::mem::size_of::<PxArticulation>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxArticulationDriveCache {
    pub structgen_pad0: [u8; 1],
}
#[test] fn check_size_PxArticulationDriveCache() { assert_eq!(std::mem::size_of::<PxArticulationDriveCache>(), 1); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxConstraintInvMassScale {
    pub linear0: f32,
    pub angular0: f32,
    pub linear1: f32,
    pub angular1: f32,
}
#[test] fn check_size_PxConstraintInvMassScale() { assert_eq!(std::mem::size_of::<PxConstraintInvMassScale>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxConstraint {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
}
#[test] fn check_size_PxConstraint() { assert_eq!(std::mem::size_of::<PxConstraint>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSolverBody {
    pub linearVelocity: PxVec3,
    pub maxSolverNormalProgress: u16,
    pub maxSolverFrictionProgress: u16,
    pub angularState: PxVec3,
    pub solverProgress: u32,
}
#[test] fn check_size_PxSolverBody() { assert_eq!(std::mem::size_of::<PxSolverBody>(), 32); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSolverBodyData {
    pub linearVelocity: PxVec3,
    pub invMass: f32,
    pub angularVelocity: PxVec3,
    pub reportThreshold: f32,
    pub sqrtInvInertia: PxMat33,
    pub penBiasClamp: f32,
    pub nodeIndex: u32,
    pub maxContactImpulse: f32,
    pub body2World: PxTransform,
    pub lockFlags: u16,
    pub pad: u16,
}
#[test] fn check_size_PxSolverBodyData() { assert_eq!(std::mem::size_of::<PxSolverBodyData>(), 112); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxTGSSolverBodyVel {
    pub linearVelocity: PxVec3,
    pub nbStaticInteractions: u16,
    pub maxDynamicPartition: u16,
    pub angularVelocity: PxVec3,
    pub partitionMask: u32,
    pub deltaAngDt: PxVec3,
    pub maxAngVel: f32,
    pub deltaLinDt: PxVec3,
    pub lockFlags: u16,
    pub isKinematic: bool,
    pub pad: u8,
}
#[test] fn check_size_PxTGSSolverBodyVel() { assert_eq!(std::mem::size_of::<PxTGSSolverBodyVel>(), 64); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxTGSSolverBodyData {
    pub originalLinearVelocity: PxVec3,
    pub maxContactImpulse: f32,
    pub originalAngularVelocity: PxVec3,
    pub penBiasClamp: f32,
    pub invMass: f32,
    pub nodeIndex: u32,
    pub reportThreshold: f32,
    pub pad: u32,
}
#[test] fn check_size_PxTGSSolverBodyData() { assert_eq!(std::mem::size_of::<PxTGSSolverBodyData>(), 48); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSpatialForce {
    pub force: PxVec3,
    pub pad0: f32,
    pub torque: PxVec3,
    pub pad1: f32,
}
#[test] fn check_size_PxSpatialForce() { assert_eq!(std::mem::size_of::<PxSpatialForce>(), 32); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSpatialVelocity {
    pub linear: PxVec3,
    pub pad0: f32,
    pub angular: PxVec3,
    pub pad1: f32,
}
#[test] fn check_size_PxSpatialVelocity() { assert_eq!(std::mem::size_of::<PxSpatialVelocity>(), 32); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxArticulationRootLinkData {
    pub transform: PxTransform,
    pub worldLinVel: PxVec3,
    pub worldAngVel: PxVec3,
    pub worldLinAccel: PxVec3,
    pub worldAngAccel: PxVec3,
}
#[test] fn check_size_PxArticulationRootLinkData() { assert_eq!(std::mem::size_of::<PxArticulationRootLinkData>(), 76); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxArticulationCache {
    pub externalForces: *mut PxSpatialForce,
    pub denseJacobian: *mut f32,
    pub massMatrix: *mut f32,
    pub jointVelocity: *mut f32,
    pub jointAcceleration: *mut f32,
    pub jointPosition: *mut f32,
    pub jointForce: *mut f32,
    pub linkVelocity: *mut PxSpatialVelocity,
    pub linkAcceleration: *mut PxSpatialVelocity,
    pub rootLinkData: *mut PxArticulationRootLinkData,
    pub coefficientMatrix: *mut f32,
    pub lambda: *mut f32,
    pub scratchMemory: *mut std::ffi::c_void,
    pub scratchAllocator: *mut std::ffi::c_void,
    pub version: u32,
    pub structgen_pad0: [u8; 4],
}
#[test] fn check_size_PxArticulationCache() { assert_eq!(std::mem::size_of::<PxArticulationCache>(), 120); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxArticulationReducedCoordinate {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
    pub userData: *mut std::ffi::c_void,
}
#[test] fn check_size_PxArticulationReducedCoordinate() { assert_eq!(std::mem::size_of::<PxArticulationReducedCoordinate>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxJoint {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
    pub userData: *mut std::ffi::c_void,
}
#[test] fn check_size_PxJoint() { assert_eq!(std::mem::size_of::<PxJoint>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxArticulationJoint {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
}
#[test] fn check_size_PxArticulationJoint() { assert_eq!(std::mem::size_of::<PxArticulationJoint>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxArticulationJointReducedCoordinate {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
}
#[test] fn check_size_PxArticulationJointReducedCoordinate() { assert_eq!(std::mem::size_of::<PxArticulationJointReducedCoordinate>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxFilterData {
    pub word0: u32,
    pub word1: u32,
    pub word2: u32,
    pub word3: u32,
}
#[test] fn check_size_PxFilterData() { assert_eq!(std::mem::size_of::<PxFilterData>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxMaterial {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
    pub userData: *mut std::ffi::c_void,
}
#[test] fn check_size_PxMaterial() { assert_eq!(std::mem::size_of::<PxMaterial>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxRigidBody {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
    pub userData: *mut std::ffi::c_void,
}
#[test] fn check_size_PxRigidBody() { assert_eq!(std::mem::size_of::<PxRigidBody>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxQueryFilterData {
    pub data: PxFilterData,
    pub flags: PxQueryFlags,
    pub structgen_pad0: [u8; 2],
}
#[test] fn check_size_PxQueryFilterData() { assert_eq!(std::mem::size_of::<PxQueryFilterData>(), 20); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxOverlapHit {
    pub actor: *mut PxRigidActor,
    pub shape: *mut PxShape,
    pub faceIndex: u32,
    pub padTo16Bytes: u32,
}
#[test] fn check_size_PxOverlapHit() { assert_eq!(std::mem::size_of::<PxOverlapHit>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxBatchQueryMemory {
    pub userRaycastResultBuffer: *mut PxRaycastQueryResult,
    pub userRaycastTouchBuffer: *mut PxRaycastHit,
    pub userSweepResultBuffer: *mut PxSweepQueryResult,
    pub userSweepTouchBuffer: *mut PxSweepHit,
    pub userOverlapResultBuffer: *mut PxOverlapQueryResult,
    pub userOverlapTouchBuffer: *mut PxOverlapHit,
    pub raycastTouchBufferSize: u32,
    pub sweepTouchBufferSize: u32,
    pub overlapTouchBufferSize: u32,
    pub raycastResultBufferSize: u32,
    pub sweepResultBufferSize: u32,
    pub overlapResultBufferSize: u32,
}
#[test] fn check_size_PxBatchQueryMemory() { assert_eq!(std::mem::size_of::<PxBatchQueryMemory>(), 72); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxBatchQueryDesc {
    pub filterShaderData: *mut std::ffi::c_void,
    pub filterShaderDataSize: u32,
    pub structgen_pad0: [u8; 4],
    pub preFilterShader: *mut std::ffi::c_void,
    pub postFilterShader: *mut std::ffi::c_void,
    pub queryMemory: PxBatchQueryMemory,
}
#[test] fn check_size_PxBatchQueryDesc() { assert_eq!(std::mem::size_of::<PxBatchQueryDesc>(), 104); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxQueryCache {
    pub shape: *mut PxShape,
    pub actor: *mut PxRigidActor,
    pub faceIndex: u32,
    pub structgen_pad0: [u8; 4],
}
#[test] fn check_size_PxQueryCache() { assert_eq!(std::mem::size_of::<PxQueryCache>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxConstraintShaderTable {
    pub solverPrep: *mut std::ffi::c_void,
    pub project: *mut std::ffi::c_void,
    pub visualize: *mut std::ffi::c_void,
    pub flag: u32,
    pub structgen_pad0: [u8; 4],
}
#[test] fn check_size_PxConstraintShaderTable() { assert_eq!(std::mem::size_of::<PxConstraintShaderTable>(), 32); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxMassModificationProps {
    pub mInvMassScale0: f32,
    pub mInvInertiaScale0: f32,
    pub mInvMassScale1: f32,
    pub mInvInertiaScale1: f32,
}
#[test] fn check_size_PxMassModificationProps() { assert_eq!(std::mem::size_of::<PxMassModificationProps>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxContactPatch {
    pub mMassModification: PxMassModificationProps,
    pub normal: PxVec3,
    pub restitution: f32,
    pub dynamicFriction: f32,
    pub staticFriction: f32,
    pub startContactIndex: u8,
    pub nbContacts: u8,
    pub materialFlags: u8,
    pub internalFlags: u8,
    pub materialIndex0: u16,
    pub materialIndex1: u16,
}
#[test] fn check_size_PxContactPatch() { assert_eq!(std::mem::size_of::<PxContactPatch>(), 48); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxContact {
    pub contact: PxVec3,
    pub separation: f32,
}
#[test] fn check_size_PxContact() { assert_eq!(std::mem::size_of::<PxContact>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxContactStreamIterator {
    pub zero: PxVec3,
    pub structgen_pad0: [u8; 4],
    pub patch: *const PxContactPatch,
    pub contact: *const PxContact,
    pub faceIndice: *const u32,
    pub totalPatches: u32,
    pub totalContacts: u32,
    pub nextContactIndex: u32,
    pub nextPatchIndex: u32,
    pub contactPatchHeaderSize: u32,
    pub contactPointSize: u32,
    pub mStreamFormat: u32,
    pub forceNoResponse: u32,
    pub pointStepped: bool,
    pub structgen_pad1: [u8; 3],
    pub hasFaceIndices: u32,
}
#[test] fn check_size_PxContactStreamIterator() { assert_eq!(std::mem::size_of::<PxContactStreamIterator>(), 80); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxModifiableContact {
    pub contact: PxVec3,
    pub separation: f32,
    pub targetVelocity: PxVec3,
    pub maxImpulse: f32,
    pub normal: PxVec3,
    pub restitution: f32,
    pub materialFlags: u32,
    pub materialIndex0: u16,
    pub materialIndex1: u16,
    pub staticFriction: f32,
    pub dynamicFriction: f32,
}
#[test] fn check_size_PxModifiableContact() { assert_eq!(std::mem::size_of::<PxModifiableContact>(), 64); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxContactSet {
    pub mCount: u32,
    pub structgen_pad0: [u8; 4],
    pub mContacts: *mut PxModifiableContact,
}
#[test] fn check_size_PxContactSet() { assert_eq!(std::mem::size_of::<PxContactSet>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxContactModifyPair {
    pub actor: [*const PxRigidActor; 2],
    pub shape: [*const PxShape; 2],
    pub transform: [PxTransform; 2],
    pub contacts: PxContactSet,
}
#[test] fn check_size_PxContactModifyPair() { assert_eq!(std::mem::size_of::<PxContactModifyPair>(), 104); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSceneLimits {
    pub maxNbActors: u32,
    pub maxNbBodies: u32,
    pub maxNbStaticShapes: u32,
    pub maxNbDynamicShapes: u32,
    pub maxNbAggregates: u32,
    pub maxNbConstraints: u32,
    pub maxNbRegions: u32,
    pub maxNbBroadPhaseOverlaps: u32,
}
#[test] fn check_size_PxSceneLimits() { assert_eq!(std::mem::size_of::<PxSceneLimits>(), 32); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxgDynamicsMemoryConfig {
    pub constraintBufferCapacity: u32,
    pub contactBufferCapacity: u32,
    pub tempBufferCapacity: u32,
    pub contactStreamSize: u32,
    pub patchStreamSize: u32,
    pub forceStreamCapacity: u32,
    pub heapCapacity: u32,
    pub foundLostPairsCapacity: u32,
}
#[test] fn check_size_PxgDynamicsMemoryConfig() { assert_eq!(std::mem::size_of::<PxgDynamicsMemoryConfig>(), 32); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSceneDesc {
    pub gravity: PxVec3,
    pub structgen_pad0: [u8; 4],
    pub simulationEventCallback: *mut PxSimulationEventCallback,
    pub contactModifyCallback: *mut PxContactModifyCallback,
    pub ccdContactModifyCallback: *mut PxCCDContactModifyCallback,
    pub filterShaderData: *const std::ffi::c_void,
    pub filterShaderDataSize: u32,
    pub structgen_pad1: [u8; 4],
    pub filterShader: *mut std::ffi::c_void,
    pub filterCallback: *mut PxSimulationFilterCallback,
    pub kineKineFilteringMode: u32,
    pub staticKineFilteringMode: u32,
    pub broadPhaseType: u32,
    pub structgen_pad2: [u8; 4],
    pub broadPhaseCallback: *mut PxBroadPhaseCallback,
    pub limits: PxSceneLimits,
    pub frictionType: u32,
    pub solverType: u32,
    pub bounceThresholdVelocity: f32,
    pub frictionOffsetThreshold: f32,
    pub ccdMaxSeparation: f32,
    pub solverOffsetSlop: f32,
    pub flags: PxSceneFlags,
    pub structgen_pad3: [u8; 4],
    pub cpuDispatcher: *mut PxCpuDispatcher,
    pub cudaContextManager: *mut PxCudaContextManager,
    pub staticStructure: u32,
    pub dynamicStructure: u32,
    pub dynamicTreeRebuildRateHint: u32,
    pub sceneQueryUpdateMode: u32,
    pub userData: *mut std::ffi::c_void,
    pub solverBatchSize: u32,
    pub solverArticulationBatchSize: u32,
    pub nbContactDataBlocks: u32,
    pub maxNbContactDataBlocks: u32,
    pub maxBiasCoefficient: f32,
    pub contactReportStreamBufferSize: u32,
    pub ccdMaxPasses: u32,
    pub ccdThreshold: f32,
    pub wakeCounterResetValue: f32,
    pub sanityBounds: PxBounds3,
    pub gpuDynamicsConfig: PxgDynamicsMemoryConfig,
    pub gpuMaxNumPartitions: u32,
    pub gpuComputeVersion: u32,
    pub structgen_pad4: [u8; 12],
}
#[test] fn check_size_PxSceneDesc() { assert_eq!(std::mem::size_of::<PxSceneDesc>(), 312); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxRigidStatic {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
    pub userData: *mut std::ffi::c_void,
}
#[test] fn check_size_PxRigidStatic() { assert_eq!(std::mem::size_of::<PxRigidStatic>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxRigidDynamic {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
    pub userData: *mut std::ffi::c_void,
}
#[test] fn check_size_PxRigidDynamic() { assert_eq!(std::mem::size_of::<PxRigidDynamic>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxPruningStructure {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
}
#[test] fn check_size_PxPruningStructure() { assert_eq!(std::mem::size_of::<PxPruningStructure>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSimulationStatistics {
    pub nbActiveConstraints: u32,
    pub nbActiveDynamicBodies: u32,
    pub nbActiveKinematicBodies: u32,
    pub nbStaticBodies: u32,
    pub nbDynamicBodies: u32,
    pub nbKinematicBodies: u32,
    pub nbShapes: [u32; 7],
    pub nbAggregates: u32,
    pub nbArticulations: u32,
    pub nbAxisSolverConstraints: u32,
    pub compressedContactSize: u32,
    pub requiredContactConstraintMemory: u32,
    pub peakConstraintMemory: u32,
    pub nbDiscreteContactPairsTotal: u32,
    pub nbDiscreteContactPairsWithCacheHits: u32,
    pub nbDiscreteContactPairsWithContacts: u32,
    pub nbNewPairs: u32,
    pub nbLostPairs: u32,
    pub nbNewTouches: u32,
    pub nbLostTouches: u32,
    pub nbPartitions: u32,
    pub nbBroadPhaseAdds: u32,
    pub nbBroadPhaseRemoves: u32,
    pub nbDiscreteContactPairs: [[u32; 7]; 7],
    pub nbCCDPairs: [[u32; 7]; 7],
    pub nbModifiedContactPairs: [[u32; 7]; 7],
    pub nbTriggerPairs: [[u32; 7]; 7],
}
#[test] fn check_size_PxSimulationStatistics() { assert_eq!(std::mem::size_of::<PxSimulationStatistics>(), 900); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxDominanceGroupPair {
    pub dominance0: u8,
    pub dominance1: u8,
}
#[test] fn check_size_PxDominanceGroupPair() { assert_eq!(std::mem::size_of::<PxDominanceGroupPair>(), 2); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxContactPair {
    pub shapes: [*mut PxShape; 2],
    pub contactPatches: *const u8,
    pub contactPoints: *const u8,
    pub contactImpulses: *const f32,
    pub requiredBufferSize: u32,
    pub contactCount: u8,
    pub patchCount: u8,
    pub contactStreamSize: u16,
    pub flags: PxContactPairFlags,
    pub events: PxPairFlags,
    pub internalData: [u32; 2],
    pub structgen_pad0: [u8; 4],
}
#[test] fn check_size_PxContactPair() { assert_eq!(std::mem::size_of::<PxContactPair>(), 64); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxContactPairHeader {
    pub actors: [*mut PxRigidActor; 2],
    pub extraDataStream: *const u8,
    pub extraDataStreamSize: u16,
    pub flags: PxContactPairHeaderFlags,
    pub structgen_pad0: [u8; 4],
    pub pairs: *const PxContactPair,
    pub nbPairs: u32,
    pub structgen_pad1: [u8; 4],
}
#[test] fn check_size_PxContactPairHeader() { assert_eq!(std::mem::size_of::<PxContactPairHeader>(), 48); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxBroadPhaseCaps {
    pub maxNbRegions: u32,
    pub maxNbObjects: u32,
    pub needsPredefinedBounds: bool,
    pub structgen_pad0: [u8; 3],
}
#[test] fn check_size_PxBroadPhaseCaps() { assert_eq!(std::mem::size_of::<PxBroadPhaseCaps>(), 12); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxBroadPhaseRegion {
    pub bounds: PxBounds3,
    pub userData: *mut std::ffi::c_void,
}
#[test] fn check_size_PxBroadPhaseRegion() { assert_eq!(std::mem::size_of::<PxBroadPhaseRegion>(), 32); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxBroadPhaseRegionInfo {
    pub region: PxBroadPhaseRegion,
    pub nbStaticObjects: u32,
    pub nbDynamicObjects: u32,
    pub active: bool,
    pub overlap: bool,
    pub structgen_pad0: [u8; 6],
}
#[test] fn check_size_PxBroadPhaseRegionInfo() { assert_eq!(std::mem::size_of::<PxBroadPhaseRegionInfo>(), 48); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSceneReadLock {
    pub structgen_pad0: [u8; 8],
}
#[test] fn check_size_PxSceneReadLock() { assert_eq!(std::mem::size_of::<PxSceneReadLock>(), 8); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSceneWriteLock {
    pub structgen_pad0: [u8; 8],
}
#[test] fn check_size_PxSceneWriteLock() { assert_eq!(std::mem::size_of::<PxSceneWriteLock>(), 8); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxContactPairExtraDataItem {
    pub _type: u8,
}
#[test] fn check_size_PxContactPairExtraDataItem() { assert_eq!(std::mem::size_of::<PxContactPairExtraDataItem>(), 1); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxContactPairVelocity {
    pub _type: u8,
    pub structgen_pad0: [u8; 3],
    pub linearVelocity: [PxVec3; 2],
    pub angularVelocity: [PxVec3; 2],
}
#[test] fn check_size_PxContactPairVelocity() { assert_eq!(std::mem::size_of::<PxContactPairVelocity>(), 52); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxContactPairPose {
    pub _type: u8,
    pub structgen_pad0: [u8; 3],
    pub globalPose: [PxTransform; 2],
}
#[test] fn check_size_PxContactPairPose() { assert_eq!(std::mem::size_of::<PxContactPairPose>(), 60); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxContactPairIndex {
    pub _type: u8,
    pub structgen_pad0: [u8; 1],
    pub index: u16,
}
#[test] fn check_size_PxContactPairIndex() { assert_eq!(std::mem::size_of::<PxContactPairIndex>(), 4); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxContactPairExtraDataIterator {
    pub currPtr: *const u8,
    pub endPtr: *const u8,
    pub preSolverVelocity: *const PxContactPairVelocity,
    pub postSolverVelocity: *const PxContactPairVelocity,
    pub eventPose: *const PxContactPairPose,
    pub contactPairIndex: u32,
    pub structgen_pad0: [u8; 4],
}
#[test] fn check_size_PxContactPairExtraDataIterator() { assert_eq!(std::mem::size_of::<PxContactPairExtraDataIterator>(), 48); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxContactPairPoint {
    pub position: PxVec3,
    pub separation: f32,
    pub normal: PxVec3,
    pub internalFaceIndex0: u32,
    pub impulse: PxVec3,
    pub internalFaceIndex1: u32,
}
#[test] fn check_size_PxContactPairPoint() { assert_eq!(std::mem::size_of::<PxContactPairPoint>(), 48); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxTriggerPair {
    pub triggerShape: *mut PxShape,
    pub triggerActor: *mut PxRigidActor,
    pub otherShape: *mut PxShape,
    pub otherActor: *mut PxRigidActor,
    pub status: u32,
    pub flags: PxTriggerPairFlags,
    pub structgen_pad0: [u8; 3],
}
#[test] fn check_size_PxTriggerPair() { assert_eq!(std::mem::size_of::<PxTriggerPair>(), 40); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxConstraintInfo {
    pub constraint: *mut PxConstraint,
    pub externalReference: *mut std::ffi::c_void,
    pub _type: u32,
    pub structgen_pad0: [u8; 4],
}
#[test] fn check_size_PxConstraintInfo() { assert_eq!(std::mem::size_of::<PxConstraintInfo>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxExtendedVec3 {
    pub x: f64,
    pub y: f64,
    pub z: f64,
}
#[test] fn check_size_PxExtendedVec3() { assert_eq!(std::mem::size_of::<PxExtendedVec3>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxObstacle {
    pub mType: i32,
    pub structgen_pad0: [u8; 4],
    pub mUserData: *mut std::ffi::c_void,
    pub mPos: PxExtendedVec3,
    pub mRot: PxQuat,
}
#[test] fn check_size_PxObstacle() { assert_eq!(std::mem::size_of::<PxObstacle>(), 56); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxBoxObstacle {
    pub mType: i32,
    pub structgen_pad0: [u8; 4],
    pub mUserData: *mut std::ffi::c_void,
    pub mPos: PxExtendedVec3,
    pub mRot: PxQuat,
    pub mHalfExtents: PxVec3,
    pub structgen_pad1: [u8; 4],
}
#[test] fn check_size_PxBoxObstacle() { assert_eq!(std::mem::size_of::<PxBoxObstacle>(), 72); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxCapsuleObstacle {
    pub mType: i32,
    pub structgen_pad0: [u8; 4],
    pub mUserData: *mut std::ffi::c_void,
    pub mPos: PxExtendedVec3,
    pub mRot: PxQuat,
    pub mHalfHeight: f32,
    pub mRadius: f32,
}
#[test] fn check_size_PxCapsuleObstacle() { assert_eq!(std::mem::size_of::<PxCapsuleObstacle>(), 64); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxControllerShapeHit {
    pub controller: *mut PxController,
    pub worldPos: PxExtendedVec3,
    pub worldNormal: PxVec3,
    pub dir: PxVec3,
    pub length: f32,
    pub structgen_pad0: [u8; 4],
    pub shape: *mut PxShape,
    pub actor: *mut PxRigidActor,
    pub triangleIndex: u32,
    pub structgen_pad1: [u8; 4],
}
#[test] fn check_size_PxControllerShapeHit() { assert_eq!(std::mem::size_of::<PxControllerShapeHit>(), 88); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxControllersHit {
    pub controller: *mut PxController,
    pub worldPos: PxExtendedVec3,
    pub worldNormal: PxVec3,
    pub dir: PxVec3,
    pub length: f32,
    pub structgen_pad0: [u8; 4],
    pub other: *mut PxController,
}
#[test] fn check_size_PxControllersHit() { assert_eq!(std::mem::size_of::<PxControllersHit>(), 72); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxControllerObstacleHit {
    pub controller: *mut PxController,
    pub worldPos: PxExtendedVec3,
    pub worldNormal: PxVec3,
    pub dir: PxVec3,
    pub length: f32,
    pub structgen_pad0: [u8; 4],
    pub userData: *const std::ffi::c_void,
}
#[test] fn check_size_PxControllerObstacleHit() { assert_eq!(std::mem::size_of::<PxControllerObstacleHit>(), 72); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxControllerFilters {
    pub mFilterData: *const PxFilterData,
    pub mFilterCallback: *mut PxQueryFilterCallback,
    pub mFilterFlags: PxQueryFlags,
    pub structgen_pad0: [u8; 6],
    pub mCCTFilterCallback: *mut PxControllerFilterCallback,
}
#[test] fn check_size_PxControllerFilters() { assert_eq!(std::mem::size_of::<PxControllerFilters>(), 32); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxControllerDesc {
    pub structgen_pad0: [u8; 8],
    pub position: PxExtendedVec3,
    pub upDirection: PxVec3,
    pub slopeLimit: f32,
    pub invisibleWallHeight: f32,
    pub maxJumpHeight: f32,
    pub contactOffset: f32,
    pub stepOffset: f32,
    pub density: f32,
    pub scaleCoeff: f32,
    pub volumeGrowth: f32,
    pub structgen_pad1: [u8; 4],
    pub reportCallback: *mut PxUserControllerHitReport,
    pub behaviorCallback: *mut PxControllerBehaviorCallback,
    pub nonWalkableMode: u32,
    pub structgen_pad2: [u8; 4],
    pub material: *mut PxMaterial,
    pub registerDeletionListener: bool,
    pub structgen_pad3: [u8; 7],
    pub userData: *mut std::ffi::c_void,
    pub mType: u32,
    pub structgen_pad4: [u8; 4],
}
#[test] fn check_size_PxControllerDesc() { assert_eq!(std::mem::size_of::<PxControllerDesc>(), 136); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxControllerState {
    pub deltaXP: PxVec3,
    pub structgen_pad0: [u8; 4],
    pub touchedShape: *mut PxShape,
    pub touchedActor: *mut PxRigidActor,
    pub touchedObstacleHandle: u32,
    pub collisionFlags: u32,
    pub standOnAnotherCCT: bool,
    pub standOnObstacle: bool,
    pub isMovingUp: bool,
    pub structgen_pad1: [u8; 5],
}
#[test] fn check_size_PxControllerState() { assert_eq!(std::mem::size_of::<PxControllerState>(), 48); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxControllerStats {
    pub nbIterations: u16,
    pub nbFullUpdates: u16,
    pub nbPartialUpdates: u16,
    pub nbTessellation: u16,
}
#[test] fn check_size_PxControllerStats() { assert_eq!(std::mem::size_of::<PxControllerStats>(), 8); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxBoxControllerDesc {
    pub structgen_pad0: [u8; 8],
    pub position: PxExtendedVec3,
    pub upDirection: PxVec3,
    pub slopeLimit: f32,
    pub invisibleWallHeight: f32,
    pub maxJumpHeight: f32,
    pub contactOffset: f32,
    pub stepOffset: f32,
    pub density: f32,
    pub scaleCoeff: f32,
    pub volumeGrowth: f32,
    pub structgen_pad1: [u8; 4],
    pub reportCallback: *mut PxUserControllerHitReport,
    pub behaviorCallback: *mut PxControllerBehaviorCallback,
    pub nonWalkableMode: u32,
    pub structgen_pad2: [u8; 4],
    pub material: *mut PxMaterial,
    pub registerDeletionListener: bool,
    pub structgen_pad3: [u8; 7],
    pub userData: *mut std::ffi::c_void,
    pub mType: u32,
    pub halfHeight: f32,
    pub halfSideExtent: f32,
    pub halfForwardExtent: f32,
}
#[test] fn check_size_PxBoxControllerDesc() { assert_eq!(std::mem::size_of::<PxBoxControllerDesc>(), 144); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxCapsuleControllerDesc {
    pub structgen_pad0: [u8; 8],
    pub position: PxExtendedVec3,
    pub upDirection: PxVec3,
    pub slopeLimit: f32,
    pub invisibleWallHeight: f32,
    pub maxJumpHeight: f32,
    pub contactOffset: f32,
    pub stepOffset: f32,
    pub density: f32,
    pub scaleCoeff: f32,
    pub volumeGrowth: f32,
    pub structgen_pad1: [u8; 4],
    pub reportCallback: *mut PxUserControllerHitReport,
    pub behaviorCallback: *mut PxControllerBehaviorCallback,
    pub nonWalkableMode: u32,
    pub structgen_pad2: [u8; 4],
    pub material: *mut PxMaterial,
    pub registerDeletionListener: bool,
    pub structgen_pad3: [u8; 7],
    pub userData: *mut std::ffi::c_void,
    pub mType: u32,
    pub radius: f32,
    pub height: f32,
    pub climbingMode: u32,
}
#[test] fn check_size_PxCapsuleControllerDesc() { assert_eq!(std::mem::size_of::<PxCapsuleControllerDesc>(), 144); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxConvexMeshDesc {
    pub points: PxBoundedData,
    pub polygons: PxBoundedData,
    pub indices: PxBoundedData,
    pub flags: PxConvexFlags,
    pub vertexLimit: u16,
    pub quantizedCount: u16,
    pub structgen_pad0: [u8; 2],
}
#[test] fn check_size_PxConvexMeshDesc() { assert_eq!(std::mem::size_of::<PxConvexMeshDesc>(), 80); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxTriangleMeshDesc {
    pub points: PxBoundedData,
    pub triangles: PxBoundedData,
    pub flags: PxMeshFlags,
    pub structgen_pad0: [u8; 6],
    pub materialIndices: PxTypedStridedData_physx_PxMaterialTableIndex_,
}
#[test] fn check_size_PxTriangleMeshDesc() { assert_eq!(std::mem::size_of::<PxTriangleMeshDesc>(), 72); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxBVH33MidphaseDesc {
    pub meshSizePerformanceTradeOff: f32,
    pub meshCookingHint: u32,
}
#[test] fn check_size_PxBVH33MidphaseDesc() { assert_eq!(std::mem::size_of::<PxBVH33MidphaseDesc>(), 8); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxBVH34MidphaseDesc {
    pub numPrimsPerLeaf: u32,
}
#[test] fn check_size_PxBVH34MidphaseDesc() { assert_eq!(std::mem::size_of::<PxBVH34MidphaseDesc>(), 4); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxMidphaseDesc {
    pub structgen_pad0: [u8; 8],
    pub mType: u32,
}
#[test] fn check_size_PxMidphaseDesc() { assert_eq!(std::mem::size_of::<PxMidphaseDesc>(), 12); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxBVHStructureDesc {
    pub bounds: PxBoundedData,
}
#[test] fn check_size_PxBVHStructureDesc() { assert_eq!(std::mem::size_of::<PxBVHStructureDesc>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxCookingParams {
    pub areaTestEpsilon: f32,
    pub planeTolerance: f32,
    pub convexMeshCookingType: u32,
    pub suppressTriangleMeshRemapTable: bool,
    pub buildTriangleAdjacencies: bool,
    pub buildGPUData: bool,
    pub structgen_pad0: [u8; 1],
    pub scale: PxTolerancesScale,
    pub meshPreprocessParams: PxMeshPreprocessingFlags,
    pub meshWeldTolerance: f32,
    pub midphaseDesc: PxMidphaseDesc,
    pub gaussMapLimit: u32,
}
#[test] fn check_size_PxCookingParams() { assert_eq!(std::mem::size_of::<PxCookingParams>(), 48); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxDefaultMemoryOutputStream {
    pub structgen_pad0: [u8; 32],
}
#[test] fn check_size_PxDefaultMemoryOutputStream() { assert_eq!(std::mem::size_of::<PxDefaultMemoryOutputStream>(), 32); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxDefaultMemoryInputData {
    pub structgen_pad0: [u8; 32],
}
#[test] fn check_size_PxDefaultMemoryInputData() { assert_eq!(std::mem::size_of::<PxDefaultMemoryInputData>(), 32); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxDefaultFileOutputStream {
    pub structgen_pad0: [u8; 16],
}
#[test] fn check_size_PxDefaultFileOutputStream() { assert_eq!(std::mem::size_of::<PxDefaultFileOutputStream>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxDefaultFileInputData {
    pub structgen_pad0: [u8; 24],
}
#[test] fn check_size_PxDefaultFileInputData() { assert_eq!(std::mem::size_of::<PxDefaultFileInputData>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSpring {
    pub stiffness: f32,
    pub damping: f32,
}
#[test] fn check_size_PxSpring() { assert_eq!(std::mem::size_of::<PxSpring>(), 8); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxDistanceJoint {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
    pub userData: *mut std::ffi::c_void,
}
#[test] fn check_size_PxDistanceJoint() { assert_eq!(std::mem::size_of::<PxDistanceJoint>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxContactJoint {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
    pub userData: *mut std::ffi::c_void,
}
#[test] fn check_size_PxContactJoint() { assert_eq!(std::mem::size_of::<PxContactJoint>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxJacobianRow {
    pub linear0: PxVec3,
    pub linear1: PxVec3,
    pub angular0: PxVec3,
    pub angular1: PxVec3,
}
#[test] fn check_size_PxJacobianRow() { assert_eq!(std::mem::size_of::<PxJacobianRow>(), 48); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxFixedJoint {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
    pub userData: *mut std::ffi::c_void,
}
#[test] fn check_size_PxFixedJoint() { assert_eq!(std::mem::size_of::<PxFixedJoint>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxJointLimitParameters {
    pub restitution: f32,
    pub bounceThreshold: f32,
    pub stiffness: f32,
    pub damping: f32,
    pub contactDistance: f32,
}
#[test] fn check_size_PxJointLimitParameters() { assert_eq!(std::mem::size_of::<PxJointLimitParameters>(), 20); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxJointLinearLimit {
    pub restitution: f32,
    pub bounceThreshold: f32,
    pub stiffness: f32,
    pub damping: f32,
    pub contactDistance: f32,
    pub value: f32,
}
#[test] fn check_size_PxJointLinearLimit() { assert_eq!(std::mem::size_of::<PxJointLinearLimit>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxJointLinearLimitPair {
    pub restitution: f32,
    pub bounceThreshold: f32,
    pub stiffness: f32,
    pub damping: f32,
    pub contactDistance: f32,
    pub upper: f32,
    pub lower: f32,
}
#[test] fn check_size_PxJointLinearLimitPair() { assert_eq!(std::mem::size_of::<PxJointLinearLimitPair>(), 28); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxJointAngularLimitPair {
    pub restitution: f32,
    pub bounceThreshold: f32,
    pub stiffness: f32,
    pub damping: f32,
    pub contactDistance: f32,
    pub upper: f32,
    pub lower: f32,
}
#[test] fn check_size_PxJointAngularLimitPair() { assert_eq!(std::mem::size_of::<PxJointAngularLimitPair>(), 28); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxJointLimitCone {
    pub restitution: f32,
    pub bounceThreshold: f32,
    pub stiffness: f32,
    pub damping: f32,
    pub contactDistance: f32,
    pub yAngle: f32,
    pub zAngle: f32,
}
#[test] fn check_size_PxJointLimitCone() { assert_eq!(std::mem::size_of::<PxJointLimitCone>(), 28); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxJointLimitPyramid {
    pub restitution: f32,
    pub bounceThreshold: f32,
    pub stiffness: f32,
    pub damping: f32,
    pub contactDistance: f32,
    pub yAngleMin: f32,
    pub yAngleMax: f32,
    pub zAngleMin: f32,
    pub zAngleMax: f32,
}
#[test] fn check_size_PxJointLimitPyramid() { assert_eq!(std::mem::size_of::<PxJointLimitPyramid>(), 36); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxPrismaticJoint {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
    pub userData: *mut std::ffi::c_void,
}
#[test] fn check_size_PxPrismaticJoint() { assert_eq!(std::mem::size_of::<PxPrismaticJoint>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxRevoluteJoint {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
    pub userData: *mut std::ffi::c_void,
}
#[test] fn check_size_PxRevoluteJoint() { assert_eq!(std::mem::size_of::<PxRevoluteJoint>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSphericalJoint {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
    pub userData: *mut std::ffi::c_void,
}
#[test] fn check_size_PxSphericalJoint() { assert_eq!(std::mem::size_of::<PxSphericalJoint>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxD6Joint {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
    pub userData: *mut std::ffi::c_void,
}
#[test] fn check_size_PxD6Joint() { assert_eq!(std::mem::size_of::<PxD6Joint>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxD6JointDrive {
    pub stiffness: f32,
    pub damping: f32,
    pub forceLimit: f32,
    pub flags: PxD6JointDriveFlags,
}
#[test] fn check_size_PxD6JointDrive() { assert_eq!(std::mem::size_of::<PxD6JointDrive>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxGroupsMask {
    pub bits0: u16,
    pub bits1: u16,
    pub bits2: u16,
    pub bits3: u16,
}
#[test] fn check_size_PxGroupsMask() { assert_eq!(std::mem::size_of::<PxGroupsMask>(), 8); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxMassProperties {
    pub inertiaTensor: PxMat33,
    pub centerOfMass: PxVec3,
    pub mass: f32,
}
#[test] fn check_size_PxMassProperties() { assert_eq!(std::mem::size_of::<PxMassProperties>(), 52); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxMeshOverlapUtil {
    pub structgen_pad0: [u8; 1040],
}
#[test] fn check_size_PxMeshOverlapUtil() { assert_eq!(std::mem::size_of::<PxMeshOverlapUtil>(), 1040); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSerialization_PxXmlMiscParameter {
    pub upVector: PxVec3,
    pub scale: PxTolerancesScale,
}
#[test] fn check_size_PxSerialization_PxXmlMiscParameter() { assert_eq!(std::mem::size_of::<PxSerialization_PxXmlMiscParameter>(), 20); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSceneQueryHit {
    pub actor: *mut PxRigidActor,
    pub shape: *mut PxShape,
    pub faceIndex: u32,
    pub structgen_pad0: [u8; 4],
}
#[test] fn check_size_PxSceneQueryHit() { assert_eq!(std::mem::size_of::<PxSceneQueryHit>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSceneQueryFilterData {
    pub data: PxFilterData,
    pub flags: PxQueryFlags,
    pub structgen_pad0: [u8; 2],
}
#[test] fn check_size_PxSceneQueryFilterData() { assert_eq!(std::mem::size_of::<PxSceneQueryFilterData>(), 20); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSceneQueryCache {
    pub shape: *mut PxShape,
    pub actor: *mut PxRigidActor,
    pub faceIndex: u32,
    pub structgen_pad0: [u8; 4],
}
#[test] fn check_size_PxSceneQueryCache() { assert_eq!(std::mem::size_of::<PxSceneQueryCache>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxRepXObject {
    pub typeName: *const i8,
    pub serializable: *const std::ffi::c_void,
    pub id: usize,
}
#[test] fn check_size_PxRepXObject() { assert_eq!(std::mem::size_of::<PxRepXObject>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxRepXInstantiationArgs {
    pub structgen_pad0: [u8; 8],
    pub cooker: *mut PxCooking,
    pub stringTable: *mut PxStringTable,
}
#[test] fn check_size_PxRepXInstantiationArgs() { assert_eq!(std::mem::size_of::<PxRepXInstantiationArgs>(), 24); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleChassisData {
    pub mMOI: PxVec3,
    pub mMass: f32,
    pub mCMOffset: PxVec3,
    pub structgen_pad0: [u8; 4],
}
#[test] fn check_size_PxVehicleChassisData() { assert_eq!(std::mem::size_of::<PxVehicleChassisData>(), 32); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleEngineData {
    pub mTorqueCurve: PxFixedSizeLookupTable_eMAX_NB_ENGINE_TORQUE_CURVE_ENTRIES_,
    pub mMOI: f32,
    pub mPeakTorque: f32,
    pub mMaxOmega: f32,
    pub mDampingRateFullThrottle: f32,
    pub mDampingRateZeroThrottleClutchEngaged: f32,
    pub mDampingRateZeroThrottleClutchDisengaged: f32,
    pub structgen_pad0: [u8; 8],
}
#[test] fn check_size_PxVehicleEngineData() { assert_eq!(std::mem::size_of::<PxVehicleEngineData>(), 112); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleGearsData {
    pub mRatios: [f32; 32],
    pub mFinalRatio: f32,
    pub mNbRatios: u32,
    pub mSwitchTime: f32,
    pub structgen_pad0: [u8; 4],
}
#[test] fn check_size_PxVehicleGearsData() { assert_eq!(std::mem::size_of::<PxVehicleGearsData>(), 144); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleAutoBoxData {
    pub mUpRatios: [f32; 32],
    pub mDownRatios: [f32; 32],
}
#[test] fn check_size_PxVehicleAutoBoxData() { assert_eq!(std::mem::size_of::<PxVehicleAutoBoxData>(), 256); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleDifferential4WData {
    pub mFrontRearSplit: f32,
    pub mFrontLeftRightSplit: f32,
    pub mRearLeftRightSplit: f32,
    pub mCentreBias: f32,
    pub mFrontBias: f32,
    pub mRearBias: f32,
    pub mType: u32,
    pub structgen_pad0: [u8; 4],
}
#[test] fn check_size_PxVehicleDifferential4WData() { assert_eq!(std::mem::size_of::<PxVehicleDifferential4WData>(), 32); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleDifferentialNWData {
    pub structgen_pad0: [u8; 16],
}
#[test] fn check_size_PxVehicleDifferentialNWData() { assert_eq!(std::mem::size_of::<PxVehicleDifferentialNWData>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleAckermannGeometryData {
    pub mAccuracy: f32,
    pub mFrontWidth: f32,
    pub mRearWidth: f32,
    pub mAxleSeparation: f32,
}
#[test] fn check_size_PxVehicleAckermannGeometryData() { assert_eq!(std::mem::size_of::<PxVehicleAckermannGeometryData>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleClutchData {
    pub mStrength: f32,
    pub mAccuracyMode: u32,
    pub mEstimateIterations: u32,
    pub structgen_pad0: [u8; 4],
}
#[test] fn check_size_PxVehicleClutchData() { assert_eq!(std::mem::size_of::<PxVehicleClutchData>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleTireLoadFilterData {
    pub mMinNormalisedLoad: f32,
    pub mMinFilteredNormalisedLoad: f32,
    pub mMaxNormalisedLoad: f32,
    pub mMaxFilteredNormalisedLoad: f32,
    pub structgen_pad0: [u8; 16],
}
#[test] fn check_size_PxVehicleTireLoadFilterData() { assert_eq!(std::mem::size_of::<PxVehicleTireLoadFilterData>(), 32); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleWheelData {
    pub mRadius: f32,
    pub mWidth: f32,
    pub mMass: f32,
    pub mMOI: f32,
    pub mDampingRate: f32,
    pub mMaxBrakeTorque: f32,
    pub mMaxHandBrakeTorque: f32,
    pub mMaxSteer: f32,
    pub mToeAngle: f32,
    pub structgen_pad0: [u8; 12],
}
#[test] fn check_size_PxVehicleWheelData() { assert_eq!(std::mem::size_of::<PxVehicleWheelData>(), 48); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleSuspensionData {
    pub mSpringStrength: f32,
    pub mSpringDamperRate: f32,
    pub mMaxCompression: f32,
    pub mMaxDroop: f32,
    pub mSprungMass: f32,
    pub mCamberAtRest: f32,
    pub mCamberAtMaxCompression: f32,
    pub mCamberAtMaxDroop: f32,
    pub structgen_pad0: [u8; 16],
}
#[test] fn check_size_PxVehicleSuspensionData() { assert_eq!(std::mem::size_of::<PxVehicleSuspensionData>(), 48); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleAntiRollBarData {
    pub mWheel0: u32,
    pub mWheel1: u32,
    pub mStiffness: f32,
    pub structgen_pad0: [u8; 4],
}
#[test] fn check_size_PxVehicleAntiRollBarData() { assert_eq!(std::mem::size_of::<PxVehicleAntiRollBarData>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleTireData {
    pub mLatStiffX: f32,
    pub mLatStiffY: f32,
    pub mLongitudinalStiffnessPerUnitGravity: f32,
    pub mCamberStiffnessPerUnitGravity: f32,
    pub mFrictionVsSlipGraph: [[f32; 2]; 3],
    pub mType: u32,
    pub structgen_pad0: [u8; 20],
}
#[test] fn check_size_PxVehicleTireData() { assert_eq!(std::mem::size_of::<PxVehicleTireData>(), 64); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleWheelsSimData {
    pub structgen_pad0: [u8; 96],
}
#[test] fn check_size_PxVehicleWheelsSimData() { assert_eq!(std::mem::size_of::<PxVehicleWheelsSimData>(), 96); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleWheelsDynData {
    pub structgen_pad0: [u8; 48],
}
#[test] fn check_size_PxVehicleWheelsDynData() { assert_eq!(std::mem::size_of::<PxVehicleWheelsDynData>(), 48); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleWheels {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
    pub mWheelsSimData: PxVehicleWheelsSimData,
    pub mWheelsDynData: PxVehicleWheelsDynData,
    pub mActor: *mut PxRigidDynamic,
    pub structgen_pad2: [u8; 5],
    pub mType: u8,
    pub mPad0: [u8; 14],
    pub structgen_pad3: [u8; 4],
}
#[test] fn check_size_PxVehicleWheels() { assert_eq!(std::mem::size_of::<PxVehicleWheels>(), 192); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleDriveSimData {
    pub mEngine: PxVehicleEngineData,
    pub mGears: PxVehicleGearsData,
    pub mClutch: PxVehicleClutchData,
    pub mAutoBox: PxVehicleAutoBoxData,
}
#[test] fn check_size_PxVehicleDriveSimData() { assert_eq!(std::mem::size_of::<PxVehicleDriveSimData>(), 528); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleDriveDynData {
    pub mControlAnalogVals: [f32; 16],
    pub mUseAutoGears: bool,
    pub mGearUpPressed: bool,
    pub mGearDownPressed: bool,
    pub structgen_pad0: [u8; 1],
    pub mCurrentGear: u32,
    pub mTargetGear: u32,
    pub mEnginespeed: f32,
    pub mGearSwitchTime: f32,
    pub mAutoBoxSwitchTime: f32,
    pub structgen_pad1: [u8; 8],
}
#[test] fn check_size_PxVehicleDriveDynData() { assert_eq!(std::mem::size_of::<PxVehicleDriveDynData>(), 96); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleDrive {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
    pub mWheelsSimData: PxVehicleWheelsSimData,
    pub mWheelsDynData: PxVehicleWheelsDynData,
    pub mActor: *mut PxRigidDynamic,
    pub structgen_pad2: [u8; 5],
    pub mType: u8,
    pub mPad0: [u8; 14],
    pub mDriveDynData: PxVehicleDriveDynData,
    pub structgen_pad3: [u8; 4],
}
#[test] fn check_size_PxVehicleDrive() { assert_eq!(std::mem::size_of::<PxVehicleDrive>(), 288); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleDriveSimData4W {
    pub mEngine: PxVehicleEngineData,
    pub mGears: PxVehicleGearsData,
    pub mClutch: PxVehicleClutchData,
    pub mAutoBox: PxVehicleAutoBoxData,
    pub structgen_pad0: [u8; 48],
}
#[test] fn check_size_PxVehicleDriveSimData4W() { assert_eq!(std::mem::size_of::<PxVehicleDriveSimData4W>(), 576); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleDrive4W {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
    pub mWheelsSimData: PxVehicleWheelsSimData,
    pub mWheelsDynData: PxVehicleWheelsDynData,
    pub mActor: *mut PxRigidDynamic,
    pub structgen_pad2: [u8; 5],
    pub mType: u8,
    pub mPad0: [u8; 14],
    pub mDriveDynData: PxVehicleDriveDynData,
    pub mDriveSimData: PxVehicleDriveSimData4W,
    pub structgen_pad3: [u8; 4],
}
#[test] fn check_size_PxVehicleDrive4W() { assert_eq!(std::mem::size_of::<PxVehicleDrive4W>(), 864); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleDriveTank {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
    pub mWheelsSimData: PxVehicleWheelsSimData,
    pub mWheelsDynData: PxVehicleWheelsDynData,
    pub mActor: *mut PxRigidDynamic,
    pub structgen_pad2: [u8; 5],
    pub mType: u8,
    pub mPad0: [u8; 14],
    pub mDriveDynData: PxVehicleDriveDynData,
    pub mDriveSimData: PxVehicleDriveSimData,
    pub structgen_pad3: [u8; 20],
}
#[test] fn check_size_PxVehicleDriveTank() { assert_eq!(std::mem::size_of::<PxVehicleDriveTank>(), 832); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleDrivableSurfaceType {
    pub mType: u32,
}
#[test] fn check_size_PxVehicleDrivableSurfaceType() { assert_eq!(std::mem::size_of::<PxVehicleDrivableSurfaceType>(), 4); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleDrivableSurfaceToTireFrictionPairs {
    pub structgen_pad0: [u8; 48],
}
#[test] fn check_size_PxVehicleDrivableSurfaceToTireFrictionPairs() { assert_eq!(std::mem::size_of::<PxVehicleDrivableSurfaceToTireFrictionPairs>(), 48); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxWheelQueryResult {
    pub suspLineStart: PxVec3,
    pub suspLineDir: PxVec3,
    pub suspLineLength: f32,
    pub isInAir: bool,
    pub structgen_pad0: [u8; 3],
    pub tireContactActor: *mut PxActor,
    pub tireContactShape: *mut PxShape,
    pub tireSurfaceMaterial: *const PxMaterial,
    pub tireSurfaceType: u32,
    pub tireContactPoint: PxVec3,
    pub tireContactNormal: PxVec3,
    pub tireFriction: f32,
    pub suspJounce: f32,
    pub suspSpringForce: f32,
    pub tireLongitudinalDir: PxVec3,
    pub tireLateralDir: PxVec3,
    pub longitudinalSlip: f32,
    pub lateralSlip: f32,
    pub steerAngle: f32,
    pub localPose: PxTransform,
}
#[test] fn check_size_PxWheelQueryResult() { assert_eq!(std::mem::size_of::<PxWheelQueryResult>(), 160); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleWheelConcurrentUpdateData {
    pub structgen_pad0: [u8; 64],
}
#[test] fn check_size_PxVehicleWheelConcurrentUpdateData() { assert_eq!(std::mem::size_of::<PxVehicleWheelConcurrentUpdateData>(), 64); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleConcurrentUpdateData {
    pub concurrentWheelUpdates: *mut PxVehicleWheelConcurrentUpdateData,
    pub nbConcurrentWheelUpdates: u32,
    pub structgen_pad0: [u8; 28],
}
#[test] fn check_size_PxVehicleConcurrentUpdateData() { assert_eq!(std::mem::size_of::<PxVehicleConcurrentUpdateData>(), 40); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleWheelQueryResult {
    pub wheelQueryResults: *mut PxWheelQueryResult,
    pub nbWheelQueryResults: u32,
    pub structgen_pad0: [u8; 4],
}
#[test] fn check_size_PxVehicleWheelQueryResult() { assert_eq!(std::mem::size_of::<PxVehicleWheelQueryResult>(), 16); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleGraph {
    pub structgen_pad0: [u8; 15840],
}
#[test] fn check_size_PxVehicleGraph() { assert_eq!(std::mem::size_of::<PxVehicleGraph>(), 15840); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleTelemetryData {
    pub structgen_pad0: [u8; 48],
}
#[test] fn check_size_PxVehicleTelemetryData() { assert_eq!(std::mem::size_of::<PxVehicleTelemetryData>(), 48); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleDriveSimDataNW {
    pub mEngine: PxVehicleEngineData,
    pub mGears: PxVehicleGearsData,
    pub mClutch: PxVehicleClutchData,
    pub mAutoBox: PxVehicleAutoBoxData,
    pub structgen_pad0: [u8; 16],
}
#[test] fn check_size_PxVehicleDriveSimDataNW() { assert_eq!(std::mem::size_of::<PxVehicleDriveSimDataNW>(), 544); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleDriveNW {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
    pub mWheelsSimData: PxVehicleWheelsSimData,
    pub mWheelsDynData: PxVehicleWheelsDynData,
    pub mActor: *mut PxRigidDynamic,
    pub structgen_pad2: [u8; 5],
    pub mType: u8,
    pub mPad0: [u8; 14],
    pub mDriveDynData: PxVehicleDriveDynData,
    pub mDriveSimData: PxVehicleDriveSimDataNW,
    pub structgen_pad3: [u8; 4],
}
#[test] fn check_size_PxVehicleDriveNW() { assert_eq!(std::mem::size_of::<PxVehicleDriveNW>(), 832); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleDrive4WRawInputData {
    pub structgen_pad0: [u8; 40],
}
#[test] fn check_size_PxVehicleDrive4WRawInputData() { assert_eq!(std::mem::size_of::<PxVehicleDrive4WRawInputData>(), 40); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleKeySmoothingData {
    pub mRiseRates: [f32; 16],
    pub mFallRates: [f32; 16],
}
#[test] fn check_size_PxVehicleKeySmoothingData() { assert_eq!(std::mem::size_of::<PxVehicleKeySmoothingData>(), 128); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehiclePadSmoothingData {
    pub mRiseRates: [f32; 16],
    pub mFallRates: [f32; 16],
}
#[test] fn check_size_PxVehiclePadSmoothingData() { assert_eq!(std::mem::size_of::<PxVehiclePadSmoothingData>(), 128); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleDriveNWRawInputData {
    pub structgen_pad0: [u8; 40],
}
#[test] fn check_size_PxVehicleDriveNWRawInputData() { assert_eq!(std::mem::size_of::<PxVehicleDriveNWRawInputData>(), 40); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleDriveTankRawInputData {
    pub structgen_pad0: [u8; 32],
}
#[test] fn check_size_PxVehicleDriveTankRawInputData() { assert_eq!(std::mem::size_of::<PxVehicleDriveTankRawInputData>(), 32); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleCopyDynamicsMap {
    pub sourceWheelIds: [u8; 20],
    pub targetWheelIds: [u8; 20],
}
#[test] fn check_size_PxVehicleCopyDynamicsMap() { assert_eq!(std::mem::size_of::<PxVehicleCopyDynamicsMap>(), 40); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleGraphChannelDesc {
    pub mMinY: f32,
    pub mMaxY: f32,
    pub mMidY: f32,
    pub mColorLow: PxVec3,
    pub mColorHigh: PxVec3,
    pub structgen_pad0: [u8; 4],
    pub mTitle: *mut i8,
}
#[test] fn check_size_PxVehicleGraphChannelDesc() { assert_eq!(std::mem::size_of::<PxVehicleGraphChannelDesc>(), 48); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleGraphDesc {
    pub structgen_pad0: [u8; 32],
}
#[test] fn check_size_PxVehicleGraphDesc() { assert_eq!(std::mem::size_of::<PxVehicleGraphDesc>(), 32); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleNoDrive {
    pub structgen_pad0: [u8; 8],
    pub mConcreteType: u16,
    pub mBaseFlags: PxBaseFlags,
    pub structgen_pad1: [u8; 4],
    pub mWheelsSimData: PxVehicleWheelsSimData,
    pub mWheelsDynData: PxVehicleWheelsDynData,
    pub mActor: *mut PxRigidDynamic,
    pub structgen_pad2: [u8; 5],
    pub mType: u8,
    pub mPad0: [u8; 14],
    pub structgen_pad3: [u8; 36],
}
#[test] fn check_size_PxVehicleNoDrive() { assert_eq!(std::mem::size_of::<PxVehicleNoDrive>(), 224); }
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxProfileScoped {
    pub mCallback: *mut PxProfilerCallback,
    pub mEventName: *const i8,
    pub mProfilerData: *mut std::ffi::c_void,
    pub mContextId: usize,
    pub mDetached: bool,
    pub structgen_pad0: [u8; 7],
}
#[test] fn check_size_PxProfileScoped() { assert_eq!(std::mem::size_of::<PxProfileScoped>(), 40); }
