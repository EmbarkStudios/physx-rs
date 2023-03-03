namespace physx {

// From PxThread.h

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

// From PxShape.h

/**
\brief Flags which affect the behavior of PxShapes.

@see PxShape PxShape.setFlag()
*/
struct PxShapeFlag
{
	enum Enum
	{
		/**
		\brief The shape will partake in collision in the physical simulation.

		\note It is illegal to raise the eSIMULATION_SHAPE and eTRIGGER_SHAPE flags.
		In the event that one of these flags is already raised the sdk will reject any 
		attempt to raise the other.  To raise the eSIMULATION_SHAPE first ensure that 
		eTRIGGER_SHAPE is already lowered.

		\note This flag has no effect if simulation is disabled for the corresponding actor (see #PxActorFlag::eDISABLE_SIMULATION).

		@see PxSimulationEventCallback.onContact() PxScene.setSimulationEventCallback() PxShape.setFlag(), PxShape.setFlags()
		*/
		eSIMULATION_SHAPE				= (1<<0),

		/**
		\brief The shape will partake in scene queries (ray casts, overlap tests, sweeps, ...).
		*/
		eSCENE_QUERY_SHAPE				= (1<<1),

		/**
		\brief The shape is a trigger which can send reports whenever other shapes enter/leave its volume.

		\note Triangle meshes and heightfields can not be triggers. Shape creation will fail in these cases.

		\note Shapes marked as triggers do not collide with other objects. If an object should act both
		as a trigger shape and a collision shape then create a rigid body with two shapes, one being a 
		trigger shape and the other a collision shape. It is illegal to raise the eTRIGGER_SHAPE and 
		eSIMULATION_SHAPE flags on a single PxShape instance.  In the event that one of these flags is already 
		raised the sdk will reject any attempt to raise the other.  To raise the eTRIGGER_SHAPE flag first 
		ensure that eSIMULATION_SHAPE flag is already lowered.

		\note Trigger shapes will no longer send notification events for interactions with other trigger shapes.

		\note Shapes marked as triggers are allowed to participate in scene queries, provided the eSCENE_QUERY_SHAPE flag is set. 

		\note This flag has no effect if simulation is disabled for the corresponding actor (see #PxActorFlag::eDISABLE_SIMULATION).

		@see PxSimulationEventCallback.onTrigger() PxScene.setSimulationEventCallback() PxShape.setFlag(), PxShape.setFlags()
		*/
		eTRIGGER_SHAPE					= (1<<2),

		/**
		\brief Enable debug renderer for this shape

		@see PxScene.getRenderBuffer() PxRenderBuffer PxVisualizationParameter
		*/
		eVISUALIZATION					= (1<<3)
	};
};

} // physx
