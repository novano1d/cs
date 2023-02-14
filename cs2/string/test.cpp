#include <cstdlib> 
#include <iostream>
#include <fstream>
#include <vector>

#include "string.hpp" 
#include "logentry.hpp"

void test(String s)
{
    std::cout << s;
}

int main()
{
    String s("100");
    test(s);
}