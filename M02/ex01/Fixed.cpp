#include "Fixed.hpp"
#include <iostream>
#include <cmath>

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

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = i << this->_pointPos;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = (int) roundf((f * (1 << this->_pointPos)));
}

int	Fixed::toInt(void) const
{
	return this->_value >> 8;
}

float	Fixed::toFloat(void) const
{
	float f;
	int	e = 1 << this->_pointPos;
	f = (float) this->_value / e;
	return (f);
}

int	Fixed::getRawBits( void ) const
{
	return this->_value;
}
 
std::ostream &operator<<(std::ostream &os, const Fixed &fx)
{
	float f = fx.toFloat();	
	return os << f;
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