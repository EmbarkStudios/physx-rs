mod record;
use anyhow::Context as _;
use record::RecBinding;
pub use record::{Access, Constructor, Method, Record};
mod enums;
use clang_ast::Id;
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
    type_alias_decl_id: Option<Id>,
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
pub struct Typedef {
    name: String,
    #[serde(rename = "type")]
    kind: Type,
    id: Id,
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
    TypedefDecl(Typedef),
    /// The deprecated declspec has been defined on the item (PX_DEPRECATED)
    DeprecatedAttr,
    /// We don't care about other items
    Other {
        kind: clang_ast::Kind,
        name: Option<String>,
    },
}

impl Item {
    #[inline]
    fn as_method(&self) -> Option<&Method> {
        let meth = match self {
            Self::CXXMethodDecl(meth) => meth,
            Self::CXXConstructorDecl(ctor) => &ctor.inner,
            Self::CXXDestructorDecl(dtor) => dtor,
            _ => return None,
        };

        Some(meth)
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
    classes: HashMap<&'ast str, (&'ast Node, &'ast Record)>,
    back_refs: HashMap<Id, &'ast Node>,
}

impl<'ast> AstConsumer<'ast> {
    pub fn consume(&mut self, root: &'ast Node) -> anyhow::Result<()> {
        self.traverse(root)
    }

    fn traverse(&mut self, node: &'ast Node) -> anyhow::Result<()> {
        if self.is_ignored(node) {
            println!("skipping node");
            return Ok(());
        }

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
                Item::TypedefDecl(td) => {
                    self.consume_typedef(inn, td)?;
                }
                _ => {
                    self.traverse(inn)?;
                }
            }
        }

        Ok(())
    }

    #[inline]
    fn is_ignored(&self, node: &'ast Node) -> bool {
        // Check to see if the node has the deprecated attribute, if so we can
        // ignore emitting it. This can get rid of entire types, so we need to
        // account for that when traversing the graph to emit types and functions
        node.inner
            .iter()
            .any(|inn| matches!(inn.kind, Item::DeprecatedAttr))

        // TODO: Maybe ignore some more types here
        //false
    }

    fn consume_typedef(&mut self, node: &'ast Node, td: &Typedef) -> anyhow::Result<()> {
        self.back_refs.insert(td.id, node);
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

    fn parse_type(&self, kind: &AstType<'_>) -> anyhow::Result<QualType> {
        // Builtin types are the most common, we already handle the common typydefs as well
        if let Some(bi) = self.parse_builtin(kind) {
            return Ok(QualType::Builtin(bi));
        }

        // First check if the type has an alias, most likely a typedef
        if let AstType::Qualified(kind) = kind {
            if let Some(alias_id) = kind.type_alias_decl_id {
                let node = self
                    .back_refs
                    .get(&alias_id)
                    .context("failed to located type alias")?;
            }
        }

        let type_str = kind.as_ref();

        if let Some(ptr) = type_str.strip_suffix('*') {
        } else if let Some(refer) = type_str.strip_suffix('&') {
        } else if let Some(array) = type_str.strip_suffix(']') {
            let ind = array
                .find('[')
                .context("uhm...we thought this was an array...")?;

            let ele_type = AstType::Simple(&array[..ind]);
            let ele_type = self
                .parse_type(&ele_type)
                .context("failed to parse element type")?;

            let len = &array[ind + 1..]
                .parse()
                .context("failed to parse array length")?;

            return Ok(QualType::Array {
                element: Box::new(ele_type),
                len,
            });
        }
    }

    fn parse_builtin(&self, kind: &AstType<'_>) -> Option<Builtin> {
        let bi = match kind.as_ref() {
            // See PxSimpleTypes for where the physx typedefs come from
            "bool" => Builtin::Bool,
            "float" | "physx::PxReal" | "physx::PxF32" => Builtin::Float,
            "double" => Builtin::Double,
            "int8_t" | "char" | "physx::PxI8" => Builtin::Char,
            "uint8_t" | "unsigned char" | "physx::PxU8" => Builtin::UChar,
            "int16_t" | "short" | "physx::PxI16" => Builtin::Short,
            "uint16_t" | "unsigned short" | "physx::PxU16" => Builtin::UShort,
            "int32_t" | "int" | "physx::PxI32" => Builtin::Int,
            "uint32_t" | "unsigned int" | "physx::PxU32" => Builtin::UInt,
            // Signed 64-bit integers are essentially unused in Physx
            "int64_t" | "long" | "physx::PxI64" => Builtin::Long,
            "uint64_t" | "unsigned long" | "physx::PxU64" => Builtin::ULong,
            // See PxVecMath.h for the vector types
            "physx::Vec3V" => Builtin::Vec3V,
            "physx::Vec4V" => Builtin::Vec4V,
            "physx::BoolV" => Builtin::BoolV,
            "physx::VecU32V" => Builtin::U32V,
            "physx::VecI32V" => Builtin::I32V,
            "physx::Mat33V" => Builtin::Mat33V,
            "physx::Mat34V" => Builtin::Mat34V,
            "physx::Mat44V" => Builtin::Mat44V,
            _ => return None,
        };

        Some(bi)
    }
}

enum AstType<'ast> {
    Simple(&'ast str),
    Qualified(&'ast Type),
}

impl<'ast> AsRef<str> for AstType<'ast> {
    fn as_ref(&self) -> &str {
        match self {
            Self::Simple(s) => s,
            Self::Qualified(kind) => &kind.qual_type,
        }
    }
}

enum Builtin {
    Bool,
    Float,
    Double,
    Char,
    UChar,
    Short,
    UShort,
    Int,
    UInt,
    Long,
    ULong,
    Vec3V,
    Vec4V,
    BoolV,
    U32V,
    I32V,
    Mat33V,
    Mat34V,
    Mat44V,
}

enum QualType<'ast> {
    Pointer {
        is_pointee_const: bool,
        pointee: Box<QualType<'ast>>,
    },
    Reference {
        is_pointee_const: bool,
        pointee: Box<QualType<'ast>>,
    },
    Builtin(Builtin),
    FunctionPointer,
    Array {
        element: Box<QualType<'ast>>,
        len: u32,
    },
    Enum {
        name: &'ast str,
        repr: EnumRepr,
        /// If the enum is used for flags we need to represent it on the FFI
        /// boundary as the scalar type
        is_flags: bool,
    },
}
