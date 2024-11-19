#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main()
{
	Zombie	*zombie;

	randomChump("chump");
	zombie = newZombie("Aloc");
	zombie->announce();
	delete zombie;
	return 0;
}