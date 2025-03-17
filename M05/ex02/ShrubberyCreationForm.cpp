#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", SIGN_GRADE, EXECUTION_GRADE), _target("UNDEFINED") 
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", SIGN_GRADE, EXECUTION_GRADE), _target(target)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm("ShrubberyCreationForm", SIGN_GRADE, EXECUTION_GRADE), _target(other._target)
{
	
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	_target = other._target;	
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	
}

void		ShrubberyCreationForm::_executeAction(Bureaucrat const & executor) const
{

	std::ofstream of;
	of.open("test.txt");
	if ()
}