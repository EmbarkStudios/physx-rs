use super::{Comment, Item, Method, QualType};
use crate::Node;
use anyhow::Context as _;
use std::borrow::Cow;

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
    pub fn consume_method(
        &mut self,
        node: &'ast Node,
        meth: &'ast Method,
        mut func: FuncBinding<'ast>,
    ) -> anyhow::Result<()> {
        // Unfortunately CXXMethodDecl's don't have a node for the return type,
        // so we need to manually parse it from the function signature...
        self.consume_return(&meth.name, &meth.kind.qual_type, &mut func)?;
        self.consume_params(&meth.name, node, &mut func)?;

        self.funcs.push(func);

        Ok(())
    }

    #[inline]
    fn consume_params(
        &self,
        name: &'ast str,
        node: &'ast Node,
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
            func.params.push(Param {
                name: param
                    .name
                    .as_deref()
                    .map_or_else(|| format!("anon_param{i}").into(), Cow::Borrowed),
                kind: self.parse_type(&param.kind).with_context(|| {
                    format!(
                        "failed to parse parameter '{:?}({})' for function '{name}'",
                        param.name, param.kind.qual_type,
                    )
                })?,
            });
        }

        Ok(())
    }

    #[inline]
    fn consume_return(
        &self,
        name: &str,
        sig: &'ast str,
        func: &mut FuncBinding<'ast>,
    ) -> anyhow::Result<()> {
        let open_ind = sig
            .find('(')
            .with_context(|| format!("function signature for '{name}' doesn't have a '('"))?;

        if func.ret.is_none() {
            let ret = sig[..open_ind].trim();
            if ret != "void" {
                func.ret = Some(
                    self.parse_type(ret)
                        .with_context(|| format!("failed to parse return type for '{name}'"))?,
                );
            }
        }

        Ok(())
    }
}
