#include "Point.hpp"
#include <iostream>

int main()
{
	Point a(10, 1);
	Point b(50, 2);
	Point c(0, 21);
	Point p(15,3);
	Point p2(999,999);

	std::cout << "a(" << a.x() << ", " << a.y() << ")" << std::endl; 
	std::cout << "b(" << b.x() << ", " << b.y() << ")" << std::endl; 
	std::cout << "c(" << c.x() << ", " << c.y() << ")" << std::endl; 

	std::cout << "p(" << p.x() << ", " << p.y() << ")" << std::endl; 
	std::cout << "p2(" << p2.x() << ", " << p2.y() << ")" << std::endl; 

	if(bsp(a, b, c, p))
		std::cout << "point p is in triangle" << std::endl;
	else
		std::cout << "point p is not in triangle" << std::endl;

	if(bsp(a, b, c, p2))
		std::cout << "point p2 is in triangle" << std::endl;
	else
		std::cout << "point p2 is not in triangle" << std::endl;
	return 0;
}