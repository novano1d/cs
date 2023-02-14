#include <iostream>
#include <string>
#include <fstream>

void readUntilSpace(std::ifstream &file)
{
    if(!file.is_open()) 
    {
      std::cout << "Unable to open file\n";
    }
    std::string out;
    std::getline(file, out, ' ');
    std::cout << out;
    file.close();
}

void addTwoNums(std::ifstream &file)
{
    if(!file.is_open()) 
    {
      std::cout << "Unable to open file\n";
    }
    std::string uno;
    std::string dos;
    std::getline(file, uno, ';');
    std::getline(file, dos, ';');
    std::cout << (std::stoi(uno) + std::stoi(dos));
    file.close();
}

int main()
{
    std::ifstream file("file1.txt");
    addTwoNums(file);
    std::ifstream file2("file2.txt");
    readUntilSpace(file2);
}