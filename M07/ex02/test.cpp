#include <iostream>

int main()
{
	int	*a = new int[0];
	if (!a)
		std::cout << "is null" << std::endl;
	else
		std::cout << a << std::endl;
	return 0;
}