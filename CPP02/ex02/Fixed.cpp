#include "Fixed.hpp"

#define FLOAT_BIAS				127
#define FLOAT_EXP_OFFSET		23
#define FLOAT_MANTISS_INVBIT	(1 << FLOAT_EXP_OFFSET)
#define FLOAT_MANTISS_MASK		((1 << FLOAT_EXP_OFFSET) - 1)
#define FLOAT_EXP_SIZE			8
#define FLOAT_EXP_MASK			(((1 << FLOAT_EXP_SIZE) - 1) << FLOAT_EXP_OFFSET)
#define FLOAT_SIGNBIT			(1 << 31)
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
		frac_raw_bits = (mantissa <<  exponent) & FLOAT_MANTISS_MASK;
	else
		frac_raw_bits = (mantissa >> -exponent) & FLOAT_MANTISS_MASK;
	frac_raw_bits >>= FLOAT_EXP_OFFSET - _fractinal_bits;
	frac_raw_bits *= 1 - (num < 0) * 2;
	frac_raw_bits &= (1 << _fractinal_bits) - 1;
	_raw_bits |= frac_raw_bits;
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
	int unsign_raw_bits = std::abs(_raw_bits);

	int i = 31;
	while (i && !(unsign_raw_bits & (1 << i)))
		i--;

	int f;
	if (i >= FLOAT_EXP_OFFSET)
		f = (unsign_raw_bits >> (i - FLOAT_EXP_OFFSET)) & FLOAT_MANTISS_MASK;
	else
		f = (unsign_raw_bits << (FLOAT_EXP_OFFSET - i)) & FLOAT_MANTISS_MASK;

	f |= FLOAT_SIGNBIT * (_raw_bits < 0);

	bool is_zero = !!_raw_bits;
	f |= (((i - _fractinal_bits) + FLOAT_BIAS) << FLOAT_EXP_OFFSET) * is_zero;
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

bool  Fixed::operator <  (Fixed const& other) const { return this->_raw_bits < other._raw_bits; }
bool  Fixed::operator <= (Fixed const& other) const { return this->_raw_bits <= other._raw_bits; }
bool  Fixed::operator >  (Fixed const& other) const { return this->_raw_bits > other._raw_bits; }
bool  Fixed::operator >= (Fixed const& other) const { return this->_raw_bits >= other._raw_bits; }
bool  Fixed::operator == (Fixed const& other) const { return this->_raw_bits == other._raw_bits; }
bool  Fixed::operator != (Fixed const& other) const { return this->_raw_bits != other._raw_bits; }

Fixed  Fixed::operator + (Fixed const& other) const { return (Fixed(*this) += other); }
Fixed  Fixed::operator - (Fixed const& other) const { return (Fixed(*this) -= other); }
Fixed  Fixed::operator * (Fixed const& other) const { return (Fixed(*this) *= other); }
Fixed  Fixed::operator / (Fixed const& other) const { return (Fixed(*this) /= other); }

Fixed&  Fixed::operator += (Fixed const& other)
{
	this->_raw_bits += other._raw_bits;
	return *this;
}

Fixed&  Fixed::operator -= (Fixed const& other)
{
	this->_raw_bits -= other._raw_bits;
	return *this;
}

Fixed&  Fixed::operator *= (Fixed const& other)
{
	_raw_bits = ((db_raw_bits_t)_raw_bits * other._raw_bits) >> _fractinal_bits;
	return *this;
}

Fixed&  Fixed::operator /= (Fixed const& other)
{
	db_raw_bits_t db_raw_bits = _raw_bits;
	db_raw_bits <<= _fractinal_bits;
	db_raw_bits /= other._raw_bits;
	this->_raw_bits = db_raw_bits;
	return *this;
}

Fixed   Fixed::operator ++ (int)
{
	Fixed copy(*this);
	this->_raw_bits++;
	return copy;
}

Fixed&  Fixed::operator ++ ()
{
	this->_raw_bits++;
	return *this;
}

Fixed   Fixed::operator -- (int)
{
	Fixed copy(*this);
	this->_raw_bits++;
	return copy;
}

Fixed&  Fixed::operator -- ()
{
	this->_raw_bits++;
	return *this;
}

Fixed&       Fixed::max(Fixed& a, Fixed& b)
{
	return a > b ? a : b;
}

Fixed const& Fixed::max(Fixed const& a, Fixed const& b)
{
	return a > b ? a : b;
}

Fixed&       Fixed::min(Fixed& a, Fixed& b)
{
	return a < b ? a : b;
}

Fixed const& Fixed::min(Fixed const& a, Fixed const& b)
{
	return a < b ? a : b;
}
