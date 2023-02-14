//==============================================================================
// Basics for openning a file for milestone 2 of Project 1. 
//
#include <iostream> 
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    std::ifstream in("data1-1.txt");    // Define stream for input
    if(!in) {                           // Make sure it opened correctly.
        std::cerr << "Could not open data1-1.txt, exiting." << std::endl;
        exit(1);
    }
    
    //Until end of file
       //Read two bigints
       //Print them out
       //Add them together
       //Print out results
    while (!in.eof())
    {
        bigint one, two, sum;
        in >> one >> two;
        if (in.eof()) break;
        sum = one + two;
        std::cout << sum << std::endl;
    }
    
    in.close();
    return 0;
}

