#ifndef __CAT_HPP__
# define __CAT_HPP__

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat: public Animal
{
	public:
		Cat(void);
		Cat(const Cat &other);
		Cat& operator=(const Cat &cp);
		void	makeSound() const;
		Brain	*getBrain() const;
		~Cat();
	private:
		Brain	*brain;
		
};

#endif