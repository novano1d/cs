//  String class test program
//
//  Tests: less than 
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
        String str1('a');
        String str2('b');

        // VERIFY
        assert(str1 < str2);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str2('b');

        // VERIFY
        assert('a' < str2);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str1('a');

        // VERIFY
        assert(str1 < 'b');
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str1("ab");
        String str2("bc");

        // VERIFY
        assert(str1 < str2);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str2("bc");

        // VERIFY
        assert("ab" < str2);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str1("ab");

        // VERIFY
        assert(str1 < "bc");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str1("abc");
        String str2("acc");

        // VERIFY
        assert(str1 < str2);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str1("a");
        String str2("aa");

        // VERIFY
        assert(str1 < str2);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str1("apple");
        String str2("banana");

        // VERIFY
        assert(str1 < str2);
    }
    std::cout << "Done testing less than." << std::endl;
    return 0;
}

