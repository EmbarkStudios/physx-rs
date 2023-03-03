#include <stddef.h>

namespace physx {

/**
\brief Abstract base class for an application defined memory allocator that can be used by the Nv library.

\note The SDK state should not be modified from within any allocation/free function.

<b>Threading:</b> All methods of this class should be thread safe as it can be called from the user thread
or the physics processing thread(s).
*/

class PxAllocatorCallback
{
  public:

    virtual ~PxAllocatorCallback()
    {
    }

    /**
    \brief Allocates size bytes of memory, which must be 16-byte aligned.

    This method should never return NULL.  If you run out of memory, then
    you should terminate the app or take some other appropriate action.

    <b>Threading:</b> This function should be thread safe as it can be called in the context of the user thread
    and physics processing thread(s).

    \param size			Number of bytes to allocate.
    \param typeName		Name of the datatype that is being allocated
    \param filename		The source file which allocated the memory
    \param line			The source line which allocated the memory
    \return				The allocated block of memory.
    */
    virtual void* allocate(size_t size, const char* typeName, const char* filename, int line) = 0;

    /**
    \brief Frees memory previously allocated by allocate().

    <b>Threading:</b> This function should be thread safe as it can be called in the context of the user thread
    and physics processing thread(s).

    \param ptr Memory to free.
    */
    virtual void deallocate(void* ptr) = 0;
};

} // namespace physx
