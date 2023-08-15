// @generated by Thrift for thrift/compiler/test/fixtures/rust-annotations/src/module.thrift
// This file is probably not the place you want to edit!

///! Client implementation for each service in `module`.

/// Client definitions for `AllMethods`.
pub struct AllMethodsImpl<P, T, S = ::fbthrift::NoopSpawner> {
    transport: T,
    _phantom: ::std::marker::PhantomData<fn() -> (P, S)>,
}

impl<P, T, S> AllMethodsImpl<P, T, S>
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


    fn _foo_impl(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::all_methods::FooError>> {
        use ::const_cstr::const_cstr;
        use ::tracing::Instrument as _;
        use ::futures::FutureExt as _;

        const_cstr! {
            SERVICE_NAME = "AllMethods";
            SERVICE_METHOD_NAME = "AllMethods.foo";
        }
        let args = self::Args_AllMethods_foo {
            _phantom: ::std::marker::PhantomData,
        };

        let transport = self.transport();

        // need to do call setup outside of async block because T: Transport isn't Send
        let request_env = match ::fbthrift::help::serialize_request_envelope::<P, _>("foo", &args) {
            ::std::result::Result::Ok(res) => res,
            ::std::result::Result::Err(err) => return ::futures::future::err(err.into()).boxed(),
        };

        let call = transport
            .call(SERVICE_NAME.as_cstr(), SERVICE_METHOD_NAME.as_cstr(), request_env, rpc_options)
            .instrument(::tracing::trace_span!("call", method = "AllMethods.foo"));

        async move {
            let reply_env = call.await?;

            let de = P::deserializer(reply_env);
            let (res, _de): (::std::result::Result<crate::services::all_methods::FooExn, _>, _) =
                ::fbthrift::help::async_deserialize_response_envelope::<P, _, S>(de).await?;

            let res = match res {
                ::std::result::Result::Ok(exn) => ::std::convert::From::from(exn),
                ::std::result::Result::Err(aexn) =>
                    ::std::result::Result::Err(crate::errors::all_methods::FooError::ApplicationException(aexn))
            };
            res
        }
        .instrument(::tracing::info_span!("stream", method = "AllMethods.foo"))
        .boxed()
    }

    fn _bar_impl(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::all_methods::BarError>> {
        use ::const_cstr::const_cstr;
        use ::tracing::Instrument as _;
        use ::futures::FutureExt as _;

        const_cstr! {
            SERVICE_NAME = "AllMethods";
            SERVICE_METHOD_NAME = "AllMethods.bar";
        }
        let args = self::Args_AllMethods_bar {
            _phantom: ::std::marker::PhantomData,
        };

        let transport = self.transport();

        // need to do call setup outside of async block because T: Transport isn't Send
        let request_env = match ::fbthrift::help::serialize_request_envelope::<P, _>("bar", &args) {
            ::std::result::Result::Ok(res) => res,
            ::std::result::Result::Err(err) => return ::futures::future::err(err.into()).boxed(),
        };

        let call = transport
            .call(SERVICE_NAME.as_cstr(), SERVICE_METHOD_NAME.as_cstr(), request_env, rpc_options)
            .instrument(::tracing::trace_span!("call", method = "AllMethods.bar"));

        async move {
            let reply_env = call.await?;

            let de = P::deserializer(reply_env);
            let (res, _de): (::std::result::Result<crate::services::all_methods::BarExn, _>, _) =
                ::fbthrift::help::async_deserialize_response_envelope::<P, _, S>(de).await?;

            let res = match res {
                ::std::result::Result::Ok(exn) => ::std::convert::From::from(exn),
                ::std::result::Result::Err(aexn) =>
                    ::std::result::Result::Err(crate::errors::all_methods::BarError::ApplicationException(aexn))
            };
            res
        }
        .instrument(::tracing::info_span!("stream", method = "AllMethods.bar"))
        .boxed()
    }
}

pub trait AllMethods: ::std::marker::Send {
    fn foo(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::all_methods::FooError>>;

    fn bar(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::all_methods::BarError>>;
}

pub trait AllMethodsExt<T>: AllMethods
where
    T: ::fbthrift::Transport,
{
    fn foo_with_rpc_opts(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::all_methods::FooError>>;
    fn bar_with_rpc_opts(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::all_methods::BarError>>;

    fn transport(&self) -> &T;
}

struct Args_AllMethods_foo<'a> {
    _phantom: ::std::marker::PhantomData<&'a ()>,
}

impl<'a, P: ::fbthrift::ProtocolWriter> ::fbthrift::Serialize<P> for self::Args_AllMethods_foo<'a> {
    #[inline]
    #[::tracing::instrument(skip_all, level = "trace", name = "serialize_args", fields(method = "AllMethods.foo"))]
    fn write(&self, p: &mut P) {
        p.write_struct_begin("args");
        p.write_field_stop();
        p.write_struct_end();
    }
}

struct Args_AllMethods_bar<'a> {
    _phantom: ::std::marker::PhantomData<&'a ()>,
}

impl<'a, P: ::fbthrift::ProtocolWriter> ::fbthrift::Serialize<P> for self::Args_AllMethods_bar<'a> {
    #[inline]
    #[::tracing::instrument(skip_all, level = "trace", name = "serialize_args", fields(method = "AllMethods.bar"))]
    fn write(&self, p: &mut P) {
        p.write_struct_begin("args");
        p.write_field_stop();
        p.write_struct_end();
    }
}

impl<P, T, S> AllMethods for AllMethodsImpl<P, T, S>
where
    P: ::fbthrift::Protocol,
    T: ::fbthrift::Transport,
    P::Frame: ::fbthrift::Framing<DecBuf = ::fbthrift::FramingDecoded<T>>,
    ::fbthrift::ProtocolEncoded<P>: ::fbthrift::BufMutExt<Final = ::fbthrift::FramingEncodedFinal<T>>,
    P::Deserializer: ::std::marker::Send,
    S: ::fbthrift::help::Spawner,
{
    fn foo(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::all_methods::FooError>> {
        let rpc_options = T::RpcOptions::default();
        self._foo_impl(
            rpc_options,
        )
    }
    fn bar(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::all_methods::BarError>> {
        let rpc_options = T::RpcOptions::default();
        self._bar_impl(
            rpc_options,
        )
    }
}

impl<P, T, S> AllMethodsExt<T> for AllMethodsImpl<P, T, S>
where
    P: ::fbthrift::Protocol,
    T: ::fbthrift::Transport,
    P::Frame: ::fbthrift::Framing<DecBuf = ::fbthrift::FramingDecoded<T>>,
    ::fbthrift::ProtocolEncoded<P>: ::fbthrift::BufMutExt<Final = ::fbthrift::FramingEncodedFinal<T>>,
    P::Deserializer: ::std::marker::Send,
    S: ::fbthrift::help::Spawner,
{
    fn foo_with_rpc_opts(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::all_methods::FooError>> {
        self._foo_impl(
            rpc_options,
        )
    }
    fn bar_with_rpc_opts(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::all_methods::BarError>> {
        self._bar_impl(
            rpc_options,
        )
    }

    fn transport(&self) -> &T {
      self.transport()
    }
}

impl<'a, S> AllMethods for S
where
    S: ::std::convert::AsRef<dyn AllMethods + 'a>,
    S: ::std::marker::Send,
{
    fn foo(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::all_methods::FooError>> {
        self.as_ref().foo(
        )
    }
    fn bar(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::all_methods::BarError>> {
        self.as_ref().bar(
        )
    }
}

impl<S, T> AllMethodsExt<T> for S
where
    S: ::std::convert::AsRef<dyn AllMethods + 'static>,
    S: ::std::convert::AsRef<dyn AllMethodsExt<T> + 'static>,
    S: ::std::marker::Send,
    T: ::fbthrift::Transport,
{
    fn foo_with_rpc_opts(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::all_methods::FooError>> {
        <Self as ::std::convert::AsRef<dyn AllMethodsExt<T>>>::as_ref(self).foo_with_rpc_opts(
            rpc_options,
        )
    }
    fn bar_with_rpc_opts(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::all_methods::BarError>> {
        <Self as ::std::convert::AsRef<dyn AllMethodsExt<T>>>::as_ref(self).bar_with_rpc_opts(
            rpc_options,
        )
    }

    fn transport(&self) -> &T {
        <dyn AllMethodsExt<T> as AllMethodsExt<T>>::transport(<Self as ::std::convert::AsRef<dyn AllMethodsExt<T>>>::as_ref(self))
    }
}

#[derive(Clone)]
pub struct make_AllMethods;

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
impl dyn AllMethods {
    pub fn new<P, T>(
        protocol: P,
        transport: T,
    ) -> ::std::sync::Arc<impl AllMethods + ::std::marker::Send + ::std::marker::Sync + 'static>
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
    ) -> ::std::sync::Arc<impl AllMethods + ::std::marker::Send + ::std::marker::Sync + 'static>
    where
        P: ::fbthrift::Protocol<Frame = T>,
        T: ::fbthrift::Transport,
        P::Deserializer: ::std::marker::Send,
        S: ::fbthrift::help::Spawner,
    {
        let _ = protocol;
        let _ = spawner;
        ::std::sync::Arc::new(AllMethodsImpl::<P, T, S>::new(transport))
    }
}

impl<T> dyn AllMethodsExt<T>
where
    T: ::fbthrift::Transport,
{
    pub fn new<P>(
        protocol: P,
        transport: T,
    ) -> ::std::sync::Arc<impl AllMethodsExt<T> + ::std::marker::Send + ::std::marker::Sync + 'static>
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
    ) -> ::std::sync::Arc<impl AllMethodsExt<T> + ::std::marker::Send + ::std::marker::Sync + 'static>
    where
        P: ::fbthrift::Protocol<Frame = T>,
        P::Deserializer: ::std::marker::Send,
        S: ::fbthrift::help::Spawner,
    {
        let _ = protocol;
        let _ = spawner;
        ::std::sync::Arc::new(AllMethodsImpl::<P, T, S>::new(transport))
    }
}

pub type AllMethodsDynClient = <make_AllMethods as ::fbthrift::ClientFactory>::Api;
pub type AllMethodsClient = ::std::sync::Arc<AllMethodsDynClient>;

/// The same thing, but to be called from generic contexts where we are
/// working with a type parameter `C: ClientFactory` to produce clients.
impl ::fbthrift::ClientFactory for make_AllMethods {
    type Api = dyn AllMethods + ::std::marker::Send + ::std::marker::Sync + 'static;

    fn with_spawner<P, T, S>(protocol: P, transport: T, spawner: S) -> ::std::sync::Arc<Self::Api>
    where
        P: ::fbthrift::Protocol<Frame = T>,
        T: ::fbthrift::Transport,
        P::Deserializer: ::std::marker::Send,
        S: ::fbthrift::help::Spawner,
    {
        <dyn AllMethods>::with_spawner(protocol, transport, spawner)
    }
}


/// Client definitions for `OneMethod`.
pub struct OneMethodImpl<P, T, S = ::fbthrift::NoopSpawner> {
    transport: T,
    _phantom: ::std::marker::PhantomData<fn() -> (P, S)>,
}

impl<P, T, S> OneMethodImpl<P, T, S>
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


    fn _foo_impl(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::one_method::FooError>> {
        use ::const_cstr::const_cstr;
        use ::tracing::Instrument as _;
        use ::futures::FutureExt as _;

        const_cstr! {
            SERVICE_NAME = "OneMethod";
            SERVICE_METHOD_NAME = "OneMethod.foo";
        }
        let args = self::Args_OneMethod_foo {
            _phantom: ::std::marker::PhantomData,
        };

        let transport = self.transport();

        // need to do call setup outside of async block because T: Transport isn't Send
        let request_env = match ::fbthrift::help::serialize_request_envelope::<P, _>("foo", &args) {
            ::std::result::Result::Ok(res) => res,
            ::std::result::Result::Err(err) => return ::futures::future::err(err.into()).boxed(),
        };

        let call = transport
            .call(SERVICE_NAME.as_cstr(), SERVICE_METHOD_NAME.as_cstr(), request_env, rpc_options)
            .instrument(::tracing::trace_span!("call", method = "OneMethod.foo"));

        async move {
            let reply_env = call.await?;

            let de = P::deserializer(reply_env);
            let (res, _de): (::std::result::Result<crate::services::one_method::FooExn, _>, _) =
                ::fbthrift::help::async_deserialize_response_envelope::<P, _, S>(de).await?;

            let res = match res {
                ::std::result::Result::Ok(exn) => ::std::convert::From::from(exn),
                ::std::result::Result::Err(aexn) =>
                    ::std::result::Result::Err(crate::errors::one_method::FooError::ApplicationException(aexn))
            };
            res
        }
        .instrument(::tracing::info_span!("stream", method = "OneMethod.foo"))
        .boxed()
    }

    fn _bar_impl(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::one_method::BarError>> {
        use ::const_cstr::const_cstr;
        use ::tracing::Instrument as _;
        use ::futures::FutureExt as _;

        const_cstr! {
            SERVICE_NAME = "OneMethod";
            SERVICE_METHOD_NAME = "OneMethod.bar";
        }
        let args = self::Args_OneMethod_bar {
            _phantom: ::std::marker::PhantomData,
        };

        let transport = self.transport();

        // need to do call setup outside of async block because T: Transport isn't Send
        let request_env = match ::fbthrift::help::serialize_request_envelope::<P, _>("bar", &args) {
            ::std::result::Result::Ok(res) => res,
            ::std::result::Result::Err(err) => return ::futures::future::err(err.into()).boxed(),
        };

        let call = transport
            .call(SERVICE_NAME.as_cstr(), SERVICE_METHOD_NAME.as_cstr(), request_env, rpc_options)
            .instrument(::tracing::trace_span!("call", method = "OneMethod.bar"));

        async move {
            let reply_env = call.await?;

            let de = P::deserializer(reply_env);
            let (res, _de): (::std::result::Result<crate::services::one_method::BarExn, _>, _) =
                ::fbthrift::help::async_deserialize_response_envelope::<P, _, S>(de).await?;

            let res = match res {
                ::std::result::Result::Ok(exn) => ::std::convert::From::from(exn),
                ::std::result::Result::Err(aexn) =>
                    ::std::result::Result::Err(crate::errors::one_method::BarError::ApplicationException(aexn))
            };
            res
        }
        .instrument(::tracing::info_span!("stream", method = "OneMethod.bar"))
        .boxed()
    }
}

pub trait OneMethod: ::std::marker::Send {
    fn foo(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::one_method::FooError>>;

    fn bar(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::one_method::BarError>>;
}

pub trait OneMethodExt<T>: OneMethod
where
    T: ::fbthrift::Transport,
{
    fn foo_with_rpc_opts(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::one_method::FooError>>;
    fn bar_with_rpc_opts(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::one_method::BarError>>;

    fn transport(&self) -> &T;
}

struct Args_OneMethod_foo<'a> {
    _phantom: ::std::marker::PhantomData<&'a ()>,
}

impl<'a, P: ::fbthrift::ProtocolWriter> ::fbthrift::Serialize<P> for self::Args_OneMethod_foo<'a> {
    #[inline]
    #[::tracing::instrument(skip_all, level = "trace", name = "serialize_args", fields(method = "OneMethod.foo"))]
    fn write(&self, p: &mut P) {
        p.write_struct_begin("args");
        p.write_field_stop();
        p.write_struct_end();
    }
}

struct Args_OneMethod_bar<'a> {
    _phantom: ::std::marker::PhantomData<&'a ()>,
}

impl<'a, P: ::fbthrift::ProtocolWriter> ::fbthrift::Serialize<P> for self::Args_OneMethod_bar<'a> {
    #[inline]
    #[::tracing::instrument(skip_all, level = "trace", name = "serialize_args", fields(method = "OneMethod.bar"))]
    fn write(&self, p: &mut P) {
        p.write_struct_begin("args");
        p.write_field_stop();
        p.write_struct_end();
    }
}

impl<P, T, S> OneMethod for OneMethodImpl<P, T, S>
where
    P: ::fbthrift::Protocol,
    T: ::fbthrift::Transport,
    P::Frame: ::fbthrift::Framing<DecBuf = ::fbthrift::FramingDecoded<T>>,
    ::fbthrift::ProtocolEncoded<P>: ::fbthrift::BufMutExt<Final = ::fbthrift::FramingEncodedFinal<T>>,
    P::Deserializer: ::std::marker::Send,
    S: ::fbthrift::help::Spawner,
{
    fn foo(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::one_method::FooError>> {
        let rpc_options = T::RpcOptions::default();
        self._foo_impl(
            rpc_options,
        )
    }
    fn bar(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::one_method::BarError>> {
        let rpc_options = T::RpcOptions::default();
        self._bar_impl(
            rpc_options,
        )
    }
}

impl<P, T, S> OneMethodExt<T> for OneMethodImpl<P, T, S>
where
    P: ::fbthrift::Protocol,
    T: ::fbthrift::Transport,
    P::Frame: ::fbthrift::Framing<DecBuf = ::fbthrift::FramingDecoded<T>>,
    ::fbthrift::ProtocolEncoded<P>: ::fbthrift::BufMutExt<Final = ::fbthrift::FramingEncodedFinal<T>>,
    P::Deserializer: ::std::marker::Send,
    S: ::fbthrift::help::Spawner,
{
    fn foo_with_rpc_opts(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::one_method::FooError>> {
        self._foo_impl(
            rpc_options,
        )
    }
    fn bar_with_rpc_opts(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::one_method::BarError>> {
        self._bar_impl(
            rpc_options,
        )
    }

    fn transport(&self) -> &T {
      self.transport()
    }
}

impl<'a, S> OneMethod for S
where
    S: ::std::convert::AsRef<dyn OneMethod + 'a>,
    S: ::std::marker::Send,
{
    fn foo(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::one_method::FooError>> {
        self.as_ref().foo(
        )
    }
    fn bar(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::one_method::BarError>> {
        self.as_ref().bar(
        )
    }
}

impl<S, T> OneMethodExt<T> for S
where
    S: ::std::convert::AsRef<dyn OneMethod + 'static>,
    S: ::std::convert::AsRef<dyn OneMethodExt<T> + 'static>,
    S: ::std::marker::Send,
    T: ::fbthrift::Transport,
{
    fn foo_with_rpc_opts(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::one_method::FooError>> {
        <Self as ::std::convert::AsRef<dyn OneMethodExt<T>>>::as_ref(self).foo_with_rpc_opts(
            rpc_options,
        )
    }
    fn bar_with_rpc_opts(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::one_method::BarError>> {
        <Self as ::std::convert::AsRef<dyn OneMethodExt<T>>>::as_ref(self).bar_with_rpc_opts(
            rpc_options,
        )
    }

    fn transport(&self) -> &T {
        <dyn OneMethodExt<T> as OneMethodExt<T>>::transport(<Self as ::std::convert::AsRef<dyn OneMethodExt<T>>>::as_ref(self))
    }
}

#[derive(Clone)]
pub struct make_OneMethod;

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
impl dyn OneMethod {
    pub fn new<P, T>(
        protocol: P,
        transport: T,
    ) -> ::std::sync::Arc<impl OneMethod + ::std::marker::Send + ::std::marker::Sync + 'static>
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
    ) -> ::std::sync::Arc<impl OneMethod + ::std::marker::Send + ::std::marker::Sync + 'static>
    where
        P: ::fbthrift::Protocol<Frame = T>,
        T: ::fbthrift::Transport,
        P::Deserializer: ::std::marker::Send,
        S: ::fbthrift::help::Spawner,
    {
        let _ = protocol;
        let _ = spawner;
        ::std::sync::Arc::new(OneMethodImpl::<P, T, S>::new(transport))
    }
}

impl<T> dyn OneMethodExt<T>
where
    T: ::fbthrift::Transport,
{
    pub fn new<P>(
        protocol: P,
        transport: T,
    ) -> ::std::sync::Arc<impl OneMethodExt<T> + ::std::marker::Send + ::std::marker::Sync + 'static>
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
    ) -> ::std::sync::Arc<impl OneMethodExt<T> + ::std::marker::Send + ::std::marker::Sync + 'static>
    where
        P: ::fbthrift::Protocol<Frame = T>,
        P::Deserializer: ::std::marker::Send,
        S: ::fbthrift::help::Spawner,
    {
        let _ = protocol;
        let _ = spawner;
        ::std::sync::Arc::new(OneMethodImpl::<P, T, S>::new(transport))
    }
}

pub type OneMethodDynClient = <make_OneMethod as ::fbthrift::ClientFactory>::Api;
pub type OneMethodClient = ::std::sync::Arc<OneMethodDynClient>;

/// The same thing, but to be called from generic contexts where we are
/// working with a type parameter `C: ClientFactory` to produce clients.
impl ::fbthrift::ClientFactory for make_OneMethod {
    type Api = dyn OneMethod + ::std::marker::Send + ::std::marker::Sync + 'static;

    fn with_spawner<P, T, S>(protocol: P, transport: T, spawner: S) -> ::std::sync::Arc<Self::Api>
    where
        P: ::fbthrift::Protocol<Frame = T>,
        T: ::fbthrift::Transport,
        P::Deserializer: ::std::marker::Send,
        S: ::fbthrift::help::Spawner,
    {
        <dyn OneMethod>::with_spawner(protocol, transport, spawner)
    }
}


/// Client definitions for `OneMethodOptOut`.
pub struct OneMethodOptOutImpl<P, T, S = ::fbthrift::NoopSpawner> {
    transport: T,
    _phantom: ::std::marker::PhantomData<fn() -> (P, S)>,
}

impl<P, T, S> OneMethodOptOutImpl<P, T, S>
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


    fn _foo_impl(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::one_method_opt_out::FooError>> {
        use ::const_cstr::const_cstr;
        use ::tracing::Instrument as _;
        use ::futures::FutureExt as _;

        const_cstr! {
            SERVICE_NAME = "OneMethodOptOut";
            SERVICE_METHOD_NAME = "OneMethodOptOut.foo";
        }
        let args = self::Args_OneMethodOptOut_foo {
            _phantom: ::std::marker::PhantomData,
        };

        let transport = self.transport();

        // need to do call setup outside of async block because T: Transport isn't Send
        let request_env = match ::fbthrift::help::serialize_request_envelope::<P, _>("foo", &args) {
            ::std::result::Result::Ok(res) => res,
            ::std::result::Result::Err(err) => return ::futures::future::err(err.into()).boxed(),
        };

        let call = transport
            .call(SERVICE_NAME.as_cstr(), SERVICE_METHOD_NAME.as_cstr(), request_env, rpc_options)
            .instrument(::tracing::trace_span!("call", method = "OneMethodOptOut.foo"));

        async move {
            let reply_env = call.await?;

            let de = P::deserializer(reply_env);
            let (res, _de): (::std::result::Result<crate::services::one_method_opt_out::FooExn, _>, _) =
                ::fbthrift::help::async_deserialize_response_envelope::<P, _, S>(de).await?;

            let res = match res {
                ::std::result::Result::Ok(exn) => ::std::convert::From::from(exn),
                ::std::result::Result::Err(aexn) =>
                    ::std::result::Result::Err(crate::errors::one_method_opt_out::FooError::ApplicationException(aexn))
            };
            res
        }
        .instrument(::tracing::info_span!("stream", method = "OneMethodOptOut.foo"))
        .boxed()
    }

    fn _bar_impl(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::one_method_opt_out::BarError>> {
        use ::const_cstr::const_cstr;
        use ::tracing::Instrument as _;
        use ::futures::FutureExt as _;

        const_cstr! {
            SERVICE_NAME = "OneMethodOptOut";
            SERVICE_METHOD_NAME = "OneMethodOptOut.bar";
        }
        let args = self::Args_OneMethodOptOut_bar {
            _phantom: ::std::marker::PhantomData,
        };

        let transport = self.transport();

        // need to do call setup outside of async block because T: Transport isn't Send
        let request_env = match ::fbthrift::help::serialize_request_envelope::<P, _>("bar", &args) {
            ::std::result::Result::Ok(res) => res,
            ::std::result::Result::Err(err) => return ::futures::future::err(err.into()).boxed(),
        };

        let call = transport
            .call(SERVICE_NAME.as_cstr(), SERVICE_METHOD_NAME.as_cstr(), request_env, rpc_options)
            .instrument(::tracing::trace_span!("call", method = "OneMethodOptOut.bar"));

        async move {
            let reply_env = call.await?;

            let de = P::deserializer(reply_env);
            let (res, _de): (::std::result::Result<crate::services::one_method_opt_out::BarExn, _>, _) =
                ::fbthrift::help::async_deserialize_response_envelope::<P, _, S>(de).await?;

            let res = match res {
                ::std::result::Result::Ok(exn) => ::std::convert::From::from(exn),
                ::std::result::Result::Err(aexn) =>
                    ::std::result::Result::Err(crate::errors::one_method_opt_out::BarError::ApplicationException(aexn))
            };
            res
        }
        .instrument(::tracing::info_span!("stream", method = "OneMethodOptOut.bar"))
        .boxed()
    }
}

pub trait OneMethodOptOut: ::std::marker::Send {
    fn foo(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::one_method_opt_out::FooError>>;

    fn bar(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::one_method_opt_out::BarError>>;
}

pub trait OneMethodOptOutExt<T>: OneMethodOptOut
where
    T: ::fbthrift::Transport,
{
    fn foo_with_rpc_opts(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::one_method_opt_out::FooError>>;
    fn bar_with_rpc_opts(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::one_method_opt_out::BarError>>;

    fn transport(&self) -> &T;
}

struct Args_OneMethodOptOut_foo<'a> {
    _phantom: ::std::marker::PhantomData<&'a ()>,
}

impl<'a, P: ::fbthrift::ProtocolWriter> ::fbthrift::Serialize<P> for self::Args_OneMethodOptOut_foo<'a> {
    #[inline]
    #[::tracing::instrument(skip_all, level = "trace", name = "serialize_args", fields(method = "OneMethodOptOut.foo"))]
    fn write(&self, p: &mut P) {
        p.write_struct_begin("args");
        p.write_field_stop();
        p.write_struct_end();
    }
}

struct Args_OneMethodOptOut_bar<'a> {
    _phantom: ::std::marker::PhantomData<&'a ()>,
}

impl<'a, P: ::fbthrift::ProtocolWriter> ::fbthrift::Serialize<P> for self::Args_OneMethodOptOut_bar<'a> {
    #[inline]
    #[::tracing::instrument(skip_all, level = "trace", name = "serialize_args", fields(method = "OneMethodOptOut.bar"))]
    fn write(&self, p: &mut P) {
        p.write_struct_begin("args");
        p.write_field_stop();
        p.write_struct_end();
    }
}

impl<P, T, S> OneMethodOptOut for OneMethodOptOutImpl<P, T, S>
where
    P: ::fbthrift::Protocol,
    T: ::fbthrift::Transport,
    P::Frame: ::fbthrift::Framing<DecBuf = ::fbthrift::FramingDecoded<T>>,
    ::fbthrift::ProtocolEncoded<P>: ::fbthrift::BufMutExt<Final = ::fbthrift::FramingEncodedFinal<T>>,
    P::Deserializer: ::std::marker::Send,
    S: ::fbthrift::help::Spawner,
{
    fn foo(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::one_method_opt_out::FooError>> {
        let rpc_options = T::RpcOptions::default();
        self._foo_impl(
            rpc_options,
        )
    }
    fn bar(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::one_method_opt_out::BarError>> {
        let rpc_options = T::RpcOptions::default();
        self._bar_impl(
            rpc_options,
        )
    }
}

impl<P, T, S> OneMethodOptOutExt<T> for OneMethodOptOutImpl<P, T, S>
where
    P: ::fbthrift::Protocol,
    T: ::fbthrift::Transport,
    P::Frame: ::fbthrift::Framing<DecBuf = ::fbthrift::FramingDecoded<T>>,
    ::fbthrift::ProtocolEncoded<P>: ::fbthrift::BufMutExt<Final = ::fbthrift::FramingEncodedFinal<T>>,
    P::Deserializer: ::std::marker::Send,
    S: ::fbthrift::help::Spawner,
{
    fn foo_with_rpc_opts(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::one_method_opt_out::FooError>> {
        self._foo_impl(
            rpc_options,
        )
    }
    fn bar_with_rpc_opts(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::one_method_opt_out::BarError>> {
        self._bar_impl(
            rpc_options,
        )
    }

    fn transport(&self) -> &T {
      self.transport()
    }
}

impl<'a, S> OneMethodOptOut for S
where
    S: ::std::convert::AsRef<dyn OneMethodOptOut + 'a>,
    S: ::std::marker::Send,
{
    fn foo(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::one_method_opt_out::FooError>> {
        self.as_ref().foo(
        )
    }
    fn bar(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::one_method_opt_out::BarError>> {
        self.as_ref().bar(
        )
    }
}

impl<S, T> OneMethodOptOutExt<T> for S
where
    S: ::std::convert::AsRef<dyn OneMethodOptOut + 'static>,
    S: ::std::convert::AsRef<dyn OneMethodOptOutExt<T> + 'static>,
    S: ::std::marker::Send,
    T: ::fbthrift::Transport,
{
    fn foo_with_rpc_opts(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::one_method_opt_out::FooError>> {
        <Self as ::std::convert::AsRef<dyn OneMethodOptOutExt<T>>>::as_ref(self).foo_with_rpc_opts(
            rpc_options,
        )
    }
    fn bar_with_rpc_opts(
        &self,
        rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::one_method_opt_out::BarError>> {
        <Self as ::std::convert::AsRef<dyn OneMethodOptOutExt<T>>>::as_ref(self).bar_with_rpc_opts(
            rpc_options,
        )
    }

    fn transport(&self) -> &T {
        <dyn OneMethodOptOutExt<T> as OneMethodOptOutExt<T>>::transport(<Self as ::std::convert::AsRef<dyn OneMethodOptOutExt<T>>>::as_ref(self))
    }
}

#[derive(Clone)]
pub struct make_OneMethodOptOut;

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
impl dyn OneMethodOptOut {
    pub fn new<P, T>(
        protocol: P,
        transport: T,
    ) -> ::std::sync::Arc<impl OneMethodOptOut + ::std::marker::Send + ::std::marker::Sync + 'static>
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
    ) -> ::std::sync::Arc<impl OneMethodOptOut + ::std::marker::Send + ::std::marker::Sync + 'static>
    where
        P: ::fbthrift::Protocol<Frame = T>,
        T: ::fbthrift::Transport,
        P::Deserializer: ::std::marker::Send,
        S: ::fbthrift::help::Spawner,
    {
        let _ = protocol;
        let _ = spawner;
        ::std::sync::Arc::new(OneMethodOptOutImpl::<P, T, S>::new(transport))
    }
}

impl<T> dyn OneMethodOptOutExt<T>
where
    T: ::fbthrift::Transport,
{
    pub fn new<P>(
        protocol: P,
        transport: T,
    ) -> ::std::sync::Arc<impl OneMethodOptOutExt<T> + ::std::marker::Send + ::std::marker::Sync + 'static>
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
    ) -> ::std::sync::Arc<impl OneMethodOptOutExt<T> + ::std::marker::Send + ::std::marker::Sync + 'static>
    where
        P: ::fbthrift::Protocol<Frame = T>,
        P::Deserializer: ::std::marker::Send,
        S: ::fbthrift::help::Spawner,
    {
        let _ = protocol;
        let _ = spawner;
        ::std::sync::Arc::new(OneMethodOptOutImpl::<P, T, S>::new(transport))
    }
}

pub type OneMethodOptOutDynClient = <make_OneMethodOptOut as ::fbthrift::ClientFactory>::Api;
pub type OneMethodOptOutClient = ::std::sync::Arc<OneMethodOptOutDynClient>;

/// The same thing, but to be called from generic contexts where we are
/// working with a type parameter `C: ClientFactory` to produce clients.
impl ::fbthrift::ClientFactory for make_OneMethodOptOut {
    type Api = dyn OneMethodOptOut + ::std::marker::Send + ::std::marker::Sync + 'static;

    fn with_spawner<P, T, S>(protocol: P, transport: T, spawner: S) -> ::std::sync::Arc<Self::Api>
    where
        P: ::fbthrift::Protocol<Frame = T>,
        T: ::fbthrift::Transport,
        P::Deserializer: ::std::marker::Send,
        S: ::fbthrift::help::Spawner,
    {
        <dyn OneMethodOptOut>::with_spawner(protocol, transport, spawner)
    }
}
