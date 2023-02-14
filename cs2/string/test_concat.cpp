//  String class test program
//
//  Tests: concatenation 
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
        String str1("1");
        String str2("2");
        String concat = str1 + str2;


        // VERIFY
        assert(concat == "12");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str1("1");
        String str2("2");
        String concat = str2 + str1;


        // VERIFY
        assert(concat == "21");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str1("1");
        String str2("2");
        str1 += str2;


        // VERIFY
        assert(str1 == "12");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str1("1");
        String str2("2");
        str2 += str1;


        // VERIFY
        assert(str2 == "21");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str1("Hello ");
        str1 += "world";

        // VERIFY
        assert(str1 == "Hello world");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str1("Hello ");
        str1 = str1 + "world";

        // VERIFY
        assert(str1 == "Hello world");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str1("123");
        String str2("321");
        str1 += str2;


        // VERIFY
        assert(str1 == "123321");
    }
    std::cout << "Done testing concatenation." << std::endl;
    return 0;
}

