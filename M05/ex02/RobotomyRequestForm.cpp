#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <string>
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", SIGN_GRADE, EXECUTION_GRADE), _target("UNDEFINED")
{
	
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", SIGN_GRADE, EXECUTION_GRADE), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm("RobotomyRequestForm", SIGN_GRADE, EXECUTION_GRADE), _target(other._target)
{
	
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	_target = other._target;
	return *this;	
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	
}

void		RobotomyRequestForm::_executeAction(Bureaucrat const & executor) const
{

}