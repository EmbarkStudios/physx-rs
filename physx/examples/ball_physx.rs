// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created:  3 July 2019

use physx::prelude::*;

type PxMaterial = physx::material::PxMaterial<()>;
type PxShape = physx::shape::PxShape<(), PxMaterial>;
type PxArticulationLink = physx::articulation_link::PxArticulationLink<(), PxShape>;
type PxRigidStatic = physx::rigid_static::PxRigidStatic<(), PxShape>;
type PxRigidDynamic = physx::rigid_dynamic::PxRigidDynamic<(), PxShape>;
type PxArticulation = physx::articulation::PxArticulation<(), PxArticulationLink>;
type PxArticulationReducedCoordinate =
    physx::articulation_reduced_coordinate::PxArticulationReducedCoordinate<(), PxArticulationLink>;
type PxScene = physx::scene::PxScene<
    (),
    PxArticulationLink,
    PxRigidStatic,
    PxRigidDynamic,
    PxArticulation,
    PxArticulationReducedCoordinate,
    OnCollision,
    OnTrigger,
    OnConstraintBreak,
    OnWakeSleep,
    OnAdvance,
>;

struct OnCollision;
impl CollisionCallback for OnCollision {
    fn on_collision(
        &mut self,
        _header: &physx_sys::PxContactPairHeader,
        _pairs: &[physx_sys::PxContactPair],
    ) {
    }
}
struct OnTrigger;
impl TriggerCallback for OnTrigger {
    fn on_trigger(&mut self, _pairs: &[physx_sys::PxTriggerPair]) {}
}

struct OnConstraintBreak;
impl ConstraintBreakCallback for OnConstraintBreak {
    fn on_constraint_break(&mut self, _constraints: &[physx_sys::PxConstraintInfo]) {}
}
struct OnWakeSleep;
impl WakeSleepCallback<PxArticulationLink, PxRigidStatic, PxRigidDynamic> for OnWakeSleep {
    fn on_wake_sleep(
        &mut self,
        _actors: &[&physx::actor::ActorMap<PxArticulationLink, PxRigidStatic, PxRigidDynamic>],
        _is_waking: bool,
    ) {
    }
}

struct OnAdvance;
impl AdvanceCallback<PxArticulationLink, PxRigidDynamic> for OnAdvance {
    unsafe fn on_advance(
        &self,
        _actors: &[&physx::rigid_body::RigidBodyMap<PxArticulationLink, PxRigidDynamic>],
        _transforms: &[PxTransform],
    ) {
    }
}

/// This is a WIP example for how the rustified wrappers lets your reduced the
/// amount of unsafe in your code, and make it clearer where we cannot abstract
/// away the underlying dangers.
///
/// Some of these will go away over time, when we add abstractions for Material
/// and Geometry, while some will remain for performance such as
/// `get_rigid_actor_unchecked`.
///
/// The overall goal is to maintain a close mapping to the underlying PhysX API
/// while improving safety and reliability of the code.

fn main() -> Result<(), ()> {
    // Holds a PxFoundation and a PxPhysics built from it.
    // Also has an optional Pvd and transport, not enabled by default.
    // The type parameters are for shape and material user data, which
    // isn't used in this demo, so they are set to (). If the never-type feature
    // is enabled, that is an even better choice.
    let mut physics_foundation = PhysicsFoundation::<_, PxShape>::default();

    let physics = physics_foundation.physics.as_mut();

    let mut scene: Owner<PxScene> = physics
        .create_scene(
            PxSceneDesc::new(
                physics,
                (),
                PxSimulationEventCallback::new(None, None, None, None, Some(OnAdvance)).unwrap(),
                FilterShaderDescriptor::Default,
                1,
            )
            .unwrap(),
        )
        .unwrap();

    let mut material = physics.create_material(0.5, 0.5, 0.6, ()).unwrap();

    let ground_plane = physics
        .create_plane(PxVec3::new(0.0, 1.0, 0.0), 0.0, material.as_mut(), ())
        .unwrap();

    scene.add_static_actor(ground_plane);

    let sphere_geo = PxSphereGeometry::new(10.0);

    let mut sphere_actor = physics
        .create_rigid_dynamic(
            PxTransform::from_translation(&PxVec3::new(0.0, 40.0, 100.0)),
            &sphere_geo,
            material.as_mut(),
            10.0,
            PxTransform::default(),
            (),
        )
        .unwrap();

    sphere_actor.set_angular_damping(0.5);
    sphere_actor.set_rigid_body_flag(RigidBodyFlag::EnablePoseIntegrationPreview, true);
    scene.add_dynamic_actor(sphere_actor);

    // Updating
    let heights_over_time = (0..100)
        .map(|_| {
            // Calls both update and fetch_results.  More complex simulation update
            // controls are not fully supported.
            scene
                .step(
                    0.1,
                    None::<&mut physx_sys::PxBaseTask>,
                    Some(unsafe { &mut ScratchBuffer::new(4) }),
                    true,
                )
                .expect("error occured during simulation");
            // For simplicity, just read out the only dynamic actor in the scene.
            // getActiveActors is also supported, it returns a Vec<&mut ActorMap> that has
            // a map method that takes a function for each actor type, and as_* methods
            // that return an Option<&mut>.
            let actors = scene.get_dynamic_actors();
            actors[0].get_global_position().y() as i32 - 10
        })
        .collect::<Vec<_>>();

    // Draw to stdout
    let max_h = 18;
    (0..max_h)
        .map(|h| {
            let h = max_h - 1 - h;
            heights_over_time
                .iter()
                .enumerate()
                .map(|(_t, p)| if h == *p { 'o' } else { ' ' })
                .collect::<String>()
        })
        .for_each(|line| println!("{}", line));

    Ok(())
}
