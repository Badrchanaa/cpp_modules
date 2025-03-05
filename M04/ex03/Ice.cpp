#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

Ice::Ice(void): AMateria("ice")
{
}

Ice::Ice(const Ice &other): AMateria("ice")
{
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

std::string const &Ice::getType() const
{
	return type;
}

Ice::~Ice(void)
{
}