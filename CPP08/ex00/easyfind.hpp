#pragma once
#include <algorithm>

template <typename T>
int easyfind(T const& container, int num) {

    typedef typename T::const_iterator citerator;
    citerator position;

    position = std::find(container.begin(), container.end(), num);

    if (position != container.end())
    {
        return (std::distance(container.begin(), position));
    }
    else
    {
        return -1;
    }
}
