// testing the implementation of templated list collection
// Mikhail Nesterenko
// 9/6/2021

#include <iostream>
#include <string>
#include "Collection.hpp" // template definition

using std::cout; using std::endl;
using std::string;

int main(){

   // manipulating integers
   Collection<int> c;
   Collection<int> d;
   for (int i = 0; i < 100; i++)
   {
      if (i % 3 == 0) c.add(1);
      else c.add(0);
   }
   c.print();
   cout << "-------------\n";
   c.remove(1);
   c.print();
   cout << "-------------\n";
   c.remove(0);
   c.print();
   if (equal(c, d))
   {
      std::cout << "equal\n";
   }
   else std::cout << "not equal\n";
   
}