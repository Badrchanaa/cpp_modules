#ifndef __CURE_HPP__
# define __CURE_HPP__

#include "AMateria.hpp"
#include <string>

class Cure: public AMateria
{
	public:
		Cure(void);
		Cure(const Cure &other);
		Cure& operator=(const Cure &cp);
		std::string const &getType() const;
		virtual	AMateria *clone() const;
		void	 use(ICharacter &target);
		~Cure();
	private:
		
};

#endif