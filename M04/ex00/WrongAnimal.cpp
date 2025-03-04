#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal(void) {
	std::cout << "A new WrongAnimal appeared" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type): type(type) {
	std::cout << "A new WrongAnimal appeared of type: " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	std::cout << "A cloned WrongAnimal appeared" << std::endl;
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &cp) {
	if (this == &cp)
		return *this;
	this->type = cp.type;
	return *this;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "(WrongAnimal sound)" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "A WrongAnimal went missing" << std::endl;
}