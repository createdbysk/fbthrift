
#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#



cdef shared_ptr[_fbthrift_ctypes.cempty_struct] empty_struct_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.empty_struct?>inst)._cpp_obj


cdef object empty_struct_from_cpp(const shared_ptr[_fbthrift_ctypes.cempty_struct]& c_struct):
    return _fbthrift_ctypes.empty_struct._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cdecorated_struct] decorated_struct_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.decorated_struct?>inst)._cpp_obj


cdef object decorated_struct_from_cpp(const shared_ptr[_fbthrift_ctypes.cdecorated_struct]& c_struct):
    return _fbthrift_ctypes.decorated_struct._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cContainerStruct] ContainerStruct_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.ContainerStruct?>inst)._cpp_obj


cdef object ContainerStruct_from_cpp(const shared_ptr[_fbthrift_ctypes.cContainerStruct]& c_struct):
    return _fbthrift_ctypes.ContainerStruct._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cCppTypeStruct] CppTypeStruct_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.CppTypeStruct?>inst)._cpp_obj


cdef object CppTypeStruct_from_cpp(const shared_ptr[_fbthrift_ctypes.cCppTypeStruct]& c_struct):
    return _fbthrift_ctypes.CppTypeStruct._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cVirtualStruct] VirtualStruct_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.VirtualStruct?>inst)._cpp_obj


cdef object VirtualStruct_from_cpp(const shared_ptr[_fbthrift_ctypes.cVirtualStruct]& c_struct):
    return _fbthrift_ctypes.VirtualStruct._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cMyStructWithForwardRefEnum] MyStructWithForwardRefEnum_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.MyStructWithForwardRefEnum?>inst)._cpp_obj


cdef object MyStructWithForwardRefEnum_from_cpp(const shared_ptr[_fbthrift_ctypes.cMyStructWithForwardRefEnum]& c_struct):
    return _fbthrift_ctypes.MyStructWithForwardRefEnum._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cTrivialNumeric] TrivialNumeric_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.TrivialNumeric?>inst)._cpp_obj


cdef object TrivialNumeric_from_cpp(const shared_ptr[_fbthrift_ctypes.cTrivialNumeric]& c_struct):
    return _fbthrift_ctypes.TrivialNumeric._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cTrivialNestedWithDefault] TrivialNestedWithDefault_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.TrivialNestedWithDefault?>inst)._cpp_obj


cdef object TrivialNestedWithDefault_from_cpp(const shared_ptr[_fbthrift_ctypes.cTrivialNestedWithDefault]& c_struct):
    return _fbthrift_ctypes.TrivialNestedWithDefault._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cComplexString] ComplexString_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.ComplexString?>inst)._cpp_obj


cdef object ComplexString_from_cpp(const shared_ptr[_fbthrift_ctypes.cComplexString]& c_struct):
    return _fbthrift_ctypes.ComplexString._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cComplexNestedWithDefault] ComplexNestedWithDefault_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.ComplexNestedWithDefault?>inst)._cpp_obj


cdef object ComplexNestedWithDefault_from_cpp(const shared_ptr[_fbthrift_ctypes.cComplexNestedWithDefault]& c_struct):
    return _fbthrift_ctypes.ComplexNestedWithDefault._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cMinPadding] MinPadding_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.MinPadding?>inst)._cpp_obj


cdef object MinPadding_from_cpp(const shared_ptr[_fbthrift_ctypes.cMinPadding]& c_struct):
    return _fbthrift_ctypes.MinPadding._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cMinPaddingWithCustomType] MinPaddingWithCustomType_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.MinPaddingWithCustomType?>inst)._cpp_obj


cdef object MinPaddingWithCustomType_from_cpp(const shared_ptr[_fbthrift_ctypes.cMinPaddingWithCustomType]& c_struct):
    return _fbthrift_ctypes.MinPaddingWithCustomType._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cMyStruct] MyStruct_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.MyStruct?>inst)._cpp_obj


cdef object MyStruct_from_cpp(const shared_ptr[_fbthrift_ctypes.cMyStruct]& c_struct):
    return _fbthrift_ctypes.MyStruct._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cMyDataItem] MyDataItem_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.MyDataItem?>inst)._cpp_obj


cdef object MyDataItem_from_cpp(const shared_ptr[_fbthrift_ctypes.cMyDataItem]& c_struct):
    return _fbthrift_ctypes.MyDataItem._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cRenaming] Renaming_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.Renaming?>inst)._cpp_obj


cdef object Renaming_from_cpp(const shared_ptr[_fbthrift_ctypes.cRenaming]& c_struct):
    return _fbthrift_ctypes.Renaming._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cAnnotatedTypes] AnnotatedTypes_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.AnnotatedTypes?>inst)._cpp_obj


cdef object AnnotatedTypes_from_cpp(const shared_ptr[_fbthrift_ctypes.cAnnotatedTypes]& c_struct):
    return _fbthrift_ctypes.AnnotatedTypes._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cForwardUsageRoot] ForwardUsageRoot_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.ForwardUsageRoot?>inst)._cpp_obj


cdef object ForwardUsageRoot_from_cpp(const shared_ptr[_fbthrift_ctypes.cForwardUsageRoot]& c_struct):
    return _fbthrift_ctypes.ForwardUsageRoot._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cForwardUsageStruct] ForwardUsageStruct_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.ForwardUsageStruct?>inst)._cpp_obj


cdef object ForwardUsageStruct_from_cpp(const shared_ptr[_fbthrift_ctypes.cForwardUsageStruct]& c_struct):
    return _fbthrift_ctypes.ForwardUsageStruct._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cForwardUsageByRef] ForwardUsageByRef_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.ForwardUsageByRef?>inst)._cpp_obj


cdef object ForwardUsageByRef_from_cpp(const shared_ptr[_fbthrift_ctypes.cForwardUsageByRef]& c_struct):
    return _fbthrift_ctypes.ForwardUsageByRef._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cIncompleteMap] IncompleteMap_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.IncompleteMap?>inst)._cpp_obj


cdef object IncompleteMap_from_cpp(const shared_ptr[_fbthrift_ctypes.cIncompleteMap]& c_struct):
    return _fbthrift_ctypes.IncompleteMap._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cIncompleteMapDep] IncompleteMapDep_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.IncompleteMapDep?>inst)._cpp_obj


cdef object IncompleteMapDep_from_cpp(const shared_ptr[_fbthrift_ctypes.cIncompleteMapDep]& c_struct):
    return _fbthrift_ctypes.IncompleteMapDep._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cCompleteMap] CompleteMap_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.CompleteMap?>inst)._cpp_obj


cdef object CompleteMap_from_cpp(const shared_ptr[_fbthrift_ctypes.cCompleteMap]& c_struct):
    return _fbthrift_ctypes.CompleteMap._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cCompleteMapDep] CompleteMapDep_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.CompleteMapDep?>inst)._cpp_obj


cdef object CompleteMapDep_from_cpp(const shared_ptr[_fbthrift_ctypes.cCompleteMapDep]& c_struct):
    return _fbthrift_ctypes.CompleteMapDep._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cIncompleteList] IncompleteList_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.IncompleteList?>inst)._cpp_obj


cdef object IncompleteList_from_cpp(const shared_ptr[_fbthrift_ctypes.cIncompleteList]& c_struct):
    return _fbthrift_ctypes.IncompleteList._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cIncompleteListDep] IncompleteListDep_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.IncompleteListDep?>inst)._cpp_obj


cdef object IncompleteListDep_from_cpp(const shared_ptr[_fbthrift_ctypes.cIncompleteListDep]& c_struct):
    return _fbthrift_ctypes.IncompleteListDep._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cCompleteList] CompleteList_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.CompleteList?>inst)._cpp_obj


cdef object CompleteList_from_cpp(const shared_ptr[_fbthrift_ctypes.cCompleteList]& c_struct):
    return _fbthrift_ctypes.CompleteList._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cCompleteListDep] CompleteListDep_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.CompleteListDep?>inst)._cpp_obj


cdef object CompleteListDep_from_cpp(const shared_ptr[_fbthrift_ctypes.cCompleteListDep]& c_struct):
    return _fbthrift_ctypes.CompleteListDep._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cAdaptedList] AdaptedList_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.AdaptedList?>inst)._cpp_obj


cdef object AdaptedList_from_cpp(const shared_ptr[_fbthrift_ctypes.cAdaptedList]& c_struct):
    return _fbthrift_ctypes.AdaptedList._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cDependentAdaptedList] DependentAdaptedList_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.DependentAdaptedList?>inst)._cpp_obj


cdef object DependentAdaptedList_from_cpp(const shared_ptr[_fbthrift_ctypes.cDependentAdaptedList]& c_struct):
    return _fbthrift_ctypes.DependentAdaptedList._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cAllocatorAware] AllocatorAware_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.AllocatorAware?>inst)._cpp_obj


cdef object AllocatorAware_from_cpp(const shared_ptr[_fbthrift_ctypes.cAllocatorAware]& c_struct):
    return _fbthrift_ctypes.AllocatorAware._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cAllocatorAware2] AllocatorAware2_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.AllocatorAware2?>inst)._cpp_obj


cdef object AllocatorAware2_from_cpp(const shared_ptr[_fbthrift_ctypes.cAllocatorAware2]& c_struct):
    return _fbthrift_ctypes.AllocatorAware2._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cTypedefStruct] TypedefStruct_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.TypedefStruct?>inst)._cpp_obj


cdef object TypedefStruct_from_cpp(const shared_ptr[_fbthrift_ctypes.cTypedefStruct]& c_struct):
    return _fbthrift_ctypes.TypedefStruct._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cStructWithDoubleUnderscores] StructWithDoubleUnderscores_convert_to_cpp(object inst):
    return (<_fbthrift_ctypes.StructWithDoubleUnderscores?>inst)._cpp_obj


cdef object StructWithDoubleUnderscores_from_cpp(const shared_ptr[_fbthrift_ctypes.cStructWithDoubleUnderscores]& c_struct):
    return _fbthrift_ctypes.StructWithDoubleUnderscores._fbthrift_create(c_struct)