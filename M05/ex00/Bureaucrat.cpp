#include "Bureaucrat.hpp"
#include <string>

Bureaucrat::Bureaucrat(std::string name): _name(name)
{
}

unsigned char	Bureaucrat::_validateGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	return (unsigned char)grade;
}

Bureaucrat::Bureaucrat(int grade, std::string name): _name(name), _grade(_validateGrade(grade))
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade)
{
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}

void	Bureaucrat::incrementGrade(void)
{
	this->_grade = _validateGrade(this->_grade - 1);
}

void	Bureaucrat::decrementGrade(void)
{
	this->_grade = _validateGrade(this->_grade + 1);
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return _grade;
}

std::string	Bureaucrat::getName(void) const
{
	return _name;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)
		return *this;
	_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
}
