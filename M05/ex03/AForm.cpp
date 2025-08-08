#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

AForm::AForm(void) : _name(""), _signGrade(100), _execGrade(100) {}

AForm::AForm(std::string name, unsigned int signGrade, unsigned int execGrade)
    : _name(name), _signGrade(_validateGrade(signGrade)), _execGrade(_validateGrade(execGrade))
{
}

const char *AForm::GradeTooHighException::what() const throw() { return ("Grade too high."); }

const char *AForm::GradeTooLowException::what() const throw() { return ("Grade too low."); }

const char *AForm::NotSignedException::what() const throw() { return ("Form is not signed."); }

AForm::AForm(const AForm &other)
    : _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
    *this = other;
}

AForm &AForm::operator=(const AForm &other)
{
    this->_isSigned = other._isSigned;
    return *this;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!_isSigned)
	throw AForm::NotSignedException();
    if (executor.getGrade() > _execGrade)
	throw AForm::GradeTooLowException();
    this->_executeAction();
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "AForm name: " << form.getName() << " signGrade: " << form.getSignGrade()
       << " executeGrade: " << form.getExecutionGrade();
    return os;
}

bool AForm::beSigned(Bureaucrat const &br)
{
    if (br.getGrade() > _signGrade)
	throw AForm::GradeTooLowException();
    _isSigned = true;
    return _isSigned;
}

AForm::~AForm(void) {}

std::string AForm::getName() const { return _name; }

bool AForm::isSigned() const { return _isSigned; }

unsigned int AForm::getSignGrade() const { return _signGrade; }

unsigned int AForm::getExecutionGrade() const { return _execGrade; }

unsigned int AForm::_validateGrade(int grade) const
{
    if (grade < 1)
	throw AForm::GradeTooHighException();
    if (grade > 150)
	throw AForm::GradeTooLowException();
    return (unsigned char)grade;
}
