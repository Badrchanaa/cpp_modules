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
	this->_value = i << 8;
}

unsigned char	floatToFixed(float frac)
{
	unsigned char uc;
	float	n;
	n = 0;
	int i = 1;
	uc = 0;
	while (i <= 8)
	{
		float t = (float)1 / (2 * i);
		if ((n + t) > frac)
		{
			i++;
			continue;
		}
		else
		{
			uc |= (128 >> (i - 1));
			n += t;
		}
		i++;
	}
	return uc;
}

float	fixedToFloat(int val)
{
	float f;
	f = 0;
	unsigned char fixed;
	fixed = val & 255;
	int i = 1;
	while (i <= 8)
	{
		if (fixed & (128 >> (i - 1)))
			f += (float)1 / (2 * i);
		i++;
	}
	return f;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	float rounded = roundf(f);
	this->_value = ((int) rounded) << 8;
	float ff = f - rounded;
	// int i = 0;
	// while (i < Fixed::_pointPos && ff > roundf(ff))
	// {
	// 	std::cout << ff << " > " << roundf(ff) << std::endl;
	// 	ff *= 10;
	// 	i++;
	// }
	// std::cout << "float " << ff << std::endl;
	this->_value |= floatToFixed(ff);
}

int	Fixed::toInt(void) const
{
	// return this->_value;
	return this->_value >> 8;
}

float	Fixed::toFloat(void) const
{
	float f;
	f = this->_value >> 8;
	f += fixedToFloat(this->_value);
	return (f);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
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