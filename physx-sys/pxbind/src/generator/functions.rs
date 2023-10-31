use super::Indent;
use crate::consumer::{functions::*, QualType};

const RET: &str = "return_val";
const RET_POD: &str = "return_val_pod";

impl<'ast> Param<'ast> {
    fn write_c_to_cpp(&self, out: &mut String, level: u32) {
        let name = &self.name;

        let indent = Indent(level);

        match &self.kind {
            QualType::Builtin(bi) => {
                // This means we got a pod type by value, so we need to copy
                // from the C pod to the C++ type
                writesln!(out, "{indent}{} {name};", bi.cpp_type());
                writesln!(out, "{indent}memcpy(&{name}, &{name}_pod, sizeof({name}));");
            }
            QualType::Pointer { .. } => {
                let ty = self.kind.cpp_type();
                writesln!(
                    out,
                    "{indent}{ty} {name} = reinterpret_cast<{ty}>({name}_pod);",
                );
            }
            QualType::Reference { pointee, .. } => {
                if let QualType::Builtin(bi) = pointee.as_ref() {
                    if !bi.is_pod() {
                        writesln!(
                            out,
                            "{indent}{} {name} = *{name}_pod;",
                            self.kind.cpp_type()
                        );
                        return;
                    }
                }

                let ty = self.kind.cpp_type();
                writesln!(
                    out,
                    "{indent}{ty} {name} = reinterpret_cast<{ty}>(*{name}_pod);",
                );
            }
            QualType::Enum { .. } => {
                writesln!(
                    out,
                    "{indent}auto {name} = static_cast<{}>({name}_pod);",
                    self.kind.cpp_type(),
                );
            }
            QualType::Flags { .. } => {
                writesln!(
                    out,
                    "{indent}auto {name} = {}({name}_pod);",
                    self.kind.cpp_type()
                );
            }
            QualType::Record { .. } => {
                writesln!(out, "{indent}{} {name};", self.kind.cpp_type());
                writesln!(out, "{indent}memcpy(&{name}, &{name}_pod, sizeof({name}));");
            }
            _ => panic!(
                "parameter '{}' kind '{:?}' is not supported ",
                self.name, self.kind
            ),
        }
    }
}

impl<'ast> FuncBinding<'ast> {
    pub(super) fn emit_cpp(&self, acc: &mut String, level: u32) -> anyhow::Result<()> {
        // Emit the function signature, this uses the C pod types that we've
        // generated to wrap the underlying physx C++ types
        {
            let indent = Indent(level);

            writes!(acc, "{indent}");

            if let Some(ret) = &self.ret {
                writes!(acc, "{}", ret.c_type());
            } else {
                acc.push_str("void");
            }

            writes!(acc, " {}(", self.name);

            for (i, param) in self.params.iter().enumerate() {
                let sep = if i > 0 { ", " } else { "" };

                writes!(
                    acc,
                    "{sep}{} {}{}",
                    param.kind.c_type(),
                    param.name,
                    if param.kind.is_pod() { "_pod" } else { "" }
                );
            }

            writesln!(acc, ") {{");
        }

        let indent = Indent(level + 1);

        // Emit the code that converts each argument to an appropriately typed/named
        // c++ variable
        if !self.params.is_empty() {
            for param in self.params.iter().filter(|p| p.kind.is_pod()) {
                param.write_c_to_cpp(acc, level + 1);
            }
        }

        let (invoke, arg_skip) = match &self.ext {
            FuncBindingExt::IsDelete(_) => {
                writesln!(acc, "{indent}delete self_;\n{}}}", Indent(level));
                return Ok(());
            }
            FuncBindingExt::None(inv) => (inv, 0),
            FuncBindingExt::HasSelf(inv) => (inv, 1),
        };

        // Emit the code that actually calls into physx
        let args = self
            .params
            .iter()
            .skip(arg_skip)
            .map(|param| param.name.as_ref());

        invoke.emit(args, self.ret.as_ref(), acc, level + 1);

        if let Some(ret) = &self.ret {
            if !ret.is_pod() {
                writesln!(acc, "{indent}return {RET};");
            } else {
                // If we're a pod type we need to generate the code to convert
                // from the C++ type to the C wrapper
                match ret {
                    QualType::Builtin(bi) => {
                        writesln!(acc, "{indent}{} {RET_POD};", bi.c_type());
                        writesln!(
                            acc,
                            "{indent}memcpy(&{RET_POD}, &{RET}, sizeof({RET_POD}));"
                        );
                    }
                    QualType::Record { name } => {
                        writesln!(acc, "{indent}physx_{name}_Pod {RET_POD};");
                        writesln!(
                            acc,
                            "{indent}memcpy(&{RET_POD}, &{RET}, sizeof({RET_POD}));"
                        );
                    }
                    QualType::Enum { repr, .. } | QualType::Flags { repr, .. } => {
                        writesln!(acc, "{indent}{} {RET_POD};", repr.c_type());
                        writesln!(
                            acc,
                            "{indent}memcpy(&{RET_POD}, &{RET}, sizeof({RET_POD}));"
                        );
                    }
                    QualType::Pointer { .. } => {
                        writesln!(
                            acc,
                            "{indent}auto {RET_POD} = reinterpret_cast<{}>({RET});",
                            ret.c_type()
                        );
                    }
                    QualType::Reference { .. } => {
                        writesln!(
                            acc,
                            "{indent}auto {RET_POD} = reinterpret_cast<{}>(&{RET});",
                            ret.c_type()
                        );
                    }
                    #[allow(clippy::unimplemented)]
                    _ => {
                        unimplemented!("return type is not supported {:?}", ret);
                    }
                }

                writesln!(acc, "{indent}return {RET_POD};");
            }
        }

        writesln!(acc, "{}}}", Indent(level));
        Ok(())
    }

    pub(super) fn emit_rust(&self, writer: &mut String, level: u32) {
        if let Some(com) = &self.comment {
            com.emit_rust(writer, level);
        }

        let indent = Indent(level);
        let mut acc = String::new();

        // write default values of params
        let mut first_param = true;
        for param in self.params.iter() {
            if let Some(v) = &param.default_value {
                if first_param {
                    writesln!(acc, "{indent}///");
                    first_param = false;
                }
                writesln!(acc, "{indent}/// {} = {}", param.name, v);
            }
        }

        writes!(acc, "{indent}pub fn {}(", self.name);

        for (i, param) in self.params.iter().enumerate() {
            // While Rust allows trailing commas in function signatures, it's
            // kind of ugly
            let sep = if i > 0 { ", " } else { "" };

            writes!(
                acc,
                "{sep}{}: {}",
                super::RustIdent(&param.name),
                param.kind.rust_type()
            );
        }

        if let Some(ret) = &self.ret {
            writes!(acc, ") -> {};", ret.rust_type());
        } else {
            writes!(acc, ");");
        }

        writesln!(writer, "{acc}");
    }
}

impl<'ast> PhysxInvoke<'ast> {
    fn emit(
        &self,
        args: impl Iterator<Item = &'ast str>,
        return_type: Option<&QualType<'ast>>,
        out: &mut String,
        level: u32,
    ) {
        let mut args = args.peekable();
        let has_args = args.peek().is_some();

        let indent = Indent(level);

        // Would be nice with https://doc.rust-lang.org/std/iter/trait.Iterator.html#method.intersperse
        // but it's not stable yet
        let emit_args = |out: &mut String| {
            for (i, arg) in args.enumerate() {
                let sep = if i > 0 { ", " } else { "" };

                writes!(out, "{sep}{arg}");
            }
        };

        match self {
            Self::Func { func_name, .. } => {
                writes!(out, "{indent}");
                if let Some(ret) = return_type {
                    writes!(out, "{} {RET} = ", ret.cpp_type());
                }

                writes!(out, "{func_name}(");
                emit_args(out);
                writes!(out, ");\n");
            }
            Self::Method {
                func_name,
                class_name,
                is_static,
            } => {
                writes!(out, "{indent}");
                if let Some(ret) = return_type {
                    writes!(out, "{} {RET} = ", ret.cpp_type());
                }

                if *is_static {
                    writes!(out, "{class_name}::{func_name}(");
                } else {
                    writes!(out, "self_->{func_name}(");
                }

                emit_args(out);
                writes!(out, ");\n");
            }
            Self::Ctor(class) => {
                writes!(out, "{indent}{class} {RET}");
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
                writes!(out, "{indent}auto {RET} = new physx::{}(", class);
                emit_args(out);
                writes!(out, ");\n");
            }
        }
    }
}
