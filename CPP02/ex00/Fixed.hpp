#pragma once

class Fixed
{
public:
    Fixed();
    Fixed(Fixed const& other);
    Fixed& operator=(Fixed const& other);
    ~Fixed();

    int     getRawBits() const;
    void    setRawBits(int raw_bits);
private:
    int                 _raw_bits;
    static int const    _fractinal_bits = 8;
};
