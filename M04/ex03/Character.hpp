#ifndef __CHARACTER_HPP__
# define __CHARACTER_HPP__

# define INVENTORY_SIZE 4
# include "ICharacter.hpp"
# include <string>

class Character: public ICharacter
{
	public:
		Character(void);
		Character(std::string const &name);
		Character(const Character &other);
		Character& operator=(const Character &cp);
		std::string const & getName() const;
		AMateria*	getInventoryItem(int idx) const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		~Character();
	private:
		std::string name;
		AMateria*	inventory[INVENTORY_SIZE];
		
};

#endif