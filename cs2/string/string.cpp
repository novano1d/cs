#include "string.hpp"

String::String()
{
    str = new char[1];
    stringSize = 1;
    str[0] = 0;
}

String::String(char c)
{
    if (c == '\0')
    {
        str = new char[1];
        stringSize = 1;
        str[0] = 0;
    }
    else
    {
        str = new char[2];
        stringSize = 2;
        str[0] = c;
        str[1] = 0;
    }
}

String::String(const char literal[])
{
    stringSize = 0;
    while(literal[stringSize] != 0) stringSize++;
    stringSize++;
    str = new char[stringSize];
    for (int i = 0; i < stringSize; i++) str[i] = literal[i];
    str[stringSize - 1] = 0;
}

String::String(const String& other)
{
    stringSize = other.stringSize;
    str = new char[stringSize];
    for (int i = 0; i < stringSize; i++) str[i] = other.str[i];
}

String::~String()
{
    delete[] str;
}

void String::swap(String& other)
{
    char *temp = str;
    str = other.str;
    other.str = temp;
    int stringSizeTemp = stringSize;
    stringSize = other.stringSize;
    other.stringSize = stringSizeTemp;
}

int String::capacity() const
{
    return stringSize - 1;
}

int String::length() const 
{
    return stringSize - 1;
    // int result = 0;
    // while (str[result] != 0) 
    // {
    //     result++;
    // }
    // return result;
}

String& String::operator=(String s)
{
    swap(s);
    return *this;
}

char String::operator[](int i) const
{
    assert(i >= 0);
    assert(i < stringSize);
    return str[i];
}

char& String::operator[](int i)
{
    assert(i >= 0);
    assert(i < stringSize);
    return str[i];
}

String& String::operator+=(const String& rhs)
{
    int rhsLength = rhs.length();
    int offset = length();
    stringSize = rhsLength + offset + 1;
    char *temp = new char[stringSize];
    for (int i = 0; i < offset; i++) //copy over vals of original string
    {
        temp[i] = str[i];
    }
    for (int i = 0; i < rhsLength; i++) //copy over characters from rhs string
    {
        temp[i + offset] = rhs[i];
    }
    delete[] str;
    str = temp;
    str[offset + rhsLength] = 0;
    return *this;
}

String operator+(String lhs, const String& rhs)
{
    return lhs += rhs;
}

bool String::operator==(const String& rhs) const
{
    int i = 0;
    while ((str[i] != 0) && (str[i] == rhs.str[i]))
    {
        i++;
    }
    return str[i] == rhs.str[i];
}

bool String::operator<(const String& rhs) const
{
    int i = 0;
    while ((str[i] != 0) && (rhs.str[i] != 0) && (str[i] == rhs.str[i])) ++i;
    return str[i] < rhs.str[i];
}

bool operator==(char lhs, const String& rhs) {return String(lhs) == rhs;}
bool operator==(const char lhs[], const String& rhs) {return String(lhs) == rhs;}
bool operator<(char lhs, const String& rhs) {return String(lhs) < rhs;}
bool operator<(const char lhs[], const String& rhs) {return String(lhs) < rhs;}
bool operator!=(const String& lhs, const String& rhs) { return !(lhs == rhs);}
bool operator<=(const String& lhs, const String& rhs) {return !(rhs < lhs);}
bool operator>=(const String& lhs, const String& rhs) {return !(lhs < rhs);}
bool operator>(const String& lhs, const String& rhs) {return rhs < lhs;}

int String::findch(int start, char ch) const 
{
    if (start >= length()) return -1;
    if (start < 0) start = 0;
    int i = start;
    while (str[i] != 0)
    {
        if (str[i] == ch) return i;
        i++;
    }
    return -1;
}

int String::findstr(int start, const String& findThis) const
{
    if (findThis.length() == 0) return -1;
    for (int i = start; i <= length() - findThis.length(); i++)
    {
        if (substr(i, i + (findThis.length() - 1)) == findThis)
        {
            return i;
        }
    }
    return -1;
}

String String::substr(int start, int end) const
{
    String result;
    if (start < 0) start = 0;
    if (end >= length()) end = length() - 1;
    if (end < start) return result;
    if (start >= length()) return result;
    int size = end - start + 1;
    for (int i = 0; i < size; i++)
    {
        result += str[i + start];
    }
    return result;
}

std::ostream& operator<<(std::ostream& out, const String& rhs)
{
    out << rhs.str;
    return out;
}

std::istream& operator>>(std::istream& in, String& rhs)
{
    char buffer[99999]; //lol
    if (in.eof())
        buffer[0] = 0;
    else
        in >> buffer;
    rhs = String(buffer);
    return in;
}

std::vector<String> String::split(char inCh) const
{
    std::vector<String> output;
    int currentLocation = 0;
    bool finalString = false;
    while (findch(currentLocation, inCh) != -1 || !finalString)
    {
        if (findch(currentLocation, inCh) == -1) finalString = true;
        if (!finalString)
        {
            int cpos = findch(currentLocation, inCh);
            output.push_back(substr(currentLocation, cpos - 1));
            currentLocation = cpos + 1;
        }
        else
        {
            output.push_back(substr(currentLocation, length() - 1));
        }
    }
    return output;
}

//for my mental health:

int integer_pow(int x, int n)
{
    int r = 1;
    while (n--)
       r *= x;
    return r; 
}

int String::toInt() const
{
    int i = 0;
    int out = 0;
    while (i < length())
    {
        int temp = str[i] - '0';
        if (temp < 0 || temp >= 10) return 0;
        out += temp * integer_pow(10, length() - 1 - i);
        i++;
    }
    return out;
}