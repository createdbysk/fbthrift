/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/client_h.h>

#include "thrift/compiler/test/fixtures/stream/gen-cpp2/module_types.h"
#include <thrift/lib/cpp2/async/ClientBufferedStream.h>

namespace apache { namespace thrift {
  class Cpp2RequestContext;
  namespace detail { namespace ac { struct ClientRequestContext; }}
  namespace transport { class THeader; }
}}

namespace cpp2 {

class PubSubStreamingServiceAsyncClient : public apache::thrift::GeneratedAsyncClient {
 public:
  using apache::thrift::GeneratedAsyncClient::GeneratedAsyncClient;

  char const* getServiceName() const noexcept override {
    return "PubSubStreamingService";
  }


  virtual void returnstream(std::unique_ptr<apache::thrift::RequestCallback> callback, ::std::int32_t p_i32_from, ::std::int32_t p_i32_to);
  virtual void returnstream(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, ::std::int32_t p_i32_from, ::std::int32_t p_i32_to);
 protected:
  void returnstreamImpl(const apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::StreamClientCallback* callback, ::std::int32_t p_i32_from, ::std::int32_t p_i32_to);
 public:

  virtual apache::thrift::ClientBufferedStream<::std::int32_t> sync_returnstream(::std::int32_t p_i32_from, ::std::int32_t p_i32_to);
  virtual apache::thrift::ClientBufferedStream<::std::int32_t> sync_returnstream(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_i32_from, ::std::int32_t p_i32_to);

  virtual folly::SemiFuture<apache::thrift::ClientBufferedStream<::std::int32_t>> semifuture_returnstream(::std::int32_t p_i32_from, ::std::int32_t p_i32_to);
  virtual folly::SemiFuture<apache::thrift::ClientBufferedStream<::std::int32_t>> semifuture_returnstream(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_i32_from, ::std::int32_t p_i32_to);
  virtual folly::SemiFuture<std::pair<apache::thrift::ClientBufferedStream<::std::int32_t>, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_returnstream(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_i32_from, ::std::int32_t p_i32_to);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<apache::thrift::ClientBufferedStream<::std::int32_t>> co_returnstream(::std::int32_t p_i32_from, ::std::int32_t p_i32_to) {
    return co_returnstream<false>(nullptr, p_i32_from, p_i32_to);
  }
  template <int = 0>
  folly::coro::Task<apache::thrift::ClientBufferedStream<::std::int32_t>> co_returnstream(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_i32_from, ::std::int32_t p_i32_to) {
    return co_returnstream<true>(&rpcOptions, p_i32_from, p_i32_to);
  }
 private:
  template <bool hasRpcOptions>
  folly::coro::Task<apache::thrift::ClientBufferedStream<::std::int32_t>> co_returnstream(apache::thrift::RpcOptions* rpcOptions, ::std::int32_t p_i32_from, ::std::int32_t p_i32_to) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    const bool cancellable = cancelToken.canBeCancelled();
    apache::thrift::ClientReceiveState returnState;
    apache::thrift::ClientSyncCallback<false> callback(&returnState);
    auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
    auto [ctx, header] = returnstreamCtx(rpcOptions);
    using CancellableCallback = apache::thrift::CancellableRequestClientCallback<false>;
    auto cancellableCallback = cancellable ? CancellableCallback::create(&callback, channel_) : nullptr;
    static const apache::thrift::RpcOptions defaultRpcOptions;
    auto wrappedCallback = apache::thrift::createStreamClientCallback(
        apache::thrift::RequestClientCallback::Ptr(cancellableCallback ? (apache::thrift::RequestClientCallback*)cancellableCallback.get() : &callback),
      hasRpcOptions ? rpcOptions->getBufferOptions() : defaultRpcOptions.getBufferOptions());
    if constexpr (hasRpcOptions) {
      returnstreamImpl(*rpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback), p_i32_from, p_i32_to);
    } else {
      returnstreamImpl(defaultRpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback), p_i32_from, p_i32_to);
    }
    if (cancellable) {
      folly::CancellationCallback cb(cancelToken, [&] { CancellableCallback::cancel(std::move(cancellableCallback)); });
      co_await callback.co_waitUntilDone();
    } else {
      co_await callback.co_waitUntilDone();
    }
    if (returnState.isException()) {
      co_yield folly::coro::co_error(std::move(returnState.exception()));
    }
    returnState.resetProtocolId(protocolId);
    returnState.resetCtx(std::move(ctx));
    SCOPE_EXIT {
      if (hasRpcOptions && returnState.header()) {
        auto* rheader = returnState.header();
        if (!rheader->getHeaders().empty()) {
          rpcOptions->setReadHeaders(rheader->releaseHeaders());
        }
        rpcOptions->setRoutingData(rheader->releaseRoutingData());
      }
    };
    apache::thrift::ClientBufferedStream<::std::int32_t> _return;
    if (auto ew = recv_wrapped_returnstream(_return, returnState)) {
      co_yield folly::coro::co_error(std::move(ew));
    }
    co_return _return;
  }
 public:
#endif // FOLLY_HAS_COROUTINES



  static folly::exception_wrapper recv_wrapped_returnstream(apache::thrift::ClientBufferedStream<::std::int32_t>& _return, ::apache::thrift::ClientReceiveState& state);
  static apache::thrift::ClientBufferedStream<::std::int32_t> recv_returnstream(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual apache::thrift::ClientBufferedStream<::std::int32_t> recv_instance_returnstream(::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_returnstream(apache::thrift::ClientBufferedStream<::std::int32_t>& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  void returnstreamT(Protocol_* prot, const apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::StreamClientCallback* callback, ::std::int32_t p_i32_from, ::std::int32_t p_i32_to);
  std::pair<std::unique_ptr<::apache::thrift::ContextStack>, std::shared_ptr<::apache::thrift::transport::THeader>> returnstreamCtx(apache::thrift::RpcOptions* rpcOptions);
 public:
  virtual void streamthrows(std::unique_ptr<apache::thrift::RequestCallback> callback, ::std::int32_t p_foo);
  virtual void streamthrows(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, ::std::int32_t p_foo);
 protected:
  void streamthrowsImpl(const apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::StreamClientCallback* callback, ::std::int32_t p_foo);
 public:

  virtual apache::thrift::ClientBufferedStream<::std::int32_t> sync_streamthrows(::std::int32_t p_foo);
  virtual apache::thrift::ClientBufferedStream<::std::int32_t> sync_streamthrows(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_foo);

  virtual folly::SemiFuture<apache::thrift::ClientBufferedStream<::std::int32_t>> semifuture_streamthrows(::std::int32_t p_foo);
  virtual folly::SemiFuture<apache::thrift::ClientBufferedStream<::std::int32_t>> semifuture_streamthrows(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_foo);
  virtual folly::SemiFuture<std::pair<apache::thrift::ClientBufferedStream<::std::int32_t>, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_streamthrows(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_foo);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<apache::thrift::ClientBufferedStream<::std::int32_t>> co_streamthrows(::std::int32_t p_foo) {
    return co_streamthrows<false>(nullptr, p_foo);
  }
  template <int = 0>
  folly::coro::Task<apache::thrift::ClientBufferedStream<::std::int32_t>> co_streamthrows(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_foo) {
    return co_streamthrows<true>(&rpcOptions, p_foo);
  }
 private:
  template <bool hasRpcOptions>
  folly::coro::Task<apache::thrift::ClientBufferedStream<::std::int32_t>> co_streamthrows(apache::thrift::RpcOptions* rpcOptions, ::std::int32_t p_foo) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    const bool cancellable = cancelToken.canBeCancelled();
    apache::thrift::ClientReceiveState returnState;
    apache::thrift::ClientSyncCallback<false> callback(&returnState);
    auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
    auto [ctx, header] = streamthrowsCtx(rpcOptions);
    using CancellableCallback = apache::thrift::CancellableRequestClientCallback<false>;
    auto cancellableCallback = cancellable ? CancellableCallback::create(&callback, channel_) : nullptr;
    static const apache::thrift::RpcOptions defaultRpcOptions;
    auto wrappedCallback = apache::thrift::createStreamClientCallback(
        apache::thrift::RequestClientCallback::Ptr(cancellableCallback ? (apache::thrift::RequestClientCallback*)cancellableCallback.get() : &callback),
      hasRpcOptions ? rpcOptions->getBufferOptions() : defaultRpcOptions.getBufferOptions());
    if constexpr (hasRpcOptions) {
      streamthrowsImpl(*rpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback), p_foo);
    } else {
      streamthrowsImpl(defaultRpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback), p_foo);
    }
    if (cancellable) {
      folly::CancellationCallback cb(cancelToken, [&] { CancellableCallback::cancel(std::move(cancellableCallback)); });
      co_await callback.co_waitUntilDone();
    } else {
      co_await callback.co_waitUntilDone();
    }
    if (returnState.isException()) {
      co_yield folly::coro::co_error(std::move(returnState.exception()));
    }
    returnState.resetProtocolId(protocolId);
    returnState.resetCtx(std::move(ctx));
    SCOPE_EXIT {
      if (hasRpcOptions && returnState.header()) {
        auto* rheader = returnState.header();
        if (!rheader->getHeaders().empty()) {
          rpcOptions->setReadHeaders(rheader->releaseHeaders());
        }
        rpcOptions->setRoutingData(rheader->releaseRoutingData());
      }
    };
    apache::thrift::ClientBufferedStream<::std::int32_t> _return;
    if (auto ew = recv_wrapped_streamthrows(_return, returnState)) {
      co_yield folly::coro::co_error(std::move(ew));
    }
    co_return _return;
  }
 public:
#endif // FOLLY_HAS_COROUTINES



  static folly::exception_wrapper recv_wrapped_streamthrows(apache::thrift::ClientBufferedStream<::std::int32_t>& _return, ::apache::thrift::ClientReceiveState& state);
  static apache::thrift::ClientBufferedStream<::std::int32_t> recv_streamthrows(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual apache::thrift::ClientBufferedStream<::std::int32_t> recv_instance_streamthrows(::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_streamthrows(apache::thrift::ClientBufferedStream<::std::int32_t>& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  void streamthrowsT(Protocol_* prot, const apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::StreamClientCallback* callback, ::std::int32_t p_foo);
  std::pair<std::unique_ptr<::apache::thrift::ContextStack>, std::shared_ptr<::apache::thrift::transport::THeader>> streamthrowsCtx(apache::thrift::RpcOptions* rpcOptions);
 public:
  virtual void boththrows(std::unique_ptr<apache::thrift::RequestCallback> callback, ::std::int32_t p_foo);
  virtual void boththrows(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, ::std::int32_t p_foo);
 protected:
  void boththrowsImpl(const apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::StreamClientCallback* callback, ::std::int32_t p_foo);
 public:

  virtual apache::thrift::ClientBufferedStream<::std::int32_t> sync_boththrows(::std::int32_t p_foo);
  virtual apache::thrift::ClientBufferedStream<::std::int32_t> sync_boththrows(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_foo);

  virtual folly::SemiFuture<apache::thrift::ClientBufferedStream<::std::int32_t>> semifuture_boththrows(::std::int32_t p_foo);
  virtual folly::SemiFuture<apache::thrift::ClientBufferedStream<::std::int32_t>> semifuture_boththrows(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_foo);
  virtual folly::SemiFuture<std::pair<apache::thrift::ClientBufferedStream<::std::int32_t>, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_boththrows(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_foo);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<apache::thrift::ClientBufferedStream<::std::int32_t>> co_boththrows(::std::int32_t p_foo) {
    return co_boththrows<false>(nullptr, p_foo);
  }
  template <int = 0>
  folly::coro::Task<apache::thrift::ClientBufferedStream<::std::int32_t>> co_boththrows(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_foo) {
    return co_boththrows<true>(&rpcOptions, p_foo);
  }
 private:
  template <bool hasRpcOptions>
  folly::coro::Task<apache::thrift::ClientBufferedStream<::std::int32_t>> co_boththrows(apache::thrift::RpcOptions* rpcOptions, ::std::int32_t p_foo) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    const bool cancellable = cancelToken.canBeCancelled();
    apache::thrift::ClientReceiveState returnState;
    apache::thrift::ClientSyncCallback<false> callback(&returnState);
    auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
    auto [ctx, header] = boththrowsCtx(rpcOptions);
    using CancellableCallback = apache::thrift::CancellableRequestClientCallback<false>;
    auto cancellableCallback = cancellable ? CancellableCallback::create(&callback, channel_) : nullptr;
    static const apache::thrift::RpcOptions defaultRpcOptions;
    auto wrappedCallback = apache::thrift::createStreamClientCallback(
        apache::thrift::RequestClientCallback::Ptr(cancellableCallback ? (apache::thrift::RequestClientCallback*)cancellableCallback.get() : &callback),
      hasRpcOptions ? rpcOptions->getBufferOptions() : defaultRpcOptions.getBufferOptions());
    if constexpr (hasRpcOptions) {
      boththrowsImpl(*rpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback), p_foo);
    } else {
      boththrowsImpl(defaultRpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback), p_foo);
    }
    if (cancellable) {
      folly::CancellationCallback cb(cancelToken, [&] { CancellableCallback::cancel(std::move(cancellableCallback)); });
      co_await callback.co_waitUntilDone();
    } else {
      co_await callback.co_waitUntilDone();
    }
    if (returnState.isException()) {
      co_yield folly::coro::co_error(std::move(returnState.exception()));
    }
    returnState.resetProtocolId(protocolId);
    returnState.resetCtx(std::move(ctx));
    SCOPE_EXIT {
      if (hasRpcOptions && returnState.header()) {
        auto* rheader = returnState.header();
        if (!rheader->getHeaders().empty()) {
          rpcOptions->setReadHeaders(rheader->releaseHeaders());
        }
        rpcOptions->setRoutingData(rheader->releaseRoutingData());
      }
    };
    apache::thrift::ClientBufferedStream<::std::int32_t> _return;
    if (auto ew = recv_wrapped_boththrows(_return, returnState)) {
      co_yield folly::coro::co_error(std::move(ew));
    }
    co_return _return;
  }
 public:
#endif // FOLLY_HAS_COROUTINES



  static folly::exception_wrapper recv_wrapped_boththrows(apache::thrift::ClientBufferedStream<::std::int32_t>& _return, ::apache::thrift::ClientReceiveState& state);
  static apache::thrift::ClientBufferedStream<::std::int32_t> recv_boththrows(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual apache::thrift::ClientBufferedStream<::std::int32_t> recv_instance_boththrows(::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_boththrows(apache::thrift::ClientBufferedStream<::std::int32_t>& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  void boththrowsT(Protocol_* prot, const apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::StreamClientCallback* callback, ::std::int32_t p_foo);
  std::pair<std::unique_ptr<::apache::thrift::ContextStack>, std::shared_ptr<::apache::thrift::transport::THeader>> boththrowsCtx(apache::thrift::RpcOptions* rpcOptions);
 public:
  virtual void responseandstreamthrows(std::unique_ptr<apache::thrift::RequestCallback> callback, ::std::int32_t p_foo);
  virtual void responseandstreamthrows(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, ::std::int32_t p_foo);
 protected:
  void responseandstreamthrowsImpl(const apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::StreamClientCallback* callback, ::std::int32_t p_foo);
 public:

  virtual apache::thrift::ResponseAndClientBufferedStream<::std::int32_t,::std::int32_t> sync_responseandstreamthrows(::std::int32_t p_foo);
  virtual apache::thrift::ResponseAndClientBufferedStream<::std::int32_t,::std::int32_t> sync_responseandstreamthrows(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_foo);

  virtual folly::SemiFuture<apache::thrift::ResponseAndClientBufferedStream<::std::int32_t,::std::int32_t>> semifuture_responseandstreamthrows(::std::int32_t p_foo);
  virtual folly::SemiFuture<apache::thrift::ResponseAndClientBufferedStream<::std::int32_t,::std::int32_t>> semifuture_responseandstreamthrows(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_foo);
  virtual folly::SemiFuture<std::pair<apache::thrift::ResponseAndClientBufferedStream<::std::int32_t,::std::int32_t>, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_responseandstreamthrows(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_foo);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<apache::thrift::ResponseAndClientBufferedStream<::std::int32_t,::std::int32_t>> co_responseandstreamthrows(::std::int32_t p_foo) {
    return co_responseandstreamthrows<false>(nullptr, p_foo);
  }
  template <int = 0>
  folly::coro::Task<apache::thrift::ResponseAndClientBufferedStream<::std::int32_t,::std::int32_t>> co_responseandstreamthrows(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_foo) {
    return co_responseandstreamthrows<true>(&rpcOptions, p_foo);
  }
 private:
  template <bool hasRpcOptions>
  folly::coro::Task<apache::thrift::ResponseAndClientBufferedStream<::std::int32_t,::std::int32_t>> co_responseandstreamthrows(apache::thrift::RpcOptions* rpcOptions, ::std::int32_t p_foo) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    const bool cancellable = cancelToken.canBeCancelled();
    apache::thrift::ClientReceiveState returnState;
    apache::thrift::ClientSyncCallback<false> callback(&returnState);
    auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
    auto [ctx, header] = responseandstreamthrowsCtx(rpcOptions);
    using CancellableCallback = apache::thrift::CancellableRequestClientCallback<false>;
    auto cancellableCallback = cancellable ? CancellableCallback::create(&callback, channel_) : nullptr;
    static const apache::thrift::RpcOptions defaultRpcOptions;
    auto wrappedCallback = apache::thrift::createStreamClientCallback(
        apache::thrift::RequestClientCallback::Ptr(cancellableCallback ? (apache::thrift::RequestClientCallback*)cancellableCallback.get() : &callback),
      hasRpcOptions ? rpcOptions->getBufferOptions() : defaultRpcOptions.getBufferOptions());
    if constexpr (hasRpcOptions) {
      responseandstreamthrowsImpl(*rpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback), p_foo);
    } else {
      responseandstreamthrowsImpl(defaultRpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback), p_foo);
    }
    if (cancellable) {
      folly::CancellationCallback cb(cancelToken, [&] { CancellableCallback::cancel(std::move(cancellableCallback)); });
      co_await callback.co_waitUntilDone();
    } else {
      co_await callback.co_waitUntilDone();
    }
    if (returnState.isException()) {
      co_yield folly::coro::co_error(std::move(returnState.exception()));
    }
    returnState.resetProtocolId(protocolId);
    returnState.resetCtx(std::move(ctx));
    SCOPE_EXIT {
      if (hasRpcOptions && returnState.header()) {
        auto* rheader = returnState.header();
        if (!rheader->getHeaders().empty()) {
          rpcOptions->setReadHeaders(rheader->releaseHeaders());
        }
        rpcOptions->setRoutingData(rheader->releaseRoutingData());
      }
    };
    apache::thrift::ResponseAndClientBufferedStream<::std::int32_t,::std::int32_t> _return;
    if (auto ew = recv_wrapped_responseandstreamthrows(_return, returnState)) {
      co_yield folly::coro::co_error(std::move(ew));
    }
    co_return _return;
  }
 public:
#endif // FOLLY_HAS_COROUTINES



  static folly::exception_wrapper recv_wrapped_responseandstreamthrows(apache::thrift::ResponseAndClientBufferedStream<::std::int32_t,::std::int32_t>& _return, ::apache::thrift::ClientReceiveState& state);
  static apache::thrift::ResponseAndClientBufferedStream<::std::int32_t,::std::int32_t> recv_responseandstreamthrows(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual apache::thrift::ResponseAndClientBufferedStream<::std::int32_t,::std::int32_t> recv_instance_responseandstreamthrows(::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_responseandstreamthrows(apache::thrift::ResponseAndClientBufferedStream<::std::int32_t,::std::int32_t>& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  void responseandstreamthrowsT(Protocol_* prot, const apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::StreamClientCallback* callback, ::std::int32_t p_foo);
  std::pair<std::unique_ptr<::apache::thrift::ContextStack>, std::shared_ptr<::apache::thrift::transport::THeader>> responseandstreamthrowsCtx(apache::thrift::RpcOptions* rpcOptions);
 public:
  virtual void returnstreamFast(std::unique_ptr<apache::thrift::RequestCallback> callback, ::std::int32_t p_i32_from, ::std::int32_t p_i32_to);
  virtual void returnstreamFast(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, ::std::int32_t p_i32_from, ::std::int32_t p_i32_to);
 protected:
  void returnstreamFastImpl(const apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::StreamClientCallback* callback, ::std::int32_t p_i32_from, ::std::int32_t p_i32_to);
 public:

  virtual apache::thrift::ClientBufferedStream<::std::int32_t> sync_returnstreamFast(::std::int32_t p_i32_from, ::std::int32_t p_i32_to);
  virtual apache::thrift::ClientBufferedStream<::std::int32_t> sync_returnstreamFast(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_i32_from, ::std::int32_t p_i32_to);

  virtual folly::SemiFuture<apache::thrift::ClientBufferedStream<::std::int32_t>> semifuture_returnstreamFast(::std::int32_t p_i32_from, ::std::int32_t p_i32_to);
  virtual folly::SemiFuture<apache::thrift::ClientBufferedStream<::std::int32_t>> semifuture_returnstreamFast(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_i32_from, ::std::int32_t p_i32_to);
  virtual folly::SemiFuture<std::pair<apache::thrift::ClientBufferedStream<::std::int32_t>, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_returnstreamFast(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_i32_from, ::std::int32_t p_i32_to);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<apache::thrift::ClientBufferedStream<::std::int32_t>> co_returnstreamFast(::std::int32_t p_i32_from, ::std::int32_t p_i32_to) {
    return co_returnstreamFast<false>(nullptr, p_i32_from, p_i32_to);
  }
  template <int = 0>
  folly::coro::Task<apache::thrift::ClientBufferedStream<::std::int32_t>> co_returnstreamFast(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_i32_from, ::std::int32_t p_i32_to) {
    return co_returnstreamFast<true>(&rpcOptions, p_i32_from, p_i32_to);
  }
 private:
  template <bool hasRpcOptions>
  folly::coro::Task<apache::thrift::ClientBufferedStream<::std::int32_t>> co_returnstreamFast(apache::thrift::RpcOptions* rpcOptions, ::std::int32_t p_i32_from, ::std::int32_t p_i32_to) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    const bool cancellable = cancelToken.canBeCancelled();
    apache::thrift::ClientReceiveState returnState;
    apache::thrift::ClientSyncCallback<false> callback(&returnState);
    auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
    auto [ctx, header] = returnstreamFastCtx(rpcOptions);
    using CancellableCallback = apache::thrift::CancellableRequestClientCallback<false>;
    auto cancellableCallback = cancellable ? CancellableCallback::create(&callback, channel_) : nullptr;
    static const apache::thrift::RpcOptions defaultRpcOptions;
    auto wrappedCallback = apache::thrift::createStreamClientCallback(
        apache::thrift::RequestClientCallback::Ptr(cancellableCallback ? (apache::thrift::RequestClientCallback*)cancellableCallback.get() : &callback),
      hasRpcOptions ? rpcOptions->getBufferOptions() : defaultRpcOptions.getBufferOptions());
    if constexpr (hasRpcOptions) {
      returnstreamFastImpl(*rpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback), p_i32_from, p_i32_to);
    } else {
      returnstreamFastImpl(defaultRpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback), p_i32_from, p_i32_to);
    }
    if (cancellable) {
      folly::CancellationCallback cb(cancelToken, [&] { CancellableCallback::cancel(std::move(cancellableCallback)); });
      co_await callback.co_waitUntilDone();
    } else {
      co_await callback.co_waitUntilDone();
    }
    if (returnState.isException()) {
      co_yield folly::coro::co_error(std::move(returnState.exception()));
    }
    returnState.resetProtocolId(protocolId);
    returnState.resetCtx(std::move(ctx));
    SCOPE_EXIT {
      if (hasRpcOptions && returnState.header()) {
        auto* rheader = returnState.header();
        if (!rheader->getHeaders().empty()) {
          rpcOptions->setReadHeaders(rheader->releaseHeaders());
        }
        rpcOptions->setRoutingData(rheader->releaseRoutingData());
      }
    };
    apache::thrift::ClientBufferedStream<::std::int32_t> _return;
    if (auto ew = recv_wrapped_returnstreamFast(_return, returnState)) {
      co_yield folly::coro::co_error(std::move(ew));
    }
    co_return _return;
  }
 public:
#endif // FOLLY_HAS_COROUTINES



  static folly::exception_wrapper recv_wrapped_returnstreamFast(apache::thrift::ClientBufferedStream<::std::int32_t>& _return, ::apache::thrift::ClientReceiveState& state);
  static apache::thrift::ClientBufferedStream<::std::int32_t> recv_returnstreamFast(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual apache::thrift::ClientBufferedStream<::std::int32_t> recv_instance_returnstreamFast(::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_returnstreamFast(apache::thrift::ClientBufferedStream<::std::int32_t>& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  void returnstreamFastT(Protocol_* prot, const apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::StreamClientCallback* callback, ::std::int32_t p_i32_from, ::std::int32_t p_i32_to);
  std::pair<std::unique_ptr<::apache::thrift::ContextStack>, std::shared_ptr<::apache::thrift::transport::THeader>> returnstreamFastCtx(apache::thrift::RpcOptions* rpcOptions);
 public:
};

} // cpp2
