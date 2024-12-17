#include "Point.hpp"
#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	// Check if points form a valid triangle ??
	(void)point;
	// point is a vertex
	float area = a.x() * (b.y() - c.y()) + b.x() * (c.y() - a.y()) + c.x() * (a.y() - b.y());
	// not a valid triangle
	std::cout << "a(" << a.x() << ", " << a.y() << ")" << std::endl; 
	std::cout << "b(" << b.x() << ", " << b.y() << ")" << std::endl; 
	std::cout << "c(" << c.x() << ", " << c.y() << ")" << std::endl; 
	if (area == 0)
	{
		std::cout << "not a valid triangle" << std::endl;
		return false;
	}
	else
		std::cout << "valid triangle (area = " << area << ")" << std::endl;
	return false;
}