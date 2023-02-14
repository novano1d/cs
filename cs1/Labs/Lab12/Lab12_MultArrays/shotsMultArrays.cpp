// Keeping track of shots fired in Battleship game
// using multidimentional arrays
// Mikhail Nesterenko
// 4/13/2013
#include <iostream>

using std::cin; using std::cout; using std::endl;


// size of the ocean
const int oceanLength = 6;
const int oceanWidth = 6;
void printField(bool[][oceanWidth]);


int main() {
    bool shots[oceanLength][oceanWidth];
    char input;
    char first;
    int second, firstAsInt;
    while (true)
    {
        cout << "Another shot? [y/n] ";
        cin >> input;
        if (input == 'y' || input == 'Y')
        {
            cout << "Location? ";
            cin >> first >> second;
            switch (first)
            {
            case 'a':
                firstAsInt = 0;
                break;
            case 'b':
                firstAsInt = 1;
                break;
            case 'c':
                firstAsInt = 2;
                break;
            case 'd':
                firstAsInt = 3;
                break;
            case 'e':
                firstAsInt = 4;
                break;
            case 'f':
                firstAsInt = 5;
                break;
            }
            if (!shots[second - 1][firstAsInt])
            {
                cout << "duplicate!\n";
            }
            else
            {
                shots[second - 1][firstAsInt] = false;
            }
            printField(shots);
        }
        else if (input == 'n' || input == 'N')
        {
            return 0;
        }
        else
        {
            cout << "Invalid input!\n";
        }
    }
}

void printField(bool field[][oceanWidth])
{
    cout << "  a b c d e f\n";
    for (size_t i = 0; i < oceanLength; i++)
    {
        cout << i + 1 << " ";
        for (size_t j = 0; j < oceanWidth; j++)
        {
            if (!field[i][j])
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}