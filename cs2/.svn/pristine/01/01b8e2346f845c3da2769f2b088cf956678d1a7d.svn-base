  /**
   * Matthew Moore
   * multiply.cpp
   * cs23001
   */

#include "bigint.hpp"
#include <fstream>
#include <cstdlib>

int main()
{
    std::ifstream in("data1-2.txt");
    if (!in)
    {
        std::cerr << "Could not open data1-2.txt, exiting." << std::endl;
        exit(1);
    }

    while (!in.eof())
    {
        bigint one, two, product;
        in >> one >> two;
        if (in.eof()) break; //ensures that if eof the while loop ends before printing anything more
        product = one * two;
        std::cout << "The first input is: " << one << std::endl << std::endl << "The second input is: " << two << std::endl << std::endl << "The product of these two numbers is: " << product << std::endl << std::endl;
    }
}