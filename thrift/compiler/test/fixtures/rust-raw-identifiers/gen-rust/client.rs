// @generated by Thrift for thrift/compiler/test/fixtures/rust-raw-identifiers/src/mod.thrift
// This file is probably not the place you want to edit!

//! Client implementation for each service in `mod`.

#![recursion_limit = "100000000"]
#![allow(non_camel_case_types, non_snake_case, non_upper_case_globals, unused_crate_dependencies, unused_imports, clippy::all)]

pub mod mock;

#[doc(inline)]
pub use :: as types;
#[doc(inline)]
pub use ::::errors;
pub(crate) use crate as client;
pub(crate) use ::::services;

// Used by Thrift-generated code to implement service inheritance.
#[doc(hidden)]
#[deprecated]
pub mod dependencies {
}


/// Client definitions for `Foo`.
pub struct FooImpl<P, T, S = ::fbthrift::NoopSpawner> {
    transport: T,
    _phantom: ::std::marker::PhantomData<fn() -> (P, S)>,
}

impl<P, T, S> FooImpl<P, T, S>
where
    P: ::fbthrift::Protocol,
    T: ::fbthrift::Transport,
    P::Frame: ::fbthrift::Framing<DecBuf = ::fbthrift::FramingDecoded<T>>,
    ::fbthrift::ProtocolEncoded<P>: ::fbthrift::BufMutExt<Final = ::fbthrift::FramingEncodedFinal<T>>,
    P::Deserializer: ::std::marker::Send,
    S: ::fbthrift::help::Spawner,
{
    pub fn new(
        transport: T,
    ) -> Self {
        Self {
            transport,
            _phantom: ::std::marker::PhantomData,
        }
    }

    pub fn transport(&self) -> &T {
        &self.transport
    }


    fn _return_impl(
        &self,
        arg_bar: &crate::types::ThereAreNoPascalCaseKeywords,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::foo::ReturnError>> {
        use ::const_cstr::const_cstr;
        use ::tracing::Instrument as _;
        use ::futures::FutureExt as _;

        const_cstr! {
            SERVICE_NAME = "Foo";
            SERVICE_METHOD_NAME = "Foo.return";
        }
        let args = self::Args_Foo_return {
            bar: arg_bar,
            _phantom: ::std::marker::PhantomData,
        };

        let transport = self.transport();

        // need to do call setup outside of async block because T: Transport isn't Send
        let request_env = match ::fbthrift::help::serialize_request_envelope::<P, _>("return", &args) {
            ::std::result::Result::Ok(res) => res,
            ::std::result::Result::Err(err) => return ::futures::future::err(err.into()).boxed(),
        };

        let call = transport
            .call(SERVICE_NAME.as_cstr(), SERVICE_METHOD_NAME.as_cstr(), request_env, rpc_options)
            .instrument(::tracing::trace_span!("call", method = "Foo.return"));

        async move {
            let reply_env = call.await?;

            let de = P::deserializer(reply_env);
            let (res, _de): (::std::result::Result<crate::services::foo::ReturnExn, _>, _) =
                ::fbthrift::help::async_deserialize_response_envelope::<P, _, S>(de).await?;

            let res = match res {
                ::std::result::Result::Ok(exn) => ::std::convert::From::from(exn),
                ::std::result::Result::Err(aexn) =>
                    ::std::result::Result::Err(crate::errors::foo::ReturnError::ApplicationException(aexn))
            };
            res
        }
        .instrument(::tracing::info_span!("stream", method = "Foo.return"))
        .boxed()
    }

    fn _super_impl(
        &self,
        arg_bar: &crate::types::ThereAreNoPascalCaseKeywords,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::foo::SuperError>> {
        use ::const_cstr::const_cstr;
        use ::tracing::Instrument as _;
        use ::futures::FutureExt as _;

        const_cstr! {
            SERVICE_NAME = "Foo";
            SERVICE_METHOD_NAME = "Foo.super";
        }
        let args = self::Args_Foo_super {
            bar: arg_bar,
            _phantom: ::std::marker::PhantomData,
        };

        let transport = self.transport();

        // need to do call setup outside of async block because T: Transport isn't Send
        let request_env = match ::fbthrift::help::serialize_request_envelope::<P, _>("super", &args) {
            ::std::result::Result::Ok(res) => res,
            ::std::result::Result::Err(err) => return ::futures::future::err(err.into()).boxed(),
        };

        let call = transport
            .call(SERVICE_NAME.as_cstr(), SERVICE_METHOD_NAME.as_cstr(), request_env, rpc_options)
            .instrument(::tracing::trace_span!("call", method = "Foo.super"));

        async move {
            let reply_env = call.await?;

            let de = P::deserializer(reply_env);
            let (res, _de): (::std::result::Result<crate::services::foo::SuperExn, _>, _) =
                ::fbthrift::help::async_deserialize_response_envelope::<P, _, S>(de).await?;

            let res = match res {
                ::std::result::Result::Ok(exn) => ::std::convert::From::from(exn),
                ::std::result::Result::Err(aexn) =>
                    ::std::result::Result::Err(crate::errors::foo::SuperError::ApplicationException(aexn))
            };
            res
        }
        .instrument(::tracing::info_span!("stream", method = "Foo.super"))
        .boxed()
    }
}

pub trait Foo: ::std::marker::Send {
    fn r#return(
        &self,
        arg_bar: &crate::types::ThereAreNoPascalCaseKeywords,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::foo::ReturnError>>;

    fn super_(
        &self,
        arg_bar: &crate::types::ThereAreNoPascalCaseKeywords,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::foo::SuperError>>;
}

pub trait FooExt<T>: Foo
where
    T: ::fbthrift::Transport,
{
    fn r#return_with_rpc_opts(
        &self,
        arg_bar: &crate::types::ThereAreNoPascalCaseKeywords,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::foo::ReturnError>>;
    fn super__with_rpc_opts(
        &self,
        arg_bar: &crate::types::ThereAreNoPascalCaseKeywords,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::foo::SuperError>>;

    fn transport(&self) -> &T;
}

struct Args_Foo_return<'a> {
    bar: &'a crate::types::ThereAreNoPascalCaseKeywords,
    _phantom: ::std::marker::PhantomData<&'a ()>,
}

impl<'a, P: ::fbthrift::ProtocolWriter> ::fbthrift::Serialize<P> for self::Args_Foo_return<'a> {
    #[inline]
    #[::tracing::instrument(skip_all, level = "trace", name = "serialize_args", fields(method = "Foo.return"))]
    fn write(&self, p: &mut P) {
        p.write_struct_begin("args");
        p.write_field_begin("bar", ::fbthrift::TType::Struct, 1i16);
        ::fbthrift::Serialize::write(&self.bar, p);
        p.write_field_end();
        p.write_field_stop();
        p.write_struct_end();
    }
}

struct Args_Foo_super<'a> {
    bar: &'a crate::types::ThereAreNoPascalCaseKeywords,
    _phantom: ::std::marker::PhantomData<&'a ()>,
}

impl<'a, P: ::fbthrift::ProtocolWriter> ::fbthrift::Serialize<P> for self::Args_Foo_super<'a> {
    #[inline]
    #[::tracing::instrument(skip_all, level = "trace", name = "serialize_args", fields(method = "Foo.super"))]
    fn write(&self, p: &mut P) {
        p.write_struct_begin("args");
        p.write_field_begin("bar", ::fbthrift::TType::Struct, 1i16);
        ::fbthrift::Serialize::write(&self.bar, p);
        p.write_field_end();
        p.write_field_stop();
        p.write_struct_end();
    }
}

impl<P, T, S> Foo for FooImpl<P, T, S>
where
    P: ::fbthrift::Protocol,
    T: ::fbthrift::Transport,
    P::Frame: ::fbthrift::Framing<DecBuf = ::fbthrift::FramingDecoded<T>>,
    ::fbthrift::ProtocolEncoded<P>: ::fbthrift::BufMutExt<Final = ::fbthrift::FramingEncodedFinal<T>>,
    P::Deserializer: ::std::marker::Send,
    S: ::fbthrift::help::Spawner,
{
    fn r#return(
        &self,
        arg_bar: &crate::types::ThereAreNoPascalCaseKeywords,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::foo::ReturnError>> {
        let rpc_options = T::RpcOptions::default();
        self._return_impl(
            arg_bar,
            rpc_options,
        )
    }
    fn super_(
        &self,
        arg_bar: &crate::types::ThereAreNoPascalCaseKeywords,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::foo::SuperError>> {
        let rpc_options = T::RpcOptions::default();
        self._super_impl(
            arg_bar,
            rpc_options,
        )
    }
}

impl<P, T, S> FooExt<T> for FooImpl<P, T, S>
where
    P: ::fbthrift::Protocol,
    T: ::fbthrift::Transport,
    P::Frame: ::fbthrift::Framing<DecBuf = ::fbthrift::FramingDecoded<T>>,
    ::fbthrift::ProtocolEncoded<P>: ::fbthrift::BufMutExt<Final = ::fbthrift::FramingEncodedFinal<T>>,
    P::Deserializer: ::std::marker::Send,
    S: ::fbthrift::help::Spawner,
{
    fn r#return_with_rpc_opts(
        &self,
        arg_bar: &crate::types::ThereAreNoPascalCaseKeywords,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::foo::ReturnError>> {
        self._return_impl(
            arg_bar,
            rpc_options,
        )
    }
    fn super__with_rpc_opts(
        &self,
        arg_bar: &crate::types::ThereAreNoPascalCaseKeywords,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::foo::SuperError>> {
        self._super_impl(
            arg_bar,
            rpc_options,
        )
    }

    fn transport(&self) -> &T {
      self.transport()
    }
}

#[allow(deprecated)]
impl<'a, S> Foo for S
where
    S: ::std::convert::AsRef<dyn Foo + 'a>,
    S: ::std::marker::Send,
{
    fn r#return(
        &self,
        arg_bar: &crate::types::ThereAreNoPascalCaseKeywords,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::foo::ReturnError>> {
        self.as_ref().r#return(
            arg_bar,
        )
    }
    fn super_(
        &self,
        arg_bar: &crate::types::ThereAreNoPascalCaseKeywords,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::foo::SuperError>> {
        self.as_ref().super_(
            arg_bar,
        )
    }
}

#[allow(deprecated)]
impl<S, T> FooExt<T> for S
where
    S: ::std::convert::AsRef<dyn Foo + 'static>,
    S: ::std::convert::AsRef<dyn FooExt<T> + 'static>,
    S: ::std::marker::Send,
    T: ::fbthrift::Transport,
{
    fn r#return_with_rpc_opts(
        &self,
        arg_bar: &crate::types::ThereAreNoPascalCaseKeywords,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::foo::ReturnError>> {
        <Self as ::std::convert::AsRef<dyn FooExt<T>>>::as_ref(self).r#return_with_rpc_opts(
            arg_bar,
            rpc_options,
        )
    }
    fn super__with_rpc_opts(
        &self,
        arg_bar: &crate::types::ThereAreNoPascalCaseKeywords,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::foo::SuperError>> {
        <Self as ::std::convert::AsRef<dyn FooExt<T>>>::as_ref(self).super__with_rpc_opts(
            arg_bar,
            rpc_options,
        )
    }

    fn transport(&self) -> &T {
        <dyn FooExt<T> as FooExt<T>>::transport(<Self as ::std::convert::AsRef<dyn FooExt<T>>>::as_ref(self))
    }
}

#[derive(Clone)]
pub struct make_Foo;

/// To be called by user directly setting up a client. Avoids
/// needing ClientFactory trait in scope, avoids unidiomatic
/// make_Trait name.
///
/// ```
/// # const _: &str = stringify! {
/// use bgs::client::BuckGraphService;
///
/// let protocol = BinaryProtocol::new();
/// let transport = HttpClient::new();
/// let client = <dyn BuckGraphService>::new(protocol, transport);
/// # };
/// ```
impl dyn Foo {
    pub fn new<P, T>(
        protocol: P,
        transport: T,
    ) -> ::std::sync::Arc<impl Foo + ::std::marker::Send + ::std::marker::Sync + 'static>
    where
        P: ::fbthrift::Protocol<Frame = T>,
        T: ::fbthrift::Transport,
        P::Deserializer: ::std::marker::Send,
    {
        let spawner = ::fbthrift::help::NoopSpawner;
        Self::with_spawner(protocol, transport, spawner)
    }

    pub fn with_spawner<P, T, S>(
        protocol: P,
        transport: T,
        spawner: S,
    ) -> ::std::sync::Arc<impl Foo + ::std::marker::Send + ::std::marker::Sync + 'static>
    where
        P: ::fbthrift::Protocol<Frame = T>,
        T: ::fbthrift::Transport,
        P::Deserializer: ::std::marker::Send,
        S: ::fbthrift::help::Spawner,
    {
        let _ = protocol;
        let _ = spawner;
        ::std::sync::Arc::new(FooImpl::<P, T, S>::new(transport))
    }
}

impl<T> dyn FooExt<T>
where
    T: ::fbthrift::Transport,
{
    pub fn new<P>(
        protocol: P,
        transport: T,
    ) -> ::std::sync::Arc<impl FooExt<T> + ::std::marker::Send + ::std::marker::Sync + 'static>
    where
        P: ::fbthrift::Protocol<Frame = T>,
        P::Deserializer: ::std::marker::Send,
    {
        let spawner = ::fbthrift::help::NoopSpawner;
        Self::with_spawner(protocol, transport, spawner)
    }

    pub fn with_spawner<P, S>(
        protocol: P,
        transport: T,
        spawner: S,
    ) -> ::std::sync::Arc<impl FooExt<T> + ::std::marker::Send + ::std::marker::Sync + 'static>
    where
        P: ::fbthrift::Protocol<Frame = T>,
        P::Deserializer: ::std::marker::Send,
        S: ::fbthrift::help::Spawner,
    {
        let _ = protocol;
        let _ = spawner;
        ::std::sync::Arc::new(FooImpl::<P, T, S>::new(transport))
    }
}

pub type FooDynClient = <make_Foo as ::fbthrift::ClientFactory>::Api;
pub type FooClient = ::std::sync::Arc<FooDynClient>;

/// The same thing, but to be called from generic contexts where we are
/// working with a type parameter `C: ClientFactory` to produce clients.
impl ::fbthrift::ClientFactory for make_Foo {
    type Api = dyn Foo + ::std::marker::Send + ::std::marker::Sync + 'static;

    fn with_spawner<P, T, S>(protocol: P, transport: T, spawner: S) -> ::std::sync::Arc<Self::Api>
    where
        P: ::fbthrift::Protocol<Frame = T>,
        T: ::fbthrift::Transport,
        P::Deserializer: ::std::marker::Send,
        S: ::fbthrift::help::Spawner,
    {
        <dyn Foo>::with_spawner(protocol, transport, spawner)
    }
}

