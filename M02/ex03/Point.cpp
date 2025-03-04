#include "Point.hpp"
#include <iostream>
#include <string>

Point::Point(void): _x(0), _y(0) {
}

Point::Point(const float x, const float y): _x(x), _y(y)
{
}

Point::Point(Point &cp)
{
	*this = cp;
}

Point &Point::operator=(Point &cp)
{
	(void)cp;
	*((Fixed *) &this->_x) = cp._x;
	*((Fixed *) &this->_y) = cp._y;
	return *this;
}

float Point::x() const
{
	return this->_x.toFloat();
}

float Point::y() const
{
	return this->_y.toFloat();
}

Point::~Point(void) {
}