#include <ruby.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static VALUE hello_world(VALUE mod){
  return rb_str_new2("hello world");
}
//checkthis: http://rune.hammersland.net/kode/ruby.h.html
static VALUE test_scanf(VALUE mod){
	int ret_val;
	int match_qty = sscanf("123", "%d", &ret_val);
  return rb_int_new(ret_val);	
}

static VALUE my_string_test(VALUE klass){
	return rb_str_new2("test");
}

/*
MANDATORY: http://www.ruby-doc.org/docs/ProgrammingRuby/html/ext_ruby.html
*/
static VALUE my_string_scanf(int argc, VALUE *argv, VALUE self){
	char val[20];
	sprintf(val, "scanf = %d", argc);
	return rb_str_new2(val);
	VALUE scanf_fmt, rest;
	rb_scan_args(argc, argv, "1*", &scanf_fmt, &rest);	
	Check_Type(scanf_fmt, T_STRING);
}

void Init_native_test(){
  VALUE mNative_test = rb_define_module("NativeTest");
  rb_define_singleton_method(mNative_test, "hello_world", hello_world, 0);
  rb_define_singleton_method(mNative_test, "test_scanf", test_scanf, 0);
  VALUE rb_cString = rb_define_class("String", rb_cObject);
  rb_define_method(rb_cString, "my_string_test", my_string_test, 0);
  rb_define_method(rb_cString, "scanf", my_string_scanf, -1);
}

