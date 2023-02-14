//  String class test program
//
//  Tests: find char 
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
        String  str("012345");

        // VERIFY
        assert(str.findch(0, '0') == 0);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("012345");

        // VERIFY
        assert(str.findch(1, '0') == -1);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("012345");

        // VERIFY
        assert(str.findch(0, '6') == -1);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("012345");

        // VERIFY
        assert(str.findch(5, '5') == 5);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("012345");

        // VERIFY
        assert(str.findch(6, '5') == -1);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("012345");

        // VERIFY
        assert(str.findch(3, '4') == 4);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("012345");

        // VERIFY
        assert(str.findch(-3, '4') == 4);
    }
    std::cout << "Done testing find char." << std::endl;
    return 0;
}

