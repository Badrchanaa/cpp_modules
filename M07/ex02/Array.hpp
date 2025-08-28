#ifndef __ARRAY_HPP__
# define __ARRAY_HPP__

#include <string>

template <typename T>
class Array
{
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array<T> &other);
		Array<T>& operator=(Array<T> other);
		~Array();
		T&	operator[](const unsigned int index);
		const T& operator[](const unsigned int index) const;
		unsigned int	size(void) const;
	private:
		T				*_content;
		unsigned int	_size;
		
};

#include "Array.tpp"

#endif