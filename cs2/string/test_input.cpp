//  String class test program
//
//  Tests: input 
//

#include "string.hpp"
#include <cassert>
#include <iostream>
#include <fstream>
 
//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        std::ifstream file("test_input.txt");
        assert(file.is_open());
        String str1;
        String str2;
        String str3;
        file >> str1 >> str2 >> str3;
        // VERIFY
        assert(str1 == "Hello");
        assert(str2 == "World!!!");
        assert(str3 == "ThirdWord");
    }
    
    std::cout << "Done testing input." << std::endl;
    return 0;
}

