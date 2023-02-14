// bigint Test Program
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 4);  
        assert(digit == 4);
    }
    
    {
        // Setup
        bigint bi(120);

        // Test 
        int digit = bi[1];

        // Verify
        assert(bi    == 120);  
        assert(digit == 2);
    }

    {
        // Setup
        bigint bi(909819123);

        // Test 
        int digit = bi[5];

        // Verify
        assert(bi    == 909819123);  
        assert(digit == 8);
    }

    {
        // Setup
        bigint bi(8999999);

        // Test 
        int digit = bi[6];

        // Verify
        assert(bi    == 8999999);  
        assert(digit == 8);
    }
    {
        // Setup
        bigint bi(8999991);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 8999991);  
        assert(digit == 1);
    }
    {
        // Setup
        bigint bi("4");

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 4);  
        assert(digit == 4);
    }
    
    {
        // Setup
        bigint bi("120");

        // Test 
        int digit = bi[1];

        // Verify
        assert(bi    == 120);  
        assert(digit == 2);
    }

    {
        // Setup
        bigint bi("909819123");

        // Test 
        int digit = bi[5];

        // Verify
        assert(bi    == 909819123);  
        assert(digit == 8);
    }

    {
        // Setup
        bigint bi("8999999");

        // Test 
        int digit = bi[6];

        // Verify
        assert(bi    == 8999999);  
        assert(digit == 8);
    }
    {
        // Setup
        bigint bi("8999991");

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 8999991);  
        assert(digit == 1);
    }

    std::cout << "Done testing subscript." << std::endl;
    return 0;
}

