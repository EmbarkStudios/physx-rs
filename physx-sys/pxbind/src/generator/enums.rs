use super::Indent;

impl<'ast> crate::consumer::EnumBinding<'ast> {
    pub fn emit_rust(&self, w: &mut String, level: u32) {
        if let Some(com) = &self.comment {
            com.emit_rust(w, level);
        }

        let indent = Indent(level);
        let indent1 = Indent(level + 1);
        writesln!(w, "{indent}#[derive(Copy, Clone)]");
        writesln!(w, "{indent}#[repr({})]", self.repr);
        writesln!(w, "{indent}pub enum {} {{", self.name);

        for var in &self.variants {
            if let Some(com) = &var.comment {
                com.emit_rust(w, level + 1);
            }

            writesln!(w, "{indent1}{} = {},", var.name, var.value);
        }

        writesln!(w, "{indent}}}");
    }
}

impl<'ast> crate::consumer::FlagsBinding<'ast> {
    pub fn emit_rust(
        &self,
        enum_binding: &crate::consumer::EnumBinding<'ast>,
        w: &mut String,
        level: u32,
    ) {
        let indent = Indent(level);
        let indent1 = Indent(level + 1);
        let indent2 = Indent(level + 2);
        writesln!(w, "{indent}bitflags::bitflags! {{");
        writesln!(w, "{indent1}/// Flags for [`{}`]", enum_binding.name);
        writesln!(w, "{indent1}#[derive(Copy, Clone, Default)]");
        writesln!(w, "{indent1}#[repr(transparent)]");
        writesln!(
            w,
            "{indent1}pub struct {}: {} {{",
            self.name,
            self.storage_type.rust_type()
        );

        for var in &enum_binding.variants {
            // If used as flags, ignore emitting any zero value, see
            // https://docs.rs/bitflags/1.3.2/bitflags/#zero-flags
            if var.value == 0 {
                continue;
            }

            // if let Some(com) = &var.comment {
            //     com.emit_rust(writer, level + 2)?;
            // }

            writes!(w, "{indent2}const {} = ", var.name);

            // Since bitflags are made up of power of 2 values that can
            // be combined, and the PhysX API sometimes defines named
            // combinations of flags, reconstruct the bitflags to be
            // easier to read
            let val = var.value as u64;
            if val & (val - 1) == 0 {
                writes!(w, "1 << {}", val.ilog2());
            } else {
                // If we're not a power of 2, we're a combination of flags,
                // find which ones and emit them in a friendly way
                for (i, which) in enum_binding
                    .variants
                    .iter()
                    .filter_map(|var| {
                        let prev = var.value as u64;
                        (prev & (prev - 1) == 0 && (prev & val) != 0).then_some(var.name)
                    })
                    .enumerate()
                {
                    if i > 0 {
                        writes!(w, " | ");
                    }

                    writes!(w, "Self::{which}.bits");
                }
            }

            writesln!(w, ";");
        }

        writesln!(w, "{indent1}}}\n{indent}}}");
    }
}
