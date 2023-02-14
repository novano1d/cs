//  String class test program
//
//  Tests: substring 
//

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
        String str("Hello World");

        // VERIFY
        assert(str.substr(0, 10) == "Hello World");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("Hello World");

        // VERIFY
        assert(str.substr(-1, 10) == "Hello World");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("Hello World");

        // VERIFY
        assert(str.substr(0, 12) == "Hello World");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("Hello World");

        // VERIFY
        assert(str.substr(0, 4) == "Hello");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("Hello World");

        // VERIFY
        assert(str.substr(6, 10) == "World");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("Hello World");

        // VERIFY
        assert(str.substr(6, 11) == "World");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("Hello World");
        String nothing;
        // VERIFY
        assert(str.substr(16, 10) == nothing);
    }
        {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("Hello World");

        // VERIFY
        assert(str.substr(2, 4) == "llo");
    }
    std::cout << "Done testing substring." << std::endl;
    return 0;
}

