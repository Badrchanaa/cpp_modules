#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <exception>
#include <string>

class Bureaucrat;

class Form
{
    public:
	Form(void);
	Form(std::string name, unsigned int signGrade, unsigned int execGrade);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();
	std::string getName() const;
	bool isSigned() const;
	unsigned int getSignGrade() const;
	unsigned int getExecutionGrade() const;
	bool beSigned(Bureaucrat const &br);
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};

    private:
	unsigned int _validateGrade(int grade) const;
	const std::string _name;
	bool _isSigned;
	const unsigned int _signGrade;
	const unsigned int _execGrade;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
