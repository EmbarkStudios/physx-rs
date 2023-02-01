mod dump;
pub mod gen;

pub use dump::{get_ast, get_parsed_ast};

pub type Node = clang_ast::Node<gen::Item>;
