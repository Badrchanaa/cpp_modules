#include <iostream>
#include <vector>
#include "Span.hpp"
#include <cstdlib>

Span	*createFullSpan(unsigned int capacity)
{
	srand(time(0));
	Span*	sp = new Span(capacity);
	for (unsigned int i = 0; i < capacity; i++)
	{
		sp->addNumber(rand());
	}
	return sp;
}

void testFull()
{
	Span *sp = createFullSpan(15000);
	try
	{
		sp->addNumber(2);
	}
	catch (const std::exception& e)
	{
		std::cout << "CATCH: Could not add number, Span full" << std::endl;
	}
	std::cout << "shortest span: " << sp->shortestSpan() << std::endl;
	std::cout << "longest span: " << sp->longestSpan() << std::endl;
	delete sp;
}

void testAddAll()
{
	Span sp(10);

	std::vector<int> v(10);
	std::fill(v.begin(), v.end(), 222);
	sp.addAll(v.begin(), v.end());
	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;
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
	catch (const std::exception& e)
	{
		std::cout << "CATCH: vector has too many elements" << std::endl;
	}
}

void testSpan()
{
	Span sp(10);

	sp.addNumber(1);
	sp.addNumber(2);
	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;
	sp.addNumber(101);
	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;
}

int main()
{
	std::cout << " ########## TEST ADD TO FULL SPAN ###########" << std::endl;
	testFull();
	std::cout << " ########## TEST ADD ALL - VECTOR(10) -> SPAN(10)  ###########" << std::endl;
	testAddAll();
	std::cout << " ########## TEST ADD ALL - VECTOR(11) -> SPAN(10) ###########" << std::endl;
	testAddAllFail();
	std::cout << " ########## TEST SPAN ###########" << std::endl;
	testSpan();
	return 0;
}
