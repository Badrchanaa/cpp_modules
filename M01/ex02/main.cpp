#include <iostream>
#include <iomanip>

int main()
{
	std::string str("HI THIS IS BRAIN");
	std::string *stringPTR;
	stringPTR = &str;
	std::string &stringREF = str;

	std::cout << std::left << std::setw(40) << "Address of str:" << &str << std::endl;
	std::cout << std::left << std::setw(40) << "Address of stringPTR:" << stringPTR << std::endl;
	std::cout << std::left << std::setw(40) << "Address of stringREF:" << &stringREF << std::endl;
	std::cout << std::left << std::setw(40) << "Value of str: " << str << std::endl;
	std::cout << std::left << std::setw(40) << "Value of stringPTR: " << *stringPTR << std::endl;
	std::cout << std::left << std::setw(40) << "Valud of stringREF: " << stringREF << std::endl;
	return 0;
}