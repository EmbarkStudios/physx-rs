pub mod Px1DConstraintFlag{
pub type Type = u32;
pub const eSPRING: Type = 1u64 as u32;
pub const eACCELERATION_SPRING: Type = 2u64 as u32;
pub const eRESTITUTION: Type = 4u64 as u32;
pub const eKEEPBIAS: Type = 8u64 as u32;
pub const eOUTPUT_FORCE: Type = 16u64 as u32;
pub const eHAS_DRIVE_LIMIT: Type = 32u64 as u32;
pub const eANGULAR_CONSTRAINT: Type = 64u64 as u32;
pub const eDRIVE_ROW: Type = 128u64 as u32;
}
pub mod PxActorFlag{
pub type Enum = u32;
pub const eVISUALIZATION: Enum = 1u64 as u32;
pub const eDISABLE_GRAVITY: Enum = 2u64 as u32;
pub const eSEND_SLEEP_NOTIFIES: Enum = 4u64 as u32;
pub const eDISABLE_SIMULATION: Enum = 8u64 as u32;
}
pub mod PxActorType{
pub type Enum = u32;
pub const eRIGID_STATIC: Enum = 0u64 as u32;
pub const eRIGID_DYNAMIC: Enum = 1u64 as u32;
pub const eARTICULATION_LINK: Enum = 2u64 as u32;
pub const eACTOR_COUNT: Enum = 3u64 as u32;
pub const eACTOR_FORCE_DWORD: Enum = 2147483647u64 as u32;
}
pub mod PxActorTypeFlag{
pub type Enum = u32;
pub const eRIGID_STATIC: Enum = 1u64 as u32;
pub const eRIGID_DYNAMIC: Enum = 2u64 as u32;
}
pub mod PxArticulationAxis{
pub type Enum = u32;
pub const eTWIST: Enum = 0u64 as u32;
pub const eSWING1: Enum = 1u64 as u32;
pub const eSWING2: Enum = 2u64 as u32;
pub const eX: Enum = 3u64 as u32;
pub const eY: Enum = 4u64 as u32;
pub const eZ: Enum = 5u64 as u32;
pub const eCOUNT: Enum = 6u64 as u32;
}
pub mod PxArticulationCacheEnum{
pub type Enum = u32;
pub const eVELOCITY: Enum = 1u64 as u32;
pub const eACCELERATION: Enum = 2u64 as u32;
pub const ePOSITION: Enum = 4u64 as u32;
pub const eFORCE: Enum = 8u64 as u32;
pub const eLINKVELOCITY: Enum = 16u64 as u32;
pub const eLINKACCELERATION: Enum = 32u64 as u32;
pub const eROOT: Enum = 64u64 as u32;
pub const eALL: Enum = 119u64 as u32;
}
pub mod PxArticulationDriveType{
pub type Enum = u32;
pub const eFORCE: Enum = 0u64 as u32;
pub const eACCELERATION: Enum = 1u64 as u32;
pub const eTARGET: Enum = 2u64 as u32;
pub const eVELOCITY: Enum = 3u64 as u32;
pub const eNONE: Enum = 4u64 as u32;
}
pub mod PxArticulationFlag{
pub type Enum = u32;
pub const eFIX_BASE: Enum = 1u64 as u32;
pub const eDRIVE_LIMITS_ARE_FORCES: Enum = 2u64 as u32;
}
pub mod PxArticulationJointDriveType{
pub type Enum = u32;
pub const eTARGET: Enum = 0u64 as u32;
pub const eERROR: Enum = 1u64 as u32;
}
pub mod PxArticulationJointType{
pub type Enum = u32;
pub const ePRISMATIC: Enum = 0u64 as u32;
pub const eREVOLUTE: Enum = 1u64 as u32;
pub const eSPHERICAL: Enum = 2u64 as u32;
pub const eFIX: Enum = 3u64 as u32;
pub const eUNDEFINED: Enum = 4u64 as u32;
}
pub mod PxArticulationMotion{
pub type Enum = u32;
pub const eLOCKED: Enum = 0u64 as u32;
pub const eLIMITED: Enum = 1u64 as u32;
pub const eFREE: Enum = 2u64 as u32;
}
pub mod PxBaseFlag{
pub type Enum = u32;
pub const eOWNS_MEMORY: Enum = 1u64 as u32;
pub const eIS_RELEASABLE: Enum = 2u64 as u32;
}
pub mod PxBatchQueryStatus{
pub type Enum = u32;
pub const ePENDING: Enum = 0u64 as u32;
pub const eSUCCESS: Enum = 1u64 as u32;
pub const eOVERFLOW: Enum = 2u64 as u32;
}
pub mod PxBroadPhaseType{
pub type Enum = u32;
pub const eSAP: Enum = 0u64 as u32;
pub const eMBP: Enum = 1u64 as u32;
pub const eABP: Enum = 2u64 as u32;
pub const eGPU: Enum = 3u64 as u32;
pub const eLAST: Enum = 4u64 as u32;
}
pub mod PxCapsuleClimbingMode{
pub type Enum = u32;
pub const eEASY: Enum = 0u64 as u32;
pub const eCONSTRAINED: Enum = 1u64 as u32;
pub const eLAST: Enum = 2u64 as u32;
}
pub mod PxCombineMode{
pub type Enum = u32;
pub const eAVERAGE: Enum = 0u64 as u32;
pub const eMIN: Enum = 1u64 as u32;
pub const eMULTIPLY: Enum = 2u64 as u32;
pub const eMAX: Enum = 3u64 as u32;
pub const eN_VALUES: Enum = 4u64 as u32;
pub const ePAD_32: Enum = 2147483647u64 as u32;
}
pub mod PxConcreteType{
pub type Enum = u32;
pub const eUNDEFINED: Enum = 0u64 as u32;
pub const eHEIGHTFIELD: Enum = 1u64 as u32;
pub const eCONVEX_MESH: Enum = 2u64 as u32;
pub const eTRIANGLE_MESH_BVH33: Enum = 3u64 as u32;
pub const eTRIANGLE_MESH_BVH34: Enum = 4u64 as u32;
pub const eRIGID_DYNAMIC: Enum = 5u64 as u32;
pub const eRIGID_STATIC: Enum = 6u64 as u32;
pub const eSHAPE: Enum = 7u64 as u32;
pub const eMATERIAL: Enum = 8u64 as u32;
pub const eCONSTRAINT: Enum = 9u64 as u32;
pub const eAGGREGATE: Enum = 10u64 as u32;
pub const eARTICULATION: Enum = 11u64 as u32;
pub const eARTICULATION_REDUCED_COORDINATE: Enum = 12u64 as u32;
pub const eARTICULATION_LINK: Enum = 13u64 as u32;
pub const eARTICULATION_JOINT: Enum = 14u64 as u32;
pub const eARTICULATION_JOINT_REDUCED_COORDINATE: Enum = 15u64 as u32;
pub const ePRUNING_STRUCTURE: Enum = 16u64 as u32;
pub const eBVH_STRUCTURE: Enum = 17u64 as u32;
pub const ePHYSX_CORE_COUNT: Enum = 18u64 as u32;
pub const eFIRST_PHYSX_EXTENSION: Enum = 256u64 as u32;
pub const eFIRST_VEHICLE_EXTENSION: Enum = 512u64 as u32;
pub const eFIRST_USER_EXTENSION: Enum = 1024u64 as u32;
}
pub mod PxConstraintExtIDs{
pub type Enum = u32;
pub const eJOINT: Enum = 0u64 as u32;
pub const eVEHICLE_SUSP_LIMIT: Enum = 1u64 as u32;
pub const eVEHICLE_STICKY_TYRE: Enum = 2u64 as u32;
pub const eNEXT_FREE_ID: Enum = 3u64 as u32;
pub const eINVALID_ID: Enum = 2147483647u64 as u32;
}
pub mod PxConstraintFlag{
pub type Enum = u32;
pub const eBROKEN: Enum = 1u64 as u32;
pub const ePROJECT_TO_ACTOR0: Enum = 2u64 as u32;
pub const ePROJECT_TO_ACTOR1: Enum = 4u64 as u32;
pub const ePROJECTION: Enum = 6u64 as u32;
pub const eCOLLISION_ENABLED: Enum = 8u64 as u32;
pub const eVISUALIZATION: Enum = 16u64 as u32;
pub const eDRIVE_LIMITS_ARE_FORCES: Enum = 32u64 as u32;
pub const eIMPROVED_SLERP: Enum = 128u64 as u32;
pub const eDISABLE_PREPROCESSING: Enum = 256u64 as u32;
pub const eENABLE_EXTENDED_LIMITS: Enum = 512u64 as u32;
pub const eGPU_COMPATIBLE: Enum = 1024u64 as u32;
}
pub mod PxConstraintSolveHint{
pub type Enum = u32;
pub const eNONE: Enum = 0u64 as u32;
pub const eACCELERATION1: Enum = 256u64 as u32;
pub const eSLERP_SPRING: Enum = 258u64 as u32;
pub const eACCELERATION2: Enum = 512u64 as u32;
pub const eACCELERATION3: Enum = 768u64 as u32;
pub const eROTATIONAL_EQUALITY: Enum = 1024u64 as u32;
pub const eROTATIONAL_INEQUALITY: Enum = 1025u64 as u32;
pub const eEQUALITY: Enum = 2048u64 as u32;
pub const eINEQUALITY: Enum = 2049u64 as u32;
}
pub mod PxConstraintVisualizationFlag{
pub type Enum = u32;
pub const eLOCAL_FRAMES: Enum = 1u64 as u32;
pub const eLIMITS: Enum = 2u64 as u32;
}
pub mod PxContactPairExtraDataType{
pub type Enum = u32;
pub const ePRE_SOLVER_VELOCITY: Enum = 0u64 as u32;
pub const ePOST_SOLVER_VELOCITY: Enum = 1u64 as u32;
pub const eCONTACT_EVENT_POSE: Enum = 2u64 as u32;
pub const eCONTACT_PAIR_INDEX: Enum = 3u64 as u32;
}
pub mod PxContactPairFlag{
pub type Enum = u32;
pub const eREMOVED_SHAPE_0: Enum = 1u64 as u32;
pub const eREMOVED_SHAPE_1: Enum = 2u64 as u32;
pub const eACTOR_PAIR_HAS_FIRST_TOUCH: Enum = 4u64 as u32;
pub const eACTOR_PAIR_LOST_TOUCH: Enum = 8u64 as u32;
pub const eINTERNAL_HAS_IMPULSES: Enum = 16u64 as u32;
pub const eINTERNAL_CONTACTS_ARE_FLIPPED: Enum = 32u64 as u32;
}
pub mod PxContactPairHeaderFlag{
pub type Enum = u32;
pub const eREMOVED_ACTOR_0: Enum = 1u64 as u32;
pub const eREMOVED_ACTOR_1: Enum = 2u64 as u32;
}
pub mod PxContactPatchEnum{
pub type PxContactPatchFlags = u32;
pub const eHAS_FACE_INDICES: PxContactPatchFlags = 1u64 as u32;
pub const eMODIFIABLE: PxContactPatchFlags = 2u64 as u32;
pub const eFORCE_NO_RESPONSE: PxContactPatchFlags = 4u64 as u32;
pub const eHAS_MODIFIED_MASS_RATIOS: PxContactPatchFlags = 8u64 as u32;
pub const eHAS_TARGET_VELOCITY: PxContactPatchFlags = 16u64 as u32;
pub const eHAS_MAX_IMPULSE: PxContactPatchFlags = 32u64 as u32;
pub const eREGENERATE_PATCHES: PxContactPatchFlags = 64u64 as u32;
pub const eCOMPRESSED_MODIFIED_CONTACT: PxContactPatchFlags = 128u64 as u32;
}
pub mod PxContactStreamIteratorEnum{
pub type StreamFormat = u32;
pub const eSIMPLE_STREAM: StreamFormat = 0u64 as u32;
pub const eMODIFIABLE_STREAM: StreamFormat = 1u64 as u32;
pub const eCOMPRESSED_MODIFIABLE_STREAM: StreamFormat = 2u64 as u32;
}
pub mod PxControllerBehaviorFlag{
pub type Enum = u32;
pub const eCCT_CAN_RIDE_ON_OBJECT: Enum = 1u64 as u32;
pub const eCCT_SLIDE: Enum = 2u64 as u32;
pub const eCCT_USER_DEFINED_RIDE: Enum = 4u64 as u32;
}
pub mod PxControllerCollisionFlag{
pub type Enum = u32;
pub const eCOLLISION_SIDES: Enum = 1u64 as u32;
pub const eCOLLISION_UP: Enum = 2u64 as u32;
pub const eCOLLISION_DOWN: Enum = 4u64 as u32;
}
pub mod PxControllerDebugRenderFlag{
pub type Enum = u32;
pub const eTEMPORAL_BV: Enum = 1u64 as u32;
pub const eCACHED_BV: Enum = 2u64 as u32;
pub const eOBSTACLES: Enum = 4u64 as u32;
pub const eNONE: Enum = 0u64 as u32;
pub const eALL: Enum = 4294967295u64 as u32;
}
pub mod PxControllerNonWalkableMode{
pub type Enum = u32;
pub const ePREVENT_CLIMBING: Enum = 0u64 as u32;
pub const ePREVENT_CLIMBING_AND_FORCE_SLIDING: Enum = 1u64 as u32;
}
pub mod PxControllerShapeType{
pub type Enum = u32;
pub const eBOX: Enum = 0u64 as u32;
pub const eCAPSULE: Enum = 1u64 as u32;
pub const eFORCE_DWORD: Enum = 2147483647u64 as u32;
}
pub mod PxConverterReportMode{
pub type Enum = u32;
pub const eNONE: Enum = 0u64 as u32;
pub const eNORMAL: Enum = 1u64 as u32;
pub const eVERBOSE: Enum = 2u64 as u32;
}
pub mod PxConvexFlag{
pub type Enum = u32;
pub const e16_BIT_INDICES: Enum = 1u64 as u32;
pub const eCOMPUTE_CONVEX: Enum = 2u64 as u32;
pub const eCHECK_ZERO_AREA_TRIANGLES: Enum = 4u64 as u32;
pub const eQUANTIZE_INPUT: Enum = 8u64 as u32;
pub const eDISABLE_MESH_VALIDATION: Enum = 16u64 as u32;
pub const ePLANE_SHIFTING: Enum = 32u64 as u32;
pub const eFAST_INERTIA_COMPUTATION: Enum = 64u64 as u32;
pub const eGPU_COMPATIBLE: Enum = 128u64 as u32;
pub const eSHIFT_VERTICES: Enum = 256u64 as u32;
}
pub mod PxConvexMeshCookingResult{
pub type Enum = u32;
pub const eSUCCESS: Enum = 0u64 as u32;
pub const eZERO_AREA_TEST_FAILED: Enum = 1u64 as u32;
pub const ePOLYGONS_LIMIT_REACHED: Enum = 2u64 as u32;
pub const eFAILURE: Enum = 3u64 as u32;
}
pub mod PxConvexMeshCookingType{
pub type Enum = u32;
pub const eQUICKHULL: Enum = 0u64 as u32;
}
pub mod PxConvexMeshGeometryFlag{
pub type Enum = u32;
pub const eTIGHT_BOUNDS: Enum = 1u64 as u32;
}
pub mod PxD6Axis{
pub type Enum = u32;
pub const eX: Enum = 0u64 as u32;
pub const eY: Enum = 1u64 as u32;
pub const eZ: Enum = 2u64 as u32;
pub const eTWIST: Enum = 3u64 as u32;
pub const eSWING1: Enum = 4u64 as u32;
pub const eSWING2: Enum = 5u64 as u32;
pub const eCOUNT: Enum = 6u64 as u32;
}
pub mod PxD6Drive{
pub type Enum = u32;
pub const eX: Enum = 0u64 as u32;
pub const eY: Enum = 1u64 as u32;
pub const eZ: Enum = 2u64 as u32;
pub const eSWING: Enum = 3u64 as u32;
pub const eTWIST: Enum = 4u64 as u32;
pub const eSLERP: Enum = 5u64 as u32;
pub const eCOUNT: Enum = 6u64 as u32;
}
pub mod PxD6JointDriveFlag{
pub type Enum = u32;
pub const eACCELERATION: Enum = 1u64 as u32;
}
pub mod PxD6Motion{
pub type Enum = u32;
pub const eLOCKED: Enum = 0u64 as u32;
pub const eLIMITED: Enum = 1u64 as u32;
pub const eFREE: Enum = 2u64 as u32;
}
pub mod PxDataAccessFlag{
pub type Enum = u32;
pub const eREADABLE: Enum = 1u64 as u32;
pub const eWRITABLE: Enum = 2u64 as u32;
pub const eDEVICE: Enum = 4u64 as u32;
}
pub mod PxDebugColor{
pub type Enum = u32;
pub const eARGB_BLACK: Enum = 4278190080u64 as u32;
pub const eARGB_RED: Enum = 4294901760u64 as u32;
pub const eARGB_GREEN: Enum = 4278255360u64 as u32;
pub const eARGB_BLUE: Enum = 4278190335u64 as u32;
pub const eARGB_YELLOW: Enum = 4294967040u64 as u32;
pub const eARGB_MAGENTA: Enum = 4294902015u64 as u32;
pub const eARGB_CYAN: Enum = 4278255615u64 as u32;
pub const eARGB_WHITE: Enum = 4294967295u64 as u32;
pub const eARGB_GREY: Enum = 4286611584u64 as u32;
pub const eARGB_DARKRED: Enum = 2290614272u64 as u32;
pub const eARGB_DARKGREEN: Enum = 2281736192u64 as u32;
pub const eARGB_DARKBLUE: Enum = 2281701512u64 as u32;
}
pub mod PxDeletionEventFlag{
pub type Enum = u32;
pub const eUSER_RELEASE: Enum = 1u64 as u32;
pub const eMEMORY_RELEASE: Enum = 2u64 as u32;
}
pub mod PxDistanceJointFlag{
pub type Enum = u32;
pub const eMAX_DISTANCE_ENABLED: Enum = 2u64 as u32;
pub const eMIN_DISTANCE_ENABLED: Enum = 4u64 as u32;
pub const eSPRING_ENABLED: Enum = 8u64 as u32;
}
pub type PxEMPTY = u32;
pub const PxEmpty: PxEMPTY = 0u64 as u32;
pub mod PxErrorCode{
pub type Enum = i32;
pub const eNO_ERROR: Enum = 0u64 as i32;
pub const eDEBUG_INFO: Enum = 1u64 as i32;
pub const eDEBUG_WARNING: Enum = 2u64 as i32;
pub const eINVALID_PARAMETER: Enum = 4u64 as i32;
pub const eINVALID_OPERATION: Enum = 8u64 as i32;
pub const eOUT_OF_MEMORY: Enum = 16u64 as i32;
pub const eINTERNAL_ERROR: Enum = 32u64 as i32;
pub const eABORT: Enum = 64u64 as i32;
pub const ePERF_WARNING: Enum = 128u64 as i32;
pub const eMASK_ALL: Enum = 4294967295u64 as i32;
}
pub mod PxFilterFlag{
pub type Enum = u32;
pub const eKILL: Enum = 1u64 as u32;
pub const eSUPPRESS: Enum = 2u64 as u32;
pub const eCALLBACK: Enum = 4u64 as u32;
pub const eNOTIFY: Enum = 12u64 as u32;
pub const eDEFAULT: Enum = 0u64 as u32;
}
pub mod PxFilterObjectFlag{
pub type Enum = u32;
pub const eKINEMATIC: Enum = 16u64 as u32;
pub const eTRIGGER: Enum = 32u64 as u32;
}
pub mod PxFilterObjectType{
pub type Enum = u32;
pub const eRIGID_STATIC: Enum = 0u64 as u32;
pub const eRIGID_DYNAMIC: Enum = 1u64 as u32;
pub const eARTICULATION: Enum = 2u64 as u32;
pub const eMAX_TYPE_COUNT: Enum = 16u64 as u32;
pub const eUNDEFINED: Enum = 15u64 as u32;
}
pub mod PxFilterOp{
pub type Enum = u32;
pub const PX_FILTEROP_AND: Enum = 0u64 as u32;
pub const PX_FILTEROP_OR: Enum = 1u64 as u32;
pub const PX_FILTEROP_XOR: Enum = 2u64 as u32;
pub const PX_FILTEROP_NAND: Enum = 3u64 as u32;
pub const PX_FILTEROP_NOR: Enum = 4u64 as u32;
pub const PX_FILTEROP_NXOR: Enum = 5u64 as u32;
pub const PX_FILTEROP_SWAP_AND: Enum = 6u64 as u32;
}
pub mod PxForceMode{
pub type Enum = u32;
pub const eFORCE: Enum = 0u64 as u32;
pub const eIMPULSE: Enum = 1u64 as u32;
pub const eVELOCITY_CHANGE: Enum = 2u64 as u32;
pub const eACCELERATION: Enum = 3u64 as u32;
}
pub mod PxFrictionType{
pub type Enum = u32;
pub const ePATCH: Enum = 0u64 as u32;
pub const eONE_DIRECTIONAL: Enum = 1u64 as u32;
pub const eTWO_DIRECTIONAL: Enum = 2u64 as u32;
pub const eFRICTION_COUNT: Enum = 3u64 as u32;
}
pub mod PxGeometryType{
pub type Enum = i32;
pub const eSPHERE: Enum = 0u64 as i32;
pub const ePLANE: Enum = 1u64 as i32;
pub const eCAPSULE: Enum = 2u64 as i32;
pub const eBOX: Enum = 3u64 as i32;
pub const eCONVEXMESH: Enum = 4u64 as i32;
pub const eTRIANGLEMESH: Enum = 5u64 as i32;
pub const eHEIGHTFIELD: Enum = 6u64 as i32;
pub const eGEOMETRY_COUNT: Enum = 7u64 as i32;
pub const eINVALID: Enum = 4294967295u64 as i32;
}
pub mod PxHeightFieldFlag{
pub type Enum = u32;
pub const eNO_BOUNDARY_EDGES: Enum = 1u64 as u32;
}
pub mod PxHeightFieldFormat{
pub type Enum = u32;
pub const eS16_TM: Enum = 1u64 as u32;
}
pub mod PxHeightFieldMaterial{
pub type Enum = u32;
pub const eHOLE: Enum = 127u64 as u32;
}
pub mod PxHeightFieldTessFlag{
pub type Enum = u32;
pub const e0TH_VERTEX_SHARED: Enum = 1u64 as u32;
}
pub mod PxHitFlag{
pub type Enum = u32;
pub const ePOSITION: Enum = 1u64 as u32;
pub const eNORMAL: Enum = 2u64 as u32;
pub const eUV: Enum = 8u64 as u32;
pub const eASSUME_NO_INITIAL_OVERLAP: Enum = 16u64 as u32;
pub const eMESH_MULTIPLE: Enum = 32u64 as u32;
pub const eMESH_ANY: Enum = 64u64 as u32;
pub const eMESH_BOTH_SIDES: Enum = 128u64 as u32;
pub const ePRECISE_SWEEP: Enum = 256u64 as u32;
pub const eMTD: Enum = 512u64 as u32;
pub const eFACE_INDEX: Enum = 1024u64 as u32;
pub const eDEFAULT: Enum = 1027u64 as u32;
pub const eMODIFIABLE_FLAGS: Enum = 432u64 as u32;
}
pub type PxIDENTITY = u32;
pub const PxIdentity: PxIDENTITY = 0u64 as u32;
pub mod PxJointActorIndex{
pub type Enum = u32;
pub const eACTOR0: Enum = 0u64 as u32;
pub const eACTOR1: Enum = 1u64 as u32;
pub const COUNT: Enum = 2u64 as u32;
}
pub mod PxJointConcreteType{
pub type Enum = u32;
pub const eSPHERICAL: Enum = 256u64 as u32;
pub const eREVOLUTE: Enum = 257u64 as u32;
pub const ePRISMATIC: Enum = 258u64 as u32;
pub const eFIXED: Enum = 259u64 as u32;
pub const eDISTANCE: Enum = 260u64 as u32;
pub const eD6: Enum = 261u64 as u32;
pub const eCONTACT: Enum = 262u64 as u32;
pub const eLast: Enum = 263u64 as u32;
}
pub mod PxMaterialFlag{
pub type Enum = u32;
pub const eDISABLE_FRICTION: Enum = 1u64 as u32;
pub const eDISABLE_STRONG_FRICTION: Enum = 2u64 as u32;
pub const eIMPROVED_PATCH_FRICTION: Enum = 4u64 as u32;
}
pub mod PxMeshCookingHint{
pub type Enum = u32;
pub const eSIM_PERFORMANCE: Enum = 0u64 as u32;
pub const eCOOKING_PERFORMANCE: Enum = 1u64 as u32;
}
pub mod PxMeshFlag{
pub type Enum = u32;
pub const eFLIPNORMALS: Enum = 1u64 as u32;
pub const e16_BIT_INDICES: Enum = 2u64 as u32;
}
pub mod PxMeshGeometryFlag{
pub type Enum = u32;
pub const eDOUBLE_SIDED: Enum = 2u64 as u32;
}
pub mod PxMeshMidPhase{
pub type Enum = u32;
pub const eBVH33: Enum = 0u64 as u32;
pub const eBVH34: Enum = 1u64 as u32;
pub const eLAST: Enum = 2u64 as u32;
}
pub mod PxMeshPreprocessingFlag{
pub type Enum = u32;
pub const eWELD_VERTICES: Enum = 1u64 as u32;
pub const eDISABLE_CLEAN_MESH: Enum = 2u64 as u32;
pub const eDISABLE_ACTIVE_EDGES_PRECOMPUTE: Enum = 4u64 as u32;
pub const eFORCE_32BIT_INDICES: Enum = 8u64 as u32;
}
pub mod PxMetaDataFlag{
pub type Enum = u32;
pub const eCLASS: Enum = 1u64 as u32;
pub const eVIRTUAL: Enum = 2u64 as u32;
pub const eTYPEDEF: Enum = 4u64 as u32;
pub const ePTR: Enum = 8u64 as u32;
pub const eHANDLE: Enum = 16u64 as u32;
pub const eEXTRA_DATA: Enum = 32u64 as u32;
pub const eEXTRA_ITEM: Enum = 64u64 as u32;
pub const eEXTRA_ITEMS: Enum = 128u64 as u32;
pub const eEXTRA_NAME: Enum = 256u64 as u32;
pub const eUNION: Enum = 512u64 as u32;
pub const ePADDING: Enum = 1024u64 as u32;
pub const eALIGNMENT: Enum = 2048u64 as u32;
pub const eCOUNT_MASK_MSB: Enum = 4096u64 as u32;
pub const eCOUNT_SKIP_IF_ONE: Enum = 8192u64 as u32;
pub const eCONTROL_FLIP: Enum = 16384u64 as u32;
pub const eCONTROL_MASK: Enum = 32768u64 as u32;
pub const eCONTROL_MASK_RANGE: Enum = 255u64 as u32;
pub const eFORCE_DWORD: Enum = 2147483647u64 as u32;
}
pub mod PxPairFilteringMode{
pub type Enum = u32;
pub const eKEEP: Enum = 0u64 as u32;
pub const eSUPPRESS: Enum = 1u64 as u32;
pub const eKILL: Enum = 2u64 as u32;
pub const eDEFAULT: Enum = 1u64 as u32;
}
pub mod PxPairFlag{
pub type Enum = u32;
pub const eSOLVE_CONTACT: Enum = 1u64 as u32;
pub const eMODIFY_CONTACTS: Enum = 2u64 as u32;
pub const eNOTIFY_TOUCH_FOUND: Enum = 4u64 as u32;
pub const eNOTIFY_TOUCH_PERSISTS: Enum = 8u64 as u32;
pub const eNOTIFY_TOUCH_LOST: Enum = 16u64 as u32;
pub const eNOTIFY_TOUCH_CCD: Enum = 32u64 as u32;
pub const eNOTIFY_THRESHOLD_FORCE_FOUND: Enum = 64u64 as u32;
pub const eNOTIFY_THRESHOLD_FORCE_PERSISTS: Enum = 128u64 as u32;
pub const eNOTIFY_THRESHOLD_FORCE_LOST: Enum = 256u64 as u32;
pub const eNOTIFY_CONTACT_POINTS: Enum = 512u64 as u32;
pub const eDETECT_DISCRETE_CONTACT: Enum = 1024u64 as u32;
pub const eDETECT_CCD_CONTACT: Enum = 2048u64 as u32;
pub const ePRE_SOLVER_VELOCITY: Enum = 4096u64 as u32;
pub const ePOST_SOLVER_VELOCITY: Enum = 8192u64 as u32;
pub const eCONTACT_EVENT_POSE: Enum = 16384u64 as u32;
pub const eNEXT_FREE: Enum = 32768u64 as u32;
pub const eCONTACT_DEFAULT: Enum = 1025u64 as u32;
pub const eTRIGGER_DEFAULT: Enum = 1044u64 as u32;
}
pub mod PxPrismaticJointFlag{
pub type Enum = u32;
pub const eLIMIT_ENABLED: Enum = 2u64 as u32;
}
pub mod PxPruningStructureType{
pub type Enum = u32;
pub const eNONE: Enum = 0u64 as u32;
pub const eDYNAMIC_AABB_TREE: Enum = 1u64 as u32;
pub const eSTATIC_AABB_TREE: Enum = 2u64 as u32;
pub const eLAST: Enum = 3u64 as u32;
}
pub mod PxPvdInstrumentationFlag{
pub type Enum = u32;
pub const eDEBUG: Enum = 1u64 as u32;
pub const ePROFILE: Enum = 2u64 as u32;
pub const eMEMORY: Enum = 4u64 as u32;
pub const eALL: Enum = 7u64 as u32;
}
pub mod PxPvdSceneFlag{
pub type Enum = u32;
pub const eTRANSMIT_CONTACTS: Enum = 1u64 as u32;
pub const eTRANSMIT_SCENEQUERIES: Enum = 2u64 as u32;
pub const eTRANSMIT_CONSTRAINTS: Enum = 4u64 as u32;
}
pub mod PxPvdUpdateType{
pub type Enum = u32;
pub const CREATE_INSTANCE: Enum = 0u64 as u32;
pub const RELEASE_INSTANCE: Enum = 1u64 as u32;
pub const UPDATE_ALL_PROPERTIES: Enum = 2u64 as u32;
pub const UPDATE_SIM_PROPERTIES: Enum = 3u64 as u32;
}
pub mod PxQueryFlag{
pub type Enum = u32;
pub const eSTATIC: Enum = 1u64 as u32;
pub const eDYNAMIC: Enum = 2u64 as u32;
pub const ePREFILTER: Enum = 4u64 as u32;
pub const ePOSTFILTER: Enum = 8u64 as u32;
pub const eANY_HIT: Enum = 16u64 as u32;
pub const eNO_BLOCK: Enum = 32u64 as u32;
pub const eRESERVED: Enum = 32768u64 as u32;
}
pub mod PxQueryHitType{
pub type Enum = u32;
pub const eNONE: Enum = 0u64 as u32;
pub const eTOUCH: Enum = 1u64 as u32;
pub const eBLOCK: Enum = 2u64 as u32;
}
pub mod PxRevoluteJointFlag{
pub type Enum = u32;
pub const eLIMIT_ENABLED: Enum = 1u64 as u32;
pub const eDRIVE_ENABLED: Enum = 2u64 as u32;
pub const eDRIVE_FREESPIN: Enum = 4u64 as u32;
}
pub mod PxRigidBodyFlag{
pub type Enum = u32;
pub const eKINEMATIC: Enum = 1u64 as u32;
pub const eUSE_KINEMATIC_TARGET_FOR_SCENE_QUERIES: Enum = 2u64 as u32;
pub const eENABLE_CCD: Enum = 4u64 as u32;
pub const eENABLE_CCD_FRICTION: Enum = 8u64 as u32;
pub const eENABLE_POSE_INTEGRATION_PREVIEW: Enum = 16u64 as u32;
pub const eENABLE_SPECULATIVE_CCD: Enum = 32u64 as u32;
pub const eENABLE_CCD_MAX_CONTACT_IMPULSE: Enum = 64u64 as u32;
pub const eRETAIN_ACCELERATIONS: Enum = 128u64 as u32;
}
pub mod PxRigidDynamicLockFlag{
pub type Enum = u32;
pub const eLOCK_LINEAR_X: Enum = 1u64 as u32;
pub const eLOCK_LINEAR_Y: Enum = 2u64 as u32;
pub const eLOCK_LINEAR_Z: Enum = 4u64 as u32;
pub const eLOCK_ANGULAR_X: Enum = 8u64 as u32;
pub const eLOCK_ANGULAR_Y: Enum = 16u64 as u32;
pub const eLOCK_ANGULAR_Z: Enum = 32u64 as u32;
}
pub mod PxSceneFlag{
pub type Enum = u32;
pub const eENABLE_ACTIVE_ACTORS: Enum = 1u64 as u32;
pub const eENABLE_CCD: Enum = 2u64 as u32;
pub const eDISABLE_CCD_RESWEEP: Enum = 4u64 as u32;
pub const eADAPTIVE_FORCE: Enum = 8u64 as u32;
pub const eENABLE_PCM: Enum = 64u64 as u32;
pub const eDISABLE_CONTACT_REPORT_BUFFER_RESIZE: Enum = 128u64 as u32;
pub const eDISABLE_CONTACT_CACHE: Enum = 256u64 as u32;
pub const eREQUIRE_RW_LOCK: Enum = 512u64 as u32;
pub const eENABLE_STABILIZATION: Enum = 1024u64 as u32;
pub const eENABLE_AVERAGE_POINT: Enum = 2048u64 as u32;
pub const eEXCLUDE_KINEMATICS_FROM_ACTIVE_ACTORS: Enum = 4096u64 as u32;
pub const eENABLE_GPU_DYNAMICS: Enum = 8192u64 as u32;
pub const eENABLE_ENHANCED_DETERMINISM: Enum = 16384u64 as u32;
pub const eENABLE_FRICTION_EVERY_ITERATION: Enum = 32768u64 as u32;
pub const eMUTABLE_FLAGS: Enum = 4097u64 as u32;
}
pub mod PxSceneQueryUpdateMode{
pub type Enum = u32;
pub const eBUILD_ENABLED_COMMIT_ENABLED: Enum = 0u64 as u32;
pub const eBUILD_ENABLED_COMMIT_DISABLED: Enum = 1u64 as u32;
pub const eBUILD_DISABLED_COMMIT_DISABLED: Enum = 2u64 as u32;
}
pub mod PxShapeFlag{
pub type Enum = u32;
pub const eSIMULATION_SHAPE: Enum = 1u64 as u32;
pub const eSCENE_QUERY_SHAPE: Enum = 2u64 as u32;
pub const eTRIGGER_SHAPE: Enum = 4u64 as u32;
pub const eVISUALIZATION: Enum = 8u64 as u32;
}
pub mod PxSimulationStatisticsEnum{
pub type RbPairStatsType = u32;
pub const eDISCRETE_CONTACT_PAIRS: RbPairStatsType = 0u64 as u32;
pub const eCCD_PAIRS: RbPairStatsType = 1u64 as u32;
pub const eMODIFIED_CONTACT_PAIRS: RbPairStatsType = 2u64 as u32;
pub const eTRIGGER_PAIRS: RbPairStatsType = 3u64 as u32;
}
pub mod PxSolverConstraintDescEnum{
pub type ConstraintType = u32;
pub const eCONTACT_CONSTRAINT: ConstraintType = 0u64 as u32;
pub const eJOINT_CONSTRAINT: ConstraintType = 1u64 as u32;
}
pub mod PxSolverConstraintPrepDescBaseEnum{
pub type BodyState = u32;
pub const eDYNAMIC_BODY: BodyState = 1u64 as u32;
pub const eSTATIC_BODY: BodyState = 2u64 as u32;
pub const eKINEMATIC_BODY: BodyState = 4u64 as u32;
pub const eARTICULATION: BodyState = 8u64 as u32;
}
pub mod PxSolverType{
pub type Enum = u32;
pub const ePGS: Enum = 0u64 as u32;
pub const eTGS: Enum = 1u64 as u32;
}
pub mod PxSphericalJointFlag{
pub type Enum = u32;
pub const eLIMIT_ENABLED: Enum = 2u64 as u32;
}
pub mod PxTaskType{
pub type Enum = u32;
pub const TT_CPU: Enum = 0u64 as u32;
pub const TT_NOT_PRESENT: Enum = 1u64 as u32;
pub const TT_COMPLETED: Enum = 2u64 as u32;
}
pub mod PxTriangleMeshCookingResult{
pub type Enum = u32;
pub const eSUCCESS: Enum = 0u64 as u32;
pub const eLARGE_TRIANGLE: Enum = 1u64 as u32;
pub const eFAILURE: Enum = 2u64 as u32;
}
pub mod PxTriangleMeshFlag{
pub type Enum = u32;
pub const e16_BIT_INDICES: Enum = 2u64 as u32;
pub const eADJACENCY_INFO: Enum = 4u64 as u32;
}
pub mod PxTriggerPairFlag{
pub type Enum = u32;
pub const eREMOVED_SHAPE_TRIGGER: Enum = 1u64 as u32;
pub const eREMOVED_SHAPE_OTHER: Enum = 2u64 as u32;
pub const eNEXT_FREE: Enum = 4u64 as u32;
}
pub mod PxVehicleClutchAccuracyMode{
pub type Enum = u32;
pub const eESTIMATE: Enum = 0u64 as u32;
pub const eBEST_POSSIBLE: Enum = 1u64 as u32;
}
pub mod PxVehicleConcreteType{
pub type Enum = u32;
pub const eVehicleNoDrive: Enum = 512u64 as u32;
pub const eVehicleDrive4W: Enum = 513u64 as u32;
pub const eVehicleDriveNW: Enum = 514u64 as u32;
pub const eVehicleDriveTank: Enum = 515u64 as u32;
}
pub mod PxVehicleDifferential4WDataEnum{
pub type Enum = u32;
pub const eDIFF_TYPE_LS_4WD: Enum = 0u64 as u32;
pub const eDIFF_TYPE_LS_FRONTWD: Enum = 1u64 as u32;
pub const eDIFF_TYPE_LS_REARWD: Enum = 2u64 as u32;
pub const eDIFF_TYPE_OPEN_4WD: Enum = 3u64 as u32;
pub const eDIFF_TYPE_OPEN_FRONTWD: Enum = 4u64 as u32;
pub const eDIFF_TYPE_OPEN_REARWD: Enum = 5u64 as u32;
pub const eMAX_NB_DIFF_TYPES: Enum = 6u64 as u32;
}
pub mod PxVehicleDrive4WControl{
pub type Enum = u32;
pub const eANALOG_INPUT_ACCEL: Enum = 0u64 as u32;
pub const eANALOG_INPUT_BRAKE: Enum = 1u64 as u32;
pub const eANALOG_INPUT_HANDBRAKE: Enum = 2u64 as u32;
pub const eANALOG_INPUT_STEER_LEFT: Enum = 3u64 as u32;
pub const eANALOG_INPUT_STEER_RIGHT: Enum = 4u64 as u32;
pub const eMAX_NB_DRIVE4W_ANALOG_INPUTS: Enum = 5u64 as u32;
}
pub mod PxVehicleDrive4WWheelOrder{
pub type Enum = u32;
pub const eFRONT_LEFT: Enum = 0u64 as u32;
pub const eFRONT_RIGHT: Enum = 1u64 as u32;
pub const eREAR_LEFT: Enum = 2u64 as u32;
pub const eREAR_RIGHT: Enum = 3u64 as u32;
}
pub mod PxVehicleDriveGraphChannel{
pub type Enum = u32;
pub const eENGINE_REVS: Enum = 0u64 as u32;
pub const eENGINE_DRIVE_TORQUE: Enum = 1u64 as u32;
pub const eCLUTCH_SLIP: Enum = 2u64 as u32;
pub const eACCEL_CONTROL: Enum = 3u64 as u32;
pub const eBRAKE_CONTROL: Enum = 4u64 as u32;
pub const eHANDBRAKE_CONTROL: Enum = 5u64 as u32;
pub const eSTEER_LEFT_CONTROL: Enum = 6u64 as u32;
pub const eSTEER_RIGHT_CONTROL: Enum = 7u64 as u32;
pub const eGEAR_RATIO: Enum = 8u64 as u32;
pub const eMAX_NB_DRIVE_CHANNELS: Enum = 9u64 as u32;
}
pub mod PxVehicleDriveNWControl{
pub type Enum = u32;
pub const eANALOG_INPUT_ACCEL: Enum = 0u64 as u32;
pub const eANALOG_INPUT_BRAKE: Enum = 1u64 as u32;
pub const eANALOG_INPUT_HANDBRAKE: Enum = 2u64 as u32;
pub const eANALOG_INPUT_STEER_LEFT: Enum = 3u64 as u32;
pub const eANALOG_INPUT_STEER_RIGHT: Enum = 4u64 as u32;
pub const eMAX_NB_DRIVENW_ANALOG_INPUTS: Enum = 5u64 as u32;
}
pub mod PxVehicleDriveTankControl{
pub type Enum = u32;
pub const eANALOG_INPUT_ACCEL: Enum = 0u64 as u32;
pub const eANALOG_INPUT_BRAKE_LEFT: Enum = 1u64 as u32;
pub const eANALOG_INPUT_BRAKE_RIGHT: Enum = 2u64 as u32;
pub const eANALOG_INPUT_THRUST_LEFT: Enum = 3u64 as u32;
pub const eANALOG_INPUT_THRUST_RIGHT: Enum = 4u64 as u32;
pub const eMAX_NB_DRIVETANK_ANALOG_INPUTS: Enum = 5u64 as u32;
}
pub mod PxVehicleDriveTankControlModel{
pub type Enum = u32;
pub const eSTANDARD: Enum = 0u64 as u32;
pub const eSPECIAL: Enum = 1u64 as u32;
}
pub mod PxVehicleDriveTankWheelOrder{
pub type Enum = u32;
pub const eFRONT_LEFT: Enum = 0u64 as u32;
pub const eFRONT_RIGHT: Enum = 1u64 as u32;
pub const e1ST_FROM_FRONT_LEFT: Enum = 2u64 as u32;
pub const e1ST_FROM_FRONT_RIGHT: Enum = 3u64 as u32;
pub const e2ND_FROM_FRONT_LEFT: Enum = 4u64 as u32;
pub const e2ND_FROM_FRONT_RIGHT: Enum = 5u64 as u32;
pub const e3RD_FROM_FRONT_LEFT: Enum = 6u64 as u32;
pub const e3RD_FROM_FRONT_RIGHT: Enum = 7u64 as u32;
pub const e4TH_FROM_FRONT_LEFT: Enum = 8u64 as u32;
pub const e4TH_FROM_FRONT_RIGHT: Enum = 9u64 as u32;
pub const e5TH_FROM_FRONT_LEFT: Enum = 10u64 as u32;
pub const e5TH_FROM_FRONT_RIGHT: Enum = 11u64 as u32;
pub const e6TH_FROM_FRONT_LEFT: Enum = 12u64 as u32;
pub const e6TH_FROM_FRONT_RIGHT: Enum = 13u64 as u32;
pub const e7TH_FROM_FRONT_LEFT: Enum = 14u64 as u32;
pub const e7TH_FROM_FRONT_RIGHT: Enum = 15u64 as u32;
pub const e8TH_FROM_FRONT_LEFT: Enum = 16u64 as u32;
pub const e8TH_FROM_FRONT_RIGHT: Enum = 17u64 as u32;
pub const e9TH_FROM_FRONT_LEFT: Enum = 18u64 as u32;
pub const e9TH_FROM_FRONT_RIGHT: Enum = 19u64 as u32;
}
pub mod PxVehicleGearsDataEnum{
pub type Enum = u32;
pub const eREVERSE: Enum = 0u64 as u32;
pub const eNEUTRAL: Enum = 1u64 as u32;
pub const eFIRST: Enum = 2u64 as u32;
pub const eSECOND: Enum = 3u64 as u32;
pub const eTHIRD: Enum = 4u64 as u32;
pub const eFOURTH: Enum = 5u64 as u32;
pub const eFIFTH: Enum = 6u64 as u32;
pub const eSIXTH: Enum = 7u64 as u32;
pub const eSEVENTH: Enum = 8u64 as u32;
pub const eEIGHTH: Enum = 9u64 as u32;
pub const eNINTH: Enum = 10u64 as u32;
pub const eTENTH: Enum = 11u64 as u32;
pub const eELEVENTH: Enum = 12u64 as u32;
pub const eTWELFTH: Enum = 13u64 as u32;
pub const eTHIRTEENTH: Enum = 14u64 as u32;
pub const eFOURTEENTH: Enum = 15u64 as u32;
pub const eFIFTEENTH: Enum = 16u64 as u32;
pub const eSIXTEENTH: Enum = 17u64 as u32;
pub const eSEVENTEENTH: Enum = 18u64 as u32;
pub const eEIGHTEENTH: Enum = 19u64 as u32;
pub const eNINETEENTH: Enum = 20u64 as u32;
pub const eTWENTIETH: Enum = 21u64 as u32;
pub const eTWENTYFIRST: Enum = 22u64 as u32;
pub const eTWENTYSECOND: Enum = 23u64 as u32;
pub const eTWENTYTHIRD: Enum = 24u64 as u32;
pub const eTWENTYFOURTH: Enum = 25u64 as u32;
pub const eTWENTYFIFTH: Enum = 26u64 as u32;
pub const eTWENTYSIXTH: Enum = 27u64 as u32;
pub const eTWENTYSEVENTH: Enum = 28u64 as u32;
pub const eTWENTYEIGHTH: Enum = 29u64 as u32;
pub const eTWENTYNINTH: Enum = 30u64 as u32;
pub const eTHIRTIETH: Enum = 31u64 as u32;
pub const eGEARSRATIO_COUNT: Enum = 32u64 as u32;
}
pub mod PxVehicleGraphType{
pub type Enum = u32;
pub const eWHEEL: Enum = 0u64 as u32;
pub const eDRIVE: Enum = 1u64 as u32;
}
pub mod PxVehicleTypes{
pub type Enum = u32;
pub const eDRIVE4W: Enum = 0u64 as u32;
pub const eDRIVENW: Enum = 1u64 as u32;
pub const eDRIVETANK: Enum = 2u64 as u32;
pub const eNODRIVE: Enum = 3u64 as u32;
pub const eUSER1: Enum = 4u64 as u32;
pub const eUSER2: Enum = 5u64 as u32;
pub const eUSER3: Enum = 6u64 as u32;
pub const eMAX_NB_VEHICLE_TYPES: Enum = 7u64 as u32;
}
pub mod PxVehicleUpdateMode{
pub type Enum = u32;
pub const eVELOCITY_CHANGE: Enum = 0u64 as u32;
pub const eACCELERATION: Enum = 1u64 as u32;
}
pub mod PxVehicleWheelGraphChannel{
pub type Enum = u32;
pub const eJOUNCE: Enum = 0u64 as u32;
pub const eSUSPFORCE: Enum = 1u64 as u32;
pub const eTIRELOAD: Enum = 2u64 as u32;
pub const eNORMALIZED_TIRELOAD: Enum = 3u64 as u32;
pub const eWHEEL_OMEGA: Enum = 4u64 as u32;
pub const eTIRE_FRICTION: Enum = 5u64 as u32;
pub const eTIRE_LONG_SLIP: Enum = 6u64 as u32;
pub const eNORM_TIRE_LONG_FORCE: Enum = 7u64 as u32;
pub const eTIRE_LAT_SLIP: Enum = 8u64 as u32;
pub const eNORM_TIRE_LAT_FORCE: Enum = 9u64 as u32;
pub const eNORM_TIRE_ALIGNING_MOMENT: Enum = 10u64 as u32;
pub const eMAX_NB_WHEEL_CHANNELS: Enum = 11u64 as u32;
}
pub mod PxVehicleWheelsSimFlag{
pub type Enum = u32;
pub const eLIMIT_SUSPENSION_EXPANSION_VELOCITY: Enum = 1u64 as u32;
}
pub mod PxVisualizationParameter{
pub type Enum = u32;
pub const eSCALE: Enum = 0u64 as u32;
pub const eWORLD_AXES: Enum = 1u64 as u32;
pub const eBODY_AXES: Enum = 2u64 as u32;
pub const eBODY_MASS_AXES: Enum = 3u64 as u32;
pub const eBODY_LIN_VELOCITY: Enum = 4u64 as u32;
pub const eBODY_ANG_VELOCITY: Enum = 5u64 as u32;
pub const eCONTACT_POINT: Enum = 6u64 as u32;
pub const eCONTACT_NORMAL: Enum = 7u64 as u32;
pub const eCONTACT_ERROR: Enum = 8u64 as u32;
pub const eCONTACT_FORCE: Enum = 9u64 as u32;
pub const eACTOR_AXES: Enum = 10u64 as u32;
pub const eCOLLISION_AABBS: Enum = 11u64 as u32;
pub const eCOLLISION_SHAPES: Enum = 12u64 as u32;
pub const eCOLLISION_AXES: Enum = 13u64 as u32;
pub const eCOLLISION_COMPOUNDS: Enum = 14u64 as u32;
pub const eCOLLISION_FNORMALS: Enum = 15u64 as u32;
pub const eCOLLISION_EDGES: Enum = 16u64 as u32;
pub const eCOLLISION_STATIC: Enum = 17u64 as u32;
pub const eCOLLISION_DYNAMIC: Enum = 18u64 as u32;
pub const eDEPRECATED_COLLISION_PAIRS: Enum = 19u64 as u32;
pub const eJOINT_LOCAL_FRAMES: Enum = 20u64 as u32;
pub const eJOINT_LIMITS: Enum = 21u64 as u32;
pub const eCULL_BOX: Enum = 22u64 as u32;
pub const eMBP_REGIONS: Enum = 23u64 as u32;
pub const eNUM_VALUES: Enum = 24u64 as u32;
pub const eFORCE_DWORD: Enum = 2147483647u64 as u32;
}
pub type PxZERO = u32;
pub const PxZero: PxZERO = 0u64 as u32;
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxAllocatorCallback{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxAssertHandler{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxErrorCallback{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxInputStream{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxInputData{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxOutputStream{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxRenderBuffer{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxProcessPxBaseCallback{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxBaseFlags{
    pub mBits: u16,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSerializationContext{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxCollection{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSerializationRegistry{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSerializer{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxRepXSerializer{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxStringTable{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxFoundation{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxProfilerCallback{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxPhysicsInsertionCallback{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxTaskManager{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxCpuDispatcher{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxConvexMeshGeometryFlags{
    pub mBits: u8,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxPadding_3_{
    pub mPadding: [u8; 3],
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxMeshGeometryFlags{
    pub mBits: u8,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub union Anonymous59{
    pub geometry: [u8; 4],
    pub _box: [u8; 16],
    pub sphere: [u8; 8],
    pub capsule: [u8; 12],
    pub plane: [u8; 4],
    pub convex: [u8; 48],
    pub mesh: [u8; 48],
    pub heightfield: [u8; 32],
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxHitFlags{
    pub mBits: u16,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxBitAndByte{
    pub mData: u8,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxHeightFieldFlags{
    pub mBits: u16,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxMeshFlags{
    pub mBits: u16,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxTriangleMeshFlags{
    pub mBits: u8,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxActorFlags{
    pub mBits: u8,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxArticulationImpl{
    pxbind_dummy: u8
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxConstraintVisualizer{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxConstraintConnector{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PvdDataStream{
    pxbind_dummy: u8
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxConstraintAllocator{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxArticulationFlags{
    pub mBits: u8,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxArticulationCacheFlags{
    pub mBits: u8,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxArticulationJointImpl{
    pxbind_dummy: u8
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxShapeFlags{
    pub mBits: u8,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxRigidBodyFlags{
    pub mBits: u8,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxFilterFlags{
    pub mBits: u16,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSimulationFilterCallback{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxPairFlags{
    pub mBits: u16,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxQueryFlags{
    pub mBits: u16,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxQueryFilterCallback{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxRaycastQueryResult{
    pxbind_dummy: u8
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSweepQueryResult{
    pxbind_dummy: u8
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxOverlapQueryResult{
    pxbind_dummy: u8
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxBatchQuery{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxConstraintFlags{
    pub mBits: u16,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxContactModifyCallback{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxCCDContactModifyCallback{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxDeletionListener{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxDataAccessFlags{
    pub mBits: u8,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxLockedData{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxMaterialFlags{
    pub mBits: u16,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxPhysics{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSimulationEventCallback{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxBroadPhaseCallback{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSceneFlags{
    pub mBits: u32,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxCudaContextManager{
    pxbind_dummy: u8
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxDeletionEventFlags{
    pub mBits: u8,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxPvd{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxRigidDynamicLockFlags{
    pub mBits: u8,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxPvdSceneClient{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxPvdSceneFlags{
    pub mBits: u8,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PvdDebugPoint{
    pxbind_dummy: u8
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PvdDebugLine{
    pxbind_dummy: u8
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PvdDebugTriangle{
    pxbind_dummy: u8
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PvdDebugText{
    pxbind_dummy: u8
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PvdClient{
    pxbind_dummy: u8
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxActorTypeFlags{
    pub mBits: u16,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxContactPairHeaderFlags{
    pub mBits: u16,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxContactPairFlags{
    pub mBits: u16,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxRaycastCallback{
    vtable_: *const std::ffi::c_void,
    pub block: PxRaycastHit,
    pub hasBlock: bool,
    pub touches: *mut PxRaycastHit,
    pub maxNbTouches: u32,
    pub nbTouches: u32,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSweepCallback{
    vtable_: *const std::ffi::c_void,
    pub block: PxSweepHit,
    pub hasBlock: bool,
    pub touches: *mut PxSweepHit,
    pub maxNbTouches: u32,
    pub nbTouches: u32,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxOverlapCallback{
    vtable_: *const std::ffi::c_void,
    pub block: PxOverlapHit,
    pub hasBlock: bool,
    pub touches: *mut PxOverlapHit,
    pub maxNbTouches: u32,
    pub nbTouches: u32,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxTriggerPairFlags{
    pub mBits: u8,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxObstacleContext{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxControllerManager{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxUserControllerHitReport{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxController{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxControllerFilterCallback{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxControllerBehaviorCallback{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxControllerCollisionFlags{
    pub mBits: u8,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxBoxController{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxCapsuleController{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxControllerBehaviorFlags{
    pub mBits: u8,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxControllerDebugRenderFlags{
    pub mBits: u32,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxConvexFlags{
    pub mBits: u16,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxTypedStridedData_physx_PxMaterialTableIndex_{
    pub stride: u32,
    pub data: *const u16,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub union Anonymous217{
    pub mBVH33Desc: PxBVH33MidphaseDesc,
    pub mBVH34Desc: PxBVH34MidphaseDesc,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxMeshPreprocessingFlags{
    pub mBits: u32,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxCooking{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxDistanceJointFlags{
    pub mBits: u16,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxDefaultAllocator{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxPrismaticJointFlags{
    pub mBits: u16,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxRevoluteJointFlags{
    pub mBits: u16,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSphericalJointFlags{
    pub mBits: u16,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxD6JointDriveFlags{
    pub mBits: u32,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxDefaultErrorCallback{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxBinaryConverter{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxDefaultCpuDispatcher{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSceneQueryFilterCallback{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxSceneQueryFlags{
    pub mBits: u16,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct XmlWriter{
    pxbind_dummy: u8
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct MemoryBuffer{
    pxbind_dummy: u8
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct XmlReader{
    pxbind_dummy: u8
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct XmlMemoryAllocator{
    pxbind_dummy: u8
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxFixedSizeLookupTable_eMAX_NB_ENGINE_TORQUE_CURVE_ENTRIES_{
    pub mDataPairs: [f32; 16],
    pub mNbDataPairs: u32,
    pub mPad: [u32; 3],
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleWheels4SimData{
    pxbind_dummy: u8
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleWheelsSimFlags{
    pub mBits: u32,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleWheels4DynData{
    pxbind_dummy: u8
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxVehicleTireForceCalculator{
    pxbind_dummy: u8
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxFixedSizeLookupTable_8_{
    pub mDataPairs: [f32; 16],
    pub mNbDataPairs: u32,
    pub mPad: [u32; 3],
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxPvdTransport{
    vtable_: *const std::ffi::c_void,
}
#[derive(Clone, Copy)]
#[repr(C)]
pub struct PxPvdInstrumentationFlags{
    pub mBits: u8,
}
extern "C" {
pub fn PxAllocatorCallback_delete(self_: *mut PxAllocatorCallback, ) -> ();
pub fn PxAllocatorCallback_allocate_mut(self_: *mut PxAllocatorCallback, size: usize, typeName: *const i8, filename: *const i8, line: i32, ) -> *mut std::ffi::c_void;
pub fn PxAllocatorCallback_deallocate_mut(self_: *mut PxAllocatorCallback, ptr: *mut std::ffi::c_void, ) -> ();
pub fn PxAssertHandler_delete(self_: *mut PxAssertHandler, ) -> ();
pub fn phys_PxGetAssertHandler() -> *mut PxAssertHandler;
pub fn phys_PxSetAssertHandler(handler: *mut PxAssertHandler, ) -> ();
pub fn phys_PxAbs(a: f32, ) -> f32;
pub fn phys_PxEquals(a: f32, b: f32, eps: f32, ) -> bool;
pub fn phys_PxAbs_1(a: f64, ) -> f64;
pub fn phys_PxAbs_2(a: i32, ) -> i32;
pub fn phys_PxSqrt(a: f32, ) -> f32;
pub fn phys_PxSqrt_1(a: f64, ) -> f64;
pub fn phys_PxRecipSqrt(a: f32, ) -> f32;
pub fn phys_PxRecipSqrt_1(a: f64, ) -> f64;
pub fn phys_PxSin(a: f32, ) -> f32;
pub fn phys_PxSin_1(a: f64, ) -> f64;
pub fn phys_PxCos(a: f32, ) -> f32;
pub fn phys_PxCos_1(a: f64, ) -> f64;
pub fn phys_PxTan(a: f32, ) -> f32;
pub fn phys_PxTan_1(a: f64, ) -> f64;
pub fn phys_PxAsin(f: f32, ) -> f32;
pub fn phys_PxAsin_1(f: f64, ) -> f64;
pub fn phys_PxAcos(f: f32, ) -> f32;
pub fn phys_PxAcos_1(f: f64, ) -> f64;
pub fn phys_PxAtan(a: f32, ) -> f32;
pub fn phys_PxAtan_1(a: f64, ) -> f64;
pub fn phys_PxAtan2(x: f32, y: f32, ) -> f32;
pub fn phys_PxAtan2_1(x: f64, y: f64, ) -> f64;
pub fn phys_PxIsFinite(f: f32, ) -> bool;
pub fn phys_PxIsFinite_1(f: f64, ) -> bool;
pub fn phys_PxFloor(a: f32, ) -> f32;
pub fn phys_PxExp(a: f32, ) -> f32;
pub fn phys_PxCeil(a: f32, ) -> f32;
pub fn phys_PxSign(a: f32, ) -> f32;
pub fn phys_PxPow(x: f32, y: f32, ) -> f32;
pub fn phys_PxLog(x: f32, ) -> f32;
pub fn PxVec3_new() -> PxVec3;
pub fn PxVec3_new_1(r: PxZERO, ) -> PxVec3;
pub fn PxVec3_new_2(a: f32, ) -> PxVec3;
pub fn PxVec3_new_3(nx: f32, ny: f32, nz: f32, ) -> PxVec3;
pub fn PxVec3_isZero(self_: *const PxVec3, ) -> bool;
pub fn PxVec3_isFinite(self_: *const PxVec3, ) -> bool;
pub fn PxVec3_isNormalized(self_: *const PxVec3, ) -> bool;
pub fn PxVec3_magnitudeSquared(self_: *const PxVec3, ) -> f32;
pub fn PxVec3_magnitude(self_: *const PxVec3, ) -> f32;
pub fn PxVec3_dot(self_: *const PxVec3, v: *const PxVec3, ) -> f32;
pub fn PxVec3_cross(self_: *const PxVec3, v: *const PxVec3, ) -> PxVec3;
pub fn PxVec3_getNormalized(self_: *const PxVec3, ) -> PxVec3;
pub fn PxVec3_normalize_mut(self_: *mut PxVec3, ) -> f32;
pub fn PxVec3_normalizeSafe_mut(self_: *mut PxVec3, ) -> f32;
pub fn PxVec3_normalizeFast_mut(self_: *mut PxVec3, ) -> f32;
pub fn PxVec3_multiply(self_: *const PxVec3, a: *const PxVec3, ) -> PxVec3;
pub fn PxVec3_minimum(self_: *const PxVec3, v: *const PxVec3, ) -> PxVec3;
pub fn PxVec3_minElement(self_: *const PxVec3, ) -> f32;
pub fn PxVec3_maximum(self_: *const PxVec3, v: *const PxVec3, ) -> PxVec3;
pub fn PxVec3_maxElement(self_: *const PxVec3, ) -> f32;
pub fn PxVec3_abs(self_: *const PxVec3, ) -> PxVec3;
pub fn PxQuat_new() -> PxQuat;
pub fn PxQuat_new_1(r: PxIDENTITY, ) -> PxQuat;
pub fn PxQuat_new_2(r: f32, ) -> PxQuat;
pub fn PxQuat_new_3(nx: f32, ny: f32, nz: f32, nw: f32, ) -> PxQuat;
pub fn PxQuat_new_4(angleRadians: f32, unitAxis: *const PxVec3, ) -> PxQuat;
pub fn PxQuat_new_5(m: *const PxMat33, ) -> PxQuat;
pub fn PxQuat_isIdentity(self_: *const PxQuat, ) -> bool;
pub fn PxQuat_isFinite(self_: *const PxQuat, ) -> bool;
pub fn PxQuat_isUnit(self_: *const PxQuat, ) -> bool;
pub fn PxQuat_isSane(self_: *const PxQuat, ) -> bool;
pub fn PxQuat_toRadiansAndUnitAxis(self_: *const PxQuat, angle: *mut f32, axis: *mut PxVec3, ) -> ();
pub fn PxQuat_getAngle(self_: *const PxQuat, ) -> f32;
pub fn PxQuat_getAngle_1(self_: *const PxQuat, q: *const PxQuat, ) -> f32;
pub fn PxQuat_magnitudeSquared(self_: *const PxQuat, ) -> f32;
pub fn PxQuat_dot(self_: *const PxQuat, v: *const PxQuat, ) -> f32;
pub fn PxQuat_getNormalized(self_: *const PxQuat, ) -> PxQuat;
pub fn PxQuat_magnitude(self_: *const PxQuat, ) -> f32;
pub fn PxQuat_normalize_mut(self_: *mut PxQuat, ) -> f32;
pub fn PxQuat_getConjugate(self_: *const PxQuat, ) -> PxQuat;
pub fn PxQuat_getImaginaryPart(self_: *const PxQuat, ) -> PxVec3;
pub fn PxQuat_getBasisVector0(self_: *const PxQuat, ) -> PxVec3;
pub fn PxQuat_getBasisVector1(self_: *const PxQuat, ) -> PxVec3;
pub fn PxQuat_getBasisVector2(self_: *const PxQuat, ) -> PxVec3;
pub fn PxQuat_rotate(self_: *const PxQuat, v: *const PxVec3, ) -> PxVec3;
pub fn PxQuat_rotateInv(self_: *const PxQuat, v: *const PxVec3, ) -> PxVec3;
pub fn PxPlane_new() -> PxPlane;
pub fn PxPlane_new_1(nx: f32, ny: f32, nz: f32, distance: f32, ) -> PxPlane;
pub fn PxPlane_new_2(normal: *const PxVec3, distance: f32, ) -> PxPlane;
pub fn PxPlane_new_3(point: *const PxVec3, normal: *const PxVec3, ) -> PxPlane;
pub fn PxPlane_new_4(p0: *const PxVec3, p1: *const PxVec3, p2: *const PxVec3, ) -> PxPlane;
pub fn PxPlane_distance(self_: *const PxPlane, p: *const PxVec3, ) -> f32;
pub fn PxPlane_contains(self_: *const PxPlane, p: *const PxVec3, ) -> bool;
pub fn PxPlane_project(self_: *const PxPlane, p: *const PxVec3, ) -> PxVec3;
pub fn PxPlane_pointInPlane(self_: *const PxPlane, ) -> PxVec3;
pub fn PxPlane_normalize_mut(self_: *mut PxPlane, ) -> ();
pub fn PxTransform_new() -> PxTransform;
pub fn PxTransform_new_1(position: *const PxVec3, ) -> PxTransform;
pub fn PxTransform_new_2(r: PxIDENTITY, ) -> PxTransform;
pub fn PxTransform_new_3(orientation: *const PxQuat, ) -> PxTransform;
pub fn PxTransform_new_4(x: f32, y: f32, z: f32, aQ: PxQuat, ) -> PxTransform;
pub fn PxTransform_new_5(p0: *const PxVec3, q0: *const PxQuat, ) -> PxTransform;
pub fn PxTransform_new_6(m: *const PxMat44, ) -> PxTransform;
pub fn PxTransform_getInverse(self_: *const PxTransform, ) -> PxTransform;
pub fn PxTransform_transform(self_: *const PxTransform, input: *const PxVec3, ) -> PxVec3;
pub fn PxTransform_transformInv(self_: *const PxTransform, input: *const PxVec3, ) -> PxVec3;
pub fn PxTransform_rotate(self_: *const PxTransform, input: *const PxVec3, ) -> PxVec3;
pub fn PxTransform_rotateInv(self_: *const PxTransform, input: *const PxVec3, ) -> PxVec3;
pub fn PxTransform_transform_1(self_: *const PxTransform, src: *const PxTransform, ) -> PxTransform;
pub fn PxTransform_isValid(self_: *const PxTransform, ) -> bool;
pub fn PxTransform_isSane(self_: *const PxTransform, ) -> bool;
pub fn PxTransform_isFinite(self_: *const PxTransform, ) -> bool;
pub fn PxTransform_transformInv_1(self_: *const PxTransform, src: *const PxTransform, ) -> PxTransform;
pub fn PxTransform_transform_2(self_: *const PxTransform, plane: *const PxPlane, ) -> PxPlane;
pub fn PxTransform_inverseTransform(self_: *const PxTransform, plane: *const PxPlane, ) -> PxPlane;
pub fn PxTransform_getNormalized(self_: *const PxTransform, ) -> PxTransform;
pub fn PxMat33_new() -> PxMat33;
pub fn PxMat33_new_1(r: PxIDENTITY, ) -> PxMat33;
pub fn PxMat33_new_2(r: PxZERO, ) -> PxMat33;
pub fn PxMat33_new_3(col0: *const PxVec3, col1: *const PxVec3, col2: *const PxVec3, ) -> PxMat33;
pub fn PxMat33_new_4(r: f32, ) -> PxMat33;
pub fn PxMat33_new_5(values: *mut f32, ) -> PxMat33;
pub fn PxMat33_new_6(q: *const PxQuat, ) -> PxMat33;
pub fn PxMat33_createDiagonal_mut(d: *const PxVec3, ) -> PxMat33;
pub fn PxMat33_getTranspose(self_: *const PxMat33, ) -> PxMat33;
pub fn PxMat33_getInverse(self_: *const PxMat33, ) -> PxMat33;
pub fn PxMat33_getDeterminant(self_: *const PxMat33, ) -> f32;
pub fn PxMat33_transform(self_: *const PxMat33, other: *const PxVec3, ) -> PxVec3;
pub fn PxMat33_transformTranspose(self_: *const PxMat33, other: *const PxVec3, ) -> PxVec3;
pub fn PxMat33_front(self_: *const PxMat33, ) -> *const f32;
pub fn PxQuat_new_6(m: *const PxMat33, ) -> PxQuat;
pub fn PxBounds3_new() -> PxBounds3;
pub fn PxBounds3_new_1(minimum: *const PxVec3, maximum: *const PxVec3, ) -> PxBounds3;
pub fn PxBounds3_empty_mut() -> PxBounds3;
pub fn PxBounds3_boundsOfPoints_mut(v0: *const PxVec3, v1: *const PxVec3, ) -> PxBounds3;
pub fn PxBounds3_centerExtents_mut(center: *const PxVec3, extent: *const PxVec3, ) -> PxBounds3;
pub fn PxBounds3_basisExtent_mut(center: *const PxVec3, basis: *const PxMat33, extent: *const PxVec3, ) -> PxBounds3;
pub fn PxBounds3_poseExtent_mut(pose: *const PxTransform, extent: *const PxVec3, ) -> PxBounds3;
pub fn PxBounds3_transformSafe_mut(matrix: *const PxMat33, bounds: *const PxBounds3, ) -> PxBounds3;
pub fn PxBounds3_transformFast_mut(matrix: *const PxMat33, bounds: *const PxBounds3, ) -> PxBounds3;
pub fn PxBounds3_transformSafe_mut_1(transform: *const PxTransform, bounds: *const PxBounds3, ) -> PxBounds3;
pub fn PxBounds3_transformFast_mut_1(transform: *const PxTransform, bounds: *const PxBounds3, ) -> PxBounds3;
pub fn PxBounds3_setEmpty_mut(self_: *mut PxBounds3, ) -> ();
pub fn PxBounds3_setMaximal_mut(self_: *mut PxBounds3, ) -> ();
pub fn PxBounds3_include_mut(self_: *mut PxBounds3, v: *const PxVec3, ) -> ();
pub fn PxBounds3_include_mut_1(self_: *mut PxBounds3, b: *const PxBounds3, ) -> ();
pub fn PxBounds3_isEmpty(self_: *const PxBounds3, ) -> bool;
pub fn PxBounds3_intersects(self_: *const PxBounds3, b: *const PxBounds3, ) -> bool;
pub fn PxBounds3_intersects1D(self_: *const PxBounds3, a: *const PxBounds3, axis: u32, ) -> bool;
pub fn PxBounds3_contains(self_: *const PxBounds3, v: *const PxVec3, ) -> bool;
pub fn PxBounds3_isInside(self_: *const PxBounds3, _box: *const PxBounds3, ) -> bool;
pub fn PxBounds3_getCenter(self_: *const PxBounds3, ) -> PxVec3;
pub fn PxBounds3_getCenter_1(self_: *const PxBounds3, axis: u32, ) -> f32;
pub fn PxBounds3_getExtents(self_: *const PxBounds3, axis: u32, ) -> f32;
pub fn PxBounds3_getDimensions(self_: *const PxBounds3, ) -> PxVec3;
pub fn PxBounds3_getExtents_1(self_: *const PxBounds3, ) -> PxVec3;
pub fn PxBounds3_scaleSafe_mut(self_: *mut PxBounds3, scale: f32, ) -> ();
pub fn PxBounds3_scaleFast_mut(self_: *mut PxBounds3, scale: f32, ) -> ();
pub fn PxBounds3_fattenSafe_mut(self_: *mut PxBounds3, distance: f32, ) -> ();
pub fn PxBounds3_fattenFast_mut(self_: *mut PxBounds3, distance: f32, ) -> ();
pub fn PxBounds3_isFinite(self_: *const PxBounds3, ) -> bool;
pub fn PxBounds3_isValid(self_: *const PxBounds3, ) -> bool;
pub fn PxBounds3_new_2(minimum_: *const PxVec3, maximum_: *const PxVec3, ) -> PxBounds3;
pub fn PxBounds3_empty_mut_1() -> PxBounds3;
pub fn PxBounds3_isFinite_1(self_: *const PxBounds3, ) -> bool;
pub fn PxBounds3_boundsOfPoints_mut_1(v0: *const PxVec3, v1: *const PxVec3, ) -> PxBounds3;
pub fn PxBounds3_centerExtents_mut_1(center: *const PxVec3, extent: *const PxVec3, ) -> PxBounds3;
pub fn PxBounds3_basisExtent_mut_1(center: *const PxVec3, basis: *const PxMat33, extent: *const PxVec3, ) -> PxBounds3;
pub fn PxBounds3_poseExtent_mut_1(pose: *const PxTransform, extent: *const PxVec3, ) -> PxBounds3;
pub fn PxBounds3_setEmpty_mut_1(self_: *mut PxBounds3, ) -> ();
pub fn PxBounds3_setMaximal_mut_1(self_: *mut PxBounds3, ) -> ();
pub fn PxBounds3_include_mut_2(self_: *mut PxBounds3, v: *const PxVec3, ) -> ();
pub fn PxBounds3_include_mut_3(self_: *mut PxBounds3, b: *const PxBounds3, ) -> ();
pub fn PxBounds3_isEmpty_1(self_: *const PxBounds3, ) -> bool;
pub fn PxBounds3_intersects_1(self_: *const PxBounds3, b: *const PxBounds3, ) -> bool;
pub fn PxBounds3_intersects1D_1(self_: *const PxBounds3, a: *const PxBounds3, axis: u32, ) -> bool;
pub fn PxBounds3_contains_1(self_: *const PxBounds3, v: *const PxVec3, ) -> bool;
pub fn PxBounds3_isInside_1(self_: *const PxBounds3, _box: *const PxBounds3, ) -> bool;
pub fn PxBounds3_getCenter_2(self_: *const PxBounds3, ) -> PxVec3;
pub fn PxBounds3_getCenter_3(self_: *const PxBounds3, axis: u32, ) -> f32;
pub fn PxBounds3_getExtents_2(self_: *const PxBounds3, axis: u32, ) -> f32;
pub fn PxBounds3_getDimensions_1(self_: *const PxBounds3, ) -> PxVec3;
pub fn PxBounds3_getExtents_3(self_: *const PxBounds3, ) -> PxVec3;
pub fn PxBounds3_scaleSafe_mut_1(self_: *mut PxBounds3, scale: f32, ) -> ();
pub fn PxBounds3_scaleFast_mut_1(self_: *mut PxBounds3, scale: f32, ) -> ();
pub fn PxBounds3_fattenSafe_mut_1(self_: *mut PxBounds3, distance: f32, ) -> ();
pub fn PxBounds3_fattenFast_mut_1(self_: *mut PxBounds3, distance: f32, ) -> ();
pub fn PxBounds3_transformSafe_mut_2(matrix: *const PxMat33, bounds: *const PxBounds3, ) -> PxBounds3;
pub fn PxBounds3_transformFast_mut_2(matrix: *const PxMat33, bounds: *const PxBounds3, ) -> PxBounds3;
pub fn PxBounds3_transformSafe_mut_3(transform: *const PxTransform, bounds: *const PxBounds3, ) -> PxBounds3;
pub fn PxBounds3_transformFast_mut_3(transform: *const PxTransform, bounds: *const PxBounds3, ) -> PxBounds3;
pub fn PxBounds3_isValid_1(self_: *const PxBounds3, ) -> bool;
pub fn PxErrorCallback_delete(self_: *mut PxErrorCallback, ) -> ();
pub fn PxErrorCallback_reportError_mut(self_: *mut PxErrorCallback, code: PxErrorCode::Enum, message: *const i8, file: *const i8, line: i32, ) -> ();
pub fn PxInputStream_read_mut(self_: *mut PxInputStream, dest: *mut std::ffi::c_void, count: u32, ) -> u32;
pub fn PxInputStream_delete(self_: *mut PxInputStream, ) -> ();
pub fn PxInputData_getLength(self_: *const PxInputData, ) -> u32;
pub fn PxInputData_seek_mut(self_: *mut PxInputData, offset: u32, ) -> ();
pub fn PxInputData_tell(self_: *const PxInputData, ) -> u32;
pub fn PxInputData_delete(self_: *mut PxInputData, ) -> ();
pub fn PxOutputStream_write_mut(self_: *mut PxOutputStream, src: *const std::ffi::c_void, count: u32, ) -> u32;
pub fn PxOutputStream_delete(self_: *mut PxOutputStream, ) -> ();
pub fn PxVec4_new() -> PxVec4;
pub fn PxVec4_new_1(r: PxZERO, ) -> PxVec4;
pub fn PxVec4_new_2(a: f32, ) -> PxVec4;
pub fn PxVec4_new_3(nx: f32, ny: f32, nz: f32, nw: f32, ) -> PxVec4;
pub fn PxVec4_new_4(v: *const PxVec3, nw: f32, ) -> PxVec4;
pub fn PxVec4_new_5(v: *const f32, ) -> PxVec4;
pub fn PxVec4_isZero(self_: *const PxVec4, ) -> bool;
pub fn PxVec4_isFinite(self_: *const PxVec4, ) -> bool;
pub fn PxVec4_isNormalized(self_: *const PxVec4, ) -> bool;
pub fn PxVec4_magnitudeSquared(self_: *const PxVec4, ) -> f32;
pub fn PxVec4_magnitude(self_: *const PxVec4, ) -> f32;
pub fn PxVec4_dot(self_: *const PxVec4, v: *const PxVec4, ) -> f32;
pub fn PxVec4_getNormalized(self_: *const PxVec4, ) -> PxVec4;
pub fn PxVec4_normalize_mut(self_: *mut PxVec4, ) -> f32;
pub fn PxVec4_multiply(self_: *const PxVec4, a: *const PxVec4, ) -> PxVec4;
pub fn PxVec4_minimum(self_: *const PxVec4, v: *const PxVec4, ) -> PxVec4;
pub fn PxVec4_maximum(self_: *const PxVec4, v: *const PxVec4, ) -> PxVec4;
pub fn PxVec4_getXYZ(self_: *const PxVec4, ) -> PxVec3;
pub fn PxVec4_setZero_mut(self_: *mut PxVec4, ) -> ();
pub fn PxMat44_new() -> PxMat44;
pub fn PxMat44_new_1(r: PxIDENTITY, ) -> PxMat44;
pub fn PxMat44_new_2(r: PxZERO, ) -> PxMat44;
pub fn PxMat44_new_3(col0: *const PxVec4, col1: *const PxVec4, col2: *const PxVec4, col3: *const PxVec4, ) -> PxMat44;
pub fn PxMat44_new_4(r: f32, ) -> PxMat44;
pub fn PxMat44_new_5(col0: *const PxVec3, col1: *const PxVec3, col2: *const PxVec3, col3: *const PxVec3, ) -> PxMat44;
pub fn PxMat44_new_6(values: *mut f32, ) -> PxMat44;
pub fn PxMat44_new_7(q: *const PxQuat, ) -> PxMat44;
pub fn PxMat44_new_8(diagonal: *const PxVec4, ) -> PxMat44;
pub fn PxMat44_new_9(axes: *const PxMat33, position: *const PxVec3, ) -> PxMat44;
pub fn PxMat44_new_10(t: *const PxTransform, ) -> PxMat44;
pub fn PxMat44_getTranspose(self_: *const PxMat44, ) -> PxMat44;
pub fn PxMat44_transform(self_: *const PxMat44, other: *const PxVec4, ) -> PxVec4;
pub fn PxMat44_transform_1(self_: *const PxMat44, other: *const PxVec3, ) -> PxVec3;
pub fn PxMat44_rotate(self_: *const PxMat44, other: *const PxVec4, ) -> PxVec4;
pub fn PxMat44_rotate_1(self_: *const PxMat44, other: *const PxVec3, ) -> PxVec3;
pub fn PxMat44_getBasis(self_: *const PxMat44, num: i32, ) -> PxVec3;
pub fn PxMat44_getPosition(self_: *const PxMat44, ) -> PxVec3;
pub fn PxMat44_setPosition_mut(self_: *mut PxMat44, position: *const PxVec3, ) -> ();
pub fn PxMat44_front(self_: *const PxMat44, ) -> *const f32;
pub fn PxMat44_scale_mut(self_: *mut PxMat44, p: *const PxVec4, ) -> ();
pub fn PxMat44_inverseRT(self_: *const PxMat44, ) -> PxMat44;
pub fn PxMat44_isFinite(self_: *const PxMat44, ) -> bool;
pub fn PxTransform_new_7(m: *const PxMat44, ) -> PxTransform;
pub fn phys_PxShortestRotation(from: *const PxVec3, target: *const PxVec3, ) -> PxQuat;
pub fn phys_PxDiagonalize(m: *const PxMat33, axes: *mut PxQuat, ) -> PxVec3;
pub fn PxVec2_new() -> PxVec2;
pub fn PxVec2_new_1(r: PxZERO, ) -> PxVec2;
pub fn PxVec2_new_2(a: f32, ) -> PxVec2;
pub fn PxVec2_new_3(nx: f32, ny: f32, ) -> PxVec2;
pub fn PxVec2_isZero(self_: *const PxVec2, ) -> bool;
pub fn PxVec2_isFinite(self_: *const PxVec2, ) -> bool;
pub fn PxVec2_isNormalized(self_: *const PxVec2, ) -> bool;
pub fn PxVec2_magnitudeSquared(self_: *const PxVec2, ) -> f32;
pub fn PxVec2_magnitude(self_: *const PxVec2, ) -> f32;
pub fn PxVec2_dot(self_: *const PxVec2, v: *const PxVec2, ) -> f32;
pub fn PxVec2_getNormalized(self_: *const PxVec2, ) -> PxVec2;
pub fn PxVec2_normalize_mut(self_: *mut PxVec2, ) -> f32;
pub fn PxVec2_multiply(self_: *const PxVec2, a: *const PxVec2, ) -> PxVec2;
pub fn PxVec2_minimum(self_: *const PxVec2, v: *const PxVec2, ) -> PxVec2;
pub fn PxVec2_minElement(self_: *const PxVec2, ) -> f32;
pub fn PxVec2_maximum(self_: *const PxVec2, v: *const PxVec2, ) -> PxVec2;
pub fn PxVec2_maxElement(self_: *const PxVec2, ) -> f32;
pub fn phys_PxMemZero(dest: *mut std::ffi::c_void, count: u32, ) -> *mut std::ffi::c_void;
pub fn phys_PxMemSet(dest: *mut std::ffi::c_void, c: i32, count: u32, ) -> *mut std::ffi::c_void;
pub fn phys_PxMemCopy(dest: *mut std::ffi::c_void, src: *const std::ffi::c_void, count: u32, ) -> *mut std::ffi::c_void;
pub fn phys_PxMemMove(dest: *mut std::ffi::c_void, src: *const std::ffi::c_void, count: u32, ) -> *mut std::ffi::c_void;
pub fn PxStridedData_new() -> PxStridedData;
pub fn PxBoundedData_new() -> PxBoundedData;
pub fn PxDebugPoint_new(p: *const PxVec3, c: *const u32, ) -> PxDebugPoint;
pub fn PxDebugLine_new(p0: *const PxVec3, p1: *const PxVec3, c: *const u32, ) -> PxDebugLine;
pub fn PxDebugTriangle_new(p0: *const PxVec3, p1: *const PxVec3, p2: *const PxVec3, c: *const u32, ) -> PxDebugTriangle;
pub fn PxDebugText_new() -> PxDebugText;
pub fn PxDebugText_new_1(p: *const PxVec3, s: *const f32, c: *const u32, str: *const i8, ) -> PxDebugText;
pub fn PxRenderBuffer_delete(self_: *mut PxRenderBuffer, ) -> ();
pub fn PxRenderBuffer_getNbPoints(self_: *const PxRenderBuffer, ) -> u32;
pub fn PxRenderBuffer_getPoints(self_: *const PxRenderBuffer, ) -> *const PxDebugPoint;
pub fn PxRenderBuffer_getNbLines(self_: *const PxRenderBuffer, ) -> u32;
pub fn PxRenderBuffer_getLines(self_: *const PxRenderBuffer, ) -> *const PxDebugLine;
pub fn PxRenderBuffer_getNbTriangles(self_: *const PxRenderBuffer, ) -> u32;
pub fn PxRenderBuffer_getTriangles(self_: *const PxRenderBuffer, ) -> *const PxDebugTriangle;
pub fn PxRenderBuffer_getNbTexts(self_: *const PxRenderBuffer, ) -> u32;
pub fn PxRenderBuffer_getTexts(self_: *const PxRenderBuffer, ) -> *const PxDebugText;
pub fn PxRenderBuffer_append_mut(self_: *mut PxRenderBuffer, other: *const PxRenderBuffer, ) -> ();
pub fn PxRenderBuffer_clear_mut(self_: *mut PxRenderBuffer, ) -> ();
pub fn PxProcessPxBaseCallback_delete(self_: *mut PxProcessPxBaseCallback, ) -> ();
pub fn PxProcessPxBaseCallback_process_mut(self_: *mut PxProcessPxBaseCallback, anonymous_arg0: *mut PxBase, ) -> ();
pub fn PxSerializationContext_registerReference_mut(self_: *mut PxSerializationContext, base: *mut PxBase, kind: u32, reference: usize, ) -> ();
pub fn PxSerializationContext_getCollection(self_: *const PxSerializationContext, ) -> *const PxCollection;
pub fn PxSerializationContext_writeData_mut(self_: *mut PxSerializationContext, data: *const std::ffi::c_void, size: u32, ) -> ();
pub fn PxSerializationContext_alignData_mut(self_: *mut PxSerializationContext, alignment: u32, ) -> ();
pub fn PxSerializationContext_writeName_mut(self_: *mut PxSerializationContext, name: *const i8, ) -> ();
pub fn PxDeserializationContext_resolveReference(self_: *const PxDeserializationContext, kind: u32, reference: usize, ) -> *mut PxBase;
pub fn PxDeserializationContext_readName_mut(self_: *mut PxDeserializationContext, name: *mut *const i8, ) -> ();
pub fn PxDeserializationContext_alignExtraData_mut(self_: *mut PxDeserializationContext, alignment: u32, ) -> ();
pub fn PxSerializationRegistry_registerSerializer_mut(self_: *mut PxSerializationRegistry, _type: u16, serializer: *mut PxSerializer, ) -> ();
pub fn PxSerializationRegistry_unregisterSerializer_mut(self_: *mut PxSerializationRegistry, _type: u16, ) -> *mut PxSerializer;
pub fn PxSerializationRegistry_registerBinaryMetaDataCallback_mut(self_: *mut PxSerializationRegistry, callback: *mut std::ffi::c_void, ) -> ();
pub fn PxSerializationRegistry_getSerializer(self_: *const PxSerializationRegistry, _type: u16, ) -> *const PxSerializer;
pub fn PxSerializationRegistry_registerRepXSerializer_mut(self_: *mut PxSerializationRegistry, _type: u16, serializer: *mut PxRepXSerializer, ) -> ();
pub fn PxSerializationRegistry_unregisterRepXSerializer_mut(self_: *mut PxSerializationRegistry, _type: u16, ) -> *mut PxRepXSerializer;
pub fn PxSerializationRegistry_getRepXSerializer(self_: *const PxSerializationRegistry, typeName: *const i8, ) -> *mut PxRepXSerializer;
pub fn PxSerializationRegistry_release_mut(self_: *mut PxSerializationRegistry, ) -> ();
pub fn PxCollection_add_mut(self_: *mut PxCollection, object: *mut PxBase, id: usize, ) -> ();
pub fn PxCollection_remove_mut(self_: *mut PxCollection, object: *mut PxBase, ) -> ();
pub fn PxCollection_contains(self_: *const PxCollection, object: *mut PxBase, ) -> bool;
pub fn PxCollection_addId_mut(self_: *mut PxCollection, object: *mut PxBase, id: usize, ) -> ();
pub fn PxCollection_removeId_mut(self_: *mut PxCollection, id: usize, ) -> ();
pub fn PxCollection_add_mut_1(self_: *mut PxCollection, collection: *mut PxCollection, ) -> ();
pub fn PxCollection_remove_mut_1(self_: *mut PxCollection, collection: *mut PxCollection, ) -> ();
pub fn PxCollection_getNbObjects(self_: *const PxCollection, ) -> u32;
pub fn PxCollection_getObject(self_: *const PxCollection, index: u32, ) -> *mut PxBase;
pub fn PxCollection_getObjects(self_: *const PxCollection, userBuffer: *mut *mut PxBase, bufferSize: u32, startIndex: u32, ) -> u32;
pub fn PxCollection_find(self_: *const PxCollection, id: usize, ) -> *mut PxBase;
pub fn PxCollection_getNbIds(self_: *const PxCollection, ) -> u32;
pub fn PxCollection_getIds(self_: *const PxCollection, userBuffer: *mut usize, bufferSize: u32, startIndex: u32, ) -> u32;
pub fn PxCollection_getId(self_: *const PxCollection, object: *const PxBase, ) -> usize;
pub fn PxCollection_release_mut(self_: *mut PxCollection, ) -> ();
pub fn phys_PxCreateCollection() -> *mut PxCollection;
pub fn PxBase_release_mut(self_: *mut PxBase, ) -> ();
pub fn PxBase_getConcreteTypeName(self_: *const PxBase, ) -> *const i8;
pub fn PxBase_getConcreteType(self_: *const PxBase, ) -> u16;
pub fn PxBase_setBaseFlag_mut(self_: *mut PxBase, flag: PxBaseFlag::Enum, value: bool, ) -> ();
pub fn PxBase_setBaseFlags_mut(self_: *mut PxBase, inFlags: PxBaseFlags, ) -> ();
pub fn PxBase_getBaseFlags(self_: *const PxBase, ) -> PxBaseFlags;
pub fn PxBase_isReleasable(self_: *const PxBase, ) -> bool;
pub fn PxTolerancesScale_new() -> PxTolerancesScale;
pub fn PxTolerancesScale_isValid(self_: *const PxTolerancesScale, ) -> bool;
pub fn PxTolerancesScale_new_1() -> PxTolerancesScale;
pub fn PxTolerancesScale_isValid_1(self_: *const PxTolerancesScale, ) -> bool;
pub fn PxStringTable_allocateStr_mut(self_: *mut PxStringTable, inSrc: *const i8, ) -> *const i8;
pub fn PxStringTable_release_mut(self_: *mut PxStringTable, ) -> ();
pub fn PxFoundation_release_mut(self_: *mut PxFoundation, ) -> ();
pub fn PxFoundation_getErrorCallback_mut(self_: *mut PxFoundation, ) -> *mut PxErrorCallback;
pub fn PxFoundation_setErrorLevel_mut(self_: *mut PxFoundation, mask: PxErrorCode::Enum, ) -> ();
pub fn PxFoundation_getErrorLevel(self_: *const PxFoundation, ) -> PxErrorCode::Enum;
pub fn PxFoundation_getAllocatorCallback_mut(self_: *mut PxFoundation, ) -> *mut PxAllocatorCallback;
pub fn PxFoundation_getReportAllocationNames(self_: *const PxFoundation, ) -> bool;
pub fn PxFoundation_setReportAllocationNames_mut(self_: *mut PxFoundation, value: bool, ) -> ();
pub fn phys_PxCreateFoundation(version: u32, allocator: *mut PxAllocatorCallback, errorCallback: *mut PxErrorCallback, ) -> *mut PxFoundation;
pub fn phys_PxGetFoundation() -> *mut PxFoundation;
pub fn phys_PxGetProfilerCallback() -> *mut PxProfilerCallback;
pub fn phys_PxSetProfilerCallback(profiler: *mut PxProfilerCallback, ) -> ();
pub fn PxSerializer_getConcreteTypeName(self_: *const PxSerializer, ) -> *const i8;
pub fn PxSerializer_requiresObjects(self_: *const PxSerializer, anonymous_arg0: *mut PxBase, anonymous_arg1: *mut PxProcessPxBaseCallback, ) -> ();
pub fn PxSerializer_isSubordinate(self_: *const PxSerializer, ) -> bool;
pub fn PxSerializer_exportExtraData(self_: *const PxSerializer, anonymous_arg0: *mut PxBase, anonymous_arg1: *mut PxSerializationContext, ) -> ();
pub fn PxSerializer_exportData(self_: *const PxSerializer, anonymous_arg0: *mut PxBase, anonymous_arg1: *mut PxSerializationContext, ) -> ();
pub fn PxSerializer_registerReferences(self_: *const PxSerializer, obj: *mut PxBase, s: *mut PxSerializationContext, ) -> ();
pub fn PxSerializer_getClassSize(self_: *const PxSerializer, ) -> usize;
pub fn PxSerializer_createObject(self_: *const PxSerializer, address: *mut *mut u8, context: *mut PxDeserializationContext, ) -> *mut PxBase;
pub fn PxSerializer_delete(self_: *mut PxSerializer, ) -> ();
pub fn PxPhysicsInsertionCallback_buildObjectFromData_mut(self_: *mut PxPhysicsInsertionCallback, _type: PxConcreteType::Enum, data: *mut std::ffi::c_void, ) -> *mut PxBase;
pub fn PxTaskManager_setCpuDispatcher_mut(self_: *mut PxTaskManager, _ref: *mut PxCpuDispatcher, ) -> ();
pub fn PxTaskManager_getCpuDispatcher(self_: *const PxTaskManager, ) -> *mut PxCpuDispatcher;
pub fn PxTaskManager_resetDependencies_mut(self_: *mut PxTaskManager, ) -> ();
pub fn PxTaskManager_startSimulation_mut(self_: *mut PxTaskManager, ) -> ();
pub fn PxTaskManager_stopSimulation_mut(self_: *mut PxTaskManager, ) -> ();
pub fn PxTaskManager_taskCompleted_mut(self_: *mut PxTaskManager, task: *mut PxTask, ) -> ();
pub fn PxTaskManager_getNamedTask_mut(self_: *mut PxTaskManager, name: *const i8, ) -> u32;
pub fn PxTaskManager_submitNamedTask_mut(self_: *mut PxTaskManager, task: *mut PxTask, name: *const i8, _type: PxTaskType::Enum, ) -> u32;
pub fn PxTaskManager_submitUnnamedTask_mut(self_: *mut PxTaskManager, task: *mut PxTask, _type: PxTaskType::Enum, ) -> u32;
pub fn PxTaskManager_getTaskFromID_mut(self_: *mut PxTaskManager, id: u32, ) -> *mut PxTask;
pub fn PxTaskManager_release_mut(self_: *mut PxTaskManager, ) -> ();
pub fn PxTaskManager_createTaskManager_mut(errorCallback: *mut PxErrorCallback, anonymous_arg1: *mut PxCpuDispatcher, ) -> *mut PxTaskManager;
pub fn PxCpuDispatcher_submitTask_mut(self_: *mut PxCpuDispatcher, task: *mut PxBaseTask, ) -> ();
pub fn PxCpuDispatcher_getWorkerCount(self_: *const PxCpuDispatcher, ) -> u32;
pub fn PxCpuDispatcher_delete(self_: *mut PxCpuDispatcher, ) -> ();
pub fn PxBaseTask_run_mut(self_: *mut PxBaseTask, ) -> ();
pub fn PxBaseTask_getName(self_: *const PxBaseTask, ) -> *const i8;
pub fn PxBaseTask_addReference_mut(self_: *mut PxBaseTask, ) -> ();
pub fn PxBaseTask_removeReference_mut(self_: *mut PxBaseTask, ) -> ();
pub fn PxBaseTask_getReference(self_: *const PxBaseTask, ) -> i32;
pub fn PxBaseTask_release_mut(self_: *mut PxBaseTask, ) -> ();
pub fn PxBaseTask_getTaskManager(self_: *const PxBaseTask, ) -> *mut PxTaskManager;
pub fn PxBaseTask_setContextId_mut(self_: *mut PxBaseTask, id: usize, ) -> ();
pub fn PxBaseTask_getContextId(self_: *const PxBaseTask, ) -> usize;
pub fn PxTask_release_mut(self_: *mut PxTask, ) -> ();
pub fn PxTask_finishBefore_mut(self_: *mut PxTask, taskID: u32, ) -> ();
pub fn PxTask_startAfter_mut(self_: *mut PxTask, taskID: u32, ) -> ();
pub fn PxTask_addReference_mut(self_: *mut PxTask, ) -> ();
pub fn PxTask_removeReference_mut(self_: *mut PxTask, ) -> ();
pub fn PxTask_getReference(self_: *const PxTask, ) -> i32;
pub fn PxTask_getTaskID(self_: *const PxTask, ) -> u32;
pub fn PxTask_submitted_mut(self_: *mut PxTask, ) -> ();
pub fn PxLightCpuTask_setContinuation_mut(self_: *mut PxLightCpuTask, tm: *mut PxTaskManager, c: *mut PxBaseTask, ) -> ();
pub fn PxLightCpuTask_setContinuation_mut_1(self_: *mut PxLightCpuTask, c: *mut PxBaseTask, ) -> ();
pub fn PxLightCpuTask_getContinuation(self_: *const PxLightCpuTask, ) -> *mut PxBaseTask;
pub fn PxLightCpuTask_removeReference_mut(self_: *mut PxLightCpuTask, ) -> ();
pub fn PxLightCpuTask_getReference(self_: *const PxLightCpuTask, ) -> i32;
pub fn PxLightCpuTask_addReference_mut(self_: *mut PxLightCpuTask, ) -> ();
pub fn PxLightCpuTask_release_mut(self_: *mut PxLightCpuTask, ) -> ();
pub fn PxGeometry_getType(self_: *const PxGeometry, ) -> PxGeometryType::Enum;
pub fn PxBoxGeometry_new() -> PxBoxGeometry;
pub fn PxBoxGeometry_new_1(hx: f32, hy: f32, hz: f32, ) -> PxBoxGeometry;
pub fn PxBoxGeometry_new_2(halfExtents_: PxVec3, ) -> PxBoxGeometry;
pub fn PxBoxGeometry_isValid(self_: *const PxBoxGeometry, ) -> bool;
pub fn PxBoxGeometry_isValid_1(self_: *const PxBoxGeometry, ) -> bool;
pub fn PxBVHStructure_raycast(self_: *const PxBVHStructure, origin: *const PxVec3, unitDir: *const PxVec3, maxDist: f32, maxHits: u32, rayHits: *mut u32, ) -> u32;
pub fn PxBVHStructure_sweep(self_: *const PxBVHStructure, aabb: *const PxBounds3, unitDir: *const PxVec3, maxDist: f32, maxHits: u32, sweepHits: *mut u32, ) -> u32;
pub fn PxBVHStructure_overlap(self_: *const PxBVHStructure, aabb: *const PxBounds3, maxHits: u32, overlapHits: *mut u32, ) -> u32;
pub fn PxBVHStructure_getBounds(self_: *const PxBVHStructure, ) -> *const PxBounds3;
pub fn PxBVHStructure_getNbBounds(self_: *const PxBVHStructure, ) -> u32;
pub fn PxBVHStructure_getConcreteTypeName(self_: *const PxBVHStructure, ) -> *const i8;
pub fn PxCapsuleGeometry_new() -> PxCapsuleGeometry;
pub fn PxCapsuleGeometry_new_1(radius_: f32, halfHeight_: f32, ) -> PxCapsuleGeometry;
pub fn PxCapsuleGeometry_isValid(self_: *const PxCapsuleGeometry, ) -> bool;
pub fn PxCapsuleGeometry_isValid_1(self_: *const PxCapsuleGeometry, ) -> bool;
pub fn phys_PxTransformFromSegment(p0: *const PxVec3, p1: *const PxVec3, halfHeight: *mut f32, ) -> PxTransform;
pub fn PxConvexMesh_getNbVertices(self_: *const PxConvexMesh, ) -> u32;
pub fn PxConvexMesh_getVertices(self_: *const PxConvexMesh, ) -> *const PxVec3;
pub fn PxConvexMesh_getIndexBuffer(self_: *const PxConvexMesh, ) -> *const u8;
pub fn PxConvexMesh_getNbPolygons(self_: *const PxConvexMesh, ) -> u32;
pub fn PxConvexMesh_getPolygonData(self_: *const PxConvexMesh, index: u32, data: *mut PxHullPolygon, ) -> bool;
pub fn PxConvexMesh_release_mut(self_: *mut PxConvexMesh, ) -> ();
pub fn PxConvexMesh_getReferenceCount(self_: *const PxConvexMesh, ) -> u32;
pub fn PxConvexMesh_acquireReference_mut(self_: *mut PxConvexMesh, ) -> ();
pub fn PxConvexMesh_getMassInformation(self_: *const PxConvexMesh, mass: *mut f32, localInertia: *mut PxMat33, localCenterOfMass: *mut PxVec3, ) -> ();
pub fn PxConvexMesh_getLocalBounds(self_: *const PxConvexMesh, ) -> PxBounds3;
pub fn PxConvexMesh_getConcreteTypeName(self_: *const PxConvexMesh, ) -> *const i8;
pub fn PxConvexMesh_isGpuCompatible(self_: *const PxConvexMesh, ) -> bool;
pub fn PxMeshScale_new() -> PxMeshScale;
pub fn PxMeshScale_new_1(r: f32, ) -> PxMeshScale;
pub fn PxMeshScale_new_2(s: *const PxVec3, ) -> PxMeshScale;
pub fn PxMeshScale_new_3(s: *const PxVec3, r: *const PxQuat, ) -> PxMeshScale;
pub fn PxMeshScale_isIdentity(self_: *const PxMeshScale, ) -> bool;
pub fn PxMeshScale_getInverse(self_: *const PxMeshScale, ) -> PxMeshScale;
pub fn PxMeshScale_toMat33(self_: *const PxMeshScale, ) -> PxMat33;
pub fn PxMeshScale_hasNegativeDeterminant(self_: *const PxMeshScale, ) -> bool;
pub fn PxMeshScale_transform(self_: *const PxMeshScale, v: *const PxVec3, ) -> PxVec3;
pub fn PxMeshScale_isValidForTriangleMesh(self_: *const PxMeshScale, ) -> bool;
pub fn PxMeshScale_isValidForConvexMesh(self_: *const PxMeshScale, ) -> bool;
pub fn PxConvexMeshGeometry_new() -> PxConvexMeshGeometry;
pub fn PxConvexMeshGeometry_new_1(mesh: *mut PxConvexMesh, scaling: *const PxMeshScale, flags: PxConvexMeshGeometryFlags, ) -> PxConvexMeshGeometry;
pub fn PxConvexMeshGeometry_isValid(self_: *const PxConvexMeshGeometry, ) -> bool;
pub fn PxConvexMeshGeometry_isValid_1(self_: *const PxConvexMeshGeometry, ) -> bool;
pub fn PxSphereGeometry_new() -> PxSphereGeometry;
pub fn PxSphereGeometry_new_1(ir: f32, ) -> PxSphereGeometry;
pub fn PxSphereGeometry_isValid(self_: *const PxSphereGeometry, ) -> bool;
pub fn PxSphereGeometry_isValid_1(self_: *const PxSphereGeometry, ) -> bool;
pub fn PxPlaneGeometry_new() -> PxPlaneGeometry;
pub fn PxPlaneGeometry_isValid(self_: *const PxPlaneGeometry, ) -> bool;
pub fn PxPlaneGeometry_isValid_1(self_: *const PxPlaneGeometry, ) -> bool;
pub fn phys_PxTransformFromPlaneEquation(plane: *const PxPlane, ) -> PxTransform;
pub fn phys_PxPlaneEquationFromTransform(transform: *const PxTransform, ) -> PxPlane;
pub fn PxTriangleMeshGeometry_new() -> PxTriangleMeshGeometry;
pub fn PxTriangleMeshGeometry_new_1(mesh: *mut PxTriangleMesh, scaling: *const PxMeshScale, flags: PxMeshGeometryFlags, ) -> PxTriangleMeshGeometry;
pub fn PxTriangleMeshGeometry_isValid(self_: *const PxTriangleMeshGeometry, ) -> bool;
pub fn PxTriangleMeshGeometry_isValid_1(self_: *const PxTriangleMeshGeometry, ) -> bool;
pub fn PxHeightFieldGeometry_new() -> PxHeightFieldGeometry;
pub fn PxHeightFieldGeometry_new_1(hf: *mut PxHeightField, flags: PxMeshGeometryFlags, heightScale_: f32, rowScale_: f32, columnScale_: f32, ) -> PxHeightFieldGeometry;
pub fn PxHeightFieldGeometry_isValid(self_: *const PxHeightFieldGeometry, ) -> bool;
pub fn PxHeightFieldGeometry_isValid_1(self_: *const PxHeightFieldGeometry, ) -> bool;
pub fn PxGeometryHolder_getType(self_: *const PxGeometryHolder, ) -> PxGeometryType::Enum;
pub fn PxGeometryHolder_any_mut(self_: *mut PxGeometryHolder, ) -> *mut PxGeometry;
pub fn PxGeometryHolder_any(self_: *const PxGeometryHolder, ) -> *const PxGeometry;
pub fn PxGeometryHolder_sphere_mut(self_: *mut PxGeometryHolder, ) -> *mut PxSphereGeometry;
pub fn PxGeometryHolder_sphere(self_: *const PxGeometryHolder, ) -> *const PxSphereGeometry;
pub fn PxGeometryHolder_plane_mut(self_: *mut PxGeometryHolder, ) -> *mut PxPlaneGeometry;
pub fn PxGeometryHolder_plane(self_: *const PxGeometryHolder, ) -> *const PxPlaneGeometry;
pub fn PxGeometryHolder_capsule_mut(self_: *mut PxGeometryHolder, ) -> *mut PxCapsuleGeometry;
pub fn PxGeometryHolder_capsule(self_: *const PxGeometryHolder, ) -> *const PxCapsuleGeometry;
pub fn PxGeometryHolder_box_mut(self_: *mut PxGeometryHolder, ) -> *mut PxBoxGeometry;
pub fn PxGeometryHolder_box(self_: *const PxGeometryHolder, ) -> *const PxBoxGeometry;
pub fn PxGeometryHolder_convexMesh_mut(self_: *mut PxGeometryHolder, ) -> *mut PxConvexMeshGeometry;
pub fn PxGeometryHolder_convexMesh(self_: *const PxGeometryHolder, ) -> *const PxConvexMeshGeometry;
pub fn PxGeometryHolder_triangleMesh_mut(self_: *mut PxGeometryHolder, ) -> *mut PxTriangleMeshGeometry;
pub fn PxGeometryHolder_triangleMesh(self_: *const PxGeometryHolder, ) -> *const PxTriangleMeshGeometry;
pub fn PxGeometryHolder_heightField_mut(self_: *mut PxGeometryHolder, ) -> *mut PxHeightFieldGeometry;
pub fn PxGeometryHolder_heightField(self_: *const PxGeometryHolder, ) -> *const PxHeightFieldGeometry;
pub fn PxGeometryHolder_storeAny_mut(self_: *mut PxGeometryHolder, geometry: *const PxGeometry, ) -> ();
pub fn PxGeometryHolder_new() -> PxGeometryHolder;
pub fn PxGeometryHolder_new_1(geometry: *const PxGeometry, ) -> PxGeometryHolder;
pub fn PxActorShape_new() -> PxActorShape;
pub fn PxActorShape_new_1(a: *mut PxRigidActor, s: *mut PxShape, ) -> PxActorShape;
pub fn PxQueryHit_new() -> PxQueryHit;
pub fn PxLocationHit_new() -> PxLocationHit;
pub fn PxLocationHit_hadInitialOverlap(self_: *const PxLocationHit, ) -> bool;
pub fn PxRaycastHit_new() -> PxRaycastHit;
pub fn PxSweepHit_new() -> PxSweepHit;
pub fn PxGeometryQuery_sweep_mut(unitDir: *const PxVec3, maxDist: f32, geom0: *const PxGeometry, pose0: *const PxTransform, geom1: *const PxGeometry, pose1: *const PxTransform, sweepHit: *mut PxSweepHit, hitFlags: PxHitFlags, inflation: f32, ) -> bool;
pub fn PxGeometryQuery_overlap_mut(geom0: *const PxGeometry, pose0: *const PxTransform, geom1: *const PxGeometry, pose1: *const PxTransform, ) -> bool;
pub fn PxGeometryQuery_raycast_mut(origin: *const PxVec3, unitDir: *const PxVec3, geom: *const PxGeometry, pose: *const PxTransform, maxDist: f32, hitFlags: PxHitFlags, maxHits: u32, rayHits: *mut PxRaycastHit, ) -> u32;
pub fn PxGeometryQuery_computePenetration_mut(direction: *mut PxVec3, depth: *mut f32, geom0: *const PxGeometry, pose0: *const PxTransform, geom1: *const PxGeometry, pose1: *const PxTransform, ) -> bool;
pub fn PxGeometryQuery_pointDistance_mut(point: *const PxVec3, geom: *const PxGeometry, pose: *const PxTransform, closestPoint: *mut PxVec3, ) -> f32;
pub fn PxGeometryQuery_getWorldBounds_mut(geom: *const PxGeometry, pose: *const PxTransform, inflation: f32, ) -> PxBounds3;
pub fn PxGeometryQuery_isValid_mut(geom: *const PxGeometry, ) -> bool;
pub fn PxHeightFieldSample_tessFlag(self_: *const PxHeightFieldSample, ) -> u8;
pub fn PxHeightFieldSample_setTessFlag_mut(self_: *mut PxHeightFieldSample, ) -> ();
pub fn PxHeightFieldSample_clearTessFlag_mut(self_: *mut PxHeightFieldSample, ) -> ();
pub fn PxHeightField_release_mut(self_: *mut PxHeightField, ) -> ();
pub fn PxHeightField_saveCells(self_: *const PxHeightField, destBuffer: *mut std::ffi::c_void, destBufferSize: u32, ) -> u32;
pub fn PxHeightField_modifySamples_mut(self_: *mut PxHeightField, startCol: i32, startRow: i32, subfieldDesc: *const PxHeightFieldDesc, shrinkBounds: bool, ) -> bool;
pub fn PxHeightField_getNbRows(self_: *const PxHeightField, ) -> u32;
pub fn PxHeightField_getNbColumns(self_: *const PxHeightField, ) -> u32;
pub fn PxHeightField_getFormat(self_: *const PxHeightField, ) -> PxHeightFieldFormat::Enum;
pub fn PxHeightField_getSampleStride(self_: *const PxHeightField, ) -> u32;
pub fn PxHeightField_getConvexEdgeThreshold(self_: *const PxHeightField, ) -> f32;
pub fn PxHeightField_getFlags(self_: *const PxHeightField, ) -> PxHeightFieldFlags;
pub fn PxHeightField_getHeight(self_: *const PxHeightField, x: f32, z: f32, ) -> f32;
pub fn PxHeightField_getReferenceCount(self_: *const PxHeightField, ) -> u32;
pub fn PxHeightField_acquireReference_mut(self_: *mut PxHeightField, ) -> ();
pub fn PxHeightField_getTriangleMaterialIndex(self_: *const PxHeightField, triangleIndex: u32, ) -> u16;
pub fn PxHeightField_getTriangleNormal(self_: *const PxHeightField, triangleIndex: u32, ) -> PxVec3;
pub fn PxHeightField_getSample(self_: *const PxHeightField, row: u32, column: u32, ) -> *const PxHeightFieldSample;
pub fn PxHeightField_getTimestamp(self_: *const PxHeightField, ) -> u32;
pub fn PxHeightField_getConcreteTypeName(self_: *const PxHeightField, ) -> *const i8;
pub fn PxHeightFieldDesc_new() -> PxHeightFieldDesc;
pub fn PxHeightFieldDesc_setToDefault_mut(self_: *mut PxHeightFieldDesc, ) -> ();
pub fn PxHeightFieldDesc_isValid(self_: *const PxHeightFieldDesc, ) -> bool;
pub fn PxHeightFieldDesc_new_1() -> PxHeightFieldDesc;
pub fn PxHeightFieldDesc_setToDefault_mut_1(self_: *mut PxHeightFieldDesc, ) -> ();
pub fn PxHeightFieldDesc_isValid_1(self_: *const PxHeightFieldDesc, ) -> bool;
pub fn PxMeshQuery_getTriangle_mut(triGeom: *const PxTriangleMeshGeometry, transform: *const PxTransform, triangleIndex: u32, triangle: *mut PxTriangle, vertexIndices: *mut u32, adjacencyIndices: *mut u32, ) -> ();
pub fn PxMeshQuery_getTriangle_mut_1(hfGeom: *const PxHeightFieldGeometry, transform: *const PxTransform, triangleIndex: u32, triangle: *mut PxTriangle, vertexIndices: *mut u32, adjacencyIndices: *mut u32, ) -> ();
pub fn PxMeshQuery_findOverlapTriangleMesh_mut(geom: *const PxGeometry, geomPose: *const PxTransform, meshGeom: *const PxTriangleMeshGeometry, meshPose: *const PxTransform, results: *mut u32, maxResults: u32, startIndex: u32, overflow: *mut bool, ) -> u32;
pub fn PxMeshQuery_findOverlapHeightField_mut(geom: *const PxGeometry, geomPose: *const PxTransform, hfGeom: *const PxHeightFieldGeometry, hfPose: *const PxTransform, results: *mut u32, maxResults: u32, startIndex: u32, overflow: *mut bool, ) -> u32;
pub fn PxMeshQuery_sweep_mut(unitDir: *const PxVec3, distance: f32, geom: *const PxGeometry, pose: *const PxTransform, triangleCount: u32, triangles: *const PxTriangle, sweepHit: *mut PxSweepHit, hitFlags: PxHitFlags, cachedIndex: *const u32, inflation: f32, doubleSided: bool, ) -> bool;
pub fn PxSimpleTriangleMesh_new() -> PxSimpleTriangleMesh;
pub fn PxSimpleTriangleMesh_setToDefault_mut(self_: *mut PxSimpleTriangleMesh, ) -> ();
pub fn PxSimpleTriangleMesh_isValid(self_: *const PxSimpleTriangleMesh, ) -> bool;
pub fn PxSimpleTriangleMesh_new_1() -> PxSimpleTriangleMesh;
pub fn PxSimpleTriangleMesh_setToDefault_mut_1(self_: *mut PxSimpleTriangleMesh, ) -> ();
pub fn PxSimpleTriangleMesh_isValid_1(self_: *const PxSimpleTriangleMesh, ) -> bool;
pub fn PxTriangle_new_alloc() -> *mut PxTriangle;
pub fn PxTriangle_new_alloc_1(p0: *const PxVec3, p1: *const PxVec3, p2: *const PxVec3, ) -> *mut PxTriangle;
pub fn PxTriangle_delete(self_: *mut PxTriangle, ) -> ();
pub fn PxTriangle_normal(self_: *const PxTriangle, _normal: *mut PxVec3, ) -> ();
pub fn PxTriangle_denormalizedNormal(self_: *const PxTriangle, _normal: *mut PxVec3, ) -> ();
pub fn PxTriangle_area(self_: *const PxTriangle, ) -> f32;
pub fn PxTriangle_pointFromUV(self_: *const PxTriangle, u: f32, v: f32, ) -> PxVec3;
pub fn PxTriangleMesh_getNbVertices(self_: *const PxTriangleMesh, ) -> u32;
pub fn PxTriangleMesh_getVertices(self_: *const PxTriangleMesh, ) -> *const PxVec3;
pub fn PxTriangleMesh_getVerticesForModification_mut(self_: *mut PxTriangleMesh, ) -> *mut PxVec3;
pub fn PxTriangleMesh_refitBVH_mut(self_: *mut PxTriangleMesh, ) -> PxBounds3;
pub fn PxTriangleMesh_getNbTriangles(self_: *const PxTriangleMesh, ) -> u32;
pub fn PxTriangleMesh_getTriangles(self_: *const PxTriangleMesh, ) -> *const std::ffi::c_void;
pub fn PxTriangleMesh_getTriangleMeshFlags(self_: *const PxTriangleMesh, ) -> PxTriangleMeshFlags;
pub fn PxTriangleMesh_getTrianglesRemap(self_: *const PxTriangleMesh, ) -> *const u32;
pub fn PxTriangleMesh_release_mut(self_: *mut PxTriangleMesh, ) -> ();
pub fn PxTriangleMesh_getTriangleMaterialIndex(self_: *const PxTriangleMesh, triangleIndex: u32, ) -> u16;
pub fn PxTriangleMesh_getLocalBounds(self_: *const PxTriangleMesh, ) -> PxBounds3;
pub fn PxTriangleMesh_getReferenceCount(self_: *const PxTriangleMesh, ) -> u32;
pub fn PxTriangleMesh_acquireReference_mut(self_: *mut PxTriangleMesh, ) -> ();
pub fn PxActor_release_mut(self_: *mut PxActor, ) -> ();
pub fn PxActor_getType(self_: *const PxActor, ) -> PxActorType::Enum;
pub fn PxActor_getScene(self_: *const PxActor, ) -> *mut PxScene;
pub fn PxActor_setName_mut(self_: *mut PxActor, name: *const i8, ) -> ();
pub fn PxActor_getName(self_: *const PxActor, ) -> *const i8;
pub fn PxActor_getWorldBounds(self_: *const PxActor, inflation: f32, ) -> PxBounds3;
pub fn PxActor_setActorFlag_mut(self_: *mut PxActor, flag: PxActorFlag::Enum, value: bool, ) -> ();
pub fn PxActor_setActorFlags_mut(self_: *mut PxActor, inFlags: PxActorFlags, ) -> ();
pub fn PxActor_getActorFlags(self_: *const PxActor, ) -> PxActorFlags;
pub fn PxActor_setDominanceGroup_mut(self_: *mut PxActor, dominanceGroup: u8, ) -> ();
pub fn PxActor_getDominanceGroup(self_: *const PxActor, ) -> u8;
pub fn PxActor_setOwnerClient_mut(self_: *mut PxActor, inClient: u8, ) -> ();
pub fn PxActor_getOwnerClient(self_: *const PxActor, ) -> u8;
pub fn PxActor_getAggregate(self_: *const PxActor, ) -> *mut PxAggregate;
pub fn PxAggregate_release_mut(self_: *mut PxAggregate, ) -> ();
pub fn PxAggregate_addActor_mut(self_: *mut PxAggregate, actor: *mut PxActor, bvhStructure: *const PxBVHStructure, ) -> bool;
pub fn PxAggregate_removeActor_mut(self_: *mut PxAggregate, actor: *mut PxActor, ) -> bool;
pub fn PxAggregate_addArticulation_mut(self_: *mut PxAggregate, articulation: *mut PxArticulationBase, ) -> bool;
pub fn PxAggregate_removeArticulation_mut(self_: *mut PxAggregate, articulation: *mut PxArticulationBase, ) -> bool;
pub fn PxAggregate_getNbActors(self_: *const PxAggregate, ) -> u32;
pub fn PxAggregate_getMaxNbActors(self_: *const PxAggregate, ) -> u32;
pub fn PxAggregate_getActors(self_: *const PxAggregate, userBuffer: *mut *mut PxActor, bufferSize: u32, startIndex: u32, ) -> u32;
pub fn PxAggregate_getScene_mut(self_: *mut PxAggregate, ) -> *mut PxScene;
pub fn PxAggregate_getSelfCollision(self_: *const PxAggregate, ) -> bool;
pub fn PxAggregate_getConcreteTypeName(self_: *const PxAggregate, ) -> *const i8;
pub fn PxArticulationBase_getScene(self_: *const PxArticulationBase, ) -> *mut PxScene;
pub fn PxArticulationBase_setSolverIterationCounts_mut(self_: *mut PxArticulationBase, minPositionIters: u32, minVelocityIters: u32, ) -> ();
pub fn PxArticulationBase_getSolverIterationCounts(self_: *const PxArticulationBase, minPositionIters: *mut u32, minVelocityIters: *mut u32, ) -> ();
pub fn PxArticulationBase_isSleeping(self_: *const PxArticulationBase, ) -> bool;
pub fn PxArticulationBase_setSleepThreshold_mut(self_: *mut PxArticulationBase, threshold: f32, ) -> ();
pub fn PxArticulationBase_getSleepThreshold(self_: *const PxArticulationBase, ) -> f32;
pub fn PxArticulationBase_setStabilizationThreshold_mut(self_: *mut PxArticulationBase, threshold: f32, ) -> ();
pub fn PxArticulationBase_getStabilizationThreshold(self_: *const PxArticulationBase, ) -> f32;
pub fn PxArticulationBase_setWakeCounter_mut(self_: *mut PxArticulationBase, wakeCounterValue: f32, ) -> ();
pub fn PxArticulationBase_getWakeCounter(self_: *const PxArticulationBase, ) -> f32;
pub fn PxArticulationBase_wakeUp_mut(self_: *mut PxArticulationBase, ) -> ();
pub fn PxArticulationBase_putToSleep_mut(self_: *mut PxArticulationBase, ) -> ();
pub fn PxArticulationBase_createLink_mut(self_: *mut PxArticulationBase, parent: *mut PxArticulationLink, pose: *const PxTransform, ) -> *mut PxArticulationLink;
pub fn PxArticulationBase_getNbLinks(self_: *const PxArticulationBase, ) -> u32;
pub fn PxArticulationBase_getLinks(self_: *const PxArticulationBase, userBuffer: *mut *mut PxArticulationLink, bufferSize: u32, startIndex: u32, ) -> u32;
pub fn PxArticulationBase_setName_mut(self_: *mut PxArticulationBase, name: *const i8, ) -> ();
pub fn PxArticulationBase_getName(self_: *const PxArticulationBase, ) -> *const i8;
pub fn PxArticulationBase_getWorldBounds(self_: *const PxArticulationBase, inflation: f32, ) -> PxBounds3;
pub fn PxArticulationBase_getAggregate(self_: *const PxArticulationBase, ) -> *mut PxAggregate;
pub fn PxArticulationBase_getImpl_mut(self_: *mut PxArticulationBase, ) -> *mut PxArticulationImpl;
pub fn PxArticulationBase_getImpl(self_: *const PxArticulationBase, ) -> *const PxArticulationImpl;
pub fn PxArticulationBase_createArticulationJoint_mut(self_: *mut PxArticulationBase, parent: *mut PxArticulationLink, parentFrame: *const PxTransform, child: *mut PxArticulationLink, childFrame: *const PxTransform, ) -> *mut PxArticulationJointBase;
pub fn PxArticulationBase_releaseArticulationJoint_mut(self_: *mut PxArticulationBase, joint: *mut PxArticulationJointBase, ) -> ();
pub fn PxArticulation_release_mut(self_: *mut PxArticulation, ) -> ();
pub fn PxArticulation_setMaxProjectionIterations_mut(self_: *mut PxArticulation, iterations: u32, ) -> ();
pub fn PxArticulation_getMaxProjectionIterations(self_: *const PxArticulation, ) -> u32;
pub fn PxArticulation_setSeparationTolerance_mut(self_: *mut PxArticulation, tolerance: f32, ) -> ();
pub fn PxArticulation_getSeparationTolerance(self_: *const PxArticulation, ) -> f32;
pub fn PxArticulation_setInternalDriveIterations_mut(self_: *mut PxArticulation, iterations: u32, ) -> ();
pub fn PxArticulation_getInternalDriveIterations(self_: *const PxArticulation, ) -> u32;
pub fn PxArticulation_setExternalDriveIterations_mut(self_: *mut PxArticulation, iterations: u32, ) -> ();
pub fn PxArticulation_getExternalDriveIterations(self_: *const PxArticulation, ) -> u32;
pub fn PxArticulation_createDriveCache(self_: *const PxArticulation, compliance: f32, driveIterations: u32, ) -> *mut PxArticulationDriveCache;
pub fn PxArticulation_updateDriveCache(self_: *const PxArticulation, driveCache: *mut PxArticulationDriveCache, compliance: f32, driveIterations: u32, ) -> ();
pub fn PxArticulation_releaseDriveCache(self_: *const PxArticulation, driveCache: *mut PxArticulationDriveCache, ) -> ();
pub fn PxArticulation_applyImpulse_mut(self_: *mut PxArticulation, link: *mut PxArticulationLink, driveCache: *const PxArticulationDriveCache, linearImpulse: *const PxVec3, angularImpulse: *const PxVec3, ) -> ();
pub fn PxArticulation_computeImpulseResponse(self_: *const PxArticulation, link: *mut PxArticulationLink, linearResponse: *mut PxVec3, angularResponse: *mut PxVec3, driveCache: *const PxArticulationDriveCache, linearImpulse: *const PxVec3, angularImpulse: *const PxVec3, ) -> ();
pub fn PxConstraintInvMassScale_new() -> PxConstraintInvMassScale;
pub fn PxConstraintInvMassScale_new_1(lin0: f32, ang0: f32, lin1: f32, ang1: f32, ) -> PxConstraintInvMassScale;
pub fn PxConstraintVisualizer_visualizeJointFrames_mut(self_: *mut PxConstraintVisualizer, parent: *const PxTransform, child: *const PxTransform, ) -> ();
pub fn PxConstraintVisualizer_visualizeLinearLimit_mut(self_: *mut PxConstraintVisualizer, t0: *const PxTransform, t1: *const PxTransform, value: f32, active: bool, ) -> ();
pub fn PxConstraintVisualizer_visualizeAngularLimit_mut(self_: *mut PxConstraintVisualizer, t0: *const PxTransform, lower: f32, upper: f32, active: bool, ) -> ();
pub fn PxConstraintVisualizer_visualizeLimitCone_mut(self_: *mut PxConstraintVisualizer, t: *const PxTransform, tanQSwingY: f32, tanQSwingZ: f32, active: bool, ) -> ();
pub fn PxConstraintVisualizer_visualizeDoubleCone_mut(self_: *mut PxConstraintVisualizer, t: *const PxTransform, angle: f32, active: bool, ) -> ();
pub fn PxConstraintVisualizer_visualizeLine_mut(self_: *mut PxConstraintVisualizer, p0: *const PxVec3, p1: *const PxVec3, color: u32, ) -> ();
pub fn PxConstraintConnector_prepareData_mut(self_: *mut PxConstraintConnector, ) -> *mut std::ffi::c_void;
pub fn PxConstraintConnector_updatePvdProperties(self_: *const PxConstraintConnector, pvdConnection: *mut PvdDataStream, c: *const PxConstraint, updateType: PxPvdUpdateType::Enum, ) -> bool;
pub fn PxConstraintConnector_onConstraintRelease_mut(self_: *mut PxConstraintConnector, ) -> ();
pub fn PxConstraintConnector_onComShift_mut(self_: *mut PxConstraintConnector, actor: u32, ) -> ();
pub fn PxConstraintConnector_onOriginShift_mut(self_: *mut PxConstraintConnector, shift: *const PxVec3, ) -> ();
pub fn PxConstraintConnector_getExternalReference_mut(self_: *mut PxConstraintConnector, typeID: *mut u32, ) -> *mut std::ffi::c_void;
pub fn PxConstraintConnector_getSerializable_mut(self_: *mut PxConstraintConnector, ) -> *mut PxBase;
pub fn PxConstraintConnector_getPrep(self_: *const PxConstraintConnector, ) -> *mut std::ffi::c_void;
pub fn PxConstraintConnector_getConstantBlock(self_: *const PxConstraintConnector, ) -> *const std::ffi::c_void;
pub fn PxConstraintConnector_delete(self_: *mut PxConstraintConnector, ) -> ();
pub fn PxSolverBody_new() -> PxSolverBody;
pub fn PxSolverBodyData_projectVelocity(self_: *const PxSolverBodyData, lin: *const PxVec3, ang: *const PxVec3, ) -> f32;
pub fn PxConstraintAllocator_reserveConstraintData_mut(self_: *mut PxConstraintAllocator, byteSize: u32, ) -> *mut u8;
pub fn PxConstraintAllocator_reserveFrictionData_mut(self_: *mut PxConstraintAllocator, byteSize: u32, ) -> *mut u8;
pub fn PxConstraintAllocator_delete(self_: *mut PxConstraintAllocator, ) -> ();
pub fn PxTGSSolverBodyVel_projectVelocity(self_: *const PxTGSSolverBodyVel, lin: *const PxVec3, ang: *const PxVec3, ) -> f32;
pub fn PxTGSSolverBodyData_projectVelocity(self_: *const PxTGSSolverBodyData, linear: *const PxVec3, angular: *const PxVec3, ) -> f32;
pub fn PxArticulationCache_new() -> PxArticulationCache;
pub fn PxArticulationReducedCoordinate_release_mut(self_: *mut PxArticulationReducedCoordinate, ) -> ();
pub fn PxArticulationReducedCoordinate_setArticulationFlags_mut(self_: *mut PxArticulationReducedCoordinate, flags: PxArticulationFlags, ) -> ();
pub fn PxArticulationReducedCoordinate_setArticulationFlag_mut(self_: *mut PxArticulationReducedCoordinate, flag: PxArticulationFlag::Enum, value: bool, ) -> ();
pub fn PxArticulationReducedCoordinate_getArticulationFlags(self_: *const PxArticulationReducedCoordinate, ) -> PxArticulationFlags;
pub fn PxArticulationReducedCoordinate_getDofs(self_: *const PxArticulationReducedCoordinate, ) -> u32;
pub fn PxArticulationReducedCoordinate_createCache(self_: *const PxArticulationReducedCoordinate, ) -> *mut PxArticulationCache;
pub fn PxArticulationReducedCoordinate_getCacheDataSize(self_: *const PxArticulationReducedCoordinate, ) -> u32;
pub fn PxArticulationReducedCoordinate_zeroCache_mut(self_: *mut PxArticulationReducedCoordinate, cache: *mut PxArticulationCache, ) -> ();
pub fn PxArticulationReducedCoordinate_applyCache_mut(self_: *mut PxArticulationReducedCoordinate, cache: *mut PxArticulationCache, flag: PxArticulationCacheFlags, autowake: bool, ) -> ();
pub fn PxArticulationReducedCoordinate_copyInternalStateToCache(self_: *const PxArticulationReducedCoordinate, cache: *mut PxArticulationCache, flag: PxArticulationCacheFlags, ) -> ();
pub fn PxArticulationReducedCoordinate_releaseCache(self_: *const PxArticulationReducedCoordinate, cache: *mut PxArticulationCache, ) -> ();
pub fn PxArticulationReducedCoordinate_packJointData(self_: *const PxArticulationReducedCoordinate, maximum: *const f32, reduced: *mut f32, ) -> ();
pub fn PxArticulationReducedCoordinate_unpackJointData(self_: *const PxArticulationReducedCoordinate, reduced: *const f32, maximum: *mut f32, ) -> ();
pub fn PxArticulationReducedCoordinate_commonInit(self_: *const PxArticulationReducedCoordinate, ) -> ();
pub fn PxArticulationReducedCoordinate_computeGeneralizedGravityForce(self_: *const PxArticulationReducedCoordinate, cache: *mut PxArticulationCache, ) -> ();
pub fn PxArticulationReducedCoordinate_computeCoriolisAndCentrifugalForce(self_: *const PxArticulationReducedCoordinate, cache: *mut PxArticulationCache, ) -> ();
pub fn PxArticulationReducedCoordinate_computeGeneralizedExternalForce(self_: *const PxArticulationReducedCoordinate, cache: *mut PxArticulationCache, ) -> ();
pub fn PxArticulationReducedCoordinate_computeJointAcceleration(self_: *const PxArticulationReducedCoordinate, cache: *mut PxArticulationCache, ) -> ();
pub fn PxArticulationReducedCoordinate_computeJointForce(self_: *const PxArticulationReducedCoordinate, cache: *mut PxArticulationCache, ) -> ();
pub fn PxArticulationReducedCoordinate_computeDenseJacobian(self_: *const PxArticulationReducedCoordinate, cache: *mut PxArticulationCache, nRows: *mut u32, nCols: *mut u32, ) -> ();
pub fn PxArticulationReducedCoordinate_computeCoefficientMatrix(self_: *const PxArticulationReducedCoordinate, cache: *mut PxArticulationCache, ) -> ();
pub fn PxArticulationReducedCoordinate_computeLambda(self_: *const PxArticulationReducedCoordinate, cache: *mut PxArticulationCache, initialState: *mut PxArticulationCache, jointTorque: *const f32, maxIter: u32, ) -> bool;
pub fn PxArticulationReducedCoordinate_computeGeneralizedMassMatrix(self_: *const PxArticulationReducedCoordinate, cache: *mut PxArticulationCache, ) -> ();
pub fn PxArticulationReducedCoordinate_addLoopJoint_mut(self_: *mut PxArticulationReducedCoordinate, joint: *mut PxJoint, ) -> ();
pub fn PxArticulationReducedCoordinate_removeLoopJoint_mut(self_: *mut PxArticulationReducedCoordinate, joint: *mut PxJoint, ) -> ();
pub fn PxArticulationReducedCoordinate_getNbLoopJoints(self_: *const PxArticulationReducedCoordinate, ) -> u32;
pub fn PxArticulationReducedCoordinate_getLoopJoints(self_: *const PxArticulationReducedCoordinate, userBuffer: *mut *mut PxJoint, bufferSize: u32, startIndex: u32, ) -> u32;
pub fn PxArticulationReducedCoordinate_getCoefficientMatrixSize(self_: *const PxArticulationReducedCoordinate, ) -> u32;
pub fn PxArticulationReducedCoordinate_teleportRootLink_mut(self_: *mut PxArticulationReducedCoordinate, pose: *const PxTransform, autowake: bool, ) -> ();
pub fn PxArticulationReducedCoordinate_getLinkVelocity_mut(self_: *mut PxArticulationReducedCoordinate, linkId: u32, ) -> PxSpatialVelocity;
pub fn PxArticulationReducedCoordinate_getLinkAcceleration_mut(self_: *mut PxArticulationReducedCoordinate, linkId: u32, ) -> PxSpatialVelocity;
pub fn PxArticulationJointBase_getParentArticulationLink(self_: *const PxArticulationJointBase, ) -> *mut PxArticulationLink;
pub fn PxArticulationJointBase_setParentPose_mut(self_: *mut PxArticulationJointBase, pose: *const PxTransform, ) -> ();
pub fn PxArticulationJointBase_getParentPose(self_: *const PxArticulationJointBase, ) -> PxTransform;
pub fn PxArticulationJointBase_getChildArticulationLink(self_: *const PxArticulationJointBase, ) -> *mut PxArticulationLink;
pub fn PxArticulationJointBase_setChildPose_mut(self_: *mut PxArticulationJointBase, pose: *const PxTransform, ) -> ();
pub fn PxArticulationJointBase_getChildPose(self_: *const PxArticulationJointBase, ) -> PxTransform;
pub fn PxArticulationJointBase_getImpl_mut(self_: *mut PxArticulationJointBase, ) -> *mut PxArticulationJointImpl;
pub fn PxArticulationJointBase_getImpl(self_: *const PxArticulationJointBase, ) -> *const PxArticulationJointImpl;
pub fn PxArticulationJoint_setTargetOrientation_mut(self_: *mut PxArticulationJoint, orientation: *const PxQuat, ) -> ();
pub fn PxArticulationJoint_getTargetOrientation(self_: *const PxArticulationJoint, ) -> PxQuat;
pub fn PxArticulationJoint_setTargetVelocity_mut(self_: *mut PxArticulationJoint, velocity: *const PxVec3, ) -> ();
pub fn PxArticulationJoint_getTargetVelocity(self_: *const PxArticulationJoint, ) -> PxVec3;
pub fn PxArticulationJoint_setDriveType_mut(self_: *mut PxArticulationJoint, driveType: PxArticulationJointDriveType::Enum, ) -> ();
pub fn PxArticulationJoint_getDriveType(self_: *const PxArticulationJoint, ) -> PxArticulationJointDriveType::Enum;
pub fn PxArticulationJoint_setStiffness_mut(self_: *mut PxArticulationJoint, spring: f32, ) -> ();
pub fn PxArticulationJoint_getStiffness(self_: *const PxArticulationJoint, ) -> f32;
pub fn PxArticulationJoint_setDamping_mut(self_: *mut PxArticulationJoint, damping: f32, ) -> ();
pub fn PxArticulationJoint_getDamping(self_: *const PxArticulationJoint, ) -> f32;
pub fn PxArticulationJoint_setInternalCompliance_mut(self_: *mut PxArticulationJoint, compliance: f32, ) -> ();
pub fn PxArticulationJoint_getInternalCompliance(self_: *const PxArticulationJoint, ) -> f32;
pub fn PxArticulationJoint_setExternalCompliance_mut(self_: *mut PxArticulationJoint, compliance: f32, ) -> ();
pub fn PxArticulationJoint_getExternalCompliance(self_: *const PxArticulationJoint, ) -> f32;
pub fn PxArticulationJoint_setSwingLimit_mut(self_: *mut PxArticulationJoint, zLimit: f32, yLimit: f32, ) -> ();
pub fn PxArticulationJoint_getSwingLimit(self_: *const PxArticulationJoint, zLimit: *mut f32, yLimit: *mut f32, ) -> ();
pub fn PxArticulationJoint_setTangentialStiffness_mut(self_: *mut PxArticulationJoint, spring: f32, ) -> ();
pub fn PxArticulationJoint_getTangentialStiffness(self_: *const PxArticulationJoint, ) -> f32;
pub fn PxArticulationJoint_setTangentialDamping_mut(self_: *mut PxArticulationJoint, damping: f32, ) -> ();
pub fn PxArticulationJoint_getTangentialDamping(self_: *const PxArticulationJoint, ) -> f32;
pub fn PxArticulationJoint_setSwingLimitContactDistance_mut(self_: *mut PxArticulationJoint, contactDistance: f32, ) -> ();
pub fn PxArticulationJoint_getSwingLimitContactDistance(self_: *const PxArticulationJoint, ) -> f32;
pub fn PxArticulationJoint_setSwingLimitEnabled_mut(self_: *mut PxArticulationJoint, enabled: bool, ) -> ();
pub fn PxArticulationJoint_getSwingLimitEnabled(self_: *const PxArticulationJoint, ) -> bool;
pub fn PxArticulationJoint_setTwistLimit_mut(self_: *mut PxArticulationJoint, lower: f32, upper: f32, ) -> ();
pub fn PxArticulationJoint_getTwistLimit(self_: *const PxArticulationJoint, lower: *mut f32, upper: *mut f32, ) -> ();
pub fn PxArticulationJoint_setTwistLimitEnabled_mut(self_: *mut PxArticulationJoint, enabled: bool, ) -> ();
pub fn PxArticulationJoint_getTwistLimitEnabled(self_: *const PxArticulationJoint, ) -> bool;
pub fn PxArticulationJoint_setTwistLimitContactDistance_mut(self_: *mut PxArticulationJoint, contactDistance: f32, ) -> ();
pub fn PxArticulationJoint_getTwistLimitContactDistance(self_: *const PxArticulationJoint, ) -> f32;
pub fn PxArticulationJoint_getConcreteTypeName(self_: *const PxArticulationJoint, ) -> *const i8;
pub fn PxArticulationJointReducedCoordinate_setJointType_mut(self_: *mut PxArticulationJointReducedCoordinate, jointType: PxArticulationJointType::Enum, ) -> ();
pub fn PxArticulationJointReducedCoordinate_getJointType(self_: *const PxArticulationJointReducedCoordinate, ) -> PxArticulationJointType::Enum;
pub fn PxArticulationJointReducedCoordinate_setMotion_mut(self_: *mut PxArticulationJointReducedCoordinate, axis: PxArticulationAxis::Enum, motion: PxArticulationMotion::Enum, ) -> ();
pub fn PxArticulationJointReducedCoordinate_getMotion(self_: *const PxArticulationJointReducedCoordinate, axis: PxArticulationAxis::Enum, ) -> PxArticulationMotion::Enum;
pub fn PxArticulationJointReducedCoordinate_setLimit_mut(self_: *mut PxArticulationJointReducedCoordinate, axis: PxArticulationAxis::Enum, lowLimit: f32, highLimit: f32, ) -> ();
pub fn PxArticulationJointReducedCoordinate_getLimit_mut(self_: *mut PxArticulationJointReducedCoordinate, axis: PxArticulationAxis::Enum, lowLimit: *mut f32, highLimit: *mut f32, ) -> ();
pub fn PxArticulationJointReducedCoordinate_setDrive_mut(self_: *mut PxArticulationJointReducedCoordinate, axis: PxArticulationAxis::Enum, stiffness: f32, damping: f32, maxForce: f32, driveType: PxArticulationDriveType::Enum, ) -> ();
pub fn PxArticulationJointReducedCoordinate_getDrive_mut(self_: *mut PxArticulationJointReducedCoordinate, axis: PxArticulationAxis::Enum, stiffness: *mut f32, damping: *mut f32, maxForce: *mut f32, driveType: *mut PxArticulationDriveType::Enum, ) -> ();
pub fn PxArticulationJointReducedCoordinate_setDriveTarget_mut(self_: *mut PxArticulationJointReducedCoordinate, axis: PxArticulationAxis::Enum, target: f32, ) -> ();
pub fn PxArticulationJointReducedCoordinate_setDriveVelocity_mut(self_: *mut PxArticulationJointReducedCoordinate, axis: PxArticulationAxis::Enum, targetVel: f32, ) -> ();
pub fn PxArticulationJointReducedCoordinate_getDriveTarget_mut(self_: *mut PxArticulationJointReducedCoordinate, axis: PxArticulationAxis::Enum, ) -> f32;
pub fn PxArticulationJointReducedCoordinate_getDriveVelocity_mut(self_: *mut PxArticulationJointReducedCoordinate, axis: PxArticulationAxis::Enum, ) -> f32;
pub fn PxArticulationJointReducedCoordinate_setFrictionCoefficient_mut(self_: *mut PxArticulationJointReducedCoordinate, coefficient: f32, ) -> ();
pub fn PxArticulationJointReducedCoordinate_getFrictionCoefficient(self_: *const PxArticulationJointReducedCoordinate, ) -> f32;
pub fn PxArticulationJointReducedCoordinate_getConcreteTypeName(self_: *const PxArticulationJointReducedCoordinate, ) -> *const i8;
pub fn PxArticulationJointReducedCoordinate_setMaxJointVelocity_mut(self_: *mut PxArticulationJointReducedCoordinate, maxJointV: f32, ) -> ();
pub fn PxArticulationJointReducedCoordinate_getMaxJointVelocity(self_: *const PxArticulationJointReducedCoordinate, ) -> f32;
pub fn PxShape_release_mut(self_: *mut PxShape, ) -> ();
pub fn PxShape_getReferenceCount(self_: *const PxShape, ) -> u32;
pub fn PxShape_acquireReference_mut(self_: *mut PxShape, ) -> ();
pub fn PxShape_getGeometryType(self_: *const PxShape, ) -> PxGeometryType::Enum;
pub fn PxShape_setGeometry_mut(self_: *mut PxShape, geometry: *const PxGeometry, ) -> ();
pub fn PxShape_getGeometry(self_: *const PxShape, ) -> PxGeometryHolder;
pub fn PxShape_getBoxGeometry(self_: *const PxShape, geometry: *mut PxBoxGeometry, ) -> bool;
pub fn PxShape_getSphereGeometry(self_: *const PxShape, geometry: *mut PxSphereGeometry, ) -> bool;
pub fn PxShape_getCapsuleGeometry(self_: *const PxShape, geometry: *mut PxCapsuleGeometry, ) -> bool;
pub fn PxShape_getPlaneGeometry(self_: *const PxShape, geometry: *mut PxPlaneGeometry, ) -> bool;
pub fn PxShape_getConvexMeshGeometry(self_: *const PxShape, geometry: *mut PxConvexMeshGeometry, ) -> bool;
pub fn PxShape_getTriangleMeshGeometry(self_: *const PxShape, geometry: *mut PxTriangleMeshGeometry, ) -> bool;
pub fn PxShape_getHeightFieldGeometry(self_: *const PxShape, geometry: *mut PxHeightFieldGeometry, ) -> bool;
pub fn PxShape_getActor(self_: *const PxShape, ) -> *mut PxRigidActor;
pub fn PxShape_setLocalPose_mut(self_: *mut PxShape, pose: *const PxTransform, ) -> ();
pub fn PxShape_getLocalPose(self_: *const PxShape, ) -> PxTransform;
pub fn PxShape_setSimulationFilterData_mut(self_: *mut PxShape, data: *const PxFilterData, ) -> ();
pub fn PxShape_getSimulationFilterData(self_: *const PxShape, ) -> PxFilterData;
pub fn PxShape_setQueryFilterData_mut(self_: *mut PxShape, data: *const PxFilterData, ) -> ();
pub fn PxShape_getQueryFilterData(self_: *const PxShape, ) -> PxFilterData;
pub fn PxShape_setMaterials_mut(self_: *mut PxShape, materials: *const *mut PxMaterial, materialCount: u16, ) -> ();
pub fn PxShape_getNbMaterials(self_: *const PxShape, ) -> u16;
pub fn PxShape_getMaterials(self_: *const PxShape, userBuffer: *mut *mut PxMaterial, bufferSize: u32, startIndex: u32, ) -> u32;
pub fn PxShape_getMaterialFromInternalFaceIndex(self_: *const PxShape, faceIndex: u32, ) -> *mut PxMaterial;
pub fn PxShape_setContactOffset_mut(self_: *mut PxShape, contactOffset: f32, ) -> ();
pub fn PxShape_getContactOffset(self_: *const PxShape, ) -> f32;
pub fn PxShape_setRestOffset_mut(self_: *mut PxShape, restOffset: f32, ) -> ();
pub fn PxShape_getRestOffset(self_: *const PxShape, ) -> f32;
pub fn PxShape_setTorsionalPatchRadius_mut(self_: *mut PxShape, radius: f32, ) -> ();
pub fn PxShape_getTorsionalPatchRadius(self_: *const PxShape, ) -> f32;
pub fn PxShape_setMinTorsionalPatchRadius_mut(self_: *mut PxShape, radius: f32, ) -> ();
pub fn PxShape_getMinTorsionalPatchRadius(self_: *const PxShape, ) -> f32;
pub fn PxShape_setFlag_mut(self_: *mut PxShape, flag: PxShapeFlag::Enum, value: bool, ) -> ();
pub fn PxShape_setFlags_mut(self_: *mut PxShape, inFlags: PxShapeFlags, ) -> ();
pub fn PxShape_getFlags(self_: *const PxShape, ) -> PxShapeFlags;
pub fn PxShape_isExclusive(self_: *const PxShape, ) -> bool;
pub fn PxShape_setName_mut(self_: *mut PxShape, name: *const i8, ) -> ();
pub fn PxShape_getName(self_: *const PxShape, ) -> *const i8;
pub fn PxShape_getConcreteTypeName(self_: *const PxShape, ) -> *const i8;
pub fn PxRigidActor_release_mut(self_: *mut PxRigidActor, ) -> ();
pub fn PxRigidActor_getGlobalPose(self_: *const PxRigidActor, ) -> PxTransform;
pub fn PxRigidActor_setGlobalPose_mut(self_: *mut PxRigidActor, pose: *const PxTransform, autowake: bool, ) -> ();
pub fn PxRigidActor_attachShape_mut(self_: *mut PxRigidActor, shape: *mut PxShape, ) -> bool;
pub fn PxRigidActor_detachShape_mut(self_: *mut PxRigidActor, shape: *mut PxShape, wakeOnLostTouch: bool, ) -> ();
pub fn PxRigidActor_getNbShapes(self_: *const PxRigidActor, ) -> u32;
pub fn PxRigidActor_getShapes(self_: *const PxRigidActor, userBuffer: *mut *mut PxShape, bufferSize: u32, startIndex: u32, ) -> u32;
pub fn PxRigidActor_getNbConstraints(self_: *const PxRigidActor, ) -> u32;
pub fn PxRigidActor_getConstraints(self_: *const PxRigidActor, userBuffer: *mut *mut PxConstraint, bufferSize: u32, startIndex: u32, ) -> u32;
pub fn PxRigidBody_setCMassLocalPose_mut(self_: *mut PxRigidBody, pose: *const PxTransform, ) -> ();
pub fn PxRigidBody_getCMassLocalPose(self_: *const PxRigidBody, ) -> PxTransform;
pub fn PxRigidBody_setMass_mut(self_: *mut PxRigidBody, mass: f32, ) -> ();
pub fn PxRigidBody_getMass(self_: *const PxRigidBody, ) -> f32;
pub fn PxRigidBody_getInvMass(self_: *const PxRigidBody, ) -> f32;
pub fn PxRigidBody_setMassSpaceInertiaTensor_mut(self_: *mut PxRigidBody, m: *const PxVec3, ) -> ();
pub fn PxRigidBody_getMassSpaceInertiaTensor(self_: *const PxRigidBody, ) -> PxVec3;
pub fn PxRigidBody_getMassSpaceInvInertiaTensor(self_: *const PxRigidBody, ) -> PxVec3;
pub fn PxRigidBody_setLinearDamping_mut(self_: *mut PxRigidBody, linDamp: f32, ) -> ();
pub fn PxRigidBody_getLinearDamping(self_: *const PxRigidBody, ) -> f32;
pub fn PxRigidBody_setAngularDamping_mut(self_: *mut PxRigidBody, angDamp: f32, ) -> ();
pub fn PxRigidBody_getAngularDamping(self_: *const PxRigidBody, ) -> f32;
pub fn PxRigidBody_getLinearVelocity(self_: *const PxRigidBody, ) -> PxVec3;
pub fn PxRigidBody_setLinearVelocity_mut(self_: *mut PxRigidBody, linVel: *const PxVec3, autowake: bool, ) -> ();
pub fn PxRigidBody_getAngularVelocity(self_: *const PxRigidBody, ) -> PxVec3;
pub fn PxRigidBody_setAngularVelocity_mut(self_: *mut PxRigidBody, angVel: *const PxVec3, autowake: bool, ) -> ();
pub fn PxRigidBody_setMaxAngularVelocity_mut(self_: *mut PxRigidBody, maxAngVel: f32, ) -> ();
pub fn PxRigidBody_getMaxAngularVelocity(self_: *const PxRigidBody, ) -> f32;
pub fn PxRigidBody_setMaxLinearVelocity_mut(self_: *mut PxRigidBody, maxLinVel: f32, ) -> ();
pub fn PxRigidBody_getMaxLinearVelocity(self_: *const PxRigidBody, ) -> f32;
pub fn PxRigidBody_addForce_mut(self_: *mut PxRigidBody, force: *const PxVec3, mode: PxForceMode::Enum, autowake: bool, ) -> ();
pub fn PxRigidBody_addTorque_mut(self_: *mut PxRigidBody, torque: *const PxVec3, mode: PxForceMode::Enum, autowake: bool, ) -> ();
pub fn PxRigidBody_clearForce_mut(self_: *mut PxRigidBody, mode: PxForceMode::Enum, ) -> ();
pub fn PxRigidBody_clearTorque_mut(self_: *mut PxRigidBody, mode: PxForceMode::Enum, ) -> ();
pub fn PxRigidBody_setForceAndTorque_mut(self_: *mut PxRigidBody, force: *const PxVec3, torque: *const PxVec3, mode: PxForceMode::Enum, ) -> ();
pub fn PxRigidBody_setRigidBodyFlag_mut(self_: *mut PxRigidBody, flag: PxRigidBodyFlag::Enum, value: bool, ) -> ();
pub fn PxRigidBody_setRigidBodyFlags_mut(self_: *mut PxRigidBody, inFlags: PxRigidBodyFlags, ) -> ();
pub fn PxRigidBody_getRigidBodyFlags(self_: *const PxRigidBody, ) -> PxRigidBodyFlags;
pub fn PxRigidBody_setMinCCDAdvanceCoefficient_mut(self_: *mut PxRigidBody, advanceCoefficient: f32, ) -> ();
pub fn PxRigidBody_getMinCCDAdvanceCoefficient(self_: *const PxRigidBody, ) -> f32;
pub fn PxRigidBody_setMaxDepenetrationVelocity_mut(self_: *mut PxRigidBody, biasClamp: f32, ) -> ();
pub fn PxRigidBody_getMaxDepenetrationVelocity(self_: *const PxRigidBody, ) -> f32;
pub fn PxRigidBody_setMaxContactImpulse_mut(self_: *mut PxRigidBody, maxImpulse: f32, ) -> ();
pub fn PxRigidBody_getMaxContactImpulse(self_: *const PxRigidBody, ) -> f32;
pub fn PxRigidBody_getInternalIslandNodeIndex(self_: *const PxRigidBody, ) -> u32;
pub fn PxArticulationLink_release_mut(self_: *mut PxArticulationLink, ) -> ();
pub fn PxArticulationLink_getArticulation(self_: *const PxArticulationLink, ) -> *mut PxArticulationBase;
pub fn PxArticulationLink_getInboundJoint(self_: *const PxArticulationLink, ) -> *mut PxArticulationJointBase;
pub fn PxArticulationLink_getInboundJointDof(self_: *const PxArticulationLink, ) -> u32;
pub fn PxArticulationLink_getNbChildren(self_: *const PxArticulationLink, ) -> u32;
pub fn PxArticulationLink_getLinkIndex(self_: *const PxArticulationLink, ) -> u32;
pub fn PxArticulationLink_getChildren(self_: *const PxArticulationLink, userBuffer: *mut *mut PxArticulationLink, bufferSize: u32, startIndex: u32, ) -> u32;
pub fn PxArticulationLink_getConcreteTypeName(self_: *const PxArticulationLink, ) -> *const i8;
pub fn PxFilterData_new(anonymous_arg0: PxEMPTY, ) -> PxFilterData;
pub fn PxFilterData_new_1() -> PxFilterData;
pub fn PxFilterData_new_2(w0: u32, w1: u32, w2: u32, w3: u32, ) -> PxFilterData;
pub fn PxFilterData_setToDefault_mut(self_: *mut PxFilterData, ) -> ();
pub fn phys_PxGetFilterObjectType(attr: u32, ) -> PxFilterObjectType::Enum;
pub fn phys_PxFilterObjectIsKinematic(attr: u32, ) -> bool;
pub fn phys_PxFilterObjectIsTrigger(attr: u32, ) -> bool;
pub fn PxSimulationFilterCallback_pairFound_mut(self_: *mut PxSimulationFilterCallback, pairID: u32, attributes0: u32, filterData0: PxFilterData, a0: *const PxActor, s0: *const PxShape, attributes1: u32, filterData1: PxFilterData, a1: *const PxActor, s1: *const PxShape, pairFlags: *mut PxPairFlags, ) -> PxFilterFlags;
pub fn PxSimulationFilterCallback_pairLost_mut(self_: *mut PxSimulationFilterCallback, pairID: u32, attributes0: u32, filterData0: PxFilterData, attributes1: u32, filterData1: PxFilterData, objectRemoved: bool, ) -> ();
pub fn PxSimulationFilterCallback_statusChange_mut(self_: *mut PxSimulationFilterCallback, pairID: *mut u32, pairFlags: *mut PxPairFlags, filterFlags: *mut PxFilterFlags, ) -> bool;
pub fn PxQueryFilterData_new() -> PxQueryFilterData;
pub fn PxQueryFilterData_new_1(fd: *const PxFilterData, f: PxQueryFlags, ) -> PxQueryFilterData;
pub fn PxQueryFilterData_new_2(f: PxQueryFlags, ) -> PxQueryFilterData;
pub fn PxQueryFilterCallback_preFilter_mut(self_: *mut PxQueryFilterCallback, filterData: *const PxFilterData, shape: *const PxShape, actor: *const PxRigidActor, queryFlags: *mut PxHitFlags, ) -> PxQueryHitType::Enum;
pub fn PxQueryFilterCallback_postFilter_mut(self_: *mut PxQueryFilterCallback, filterData: *const PxFilterData, hit: *const PxQueryHit, ) -> PxQueryHitType::Enum;
pub fn PxQueryFilterCallback_delete(self_: *mut PxQueryFilterCallback, ) -> ();
pub fn PxBatchQueryMemory_getMaxRaycastsPerExecute(self_: *const PxBatchQueryMemory, ) -> u32;
pub fn PxBatchQueryMemory_getMaxSweepsPerExecute(self_: *const PxBatchQueryMemory, ) -> u32;
pub fn PxBatchQueryMemory_getMaxOverlapsPerExecute(self_: *const PxBatchQueryMemory, ) -> u32;
pub fn PxBatchQueryMemory_new(raycastResultBufferSize_: u32, sweepResultBufferSize_: u32, overlapResultBufferSize_: u32, ) -> PxBatchQueryMemory;
pub fn PxBatchQueryDesc_new(maxRaycastsPerExecute: u32, maxSweepsPerExecute: u32, maxOverlapsPerExecute: u32, ) -> PxBatchQueryDesc;
pub fn PxBatchQueryDesc_isValid(self_: *const PxBatchQueryDesc, ) -> bool;
pub fn PxBatchQueryDesc_new_1(maxRaycastsPerExecute: u32, maxSweepsPerExecute: u32, maxOverlapsPerExecute: u32, ) -> PxBatchQueryDesc;
pub fn PxBatchQueryDesc_isValid_1(self_: *const PxBatchQueryDesc, ) -> bool;
pub fn PxBatchQuery_execute_mut(self_: *mut PxBatchQuery, ) -> ();
pub fn PxBatchQuery_getPreFilterShader(self_: *const PxBatchQuery, ) -> *mut std::ffi::c_void;
pub fn PxBatchQuery_getPostFilterShader(self_: *const PxBatchQuery, ) -> *mut std::ffi::c_void;
pub fn PxBatchQuery_getFilterShaderData(self_: *const PxBatchQuery, ) -> *const std::ffi::c_void;
pub fn PxBatchQuery_getFilterShaderDataSize(self_: *const PxBatchQuery, ) -> u32;
pub fn PxBatchQuery_setUserMemory_mut(self_: *mut PxBatchQuery, anonymous_arg0: *const PxBatchQueryMemory, ) -> ();
pub fn PxBatchQuery_getUserMemory_mut(self_: *mut PxBatchQuery, ) -> *const PxBatchQueryMemory;
pub fn PxBatchQuery_release_mut(self_: *mut PxBatchQuery, ) -> ();
pub fn PxBatchQuery_raycast_mut(self_: *mut PxBatchQuery, origin: *const PxVec3, unitDir: *const PxVec3, distance: f32, maxTouchHits: u16, hitFlags: PxHitFlags, filterData: *const PxQueryFilterData, userData: *mut std::ffi::c_void, cache: *const PxQueryCache, ) -> ();
pub fn PxBatchQuery_overlap_mut(self_: *mut PxBatchQuery, geometry: *const PxGeometry, pose: *const PxTransform, maxTouchHits: u16, filterData: *const PxQueryFilterData, userData: *mut std::ffi::c_void, cache: *const PxQueryCache, ) -> ();
pub fn PxBatchQuery_sweep_mut(self_: *mut PxBatchQuery, geometry: *const PxGeometry, pose: *const PxTransform, unitDir: *const PxVec3, distance: f32, maxTouchHits: u16, hitFlags: PxHitFlags, filterData: *const PxQueryFilterData, userData: *mut std::ffi::c_void, cache: *const PxQueryCache, inflation: f32, ) -> ();
pub fn PxConstraint_release_mut(self_: *mut PxConstraint, ) -> ();
pub fn PxConstraint_getScene(self_: *const PxConstraint, ) -> *mut PxScene;
pub fn PxConstraint_getActors(self_: *const PxConstraint, actor0: *mut *mut PxRigidActor, actor1: *mut *mut PxRigidActor, ) -> ();
pub fn PxConstraint_setActors_mut(self_: *mut PxConstraint, actor0: *mut PxRigidActor, actor1: *mut PxRigidActor, ) -> ();
pub fn PxConstraint_markDirty_mut(self_: *mut PxConstraint, ) -> ();
pub fn PxConstraint_setFlags_mut(self_: *mut PxConstraint, flags: PxConstraintFlags, ) -> ();
pub fn PxConstraint_getFlags(self_: *const PxConstraint, ) -> PxConstraintFlags;
pub fn PxConstraint_setFlag_mut(self_: *mut PxConstraint, flag: PxConstraintFlag::Enum, value: bool, ) -> ();
pub fn PxConstraint_getForce(self_: *const PxConstraint, linear: *mut PxVec3, angular: *mut PxVec3, ) -> ();
pub fn PxConstraint_isValid(self_: *const PxConstraint, ) -> bool;
pub fn PxConstraint_setBreakForce_mut(self_: *mut PxConstraint, linear: f32, angular: f32, ) -> ();
pub fn PxConstraint_getBreakForce(self_: *const PxConstraint, linear: *mut f32, angular: *mut f32, ) -> ();
pub fn PxConstraint_setMinResponseThreshold_mut(self_: *mut PxConstraint, threshold: f32, ) -> ();
pub fn PxConstraint_getMinResponseThreshold(self_: *const PxConstraint, ) -> f32;
pub fn PxConstraint_getExternalReference_mut(self_: *mut PxConstraint, typeID: *mut u32, ) -> *mut std::ffi::c_void;
pub fn PxConstraint_setConstraintFunctions_mut(self_: *mut PxConstraint, connector: *mut PxConstraintConnector, shaders: *const PxConstraintShaderTable, ) -> ();
pub fn PxConstraint_getConcreteTypeName(self_: *const PxConstraint, ) -> *const i8;
pub fn PxContactStreamIterator_new(contactPatches: *const u8, contactPoints: *const u8, contactFaceIndices: *const u32, nbPatches: u32, nbContacts: u32, ) -> PxContactStreamIterator;
pub fn PxContactStreamIterator_hasNextPatch(self_: *const PxContactStreamIterator, ) -> bool;
pub fn PxContactStreamIterator_getTotalContactCount(self_: *const PxContactStreamIterator, ) -> u32;
pub fn PxContactStreamIterator_getTotalPatchCount(self_: *const PxContactStreamIterator, ) -> u32;
pub fn PxContactStreamIterator_nextPatch_mut(self_: *mut PxContactStreamIterator, ) -> ();
pub fn PxContactStreamIterator_hasNextContact(self_: *const PxContactStreamIterator, ) -> bool;
pub fn PxContactStreamIterator_nextContact_mut(self_: *mut PxContactStreamIterator, ) -> ();
pub fn PxContactStreamIterator_getContactNormal(self_: *const PxContactStreamIterator, ) -> *const PxVec3;
pub fn PxContactStreamIterator_getInvMassScale0(self_: *const PxContactStreamIterator, ) -> f32;
pub fn PxContactStreamIterator_getInvMassScale1(self_: *const PxContactStreamIterator, ) -> f32;
pub fn PxContactStreamIterator_getInvInertiaScale0(self_: *const PxContactStreamIterator, ) -> f32;
pub fn PxContactStreamIterator_getInvInertiaScale1(self_: *const PxContactStreamIterator, ) -> f32;
pub fn PxContactStreamIterator_getMaxImpulse(self_: *const PxContactStreamIterator, ) -> f32;
pub fn PxContactStreamIterator_getTargetVel(self_: *const PxContactStreamIterator, ) -> *const PxVec3;
pub fn PxContactStreamIterator_getContactPoint(self_: *const PxContactStreamIterator, ) -> *const PxVec3;
pub fn PxContactStreamIterator_getSeparation(self_: *const PxContactStreamIterator, ) -> f32;
pub fn PxContactStreamIterator_getFaceIndex0(self_: *const PxContactStreamIterator, ) -> u32;
pub fn PxContactStreamIterator_getFaceIndex1(self_: *const PxContactStreamIterator, ) -> u32;
pub fn PxContactStreamIterator_getStaticFriction(self_: *const PxContactStreamIterator, ) -> f32;
pub fn PxContactStreamIterator_getDynamicFriction(self_: *const PxContactStreamIterator, ) -> f32;
pub fn PxContactStreamIterator_getRestitution(self_: *const PxContactStreamIterator, ) -> f32;
pub fn PxContactStreamIterator_getMaterialFlags(self_: *const PxContactStreamIterator, ) -> u32;
pub fn PxContactStreamIterator_getMaterialIndex0(self_: *const PxContactStreamIterator, ) -> u16;
pub fn PxContactStreamIterator_getMaterialIndex1(self_: *const PxContactStreamIterator, ) -> u16;
pub fn PxContactStreamIterator_advanceToIndex_mut(self_: *mut PxContactStreamIterator, initialIndex: u32, ) -> bool;
pub fn PxContactSet_getPoint(self_: *const PxContactSet, i: u32, ) -> *const PxVec3;
pub fn PxContactSet_setPoint_mut(self_: *mut PxContactSet, i: u32, p: *const PxVec3, ) -> ();
pub fn PxContactSet_getNormal(self_: *const PxContactSet, i: u32, ) -> *const PxVec3;
pub fn PxContactSet_setNormal_mut(self_: *mut PxContactSet, i: u32, n: *const PxVec3, ) -> ();
pub fn PxContactSet_getSeparation(self_: *const PxContactSet, i: u32, ) -> f32;
pub fn PxContactSet_setSeparation_mut(self_: *mut PxContactSet, i: u32, s: f32, ) -> ();
pub fn PxContactSet_getTargetVelocity(self_: *const PxContactSet, i: u32, ) -> *const PxVec3;
pub fn PxContactSet_setTargetVelocity_mut(self_: *mut PxContactSet, i: u32, v: *const PxVec3, ) -> ();
pub fn PxContactSet_getInternalFaceIndex0_mut(self_: *mut PxContactSet, i: u32, ) -> u32;
pub fn PxContactSet_getInternalFaceIndex1_mut(self_: *mut PxContactSet, i: u32, ) -> u32;
pub fn PxContactSet_getMaxImpulse(self_: *const PxContactSet, i: u32, ) -> f32;
pub fn PxContactSet_setMaxImpulse_mut(self_: *mut PxContactSet, i: u32, s: f32, ) -> ();
pub fn PxContactSet_getRestitution(self_: *const PxContactSet, i: u32, ) -> f32;
pub fn PxContactSet_setRestitution_mut(self_: *mut PxContactSet, i: u32, r: f32, ) -> ();
pub fn PxContactSet_getStaticFriction(self_: *const PxContactSet, i: u32, ) -> f32;
pub fn PxContactSet_setStaticFriction_mut(self_: *mut PxContactSet, i: u32, f: f32, ) -> ();
pub fn PxContactSet_getDynamicFriction(self_: *const PxContactSet, i: u32, ) -> f32;
pub fn PxContactSet_setDynamicFriction_mut(self_: *mut PxContactSet, i: u32, f: f32, ) -> ();
pub fn PxContactSet_ignore_mut(self_: *mut PxContactSet, i: u32, ) -> ();
pub fn PxContactSet_size(self_: *const PxContactSet, ) -> u32;
pub fn PxContactSet_getInvMassScale0(self_: *const PxContactSet, ) -> f32;
pub fn PxContactSet_getInvMassScale1(self_: *const PxContactSet, ) -> f32;
pub fn PxContactSet_getInvInertiaScale0(self_: *const PxContactSet, ) -> f32;
pub fn PxContactSet_getInvInertiaScale1(self_: *const PxContactSet, ) -> f32;
pub fn PxContactSet_setInvMassScale0_mut(self_: *mut PxContactSet, scale: f32, ) -> ();
pub fn PxContactSet_setInvMassScale1_mut(self_: *mut PxContactSet, scale: f32, ) -> ();
pub fn PxContactSet_setInvInertiaScale0_mut(self_: *mut PxContactSet, scale: f32, ) -> ();
pub fn PxContactSet_setInvInertiaScale1_mut(self_: *mut PxContactSet, scale: f32, ) -> ();
pub fn PxContactModifyCallback_onContactModify_mut(self_: *mut PxContactModifyCallback, pairs: *mut PxContactModifyPair, count: u32, ) -> ();
pub fn PxCCDContactModifyCallback_onCCDContactModify_mut(self_: *mut PxCCDContactModifyCallback, pairs: *mut PxContactModifyPair, count: u32, ) -> ();
pub fn PxDeletionListener_onRelease_mut(self_: *mut PxDeletionListener, observed: *const PxBase, userData: *mut std::ffi::c_void, deletionEvent: PxDeletionEventFlag::Enum, ) -> ();
pub fn PxLockedData_getDataAccessFlags_mut(self_: *mut PxLockedData, ) -> PxDataAccessFlags;
pub fn PxLockedData_unlock_mut(self_: *mut PxLockedData, ) -> ();
pub fn PxLockedData_delete(self_: *mut PxLockedData, ) -> ();
pub fn PxMaterial_release_mut(self_: *mut PxMaterial, ) -> ();
pub fn PxMaterial_getReferenceCount(self_: *const PxMaterial, ) -> u32;
pub fn PxMaterial_acquireReference_mut(self_: *mut PxMaterial, ) -> ();
pub fn PxMaterial_setDynamicFriction_mut(self_: *mut PxMaterial, coef: f32, ) -> ();
pub fn PxMaterial_getDynamicFriction(self_: *const PxMaterial, ) -> f32;
pub fn PxMaterial_setStaticFriction_mut(self_: *mut PxMaterial, coef: f32, ) -> ();
pub fn PxMaterial_getStaticFriction(self_: *const PxMaterial, ) -> f32;
pub fn PxMaterial_setRestitution_mut(self_: *mut PxMaterial, rest: f32, ) -> ();
pub fn PxMaterial_getRestitution(self_: *const PxMaterial, ) -> f32;
pub fn PxMaterial_setFlag_mut(self_: *mut PxMaterial, flag: PxMaterialFlag::Enum, anonymous_arg1: bool, ) -> ();
pub fn PxMaterial_setFlags_mut(self_: *mut PxMaterial, inFlags: PxMaterialFlags, ) -> ();
pub fn PxMaterial_getFlags(self_: *const PxMaterial, ) -> PxMaterialFlags;
pub fn PxMaterial_setFrictionCombineMode_mut(self_: *mut PxMaterial, combMode: PxCombineMode::Enum, ) -> ();
pub fn PxMaterial_getFrictionCombineMode(self_: *const PxMaterial, ) -> PxCombineMode::Enum;
pub fn PxMaterial_setRestitutionCombineMode_mut(self_: *mut PxMaterial, combMode: PxCombineMode::Enum, ) -> ();
pub fn PxMaterial_getRestitutionCombineMode(self_: *const PxMaterial, ) -> PxCombineMode::Enum;
pub fn PxMaterial_getConcreteTypeName(self_: *const PxMaterial, ) -> *const i8;
pub fn PxPhysics_release_mut(self_: *mut PxPhysics, ) -> ();
pub fn PxPhysics_getFoundation_mut(self_: *mut PxPhysics, ) -> *mut PxFoundation;
pub fn PxPhysics_createAggregate_mut(self_: *mut PxPhysics, maxSize: u32, enableSelfCollision: bool, ) -> *mut PxAggregate;
pub fn PxPhysics_getTolerancesScale(self_: *const PxPhysics, ) -> *const PxTolerancesScale;
pub fn PxPhysics_createTriangleMesh_mut(self_: *mut PxPhysics, stream: *mut PxInputStream, ) -> *mut PxTriangleMesh;
pub fn PxPhysics_getNbTriangleMeshes(self_: *const PxPhysics, ) -> u32;
pub fn PxPhysics_getTriangleMeshes(self_: *const PxPhysics, userBuffer: *mut *mut PxTriangleMesh, bufferSize: u32, startIndex: u32, ) -> u32;
pub fn PxPhysics_createHeightField_mut(self_: *mut PxPhysics, stream: *mut PxInputStream, ) -> *mut PxHeightField;
pub fn PxPhysics_getNbHeightFields(self_: *const PxPhysics, ) -> u32;
pub fn PxPhysics_getHeightFields(self_: *const PxPhysics, userBuffer: *mut *mut PxHeightField, bufferSize: u32, startIndex: u32, ) -> u32;
pub fn PxPhysics_createConvexMesh_mut(self_: *mut PxPhysics, stream: *mut PxInputStream, ) -> *mut PxConvexMesh;
pub fn PxPhysics_getNbConvexMeshes(self_: *const PxPhysics, ) -> u32;
pub fn PxPhysics_getConvexMeshes(self_: *const PxPhysics, userBuffer: *mut *mut PxConvexMesh, bufferSize: u32, startIndex: u32, ) -> u32;
pub fn PxPhysics_createBVHStructure_mut(self_: *mut PxPhysics, stream: *mut PxInputStream, ) -> *mut PxBVHStructure;
pub fn PxPhysics_getNbBVHStructures(self_: *const PxPhysics, ) -> u32;
pub fn PxPhysics_getBVHStructures(self_: *const PxPhysics, userBuffer: *mut *mut PxBVHStructure, bufferSize: u32, startIndex: u32, ) -> u32;
pub fn PxPhysics_createScene_mut(self_: *mut PxPhysics, sceneDesc: *const PxSceneDesc, ) -> *mut PxScene;
pub fn PxPhysics_getNbScenes(self_: *const PxPhysics, ) -> u32;
pub fn PxPhysics_getScenes(self_: *const PxPhysics, userBuffer: *mut *mut PxScene, bufferSize: u32, startIndex: u32, ) -> u32;
pub fn PxPhysics_createRigidStatic_mut(self_: *mut PxPhysics, pose: *const PxTransform, ) -> *mut PxRigidStatic;
pub fn PxPhysics_createRigidDynamic_mut(self_: *mut PxPhysics, pose: *const PxTransform, ) -> *mut PxRigidDynamic;
pub fn PxPhysics_createPruningStructure_mut(self_: *mut PxPhysics, actors: *const *mut PxRigidActor, nbActors: u32, ) -> *mut PxPruningStructure;
pub fn PxPhysics_createShape_mut(self_: *mut PxPhysics, geometry: *const PxGeometry, material: *const PxMaterial, isExclusive: bool, shapeFlags: PxShapeFlags, ) -> *mut PxShape;
pub fn PxPhysics_createShape_mut_1(self_: *mut PxPhysics, geometry: *const PxGeometry, materials: *const *mut PxMaterial, materialCount: u16, isExclusive: bool, shapeFlags: PxShapeFlags, ) -> *mut PxShape;
pub fn PxPhysics_getNbShapes(self_: *const PxPhysics, ) -> u32;
pub fn PxPhysics_getShapes(self_: *const PxPhysics, userBuffer: *mut *mut PxShape, bufferSize: u32, startIndex: u32, ) -> u32;
pub fn PxPhysics_createConstraint_mut(self_: *mut PxPhysics, actor0: *mut PxRigidActor, actor1: *mut PxRigidActor, connector: *mut PxConstraintConnector, shaders: *const PxConstraintShaderTable, dataSize: u32, ) -> *mut PxConstraint;
pub fn PxPhysics_createArticulation_mut(self_: *mut PxPhysics, ) -> *mut PxArticulation;
pub fn PxPhysics_createArticulationReducedCoordinate_mut(self_: *mut PxPhysics, ) -> *mut PxArticulationReducedCoordinate;
pub fn PxPhysics_createMaterial_mut(self_: *mut PxPhysics, staticFriction: f32, dynamicFriction: f32, restitution: f32, ) -> *mut PxMaterial;
pub fn PxPhysics_getNbMaterials(self_: *const PxPhysics, ) -> u32;
pub fn PxPhysics_getMaterials(self_: *const PxPhysics, userBuffer: *mut *mut PxMaterial, bufferSize: u32, startIndex: u32, ) -> u32;
pub fn PxPhysics_registerDeletionListener_mut(self_: *mut PxPhysics, observer: *mut PxDeletionListener, deletionEvents: *const PxDeletionEventFlags, restrictedObjectSet: bool, ) -> ();
pub fn PxPhysics_unregisterDeletionListener_mut(self_: *mut PxPhysics, observer: *mut PxDeletionListener, ) -> ();
pub fn PxPhysics_registerDeletionListenerObjects_mut(self_: *mut PxPhysics, observer: *mut PxDeletionListener, observables: *const *const PxBase, observableCount: u32, ) -> ();
pub fn PxPhysics_unregisterDeletionListenerObjects_mut(self_: *mut PxPhysics, observer: *mut PxDeletionListener, observables: *const *const PxBase, observableCount: u32, ) -> ();
pub fn PxPhysics_getPhysicsInsertionCallback_mut(self_: *mut PxPhysics, ) -> *mut PxPhysicsInsertionCallback;
pub fn phys_PxRegisterArticulations(physics: *mut PxPhysics, ) -> ();
pub fn phys_PxRegisterArticulationsReducedCoordinate(physics: *mut PxPhysics, ) -> ();
pub fn phys_PxRegisterHeightFields(physics: *mut PxPhysics, ) -> ();
pub fn phys_PxCreateBasePhysics(version: u32, foundation: *mut PxFoundation, scale: *const PxTolerancesScale, trackOutstandingAllocations: bool, pvd: *mut PxPvd, ) -> *mut PxPhysics;
pub fn phys_PxCreatePhysics(version: u32, foundation: *mut PxFoundation, scale: *const PxTolerancesScale, trackOutstandingAllocations: bool, pvd: *mut PxPvd, ) -> *mut PxPhysics;
pub fn phys_PxGetPhysics() -> *mut PxPhysics;
pub fn PxRigidDynamic_setKinematicTarget_mut(self_: *mut PxRigidDynamic, destination: *const PxTransform, ) -> ();
pub fn PxRigidDynamic_getKinematicTarget(self_: *const PxRigidDynamic, target: *mut PxTransform, ) -> bool;
pub fn PxRigidDynamic_isSleeping(self_: *const PxRigidDynamic, ) -> bool;
pub fn PxRigidDynamic_setSleepThreshold_mut(self_: *mut PxRigidDynamic, threshold: f32, ) -> ();
pub fn PxRigidDynamic_getSleepThreshold(self_: *const PxRigidDynamic, ) -> f32;
pub fn PxRigidDynamic_setStabilizationThreshold_mut(self_: *mut PxRigidDynamic, threshold: f32, ) -> ();
pub fn PxRigidDynamic_getStabilizationThreshold(self_: *const PxRigidDynamic, ) -> f32;
pub fn PxRigidDynamic_getRigidDynamicLockFlags(self_: *const PxRigidDynamic, ) -> PxRigidDynamicLockFlags;
pub fn PxRigidDynamic_setRigidDynamicLockFlag_mut(self_: *mut PxRigidDynamic, flag: PxRigidDynamicLockFlag::Enum, value: bool, ) -> ();
pub fn PxRigidDynamic_setRigidDynamicLockFlags_mut(self_: *mut PxRigidDynamic, flags: PxRigidDynamicLockFlags, ) -> ();
pub fn PxRigidDynamic_setWakeCounter_mut(self_: *mut PxRigidDynamic, wakeCounterValue: f32, ) -> ();
pub fn PxRigidDynamic_getWakeCounter(self_: *const PxRigidDynamic, ) -> f32;
pub fn PxRigidDynamic_wakeUp_mut(self_: *mut PxRigidDynamic, ) -> ();
pub fn PxRigidDynamic_putToSleep_mut(self_: *mut PxRigidDynamic, ) -> ();
pub fn PxRigidDynamic_setSolverIterationCounts_mut(self_: *mut PxRigidDynamic, minPositionIters: u32, minVelocityIters: u32, ) -> ();
pub fn PxRigidDynamic_getSolverIterationCounts(self_: *const PxRigidDynamic, minPositionIters: *mut u32, minVelocityIters: *mut u32, ) -> ();
pub fn PxRigidDynamic_getContactReportThreshold(self_: *const PxRigidDynamic, ) -> f32;
pub fn PxRigidDynamic_setContactReportThreshold_mut(self_: *mut PxRigidDynamic, threshold: f32, ) -> ();
pub fn PxRigidDynamic_getConcreteTypeName(self_: *const PxRigidDynamic, ) -> *const i8;
pub fn PxRigidStatic_getConcreteTypeName(self_: *const PxRigidStatic, ) -> *const i8;
pub fn PxBroadPhaseCallback_delete(self_: *mut PxBroadPhaseCallback, ) -> ();
pub fn PxBroadPhaseCallback_onObjectOutOfBounds_mut(self_: *mut PxBroadPhaseCallback, shape: *mut PxShape, actor: *mut PxActor, ) -> ();
pub fn PxBroadPhaseCallback_onObjectOutOfBounds_mut_1(self_: *mut PxBroadPhaseCallback, aggregate: *mut PxAggregate, ) -> ();
pub fn PxSceneLimits_new() -> PxSceneLimits;
pub fn PxSceneLimits_setToDefault_mut(self_: *mut PxSceneLimits, ) -> ();
pub fn PxSceneLimits_isValid(self_: *const PxSceneLimits, ) -> bool;
pub fn PxSceneLimits_new_1() -> PxSceneLimits;
pub fn PxSceneLimits_setToDefault_mut_1(self_: *mut PxSceneLimits, ) -> ();
pub fn PxSceneLimits_isValid_1(self_: *const PxSceneLimits, ) -> bool;
pub fn PxgDynamicsMemoryConfig_new() -> PxgDynamicsMemoryConfig;
pub fn PxSceneDesc_new(scale: *const PxTolerancesScale, ) -> PxSceneDesc;
pub fn PxSceneDesc_setToDefault_mut(self_: *mut PxSceneDesc, scale: *const PxTolerancesScale, ) -> ();
pub fn PxSceneDesc_isValid(self_: *const PxSceneDesc, ) -> bool;
pub fn PxSceneDesc_getTolerancesScale(self_: *const PxSceneDesc, ) -> *const PxTolerancesScale;
pub fn PxSceneDesc_new_1(scale: *const PxTolerancesScale, ) -> PxSceneDesc;
pub fn PxSceneDesc_setToDefault_mut_1(self_: *mut PxSceneDesc, scale: *const PxTolerancesScale, ) -> ();
pub fn PxSceneDesc_isValid_1(self_: *const PxSceneDesc, ) -> bool;
pub fn PxSimulationStatistics_getNbBroadPhaseAdds(self_: *const PxSimulationStatistics, ) -> u32;
pub fn PxSimulationStatistics_getNbBroadPhaseRemoves(self_: *const PxSimulationStatistics, ) -> u32;
pub fn PxSimulationStatistics_getRbPairStats(self_: *const PxSimulationStatistics, pairType: PxSimulationStatisticsEnum::RbPairStatsType, g0: PxGeometryType::Enum, g1: PxGeometryType::Enum, ) -> u32;
pub fn PxSimulationStatistics_new() -> PxSimulationStatistics;
pub fn PxPvdSceneClient_setScenePvdFlag_mut(self_: *mut PxPvdSceneClient, flag: PxPvdSceneFlag::Enum, value: bool, ) -> ();
pub fn PxPvdSceneClient_setScenePvdFlags_mut(self_: *mut PxPvdSceneClient, flags: PxPvdSceneFlags, ) -> ();
pub fn PxPvdSceneClient_getScenePvdFlags(self_: *const PxPvdSceneClient, ) -> PxPvdSceneFlags;
pub fn PxPvdSceneClient_updateCamera_mut(self_: *mut PxPvdSceneClient, name: *const i8, origin: *const PxVec3, up: *const PxVec3, target: *const PxVec3, ) -> ();
pub fn PxPvdSceneClient_drawPoints_mut(self_: *mut PxPvdSceneClient, points: *const PvdDebugPoint, count: u32, ) -> ();
pub fn PxPvdSceneClient_drawLines_mut(self_: *mut PxPvdSceneClient, lines: *const PvdDebugLine, count: u32, ) -> ();
pub fn PxPvdSceneClient_drawTriangles_mut(self_: *mut PxPvdSceneClient, triangles: *const PvdDebugTriangle, count: u32, ) -> ();
pub fn PxPvdSceneClient_drawText_mut(self_: *mut PxPvdSceneClient, text: *const PvdDebugText, ) -> ();
pub fn PxPvdSceneClient_getClientInternal_mut(self_: *mut PxPvdSceneClient, ) -> *mut PvdClient;
pub fn PxDominanceGroupPair_new(a: u8, b: u8, ) -> PxDominanceGroupPair;
pub fn PxQueryCache_new() -> PxQueryCache;
pub fn PxQueryCache_new_1(s: *mut PxShape, findex: u32, ) -> PxQueryCache;
pub fn PxScene_release_mut(self_: *mut PxScene, ) -> ();
pub fn PxScene_setFlag_mut(self_: *mut PxScene, flag: PxSceneFlag::Enum, value: bool, ) -> ();
pub fn PxScene_getFlags(self_: *const PxScene, ) -> PxSceneFlags;
pub fn PxScene_setLimits_mut(self_: *mut PxScene, limits: *const PxSceneLimits, ) -> ();
pub fn PxScene_getLimits(self_: *const PxScene, ) -> PxSceneLimits;
pub fn PxScene_getPhysics_mut(self_: *mut PxScene, ) -> *mut PxPhysics;
pub fn PxScene_getTimestamp(self_: *const PxScene, ) -> u32;
pub fn PxScene_addArticulation_mut(self_: *mut PxScene, articulation: *mut PxArticulationBase, ) -> ();
pub fn PxScene_removeArticulation_mut(self_: *mut PxScene, articulation: *mut PxArticulationBase, wakeOnLostTouch: bool, ) -> ();
pub fn PxScene_addActor_mut(self_: *mut PxScene, actor: *mut PxActor, bvhStructure: *const PxBVHStructure, ) -> ();
pub fn PxScene_addActors_mut(self_: *mut PxScene, actors: *const *mut PxActor, nbActors: u32, ) -> ();
pub fn PxScene_addActors_mut_1(self_: *mut PxScene, pruningStructure: *const PxPruningStructure, ) -> ();
pub fn PxScene_removeActor_mut(self_: *mut PxScene, actor: *mut PxActor, wakeOnLostTouch: bool, ) -> ();
pub fn PxScene_removeActors_mut(self_: *mut PxScene, actors: *const *mut PxActor, nbActors: u32, wakeOnLostTouch: bool, ) -> ();
pub fn PxScene_addAggregate_mut(self_: *mut PxScene, aggregate: *mut PxAggregate, ) -> ();
pub fn PxScene_removeAggregate_mut(self_: *mut PxScene, aggregate: *mut PxAggregate, wakeOnLostTouch: bool, ) -> ();
pub fn PxScene_addCollection_mut(self_: *mut PxScene, collection: *const PxCollection, ) -> ();
pub fn PxScene_getNbActors(self_: *const PxScene, types: PxActorTypeFlags, ) -> u32;
pub fn PxScene_getActors(self_: *const PxScene, types: PxActorTypeFlags, userBuffer: *mut *mut PxActor, bufferSize: u32, startIndex: u32, ) -> u32;
pub fn PxScene_getActiveActors_mut(self_: *mut PxScene, nbActorsOut: *mut u32, ) -> *mut *mut PxActor;
pub fn PxScene_getNbArticulations(self_: *const PxScene, ) -> u32;
pub fn PxScene_getArticulations(self_: *const PxScene, userBuffer: *mut *mut PxArticulationBase, bufferSize: u32, startIndex: u32, ) -> u32;
pub fn PxScene_getNbConstraints(self_: *const PxScene, ) -> u32;
pub fn PxScene_getConstraints(self_: *const PxScene, userBuffer: *mut *mut PxConstraint, bufferSize: u32, startIndex: u32, ) -> u32;
pub fn PxScene_getNbAggregates(self_: *const PxScene, ) -> u32;
pub fn PxScene_getAggregates(self_: *const PxScene, userBuffer: *mut *mut PxAggregate, bufferSize: u32, startIndex: u32, ) -> u32;
pub fn PxScene_setDominanceGroupPair_mut(self_: *mut PxScene, group1: u8, group2: u8, dominance: *const PxDominanceGroupPair, ) -> ();
pub fn PxScene_getDominanceGroupPair(self_: *const PxScene, group1: u8, group2: u8, ) -> PxDominanceGroupPair;
pub fn PxScene_getCpuDispatcher(self_: *const PxScene, ) -> *mut PxCpuDispatcher;
pub fn PxScene_getCudaContextManager(self_: *const PxScene, ) -> *mut PxCudaContextManager;
pub fn PxScene_createClient_mut(self_: *mut PxScene, ) -> u8;
pub fn PxScene_setSimulationEventCallback_mut(self_: *mut PxScene, callback: *mut PxSimulationEventCallback, ) -> ();
pub fn PxScene_getSimulationEventCallback(self_: *const PxScene, ) -> *mut PxSimulationEventCallback;
pub fn PxScene_setContactModifyCallback_mut(self_: *mut PxScene, callback: *mut PxContactModifyCallback, ) -> ();
pub fn PxScene_setCCDContactModifyCallback_mut(self_: *mut PxScene, callback: *mut PxCCDContactModifyCallback, ) -> ();
pub fn PxScene_getContactModifyCallback(self_: *const PxScene, ) -> *mut PxContactModifyCallback;
pub fn PxScene_getCCDContactModifyCallback(self_: *const PxScene, ) -> *mut PxCCDContactModifyCallback;
pub fn PxScene_setBroadPhaseCallback_mut(self_: *mut PxScene, callback: *mut PxBroadPhaseCallback, ) -> ();
pub fn PxScene_getBroadPhaseCallback(self_: *const PxScene, ) -> *mut PxBroadPhaseCallback;
pub fn PxScene_setFilterShaderData_mut(self_: *mut PxScene, data: *const std::ffi::c_void, dataSize: u32, ) -> ();
pub fn PxScene_getFilterShaderData(self_: *const PxScene, ) -> *const std::ffi::c_void;
pub fn PxScene_getFilterShaderDataSize(self_: *const PxScene, ) -> u32;
pub fn PxScene_getFilterShader(self_: *const PxScene, ) -> *mut std::ffi::c_void;
pub fn PxScene_getFilterCallback(self_: *const PxScene, ) -> *mut PxSimulationFilterCallback;
pub fn PxScene_resetFiltering_mut(self_: *mut PxScene, actor: *mut PxActor, ) -> ();
pub fn PxScene_resetFiltering_mut_1(self_: *mut PxScene, actor: *mut PxRigidActor, shapes: *const *mut PxShape, shapeCount: u32, ) -> ();
pub fn PxScene_getKinematicKinematicFilteringMode(self_: *const PxScene, ) -> PxPairFilteringMode::Enum;
pub fn PxScene_getStaticKinematicFilteringMode(self_: *const PxScene, ) -> PxPairFilteringMode::Enum;
pub fn PxScene_simulate_mut(self_: *mut PxScene, elapsedTime: f32, completionTask: *mut PxBaseTask, scratchMemBlock: *mut std::ffi::c_void, scratchMemBlockSize: u32, controlSimulation: bool, ) -> ();
pub fn PxScene_advance_mut(self_: *mut PxScene, completionTask: *mut PxBaseTask, ) -> ();
pub fn PxScene_collide_mut(self_: *mut PxScene, elapsedTime: f32, completionTask: *mut PxBaseTask, scratchMemBlock: *mut std::ffi::c_void, scratchMemBlockSize: u32, controlSimulation: bool, ) -> ();
pub fn PxScene_checkResults_mut(self_: *mut PxScene, block: bool, ) -> bool;
pub fn PxScene_fetchCollision_mut(self_: *mut PxScene, block: bool, ) -> bool;
pub fn PxScene_fetchResults_mut(self_: *mut PxScene, block: bool, errorState: *mut u32, ) -> bool;
pub fn PxScene_fetchResultsStart_mut(self_: *mut PxScene, contactPairs: *mut *const PxContactPairHeader, nbContactPairs: *mut u32, block: bool, ) -> bool;
pub fn PxScene_processCallbacks_mut(self_: *mut PxScene, continuation: *mut PxBaseTask, ) -> ();
pub fn PxScene_fetchResultsFinish_mut(self_: *mut PxScene, errorState: *mut u32, ) -> ();
pub fn PxScene_flushSimulation_mut(self_: *mut PxScene, sendPendingReports: bool, ) -> ();
pub fn PxScene_setGravity_mut(self_: *mut PxScene, vec: *const PxVec3, ) -> ();
pub fn PxScene_getGravity(self_: *const PxScene, ) -> PxVec3;
pub fn PxScene_setBounceThresholdVelocity_mut(self_: *mut PxScene, t: f32, ) -> ();
pub fn PxScene_getBounceThresholdVelocity(self_: *const PxScene, ) -> f32;
pub fn PxScene_setCCDMaxPasses_mut(self_: *mut PxScene, ccdMaxPasses: u32, ) -> ();
pub fn PxScene_getCCDMaxPasses(self_: *const PxScene, ) -> u32;
pub fn PxScene_getFrictionOffsetThreshold(self_: *const PxScene, ) -> f32;
pub fn PxScene_setFrictionType_mut(self_: *mut PxScene, frictionType: PxFrictionType::Enum, ) -> ();
pub fn PxScene_getFrictionType(self_: *const PxScene, ) -> PxFrictionType::Enum;
pub fn PxScene_setVisualizationParameter_mut(self_: *mut PxScene, param: PxVisualizationParameter::Enum, value: f32, ) -> bool;
pub fn PxScene_getVisualizationParameter(self_: *const PxScene, paramEnum: PxVisualizationParameter::Enum, ) -> f32;
pub fn PxScene_setVisualizationCullingBox_mut(self_: *mut PxScene, _box: *const PxBounds3, ) -> ();
pub fn PxScene_getVisualizationCullingBox(self_: *const PxScene, ) -> PxBounds3;
pub fn PxScene_getRenderBuffer_mut(self_: *mut PxScene, ) -> *const PxRenderBuffer;
pub fn PxScene_getSimulationStatistics(self_: *const PxScene, stats: *mut PxSimulationStatistics, ) -> ();
pub fn PxScene_getStaticStructure(self_: *const PxScene, ) -> PxPruningStructureType::Enum;
pub fn PxScene_getDynamicStructure(self_: *const PxScene, ) -> PxPruningStructureType::Enum;
pub fn PxScene_flushQueryUpdates_mut(self_: *mut PxScene, ) -> ();
pub fn PxScene_createBatchQuery_mut(self_: *mut PxScene, desc: *const PxBatchQueryDesc, ) -> *mut PxBatchQuery;
pub fn PxScene_setDynamicTreeRebuildRateHint_mut(self_: *mut PxScene, dynamicTreeRebuildRateHint: u32, ) -> ();
pub fn PxScene_getDynamicTreeRebuildRateHint(self_: *const PxScene, ) -> u32;
pub fn PxScene_forceDynamicTreeRebuild_mut(self_: *mut PxScene, rebuildStaticStructure: bool, rebuildDynamicStructure: bool, ) -> ();
pub fn PxScene_setSceneQueryUpdateMode_mut(self_: *mut PxScene, updateMode: PxSceneQueryUpdateMode::Enum, ) -> ();
pub fn PxScene_getSceneQueryUpdateMode(self_: *const PxScene, ) -> PxSceneQueryUpdateMode::Enum;
pub fn PxScene_sceneQueriesUpdate_mut(self_: *mut PxScene, completionTask: *mut PxBaseTask, controlSimulation: bool, ) -> ();
pub fn PxScene_checkQueries_mut(self_: *mut PxScene, block: bool, ) -> bool;
pub fn PxScene_fetchQueries_mut(self_: *mut PxScene, block: bool, ) -> bool;
pub fn PxScene_raycast(self_: *const PxScene, origin: *const PxVec3, unitDir: *const PxVec3, distance: f32, hitCall: *mut PxRaycastCallback, hitFlags: PxHitFlags, filterData: *const PxQueryFilterData, filterCall: *mut PxQueryFilterCallback, cache: *const PxQueryCache, ) -> bool;
pub fn PxScene_sweep(self_: *const PxScene, geometry: *const PxGeometry, pose: *const PxTransform, unitDir: *const PxVec3, distance: f32, hitCall: *mut PxSweepCallback, hitFlags: PxHitFlags, filterData: *const PxQueryFilterData, filterCall: *mut PxQueryFilterCallback, cache: *const PxQueryCache, inflation: f32, ) -> bool;
pub fn PxScene_overlap(self_: *const PxScene, geometry: *const PxGeometry, pose: *const PxTransform, hitCall: *mut PxOverlapCallback, filterData: *const PxQueryFilterData, filterCall: *mut PxQueryFilterCallback, ) -> bool;
pub fn PxScene_getSceneQueryStaticTimestamp(self_: *const PxScene, ) -> u32;
pub fn PxScene_getBroadPhaseType(self_: *const PxScene, ) -> PxBroadPhaseType::Enum;
pub fn PxScene_getBroadPhaseCaps(self_: *const PxScene, caps: *mut PxBroadPhaseCaps, ) -> bool;
pub fn PxScene_getNbBroadPhaseRegions(self_: *const PxScene, ) -> u32;
pub fn PxScene_getBroadPhaseRegions(self_: *const PxScene, userBuffer: *mut PxBroadPhaseRegionInfo, bufferSize: u32, startIndex: u32, ) -> u32;
pub fn PxScene_addBroadPhaseRegion_mut(self_: *mut PxScene, region: *const PxBroadPhaseRegion, populateRegion: bool, ) -> u32;
pub fn PxScene_removeBroadPhaseRegion_mut(self_: *mut PxScene, handle: u32, ) -> bool;
pub fn PxScene_getTaskManager(self_: *const PxScene, ) -> *mut PxTaskManager;
pub fn PxScene_lockRead_mut(self_: *mut PxScene, file: *const i8, line: u32, ) -> ();
pub fn PxScene_unlockRead_mut(self_: *mut PxScene, ) -> ();
pub fn PxScene_lockWrite_mut(self_: *mut PxScene, file: *const i8, line: u32, ) -> ();
pub fn PxScene_unlockWrite_mut(self_: *mut PxScene, ) -> ();
pub fn PxScene_setNbContactDataBlocks_mut(self_: *mut PxScene, numBlocks: u32, ) -> ();
pub fn PxScene_getNbContactDataBlocksUsed(self_: *const PxScene, ) -> u32;
pub fn PxScene_getMaxNbContactDataBlocksUsed(self_: *const PxScene, ) -> u32;
pub fn PxScene_getContactReportStreamBufferSize(self_: *const PxScene, ) -> u32;
pub fn PxScene_setSolverBatchSize_mut(self_: *mut PxScene, solverBatchSize: u32, ) -> ();
pub fn PxScene_getSolverBatchSize(self_: *const PxScene, ) -> u32;
pub fn PxScene_setSolverArticulationBatchSize_mut(self_: *mut PxScene, solverBatchSize: u32, ) -> ();
pub fn PxScene_getSolverArticulationBatchSize(self_: *const PxScene, ) -> u32;
pub fn PxScene_getWakeCounterResetValue(self_: *const PxScene, ) -> f32;
pub fn PxScene_shiftOrigin_mut(self_: *mut PxScene, shift: *const PxVec3, ) -> ();
pub fn PxScene_getScenePvdClient_mut(self_: *mut PxScene, ) -> *mut PxPvdSceneClient;
pub fn PxSceneReadLock_new_alloc(scene: *mut PxScene, file: *const i8, line: u32, ) -> *mut PxSceneReadLock;
pub fn PxSceneReadLock_delete(self_: *mut PxSceneReadLock, ) -> ();
pub fn PxSceneWriteLock_new_alloc(scene: *mut PxScene, file: *const i8, line: u32, ) -> *mut PxSceneWriteLock;
pub fn PxSceneWriteLock_delete(self_: *mut PxSceneWriteLock, ) -> ();
pub fn PxContactPairExtraDataItem_new() -> PxContactPairExtraDataItem;
pub fn PxContactPairVelocity_new() -> PxContactPairVelocity;
pub fn PxContactPairPose_new() -> PxContactPairPose;
pub fn PxContactPairIndex_new() -> PxContactPairIndex;
pub fn PxContactPairExtraDataIterator_new(stream: *const u8, size: u32, ) -> PxContactPairExtraDataIterator;
pub fn PxContactPairExtraDataIterator_nextItemSet_mut(self_: *mut PxContactPairExtraDataIterator, ) -> bool;
pub fn PxContactPairHeader_new() -> PxContactPairHeader;
pub fn PxContactPair_new() -> PxContactPair;
pub fn PxContactPair_extractContacts(self_: *const PxContactPair, userBuffer: *mut PxContactPairPoint, bufferSize: u32, ) -> u32;
pub fn PxContactPair_bufferContacts(self_: *const PxContactPair, newPair: *mut PxContactPair, bufferMemory: *mut u8, ) -> ();
pub fn PxContactPair_getInternalFaceIndices(self_: *const PxContactPair, ) -> *const u32;
pub fn PxContactPair_extractContacts_1(self_: *const PxContactPair, userBuffer: *mut PxContactPairPoint, bufferSize: u32, ) -> u32;
pub fn PxContactPair_bufferContacts_1(self_: *const PxContactPair, newPair: *mut PxContactPair, bufferMemory: *mut u8, ) -> ();
pub fn PxContactPair_getInternalFaceIndices_1(self_: *const PxContactPair, ) -> *const u32;
pub fn PxTriggerPair_new() -> PxTriggerPair;
pub fn PxConstraintInfo_new() -> PxConstraintInfo;
pub fn PxConstraintInfo_new_1(c: *mut PxConstraint, extRef: *mut std::ffi::c_void, t: u32, ) -> PxConstraintInfo;
pub fn PxSimulationEventCallback_onConstraintBreak_mut(self_: *mut PxSimulationEventCallback, constraints: *mut PxConstraintInfo, count: u32, ) -> ();
pub fn PxSimulationEventCallback_onWake_mut(self_: *mut PxSimulationEventCallback, actors: *mut *mut PxActor, count: u32, ) -> ();
pub fn PxSimulationEventCallback_onSleep_mut(self_: *mut PxSimulationEventCallback, actors: *mut *mut PxActor, count: u32, ) -> ();
pub fn PxSimulationEventCallback_onContact_mut(self_: *mut PxSimulationEventCallback, pairHeader: *const PxContactPairHeader, pairs: *const PxContactPair, nbPairs: u32, ) -> ();
pub fn PxSimulationEventCallback_onTrigger_mut(self_: *mut PxSimulationEventCallback, pairs: *mut PxTriggerPair, count: u32, ) -> ();
pub fn PxSimulationEventCallback_onAdvance_mut(self_: *mut PxSimulationEventCallback, bodyBuffer: *const *const PxRigidBody, poseBuffer: *const PxTransform, count: u32, ) -> ();
pub fn PxSimulationEventCallback_delete(self_: *mut PxSimulationEventCallback, ) -> ();
pub fn PxPruningStructure_release_mut(self_: *mut PxPruningStructure, ) -> ();
pub fn PxPruningStructure_getRigidActors(self_: *const PxPruningStructure, userBuffer: *mut *mut PxRigidActor, bufferSize: u32, startIndex: u32, ) -> u32;
pub fn PxPruningStructure_getNbRigidActors(self_: *const PxPruningStructure, ) -> u32;
pub fn PxPruningStructure_getConcreteTypeName(self_: *const PxPruningStructure, ) -> *const i8;
pub fn PxExtendedVec3_new() -> PxExtendedVec3;
pub fn PxExtendedVec3_new_1(_x: f64, _y: f64, _z: f64, ) -> PxExtendedVec3;
pub fn PxExtendedVec3_isZero(self_: *const PxExtendedVec3, ) -> bool;
pub fn PxExtendedVec3_dot(self_: *const PxExtendedVec3, v: *const PxVec3, ) -> f64;
pub fn PxExtendedVec3_distanceSquared(self_: *const PxExtendedVec3, v: *const PxExtendedVec3, ) -> f64;
pub fn PxExtendedVec3_magnitudeSquared(self_: *const PxExtendedVec3, ) -> f64;
pub fn PxExtendedVec3_magnitude(self_: *const PxExtendedVec3, ) -> f64;
pub fn PxExtendedVec3_normalize_mut(self_: *mut PxExtendedVec3, ) -> f64;
pub fn PxExtendedVec3_isFinite(self_: *const PxExtendedVec3, ) -> bool;
pub fn PxExtendedVec3_maximum_mut(self_: *mut PxExtendedVec3, v: *const PxExtendedVec3, ) -> ();
pub fn PxExtendedVec3_minimum_mut(self_: *mut PxExtendedVec3, v: *const PxExtendedVec3, ) -> ();
pub fn PxExtendedVec3_set_mut(self_: *mut PxExtendedVec3, x_: f64, y_: f64, z_: f64, ) -> ();
pub fn PxExtendedVec3_setPlusInfinity_mut(self_: *mut PxExtendedVec3, ) -> ();
pub fn PxExtendedVec3_setMinusInfinity_mut(self_: *mut PxExtendedVec3, ) -> ();
pub fn PxExtendedVec3_cross_mut(self_: *mut PxExtendedVec3, left: *const PxExtendedVec3, right: *const PxVec3, ) -> ();
pub fn PxExtendedVec3_cross_mut_1(self_: *mut PxExtendedVec3, left: *const PxExtendedVec3, right: *const PxExtendedVec3, ) -> ();
pub fn PxExtendedVec3_cross(self_: *const PxExtendedVec3, v: *const PxExtendedVec3, ) -> PxExtendedVec3;
pub fn PxExtendedVec3_cross_mut_2(self_: *mut PxExtendedVec3, left: *const PxVec3, right: *const PxExtendedVec3, ) -> ();
pub fn PxObstacle_getType(self_: *const PxObstacle, ) -> PxGeometryType::Enum;
pub fn PxBoxObstacle_new() -> PxBoxObstacle;
pub fn PxCapsuleObstacle_new() -> PxCapsuleObstacle;
pub fn PxObstacleContext_release_mut(self_: *mut PxObstacleContext, ) -> ();
pub fn PxObstacleContext_getControllerManager(self_: *const PxObstacleContext, ) -> *mut PxControllerManager;
pub fn PxObstacleContext_addObstacle_mut(self_: *mut PxObstacleContext, obstacle: *const PxObstacle, ) -> u32;
pub fn PxObstacleContext_removeObstacle_mut(self_: *mut PxObstacleContext, handle: u32, ) -> bool;
pub fn PxObstacleContext_updateObstacle_mut(self_: *mut PxObstacleContext, handle: u32, obstacle: *const PxObstacle, ) -> bool;
pub fn PxObstacleContext_getNbObstacles(self_: *const PxObstacleContext, ) -> u32;
pub fn PxObstacleContext_getObstacle(self_: *const PxObstacleContext, i: u32, ) -> *const PxObstacle;
pub fn PxObstacleContext_getObstacleByHandle(self_: *const PxObstacleContext, handle: u32, ) -> *const PxObstacle;
pub fn PxUserControllerHitReport_onShapeHit_mut(self_: *mut PxUserControllerHitReport, hit: *const PxControllerShapeHit, ) -> ();
pub fn PxUserControllerHitReport_onControllerHit_mut(self_: *mut PxUserControllerHitReport, hit: *const PxControllersHit, ) -> ();
pub fn PxUserControllerHitReport_onObstacleHit_mut(self_: *mut PxUserControllerHitReport, hit: *const PxControllerObstacleHit, ) -> ();
pub fn PxControllerFilterCallback_delete(self_: *mut PxControllerFilterCallback, ) -> ();
pub fn PxControllerFilterCallback_filter_mut(self_: *mut PxControllerFilterCallback, a: *const PxController, b: *const PxController, ) -> bool;
pub fn PxControllerFilters_new(filterData: *const PxFilterData, cb: *mut PxQueryFilterCallback, cctFilterCb: *mut PxControllerFilterCallback, ) -> PxControllerFilters;
pub fn PxControllerDesc_isValid(self_: *const PxControllerDesc, ) -> bool;
pub fn PxControllerDesc_getType(self_: *const PxControllerDesc, ) -> PxControllerShapeType::Enum;
pub fn PxControllerDesc_isValid_1(self_: *const PxControllerDesc, ) -> bool;
pub fn PxController_getType(self_: *const PxController, ) -> PxControllerShapeType::Enum;
pub fn PxController_release_mut(self_: *mut PxController, ) -> ();
pub fn PxController_move_mut(self_: *mut PxController, disp: *const PxVec3, minDist: f32, elapsedTime: f32, filters: *const PxControllerFilters, obstacles: *const PxObstacleContext, ) -> PxControllerCollisionFlags;
pub fn PxController_setPosition_mut(self_: *mut PxController, position: *const PxExtendedVec3, ) -> bool;
pub fn PxController_getPosition(self_: *const PxController, ) -> *const PxExtendedVec3;
pub fn PxController_setFootPosition_mut(self_: *mut PxController, position: *const PxExtendedVec3, ) -> bool;
pub fn PxController_getFootPosition(self_: *const PxController, ) -> PxExtendedVec3;
pub fn PxController_getActor(self_: *const PxController, ) -> *mut PxRigidDynamic;
pub fn PxController_setStepOffset_mut(self_: *mut PxController, offset: f32, ) -> ();
pub fn PxController_getStepOffset(self_: *const PxController, ) -> f32;
pub fn PxController_setNonWalkableMode_mut(self_: *mut PxController, flag: PxControllerNonWalkableMode::Enum, ) -> ();
pub fn PxController_getNonWalkableMode(self_: *const PxController, ) -> PxControllerNonWalkableMode::Enum;
pub fn PxController_getContactOffset(self_: *const PxController, ) -> f32;
pub fn PxController_setContactOffset_mut(self_: *mut PxController, offset: f32, ) -> ();
pub fn PxController_getUpDirection(self_: *const PxController, ) -> PxVec3;
pub fn PxController_setUpDirection_mut(self_: *mut PxController, up: *const PxVec3, ) -> ();
pub fn PxController_getSlopeLimit(self_: *const PxController, ) -> f32;
pub fn PxController_setSlopeLimit_mut(self_: *mut PxController, slopeLimit: f32, ) -> ();
pub fn PxController_invalidateCache_mut(self_: *mut PxController, ) -> ();
pub fn PxController_getScene_mut(self_: *mut PxController, ) -> *mut PxScene;
pub fn PxController_getUserData(self_: *const PxController, ) -> *mut std::ffi::c_void;
pub fn PxController_setUserData_mut(self_: *mut PxController, userData: *mut std::ffi::c_void, ) -> ();
pub fn PxController_getState(self_: *const PxController, state: *mut PxControllerState, ) -> ();
pub fn PxController_getStats(self_: *const PxController, stats: *mut PxControllerStats, ) -> ();
pub fn PxController_resize_mut(self_: *mut PxController, height: f32, ) -> ();
pub fn PxBoxControllerDesc_new_alloc() -> *mut PxBoxControllerDesc;
pub fn PxBoxControllerDesc_delete(self_: *mut PxBoxControllerDesc, ) -> ();
pub fn PxBoxControllerDesc_setToDefault_mut(self_: *mut PxBoxControllerDesc, ) -> ();
pub fn PxBoxControllerDesc_isValid(self_: *const PxBoxControllerDesc, ) -> bool;
pub fn PxBoxControllerDesc_new_alloc_1() -> *mut PxBoxControllerDesc;
pub fn PxBoxControllerDesc_setToDefault_mut_1(self_: *mut PxBoxControllerDesc, ) -> ();
pub fn PxBoxControllerDesc_isValid_1(self_: *const PxBoxControllerDesc, ) -> bool;
pub fn PxBoxController_getHalfHeight(self_: *const PxBoxController, ) -> f32;
pub fn PxBoxController_getHalfSideExtent(self_: *const PxBoxController, ) -> f32;
pub fn PxBoxController_getHalfForwardExtent(self_: *const PxBoxController, ) -> f32;
pub fn PxBoxController_setHalfHeight_mut(self_: *mut PxBoxController, halfHeight: f32, ) -> bool;
pub fn PxBoxController_setHalfSideExtent_mut(self_: *mut PxBoxController, halfSideExtent: f32, ) -> bool;
pub fn PxBoxController_setHalfForwardExtent_mut(self_: *mut PxBoxController, halfForwardExtent: f32, ) -> bool;
pub fn PxCapsuleControllerDesc_new_alloc() -> *mut PxCapsuleControllerDesc;
pub fn PxCapsuleControllerDesc_delete(self_: *mut PxCapsuleControllerDesc, ) -> ();
pub fn PxCapsuleControllerDesc_setToDefault_mut(self_: *mut PxCapsuleControllerDesc, ) -> ();
pub fn PxCapsuleControllerDesc_isValid(self_: *const PxCapsuleControllerDesc, ) -> bool;
pub fn PxCapsuleControllerDesc_new_alloc_1() -> *mut PxCapsuleControllerDesc;
pub fn PxCapsuleControllerDesc_setToDefault_mut_1(self_: *mut PxCapsuleControllerDesc, ) -> ();
pub fn PxCapsuleControllerDesc_isValid_1(self_: *const PxCapsuleControllerDesc, ) -> bool;
pub fn PxCapsuleController_getRadius(self_: *const PxCapsuleController, ) -> f32;
pub fn PxCapsuleController_setRadius_mut(self_: *mut PxCapsuleController, radius: f32, ) -> bool;
pub fn PxCapsuleController_getHeight(self_: *const PxCapsuleController, ) -> f32;
pub fn PxCapsuleController_setHeight_mut(self_: *mut PxCapsuleController, height: f32, ) -> bool;
pub fn PxCapsuleController_getClimbingMode(self_: *const PxCapsuleController, ) -> PxCapsuleClimbingMode::Enum;
pub fn PxCapsuleController_setClimbingMode_mut(self_: *mut PxCapsuleController, mode: PxCapsuleClimbingMode::Enum, ) -> bool;
pub fn PxControllerBehaviorCallback_getBehaviorFlags_mut(self_: *mut PxControllerBehaviorCallback, shape: *const PxShape, actor: *const PxActor, ) -> PxControllerBehaviorFlags;
pub fn PxControllerBehaviorCallback_getBehaviorFlags_mut_1(self_: *mut PxControllerBehaviorCallback, controller: *const PxController, ) -> PxControllerBehaviorFlags;
pub fn PxControllerBehaviorCallback_getBehaviorFlags_mut_2(self_: *mut PxControllerBehaviorCallback, obstacle: *const PxObstacle, ) -> PxControllerBehaviorFlags;
pub fn PxControllerManager_release_mut(self_: *mut PxControllerManager, ) -> ();
pub fn PxControllerManager_getScene(self_: *const PxControllerManager, ) -> *mut PxScene;
pub fn PxControllerManager_getNbControllers(self_: *const PxControllerManager, ) -> u32;
pub fn PxControllerManager_getController_mut(self_: *mut PxControllerManager, index: u32, ) -> *mut PxController;
pub fn PxControllerManager_createController_mut(self_: *mut PxControllerManager, desc: *const PxControllerDesc, ) -> *mut PxController;
pub fn PxControllerManager_purgeControllers_mut(self_: *mut PxControllerManager, ) -> ();
pub fn PxControllerManager_getRenderBuffer_mut(self_: *mut PxControllerManager, ) -> *mut PxRenderBuffer;
pub fn PxControllerManager_setDebugRenderingFlags_mut(self_: *mut PxControllerManager, flags: PxControllerDebugRenderFlags, ) -> ();
pub fn PxControllerManager_getNbObstacleContexts(self_: *const PxControllerManager, ) -> u32;
pub fn PxControllerManager_getObstacleContext_mut(self_: *mut PxControllerManager, index: u32, ) -> *mut PxObstacleContext;
pub fn PxControllerManager_createObstacleContext_mut(self_: *mut PxControllerManager, ) -> *mut PxObstacleContext;
pub fn PxControllerManager_computeInteractions_mut(self_: *mut PxControllerManager, elapsedTime: f32, cctFilterCb: *mut PxControllerFilterCallback, ) -> ();
pub fn PxControllerManager_setTessellation_mut(self_: *mut PxControllerManager, flag: bool, maxEdgeLength: f32, ) -> ();
pub fn PxControllerManager_setOverlapRecoveryModule_mut(self_: *mut PxControllerManager, flag: bool, ) -> ();
pub fn PxControllerManager_setPreciseSweeps_mut(self_: *mut PxControllerManager, flag: bool, ) -> ();
pub fn PxControllerManager_setPreventVerticalSlidingAgainstCeiling_mut(self_: *mut PxControllerManager, flag: bool, ) -> ();
pub fn PxControllerManager_shiftOrigin_mut(self_: *mut PxControllerManager, shift: *const PxVec3, ) -> ();
pub fn phys_PxCreateControllerManager(scene: *mut PxScene, lockingEnabled: bool, ) -> *mut PxControllerManager;
pub fn PxConvexMeshDesc_new() -> PxConvexMeshDesc;
pub fn PxConvexMeshDesc_setToDefault_mut(self_: *mut PxConvexMeshDesc, ) -> ();
pub fn PxConvexMeshDesc_isValid(self_: *const PxConvexMeshDesc, ) -> bool;
pub fn PxConvexMeshDesc_new_1() -> PxConvexMeshDesc;
pub fn PxConvexMeshDesc_setToDefault_mut_1(self_: *mut PxConvexMeshDesc, ) -> ();
pub fn PxConvexMeshDesc_isValid_1(self_: *const PxConvexMeshDesc, ) -> bool;
pub fn PxTriangleMeshDesc_new() -> PxTriangleMeshDesc;
pub fn PxTriangleMeshDesc_setToDefault_mut(self_: *mut PxTriangleMeshDesc, ) -> ();
pub fn PxTriangleMeshDesc_isValid(self_: *const PxTriangleMeshDesc, ) -> bool;
pub fn PxTriangleMeshDesc_new_1() -> PxTriangleMeshDesc;
pub fn PxTriangleMeshDesc_setToDefault_mut_1(self_: *mut PxTriangleMeshDesc, ) -> ();
pub fn PxTriangleMeshDesc_isValid_1(self_: *const PxTriangleMeshDesc, ) -> bool;
pub fn PxBVH33MidphaseDesc_setToDefault_mut(self_: *mut PxBVH33MidphaseDesc, ) -> ();
pub fn PxBVH33MidphaseDesc_isValid(self_: *const PxBVH33MidphaseDesc, ) -> bool;
pub fn PxBVH34MidphaseDesc_setToDefault_mut(self_: *mut PxBVH34MidphaseDesc, ) -> ();
pub fn PxBVH34MidphaseDesc_isValid(self_: *const PxBVH34MidphaseDesc, ) -> bool;
pub fn PxMidphaseDesc_new() -> PxMidphaseDesc;
pub fn PxMidphaseDesc_getType(self_: *const PxMidphaseDesc, ) -> PxMeshMidPhase::Enum;
pub fn PxMidphaseDesc_setToDefault_mut(self_: *mut PxMidphaseDesc, _type: PxMeshMidPhase::Enum, ) -> ();
pub fn PxMidphaseDesc_isValid(self_: *const PxMidphaseDesc, ) -> bool;
pub fn PxBVHStructureDesc_new() -> PxBVHStructureDesc;
pub fn PxBVHStructureDesc_setToDefault_mut(self_: *mut PxBVHStructureDesc, ) -> ();
pub fn PxBVHStructureDesc_isValid(self_: *const PxBVHStructureDesc, ) -> bool;
pub fn PxBVHStructureDesc_new_1() -> PxBVHStructureDesc;
pub fn PxBVHStructureDesc_setToDefault_mut_1(self_: *mut PxBVHStructureDesc, ) -> ();
pub fn PxBVHStructureDesc_isValid_1(self_: *const PxBVHStructureDesc, ) -> bool;
pub fn PxCookingParams_new(sc: *const PxTolerancesScale, ) -> PxCookingParams;
pub fn PxCooking_release_mut(self_: *mut PxCooking, ) -> ();
pub fn PxCooking_setParams_mut(self_: *mut PxCooking, params: *const PxCookingParams, ) -> ();
pub fn PxCooking_getParams(self_: *const PxCooking, ) -> *const PxCookingParams;
pub fn PxCooking_platformMismatch(self_: *const PxCooking, ) -> bool;
pub fn PxCooking_cookTriangleMesh(self_: *const PxCooking, desc: *const PxTriangleMeshDesc, stream: *mut PxOutputStream, condition: *mut PxTriangleMeshCookingResult::Enum, ) -> bool;
pub fn PxCooking_createTriangleMesh(self_: *const PxCooking, desc: *const PxTriangleMeshDesc, insertionCallback: *mut PxPhysicsInsertionCallback, condition: *mut PxTriangleMeshCookingResult::Enum, ) -> *mut PxTriangleMesh;
pub fn PxCooking_validateTriangleMesh(self_: *const PxCooking, desc: *const PxTriangleMeshDesc, ) -> bool;
pub fn PxCooking_cookConvexMesh(self_: *const PxCooking, desc: *const PxConvexMeshDesc, stream: *mut PxOutputStream, condition: *mut PxConvexMeshCookingResult::Enum, ) -> bool;
pub fn PxCooking_createConvexMesh(self_: *const PxCooking, desc: *const PxConvexMeshDesc, insertionCallback: *mut PxPhysicsInsertionCallback, condition: *mut PxConvexMeshCookingResult::Enum, ) -> *mut PxConvexMesh;
pub fn PxCooking_validateConvexMesh(self_: *const PxCooking, desc: *const PxConvexMeshDesc, ) -> bool;
pub fn PxCooking_computeHullPolygons(self_: *const PxCooking, mesh: *const PxSimpleTriangleMesh, inCallback: *mut PxAllocatorCallback, nbVerts: *mut u32, vertices: *mut *mut PxVec3, nbIndices: *mut u32, indices: *mut *mut u32, nbPolygons: *mut u32, hullPolygons: *mut *mut PxHullPolygon, ) -> bool;
pub fn PxCooking_cookHeightField(self_: *const PxCooking, desc: *const PxHeightFieldDesc, stream: *mut PxOutputStream, ) -> bool;
pub fn PxCooking_createHeightField(self_: *const PxCooking, desc: *const PxHeightFieldDesc, insertionCallback: *mut PxPhysicsInsertionCallback, ) -> *mut PxHeightField;
pub fn PxCooking_cookBVHStructure(self_: *const PxCooking, desc: *const PxBVHStructureDesc, stream: *mut PxOutputStream, ) -> bool;
pub fn PxCooking_createBVHStructure(self_: *const PxCooking, desc: *const PxBVHStructureDesc, insertionCallback: *mut PxPhysicsInsertionCallback, ) -> *mut PxBVHStructure;
pub fn phys_PxCreateCooking(version: u32, foundation: *mut PxFoundation, params: *const PxCookingParams, ) -> *mut PxCooking;
pub fn PxDefaultMemoryOutputStream_new_alloc(allocator: *mut PxAllocatorCallback, ) -> *mut PxDefaultMemoryOutputStream;
pub fn PxDefaultMemoryOutputStream_delete(self_: *mut PxDefaultMemoryOutputStream, ) -> ();
pub fn PxDefaultMemoryOutputStream_write_mut(self_: *mut PxDefaultMemoryOutputStream, src: *const std::ffi::c_void, count: u32, ) -> u32;
pub fn PxDefaultMemoryOutputStream_getSize(self_: *const PxDefaultMemoryOutputStream, ) -> u32;
pub fn PxDefaultMemoryOutputStream_getData(self_: *const PxDefaultMemoryOutputStream, ) -> *mut u8;
pub fn PxDefaultMemoryInputData_new_alloc(data: *mut u8, length: u32, ) -> *mut PxDefaultMemoryInputData;
pub fn PxDefaultMemoryInputData_read_mut(self_: *mut PxDefaultMemoryInputData, dest: *mut std::ffi::c_void, count: u32, ) -> u32;
pub fn PxDefaultMemoryInputData_getLength(self_: *const PxDefaultMemoryInputData, ) -> u32;
pub fn PxDefaultMemoryInputData_seek_mut(self_: *mut PxDefaultMemoryInputData, pos: u32, ) -> ();
pub fn PxDefaultMemoryInputData_tell(self_: *const PxDefaultMemoryInputData, ) -> u32;
pub fn PxDefaultMemoryInputData_delete(self_: *mut PxDefaultMemoryInputData, ) -> ();
pub fn PxDefaultFileOutputStream_new_alloc(name: *const i8, ) -> *mut PxDefaultFileOutputStream;
pub fn PxDefaultFileOutputStream_delete(self_: *mut PxDefaultFileOutputStream, ) -> ();
pub fn PxDefaultFileOutputStream_write_mut(self_: *mut PxDefaultFileOutputStream, src: *const std::ffi::c_void, count: u32, ) -> u32;
pub fn PxDefaultFileOutputStream_isValid_mut(self_: *mut PxDefaultFileOutputStream, ) -> bool;
pub fn PxDefaultFileInputData_new_alloc(name: *const i8, ) -> *mut PxDefaultFileInputData;
pub fn PxDefaultFileInputData_delete(self_: *mut PxDefaultFileInputData, ) -> ();
pub fn PxDefaultFileInputData_read_mut(self_: *mut PxDefaultFileInputData, dest: *mut std::ffi::c_void, count: u32, ) -> u32;
pub fn PxDefaultFileInputData_seek_mut(self_: *mut PxDefaultFileInputData, pos: u32, ) -> ();
pub fn PxDefaultFileInputData_tell(self_: *const PxDefaultFileInputData, ) -> u32;
pub fn PxDefaultFileInputData_getLength(self_: *const PxDefaultFileInputData, ) -> u32;
pub fn PxDefaultFileInputData_isValid(self_: *const PxDefaultFileInputData, ) -> bool;
pub fn PxJoint_setActors_mut(self_: *mut PxJoint, actor0: *mut PxRigidActor, actor1: *mut PxRigidActor, ) -> ();
pub fn PxJoint_getActors(self_: *const PxJoint, actor0: *mut *mut PxRigidActor, actor1: *mut *mut PxRigidActor, ) -> ();
pub fn PxJoint_setLocalPose_mut(self_: *mut PxJoint, actor: PxJointActorIndex::Enum, localPose: *const PxTransform, ) -> ();
pub fn PxJoint_getLocalPose(self_: *const PxJoint, actor: PxJointActorIndex::Enum, ) -> PxTransform;
pub fn PxJoint_getRelativeTransform(self_: *const PxJoint, ) -> PxTransform;
pub fn PxJoint_getRelativeLinearVelocity(self_: *const PxJoint, ) -> PxVec3;
pub fn PxJoint_getRelativeAngularVelocity(self_: *const PxJoint, ) -> PxVec3;
pub fn PxJoint_setBreakForce_mut(self_: *mut PxJoint, force: f32, torque: f32, ) -> ();
pub fn PxJoint_getBreakForce(self_: *const PxJoint, force: *mut f32, torque: *mut f32, ) -> ();
pub fn PxJoint_setConstraintFlags_mut(self_: *mut PxJoint, flags: PxConstraintFlags, ) -> ();
pub fn PxJoint_setConstraintFlag_mut(self_: *mut PxJoint, flag: PxConstraintFlag::Enum, value: bool, ) -> ();
pub fn PxJoint_getConstraintFlags(self_: *const PxJoint, ) -> PxConstraintFlags;
pub fn PxJoint_setInvMassScale0_mut(self_: *mut PxJoint, invMassScale: f32, ) -> ();
pub fn PxJoint_getInvMassScale0(self_: *const PxJoint, ) -> f32;
pub fn PxJoint_setInvInertiaScale0_mut(self_: *mut PxJoint, invInertiaScale: f32, ) -> ();
pub fn PxJoint_getInvInertiaScale0(self_: *const PxJoint, ) -> f32;
pub fn PxJoint_setInvMassScale1_mut(self_: *mut PxJoint, invMassScale: f32, ) -> ();
pub fn PxJoint_getInvMassScale1(self_: *const PxJoint, ) -> f32;
pub fn PxJoint_setInvInertiaScale1_mut(self_: *mut PxJoint, invInertiaScale: f32, ) -> ();
pub fn PxJoint_getInvInertiaScale1(self_: *const PxJoint, ) -> f32;
pub fn PxJoint_getConstraint(self_: *const PxJoint, ) -> *mut PxConstraint;
pub fn PxJoint_setName_mut(self_: *mut PxJoint, name: *const i8, ) -> ();
pub fn PxJoint_getName(self_: *const PxJoint, ) -> *const i8;
pub fn PxJoint_release_mut(self_: *mut PxJoint, ) -> ();
pub fn PxJoint_getScene(self_: *const PxJoint, ) -> *mut PxScene;
pub fn PxJoint_getBinaryMetaData_mut(stream: *mut PxOutputStream, ) -> ();
pub fn PxSpring_new(stiffness_: f32, damping_: f32, ) -> PxSpring;
pub fn phys_PxSetJointGlobalFrame(joint: *mut PxJoint, wsAnchor: *const PxVec3, wsAxis: *const PxVec3, ) -> ();
pub fn phys_PxDistanceJointCreate(physics: *mut PxPhysics, actor0: *mut PxRigidActor, localFrame0: *const PxTransform, actor1: *mut PxRigidActor, localFrame1: *const PxTransform, ) -> *mut PxDistanceJoint;
pub fn PxDistanceJoint_getDistance(self_: *const PxDistanceJoint, ) -> f32;
pub fn PxDistanceJoint_setMinDistance_mut(self_: *mut PxDistanceJoint, distance: f32, ) -> ();
pub fn PxDistanceJoint_getMinDistance(self_: *const PxDistanceJoint, ) -> f32;
pub fn PxDistanceJoint_setMaxDistance_mut(self_: *mut PxDistanceJoint, distance: f32, ) -> ();
pub fn PxDistanceJoint_getMaxDistance(self_: *const PxDistanceJoint, ) -> f32;
pub fn PxDistanceJoint_setTolerance_mut(self_: *mut PxDistanceJoint, tolerance: f32, ) -> ();
pub fn PxDistanceJoint_getTolerance(self_: *const PxDistanceJoint, ) -> f32;
pub fn PxDistanceJoint_setStiffness_mut(self_: *mut PxDistanceJoint, stiffness: f32, ) -> ();
pub fn PxDistanceJoint_getStiffness(self_: *const PxDistanceJoint, ) -> f32;
pub fn PxDistanceJoint_setDamping_mut(self_: *mut PxDistanceJoint, damping: f32, ) -> ();
pub fn PxDistanceJoint_getDamping(self_: *const PxDistanceJoint, ) -> f32;
pub fn PxDistanceJoint_setDistanceJointFlags_mut(self_: *mut PxDistanceJoint, flags: PxDistanceJointFlags, ) -> ();
pub fn PxDistanceJoint_setDistanceJointFlag_mut(self_: *mut PxDistanceJoint, flag: PxDistanceJointFlag::Enum, value: bool, ) -> ();
pub fn PxDistanceJoint_getDistanceJointFlags(self_: *const PxDistanceJoint, ) -> PxDistanceJointFlags;
pub fn PxDistanceJoint_getConcreteTypeName(self_: *const PxDistanceJoint, ) -> *const i8;
pub fn PxDefaultAllocator_allocate_mut(self_: *mut PxDefaultAllocator, size: usize, anonymous_arg1: *const i8, anonymous_arg2: *const i8, anonymous_arg3: i32, ) -> *mut std::ffi::c_void;
pub fn PxDefaultAllocator_deallocate_mut(self_: *mut PxDefaultAllocator, ptr: *mut std::ffi::c_void, ) -> ();
pub fn PxDefaultAllocator_delete(self_: *mut PxDefaultAllocator, ) -> ();
pub fn phys_PxContactJointCreate(physics: *mut PxPhysics, actor0: *mut PxRigidActor, localFrame0: *const PxTransform, actor1: *mut PxRigidActor, localFrame1: *const PxTransform, ) -> *mut PxContactJoint;
pub fn PxJacobianRow_new() -> PxJacobianRow;
pub fn PxJacobianRow_new_1(lin0: *const PxVec3, lin1: *const PxVec3, ang0: *const PxVec3, ang1: *const PxVec3, ) -> PxJacobianRow;
pub fn PxContactJoint_setContact_mut(self_: *mut PxContactJoint, contact: *const PxVec3, ) -> ();
pub fn PxContactJoint_setContactNormal_mut(self_: *mut PxContactJoint, contactNormal: *const PxVec3, ) -> ();
pub fn PxContactJoint_setPenetration_mut(self_: *mut PxContactJoint, penetration: f32, ) -> ();
pub fn PxContactJoint_getContact(self_: *const PxContactJoint, ) -> PxVec3;
pub fn PxContactJoint_getContactNormal(self_: *const PxContactJoint, ) -> PxVec3;
pub fn PxContactJoint_getPenetration(self_: *const PxContactJoint, ) -> f32;
pub fn PxContactJoint_getResititution(self_: *const PxContactJoint, ) -> f32;
pub fn PxContactJoint_setResititution_mut(self_: *mut PxContactJoint, resititution: f32, ) -> ();
pub fn PxContactJoint_getBounceThreshold(self_: *const PxContactJoint, ) -> f32;
pub fn PxContactJoint_setBounceThreshold_mut(self_: *mut PxContactJoint, bounceThreshold: f32, ) -> ();
pub fn PxContactJoint_getConcreteTypeName(self_: *const PxContactJoint, ) -> *const i8;
pub fn PxContactJoint_computeJacobians(self_: *const PxContactJoint, jacobian: *mut PxJacobianRow, ) -> ();
pub fn PxContactJoint_getNbJacobianRows(self_: *const PxContactJoint, ) -> u32;
pub fn phys_PxFixedJointCreate(physics: *mut PxPhysics, actor0: *mut PxRigidActor, localFrame0: *const PxTransform, actor1: *mut PxRigidActor, localFrame1: *const PxTransform, ) -> *mut PxFixedJoint;
pub fn PxFixedJoint_setProjectionLinearTolerance_mut(self_: *mut PxFixedJoint, tolerance: f32, ) -> ();
pub fn PxFixedJoint_getProjectionLinearTolerance(self_: *const PxFixedJoint, ) -> f32;
pub fn PxFixedJoint_setProjectionAngularTolerance_mut(self_: *mut PxFixedJoint, tolerance: f32, ) -> ();
pub fn PxFixedJoint_getProjectionAngularTolerance(self_: *const PxFixedJoint, ) -> f32;
pub fn PxFixedJoint_getConcreteTypeName(self_: *const PxFixedJoint, ) -> *const i8;
pub fn PxJointLimitParameters_new_alloc() -> *mut PxJointLimitParameters;
pub fn PxJointLimitParameters_isValid(self_: *const PxJointLimitParameters, ) -> bool;
pub fn PxJointLimitParameters_isSoft(self_: *const PxJointLimitParameters, ) -> bool;
pub fn PxJointLinearLimit_new(scale: *const PxTolerancesScale, extent: f32, contactDist: f32, ) -> PxJointLinearLimit;
pub fn PxJointLinearLimit_new_1(extent: f32, spring: *const PxSpring, ) -> PxJointLinearLimit;
pub fn PxJointLinearLimit_isValid(self_: *const PxJointLinearLimit, ) -> bool;
pub fn PxJointLinearLimit_delete(self_: *mut PxJointLinearLimit, ) -> ();
pub fn PxJointLinearLimitPair_new(scale: *const PxTolerancesScale, lowerLimit: f32, upperLimit: f32, contactDist: f32, ) -> PxJointLinearLimitPair;
pub fn PxJointLinearLimitPair_new_1(lowerLimit: f32, upperLimit: f32, spring: *const PxSpring, ) -> PxJointLinearLimitPair;
pub fn PxJointLinearLimitPair_isValid(self_: *const PxJointLinearLimitPair, ) -> bool;
pub fn PxJointLinearLimitPair_delete(self_: *mut PxJointLinearLimitPair, ) -> ();
pub fn PxJointAngularLimitPair_new(lowerLimit: f32, upperLimit: f32, contactDist: f32, ) -> PxJointAngularLimitPair;
pub fn PxJointAngularLimitPair_new_1(lowerLimit: f32, upperLimit: f32, spring: *const PxSpring, ) -> PxJointAngularLimitPair;
pub fn PxJointAngularLimitPair_isValid(self_: *const PxJointAngularLimitPair, ) -> bool;
pub fn PxJointAngularLimitPair_delete(self_: *mut PxJointAngularLimitPair, ) -> ();
pub fn PxJointLimitCone_new(yLimitAngle: f32, zLimitAngle: f32, contactDist: f32, ) -> PxJointLimitCone;
pub fn PxJointLimitCone_new_1(yLimitAngle: f32, zLimitAngle: f32, spring: *const PxSpring, ) -> PxJointLimitCone;
pub fn PxJointLimitCone_isValid(self_: *const PxJointLimitCone, ) -> bool;
pub fn PxJointLimitCone_delete(self_: *mut PxJointLimitCone, ) -> ();
pub fn PxJointLimitPyramid_new(yLimitAngleMin: f32, yLimitAngleMax: f32, zLimitAngleMin: f32, zLimitAngleMax: f32, contactDist: f32, ) -> PxJointLimitPyramid;
pub fn PxJointLimitPyramid_new_1(yLimitAngleMin: f32, yLimitAngleMax: f32, zLimitAngleMin: f32, zLimitAngleMax: f32, spring: *const PxSpring, ) -> PxJointLimitPyramid;
pub fn PxJointLimitPyramid_isValid(self_: *const PxJointLimitPyramid, ) -> bool;
pub fn PxJointLimitPyramid_delete(self_: *mut PxJointLimitPyramid, ) -> ();
pub fn phys_PxPrismaticJointCreate(physics: *mut PxPhysics, actor0: *mut PxRigidActor, localFrame0: *const PxTransform, actor1: *mut PxRigidActor, localFrame1: *const PxTransform, ) -> *mut PxPrismaticJoint;
pub fn PxPrismaticJoint_getPosition(self_: *const PxPrismaticJoint, ) -> f32;
pub fn PxPrismaticJoint_getVelocity(self_: *const PxPrismaticJoint, ) -> f32;
pub fn PxPrismaticJoint_setLimit_mut(self_: *mut PxPrismaticJoint, anonymous_arg0: *const PxJointLinearLimitPair, ) -> ();
pub fn PxPrismaticJoint_getLimit(self_: *const PxPrismaticJoint, ) -> PxJointLinearLimitPair;
pub fn PxPrismaticJoint_setPrismaticJointFlags_mut(self_: *mut PxPrismaticJoint, flags: PxPrismaticJointFlags, ) -> ();
pub fn PxPrismaticJoint_setPrismaticJointFlag_mut(self_: *mut PxPrismaticJoint, flag: PxPrismaticJointFlag::Enum, value: bool, ) -> ();
pub fn PxPrismaticJoint_getPrismaticJointFlags(self_: *const PxPrismaticJoint, ) -> PxPrismaticJointFlags;
pub fn PxPrismaticJoint_setProjectionLinearTolerance_mut(self_: *mut PxPrismaticJoint, tolerance: f32, ) -> ();
pub fn PxPrismaticJoint_getProjectionLinearTolerance(self_: *const PxPrismaticJoint, ) -> f32;
pub fn PxPrismaticJoint_setProjectionAngularTolerance_mut(self_: *mut PxPrismaticJoint, tolerance: f32, ) -> ();
pub fn PxPrismaticJoint_getProjectionAngularTolerance(self_: *const PxPrismaticJoint, ) -> f32;
pub fn PxPrismaticJoint_getConcreteTypeName(self_: *const PxPrismaticJoint, ) -> *const i8;
pub fn phys_PxRevoluteJointCreate(physics: *mut PxPhysics, actor0: *mut PxRigidActor, localFrame0: *const PxTransform, actor1: *mut PxRigidActor, localFrame1: *const PxTransform, ) -> *mut PxRevoluteJoint;
pub fn PxRevoluteJoint_getAngle(self_: *const PxRevoluteJoint, ) -> f32;
pub fn PxRevoluteJoint_getVelocity(self_: *const PxRevoluteJoint, ) -> f32;
pub fn PxRevoluteJoint_setLimit_mut(self_: *mut PxRevoluteJoint, limits: *const PxJointAngularLimitPair, ) -> ();
pub fn PxRevoluteJoint_getLimit(self_: *const PxRevoluteJoint, ) -> PxJointAngularLimitPair;
pub fn PxRevoluteJoint_setDriveVelocity_mut(self_: *mut PxRevoluteJoint, velocity: f32, autowake: bool, ) -> ();
pub fn PxRevoluteJoint_getDriveVelocity(self_: *const PxRevoluteJoint, ) -> f32;
pub fn PxRevoluteJoint_setDriveForceLimit_mut(self_: *mut PxRevoluteJoint, limit: f32, ) -> ();
pub fn PxRevoluteJoint_getDriveForceLimit(self_: *const PxRevoluteJoint, ) -> f32;
pub fn PxRevoluteJoint_setDriveGearRatio_mut(self_: *mut PxRevoluteJoint, ratio: f32, ) -> ();
pub fn PxRevoluteJoint_getDriveGearRatio(self_: *const PxRevoluteJoint, ) -> f32;
pub fn PxRevoluteJoint_setRevoluteJointFlags_mut(self_: *mut PxRevoluteJoint, flags: PxRevoluteJointFlags, ) -> ();
pub fn PxRevoluteJoint_setRevoluteJointFlag_mut(self_: *mut PxRevoluteJoint, flag: PxRevoluteJointFlag::Enum, value: bool, ) -> ();
pub fn PxRevoluteJoint_getRevoluteJointFlags(self_: *const PxRevoluteJoint, ) -> PxRevoluteJointFlags;
pub fn PxRevoluteJoint_setProjectionLinearTolerance_mut(self_: *mut PxRevoluteJoint, tolerance: f32, ) -> ();
pub fn PxRevoluteJoint_getProjectionLinearTolerance(self_: *const PxRevoluteJoint, ) -> f32;
pub fn PxRevoluteJoint_setProjectionAngularTolerance_mut(self_: *mut PxRevoluteJoint, tolerance: f32, ) -> ();
pub fn PxRevoluteJoint_getProjectionAngularTolerance(self_: *const PxRevoluteJoint, ) -> f32;
pub fn PxRevoluteJoint_getConcreteTypeName(self_: *const PxRevoluteJoint, ) -> *const i8;
pub fn phys_PxSphericalJointCreate(physics: *mut PxPhysics, actor0: *mut PxRigidActor, localFrame0: *const PxTransform, actor1: *mut PxRigidActor, localFrame1: *const PxTransform, ) -> *mut PxSphericalJoint;
pub fn PxSphericalJoint_getLimitCone(self_: *const PxSphericalJoint, ) -> PxJointLimitCone;
pub fn PxSphericalJoint_setLimitCone_mut(self_: *mut PxSphericalJoint, limit: *const PxJointLimitCone, ) -> ();
pub fn PxSphericalJoint_getSwingYAngle(self_: *const PxSphericalJoint, ) -> f32;
pub fn PxSphericalJoint_getSwingZAngle(self_: *const PxSphericalJoint, ) -> f32;
pub fn PxSphericalJoint_setSphericalJointFlags_mut(self_: *mut PxSphericalJoint, flags: PxSphericalJointFlags, ) -> ();
pub fn PxSphericalJoint_setSphericalJointFlag_mut(self_: *mut PxSphericalJoint, flag: PxSphericalJointFlag::Enum, value: bool, ) -> ();
pub fn PxSphericalJoint_getSphericalJointFlags(self_: *const PxSphericalJoint, ) -> PxSphericalJointFlags;
pub fn PxSphericalJoint_setProjectionLinearTolerance_mut(self_: *mut PxSphericalJoint, tolerance: f32, ) -> ();
pub fn PxSphericalJoint_getProjectionLinearTolerance(self_: *const PxSphericalJoint, ) -> f32;
pub fn PxSphericalJoint_getConcreteTypeName(self_: *const PxSphericalJoint, ) -> *const i8;
pub fn phys_PxD6JointCreate(physics: *mut PxPhysics, actor0: *mut PxRigidActor, localFrame0: *const PxTransform, actor1: *mut PxRigidActor, localFrame1: *const PxTransform, ) -> *mut PxD6Joint;
pub fn PxD6JointDrive_new() -> PxD6JointDrive;
pub fn PxD6JointDrive_new_1(driveStiffness: f32, driveDamping: f32, driveForceLimit: f32, isAcceleration: bool, ) -> PxD6JointDrive;
pub fn PxD6JointDrive_isValid(self_: *const PxD6JointDrive, ) -> bool;
pub fn PxD6Joint_setMotion_mut(self_: *mut PxD6Joint, axis: PxD6Axis::Enum, _type: PxD6Motion::Enum, ) -> ();
pub fn PxD6Joint_getMotion(self_: *const PxD6Joint, axis: PxD6Axis::Enum, ) -> PxD6Motion::Enum;
pub fn PxD6Joint_getTwistAngle(self_: *const PxD6Joint, ) -> f32;
pub fn PxD6Joint_getTwist(self_: *const PxD6Joint, ) -> f32;
pub fn PxD6Joint_getSwingYAngle(self_: *const PxD6Joint, ) -> f32;
pub fn PxD6Joint_getSwingZAngle(self_: *const PxD6Joint, ) -> f32;
pub fn PxD6Joint_setDistanceLimit_mut(self_: *mut PxD6Joint, limit: *const PxJointLinearLimit, ) -> ();
pub fn PxD6Joint_getDistanceLimit(self_: *const PxD6Joint, ) -> PxJointLinearLimit;
pub fn PxD6Joint_setLinearLimit_mut(self_: *mut PxD6Joint, limit: *const PxJointLinearLimit, ) -> ();
pub fn PxD6Joint_getLinearLimit(self_: *const PxD6Joint, ) -> PxJointLinearLimit;
pub fn PxD6Joint_setLinearLimit_mut_1(self_: *mut PxD6Joint, axis: PxD6Axis::Enum, limit: *const PxJointLinearLimitPair, ) -> ();
pub fn PxD6Joint_getLinearLimit_1(self_: *const PxD6Joint, axis: PxD6Axis::Enum, ) -> PxJointLinearLimitPair;
pub fn PxD6Joint_setTwistLimit_mut(self_: *mut PxD6Joint, limit: *const PxJointAngularLimitPair, ) -> ();
pub fn PxD6Joint_getTwistLimit(self_: *const PxD6Joint, ) -> PxJointAngularLimitPair;
pub fn PxD6Joint_setSwingLimit_mut(self_: *mut PxD6Joint, limit: *const PxJointLimitCone, ) -> ();
pub fn PxD6Joint_getSwingLimit(self_: *const PxD6Joint, ) -> PxJointLimitCone;
pub fn PxD6Joint_setPyramidSwingLimit_mut(self_: *mut PxD6Joint, limit: *const PxJointLimitPyramid, ) -> ();
pub fn PxD6Joint_getPyramidSwingLimit(self_: *const PxD6Joint, ) -> PxJointLimitPyramid;
pub fn PxD6Joint_setDrive_mut(self_: *mut PxD6Joint, index: PxD6Drive::Enum, drive: *const PxD6JointDrive, ) -> ();
pub fn PxD6Joint_getDrive(self_: *const PxD6Joint, index: PxD6Drive::Enum, ) -> PxD6JointDrive;
pub fn PxD6Joint_setDrivePosition_mut(self_: *mut PxD6Joint, pose: *const PxTransform, autowake: bool, ) -> ();
pub fn PxD6Joint_getDrivePosition(self_: *const PxD6Joint, ) -> PxTransform;
pub fn PxD6Joint_setDriveVelocity_mut(self_: *mut PxD6Joint, linear: *const PxVec3, angular: *const PxVec3, autowake: bool, ) -> ();
pub fn PxD6Joint_getDriveVelocity(self_: *const PxD6Joint, linear: *mut PxVec3, angular: *mut PxVec3, ) -> ();
pub fn PxD6Joint_setProjectionLinearTolerance_mut(self_: *mut PxD6Joint, tolerance: f32, ) -> ();
pub fn PxD6Joint_getProjectionLinearTolerance(self_: *const PxD6Joint, ) -> f32;
pub fn PxD6Joint_setProjectionAngularTolerance_mut(self_: *mut PxD6Joint, tolerance: f32, ) -> ();
pub fn PxD6Joint_getProjectionAngularTolerance(self_: *const PxD6Joint, ) -> f32;
pub fn PxD6Joint_getConcreteTypeName(self_: *const PxD6Joint, ) -> *const i8;
pub fn PxGroupsMask_new_alloc() -> *mut PxGroupsMask;
pub fn PxGroupsMask_delete(self_: *mut PxGroupsMask, ) -> ();
pub fn phys_PxDefaultSimulationFilterShader(attributes0: u32, filterData0: PxFilterData, attributes1: u32, filterData1: PxFilterData, pairFlags: *mut PxPairFlags, constantBlock: *const std::ffi::c_void, constantBlockSize: u32, ) -> PxFilterFlags;
pub fn phys_PxGetGroupCollisionFlag(group1: u16, group2: u16, ) -> bool;
pub fn phys_PxSetGroupCollisionFlag(group1: u16, group2: u16, enable: bool, ) -> ();
pub fn phys_PxGetGroup(actor: *const PxActor, ) -> u16;
pub fn phys_PxSetGroup(actor: *mut PxActor, collisionGroup: u16, ) -> ();
pub fn phys_PxGetFilterOps(op0: *mut PxFilterOp::Enum, op1: *mut PxFilterOp::Enum, op2: *mut PxFilterOp::Enum, ) -> ();
pub fn phys_PxSetFilterOps(op0: *const PxFilterOp::Enum, op1: *const PxFilterOp::Enum, op2: *const PxFilterOp::Enum, ) -> ();
pub fn phys_PxGetFilterBool() -> bool;
pub fn phys_PxSetFilterBool(enable: bool, ) -> ();
pub fn phys_PxGetFilterConstants(c0: *mut PxGroupsMask, c1: *mut PxGroupsMask, ) -> ();
pub fn phys_PxSetFilterConstants(c0: *const PxGroupsMask, c1: *const PxGroupsMask, ) -> ();
pub fn phys_PxGetGroupsMask(actor: *const PxActor, ) -> PxGroupsMask;
pub fn phys_PxSetGroupsMask(actor: *mut PxActor, mask: *const PxGroupsMask, ) -> ();
pub fn PxDefaultErrorCallback_new_alloc() -> *mut PxDefaultErrorCallback;
pub fn PxDefaultErrorCallback_delete(self_: *mut PxDefaultErrorCallback, ) -> ();
pub fn PxDefaultErrorCallback_reportError_mut(self_: *mut PxDefaultErrorCallback, code: PxErrorCode::Enum, message: *const i8, file: *const i8, line: i32, ) -> ();
pub fn PxRigidActorExt_createExclusiveShape_mut(actor: *mut PxRigidActor, geometry: *const PxGeometry, materials: *const *mut PxMaterial, materialCount: u16, shapeFlags: PxShapeFlags, ) -> *mut PxShape;
pub fn PxRigidActorExt_createExclusiveShape_mut_1(actor: *mut PxRigidActor, geometry: *const PxGeometry, material: *const PxMaterial, shapeFlags: PxShapeFlags, ) -> *mut PxShape;
pub fn PxRigidActorExt_getRigidActorShapeLocalBoundsList_mut(actor: *const PxRigidActor, numBounds: *mut u32, ) -> *mut PxBounds3;
pub fn PxMassProperties_new() -> PxMassProperties;
pub fn PxMassProperties_new_1(m: f32, inertiaT: *const PxMat33, com: *const PxVec3, ) -> PxMassProperties;
pub fn PxMassProperties_new_2(geometry: *const PxGeometry, ) -> PxMassProperties;
pub fn PxMassProperties_translate_mut(self_: *mut PxMassProperties, t: *const PxVec3, ) -> ();
pub fn PxMassProperties_getMassSpaceInertia_mut(inertia: *const PxMat33, massFrame: *mut PxQuat, ) -> PxVec3;
pub fn PxMassProperties_translateInertia_mut(inertia: *const PxMat33, mass: f32, t: *const PxVec3, ) -> PxMat33;
pub fn PxMassProperties_rotateInertia_mut(inertia: *const PxMat33, q: *const PxQuat, ) -> PxMat33;
pub fn PxMassProperties_scaleInertia_mut(inertia: *const PxMat33, scaleRotation: *const PxQuat, scale: *const PxVec3, ) -> PxMat33;
pub fn PxMassProperties_sum_mut(props: *const PxMassProperties, transforms: *const PxTransform, count: u32, ) -> PxMassProperties;
pub fn PxRigidBodyExt_updateMassAndInertia_mut(body: *mut PxRigidBody, shapeDensities: *const f32, shapeDensityCount: u32, massLocalPose: *const PxVec3, includeNonSimShapes: bool, ) -> bool;
pub fn PxRigidBodyExt_updateMassAndInertia_mut_1(body: *mut PxRigidBody, density: f32, massLocalPose: *const PxVec3, includeNonSimShapes: bool, ) -> bool;
pub fn PxRigidBodyExt_setMassAndUpdateInertia_mut(body: *mut PxRigidBody, shapeMasses: *const f32, shapeMassCount: u32, massLocalPose: *const PxVec3, includeNonSimShapes: bool, ) -> bool;
pub fn PxRigidBodyExt_setMassAndUpdateInertia_mut_1(body: *mut PxRigidBody, mass: f32, massLocalPose: *const PxVec3, includeNonSimShapes: bool, ) -> bool;
pub fn PxRigidBodyExt_computeMassPropertiesFromShapes_mut(shapes: *const *const PxShape, shapeCount: u32, ) -> PxMassProperties;
pub fn PxRigidBodyExt_addForceAtPos_mut(body: *mut PxRigidBody, force: *const PxVec3, pos: *const PxVec3, mode: PxForceMode::Enum, wakeup: bool, ) -> ();
pub fn PxRigidBodyExt_addForceAtLocalPos_mut(body: *mut PxRigidBody, force: *const PxVec3, pos: *const PxVec3, mode: PxForceMode::Enum, wakeup: bool, ) -> ();
pub fn PxRigidBodyExt_addLocalForceAtPos_mut(body: *mut PxRigidBody, force: *const PxVec3, pos: *const PxVec3, mode: PxForceMode::Enum, wakeup: bool, ) -> ();
pub fn PxRigidBodyExt_addLocalForceAtLocalPos_mut(body: *mut PxRigidBody, force: *const PxVec3, pos: *const PxVec3, mode: PxForceMode::Enum, wakeup: bool, ) -> ();
pub fn PxRigidBodyExt_getVelocityAtPos_mut(body: *const PxRigidBody, pos: *const PxVec3, ) -> PxVec3;
pub fn PxRigidBodyExt_getLocalVelocityAtLocalPos_mut(body: *const PxRigidBody, pos: *const PxVec3, ) -> PxVec3;
pub fn PxRigidBodyExt_getVelocityAtOffset_mut(body: *const PxRigidBody, pos: *const PxVec3, ) -> PxVec3;
pub fn PxRigidBodyExt_linearSweepSingle_mut(body: *mut PxRigidBody, scene: *mut PxScene, unitDir: *const PxVec3, distance: f32, outputFlags: PxHitFlags, closestHit: *mut PxSweepHit, shapeIndex: *mut u32, filterData: *const PxQueryFilterData, filterCall: *mut PxQueryFilterCallback, cache: *const PxQueryCache, inflation: f32, ) -> bool;
pub fn PxRigidBodyExt_linearSweepMultiple_mut(body: *mut PxRigidBody, scene: *mut PxScene, unitDir: *const PxVec3, distance: f32, outputFlags: PxHitFlags, touchHitBuffer: *mut PxSweepHit, touchHitShapeIndices: *mut u32, touchHitBufferSize: u32, block: *mut PxSweepHit, blockingShapeIndex: *mut i32, overflow: *mut bool, filterData: *const PxQueryFilterData, filterCall: *mut PxQueryFilterCallback, cache: *const PxQueryCache, inflation: f32, ) -> u32;
pub fn PxRigidBodyExt_computeVelocityDeltaFromImpulse_mut(body: *const PxRigidBody, impulsiveForce: *const PxVec3, impulsiveTorque: *const PxVec3, deltaLinearVelocity: *mut PxVec3, deltaAngularVelocity: *mut PxVec3, ) -> ();
pub fn PxRigidBodyExt_computeVelocityDeltaFromImpulse_mut_1(body: *const PxRigidBody, globalPose: *const PxTransform, point: *const PxVec3, impulse: *const PxVec3, invMassScale: f32, invInertiaScale: f32, deltaLinearVelocity: *mut PxVec3, deltaAngularVelocity: *mut PxVec3, ) -> ();
pub fn PxRigidBodyExt_computeLinearAngularImpulse_mut(body: *const PxRigidBody, globalPose: *const PxTransform, point: *const PxVec3, impulse: *const PxVec3, invMassScale: f32, invInertiaScale: f32, linearImpulse: *mut PxVec3, angularImpulse: *mut PxVec3, ) -> ();
pub fn PxShapeExt_getGlobalPose_mut(shape: *const PxShape, actor: *const PxRigidActor, ) -> PxTransform;
pub fn PxShapeExt_raycast_mut(shape: *const PxShape, actor: *const PxRigidActor, rayOrigin: *const PxVec3, rayDir: *const PxVec3, maxDist: f32, hitFlags: PxHitFlags, maxHits: u32, rayHits: *mut PxRaycastHit, ) -> u32;
pub fn PxShapeExt_overlap_mut(shape: *const PxShape, actor: *const PxRigidActor, otherGeom: *const PxGeometry, otherGeomPose: *const PxTransform, ) -> bool;
pub fn PxShapeExt_sweep_mut(shape: *const PxShape, actor: *const PxRigidActor, unitDir: *const PxVec3, distance: f32, otherGeom: *const PxGeometry, otherGeomPose: *const PxTransform, sweepHit: *mut PxSweepHit, hitFlags: PxHitFlags, ) -> bool;
pub fn PxShapeExt_getWorldBounds_mut(shape: *const PxShape, actor: *const PxRigidActor, inflation: f32, ) -> PxBounds3;
pub fn PxMeshOverlapUtil_new_alloc() -> *mut PxMeshOverlapUtil;
pub fn PxMeshOverlapUtil_delete(self_: *mut PxMeshOverlapUtil, ) -> ();
pub fn PxMeshOverlapUtil_findOverlap_mut(self_: *mut PxMeshOverlapUtil, geom: *const PxGeometry, geomPose: *const PxTransform, meshGeom: *const PxTriangleMeshGeometry, meshPose: *const PxTransform, ) -> u32;
pub fn PxMeshOverlapUtil_findOverlap_mut_1(self_: *mut PxMeshOverlapUtil, geom: *const PxGeometry, geomPose: *const PxTransform, hfGeom: *const PxHeightFieldGeometry, hfPose: *const PxTransform, ) -> u32;
pub fn PxMeshOverlapUtil_getResults(self_: *const PxMeshOverlapUtil, ) -> *const u32;
pub fn PxMeshOverlapUtil_getNbResults(self_: *const PxMeshOverlapUtil, ) -> u32;
pub fn phys_PxComputeTriangleMeshPenetration(direction: *mut PxVec3, depth: *mut f32, geom: *const PxGeometry, geomPose: *const PxTransform, meshGeom: *const PxTriangleMeshGeometry, meshPose: *const PxTransform, maxIter: u32, usedIter: *mut u32, ) -> bool;
pub fn phys_PxComputeHeightFieldPenetration(direction: *mut PxVec3, depth: *mut f32, geom: *const PxGeometry, geomPose: *const PxTransform, heightFieldGeom: *const PxHeightFieldGeometry, heightFieldPose: *const PxTransform, maxIter: u32, usedIter: *mut u32, ) -> bool;
pub fn PxXmlMiscParameter_new() -> PxSerialization_PxXmlMiscParameter;
pub fn PxXmlMiscParameter_new_1(inUpVector: *mut PxVec3, inScale: PxTolerancesScale, ) -> PxSerialization_PxXmlMiscParameter;
pub fn PxSerialization_isSerializable_mut(collection: *mut PxCollection, sr: *mut PxSerializationRegistry, externalReferences: *const PxCollection, ) -> bool;
pub fn PxSerialization_complete_mut(collection: *mut PxCollection, sr: *mut PxSerializationRegistry, exceptFor: *const PxCollection, followJoints: bool, ) -> ();
pub fn PxSerialization_createSerialObjectIds_mut(collection: *mut PxCollection, base: usize, ) -> ();
pub fn PxSerialization_createCollectionFromXml_mut(inputData: *mut PxInputData, cooking: *mut PxCooking, sr: *mut PxSerializationRegistry, externalRefs: *const PxCollection, stringTable: *mut PxStringTable, outArgs: *mut PxSerialization_PxXmlMiscParameter, ) -> *mut PxCollection;
pub fn PxSerialization_createCollectionFromBinary_mut(memBlock: *mut std::ffi::c_void, sr: *mut PxSerializationRegistry, externalRefs: *const PxCollection, ) -> *mut PxCollection;
pub fn PxSerialization_serializeCollectionToXml_mut(outputStream: *mut PxOutputStream, collection: *mut PxCollection, sr: *mut PxSerializationRegistry, cooking: *mut PxCooking, externalRefs: *const PxCollection, inArgs: *mut PxSerialization_PxXmlMiscParameter, ) -> bool;
pub fn PxSerialization_serializeCollectionToBinary_mut(outputStream: *mut PxOutputStream, collection: *mut PxCollection, sr: *mut PxSerializationRegistry, externalRefs: *const PxCollection, exportNames: bool, ) -> bool;
pub fn PxSerialization_serializeCollectionToBinaryDeterministic_mut(outputStream: *mut PxOutputStream, collection: *mut PxCollection, sr: *mut PxSerializationRegistry, externalRefs: *const PxCollection, exportNames: bool, ) -> bool;
pub fn PxSerialization_dumpBinaryMetaData_mut(outputStream: *mut PxOutputStream, sr: *mut PxSerializationRegistry, ) -> ();
pub fn PxSerialization_createBinaryConverter_mut() -> *mut PxBinaryConverter;
pub fn PxSerialization_createSerializationRegistry_mut(physics: *mut PxPhysics, ) -> *mut PxSerializationRegistry;
pub fn PxDefaultCpuDispatcher_release_mut(self_: *mut PxDefaultCpuDispatcher, ) -> ();
pub fn PxDefaultCpuDispatcher_setRunProfiled_mut(self_: *mut PxDefaultCpuDispatcher, runProfiled: bool, ) -> ();
pub fn PxDefaultCpuDispatcher_getRunProfiled(self_: *const PxDefaultCpuDispatcher, ) -> bool;
pub fn phys_PxDefaultCpuDispatcherCreate(numThreads: u32, affinityMasks: *mut u32, ) -> *mut PxDefaultCpuDispatcher;
pub fn phys_PxBuildSmoothNormals(nbTris: u32, nbVerts: u32, verts: *const PxVec3, dFaces: *const u32, wFaces: *const u16, normals: *mut PxVec3, flip: bool, ) -> bool;
pub fn phys_PxCreateDynamic(sdk: *mut PxPhysics, transform: *const PxTransform, geometry: *const PxGeometry, material: *mut PxMaterial, density: f32, shapeOffset: *const PxTransform, ) -> *mut PxRigidDynamic;
pub fn phys_PxCreateDynamic_1(sdk: *mut PxPhysics, transform: *const PxTransform, shape: *mut PxShape, density: f32, ) -> *mut PxRigidDynamic;
pub fn phys_PxCreateKinematic(sdk: *mut PxPhysics, transform: *const PxTransform, geometry: *const PxGeometry, material: *mut PxMaterial, density: f32, shapeOffset: *const PxTransform, ) -> *mut PxRigidDynamic;
pub fn phys_PxCreateKinematic_1(sdk: *mut PxPhysics, transform: *const PxTransform, shape: *mut PxShape, density: f32, ) -> *mut PxRigidDynamic;
pub fn phys_PxCreateStatic(sdk: *mut PxPhysics, transform: *const PxTransform, geometry: *const PxGeometry, material: *mut PxMaterial, shapeOffset: *const PxTransform, ) -> *mut PxRigidStatic;
pub fn phys_PxCreateStatic_1(sdk: *mut PxPhysics, transform: *const PxTransform, shape: *mut PxShape, ) -> *mut PxRigidStatic;
pub fn phys_PxCreateStatic_2(sdk: *mut PxPhysics, transform: *const PxTransform, shape: *mut PxShape, ) -> *mut PxRigidStatic;
pub fn phys_PxCloneShape(physicsSDK: *mut PxPhysics, shape: *const PxShape, isExclusive: bool, ) -> *mut PxShape;
pub fn phys_PxCloneStatic(physicsSDK: *mut PxPhysics, transform: *const PxTransform, actor: *const PxRigidActor, ) -> *mut PxRigidStatic;
pub fn phys_PxCloneDynamic(physicsSDK: *mut PxPhysics, transform: *const PxTransform, body: *const PxRigidDynamic, ) -> *mut PxRigidDynamic;
pub fn phys_PxCreatePlane(sdk: *mut PxPhysics, plane: *const PxPlane, material: *mut PxMaterial, ) -> *mut PxRigidStatic;
pub fn phys_PxScaleRigidActor(actor: *mut PxRigidActor, scale: f32, scaleMassProps: bool, ) -> ();
pub fn PxStringTableExt_createStringTable_mut(inAllocator: *mut PxAllocatorCallback, ) -> *mut PxStringTable;
pub fn PxBroadPhaseExt_createRegionsFromWorldBounds_mut(regions: *mut PxBounds3, globalBounds: *const PxBounds3, nbSubdiv: u32, upAxis: u32, ) -> u32;
pub fn PxSceneQueryExt_raycastAny_mut(scene: *const PxScene, origin: *const PxVec3, unitDir: *const PxVec3, distance: f32, hit: *mut PxSceneQueryHit, filterData: *const PxSceneQueryFilterData, filterCall: *mut PxSceneQueryFilterCallback, cache: *const PxSceneQueryCache, ) -> bool;
pub fn PxSceneQueryExt_raycastSingle_mut(scene: *const PxScene, origin: *const PxVec3, unitDir: *const PxVec3, distance: f32, outputFlags: PxSceneQueryFlags, hit: *mut PxRaycastHit, filterData: *const PxSceneQueryFilterData, filterCall: *mut PxSceneQueryFilterCallback, cache: *const PxSceneQueryCache, ) -> bool;
pub fn PxSceneQueryExt_raycastMultiple_mut(scene: *const PxScene, origin: *const PxVec3, unitDir: *const PxVec3, distance: f32, outputFlags: PxSceneQueryFlags, hitBuffer: *mut PxRaycastHit, hitBufferSize: u32, blockingHit: *mut bool, filterData: *const PxSceneQueryFilterData, filterCall: *mut PxSceneQueryFilterCallback, cache: *const PxSceneQueryCache, ) -> i32;
pub fn PxSceneQueryExt_sweepAny_mut(scene: *const PxScene, geometry: *const PxGeometry, pose: *const PxTransform, unitDir: *const PxVec3, distance: f32, queryFlags: PxSceneQueryFlags, hit: *mut PxSceneQueryHit, filterData: *const PxSceneQueryFilterData, filterCall: *mut PxSceneQueryFilterCallback, cache: *const PxSceneQueryCache, inflation: f32, ) -> bool;
pub fn PxSceneQueryExt_sweepSingle_mut(scene: *const PxScene, geometry: *const PxGeometry, pose: *const PxTransform, unitDir: *const PxVec3, distance: f32, outputFlags: PxSceneQueryFlags, hit: *mut PxSweepHit, filterData: *const PxSceneQueryFilterData, filterCall: *mut PxSceneQueryFilterCallback, cache: *const PxSceneQueryCache, inflation: f32, ) -> bool;
pub fn PxSceneQueryExt_sweepMultiple_mut(scene: *const PxScene, geometry: *const PxGeometry, pose: *const PxTransform, unitDir: *const PxVec3, distance: f32, outputFlags: PxSceneQueryFlags, hitBuffer: *mut PxSweepHit, hitBufferSize: u32, blockingHit: *mut bool, filterData: *const PxSceneQueryFilterData, filterCall: *mut PxSceneQueryFilterCallback, cache: *const PxSceneQueryCache, inflation: f32, ) -> i32;
pub fn PxSceneQueryExt_overlapMultiple_mut(scene: *const PxScene, geometry: *const PxGeometry, pose: *const PxTransform, hitBuffer: *mut PxOverlapHit, hitBufferSize: u32, filterData: *const PxSceneQueryFilterData, filterCall: *mut PxSceneQueryFilterCallback, ) -> i32;
pub fn PxSceneQueryExt_overlapAny_mut(scene: *const PxScene, geometry: *const PxGeometry, pose: *const PxTransform, hit: *mut PxOverlapHit, filterData: *const PxSceneQueryFilterData, filterCall: *mut PxSceneQueryFilterCallback, ) -> bool;
pub fn phys_PxInitExtensions(physics: *mut PxPhysics, pvd: *mut PxPvd, ) -> bool;
pub fn phys_PxCloseExtensions() -> ();
pub fn phys_PxFindFaceIndex(convexGeom: *const PxConvexMeshGeometry, geomPose: *const PxTransform, impactPos: *const PxVec3, unitDir: *const PxVec3, ) -> u32;
pub fn PxBinaryConverter_release_mut(self_: *mut PxBinaryConverter, ) -> ();
pub fn PxBinaryConverter_setReportMode_mut(self_: *mut PxBinaryConverter, mode: PxConverterReportMode::Enum, ) -> ();
pub fn PxBinaryConverter_setMetaData_mut(self_: *mut PxBinaryConverter, srcMetaData: *mut PxInputStream, dstMetaData: *mut PxInputStream, ) -> bool;
pub fn PxBinaryConverter_compareMetaData(self_: *const PxBinaryConverter, ) -> bool;
pub fn PxBinaryConverter_convert_mut(self_: *mut PxBinaryConverter, srcStream: *mut PxInputStream, srcSize: u32, targetStream: *mut PxOutputStream, ) -> bool;
pub fn PxRepXObject_new(inTypeName: *const i8, inSerializable: *const std::ffi::c_void, inId: usize, ) -> PxRepXObject;
pub fn PxRepXObject_isValid(self_: *const PxRepXObject, ) -> bool;
pub fn PxRepXInstantiationArgs_new(inPhysics: *mut PxPhysics, inCooking: *mut PxCooking, inStringTable: *mut PxStringTable, ) -> PxRepXInstantiationArgs;
pub fn PxRepXSerializer_getTypeName_mut(self_: *mut PxRepXSerializer, ) -> *const i8;
pub fn PxRepXSerializer_objectToFile_mut(self_: *mut PxRepXSerializer, inLiveObject: *const PxRepXObject, inCollection: *mut PxCollection, inWriter: *mut XmlWriter, inTempBuffer: *mut MemoryBuffer, inArgs: *mut PxRepXInstantiationArgs, ) -> ();
pub fn PxRepXSerializer_fileToObject_mut(self_: *mut PxRepXSerializer, inReader: *mut XmlReader, inAllocator: *mut XmlMemoryAllocator, inArgs: *mut PxRepXInstantiationArgs, inCollection: *mut PxCollection, ) -> PxRepXObject;
pub fn phys_PxCreateRepXObject(inType: *const PxBase, inId: usize, ) -> PxRepXObject;
pub fn phys_PxInitVehicleSDK(physics: *mut PxPhysics, serializationRegistry: *mut PxSerializationRegistry, ) -> bool;
pub fn phys_PxCloseVehicleSDK(serializationRegistry: *mut PxSerializationRegistry, ) -> ();
pub fn phys_PxVehicleSetBasisVectors(up: *const PxVec3, forward: *const PxVec3, ) -> ();
pub fn phys_PxVehicleSetUpdateMode(vehicleUpdateMode: PxVehicleUpdateMode::Enum, ) -> ();
pub fn phys_PxVehicleSetSweepHitRejectionAngles(pointRejectAngle: f32, normalRejectAngle: f32, ) -> ();
pub fn phys_PxVehicleSetMaxHitActorAcceleration(maxHitActorAcceleration: f32, ) -> ();
pub fn PxVehicleChassisData_new() -> PxVehicleChassisData;
pub fn PxVehicleEngineData_new() -> PxVehicleEngineData;
pub fn PxVehicleEngineData_getRecipMOI(self_: *const PxVehicleEngineData, ) -> f32;
pub fn PxVehicleEngineData_getRecipMaxOmega(self_: *const PxVehicleEngineData, ) -> f32;
pub fn PxVehicleEngineData_new_1(anonymous_arg0: PxEMPTY, ) -> PxVehicleEngineData;
pub fn PxVehicleEngineData_delete(self_: *mut PxVehicleEngineData, ) -> ();
pub fn PxVehicleGearsData_new() -> PxVehicleGearsData;
pub fn PxVehicleGearsData_new_1(anonymous_arg0: PxEMPTY, ) -> PxVehicleGearsData;
pub fn PxVehicleGearsData_getGearRatio(self_: *const PxVehicleGearsData, a: PxVehicleGearsDataEnum::Enum, ) -> f32;
pub fn PxVehicleGearsData_setGearRatio_mut(self_: *mut PxVehicleGearsData, a: PxVehicleGearsDataEnum::Enum, ratio: f32, ) -> ();
pub fn PxVehicleAutoBoxData_new() -> PxVehicleAutoBoxData;
pub fn PxVehicleAutoBoxData_setLatency_mut(self_: *mut PxVehicleAutoBoxData, latency: f32, ) -> ();
pub fn PxVehicleAutoBoxData_getLatency(self_: *const PxVehicleAutoBoxData, ) -> f32;
pub fn PxVehicleAutoBoxData_new_1(anonymous_arg0: PxEMPTY, ) -> PxVehicleAutoBoxData;
pub fn PxVehicleAutoBoxData_getUpRatios(self_: *const PxVehicleAutoBoxData, a: PxVehicleGearsDataEnum::Enum, ) -> f32;
pub fn PxVehicleAutoBoxData_setUpRatios_mut(self_: *mut PxVehicleAutoBoxData, a: PxVehicleGearsDataEnum::Enum, ratio: f32, ) -> ();
pub fn PxVehicleAutoBoxData_getDownRatios(self_: *const PxVehicleAutoBoxData, a: PxVehicleGearsDataEnum::Enum, ) -> f32;
pub fn PxVehicleAutoBoxData_setDownRatios_mut(self_: *mut PxVehicleAutoBoxData, a: PxVehicleGearsDataEnum::Enum, ratio: f32, ) -> ();
pub fn PxVehicleDifferential4WData_new() -> PxVehicleDifferential4WData;
pub fn PxVehicleDifferential4WData_new_1(anonymous_arg0: PxEMPTY, ) -> PxVehicleDifferential4WData;
pub fn PxVehicleDifferentialNWData_new() -> PxVehicleDifferentialNWData;
pub fn PxVehicleDifferentialNWData_setDrivenWheel_mut(self_: *mut PxVehicleDifferentialNWData, wheelId: u32, drivenState: bool, ) -> ();
pub fn PxVehicleDifferentialNWData_getIsDrivenWheel(self_: *const PxVehicleDifferentialNWData, wheelId: u32, ) -> bool;
pub fn PxVehicleDifferentialNWData_new_1(anonymous_arg0: PxEMPTY, ) -> PxVehicleDifferentialNWData;
pub fn PxVehicleDifferentialNWData_getDrivenWheelStatus(self_: *const PxVehicleDifferentialNWData, ) -> u32;
pub fn PxVehicleDifferentialNWData_setDrivenWheelStatus_mut(self_: *mut PxVehicleDifferentialNWData, status: u32, ) -> ();
pub fn PxVehicleAckermannGeometryData_new() -> PxVehicleAckermannGeometryData;
pub fn PxVehicleAckermannGeometryData_new_1(anonymous_arg0: PxEMPTY, ) -> PxVehicleAckermannGeometryData;
pub fn PxVehicleClutchData_new() -> PxVehicleClutchData;
pub fn PxVehicleClutchData_new_1(anonymous_arg0: PxEMPTY, ) -> PxVehicleClutchData;
pub fn PxVehicleTireLoadFilterData_new() -> PxVehicleTireLoadFilterData;
pub fn PxVehicleTireLoadFilterData_getDenominator(self_: *const PxVehicleTireLoadFilterData, ) -> f32;
pub fn PxVehicleTireLoadFilterData_new_1(anonymous_arg0: PxEMPTY, ) -> PxVehicleTireLoadFilterData;
pub fn PxVehicleWheelData_new() -> PxVehicleWheelData;
pub fn PxVehicleWheelData_getRecipRadius(self_: *const PxVehicleWheelData, ) -> f32;
pub fn PxVehicleWheelData_getRecipMOI(self_: *const PxVehicleWheelData, ) -> f32;
pub fn PxVehicleSuspensionData_new() -> PxVehicleSuspensionData;
pub fn PxVehicleSuspensionData_getRecipMaxCompression(self_: *const PxVehicleSuspensionData, ) -> f32;
pub fn PxVehicleSuspensionData_getRecipMaxDroop(self_: *const PxVehicleSuspensionData, ) -> f32;
pub fn PxVehicleSuspensionData_setMassAndPreserveNaturalFrequency_mut(self_: *mut PxVehicleSuspensionData, newSprungMass: f32, ) -> ();
pub fn PxVehicleAntiRollBarData_new() -> PxVehicleAntiRollBarData;
pub fn PxVehicleTireData_new() -> PxVehicleTireData;
pub fn PxVehicleTireData_getRecipLongitudinalStiffnessPerUnitGravity(self_: *const PxVehicleTireData, ) -> f32;
pub fn PxVehicleTireData_getFrictionVsSlipGraphRecipx1Minusx0(self_: *const PxVehicleTireData, ) -> f32;
pub fn PxVehicleTireData_getFrictionVsSlipGraphRecipx2Minusx1(self_: *const PxVehicleTireData, ) -> f32;
pub fn PxVehicleWheelsSimData_allocate_mut(nbWheels: u32, ) -> *mut PxVehicleWheelsSimData;
pub fn PxVehicleWheelsSimData_setChassisMass_mut(self_: *mut PxVehicleWheelsSimData, chassisMass: f32, ) -> ();
pub fn PxVehicleWheelsSimData_free_mut(self_: *mut PxVehicleWheelsSimData, ) -> ();
pub fn PxVehicleWheelsSimData_copy_mut(self_: *mut PxVehicleWheelsSimData, src: *const PxVehicleWheelsSimData, srcWheel: u32, trgWheel: u32, ) -> ();
pub fn PxVehicleWheelsSimData_getNbWheels(self_: *const PxVehicleWheelsSimData, ) -> u32;
pub fn PxVehicleWheelsSimData_getSuspensionData(self_: *const PxVehicleWheelsSimData, id: u32, ) -> *const PxVehicleSuspensionData;
pub fn PxVehicleWheelsSimData_getWheelData(self_: *const PxVehicleWheelsSimData, id: u32, ) -> *const PxVehicleWheelData;
pub fn PxVehicleWheelsSimData_getTireData(self_: *const PxVehicleWheelsSimData, id: u32, ) -> *const PxVehicleTireData;
pub fn PxVehicleWheelsSimData_getSuspTravelDirection(self_: *const PxVehicleWheelsSimData, id: u32, ) -> *const PxVec3;
pub fn PxVehicleWheelsSimData_getSuspForceAppPointOffset(self_: *const PxVehicleWheelsSimData, id: u32, ) -> *const PxVec3;
pub fn PxVehicleWheelsSimData_getTireForceAppPointOffset(self_: *const PxVehicleWheelsSimData, id: u32, ) -> *const PxVec3;
pub fn PxVehicleWheelsSimData_getWheelCentreOffset(self_: *const PxVehicleWheelsSimData, id: u32, ) -> *const PxVec3;
pub fn PxVehicleWheelsSimData_getWheelShapeMapping(self_: *const PxVehicleWheelsSimData, wheelId: u32, ) -> i32;
pub fn PxVehicleWheelsSimData_getSceneQueryFilterData(self_: *const PxVehicleWheelsSimData, suspId: u32, ) -> *const PxFilterData;
pub fn PxVehicleWheelsSimData_getNbAntiRollBars(self_: *const PxVehicleWheelsSimData, ) -> u32;
pub fn PxVehicleWheelsSimData_getAntiRollBarData(self_: *const PxVehicleWheelsSimData, antiRollId: u32, ) -> *const PxVehicleAntiRollBarData;
pub fn PxVehicleWheelsSimData_getTireLoadFilterData(self_: *const PxVehicleWheelsSimData, ) -> *const PxVehicleTireLoadFilterData;
pub fn PxVehicleWheelsSimData_setSuspensionData_mut(self_: *mut PxVehicleWheelsSimData, id: u32, susp: *const PxVehicleSuspensionData, ) -> ();
pub fn PxVehicleWheelsSimData_setWheelData_mut(self_: *mut PxVehicleWheelsSimData, id: u32, wheel: *const PxVehicleWheelData, ) -> ();
pub fn PxVehicleWheelsSimData_setTireData_mut(self_: *mut PxVehicleWheelsSimData, id: u32, tire: *const PxVehicleTireData, ) -> ();
pub fn PxVehicleWheelsSimData_setSuspTravelDirection_mut(self_: *mut PxVehicleWheelsSimData, id: u32, dir: *const PxVec3, ) -> ();
pub fn PxVehicleWheelsSimData_setSuspForceAppPointOffset_mut(self_: *mut PxVehicleWheelsSimData, id: u32, offset: *const PxVec3, ) -> ();
pub fn PxVehicleWheelsSimData_setTireForceAppPointOffset_mut(self_: *mut PxVehicleWheelsSimData, id: u32, offset: *const PxVec3, ) -> ();
pub fn PxVehicleWheelsSimData_setWheelCentreOffset_mut(self_: *mut PxVehicleWheelsSimData, id: u32, offset: *const PxVec3, ) -> ();
pub fn PxVehicleWheelsSimData_setWheelShapeMapping_mut(self_: *mut PxVehicleWheelsSimData, wheelId: u32, shapeId: i32, ) -> ();
pub fn PxVehicleWheelsSimData_setSceneQueryFilterData_mut(self_: *mut PxVehicleWheelsSimData, suspId: u32, sqFilterData: *const PxFilterData, ) -> ();
pub fn PxVehicleWheelsSimData_setTireLoadFilterData_mut(self_: *mut PxVehicleWheelsSimData, tireLoadFilter: *const PxVehicleTireLoadFilterData, ) -> ();
pub fn PxVehicleWheelsSimData_addAntiRollBarData_mut(self_: *mut PxVehicleWheelsSimData, antiRoll: *const PxVehicleAntiRollBarData, ) -> u32;
pub fn PxVehicleWheelsSimData_disableWheel_mut(self_: *mut PxVehicleWheelsSimData, wheel: u32, ) -> ();
pub fn PxVehicleWheelsSimData_enableWheel_mut(self_: *mut PxVehicleWheelsSimData, wheel: u32, ) -> ();
pub fn PxVehicleWheelsSimData_getIsWheelDisabled(self_: *const PxVehicleWheelsSimData, wheel: u32, ) -> bool;
pub fn PxVehicleWheelsSimData_setSubStepCount_mut(self_: *mut PxVehicleWheelsSimData, thresholdLongitudinalSpeed: f32, lowForwardSpeedSubStepCount: u32, highForwardSpeedSubStepCount: u32, ) -> ();
pub fn PxVehicleWheelsSimData_setMinLongSlipDenominator_mut(self_: *mut PxVehicleWheelsSimData, minLongSlipDenominator: f32, ) -> ();
pub fn PxVehicleWheelsSimData_setFlags_mut(self_: *mut PxVehicleWheelsSimData, flags: PxVehicleWheelsSimFlags, ) -> ();
pub fn PxVehicleWheelsSimData_getFlags(self_: *const PxVehicleWheelsSimData, ) -> PxVehicleWheelsSimFlags;
pub fn PxVehicleWheelsSimData_new_alloc(anonymous_arg0: PxEMPTY, ) -> *mut PxVehicleWheelsSimData;
pub fn PxVehicleWheelsSimData_getBinaryMetaData_mut(stream: *mut PxOutputStream, ) -> ();
pub fn PxVehicleWheelsSimData_getNbWheels4(self_: *const PxVehicleWheelsSimData, ) -> u32;
pub fn PxVehicleWheelsSimData_getNbSuspensionData(self_: *const PxVehicleWheelsSimData, ) -> u32;
pub fn PxVehicleWheelsSimData_getNbWheelData(self_: *const PxVehicleWheelsSimData, ) -> u32;
pub fn PxVehicleWheelsSimData_getNbSuspTravelDirection(self_: *const PxVehicleWheelsSimData, ) -> u32;
pub fn PxVehicleWheelsSimData_getNbTireData(self_: *const PxVehicleWheelsSimData, ) -> u32;
pub fn PxVehicleWheelsSimData_getNbSuspForceAppPointOffset(self_: *const PxVehicleWheelsSimData, ) -> u32;
pub fn PxVehicleWheelsSimData_getNbTireForceAppPointOffset(self_: *const PxVehicleWheelsSimData, ) -> u32;
pub fn PxVehicleWheelsSimData_getNbWheelCentreOffset(self_: *const PxVehicleWheelsSimData, ) -> u32;
pub fn PxVehicleWheelsSimData_getNbWheelShapeMapping(self_: *const PxVehicleWheelsSimData, ) -> u32;
pub fn PxVehicleWheelsSimData_getNbSceneQueryFilterData(self_: *const PxVehicleWheelsSimData, ) -> u32;
pub fn PxVehicleWheelsSimData_getMinLongSlipDenominator(self_: *const PxVehicleWheelsSimData, ) -> f32;
pub fn PxVehicleWheelsSimData_setThresholdLongSpeed_mut(self_: *mut PxVehicleWheelsSimData, f: f32, ) -> ();
pub fn PxVehicleWheelsSimData_getThresholdLongSpeed(self_: *const PxVehicleWheelsSimData, ) -> f32;
pub fn PxVehicleWheelsSimData_setLowForwardSpeedSubStepCount_mut(self_: *mut PxVehicleWheelsSimData, f: u32, ) -> ();
pub fn PxVehicleWheelsSimData_getLowForwardSpeedSubStepCount(self_: *const PxVehicleWheelsSimData, ) -> u32;
pub fn PxVehicleWheelsSimData_setHighForwardSpeedSubStepCount_mut(self_: *mut PxVehicleWheelsSimData, f: u32, ) -> ();
pub fn PxVehicleWheelsSimData_getHighForwardSpeedSubStepCount(self_: *const PxVehicleWheelsSimData, ) -> u32;
pub fn PxVehicleWheelsSimData_setWheelEnabledState_mut(self_: *mut PxVehicleWheelsSimData, wheel: u32, state: bool, ) -> ();
pub fn PxVehicleWheelsSimData_getWheelEnabledState(self_: *const PxVehicleWheelsSimData, wheel: u32, ) -> bool;
pub fn PxVehicleWheelsSimData_getNbWheelEnabledState(self_: *const PxVehicleWheelsSimData, ) -> u32;
pub fn PxVehicleWheelsSimData_getNbAntiRollBars4(self_: *const PxVehicleWheelsSimData, ) -> u32;
pub fn PxVehicleWheelsSimData_getNbAntiRollBarData(self_: *const PxVehicleWheelsSimData, ) -> u32;
pub fn PxVehicleWheelsSimData_setAntiRollBarData_mut(self_: *mut PxVehicleWheelsSimData, id: u32, antiRoll: *const PxVehicleAntiRollBarData, ) -> ();
pub fn PxVehicleWheelsSimData_new_alloc_1() -> *mut PxVehicleWheelsSimData;
pub fn PxVehicleWheelsSimData_delete(self_: *mut PxVehicleWheelsSimData, ) -> ();
pub fn PxVehicleWheelsDynData_new_alloc() -> *mut PxVehicleWheelsDynData;
pub fn PxVehicleWheelsDynData_delete(self_: *mut PxVehicleWheelsDynData, ) -> ();
pub fn PxVehicleWheelsDynData_setToRestState_mut(self_: *mut PxVehicleWheelsDynData, ) -> ();
pub fn PxVehicleWheelsDynData_setTireForceShaderFunction_mut(self_: *mut PxVehicleWheelsDynData, tireForceShaderFn: *mut std::ffi::c_void, ) -> ();
pub fn PxVehicleWheelsDynData_setTireForceShaderData_mut(self_: *mut PxVehicleWheelsDynData, tireId: u32, tireForceShaderData: *const std::ffi::c_void, ) -> ();
pub fn PxVehicleWheelsDynData_getTireForceShaderData(self_: *const PxVehicleWheelsDynData, tireId: u32, ) -> *const std::ffi::c_void;
pub fn PxVehicleWheelsDynData_setWheelRotationSpeed_mut(self_: *mut PxVehicleWheelsDynData, wheelIdx: u32, speed: f32, ) -> ();
pub fn PxVehicleWheelsDynData_getWheelRotationSpeed(self_: *const PxVehicleWheelsDynData, wheelIdx: u32, ) -> f32;
pub fn PxVehicleWheelsDynData_setWheelRotationAngle_mut(self_: *mut PxVehicleWheelsDynData, wheelIdx: u32, angle: f32, ) -> ();
pub fn PxVehicleWheelsDynData_getWheelRotationAngle(self_: *const PxVehicleWheelsDynData, wheelIdx: u32, ) -> f32;
pub fn PxVehicleWheelsDynData_setUserData_mut(self_: *mut PxVehicleWheelsDynData, tireIdx: u32, userData: *mut std::ffi::c_void, ) -> ();
pub fn PxVehicleWheelsDynData_getUserData(self_: *const PxVehicleWheelsDynData, tireIdx: u32, ) -> *mut std::ffi::c_void;
pub fn PxVehicleWheelsDynData_copy_mut(self_: *mut PxVehicleWheelsDynData, src: *const PxVehicleWheelsDynData, srcWheel: u32, trgWheel: u32, ) -> ();
pub fn PxVehicleWheelsDynData_getBinaryMetaData_mut(stream: *mut PxOutputStream, ) -> ();
pub fn PxVehicleWheelsDynData_getNbWheelRotationSpeed(self_: *const PxVehicleWheelsDynData, ) -> u32;
pub fn PxVehicleWheelsDynData_getNbWheelRotationAngle(self_: *const PxVehicleWheelsDynData, ) -> u32;
pub fn PxVehicleWheelsDynData_getWheel4DynData(self_: *const PxVehicleWheelsDynData, ) -> *mut PxVehicleWheels4DynData;
pub fn PxVehicleWheels_getVehicleType(self_: *const PxVehicleWheels, ) -> u32;
pub fn PxVehicleWheels_getRigidDynamicActor_mut(self_: *mut PxVehicleWheels, ) -> *mut PxRigidDynamic;
pub fn PxVehicleWheels_getRigidDynamicActor(self_: *const PxVehicleWheels, ) -> *const PxRigidDynamic;
pub fn PxVehicleWheels_computeForwardSpeed(self_: *const PxVehicleWheels, ) -> f32;
pub fn PxVehicleWheels_computeSidewaysSpeed(self_: *const PxVehicleWheels, ) -> f32;
pub fn PxVehicleWheels_requiresObjects_mut(self_: *mut PxVehicleWheels, c: *mut PxProcessPxBaseCallback, ) -> ();
pub fn PxVehicleWheels_getConcreteTypeName(self_: *const PxVehicleWheels, ) -> *const i8;
pub fn PxVehicleWheels_isKindOf(self_: *const PxVehicleWheels, name: *const i8, ) -> bool;
pub fn PxVehicleWheels_preExportDataReset_mut(self_: *mut PxVehicleWheels, ) -> ();
pub fn PxVehicleWheels_exportExtraData_mut(self_: *mut PxVehicleWheels, anonymous_arg0: *mut PxSerializationContext, ) -> ();
pub fn PxVehicleWheels_importExtraData_mut(self_: *mut PxVehicleWheels, anonymous_arg0: *mut PxDeserializationContext, ) -> ();
pub fn PxVehicleWheels_resolveReferences_mut(self_: *mut PxVehicleWheels, anonymous_arg0: *mut PxDeserializationContext, ) -> ();
pub fn PxVehicleWheels_getBinaryMetaData_mut(stream: *mut PxOutputStream, ) -> ();
pub fn PxVehicleWheels_getNbNonDrivenWheels(self_: *const PxVehicleWheels, ) -> u32;
pub fn PxVehicleWheels_new_alloc(concreteType: u16, baseFlags: PxBaseFlags, ) -> *mut PxVehicleWheels;
pub fn PxVehicleWheels_new_alloc_1(baseFlags: PxBaseFlags, ) -> *mut PxVehicleWheels;
pub fn PxVehicleWheels_release_mut(self_: *mut PxVehicleWheels, ) -> ();
pub fn PxVehicleDriveSimData_getEngineData(self_: *const PxVehicleDriveSimData, ) -> *const PxVehicleEngineData;
pub fn PxVehicleDriveSimData_setEngineData_mut(self_: *mut PxVehicleDriveSimData, engine: *const PxVehicleEngineData, ) -> ();
pub fn PxVehicleDriveSimData_getGearsData(self_: *const PxVehicleDriveSimData, ) -> *const PxVehicleGearsData;
pub fn PxVehicleDriveSimData_setGearsData_mut(self_: *mut PxVehicleDriveSimData, gears: *const PxVehicleGearsData, ) -> ();
pub fn PxVehicleDriveSimData_getClutchData(self_: *const PxVehicleDriveSimData, ) -> *const PxVehicleClutchData;
pub fn PxVehicleDriveSimData_setClutchData_mut(self_: *mut PxVehicleDriveSimData, clutch: *const PxVehicleClutchData, ) -> ();
pub fn PxVehicleDriveSimData_getAutoBoxData(self_: *const PxVehicleDriveSimData, ) -> *const PxVehicleAutoBoxData;
pub fn PxVehicleDriveSimData_setAutoBoxData_mut(self_: *mut PxVehicleDriveSimData, autobox: *const PxVehicleAutoBoxData, ) -> ();
pub fn PxVehicleDriveSimData_new() -> PxVehicleDriveSimData;
pub fn PxVehicleDriveSimData_new_1(anonymous_arg0: PxEMPTY, ) -> PxVehicleDriveSimData;
pub fn PxVehicleDriveSimData_getBinaryMetaData_mut(stream: *mut PxOutputStream, ) -> ();
pub fn PxVehicleDriveSimData_delete(self_: *mut PxVehicleDriveSimData, ) -> ();
pub fn PxVehicleDriveDynData_setToRestState_mut(self_: *mut PxVehicleDriveDynData, ) -> ();
pub fn PxVehicleDriveDynData_setAnalogInput_mut(self_: *mut PxVehicleDriveDynData, _type: u32, analogVal: f32, ) -> ();
pub fn PxVehicleDriveDynData_getAnalogInput(self_: *const PxVehicleDriveDynData, _type: u32, ) -> f32;
pub fn PxVehicleDriveDynData_setGearUp_mut(self_: *mut PxVehicleDriveDynData, digitalVal: bool, ) -> ();
pub fn PxVehicleDriveDynData_setGearDown_mut(self_: *mut PxVehicleDriveDynData, digitalVal: bool, ) -> ();
pub fn PxVehicleDriveDynData_getGearUp(self_: *const PxVehicleDriveDynData, ) -> bool;
pub fn PxVehicleDriveDynData_getGearDown(self_: *const PxVehicleDriveDynData, ) -> bool;
pub fn PxVehicleDriveDynData_setUseAutoGears_mut(self_: *mut PxVehicleDriveDynData, useAutoGears: bool, ) -> ();
pub fn PxVehicleDriveDynData_getUseAutoGears(self_: *const PxVehicleDriveDynData, ) -> bool;
pub fn PxVehicleDriveDynData_toggleAutoGears_mut(self_: *mut PxVehicleDriveDynData, ) -> ();
pub fn PxVehicleDriveDynData_setCurrentGear_mut(self_: *mut PxVehicleDriveDynData, currentGear: u32, ) -> ();
pub fn PxVehicleDriveDynData_getCurrentGear(self_: *const PxVehicleDriveDynData, ) -> u32;
pub fn PxVehicleDriveDynData_setTargetGear_mut(self_: *mut PxVehicleDriveDynData, targetGear: u32, ) -> ();
pub fn PxVehicleDriveDynData_getTargetGear(self_: *const PxVehicleDriveDynData, ) -> u32;
pub fn PxVehicleDriveDynData_startGearChange_mut(self_: *mut PxVehicleDriveDynData, targetGear: u32, ) -> ();
pub fn PxVehicleDriveDynData_forceGearChange_mut(self_: *mut PxVehicleDriveDynData, targetGear: u32, ) -> ();
pub fn PxVehicleDriveDynData_setEngineRotationSpeed_mut(self_: *mut PxVehicleDriveDynData, speed: f32, ) -> ();
pub fn PxVehicleDriveDynData_getEngineRotationSpeed(self_: *const PxVehicleDriveDynData, ) -> f32;
pub fn PxVehicleDriveDynData_getGearSwitchTime(self_: *const PxVehicleDriveDynData, ) -> f32;
pub fn PxVehicleDriveDynData_getAutoBoxSwitchTime(self_: *const PxVehicleDriveDynData, ) -> f32;
pub fn PxVehicleDriveDynData_new() -> PxVehicleDriveDynData;
pub fn PxVehicleDriveDynData_new_1(anonymous_arg0: PxEMPTY, ) -> PxVehicleDriveDynData;
pub fn PxVehicleDriveDynData_getNbAnalogInput(self_: *const PxVehicleDriveDynData, ) -> u32;
pub fn PxVehicleDriveDynData_setGearChange_mut(self_: *mut PxVehicleDriveDynData, gearChange: u32, ) -> ();
pub fn PxVehicleDriveDynData_getGearChange(self_: *const PxVehicleDriveDynData, ) -> u32;
pub fn PxVehicleDriveDynData_setGearSwitchTime_mut(self_: *mut PxVehicleDriveDynData, switchTime: f32, ) -> ();
pub fn PxVehicleDriveDynData_setAutoBoxSwitchTime_mut(self_: *mut PxVehicleDriveDynData, autoBoxSwitchTime: f32, ) -> ();
pub fn PxVehicleDrive_getBinaryMetaData_mut(stream: *mut PxOutputStream, ) -> ();
pub fn PxVehicleDrive_new_alloc(baseFlags: PxBaseFlags, ) -> *mut PxVehicleDrive;
pub fn PxVehicleDrive_getConcreteTypeName(self_: *const PxVehicleDrive, ) -> *const i8;
pub fn PxVehicleDriveSimData4W_new() -> PxVehicleDriveSimData4W;
pub fn PxVehicleDriveSimData4W_getDiffData(self_: *const PxVehicleDriveSimData4W, ) -> *const PxVehicleDifferential4WData;
pub fn PxVehicleDriveSimData4W_getAckermannGeometryData(self_: *const PxVehicleDriveSimData4W, ) -> *const PxVehicleAckermannGeometryData;
pub fn PxVehicleDriveSimData4W_setDiffData_mut(self_: *mut PxVehicleDriveSimData4W, diff: *const PxVehicleDifferential4WData, ) -> ();
pub fn PxVehicleDriveSimData4W_setAckermannGeometryData_mut(self_: *mut PxVehicleDriveSimData4W, ackermannData: *const PxVehicleAckermannGeometryData, ) -> ();
pub fn PxVehicleDriveSimData4W_new_1(anonymous_arg0: PxEMPTY, ) -> PxVehicleDriveSimData4W;
pub fn PxVehicleDriveSimData4W_getBinaryMetaData_mut(stream: *mut PxOutputStream, ) -> ();
pub fn PxVehicleDriveSimData4W_delete(self_: *mut PxVehicleDriveSimData4W, ) -> ();
pub fn PxVehicleDrive4W_allocate_mut(nbWheels: u32, ) -> *mut PxVehicleDrive4W;
pub fn PxVehicleDrive4W_free_mut(self_: *mut PxVehicleDrive4W, ) -> ();
pub fn PxVehicleDrive4W_setup_mut(self_: *mut PxVehicleDrive4W, physics: *mut PxPhysics, vehActor: *mut PxRigidDynamic, wheelsData: *const PxVehicleWheelsSimData, driveData: *const PxVehicleDriveSimData4W, nbNonDrivenWheels: u32, ) -> ();
pub fn PxVehicleDrive4W_create_mut(physics: *mut PxPhysics, vehActor: *mut PxRigidDynamic, wheelsData: *const PxVehicleWheelsSimData, driveData: *const PxVehicleDriveSimData4W, nbNonDrivenWheels: u32, ) -> *mut PxVehicleDrive4W;
pub fn PxVehicleDrive4W_setToRestState_mut(self_: *mut PxVehicleDrive4W, ) -> ();
pub fn PxVehicleDrive4W_createObject_mut(address: *mut *mut u8, context: *mut PxDeserializationContext, ) -> *mut PxVehicleDrive4W;
pub fn PxVehicleDrive4W_getBinaryMetaData_mut(stream: *mut PxOutputStream, ) -> ();
pub fn PxVehicleDrive4W_new_alloc(baseFlags: PxBaseFlags, ) -> *mut PxVehicleDrive4W;
pub fn PxVehicleDrive4W_getConcreteTypeName(self_: *const PxVehicleDrive4W, ) -> *const i8;
pub fn PxVehicleDriveTank_allocate_mut(nbWheels: u32, ) -> *mut PxVehicleDriveTank;
pub fn PxVehicleDriveTank_free_mut(self_: *mut PxVehicleDriveTank, ) -> ();
pub fn PxVehicleDriveTank_setup_mut(self_: *mut PxVehicleDriveTank, physics: *mut PxPhysics, vehActor: *mut PxRigidDynamic, wheelsData: *const PxVehicleWheelsSimData, driveData: *const PxVehicleDriveSimData, nbDrivenWheels: u32, ) -> ();
pub fn PxVehicleDriveTank_create_mut(physics: *mut PxPhysics, vehActor: *mut PxRigidDynamic, wheelsData: *const PxVehicleWheelsSimData, driveData: *const PxVehicleDriveSimData, nbDrivenWheels: u32, ) -> *mut PxVehicleDriveTank;
pub fn PxVehicleDriveTank_setDriveModel_mut(self_: *mut PxVehicleDriveTank, driveModel: PxVehicleDriveTankControlModel::Enum, ) -> ();
pub fn PxVehicleDriveTank_getDriveModel(self_: *const PxVehicleDriveTank, ) -> PxVehicleDriveTankControlModel::Enum;
pub fn PxVehicleDriveTank_setToRestState_mut(self_: *mut PxVehicleDriveTank, ) -> ();
pub fn PxVehicleDriveTank_new_alloc(baseFlags: PxBaseFlags, ) -> *mut PxVehicleDriveTank;
pub fn PxVehicleDriveTank_createObject_mut(address: *mut *mut u8, context: *mut PxDeserializationContext, ) -> *mut PxVehicleDriveTank;
pub fn PxVehicleDriveTank_getBinaryMetaData_mut(stream: *mut PxOutputStream, ) -> ();
pub fn PxVehicleDriveTank_getConcreteTypeName(self_: *const PxVehicleDriveTank, ) -> *const i8;
pub fn PxVehicleDriveTank_isKindOf(self_: *const PxVehicleDriveTank, name: *const i8, ) -> bool;
pub fn PxVehicleDrivableSurfaceToTireFrictionPairs_allocate_mut(maxNbTireTypes: u32, maxNbSurfaceTypes: u32, ) -> *mut PxVehicleDrivableSurfaceToTireFrictionPairs;
pub fn PxVehicleDrivableSurfaceToTireFrictionPairs_setup_mut(self_: *mut PxVehicleDrivableSurfaceToTireFrictionPairs, nbTireTypes: u32, nbSurfaceTypes: u32, drivableSurfaceMaterials: *mut *const PxMaterial, drivableSurfaceTypes: *const PxVehicleDrivableSurfaceType, ) -> ();
pub fn PxVehicleDrivableSurfaceToTireFrictionPairs_release_mut(self_: *mut PxVehicleDrivableSurfaceToTireFrictionPairs, ) -> ();
pub fn PxVehicleDrivableSurfaceToTireFrictionPairs_setTypePairFriction_mut(self_: *mut PxVehicleDrivableSurfaceToTireFrictionPairs, surfaceType: u32, tireType: u32, value: f32, ) -> ();
pub fn PxVehicleDrivableSurfaceToTireFrictionPairs_getTypePairFriction(self_: *const PxVehicleDrivableSurfaceToTireFrictionPairs, surfaceType: u32, tireType: u32, ) -> f32;
pub fn PxVehicleDrivableSurfaceToTireFrictionPairs_getMaxNbSurfaceTypes(self_: *const PxVehicleDrivableSurfaceToTireFrictionPairs, ) -> u32;
pub fn PxVehicleDrivableSurfaceToTireFrictionPairs_getMaxNbTireTypes(self_: *const PxVehicleDrivableSurfaceToTireFrictionPairs, ) -> u32;
pub fn PxWheelQueryResult_new() -> PxWheelQueryResult;
pub fn PxVehicleWheelConcurrentUpdateData_new() -> PxVehicleWheelConcurrentUpdateData;
pub fn PxVehicleConcurrentUpdateData_new() -> PxVehicleConcurrentUpdateData;
pub fn phys_PxVehicleSuspensionRaycasts(batchQuery: *mut PxBatchQuery, nbVehicles: u32, vehicles: *mut *mut PxVehicleWheels, nbSceneQueryResults: u32, sceneQueryResults: *mut PxRaycastQueryResult, vehiclesToRaycast: *const bool, ) -> ();
pub fn phys_PxVehicleSuspensionSweeps(batchQuery: *mut PxBatchQuery, nbVehicles: u32, vehicles: *mut *mut PxVehicleWheels, nbSceneQueryResults: u32, sceneQueryResults: *mut PxSweepQueryResult, nbHitsPerQuery: u16, vehiclesToSweep: *const bool, sweepWidthScale: f32, sweepRadiusScale: f32, ) -> ();
pub fn phys_PxVehicleModifyWheelContacts(vehicle: *const PxVehicleWheels, wheelId: u32, wheelTangentVelocityMultiplier: f32, maxImpulse: f32, contactModifyPair: *mut PxContactModifyPair, ) -> u32;
pub fn phys_PxVehicleUpdates(timestep: f32, gravity: *const PxVec3, vehicleDrivableSurfaceToTireFrictionPairs: *const PxVehicleDrivableSurfaceToTireFrictionPairs, nbVehicles: u32, vehicles: *mut *mut PxVehicleWheels, vehicleWheelQueryResults: *mut PxVehicleWheelQueryResult, vehicleConcurrentUpdates: *mut PxVehicleConcurrentUpdateData, ) -> ();
pub fn phys_PxVehiclePostUpdates(vehicleConcurrentUpdates: *const PxVehicleConcurrentUpdateData, nbVehicles: u32, vehicles: *mut *mut PxVehicleWheels, ) -> ();
pub fn phys_PxVehicleShiftOrigin(shift: *const PxVec3, nbVehicles: u32, vehicles: *mut *mut PxVehicleWheels, ) -> ();
pub fn phys_PxVehicleUpdateSingleVehicleAndStoreTelemetryData(timestep: f32, gravity: *const PxVec3, vehicleDrivableSurfaceToTireFrictionPairs: *const PxVehicleDrivableSurfaceToTireFrictionPairs, focusVehicle: *mut PxVehicleWheels, vehicleWheelQueryResults: *mut PxVehicleWheelQueryResult, telemetryData: *mut PxVehicleTelemetryData, ) -> ();
pub fn PxVehicleDriveSimDataNW_new() -> PxVehicleDriveSimDataNW;
pub fn PxVehicleDriveSimDataNW_getDiffData(self_: *const PxVehicleDriveSimDataNW, ) -> *const PxVehicleDifferentialNWData;
pub fn PxVehicleDriveSimDataNW_setDiffData_mut(self_: *mut PxVehicleDriveSimDataNW, diff: *const PxVehicleDifferentialNWData, ) -> ();
pub fn PxVehicleDriveSimDataNW_new_1(anonymous_arg0: PxEMPTY, ) -> PxVehicleDriveSimDataNW;
pub fn PxVehicleDriveSimDataNW_getBinaryMetaData_mut(stream: *mut PxOutputStream, ) -> ();
pub fn PxVehicleDriveSimDataNW_delete(self_: *mut PxVehicleDriveSimDataNW, ) -> ();
pub fn PxVehicleDriveNW_allocate_mut(nbWheels: u32, ) -> *mut PxVehicleDriveNW;
pub fn PxVehicleDriveNW_free_mut(self_: *mut PxVehicleDriveNW, ) -> ();
pub fn PxVehicleDriveNW_setup_mut(self_: *mut PxVehicleDriveNW, physics: *mut PxPhysics, vehActor: *mut PxRigidDynamic, wheelsData: *const PxVehicleWheelsSimData, driveData: *const PxVehicleDriveSimDataNW, nbWheels: u32, ) -> ();
pub fn PxVehicleDriveNW_create_mut(physics: *mut PxPhysics, vehActor: *mut PxRigidDynamic, wheelsData: *const PxVehicleWheelsSimData, driveData: *const PxVehicleDriveSimDataNW, nbWheels: u32, ) -> *mut PxVehicleDriveNW;
pub fn PxVehicleDriveNW_setToRestState_mut(self_: *mut PxVehicleDriveNW, ) -> ();
pub fn PxVehicleDriveNW_new_alloc(baseFlags: PxBaseFlags, ) -> *mut PxVehicleDriveNW;
pub fn PxVehicleDriveNW_new_alloc_1() -> *mut PxVehicleDriveNW;
pub fn PxVehicleDriveNW_createObject_mut(address: *mut *mut u8, context: *mut PxDeserializationContext, ) -> *mut PxVehicleDriveNW;
pub fn PxVehicleDriveNW_getBinaryMetaData_mut(stream: *mut PxOutputStream, ) -> ();
pub fn PxVehicleDriveNW_getConcreteTypeName(self_: *const PxVehicleDriveNW, ) -> *const i8;
pub fn PxVehicleDriveNW_isKindOf(self_: *const PxVehicleDriveNW, name: *const i8, ) -> bool;
pub fn PxVehicleDrive4WRawInputData_new_alloc() -> *mut PxVehicleDrive4WRawInputData;
pub fn PxVehicleDrive4WRawInputData_delete(self_: *mut PxVehicleDrive4WRawInputData, ) -> ();
pub fn PxVehicleDrive4WRawInputData_setDigitalAccel_mut(self_: *mut PxVehicleDrive4WRawInputData, accelKeyPressed: bool, ) -> ();
pub fn PxVehicleDrive4WRawInputData_setDigitalBrake_mut(self_: *mut PxVehicleDrive4WRawInputData, brakeKeyPressed: bool, ) -> ();
pub fn PxVehicleDrive4WRawInputData_setDigitalHandbrake_mut(self_: *mut PxVehicleDrive4WRawInputData, handbrakeKeyPressed: bool, ) -> ();
pub fn PxVehicleDrive4WRawInputData_setDigitalSteerLeft_mut(self_: *mut PxVehicleDrive4WRawInputData, steerLeftKeyPressed: bool, ) -> ();
pub fn PxVehicleDrive4WRawInputData_setDigitalSteerRight_mut(self_: *mut PxVehicleDrive4WRawInputData, steerRightKeyPressed: bool, ) -> ();
pub fn PxVehicleDrive4WRawInputData_getDigitalAccel(self_: *const PxVehicleDrive4WRawInputData, ) -> bool;
pub fn PxVehicleDrive4WRawInputData_getDigitalBrake(self_: *const PxVehicleDrive4WRawInputData, ) -> bool;
pub fn PxVehicleDrive4WRawInputData_getDigitalHandbrake(self_: *const PxVehicleDrive4WRawInputData, ) -> bool;
pub fn PxVehicleDrive4WRawInputData_getDigitalSteerLeft(self_: *const PxVehicleDrive4WRawInputData, ) -> bool;
pub fn PxVehicleDrive4WRawInputData_getDigitalSteerRight(self_: *const PxVehicleDrive4WRawInputData, ) -> bool;
pub fn PxVehicleDrive4WRawInputData_setAnalogAccel_mut(self_: *mut PxVehicleDrive4WRawInputData, accel: f32, ) -> ();
pub fn PxVehicleDrive4WRawInputData_setAnalogBrake_mut(self_: *mut PxVehicleDrive4WRawInputData, brake: f32, ) -> ();
pub fn PxVehicleDrive4WRawInputData_setAnalogHandbrake_mut(self_: *mut PxVehicleDrive4WRawInputData, handbrake: f32, ) -> ();
pub fn PxVehicleDrive4WRawInputData_setAnalogSteer_mut(self_: *mut PxVehicleDrive4WRawInputData, steer: f32, ) -> ();
pub fn PxVehicleDrive4WRawInputData_getAnalogAccel(self_: *const PxVehicleDrive4WRawInputData, ) -> f32;
pub fn PxVehicleDrive4WRawInputData_getAnalogBrake(self_: *const PxVehicleDrive4WRawInputData, ) -> f32;
pub fn PxVehicleDrive4WRawInputData_getAnalogHandbrake(self_: *const PxVehicleDrive4WRawInputData, ) -> f32;
pub fn PxVehicleDrive4WRawInputData_getAnalogSteer(self_: *const PxVehicleDrive4WRawInputData, ) -> f32;
pub fn PxVehicleDrive4WRawInputData_setGearUp_mut(self_: *mut PxVehicleDrive4WRawInputData, gearUpKeyPressed: bool, ) -> ();
pub fn PxVehicleDrive4WRawInputData_setGearDown_mut(self_: *mut PxVehicleDrive4WRawInputData, gearDownKeyPressed: bool, ) -> ();
pub fn PxVehicleDrive4WRawInputData_getGearUp(self_: *const PxVehicleDrive4WRawInputData, ) -> bool;
pub fn PxVehicleDrive4WRawInputData_getGearDown(self_: *const PxVehicleDrive4WRawInputData, ) -> bool;
pub fn phys_PxVehicleDrive4WSmoothDigitalRawInputsAndSetAnalogInputs(keySmoothing: *const PxVehicleKeySmoothingData, steerVsForwardSpeedTable: *const PxFixedSizeLookupTable_8_, rawInputData: *const PxVehicleDrive4WRawInputData, timestep: f32, isVehicleInAir: bool, focusVehicle: *mut PxVehicleDrive4W, ) -> ();
pub fn phys_PxVehicleDrive4WSmoothAnalogRawInputsAndSetAnalogInputs(padSmoothing: *const PxVehiclePadSmoothingData, steerVsForwardSpeedTable: *const PxFixedSizeLookupTable_8_, rawInputData: *const PxVehicleDrive4WRawInputData, timestep: f32, isVehicleInAir: bool, focusVehicle: *mut PxVehicleDrive4W, ) -> ();
pub fn PxVehicleDriveNWRawInputData_new_alloc() -> *mut PxVehicleDriveNWRawInputData;
pub fn PxVehicleDriveNWRawInputData_delete(self_: *mut PxVehicleDriveNWRawInputData, ) -> ();
pub fn phys_PxVehicleDriveNWSmoothDigitalRawInputsAndSetAnalogInputs(keySmoothing: *const PxVehicleKeySmoothingData, steerVsForwardSpeedTable: *const PxFixedSizeLookupTable_8_, rawInputData: *const PxVehicleDriveNWRawInputData, timestep: f32, isVehicleInAir: bool, focusVehicle: *mut PxVehicleDriveNW, ) -> ();
pub fn phys_PxVehicleDriveNWSmoothAnalogRawInputsAndSetAnalogInputs(padSmoothing: *const PxVehiclePadSmoothingData, steerVsForwardSpeedTable: *const PxFixedSizeLookupTable_8_, rawInputData: *const PxVehicleDriveNWRawInputData, timestep: f32, isVehicleInAir: bool, focusVehicle: *mut PxVehicleDriveNW, ) -> ();
pub fn PxVehicleDriveTankRawInputData_new_alloc(mode: PxVehicleDriveTankControlModel::Enum, ) -> *mut PxVehicleDriveTankRawInputData;
pub fn PxVehicleDriveTankRawInputData_delete(self_: *mut PxVehicleDriveTankRawInputData, ) -> ();
pub fn PxVehicleDriveTankRawInputData_getDriveModel(self_: *const PxVehicleDriveTankRawInputData, ) -> PxVehicleDriveTankControlModel::Enum;
pub fn PxVehicleDriveTankRawInputData_setDigitalAccel_mut(self_: *mut PxVehicleDriveTankRawInputData, b: bool, ) -> ();
pub fn PxVehicleDriveTankRawInputData_setDigitalLeftThrust_mut(self_: *mut PxVehicleDriveTankRawInputData, b: bool, ) -> ();
pub fn PxVehicleDriveTankRawInputData_setDigitalRightThrust_mut(self_: *mut PxVehicleDriveTankRawInputData, b: bool, ) -> ();
pub fn PxVehicleDriveTankRawInputData_setDigitalLeftBrake_mut(self_: *mut PxVehicleDriveTankRawInputData, b: bool, ) -> ();
pub fn PxVehicleDriveTankRawInputData_setDigitalRightBrake_mut(self_: *mut PxVehicleDriveTankRawInputData, b: bool, ) -> ();
pub fn PxVehicleDriveTankRawInputData_getDigitalAccel(self_: *const PxVehicleDriveTankRawInputData, ) -> bool;
pub fn PxVehicleDriveTankRawInputData_getDigitalLeftThrust(self_: *const PxVehicleDriveTankRawInputData, ) -> bool;
pub fn PxVehicleDriveTankRawInputData_getDigitalRightThrust(self_: *const PxVehicleDriveTankRawInputData, ) -> bool;
pub fn PxVehicleDriveTankRawInputData_getDigitalLeftBrake(self_: *const PxVehicleDriveTankRawInputData, ) -> bool;
pub fn PxVehicleDriveTankRawInputData_getDigitalRightBrake(self_: *const PxVehicleDriveTankRawInputData, ) -> bool;
pub fn PxVehicleDriveTankRawInputData_setAnalogAccel_mut(self_: *mut PxVehicleDriveTankRawInputData, accel: f32, ) -> ();
pub fn PxVehicleDriveTankRawInputData_setAnalogLeftThrust_mut(self_: *mut PxVehicleDriveTankRawInputData, leftThrust: f32, ) -> ();
pub fn PxVehicleDriveTankRawInputData_setAnalogRightThrust_mut(self_: *mut PxVehicleDriveTankRawInputData, rightThrust: f32, ) -> ();
pub fn PxVehicleDriveTankRawInputData_setAnalogLeftBrake_mut(self_: *mut PxVehicleDriveTankRawInputData, leftBrake: f32, ) -> ();
pub fn PxVehicleDriveTankRawInputData_setAnalogRightBrake_mut(self_: *mut PxVehicleDriveTankRawInputData, rightBrake: f32, ) -> ();
pub fn PxVehicleDriveTankRawInputData_getAnalogAccel(self_: *const PxVehicleDriveTankRawInputData, ) -> f32;
pub fn PxVehicleDriveTankRawInputData_getAnalogLeftThrust(self_: *const PxVehicleDriveTankRawInputData, ) -> f32;
pub fn PxVehicleDriveTankRawInputData_getAnalogRightThrust(self_: *const PxVehicleDriveTankRawInputData, ) -> f32;
pub fn PxVehicleDriveTankRawInputData_getAnalogLeftBrake(self_: *const PxVehicleDriveTankRawInputData, ) -> f32;
pub fn PxVehicleDriveTankRawInputData_getAnalogRightBrake(self_: *const PxVehicleDriveTankRawInputData, ) -> f32;
pub fn PxVehicleDriveTankRawInputData_setGearUp_mut(self_: *mut PxVehicleDriveTankRawInputData, gearUp: bool, ) -> ();
pub fn PxVehicleDriveTankRawInputData_setGearDown_mut(self_: *mut PxVehicleDriveTankRawInputData, gearDown: bool, ) -> ();
pub fn PxVehicleDriveTankRawInputData_getGearUp(self_: *const PxVehicleDriveTankRawInputData, ) -> bool;
pub fn PxVehicleDriveTankRawInputData_getGearDown(self_: *const PxVehicleDriveTankRawInputData, ) -> bool;
pub fn phys_PxVehicleDriveTankSmoothDigitalRawInputsAndSetAnalogInputs(keySmoothing: *const PxVehicleKeySmoothingData, rawInputData: *const PxVehicleDriveTankRawInputData, timestep: f32, focusVehicle: *mut PxVehicleDriveTank, ) -> ();
pub fn phys_PxVehicleDriveTankSmoothAnalogRawInputsAndSetAnalogInputs(padSmoothing: *const PxVehiclePadSmoothingData, rawInputData: *const PxVehicleDriveTankRawInputData, timestep: f32, focusVehicle: *mut PxVehicleDriveTank, ) -> ();
pub fn phys_PxVehicle4WEnable3WTadpoleMode(wheelsSimData: *mut PxVehicleWheelsSimData, wheelsDynData: *mut PxVehicleWheelsDynData, driveSimData: *mut PxVehicleDriveSimData4W, ) -> ();
pub fn phys_PxVehicle4WEnable3WDeltaMode(wheelsSimData: *mut PxVehicleWheelsSimData, wheelsDynData: *mut PxVehicleWheelsDynData, driveSimData: *mut PxVehicleDriveSimData4W, ) -> ();
pub fn phys_PxVehicleComputeSprungMasses(nbSprungMasses: u32, sprungMassCoordinates: *const PxVec3, centreOfMass: *const PxVec3, totalMass: f32, gravityDirection: u32, sprungMasses: *mut f32, ) -> ();
pub fn phys_PxVehicleUpdateCMassLocalPose(oldCMassLocalPose: *const PxTransform, newCMassLocalPose: *const PxTransform, gravityDirection: u32, vehicle: *mut PxVehicleWheels, ) -> ();
pub fn PxVehicleCopyDynamicsMap_new() -> PxVehicleCopyDynamicsMap;
pub fn phys_PxVehicleCopyDynamicsData(wheelMap: *const PxVehicleCopyDynamicsMap, src: *const PxVehicleWheels, trg: *mut PxVehicleWheels, ) -> ();
pub fn PxVehicleGraphChannelDesc_new() -> PxVehicleGraphChannelDesc;
pub fn PxVehicleGraph_setup_mut(self_: *mut PxVehicleGraph, desc: *const PxVehicleGraphDesc, graphType: PxVehicleGraphType::Enum, ) -> ();
pub fn PxVehicleGraph_clearRecordedChannelData_mut(self_: *mut PxVehicleGraph, ) -> ();
pub fn PxVehicleGraph_getBackgroundColor(self_: *const PxVehicleGraph, ) -> *const PxVec3;
pub fn PxVehicleGraph_getBackgroundAlpha(self_: *const PxVehicleGraph, ) -> f32;
pub fn PxVehicleGraph_getBackgroundCoords(self_: *const PxVehicleGraph, xMin: *mut f32, yMin: *mut f32, xMax: *mut f32, yMax: *mut f32, ) -> ();
pub fn PxVehicleGraph_computeGraphChannel(self_: *const PxVehicleGraph, channel: u32, xy: *mut f32, colors: *mut PxVec3, title: *mut i8, ) -> ();
pub fn PxVehicleGraph_getLatestValue(self_: *const PxVehicleGraph, channel: u32, ) -> f32;
pub fn PxVehicleTelemetryData_allocate_mut(nbWheels: u32, ) -> *mut PxVehicleTelemetryData;
pub fn PxVehicleTelemetryData_free_mut(self_: *mut PxVehicleTelemetryData, ) -> ();
pub fn PxVehicleTelemetryData_setup_mut(self_: *mut PxVehicleTelemetryData, graphSizeX: f32, graphSizeY: f32, engineGraphPosX: f32, engineGraphPosY: f32, wheelGraphPosX: *const f32, wheelGraphPosY: *const f32, backGroundColor: *const PxVec3, lineColorHigh: *const PxVec3, lineColorLow: *const PxVec3, ) -> ();
pub fn PxVehicleTelemetryData_clear_mut(self_: *mut PxVehicleTelemetryData, ) -> ();
pub fn PxVehicleTelemetryData_getEngineGraph(self_: *const PxVehicleTelemetryData, ) -> *const PxVehicleGraph;
pub fn PxVehicleTelemetryData_getNbWheelGraphs(self_: *const PxVehicleTelemetryData, ) -> u32;
pub fn PxVehicleTelemetryData_getWheelGraph(self_: *const PxVehicleTelemetryData, k: u32, ) -> *const PxVehicleGraph;
pub fn PxVehicleTelemetryData_getTireforceAppPoints(self_: *const PxVehicleTelemetryData, ) -> *const PxVec3;
pub fn PxVehicleTelemetryData_getSuspforceAppPoints(self_: *const PxVehicleTelemetryData, ) -> *const PxVec3;
pub fn PxVehicleNoDrive_allocate_mut(nbWheels: u32, ) -> *mut PxVehicleNoDrive;
pub fn PxVehicleNoDrive_free_mut(self_: *mut PxVehicleNoDrive, ) -> ();
pub fn PxVehicleNoDrive_setup_mut(self_: *mut PxVehicleNoDrive, physics: *mut PxPhysics, vehActor: *mut PxRigidDynamic, wheelsData: *const PxVehicleWheelsSimData, ) -> ();
pub fn PxVehicleNoDrive_create_mut(physics: *mut PxPhysics, vehActor: *mut PxRigidDynamic, wheelsData: *const PxVehicleWheelsSimData, ) -> *mut PxVehicleNoDrive;
pub fn PxVehicleNoDrive_setToRestState_mut(self_: *mut PxVehicleNoDrive, ) -> ();
pub fn PxVehicleNoDrive_setBrakeTorque_mut(self_: *mut PxVehicleNoDrive, id: u32, brakeTorque: f32, ) -> ();
pub fn PxVehicleNoDrive_setDriveTorque_mut(self_: *mut PxVehicleNoDrive, id: u32, driveTorque: f32, ) -> ();
pub fn PxVehicleNoDrive_setSteerAngle_mut(self_: *mut PxVehicleNoDrive, id: u32, steerAngle: f32, ) -> ();
pub fn PxVehicleNoDrive_getBrakeTorque(self_: *const PxVehicleNoDrive, id: u32, ) -> f32;
pub fn PxVehicleNoDrive_getDriveTorque(self_: *const PxVehicleNoDrive, id: u32, ) -> f32;
pub fn PxVehicleNoDrive_getSteerAngle(self_: *const PxVehicleNoDrive, id: u32, ) -> f32;
pub fn PxVehicleNoDrive_new_alloc(baseFlags: PxBaseFlags, ) -> *mut PxVehicleNoDrive;
pub fn PxVehicleNoDrive_exportExtraData_mut(self_: *mut PxVehicleNoDrive, anonymous_arg0: *mut PxSerializationContext, ) -> ();
pub fn PxVehicleNoDrive_importExtraData_mut(self_: *mut PxVehicleNoDrive, anonymous_arg0: *mut PxDeserializationContext, ) -> ();
pub fn PxVehicleNoDrive_createObject_mut(address: *mut *mut u8, context: *mut PxDeserializationContext, ) -> *mut PxVehicleNoDrive;
pub fn PxVehicleNoDrive_getBinaryMetaData_mut(stream: *mut PxOutputStream, ) -> ();
pub fn PxVehicleNoDrive_getConcreteTypeName(self_: *const PxVehicleNoDrive, ) -> *const i8;
pub fn PxVehicleNoDrive_isKindOf(self_: *const PxVehicleNoDrive, name: *const i8, ) -> bool;
pub fn PxVehicleNoDrive_getNbSteerAngle(self_: *const PxVehicleNoDrive, ) -> u32;
pub fn PxVehicleNoDrive_getNbDriveTorque(self_: *const PxVehicleNoDrive, ) -> u32;
pub fn PxVehicleNoDrive_getNbBrakeTorque(self_: *const PxVehicleNoDrive, ) -> u32;
pub fn PxProfilerCallback_zoneStart_mut(self_: *mut PxProfilerCallback, eventName: *const i8, detached: bool, contextId: usize, ) -> *mut std::ffi::c_void;
pub fn PxProfilerCallback_zoneEnd_mut(self_: *mut PxProfilerCallback, profilerData: *mut std::ffi::c_void, eventName: *const i8, detached: bool, contextId: usize, ) -> ();
pub fn PxProfileScoped_new_alloc(callback: *mut PxProfilerCallback, eventName: *const i8, detached: bool, contextId: usize, ) -> *mut PxProfileScoped;
pub fn PxProfileScoped_delete(self_: *mut PxProfileScoped, ) -> ();
pub fn PxPvd_connect_mut(self_: *mut PxPvd, transport: *mut PxPvdTransport, flags: PxPvdInstrumentationFlags, ) -> bool;
pub fn PxPvd_disconnect_mut(self_: *mut PxPvd, ) -> ();
pub fn PxPvd_isConnected_mut(self_: *mut PxPvd, useCachedStatus: bool, ) -> bool;
pub fn PxPvd_getTransport_mut(self_: *mut PxPvd, ) -> *mut PxPvdTransport;
pub fn PxPvd_getInstrumentationFlags_mut(self_: *mut PxPvd, ) -> PxPvdInstrumentationFlags;
pub fn PxPvd_release_mut(self_: *mut PxPvd, ) -> ();
pub fn phys_PxCreatePvd(foundation: *mut PxFoundation, ) -> *mut PxPvd;
pub fn PxPvdTransport_connect_mut(self_: *mut PxPvdTransport, ) -> bool;
pub fn PxPvdTransport_disconnect_mut(self_: *mut PxPvdTransport, ) -> ();
pub fn PxPvdTransport_isConnected_mut(self_: *mut PxPvdTransport, ) -> bool;
pub fn PxPvdTransport_write_mut(self_: *mut PxPvdTransport, inBytes: *const u8, inLength: u32, ) -> bool;
pub fn PxPvdTransport_lock_mut(self_: *mut PxPvdTransport, ) -> *mut PxPvdTransport;
pub fn PxPvdTransport_unlock_mut(self_: *mut PxPvdTransport, ) -> ();
pub fn PxPvdTransport_flush_mut(self_: *mut PxPvdTransport, ) -> ();
pub fn PxPvdTransport_getWrittenDataSize_mut(self_: *mut PxPvdTransport, ) -> usize;
pub fn PxPvdTransport_release_mut(self_: *mut PxPvdTransport, ) -> ();
pub fn phys_PxDefaultPvdSocketTransportCreate(host: *const i8, port: i32, timeoutInMilliseconds: u32, ) -> *mut PxPvdTransport;
pub fn phys_PxDefaultPvdFileTransportCreate(name: *const i8, ) -> *mut PxPvdTransport;
}
