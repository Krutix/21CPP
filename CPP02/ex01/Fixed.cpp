#include "Fixed.hpp"

#define FLOAT_BIAS				127
#define FLOAT_EXP_OFFSET		23
#define FLOAT_MANTISS_INVBIT	(1 << FLOAT_EXP_OFFSET)
#define FLOAT_MANTISS_MASK		((1 << FLOAT_EXP_OFFSET) - 1)
#define FLOAT_EXP_SIZE			8
#define FLOAT_EXP_MASK			(((1 << FLOAT_EXP_SIZE) - 1) << FLOAT_EXP_OFFSET)
#define INT_BIT_SIZE			(sizeof(int) * 8)

Fixed::Fixed()
	: _raw_bits(0) {}

Fixed::Fixed(float num)
{
	_raw_bits = static_cast<int>(num) << _fractinal_bits;

	int exponent =
		((reinterpret_cast<int&>(num) & FLOAT_EXP_MASK) >> FLOAT_EXP_OFFSET)
			- FLOAT_BIAS;
	int mantissa =
		((reinterpret_cast<int&>(num) & FLOAT_MANTISS_MASK) | FLOAT_MANTISS_INVBIT);
	int frac_raw_bits;
	if (exponent >= 0)
		frac_raw_bits = mantissa << exponent;
	else
		frac_raw_bits = mantissa >> -exponent;
	_raw_bits |= ((frac_raw_bits & FLOAT_MANTISS_MASK)
				>> (FLOAT_EXP_OFFSET - _fractinal_bits));
}

Fixed::Fixed(int num)
	: _raw_bits(num << _fractinal_bits) {}

Fixed::Fixed(Fixed const& other)
	: _raw_bits(other._raw_bits) {}

Fixed& Fixed::operator=(Fixed const& other)
{
	if (this == &other)
		return *this;
	_raw_bits = other._raw_bits;
	return (*this);
}

float Fixed::toFloat() const
{
	int i = 31;
	while (i && !(_raw_bits & (1 << i)))
		i--;
	int f;
	if (i >= FLOAT_EXP_OFFSET)
		f = (_raw_bits >> (i - FLOAT_EXP_OFFSET)) & FLOAT_MANTISS_MASK;
	else
		f = (_raw_bits << (FLOAT_EXP_OFFSET - i)) & FLOAT_MANTISS_MASK;
	f |= (((i - _fractinal_bits) + FLOAT_BIAS) * !!_raw_bits) << FLOAT_EXP_OFFSET;
	return reinterpret_cast<float&>(f);
}

int Fixed::toInt() const
{
	return (roundf(this->toFloat()));
}

Fixed::~Fixed() {}

std::ostream& operator<< (std::ostream& os, Fixed const& fixed)
{
	return os << fixed.toFloat();
}
