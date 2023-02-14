//  String class test program
//
//  Tests: length and capacity 
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
        String str;

        // VERIFY
        assert(str.capacity() == 0);
        assert(str.length() == 0);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("1234");

        // VERIFY
        assert(str.length() == 4);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("woeiihfwkuuhlfiuqh3er8qydliudsflkerliuvhwpe98fhwefsdhvb9p84r23blhdkvbdluif");

        // VERIFY
        assert(str.length() == 74);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("woeiihfwkuuhlfiuqh3r8qydliudsflkerliuvhwpe98fhwefsdhvbd9p84r23blhdkvbdluifweqwlehrowehriwuhqdeqlweqwwoeiihfwkuuhlfiuqh3er8qydliudsflkerliuvhwpe98fhwefsdhvb9p84r23blhdkvbdluifweqwlehrowehriwuhqdeqlweqwokdlkjqlwejq;lwjeq;oiwjeqwoeijqoewjiqoiwejqoijrbfjgdjhv");

        // VERIFY
        assert(str.length() == 255);
    }
    
    std::cout << "Done testing length and capacity." << std::endl;
    return 0;
}

