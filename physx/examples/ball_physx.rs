// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created:  3 July 2019

use glam::{Mat4, Vec3};
use physx::prelude::*;

const PX_PHYSICS_VERSION: u32 = physx::version(4, 1, 1);

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

fn main() {
    let mut foundation = Foundation::new(PX_PHYSICS_VERSION);

    let mut physics = PhysicsBuilder::default()
        .load_extensions(false)
        .build(&mut foundation);

    let mut scene = physics.create_scene(
        SceneBuilder::default()
            .set_gravity(Vec3::new(0.0, -9.81, 0.0))
            .set_simulation_threading(SimulationThreadType::Dedicated(1)),
    );

    let material = physics.create_material(0.5, 0.5, 0.6);
    let ground_plane = unsafe { physics.create_plane(Vec3::new(0.0, 1.0, 0.0), 0.0, material) };
    scene.add_actor(ground_plane);

    let sphere_geo = PhysicsGeometry::from(&ColliderDesc::Sphere(10.0));
    let mut sphere_actor = unsafe {
        physics.create_dynamic(
            Mat4::from_translation(Vec3::new(0.0, 40.0, 100.0)),
            sphere_geo.as_raw(), // todo: this should take the PhysicsGeometry straight.
            material,
            10.0,
            Mat4::identity(),
        )
    };

    sphere_actor.set_angular_damping(0.5);
    let sphere_handle = scene.add_dynamic(sphere_actor);

    let heights_over_time = (0..100)
        .map(|_| {
            scene.simulate(0.1);
            scene
                .fetch_results(true)
                .expect("error occured during simulation");

            // in this case, we know the sphere still exists and is a
            // RigidActor-type so we can use the unchecked API
            unsafe { scene.get_rigid_actor_unchecked(&sphere_handle) }
                .get_global_position()
                .y() as i32
                - 10
        })
        .collect::<Vec<_>>();

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

    unsafe {
        scene.release();
    }

    drop(physics);

    foundation.release();
}
