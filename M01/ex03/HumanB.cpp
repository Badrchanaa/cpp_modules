#include "HumanB.hpp"
#include "Weapon.hpp"

#include <iostream>

HumanB::HumanB(std::string const &name): _name(name), _weapon(NULL)
{
}

void	HumanB::attack( void ) const
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon const &wp)
{
	this->_weapon = &wp;
}