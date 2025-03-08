#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap(std::string name): ClapTrap(name, 100, 100, 30) {
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(): ClapTrap("", 100, 100, 30) {
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &cp) {
	if (this == &cp)
		return *this;	
	name = cp.name;
	hit_points = cp.hit_points;
	energy = cp.energy;
	attack_damage = cp.attack_damage;
	return *this;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " is requesting a high five." << std::endl;
}

FragTrap::~FragTrap(void) {
	
	std::cout << "FragTrap destructor called" << std::endl;
}