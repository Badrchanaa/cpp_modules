#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog(void): Animal("Dog") {
	std::cout << "A new Dog appeared" << std::endl;
}

Dog::Dog(const Dog &other): Animal("Dog") {
	*this = other;	
}

Dog& Dog::operator=(const Dog &cp) {
	if (this == &cp)	
		return *this;	
	this->type = cp.type;
	return *this;
}
void Dog::makeSound() const
{
	std::cout << "Dog says Woof Woof" << std::endl;
}

Dog::~Dog(void) {
	std::cout << "A Dog went missing" << std::endl;
}