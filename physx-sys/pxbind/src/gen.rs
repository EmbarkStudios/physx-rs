use crate::Node;
use anyhow::Context as _;
use serde::Deserialize;
use std::fmt;

#[derive(Deserialize, Debug)]
pub struct DefinitionData {
    #[serde(default, rename = "isPOD")]
    is_pod: bool,
}

#[derive(Deserialize, Debug)]
#[serde(rename_all = "camelCase")]
pub struct Record {
    name: String,
    definition_data: Option<DefinitionData>,
}

#[derive(Deserialize, Debug)]
#[serde(rename_all = "camelCase")]
pub struct Type {
    qual_type: String,
}

#[derive(Deserialize, Debug)]
pub struct EnumDecl {
    name: String,
    // #[serde(rename = "type")]
    // kind: Type,
}

#[derive(Deserialize, Debug)]
pub struct EnumConstDecl {
    name: String,
    #[serde(rename = "type")]
    kind: Type,
}

#[derive(Deserialize, Debug)]
pub enum Item {
    /// Declarations for classes and structs
    CXXRecordDecl(Record),
    /// Enums
    EnumDecl(EnumDecl),
    /// Enum variants
    EnumConstantDecl(EnumConstDecl),
    BlockCommandComment {
        /// PhysX uses doxygen, so this will often be "brief", which in Rust
        /// terms means we place the _next_ `TextComment::text` as the top line
        /// for the item, and then any _other_ comments as separate
        name: Option<String>,
    },
    ParagraphComment,
    /// The text part of a C++ comment
    TextComment {
        text: String,
    },
    ImplicitCastExpr {
        #[serde(rename = "type")]
        kind: Type,
    },
    ConstantExpr {
        value: String,
        #[serde(rename = "type")]
        kind: Type,
    },
    /// We don't care about other items
    Other {
        kind: clang_ast::Kind,
        name: Option<String>,
    },
}

#[derive(Copy, Clone)]
enum EnumRepr {
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

struct EnumBinding<'ast> {
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

#[derive(Default)]
struct Block<'ast> {
    b: Vec<&'ast str>,
}

impl<'ast> Block<'ast> {
    #[inline]
    fn push(&mut self, line: &'ast str) {
        self.b.push(line);
    }

    #[inline]
    fn merge(&mut self, next: Block<'ast>) {
        if next.is_empty() {
            return;
        }

        if !self.b.is_empty() {
            self.push("");
        }

        for line in next.b {
            self.b.push(line);
        }
    }

    #[inline]
    fn as_slice(&self) -> &[&'ast str] {
        self.b.as_slice()
    }

    #[inline]
    fn is_empty(&self) -> bool {
        self.b.is_empty()
    }
}

struct Comment<'ast> {
    /// This is the top line, we attempt to retrieve this if the comment is a
    /// doxygen `/brief` section
    summary: Block<'ast>,
    /// Additional information outside of the brief section, note that the content
    /// in this paragraph will be massaged so that doxygen style # references
    /// will be transformed into appropriate rustdoc intralinks
    additional: Block<'ast>,
}

impl<'ast> Comment<'ast> {
    fn emit_rust<W: std::io::Write>(&self, writer: &mut W, level: u32) -> anyhow::Result<()> {
        // It's impossible (I believe) with Rust's format strings to have the width
        // of the alignment be dynamic, so we just uhhh...be lame
        struct Indent(u32);

        impl fmt::Display for Indent {
            fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
                for _ in 0..self.0 {
                    f.write_str("    ")?;
                }

                Ok(())
            }
        }

        let indent = Indent(level);

        let emit_lines = |w: &mut W, lines: &[&str]| -> anyhow::Result<()> {
            for line in lines {
                if line.is_empty() {
                    writeln!(w, "{indent}///")?;
                // PhysX _tends_ to use `#type::field/variant` style intralinks
                // so attempt to convert them to proper rustdoc style intralinks
                } else if let Some(ind) = line.find('#') {
                    write!(w, "{indent}/// {}", &line[..ind])?;
                    write!(w, "[`")?;
                    match line[ind + 1..]
                        .find(|c: char| !c.is_alphanumeric() && c != ':' && c != '_')
                    {
                        Some(end) => {
                            write!(w, "{}`]", &line[ind + 1..ind + end + 1])?;
                            writeln!(w, "{}", &line[ind + end + 1..])?;
                        }
                        None => {
                            writeln!(w, "{}`]", &line[ind + 1..])?;
                        }
                    };
                } else {
                    writeln!(w, "{indent}/// {line}")?;
                }
            }

            Ok(())
        };

        emit_lines(writer, self.summary.as_slice())?;

        if !self.additional.is_empty() {
            writeln!(writer, "{indent}///")?;
            emit_lines(writer, self.additional.as_slice())?;
        }

        Ok(())
    }
}

#[derive(Default)]
pub struct AstConsumer<'ast> {
    enums: Vec<EnumBinding<'ast>>,
}

impl<'ast> AstConsumer<'ast> {
    pub fn consume(&mut self, root: &'ast Node) -> anyhow::Result<()> {
        self.traverse(root)
    }

    fn traverse(&mut self, node: &'ast Node) -> anyhow::Result<()> {
        for inn in &node.inner {
            match &inn.kind {
                Item::EnumDecl(decl) => {
                    let enum_binding = self.consume_enum(node, inn, decl)?;
                    self.enums.push(enum_binding);
                }
                _ => {
                    self.traverse(inn)?;
                }
            }
        }

        Ok(())
    }

    fn consume_enum(
        &mut self,
        parent: &'ast Node,
        enum_node: &'ast Node,
        enum_decl: &'ast EnumDecl,
    ) -> anyhow::Result<EnumBinding<'ast>> {
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

        Ok(EnumBinding {
            repr,
            name,
            cxx_qt,
            comment,
            variants,
        })
    }

    /// Walks the AST of a node and attempts to retrieve a comment for it
    fn get_comment(node: &Node) -> Option<Comment<'_>> {
        let full_comment = node.inner.iter().find(|inner| {
            matches!(
                inner.kind,
                Item::Other {
                    kind: clang_ast::Kind::FullComment,
                    name: _,
                }
            )
        })?;

        fn gather<'ast>(
            node: &'ast Node,
            name: Option<&str>,
            summary: &mut Block<'ast>,
            additional: &mut Block<'ast>,
        ) -> anyhow::Result<()> {
            fn gather_paragraph<'ast>(node: &'ast Node) -> Block<'ast> {
                let mut block = Block::default();

                for inner in &node.inner {
                    if let Item::TextComment { text } = &inner.kind {
                        let trimmed = text.trim();

                        if trimmed.is_empty() {
                            continue;
                        } else {
                            block.push(trimmed);
                        }
                    }
                }

                block
            }

            for inner in &node.inner {
                match &inner.kind {
                    Item::BlockCommandComment { name } => {
                        // @see comments are just filled with C++ junk that would
                        // take more effort than it is worth to translate to intralinks,
                        // so we just skip them instead
                        if name.as_deref() == Some("see") {
                            continue;
                        }

                        gather(inner, name.as_deref(), summary, additional)?;
                    }
                    Item::ParagraphComment => {
                        let para = gather_paragraph(inner);

                        if summary.is_empty() {
                            *summary = para;
                        } else {
                            additional.merge(para);
                        }
                    }
                    _ => continue,
                }
            }

            Ok(())
        }

        let mut summary = Block::default();
        let mut additional = Block::default();

        if let Err(err) = gather(full_comment, None, &mut summary, &mut additional) {
            eprintln!("Failed to gather comment for {:?}: {err:#}", node.kind);
            return None;
        }

        if summary.is_empty() && additional.is_empty() {
            return None;
        }

        Some(Comment {
            summary,
            additional,
        })
    }

    pub fn generate_rust_enums(&self, writer: &mut impl std::io::Write) -> anyhow::Result<u32> {
        let comment = "#[derive(Copy, Clone)]";

        for (i, enum_binding) in self.enums.iter().enumerate() {
            if i > 0 {
                writeln!(writer)?;
            }

            if let Some(com) = &enum_binding.comment {
                com.emit_rust(writer, 0)?;
            }

            writeln!(writer, "{comment}")?;
            writeln!(writer, "#[repr({})]", enum_binding.repr)?;
            writeln!(writer, "pub enum {} {{", enum_binding.name)?;

            for var in &enum_binding.variants {
                if let Some(com) = &var.comment {
                    com.emit_rust(writer, 1)?;
                }

                writeln!(writer, "    {} = {},", var.name, var.value)?;
            }

            writeln!(writer, "}}")?;
        }

        Ok(self.enums.len() as u32)
    }
}
