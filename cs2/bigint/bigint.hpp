  /**
   * Matthew Moore
   * bigint.hpp
   * cs23001
   */

#ifndef BIGINT_HPP
#define BIGINT_HPP
#include <iostream>
#include <assert.h>

const int CAPACITY = 200;

class bigint
{
public:
    bigint(); //default constructor
    bigint(int); //init to int
    bigint(const char[]); //init to char array
    void debugPrint(std::ostream&) const;
    friend std::ostream& operator<<(std::ostream&, const bigint&);
    friend std::istream& operator>>(std::istream&, bigint&);
    bool operator==(const bigint&);
    bigint operator+(const bigint&) const;
    int operator[](int) const;
    int& operator[](int);
    bigint timesDigit(int) const;
    bigint times10(int) const;
    bigint operator*(const bigint&) const;
private:
    int arr[CAPACITY] = {0};
    int size = 0;
};
bool operator==(int, const bigint&);
bigint operator+(int, const bigint&);
bigint nfact(int);
#endif