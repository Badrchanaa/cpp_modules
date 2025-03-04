#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name", 100, 50, 30), 
											ScavTrap(name), FragTrap(name), name(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	std::cout << "energy: " << energy << " hit points: " << hit_points << 
		" attack damage: " << attack_damage << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)  {
	*this = other;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &cp) {
	if (this == &cp)
		return *this;	
	name = cp.name;
	hit_points = cp.FragTrap::hit_points;
	energy = cp.ScavTrap::energy;
	attack_damage = cp.FragTrap::attack_damage;
	return *this;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "name: " << this->name << std::endl;
	std::cout << "claptrap name: " << this->ClapTrap::name << std::endl;
}

// void	attack()
// {
// }

DiamondTrap::~DiamondTrap(void) {
	
	std::cout << "DiamondTrap destructor called" << std::endl;
}