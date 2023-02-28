use super::{Comment, Item, Method, QualType, TemplateArg};
use crate::Node;
use anyhow::Context as _;
use std::borrow::Cow;

#[derive(serde::Deserialize, Debug)]
pub struct Function {
    pub name: String,
    #[serde(rename = "type")]
    pub kind: super::Type,
    pub range: Option<clang_ast::SourceRange>,
}

#[derive(Debug)]
pub struct Param<'ast> {
    pub name: Cow<'ast, str>,
    pub kind: QualType<'ast>,
}

impl<'ast> Param<'ast> {
    #[inline]
    pub fn self_pod(rec_type: QualType<'ast>, is_const: bool) -> Self {
        Self {
            name: Cow::Borrowed("self_"),
            kind: QualType::Pointer {
                is_const: false,
                is_pointee_const: is_const,
                pointee: Box::new(rec_type),
            },
        }
    }
}

pub enum PhysxInvoke<'ast> {
    /// Normal function call. Not many of these in PhysX, it's pretty OO
    Func { func_name: &'ast str, is_c: bool },
    /// Method call
    Method {
        func_name: &'ast str,
        class_name: &'ast str,
        is_static: bool,
    },
    /// Constructor call
    Ctor(&'ast str),
    /// New
    New(&'ast str),
}

pub enum FuncBindingExt<'ast> {
    IsDelete(&'ast str),
    None(PhysxInvoke<'ast>),
    HasSelf(PhysxInvoke<'ast>),
}

pub struct FuncBinding<'ast> {
    pub name: String,
    pub comment: Option<Comment<'ast>>,
    pub ext: FuncBindingExt<'ast>,
    pub params: Vec<Param<'ast>>,
    pub ret: Option<QualType<'ast>>,
}

impl<'ast> FuncBinding<'ast> {
    pub fn owning_class(&self) -> Option<&'ast str> {
        match &self.ext {
            FuncBindingExt::None(pi) | FuncBindingExt::HasSelf(pi) => match pi {
                PhysxInvoke::Ctor(name)
                | PhysxInvoke::New(name)
                | PhysxInvoke::Method {
                    class_name: name, ..
                } => Some(name),
                PhysxInvoke::Func { .. } => None,
            },
            FuncBindingExt::IsDelete(class_name) => Some(class_name),
        }
    }
}

impl<'ast> super::AstConsumer<'ast> {
    /// Retrieves a unique name for the function to ensure that overloads have
    /// different names. It also appends `phys_` before the name to ensure that
    /// the C++ code compiles by avoiding errors due to functions that only
    /// differ by return type being ambiguous
    fn get_func_name(&mut self, name: &'ast str) -> String {
        if let Some(count) = self.func_map.get_mut(name) {
            *count += 1;
            format!("phys_{name}_{count}")
        } else {
            self.func_map.insert(name, 0);
            format!("phys_{name}")
        }
    }

    pub fn consume_function(
        &mut self,
        node: &'ast Node,
        func: &'ast Function,
        template_types: &[(&str, &TemplateArg<'ast>)],
        is_c: bool,
    ) -> anyhow::Result<()> {
        if func.name.starts_with("operator") {
            return Ok(());
        }

        // Check the source location for the function
        //
        // - PxMath - trivial functions that we can just do in Rust if needed
        // without crossing the FFI boundary
        // - PxString - internal-only string funtions we don't care about
        // - PxUtilities - useless internal-only functions
        // - PxAtomic - internal-only functions
        // - PxHash - internal-only functions
        let ignored = [
            "PxMath.h",
            "PxString.h",
            "PxUtilities.h",
            "PxAtomic.h",
            "PxHash.h",
        ];
        if func
            .range
            .as_ref()
            .and_then(|r| r.begin.expansion_loc.as_ref())
            .map_or(false, |el| {
                el.file
                    .rfind('/')
                    .map_or(false, |sep| ignored.contains(&&el.file[sep + 1..]))
            })
        {
            log::debug!("skipping PxMath.h function {}", func.name);
            return Ok(());
        }

        let comment = Self::get_comment(node);

        let mut fb = FuncBinding {
            name: self.get_func_name(&func.name),
            comment,
            ext: FuncBindingExt::None(PhysxInvoke::Func {
                func_name: &func.name,
                is_c,
            }),
            ret: None,
            params: Vec::new(),
        };

        self.consume_return(&func.name, &func.kind.qual_type, template_types, &mut fb)?;
        self.consume_params(&func.name, node, template_types, &mut fb)?;

        self.funcs.push(fb);
        Ok(())
    }

    pub fn consume_method(
        &mut self,
        node: &'ast Node,
        meth: &'ast Method,
        template_types: &[(&str, &TemplateArg<'ast>)],
        mut func: FuncBinding<'ast>,
    ) -> anyhow::Result<()> {
        if meth.kind.qual_type.contains('<') {
            log::debug!(
                "ignoring method '{}' which has 1 or more templated parameters",
                meth.name
            );
        }

        self.consume_return(&meth.name, &meth.kind.qual_type, template_types, &mut func)?;
        self.consume_params(&meth.name, node, template_types, &mut func)?;

        self.funcs.push(func);

        Ok(())
    }

    #[inline]
    fn consume_params(
        &self,
        name: &'ast str,
        node: &'ast Node,
        template_types: &[(&str, &TemplateArg<'ast>)],
        func: &mut FuncBinding<'ast>,
    ) -> anyhow::Result<()> {
        for (i, param) in node
            .inner
            .iter()
            .filter_map(|inn| {
                if let Item::ParmVarDecl(param) = &inn.kind {
                    Some(param)
                } else {
                    None
                }
            })
            .enumerate()
        {
            let pname = param
                .name
                .as_deref()
                .map_or_else(|| format!("anon_param{i}").into(), Cow::Borrowed);
            let kind = self
                .parse_type(&param.kind, template_types)
                .with_context(|| {
                    format!(
                        "failed to parse parameter '{pname} ({})' for function '{name}'",
                        param.kind.qual_type,
                    )
                })?;

            func.params.push(Param { name: pname, kind });
        }

        Ok(())
    }

    /// Unfortunately `CXXMethodDecl`'s don't have a node for the return type,
    /// so we need to manually parse it from the function signature...
    #[inline]
    fn consume_return(
        &self,
        name: &str,
        sig: &'ast str,
        template_types: &[(&str, &TemplateArg<'ast>)],
        func: &mut FuncBinding<'ast>,
    ) -> anyhow::Result<()> {
        // Ignore functions that already have a return type, notably constructors
        if func.ret.is_none() {
            let open_ind = sig
                .find('(')
                .with_context(|| format!("function signature for '{name}' doesn't have a '('"))?;

            let ret = sig[..open_ind].trim();
            if ret != "void" {
                func.ret = Some(
                    self.parse_type(ret, template_types)
                        .with_context(|| format!("failed to parse return type for '{name}'"))?,
                );
            }
        }

        Ok(())
    }
}
