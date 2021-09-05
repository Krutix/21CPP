#include "Fixed.hpp"

#define FLOAT_BIAS				127
#define FLOAT_EXP_OFFSET		23
#define FLOAT_MANTISS_INVBIT	(1 << FLOAT_EXP_OFFSET)
#define FLOAT_MANTISS_MASK		((1 << FLOAT_EXP_OFFSET) - 1)
#define FLOAT_EXP_SIZE			8
#define FLOAT_EXP_MASK			(((1 << FLOAT_EXP_SIZE) - 1) << FLOAT_EXP_OFFSET)
#define FLOAT_SIGNBIT			(1 << 31)
#define INT_BIT_SIZE			(sizeof(int) * 8)

template<size_t Frac_Bits>
Fixed<Frac_Bits>::Fixed() : _raw_bits(0) {}

template<size_t Frac_Bits>
Fixed<Frac_Bits>::Fixed(float num)
{
	float abs_num = std::abs(num);
	_raw_bits = static_cast<int>(abs_num) << Frac_Bits;

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
	frac_raw_bits >>= FLOAT_EXP_OFFSET - Frac_Bits;
	frac_raw_bits &= (1 << Frac_Bits) - 1;
	_raw_bits |= frac_raw_bits;
	_raw_bits *= 1 - (num < 0) * 2;
}

template<size_t Frac_Bits>
Fixed<Frac_Bits>::Fixed(int num)
	: _raw_bits(num << Frac_Bits) {}

template<size_t Frac_Bits>
Fixed<Frac_Bits>::Fixed(Fixed<Frac_Bits> const& other)
	: _raw_bits(other._raw_bits) {}

template<size_t Frac_Bits>
template<size_t Other_Frac_Bits>
Fixed<Frac_Bits>::Fixed(Fixed<Other_Frac_Bits> const& other)
{
    if (Frac_Bits > Other_Frac_Bits)
        _raw_bits = other.getRawBits() << (Frac_Bits - Other_Frac_Bits);
    else
        _raw_bits = other.getRawBits() >> (Other_Frac_Bits - Frac_Bits);
}

template<size_t Frac_Bits>
Fixed<Frac_Bits>& Fixed<Frac_Bits>::operator=(Fixed<Frac_Bits> const& other)
{
	if (this == &other)
		return *this;
	_raw_bits = other._raw_bits;
	return (*this);
}

template<size_t Frac_Bits>
float Fixed<Frac_Bits>::toFloat() const
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
	f |= (((i - Frac_Bits) + FLOAT_BIAS) << FLOAT_EXP_OFFSET) * is_zero;
	return reinterpret_cast<float&>(f);
}

template<size_t Frac_Bits>
int Fixed<Frac_Bits>::toInt() const
{
	return (roundf(this->toFloat()));
}

template<size_t Frac_Bits>
Fixed<Frac_Bits>::~Fixed() {}

template<size_t Frac_Bits>
std::ostream& operator<< (std::ostream& os, Fixed<Frac_Bits> const& fixed)
{
	return os << fixed.toFloat();
}

template<size_t Frac_Bits>
bool  Fixed<Frac_Bits>::operator <  (Fixed<Frac_Bits> const& other) const { return this->_raw_bits < other._raw_bits; }
template<size_t Frac_Bits>
bool  Fixed<Frac_Bits>::operator <= (Fixed<Frac_Bits> const& other) const { return this->_raw_bits <= other._raw_bits; }
template<size_t Frac_Bits>
bool  Fixed<Frac_Bits>::operator >  (Fixed<Frac_Bits> const& other) const { return this->_raw_bits > other._raw_bits; }
template<size_t Frac_Bits>
bool  Fixed<Frac_Bits>::operator >= (Fixed<Frac_Bits> const& other) const { return this->_raw_bits >= other._raw_bits; }
template<size_t Frac_Bits>
bool  Fixed<Frac_Bits>::operator == (Fixed<Frac_Bits> const& other) const { return this->_raw_bits == other._raw_bits; }
template<size_t Frac_Bits>
bool  Fixed<Frac_Bits>::operator != (Fixed<Frac_Bits> const& other) const { return this->_raw_bits != other._raw_bits; }

template<size_t Frac_Bits>
Fixed<Frac_Bits>  Fixed<Frac_Bits>::operator + (Fixed<Frac_Bits> const& other) const { return (Fixed<Frac_Bits>(*this) += other); }
template<size_t Frac_Bits>
Fixed<Frac_Bits>  Fixed<Frac_Bits>::operator - (Fixed<Frac_Bits> const& other) const { return (Fixed<Frac_Bits>(*this) -= other); }
template<size_t Frac_Bits>
Fixed<Frac_Bits>  Fixed<Frac_Bits>::operator * (Fixed<Frac_Bits> const& other) const { return (Fixed<Frac_Bits>(*this) *= other); }
template<size_t Frac_Bits>
Fixed<Frac_Bits>  Fixed<Frac_Bits>::operator / (Fixed<Frac_Bits> const& other) const { return (Fixed<Frac_Bits>(*this) /= other); }

template<size_t Frac_Bits>
Fixed<Frac_Bits>&  Fixed<Frac_Bits>::operator += (Fixed<Frac_Bits> const& other)
{
	this->_raw_bits += other._raw_bits;
	return *this;
}

template<size_t Frac_Bits>
Fixed<Frac_Bits>&  Fixed<Frac_Bits>::operator -= (Fixed<Frac_Bits> const& other)
{
	this->_raw_bits -= other._raw_bits;
	return *this;
}

template<size_t Frac_Bits>
Fixed<Frac_Bits>&  Fixed<Frac_Bits>::operator *= (Fixed<Frac_Bits> const& other)
{
	_raw_bits = ((db_raw_bits_t)_raw_bits * other._raw_bits) >> Frac_Bits;
	return *this;
}

template<size_t Frac_Bits>
Fixed<Frac_Bits>&  Fixed<Frac_Bits>::operator /= (Fixed<Frac_Bits> const& other)
{
	db_raw_bits_t db_raw_bits = _raw_bits;
	db_raw_bits <<= Frac_Bits;
	db_raw_bits /= other._raw_bits;
	this->_raw_bits = db_raw_bits;
	return *this;
}

template<size_t Frac_Bits>
Fixed<Frac_Bits>   Fixed<Frac_Bits>::operator ++ (int)
{
	Fixed copy(*this);
	this->_raw_bits++;
	return copy;
}

template<size_t Frac_Bits>
Fixed<Frac_Bits>&  Fixed<Frac_Bits>::operator ++ ()
{
	this->_raw_bits++;
	return *this;
}

template<size_t Frac_Bits>
Fixed<Frac_Bits>   Fixed<Frac_Bits>::operator -- (int)
{
	Fixed copy(*this);
	this->_raw_bits++;
	return copy;
}

template<size_t Frac_Bits>
Fixed<Frac_Bits>&  Fixed<Frac_Bits>::operator -- ()
{
	this->_raw_bits++;
	return *this;
}

template<size_t Frac_Bits>
Fixed<Frac_Bits>&       Fixed<Frac_Bits>::max(Fixed<Frac_Bits>& a, Fixed<Frac_Bits>& b)
{
	return a > b ? a : b;
}

template<size_t Frac_Bits>
Fixed<Frac_Bits> const& Fixed<Frac_Bits>::max(Fixed<Frac_Bits> const& a, Fixed<Frac_Bits> const& b)
{
	return a > b ? a : b;
}

template<size_t Frac_Bits>
Fixed<Frac_Bits>&       Fixed<Frac_Bits>::min(Fixed<Frac_Bits>& a, Fixed<Frac_Bits>& b)
{
	return a < b ? a : b;
}

template<size_t Frac_Bits>
Fixed<Frac_Bits> const& Fixed<Frac_Bits>::min(Fixed<Frac_Bits> const& a, Fixed<Frac_Bits> const& b)
{
	return a < b ? a : b;
}

#undef FLOAT_BIAS
#undef FLOAT_EXP_OFFSET
#undef FLOAT_MANTISS_INVBIT
#undef FLOAT_MANTISS_MASK
#undef FLOAT_EXP_SIZE
#undef FLOAT_EXP_MASK
#undef FLOAT_SIGNBIT
#undef INT_BIT_SIZE
