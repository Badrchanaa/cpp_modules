#ifndef __DOG_HPP__
# define __DOG_HPP__

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>

class Dog: public AAnimal
{
	public:
		Dog(void);
		Dog(const Dog &other);
		Dog& operator=(const Dog &cp);
		void makeSound() const;
		Brain * getBrain() const;
		~Dog();
	private:
		Brain	*brain;
		
};

#endif