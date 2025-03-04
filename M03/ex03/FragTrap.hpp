#ifndef __FRAG_TRAP_HPP__
# define __FRAG_TRAP_HPP__

#include "ClapTrap.hpp"
#include <string>

class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		FragTrap& operator=(const FragTrap &cp);
		void	highFivesGuys();
		~FragTrap();
	private:

};

#endif