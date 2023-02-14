//This program provides the sum of the entered positive integers.
//Matthew Moore
//9-13-2021

#include <iostream>

using std::cin; using std::cout; using std::endl;

int main() 
{
	int i;
	int sum = 0;
	cout << "Input sequence of integers (zero to stop):";
	cin >> i;
	while (i != 0)
	{
		if (i > 0)
		{
			sum += i;
		}
		cin >> i;
	}
	cout << "The sum of positive numbers is: " << sum;
}