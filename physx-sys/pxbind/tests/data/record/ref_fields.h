#include "common/PxPhysXCommonConfig.h"
#include "foundation/PxVecTransform.h"


namespace physx {
    class PxReffyMcRefface
    {
    public:
        PxVec3 shapeSpaceCenterOfMass;
        const PxTransform& transform;
        const PxMat33& vertex2Shape;
        const PxMat33& shape2Vertex;
        const bool isIdentityScale;
    };
}
