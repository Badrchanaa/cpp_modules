#include "iter.hpp"

template <typename T>
void	ft_abs(T &n)
{
	if (n < 0)
		n = -n;
}

template <typename T>
void	print(T const &x)
{
	std::cout << x << std::endl;
}

int main()
{
	int arr[] = {0, 1, -2 ,3 ,-4};
	std::cout << "Before ft_abs" << std::endl;
	iter(arr, 5, print);
	iter(arr, 5, ft_abs);
	std::cout << "After ft_abs" << std::endl;
	iter(arr, 5, print);
	return 0;
}