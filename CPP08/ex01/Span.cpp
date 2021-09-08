#include "Span.hpp"

#include <algorithm>

#include <iostream>

Span::Span(size_t max_size)
    : m_arr(0), m_max_size(max_size), m_size(0) {}

Span::Span(Span const &src)
    : m_arr(src.m_arr), m_max_size(src.m_max_size), m_size(src.m_size) {}

Span::~Span() {}

Span& Span::operator=(Span const &src)
{
    if (&src == this)
        return *this;
    m_arr = src.m_arr;
    m_max_size = src.m_max_size;
    m_size = src.m_size;
    return *this;
}

void Span::addNumber(int n)
{
    if (m_arr.size() == m_max_size)
        throw std::out_of_range("Insertion of new element is out of range");
    m_arr.push_back(n);
}

size_t Span::longestSpan() const
{
    typedef std::vector<int>::const_iterator const_iterator;

    if (m_arr.size() < 2)
        throw NoSpanAvailable("Too few numbers available");

    std::pair<const_iterator, const_iterator> p
        = std::minmax_element(m_arr.begin(), m_arr.end());
    return *p.second - *p.first;
}

size_t Span::shortestSpan() const
{
    typedef std::vector<int>::iterator iterator;

    if (m_arr.size() < 2)
        throw NoSpanAvailable("Too few numbers available");

    std::vector<int> copy_arr(m_arr);
    std::sort(copy_arr.begin(), copy_arr.end());
    iterator left  = copy_arr.begin();
    iterator right = copy_arr.begin() + 1;
    size_t spin = std::numeric_limits<size_t>::max();
    while (right != copy_arr.end())
    {
        if (static_cast<size_t>(*right - *left) < spin)
            spin = *right - *left;
        left++;
        right++;
    }

    return spin;
}
