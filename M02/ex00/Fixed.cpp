#include "Fixed.hpp"
#include <iostream>

const int Fixed::_pointPos = 8;

Fixed::Fixed(void): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fx)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fx;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

Fixed	&Fixed::operator=(const Fixed &fx)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = fx.getRawBits();
	return *this;
}

void	Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}


Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}