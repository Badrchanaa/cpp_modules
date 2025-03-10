#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

Ice::Ice(void): AMateria("ice")
{
	// std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &other): AMateria("ice")
{
	// std::cout << "Ice copy constructor called" << std::endl;
	*this = other;	
}

Ice& Ice::operator=(const Ice &cp)
{
	(void)cp;
	return *this;
}

AMateria* Ice::clone() const
{
	AMateria	*newClone = new Ice();

	*newClone = *this;
	return newClone;
}

void	 Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice(void)
{
	// std::cout << "Ice destructor called" << std::endl;
}