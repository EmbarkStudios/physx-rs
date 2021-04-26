use crate::{
    actor::{Actor, ActorMap},
    articulation::Articulation,
    articulation_base::ArticulationBase,
    articulation_link::ArticulationLink,
    articulation_reduced_coordinate::ArticulationReducedCoordinate,
    base::Base,
    bvh_structure::BvhStructure,
    owner::Owner,
    rigid_actor::RigidActor,
    rigid_dynamic::RigidDynamic,
    rigid_static::RigidStatic,
    traits::Class,
};

use std::{marker::PhantomData, ptr::null};

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

/// A collection of actors sharing a broad-phase entry.
/// Parametrized by the ArticulationLink, RigidStatic, RigidDynamic, Articulation and
/// ArticulationReducedCoordinate types that it may contain.
#[repr(transparent)]
pub struct PxAggregate<L, S, D, T, C>
where
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,
    T: Articulation,
    C: ArticulationReducedCoordinate,
{
    obj: physx_sys::PxAggregate,
    phantom_user_data: PhantomData<(*const L, *const S, *const D, *const T, *const C)>,
}

impl<L, S, D, T, C> Drop for PxAggregate<L, S, D, T, C>
where
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,
    T: Articulation,
    C: ArticulationReducedCoordinate,
{
    fn drop(&mut self) {
        unsafe {
            PxAggregate_release_mut(self.as_mut_ptr());
        }
    }
}

unsafe impl<L, S, D, T, C> Send for PxAggregate<L, S, D, T, C>
where
    L: ArticulationLink + Send,
    S: RigidStatic + Send,
    D: RigidDynamic + Send,
    T: Articulation + Send,
    C: ArticulationReducedCoordinate + Send,
{
}

unsafe impl<L, S, D, T, C> Sync for PxAggregate<L, S, D, T, C>
where
    L: ArticulationLink + Sync,
    S: RigidStatic + Sync,
    D: RigidDynamic + Sync,
    T: Articulation + Sync,
    C: ArticulationReducedCoordinate + Sync,
{
}

unsafe impl<P, L, S, D, T, C> Class<P> for PxAggregate<L, S, D, T, C>
where
    physx_sys::PxAggregate: Class<P>,
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,
    T: Articulation,
    C: ArticulationReducedCoordinate,
{
    fn as_ptr(&self) -> *const P {
        self.obj.as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut P {
        self.obj.as_mut_ptr()
    }
}

impl<L, S, D, T, C> Aggregate for PxAggregate<L, S, D, T, C>
where
    L: ArticulationLink,
    S: RigidStatic,
    D: RigidDynamic,
    T: Articulation,
    C: ArticulationReducedCoordinate,
{
    type ActorMap = ActorMap<L, S, D>;
    type ArticulationLink = L;
    type RigidStatic = S;
    type RigidDynamic = D;
    type Articulation = T;
    type ArticulationReducedCoordinate = C;
}

pub trait Aggregate: Class<physx_sys::PxAggregate> + Base {
    type ActorMap: RigidActor;
    type ArticulationLink: ArticulationLink;
    type RigidStatic: RigidStatic;
    type RigidDynamic: RigidDynamic;
    type Articulation: Articulation;
    type ArticulationReducedCoordinate: ArticulationReducedCoordinate;

    /// Create a new owning wrapper around a raw `physx_sys::PxAggregate`.
    ///
    /// # Safety
    /// Owner's own the pointer they wrap, using the pointer after dropping the Owner,
    /// or creating multiple Owners from the same pointer will cause UB.  Use `into_ptr` to
    /// retrieve the pointer and consume the Owner without dropping the pointee.
    unsafe fn from_raw(ptr: *mut physx_sys::PxAggregate) -> Option<Owner<Self>> {
        Owner::from_raw(ptr as *mut Self)
    }

    /// Add an actor to the aggregate.
    fn add_articulation_link(
        &mut self,
        actor: &mut Self::ArticulationLink,
        bvh: Option<&BvhStructure>,
    ) -> bool {
        unsafe {
            PxAggregate_addActor_mut(
                self.as_mut_ptr(),
                actor.as_mut_ptr(),
                bvh.map_or(null(), Class::as_ptr),
            )
        }
    }

    /// Add an actor to the aggregate.
    fn add_rigid_static(
        &mut self,
        actor: &mut Self::RigidStatic,
        bvh: Option<&BvhStructure>,
    ) -> bool {
        unsafe {
            PxAggregate_addActor_mut(
                self.as_mut_ptr(),
                actor.as_mut_ptr(),
                bvh.map_or(null(), Class::as_ptr),
            )
        }
    }

    /// Add an actor to the aggregate.
    fn add_rigid_dynamic(
        &mut self,
        actor: &mut Self::RigidDynamic,
        bvh: Option<&BvhStructure>,
    ) -> bool {
        unsafe {
            PxAggregate_addActor_mut(
                self.as_mut_ptr(),
                actor.as_mut_ptr(),
                bvh.map_or(null(), Class::as_ptr),
            )
        }
    }

    /// Add an articulation to the aggregate.
    fn add_articulation(&mut self, articulation: &mut Self::Articulation) -> bool {
        unsafe { PxAggregate_addArticulation_mut(self.as_mut_ptr(), articulation.as_mut_ptr()) }
    }

    /// Add an articulation to the aggregate.
    fn add_articulation_reduced_coordinate(
        &mut self,
        articulation: &mut Self::ArticulationReducedCoordinate,
    ) -> bool {
        unsafe { PxAggregate_addArticulation_mut(self.as_mut_ptr(), articulation.as_mut_ptr()) }
    }

    /// Get a Vec of all the actors in the aggregate.
    fn get_actors(&mut self) -> Vec<&mut Self::ActorMap> {
        let capacity = self.get_nb_actors();
        let mut buffer: Vec<&mut Self::ActorMap> = Vec::with_capacity(capacity as usize);
        unsafe {
            let len = PxAggregate_getActors(
                self.as_mut_ptr(),
                buffer.as_mut_ptr() as *mut *mut physx_sys::PxActor,
                capacity,
                0,
            );
            buffer.set_len(len as usize);
        }
        buffer
    }

    /// Return the maximum possible number of actors in the aggregate.
    fn get_max_nb_actors(&self) -> u32 {
        unsafe { PxAggregate_getMaxNbActors(self.as_ptr()) }
    }

    /// Returns the number of actors in the aggregate.
    fn get_nb_actors(&self) -> u32 {
        unsafe { PxAggregate_getNbActors(self.as_ptr()) }
    }

    /// Returns whether the aggregate will collide with itself.
    fn get_self_collision(&self) -> bool {
        unsafe { PxAggregate_getSelfCollision(self.as_ptr()) }
    }

    /// Remove an actor from the aggregate.
    fn remove_actor(&mut self, actor: &mut impl Actor) -> bool {
        unsafe { PxAggregate_removeActor_mut(self.as_mut_ptr(), actor.as_mut_ptr()) }
    }

    /// Remove an articulation from the aggregate.
    fn remove_articulation(&mut self, articulation: &mut impl ArticulationBase) -> bool {
        unsafe { PxAggregate_removeArticulation_mut(self.as_mut_ptr(), articulation.as_mut_ptr()) }
    }
}
