use super::Indent;

impl<'ast> crate::consumer::Comment<'ast> {
    pub(super) fn emit_rust(&self, writer: &mut String, level: u32) {
        let indent = Indent(level);

        let emit_lines = |w: &mut String, lines: &[&str]| {
            for line in lines {
                if line.is_empty() {
                    writesln!(w, "{indent}///");
                // PhysX _tends_ to use `#type::field/variant` style intralinks
                // so attempt to convert them to proper rustdoc style intralinks
                } else if let Some(ind) = line.find('#') {
                    writes!(w, "{indent}/// {}", &line[..ind]);
                    writes!(w, "[`");
                    match line[ind + 1..]
                        .find(|c: char| !c.is_alphanumeric() && c != ':' && c != '_')
                    {
                        Some(end) => {
                            writes!(w, "{}`]", &line[ind + 1..ind + end + 1]);
                            writesln!(w, "{}", &line[ind + end + 1..]);
                        }
                        None => {
                            writesln!(w, "{}`]", &line[ind + 1..]);
                        }
                    };
                } else {
                    writesln!(w, "{indent}/// {line}");
                }
            }
        };

        emit_lines(writer, self.summary.as_slice());

        if !self.additional.is_empty() {
            writesln!(writer, "{indent}///");
            emit_lines(writer, self.additional.as_slice());
        }
    }
}
