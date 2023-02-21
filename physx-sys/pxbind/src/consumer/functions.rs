use super::{Comment, Item, Method, QualType, TemplateArg};
use crate::Node;
use anyhow::Context as _;
use std::borrow::Cow;

#[derive(serde::Deserialize, Debug)]
pub struct Function {
    pub name: String,
    #[serde(rename = "type")]
    pub kind: super::Type,
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
                is_const,
                pointee: Box::new(rec_type),
            },
        }
    }
}

pub enum PhysxInvoke<'ast> {
    /// Normal function call. Not many of these in PhysX, it's pretty OO
    Func { func_name: &'ast str },
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
                _ => None,
            },
            FuncBindingExt::IsDelete(class_name) => Some(class_name),
        }
    }
}

impl<'ast> super::AstConsumer<'ast> {
    pub fn consume_function(
        &mut self,
        node: &'ast Node,
        func: &'ast Function,
        template_types: &[(&str, &TemplateArg<'ast>)],
    ) -> anyhow::Result<()> {
        if func.name.starts_with("operator") {
            return Ok(());
        }

        let comment = Self::get_comment(node);

        let mut fb = FuncBinding {
            name: func.name.to_owned(),
            comment,
            ext: FuncBindingExt::None(PhysxInvoke::Func {
                func_name: &func.name,
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

    /// Unfortunately CXXMethodDecl's don't have a node for the return type,
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
