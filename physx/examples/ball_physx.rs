use nalgebra_glm as glm;
use physx::prelude::*;

const PX_PHYSICS_VERSION: u32 = (4 << 24) + (1 << 16);

fn main() {
    let mut foundation = Foundation::new(PX_PHYSICS_VERSION);

    let mut physics = PhysicsBuilder::default()
        .load_extensions(false)
        .build(&mut foundation);

    let mut scene = physics.create_scene(
        SceneBuilder::default()
            .set_gravity(glm::vec3(0.0, -9.81, 0.0))
            .set_simulation_threading(SimulationThreadType::Dedicated(1)),
    );

    let material = physics.create_material(0.5, 0.5, 0.6);
    let ground_plane = physics.create_plane(glm::vec3(0.0, 1.0, 0.0), 0.0, material);
    scene.add_actor(ground_plane);

    let sphere_geo = PhysicsGeometry::from(&ColliderDesc::Sphere(10.0));
    let mut sphere_actor = physics.create_dynamic(
        glm::translation(&glm::vec3(0.0, 40.0, 100.0)),
        sphere_geo.as_raw(), // todo: this should take the PhysicsGeometry straight.
        material,
        10.0,
        glm::Mat4::identity(),
    );

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
            scene
                .get_rigid_actor_unchecked(&sphere_handle)
                .get_global_position()
                .y as i32
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

    scene.release();
    drop(physics); // todo: this looks weird...
    foundation.release();
}
