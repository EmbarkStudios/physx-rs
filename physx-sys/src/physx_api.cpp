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

struct FilterCallbackData {
    SimulationShaderFilter filter;
    bool call_default_filter_shader_first;
};

PxFilterFlags FilterShaderTrampoline(PxFilterObjectAttributes attributes0,
                                     PxFilterData filterData0,
                                     PxFilterObjectAttributes attributes1,
                                     PxFilterData filterData1,
                                     PxPairFlags &pairFlags,
                                     const void *constantBlock,
                                     PxU32 constantBlockSize)
{
    const FilterCallbackData *data = static_cast<const FilterCallbackData *>(constantBlock);

    if (data->call_default_filter_shader_first) {
        // Let the default handler set the pair flags, but ignore the collision filtering
        PxDefaultSimulationFilterShader(attributes0, filterData0, attributes1, filterData1, pairFlags, constantBlock,
                                        constantBlockSize);
    }

    // Get the filter shader from the constant block
    SimulationShaderFilter shaderfilter = data->filter;

    // This is a bit expensive since we're putting things on the stack but with LTO this should optimize OK,
    // and I was having issues with corrupted values when passing by value
    FilterShaderCallbackInfo info{attributes0, attributes1, filterData0, filterData1, &pairFlags, nullptr, 0};

    // We return a u16 since PxFilterFlags is a complex type and C++ wants it to be returned on the stack,
    // but Rust thinks it's simple due to the codegen and wants to return it in EAX.
    return PxFilterFlags{shaderfilter(&info)};
}

using CollisionCallback = void (*)(void *, PxContactPairHeader const *, PxContactPair const *, PxU32);
using TriggerCallback = void (*)(void *, PxTriggerPair const *, PxU32);
using ConstraintBreakCallback = void (*)(void *, PxConstraintInfo const *, PxU32);
using WakeSleepCallback = void (*)(void *, PxActor **const, PxU32, bool);
using AdvanceCallback = void (*)(void *, const PxRigidBody *const *, const PxTransform *const, PxU32);

struct SimulationEventCallbackInfo {
    // Callback for collision events.
    CollisionCallback collisionCallback = nullptr;
    void *collisionUserData = nullptr;
    // Callback for trigger shape events (an object entered or left a trigger shape).
    TriggerCallback triggerCallback = nullptr;
    void *triggerUserData = nullptr;
    // Callback for when a constraint breaks (such as a joint with a force limit)
    ConstraintBreakCallback constraintBreakCallback = nullptr;
    void *constraintBreakUserData = nullptr;
    // Callback for when an object falls asleep or is awoken.
    WakeSleepCallback wakeSleepCallback = nullptr;
    void *wakeSleepUserData = nullptr;
    // Callback to get the next pose early for objects (if flagged with eENABLE_POSE_INTEGRATION_PREVIEW).
    AdvanceCallback advanceCallback = nullptr;
    void *advanceUserData = nullptr;
};

class SimulationEventTrampoline : public PxSimulationEventCallback
{
  public:
    SimulationEventTrampoline(const SimulationEventCallbackInfo *callbacks) : mCallbacks(*callbacks) {}

    // Collisions
    void onContact(const PxContactPairHeader &pairHeader, const PxContactPair *pairs, PxU32 nbPairs) override {
        if (mCallbacks.collisionCallback) {
            mCallbacks.collisionCallback(mCallbacks.collisionUserData, &pairHeader, pairs, nbPairs);
        }
    }

    // Triggers
    void onTrigger(PxTriggerPair *pairs, PxU32 count) override {
        if (mCallbacks.triggerCallback) {
            mCallbacks.triggerCallback(mCallbacks.triggerUserData, pairs, count);
        }
    }

    // Constraint breaks
    void onConstraintBreak(PxConstraintInfo *constraints, PxU32 count) override {
        if (mCallbacks.constraintBreakCallback) {
            mCallbacks.constraintBreakCallback(mCallbacks.constraintBreakUserData, constraints, count);
        }
    }

    // Wake/Sleep (combined for convenience)
    void onWake(PxActor **actors, PxU32 count) override {
        if (mCallbacks.wakeSleepCallback) {
            mCallbacks.wakeSleepCallback(mCallbacks.wakeSleepUserData, actors, count, true);
        }
    }
    void onSleep(PxActor **actors, PxU32 count) override {
        if (mCallbacks.wakeSleepCallback) {
            mCallbacks.wakeSleepCallback(mCallbacks.wakeSleepUserData, actors, count, false);
        }
    }

    // Advance
    void onAdvance(const PxRigidBody *const * bodyBuffer, const PxTransform *poseBuffer, const PxU32 count) override {
        if (mCallbacks.advanceCallback) {
            mCallbacks.advanceCallback(mCallbacks.advanceUserData, bodyBuffer, poseBuffer, count);
        }
    }

  private:
    SimulationEventCallbackInfo mCallbacks;
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

typedef uint32_t (*RaycastHitCallback)(const PxRigidActor *actor, const PxFilterData *filterData, const PxShape *shape, uint32_t hitFlags, const void *userData);

class RaycastFilterTrampoline : public PxQueryFilterCallback
{
  public:
    RaycastFilterTrampoline(RaycastHitCallback callback, const void *userdata)
        : mCallback(callback), mUserData(userdata) {}

    RaycastHitCallback mCallback;
    const void *mUserData;

    virtual PxQueryHitType::Enum preFilter(const PxFilterData &filterData, const PxShape *shape, const PxRigidActor *actor, PxHitFlags &hitFlags)
    {
        switch (mCallback(actor, &filterData, shape, (uint32_t)hitFlags, mUserData)) {
        case 0: return PxQueryHitType::eNONE;
        case 1: return PxQueryHitType::eTOUCH;
        case 2: return PxQueryHitType::eBLOCK;
        default: return PxQueryHitType::eNONE;
        }
    }

    virtual PxQueryHitType::Enum postFilter(const PxFilterData &, const PxQueryHit &)
    {
        return PxQueryHitType::eNONE;
    }
};

typedef void * (*AllocCallback)(uint64_t size, const char *typeName, const char *filename, int line, void *userdata);
typedef void (*DeallocCallback)(void *ptr, void *userdata);

class CustomAllocatorTrampoline : public PxAllocatorCallback {
public:
    CustomAllocatorTrampoline(AllocCallback allocCb, DeallocCallback deallocCb, void *userdata)
        : mAllocCallback(allocCb), mDeallocCallback(deallocCb), mUserData(userdata) {
    }

	void *allocate(size_t size, const char* typeName, const char* filename, int line) {
        return mAllocCallback((uint64_t)size, typeName, filename, line, mUserData);
    }

	virtual void deallocate(void* ptr) {
        mDeallocCallback(ptr, mUserData);
    }

private:
    AllocCallback mAllocCallback;
    DeallocCallback mDeallocCallback;
    void *mUserData;
};

extern "C"
{
    PxFoundation *physx_create_foundation()
    {
        return PxCreateFoundation(PX_PHYSICS_VERSION, gAllocator, gErrorCallback);
    }

    PxFoundation *physx_create_foundation_with_alloc(PxAllocatorCallback *allocator)
    {
        return PxCreateFoundation(PX_PHYSICS_VERSION, *allocator, gErrorCallback);
    }

    // fixme[tolsson]: this might be iffy on Windows with DLLs if we have multiple packages
    // linking against the raw interface
    PxAllocatorCallback* get_default_allocator()
    {
        return &gAllocator;
    }

    // fixme[tolsson]: this might be iffy on Windows with DLLs if we have multiple packages
    // linking against the raw interface
    PxErrorCallback* get_default_error_callback()
    {
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

    PxQueryFilterCallback *create_raycast_filter_callback_func(RaycastHitCallback callback, void *userData) {
        return new RaycastFilterTrampoline(callback, userData);
    }

    PxAllocatorCallback *create_alloc_callback(
        AllocCallback alloc_callback,
        DeallocCallback dealloc_callback,
        void *userdata
    ) {
        return new CustomAllocatorTrampoline(alloc_callback, dealloc_callback, userdata);
    }

    void *get_default_simulation_filter_shader()
    {
        return (void *)PxDefaultSimulationFilterShader;
    }

    PxSimulationEventCallback *create_simulation_event_callbacks(const SimulationEventCallbackInfo *callbacks)
    {
        SimulationEventTrampoline *trampoline = new SimulationEventTrampoline(callbacks);
        return static_cast<PxSimulationEventCallback *>(trampoline);
    }

    void destroy_simulation_event_callbacks(PxSimulationEventCallback *callback)
    {
        SimulationEventTrampoline *trampoline = static_cast<SimulationEventTrampoline *>(callback);
        delete trampoline;
    }

    void enable_custom_filter_shader(PxSceneDesc *desc, SimulationShaderFilter filter, uint32_t call_default_filter_shader_first)
    {
        /* Note: This is a workaround to PhysX copying the filter data */
        static FilterCallbackData filterShaderData = {
            filter,
            call_default_filter_shader_first != 0
        };
        desc->filterShader = FilterShaderTrampoline;
        // printf("Setting pointer to %p\n", filter);
        desc->filterShaderData     = (void *)&filterShaderData;
        desc->filterShaderDataSize = sizeof(FilterCallbackData);
    }
}
