#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", SCF_SIGN_GRADE, SCF_EXECUTION_GRADE), _target("UNDEFINED") 
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", SCF_SIGN_GRADE, SCF_EXECUTION_GRADE), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm("ShrubberyCreationForm", SCF_SIGN_GRADE, SCF_EXECUTION_GRADE), _target(other._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	_target = other._target;	
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	
}

void		ShrubberyCreationForm::_executeAction() const
{
	std::ofstream	of;
	std::string	filename;

	filename = _target + "_shruberry";
	of.exceptions(std::ofstream::failbit | std::ofstream::badbit);
	of.open(filename.c_str());
	of << "               ,@@@@@@@," << "\n";
	of << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << "\n";
	of << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << "\n";
	of << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << "\n";
	of << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << "\n";
	of << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << "\n";
	of << "   `&%\\ ` /%&'    |.|        \\ '|8'" << "\n";
	of << "       |o|        | |         | |" << "\n";
	of << "       |.|        | |         | |" << "\n";
	of << "jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << "\n";
	of << std::flush;
	of.close();
}


