use super::{Comment, EnumDecl, Indent, Item, Node};
use anyhow::Context as _;
use std::fmt;

#[derive(Copy, Clone)]
pub(super) enum EnumRepr {
    I32,
    U32,
}

impl fmt::Display for EnumRepr {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::I32 => f.write_str("i32"),
            Self::U32 => f.write_str("u32"),
        }
    }
}

impl std::str::FromStr for EnumRepr {
    type Err = anyhow::Error;

    fn from_str(s: &str) -> Result<Self, Self::Err> {
        match s {
            "unsigned int" => Ok(Self::U32),
            _ => anyhow::bail!("unknown enum repr {s}"),
        }
    }
}

struct EnumVariant<'ast> {
    /// The name of the variant
    name: &'ast str,
    /// The constant value of the variant
    value: i64,
    /// Text comment on the enum constant
    comment: Option<Comment<'ast>>,
}

pub(super) struct EnumBinding<'ast> {
    /// The repr() applied to the the Rust enum to get it the correct size
    repr: EnumRepr,
    /// The "friendly" name of the enum, eg `PxErrorCode`
    name: &'ast str,
    /// The qualified type of the enum, minus the physx:: namespace since all
    /// the c/cpp code we compile is done within that namespace, eg. PxErrorCode::Enum
    cxx_qt: &'ast str,
    /// Text comment on the enum (or more usually, the wrapping struct)
    comment: Option<Comment<'ast>>,
    /// The list of constants
    variants: Vec<EnumVariant<'ast>>,
}

impl<'ast> super::AstConsumer<'ast> {
    pub(super) fn consume_enum(
        &mut self,
        parent: &'ast Node,
        enum_node: &'ast Node,
        enum_decl: &'ast EnumDecl,
    ) -> anyhow::Result<()> {
        let comment = match Self::get_comment(enum_node) {
            Some(com) => Some(com),
            None => {
                // If the comment isn't directly on the enum itself, check if
                // the parent is a struct since most physx enums follow the classic
                // struct EnumName { enum Enum {}; }; pattern
                if matches!(parent.kind, Item::CXXRecordDecl(_)) {
                    Self::get_comment(parent)
                } else {
                    None
                }
            }
        };

        let name = if let Item::CXXRecordDecl(rec) = &parent.kind {
            &rec.name
        } else {
            &enum_decl.name
        };

        let mut repr = EnumRepr::I32;
        let mut variants = Vec::new();

        // Unfortunately the qualified type isn't present on the enum itself,
        // but rather each and every variant. They _should_ all be the same
        let mut cxx_qt = None;

        fn get_value(node: &Node, current: i64, repr: &mut EnumRepr) -> anyhow::Result<i64> {
            for inn in &node.inner {
                match &inn.kind {
                    Item::ImplicitCastExpr { kind } => {
                        *repr = kind.qual_type.parse()?;
                        return get_value(inn, current, repr);
                    }
                    Item::ConstantExpr { value, .. } => {
                        return value.parse().context("failed to parse enum constant");
                    }
                    _ => continue,
                }
            }

            Ok(current)
        }

        let mut current = 0;

        for (varn, vard) in enum_node.inner.iter().filter_map(|inn| {
            if let Item::EnumConstantDecl(cdecl) = &inn.kind {
                Some((inn, cdecl))
            } else {
                None
            }
        }) {
            let name = &vard.name;

            if let Some(cxx_qt) = cxx_qt {
                anyhow::ensure!(
                    cxx_qt == vard.kind.qual_type,
                    "enum has mismatching qualified types current: '{cxx_qt}', new: '{}'",
                    vard.kind.qual_type
                );
            } else {
                cxx_qt = Some(vard.kind.qual_type.as_str());
            }

            let comment = Self::get_comment(varn);
            let value = get_value(varn, current, &mut repr)?;
            current = value + 1;

            variants.push(EnumVariant {
                name,
                comment,
                value,
            });
        }

        // All cpp code is used within the physx namespace, so strip that prefix
        let cxx_qt =
            cxx_qt.with_context(|| format!("enum '{name}' never declared a qualified typename"))?;
        let cxx_qt = cxx_qt.strip_prefix("physx::").unwrap_or(cxx_qt);

        self.enums.push(EnumBinding {
            repr,
            name,
            cxx_qt,
            comment,
            variants,
        });
        self.enum_map.insert(cxx_qt, repr);

        Ok(())
    }

    pub fn generate_rust_enums(
        &self,
        writer: &mut impl std::io::Write,
        level: u32,
    ) -> anyhow::Result<u32> {
        let indent = Indent(level);
        let var_indent = Indent(level + 1);
        let derive = "#[derive(Copy, Clone)]";

        for (i, enum_binding) in self.enums.iter().enumerate() {
            if i > 0 {
                writeln!(writer)?;
            }

            if let Some(com) = &enum_binding.comment {
                com.emit_rust(writer, level)?;
            }

            writeln!(writer, "{indent}{derive}")?;
            writeln!(writer, "{indent}#[repr({})]", enum_binding.repr)?;
            writeln!(writer, "{indent}pub enum {} {{", enum_binding.name)?;

            for var in &enum_binding.variants {
                if let Some(com) = &var.comment {
                    com.emit_rust(writer, level + 1)?;
                }

                writeln!(writer, "{var_indent}{} = {},", var.name, var.value)?;
            }

            writeln!(writer, "{indent}}}")?;
        }

        Ok(self.enums.len() as u32)
    }
}
