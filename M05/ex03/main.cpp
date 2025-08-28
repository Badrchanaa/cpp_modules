#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "PresedentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	AForm *form = NULL;
	{
		Intern someRandomIntern;
		AForm *form;
		form = someRandomIntern.makeForm("robotomy request", "Bender");
		delete form;
		form = NULL;
	}
	std::cout << " ######### ROBOTOMY REQUEST #########" << std::endl;
	try
	{
		Bureaucrat br(1, "xman");
		Intern intern;

		form = intern.makeForm("Robotomy Request", "candidate");
		if (form)
		{
			form->beSigned(br);
			form->execute(br);
			delete form;
			form = NULL;
		}
	}
	catch (const Bureaucrat::GradeTooHighException &)
	{
		std::cout << "Grade too high exception caught" << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &)
	{
		std::cout << "Grade too low exception caught" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete form;
	std::cout << " ######## PRESEDENTIAL PARDON #########" << std::endl;
	try
	{
		Bureaucrat br(1, "xman");
		Intern intern;

		form = intern.makeForm("Presedential Pardon", "candidate");
		if (form)
		{
			form->beSigned(br);
			form->execute(br);
			delete form;
			form = NULL;
		}
	}
	catch (const Bureaucrat::GradeTooHighException &)
	{
		std::cout << "Grade too high exception caught" << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &)
	{
		std::cout << "Grade too low exception caught" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete form;
	std::cout << " ######## SHRUBERRY CREATION #########" << std::endl;
	try
	{
		Bureaucrat br(1, "xman");
		Intern intern;

		form = intern.makeForm("Shrubbery creation", "candidate");
		if (form)
		{
			form->beSigned(br);
			form->execute(br);
			delete form;
			form = NULL;
		}
	}
	catch (const Bureaucrat::GradeTooHighException &)
	{
		std::cout << "Grade too high exception caught" << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &)
	{
		std::cout << "Grade too low exception caught" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete form;
	return 0;
}