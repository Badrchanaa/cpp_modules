#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "PresedentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat br(2, "Someone");
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
	}
	catch (const Bureaucrat::GradeTooHighException &)
    {
		std::cout << "Grade too high exception caught" << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &)
    {
		std::cout << "Grade too low exception caught" << std::endl;
    }
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}