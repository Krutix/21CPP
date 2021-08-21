#include <iostream>
#include <cmath>

class Fixed
{
public:
    Fixed() : _raw_bits(0) {}

    Fixed(float num)
    {
        _raw_bits = (int)num << _fractinal_bits;
    }

    Fixed(int num) : _raw_bits(num << _fractinal_bits) {}

    Fixed(Fixed const& other) : _raw_bits(other._raw_bits) {}

    Fixed operator=(Fixed const& other)
    {
        this->_raw_bits = other._raw_bits;
        return *this;
    }

    float toFloat() const
    {
        return static_cast<float>(_raw_bits >> _fractinal_bits)
                + (_raw_bits & (_fractinal_bits - 1));
    }

    int toInt() const { return std::roundf(this->toFloat()); }

    ~Fixed() {}

    int32_t getRawBits() const { return _raw_bits; }
    void    setRawBits(int32_t raw_bits) { this->_raw_bits = raw_bits; }
private:
    int32_t                 _raw_bits;
    static uint8_t const    _fractinal_bits = 8;
};

int main()
{
    Fixed a;
    Fixed b(a);
    Fixed c;
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}
