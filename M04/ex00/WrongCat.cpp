#include "WrongCat.hpp"
#include <iostream>
#include <string>

WrongCat::WrongCat(void): WrongAnimal("WrongCat") {
	std::cout << "A WrongCat has appeared" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal("WrongCat") {
	std::cout << "A cloned WrongCat has appeared" << std::endl;
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
	std::cout << "a WrongCat disappeared."	<< std::endl;
}