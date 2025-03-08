#ifndef __DIAMOND_TRAP_HPP__
# define __DIAMOND_TRAP_HPP__

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <string>

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap& operator=(const DiamondTrap &cp);
		void	whoAmI();
		~DiamondTrap();
	private:
		std::string name;
};

#endif