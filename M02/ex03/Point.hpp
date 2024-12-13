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
		bool	operator==(const Point &point);
		~Point();
	private:
		const Fixed _x;
		const Fixed _y;
};

#endif