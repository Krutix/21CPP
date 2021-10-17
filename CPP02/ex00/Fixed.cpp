#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _raw_bits(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const& other) : _raw_bits(other._raw_bits)
{
    std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(Fixed const& other)
{
    std::cout << "Assignation operator called\n";
    this->_raw_bits = other._raw_bits;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

int     Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called\n";
    return _raw_bits;
}

void    Fixed::setRawBits(int raw_bits)
{
    std::cout << "setRawBits member function called\n";
    this->_raw_bits = raw_bits;
}
