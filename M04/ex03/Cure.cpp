#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

Cure::Cure(void): AMateria("cure")
{
	
}

Cure::Cure(const Cure &other): AMateria("cure")
{
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

std::string const &Cure::getType() const
{
	return type;
}

Cure::~Cure(void)
{
	
}