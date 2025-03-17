#include "Cat.hpp"
#include <iostream>

Cat::Cat(void): AAnimal("Cat") {
	std::cout << "A new cat appeared" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat &other): AAnimal("Cat") {
	std::cout << "A cloned cat appeared" << std::endl;
	this->brain = new Brain();
	*this = other;	
}

Cat& Cat::operator=(const Cat &cp) {
	if (this == &cp)
		return *this;
	this->type = cp.type;
	*this->brain = *cp.brain;
	return *this;
}

Brain * Cat::getBrain() const
{
	return brain;
}

void	Cat::makeSound() const
{
	std::cout << "Cat says miaw" << std::endl;
}

Cat::~Cat(void) {
	delete this->brain;
	std::cout << "a Cat disappeared" << std::endl;
}