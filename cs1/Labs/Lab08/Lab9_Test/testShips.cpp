// Mikhail Nesterenko
// tests battleShip functions implementation
// 3/11/2019

#include "battleship.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {
    
     srand(time(nullptr)); // random seed
    //srand(1); // fixed seed    

    // first part:
    // checking Location functions
    // 

    // create Location
    Location mySpot;
    mySpot.x = 5;
    mySpot.y = 'e';

    // print Location 
    cout << "mySpot.x = " << mySpot.x << " mySpot.y = " << mySpot.y << endl;

    mySpot = pick(); // assign randomly generated Location to mySpot
    cout << "mySpot.x = " << mySpot.x << " mySpot.y = " << mySpot.y << endl;

    mySpot = fire(); // assign user input Location to mySpot
    cout << "mySpot.x = " << mySpot.x << " mySpot.y = " << mySpot.y << endl;

    // second part:
    // checking Ship functions
    //

    

    Ship myShip;

    myShip.loc = pick(); // assign random Location to myShip
    myShip.sunk = false;  // myShip is not sunk
    printShip(myShip); // print myShip information
    cout << endl;
    if (match(myShip, mySpot))
       cout << "myShip is at mySpot Location\n";
    else
       cout << "myShip is not at mySpot Location\n";

    sink(myShip); // sinking myShip
    printShip(myShip); // print sunk ship
    cout << endl;
    

    // third part:
    // checking fleet functions
    // 

    
    Ship myFleet[fleetSize];

    initialize(myFleet); //assigning -1 to all ship's Locations in myFleet
    printFleet(myFleet);
    cout << endl;

    if (check(myFleet, mySpot) != -1)
       cout << "myFleet has a ship at mySpot\n";
    else
       cout << "myFleet does not have a ship at mySpot\n";

    deploy(myFleet); // deploying ships at random Locations
    printFleet(myFleet);
    cout << endl;

    if (operational(myFleet))
       cout << "at least one ship is not sunk\n";
    else
       cout << "all ships are sunk\n";
    
}