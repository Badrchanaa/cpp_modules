#include "tests.hpp"
#include <iostream>
#include <vector>

void testFull()
{
	Span *sp = createFullSpan(10000);
	try
	{
		sp->addNumber(2);
	}
	catch (std::exception)
	{
		std::cout << "CATCH: Could not add number, Span full" << std::endl;
	}
	delete sp;
}

void testAddAll()
{
	Span sp(10);

	std::vector<int> v(10);
	std::fill(v.begin(), v.end(), 222);
	sp.addAll(v.begin(), v.end());
}

void testAddAllFail()
{
	Span sp(10);

	try
	{
		std::vector<int> v(11);
		std::fill(v.begin(), v.end(), 222);
		sp.addAll(v.begin(), v.end());
	}
	catch (std::exception)
	{
		std::cout << "CATCH: vector has too many elements" << std::endl;
	}
}

int main()
{
	std::cout << " ########## TEST ADD TO FULL SPAN ###########" << std::endl;
	testFull();
	std::cout << " ########## TEST ADD ALL - VECTOR(10) -> SPAN(10)  ###########" << std::endl;
	testAddAll();
	std::cout << " ########## TEST ADD ALL - VECTOR(11) -> SPAN(10) ###########" << std::endl;
	testAddAllFail();
	return 0;
}
