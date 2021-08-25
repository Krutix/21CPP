#pragma once
#include <cmath>
#include <iostream>
#include <numeric>

class Fixed
{
private:
    typedef int32_t raw_bits_t;
    typedef int64_t db_raw_bits_t;
public:
    Fixed();
    Fixed(float num);
    Fixed(int num);
    Fixed(Fixed const& other);
    ~Fixed();

    bool  operator <  (Fixed const& other) const;
    bool  operator <= (Fixed const& other) const;
    bool  operator >  (Fixed const& other) const;
    bool  operator >= (Fixed const& other) const;
    bool  operator == (Fixed const& other) const;
    bool  operator != (Fixed const& other) const;

    Fixed  operator + (Fixed const& other) const;
    Fixed  operator - (Fixed const& other) const;
    Fixed  operator * (Fixed const& other) const;
    Fixed  operator / (Fixed const& other) const;

    Fixed&  operator =  (Fixed const& other);
    Fixed&  operator += (Fixed const& other);
    Fixed&  operator -= (Fixed const& other);
    Fixed&  operator *= (Fixed const& other);
    Fixed&  operator /= (Fixed const& other);

    Fixed   operator ++ (int);
    Fixed&  operator ++ ();
    Fixed   operator -- (int);
    Fixed&  operator -- ();

    float toFloat() const;
    int   toInt()   const;

    static Fixed&         max(Fixed& a, Fixed& b);
    static Fixed const&   max(Fixed const& a, Fixed const& b);
    static Fixed&         min(Fixed& a, Fixed& b);
    static Fixed const&   min(Fixed const& a, Fixed const& b);

    raw_bits_t  getRawBits() const { return _raw_bits; }
    void        setRawBits(raw_bits_t raw_bits) { this->_raw_bits = raw_bits; }
private:
    raw_bits_t              _raw_bits;
    static u_int8_t const   _fractinal_bits = 8;
};

std::ostream& operator<< (std::ostream& os, Fixed const& fixed);
