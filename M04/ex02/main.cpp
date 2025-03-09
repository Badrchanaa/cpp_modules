#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	const Dog* dog = new Dog();
	const AAnimal* cat = new Cat();
	const AAnimal *copyDog = new Dog(*dog);	
	
	std::cout << "----- MAIN START ------" << std::endl;
	for (int i = 0; i < 99; i++)
		dog->getBrain()->ideas[i] = "HELLO";

	if (copyDog->getBrain() == dog->getBrain())
		std::cout << "shallow copy" << std::endl;
	else
		std::cout << "deep copy" << std::endl;

	// AAnimal should_not_compile;
	std::cout << "----- MAIN END ------" << std::endl;
	delete dog;//should not create a leak
	delete cat;
	delete copyDog;
	return 0;
}