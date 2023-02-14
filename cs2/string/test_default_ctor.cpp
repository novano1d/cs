//  String class test program
//
//  Tests: default constructor 
//

#include "string.hpp"
#include <assert.h>
#include <iostream>
 
//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str;

        // VERIFY
        assert(str.length() == 0);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str[2];

        // VERIFY
        assert(str[0].length() == 0);
        assert(str[1].length() == 0);
    }
    
    std::cout << "Done testing default constructor." << std::endl;
    return 0;
}

