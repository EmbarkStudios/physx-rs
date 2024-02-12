use crate::Node;

use serde::Deserialize;

mod record;
use anyhow::Context as _;
pub use record::*;
mod enums;
use clang_ast::Id;
pub use enums::{EnumBinding, FlagsBinding};
pub mod functions;
pub use functions::{FuncBinding, PhysxInvoke};
mod templates;
pub use templates::{Template, TemplateArg};

#[derive(Deserialize, Debug)]
#[serde(rename_all = "camelCase")]
pub struct Type {
    desugared_qual_type: Option<String>,
    qual_type: String,
    //type_alias_decl_id: Option<Id>,
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

// #[derive(Deserialize, Debug)]
// pub struct Decl {
//     id: Id,
//     kind: clang_ast::Kind,
//     name: String,
// }

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
    FunctionTemplateDecl,
    FunctionDecl(functions::Function),
    LinkageSpecDecl {
        language: String,
    },
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
        //decl: Decl,
    },
    ClassTemplateDecl {
        name: String,
    },
    TemplateTypeParmDecl {
        name: Option<String>,
    },
    NonTypeTemplateParmDecl {
        name: Option<String>,
        #[serde(rename = "type")]
        kind: Type,
    },
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

impl fmt::Display for Item {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::NamespaceDecl { name } => write!(f, "namespace '{name:?}'"),
            Self::CXXRecordDecl(rec) => {
                write!(f, "{} '{:?}'", rec.tag_used.unwrap_or(Tag::Class), rec.name)
            }
            Self::FieldDecl { name, .. } => write!(f, "field '{name:?}'"),
            Self::CXXMethodDecl(method) => write!(f, "method '{:?}'", method.name),
            Self::CXXConstructorDecl(ctor) => write!(f, "constructor '{:?}'", ctor.inner.name),
            Self::CXXDestructorDecl(dtor) => write!(f, "destructor '{:?}'", dtor.name),
            Self::EnumDecl(enm) => write!(f, "enum '{:?}'", enm.name),
            Self::FunctionDecl(fun) => write!(f, "function '{}'", fun.name),
            Self::TypedefDecl(td) => write!(f, "typedef '{}'", td.name),
            _ => write!(f, "{self:?}"),
        }
    }
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

pub struct ClassDef<'ast> {
    /// Index in `recs` where the binding is located
    pub index: usize,
    pub node: &'ast Node,
    pub rec: &'ast Record,
}

#[derive(Default)]
pub struct AstConsumer<'ast> {
    pub enums: Vec<EnumBinding<'ast>>,
    pub enum_map: HashMap<&'ast str, (Builtin, &'ast str)>,
    pub flags: Vec<FlagsBinding<'ast>>,
    pub flags_map: HashMap<&'ast str, Builtin>,
    pub type_defs: HashMap<&'ast str, QualType<'ast>>,
    pub recs: Vec<RecBinding<'ast>>,
    pub funcs: Vec<FuncBinding<'ast>>,
    func_map: HashMap<&'ast str, u8>,
    pub templates: HashMap<&'ast str, Template<'ast>>,
    /// Mapping of class names -> node & record so we can check hierarchies
    /// for `release` methods, or whether something is a record at all
    pub classes: HashMap<&'ast str, Option<ClassDef<'ast>>>,
    pub back_refs: HashMap<Id, &'ast Node>,
}

impl<'ast> AstConsumer<'ast> {
    pub fn consume(&mut self, root: &'ast Node) -> anyhow::Result<()> {
        self.traverse(root, root, false, false)
    }

    fn traverse(
        &mut self,
        node: &'ast Node,
        root: &'ast Node,
        in_physx: bool,
        in_c: bool,
    ) -> anyhow::Result<()> {
        for inn in &node.inner {
            if Self::is_deprecated(inn) {
                log::debug!("skipping deprecated node {}", inn.kind);
                continue;
            }

            #[allow(clippy::match_same_arms)]
            match &inn.kind {
                Item::NamespaceDecl { name } => {
                    if name.as_deref() == Some("physx") {
                        self.traverse(inn, root, true, false)?;
                    }
                }
                Item::EnumDecl(decl) if in_physx => {
                    self.consume_enum(node, inn, decl)?;
                }
                Item::CXXRecordDecl(rec) if in_physx => {
                    if !in_physx {
                        continue;
                    }

                    // If a record decl doesn't have any inner nodes, it's just
                    // a foreward declaration and we can skip it
                    if inn.inner.is_empty() || rec.definition_data.is_none() {
                        let Some(name) = rec.name.as_deref() else {
                            continue;
                        };

                        if !self.classes.contains_key(name) {
                            self.recs
                                .push(RecBinding::Forward(RecBindingForward { name }));
                            self.classes.insert(name, None);
                        }

                        continue;
                    }

                    self.consume_record(inn, rec)
                        .with_context(|| format!("failed to consume {rec:?}"))?;
                }
                Item::TypedefDecl(td) if in_physx => {
                    self.consume_typedef(inn, td, root)?;
                }
                Item::FunctionDecl(func) => {
                    if in_physx || (in_c && func.name.starts_with("Px")) {
                        self.consume_function(inn, func, &[], in_c)?;
                    }
                }
                Item::ClassTemplateDecl { .. } => {
                    //self.consume_template_decl(inn, name)?;
                }
                Item::FunctionTemplateDecl => {}
                Item::LinkageSpecDecl { language } if language == "C" => {
                    self.traverse(inn, root, in_physx, true)?;
                }
                _ => {
                    self.traverse(inn, root, in_physx, in_c)?;
                }
            }
        }

        Ok(())
    }

    /// Check to see if the node has the deprecated attribute, if so we can
    /// ignore emitting it.
    ///
    /// This can get rid of entire types, so we need to account for that when
    /// traversing the graph to emit types and functions
    #[inline]
    fn is_deprecated(node: &'ast Node) -> bool {
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

        if td.kind.qual_type.starts_with("physx::PxFlags<")
            || td.kind.qual_type.starts_with("PxFlags<")
        {
            self.consume_flags(node, td)?;
        } else if let Some(tid) = Self::is_template_we_care_about(node, td) {
            self.consume_template_typedef(node, td, tid, root)?;
        } else if td.name == "PxFileHandle" {
            self.type_defs.insert(
                &td.name,
                QualType::Pointer {
                    is_const: false,
                    is_pointee_const: false,
                    pointee: Box::new(QualType::Builtin(Builtin::Void)),
                },
            );
        } else if let Ok(qt) = self.parse_type(&td.kind, &[]) {
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
            _name: Option<&str>,
            summary: &mut Block<'ast>,
            additional: &mut Block<'ast>,
        ) -> anyhow::Result<()> {
            fn gather_paragraph(node: &Node) -> Block<'_> {
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
            log::warn!("Failed to gather comment for {:?}: {err:#}", node.kind);
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

    fn parse_type(
        &self,
        kind: impl Into<AstType<'ast>>,
        template_types: &[(&str, &TemplateArg<'ast>)],
    ) -> anyhow::Result<QualType<'ast>> {
        let kind = kind.into();

        let type_str = kind.as_str();

        if let Some(treplace) = template_types.iter().find_map(|(t, ty)| {
            if let (TemplateArg::Type(ty), true) = (ty, *t == type_str) {
                Some(ty)
            } else {
                None
            }
        }) {
            return Ok(treplace.clone());
        }

        // Builtin types are the most common, we already handle the common typedefs as well
        if let Some(bi) = Self::parse_builtin(type_str) {
            return Ok(QualType::Builtin(bi));
        }

        if type_str.contains("(*)") {
            return Ok(QualType::FunctionPointer);
        }

        if let AstType::Qualified(kind) = &kind {
            if let Some(qt) = &kind.desugared_qual_type {
                if qt.contains("(*)") {
                    return Ok(QualType::FunctionPointer);
                }
            }
        }

        // There's probably a smarter way to do this, but ugh, C++ pointers are so
        // dumb
        fn parse_ptr(inner: &str) -> (&str, bool) {
            if inner.contains('*') {
                if let Some(s) = inner.strip_suffix("const ") {
                    (s, true)
                } else {
                    (inner, false)
                }
            } else if let Some(s) = inner.strip_prefix("const ") {
                (s, true)
            } else {
                (inner, false)
            }
        }

        if let Some(ptr) = type_str.strip_suffix('*') {
            let (inner, is_pointee_const) = parse_ptr(ptr);

            let pointee = self.parse_type(inner.trim(), template_types)?;

            return Ok(QualType::Pointer {
                is_const: false,
                is_pointee_const,
                pointee: Box::new(pointee),
            });
        } else if let Some(ptr) = type_str.strip_suffix("*const") {
            let (inner, is_pointee_const) = parse_ptr(ptr);

            let pointee = self.parse_type(inner.trim(), template_types)?;

            return Ok(QualType::Pointer {
                is_const: true,
                is_pointee_const,
                pointee: Box::new(pointee),
            });
        } else if let Some(refer) = type_str.strip_suffix('&') {
            let (inner, is_const) = parse_ptr(refer);

            let pointee = self.parse_type(inner.trim(), template_types)?;

            return Ok(QualType::Reference {
                is_const,
                pointee: Box::new(pointee),
            });
        } else if let Some(array) = type_str.strip_suffix(']') {
            let ind = array.rfind('[').context("found a closing ']' but no '['")?;

            let ele_type = self
                .parse_type(&array[..ind], template_types)
                .context("failed to parse element type")?;

            let element = Box::new(ele_type);

            let arr_len = &array[ind + 1..];

            let len = if let Some(len) = template_types.iter().find_map(|(tn, ta)| {
                if let (TemplateArg::Value(val), true) = (ta, *tn == arr_len) {
                    Some(*val)
                } else {
                    None
                }
            }) {
                len
            } else {
                arr_len.parse().context("failed to parse array length")?
            };

            return Ok(QualType::Array { element, len });
        }

        // Check if it's an enum, we'll always know the enum by the time we hit
        // a reference to it, since physx doesn't do forward declaration of
        // enums, just old school
        if let Some((repr, name)) = self.enum_map.get(type_str) {
            Ok(QualType::Enum {
                name,
                cxx_qt: type_str,
                repr: *repr,
            })
        } else if let Some(name) = type_str.strip_prefix("physx::") {
            let qt = if let Some((repr, unqualified)) = self.enum_map.get(name) {
                QualType::Enum {
                    name: unqualified,
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
        } else if let Some(name) = type_str.strip_prefix("union ") {
            Ok(QualType::Record { name })
        } else if let Some(name) = type_str.strip_prefix("struct ") {
            Ok(QualType::Record { name })
        } else {
            anyhow::bail!("Unknown type '{kind:?}'");
        }
    }

    fn parse_builtin(kind: impl Into<AstType<'ast>>) -> Option<Builtin> {
        let name = kind.into().as_str();
        let name = no_physx(name);
        let bi = match name {
            "void" => Builtin::Void,
            // See PxSimpleTypes for where the physx typedefs come from
            "bool" => Builtin::Bool,
            "float" | "PxReal" | "PxF32" => Builtin::Float,
            "double" => Builtin::Double,
            "int8_t" | "char" | "PxI8" => Builtin::Char,
            "uint8_t" | "unsigned char" | "PxU8" => Builtin::UChar,
            "int16_t" | "short" | "PxI16" => Builtin::Short,
            "uint16_t" | "unsigned short" | "PxU16" => Builtin::UShort,
            "int32_t" | "int" | "PxI32" => Builtin::Int,
            "uint32_t" | "unsigned int" | "PxU32" => Builtin::UInt,
            // Signed 64-bit integers are essentially unused in Physx
            "int64_t" | "long" | "PxI64" => Builtin::Long,
            "uint64_t" | "unsigned long" | "PxU64" => Builtin::ULong,
            "size_t" => Builtin::USize,
            "PxVec3" => Builtin::Vec3,
            "PxVec4" => Builtin::Vec4,
            "PxMat33" => Builtin::Mat33,
            "PxMat44" => Builtin::Mat44,
            _ => return None,
        };

        Some(bi)
    }
}

#[inline]
fn no_physx(n: &str) -> &str {
    n.strip_prefix("physx::").unwrap_or(n)
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

        let ty = ty.strip_prefix("volatile ").unwrap_or(ty);

        // If the type is _not_ a pointer or reference, strip any const prefix
        // since it's useless and just makes parsing easier
        if !ty.contains('*') && !ty.contains('&') {
            if let Some(stripped) = ty.strip_prefix("const ") {
                return stripped;
            }
        } else if ty.contains('*') {
            if let Some(stripped) = ty.strip_suffix("__restrict") {
                return stripped;
            } else if ty.starts_with("class ") {
                return "void *";
            }
        }

        ty
    }
}

#[derive(Copy, Clone, Debug, PartialEq)]
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
    USize,
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
    // on the C++ side, `void*`, but we want to be able to pack arbitrary data into the space
    // available so we treat it as a separate type so we can do that properly in the Rust side
    UserData,
    // same as above but `const void*
    ConstUserData,
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
            Self::USize => "usize",
            Self::Vec3V => "glam::Vec3A",
            Self::Vec3 => "PxVec3",
            Self::Vec3p => "PxVec3Padded",
            Self::Vec4V | Self::Vec4 => "PxVec4",
            Self::QuatV | Self::Quat => "PxQuat",
            Self::BoolV => "glam::BVec4A",
            Self::U32V => "glam::UVec4",
            Self::I32V => "glam::IVec4",
            Self::Mat33V => "glam::Mat3A",
            Self::Mat33 => "PxMat33",
            Self::Mat34V => "glam::Affine3A",
            Self::Mat34 => "Affine",
            Self::Mat44V | Self::Mat44 => "PxMat44",
            Self::UserData => "UserData",
            Self::ConstUserData => "ConstUserData",
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
            Self::USize => "size_t",
            Self::Vec3V => "physx_Vec3V_Pod",
            Self::Vec3 => "physx_PxVec3_Pod",
            Self::Vec3p => "physx_Vec3p_Pod",
            Self::Vec4V => "physx_Vec4V_Pod",
            Self::Vec4 => "physx_PxVec4_Pod",
            Self::QuatV => "physx_QuatV_Pod",
            Self::Quat => "physx_PxQuat_Pod",
            Self::BoolV => "physx_BoolV_Pod",
            Self::U32V => "physx_VecU32V_Pod",
            Self::I32V => "physx_VecI32V_Pod",
            Self::Mat33V => "physx_Mat33V_Pod",
            Self::Mat33 => "physx_PxMat33_Pod",
            Self::Mat34V => "physx_Mat34V_Pod",
            Self::Mat34 => "physx_Mat34_Pod",
            Self::Mat44V => "physx_Mat44V_Pod",
            Self::Mat44 => "physx_PxMat44_Pod",
            Self::UserData => "void*",
            Self::ConstUserData => "void const*",
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
            Self::USize => "size_t",
            Self::Vec3V => "physx::PxVec3V",
            Self::Vec3 => "physx::PxVec3",
            Self::Vec3p => "physx::PxVec3p",
            Self::Vec4V => "physx::PxVec4V",
            Self::Vec4 => "physx::PxVec4",
            Self::QuatV => "physx::PxQuatV",
            Self::Quat => "physx::PxQuat",
            Self::BoolV => "physx::PxBoolV",
            Self::U32V => "physx::PxVecU32V",
            Self::I32V => "physx::PxVecI32V",
            Self::Mat33V => "physx::PxMat33V",
            Self::Mat33 => "physx::PxMat33",
            Self::Mat34V => "physx::PxMat34V",
            Self::Mat34 => "physx::PxMat34",
            Self::Mat44V => "physx::PxMat44V",
            Self::Mat44 => "physx::PxMat44",
            Self::UserData => "void*",
            Self::ConstUserData => "void const*",
        }
    }

    #[inline]
    pub fn is_pod(self) -> bool {
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
                | Self::UserData
                | Self::ConstUserData
        )
    }
}

#[derive(Debug, Clone, PartialEq)]
pub enum QualType<'ast> {
    Pointer {
        is_const: bool,
        is_pointee_const: bool,
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
    TemplateTypedef {
        name: String,
    },
}

use std::fmt;

#[derive(Copy, Clone)]
pub struct RustType<'qt, 'ast>(&'qt QualType<'ast>);

impl<'qt, 'ast> fmt::Display for RustType<'qt, 'ast> {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self.0 {
            QualType::Pointer {
                is_pointee_const,
                pointee,
                ..
            } => {
                write!(f, "*{} ", if *is_pointee_const { "const" } else { "mut" })?;
                write!(f, "{}", pointee.rust_type())
            }
            QualType::Reference {
                is_const, pointee, ..
            } => {
                write!(f, "*{} ", if *is_const { "const" } else { "mut" })?;
                write!(f, "{}", pointee.rust_type())
            }
            QualType::Builtin(bi) => f.write_str(bi.rust_type()),
            QualType::FunctionPointer => f.write_str("*mut std::ffi::c_void"),
            QualType::Array { element, len } => {
                write!(f, "[{}; {len}]", element.rust_type())
            }
            QualType::Enum { name, .. }
            | QualType::Flags { name, .. }
            | QualType::Record { name } => f.write_str(name),
            QualType::TemplateTypedef { name } => f.write_str(name),
        }
    }
}

#[derive(Copy, Clone)]
pub struct CppType<'qt, 'ast>(&'qt QualType<'ast>);

impl<'qt, 'ast> fmt::Display for CppType<'qt, 'ast> {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self.0 {
            QualType::Pointer {
                is_const,
                pointee,
                is_pointee_const,
            } => {
                write!(f, "{}", pointee.cpp_type())?;
                write!(f, "{}*", if *is_pointee_const { " const" } else { "" })?;
                if *is_const {
                    write!(f, "const")?;
                }

                Ok(())
            }
            QualType::Reference {
                is_const, pointee, ..
            } => {
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
            QualType::TemplateTypedef { name } => f.write_str(name),
        }
    }
}

#[derive(Copy, Clone)]
pub struct CType<'qt, 'ast>(&'qt QualType<'ast>);

impl<'qt, 'ast> fmt::Display for CType<'qt, 'ast> {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self.0 {
            QualType::Pointer {
                is_const,
                pointee,
                is_pointee_const,
            } => {
                write!(f, "{}", pointee.c_type())?;
                write!(f, "{}*", if *is_pointee_const { " const" } else { "" })?;
                if *is_const {
                    write!(f, "const")?;
                }
                Ok(())
            }
            QualType::Reference { is_const, pointee } => {
                write!(f, "{}", pointee.c_type())?;
                write!(f, "{}*", if *is_const { " const" } else { "" })
            }
            QualType::Builtin(bi) => f.write_str(bi.c_type()),
            QualType::FunctionPointer => f.write_str("void *"),
            QualType::Array { element, len } => {
                panic!("C array `{}[{len}]` breaks the pattern of every other type by have elements on both sides of an identifier", element.c_type());
            }
            QualType::Enum { repr, .. } | QualType::Flags { repr, .. } => {
                f.write_str(repr.c_type())
            }
            QualType::Record { name } => write!(f, "physx_{name}_Pod"),
            QualType::TemplateTypedef { name } => write!(f, "physx_{name}_Pod"),
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
            QualType::Builtin(bi) => bi.is_pod(),
            QualType::FunctionPointer => false,
            QualType::Array { element, .. } => element.is_pod(),
            QualType::Enum { .. }
            | QualType::Flags { .. }
            | QualType::Record { .. }
            | QualType::Reference { .. }
            | QualType::TemplateTypedef { .. } => true,
        }
    }
}
