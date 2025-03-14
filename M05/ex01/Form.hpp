#ifndef __FORM_HPP__
# define __FORM_HPP__

#include <string>
#include <exception>

class Form
{
	public:
		Form(void);
		Form(const Form &other);
		Form& operator=(const Form &other);
		~Form();
		std::string getName() const;
		std::string isSigned() const;
		std::string getSignGrade() const;
		std::string getExecutionGrade() const;
		class GradeTooHighException: public std::exception {};
		class GradeTooLowException: public std::exception {};
	private:
		const std::string	_name;
		bool				_isSigned;
		const unsigned int	_signGrade;
		const unsigned int	_execGrade;

};

#endif