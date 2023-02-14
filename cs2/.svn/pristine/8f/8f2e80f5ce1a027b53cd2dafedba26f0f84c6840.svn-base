//  String class test program
//
//  Tests: char array constructor 
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
        String str("test");

        // VERIFY
        assert(str == "test");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("");

        // VERIFY
        assert(str == "");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        char s[3] = {'1' , '2' , '3'};
        String str(s);

        // VERIFY
        assert(str == "123");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("fileufgljsfdlijasdf;piidqeodu3pq89edlcuSDF");

        // VERIFY
        assert(str == "fileufgljsfdlijasdf;piidqeodu3pq89edlcuSDF");
    }
    std::cout << "Done testing char array constructor." << std::endl;
    return 0;
}

