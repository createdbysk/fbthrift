
/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT
 *  @generated
 *
 */

#include <folly/python/import.h>
#include <thrift/lib/python/capi/iobuf.h>
#include <thrift/lib/python/types.h>

#include <thrift/compiler/test/fixtures/stream/src/gen-python-capi/module/thrift_types_api.h>
#include <thrift/compiler/test/fixtures/stream/src/gen-python-capi/module/thrift_types_capi.h>


namespace apache {
namespace thrift {
namespace python {
namespace capi {
namespace {
bool ensure_module_imported() {
  static ::folly::python::import_cache_nocapture import((
      ::import_module__thrift_types_capi));
  return import();
}
} // namespace

ExtractorResult<::cpp2::FooStreamEx>
Extractor<::cpp2::FooStreamEx>::operator()(PyObject* obj) {
  int tCheckResult = typeCheck(obj);
  if (tCheckResult != 1) {
      if (tCheckResult == 0) {
        PyErr_SetString(PyExc_TypeError, "Not a FooStreamEx");
      }
      return extractorError<::cpp2::FooStreamEx>(
          "Marshal error: FooStreamEx");
  }
  return ::cpp2::FooStreamEx{};
}

ExtractorResult<::cpp2::FooStreamEx>
Extractor<::apache::thrift::python::capi::ComposedStruct<
    ::cpp2::FooStreamEx>>::operator()(PyObject* fbThriftData) {
  ::cpp2::FooStreamEx cpp;
  (void)fbThriftData;
  return cpp;
}


int Extractor<::cpp2::FooStreamEx>::typeCheck(PyObject* obj) {
  if (!ensure_module_imported()) {
    ::folly::python::handlePythonError(
      "Module module import error");
  }
  int result =
      can_extract__module__FooStreamEx(obj);
  if (result < 0) {
    ::folly::python::handlePythonError(
      "Unexpected type check error: FooStreamEx");
  }
  return result;
}


PyObject* Constructor<::cpp2::FooStreamEx>::operator()(
    const ::cpp2::FooStreamEx& val) {
  if (!ensure_module_imported()) {
    DCHECK(PyErr_Occurred() != nullptr);
    return nullptr;
  }
  Constructor<::apache::thrift::python::capi::ComposedStruct<
        ::cpp2::FooStreamEx>> ctor;
  StrongRef fbthrift_data(ctor(val));
  if (!fbthrift_data) {
    return nullptr;
  }
  return init__module__FooStreamEx(*fbthrift_data);
}

PyObject* Constructor<::apache::thrift::python::capi::ComposedStruct<
        ::cpp2::FooStreamEx>>::operator()(
    [[maybe_unused]] const ::cpp2::FooStreamEx& val) {
  StrongRef fbthrift_data(createStructTuple(0));
  return std::move(fbthrift_data).release();
}


ExtractorResult<::cpp2::FooEx>
Extractor<::cpp2::FooEx>::operator()(PyObject* obj) {
  int tCheckResult = typeCheck(obj);
  if (tCheckResult != 1) {
      if (tCheckResult == 0) {
        PyErr_SetString(PyExc_TypeError, "Not a FooEx");
      }
      return extractorError<::cpp2::FooEx>(
          "Marshal error: FooEx");
  }
  return ::cpp2::FooEx{};
}

ExtractorResult<::cpp2::FooEx>
Extractor<::apache::thrift::python::capi::ComposedStruct<
    ::cpp2::FooEx>>::operator()(PyObject* fbThriftData) {
  ::cpp2::FooEx cpp;
  (void)fbThriftData;
  return cpp;
}


int Extractor<::cpp2::FooEx>::typeCheck(PyObject* obj) {
  if (!ensure_module_imported()) {
    ::folly::python::handlePythonError(
      "Module module import error");
  }
  int result =
      can_extract__module__FooEx(obj);
  if (result < 0) {
    ::folly::python::handlePythonError(
      "Unexpected type check error: FooEx");
  }
  return result;
}


PyObject* Constructor<::cpp2::FooEx>::operator()(
    const ::cpp2::FooEx& val) {
  if (!ensure_module_imported()) {
    DCHECK(PyErr_Occurred() != nullptr);
    return nullptr;
  }
  Constructor<::apache::thrift::python::capi::ComposedStruct<
        ::cpp2::FooEx>> ctor;
  StrongRef fbthrift_data(ctor(val));
  if (!fbthrift_data) {
    return nullptr;
  }
  return init__module__FooEx(*fbthrift_data);
}

PyObject* Constructor<::apache::thrift::python::capi::ComposedStruct<
        ::cpp2::FooEx>>::operator()(
    [[maybe_unused]] const ::cpp2::FooEx& val) {
  StrongRef fbthrift_data(createStructTuple(0));
  return std::move(fbthrift_data).release();
}


ExtractorResult<::cpp2::FooEx2>
Extractor<::cpp2::FooEx2>::operator()(PyObject* obj) {
  int tCheckResult = typeCheck(obj);
  if (tCheckResult != 1) {
      if (tCheckResult == 0) {
        PyErr_SetString(PyExc_TypeError, "Not a FooEx2");
      }
      return extractorError<::cpp2::FooEx2>(
          "Marshal error: FooEx2");
  }
  return ::cpp2::FooEx2{};
}

ExtractorResult<::cpp2::FooEx2>
Extractor<::apache::thrift::python::capi::ComposedStruct<
    ::cpp2::FooEx2>>::operator()(PyObject* fbThriftData) {
  ::cpp2::FooEx2 cpp;
  (void)fbThriftData;
  return cpp;
}


int Extractor<::cpp2::FooEx2>::typeCheck(PyObject* obj) {
  if (!ensure_module_imported()) {
    ::folly::python::handlePythonError(
      "Module module import error");
  }
  int result =
      can_extract__module__FooEx2(obj);
  if (result < 0) {
    ::folly::python::handlePythonError(
      "Unexpected type check error: FooEx2");
  }
  return result;
}


PyObject* Constructor<::cpp2::FooEx2>::operator()(
    const ::cpp2::FooEx2& val) {
  if (!ensure_module_imported()) {
    DCHECK(PyErr_Occurred() != nullptr);
    return nullptr;
  }
  Constructor<::apache::thrift::python::capi::ComposedStruct<
        ::cpp2::FooEx2>> ctor;
  StrongRef fbthrift_data(ctor(val));
  if (!fbthrift_data) {
    return nullptr;
  }
  return init__module__FooEx2(*fbthrift_data);
}

PyObject* Constructor<::apache::thrift::python::capi::ComposedStruct<
        ::cpp2::FooEx2>>::operator()(
    [[maybe_unused]] const ::cpp2::FooEx2& val) {
  StrongRef fbthrift_data(createStructTuple(0));
  return std::move(fbthrift_data).release();
}


} // namespace capi
} // namespace python
} // namespace thrift
} // namespace apache
