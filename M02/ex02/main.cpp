#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	if (Fixed(2) > Fixed(1))
		std::cout << "Fixed(2) > Fixed(1)" << std::endl;
	if (Fixed(1) < Fixed(2))
		std::cout << "Fixed(1) < Fixed(2)" << std::endl;
	if (Fixed(2) == Fixed(2))
		std::cout << "Fixed(2) == Fixed(2)" << std::endl;
	if (Fixed(2) != Fixed(1))
		std::cout << "Fixed(2) != Fixed(1)" << std::endl;
	if (Fixed(2) >= Fixed(2))
		std::cout << "Fixed(2) >= Fixed(2)" << std::endl;
	if (Fixed(2) <= Fixed(2))
		std::cout << "Fixed(2) <= Fixed(2)" << std::endl;
	Fixed x;
	x = Fixed(2) + Fixed(1);
	std::cout << "Fixed(2) + Fixed(1)" << " = " << x << std::endl;
	x = Fixed(2) - Fixed(1);
	std::cout << "Fixed(2) - Fixed(1)" << " = " << x << std::endl;
	x = Fixed(2) * Fixed(3);
	std::cout << "Fixed(2) * Fixed(3)" << " = " << x << std::endl;
	x = Fixed(4) / Fixed(2);
	std::cout << "Fixed(4) / Fixed(2)" << " = " << x << std::endl;
	std::cout << "min(4, 2) = " << Fixed::min(Fixed(4), Fixed(2)) << std::endl;
	std::cout << "max(4, 2) = " << Fixed::max(Fixed(4), Fixed(2)) << std::endl;
	return 0;
}