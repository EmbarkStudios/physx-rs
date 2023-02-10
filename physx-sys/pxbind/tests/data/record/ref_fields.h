#include "common/PxPhysXCommonConfig.h"
#include "foundation/PxVecTransform.h"

namespace physx { namespace Gu {
    class TriangleV; 
    class CapsuleV;
    class BoxV;
    class ConvexHullV;
    class ConvexHullNoScaleV;

    class SupportLocal
    {
    public:
        aos::Vec3V shapeSpaceCenterOfMass;
        const aos::PxTransformV& transform;
        const aos::Mat33V& vertex2Shape;
        const aos::Mat33V& shape2Vertex;
        const bool isIdentityScale;

        SupportLocal(
            const aos::PxTransformV& _transform,
            const aos::Mat33V& _vertex2Shape,
            const aos::Mat33V& _shape2Vertex,
            const bool _isIdentityScale = true
        ) : transform(_transform)
          , vertex2Shape(_vertex2Shape)
          , shape2Vertex(_shape2Vertex)
          , isIdentityScale(_isIdentityScale)
        {
        }

        PX_FORCE_INLINE void setShapeSpaceCenterofMass(const aos::Vec3VArg _shapeSpaceCenterOfMass)
        {
            shapeSpaceCenterOfMass = _shapeSpaceCenterOfMass;
        }

        virtual ~SupportLocal() {}
        virtual aos::Vec3V doSupport(const aos::Vec3VArg dir) const = 0;
        virtual void doSupport(const aos::Vec3VArg dir, aos::FloatV& min, aos::FloatV& max) const = 0;
        virtual void populateVerts(const PxU8* inds, PxU32 numInds, const PxVec3* originalVerts, aos::Vec3V* verts) const = 0;
    
    protected:
        SupportLocal& operator=(const SupportLocal&);
    };
} }
