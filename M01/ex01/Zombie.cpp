#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void)
{
}

void	Zombie::setName(std::string const name)
{
	this->_name = name;
}

Zombie::Zombie(std::string name): _name(name)
{
}

void	Zombie::announce(void)
{
	std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " has been deleted." << std::endl;
}