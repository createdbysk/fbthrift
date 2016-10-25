namespace java.swift test.fixtures.shapes
namespace hack test.fixtures

enum Enum {
  ENUM = 1;
}

struct A {
  1: string a;
}

struct B {
  1: A just_an_A;
  2: set<i32> set_of_i32;
  3: list<i32> list_of_i32;
  4: list<string> list_of_string;
  5: map<string, i32> map_of_string_to_i32;
  6: map<string, A> map_of_string_to_A;
  7: map<string, list<i32>> map_of_string_to_list_of_i32;
  8: map<string, list<A>> map_of_string_to_list_of_A;
  9: map<string, set<i32>> map_of_string_to_set_of_i32;
  10: map<string, map<string, i32>> map_of_string_to_map_of_string_to_i32;
  11: map<string, map<string, A>> map_of_string_to_map_of_string_to_A;
  12: list<set<i32>> list_of_set_of_i32;
  13: list<map<string, list<A>>> list_of_map_of_string_to_list_of_A;
  14: list<map<string, A>> list_of_map_of_string_to_A;
  15: list<B> list_of_self;
  16: map<string, B> map_of_string_to_self;
  17: Enum just_an_enum;

  51: optional A optional_just_an_A;
  52: optional set<i32>  optional_set_of_i32;
  53: optional list<i32>  optional_list_of_i32;
  54: optional list<string>  optional_list_of_string;
  55: optional map<string, i32>  optional_map_of_string_to_i32;
  56: optional map<string, A>  optional_map_of_string_to_A;
  57: optional map<string, list<i32>>  optional_map_of_string_to_list_of_i32;
  58: optional map<string, list<A>>  optional_map_of_string_to_list_of_A;
  59: optional map<string, set<i32>>  optional_map_of_string_to_set_of_i32;
  60: optional Enum optional_enum;
}
