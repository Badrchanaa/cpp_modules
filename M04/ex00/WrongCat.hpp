#ifndef __WRONGCAT_HPP__
# define __WRONGCAT_HPP__

#include "WrongAnimal.hpp"
#include <string>

class WrongCat: public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(const WrongCat &other);
		WrongCat& operator=(const WrongCat &cp);
		void	makeSound() const;
		~WrongCat();
	private:
		
};

#endif