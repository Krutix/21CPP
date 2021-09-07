#pragma once

#include <cstddef>

template<typename T>
void iter(T* begin, size_t size, void (*func)(T&))
{
    for (size_t idx = 0; idx < size; idx++)
        func(begin[idx]);
}

template<typename T>
void iter(T const* begin, size_t size, void (*func)(T const&))
{
    for (size_t idx = 0; idx < size; idx++)
        func(begin[idx]);
}
