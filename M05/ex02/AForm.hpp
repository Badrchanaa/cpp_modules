#ifndef __FORM_HPP__
# define __FORM_HPP__

#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
	public:
		AForm(void);
		AForm(std::string name, unsigned int signGrade, unsigned int execGrade);
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
		virtual	~AForm();

		std::string		getName() const;
		unsigned int	getSignGrade() const;
		unsigned int	getExecutionGrade() const;
		bool			isSigned() const;

		bool			beSigned(Bureaucrat const &br);
		void			execute(Bureaucrat const & executor) const;

		class GradeTooHighException: public std::exception {
			const char *what() const throw();
		};
		class GradeTooLowException: public std::exception {
			const char *what() const throw();
		};
		class NotSignedException: public std::exception {
			const char *what() const throw();
		};
	private:
		virtual void		_executeAction() const = 0;
		unsigned int		_validateGrade(int grade) const;
		const std::string	_name;
		bool				_isSigned;
		const unsigned int	_signGrade;
		const unsigned int	_execGrade;

};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif