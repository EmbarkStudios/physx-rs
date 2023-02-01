use crate::Node;
use serde::Deserialize;
use std::borrow::Cow;

#[derive(Deserialize, Debug)]
pub struct DefinitionData {
    #[serde(default, rename = "isPOD")]
    is_pod: bool,
}

#[derive(Deserialize, Debug)]
#[serde(rename_all = "camelCase")]
pub struct Record {
    name: Option<String>,
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
    #[serde(rename = "type")]
    kind: Type,
}

#[derive(Deserialize, Debug)]
pub struct EnumConstDecl {
    name: String,
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
    /// The text part of a C++ comment
    TextComment { text: String },
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

struct EnumVariant<'ast> {
    /// The name of the variant
    name: &'ast str,
    /// The constant value of the variant
    value: i64,
    /// Text comment on the enum constant
    comment: Option<&'ast str>,
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

struct Comment<'ast> {
    /// This is the top line, we attempt to retrieve this if the comment is a
    /// doxygen `/brief` section
    summary: &'ast str,
    /// Additional information outside of the brief section, note that the content
    /// in this paragraph will be massaged so that doxygen style # references
    /// will be transformed into appropriate rustdoc intralinks
    additional: Option<String>,
}

impl<'ast> Comment<'ast> {
    fn emit_rust(&self, writer: &mut impl std::io::Write) -> anyhow::Result<()> {
        writeln!(writer, "/// {}", self.summary)?;

        if let Some(additional) = &self.additional {
            writeln!(writer, "///\n/// {}", additional)?;
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
        unreachable!()
    }

    fn consume_enum(&mut self, enum_node: &'ast Node) -> anyhow::Result<()> {
        let Item::EnumDecl(enum_decl) = &enum_node.kind else { anyhow::bail!("item is not an enum") };

        let comment = Self::get_comment(enum_node);

        let mut repr = EnumRepr::I32;
        //let mut variants = Vec::new();

        unreachable!()
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

        let mut summary = None;
        let mut additional = String::new();

        fn gather<'ast>(
            node: &'ast Node,
            name: Option<&str>,
            summary: &mut Option<&'ast str>,
            additional: &mut String,
        ) -> anyhow::Result<()> {
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
                    Item::TextComment { text } => {
                        let trimmed = text.trim();
                        if let Some("brief") = name {
                            anyhow::ensure!(
                                summary.is_none(),
                                "item has more than 1 /brief comment"
                            );
                            anyhow::ensure!(!trimmed.is_empty(), "/brief section is empty");

                            *summary = Some(trimmed);
                        } else if !trimmed.is_empty() {
                            if !additional.is_empty() {
                                additional.push('\n');
                            }
                            additional.push_str(trimmed);
                        }
                    }
                    _ => gather(inner, name, summary, additional)?,
                }
            }

            Ok(())
        }

        if let Err(err) = gather(full_comment, None, &mut summary, &mut additional) {
            eprintln!("Failed to gather comment for {:?}: {err:#}", node.kind);
            return None;
        }

        if summary.is_none() && additional.is_empty() {
            return None;
        }

        let comment = Comment {
            summary: summary.unwrap(),
            additional: (!additional.is_empty()).then(|| {
                // PhysX _tends_ to use `#type::field/variant` style intralinks
                // so attempt to convert them to proper rustdoc style intralinks
                if additional.contains('#') {
                    let mut fixed = String::new();
                    let mut cursor = 0;

                    while let Some(ind) = additional[cursor..].find('#') {
                        if ind > cursor {
                            fixed.push_str(&additional[cursor..ind]);
                        }

                        let remainder = &additional[cursor + ind + 1..];

                        match remainder.find(char::is_whitespace) {
                            Some(end) => {
                                fixed.push_str("[`");
                                fixed.push_str(&remainder[..end]);
                                fixed.push_str("`]");

                                cursor += end;
                            }
                            None => {
                                fixed.push_str("[`");
                                fixed.push_str(remainder);
                                fixed.push_str("`]");
                                break;
                            }
                        }
                    }

                    fixed
                } else {
                    additional
                }
            }),
        };

        Some(comment)
    }

    pub fn generate_rust_enums(&self, writer: &mut impl std::io::Write) -> anyhow::Result<u32> {
        let comment = "#[derive(Copy, Clone)]";

        for enum_binding in &self.enums {
            if let Some(com) = &enum_binding.comment {
                com.emit_rust(writer)?;
            }
        }

        Ok(self.enums.len() as u32)
    }
}
