//  Stack class test program
//
//  Tests: stack constructor
//

#include "stack.hpp"
#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<int> x;

        // VERIFY
        assert(x.empty());
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<char> x;

        // VERIFY
        assert(x.empty());
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String> x[2];

        // VERIFY
        assert(x[0].empty());
        assert(x[1].empty());
    }
    
    std::cout << "Done testing stack default constructor." << std::endl;
    return 0;
}

