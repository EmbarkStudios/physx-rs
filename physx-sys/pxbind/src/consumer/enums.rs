use super::{Builtin, Comment, EnumDecl, Item, Node, Typedef};
use anyhow::Context as _;

pub struct EnumVariant<'ast> {
    /// The name of the variant
    pub name: &'ast str,
    /// The constant value of the variant
    pub value: i64,
    /// Text comment on the enum constant
    pub comment: Option<Comment<'ast>>,
}

pub struct EnumBinding<'ast> {
    /// The repr() applied to the the Rust enum to get it the correct size
    pub repr: Builtin,
    /// The "friendly" name of the enum, eg `PxErrorCode`
    pub name: &'ast str,
    /// The qualified type of the enum, minus the physx:: namespace since all
    /// the c/cpp code we compile is done within that namespace, eg. PxErrorCode::Enum
    pub cxx_qt: &'ast str,
    /// Text comment on the enum (or more usually, the wrapping struct)
    pub comment: Option<Comment<'ast>>,
    /// The list of constants
    pub variants: Vec<EnumVariant<'ast>>,
}

pub struct FlagsBinding<'ast> {
    /// The name of the typedef used in the public API
    pub name: &'ast str,
    /// The index in the AstConsumer of the enum binding
    pub enums_index: usize,
    /// The storage type used by the flags
    pub storage_type: super::Builtin,
}

impl<'ast> super::AstConsumer<'ast> {
    pub(super) fn consume_enum(
        &mut self,
        parent: &'ast Node,
        enum_node: &'ast Node,
        enum_decl: &'ast EnumDecl,
    ) -> anyhow::Result<()> {
        let comment = match Self::get_comment(enum_node) {
            Some(com) => Some(com),
            None => {
                // If the comment isn't directly on the enum itself, check if
                // the parent is a struct since most physx enums follow the classic
                // struct EnumName { enum Enum {}; }; pattern
                if matches!(parent.kind, Item::CXXRecordDecl(_)) {
                    Self::get_comment(parent)
                } else {
                    None
                }
            }
        };

        let name = if let Item::CXXRecordDecl(rec) = &parent.kind {
            if let Some(rname) = rec.name.as_deref() {
                // Check if the record is actually not just a wrapper (ie, has fields or methods)
                // as that means we'll need to the name the enum with the inner name
                // as that is _probably_ still unique
                if parent
                    .inner
                    .iter()
                    .any(|inn| matches!(&inn.kind, Item::FieldDecl { .. }))
                {
                    if let Some(ename) = enum_decl.name.as_deref() {
                        ename
                    } else {
                        log::debug!("Wrapper struct {rname} that will also be a POD contained an anonymous enum");
                        return Ok(());
                    }
                } else {
                    rname
                }
            } else {
                log::debug!(
                    "skipping enum {:?} with anonymous wrapper struct",
                    enum_decl.name
                );
                return Ok(());
            }
        } else if let Some(ename) = enum_decl.name.as_deref() {
            ename
        } else {
            log::debug!("skipping anonymous enum");
            return Ok(());
        };

        let mut repr = Builtin::Int;
        let mut variants = Vec::new();

        // Unfortunately the qualified type isn't present on the enum itself,
        // but rather each and every variant. They _should_ all be the same
        let mut cxx_qt = None;

        fn get_value(node: &Node, current: i64, repr: &mut Builtin) -> anyhow::Result<i64> {
            for inn in &node.inner {
                match &inn.kind {
                    Item::ImplicitCastExpr { .. } => {
                        return get_value(inn, current, repr);
                    }
                    Item::ConstantExpr { value, kind } => {
                        // There are a couple of cases where clang will emit
                        // unsigned int for some variants and int for others,
                        // so we need to just ignore changes once it's not the default
                        if matches!(repr, Builtin::Int) {
                            if let Some(builtin) = super::AstConsumer::parse_builtin(kind) {
                                *repr = builtin;
                            }
                        }

                        return value.parse().context("failed to parse enum constant");
                    }
                    _ => continue,
                }
            }

            Ok(current)
        }

        let mut current = 0;

        for (varn, vard) in enum_node.inner.iter().filter_map(|inn| {
            if let Item::EnumConstantDecl(cdecl) = &inn.kind {
                Some((inn, cdecl))
            } else {
                None
            }
        }) {
            if Self::is_deprecated(varn) {
                log::debug!("ignoring deprecated variant {name}::{}", vard.name);
                continue;
            }

            let name = &vard.name;

            if let Some(cxx_qt) = cxx_qt {
                anyhow::ensure!(
                    cxx_qt == vard.kind.qual_type,
                    "enum has mismatching qualified types current: '{cxx_qt}', new: '{}'",
                    vard.kind.qual_type
                );
            } else {
                cxx_qt = Some(vard.kind.qual_type.as_str());
            }

            let comment = Self::get_comment(varn);
            let value = get_value(varn, current, &mut repr)?;

            current = value + 1;

            variants.push(EnumVariant {
                name,
                comment,
                value,
            });
        }

        // All cpp code is used within the physx namespace, so strip that prefix
        let cxx_qt =
            cxx_qt.with_context(|| format!("enum '{name}' never declared a qualified typename"))?;
        let cxx_qt = super::no_physx(cxx_qt);

        self.enums.push(EnumBinding {
            repr,
            name,
            cxx_qt,
            comment,
            variants,
        });
        self.enum_map.insert(cxx_qt, (repr, name));

        Ok(())
    }

    pub(super) fn consume_flags(
        &mut self,
        _node: &'ast Node,
        td: &'ast Typedef,
    ) -> anyhow::Result<()> {
        // PhysX uses a PxFlags<> template typedef to create a bitfield type for
        // a specific enum, we use this typedef to also generate an appropriate
        // bitflags that can be transparently passed between the FFI boundary
        let Some(flags) = super::no_physx(&td.kind.qual_type).strip_prefix("PxFlags<") else {
            return Ok(());
        };
        // Get rid of `>`
        let flags = &flags[..flags.len() - 1];

        let mut iter = flags.split(',');

        // PxFlags<PxDistanceJointFlag::Enum, physx::PxU16>
        // First template parameter is the enum type being wrapped
        let enum_type = iter
            .next()
            .with_context(|| format!("PxFlags typedef '{}' did not specify an enum type", td.name))?
            .trim();

        // Second is the storage type, which _should_ always be an unsigned integer
        // type, so we assert on this to ensure shenanigans aren't happening
        // Though the PxFlags template allows for defaulting to u32 for storage,
        // this is not used AFAICT in PhysX, so we require that the storage
        // type be specified as well, for now
        let storage_type = iter
            .next()
            .with_context(|| {
                format!(
                    "PxFlags typedef '{}' did not specify a storage type",
                    td.name
                )
            })?
            .trim();

        let storage_type = Self::parse_builtin(storage_type).with_context(|| {
            format!(
                "PxFlags typedef '{}' has storage type '{storage_type}' which is not a builtin",
                td.name
            )
        })?;

        // Find the enum binding, we use this later when generating the bitflags,
        // we search in reverse order since the enum being wrapped almost always
        // comes directly before the flags typedef
        let enums_index = self
            .enums
            .iter()
            .rposition(|eb| eb.cxx_qt == enum_type)
            .with_context(|| {
                format!(
                    "PxFlags typedef '{}' references unknown enum type '{enum_type}'",
                    td.name
                )
            })?;

        self.flags.push(FlagsBinding {
            name: &td.name,
            enums_index,
            storage_type,
        });
        self.flags_map.insert(&td.name, storage_type);

        Ok(())
    }
}
