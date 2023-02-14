// bigint Test Program
//
// Tests:  times_10, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(1);
 
        // Verify
        assert(bi == 3);  
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(0);
 
        // Verify
        assert(bi == 0);  
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(1111);

        // Test 
        bi = bi.timesDigit(5);
 
        // Verify
        assert(bi == 5555);  
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(9999);

        // Test 
        bi = bi.timesDigit(9);
 
        // Verify
        assert(bi == 89991);  
    }


    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("923852341734");

        // Test 
        bi = bi.timesDigit(5);
 
        // Verify
        assert(bi == bigint("4619261708670"));  
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(0);

        // Test 
        bi = bi.timesDigit(5);
 
        // Verify
        assert(bi == 0);  
    }

    //Add test cases as needed.
    
    std::cout << "Done testing bigint * digit" << std::endl;
    return 0;
}

