#ifndef __MATERIASOURCE_HPP__
# define __MATERIASOURCE_HPP__

# define MS_INVENTORY_SIZE 4

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <string>

class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &other);

		MateriaSource&		operator=(const MateriaSource &cp);
		void				learnMateria(AMateria*);
		AMateria*			createMateria(std::string const & type);
		AMateria*			getMateria(int idx) const;

		~MateriaSource();
	private:
		AMateria*	inventory[MS_INVENTORY_SIZE];
};

#endif