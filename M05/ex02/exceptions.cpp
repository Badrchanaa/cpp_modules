#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("Form is not signed.");
}

// RobotomyRequestForm::RobotomyFailure::RobotomyFailure(std::string target): _target(target)
// {
// }

const char	*RobotomyRequestForm::RobotomyFailure::what() const throw()
{
	return (" robotomy has failed.");
}
