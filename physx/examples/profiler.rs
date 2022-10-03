use physx::{physics::ProfilerCallback, prelude::*};
use std::ffi::CStr;

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

struct PrintProfilerCallback {
    start: std::time::Instant,
}

unsafe impl ProfilerCallback for PrintProfilerCallback {
    unsafe extern "C" fn zone_start(
        _name: *const i8,
        _detached: bool,
        _context_id: u64,
        user_data: *const std::ffi::c_void,
    ) -> *mut std::ffi::c_void {
        let this = &*(user_data as *const Self);
        let start = this.start.elapsed().as_micros() as u64;

        start as *mut std::ffi::c_void
    }

    unsafe extern "C" fn zone_end(
        context: *const std::ffi::c_void,
        name: *const i8,
        _detached: bool,
        _context_id: u64,
        user_data: *const std::ffi::c_void,
    ) {
        let name: &'static str = std::mem::transmute(CStr::from_ptr(name).to_str().unwrap());
        let this = &*(user_data as *const Self);
        let end = this.start.elapsed().as_micros() as u64;

        let start = context as u64;

        eprintln!("{name}: {:?}ms", (end - start) as f64 / 1000.0);
    }
}
fn main() {
    // Holds a PxFoundation and a PxPhysics.
    // Also has an optional Pvd and transport, not enabled by default.
    // The default allocator is the one provided by PhysX.
    let mut physics = PhysicsFoundation::<_, PxShape>::default();

    physics.set_profiler(PrintProfilerCallback {
        start: std::time::Instant::now(),
    });
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
        .create_plane(PxVec3::new(0.0, 1.0, 0.0), 0.0, material.as_mut(), ())
        .unwrap();
    // The scene owns actors that are added to it.  They can be retrieved using the
    // various getters on the scene.
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

    for _ in 0..100 {
        // Calls both simulate and fetch_results.  More complex simulation update
        // controls are not fully supported.
        scene
            .step(
                0.1,
                None::<&mut physx_sys::PxBaseTask>,
                Some(unsafe { &mut ScratchBuffer::new(4) }),
                true,
            )
            .expect("error occured during simulation");
    }
}
