//  String class test program
//
//  Tests: char constructor 
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
        String  str('x');

        // VERIFY
        assert(str == 'x');
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('\0');
        String nothing;

        // VERIFY
        assert(str == nothing);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        char s = '!';
        String  str(s);

        // VERIFY
        assert(str == '!');
    }
    
    
    std::cout << "Done testing char constructor." << std::endl;
    return 0;
}

