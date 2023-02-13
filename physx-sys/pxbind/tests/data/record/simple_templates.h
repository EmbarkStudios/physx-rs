#include <stdint.h>

namespace physx {
    template<class Type>
    class PxVec3T {
    public:
        Type x, y, z;
    };

    typedef PxVec3T<float>	PxVec3;

    class PxVec3Padded : public PxVec3 {
    public:
        uint32_t padding;
    };

    typedef PxVec3Padded	PxVec3p;

    template<class Type>
    class PxVec4T {
    public:
        Type	x, y, z, w;
    };

    typedef PxVec4T<float>	PxVec4;

    template<class Type>
    class PxMat44T {
    public:
        PxVec4T<Type>	column0, column1, column2, column3; // the four base vectors
    };

    typedef PxMat44T<float>		PxMat44;

    template<class Type>
    class PxQuatT {
    public:
        Type	x, y, z, w;
    };

    typedef PxQuatT<float>	PxQuat;
}
