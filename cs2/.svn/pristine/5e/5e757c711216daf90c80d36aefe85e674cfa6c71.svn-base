//  Stack class test program
//
//  Tests: assign
//

#include "stack.hpp"
#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    { //Test swap first
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String> x;
        stack<String> y;

        x.push("first");
        x.push("second");
        x.push("third");

        x.swap(y);

        assert(x.empty());
        assert(y.pop() == "third");
        assert(y.pop() == "second");
        assert(y.pop() == "first");
    } 

    {
        stack<String> x;
        stack<String> y;

        x.push("first");
        x.push("second");
        x.push("third");

        x = y;

        assert(x.empty());
    }

    {
        stack<String> x;
        stack<String> y;

        x.push("first");
        x.push("second");
        x.push("third");

        y = x;

        assert(y.pop() == "third");
        assert(y.pop() == "second");
        assert(y.pop() == "first");
        assert(x.pop() == "third");
        assert(x.pop() == "second");
        assert(x.pop() == "first");
    }

    {
        stack<int> x;
        stack<int> y;

        for(int i = 0; i < 5; i++)
        {
            x.push(i);
            y.push(i + 5);
        }
        assert(y.top() == 9);
        y = x;
        for (int i = 4; i >= 0; i--)
        {
            assert(x.pop() == i && y.pop() == i);
        }
        assert(x.empty() && y.empty());
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing assign." << std::endl;
    return 0;
}

