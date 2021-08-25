#pragma once
#include "Fixed.hpp"

class Point
{
public:
	Point()
		: _x(0), _y(0) {}
	Point(float x, float y)
		: _x(x), _y(y) {}

	Point(Point const& other)
		: _x(other._x), _y(other._y) {}

	Point& operator = (Point const& other)
	{
		const_cast<Fixed&>(_x) = other._x;
		const_cast<Fixed&>(_y) = other._y;
		return *this;
	}

	~Point() {}

	Fixed const& getX() const { return _x; }
	Fixed const& getY() const { return _y; }

	void setX(Fixed const& a) { const_cast<Fixed&>(_x) = a; }
	void setY(Fixed const& a) { const_cast<Fixed&>(_y) = a; }

private:
	Fixed const _x;
	Fixed const _y;
};
