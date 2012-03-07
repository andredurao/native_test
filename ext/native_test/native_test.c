#include <ruby.h>
#include <stdio.h>
#include <stdlib.h>

static VALUE hello_world(VALUE mod){
  return rb_str_new2("hello world");
}
//checkthis: http://rune.hammersland.net/kode/ruby.h.html
static VALUE test_scanf(VALUE mod){
	int ret_val;
	int match_qty = sscanf("123", "%d", &ret_val);
  return rb_int_new(ret_val);	
}

void Init_native_test(){
  VALUE mNative_test = rb_define_module("NativeTest");
  rb_define_singleton_method(mNative_test, "hello_world", hello_world, 0);
  rb_define_singleton_method(mNative_test, "test_scanf", test_scanf, 0);
}