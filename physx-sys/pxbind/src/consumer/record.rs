use std::fmt;

use super::{functions, Builtin, ClassDef, Id, Item, QualType, Type, Typedef};
use crate::Node;
use anyhow::Context as _;
use functions::*;
use serde::Deserialize;

#[derive(Copy, Clone, Deserialize, Debug)]
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
    pub name: String,
    #[serde(rename = "type")]
    pub kind: Type,
    #[serde(default, rename = "storageClass", deserialize_with = "storage_class")]
    pub is_static: bool,
    #[serde(default, rename = "virtual")]
    pub is_virtual: bool,
}

impl Method {
    #[inline]
    fn is_const(&self) -> bool {
        self.is_static || self.kind.qual_type.ends_with(") const")
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
    fn is_copy_or_move_constructor(&self, node: &Node) -> bool {
        let mut iter = node.inner.iter().filter_map(|inn| {
            if let Item::ParmVarDecl(param) = &inn.kind {
                Some(&param.kind.qual_type)
            } else {
                None
            }
        });

        let Some(first) = iter.next() else {
            return false;
        };

        if first.ends_with(" &&") {
            return true;
        }

        let maybe_copy = first
            .strip_suffix(" &")
            .map_or(false, |is_ref| is_ref.ends_with(&self.inner.name));

        maybe_copy && iter.next().is_none()
    }
}

#[derive(Deserialize, Debug)]
#[serde(rename_all = "camelCase")]
struct Dtor {
    #[serde(default)]
    irrelevant: bool,
    #[serde(default)]
    simple: bool,
}

#[derive(Deserialize, Debug)]
#[serde(rename_all = "camelCase")]
pub struct DefinitionData {
    // #[serde(default, rename = "isPOD")]
    // is_pod: bool,
    dtor: Dtor,
    #[serde(default)]
    is_abstract: bool,
    #[serde(default)]
    is_polymorphic: bool,
}

#[derive(Deserialize, Debug)]
#[serde(rename_all = "camelCase")]
pub struct Base {
    //access: String,
    #[serde(rename = "type")]
    kind: Type,
    //written_access: String,
}

#[derive(Copy, Clone, Deserialize, Debug)]
#[serde(rename_all = "camelCase")]
pub enum Tag {
    Struct,
    Class,
    Union,
}

impl fmt::Display for Tag {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::Struct => f.write_str("struct"),
            Self::Class => f.write_str("class"),
            Self::Union => f.write_str("union"),
        }
    }
}

#[derive(Deserialize, Debug)]
#[serde(rename_all = "camelCase")]
pub struct Record {
    pub id: Option<Id>,
    pub name: Option<String>,
    pub tag_used: Option<Tag>,
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
pub struct RecBindingDef<'ast> {
    pub name: &'ast str,
    pub has_vtable: bool,
    pub ast: &'ast Record,
    pub fields: Vec<FieldBinding<'ast>>,
    pub calc_layout: bool,
}

#[derive(Debug)]
pub struct RecBindingForward<'ast> {
    pub name: &'ast str,
}

#[derive(Debug)]
pub enum RecBinding<'ast> {
    Forward(RecBindingForward<'ast>),
    Def(RecBindingDef<'ast>),
}

impl<'ast> RecBinding<'ast> {
    pub fn name(&self) -> &'ast str {
        match self {
            Self::Def(def) => def.name,
            Self::Forward(fwd) => fwd.name,
        }
    }
}

impl<'ast> PartialEq<str> for RecBinding<'ast> {
    fn eq(&self, other: &str) -> bool {
        match self {
            Self::Def(def) => def.name == other,
            Self::Forward(fwd) => fwd.name == other,
        }
    }
}

#[derive(Debug, Clone)]
pub struct FieldBinding<'ast> {
    pub name: &'ast str,
    pub kind: QualType<'ast>,
    pub is_public: bool,
    pub is_reference: bool,
}

impl<'ast> super::AstConsumer<'ast> {
    fn has_release_method(&self, node: &'ast Node, rec: &'ast Record) -> anyhow::Result<bool> {
        if node.inner.iter().any(|inn| {
            if let Item::CXXMethodDecl(method) = &inn.kind {
                method.name == "release"
            } else {
                false
            }
        }) {
            return Ok(true);
        }

        for base in self.iter_bases(rec) {
            let (cdef, _) = base?;
            if self.has_release_method(cdef.node, cdef.rec)? {
                return Ok(true);
            }
        }

        Ok(false)
    }

    #[inline]
    pub(super) fn is_template_we_care_about(
        node: &'ast Node,
        td: &'ast Typedef,
    ) -> Option<&'ast str> {
        let tds = [
            "PxBitAndByte",
            "PxRaycastCallback",
            "PxOverlapCallback",
            "PxSweepCallback",
            "PxRaycastBuffer",
            "PxOverlapBuffer",
            "PxSweepBuffer",
            "PxBitMap",
        ];

        if !tds.contains(&td.name.as_str()) {
            return None;
        }

        node.inner.iter().find_map(|inn| {
            if let Item::TemplateSpecializationType { template_name } = &inn.kind {
                Some(template_name.as_str())
            } else {
                None
            }
        })
    }

    pub(super) fn consume_template_typedef(
        &mut self,
        _node: &'ast Node,
        td: &'ast Typedef,
        template_name: &'ast str,
        root: &'ast Node,
    ) -> anyhow::Result<()> {
        if self.classes.contains_key(td.name.as_str()) {
            return Ok(());
        }

        let mut fields = Vec::new();
        match td.name.as_str() {
            "PxBitAndByte" => {
                fields.push(FieldBinding {
                    name: "mData",
                    kind: QualType::Builtin(Builtin::UChar),
                    is_public: false,
                    is_reference: false,
                });
            }
            "PxRaycastCallback" | "PxOverlapCallback" | "PxSweepCallback" | "PxRaycastBuffer"
            | "PxOverlapBuffer" | "PxSweepBuffer" => {
                let hit_type = match td.name.as_str() {
                    "PxRaycastCallback" | "PxRaycastBuffer" => "PxRaycastHit",
                    "PxOverlapCallback" | "PxOverlapBuffer" => "PxOverlapHit",
                    "PxSweepCallback" | "PxSweepBuffer" => "PxSweepHit",
                    _ => unreachable!(),
                };

                fields.push(FieldBinding {
                    name: "block",
                    kind: QualType::Record { name: hit_type },
                    is_public: true,
                    is_reference: false,
                });
                fields.push(FieldBinding {
                    name: "hasBlock",
                    kind: QualType::Builtin(Builtin::Bool),
                    is_public: true,
                    is_reference: false,
                });
                fields.push(FieldBinding {
                    name: "touches",
                    kind: QualType::Pointer {
                        is_const: false,
                        is_pointee_const: false,
                        pointee: Box::new(QualType::Record { name: hit_type }),
                    },
                    is_public: true,
                    is_reference: false,
                });
                fields.push(FieldBinding {
                    name: "maxNbTouches",
                    kind: QualType::Builtin(Builtin::UInt),
                    is_public: true,
                    is_reference: false,
                });
                fields.push(FieldBinding {
                    name: "nbTouches",
                    kind: QualType::Builtin(Builtin::UInt),
                    is_public: true,
                    is_reference: false,
                });
            }
            "PxBitMap" => {
                fields.push(FieldBinding {
                    name: "mMap",
                    kind: QualType::Pointer {
                        is_const: false,
                        is_pointee_const: false,
                        pointee: Box::new(QualType::Builtin(Builtin::UInt)),
                    },
                    is_public: false,
                    is_reference: false,
                });
                fields.push(FieldBinding {
                    name: "mWordCount",
                    kind: QualType::Builtin(Builtin::UInt),
                    is_public: false,
                    is_reference: false,
                });
            }
            _ => {
                self.consume_template_instance(&td.kind.qual_type, Some(&td.name))?;
            }
        }

        let name = &td.name;
        let (node, ast) = super::search(root, &|node: &Node| match &node.kind {
            Item::ClassTemplateSpecializationDecl(rec) | Item::CXXRecordDecl(rec) => {
                (rec.name.as_deref() == Some(template_name)).then_some(rec)
            }
            _ => None,
        })
        .with_context(|| format!("failed to locate template specialization for {name}"))?;

        self.classes.insert(
            name,
            Some(super::ClassDef {
                index: self.recs.len(),
                node,
                rec: ast,
            }),
        );

        self.recs.push(RecBinding::Def(RecBindingDef {
            name,
            has_vtable: ast.is_polymorphic(),
            fields,
            ast,
            calc_layout: true,
        }));

        Ok(())
    }

    fn iter_bases(
        &self,
        rec: &'ast Record,
    ) -> impl Iterator<Item = anyhow::Result<(&ClassDef<'ast>, &RecBindingDef<'ast>)>> {
        rec.bases.iter().filter_map(|base| {
            let Some(base_name) = base.kind.qual_type.strip_prefix("physx::") else {
                log::debug!("skipping non-physx base class '{}'", base.kind.qual_type);
                return None;
            };

            let get = || {
                let base_rec = self.classes.get(base_name).with_context(|| {
                    format!(
                        "failed to find base '{}' for '{}'",
                        base.kind.qual_type,
                        rec.name.as_deref().unwrap(),
                    )
                })?;

                let base_rec = base_rec.as_ref().with_context(|| {
                    format!(
                        "Definition for base class {} has not been consumed",
                        base.kind.qual_type
                    )
                })?;

                if let RecBinding::Def(base_binding) = &self.recs[base_rec.index] {
                    anyhow::ensure!(
                        base_binding.name == base_name,
                        "Retrieved incorrect binding for base class"
                    );
                    Ok((base_rec, base_binding))
                } else {
                    anyhow::bail!("Found a forward declaration instead of the base definition");
                }
            };

            Some(get())
        })
    }

    pub(super) fn consume_record(
        &mut self,
        node: &'ast Node,
        rec: &'ast Record,
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

        let Some(rname) = rec.name.as_deref() else {
            return Ok(());
        };

        anyhow::ensure!(
            rec.definition_data.is_some(),
            "can't consume a record without a definition"
        );
        let has_vtable = rec.is_polymorphic();

        let mut is_public = !matches!(rec.tag_used, Some(Tag::Class));

        let mut fields = Vec::new();
        for base_binding in self.iter_bases(rec) {
            let (_, base_binding) = base_binding?;
            fields.extend(base_binding.fields.iter().cloned());
        }

        self.get_fields(node, rec, &[], &mut fields)?;

        // Keep a record of each method that we are binding, to account for
        // overloading, particularly constructors, we need to append a counter
        // to keep the binding functions unique
        let mut meth_map = std::collections::BTreeMap::<String, u8>::new();

        let mut get_name = |req: String| -> String {
            if let Some(count) = meth_map.get_mut(&req) {
                *count += 1;
                format!("{req}_{count}")
            } else {
                meth_map.insert(req.clone(), 0);
                req
            }
        };

        for inn in &node.inner {
            // Ignore any method that isn't public, it's not part of the API we care about
            if let Some(method) = inn.kind.as_method() {
                if !is_public {
                    continue;
                } else if method.kind.qual_type.contains('<') {
                    log::debug!(
                        "skipping `{rname}::{}` as it contains a templated parameter",
                        method.name
                    );
                    continue;
                } else if Self::is_deprecated(inn) {
                    log::debug!("skipping deprecated method {rname}::{}", method.name);
                    continue;
                }
            }

            let comment = Self::get_comment(inn);

            let (mut func, method, has_self) = match &inn.kind {
                Item::AccessSpecDecl { access } => {
                    is_public = matches!(access, Access::Public);
                    continue;
                }
                Item::CXXConstructorDecl(method) => {
                    // If the class is abstract we can't construct it directly so don't need to bind constructors
                    // We don't care about copy or move constructors because they don't make sense in a C API
                    if rec.is_abstract() || method.is_copy_or_move_constructor(inn) {
                        continue;
                    }

                    let func_binding = if rec.is_polymorphic() || !rec.has_simple_destructor() {
                        FuncBinding {
                            name: get_name(format!("{rname}_new_alloc")),
                            ret: Some(QualType::Pointer {
                                is_const: false,
                                is_pointee_const: false,
                                pointee: Box::new(QualType::Record { name: rname }),
                            }),
                            comment,
                            ext: FuncBindingExt::None(PhysxInvoke::New(rname)),
                            params: Vec::new(),
                        }
                    } else {
                        FuncBinding {
                            name: get_name(format!("{rname}_new")),
                            ret: Some(QualType::Record { name: rname }),
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
                        name: get_name(format!(
                            "{rname}_{}{}",
                            method.name,
                            if method.is_const() { "" } else { "_mut" }
                        )),
                        ret: None,
                        comment,
                        ext: if method.is_static {
                            FuncBindingExt::None(PhysxInvoke::Method {
                                func_name: &method.name,
                                class_name: rname,
                                is_static: method.is_static,
                            })
                        } else {
                            FuncBindingExt::HasSelf(PhysxInvoke::Method {
                                func_name: &method.name,
                                class_name: rname,
                                is_static: method.is_static,
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
                            ext: FuncBindingExt::IsDelete(rname),
                            params: Vec::new(),
                            ret: None,
                        },
                        method,
                        true,
                    )
                }
                _ => continue,
            };

            if has_self {
                func.params.push(Param::self_pod(
                    QualType::Record { name: rname },
                    method.is_const(),
                ));
            }

            self.consume_method(inn, method, &[], func)?;
        }

        // Check the fields to see if any records need to be forward declared
        // Note this doesn't apply to function parameters since functions are
        // emitted after all Pod types
        for field in &fields {
            if let QualType::Pointer { pointee, .. } | QualType::Reference { pointee, .. } =
                &field.kind
            {
                if let QualType::Record { name } = &**pointee {
                    // Special case for PxTempAllocatorChunk which is an internal
                    // linked list
                    if *name != rname && !self.classes.contains_key(name) {
                        self.recs
                            .push(RecBinding::Forward(RecBindingForward { name }));
                        self.classes.insert(name, None);
                    }
                }
            }
        }

        // If there are no fields, we need to add a dummy field since C++ doesn't have
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

        // Decide whether we should use "structgen" to calculate the exact layout of
        // this C++ struct.
        //
        // Ideally we would do this for all types, but we must be able to name them,
        // which is not feasible for anonymous types, or types which the generator
        // doesn't support yet (their cppTypeName will be empty).
        //
        // Note that empty types are only refered to by pointers and references in
        // PhysX, so we can generate dummy contents for them.
        let calc_layout = (!matches!(rec.tag_used, Some(crate::consumer::Tag::Union))
            && !fields.is_empty())
            || rname == "PxBroadcastingErrorCallback";

        let record = RecBindingDef {
            name: rname,
            has_vtable,
            fields,
            ast: rec,
            calc_layout,
        };

        self.classes.insert(
            rname,
            Some(super::ClassDef {
                index: self.recs.len(),
                node,
                rec,
            }),
        );
        self.recs.push(RecBinding::Def(record));
        Ok(())
    }

    pub fn get_fields(
        &self,
        node: &'ast Node,
        rec: &'ast Record,
        template_types: &[(&str, &super::TemplateArg<'ast>)],
        fields: &mut Vec<FieldBinding<'ast>>,
    ) -> anyhow::Result<()> {
        let Some(rname) = rec.name.as_deref() else {
            return Ok(());
        };
        let mut is_public = !matches!(rec.tag_used, Some(Tag::Class));

        for inn in &node.inner {
            // We _could_ get comments for fields here, but due to the rust
            // declarations being emitted by structgen, it becomes a bit noisy

            match &inn.kind {
                Item::AccessSpecDecl { access } => {
                    is_public = matches!(access, Access::Public);
                }
                Item::FieldDecl { name, kind } => {
                    // Skip anonymous fields, they aren't really accessible
                    if let Some(name) = name.as_deref() {
                        // PhysX uses PxPadding<BYTES> in some struct, but this
                        // is uninteresting so we can just skip it, they'll be
                        // accounted for in our own padding calculations regardless
                        if kind.qual_type.starts_with("PxPadding<") {
                            log::debug!("skipping padding field");
                            continue;
                        }

                        if kind.qual_type.contains('<') {
                            log::debug!("skipping templated field {rname}::{name}");
                            continue;
                        }

                        // We've made modifications to the C++ code to deprecate
                        // fields that are using deprecated types
                        if Self::is_deprecated(inn) {
                            continue;
                        }

                        let kind = if name == "userData" || name == "mUserData" {
                            QualType::Builtin(Builtin::UserData)
                        } else {
                            self
                                .parse_type(kind, template_types)
                                .with_context(|| format!("failed to parse type for {rname}::{name}"))?
                        };

                        // if matches!(&kind, QualType::FunctionPointer) {
                        //     continue;
                        // }

                        let is_reference = matches!(kind, QualType::Reference { .. });


                        fields.push(FieldBinding {
                            name,
                            kind,
                            is_public,
                            is_reference,
                        });
                    }
                }
                _ => {}
            }
        }

        Ok(())
    }
}
