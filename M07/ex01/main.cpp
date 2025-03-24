#include "iter.hpp"

template <typename T>
void	ft_abs(T &n)
{
	if (n < 0)
		n = -n;
}

class Awesome
{
	public:
		Awesome(void): _n(42) {return ;}
		int	get(void) const { return this->_n;}
	private:
		int	_n;
};

std::ostream &operator<<(std::ostream &o, Awesome const &rhs)
{
	o << rhs.get();
	return o;
}

template <typename T>
void	print(T const &x)
{
	std::cout << x << std::endl; return;
}

int main()
{
	// int	arr[] = {-1, 2, -3, 4, -5};

	// std::size_t s = 5;
	// ::iter(arr, s, ft_abs);

	// for (std::size_t i = 0; i < s; i++)
	// {
	// 	std::cout << arr[i] << " ";
	// }
	// std::cout << std::endl;

	int tab[] = {0, 1, 2 ,3 ,4};
	Awesome tab2[5];

	iter(tab, 5, print);
	iter(tab2, 5, print);
	return 0;
}