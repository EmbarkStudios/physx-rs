#include "PxPhysicsAPI.h"
#include <cstdint>
#include "physx_generated.hpp"

PxDefaultAllocator gAllocator;
PxDefaultErrorCallback gErrorCallback;

struct FilterShaderCallbackInfo
{
    PxFilterObjectAttributes attributes0;
    PxFilterObjectAttributes attributes1;
    PxFilterData filterData0;
    PxFilterData filterData1;
    PxPairFlags *pairFlags;
    const void *constantBlock;
    PxU32 constantBlockSize;
};

typedef void (*CollisionCallback)(void *, PxContactPairHeader const *, PxContactPair const *, PxU32);
extern "C" typedef PxU16 (*SimulationShaderFilter)(FilterShaderCallbackInfo *);

PxFilterFlags FilterShaderTrampoline(PxFilterObjectAttributes attributes0,
                                     PxFilterData filterData0,
                                     PxFilterObjectAttributes attributes1,
                                     PxFilterData filterData1,
                                     PxPairFlags &pairFlags,
                                     const void *constantBlock,
                                     PxU32 constantBlockSize)
{
    // Let the default handler set the pair flags, but ignore the collision filtering
    PxDefaultSimulationFilterShader(attributes0, filterData0, attributes1, filterData1, pairFlags, constantBlock,
                                    constantBlockSize);

    // Get the filter shader from the constant block
    SimulationShaderFilter shaderfilter = *(SimulationShaderFilter *)constantBlock;

    // This is a bit expensive since we're putting things on the stack but with LTO this should optimize OK,
    // and I was having issues with corrupted values when passing by value
    FilterShaderCallbackInfo info{attributes0, attributes1, filterData0, filterData1, &pairFlags, nullptr, 0};

    // We return a u16 since PxFilterFlags is a complex type and C++ wants it to be returned on the stack,
    // but Rust thinks it's simple due to the codegen and wants to return it in EAX.
    return PxFilterFlags{shaderfilter(&info)};
}

class CollisionFilterTrampoline : public PxSimulationEventCallback
{
  public:
    CollisionFilterTrampoline(CollisionCallback callback, void *userData) : mUserData(userData), mCallback(callback)
    {}

    void onContact(const PxContactPairHeader &pairHeader, const PxContactPair *pairs, PxU32 nbPairs) override
    {
        mCallback(mUserData, &pairHeader, pairs, nbPairs);
    }

    void onTrigger(PxTriggerPair *pairs, PxU32 count) override
    {
        /* noop */
    }

    void onConstraintBreak(PxConstraintInfo *constraints, PxU32 count) override
    {
        /* noop */
    }

    void onWake(PxActor **actors, PxU32 count) override
    {
        /* noop */
    }

    void onSleep(PxActor **actors, PxU32 count) override
    {
        /* noop */
    }

    void onAdvance(const PxRigidBody *const *bodyBuffer, const PxTransform *poseBuffer, const PxU32 count) override
    {
        /* noop */
    }

  private:
    void *mUserData;
    CollisionCallback mCallback;
};

class RaycastFilterCallback : public PxQueryFilterCallback
{
  public:
    explicit RaycastFilterCallback(PxRigidActor *actor) : mActor(actor) {}

    PxRigidActor *mActor;

    virtual PxQueryHitType::Enum preFilter(const PxFilterData &, const PxShape *shape, const PxRigidActor *actor, PxHitFlags &)
    {
        if (mActor == actor)
        {
            return PxQueryHitType::eNONE;
        }
        else
        {
            return PxQueryHitType::eBLOCK;
        }
    }

    virtual PxQueryHitType::Enum postFilter(const PxFilterData &, const PxQueryHit &)
    {
        return PxQueryHitType::eNONE;
    }
};

extern "C"
{
    PxFoundation *physx_create_foundation()
    {
        return PxCreateFoundation(PX_PHYSICS_VERSION, gAllocator, gErrorCallback);
    }

    // fixme[tolsson]: this might be iffy on Windows with DLLs if we have multiple packages
    // linking against the raw interface
    PxAllocatorCallback* get_default_allocator()
    {
        return &gAllocator;
    }

    // fixme[tolsson]: this might be iffy on Windows with DLLs if we have multiple packages
    // linking against the raw interface
    PxErrorCallback* get_default_error_callback() {
        return &gErrorCallback;
    }

    PxPhysics *physx_create_physics(PxFoundation *foundation)
    {
        return PxCreatePhysics(PX_PHYSICS_VERSION, *foundation, PxTolerancesScale(), true, nullptr);
    }

    PxQueryFilterCallback *create_raycast_filter_callback(PxRigidActor *actor_to_ignore)
    {
        return new RaycastFilterCallback(actor_to_ignore);
    }

    void *get_default_simulation_filter_shader()
    {
        return (void *)PxDefaultSimulationFilterShader;
    }

    PxSimulationEventCallback *create_contact_callback(CollisionCallback callback, void *userData)
    {
        return new CollisionFilterTrampoline(callback, userData);
    }

    void destroy_contact_callback(PxSimulationEventCallback *callback)
    {
        delete reinterpret_cast<CollisionFilterTrampoline *>(callback);
    }

    void enable_custom_filter_shader(PxSceneDesc *desc, SimulationShaderFilter filter)
    {
        /* Note: This is a workaround to PhysX copying the filter data */
        static SimulationShaderFilter filterShaderData[] = {filter};
        desc->filterShader                               = FilterShaderTrampoline;
        // printf("Setting pointer to %p\n", filter);
        desc->filterShaderData     = (void *)filterShaderData;
        desc->filterShaderDataSize = sizeof(filter);
    }
}
