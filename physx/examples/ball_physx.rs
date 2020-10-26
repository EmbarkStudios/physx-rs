// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created:  3 July 2019

//use physx::prelude::*;
use physx::{
    geometry::{SphereGeometry, PxSphereGeometry},
    math::{PxVec3, PxTransform},
    physics::PhysicsFoundation,
    rigid_actor::RigidActor,
    rigid_body::RigidBody,
    scene::{SceneFlag, SceneDescriptor},
};

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
    // The type parameters are for shape and material usier data, which
    // isn't used in this demo, so set it to (). If the never-type feature
    // is enabled, that is an even better choice.
    let mut physics_foundation = PhysicsFoundation::<(), ()>::default();
    let physics = physics_foundation.physics.as_mut();

    // Scene has a rather lengthy generics list since it has to tracksall the user data types.
    let mut scene = physics.create_scene(
        SceneDescriptor {
            // Default::default() turns on active actors but this very simple demo doesn't use it.
            scene_flags: SceneFlag::EnablePcm.into(),
            ..Default::default()
        }
        // This is purely for demonstration. User data is not read by PhysX,
        // and is packed directly into the *mut c_void field if possible.
        // Reading user data should be const-propped, so this ends up being
        // free!  One upside of this is storing bevy Entity IDs (or other component
        // ID type) is super efficient and can be read back by callbacks.
        .set_actor_user_data_types::<usize>()
        .rigid_dynamic_type::<f64>()
    ).unwrap();

    // The user_data field here is () since that's what was set when PhysicsFoundation was created.
    let mut material = physics.create_material(
        0.5,
        0.5,
        0.6,
        ()
    ).unwrap();

    // Here, the user_data type is usize because of the earlier call to set_actor_user_data_types
    let ground_plane = physics.create_plane(
        PxVec3::new(0.0, 1.0, 0.0),
        0.0,
        material.as_mut(),
        0
    ).unwrap();

    scene.add_static_actor(ground_plane);

    let sphere_geo = PxSphereGeometry::new(10.0);

    // Here, user data is a float!
    let mut sphere_actor = physics.create_rigid_dynamic(
        PxTransform::from_translation(&PxVec3::new(0.0, 40.0, 100.0)),
        &sphere_geo,
        material.as_mut(),
        10.0,
        PxTransform::default(),
        0.0
    ).unwrap();

    sphere_actor.set_angular_damping(0.5);
    scene.add_dynamic_actor(sphere_actor);

    // Updating
    let heights_over_time = (0..100)
        .map(|_| {
            // Calls both update and fetch_results.  More complex simulation update
            // controls are not currently supported.
            scene.step(
                0.1,
                None::<&mut physx_sys::PxBaseTask>,
                Some(
                    // Scratch needs to be align(16), 16K blocks (and an actual type defined for it)
                    Box::new([[(0,0); 1024]; 2]).as_mut()
                ),
                true
            ).expect("error occured during simulation");
            // For simplicity, just read out the only dynamic actor in the scene.
            // getActiveActors is also supported, it returns a Vec<ActorMap> that has
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
