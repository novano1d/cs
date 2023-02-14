//Simple troll guessing game
//Matthew Moore
//9-23-2021

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	srand(time(nullptr));
	int age = rand() % 101 + 100;
	int guess; 
	while (true)
	{
		cout << "Hello, handsome prince. I am an ugly old troll. How old am I? ";
		cin >> guess;
		if (guess == age)
		{
			cout << "You got it! Here is the fair maiden. Live happily ever after!";
			break;
		}
		else if (guess < age)
		{
			cout << "Wrong, I am older. No fair maiden for you. Better luck next year." << endl;
		}
		else if (guess > age)
		{
			cout << "Wrong, I am younger. No fair maiden for you. Better luck next year." << endl;
		}
		age++;
	}
}