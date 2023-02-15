use super::{functions, Builtin, Id, Item, QualType, Type, Typedef};
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
    fn is_copy_or_move_constructor(&self, node: &Node) -> bool {
        let mut iter = node.inner.iter().filter_map(|inn| {
            if let Item::ParmVarDecl(param) = &inn.kind {
                Some(&param.kind.qual_type)
            } else {
                None
            }
        });

        let Some(first) = iter.next() else { return false };

        if first.ends_with(" &&") {
            return true;
        }

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
pub struct RecBinding<'ast> {
    pub name: &'ast str,
    pub has_vtable: bool,
    pub ast: &'ast Record,
    pub fields: Vec<FieldBinding<'ast>>,
    pub is_empty: bool,
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

    #[inline]
    pub(super) fn is_template_we_care_about(
        &self,
        node: &'ast Node,
        td: &'ast Typedef,
    ) -> Option<&'ast str> {
        let tds = [
            "PxVec3",
            "PxVec3p",
            "PxVec4",
            "PxQuat",
            "PxMat33",
            "PxMat34",
            "PxMat44",
            "PxTransform",
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

    pub(super) fn consume_template(
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
            "PxVec3" => {
                fields.push(FieldBinding {
                    name: "x",
                    kind: QualType::Builtin(Builtin::Float),
                    is_public: true,
                    is_reference: false,
                });
                fields.push(FieldBinding {
                    name: "y",
                    kind: QualType::Builtin(Builtin::Float),
                    is_public: true,
                    is_reference: false,
                });
                fields.push(FieldBinding {
                    name: "z",
                    kind: QualType::Builtin(Builtin::Float),
                    is_public: true,
                    is_reference: false,
                });
            }
            "PxVec3p" => {
                fields.push(FieldBinding {
                    name: "x",
                    kind: QualType::Builtin(Builtin::Float),
                    is_public: true,
                    is_reference: false,
                });
                fields.push(FieldBinding {
                    name: "y",
                    kind: QualType::Builtin(Builtin::Float),
                    is_public: true,
                    is_reference: false,
                });
                fields.push(FieldBinding {
                    name: "z",
                    kind: QualType::Builtin(Builtin::Float),
                    is_public: true,
                    is_reference: false,
                });
                fields.push(FieldBinding {
                    name: "padding",
                    kind: QualType::Builtin(Builtin::UInt),
                    is_public: false,
                    is_reference: false,
                });
            }
            "PxVec4" => {
                fields.push(FieldBinding {
                    name: "x",
                    kind: QualType::Builtin(Builtin::Float),
                    is_public: true,
                    is_reference: false,
                });
                fields.push(FieldBinding {
                    name: "y",
                    kind: QualType::Builtin(Builtin::Float),
                    is_public: true,
                    is_reference: false,
                });
                fields.push(FieldBinding {
                    name: "z",
                    kind: QualType::Builtin(Builtin::Float),
                    is_public: true,
                    is_reference: false,
                });
                fields.push(FieldBinding {
                    name: "w",
                    kind: QualType::Builtin(Builtin::Float),
                    is_public: true,
                    is_reference: false,
                });
            }
            "PxQuat" => {
                fields.push(FieldBinding {
                    name: "x",
                    kind: QualType::Builtin(Builtin::Float),
                    is_public: true,
                    is_reference: false,
                });
                fields.push(FieldBinding {
                    name: "y",
                    kind: QualType::Builtin(Builtin::Float),
                    is_public: true,
                    is_reference: false,
                });
                fields.push(FieldBinding {
                    name: "z",
                    kind: QualType::Builtin(Builtin::Float),
                    is_public: true,
                    is_reference: false,
                });
                fields.push(FieldBinding {
                    name: "w",
                    kind: QualType::Builtin(Builtin::Float),
                    is_public: true,
                    is_reference: false,
                });
            }
            "PxMat33" => {
                fields.push(FieldBinding {
                    name: "column0",
                    kind: QualType::Builtin(Builtin::Vec3),
                    is_public: true,
                    is_reference: false,
                });
                fields.push(FieldBinding {
                    name: "column1",
                    kind: QualType::Builtin(Builtin::Vec3),
                    is_public: true,
                    is_reference: false,
                });
                fields.push(FieldBinding {
                    name: "column2",
                    kind: QualType::Builtin(Builtin::Vec3),
                    is_public: true,
                    is_reference: false,
                });
            }
            "PxMat34" => {
                fields.push(FieldBinding {
                    name: "m",
                    kind: QualType::Builtin(Builtin::Mat33),
                    is_public: true,
                    is_reference: false,
                });
                fields.push(FieldBinding {
                    name: "p",
                    kind: QualType::Builtin(Builtin::Vec3),
                    is_public: true,
                    is_reference: false,
                });
            }
            "PxMat44" => {
                fields.push(FieldBinding {
                    name: "column0",
                    kind: QualType::Builtin(Builtin::Vec4),
                    is_public: true,
                    is_reference: false,
                });
                fields.push(FieldBinding {
                    name: "column1",
                    kind: QualType::Builtin(Builtin::Vec4),
                    is_public: true,
                    is_reference: false,
                });
                fields.push(FieldBinding {
                    name: "column2",
                    kind: QualType::Builtin(Builtin::Vec4),
                    is_public: true,
                    is_reference: false,
                });
                fields.push(FieldBinding {
                    name: "column3",
                    kind: QualType::Builtin(Builtin::Vec4),
                    is_public: true,
                    is_reference: false,
                });
            }
            "PxTransform" => {
                fields.push(FieldBinding {
                    name: "q",
                    kind: QualType::Builtin(Builtin::Quat),
                    is_public: true,
                    is_reference: false,
                });
                fields.push(FieldBinding {
                    name: "p",
                    kind: QualType::Builtin(Builtin::Vec3),
                    is_public: true,
                    is_reference: false,
                });
            }
            other => anyhow::bail!("template typedef {other} is not implemented"),
        }

        let name = &td.name;
        let (node, ast) = super::search(root, &|node: &Node| match &node.kind {
            Item::ClassTemplateSpecializationDecl(rec) | Item::CXXRecordDecl(rec) => {
                (rec.name.as_deref() == Some(template_name)).then_some(rec)
            }
            _ => None,
        })
        .with_context(|| format!("failed to locate template specialization for {name}"))?;

        self.recs.push(RecBinding {
            name,
            has_vtable: ast.is_polymorphic(),
            fields,
            ast,
            is_empty: false,
        });

        self.classes.insert(name, (node, ast));

        Ok(())
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

        let mut is_public = !matches!(rec.tag_used, Some(Tag::Class));

        let mut fields = Vec::new();

        for base in &rec.bases {
            let Some(base_name) = base.kind.qual_type.strip_prefix("physx::") else {
                println!("skipping non-physx base '{}'", base.kind.qual_type);
                continue;
            };
            let base_rec = self
                .recs
                .iter()
                .find(|r| r.name == base_name)
                .with_context(|| {
                    format!(
                        "failed to find base '{}' for '{rname}'",
                        base.kind.qual_type
                    )
                })?;
            fields.extend(base_rec.fields.iter().cloned());
        }

        self.get_fields(node, rec, &mut fields)?;

        // Keep a record of each method that we are binding, to account for
        // overloading, particularly constructors, we need to append a counter
        // to keep the binding functions unique
        let mut meth_map = std::collections::BTreeMap::<String, u8>::new();

        let mut get_name = |req: String| -> String {
            match meth_map.get_mut(&req) {
                Some(count) => {
                    *count += 1;
                    format!("{req}_{count}")
                }
                None => {
                    meth_map.insert(req.clone(), 0);
                    req
                }
            }
        };

        for inn in &node.inner {
            // Ignore any method that isn't public, it's not part of the API we care about
            if let Some(method) = inn.kind.as_method() {
                if !is_public {
                    continue;
                } else if self.is_ignored(inn) {
                    println!("skipping deprecated method {rname}::{}", method.name);
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
                            ext: FuncBindingExt::IsDelete(&rname),
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

            self.consume_method(inn, method, func)?;
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

    fn get_fields(
        &self,
        node: &'ast Node,
        rec: &'ast Record,
        fields: &mut Vec<FieldBinding<'ast>>,
    ) -> anyhow::Result<()> {
        let Some(rname) = rec.name.as_deref() else { return Ok(()) };
        let mut is_public = !matches!(rec.tag_used, Some(Tag::Class));

        for inn in &node.inner {
            // Note we could get comments for fields here, but due to the rust
            // declarations being emitted by structgen, it becomes a bit noisy

            match &inn.kind {
                Item::AccessSpecDecl { access } => {
                    is_public = matches!(access, Access::Public);
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
                }
                _ => {}
            }
        }

        Ok(())
    }
}
