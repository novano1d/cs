#include "object_construction.hpp"

example callRefAndCallVal(example &r, example v);

int main()
{
    std::cout << "main begins\n";
    example e1("main e1");
    example e2("main e2");
    callRefAndCallVal(e1, e2);
    example *ptr = new example("dynamic example");
    delete ptr;
    std::cout << "main terminates\n";
}

example callRefAndCallVal(example &r, example v)
{
    std::cout << "in method\n";
    example e3("method e1");
    std::cout << "method end\n";
    return v;
}
