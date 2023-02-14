//  String class test program
//
//  Tests: find string 
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
        String str("012 45 789");

        // VERIFY
        assert(str.findstr(0, "0") == 0);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("012 45 789");

        // VERIFY
        assert(str.findstr(0, "012") == 0);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("012 45 789");

        // VERIFY
        assert(str.findstr(1, "012") == -1);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("012 45 789");

        // VERIFY
        assert(str.findstr(0, "") == -1);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("");

        // VERIFY
        assert(str.findstr(0, "1") == -1);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("012 45 789");

        // VERIFY
        assert(str.findstr(0, "789") == 7);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("012 45 789");

        // VERIFY
        assert(str.findstr(3, "789") == 7);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("012 45 789");

        // VERIFY
        assert(str.findstr(9, "9") == 9);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("Hello World!");

        // VERIFY
        assert(str.findstr(1, "llo") == 2);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("Hello World!");

        // VERIFY
        assert(str.findstr(3, "ld!") == 9);
    }
    std::cout << "Done testing find string." << std::endl;
    return 0;
}

