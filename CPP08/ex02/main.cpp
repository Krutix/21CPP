#include "mutantstack.hpp"
#include <list>
#include <iostream>

namespace ft {

template<typename T>
T const& constCast(T& l)
{
    return const_cast<T const&>(l);
}

}

int main()
{
    {
    typedef mutantstack<int>::iterator iterator;
    typedef mutantstack<int>::const_iterator const_iterator;
    mutantstack<int> a;

    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    for (iterator b = a.begin(); b != a.end(); b++)
        std::cout << *b;
    std::cout << std::endl;
    for (const_iterator b = ft::constCast(a).begin(); b != ft::constCast(a).end(); b++)
        std::cout << *b;
    std::cout << std::endl;
    }
    {
    typedef mutantstack<int, std::list<int> >::iterator iterator;
    typedef mutantstack<int, std::list<int> >::const_iterator const_iterator;
    mutantstack<int, std::list<int> > a;

    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    for (iterator b = a.begin(); b != a.end(); b++)
        std::cout << *b;
    std::cout << std::endl;
    for (const_iterator b = ft::constCast(a).begin(); b != ft::constCast(a).end(); b++)
        std::cout << *b;
    std::cout << std::endl;
    }
}
