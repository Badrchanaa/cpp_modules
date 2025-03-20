#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <string>
#include "AForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", RRF_SIGN_GRADE, RRF_EXECUTION_GRADE), _target("UNDEFINED")
{
	
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", RRF_SIGN_GRADE, RRF_EXECUTION_GRADE), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm("RobotomyRequestForm", RRF_SIGN_GRADE, RRF_EXECUTION_GRADE), _target(other._target)
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

void		RobotomyRequestForm::_executeAction() const
{
	std::cout <<  "** drilling noise **" << std::endl;
	srand(time(NULL));
	int randomNumber = rand() % 100;
	if (randomNumber < 50)
		throw RobotomyRequestForm::RobotomyFailure(_target);	
	std::cout << _target << " has been robotomized successfully." << std::endl;
}