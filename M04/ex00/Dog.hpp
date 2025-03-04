#ifndef __DOG_HPP__
# define __DOG_HPP__

#include "Animal.hpp"
#include <string>

class Dog: public Animal
{
	public:
		Dog(void);
		Dog(const Dog &other);
		Dog& operator=(const Dog &cp);
		void makeSound() const;
		~Dog();
	private:
		
};

#endif