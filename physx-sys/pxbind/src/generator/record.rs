use super::{Indent, SG, UOF};

impl<'ast> crate::consumer::RecBinding<'ast> {
    /// Decide whether we should use "structgen" to calculate the exact layout of
    /// this C++ struct.
    ///
    /// Ideally we would do this for all types, but we must be able to name them,
    /// which is not feasible for anonymous types, or types which the generator
    /// doesn't support yet (their cppTypeName will be empty).
    ///
    /// Note that empty types are only refered to by pointers and references in
    /// PhysX, so we can generate dummy contents for them.
    #[inline]
    fn should_calculate_layout(&self) -> bool {
        self.ast.definition_data.is_some()
            && !matches!(self.ast.tag_used, crate::consumer::Tag::Union)
            && !self.is_empty
    }

    pub(super) fn emit_structgen(&self, writer: &mut String, level: u32) {
        if self.should_calculate_layout() {
            self.emit_structgen_calc(writer, level);
        } else {
            self.emit_structgen_passthrough(writer, level);
        }
    }

    fn emit_structgen_calc(&self, w: &mut String, level: u32) {
        let indent = Indent(level);
        let indent1 = Indent(level + 1);
        let indent2 = Indent(level + 2);

        let name = self.name;

        writesln!(
            w,
            "{indent}struct physx_{name}_Pod: public physx::{name} {{"
        );
        writesln!(w, "{indent1}static void dump_layout(PodStructGen& {SG}) {{");
        writesln!(
            w,
            r#"{indent2}{SG}.begin_struct("physx_{name}_Pod", "{name}");"#
        );

        for field in &self.fields {
            if !field.is_public || field.is_reference {
                continue;
            }

            let fname = field.name;
            let cpp_type = field.kind.cpp_type();
            let rust_type = field.kind.rust_type();

            writesln!(
                w,
                r#"{indent2}{SG}.add_field("{cpp_type} {fname}", "{fname}", "{rust_type}", sizeof({cpp_type}), {UOF}(physx_{name}_Pod, {fname});"#
            );
        }

        writesln!(w, "{indent2}{SG}.end_struct(sizeof(physx::{name}));");
        writesln!(w, "{indent1}}}\n{indent}}};");
        writesln!(w, "{indent}physx_{name}_Pod::dump_layout({SG});");
    }

    fn emit_structgen_passthrough(&self, w: &mut String, level: u32) {
        let indent = Indent(level);

        writes!(w, "{indent}{SG}.pass_thru(\"struct physx_{}_Pod", self.name);

        if self.ast.definition_data.is_none() {
            writesln!(w, ";\\n\");");
            return;
        }

        writes!(w, " {{\\n");

        if self.has_vtable {
            writes!(w, "    void* vtable_;\\n");
        }

        for field in &self.fields {
            writes!(w, "    {} {};\\n", field.kind.cpp_type(), field.name);
        }

        writesln!(w, "}};\\n\");");
    }

    pub fn emit_rust(&self, w: &mut String, level: u32) -> bool {
        if dbg!(self.should_calculate_layout()) {
            return false;
        }

        let indent = Indent(level);
        let indent1 = Indent(level + 1);

        writesln!(w, "{indent}#[derive(Clone, Copy)]");
        writesln!(w, "{indent}#[repr(C)]");
        writesln!(
            w,
            "{indent}pub {} {} {{",
            if matches!(self.ast.tag_used, crate::consumer::Tag::Union) {
                "union"
            } else {
                "struct"
            },
            self.name
        );

        if self.has_vtable {
            writesln!(w, "{indent1}vtable_: *const std::ffi::c_void,");
        }

        for field in &self.fields {
            if field.is_public {
                writes!(w, "{indent1}pub ");
            }

            writesln!(w, "{}: {},", field.name, field.kind.rust_type());
        }

        writesln!(w, "{indent}}}");
        true
    }
}
