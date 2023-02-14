#include <iostream>

int fib_tail(int n, int a = 0, int b = 1)
{
    if (n == 0) return a;
    if (n == 1) return b;
    return fib_tail(n - 1, b, a + b);
}

int fib_not_tail(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib_not_tail(n - 1) + fib_not_tail(n - 2);
}

int main()
{
    int num;
    std::cout << "Enter the n of the sequence that you wish to find: ";
    std::cin >> num;
    std::cout << "Using Tail Recursion: ";
    for (int i = 0; i <= num; i++)
    {
        std::cout << fib_tail(i) << " ";
    }
    std::cout << std::endl << "Using (non-tail) Recursion: ";
    for (int i = 0; i <= num; i++)
    {
        std::cout << fib_not_tail(i) << " ";
    }
}