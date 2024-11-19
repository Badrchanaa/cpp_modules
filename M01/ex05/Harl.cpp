#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{

}

int	Harl::strtoint(std::string level)
{
	const char	*levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	for (int i = 0; i < 4; i++)
		if (level == levels[i])
			return i;
	return -1;
}

void	Harl::complain(std::string level) const
{
	void (Harl::* harl_fns[4]) (void) const = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	int lvl = Harl::strtoint(level);
	if (lvl >= 0 && lvl <= 4)
		(this->*harl_fns[Harl::strtoint(level)])();
}

void	Harl::debug( void ) const 
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my "
			<< "7XL-double-cheese-triple-pickle-specialketchup "
			<< "burger. I really do!" << std::endl;

}

void	Harl::info( void ) const 
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. "
			<< "You didn’t put enough bacon in my burger! "
			<< "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning( void ) const 
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon "
			<< "for free. I’ve been coming for years whereas "
			<< "you started working here since last month." << std::endl;
}

void	Harl::error( void ) const 
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::~Harl()
{}