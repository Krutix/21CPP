#include "Array.hpp"
#include <iostream>

static size_t counter = 0;

struct test
{
    size_t idx;
    test() : idx(counter++) { std::cout << "construct " << idx << std::endl; }
    test(test const& other) : idx(counter++) { std::cout << "copy construct " << idx << " from " << other.idx << std::endl; }
    test& operator = (test const& other) { std::cout << "copy construct " << idx << " from " << other.idx << std::endl; return *this; }
    ~test() { std::cout << "destructor " << idx << std::endl; }
};

namespace ft {

template<typename T>
T const& constCast(T& l)
{
    return const_cast<T const&>(l);
}

}

int main()
{
    Array<test> arr(10);
    arr[5] = test();
    arr = ft::constCast(arr);
    arr = Array<test>(5);
    try
    {
        arr[5] = test();
    }
    catch(std::out_of_range const& e) { std::cerr << e.what() << '\n'; }
    catch(std::exception const& e) { std::cerr << "Mmmmm... Ok: " << e.what() << '\n'; }

    std::cout << ft::constCast(arr)[4].idx << '\n';
}
