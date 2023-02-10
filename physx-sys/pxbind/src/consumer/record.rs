use super::{Comment, Item, QualType, Type};
use crate::{writes, Node};
use anyhow::Context as _;
use serde::Deserialize;

enum TypeBinding<'ast> {
    SelfPod { typename: &'ast str, is_const: bool },
    Builtin(super::Builtin),
}

impl<'ast> TypeBinding<'ast> {
    fn write_c_type(&self, out: &mut String) {
        match self {
            Self::SelfPod { typename, is_const } => {
                writes!(
                    out,
                    "physx_{typename}_Pod{}*",
                    if *is_const { " const" } else { "" }
                );
            }
            _ => unreachable!(),
        }
    }

    fn write_cpp_type(&self, out: &mut String) {
        match self {
            Self::SelfPod { typename, is_const } => {
                writes!(
                    out,
                    "physx::{typename}{}*",
                    if *is_const { " const" } else { "" }
                );
            }
            _ => unreachable!(),
        }
    }

    fn write_rust_type(&self, out: &mut String) {
        match self {
            Self::SelfPod { typename, is_const } => {
                writes!(
                    out,
                    "*{} physx_{typename}_Pod",
                    if *is_const { "const" } else { "mut" }
                );
            }
            _ => unreachable!(),
        }
    }
}

struct Param<'ast> {
    c_name: &'ast str,
    cpp_name: &'ast str,
    kind: TypeBinding<'ast>,
}

impl<'ast> Param<'ast> {
    #[inline]
    fn self_pod(typename: &'ast str, is_const: bool) -> Self {
        Self {
            c_name: "self__pod",
            cpp_name: "self_",
            kind: TypeBinding::SelfPod { typename, is_const },
        }
    }

    fn write_c_to_cpp(&self, out: &mut String) {
        match &self.kind {
            TypeBinding::SelfPod { typename, is_const } => {
                self.kind.write_cpp_type(out);
                writes!(out, " self_ = reinterpret_cast<");
                self.kind.write_cpp_type(out);
                writes!(out, ">({})", self.c_name);
            }
            _ => unreachable!(),
        }

        writes!(out, ";\n");
    }
}

enum PhysxInvoke<'ast> {
    /// Normal function call. Not many of these in PhysX, it's pretty OO
    Func {
        func_name: &'ast str,
        return_type: Option<&'ast str>,
    },
    /// Method call
    Method {
        func_name: &'ast str,
        return_type: Option<&'ast str>,
        /// If set, this is a static method call
        class_name: Option<&'ast str>,
    },
    /// Constructor call
    Ctor(&'ast str),
    /// New
    New(&'ast str),
}

impl<'ast> PhysxInvoke<'ast> {
    fn emit(&self, args: impl Iterator<Item = &'ast str>, out: &mut String) {
        let mut args = args.peekable();
        let has_args = args.peek().is_some();

        // Would be nice with https://doc.rust-lang.org/std/iter/trait.Iterator.html#method.intersperse
        // but it's not stable yet
        let emit_args = |out: &mut String| {
            for (i, arg) in args.enumerate() {
                let sep = if i > 0 { ", " } else { "" };

                writes!(out, "{sep}{arg}");
            }
        };

        match self {
            Self::Func {
                func_name,
                return_type,
            } => {
                if let Some(rt) = return_type {
                    writes!(out, "{rt} return_val = ");
                }

                writes!(out, "{func_name}(");
                emit_args(out);
                writes!(out, ");\n");
            }
            Self::Method {
                func_name,
                return_type,
                class_name,
            } => {
                if let Some(rt) = return_type {
                    writes!(out, "{rt} return_val = ");
                }

                if let Some(cn) = class_name {
                    writes!(out, "{cn}::{func_name}(");
                } else {
                    writes!(out, "self_->{func_name}(");
                }

                emit_args(out);
                writes!(out, ");\n");
            }
            Self::Ctor(class) => {
                writes!(out, "{class} return_val");
                // Deal with Most Vexing Parse, thanks C++
                if has_args {
                    writes!(out, "(");
                    emit_args(out);
                    writes!(out, ");\n");
                } else {
                    writes!(out, ";\n");
                }
            }
            Self::New(class) => {
                writes!(out, "auto return_val = new {}(", class);
                emit_args(out);
                writes!(out, ");\n");
            }
        }
    }
}

enum FuncBindingExt<'ast> {
    IsDelete,
    None(PhysxInvoke<'ast>),
    HasSelf(PhysxInvoke<'ast>),
}

struct FuncBinding<'ast> {
    name: String,
    comment: Option<Comment<'ast>>,
    ext: FuncBindingExt<'ast>,
    params: Vec<Param<'ast>>,
    ret: Option<TypeBinding<'ast>>,
}

//     bool hasSelf = false;
//     vector<CppFnArg> args;
//     shared_ptr<CppResultCalc> valueExpr;
//     CppType returnType;

//     string genCppDef() const {
//         string result;
//         result += fmt::format("{} {}(", returnType.getCType(), name);

//         int i = 0;
//         for (auto& arg : args) {
//             if (i > 0) {
//                 result += ", ";
//             }
//             result += fmt::format("{} {}", arg.getCType(), arg.cName());
//             ++i;
//         }

//         result += ") {\n";

//         for (const CppFnArg& arg : this->args) {
//             result += arg.getC2CppCode();
//         }

//         result += bodyPreamble;

//         if (this->valueExpr) {
//             vector<string> argNames;
//             {
//                 auto arg = this->args.begin();
//                 if (this->hasSelf) {
//                     // Skip self when calling the function
//                     ++arg;
//                 }

//                 for (; arg != this->args.end(); ++arg) {
//                     argNames.push_back(arg->cppName);
//                 }
//             }

//             CppFnArg returnValue(this->returnType, "returnValue");

//             // Calculate the result
//             result +=
//                 this->valueExpr->toString(
//                     returnValue.cppName, returnValue.getCppType(), argNames) +
//                 "\n";

//             // Convert the result to a C POD representation
//             result += returnValue.getCpp2CCode();

//             if (this->returnType.getCType() != "void") {
//                 result += fmt::format("return {};\n", returnValue.cName());
//             }
//         }
//         result += "}\n";

//         return result;
//     }
// }

// impl<'ast> FuncBinding<'ast> {
//     fn emit_cpp<W: std::io::Write>(&self, writer: &mut W, level: u32) -> anyhow::Result<()> {
//         let mut acc = String::new();

//         // Emit the function signature
//         {
//             let indent = Indent(level);

//             writes!(acc, "{indent}");

//             if let Some(ret) = &self.ret {
//                 ret.write_c_type(&mut acc);
//             } else {
//                 acc.push_str("void")
//             }

//             writes!(acc, " {}(", self.name);

//             for (i, param) in self.params.iter().enumerate() {
//                 // No trailing commas :(
//                 let sep = if i > 0 { ", " } else { "" };

//                 writes!(acc, "{sep}");
//                 param.kind.write_c_type(&mut acc);
//                 writes!(acc, " {}", param.c_name);
//             }

//             writeln!(writer, "{acc}) {{")?;
//             acc.clear();
//         }

//         let indent = Indent(level + 1);

//         // Emit the code that converts each argument to an appropriately typed/named
//         // c++ variable
//         if self.params.is_empty() {
//             for param in &self.params {
//                 writes!(acc, "{indent}");
//                 param.write_c_to_cpp(&mut acc);
//             }

//             writeln!(writer, "{acc}")?;
//             acc.clear();
//         }

//         let (invoke, arg_skip) = match &self.ext {
//             FuncBindingExt::IsDelete => {
//                 writeln!(writer, "{indent}delete self_;\n}}")?;
//                 return Ok(());
//             }
//             FuncBindingExt::None(inv) => (inv, 0),
//             FuncBindingExt::HasSelf(inv) => (inv, 1),
//         };

//         // Emit the code that actually calls into physx
//         let args = self
//             .params
//             .iter()
//             .skip(arg_skip)
//             .map(|param| param.cpp_name);

//         invoke.emit(args, &mut acc);

//         if let Some(rt) = &self.ret {
//             unreachable!()
//             //     rt.
//             // result += returnValue.getCpp2CCode();

//             //     if (this->returnType.getCType() != "void") {
//             //         result += fmt::format("return {};\n", returnValue.cName());
//             //     }
//         }

//         Ok(())
//     }

//     fn emit_rust(&self, writer: &mut String, level: u32) {
//         if let Some(com) = &self.comment {
//             com.emit_rust(writer, level);
//         }

//         let indent = Indent(level);

//         let mut acc = String::new();
//         writes!(acc, "{indent}pub fn {}(", self.name);

//         for param in &self.params {
//             writes!(acc, "{}: ", param.c_name);
//             param.kind.write_rust_type(&mut acc);
//             writes!(acc, ", ");
//         }

//         if let Some(ret) = &self.ret {
//             writes!(acc, ") -> ");
//             ret.write_rust_type(&mut acc);
//             writes!(acc, ";");
//         } else {
//             writes!(acc, ");");
//         }

//         writesln!(writer, "{acc}");
//     }
// }

#[derive(Deserialize, Debug)]
#[serde(rename_all = "camelCase")]
pub enum Access {
    Public,
    Protected,
    Private,
}

fn storage_class<'de, D>(deserializer: D) -> Result<bool, D::Error>
where
    D: serde::de::Deserializer<'de>,
{
    let s: &str = serde::de::Deserialize::deserialize(deserializer)?;
    Ok(s == "static")
}

#[derive(Deserialize, Debug)]
pub struct Method {
    name: String,
    #[serde(rename = "type")]
    kind: Type,
    #[serde(default, rename = "storageClass", deserialize_with = "storage_class")]
    is_static: bool,
    #[serde(default, rename = "virtual")]
    is_virtual: bool,
}

impl Method {
    #[inline]
    fn is_const(&self) -> bool {
        self.kind.qual_type.ends_with(") const")
    }
}

#[derive(Deserialize, Debug)]
pub struct Constructor {
    #[serde(flatten)]
    pub(super) inner: Method,
}

impl Constructor {
    /// Determines whether a constructor is a [copy constructor](https://en.cppreference.com/w/cpp/language/copy_constructor)
    #[inline]
    fn is_copy_constructor(&self, node: &Node) -> bool {
        let mut iter = node.inner.iter().filter_map(|inn| {
            if let Item::ParmVarDecl(param) = &inn.kind {
                Some(&param.kind.qual_type)
            } else {
                None
            }
        });

        let Some(first) = iter.next() else { return false };

        let maybe_copy = first
            .strip_suffix(" &")
            .map(|is_ref| is_ref.ends_with(&self.inner.name))
            .unwrap_or(false);

        maybe_copy && iter.next().is_none()
    }
}

#[derive(Deserialize, Debug)]
#[serde(rename_all = "camelCase")]
struct Dtor {
    #[serde(default)]
    irrelevant: bool,
    #[serde(default)]
    needs_implicit: bool,
    #[serde(default)]
    simple: bool,
    #[serde(default)]
    trivial: bool,
}

#[derive(Deserialize, Debug)]
#[serde(rename_all = "camelCase")]
pub struct DefinitionData {
    #[serde(default, rename = "isPOD")]
    is_pod: bool,
    dtor: Dtor,
    #[serde(default)]
    is_abstract: bool,
    #[serde(default)]
    is_polymorphic: bool,
}

#[derive(Deserialize, Debug)]
#[serde(rename_all = "camelCase")]
pub struct Base {
    access: String,
    #[serde(rename = "type")]
    kind: Type,
    written_access: String,
}

#[derive(Deserialize, Debug)]
#[serde(rename_all = "camelCase")]
pub enum Tag {
    Struct,
    Class,
    Union,
}

#[derive(Deserialize, Debug)]
#[serde(rename_all = "camelCase")]
pub struct Record {
    pub name: Option<String>,
    pub tag_used: Tag,
    pub definition_data: Option<DefinitionData>,
    #[serde(default)]
    pub bases: Vec<Base>,
}

impl Record {
    #[inline]
    fn is_abstract(&self) -> bool {
        self.definition_data
            .as_ref()
            .map_or(false, |dd| dd.is_abstract)
    }

    #[inline]
    fn is_polymorphic(&self) -> bool {
        self.definition_data
            .as_ref()
            .map_or(false, |dd| dd.is_polymorphic)
    }

    #[inline]
    fn has_irrelevant_destructor(&self) -> bool {
        self.definition_data
            .as_ref()
            .map_or(false, |dd| dd.dtor.irrelevant)
    }

    #[inline]
    fn has_simple_destructor(&self) -> bool {
        self.definition_data
            .as_ref()
            .map_or(false, |dd| dd.dtor.simple)
    }
}

#[derive(Debug)]
pub struct RecBinding<'ast> {
    pub name: &'ast str,
    pub has_vtable: bool,
    pub ast: &'ast Record,
    pub fields: Vec<FieldBinding<'ast>>,
    pub is_empty: bool,
}

#[derive(Debug)]
pub struct FieldBinding<'ast> {
    pub name: &'ast str,
    pub kind: QualType<'ast>,
    pub is_public: bool,
    pub is_reference: bool,
}

impl<'ast> super::AstConsumer<'ast> {
    fn has_release_method(&self, node: &'ast Node, rec: &'ast Record) -> anyhow::Result<bool> {
        if node
            .inner
            .iter()
            .find(|inn| {
                if let Item::CXXMethodDecl(method) = &inn.kind {
                    method.name == "release"
                } else {
                    false
                }
            })
            .is_some()
        {
            return Ok(true);
        }

        for base in &rec.bases {
            if let Some(base_name) = base.kind.qual_type.strip_prefix("physx::") {
                if let Some((supern, superr)) = self.classes.get(base_name) {
                    if self.has_release_method(supern, superr)? {
                        return Ok(true);
                    }
                } else {
                    // Explicitly fail here, we _should_ always have encountered the
                    // base class before any derived class, so if we didn't, something
                    // is wrong
                    anyhow::bail!(
                        "{:?} {:?} has base `{}`, but we couldn't find it",
                        rec.tag_used,
                        rec.name,
                        base.kind.qual_type
                    );
                }
            }
        }

        Ok(false)
    }

    pub(super) fn consume_record(
        &mut self,
        node: &'ast Node,
        rec: &'ast Record,
        root: &'ast Node,
    ) -> anyhow::Result<()> {
        // Do a quick check of the inner nodes, if we have an enumdecl, but no fields
        // or methods, this is just a wrapper around an enum and we can just emit the enum
        // and exit
        let mut had_enums = false;
        let mut had_more = false;

        for inn in &node.inner {
            match &inn.kind {
                Item::FieldDecl { .. } => had_more = true,
                kind if kind.as_method().is_some() => had_more = true,
                Item::EnumDecl(decl) => {
                    self.consume_enum(node, inn, decl)?;
                    had_enums = true;
                }
                _ => continue,
            }
        }

        if had_enums && !had_more {
            return Ok(());
        }

        let Some(rname) = rec.name.as_deref() else { return Ok(()) };

        // Skip records we've already seen, this happens a lot as forward declarations
        // and record definitions have the same kind
        if self.classes.contains_key(rname) {
            return Ok(());
        }

        // If we don't have definition data, that means this is a forward declaration,
        // so we want to find the actual definition since that has information we need
        let has_vtable = if rec.definition_data.is_none() {
            if let Some(definition) = super::search(root, &|node: &Node| {
                if let Item::CXXRecordDecl(rec) = &node.kind {
                    rec.name.as_deref().filter(|rn| *rn == rname).map(|_| rec)
                } else {
                    None
                }
            }) {
                self.classes.insert(rname, definition);
                definition.1.is_polymorphic()
            } else {
                self.classes.insert(rname, (node, rec));
                rec.is_polymorphic()
            }
        } else {
            self.classes.insert(rname, (node, rec));
            rec.is_polymorphic()
        };

        let mut is_public = !matches!(rec.tag_used, Tag::Class);

        let mut fields = Vec::new();

        // Keep a record of each method that we are binding, to account for
        // overloading, particularly constructors, we need to append a counter
        // to keep the binding functions unique
        let mut meth_map = std::collections::BTreeMap::<&str, u8>::new();

        for inn in &node.inner {
            // Ignore any method that isn't public, it's not part of the API we care about
            if let Some(method) = inn.kind.as_method() {
                continue;
                // if !is_public {
                //     continue;
                // } else if self.is_ignored(inn) {
                //     println!("skipping deprecated method {rname}::{}", method.name);
                //     continue;
                // }
            }

            let comment = Self::get_comment(inn);

            let (mut func, method, has_self) = match &inn.kind {
                Item::AccessSpecDecl { access } => {
                    is_public = matches!(access, Access::Public);
                    continue;
                }
                Item::CXXConstructorDecl(method) => {
                    // If the class is abstract we can't construct it directly so don't need to bind constructors
                    // We don't care about copy constructors because we're rebels
                    // We also don't care about move constructors, but physx doesn't have any
                    if rec.is_abstract() || method.is_copy_constructor(inn) {
                        continue;
                    }

                    let func_binding = if rec.is_polymorphic() || !rec.has_simple_destructor() {
                        FuncBinding {
                            name: format!("{rname}_new_alloc"),
                            ret: None, // TODO
                            comment,
                            ext: FuncBindingExt::None(PhysxInvoke::New(rname)),
                            params: Vec::new(),
                        }
                    } else {
                        FuncBinding {
                            name: format!("{rname}_new"),
                            ret: None, // TODO
                            comment,
                            ext: FuncBindingExt::None(PhysxInvoke::Ctor(rname)),
                            params: Vec::new(),
                        }
                    };

                    (func_binding, &method.inner, false)
                }
                Item::CXXMethodDecl(method) => {
                    // We don't care about operator overloads
                    if method.name.starts_with("operator") {
                        continue;
                    }

                    let func_binding = FuncBinding {
                        name: format!(
                            "{rname}_{}{}",
                            method.name,
                            if method.is_const() { "" } else { "_mut" }
                        ),
                        ret: None, // TODO
                        comment,
                        ext: if method.is_static {
                            FuncBindingExt::None(PhysxInvoke::Method {
                                func_name: &method.name,
                                return_type: None,
                                class_name: Some(rname),
                            })
                        } else {
                            FuncBindingExt::HasSelf(PhysxInvoke::Method {
                                func_name: &method.name,
                                return_type: None,
                                class_name: None,
                            })
                        },
                        params: Vec::new(),
                    };

                    (func_binding, method, !method.is_static)
                }
                Item::CXXDestructorDecl(method) => {
                    // Determine whether this class has a destructor which has no semantic effect.
                    //
                    // PhysX uses reference counting for many things, in which
                    // case it should be deleted with a `release` method instead
                    // of explicitly deleting it, but we need to account for that
                    // `release` method possibly being on a base class, so we
                    // need to walk up the base class chain until we hit the root
                    // or a base that has a `release` method
                    // https://nvidia-omniverse.github.io/PhysX/physx/5.1.2/docs/API.html#reference-counting
                    if rec.has_irrelevant_destructor() || self.has_release_method(node, rec)? {
                        continue;
                    }

                    (
                        FuncBinding {
                            name: format!("{rname}_delete"),
                            comment,
                            ext: FuncBindingExt::IsDelete,
                            params: Vec::new(),
                            ret: None,
                        },
                        method,
                        true,
                    )
                }
                Item::FieldDecl { name, kind } => {
                    // Skip anonymous fields, they aren't really accessible
                    if let Some(name) = name.as_deref() {
                        let kind = self
                            .parse_type(kind)
                            .with_context(|| format!("failed to parse type for {rname}::{name}"))?;
                        let is_reference = matches!(kind, QualType::Reference { .. });

                        fields.push(FieldBinding {
                            name,
                            kind,
                            is_public,
                            is_reference,
                        });
                    }
                    continue;
                }
                _ => continue,
            };

            if !method.is_static {
                func.params.push(Param::self_pod(rname, method.is_const()));
            }
        }

        // If there are no fields, we need to add a dummy since C++ doesn't have
        // zero-sized types. This is fine in practice since these types are only
        // ever passed by pointer
        let is_empty = fields.is_empty() && !has_vtable;
        if is_empty {
            fields.push(FieldBinding {
                name: "pxbind_dummy",
                kind: QualType::Builtin(super::Builtin::Char),
                is_public: false,
                is_reference: false,
            });
        }

        let record = RecBinding {
            name: rname,
            has_vtable,
            fields,
            ast: rec,
            is_empty,
        };

        self.recs.push(record);
        Ok(())
    }
}
