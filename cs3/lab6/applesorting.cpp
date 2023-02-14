//Modified by Matthew Moore 10/07/2022

// sorting apples
// non STL-algorithm code to be replaced by algorthms
// Mikhail Nesterenko
// 09/26/2022


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <deque>
#include <string>
#include <numeric>
#include <algorithm>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector; using std::deque;

struct Apples{
   double weight; // oz
   string color;  // red or green
   void print() const { cout << color << ", " <<  weight << endl; }
   bool operator<(Apples &rhs)
   {
    return weight < rhs.weight;
   }
};



int main(){
   srand(time(nullptr));
   const double minWeight = 8.;
   const double maxWeight = 3.;

   cout << "Input crate size: ";
   int size;
   cin >> size;

   vector <Apples> crate(size);

   // assign random weight and color to apples in the crate
   // replace with generate()
    std::generate(crate.begin(), crate.end(), [=]() {
        Apples temp;
        temp.color = rand() % 2 == 1 ? "green" : "red";
        temp.weight = minWeight + static_cast<double>(rand())/RAND_MAX*(maxWeight - minWeight);
        return temp;
    });

    // for_each() possibly
   cout << "all apples"<< endl;
   std::for_each(crate.begin(), crate.end(), [](Apples e) {e.print();});

   
   cout << "Enter weight to find: ";
   double toFind;
   cin >> toFind;

   // count_if()
   int cnt = std::count_if(crate.begin(), crate.end(), [=](Apples e){return e.weight > toFind;});

   cout << "There are " << cnt << " apples heavier than " 
	<< toFind << " oz" <<  endl;

    cout << "at positions ";
    auto tempit = crate.begin();
    while ((tempit = std::find_if(tempit, crate.end(), [=](Apples e){return e.weight > toFind;})) != crate.end())
    {
        cout << std::distance(crate.begin(), tempit) << ", ";
        tempit++;
    }
    cout << endl;
   


   // max_element()
   auto heaviest = std::max_element(crate.begin(), crate.end());
   cout << "Heaviest apple weighs: " << heaviest->weight << " oz" << endl;
    

   // for_each() or accumulate()
   double totalWeight = 0;
   std::for_each(crate.begin(), crate.end(), [&](Apples e){ totalWeight += e.weight;});
   cout << "Total apple weight is: " << totalWeight << " oz" << endl;


   // transform();
   cout << "How much should they grow: ";
   double toGrow;
   cin >> toGrow;
   std::transform(crate.begin(), crate.end(), crate.begin(), [=](Apples e){e.weight += toGrow; return e;});

   // remove_if()
   cout << "Input minimum acceptable weight: ";
   double minAccept;
   cin >> minAccept;
    crate.erase(std::remove_if(crate.begin(), crate.end(), [minAccept](Apples e){return e.weight < minAccept;}), crate.end());
   cout << "removed " << size - crate.size() << " elements" << endl;


   // bubble sort, replace with sort()
   sort(crate.begin(), crate.end());


   // for_each() possibly
   cout << "sorted remaining apples"<< endl;
   std::for_each(crate.begin(), crate.end(), [](Apples e) {e.print();});
}
