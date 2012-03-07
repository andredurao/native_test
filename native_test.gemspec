# -*- encoding: utf-8 -*-
$:.push File.expand_path("../lib", __FILE__)
require "native_test"

Gem::Specification.new do |s|
  s.name        = "native_test"
  s.version     = NativeTest::VERSION
  s.authors     = ["Andre Durao"]
  s.email       = ["andreluisdurao@gmail.com"]
  s.homepage    = ""
  s.summary     = %q{TODO: Simple Gem to test native extensions}
  s.description = %q{TODO: Simple Gem to test native extensions}

  s.files         = `git ls-files`.split("\n")
  s.test_files    = `git ls-files -- {test,spec,features}/*`.split("\n")
  s.executables   = `git ls-files -- bin/*`.split("\n").map{ |f| File.basename(f) }
  s.require_paths = ["lib"]

  s.platform    = Gem::Platform::RUBY
  s.add_dependency "rake", "0.8.7"
  s.add_dependency "rake-compiler", "0.8.0"
end
