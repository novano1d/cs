#ifndef UTILITIES_HPP
#define UTILITIES_HPP
#include "string.hpp"
#include "stack.hpp"
#include <vector>


String nextToken(std::istream& in); //grabs next token
String infixToPostfix(std::istream& in); //converts string from infix to postfix
String postfixToAssembly(String expr, std::ostream& out);
String evaluate(String left, String op, String right, std::ostream& out);
String intToString(int in);

#endif