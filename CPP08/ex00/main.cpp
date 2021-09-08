#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::vector<int> a;
    a.push_back(0), a.push_back(1), a.push_back(2), a.push_back(3);
    std::list<int> b;
    b.push_back(0), b.push_back(1), b.push_back(2), b.push_back(3);
    std::cout << easyfind(a, 3) << " == 3" << std::endl;
    std::cout << easyfind(b, 3) << " == 3" << std::endl;
    std::cout << easyfind(a, 4) << " == -1" << std::endl;
    std::cout << easyfind(b, 4) << " == -1" << std::endl;
}
