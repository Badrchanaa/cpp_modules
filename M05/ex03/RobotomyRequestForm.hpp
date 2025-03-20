#ifndef __ROBOTOMYREQUESTFORM_HPP__
# define __ROBOTOMYREQUESTFORM_HPP__

#include <string>
#include "AForm.hpp"
# define RRF_SIGN_GRADE 72
# define RRF_EXECUTION_GRADE 45

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();
		class RobotomyFailure: public std::exception
		{
			private:
				std::string _msg;
			public:
				RobotomyFailure(std::string target);
				const char *what() const throw();
				~RobotomyFailure() throw();
		};
	private:
		virtual void		_executeAction() const;
		std::string			_target;
};

#endif