use std::{marker::PhantomData, slice};

#[rustfmt::skip]
use crate::{
    actor::ActorMap,
    articulation_link::ArticulationLink,
    math::PxTransform,
    owner::Owner,
    rigid_body::RigidBodyMap,
    rigid_dynamic::RigidDynamic,
    rigid_static::RigidStatic,
    traits::Class,
};

use physx_sys::UserData;
#[rustfmt::skip]
use physx_sys::{
    create_simulation_event_callbacks,
    destroy_simulation_event_callbacks,
    get_simulation_event_info,
    PxConstraintInfo,
    PxContactPair,
    PxContactPairHeader,
    PxTriggerPair,
    SimulationEventCallbackInfo,
};

/// A new type wrapper for PxSimulationEventCallback.  Parametrized by the ArticulationLink,
/// RigidStatic, and RigidDynamic actors the callbacks expect, and the Collision, Trigger,
/// ConstraintBreak, WakeSleep, and Advance Callbacks themselves.
#[repr(transparent)]
#[allow(clippy::type_complexity)]
pub struct PxSimulationEventCallback<L, S, D, OC, OT, OCB, OWS, OA>
where
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,
    OC: CollisionCallback,
    OT: TriggerCallback,
    OCB: ConstraintBreakCallback,
    OWS: WakeSleepCallback<L, S, D>,
    OA: AdvanceCallback<L, D>,
{
    obj: physx_sys::PxSimulationEventCallback,
    phantom_user_data: PhantomData<(*const L, *const S, *const D, OC, OT, OCB, OWS, OA)>,
}

unsafe impl<L, S, D, OC, OT, OCB, OWS, OA> Class<physx_sys::PxSimulationEventCallback>
    for PxSimulationEventCallback<L, S, D, OC, OT, OCB, OWS, OA>
where
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,
    OC: CollisionCallback,
    OT: TriggerCallback,
    OCB: ConstraintBreakCallback,
    OWS: WakeSleepCallback<L, S, D>,
    OA: AdvanceCallback<L, D>,
{
    fn as_ptr(&self) -> *const physx_sys::PxSimulationEventCallback {
        &self.obj
    }

    fn as_mut_ptr(&mut self) -> *mut physx_sys::PxSimulationEventCallback {
        &mut self.obj
    }
}

impl<L, S, D, OC, OT, OCB, OWS, OA> PxSimulationEventCallback<L, S, D, OC, OT, OCB, OWS, OA>
where
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,
    OC: CollisionCallback,
    OT: TriggerCallback,
    OCB: ConstraintBreakCallback,
    OWS: WakeSleepCallback<L, S, D>,
    OA: AdvanceCallback<L, D>,
{
    /// Create a new simulation event callback.
    #[allow(clippy::type_complexity)]
    pub fn new(
        on_collide: Option<OC>,
        on_trigger: Option<OT>,
        on_constraint_break: Option<OCB>,
        on_wake_sleep: Option<OWS>,
        on_advance: Option<OA>,
    ) -> Option<Owner<PxSimulationEventCallback<L, S, D, OC, OT, OCB, OWS, OA>>>
    where
        L: ArticulationLink,
        S: RigidStatic,
        D: RigidDynamic,
        OC: CollisionCallback,
        OT: TriggerCallback,
        OCB: ConstraintBreakCallback,
        OWS: WakeSleepCallback<L, S, D>,
        OA: AdvanceCallback<L, D>,
    {
        unsafe {
            let (collision_callback, collision_user_data) =
                on_collide.map_or((None, UserData::null()), OC::into_cb_user_data);
            let (trigger_callback, trigger_user_data) =
                on_trigger.map_or((None, UserData::null()), OT::into_cb_user_data);
            let (constraint_break_callback, constraint_break_user_data) =
                on_constraint_break.map_or((None, UserData::null()), OCB::into_cb_user_data);
            let (wake_sleep_callback, wake_sleep_user_data) =
                on_wake_sleep.map_or((None, UserData::null()), OWS::into_cb_user_data);
            let (advance_callback, advance_user_data) =
                on_advance.map_or((None, UserData::null()), OA::into_cb_user_data);

            Owner::from_raw(
                create_simulation_event_callbacks(&SimulationEventCallbackInfo {
                    collision_callback,
                    collision_user_data,
                    trigger_callback,
                    trigger_user_data,
                    constraint_break_callback,
                    constraint_break_user_data,
                    wake_sleep_callback,
                    wake_sleep_user_data,
                    advance_callback,
                    advance_user_data,
                }) as *mut _,
            )
        }
    }
}

impl<L, S, D, OC, OT, OCB, OWS, OA> Drop
    for PxSimulationEventCallback<L, S, D, OC, OT, OCB, OWS, OA>
where
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,

    OC: CollisionCallback,
    OT: TriggerCallback,
    OCB: ConstraintBreakCallback,
    OWS: WakeSleepCallback<L, S, D>,
    OA: AdvanceCallback<L, D>,
{
    fn drop(&mut self) {
        unsafe {
            let info = &mut *get_simulation_event_info(self.as_mut_ptr());
            {
                if info.collision_callback.is_some() {
                    info.collision_user_data.heap_drop_and_dealloc::<OC>();
                };
                if info.trigger_callback.is_some() {
                    info.trigger_user_data.heap_drop_and_dealloc::<OT>();
                };
                if info.constraint_break_callback.is_some() {
                    info.constraint_break_user_data
                        .heap_drop_and_dealloc::<OCB>();
                };
                if info.wake_sleep_callback.is_some() {
                    info.wake_sleep_user_data.heap_drop_and_dealloc::<OWS>();
                };
                if info.advance_callback.is_some() {
                    info.advance_user_data.heap_drop_and_dealloc::<OA>();
                };
            }
            destroy_simulation_event_callbacks(self.as_mut_ptr());
        }
    }
}

/// A trait for onCollision()
pub trait CollisionCallback: Sized {
    fn on_collision(&mut self, header: &PxContactPairHeader, pairs: &[PxContactPair]);
}

impl<T> CollisionCallbackRaw for T where T: CollisionCallback {}

trait CollisionCallbackRaw: CollisionCallback {
    unsafe extern "C" fn callback(
        mut user_data: UserData,
        header: *const physx_sys::PxContactPairHeader,
        pairs: *const physx_sys::PxContactPair,
        nb_pairs: u32,
    ) {
        unsafe {
            Self::on_collision(
                user_data.heap_data_mut::<Self>(),
                &*header,
                slice::from_raw_parts(pairs, nb_pairs as usize),
            )
        }
    }

    fn into_cb_user_data(self) -> (Option<physx_sys::CollisionCallback>, UserData) {
        (Some(Self::callback), UserData::new_on_heap(self))
    }
}

/// A trait for onTrigger().
pub trait TriggerCallback: Sized {
    fn on_trigger(&mut self, pairs: &[PxTriggerPair]);
}

impl<T> TriggerCallbackRaw for T where T: TriggerCallback {}

trait TriggerCallbackRaw: TriggerCallback {
    unsafe extern "C" fn callback(
        mut user_data: UserData,
        pairs: *const physx_sys::PxTriggerPair,
        nb_pairs: u32,
    ) {
        unsafe {
            Self::on_trigger(
                user_data.heap_data_mut::<Self>(),
                slice::from_raw_parts(pairs, nb_pairs as usize),
            )
        }
    }

    fn into_cb_user_data(self) -> (Option<physx_sys::TriggerCallback>, UserData) {
        (Some(Self::callback), UserData::new_on_heap(self))
    }
}

/// A trait for onConstraintBReak().
pub trait ConstraintBreakCallback: Sized {
    fn on_constraint_break(&mut self, constraints: &[PxConstraintInfo]);
}

impl<T> ConstraintBreakCallbackRaw for T where T: ConstraintBreakCallback {}

trait ConstraintBreakCallbackRaw: ConstraintBreakCallback {
    unsafe extern "C" fn callback(
        mut user_data: UserData,
        constraints: *const physx_sys::PxConstraintInfo,
        nb_constraints: u32,
    ) {
        unsafe {
            Self::on_constraint_break(
                user_data.heap_data_mut::<Self>(),
                slice::from_raw_parts(constraints, nb_constraints as usize),
            )
        }
    }

    fn into_cb_user_data(self) -> (Option<physx_sys::ConstraintBreakCallback>, UserData) {
        (Some(Self::callback), UserData::new_on_heap(self))
    }
}

/// A trait for `onWake()` and `onSleep()` callbacks. Parametrized by the [`ArticulationLink`],
/// [`RigidStatic`], and [`RigidDynamic`] types of the scene it is  in.
pub trait WakeSleepCallback<L: ArticulationLink, S: RigidStatic, D: RigidDynamic>: Sized {
    fn on_wake_sleep(&mut self, actors: &[&ActorMap<L, S, D>], is_waking: bool);
}

impl<T, L, S, D> WakeSleepCallbackRaw<L, S, D> for T
where
    T: WakeSleepCallback<L, S, D>,
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,
{
}

trait WakeSleepCallbackRaw<L, S, D>: WakeSleepCallback<L, S, D>
where
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,
{
    unsafe extern "C" fn callback(
        mut user_data: UserData,
        actors: *const *const physx_sys::PxActor,
        nb_actors: u32,
        is_waking: bool,
    ) {
        unsafe {
            Self::on_wake_sleep(
                user_data.heap_data_mut::<Self>(),
                slice::from_raw_parts(actors as *const &ActorMap<L, S, D>, nb_actors as usize),
                is_waking,
            );
        }
    }

    fn into_cb_user_data(self) -> (Option<physx_sys::WakeSleepCallback>, UserData) {
        (Some(Self::callback), UserData::new_on_heap(self))
    }
}

/// A trait for the Advance Callback.  onAdvance() is called during simulation, so it must
/// be thread safe, and `self` is not mutable. Parametrized by the `ArticulationLink`
/// and `RigidDynamic` types of the scene it is  in.
pub trait AdvanceCallback<L: ArticulationLink, D: RigidDynamic>: Sized {
    /// All actors with  `PxRigidBodyFlag::eENABLE_POSE_INTEGRATION_PREVIEW` set will be passed into here
    /// once the simulate call has updated their position.
    fn on_advance(&self, actors: &[&RigidBodyMap<L, D>], transforms: &[PxTransform]);
}

impl<T, L, D> AdvanceCallbackRaw<L, D> for T
where
    T: AdvanceCallback<L, D>,
    L: ArticulationLink,
    D: RigidDynamic,
{
}

trait AdvanceCallbackRaw<L, D>: AdvanceCallback<L, D>
where
    L: ArticulationLink,
    D: RigidDynamic,
{
    unsafe extern "C" fn callback(
        user_data: UserData,
        bodies: *const *const physx_sys::PxRigidBody,
        transforms: *const physx_sys::PxTransform,
        nb_actors: u32,
    ) {
        unsafe {
            Self::on_advance(
                user_data.heap_data_ref::<Self>(),
                slice::from_raw_parts(bodies as *const &RigidBodyMap<L, D>, nb_actors as usize),
                slice::from_raw_parts(transforms as *const PxTransform, nb_actors as usize),
            )
        }
    }

    fn into_cb_user_data(self) -> (Option<physx_sys::AdvanceCallback>, UserData) {
        (Some(Self::callback), UserData::new_on_heap(self))
    }
}
