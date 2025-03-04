#include "WrongCat.hpp"
#include <iostream>
#include <string>

WrongCat::WrongCat(void): WrongAnimal("Cat") {
		
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal("Cat") {
	*this = other;	
}

WrongCat& WrongCat::operator=(const WrongCat &cp) {
	if (this == &cp)
		return *this;
	this->type = cp.type;
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "Cat says miaw" << std::endl;
}

WrongCat::~WrongCat(void) {
	
}