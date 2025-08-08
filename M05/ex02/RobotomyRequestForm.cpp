#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

RobotomyRequestForm::RobotomyRequestForm(void)
    : AForm("RobotomyRequestForm", RRF_SIGN_GRADE, RRF_EXECUTION_GRADE), _target("UNDEFINED")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", RRF_SIGN_GRADE, RRF_EXECUTION_GRADE), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm("RobotomyRequestForm", RRF_SIGN_GRADE, RRF_EXECUTION_GRADE), _target(other._target)
{
}

RobotomyRequestForm::RobotomyFailure::RobotomyFailure(std::string target)
    : _msg(target + " robotomy has failed.")
{
}

RobotomyRequestForm::RobotomyFailure::~RobotomyFailure() throw() {}

const char *RobotomyRequestForm::RobotomyFailure::what() const throw() { return _msg.c_str(); }

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    _target = other._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void RobotomyRequestForm::_executeAction() const
{
    std::cout << "** drilling noise **" << std::endl;
    srand(time(NULL));
    int randomNumber = rand() % 100;
    if (randomNumber < 50)
	throw RobotomyRequestForm::RobotomyFailure(_target);
    std::cout << _target << " has been robotomized successfully." << std::endl;
}
