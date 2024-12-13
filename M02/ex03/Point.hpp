#ifndef __POINT_HPP__
# define __POINT_HPP__

#include <string>
#include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &other);
		Point& operator=(const Point &cp);
		~Point();
	private:
		Fixed _x;
		Fixed _y;
};

#endif