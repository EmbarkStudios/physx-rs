mod record;
use record::RecBinding;
pub use record::{Access, Constructor, Method, Record};
mod enums;
use enums::{EnumBinding, EnumRepr};

use crate::Node;

use serde::Deserialize;
use std::fmt;

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

#[derive(Deserialize, Debug)]
#[serde(rename_all = "camelCase")]
pub struct Type {
    desugured_qual_type: Option<String>,
    qual_type: String,
    type_alias_decl_id: Option<u64>,
}

#[derive(Deserialize, Debug)]
pub struct EnumDecl {
    name: String,
}

#[derive(Deserialize, Debug)]
pub struct EnumConstDecl {
    name: String,
    #[serde(rename = "type")]
    kind: Type,
}

#[derive(Deserialize, Debug)]
pub struct Param {
    name: String,
    #[serde(rename = "type")]
    kind: Type,
}

#[derive(Deserialize, Debug)]
pub enum Item {
    /// Declarations for classes and structs
    CXXRecordDecl(Record),
    FieldDecl {
        name: String,
        #[serde(rename = "type")]
        kind: Type,
    },
    CXXMethodDecl(Method),
    CXXConstructorDecl(Constructor),
    CXXDestructorDecl(Method),
    ParmVarDecl(Param),
    /// Enums
    EnumDecl(EnumDecl),
    /// Enum variants
    EnumConstantDecl(EnumConstDecl),
    /// Access, eg public/protected/private
    AccessSpecDecl {
        access: Access,
    },
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

impl Item {
    #[inline]
    fn is_method(&self) -> bool {
        matches!(
            self,
            Self::CXXMethodDecl(_) | Self::CXXConstructorDecl(_) | Self::CXXDestructorDecl(_)
        )
    }
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

use std::collections::HashMap;

#[derive(Default)]
pub struct AstConsumer<'ast> {
    enums: Vec<EnumBinding<'ast>>,
    enum_map: HashMap<&'ast str, EnumRepr>,
    recs: Vec<RecBinding<'ast>>,
    /// Mapping of class names -> node & record so we can check hierarchies
    /// for `release` methods, or whether something is a record at all
    classes: std::collections::HashMap<&'ast str, (&'ast Node, &'ast Record)>,
}

impl<'ast> AstConsumer<'ast> {
    pub fn consume(&mut self, root: &'ast Node) -> anyhow::Result<()> {
        self.traverse(root)
    }

    fn traverse(&mut self, node: &'ast Node) -> anyhow::Result<()> {
        for inn in &node.inner {
            match &inn.kind {
                Item::EnumDecl(decl) => {
                    self.consume_enum(node, inn, decl)?;
                }
                Item::CXXRecordDecl(rec) => {
                    // If a record decl doesn't have any inner nodes, it's just a foreward declaration
                    // and we can skip it
                    if inn.inner.is_empty() {
                        continue;
                    }

                    if let Some(record) = self.consume_record(inn, rec)? {
                        self.recs.push(record);
                    }
                }
                _ => {
                    self.traverse(inn)?;
                }
            }
        }

        Ok(())
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
}
