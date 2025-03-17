#ifndef __ROBOTOMYREQUESTFORM_HPP__
# define __ROBOTOMYREQUESTFORM_HPP__

#include <string>
#include "AForm.hpp"
# define SIGN_GRADE 72
# define EXECUTION_GRADE 45

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();
	private:
		virtual void		_executeAction(Bureaucrat const & executor) const;
		std::string			_target;
		
};

#endif