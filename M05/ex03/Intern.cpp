#include "Intern.hpp"
#include "PresedentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

Intern::Intern(void) {}

Intern::Intern(const Intern &other) { *this = other; }

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

std::string Intern::_formatFormName(std::string name)
{
    std::string formattedName;

    for (std::string::size_type i = 0; i < name.length(); i++)
    {
        if (name[i] == ' ')
            continue;
        if (name[i] >= 'A' && name[i] <= 'Z')
            formattedName += name[i] - ('A' - 'a');
        else
            formattedName += name[i];
    }
    return formattedName;
}

form_type Intern::_getFormType(std::string name)
{
    std::string formattedName;
    const char *formNames[FORM_MAX] = {SCF_NAME, PPF_NAME, RRF_NAME};

    formattedName = Intern::_formatFormName(name);
    for (int i = FORM_SCF; i < FORM_MAX; i++)
    {
        if (formattedName.compare(formNames[i]) == 0)
            return ((form_type)i);
    }
    throw Intern::InvalidFormName();
}

AForm *Intern::_makeSCF(std::string target)
{
    AForm *form = new ShrubberyCreationForm(target);
    return form;
}

AForm *Intern::_makeRRF(std::string target)
{
    AForm *form = new RobotomyRequestForm(target);
    return form;
}

AForm *Intern::_makePPF(std::string target)
{
    AForm *form = new PresedentialPardonForm(target);
    return form;
}

AForm *Intern::makeForm(std::string name, std::string target)
{

    AForm *(Intern::*formFns[FORM_MAX])(std::string) = {&Intern::_makeSCF, &Intern::_makePPF,
                                                        &Intern::_makeRRF};
    try
    {
        form_type formType = Intern::_getFormType(name);
        AForm *(Intern::*memberFn)(std::string) = formFns[formType];
        AForm *form = (this->*memberFn)(target);
        return form;
    }
    catch (const std::bad_alloc &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const Intern::InvalidFormName &e)
    {
        std::cout << "Invalid form name argument." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Something went wrong." << std::endl;
    }
    return NULL;
}

Intern::~Intern(void) {}
