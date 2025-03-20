#ifndef __INTERN_HPP__
# define __INTERN_HPP__

#include "AForm.hpp"
#include <string>
# define SCF_NAME "shrubberycreation"
# define PPF_NAME "presedentialpardon"
# define RRF_NAME "robotomyrequest"

typedef enum e_form_type
{
	FORM_SCF = 0,
	FORM_PPF,
	FORM_RRF,
	FORM_MAX,
} form_type;

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &other);
		Intern& operator=(const Intern &other);
		~Intern();
		AForm	*makeForm(std::string name, std::string target);
		class InvalidFormName: public std::exception {};
	private:
		static form_type	_getFormType(std::string name);
		static std::string	_formatFormName(std::string name);
		AForm	*_makeSCF(std::string target);
		AForm	*_makePPF(std::string target);
		AForm	*_makeRRF(std::string target);
		
};

#endif