#include "battleship.hpp"

using std::cin; using std::cout; using std::endl;

int main()
{
	srand(time(nullptr));
	Fleet f;
	char input;
	bool print = false;
	f.deployFleet();
	cout << "Do you want ships' positions and status to be printed? (Y/N) ";
	cin >> input;
	if (input == 'Y' || input == 'y')
	{
		print = true;
	}
	while (f.operational())
	{
		Location l;
		l.fire();
		if (f.isHitNSink(l))
		{
			cout << "Hit!\n";
		}
		else
		{
			cout << "Miss!\n";
		}
		if (print)
		{
			f.printFleet();
			cout << endl;
		}
	}
	cout << "Congratulations! You win. You've sunk all the battleships.";
}