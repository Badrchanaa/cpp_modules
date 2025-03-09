#include "AAnimal.hpp"
#include <iostream>
#include <string>

AAnimal::AAnimal(void) {
	std::cout << "A new Animal appeared" << std::endl;
}

AAnimal::AAnimal(const std::string &type): type(type) {
	std::cout << "A new Animal appeared of type: " << type << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) {
	std::cout << "A cloned Animal appeared" << std::endl;
	*this = other;
}

AAnimal& AAnimal::operator=(const AAnimal &cp) {
	if (this == &cp)
		return *this;
	this->type = cp.type;
	return *this;
}

std::string AAnimal::getType() const
{
	return this->type;
}

// void	Animal::makeSound() const
// {
// 	std::cout << "(Animal sound)" << std::endl;
// }

AAnimal::~AAnimal(void) {
	std::cout << "An Animal went missing" << std::endl;
}