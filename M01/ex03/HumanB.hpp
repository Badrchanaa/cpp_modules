
#ifndef __HUMAN_B_HPP__
# define __HUMAN_B_HPP__

#include <string>

class Weapon;

class HumanB
{
	public:
		HumanB(std::string const &name);
		void	attack( void ) const;
		void	setWeapon(Weapon const &wp);
	private:
		std::string		_name;
		Weapon const *  _weapon;
};

#endif