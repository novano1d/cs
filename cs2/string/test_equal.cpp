//  String class test program
//
//  Tests: equal 
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
        String  str1("123");
        String  str2("123");

        // VERIFY
        assert(str1 == str2);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1("testing");
        String  str2("test");

        // VERIFY
        assert(!(str1 == str2));
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1("123");

        // VERIFY
        assert(str1 == "123");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str2("123");

        // VERIFY
        assert("123" == str2);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1('x');

        // VERIFY
        assert(str1 == 'x');
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1('x');

        // VERIFY
        assert('x' == str1);
    }

    std::cout << "Done testing equal." << std::endl;
    return 0;
}

