#include "Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal(void) {
	std::cout << "A new Animal appeared" << std::endl;
}

Animal::Animal(const std::string &type): type(type) {
	std::cout << "A new Animal appeared of type: " << type << std::endl;
}

Animal::Animal(const Animal &other) {
	std::cout << "A cloned Animal appeared" << std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal &cp) {
	if (this == &cp)
		return *this;
	this->type = cp.type;
	return *this;
}

std::string Animal::getType() const
{
	return this->type;
}

// void	Animal::makeSound() const
// {
// 	std::cout << "(Animal sound)" << std::endl;
// }

Animal::~Animal(void) {
	std::cout << "An Animal went missing" << std::endl;
}