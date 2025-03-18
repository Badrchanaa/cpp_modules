#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__

#include <string>
#include <exception>
#include <ostream>
#include "AForm.hpp"

class Bureaucrat
{
	public:
		Bureaucrat(std::string name="");
		Bureaucrat(int grade, std::string name="");
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &cp);
		~Bureaucrat();
		unsigned int	getGrade() const;
		std::string		getName() const;
		void			incrementGrade();
		void			decrementGrade();
		void			signForm(AForm &form) const;
		void			executeForm(AForm const &form) const;
		class GradeTooHighException: public std::exception {};
		class GradeTooLowException: public std::exception {};
	private:
		unsigned char	_validateGrade(int grade);
		const std::string	_name;
		unsigned char		_grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif