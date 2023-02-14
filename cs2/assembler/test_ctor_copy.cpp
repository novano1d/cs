//  Stack class test program
//
//  Tests: copy constructor
//

#include "string.hpp"
#include "stack.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String> x;
        
        x.push("a");
        x.push("b");
        x.push("c");
        x.push("d");
        stack<String> y(x);

        assert(y.pop() == "d");
        assert(y.pop() == "c");
        assert(y.pop() == "b");
        assert(y.pop() == "a");
        assert(x.pop() == "d");
        assert(x.pop() == "c");
        assert(x.pop() == "b");
        assert(x.pop() == "a");
    }

    {
        stack<char> x;
        x.push('a');
        x.push('b');
        x.push('c');
        x.push('d');

        stack<char> y(x);

        assert(y.pop() == 'd');
        assert(y.pop() == 'c');
        assert(y.pop() == 'b');
        assert(y.pop() == 'a');
        assert(x.pop() == 'd');
        assert(x.pop() == 'c');
        assert(x.pop() == 'b');
        assert(x.pop() == 'a');
    }

    {
        stack<int> x;
        x.push(1);
        x.push(2);
        stack<int> y;
        x = stack<int>(y);
        assert(x.empty());
        assert(y.empty());
    }

    {
        stack<int> x;
        for(int i = 1; i <= 5; i++) x.push(i);
        stack<int> y(x);
        assert(y.pop() == 5);
        assert(y.top() == 4);
        assert(x.top() == 5);
    }
    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing copy constructor." << std::endl;
    return 0;
}

