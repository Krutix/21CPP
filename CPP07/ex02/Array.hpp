#pragma once

#include <cstddef>
#include <exception>
#include <stdexcept>
#include <string>

template<typename T>
class Array
{
public:
    Array(size_t size = 0)
        : m_size(size), m_array(new T[size]) { }

    Array(Array<T> const& right)
        : m_size(right.m_size), m_array(new T[right.m_size])
    {
        for (size_t i = 0; i < m_size; i++)
            m_array[i] = right.m_array[i];
    }

    ~Array()
    {
        delete[] m_array;
    }
    
    Array& operator = (Array const& right)
    {
        if (&right == this)
            return *this;
        this->~Array();
        new (this)Array<T>(right);
        return *this;
    }

    T const& operator[](size_t pos) const
    {
        if (pos >= m_size)
            throw std::out_of_range("Out of range");
        return m_array[pos];
    }

    T& operator[](size_t pos)
    {
        return const_cast<T&>(const_cast<Array<T> const&>(*this)[pos]);
    }
private:
    size_t m_size;
    T*     m_array;
};
