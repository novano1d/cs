#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
using std::cout; using std::string; using std::ifstream; using std::endl; using std::vector;

int indexOfDiff(string s1, string s2)
{
    if (s2 > s1)
    {
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != s2[i])
            {
                return i;
            }
        }
        return s1.length();
    }
    else if (s1 > s2)
    {
        for (int i = 0; i < s2.length(); i++)
        {
            if (s1[i] != s2[i])
            {
                return i;
            }
        }
        return s2.length();
    }
    return -1;
}

int numOfDigs(int number)
{
    if (number == 0) return 1;
    int digits = 0; 
    while (number != 0) 
    { 
        number /= 10; 
        digits++; 
    }
    return digits;
}

int main(int argc, char* argv[])
{
    string f1;
    string f2;
    if (argc != 3) 
    {
        cout << "Error, invalid arguments.\n";
        return 0;
    }
    else
    {
        f1 = argv[1];
        f2 = argv[2];
    }
    ifstream readf1(f1);
    ifstream readf2(f2);
    if (!readf1.is_open() || !readf2.is_open()) 
    {
        std::cerr << "Could not open one or more files.\n";
        return 0;
    }
    std::vector<std::string> linesf1;
    std::copy(std::istream_iterator<string>(readf1), std::istream_iterator<std::string>(), std::back_inserter(linesf1));
    std::vector<std::string> linesf2;
    std::copy(std::istream_iterator<string>(readf2), std::istream_iterator<std::string>(), std::back_inserter(linesf2));
    string spaceString;
    if (linesf1.size() < linesf2.size())
    {
        for (int i = 0; i < linesf1.size(); i++)
        {
            if (linesf1[i] != linesf2[i])
            {
                cout << f1 << ": " << i + 1 << ": " << linesf1[i] << endl;
                cout << f2 << ": " << i + 1 << ": " << linesf2[i] << endl;
                cout << spaceString.assign(f1.length() + 4 + numOfDigs(i) + indexOfDiff(linesf1[i], linesf2[i]), ' ') << '^' << endl;
            }
        }
        //deal with leftovers
        for (int i = 0; i < linesf2.size() - linesf1.size(); i++)
        {
            cout << f1 << ": " << linesf1.size() + i + 1 << ": " << endl;
            cout << f2 << ": " << linesf1.size() + i + 1 << ": " << linesf2[i + linesf1.size()] << endl;
            cout << spaceString.assign(f1.length() + 4 + numOfDigs(i), ' ') << '^' << endl;
        }
        
    }
    else if (linesf2.size() < linesf1.size())
    {
        for (int i = 0; i < linesf2.size(); i++)
        {
            if (linesf1[i] != linesf2[i])
            {
                cout << f1 << ": " << i + 1 << ": " << linesf1[i] << endl;
                cout << f2 << ": " << i + 1 << ": " << linesf2[i] << endl;
                cout << spaceString.assign(f1.length() + 4 + numOfDigs(i) + indexOfDiff(linesf1[i], linesf2[i]), ' ') << '^' << endl;
            }
        }
        //deal with leftovers
        for (int i = 0; i < linesf1.size() - linesf2.size(); i++)
        {
            cout << f1 << ": " << linesf2.size() + i + 1 << ": " << linesf1[i + linesf2.size()] << endl;
            cout << f2 << ": " << linesf2.size() + i + 1 << ": " << endl;
            cout << spaceString.assign(f1.length() + 4 + numOfDigs(i), ' ') << '^' << endl;
        }
    }
    else
    {
        for (int i = 0; i < linesf2.size(); i++)
        {
            if (linesf1[i] != linesf2[i])
            {
                cout << f1 << ": " << i + 1 << ": " << linesf1[i] << endl;
                cout << f2 << ": " << i + 1 << ": " << linesf2[i] << endl;
                cout << spaceString.assign(f1.length() + 4 + numOfDigs(i) + indexOfDiff(linesf1[i], linesf2[i]), ' ') << '^' << endl;
            }
        }
    }
    readf1.close();
    readf2.close();
}