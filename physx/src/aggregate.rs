use crate::{
    actor::{Actor, ActorMap},
    articulation_base::ArticulationBase,
    bvh_structure::BVHStructure,
    owner::Owner,
    traits::Class,
};

use std::marker::PhantomData;

use physx_sys::{
    PxAggregate_addActor_mut,
    PxAggregate_addArticulation_mut,
    PxAggregate_getActors,
    PxAggregate_getMaxNbActors,
    PxAggregate_getNbActors,
    PxAggregate_getSelfCollision,
    PxAggregate_release_mut,
    PxAggregate_removeActor_mut,
    PxAggregate_removeArticulation_mut,
    //PxAggregate_getScene_mut,
    //PxAggregate_getConcreteTypeName,
};

use std::ptr::null;

#[repr(transparent)]
pub struct Aggregate<L, S, D, H, M> {
    obj: physx_sys::PxAggregate,
    phantom_user_data: PhantomData<(L, S, D, H, M)>,
}

unsafe impl<P, L, S, D, H, M> Class<P> for Aggregate<L, S, D, H, M>
where
    physx_sys::PxAggregate: Class<P>,
{
    fn as_ptr(&self) -> *const P {
        self.obj.as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut P {
        self.obj.as_mut_ptr()
    }
}

impl<L, S, D, H, M> Aggregate<L, S, D, H, M> {
    pub(crate) unsafe fn from_raw(ptr: *mut physx_sys::PxAggregate) -> Option<Owner<Self>> {
        Owner::from_raw(ptr as *mut Self)
    }

    pub fn add_actor(&mut self, actor: &mut impl Actor, bvh: Option<&BVHStructure>) -> bool {
        unsafe {
            PxAggregate_addActor_mut(
                self.as_mut_ptr(),
                actor.as_mut_ptr(),
                bvh.map(Class::as_ptr).unwrap_or(null()),
            )
        }
    }

    pub fn add_articulation(&mut self, articulation: &mut impl ArticulationBase) -> bool {
        unsafe { PxAggregate_addArticulation_mut(self.as_mut_ptr(), articulation.as_mut_ptr()) }
    }

    pub fn get_actors(&mut self) -> Vec<&mut ActorMap<L, S, D, H, M>> {
        unsafe {
            let capacity = PxAggregate_getNbActors(self.as_ptr());
            let mut buffer: Vec<&mut ActorMap<L, S, D, H, M>> =
                Vec::with_capacity(capacity as usize);
            let len = PxAggregate_getActors(
                self.as_mut_ptr(),
                buffer.as_mut_ptr() as *mut *mut physx_sys::PxActor,
                capacity,
                0,
            );
            buffer.set_len(len as usize);
            buffer
        }
    }

    pub fn get_max_number_actors(&self) -> u32 {
        unsafe { PxAggregate_getMaxNbActors(self.as_ptr()) }
    }

    pub fn get_number_actors(&self) -> u32 {
        unsafe { PxAggregate_getNbActors(self.as_ptr()) }
    }

    pub fn get_self_collision(&self) -> bool {
        unsafe { PxAggregate_getSelfCollision(self.as_ptr()) }
    }

    pub fn remove_actor(&mut self, actor: &mut impl Actor) -> bool {
        unsafe { PxAggregate_removeActor_mut(self.as_mut_ptr(), actor.as_mut_ptr()) }
    }

    pub fn remove_articulation(&mut self, articulation: &mut impl ArticulationBase) -> bool {
        unsafe { PxAggregate_removeArticulation_mut(self.as_mut_ptr(), articulation.as_mut_ptr()) }
    }
}

unsafe impl<L: Send, S: Send, D: Send, H: Send, M: Send> Send for Aggregate<L, S, D, H, M> {}
unsafe impl<L: Sync, S: Sync, D: Sync, H: Sync, M: Sync> Sync for Aggregate<L, S, D, H, M> {}

impl<L, S, D, H, M> Drop for Aggregate<L, S, D, H, M> {
    fn drop(&mut self) {
        // TODO do aggregates own their actors? Should they be dropped here?
        unsafe {
            PxAggregate_release_mut(self.as_mut_ptr());
        }
    }
}
