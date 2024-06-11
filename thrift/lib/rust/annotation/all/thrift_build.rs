// @generated by autocargo

use std::env;
use std::fs;
use std::path::Path;
use thrift_compiler::Config;
use thrift_compiler::GenContext;
const CRATEMAP: &str = "\
annotation annotations //thrift/facebook/erlang:annotations-rust
compat compat //thrift/annotation:compat-rust
cpp cpp //thrift/annotation:cpp-rust
go go //thrift/annotation:go-rust
hack hack //thrift/annotation:hack-rust
internal internal //thrift/annotation:internal-rust
java java //thrift/annotation:java-rust
python python //thrift/annotation:python-rust
rust rust //thrift/annotation:rust-rust
scope scope //thrift/annotation:scope-rust
thrift thrift //thrift/annotation:thrift-rust
";
#[rustfmt::skip]
fn main() {
    println!("cargo:rerun-if-changed=thrift_build.rs");
    let out_dir = env::var_os("OUT_DIR").expect("OUT_DIR env not provided");
    let cratemap_path = Path::new(&out_dir).join("cratemap");
    fs::write(cratemap_path, CRATEMAP).expect("Failed to write cratemap");
    let mut conf = Config::from_env(GenContext::Types)
        .expect("Failed to instantiate thrift_compiler::Config");
    conf.base_path("../../../../..");
    conf.types_crate("all__types");
    conf.clients_crate("all__clients");
    let srcs: &[&str] = &[];
    conf.run(srcs).expect("Failed while running thrift compilation");
}
