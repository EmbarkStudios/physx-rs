use physx::{base::RefCounted, prelude::*};

type PxMaterial = physx::material::PxMaterial<()>;
type PxShape = physx::shape::PxShape<(), PxMaterial>;

#[test]
fn test_double_free() {
    let mut physics = PhysicsFoundation::<_, PxShape>::default();

    let mut material = physics.create_material(0.5, 0.5, 0.6, ()).unwrap();
    let geometry = PxBoxGeometry::new(1., 1., 1.);
    let flags =
        ShapeFlags::SceneQueryShape | ShapeFlags::SimulationShape | ShapeFlags::Visualization;

    let shape = physics
        .create_shape(&geometry, &mut [&mut material], false, flags, ())
        .unwrap();

    assert_eq!(material.get_reference_count(), 2);
    drop(shape);

    assert_eq!(material.get_reference_count(), 1);
    drop(material);
}
