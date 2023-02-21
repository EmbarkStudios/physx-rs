pub mod consumer;
mod dump;
pub mod generator;

pub use dump::*;

pub type Node = clang_ast::Node<consumer::Item>;
