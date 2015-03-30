#include <ruby.h>
#include <stdio.h>
#include <stdlib.h>

// Create C pallendrome
char* pallendrome(char* input) {
	printf("C pallendrome called.\n");;
        int length = 0;
        for (int i = 0; input[i] != '\0'; i++)
                length++;

        int pallendrome_length = length * 2 - 1;

        char* result = malloc(pallendrome_length * sizeof(char));
        char* work = result;
        for (int i = 0; i < pallendrome_length; i++) {
                *work = *input;
                work++;
                if (i < length-1) {
                        input++;
                } else {
                        input--;
                }
        }
        return result;
}

// Handle ruby types
static VALUE ruby_pallendrome(VALUE rb_self, VALUE rb_input) {
	printf("ruby_pallendrome called.\n");
	VALUE result = Qnil;
	Check_Type(rb_input, T_STRING);
	
	char * c_string = RSTRING_PTR(rb_input);
	char * c_pallendrome = pallendrome(c_string);
	result = rb_str_new2(c_pallendrome);
	// Not sure if this is required, not mentioned on https://github.com/ruby/ruby/blob/trunk/doc/extension.rdoc
	free(c_pallendrome);
	
	return result;
}

// Executed by ruby require:
void Init_pallendrome() {
	printf("Init_pallendrome called.\n");
	rb_define_method(rb_cObject, "pallendrome", ruby_pallendrome, 1);
}

int main(int argc, char *argv[]) {
	for (int i = 1; i < argc; i++) {
		printf("%s\n",pallendrome(argv[i]));
	}
}

