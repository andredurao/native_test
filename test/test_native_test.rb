require "test/unit"
require "native_test"

class TestNativeTest < Test::Unit::TestCase
  def test_hello_world
    assert_equal 'hello world', NativeTest.hello_world
  end
  
  def test_scanf
    assert_equal 123, NativeTest.test_scanf    
  end
  
  def test_string_my_string_test
    str = "str"
    assert_equal 'test', str.my_string_test
  end
  
end
