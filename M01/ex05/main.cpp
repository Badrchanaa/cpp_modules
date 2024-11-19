#include "Harl.hpp"
#include <iostream>

int main()
{
	Harl harl1;
	std::cout << "[DEBUG]" << std::endl;
	harl1.complain("debug");
	std::cout << "[INFO]" << std::endl;
	harl1.complain("info");
	std::cout << "[WARNING]" << std::endl;
	harl1.complain("warning");
	std::cout << "[ERROR]" << std::endl;
	harl1.complain("error");
}