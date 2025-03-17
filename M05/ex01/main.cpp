#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	Bureaucrat br(101, "Someone");
	Form form("Document A", 100, 50);
	Form form2("Document B", 110, 50);

	br.signForm(form);
	br.signForm(form2);
	return 0;
}