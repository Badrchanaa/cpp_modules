#include "Zombie.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>

int main()
{
	Zombie *zombies = zombieHorde(10, "test");
	for (int i = 0; i < 10; i++)
	{
		zombies[i].announce();
	}
	delete []zombies;
	return 0;
}