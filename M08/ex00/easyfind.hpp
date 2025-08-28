#ifndef __EASYFIND_HPP__
# define __EASYFIND_HPP__

template <typename T>
int easyfind(T& container, int needle)
{
	typename T::iterator it = std::find(container.begin(), container.end(), needle);
	if (it == container.end())
		throw std::exception();
	return *it;
}

#endif