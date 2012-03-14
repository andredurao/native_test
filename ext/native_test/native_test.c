#include <ruby.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>

/********************************************************************
 Name: 
 chrcount(). 

 Description: 
 The chrcount() function counts the number of times a character 
 value appears in a string and returns the count to the caller 
 
 Arguments: 
 const char *string - The string to search. 
 int chr - The character value to search for. 

 Return Value: 
 The number of times the character value appeared in the string
*********************************************************************/

size_t
chrcount(char *s1, int ch) {
    size_t count = 0; /* The count to return */
    if (s1 == NULL)
        errno = EINVAL;
    else while (*s1)
            if (*s1++ == ch)
                count++;
    return count; /* Return the count */
}


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
scanf escape code matches (simplified):
d     Matches an optionally signed decimal integer; the next pointer must be a pointer to int.
i     Matches an optionally signed integer; the next pointer must be a pointer to int.  
o     Matches an octal integer; the next pointer must be a pointer to unsigned int.
u     Matches an optionally signed decimal integer; the next pointer must be a pointer to unsigned int.
x, X  Matches an optionally signed hexadecimal integer; the next pointer must be a pointer to unsigned int.
a, A, e, E, f, F, g, G
      Matches a floating-point number in the style of strtod(3).  
			The next pointer must be a pointer to float (unless l or L is specified.)
s     Matches a sequence of non-white-space characters; the next pointer must be a pointer to char
S     The same as ls.
c     Matches a sequence of width count characters (default 1); the next pointer must be a pointer to char
C     The same as lc.
[     Matches a nonempty sequence of characters from the specified set of accepted characters; 
      the next pointer must be a pointer to char
*/

int* match_params(char* scanf_fmt){
	
}

static VALUE my_string_scanf(VALUE self, VALUE scanf_fmt){
	int i = 0;
	int output_ary_size = 0;
	
	char* scanf_str;
	Check_Type(scanf_fmt, T_STRING);
	scanf_str = StringValuePtr(scanf_fmt);
	output_ary_size = chrcount(scanf_str, '%');
	VALUE output_ary = rb_ary_new();
	for(i = 0;i < output_ary_size; i++)
		rb_ary_push(output_ary, INT2FIX(output_ary_size));
	return output_ary;
}


static VALUE string_time_in_seconds(VALUE self){
	int h, m, s;
	char* scanf_str;
	Check_Type(self, T_STRING);
	scanf_str = StringValuePtr(self);
  if (sscanf(scanf_str, "%d:%d:%d", &h, &m, &s) == 3) {
      s = h * 3600L + m * 60L + s;
  }
	return(INT2FIX(s));
}

void Init_native_test(){
  VALUE mNative_test = rb_define_module("NativeTest");
  rb_define_singleton_method(mNative_test, "hello_world", hello_world, 0);
  rb_define_singleton_method(mNative_test, "test_scanf", test_scanf, 0);
  VALUE rb_cString = rb_define_class("String", rb_cObject);
  rb_define_method(rb_cString, "my_string_test", my_string_test, 0);
  rb_define_method(rb_cString, "scanf", my_string_scanf, 1);
  rb_define_method(rb_cString, "to_seconds", string_time_in_seconds, 0);
}
