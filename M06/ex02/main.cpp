#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base	*generate(void)
{
	Base	*ptr;

	std::srand(time(0));
	int randInt = std::rand() % 3;
	switch (randInt)
	{
		case 0:
			std::cout << "generated type A" << std::endl;
			ptr = new A();
			break;
		case 1:
			std::cout << "generated type B" << std::endl;
			ptr = new B();
			break;
		default:
			std::cout << "generated type C" << std::endl;
			ptr = new C();
	}
	return ptr;
}


void	identify(Base *p)
{
	std::cout << "identify(Base *p): ";
	if (dynamic_cast<A*>(p))
		std::cout << "type of *p is A*" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "type of *p is B*" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "type of *p is C*" << std::endl;
	else
		std::cout << "invalid pointer" << std::endl;
}

void	identify(Base &p)
{
	std::cout << "identify(Base &p): ";
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "type of &p is A&" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "type of &p is B&" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "type of &p is C&" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "invalid type" << std::endl;
	}
}

int	main()
{
	A a;
	B b;
	C c;

	identify(a);
	identify(b);
	identify(c);

	Base	*ptr = generate();
	Base	&ref = *ptr;

	identify(ptr);
	identify(ref);
	delete ptr;

	return 0;
}