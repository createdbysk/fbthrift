/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include "thrift/compiler/test/fixtures/sink/gen-cpp2/SinkService.h"

#include <thrift/lib/cpp2/gen/service_tcc.h>

namespace cpp2 {
typedef apache::thrift::ThriftPresult<false> SinkService_method_pargs;
typedef apache::thrift::ThriftPResultSink<
    apache::thrift::ThriftPresult<true>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::SinkPayload*>>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::FinalResponse*>>
    > SinkService_method_presult;
typedef apache::thrift::ThriftPresult<false> SinkService_methodAndReponse_pargs;
typedef apache::thrift::ThriftPResultSink<
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::InitialResponse*>>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::SinkPayload*>>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::FinalResponse*>>
    > SinkService_methodAndReponse_presult;
typedef apache::thrift::ThriftPresult<false> SinkService_methodThrow_pargs;
typedef apache::thrift::ThriftPResultSink<
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<1, ::apache::thrift::type_class::structure, ::cpp2::InitialException>>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::SinkPayload*>>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::FinalResponse*>>
    > SinkService_methodThrow_presult;
typedef apache::thrift::ThriftPresult<false> SinkService_methodSinkThrow_pargs;
typedef apache::thrift::ThriftPResultSink<
    apache::thrift::ThriftPresult<true>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::SinkPayload*>, apache::thrift::FieldData<1, ::apache::thrift::type_class::structure, ::cpp2::SinkException1>>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::FinalResponse*>>
    > SinkService_methodSinkThrow_presult;
typedef apache::thrift::ThriftPresult<false> SinkService_methodFinalThrow_pargs;
typedef apache::thrift::ThriftPResultSink<
    apache::thrift::ThriftPresult<true>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::SinkPayload*>>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::FinalResponse*>, apache::thrift::FieldData<1, ::apache::thrift::type_class::structure, ::cpp2::SinkException2>>
    > SinkService_methodFinalThrow_presult;
typedef apache::thrift::ThriftPresult<false> SinkService_methodBothThrow_pargs;
typedef apache::thrift::ThriftPResultSink<
    apache::thrift::ThriftPresult<true>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::SinkPayload*>, apache::thrift::FieldData<1, ::apache::thrift::type_class::structure, ::cpp2::SinkException1>>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::FinalResponse*>, apache::thrift::FieldData<1, ::apache::thrift::type_class::structure, ::cpp2::SinkException2>>
    > SinkService_methodBothThrow_presult;
typedef apache::thrift::ThriftPresult<false> SinkService_methodFast_pargs;
typedef apache::thrift::ThriftPResultSink<
    apache::thrift::ThriftPresult<true>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::SinkPayload*>>,
    apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::cpp2::FinalResponse*>>
    > SinkService_methodFast_presult;
template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::setUpAndProcess_method(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  if (!setUpRequestProcessing(req, ctx, eb, tm, apache::thrift::RpcKind::SINK, iface_)) {
    return;
  }
  auto scope = iface_->getRequestExecutionScope(ctx, apache::thrift::concurrency::NORMAL);
  ctx->setRequestExecutionScope(std::move(scope));
  processInThread(std::move(req), std::move(serializedRequest), ctx, eb, tm, apache::thrift::RpcKind::SINK, &SinkServiceAsyncProcessor::process_method<ProtocolIn_, ProtocolOut_>, this);
}

template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::process_method(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  if (!req->getShouldStartProcessing()) {
    apache::thrift::HandlerCallbackBase::releaseRequest(std::move(req), eb);
    return;
  }
  // make sure getRequestContext is null
  // so async calls don't accidentally use it
  iface_->setRequestContext(nullptr);
  SinkService_method_pargs args;
  std::unique_ptr<apache::thrift::ContextStack> ctxStack(this->getContextStack(this->getServiceName(), "SinkService.method", ctx));
  try {
    deserializeRequest<ProtocolIn_>(args, ctx->getMethodName(), std::move(serializedRequest).uncompress(), ctxStack.get());
  }
  catch (const std::exception& ex) {
    folly::exception_wrapper ew(std::current_exception(), ex);
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ew, std::move(req), ctx, eb, "method");
    return;
  }
  auto callback = std::make_unique<apache::thrift::HandlerCallback<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>>>(std::move(req), std::move(ctxStack), return_method<ProtocolIn_,ProtocolOut_>, throw_wrapped_method<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx, apache::thrift::ServerInterface::getBlockingThreadManager(tm));
  iface_->async_tm_method(std::move(callback));
}

template <class ProtocolIn_, class ProtocolOut_>
std::pair<apache::thrift::LegacySerializedResponse, apache::thrift::detail::SinkConsumerImpl> SinkServiceAsyncProcessor::return_method(apache::thrift::ContextStack* ctx, ::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>&& _return, folly::Executor::KeepAlive<> executor) {
  ProtocolOut_ prot;
  SinkService_method_presult::FieldsType result;
  using SinkPResultType = SinkService_method_presult::SinkPResultType;
  using FinalResponsePResultType = SinkService_method_presult::FinalResponsePResultType;

  using ExMapType = apache::thrift::detail::ap::EmptyExMapType;

  auto sinkConsumerImpl = apache::thrift::detail::ap::toSinkConsumerImpl<
      ProtocolIn_,
      ProtocolOut_,
      SinkPResultType,
      FinalResponsePResultType,
      ExMapType>(
      std::move(_return),
      std::move(executor));

  return {serializeLegacyResponse("method", &prot, 0, ctx, result), std::move(sinkConsumerImpl)};
}

template <class ProtocolIn_, class ProtocolOut_>
void SinkServiceAsyncProcessor::throw_wrapped_method(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  {
    (void)protoSeqId;
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "method");
    return;
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::setUpAndProcess_methodAndReponse(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  if (!setUpRequestProcessing(req, ctx, eb, tm, apache::thrift::RpcKind::SINK, iface_)) {
    return;
  }
  auto scope = iface_->getRequestExecutionScope(ctx, apache::thrift::concurrency::NORMAL);
  ctx->setRequestExecutionScope(std::move(scope));
  processInThread(std::move(req), std::move(serializedRequest), ctx, eb, tm, apache::thrift::RpcKind::SINK, &SinkServiceAsyncProcessor::process_methodAndReponse<ProtocolIn_, ProtocolOut_>, this);
}

template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::process_methodAndReponse(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  if (!req->getShouldStartProcessing()) {
    apache::thrift::HandlerCallbackBase::releaseRequest(std::move(req), eb);
    return;
  }
  // make sure getRequestContext is null
  // so async calls don't accidentally use it
  iface_->setRequestContext(nullptr);
  SinkService_methodAndReponse_pargs args;
  std::unique_ptr<apache::thrift::ContextStack> ctxStack(this->getContextStack(this->getServiceName(), "SinkService.methodAndReponse", ctx));
  try {
    deserializeRequest<ProtocolIn_>(args, ctx->getMethodName(), std::move(serializedRequest).uncompress(), ctxStack.get());
  }
  catch (const std::exception& ex) {
    folly::exception_wrapper ew(std::current_exception(), ex);
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ew, std::move(req), ctx, eb, "methodAndReponse");
    return;
  }
  auto callback = std::make_unique<apache::thrift::HandlerCallback<::apache::thrift::ResponseAndSinkConsumer<::cpp2::InitialResponse, ::cpp2::SinkPayload, ::cpp2::FinalResponse>>>(std::move(req), std::move(ctxStack), return_methodAndReponse<ProtocolIn_,ProtocolOut_>, throw_wrapped_methodAndReponse<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx, apache::thrift::ServerInterface::getBlockingThreadManager(tm));
  iface_->async_tm_methodAndReponse(std::move(callback));
}

template <class ProtocolIn_, class ProtocolOut_>
std::pair<apache::thrift::LegacySerializedResponse, apache::thrift::detail::SinkConsumerImpl> SinkServiceAsyncProcessor::return_methodAndReponse(apache::thrift::ContextStack* ctx, ::apache::thrift::ResponseAndSinkConsumer<::cpp2::InitialResponse, ::cpp2::SinkPayload, ::cpp2::FinalResponse>&& _return, folly::Executor::KeepAlive<> executor) {
  ProtocolOut_ prot;
  SinkService_methodAndReponse_presult::FieldsType result;
  using SinkPResultType = SinkService_methodAndReponse_presult::SinkPResultType;
  using FinalResponsePResultType = SinkService_methodAndReponse_presult::FinalResponsePResultType;
  result.get<0>().value = &_return.response;
  result.setIsSet(0, true);

  using ExMapType = apache::thrift::detail::ap::EmptyExMapType;

  auto sinkConsumerImpl = apache::thrift::detail::ap::toSinkConsumerImpl<
      ProtocolIn_,
      ProtocolOut_,
      SinkPResultType,
      FinalResponsePResultType,
      ExMapType>(
      std::move(_return.sinkConsumer),
      std::move(executor));

  return {serializeLegacyResponse("methodAndReponse", &prot, 0, ctx, result), std::move(sinkConsumerImpl)};
}

template <class ProtocolIn_, class ProtocolOut_>
void SinkServiceAsyncProcessor::throw_wrapped_methodAndReponse(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  {
    (void)protoSeqId;
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "methodAndReponse");
    return;
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::setUpAndProcess_methodThrow(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  if (!setUpRequestProcessing(req, ctx, eb, tm, apache::thrift::RpcKind::SINK, iface_)) {
    return;
  }
  auto scope = iface_->getRequestExecutionScope(ctx, apache::thrift::concurrency::NORMAL);
  ctx->setRequestExecutionScope(std::move(scope));
  processInThread(std::move(req), std::move(serializedRequest), ctx, eb, tm, apache::thrift::RpcKind::SINK, &SinkServiceAsyncProcessor::process_methodThrow<ProtocolIn_, ProtocolOut_>, this);
}

template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::process_methodThrow(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  if (!req->getShouldStartProcessing()) {
    apache::thrift::HandlerCallbackBase::releaseRequest(std::move(req), eb);
    return;
  }
  // make sure getRequestContext is null
  // so async calls don't accidentally use it
  iface_->setRequestContext(nullptr);
  SinkService_methodThrow_pargs args;
  std::unique_ptr<apache::thrift::ContextStack> ctxStack(this->getContextStack(this->getServiceName(), "SinkService.methodThrow", ctx));
  try {
    deserializeRequest<ProtocolIn_>(args, ctx->getMethodName(), std::move(serializedRequest).uncompress(), ctxStack.get());
  }
  catch (const std::exception& ex) {
    folly::exception_wrapper ew(std::current_exception(), ex);
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ew, std::move(req), ctx, eb, "methodThrow");
    return;
  }
  auto callback = std::make_unique<apache::thrift::HandlerCallback<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>>>(std::move(req), std::move(ctxStack), return_methodThrow<ProtocolIn_,ProtocolOut_>, throw_wrapped_methodThrow<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx, apache::thrift::ServerInterface::getBlockingThreadManager(tm));
  iface_->async_tm_methodThrow(std::move(callback));
}

template <class ProtocolIn_, class ProtocolOut_>
std::pair<apache::thrift::LegacySerializedResponse, apache::thrift::detail::SinkConsumerImpl> SinkServiceAsyncProcessor::return_methodThrow(apache::thrift::ContextStack* ctx, ::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>&& _return, folly::Executor::KeepAlive<> executor) {
  ProtocolOut_ prot;
  SinkService_methodThrow_presult::FieldsType result;
  using SinkPResultType = SinkService_methodThrow_presult::SinkPResultType;
  using FinalResponsePResultType = SinkService_methodThrow_presult::FinalResponsePResultType;

  using ExMapType = apache::thrift::detail::ap::EmptyExMapType;

  auto sinkConsumerImpl = apache::thrift::detail::ap::toSinkConsumerImpl<
      ProtocolIn_,
      ProtocolOut_,
      SinkPResultType,
      FinalResponsePResultType,
      ExMapType>(
      std::move(_return),
      std::move(executor));

  return {serializeLegacyResponse("methodThrow", &prot, 0, ctx, result), std::move(sinkConsumerImpl)};
}

template <class ProtocolIn_, class ProtocolOut_>
void SinkServiceAsyncProcessor::throw_wrapped_methodThrow(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  SinkService_methodThrow_presult result;
  if (ew.with_exception([&]( ::cpp2::InitialException& e) {
    if (ctx) {
      ctx->userExceptionWrapped(true, ew);
    }
    ::apache::thrift::util::appendExceptionToHeader(ew, *reqCtx);
    ::apache::thrift::util::appendErrorClassificationToHeader< ::cpp2::InitialException>(*reqCtx);
    result.fields.get<0>().ref() = e;
    result.fields.setIsSet(0, true);
  }
  )) {} else
  {
    (void)protoSeqId;
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "methodThrow");
    return;
  }
  ProtocolOut_ prot;
  auto response = serializeLegacyResponse("methodThrow", &prot, protoSeqId, ctx, result.fields);
  response.buffer = apache::thrift::transport::THeader::transform(std::move(response.buffer), reqCtx->getHeader()->getWriteTransforms());
  req->sendSinkReply(std::move(response.buffer), apache::thrift::detail::SinkConsumerImpl{});
}

template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::setUpAndProcess_methodSinkThrow(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  if (!setUpRequestProcessing(req, ctx, eb, tm, apache::thrift::RpcKind::SINK, iface_)) {
    return;
  }
  auto scope = iface_->getRequestExecutionScope(ctx, apache::thrift::concurrency::NORMAL);
  ctx->setRequestExecutionScope(std::move(scope));
  processInThread(std::move(req), std::move(serializedRequest), ctx, eb, tm, apache::thrift::RpcKind::SINK, &SinkServiceAsyncProcessor::process_methodSinkThrow<ProtocolIn_, ProtocolOut_>, this);
}

template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::process_methodSinkThrow(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  if (!req->getShouldStartProcessing()) {
    apache::thrift::HandlerCallbackBase::releaseRequest(std::move(req), eb);
    return;
  }
  // make sure getRequestContext is null
  // so async calls don't accidentally use it
  iface_->setRequestContext(nullptr);
  SinkService_methodSinkThrow_pargs args;
  std::unique_ptr<apache::thrift::ContextStack> ctxStack(this->getContextStack(this->getServiceName(), "SinkService.methodSinkThrow", ctx));
  try {
    deserializeRequest<ProtocolIn_>(args, ctx->getMethodName(), std::move(serializedRequest).uncompress(), ctxStack.get());
  }
  catch (const std::exception& ex) {
    folly::exception_wrapper ew(std::current_exception(), ex);
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ew, std::move(req), ctx, eb, "methodSinkThrow");
    return;
  }
  auto callback = std::make_unique<apache::thrift::HandlerCallback<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>>>(std::move(req), std::move(ctxStack), return_methodSinkThrow<ProtocolIn_,ProtocolOut_>, throw_wrapped_methodSinkThrow<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx, apache::thrift::ServerInterface::getBlockingThreadManager(tm));
  iface_->async_tm_methodSinkThrow(std::move(callback));
}

template <class ProtocolIn_, class ProtocolOut_>
std::pair<apache::thrift::LegacySerializedResponse, apache::thrift::detail::SinkConsumerImpl> SinkServiceAsyncProcessor::return_methodSinkThrow(apache::thrift::ContextStack* ctx, ::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>&& _return, folly::Executor::KeepAlive<> executor) {
  ProtocolOut_ prot;
  SinkService_methodSinkThrow_presult::FieldsType result;
  using SinkPResultType = SinkService_methodSinkThrow_presult::SinkPResultType;
  using FinalResponsePResultType = SinkService_methodSinkThrow_presult::FinalResponsePResultType;

  using ExMapType = apache::thrift::detail::ap::EmptyExMapType;

  auto sinkConsumerImpl = apache::thrift::detail::ap::toSinkConsumerImpl<
      ProtocolIn_,
      ProtocolOut_,
      SinkPResultType,
      FinalResponsePResultType,
      ExMapType>(
      std::move(_return),
      std::move(executor));

  return {serializeLegacyResponse("methodSinkThrow", &prot, 0, ctx, result), std::move(sinkConsumerImpl)};
}

template <class ProtocolIn_, class ProtocolOut_>
void SinkServiceAsyncProcessor::throw_wrapped_methodSinkThrow(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  {
    (void)protoSeqId;
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "methodSinkThrow");
    return;
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::setUpAndProcess_methodFinalThrow(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  if (!setUpRequestProcessing(req, ctx, eb, tm, apache::thrift::RpcKind::SINK, iface_)) {
    return;
  }
  auto scope = iface_->getRequestExecutionScope(ctx, apache::thrift::concurrency::NORMAL);
  ctx->setRequestExecutionScope(std::move(scope));
  processInThread(std::move(req), std::move(serializedRequest), ctx, eb, tm, apache::thrift::RpcKind::SINK, &SinkServiceAsyncProcessor::process_methodFinalThrow<ProtocolIn_, ProtocolOut_>, this);
}

template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::process_methodFinalThrow(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  if (!req->getShouldStartProcessing()) {
    apache::thrift::HandlerCallbackBase::releaseRequest(std::move(req), eb);
    return;
  }
  // make sure getRequestContext is null
  // so async calls don't accidentally use it
  iface_->setRequestContext(nullptr);
  SinkService_methodFinalThrow_pargs args;
  std::unique_ptr<apache::thrift::ContextStack> ctxStack(this->getContextStack(this->getServiceName(), "SinkService.methodFinalThrow", ctx));
  try {
    deserializeRequest<ProtocolIn_>(args, ctx->getMethodName(), std::move(serializedRequest).uncompress(), ctxStack.get());
  }
  catch (const std::exception& ex) {
    folly::exception_wrapper ew(std::current_exception(), ex);
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ew, std::move(req), ctx, eb, "methodFinalThrow");
    return;
  }
  auto callback = std::make_unique<apache::thrift::HandlerCallback<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>>>(std::move(req), std::move(ctxStack), return_methodFinalThrow<ProtocolIn_,ProtocolOut_>, throw_wrapped_methodFinalThrow<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx, apache::thrift::ServerInterface::getBlockingThreadManager(tm));
  iface_->async_tm_methodFinalThrow(std::move(callback));
}

template <class ProtocolIn_, class ProtocolOut_>
std::pair<apache::thrift::LegacySerializedResponse, apache::thrift::detail::SinkConsumerImpl> SinkServiceAsyncProcessor::return_methodFinalThrow(apache::thrift::ContextStack* ctx, ::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>&& _return, folly::Executor::KeepAlive<> executor) {
  ProtocolOut_ prot;
  SinkService_methodFinalThrow_presult::FieldsType result;
  using SinkPResultType = SinkService_methodFinalThrow_presult::SinkPResultType;
  using FinalResponsePResultType = SinkService_methodFinalThrow_presult::FinalResponsePResultType;

  struct ExMapType {
    bool operator()(FinalResponsePResultType& res, folly::exception_wrapper ew) {
      if (ew.with_exception([&]( ::cpp2::SinkException2& e) {
            res.get<1>().ref() = e;
            res.setIsSet(1, true);
          })) {
        return true;
      }
      return false;
    }
  };

  auto sinkConsumerImpl = apache::thrift::detail::ap::toSinkConsumerImpl<
      ProtocolIn_,
      ProtocolOut_,
      SinkPResultType,
      FinalResponsePResultType,
      ExMapType>(
      std::move(_return),
      std::move(executor));

  return {serializeLegacyResponse("methodFinalThrow", &prot, 0, ctx, result), std::move(sinkConsumerImpl)};
}

template <class ProtocolIn_, class ProtocolOut_>
void SinkServiceAsyncProcessor::throw_wrapped_methodFinalThrow(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  {
    (void)protoSeqId;
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "methodFinalThrow");
    return;
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::setUpAndProcess_methodBothThrow(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  if (!setUpRequestProcessing(req, ctx, eb, tm, apache::thrift::RpcKind::SINK, iface_)) {
    return;
  }
  auto scope = iface_->getRequestExecutionScope(ctx, apache::thrift::concurrency::NORMAL);
  ctx->setRequestExecutionScope(std::move(scope));
  processInThread(std::move(req), std::move(serializedRequest), ctx, eb, tm, apache::thrift::RpcKind::SINK, &SinkServiceAsyncProcessor::process_methodBothThrow<ProtocolIn_, ProtocolOut_>, this);
}

template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::process_methodBothThrow(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  if (!req->getShouldStartProcessing()) {
    apache::thrift::HandlerCallbackBase::releaseRequest(std::move(req), eb);
    return;
  }
  // make sure getRequestContext is null
  // so async calls don't accidentally use it
  iface_->setRequestContext(nullptr);
  SinkService_methodBothThrow_pargs args;
  std::unique_ptr<apache::thrift::ContextStack> ctxStack(this->getContextStack(this->getServiceName(), "SinkService.methodBothThrow", ctx));
  try {
    deserializeRequest<ProtocolIn_>(args, ctx->getMethodName(), std::move(serializedRequest).uncompress(), ctxStack.get());
  }
  catch (const std::exception& ex) {
    folly::exception_wrapper ew(std::current_exception(), ex);
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ew, std::move(req), ctx, eb, "methodBothThrow");
    return;
  }
  auto callback = std::make_unique<apache::thrift::HandlerCallback<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>>>(std::move(req), std::move(ctxStack), return_methodBothThrow<ProtocolIn_,ProtocolOut_>, throw_wrapped_methodBothThrow<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx, apache::thrift::ServerInterface::getBlockingThreadManager(tm));
  iface_->async_tm_methodBothThrow(std::move(callback));
}

template <class ProtocolIn_, class ProtocolOut_>
std::pair<apache::thrift::LegacySerializedResponse, apache::thrift::detail::SinkConsumerImpl> SinkServiceAsyncProcessor::return_methodBothThrow(apache::thrift::ContextStack* ctx, ::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>&& _return, folly::Executor::KeepAlive<> executor) {
  ProtocolOut_ prot;
  SinkService_methodBothThrow_presult::FieldsType result;
  using SinkPResultType = SinkService_methodBothThrow_presult::SinkPResultType;
  using FinalResponsePResultType = SinkService_methodBothThrow_presult::FinalResponsePResultType;

  struct ExMapType {
    bool operator()(FinalResponsePResultType& res, folly::exception_wrapper ew) {
      if (ew.with_exception([&]( ::cpp2::SinkException2& e) {
            res.get<1>().ref() = e;
            res.setIsSet(1, true);
          })) {
        return true;
      }
      return false;
    }
  };

  auto sinkConsumerImpl = apache::thrift::detail::ap::toSinkConsumerImpl<
      ProtocolIn_,
      ProtocolOut_,
      SinkPResultType,
      FinalResponsePResultType,
      ExMapType>(
      std::move(_return),
      std::move(executor));

  return {serializeLegacyResponse("methodBothThrow", &prot, 0, ctx, result), std::move(sinkConsumerImpl)};
}

template <class ProtocolIn_, class ProtocolOut_>
void SinkServiceAsyncProcessor::throw_wrapped_methodBothThrow(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  {
    (void)protoSeqId;
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "methodBothThrow");
    return;
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::setUpAndProcess_methodFast(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  if (!setUpRequestProcessing(req, ctx, eb, nullptr, apache::thrift::RpcKind::SINK, iface_)) {
    return;
  }
  process_methodFast<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(serializedRequest), ctx, eb, tm);
}

template <typename ProtocolIn_, typename ProtocolOut_>
void SinkServiceAsyncProcessor::process_methodFast(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  if (!req->getShouldStartProcessing()) {
    apache::thrift::HandlerCallbackBase::releaseRequest(std::move(req), eb);
    return;
  }
  // make sure getRequestContext is null
  // so async calls don't accidentally use it
  iface_->setRequestContext(nullptr);
  SinkService_methodFast_pargs args;
  std::unique_ptr<apache::thrift::ContextStack> ctxStack(this->getContextStack(this->getServiceName(), "SinkService.methodFast", ctx));
  try {
    deserializeRequest<ProtocolIn_>(args, ctx->getMethodName(), std::move(serializedRequest).uncompress(), ctxStack.get());
  }
  catch (const std::exception& ex) {
    folly::exception_wrapper ew(std::current_exception(), ex);
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ew, std::move(req), ctx, eb, "methodFast");
    return;
  }
  auto callback = std::make_unique<apache::thrift::HandlerCallback<::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>>>(std::move(req), std::move(ctxStack), return_methodFast<ProtocolIn_,ProtocolOut_>, throw_wrapped_methodFast<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx, eb);
  iface_->async_eb_methodFast(std::move(callback));
}

template <class ProtocolIn_, class ProtocolOut_>
std::pair<apache::thrift::LegacySerializedResponse, apache::thrift::detail::SinkConsumerImpl> SinkServiceAsyncProcessor::return_methodFast(apache::thrift::ContextStack* ctx, ::apache::thrift::SinkConsumer<::cpp2::SinkPayload, ::cpp2::FinalResponse>&& _return, folly::Executor::KeepAlive<> executor) {
  ProtocolOut_ prot;
  SinkService_methodFast_presult::FieldsType result;
  using SinkPResultType = SinkService_methodFast_presult::SinkPResultType;
  using FinalResponsePResultType = SinkService_methodFast_presult::FinalResponsePResultType;

  using ExMapType = apache::thrift::detail::ap::EmptyExMapType;

  auto sinkConsumerImpl = apache::thrift::detail::ap::toSinkConsumerImpl<
      ProtocolIn_,
      ProtocolOut_,
      SinkPResultType,
      FinalResponsePResultType,
      ExMapType>(
      std::move(_return),
      std::move(executor));

  return {serializeLegacyResponse("methodFast", &prot, 0, ctx, result), std::move(sinkConsumerImpl)};
}

template <class ProtocolIn_, class ProtocolOut_>
void SinkServiceAsyncProcessor::throw_wrapped_methodFast(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  {
    (void)protoSeqId;
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "methodFast");
    return;
  }
}


} // cpp2
