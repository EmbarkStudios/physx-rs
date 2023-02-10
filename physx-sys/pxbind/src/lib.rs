pub mod consumer;
mod dump;
pub mod generator;

pub use dump::{get_ast, get_parsed_ast};

pub type Node = clang_ast::Node<consumer::Item>;
