#![warn(clippy::all)]
#![warn(rust_2018_idioms)]
#![recursion_limit = "128"]

//! # 🎳 physx-macros
//!
//! [![Build Status](https://travis-ci.com/EmbarkStudios/physx-rs.svg?branch=master)](https://travis-ci.com/EmbarkStudios/physx-rs)
//! [![Crates.io](https://img.shields.io/crates/v/physx-macros.svg)](https://crates.io/crates/physx-macros)
//! [![Docs](https://docs.rs/physx/badge.svg)](https://docs.rs/physx)
//! [![Contributor Covenant](https://img.shields.io/badge/contributor%20covenant-v1.4%20adopted-ff69b4.svg)](../CODE_OF_CONDUCT.md)
//! [![Embark](https://img.shields.io/badge/embark-open%20source-blueviolet.svg)](http://embark.games)
//!
//! Utility macros used internally by the [`physx`](https://crates.io/crates/physx) crate.
//!
//! ## License
//!
//! Licensed under either of
//!
//! * Apache License, Version 2.0, ([LICENSE-APACHE](../LICENSE-APACHE) or http://www.apache.org/licenses/LICENSE-2.0)
//! * MIT license ([LICENSE-MIT](../LICENSE-MIT) or http://opensource.org/licenses/MIT)
//!
//! at your option.
//!
//! Note that the [PhysX C++ SDK](https://github.com/NVIDIAGameWorks/PhysX) has it's [own BSD 3 license](https://gameworksdocs.nvidia.com/PhysX/4.1/documentation/physxguide/Manual/License.html) and depends on [additional C++ third party libraries](https://github.com/NVIDIAGameWorks/PhysX/tree/4.1/externals).
//!
//! ### Contribution
//!
//! Unless you explicitly state otherwise, any contribution intentionally
//! submitted for inclusion in the work by you, as defined in the Apache-2.0
//! license, shall be dual licensed as above, without any additional terms or
//! conditions.

use proc_macro2::{Ident, Span, TokenStream, TokenTree};
use quote::quote;
use syn::{parse_macro_input, AttributeArgs, Lit, Meta, NestedMeta};

#[proc_macro_attribute]
pub fn physx_type(
    attr: proc_macro::TokenStream,
    item: proc_macro::TokenStream,
) -> proc_macro::TokenStream {
    let item = proc_macro2::TokenStream::from(item);
    let attr = MacroArgs::from_meta(parse_macro_input!(attr as AttributeArgs));
    let itm = item.clone();
    let info = ParseTarget::parse(itm);
    let name = info.name;
    let pxname = Ident::new(&(String::from("Px") + &name.to_string()), Span::call_site());

    let output1 = quote! {
        pub type #name = PxType<#pxname>;
        impl PxPtr for #pxname {}

    };

    let ts = if let Some(inherit) = attr.inherit {
        let parent = Ident::new(&inherit, Span::call_site());
        quote! {
        use core::ops::{Deref, DerefMut};
        impl Deref for #name {
            type Target = #parent;
            fn deref(&self) -> &Self::Target {
                self.as_ptr()
            }
        }

        impl DerefMut for #name {
            fn deref_mut(&mut self) -> &mut Self::Target {
                self.as_ptr_mut()
            }
        }
        }
    } else {
        TokenStream::new()
    };

    let output: TokenStream = output1
        .into_iter()
        .chain(ts.into_iter())
        .chain(item.into_iter())
        .collect();

    proc_macro::TokenStream::from(output)
}

#[derive(Debug)]
struct ParseTarget {
    name: Ident,
}

impl ParseTarget {
    fn parse(stream: TokenStream) -> Self {
        let mut iter = stream.into_iter();
        let _struct_token = iter.next();
        let name = iter.next();
        let name = if let Some(f) = name {
            if let TokenTree::Ident(f) = f {
                Some(f)
            } else {
                None
            }
        } else {
            None
        };

        ParseTarget {
            name: name.unwrap(),
        }
    }
}
#[derive(Default, Debug)]
struct MacroArgs {
    inherit: Option<String>,
}

impl MacroArgs {
    fn from_meta(args: AttributeArgs) -> Self {
        let mut margs = Self::default();

        for item in args.iter() {
            match item {
                NestedMeta::Meta(meta) => {
                    if let Meta::NameValue(namevalue) = meta {
                        match meta.path().get_ident() {
                            Some(ident) if ident == "inherit" => {
                                margs.inherit = visit_literal_to_string(&namevalue.lit)
                            }
                            _ => (),
                        }
                    }
                }
                NestedMeta::Lit(_) => panic!("Expected ident but found literal"),
            }
        }
        margs
    }
}

fn visit_literal_to_string(lit: &Lit) -> Option<String> {
    match lit {
        Lit::Str(val) => Some(val.value()),
        _ => None,
    }
}
