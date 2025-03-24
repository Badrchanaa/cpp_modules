#include "Array.hpp"
#include <iostream>
#include <string>
#include "Array.hpp"

template <typename T> Array<T>::Array(void)
{
	std::cout << "void cons" << std::endl;
	
}

template <typename T> Array<T>::Array(const Array<T> &other)
{
	(void)other;	
}

template <typename T> Array<T>& Array<T>::operator=(const Array<T> &other)
{
	(void)other;	
}

template <typename T> Array<T>::~Array(void)
{
	
}
template <typename T> unsigned int	Array<T>::size(void) const
{
	return this->_size;
}