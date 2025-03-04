#ifndef __SCAV_TRAP_HPP__
# define __SCAV_TRAP_HPP__

#include "ClapTrap.hpp"
#include <string>

class ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		ScavTrap& operator=(const ScavTrap &cp);
		void	attack(const std::string &target);
		void	guardGate();
		~ScavTrap();
	private:

};

#endif