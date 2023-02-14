//  String class test program
//
//  Tests: Copy Constructor 
//

#include "string.hpp"
#include <cassert>
#include <iostream>

String global("Global");

void testcpy(String s)
{
    assert(s == global);
}

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("Hello");
        String copy(str);

        // VERIFY
        assert(copy == str);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        testcpy(global);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("Hello");
        String copy(str);

        str = "Not hello";

        // VERIFY
        assert(str == "Not hello");
        assert(copy == "Hello");
    }
    
    std::cout << "Done testing copy constructor." << std::endl;
    return 0;
}

