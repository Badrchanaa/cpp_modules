#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

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

void	ScalarConverter::convert(std::string literal)
{
	if (!ScalarConverter::_validate(literal))
	{
		std::cout << "please enter a valid literal" << std::endl;
		return;
	}
	double d = std::strtod(literal.c_str(), NULL);
	if (literal.length() == 1 && !ScalarConverter::_isdigit(literal[0]))
	{
		// is a character literal
		return;
	}
	std::cout << "char: " << static_cast<char>(d) << std::endl;
	std::cout << "int: ";
	if (std::isnan(d) || std::isinf(d))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
	std::cout << "float: " << std::strtof(literal.c_str(), NULL) << std::endl;
	std::cout << "double: "  << d << std::endl;
}