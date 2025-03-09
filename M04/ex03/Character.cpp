#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <iostream>
#include <string>

Character::Character(void) {
	std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string const &name): name(name)
{
	std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
		this->inventory[i] = NULL;
}

Character::Character(const Character &other) {
	std::cout << "Character copy constructor called" << std::endl;
	*this = other;	
}

Character& Character::operator=(const Character &cp) {
	if (this == &cp)
		return *this;
	this->name = cp.name;
	AMateria*	tmp;
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		delete inventory[i];
		inventory[i] = NULL;
		tmp = cp.inventory[i];
		if (!tmp)
			continue;	
		if (tmp->getType() == "cure")
			inventory[i] = new Cure();
		else if (tmp->getType() == "ice")
			inventory[i] = new Ice();
		else
			continue;
		*inventory[i] = *tmp;// 
	}
	return *this;
}

void Character::equip(AMateria* m)
{
	int	i;

	i = 0;
	while (i < INVENTORY_SIZE && inventory[i])
		i++;
	if (i < INVENTORY_SIZE)
		inventory[i] = m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= INVENTORY_SIZE || !inventory[idx])
		return;
	inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= INVENTORY_SIZE || !inventory[idx])
		return;
	inventory[idx]->use(target);
}

std::string const & Character::getName() const
{
	return name;
}

Character::~Character(void) {
	std::cout << "Character destructor called" << std::endl;
	for(int i = 0; i < INVENTORY_SIZE; i++)
		delete inventory[i];
}