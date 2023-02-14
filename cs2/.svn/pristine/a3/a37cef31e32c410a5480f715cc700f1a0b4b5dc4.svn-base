// bigint Test Program
//
// Tests:  int constructor, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream> 
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {

        // VERY INCOMPLETE set of tests.


        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(0);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 0);
      assert(right  == 1);
      assert(result == 1);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1234);
      bigint right(1111);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1234);
      assert(right  == 1111);
      assert(result == 2345);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(999);
      bigint right(999);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 999);
      assert(right  == 999);
      assert(result == 1998);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(123456);
      bigint right(111);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 123456);
      assert(right  == 111);
      assert(result == 123567);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(999999);
      bigint right(222);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 999999);
      assert(right  == 222);
      assert(result == 1000221);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("0");
      bigint right("0");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 0);
      assert(right  == 0);
      assert(result == 0);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("1");
      bigint right("0");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("0");
      bigint right("1");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 0);
      assert(right  == 1);
      assert(result == 1);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("9999999999999999999999999");
      bigint right("349857298409123");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == "9999999999999999999999999");
      assert(right  == "349857298409123");
      assert(result == "10000000000349857298409122");
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("9999999999999999999999999");
      bigint right("0000000349857298409123");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == "9999999999999999999999999");
      assert(right  == "0000000349857298409123");
      assert(result == "10000000000349857298409122");
    }

    //assert(1 == 2); WRONG. This will fail, of course.
                    //You need to add more test cases here. Remove this assert.

    
    //Add test cases as needed.
    
    
    std::cout << "Done with testing addition." << std::endl;
    return 0;
}

