#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

Cure::Cure(void): AMateria("cure")
{
	// std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure &other): AMateria("cure")
{
	// std::cout << "Cure copy constructor called" << std::endl;
	*this = other;	
}

Cure& Cure::operator=(const Cure &cp)
{
	(void)cp;
	return *this;
}

AMateria* Cure::clone() const
{
	AMateria	*newClone = new Cure();

	*newClone = *this;
	return newClone;
}

void	 Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::~Cure(void)
{
	// std::cout << "Cure constructor called" << std::endl;
}