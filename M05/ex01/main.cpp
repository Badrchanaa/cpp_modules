#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat br(100, "Someone");
		std::cout << br << std::endl;
		Form form("Document A", 23, 50);
		Form form2("Document B", 110, 50);
		std::cout << form << std::endl;
		std::cout << form2 << std::endl;
		br.signForm(form);
		br.signForm(form2);
		std::cout << form << std::endl;
		std::cout << form2 << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &)
    {
		std::cout << "Bureaucrat Grade too high exception caught" << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &)
    {
		std::cout << "Bureaucrat Grade too low exception caught" << std::endl;
    }
	catch (const Form::GradeTooHighException &)
    {
		std::cout << "Bureaucrat Grade too high exception caught" << std::endl;
    }
    catch (const Form::GradeTooLowException &)
    {
		std::cout << "Bureaucrat Grade too low exception caught" << std::endl;
    }
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
