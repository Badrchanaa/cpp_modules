#ifndef __ICE_HPP__
# define __ICE_HPP__

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Ice: public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &other);
		Ice& operator=(const Ice &cp);
		std::string const &getType() const;
		virtual	AMateria *clone() const;
		void	 use(ICharacter &target);
		~Ice();
	private:
		
};

#endif