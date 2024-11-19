#include "Zombie.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zombies[i].setName(name);
	}
	return zombies;
}

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