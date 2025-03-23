#include "Data.hpp"
#include <iostream>
#include <string>

Data::Data(void): num(0), str("")
{
}

Data::Data(std::string str, unsigned int num): num(num), str(str)
{
}

Data::Data(const Data &other): num(other.num), str(other.str)
{
	(void)other;
}

Data& Data::operator=(const Data &other)
{
	num = other.num;
	str = other.str;	
	return *this;
}

Data::~Data(void)
{
}