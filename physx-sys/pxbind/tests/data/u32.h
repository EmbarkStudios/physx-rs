namespace physx {

struct PxThreadPriority
{
	enum Enum
	{
		eHIGH         = 0,	//!< High priority
		eABOVE_NORMAL = 1,	//!< Above Normal priority
		eNORMAL       = 2,	//!< Normal/default priority
		eBELOW_NORMAL = 3,	//!< Below Normal priority
		eLOW          = 4,	//!< Low priority.
		eFORCE_DWORD  = 0xffFFffFF
	};
};

} // physx
