#include "AMateria.hpp"
#include <iostream>
#include <string>

AMateria::AMateria(void) {
	
}

AMateria::AMateria(std::string const &type): type(type)
{

}

std::string const &AMateria::getType() const
{
	return type;
}
		
		
void	 AMateria::use(ICharacter &target)
{
	(void)target;	
}

AMateria::AMateria(const AMateria &other) {
	(void)other;	
}

AMateria& AMateria::operator=(const AMateria &cp) {
	(void)cp;	
	return *this;
}

AMateria::~AMateria(void) {
	
}