#include <algorithm>
#include <vector>
#include <iostream>

template <typename T>
int easyfind(T& container, int needle)
{
	typename T::iterator it = std::find(container.begin(), container.end(), needle);
	if (it == container.end())
		throw std::exception();
	return *it;
}

int main()
{
	std::cout << "test 1: find 5" << std::endl;
	{
		std::vector<int> a;
		a.push_back(20);
		a.push_back(20);
		a.push_back(20);
		a.push_back(20);
		a.push_back(5);
		a.push_back(20);
		a.push_back(20);
		try
		{
			int b = easyfind(a, 5);
			std::cout << "found it" << std::endl;
		}
		catch (std::exception)
		{
			std::cout << "could not find value" << std::endl;
		}
	}
	std::cout << "test 2: find 6" << std::endl;
	{
		std::vector<int> a;
		a.push_back(20);
		a.push_back(20);
		a.push_back(20);
		a.push_back(20);
		a.push_back(5);
		a.push_back(20);
		a.push_back(20);
		try
		{
			int b = easyfind(a, 6);
			std::cout << "found it" << std::endl;
		}
		catch (std::exception)
		{
			std::cout << "could not find value" << std::endl;
		}
	}
	return 0;
}
