// @generated by autocargo

use std::env;
use std::fs;
use std::path::Path;
use thrift_compiler::Config;
use thrift_compiler::GenContext;
const CRATEMAP: &str = "\
thrift/annotation/compat.thrift compat //thrift/annotation:compat-rust
thrift/annotation/cpp.thrift cpp //thrift/annotation:cpp-rust
thrift/annotation/go.thrift go //thrift/annotation:go-rust
thrift/annotation/hack.thrift hack //thrift/annotation:hack-rust
thrift/annotation/internal.thrift internal //thrift/annotation:internal-rust
thrift/annotation/java.thrift java //thrift/annotation:java-rust
thrift/annotation/python.thrift python //thrift/annotation:python-rust
thrift/annotation/rust.thrift rust //thrift/annotation:rust-rust
thrift/annotation/scope.thrift scope //thrift/annotation:scope-rust
thrift/annotation/thrift.thrift thrift //thrift/annotation:thrift-rust
thrift/facebook/erlang/annotation.thrift annotations //thrift/facebook/erlang:annotations-rust
";
#[rustfmt::skip]
fn main() {
    println!("cargo:rerun-if-changed=thrift_build.rs");
    let out_dir = env::var_os("OUT_DIR").expect("OUT_DIR env not provided");
    let cratemap_path = Path::new(&out_dir).join("cratemap");
    fs::write(cratemap_path, CRATEMAP).expect("Failed to write cratemap");
    Config::from_env(GenContext::Services)
        .expect("Failed to instantiate thrift_compiler::Config")
        .base_path("../../../../../..")
        .types_crate("all__types")
        .clients_crate("all__clients")
        .run([] as [&Path; 0])
        .expect("Failed while running thrift compilation");
}
