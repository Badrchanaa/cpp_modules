#ifndef __AMATERIA_HPP__
# define __AMATERIA_HPP__

#include <string>
// #include "ICharacter.hpp"
class ICharacter;

class AMateria
{
	public:
		AMateria(void);
		AMateria(std::string const &type);
		AMateria(const AMateria &other);
		AMateria& operator=(const AMateria &cp);
		std::string const &getType() const;
		virtual	AMateria *clone() const = 0;
		virtual void	 use(ICharacter &target);
		virtual ~AMateria();
	protected:
		std::string type;
		
};

#endif