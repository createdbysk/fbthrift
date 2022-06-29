/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/service_h.h>

#include "thrift/compiler/test/fixtures/namespace_from_package/gen-cpp2/TestServiceAsyncClient.h"
#include "thrift/compiler/test/fixtures/namespace_from_package/gen-cpp2/module_types.h"

namespace folly {
  class IOBuf;
  class IOBufQueue;
}
namespace apache { namespace thrift {
  class Cpp2RequestContext;
  class BinaryProtocolReader;
  class CompactProtocolReader;
  namespace transport { class THeader; }
}}

namespace test { namespace namespace_from_package { namespace module {
class TestService;
class TestServiceAsyncProcessor;

class TestServiceServiceInfoHolder : public apache::thrift::ServiceInfoHolder {
  public:
   apache::thrift::ServiceRequestInfoMap const& requestInfoMap() const override;
   static apache::thrift::ServiceRequestInfoMap staticRequestInfoMap();
};
}}} // test::namespace_from_package::module

namespace apache::thrift {
template <>
class ServiceHandler<::test::namespace_from_package::module::TestService> : public apache::thrift::ServerInterface {
 public:
  std::string_view getGeneratedName() const override { return "TestService"; }

  static const char* __fbthrift_thrift_uri() {
    return "test.dev/namespace_from_package/module/TestService";
  }

  typedef ::test::namespace_from_package::module::TestServiceAsyncProcessor ProcessorType;
  std::unique_ptr<apache::thrift::AsyncProcessor> getProcessor() override;
  CreateMethodMetadataResult createMethodMetadata() override;
 private:
  std::optional<std::reference_wrapper<apache::thrift::ServiceRequestInfoMap const>> getServiceRequestInfoMap() const;
 public:

  virtual ::std::int64_t init(::std::int64_t /*int1*/);
  virtual folly::Future<::std::int64_t> future_init(::std::int64_t p_int1);
  virtual folly::SemiFuture<::std::int64_t> semifuture_init(::std::int64_t p_int1);
  virtual void async_tm_init(std::unique_ptr<apache::thrift::HandlerCallback<::std::int64_t>> callback, ::std::int64_t p_int1);
 private:
  static ::test::namespace_from_package::module::TestServiceServiceInfoHolder __fbthrift_serviceInfoHolder;
  std::atomic<apache::thrift::detail::si::InvocationType> __fbthrift_invocation_init{apache::thrift::detail::si::InvocationType::AsyncTm};
};

} // namespace apache::thrift

namespace test { namespace namespace_from_package { namespace module {
using TestServiceSvIf [[deprecated("Use apache::thrift::ServiceHandler<TestService> instead")]] = ::apache::thrift::ServiceHandler<TestService>;
}}} // test::namespace_from_package::module
namespace test { namespace namespace_from_package { namespace module {
class TestServiceSvNull : public TestServiceSvIf {
 public:
  ::std::int64_t init(::std::int64_t /*int1*/) override;
};

class TestServiceAsyncProcessor : public ::apache::thrift::GeneratedAsyncProcessor {
 public:
  const char* getServiceName() override;
  void getServiceMetadata(apache::thrift::metadata::ThriftServiceMetadataResponse& response) override;
  using BaseAsyncProcessor = void;
 protected:
  ::apache::thrift::ServiceHandler<::test::namespace_from_package::module::TestService>* iface_;
 public:
  // This is implemented in case the corresponding AsyncProcessorFactory did not implement createMethodMetadata.
  // This can happen if the service is using a custom AsyncProcessorFactory but re-using the same AsyncProcessor.
  void processSerializedCompressedRequest(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) override;
  // By default, this overload will be called for generated services
  void processSerializedCompressedRequestWithMetadata(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, const apache::thrift::AsyncProcessorFactory::MethodMetadata& methodMetadata, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) override;
  void executeRequest(apache::thrift::ServerRequest&& serverRequest, const apache::thrift::AsyncProcessorFactory::MethodMetadata& methodMetadata) override;
 public:
  using ProcessFuncs = GeneratedAsyncProcessor::ProcessFuncs<TestServiceAsyncProcessor>;
  using ProcessMap = GeneratedAsyncProcessor::ProcessMap<ProcessFuncs>;
  static const TestServiceAsyncProcessor::ProcessMap& getOwnProcessMap();
 private:
  static const TestServiceAsyncProcessor::ProcessMap kOwnProcessMap_;
 private:
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_init(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void executeRequest_init(apache::thrift::ServerRequest&& serverRequest);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::SerializedResponse return_init(apache::thrift::ContextStack* ctx, ::std::int64_t const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_init(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
 public:
  TestServiceAsyncProcessor(::apache::thrift::ServiceHandler<::test::namespace_from_package::module::TestService>* iface) :
      iface_(iface) {}
  ~TestServiceAsyncProcessor() override {}
};

}}} // test::namespace_from_package::module
