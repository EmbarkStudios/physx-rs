// Author: Nick Caplinger <the.nick.caplinger@gmail.com>
// Copyright © 2020, Embark Studios, all rights reserved.
// Created:  8 December 2020

use glam::Vec3;
use physx::prelude::*;
use physx::query::{
    OverlapCallback, PxOverlapBuffer, PxQueryFilterData, PxRaycastBuffer, PxSweepBuffer,
    RaycastCallback, SweepCallback,
};
use physx::scene::HitFlag;
use std::ffi::c_void;

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

struct MyRaycastCallback;

unsafe impl RaycastCallback for MyRaycastCallback {
    unsafe fn new() -> Self {
        Self {}
    }

    unsafe fn get_raycast_hit(&mut self) -> Option<physx_sys::PxRaycastHit> {
        None
    }

    unsafe extern "C" fn process_touches(
        _buffer: *const physx_sys::PxRaycastHit,
        _num_hits: u32,
        _user_data: *const c_void,
    ) -> bool {
        println!("custom process_touches logic happens here");
        false
    }

    /// # Safety
    /// Must not panic.
    unsafe extern "C" fn finalize_query(_user_data: *const c_void) {
        println!("custom finalize_query logic happens here");
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
    unsafe {
        // Raycasts
        let mut hit = PxRaycastBuffer::new();
        let hit_flags = HitFlag::default_hit_flags();
        let filter_data = PxQueryFilterData::default();

        let mut custom_hit = MyRaycastCallback::new();

        let did_ray_hit = scene.raycast(
            &origin.into(),
            &down_dir.into(),
            distance,
            &mut hit,
            hit_flags,
            &filter_data,
            None,
            None,
        );
        assert!(did_ray_hit); // hits dynamic sphere in scene

        // Let's see some info about the hit
        let hit_info = hit.get_raycast_hit().unwrap();
        dbg!(hit_info.distance);
        // dbg!(PxVec3::from(hit_info.position));
        // dbg!(PxVec3::from(hit_info.normal));

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

        let did_ray_hit = scene.raycast(
            &origin.into(),
            &up_dir.into(),
            distance,
            &mut hit,
            hit_flags,
            &filter_data,
            None,
            None,
        );
        assert!(!did_ray_hit); // raycast upward does not hit anything

        // Overlaps
        let mut overlap_callback = PxOverlapBuffer::new();
        let did_overlap = scene.overlap(
            &sphere_geo,
            &PxTransform::default(),
            &mut overlap_callback,
            &filter_data,
            None,
        );
        assert!(did_overlap); // overlaps with ground plane

        let did_overlap = scene.overlap(
            &sphere_geo,
            &PxTransform::from_translation(&Vec3::new(0.0, 30.0, 0.0).into()),
            &mut overlap_callback,
            &filter_data,
            None,
        );
        assert!(!did_overlap); // midair sphere overlaps with nothing

        let mut sweep_callback = PxSweepBuffer::new();
        let did_sweep_hit = scene.sweep(
            &sphere_geo,
            &PxTransform::from_translation(&Vec3::new(0.0, 30.0, 0.0).into()),
            &down_dir.into(),
            60.0,
            &mut sweep_callback,
            hit_flags,
            &filter_data,
            None,
            None,
            0.0,
        );
        assert!(did_sweep_hit); // sweeping through the plane should hit

        let did_sweep_hit = scene.sweep(
            &sphere_geo,
            &PxTransform::from_translation(&Vec3::new(0.0, 30.0, 0.0).into()),
            &up_dir.into(),
            60.0,
            &mut sweep_callback,
            hit_flags,
            &filter_data,
            None,
            None,
            0.0,
        );
        assert!(!did_sweep_hit); // sweeping upward should not hit anything
    }
}
