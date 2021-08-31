#include <iostream>
#include <assert.h>
#include "Point.hpp"

bool bsp(Point t1, Point t2, Point t3, Point pt);

void test_template()
{
	Fixed<> a(10.25f);
	Fixed<1> b(a);
	assert((a + b) == 20.25f);
	assert(a != b);
	assert(a > b);
	assert(b == a);
}

int main()
{
	test_template();
	Point triangle[] = { Point(1.f, 1.f), Point(0.f, 0.f), Point(2.f, 0.f) };
	Point points[] = { Point(1.f, 1.f), Point(1.1f, 1.f) };
	bool  expected[] = { 1, 0 };
	assert(sizeof(expected) / sizeof(expected[0]) == sizeof(points) / sizeof(points[0]));
	size_t points_size = sizeof(points) / sizeof(points[0]);
	for (size_t i = 0; i < points_size; i++)
		assert(bsp(triangle[0], triangle[1], triangle[2],
				points[i]) == expected[i]);
}
