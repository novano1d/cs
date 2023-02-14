//Unique numbers lab
//Matthew Moore
//10-5-2021

#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

int main() 
{
	const int arraySize = 10;
	int uniqueElements = 0;
	int uniqueNumbers[arraySize] = { 0 }; // declaraing and initializing array
	srand(time(nullptr)); // initializing radom number generator
	outerloop:
	while (uniqueElements < arraySize)
	{
		int num = rand() % 100 + 1;
		for (int i : uniqueNumbers)
		{
			if (i == num)
			{
				goto outerloop; //breaks out of nested loop
			}
		}
		uniqueNumbers[uniqueElements] = num;
		uniqueElements++;
	}
	for (int i : uniqueNumbers)
	{
		cout << i << " ";
	}
}