use crate::consumer::{Builtin, EnumBinding};

use super::Indent;

/// Fixes enum variant names from the ugly C++ style of `eWHY_ARE_YOU_SHOUTING`
/// to `WhyAreYouShouting`
fn fix_variant_name(s: &str) -> String {
    let no_e = s
        .strip_prefix('e')
        .filter(|s| s.chars().next().unwrap().is_ascii_alphabetic())
        .unwrap_or(s);

    use heck::ToUpperCamelCase;
    no_e.to_upper_camel_case()
}

impl<'ast> EnumBinding<'ast> {
    pub fn emit_rust(&self, w: &mut String, level: u32) {
        if let Some(com) = &self.comment {
            com.emit_rust(w, level);
        }

        let indent = Indent(level);
        let indent1 = Indent(level + 1);
        writesln!(w, "{indent}#[derive(Debug, Clone, Copy, PartialEq, Eq)]");
        writesln!(w, "{indent}#[repr({})]", self.repr.rust_type());
        writesln!(w, "{indent}pub enum {} {{", self.name);

        for var in &self.variants {
            if let Some(com) = &var.comment {
                com.emit_rust(w, level + 1);
            }

            writesln!(
                w,
                "{indent1}{} = {},",
                fix_variant_name(var.name),
                var.value
            );
        }

        writesln!(w, "{indent}}}");
    }

    pub fn emit_rust_conversion(&self, w: &mut String, level: u32, from: Builtin, default: &str) {
        let indent = Indent(level);
        let indent1 = Indent(level + 1);
        let indent2 = Indent(level + 2);

        let int_type = from.rust_type();

        writesln!(w, "{indent}impl From<{int_type}> for {} {{", self.name);
        writesln!(w, "{indent1}fn from(val: {int_type}) -> Self {{");
        writesln!(w, "{indent2}#[allow(clippy::match_same_arms)]");
        writesln!(w, "{indent2}match val {{");

        let indentm = Indent(level + 3);

        for var in &self.variants {
            writesln!(
                w,
                "{indentm}{} => Self::{},",
                var.value,
                fix_variant_name(var.name)
            );
        }

        writesln!(w, "{indentm}_ => Self::{default},");
        writesln!(w, "{indent2}}}");
        writesln!(w, "{indent1}}}");
        writesln!(w, "{indent}}}");
    }
}

impl<'ast> crate::consumer::FlagsBinding<'ast> {
    pub fn emit_rust(&self, enum_binding: &EnumBinding<'ast>, w: &mut String, level: u32) {
        let indent = Indent(level);
        let indent1 = Indent(level + 1);
        let indent2 = Indent(level + 2);
        writesln!(w, "{indent}bitflags::bitflags! {{");
        writesln!(w, "{indent1}/// Flags for [`{}`]", enum_binding.name);
        writesln!(w, "{indent1}#[derive(Default)]");
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

            writes!(w, "{indent2}const {} = ", fix_variant_name(var.name));

            // Since bitflags are made up of power of 2 values that can
            // be combined, and the PhysX API sometimes defines named
            // combinations of flags, reconstruct the bitflags to be
            // easier to read
            let val = var.value as u64;
            if val & (val - 1) == 0 {
                writes!(w, "1 << {}", val.ilog2());
            } else {
                let mut is_combo = false;
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
                    is_combo = true;
                    if i > 0 {
                        writes!(w, " | ");
                    }

                    writes!(w, "Self::{}.bits", fix_variant_name(which));
                }

                // There are a couple of cases where they're not combos, so just
                // emit the raw value
                if !is_combo {
                    writes!(w, "0x{val:08x}");
                }
            }

            writesln!(w, ";");
        }

        writesln!(w, "{indent1}}}\n{indent}}}");
    }
}
