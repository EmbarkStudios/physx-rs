fn main() -> anyhow::Result<()> {
    // This is the root API include that includes all the other public
    // APIs
    let node = pxbind::get_ast("physx-sys/physx/physx/include/PxPhysicsAPI.h")?;

    // // Luckily PhysX is fairly consistent, all public structs and classes are
    // // prefixed with `Px`, so we just use that to determine which records we
    // // want to add bindings for. We could also just check to see if it's part
    // // of the `physx` namespace.
    // let mut pods = 0;
    // let mut total = 0;
    // let mut unique = std::collections::HashSet::<&str>::new();

    // fn print<'n>(
    //     node: &'n Node,
    //     unique: &mut std::collections::HashSet<&'n str>,
    //     pods: &mut u32,
    //     total: &mut u32,
    // ) {
    //     for record in node.inner.iter().filter_map(|inn| {
    //         if let Item::CXXRecordDecl(rec) = &inn.kind {
    //             Some(rec)
    //         } else {
    //             None
    //         }
    //     }) {
    //         let Some(name) = record.name.as_deref().filter(|n| n.starts_with("Px")) else { continue };

    //         if !unique.insert(name) {
    //             continue;
    //         }

    //         *total += 1;

    //         if record
    //             .definition_data
    //             .as_ref()
    //             .map_or(false, |dd| dd.is_pod)
    //         {
    //             *pods += 1;
    //             println!("generate_pod!(\"physx::{name}\")");
    //         } else {
    //             println!("generate!(\"physx::{name}\")");
    //         }
    //     }

    //     for node in &node.inner {
    //         print(node, unique, pods, total);
    //     }
    // }

    // print(&node, &mut unique, &mut pods, &mut total);

    // println!("--- Summary ---");
    // println!("PODs: {pods} NonPODs: {}", total - pods);

    Ok(())
}
