#ifndef __WRONGANIMAL_HPP__
# define __WRONGANIMAL_HPP__

#include <string>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal& operator=(const WrongAnimal &cp);
		void	makeSound() const;
		~WrongAnimal();
	private:
		
};

#endif