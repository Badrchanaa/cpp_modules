#ifndef __AANIMAL_HPP__
# define __AANIMAL_HPP__

#include "Brain.hpp"
#include <string>


class AAnimal
{
	public:
		AAnimal(void);
		AAnimal(const AAnimal &other);
		AAnimal(const std::string &type);
		AAnimal& operator=(const AAnimal &cp);
		virtual void	makeSound() const = 0;
		virtual Brain	*getBrain() const = 0;
		std::string getType() const;
		virtual ~AAnimal();
	protected:
		std::string type;	
};

#endif