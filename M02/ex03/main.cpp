#include "Point.hpp"
#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	Fixed f(50);
	Point a(0, 1);
	Point b(5, 2);
	Point c(0, 21);
	Point p(0, 5);
	bsp(a, b, c, p);
	std::cout << "f = " << f.toFloat() << std::endl;

	return 0;
}