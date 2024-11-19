#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string const &name, Weapon &weapon): _name(name), _weapon(weapon)
{
}

void	HumanA::attack( void ) const
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}