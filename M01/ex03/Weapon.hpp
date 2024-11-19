#ifndef __WEAPON_HPP__
# define __WEAPON_HPP__

#include <string>

class Weapon
{
	public:
		Weapon(std::string const &type);
		std::string const	&getType(void) const;
		void				setType(std::string const &str);
	private:
		std::string	_type;
};

#endif