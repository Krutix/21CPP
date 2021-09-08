#pragma once

#include <cstddef>
#include <exception>
#include <stdexcept>
#include <string>

template<typename T>
struct autofree_ptr
{
    T* m_ptr;
    typedef void (*t_del)(void*);

    autofree_ptr(T* ptr = NULL, t_del deleter = ::operator delete)
            : m_ptr(ptr), m_deleter(deleter) {}
    ~autofree_ptr() { m_deleter(m_ptr); }
    T* release() { T* tmp = m_ptr; m_ptr = NULL; return tmp; }
private:
    autofree_ptr(autofree_ptr const&);
    autofree_ptr& operator = (autofree_ptr const&);

    t_del m_deleter;
};

template<typename T>
class Array
{
public:
    Array(size_t size = 0);
    Array(Array<T> const& right);
    ~Array();
    
    Array& operator = (Array const& right);

    T const& operator[](size_t pos) const;
    T&       operator[](size_t pos);
private:
    size_t  m_size;
    T*      m_array;
};

template<typename T>
Array<T>::Array(size_t size)
    : m_size(size), m_array(new T[size]) { }

template<typename T>
Array<T>::Array(Array<T> const& right)
    : m_size(right.m_size)
{
    autofree_ptr<T> new_arr(new T[m_size], ::operator delete[]);
    for (size_t i = 0; i < m_size; i++)
        new_arr.m_ptr[i] = right.m_array[i];
    m_array = new_arr.release();
}

template<typename T>
Array<T>::~Array()
{
    delete[] m_array;
}

template<typename T>
Array<T>& Array<T>::operator = (Array const& right)
{
    if (&right == this)
        return *this;

    autofree_ptr<T> new_array(new T[right.m_size], ::operator delete[]);
    for (size_t i = 0; i < right.m_size; i++)
        new_array.m_ptr[i] = right.m_array[i];

    m_size = right.m_size;
    delete[] m_array;
    m_array = new_array.release();
    return *this;
}

template<typename T>
T const& Array<T>::operator[](size_t pos) const
{
    if (pos >= m_size)
        throw std::out_of_range("Out of range");
    return m_array[pos];
}

template<typename T>
T& Array<T>::operator[](size_t pos)
{
    return const_cast<T&>(const_cast<Array<T> const&>(*this)[pos]);
}
