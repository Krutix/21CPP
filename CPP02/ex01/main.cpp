#include <iostream>
#include "Fixed.hpp"

int main()
{
    Fixed a(3.5f);
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    Fixed const g( 0.42f );
    Fixed const z( 0.f );
    a = Fixed( 1234.4321f );
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "g is " << g << std::endl;
    std::cout << "z is " << z << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    std::cout << "g is " << g.toInt() << " as integer" << std::endl;
    std::cout << "z is " << z.toInt() << " as integer" << std::endl;
    return 0;
}