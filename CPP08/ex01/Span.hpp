#pragma once

#include <cstddef>
#include <vector>
#include <stdexcept>

class Span
{
public:
    class NoSpanAvailable : public std::logic_error
    {
    public:
        NoSpanAvailable(char const* what)
            : std::logic_error(what) {}
    };

public:
    Span(size_t max_size = 0);
    Span(Span const &src);
    ~Span();
    Span& operator=(Span const &src);

    void addNumber(int n);

    size_t longestSpan() const;
    size_t shortestSpan() const;

private:
    std::vector<int>    m_arr;
    size_t              m_max_size;
    size_t              m_size;
};
