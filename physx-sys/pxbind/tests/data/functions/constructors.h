#include "characterkinematic/PxController.h"

namespace physx {
/**
\brief Descriptor for a box character controller.

@see PxBoxController PxControllerDesc
*/
class PxBoxControllerDesc : public PxControllerDesc
{
public:
    /**
    \brief constructor sets to default.
    */
    PX_INLINE								PxBoxControllerDesc();
    PX_INLINE virtual						~PxBoxControllerDesc() {}

    /**
    \brief copy constructor.
    */
    PX_INLINE								PxBoxControllerDesc(const PxBoxControllerDesc&);

    /**
    \brief assignment operator.
    */
    PX_INLINE PxBoxControllerDesc&			operator=(const PxBoxControllerDesc&);

    /**
    \brief (re)sets the structure to the default.
    */
    PX_INLINE virtual	void				setToDefault();

    /**
    \brief returns true if the current settings are valid

    \return True if the descriptor is valid.
    */
    PX_INLINE virtual	bool				isValid()		const;

    /**
    \brief Half height

    <b>Default:</b> 1.0
    */
    PxF32				halfHeight;			// Half-height in the "up" direction

    /**
    \brief Half side extent

    <b>Default:</b> 0.5
    */
    PxF32				halfSideExtent;		// Half-extent in the "side" direction

    /**
    \brief Half forward extent

    <b>Default:</b> 0.5
    */
    PxF32				halfForwardExtent;	// Half-extent in the "forward" direction

protected:
    PX_INLINE void copy(const PxBoxControllerDesc&);
};

PX_INLINE PxBoxControllerDesc::PxBoxControllerDesc() :
    PxControllerDesc	(PxControllerShapeType::eBOX),
    halfHeight			(1.0f),
    halfSideExtent		(0.5f),
    halfForwardExtent	(0.5f)
{
}

PX_INLINE PxBoxControllerDesc::PxBoxControllerDesc(const PxBoxControllerDesc& other) : PxControllerDesc(other)
{
    copy(other);
}

PX_INLINE PxBoxControllerDesc& PxBoxControllerDesc::operator=(const PxBoxControllerDesc& other)
{
    PxControllerDesc::operator=(other);
    copy(other);
    return *this;
}

PX_INLINE void PxBoxControllerDesc::copy(const PxBoxControllerDesc& other)
{
    halfHeight			= other.halfHeight;
    halfSideExtent		= other.halfSideExtent;
    halfForwardExtent	= other.halfForwardExtent;
}

PX_INLINE void PxBoxControllerDesc::setToDefault()
{
    *this = PxBoxControllerDesc();
}

PX_INLINE bool PxBoxControllerDesc::isValid() const
{
    if(!PxControllerDesc::isValid())	return false;
    if(halfHeight<=0.0f)				return false;
    if(halfSideExtent<=0.0f)			return false;
    if(halfForwardExtent<=0.0f)			return false;
    if(stepOffset>2.0f*halfHeight)		return false;	// Prevents obvious mistakes
    return true;
}
}