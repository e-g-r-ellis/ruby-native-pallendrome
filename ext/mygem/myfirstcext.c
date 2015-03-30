#include <ruby.h>
#include <stdio.h>

static VALUE object_first_cext_call(VALUE rb_self) {
	printf("First C extension call\n");
	return Qnil;
}

void Init_myfirstcext() {
	// Define method Object#first_cext_call
	rb_define_method(rb_cObject, "first_cext_call", object_first_cext_call, 0);
}

