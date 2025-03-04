#include "Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat(void): Animal("Cat") {
	std::cout << "A new cat appeared" << std::endl;
}

Cat::Cat(const Cat &other): Animal("Cat") {
	std::cout << "A cloned cat appeared" << std::endl;
	*this = other;	
}

Cat& Cat::operator=(const Cat &cp) {
	if (this == &cp)
		return *this;
	this->type = cp.type;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Cat says miaw" << std::endl;
}

Cat::~Cat(void) {
	std::cout << "a Cat disappeared" << std::endl;
}