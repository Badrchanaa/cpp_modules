#ifndef __WHATEVER_HPP__
# define __WHATEVER_HPP__

template<typename T>
void	swap(T &a, T &b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
const T&	min(const T& a, const T& b)
{
	if (a < b)
		return a;
	return b;
}

template<typename T>
const T&	max(const T& a, const T& b)
{
	if (a > b)
		return a;
	return b;
}

#endif