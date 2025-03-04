#ifndef __WRONGANIMAL_HPP__
# define __WRONGANIMAL_HPP__

#include <string>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(const std::string &type);
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal& operator=(const WrongAnimal &cp);
		void	makeSound() const;
		std::string	getType() const;
		~WrongAnimal();
	protected:
		std::string type;	
};

#endif