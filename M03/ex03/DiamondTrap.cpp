#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name", 100, 50, 30),
											ScavTrap(name), FragTrap(name), name(name)
{
	std::cout << "DiamondTrap name constructor called" << std::endl;
	// std::cout << "energy: " << energy << " hit points: " << hit_points << 
	// 	" attack damage: " << attack_damage << std::endl;
}

DiamondTrap::DiamondTrap(): ClapTrap("_clap_name", 100, 50, 30)
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other.name + "_clap_name"), ScavTrap(other.name), FragTrap(other.name)  {
	*this = other;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &cp) {
	if (this == &cp)
		return *this;	
	name = cp.name;
	hit_points = cp.hit_points;
	energy = cp.energy;
	attack_damage = cp.attack_damage;
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