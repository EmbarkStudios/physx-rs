#[macro_export]
macro_rules! writes {
    ($s:expr, $f:expr $(,)?) => {{
        use std::fmt::Write;
        write!($s, $f).unwrap();
    }};
    ($s:expr, $f:expr, $($arg:tt)*) => {{
        use std::fmt::Write;
        write!($s, $f, $($arg)*).unwrap();
    }};
}

#[macro_export]
macro_rules! writesln {
    ($s:expr) => {{
        use std::fmt::Write;
        writeln!($s).unwrap();
    }};
    ($s:expr, $f:expr $(,)?) => {{
        use std::fmt::Write;
        writeln!($s, $f).unwrap();
    }};
    ($s:expr, $f:expr, $($arg:tt)*) => {{
        use std::fmt::Write;
        writeln!($s, $f, $($arg)*).unwrap();
    }};
}

mod comment;
mod record;

use crate::consumer::AstConsumer;
use std::{fmt, io::Write};

/// The variable name of `PodStructGen` in the structgen program
const SG: &str = "sg";
/// The name of the macro used to calculate a field's offset in the structgen program
const UOF: &str = "unsafe_offsetof";

/// It's impossible (I believe) with Rust's format strings to have the width
/// of the alignment be dynamic, so we just uhhh...be lame
struct Indent(u32);

impl fmt::Display for Indent {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        for _ in 0..self.0 {
            f.write_str("    ")?;
        }

        Ok(())
    }
}

pub struct Generator {}

impl Generator {
    pub fn generate_all(
        &self,
        ast: &AstConsumer<'_>,
        structgen: &mut impl Write,
        cpp: &mut impl Write,
        rust: &mut impl Write,
    ) -> anyhow::Result<()> {
        self.generate_structgen(ast, structgen)?;

        Ok(())
    }

    pub fn generate_structgen(
        &self,
        ast: &AstConsumer<'_>,
        out: &mut impl Write,
    ) -> anyhow::Result<()> {
        // Write the preamble
        {
            writeln!(out, "// Automatically generated by pxbind")?;
            writeln!(out, r#"#include "PxPhysicsAPI.h""#)?;
            writeln!(out, "\nusing namespace physx;")?;
            writeln!(
                out,
                "\n#define {UOF}(st, m) ((size_t) ( (char *)&((st *)(0))->m - (char *)0 ))"
            )?;
            writeln!(out, r#"#include "structgen.hpp""#)?;
            writeln!(out, "\nint main() {{")?;
        }

        let indent = Indent(1);
        writeln!(out, "{indent}PodStructGen {SG};")?;

        let mut acc = String::new();
        for rec in &ast.recs {
            acc.clear();
            rec.emit_structgen(&mut acc, 1);
            writeln!(out, "{acc}")?;
        }

        writeln!(out, "{indent}{SG}.finish();\n}}")?;

        Ok(())
    }

    pub fn generate_rust_enums(
        &self,
        ast: &AstConsumer<'_>,
        writer: &mut impl Write,
        level: u32,
    ) -> anyhow::Result<u32> {
        let indent = Indent(level);
        let indent2 = Indent(level + 1);
        let indent3 = Indent(level + 2);
        let enum_derive = "#[derive(Copy, Clone)]";
        let flags_derive = "#[derive(Copy, Clone, Default)]";

        let mut fiter = ast.flags.iter().peekable();
        let mut acc = String::new();

        for (i, enum_binding) in ast.enums.iter().enumerate() {
            acc.clear();

            if i > 0 {
                writesln!(acc);
            }

            if let Some(com) = &enum_binding.comment {
                com.emit_rust(&mut acc, level);
            }

            let is_flags_enum = fiter.peek().map_or(false, |f| f.enums_index == i);

            writesln!(acc, "{indent}{enum_derive}");
            writesln!(acc, "{indent}#[repr({})]", enum_binding.repr);
            writesln!(acc, "{indent}pub enum {} {{", enum_binding.name);

            for var in &enum_binding.variants {
                if let Some(com) = &var.comment {
                    com.emit_rust(&mut acc, level + 1);
                }

                writesln!(acc, "{indent2}{} = {},", var.name, var.value);
            }

            writesln!(acc, "{indent}}}");

            if is_flags_enum {
                let flags = fiter.next().unwrap();

                writesln!(acc);
                writesln!(acc, "{indent}bitflags::bitflags! {{");
                writesln!(acc, "{indent2}/// Flags for [`{}`]", enum_binding.name);
                writesln!(acc, "{indent2}{flags_derive}");
                writesln!(acc, "{indent2}#[repr(transparent)]");
                writesln!(
                    acc,
                    "{indent2}pub struct {}: {} {{",
                    flags.name,
                    flags.storage_type.rust_type()
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

                    writes!(acc, "{indent3}const {} = ", var.name);

                    // Since bitflags are made up of power of 2 values that can
                    // be combined, and the PhysX API sometimes defines named
                    // combinations of flags, reconstruct the bitflags to be
                    // easier to read
                    let val = var.value as u64;
                    if val & (val - 1) == 0 {
                        writes!(acc, "1 << {}", val.ilog2());
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
                                writes!(acc, " | ");
                            }

                            writes!(acc, "Self::{which}.bits");
                        }
                    }

                    writesln!(acc, ";");
                }

                writesln!(acc, "{indent2}}}");
                writesln!(acc, "{indent}}}");
            }

            write!(writer, "{acc}")?;
        }

        Ok((ast.enums.len() + ast.flags.len()) as u32)
    }
}
