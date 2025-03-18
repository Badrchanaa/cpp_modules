#ifndef __SHRUBBERYCREATIONFORM_HPP__
# define __SHRUBBERYCREATIONFORM_HPP__

#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
# define SCF_SIGN_GRADE 145
# define SCF_EXECUTION_GRADE 137

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();
	private:
		virtual void		_executeAction() const;
		std::string			_target;
};

#endif