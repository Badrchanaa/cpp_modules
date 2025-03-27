#include "Array.hpp"

int main()
{
	Array<int> a(5);

	for (int i = 0; i < 5; i++)
	{
		a[i] = i * 2;
		std::cout << "a[" << i << "] = " << a[i] << std::endl;
	}
	Array<int> x;

	x = a;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "x[" << i << "] = " << x[i] << std::endl;
	}
	return 0;
}