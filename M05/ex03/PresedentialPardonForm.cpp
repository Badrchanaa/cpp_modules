#include "PresedentialPardonForm.hpp"
#include <iostream>
#include <string>

PresedentialPardonForm::PresedentialPardonForm(void): AForm("PresedentialPardonForm", PPF_SIGN_GRADE, PPF_EXECUTION_GRADE), _target("")
{
}

PresedentialPardonForm::PresedentialPardonForm(std::string target): AForm("PresedentialPardonForm", PPF_SIGN_GRADE, PPF_EXECUTION_GRADE), _target(target)
{
}

PresedentialPardonForm::PresedentialPardonForm(const PresedentialPardonForm &other): AForm("PresedentialPardonForm", PPF_SIGN_GRADE, PPF_EXECUTION_GRADE), _target(other._target)
{
}

PresedentialPardonForm& PresedentialPardonForm::operator=(const PresedentialPardonForm &other)
{
	_target = other._target;
	return *this;
}

PresedentialPardonForm::~PresedentialPardonForm(void)
{
}

void	PresedentialPardonForm::_executeAction() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}