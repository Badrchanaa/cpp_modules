#include "Point.hpp"
#include <iostream>

float	ft_abs(float x)
{
	if (x < 0)
		return -x;
	return x;
}

// calculates and returns the area of the triangle formed by the points a, b, and c
static float	calcArea(Point const &a, Point const &b, Point const &c)
{
	return (0.5 * ft_abs(a.x() * (b.y() - c.y()) + b.x() * (c.y() - a.y()) + c.x() * (a.y() - b.y())));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	abcArea = calcArea(a, b, c);
	float	abpArea = calcArea(a, b, point);
	float 	apcArea = calcArea(a, point, c);
	float	bpcArea = calcArea(b, point ,c);

	if (abcArea == 0)
	{
		std::cout << "ABC does not form a valid triangle" << std::endl;
		return false;
	}
	return (abcArea >= (abpArea + apcArea + bpcArea));
}