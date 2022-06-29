/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/service_h.h>

#include "thrift/compiler/test/fixtures/mcpp2-compare/gen-cpp2/EmptyServiceAsyncClient.h"
#include "thrift/compiler/test/fixtures/mcpp2-compare/gen-cpp2/module_types.h"
#include "thrift/compiler/test/fixtures/mcpp2-compare/gen-cpp2/includes_types.h"
#include <folly/small_vector.h>

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

namespace some { namespace valid { namespace ns {
class EmptyService;
class EmptyServiceAsyncProcessor;

class EmptyServiceServiceInfoHolder : public apache::thrift::ServiceInfoHolder {
  public:
   apache::thrift::ServiceRequestInfoMap const& requestInfoMap() const override;
   static apache::thrift::ServiceRequestInfoMap staticRequestInfoMap();
};
}}} // some::valid::ns

namespace apache::thrift {
template <>
class ServiceHandler<::some::valid::ns::EmptyService> : public apache::thrift::ServerInterface {
 public:
  std::string_view getGeneratedName() const override { return "EmptyService"; }

  typedef ::some::valid::ns::EmptyServiceAsyncProcessor ProcessorType;
  std::unique_ptr<apache::thrift::AsyncProcessor> getProcessor() override;
  CreateMethodMetadataResult createMethodMetadata() override;
 private:
  std::optional<std::reference_wrapper<apache::thrift::ServiceRequestInfoMap const>> getServiceRequestInfoMap() const;
 public:

 private:
  static ::some::valid::ns::EmptyServiceServiceInfoHolder __fbthrift_serviceInfoHolder;
};

} // namespace apache::thrift

namespace some { namespace valid { namespace ns {
using EmptyServiceSvIf [[deprecated("Use apache::thrift::ServiceHandler<EmptyService> instead")]] = ::apache::thrift::ServiceHandler<EmptyService>;
}}} // some::valid::ns
namespace some { namespace valid { namespace ns {
class EmptyServiceSvNull : public EmptyServiceSvIf {
 public:
};

class EmptyServiceAsyncProcessor : public ::apache::thrift::GeneratedAsyncProcessor {
 public:
  const char* getServiceName() override;
  void getServiceMetadata(apache::thrift::metadata::ThriftServiceMetadataResponse& response) override;
  using BaseAsyncProcessor = void;
 protected:
  ::apache::thrift::ServiceHandler<::some::valid::ns::EmptyService>* iface_;
 public:
  // This is implemented in case the corresponding AsyncProcessorFactory did not implement createMethodMetadata.
  // This can happen if the service is using a custom AsyncProcessorFactory but re-using the same AsyncProcessor.
  void processSerializedCompressedRequest(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) override;
  // By default, this overload will be called for generated services
  void processSerializedCompressedRequestWithMetadata(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, const apache::thrift::AsyncProcessorFactory::MethodMetadata& methodMetadata, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) override;
  void executeRequest(apache::thrift::ServerRequest&& serverRequest, const apache::thrift::AsyncProcessorFactory::MethodMetadata& methodMetadata) override;
 public:
  using ProcessFuncs = GeneratedAsyncProcessor::ProcessFuncs<EmptyServiceAsyncProcessor>;
  using ProcessMap = GeneratedAsyncProcessor::ProcessMap<ProcessFuncs>;
  static const EmptyServiceAsyncProcessor::ProcessMap& getOwnProcessMap();
 private:
  static const EmptyServiceAsyncProcessor::ProcessMap kOwnProcessMap_;
 private:
 public:
  EmptyServiceAsyncProcessor(::apache::thrift::ServiceHandler<::some::valid::ns::EmptyService>* iface) :
      iface_(iface) {}
  ~EmptyServiceAsyncProcessor() override {}
};

}}} // some::valid::ns
