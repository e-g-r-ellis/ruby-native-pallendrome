#include <ruby.h>
#include <stdio.h>

static VALUE object_second_cext_call(VALUE rb_self) {
	printf("Second C extension call\n");
	return Qnil;
}

void Init_mysecondcext() {
	// Define method Object#second_cext_call, corresponding to our C function object_second_cest_call; it has 0 arguement.
	rb_define_method(rb_cObject, "second_cest_call", object_second_cext_call, 0);
}
