//  Stack class test program
//
//  Tests: infix to postfix method
//

#include "utilities.hpp"
#include <cassert>
#include <iostream>
#include <fstream>

//===========================================================================
int main ()
{
    
    {
        std::fstream file("data3-1.txt");
        if (!file.is_open())
        {
            std::cout << "missing data3-1.txt\n";
        }
        assert("AX B C * +" == infixToPostfix(file));
        assert("AX B CY * + D E - /" == infixToPostfix(file));
        assert("A B + C E + *" == infixToPostfix(file));
        assert("AX BX CY AY + BY + CX * * *" == infixToPostfix(file));
        assert("H A B C + D * + F * G * E * * J +" == infixToPostfix(file));
    }


    std::cout << "Done testing infix to postfix." << std::endl;
    return 0;
}