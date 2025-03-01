#include "ScavTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 50, 20) {
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &cp) {
	if (this == &cp)
		return *this;	
	name = cp.name;
	hit_points = cp.hit_points;
	energy = cp.energy;
	attack_damage = cp.attack_damage;
	return *this;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in gate keeper mode." << std::endl;
}

ScavTrap::~ScavTrap(void) {
	
	std::cout << "ScavTrap destructor called" << std::endl;
}