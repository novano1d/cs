#include "object_construction.hpp"

example::example(std::string e)
{
    example_name = e;
    std::cout << this << " | " << example_name << " constructor called\n";
}

example::example(const example& other)
{
    example_name = other.example_name;
    std::cout << this << " | " << example_name << " copy constructor called on " << other.example_name << " | " << &other << std::endl;
}

example::~example()
{
    std::cout << this << " | " <<  example_name << " destructor called\n";
}