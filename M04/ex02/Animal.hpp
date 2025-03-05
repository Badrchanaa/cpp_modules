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
		virtual void	makeSound() const = 0;
		virtual Brain	*getBrain() const = 0;
		std::string getType() const;
		virtual ~Animal();
	protected:
		std::string type;	
};

#endif