#include "Point.hpp"

namespace {

Fixed<> sign(Point p1, Point p2, Point p3)
{
	return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY())
		- (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

}

bool bsp(Point t1, Point t2, Point t3, Point pt)
{
	Fixed<> d1, d2, d3;
	bool has_neg, has_pos;

	d1 = sign(pt, t1, t2);
	d2 = sign(pt, t2, t3);
	d3 = sign(pt, t3, t1);

	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);
}
