#pragma once
#include <stack>

template<typename T, typename Container = std::deque<T> >
class mutantstack : public std::stack<T, Container>
{
public:
    typedef typename std::stack<T, Container>::container_type   container_type;
    typedef typename container_type::iterator                   iterator;
    typedef typename container_type::const_iterator             const_iterator;

    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
};
