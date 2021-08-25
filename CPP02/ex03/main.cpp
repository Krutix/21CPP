#include <iostream>
#include "Point.hpp"

bool bsp(Point t1, Point t2, Point t3, Point pt);

int main()
{
	std::cout << bsp(Point(1.f, 1.f),
			Point(0.f, 0.f), Point(2.f, 0.f),
			Point(0.5f, 0.5f)) << std::endl;
	std::cout << bsp(Point(1.f, 1.f),
			Point(0.f, 0.f), Point(2.f, 0.f),
			Point(0.0f, 0.0f)) << std::endl;
	std::cout << bsp(Point(1.f, 1.f),
			Point(0.f, 0.f), Point(2.f, 0.f),
			Point(5.f, 5.0f)) << std::endl;
}
