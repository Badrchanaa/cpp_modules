
#ifndef __HUMAN_A_HPP__
# define __HUMAN_A_HPP__
#include <string>

class Weapon;

class HumanA
{
	public:
		HumanA(std::string const &name, Weapon &weapon);
		void	attack( void ) const;
	private:
		std::string	_name;
		Weapon&	 	_weapon;
};

#endif
