#include "Harl.hpp"
#include <iostream>

int main(int ac, char *av[])
{
	if (ac == 1)
		return 0;
	Harl harl;
	harl.complain((enum Level) Harl::strtoint(std::string(av[1])));
	return 0;
}
