#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	// Check if points form a valid triangle ??

	// point is a vertex
	if (point == a || point == b || point == c)
		return false;
	return false;
}