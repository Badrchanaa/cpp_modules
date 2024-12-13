#include "Point.hpp"
#include <iostream>
#include <string>

Point::Point(void) {
	this->_x = Fixed(0);
	this->_y = Fixed(0);
}

Point::Point(const Point &cp) {
	*this = cp;
}

Point& Point::operator=(const Point &cp) {
	this->_x = cp._x;
	this->_y = cp._y;	
}

Point::Point(const float x, const float y)
{
	this->_x = Fixed(x);
	this->_y = Fixed(y);
}

Point::~Point(void) {
}