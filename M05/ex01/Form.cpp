#include "Form.hpp"
#include <iostream>
#include <string>

Form::Form(void): _name(""), _signGrade(100), _execGrade(100)
{
}

Form::Form(std::string name, unsigned int signGrade, unsigned int execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
}

Form::Form(const Form &other): _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
}

Form& Form::operator=(const Form &other)
{
}

Form::~Form(void)
{
}

std::string getName() const
{
	return _name;
}

bool isSigned() const
{
	return _isSigned;
}

unsigned int getSignGrade() const
{
	return _signGrade;
}

unsigned int getExecutionGrade() const
{
	return _execGrade;
}