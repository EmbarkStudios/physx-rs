// From PxBroadPhase.h

namespace physx {

/**
\brief Broad phase algorithm used in the simulation

eSAP is a good generic choice with great performance when many objects are sleeping. Performance
can degrade significantly though, when all objects are moving, or when large numbers of objects
are added to or removed from the broad phase. This algorithm does not need world bounds to be
defined in order to work.

eMBP is an alternative broad phase algorithm that does not suffer from the same performance
issues as eSAP when all objects are moving or when inserting large numbers of objects. However
its generic performance when many objects are sleeping might be inferior to eSAP, and it requires
users to define world bounds in order to work.

eABP is a revisited implementation of MBP, which automatically manages broad-phase regions.
It offers the convenience of eSAP (no need to define world bounds or regions) and the performance
of eMBP when a lot of objects are moving. While eSAP can remain faster when most objects are
sleeping and eMBP can remain faster when it uses a large number of properly-defined regions,
eABP often gives the best performance on average and the best memory usage.

ePABP is a parallel implementation of ABP. It can often be the fastest (CPU) broadphase, but it
can use more memory than ABP.

eGPU is a GPU implementation of the incremental sweep and prune approach. Additionally, it uses a ABP-style
initial pair generation approach to avoid large spikes when inserting shapes. It not only has the advantage 
of traditional SAP approch which is good for when many objects are sleeping, but due to being fully parallel, 
it also is great when lots of shapes are moving or for runtime pair insertion and removal. It can become a 
performance bottleneck if there are a very large number of shapes roughly projecting to the same values
on a given axis. If the scene has a very large number of shapes in an actor, e.g. a humanoid, it is recommended
to use an aggregate to represent multi-shape or multi-body actors to minimize stress placed on the broad phase.
*/
struct PxBroadPhaseType
{
	enum Enum
	{
		eSAP,	//!< 3-axes sweep-and-prune
		eMBP,	//!< Multi box pruning
		eABP,	//!< Automatic box pruning
		ePABP,	//!< Parallel automatic box pruning
		eGPU,	//!< GPU broad phase
		eLAST
	};
};

} // physx
