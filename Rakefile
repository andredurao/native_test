# -*- ruby -*-

require 'rubygems'
require 'hoe'
require 'rake/extensiontask'

# Hoe.plugin :compiler
# Hoe.plugin :gem_prelude_sucks
# Hoe.plugin :inline
# Hoe.plugin :racc
# Hoe.plugin :rubyforge

Hoe.spec 'native_test' do
  developer('Andre Durao', 'andreluisdurao@gmail.com')
  self.readme_file = 'README.rdoc'

  # self.rubyforge_name = 'native_testx' # if different than 'native_test'
  
  self.history_file  = 'CHANGELOG.rdoc'
  self.extra_rdoc_files  = FileList['*.rdoc']
  self.extra_dev_deps << ['rake-compiler', '>= 0']
  self.spec_extras = { :extensions => ["ext/native_test/extconf.rb"] }

  Rake::ExtensionTask.new('native_test', spec) do |ext|
    ext.lib_dir = File.join('lib', 'native_test')
  end
  
end

Rake::Task[:test].prerequisites << :compile

# vim: syntax=ruby
