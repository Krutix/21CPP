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
	std::cout << "-a: " << a << std::endl;
	std::cout << "-c: " << c << std::endl;
	std::cout << c / a << std::endl;
	std::cout << c * a << std::endl;
	a = Fixed(-0.5f);
	c = Fixed(10);
	std::cout << c * a << std::endl;

	std::cout << Fixed(-2) << ' ' << Fixed(-2.f) << '\n';
	std::cout << Fixed(-1) << ' ' << Fixed(-1.f) << '\n';
	std::cout << Fixed(-.5f) << '\n';
	std::cout << Fixed(-10) << ' ' << Fixed(-10.f) << '\n';
	//TODO fix this shit
	std::cout << Fixed(-.42f) << '\n';
	std::cout << Fixed(.42f) << '\n';
	std::cout << Fixed(-42.42f) + 0.42f << '\n';
	std::cout << Fixed(-42.42f) - -0.42f << '\n';
}
