//Matthew Moore
//11-3-2022
#include <iostream>
#include <vector>
#include <cstdlib>
#include <array>
#include "CarFactory.hpp"

using std::vector;
using std::cout; using std::endl;
using std::string;

class CarLot{
public:
   CarLot();
   Car *testDriveCar(){return car4sale_;}

   // if a car is bought, requests a new one
   Car* buyCar() {
       next_ = 0;
       Car* bought = &car4sale_[next_];
       car4sale_[next_] = *(factories_[rand() % factories_.size()]->requestCar());
       return bought;
   }

   Car* nextCar() {
       next_++;
       if (next_ == LOT_SIZE) next_ = 0;
       return &car4sale_[next_];
   }

   int lotSize() { return LOT_SIZE; }

private:
    static const int LOT_SIZE = 10;
    inline static int next_ = 0;
    Car car4sale_[LOT_SIZE]; //array of cars for sale
    vector<CarFactory*> factories_;
};


CarLot::CarLot(){
   // creates 2 Ford factories and 2 Toyota factories 
   factories_.push_back(new FordFactory());   
   factories_.push_back(new ToyotaFactory());
   factories_.push_back(new FordFactory());
   factories_.push_back(new ToyotaFactory());

   // Fill lot with random cars
   for (int i = 0; i < LOT_SIZE; ++i) {
       car4sale_[i] = *(factories_[rand() % factories_.size()]->requestCar());
   }
}

CarLot *carLotPtr = nullptr; // global pointer instantiation

// test-drives a car
// buys it if Toyota
void toyotaLover(int id){
   if (carLotPtr == nullptr)
      carLotPtr = new CarLot();

   for (int i = 0; i < carLotPtr->lotSize(); ++i) {
       Car* toBuy = carLotPtr->nextCar();
       cout << "Buyer " << id << endl;
       cout << "test driving "
           << toBuy->getMake() << " "
           << toBuy->getModel();

       if (toBuy->getMake() == "Toyota") {
           cout << " loves it! buying it!" << endl;
           carLotPtr->buyCar();
            return;
       }
       else
           cout << " did not like it!" << endl;
   }
}

// test-drives a car
// buys it if Ford
void fordLover(int id){
   for (int i = 0; i < carLotPtr->lotSize(); ++i) {
       Car* toBuy = carLotPtr->nextCar();
       cout << "Buyer " << id << endl;
       cout << "test driving "
           << toBuy->getMake() << " "
           << toBuy->getModel();

       if (toBuy->getMake() == "Ford") {
           cout << " loves it! buying it!" << endl;
           carLotPtr->buyCar();
            return;
       }
       else
           cout << " did not like it!" << endl;
   }
}

//customers are picky to maker AND model
//Randomly chooses if toyota or ford lover
//Randomly chooses the model they want as well
void carBuyer(int id)
{
    if (carLotPtr == nullptr) carLotPtr = new CarLot();
    Car *toBuy = carLotPtr->testDriveCar();
    string maker = "Toyota";
    string model;
    if (rand() % 2 == 0) maker = "Ford";
    if (maker == "Toyota")
    {
        static const std::array<std::string, 5> models = {"Corolla", "Camry", "Prius", "4Runner", "Yaris"};
        model = models[rand() % models.size()];
    }
    else
    {
        static const std::array<std::string, 4> models = {"Focus", "Mustang", "Explorer", "F-150"};
        model = models[rand() % models.size()];
    }
    for (int i = 0; i < carLotPtr->lotSize(); ++i) {
       Car* toBuy = carLotPtr->nextCar();
       cout << "Buyer " << id << endl;
       cout << "test driving "
           << toBuy->getMake() << " "
           << toBuy->getModel();

       if (toBuy->getMake() == maker && toBuy->getModel() == model) {
           cout << " loves it! buying it!" << endl;
           carLotPtr->buyCar();
            return;
       }
       else
           cout << " did not like it!" << endl;
   }

}

int main() {
   srand(time(nullptr));

   const int numBuyers=10;
   for(int i=0; i < numBuyers; ++i)
        carBuyer(i);
    //   if(rand()% 2 == 0)
    //      toyotaLover(i);
    //   else
    //      fordLover(i);
  
}
