#include "Form.hpp"
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

Form::Form(void): _name(""), _signGrade(100), _execGrade(100)
{
}

Form::Form(std::string name, unsigned int signGrade, unsigned int execGrade): 
			_name(name), _signGrade(_validateGrade(signGrade)), _execGrade(_validateGrade(execGrade))
{
}

Form::Form(const Form &other): _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	*this = other;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

Form& Form::operator=(const Form &other)
{
	this->_isSigned = other._isSigned;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form name: " << form.getName() << " ";
	if (form.isSigned())
		os << "(signed)";
	else
		os << "(not signed)";
	os << " signGrade: " << form.getSignGrade() << " executeGrade: " << form.getExecutionGrade();
	return os;
}

bool	Form::beSigned(Bureaucrat const &br)
{
	if (br.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	_isSigned = true;
	return _isSigned;
}


Form::~Form(void)
{
}

std::string Form::getName() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _isSigned;
}

unsigned int Form::getSignGrade() const
{
	return _signGrade;
}

unsigned int Form::getExecutionGrade() const
{
	return _execGrade;
}

unsigned int	Form::_validateGrade(int grade) const
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	if (grade > 150)
		throw Form::GradeTooLowException();
	return (unsigned char)grade;
}
