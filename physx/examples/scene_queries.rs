// Author: Nick Caplinger <the.nick.caplinger@gmail.com>
// Copyright © 2020, Embark Studios, all rights reserved.
// Created:  8 December 2020

use glam::Vec3;
use physx::prelude::*;
use physx::query::{
    PxQueryFilterData, RaycastCallback, PxRaycastCallback, RaycastCallbackDefault,
};
use physx::scene::HitFlag;
use physx::traits::PxFlags;

/// This is an example demonstrating the usage of scene queries within the physx crate.
/// This includes raycast, sweep, and overlap tests.
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

/// Next up, the simulation event callbacks need to be defined, and possibly an
/// allocator callback as well.
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
    fn on_advance(
        &self,
        _actors: &[&physx::rigid_body::RigidBodyMap<PxArticulationLink, PxRigidDynamic>],
        _transforms: &[PxTransform],
    ) {
    }
}

// A test raycast callback that stores positions of all touches
#[derive(Default)]
struct PositionCollectorRaycastCallback {
    positions: Vec<PxVec3>,
}

impl RaycastCallback for PositionCollectorRaycastCallback {

    fn process_touches(&mut self, touches: &[physx_sys::PxRaycastHit]) -> bool {
        for touch in touches {
            self.positions.push(touch.position.into());
        }

        // We should return true if we determine that the touched object should block further hits
        // For our example callback, we'll just collected all the touched objects
        false
    }

    fn finalize_query(&mut self) {
        println!("Collected a total of {} positions!", self.positions.len());
    }
}

fn main() {
    // Holds a PxFoundation and a PxPhysics.
    // Also has an optional Pvd and transport, not enabled by default.
    // The default allocator is the one provided by PhysX.
    let mut physics = PhysicsFoundation::<_, PxShape>::default();

    // Setup the scene object.  The PxScene type alias makes this much cleaner.
    // There are lots of unwrap calls due to potential null pointers.
    let mut scene: Owner<PxScene> = physics
        .create(SceneDescriptor {
            gravity: PxVec3::new(0.0, -9.81, 0.0),
            on_advance: Some(OnAdvance),
            ..SceneDescriptor::new(())
        })
        .unwrap();

    let mut material = physics.create_material(0.5, 0.5, 0.6, ()).unwrap();

    let ground_plane = physics
        .create_plane(Vec3::new(0.0, 1.0, 0.0).into(), 0.0, material.as_mut(), ())
        .unwrap();
    // The scene owns actors that are added to it.  They can be retrieved using the
    // various getters on the scene.
    scene.add_static_actor(ground_plane);

    let sphere_geo = PxSphereGeometry::new(10.0);
    let sphere_pos = Vec3::new(0.0, 40.0, 100.0);

    let mut sphere_actor = physics
        .create_rigid_dynamic(
            PxTransform::from_translation(&sphere_pos.into()),
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

    // Do some scene queries
    let origin = sphere_pos + Vec3::new(0.0, 100.0, 0.0);
    let up_dir = Vec3::new(0.0, 1.0, 0.0);
    let down_dir = -up_dir;
    let distance = 5000.0;

    // Raycasts
//    let mut hit = PxRaycastBuffer::new();
    let hit_flags = HitFlag::default_hit_flags();
    let filter_data = PxQueryFilterData::default();

    let default_touch_buffer = physx_sys::PxRaycastHit {
        actor: std::ptr::null_mut(),
        shape: std::ptr::null_mut(),
        faceIndex: 0,
        structgen_pad0: [0u8; 4],
        flags: HitFlag::default_hit_flags().into_px(),
        structgen_pad1: [0u8; 2],
        position: PxVec3::default().into(),
        normal: PxVec3::default().into(),
        distance: 0.0,
        u: 0.0,
        v: 0.0,
    };

    // NOTE touch_buffer is used as the backing storage for the callback.
    //      It can be allocated however you see fit.
    // let mut touch_buffer = [default_touch_buffer; 16];
    let mut touch_buffer = vec![default_touch_buffer; 128];

    let mut custom_hit_callbacks = PositionCollectorRaycastCallback::default();
    let mut custom_hit = PxRaycastCallback::with_user_callbacks(&mut custom_hit_callbacks, Some(&mut touch_buffer));

    // let did_ray_hit = scene.raycast(
    //     &origin.into(),
    //     &down_dir.into(),
    //     distance,
    //     &mut hit,
    //     hit_flags,
    //     &filter_data,
    //     None,
    //     None,
    // );
    // assert!(did_ray_hit); // hits dynamic sphere in scene

    // // Let's see some info about the hit
    // let hit_info = hit.get_raycast_hit().unwrap();
    // dbg!(hit_info.distance);
    // // dbg!(PxVec3::from(hit_info.position));
    // // dbg!(PxVec3::from(hit_info.normal));

    let did_ray_hit = scene.raycast(
        &origin.into(),
        &down_dir.into(),
        distance,
        &mut custom_hit,
        hit_flags,
        &filter_data,
        None,
        None,
    );
    assert!(did_ray_hit); // hits dynamic sphere in scene

    // NOTE touch_buffer is borrowed for the duration of the PxRaycastCallback's lifetime!
    //      Uncommenting this line will cause a build error.
    // touch_buffer.clear();

    for position in &custom_hit_callbacks.positions {
        println!("position: {}, {}, {}", position.x(), position.y(), position.z());
    }

    if let Some(touches) = custom_hit.get_touching_hits() {
        for touch in touches {
            println!("touch position: {}, {}, {}", touch.position.x, touch.position.y, touch.position.z);
        }
    }

    if let Some(blocker) = custom_hit.get_blocking_hit() {
        println!("blocker position: {}, {}, {}", blocker.position.x, blocker.position.y, blocker.position.z);
    }

    custom_hit_callbacks.positions.clear();
    let did_ray_hit = scene.raycast(
        &origin.into(),
        &up_dir.into(),
        distance,
        &mut custom_hit,
        hit_flags,
        &filter_data,
        None,
        None,
    );
    assert!(!did_ray_hit); // raycast upward does not hit anything

    {
        let mut simple_hit_callback = PxRaycastCallback::<RaycastCallbackDefault>::new();

        let _did_ray_hit = scene.raycast(
            &origin.into(),
            &down_dir.into(),
            distance,
            &mut simple_hit_callback,
            hit_flags,
            &filter_data,
            None,
            None,
        );

        if let Some(blocker) = simple_hit_callback.get_blocking_hit() {
            println!("blocker position: {}, {}, {}", blocker.position.x, blocker.position.y, blocker.position.z);
        }
    }

    // Overlaps
    // TODO

    // Sweeps
    // TODO
}
