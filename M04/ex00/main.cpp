#include "Animal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>


void	correctImplementation()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
}

void	wrongImplementation()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const WrongAnimal* i = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the WrongAnimal sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
}

int main()
{
	std::cout << "------------ CORRECT IMPLEMENTATION ----------" << std::endl;
	correctImplementation();
	std::cout << "------------ WRONG IMPLEMENTATION ----------" << std::endl;
	wrongImplementation();
return 0;
}