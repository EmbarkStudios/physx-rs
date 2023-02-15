use crate::Node;

use serde::Deserialize;

mod record;
use anyhow::Context as _;
pub use record::{Access, Constructor, Method, RecBinding, Record, Tag};
mod enums;
use clang_ast::Id;
pub use enums::{EnumBinding, FlagsBinding};
pub mod functions;
pub use functions::{FuncBinding, PhysxInvoke};

#[derive(Deserialize, Debug)]
#[serde(rename_all = "camelCase")]
pub struct Type {
    desugured_qual_type: Option<String>,
    qual_type: String,
    type_alias_decl_id: Option<Id>,
}

#[derive(Deserialize, Debug)]
pub struct EnumDecl {
    name: Option<String>,
}

#[derive(Deserialize, Debug)]
pub struct EnumConstDecl {
    name: String,
    #[serde(rename = "type")]
    kind: Type,
}

#[derive(Deserialize, Debug)]
pub struct Param {
    name: Option<String>,
    #[serde(rename = "type")]
    kind: Type,
}

#[derive(Deserialize, Debug)]
pub struct Typedef {
    name: String,
    #[serde(rename = "type")]
    kind: Type,
    id: Option<Id>,
}

#[derive(Deserialize, Debug)]
pub struct Decl {
    id: Id,
    kind: clang_ast::Kind,
    name: String,
}

#[derive(Deserialize, Debug)]
pub enum Item {
    NamespaceDecl {
        name: Option<String>,
    },
    /// Declarations for classes and structs
    CXXRecordDecl(Record),
    FieldDecl {
        name: Option<String>,
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
    TemplateSpecializationType {
        #[serde(rename = "templateName")]
        template_name: String,
    },
    TemplateArgument {
        #[serde(rename = "type")]
        kind: Option<Type>,
        value: Option<i32>,
    },
    RecordType {
        #[serde(rename = "type")]
        kind: Type,
        decl: Decl,
    },
    ClassTemplateDecl,
    ClassTemplateSpecializationDecl(Record),
    TypedefDecl(Typedef),
    /// The deprecated declspec has been defined on the item (PX_DEPRECATED)
    DeprecatedAttr,
    /// We don't care about other items
    Other {
        kind: Option<clang_ast::Kind>,
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
pub struct Block<'ast> {
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
    pub fn as_slice(&self) -> &[&'ast str] {
        self.b.as_slice()
    }

    #[inline]
    pub fn is_empty(&self) -> bool {
        self.b.is_empty()
    }
}

pub fn search<'ast, T>(
    node: &'ast Node,
    f: &impl Fn(&'ast Node) -> Option<&'ast T>,
) -> Option<(&'ast Node, &'ast T)> {
    if let Some(t) = f(node) {
        return Some((node, t));
    }

    for inn in &node.inner {
        if let Some(t) = search(inn, f) {
            return Some(t);
        }
    }

    None
}

pub struct Comment<'ast> {
    /// This is the top line, we attempt to retrieve this if the comment is a
    /// doxygen `/brief` section
    pub summary: Block<'ast>,
    /// Additional information outside of the brief section, note that the content
    /// in this paragraph will be massaged so that doxygen style # references
    /// will be transformed into appropriate rustdoc intralinks
    pub additional: Block<'ast>,
}

use std::collections::HashMap;

#[derive(Default)]
pub struct AstConsumer<'ast> {
    pub enums: Vec<EnumBinding<'ast>>,
    pub enum_map: HashMap<&'ast str, (Builtin, &'ast str)>,
    pub flags: Vec<FlagsBinding<'ast>>,
    pub flags_map: HashMap<&'ast str, Builtin>,
    pub type_defs: HashMap<&'ast str, QualType<'ast>>,
    pub recs: Vec<RecBinding<'ast>>,
    pub funcs: Vec<FuncBinding<'ast>>,
    /// Mapping of class names -> node & record so we can check hierarchies
    /// for `release` methods, or whether something is a record at all
    pub classes: HashMap<&'ast str, (&'ast Node, &'ast Record)>,
    pub back_refs: HashMap<Id, &'ast Node>,
}

impl<'ast> AstConsumer<'ast> {
    pub fn consume(&mut self, root: &'ast Node) -> anyhow::Result<()> {
        self.traverse(root, root, false)
    }

    fn traverse(
        &mut self,
        node: &'ast Node,
        root: &'ast Node,
        in_physx: bool,
    ) -> anyhow::Result<()> {
        if self.is_ignored(node) {
            println!("skipping node");
            return Ok(());
        }

        for inn in &node.inner {
            match &inn.kind {
                Item::NamespaceDecl { name } => {
                    if in_physx || name.as_deref() == Some("physx") {
                        self.traverse(inn, root, true)?;
                    }
                }
                Item::EnumDecl(decl) => {
                    self.consume_enum(node, inn, decl)?;
                }
                Item::CXXRecordDecl(rec) => {
                    // If a record decl doesn't have any inner nodes, it's just a foreward declaration
                    // and we can skip it
                    if inn.inner.is_empty() {
                        continue;
                    }

                    if !in_physx {
                        continue;
                    }

                    self.consume_record(inn, rec, root)
                        .with_context(|| format!("failed to consume {rec:?}"))?;
                }
                Item::TypedefDecl(td) => {
                    self.consume_typedef(inn, td, root)?;
                }
                Item::ClassTemplateDecl => {}
                _ => {
                    self.traverse(inn, root, in_physx)?;
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

    fn consume_typedef(
        &mut self,
        node: &'ast Node,
        td: &'ast Typedef,
        root: &'ast Node,
    ) -> anyhow::Result<()> {
        if let Some(id) = td.id {
            self.back_refs.insert(id, node);
        }

        if self.type_defs.contains_key(&td.name.as_str()) {
            return Ok(());
        }

        if td.kind.qual_type.starts_with("PxFlags<") {
            self.consume_flags(node, td)?;
        } else if let Some(tid) = self.is_template_we_care_about(node, td) {
            self.consume_template(node, td, tid, root)?;
        } else if let Ok(qt) = self.parse_type(&td.kind) {
            self.type_defs.insert(&td.name, qt);
        }

        Ok(())
    }

    /// Walks the AST of a node and attempts to retrieve a comment for it
    fn get_comment(node: &Node) -> Option<Comment<'_>> {
        let full_comment = node.inner.iter().find(|inner| {
            matches!(
                inner.kind,
                Item::Other {
                    kind: Some(clang_ast::Kind::FullComment),
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

    fn parse_type(&self, kind: impl Into<AstType<'ast>>) -> anyhow::Result<QualType<'ast>> {
        let kind = kind.into();

        // Builtin types are the most common, we already handle the common typydefs as well
        if let Some(bi) = self.parse_builtin(kind) {
            return Ok(QualType::Builtin(bi));
        }

        // First check if the type has an alias, most likely a typedef
        if let AstType::Qualified(kind) = &kind {
            if let Some(alias_id) = kind.type_alias_decl_id {
                // let node = self
                //     .back_refs
                //     .get(&alias_id)

                //     .context("failed to locate type alias")?;
            }
        }

        let type_str = kind.as_str();

        // There's probably a smarter way to do this, but ugh, C++ pointers are so
        // dumb
        fn parse_ptr(inner: &str) -> (&str, bool) {
            if inner.contains('*') {
                if let Some(s) = inner.strip_suffix("const ") {
                    (s, true)
                } else {
                    (inner, false)
                }
            } else {
                if let Some(s) = inner.strip_prefix("const ") {
                    (s, true)
                } else {
                    (inner, false)
                }
            }
        }

        if let Some(ptr) = type_str.strip_suffix('*') {
            let (inner, is_const) = parse_ptr(ptr);

            let pointee = self.parse_type(inner.trim())?;

            return Ok(QualType::Pointer {
                is_const,
                pointee: Box::new(pointee),
            });
        } else if let Some(refer) = type_str.strip_suffix('&') {
            let (inner, is_const) = parse_ptr(refer);

            let pointee = self.parse_type(inner.trim())?;

            return Ok(QualType::Reference {
                is_const,
                pointee: Box::new(pointee),
            });
        } else if let Some(array) = type_str.strip_suffix(']') {
            let ind = array
                .find('[')
                .context("uhm...we thought this was an array...")?;

            let ele_type = self
                .parse_type(&array[..ind])
                .context("failed to parse element type")?;

            let len = array[ind + 1..]
                .parse()
                .context("failed to parse array length")?;

            return Ok(QualType::Array {
                element: Box::new(ele_type),
                len,
            });
        }

        // Check if it's an enum, we'll always know the enum by the time we hit
        // a reference to it, since physx doesn't do forward declaration of
        // enums, just old school
        if let Some((repr, name)) = self.enum_map.get(type_str) {
            return Ok(QualType::Enum {
                name,
                cxx_qt: type_str,
                repr: *repr,
            });
        } else if let Some(name) = type_str.strip_prefix("physx::") {
            let qt = if let Some((repr, name)) = self.enum_map.get(name) {
                QualType::Enum {
                    name,
                    cxx_qt: name,
                    repr: *repr,
                }
            } else if let Some(repr) = self.flags_map.get(name) {
                QualType::Flags { name, repr: *repr }
            } else if let Some(qt) = self.type_defs.get(name) {
                qt.clone()
            } else {
                QualType::Record { name }
            };

            Ok(qt)
        } else {
            Ok(QualType::Enum {
                name: "OHNO",
                cxx_qt: "OHNOCPP",
                repr: Builtin::UInt,
            })
        }

        //anyhow::bail!("oops {kind:?}")
    }

    fn parse_builtin(&self, kind: impl Into<AstType<'ast>>) -> Option<Builtin> {
        let bi = match kind.into().as_str() {
            "void" => Builtin::Void,
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
            math if math.contains("aos::") => {
                let mt = &math[math.rfind(':').unwrap() + 1..];

                match mt {
                    "Vec3V" => Builtin::Vec3V,
                    "Vec3" => Builtin::Vec3,
                    "Vec4V" => Builtin::Vec4V,
                    "Vec4" => Builtin::Vec4,
                    "BoolV" => Builtin::BoolV,
                    "VecU32V" => Builtin::U32V,
                    "VecI32V" => Builtin::I32V,
                    "Mat33V" => Builtin::Mat33V,
                    "Mat34V" => Builtin::Mat34V,
                    "Mat44V" => Builtin::Mat44V,
                    _ => return None,
                }
            }
            _ => return None,
        };

        Some(bi)
    }
}

#[derive(Copy, Clone, Debug)]
enum AstType<'ast> {
    Simple(&'ast str),
    Qualified(&'ast Type),
}

impl<'ast> From<&'ast Type> for AstType<'ast> {
    fn from(t: &'ast Type) -> Self {
        Self::Qualified(t)
    }
}

impl<'ast> From<&'ast str> for AstType<'ast> {
    fn from(t: &'ast str) -> Self {
        Self::Simple(t)
    }
}

impl<'ast> AstType<'ast> {
    fn as_str(&self) -> &'ast str {
        let ty = match self {
            Self::Simple(s) => s,
            Self::Qualified(kind) => kind.qual_type.as_str(),
        };

        // If the type is _not_ a pointer or reference, strip any const prefix
        // since it's useless and just makes parsing easier
        if !ty.contains('*') && !ty.contains('&') {
            if let Some(stripped) = ty.strip_prefix("const ") {
                return stripped;
            }
        }

        ty
    }
}

#[derive(Copy, Clone, Debug)]
pub enum Builtin {
    Void,
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
    // SIMD
    Vec3V,
    QuatV,
    Vec4V,
    BoolV,
    U32V,
    I32V,
    Mat33V,
    Mat34V,
    Mat44V,
    // Non-SIMD
    Vec3,
    Vec3p,
    Vec4,
    Quat,
    Mat33,
    Mat34,
    Mat44,
}

impl Builtin {
    #[inline]
    pub fn rust_type(self) -> &'static str {
        match self {
            Self::Void => "std::ffi::c_void",
            Self::Bool => "bool",
            Self::Float => "f32",
            Self::Double => "f64",
            Self::Char => "std::ffi::c_char",
            Self::UChar => "u8",
            Self::Short => "i16",
            Self::UShort => "u16",
            Self::Int => "i32",
            Self::UInt => "u32",
            Self::Long => "i64",
            Self::ULong => "u64",
            Self::Vec3V => "glam::Vec3A",
            Self::Vec3 => "glam::Vec3",
            Self::Vec3p => "Vec3p",
            Self::Vec4V | Self::Vec4 => "glam::Vec4",
            Self::QuatV | Self::Quat => "glam::Quat",
            Self::BoolV => "glam::BVec4A",
            Self::U32V => "glam::UVec4",
            Self::I32V => "glam::IVec4",
            Self::Mat33V => "glam::Mat3A",
            Self::Mat33 => "glam::Mat3",
            Self::Mat34V => "glam::Affine3A",
            Self::Mat34 => "Affine",
            Self::Mat44V | Self::Mat44 => "glam::Mat4",
        }
    }

    #[inline]
    pub fn c_type(self) -> &'static str {
        match self {
            Self::Void => "void",
            Self::Bool => "bool",
            Self::Float => "float",
            Self::Double => "double",
            Self::Char => "char",
            Self::UChar => "uint8_t",
            Self::Short => "int16_t",
            Self::UShort => "uint16_t",
            Self::Int => "int32_t",
            Self::UInt => "uint32_t",
            Self::Long => "int64_t",
            Self::ULong => "uint64_t",
            Self::Vec3V => "Vec3V",
            Self::Vec3 => "Vec3",
            Self::Vec3p => "Vec3p",
            Self::Vec4V => "Vec4V",
            Self::Vec4 => "Vec4",
            Self::QuatV => "QuatV",
            Self::Quat => "Quat",
            Self::BoolV => "BoolV",
            Self::U32V => "VecU32V",
            Self::I32V => "VecI32V",
            Self::Mat33V => "Mat33V",
            Self::Mat33 => "Mat33",
            Self::Mat34V => "Mat34V",
            Self::Mat34 => "Mat34",
            Self::Mat44V => "Mat44V",
            Self::Mat44 => "Mat44",
        }
    }

    #[inline]
    pub fn cpp_type(self) -> &'static str {
        match self {
            Self::Void => "void",
            Self::Bool => "bool",
            Self::Float => "float",
            Self::Double => "double",
            Self::Char => "char",
            Self::UChar => "uint8_t",
            Self::Short => "int16_t",
            Self::UShort => "uint16_t",
            Self::Int => "int32_t",
            Self::UInt => "uint32_t",
            Self::Long => "int64_t",
            Self::ULong => "uint64_t",
            Self::Vec3V => "physx::Vec3V",
            Self::Vec3 => "physx::Vec3",
            Self::Vec3p => "physx::Vec3p",
            Self::Vec4V => "physx::Vec4V",
            Self::Vec4 => "physx::Vec4",
            Self::QuatV => "physx::QuatV",
            Self::Quat => "physx::Quat",
            Self::BoolV => "physx::BoolV",
            Self::U32V => "physx::VecU32V",
            Self::I32V => "physx::VecI32V",
            Self::Mat33V => "physx::Mat33V",
            Self::Mat33 => "physx::Mat33",
            Self::Mat34V => "physx::Mat34V",
            Self::Mat34 => "physx::Mat34",
            Self::Mat44V => "physx::Mat44V",
            Self::Mat44 => "physx::Mat44",
        }
    }

    #[inline]
    fn is_pod(self) -> bool {
        !matches!(
            self,
            Self::Void
                | Self::Bool
                | Self::Float
                | Self::Double
                | Self::Char
                | Self::UChar
                | Self::Short
                | Self::UShort
                | Self::Int
                | Self::UInt
                | Self::Long
                | Self::ULong
        )
    }
}

#[derive(Debug, Clone)]
pub enum QualType<'ast> {
    Pointer {
        is_const: bool,
        pointee: Box<QualType<'ast>>,
    },
    Reference {
        is_const: bool,
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
        cxx_qt: &'ast str,
        repr: Builtin,
    },
    Flags {
        name: &'ast str,
        repr: Builtin,
    },
    Record {
        name: &'ast str,
    },
}

use std::fmt;

#[derive(Copy, Clone)]
pub struct RustType<'qt, 'ast>(&'qt QualType<'ast>);

impl<'qt, 'ast> fmt::Display for RustType<'qt, 'ast> {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self.0 {
            QualType::Pointer { is_const, pointee } => {
                write!(f, "*{} ", if *is_const { "const" } else { "mut" })?;
                write!(f, "{}", pointee.rust_type())
            }
            QualType::Reference { is_const, pointee } => {
                write!(f, "*{} ", if *is_const { "const" } else { "mut" })?;
                write!(f, "{}", pointee.rust_type())
            }
            QualType::Builtin(bi) => f.write_str(bi.rust_type()),
            QualType::FunctionPointer => f.write_str("*mut std::ffi::c_void"),
            QualType::Array { element, len } => {
                write!(f, "[{}; {len}]", element.rust_type())
            }
            QualType::Enum { name, .. } => f.write_str(name),
            QualType::Flags { name, .. } => f.write_str(name),
            QualType::Record { name } => write!(f, "physx_{name}_Pod"),
        }
    }
}

#[derive(Copy, Clone)]
pub struct CppType<'qt, 'ast>(&'qt QualType<'ast>);

impl<'qt, 'ast> fmt::Display for CppType<'qt, 'ast> {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self.0 {
            QualType::Pointer { is_const, pointee } => {
                write!(f, "{}", pointee.cpp_type())?;
                write!(f, "{}*", if *is_const { " const" } else { "" })
            }
            QualType::Reference { is_const, pointee } => {
                write!(f, "{}", pointee.cpp_type())?;
                write!(f, "{}&", if *is_const { " const" } else { "" })
            }
            QualType::Builtin(bi) => f.write_str(bi.cpp_type()),
            QualType::FunctionPointer => f.write_str("void *"),
            QualType::Array { element, len } => {
                write!(f, "{}[{len}]", element.cpp_type())
            }
            QualType::Enum { cxx_qt: name, .. }
            | QualType::Flags { name, .. }
            | QualType::Record { name } => write!(f, "physx::{name}"),
        }
    }
}

#[derive(Copy, Clone)]
pub struct CType<'qt, 'ast>(&'qt QualType<'ast>);

impl<'qt, 'ast> fmt::Display for CType<'qt, 'ast> {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self.0 {
            QualType::Pointer { is_const, pointee } | QualType::Reference { is_const, pointee } => {
                write!(f, "{}", pointee.c_type())?;
                write!(f, "{}*", if *is_const { " const" } else { "" })
            }
            QualType::Builtin(bi) => f.write_str(bi.c_type()),
            QualType::FunctionPointer => f.write_str("void *"),
            QualType::Array { element, len } => {
                write!(f, "{}[{len}]", element.c_type())
            }
            QualType::Enum { repr, .. } => f.write_str(repr.c_type()),
            QualType::Flags { repr, .. } => f.write_str(repr.c_type()),
            QualType::Record { name } => write!(f, "physx_{name}_Pod"),
        }
    }
}

impl<'ast> QualType<'ast> {
    #[inline]
    pub fn rust_type(&self) -> RustType<'_, 'ast> {
        RustType(self)
    }

    #[inline]
    pub fn cpp_type(&self) -> CppType<'_, 'ast> {
        CppType(self)
    }

    #[inline]
    pub fn c_type(&self) -> CType<'_, 'ast> {
        CType(self)
    }

    #[inline]
    pub fn is_pod(&self) -> bool {
        match self {
            QualType::Pointer { pointee, .. } => pointee.is_pod(),
            QualType::Reference { pointee, .. } => pointee.is_pod(),
            QualType::Builtin(bi) => bi.is_pod(),
            QualType::FunctionPointer => false,
            QualType::Array { element, .. } => element.is_pod(),
            QualType::Enum { .. } => true,
            QualType::Flags { .. } => true,
            QualType::Record { .. } => true,
        }
    }
}
