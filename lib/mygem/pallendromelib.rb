require 'mygem/pallendrome'

def first_ruby_call
	puts "Calling ruby pallendrome with 'hello'"
	result = pallendrome "hello"
	puts "Ruby result: "+result.to_s	
end

