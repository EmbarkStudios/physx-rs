use physx_sys::*;
use std::ptr::null_mut;

fn main() {
    #[allow(unsafe_code)]
    // SAFETY: It works...but is it safe? :D
    unsafe {
        let foundation = physx_create_foundation();
        let physics = physx_create_physics(foundation);

        let mut scene_desc = PxSceneDesc_new(PxPhysics_getTolerancesScale(physics));
        scene_desc.gravity = PxVec3 {
            x: 0.0,
            y: -9.81,
            z: 0.0,
        };

        let dispatcher = phys_PxDefaultCpuDispatcherCreate(
            1,
            null_mut(),
            PxDefaultCpuDispatcherWaitForWorkMode::WaitForWork,
            0,
        );
        scene_desc.cpuDispatcher = dispatcher.cast();
        scene_desc.filterShader = get_default_simulation_filter_shader();

        let scene = PxPhysics_createScene_mut(physics, &scene_desc);

        let material = PxPhysics_createMaterial_mut(physics, 0.5, 0.5, 0.6);
        let ground_plane =
            phys_PxCreatePlane(physics, &PxPlane_new_1(0.0, 1.0, 0.0, 0.0), material);
        PxScene_addActor_mut(scene, ground_plane.cast(), null_mut());

        let sphere_geo = PxSphereGeometry_new(10.0);
        let sphere = phys_PxCreateDynamic(
            physics,
            &PxTransform_new_1(&PxVec3 {
                x: 0.0,
                y: 40.0,
                z: 100.0,
            }),
            (&sphere_geo as *const PxSphereGeometry).cast(),
            material,
            10.0,
            &PxTransform_new_2(PxIDENTITY::PxIdentity),
        );
        PxRigidBody_setAngularDamping_mut(sphere.cast(), 0.5);
        PxScene_addActor_mut(scene, sphere.cast(), null_mut());

        let filter_data = PxQueryFilterData_new();
        let mut raycast_hits = Vec::new();

        let heights_over_time = (0..100)
            .map(|_| {
                PxScene_simulate_mut(scene, 0.1, null_mut(), null_mut(), 0, true);
                let mut error: u32 = 0;
                PxScene_fetchResults_mut(scene, true, &mut error);
                assert!(error == 0, "fetchResults has failed");

                let mut hit = std::mem::MaybeUninit::uninit();

                if physx_sys::PxSceneQueryExt_raycastSingle(
                    scene,
                    &PxVec3 {
                        x: 0.0,
                        y: 100.0,
                        z: 100.0,
                    }, // origin
                    &PxVec3 {
                        x: 0.0,
                        y: -1.0,
                        z: 0.0,
                    }, // dir
                    1000.0, // max distance
                    PxHitFlags::Default,
                    hit.as_mut_ptr(),
                    &filter_data,
                    null_mut(),
                    null_mut(),
                ) {
                    let hit = hit.assume_init();
                    raycast_hits.push(hit);
                }

                let pose = PxRigidActor_getGlobalPose(sphere.cast());
                (pose.p.y) as i32 - 10
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
            .for_each(|line| {
                println!("{line}");
            });
        PxScene_release_mut(scene);
        PxDefaultCpuDispatcher_release_mut(dispatcher);
        PxPhysics_release_mut(physics);

        for hit in raycast_hits {
            eprintln!("Raycast hit object {:.02}m away", hit.distance);
        }
    }
}
