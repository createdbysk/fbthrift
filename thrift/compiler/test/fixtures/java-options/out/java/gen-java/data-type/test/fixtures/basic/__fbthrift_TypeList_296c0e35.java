/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.basic;

import com.facebook.thrift.type.TypeList;
import java.util.ArrayList;
import java.util.List;

public class __fbthrift_TypeList_296c0e35 implements TypeList {

  private static List<TypeMapping> list = new ArrayList<>();

  private static void add(String uri, String className) {
    list.add(new TypeList.TypeMapping(uri, className));
  }

  private static void addToList0() {
    add("test.dev/fixtures/basic/MyStruct", "test.fixtures.basic.MyStruct");
    add("test.dev/fixtures/basic/MyDataItem", "test.fixtures.basic.MyDataItem");
    add("test.dev/fixtures/basic/MyUnion", "test.fixtures.basic.MyUnion");
    add("test.dev/fixtures/basic/MyEnum", "test.fixtures.basic.MyEnum");
  }

  static {
    addToList0();
  }

  @java.lang.Override
  public List<TypeList.TypeMapping> getTypes() {
    return list;
  }
}