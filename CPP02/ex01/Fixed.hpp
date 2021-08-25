#pragma once
#include <cmath>
#include <iostream>
#include <numeric>

class Fixed
{
private:
    typedef int raw_bits_t;
public:
    Fixed();

    Fixed(float num);

    Fixed(int num);

    Fixed(Fixed const& other);

    Fixed& operator=(Fixed const& other);

    float toFloat() const;

    int toInt() const;

    ~Fixed();

    raw_bits_t getRawBits() const { return _raw_bits; }
    void       setRawBits(raw_bits_t raw_bits) { this->_raw_bits = raw_bits; }
private:
    raw_bits_t              _raw_bits;
    static u_int8_t const   _fractinal_bits = 8;
};

std::ostream& operator<< (std::ostream& os, Fixed const& fixed);
