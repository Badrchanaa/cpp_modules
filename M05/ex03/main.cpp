#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "PresedentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat br(1, "xman");
	Intern intern;

	AForm * form = intern.makeForm("Robotomy Request", "candidate");
	if (!form)
		return (0);

	try
	{
		form->beSigned(br);
		form->execute(br);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	delete form;
	return 0;
}