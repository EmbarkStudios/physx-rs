#include "common/PxBase.h"
#include "foundation/PxMath.h"

namespace physx {
class PxJointLimitParameters
{
public:
    PxReal restitution;
    PxReal bounceThreshold;
    PxReal stiffness;
    PxReal damping;
    PxReal contactDistance_deprecated;

    PxJointLimitParameters() :
        restitution		(0.0f),
        bounceThreshold	(0.0f),
        stiffness		(0.0f),
        damping			(0.0f),
        contactDistance_deprecated	(0.0f)
    {
    }
    
    PxJointLimitParameters(const PxJointLimitParameters& p) :
        restitution		(p.restitution),
        bounceThreshold	(p.bounceThreshold),
        stiffness		(p.stiffness),
        damping			(p.damping),
        contactDistance_deprecated	(p.contactDistance_deprecated)
    {
    }	

    /**
    \brief Returns true if the current settings are valid.

    \return true if the current settings are valid
    */
    PX_INLINE bool isValid() const
    {
        return	PxIsFinite(restitution) && restitution >= 0 && restitution <= 1 && 
                PxIsFinite(stiffness) && stiffness >= 0 && 
                PxIsFinite(damping) && damping >= 0 &&
                PxIsFinite(bounceThreshold) && bounceThreshold >= 0 &&
                PxIsFinite(contactDistance_deprecated) && contactDistance_deprecated >= 0;
    }

    PX_INLINE bool isSoft() const
    {
        return damping>0 || stiffness>0;
    }

protected:
    ~PxJointLimitParameters() {}
};

class PxJointAngularLimitPair : public PxJointLimitParameters
{
public:
    PxReal upper, lower;

    PxJointAngularLimitPair(PxReal lowerLimit, PxReal upperLimit, PxReal contactDist_deprecated = -1.0f) :
        upper(upperLimit),
        lower(lowerLimit)
    {
        PxJointLimitParameters::contactDistance_deprecated = contactDist_deprecated ==-1.0f ? PxMin(0.1f, 0.49f*(upperLimit-lowerLimit)) : contactDist_deprecated;
        bounceThreshold = 0.5f;
    }

    /**
    \brief Returns true if the limit is valid.

    \return true if the current settings are valid
    */
    PX_INLINE bool isValid() const
    {
        return PxJointLimitParameters::isValid() &&
               PxIsFinite(upper) && PxIsFinite(lower) && upper >= lower;
    }
};
}
