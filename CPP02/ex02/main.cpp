#include <iostream>
#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	a = Fixed(0.5f);
	Fixed c(10);
	std::cout << a / c << std::endl;
	std::cout << a * c << std::endl;
	std::cout << c / a << std::endl;
	std::cout << c * a << std::endl;
	std::cout << c + a << std::endl;
	std::cout << c - a << std::endl;

	std::cout << c - c - c << std::endl;
	std::cout << c - c - a << std::endl;

	a = Fixed(0.5f);
	c = Fixed(-10);
	std::cout << c / a << std::endl;
	a = Fixed(-0.5f);
	c = Fixed(-10);
	std::cout << c / a << std::endl;
	a = Fixed(-0.5f);
	c = Fixed(-10);
	std::cout << c * a << std::endl;
	a = Fixed(-0.5f);
	c = Fixed(10);
	std::cout << c * a << std::endl;
}
