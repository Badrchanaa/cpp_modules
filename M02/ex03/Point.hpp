#ifndef __POINT_HPP__
# define __POINT_HPP__
#include "Fixed.hpp"

#include <string>


class Point
{
	public:
		Point(void);
		Point(const float x, const float y);
		Point(Point &cp);
		Point &operator=(Point &cp);
		float	x() const;
		float	y() const;
		~Point();
	private:
		const Fixed _x;
		const Fixed _y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif