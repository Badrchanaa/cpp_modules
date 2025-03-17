#ifndef __SHRUBBERYCREATIONFORM_HPP__
# define __SHRUBBERYCREATIONFORM_HPP__

#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
# define SIGN_GRADE 145
# define EXECUTION_GRADE 137

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();
	private:
		virtual void		_executeAction(Bureaucrat const & executor) const;
		std::string			_target;
};

#endif