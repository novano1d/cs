//  String class test program
//
//  Tests: swap assign 
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
        String s2 = str;

        // VERIFY
        assert(str == "Hello World");
        assert(s2 == "Hello World");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("Hello World");
        String s2 = str;
        str[0] = 'B'; //make sure not the same pointer

        // VERIFY
        assert(str == "Bello World");
        assert(s2 == "Hello World");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("Hello World");
        String s2("Goodbye World");
        str.swap(s2);
        s2[0] = 'B'; //make sure not the same pointer

        // VERIFY
        assert(s2 == "Bello World");
        assert(str == "Goodbye World");
    }
    
    std::cout << "Done testing swap assign." << std::endl;
    return 0;
}

