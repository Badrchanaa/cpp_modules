#include "Harl.hpp"
#include <iostream>

int main(int ac, char *av[])
{
	if (ac == 1)
	{
		std::cerr << "missing level argument." << std::endl;
		return 1;
	}
	Harl harl;
	harl.complain((enum Level) Harl::strtoint(std::string(av[1])));
	return 0;
}
