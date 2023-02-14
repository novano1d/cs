//  Stack class test program
//
//  Tests: push and pop
//

#include "stack.hpp"
#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<int> x;

        // TEST
        x.push(1);

        // VERIFY
        assert(x.top() == 1);
        x.push(2);
        x.push(3);
        assert(x.top() == 3);
        assert(x.pop() == 3);
        assert(x.pop() == 2);
        assert(x.pop() == 1);
        assert(x.empty());
    }

    {
        stack<String> x;
        
        x.push("Hello World");
        assert(x.pop() == "Hello World");
        assert(x.empty());
        x.push("second string");
        x.push("third");
        x.push('4');
        assert(x.top() == "4");
        assert(x.pop() == "4");
        x.push("fourth");
        assert(x.pop() == "fourth");
        assert(x.pop() == "third");
        assert(x.pop() == "second string");
        assert(x.empty());
    }

    {
        stack<char> x;
        assert(x.empty());
        x.push('a');
        x.push('b');
        assert(x.top() == 'b');
        x.push('c');
        assert(x.pop() == 'c');
        assert(x.pop() == 'b');
        assert(x.pop() == 'a');
        assert(x.empty());
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing push and pop." << std::endl;
    return 0;
}

