#ifndef __ITER_HPP__
# define __ITER_HPP__

#include <iostream>

template <typename T>
void	iter(T arr[], std::size_t size, void (*fn)(T const &))
{
	for(std::size_t i = 0; i < size; i++)
	{
		fn(arr[i]);
	}
}

#endif