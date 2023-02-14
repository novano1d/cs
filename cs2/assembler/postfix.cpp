#include <iostream>
#include <fstream>
#include "utilities.hpp"

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        std::ifstream f(argv[1]);
        if (!f.is_open())
        {
            std::cout << "Unable to open file\n";
            return 1;
        }
        while (!f.eof())
        {
            String temp = infixToPostfix(f);
            if (temp != "END_OF_FILE")
            {
                std::cout << temp << std::endl;
            }
        }
    }
    else if (argc == 3)
    {
        std::ifstream f(argv[1]);
        std::ofstream outputf(argv[2]);
        if (!f.is_open())
        {
            std::cout << "Unable to open file\n";
            return 1;
        }
        while (!f.eof())
        {
            String temp = infixToPostfix(f);
            if (temp != "END_OF_FILE")
            {
                outputf << temp << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Invalid command line arguments\n";
    }
}