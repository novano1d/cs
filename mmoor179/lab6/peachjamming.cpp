//Modified by Matthew Moore 10/07/2022
// jamming peaches
// non STL-algorithm code to be replaced by algorthms
// Mikhail Nesterenko
// 9/30/2021


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector; using std::deque;
using namespace std::placeholders;

struct Peaches{
   double weight; // oz
   bool ripe;  // ripe or not
   void print() const { cout << (ripe?"ripe":"green") << ", " <<  weight << endl; }
};



int main(){
   srand(time(nullptr));
   const double minWeight = 8.;
   const double maxWeight = 3.;

   cout << "Input basket size: ";
   int size;
   cin >> size;

   vector <Peaches> basket(size);

   // assign random weight and ripeness peaches in the basket
   // replace with generate()
    std::generate(basket.begin(), basket.end(), [&](){
        Peaches temp;
        temp.weight = minWeight + static_cast<double>(rand())/RAND_MAX*(maxWeight - minWeight);
        temp.ripe = rand() % 2;
        return temp;
    });


   
   // for_each() possibly
   cout << "all peaches"<< endl;
    std::for_each(basket.begin(), basket.end(), [](Peaches e){e.print();});

   // moving all the ripe peaches from basket to peck
   // remove_copy_if() with back_inserter()/front_inserter() or equivalents
   deque<Peaches> peck;
//    for(auto it=basket.begin(); it != basket.end();)
//       if(it->ripe){
// 	 peck.push_front(std::move(*it));
// 	 it=basket.erase(it);
//       }else
// 	 ++it;

    std::remove_copy_if(basket.begin(), basket.end(), std::back_inserter(peck), [](Peaches &e){
        return !e.ripe;
    });
    auto tempit = std::remove_if(basket.begin(), basket.end(), [](Peaches &e){ return e.ripe; });
    basket.erase(tempit, basket.end());

   // for_each() possibly
   cout << "peaches remainng in the basket"<< endl;
   std::for_each(basket.begin(), basket.end(), [](Peaches &e){e.print();});

   cout << endl;

   // for_each() possibly
   cout << "peaches moved to the peck"<< endl;
   std::for_each(peck.begin(), peck.end(), [](Peaches &e){e.print();});


   // prints every "space" peach in the peck
   const int space=3; 
   cout << "\nevery " << space << "\'d peach in the peck"<< endl;

   // replace with advance()/next()/distance()
   // no explicit iterator arithmetic
   auto it=peck.cbegin(); 
    int i = 1;   
    while (it != peck.end())
    {
        if (i % 3 == 0) it->print();
        std::advance(it, 1);
        i++;
    }
    


   // putting all small ripe peaches in a jam
   // use a binder to create a functor with configurable max weight
   // accumulate() or count_if() then remove_if()
   const double weightToJam = 10.0;
   double jamWeight = 0; 
    auto comparePeach = std::bind(std::greater<double>(), weightToJam, _1);
    std::count_if(peck.begin(), peck.end(), [&](Peaches e) {
        if (comparePeach(e.weight)) jamWeight += e.weight;
        return comparePeach(e.weight);
    });
    peck.erase(std::remove_if(peck.begin(), peck.end(), [&](Peaches &e){return comparePeach(e.weight);}));
   cout << "Weight of jam is: " << jamWeight << endl;

}
