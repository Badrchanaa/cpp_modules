#ifndef __SCAV_TRAP_HPP__
# define __SCAV_TRAP_HPP__

#include "ClapTrap.hpp"

#include <string>

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		ScavTrap& operator=(const ScavTrap &cp);
		void	guardGate();
		~ScavTrap();
	private:

};

#endif