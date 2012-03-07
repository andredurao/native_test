#include <ruby.h>

static VALUE hello_world(VALUE mod)
{
  return rb_str_new2("hello world");
}

void Init_native_test(){
  VALUE mNative_test = rb_define_module("NativeTest");
  rb_define_singleton_method(mNative_test, "hello_world", hello_world, 0);
}