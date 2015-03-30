Gem::Specification.new do |spec|
	spec.name = 'mygem'
	spec.version = '0.1'
	spec.summary = 'Summary'
	spec.description = 'Description'
	spec.email = 'myemail@provieder.com'
	spec.homepage = 'http://myapp.com'
	spec.author = 'me'
	spec.bindir = 'bin'
	spec.executable = 'exec.rb'
	spec.files = Dir['lib/**/*.rb'] + Dir['bin/*'] + Dir['ext/**/*.c'] + Dir['ext/**/*.so'] + Dir['ext/**/*.dll'] + Dir['ext/**/*.o']
	spec.platform = Gem::Platform::RUBY
	spec.require_paths = [ 'lib', 'ext' ]
	spec.extensions = Dir['ext/**/extconf.rb']
end

