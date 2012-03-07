# -*- ruby -*-

require 'rubygems'
require 'rake/extensiontask'

spec = Gem::Specification.new do |s|
  s.name = 'native_test'
  s.platform = Gem::Platform::RUBY
  s.extensions = FileList["ext/**/extconf.rb"]
end

Rake::ExtensionTask.new('native_test', spec)

Rake::Task[:test].prerequisites << :compile

