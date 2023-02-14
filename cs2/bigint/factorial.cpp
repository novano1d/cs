  /**
   * Matthew Moore
   * factorial.cpp
   * cs23001
   */


#include "bigint.hpp"

int fiveToTheN(int n)
{
    assert(n >= 0);
    if (n == 0)
    {
        return 1; // base case
    }
    return 5 * fiveToTheN(n - 1);
}

int countTrailing0s(int nFactorial)
{
    int trailing = 0;
    int n = 1;
    while (nFactorial / fiveToTheN(n) > 0) //continues until n! / 5^i is a decimal value
    {
        trailing += nFactorial / fiveToTheN(n); //truncates decimal and adds only whole numbers
        n++;
    }
    return trailing;
}

int main()
{
    std::cout << "10! has 2 trailing 0s\n";
    std::cout << "Demonstration of nfact method using 10! : " << nfact(10) << std::endl;
    std::cout << "To count trailing 0s, you find the sum of all the times each power of five completely fits into the number you are taking the factorial of.\n";
    std::cout << "ie with 10! ... 10 / 5 = 2 therefore 2 trailing zeros\n";
    std::cout << "ie with 100! ... 100 / 5 = 20 ... 100 / 25 = 4 ... 100 / 125 = decimal so disregard ... sum of 20 + 4 = 24\n";
    std::cout << "So that's the mathmatical way to calculate the number of trailing 0s. But how did I implement it into code?\n";
    std::cout << "I simply created a method that calculates 5^n power and then created a method that loops until the factorial divided by 5^n does not produce a whole number that can be truncated.\n";
    std::cout << "Demonstration: 4617! has " << countTrailing0s(4617) << " trailing zeros.";
}