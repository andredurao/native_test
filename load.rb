require "rubygems"
require "bundler/setup"
require "benchmark"
require "scanf"
Bundler.require(:default)

n = 500000

def duration_in_seconds_regex(duration)
  if duration =~ /^\d{2,}\:\d{2}:\d{2}$/
    h, m, s = duration.split(":").map{ |n| n.to_i }
    h * 3600 + m * 60 + s
  end
end

def duration_in_seconds_scanf(duration)
  a = duration.scanf("%d:%d:%d")
  a[0] * 3600 + a[1] * 60 + a[2]
end

puts "="*80
puts "NATIVE"
Benchmark.bm do |x|
  x.report { for i in 1..n; "00:10:30".to_seconds; end }
end

puts "="*80
puts "SCANF"
Benchmark.bm do |x|
  x.report { for i in 1..n; duration_in_seconds_scanf("00:10:30"); end }
end

puts "="*80
puts "REGEX"
Benchmark.bm do |x|
  x.report { for i in 1..n; duration_in_seconds_regex("00:10:30"); end }
end