#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>
#include <string>

MateriaSource::MateriaSource(void)
{
	// std::cout << "MateriaSource constructor called" << std::endl;
	for (int i = 0; i < MS_INVENTORY_SIZE; i++)	
	{
		inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	// std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = other;	
}
	
AMateria*	MateriaSource::getMateria(int idx) const
{
	if (idx < 0 || idx >= MS_INVENTORY_SIZE)
		return NULL;
	return inventory[idx];
}

MateriaSource& MateriaSource::operator=(const MateriaSource &cp)
{
	AMateria*	tmp;

	if (this == &cp)	
		return *this;
	for (int i = 0; i < MS_INVENTORY_SIZE; i++)
	{
		delete inventory[i];
		inventory[i] = NULL;
		tmp = cp.getMateria(i);
		if (!tmp)
			continue;	
		if (tmp->getType() == "cure")
			inventory[i] = new Cure();
		else if (tmp->getType() == "ice")
			inventory[i] = new Ice();
		else
			continue;
		*inventory[i] = *tmp;
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	int	i;

	i = 0;
	while (i < MS_INVENTORY_SIZE && inventory[i])
		i++;
	if (i < MS_INVENTORY_SIZE)
		inventory[i] = materia;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	AMateria	*materia;

	materia = NULL;
	if (type.empty())
		return NULL;
	for (int i = 0; i < MS_INVENTORY_SIZE; i++)
	{
		if (inventory[i] && inventory[i]->getType() == type)
		{
			if (type == "cure")
				materia = new Cure();
			else if (type == "ice")
				materia = new Ice();
			if (materia)
				*materia = *inventory[i];
			return materia;
		}
	}
	return NULL;
}

MateriaSource::~MateriaSource(void)
{
	// std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < MS_INVENTORY_SIZE; i++)
		delete inventory[i];
}