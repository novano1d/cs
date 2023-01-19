#include "hashmap.hpp"
#include <iostream>

using namespace::std;

// template tests hashmap erases
template <typename Key, typename Value>
void test_erase(hashmap<Key, Value>& hm, Key key) {
   cout << "[*] Erasing " << key << "...\n";
   pair<const pair<const Key, Value>*, bool> result = hm.erase(key);

   if(result.second) {
      cout << "--> Done! ";
      if(result.first) 
         cout << "The next element is " << result.first->first
	      << ": " << result.first->second << endl;
      else 
         cout << "There is no next element\n";
   }
   else {
      cout << "--> Failed! Key " << key << " doesn't exist!\n";
   }
}

int main()
{
    hashmap<int, int> mymap;
    for (int i = 0; i < 1000; i++)
    {
        mymap.insert(std::make_pair(i, i*2));
    }
    test_erase(mymap, 55);

    hashmap<int, int> mymap2;
    for (int i = 0; i < 1; i++)
    {
        mymap2.insert(std::make_pair(i, i*2));
    }
    test_erase(mymap2, 0);
}