require "test/unit"
require "native_test"

class TestNativeTest < Test::Unit::TestCase
  def test_hello_world
    assert_equal 'hello world', NativeTest.hello_world
  end
end
