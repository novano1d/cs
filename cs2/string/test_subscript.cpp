//  String class test program
//
//  Tests: subscript 
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
        String str("012345");

        // VERIFY
        assert(str[3] == '3');
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("012345");

        // VERIFY
        assert(str[0] == '0');
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("012345");

        // VERIFY
        assert(str[5] == '5');
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("012345");
        str[0] = 'X';

        // VERIFY
        assert(str[0] == 'X');
        assert(str == "X12345");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("012345");
        str[5] = 'X';

        // VERIFY
        assert(str[5] == 'X');
        assert(str == "01234X");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("abcd");
        str[1] = 'X';

        // VERIFY
        assert(str[1] == 'X');
        assert(str == "aXcd");
    }
    std::cout << "Done testing subscript." << std::endl;
    return 0;
}

