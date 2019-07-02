#![warn(clippy::all)]
#![warn(rust_2018_idioms)]
#![recursion_limit = "128"]
extern crate proc_macro;

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
                        if namevalue.ident == "inherit" {
                            margs.inherit = visit_literal_to_string(&namevalue.lit);
                        }
                    }
                }
                NestedMeta::Literal(lit) => eprintln!("lit {:?}", lit),
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
