#include <iostream>

class Fixed
{
public:
    Fixed() : _raw_bits(0)
    {
        std::cout << "Default constructor called\n";
    }

    Fixed(Fixed const& other) : _raw_bits(other._raw_bits)
    {
        std::cout << "Copy constructor called\n";
    }

    Fixed operator=(Fixed const& other)
    {
        std::cout << "Assignation operator called\n";
        this->_raw_bits = other._raw_bits;
        return *this;
    }

    ~Fixed()
    {
        std::cout << "Destructor called\n";
    }

    int32_t getRawBits() const
    {
        std::cout << "getRawBits member function called\n";
        return _raw_bits;
    }
    void    setRawBits(int32_t raw_bits)
    {
        std::cout << "setRawBits member function called\n";
        this->_raw_bits = raw_bits;
    }
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
