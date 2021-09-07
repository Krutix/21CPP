#include "iter.hpp"
#include <iostream>

void fooa(char& a)
{
    a++;
}

void foob(char const& b)
{
    std::cout << b;
}

int main()
{
    char a[] = {'a','a','a','a','a'};
    char const b[] = {'b','b','b','b','b'};
    iter(a, 5, foob), std::cout << std::endl;
    iter(a, 5, fooa); iter(a, 5, fooa);
    iter(b, 5, foob), std::cout << std::endl;
    iter(a, 5, foob), std::cout << std::endl;
}
