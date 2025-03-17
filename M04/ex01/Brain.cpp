#include "Brain.hpp"
#include <iostream>

Brain::Brain(void) {
	std::cout << "Someone gained a Brain" << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cout << "a Brain has cloned." << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain &cp) {
	if (this == &cp)
		return *this;	
	for (int i = 0; i < 99; i++)
		this->ideas[i] = cp.ideas[i];
	return *this;
}

Brain::~Brain(void) {
	std::cout << "Someone lost a Brain" << std::endl;
}