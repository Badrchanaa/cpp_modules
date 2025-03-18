#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "PresedentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat br(1, "Someone");
	RobotomyRequestForm rrf("RAZ");
	PresedentialPardonForm ppf("xman");
	ShrubberyCreationForm scf("home");

	std::cout << "----- SIGNING -----" << std::endl;
	br.signForm(rrf);
	br.signForm(ppf);
	br.signForm(scf);
	std::cout << "----- EXECUTION -----" << std::endl;
	br.executeForm(rrf);
	br.executeForm(ppf);
	br.executeForm(scf);
	return 0;
}