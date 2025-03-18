#ifndef __PRESEDENTIALPARDONFORM_HPP__
# define __PRESEDENTIALPARDONFORM_HPP__

#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

# define PPF_SIGN_GRADE 25
# define PPF_EXECUTION_GRADE 5

class PresedentialPardonForm: public AForm
{
	public:
		PresedentialPardonForm(void);
		PresedentialPardonForm(std::string target);
		PresedentialPardonForm(const PresedentialPardonForm &other);
		PresedentialPardonForm& operator=(const PresedentialPardonForm &other);
		~PresedentialPardonForm();
	private:
		virtual void		_executeAction() const;
		std::string			_target;
};

#endif