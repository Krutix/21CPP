#pragma once

template<typename T>
void swap(T& a, T& b)
{
    T tbh(a);
    a = b;
    b = tbh;
}

template<typename T>
T const& max(T const& a, T const& b)
{
    return a < b ? b : a;
}

template<typename T>
T const& min(T const& a, T const& b)
{
    return a < b ? a : b;
}
