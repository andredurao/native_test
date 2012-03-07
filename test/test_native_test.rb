require "test/unit"
require "native_test"

class TestNativeTest < Test::Unit::TestCase
  def test_hello_world
    assert_equal 'hello world', NativeTest.hello_world
    assert_equal 123, NativeTest.test_scanf
  end
end
