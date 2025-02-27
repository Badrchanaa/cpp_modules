#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
}

enum Level	Harl::strtoint(std::string level)
{
	const char	*levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	for (int i = DEBUG; i <= ERROR; i++)
		if (level == std::string(levels[i]))
			return (enum Level) (i + 1);
	return (enum Level) 0;
}

void	Harl::complain(enum Level lvl) const
{
	switch(lvl)
	{
		case DEBUG:
			this->debug();
			this->complain(INFO);
			break;
		case INFO:
			this->info();
			this->complain(WARNING);
			break;
		case WARNING:
			this->warning();
			this->complain(ERROR);
			break;
		case ERROR:
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
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