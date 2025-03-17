#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(void) {
	// std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type): type(type)
{
	// std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other) {
	// std::cout << "AMateria copy constructor called" << std::endl;
	(void)other;	
}

AMateria& AMateria::operator=(const AMateria &cp) {
	(void)cp;	
	return *this;
}

std::string const &AMateria::getType() const
{
	return type;
}
		
void	 AMateria::use(ICharacter &target)
{
	(void)target;	
}

AMateria::~AMateria(void) {
	// std::cout << "AMateria destructor called" << std::endl;
}