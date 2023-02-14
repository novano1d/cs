//Matthew Moore
//Uses call by reference to sort 3 numbers
//10-4-2021
#include <iostream>
using namespace std;

void swap(int&, int&); // interchanges first and second parameter.

int main()
{
    int a, b, c;
    cout << "Please input 3 integers: ";
    cin >> a >> b >> c;
    if (a > b)
    {
        swap(a, b);
    }
    if (a > c)
    {
        swap(a, c);
    }
    if (b > c)
    {
        swap(b, c);
    }
    cout << "The numbers in sorted order are: " << a << " "<< b << " " << c;
}

//interchanges left and right
void swap(int& left, int& right) 
{
    const int tmp = left;
    left = right;
    right = tmp;
}
