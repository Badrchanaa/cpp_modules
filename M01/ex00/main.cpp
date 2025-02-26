#include "Zombie.hpp"

int main()
{
	Zombie	*zombie;

	randomChump("chump");
	zombie = newZombie("Aloc");
	zombie->announce();
	delete zombie;
	return 0;
}