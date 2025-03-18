#ifndef __INTERN_HPP__
# define __INTERN_HPP__

#include "AForm.hpp"
#include <string>
# define SCF_NAME "shrubberycreation"
# define PPF_NAME "presedentialpardon"
# define RRF_NAME "robotomyrequest"

typedef enum e_form_type
{
	SCF = 0,
	PPF,
	RRF
} form_type;

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &other);
		Intern& operator=(const Intern &other);
		~Intern();
		AForm	*makeForm(std::string name, std::string target);
	private:
		AForm *(Intern::*forms[3])();
		
};

#endif