/* 
   Matthew Moore
   9-8-2022
   Tracks rarity of words in a given text
*/
#include "wordtracking.hpp"
#include <fstream>
int main(int argc, char *argv[])
{
    WordList w;
    if (argc != 2)
    {
        std::cout << "Invalid arguments.\n";
        return 0;
    }
    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::cout << "File does not exist or has failed to open.\n";
        return 0;
    }
    
    string word;
    while (file >> word)
    {
        w.addWord(word);
    }
    w.print();
}