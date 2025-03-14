#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "======== TEST GRADE > 150 ==========" << std::endl;
	try
	{
		Bureaucrat br(149, "someone");

		std::cout << br << std::endl;
		br.decrementGrade();
		std::cout << br << std::endl;
		br.decrementGrade();
		std::cout << br << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException)
	{
		std::cout << "Grade too high exception caught" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException)
	{
		std::cout << "Grade too low exception caught" << std::endl;
	}
	catch (...)
	{
		std::cout << "unexpected exception caught" << std::endl;
	}

	std::cout << "======== TEST GRADE < 1 ==========" << std::endl;
	try
	{
		Bureaucrat br(2, "someone");

		std::cout << br << std::endl;
		br.incrementGrade();
		std::cout << br << std::endl;
		br.incrementGrade	();
		std::cout << br << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException)
	{
		std::cout << "Grade too high exception caught" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException)
	{
		std::cout << "Grade too low exception caught" << std::endl;
	}
	catch (...)
	{
		std::cout << "unexpected exception caught" << std::endl;
	}
	return 0;
}