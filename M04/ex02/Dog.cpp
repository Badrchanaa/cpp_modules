#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog(void): Animal("Dog") {
	std::cout << "A new Dog appeared" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog &other): Animal("Dog") {
	std::cout << "A cloned Dog appeared" << std::endl;
	this->brain = new Brain();
	*this = other;	
}

Dog& Dog::operator=(const Dog &cp) {
	if (this == &cp)	
		return *this;	
	this->type = cp.type;
	*this->brain = *cp.brain;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog says Woof Woof" << std::endl;
}

Brain * Dog::getBrain() const
{
	return brain;
}
Dog::~Dog(void) {
	delete this->brain;
	std::cout << "A Dog went missing" << std::endl;
}