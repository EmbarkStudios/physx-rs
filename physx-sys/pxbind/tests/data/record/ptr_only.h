namespace physx {

class PxAllocatorCallback;

class PxAllocatorCallback
{
  public:

    virtual ~PxAllocatorCallback()
    {
    }

    virtual void deallocate(void* ptr) = 0;
};

class MemoryBuffer;

} // namespace physx
