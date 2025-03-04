#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_pointPos = 8;

Fixed::Fixed(void): _value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

bool	Fixed::operator!=(Fixed const &fx)
{
	return this->toFloat() != fx.toFloat();
}

bool	Fixed::operator<(Fixed const &fx)
{
	return this->toFloat() < fx.toFloat();
}

bool	Fixed::operator>(Fixed const &fx)
{
	return this->toFloat() > fx.toFloat();
}

Fixed	const &Fixed::max(Fixed const &fx1, Fixed const &fx2)
{
	if ((Fixed) fx1 > fx2)
		return fx1;
	return fx2;
}

Fixed &Fixed::max(Fixed &fx1, Fixed &fx2)
{
	if (fx1 > fx2)
		return fx1;
	return fx2;
}

Fixed const &Fixed::min(Fixed const &fx1, Fixed const &fx2)
{
	if ((Fixed) fx1 < fx2)
		return fx1;
	return fx2;
}

Fixed &Fixed::min(Fixed &fx1, Fixed &fx2)
{
	if (fx1 < fx2)
		return fx1;
	return fx2;
}

bool	Fixed::operator<=(Fixed const &fx)
{
	return this->toFloat() <= fx.toFloat();
}

bool	Fixed::operator>=(Fixed const &fx)
{
	return this->toFloat() >= fx.toFloat();
}

bool	Fixed::operator==(Fixed const &fx)
{
	return this->toFloat() == fx.toFloat();
}

Fixed	Fixed::operator*(Fixed const &fx)
{
	return Fixed(this->toFloat() * fx.toFloat());
}

Fixed	Fixed::operator+(Fixed const &fx)
{
	return Fixed(this->toFloat() + fx.toFloat());
}

Fixed	Fixed::operator-(Fixed const &fx)
{
	return Fixed(this->toFloat() - fx.toFloat());
}

Fixed	Fixed::operator/(Fixed const &fx)
{
	return Fixed(this->toFloat() / fx.toFloat());
}

float	Fixed::operator++(int)
{
	float	tmp;
	tmp = this->toFloat();
	this->_value++;
	return tmp;
}

float	Fixed::operator++()
{
	this->_value++;
	return this->toFloat();
}

float	Fixed::operator--(int)
{
	float	tmp;
	tmp = this->toFloat();
	this->_value--;
	return tmp;
}

float	Fixed::operator--()
{
	this->_value--;
	return this->toFloat();
}

Fixed::Fixed(const Fixed &fx)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = fx;
}

Fixed::Fixed(const int i)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_value = i << Fixed::_pointPos;
}

Fixed::Fixed(const float f)
{
	int	e = 1 << Fixed::_pointPos;
	// std::cout << "Float constructor called" << std::endl;
	this->_value = (int) roundf((f * e));
}

int	Fixed::toInt(void) const
{
	return this->_value >> Fixed::_pointPos;
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
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_value = fx.getRawBits();
	return *this;
}

void	Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}