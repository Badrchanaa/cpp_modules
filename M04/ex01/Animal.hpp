#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

#include "Brain.hpp"
#include <string>

class Animal
{
	public:
		Animal(void);
		Animal(const Animal &other);
		Animal(const std::string &type);
		Animal& operator=(const Animal &cp);
		virtual void	makeSound() const;
		virtual Brain	*getBrain() const;
		std::string getType() const;
		virtual ~Animal();
	protected:
		std::string type;	
};

#endif