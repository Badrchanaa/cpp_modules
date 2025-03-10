#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	const Dog* dog = new Dog();
	const AAnimal* cat = new Cat();
	const AAnimal *copyDog = new Dog(*dog);	
	
	std::cout << "---------------- MAIN START ------------" << std::endl;
	Dog d;
	{
		Dog test;
		test.getBrain()->ideas[0] = "HELLO DOG";
		d = test;
	}
	std::cout << "dog brain[0]: " << d.getBrain()->ideas[0] << std::endl;
	Cat c;
	{
		Cat test;
		test.getBrain()->ideas[0] = "HELLO CAT";
		c = test;
	}
	std::cout << "cat brain[0]: " << c.getBrain()->ideas[0] << std::endl;
	dog->makeSound();
	cat->makeSound();

	// AAnimal should_not_compile;

	std::cout << "--------------- MAIN END ------------------" << std::endl;
	delete dog;//should not create a leak
	delete cat;
	delete copyDog;

	return 0;
}