#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <limits.h>

ScalarConverter::ScalarConverter()
{
}

bool	ScalarConverter::_isalpha(char c)
{
	return (c  >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool	ScalarConverter::_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

bool	ScalarConverter::_validate(std::string literal)
{
	if (literal.length() == 1)
		return true;
	if (literal[0] == '+' || literal[0] == '-')
		literal.erase(0, 1);
	if (literal[literal.length() - 1] == 'f')
		literal.erase(literal.length() - 1, 1);
	if (literal.find('.') != literal.rfind('.'))
		return false;
	return (literal.find_first_not_of("0123456789.") == std::string::npos);
}

void	ScalarConverter::_printInt(double num)
{
	std::cout << "int: ";
	if (std::isnan(num) || std::isinf(num) || num > INT_MAX || num < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(num) << std::endl;
}

void	ScalarConverter::_printFloat(double num)
{
	std::cout << "float: "  << static_cast<float>(num);
	std::cout << "f" << std::endl;
}

void	ScalarConverter::_printChar(double num)
{
	std::cout << "char: "; 
	if (std::isnan(num) || std::isinf(num) || num > 255 || num < 0)
		std::cout << "impossible" << std::endl;
	else if (isprint(static_cast<int>(num)))
		std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void	ScalarConverter::convert(std::string literal)
{
	int		i;
	double	d;

	if (literal.length() == 1 && !ScalarConverter::_isdigit(literal[0]))
		d = static_cast<double>(literal[0]);
	else
	{
		char *end;
		const char *str = literal.c_str();
		d = std::strtod(str, &end);
		if (*end == 'f' || *end == 'F')
			end++;
		if (*end)
		{
			std::cout << "please enter a valid number or character" << std::endl;
			return;
		}
	}
	if (!std::isnan(d) && !std::isinf(d) && !ScalarConverter::_validate(literal))
	{
		std::cout << "please enter a valid number or character" << std::endl;
		return ;
	}

	i = static_cast<int>(d);
	if (d == static_cast<double>(i))
		std::cout << std::fixed << std::setprecision(1);
	ScalarConverter::_printChar(d);
	ScalarConverter::_printInt(d);
	ScalarConverter::_printFloat(d);
	std::cout << "double: "  << d << std::endl;
}