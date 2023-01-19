//Matthew Moore
//10-28-2022
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using std::string;

class Logger
{
public:
    static Logger& instance()
    {
        static Logger l;
        return l;
    }
    void report(const string& s)
    {
        if (!fout.is_open())
        {
            fout.open("log.txt", std::fstream::out | std::fstream::app);
        }
        fout << s;
    }
    ~Logger()
    {
        fout.close();
    }
private:
    Logger(){}
    Logger(const Logger&){}
    Logger& operator=(const Logger&){}
    std::ofstream fout;
};

void testFuncEvens()
{
    Logger &log = Logger::instance();
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0) log.report(std::to_string(i));
    }
    log.report("\n");
}

void testFuncOdds()
{
    Logger &log = Logger::instance();
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 1) log.report(std::to_string(i));
    }
    log.report("\n");
}

int main()
{
    Logger &log = Logger::instance();
    log.report("test1");
    log.report("\ntest2\n");
    testFuncEvens();
    testFuncOdds();
}