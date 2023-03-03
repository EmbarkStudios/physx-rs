#![allow(unused)]

use crate::Node;

use super::{AstConsumer, Builtin, QualType, Record};
use anyhow::Context as _;
use std::borrow::Cow;

#[derive(PartialEq)]
pub enum TemplateArg<'ast> {
    Type(QualType<'ast>),
    Value(u32),
}

struct TemplateParam<'ast> {
    name: &'ast str,
    builtin: Option<Builtin>,
}

enum TemplateItemKind<'ast> {
    Concrete(QualType<'ast>),
    Parameterized(&'ast str),
}

struct TemplateItem<'ast> {
    name: &'ast str,
    kind: TemplateItemKind<'ast>,
}

struct TemplateMethod<'ast> {
    name: String,
    params: Vec<TemplateItem<'ast>>,
}

struct TemplateStamp<'ast> {
    name: Cow<'ast, str>,
    args: Vec<TemplateArg<'ast>>,
}

pub struct Template<'ast> {
    params: Vec<TemplateParam<'ast>>,
    instanced: Vec<TemplateStamp<'ast>>,
    /// This is the
    top_record: &'ast Record,
    def_record: &'ast Node,
}

impl<'ast> Template<'ast> {
    fn parse_template_args(
        &self,
        ast: &AstConsumer<'ast>,
        qt: &'ast str,
    ) -> anyhow::Result<Vec<TemplateArg<'ast>>> {
        let begin = qt.find('<').context("not a template")?;
        let end = qt.rfind('>').context("not a template")?;

        let mut targs = Vec::new();
        for (arg, param) in qt[begin + 1..end].split(',').zip(self.params.iter()) {
            // We don't really do error checking here, if the templates are messed
            // up PhysX won't compile
            if param.builtin.is_some() {
                targs.push(TemplateArg::Value(arg.parse()?));
            } else {
                targs.push(TemplateArg::Type(ast.parse_type(arg, &[])?));
            }
        }

        Ok(targs)
    }

    #[inline]
    fn get_stamped(&self, args: &[TemplateArg<'ast>]) -> Option<Cow<'ast, str>> {
        self.instanced
            .iter()
            .find_map(|i| (i.args == args).then(|| i.name.clone()))
    }
}

impl<'ast> AstConsumer<'ast> {
    pub(super) fn consume_template_instance(
        &mut self,
        qual_type: &'ast str,
        name: Option<&'ast str>,
    ) -> anyhow::Result<Cow<'ast, str>> {
        let qual_type = if let Some(stripped) = qual_type.strip_prefix("const ") {
            stripped
        } else {
            qual_type
        };

        let begin = qual_type.find('<').context("this isn't a template")?;

        let template_name = &qual_type[..begin];
        let tdecl = self
            .templates
            .get(template_name)
            .with_context(|| format!("template decl '{template_name}' has not been consumed"))?;

        let targs = tdecl.parse_template_args(self, qual_type)?;

        // If we've already stamped out this template just return the name it was given
        if let Some(stamped) = tdecl.get_stamped(&targs) {
            return Ok(stamped);
        }

        let instance_name = name.map_or_else(
            || Cow::Owned(format!("{template_name}_T{}", tdecl.instanced.len())),
            Cow::Borrowed,
        );

        let mut mappings: Vec<_> = targs
            .iter()
            .zip(tdecl.params.iter())
            .map(|(ta, tp)| (tp.name, ta))
            .collect();

        let mut fields = Vec::new();
        self.get_fields(tdecl.def_record, tdecl.top_record, &mappings, &mut fields)?;

        Ok(instance_name)
    }

    pub(super) fn consume_template_decl(
        &mut self,
        node: &'ast Node,
        name: &'ast str,
    ) -> anyhow::Result<()> {
        anyhow::ensure!(
            !self.templates.contains_key(name),
            "template '{name}' has already been consumed"
        );

        unreachable!();
    }
}
