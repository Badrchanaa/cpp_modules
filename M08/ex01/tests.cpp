#include "tests.hpp"
#include <cstdlib>
#include <ctime>

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


