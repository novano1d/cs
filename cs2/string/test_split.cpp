//  String class test program
//
//  Tests: split 
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
        String str("abc ef gh");

        // VERIFY
        assert(str.split(' ').at(0) == "abc");
        assert(str.split(' ').at(1) == "ef");
        assert(str.split(' ').at(2) == "gh");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("-a--b-");

        // VERIFY
        assert(str.split('-').at(0) == "");
        assert(str.split('-').at(1) == "a");
        assert(str.split('-').at(2) == "");
        assert(str.split('-').at(3) == "b");
        assert(str.split('-').at(4) == "");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str(" ");

        // VERIFY
        assert(str.split(' ').at(0) == "");
        assert(str.split(' ').at(1) == "");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("abc");
        // VERIFY
        assert(str.split(' ').size() == 1);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("ab ");

        // VERIFY
        assert(str.split(' ').at(0) == "ab");
        assert(str.split(' ').at(1) == "");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str(" ab");

        // VERIFY
        assert(str.split(' ').at(0) == "");
        assert(str.split(' ').at(1) == "ab");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("ab cd");

        // VERIFY
        assert(str.split(' ').at(0) == "ab");
        assert(str.split(' ').at(1) == "cd");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("ab cd ef gh");

        // VERIFY
        assert(str.split(' ').at(0) == "ab");
        assert(str.split(' ').at(1) == "cd");
        assert(str.split(' ').at(2) == "ef");
        assert(str.split(' ').at(3) == "gh");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str("text1|text2|text3||");

        // VERIFY
        assert(str.split('|').at(0) == "text1");
        assert(str.split('|').at(1) == "text2");
        assert(str.split('|').at(2) == "text3");
        assert(str.split('|').at(3) == "");
        assert(str.split('|').at(4) == "");
    }
    std::cout << "Done testing split." << std::endl;
    return 0;
}

