#ifndef __ARRAY_HPP__
# define __ARRAY_HPP__

#include <string>

template <typename T>
class Array
{
	public:
		Array(void): _content(NULL), _size(0)
		{
		}

		Array(unsigned int n):
		{
			if (n != 0)
				this->_content = new T[n];
			else
				this->_content = NULL;
			this->_size = n;
		}

		Array(const Array<T> &other)
		{
			if (other._size != 0)
				this->_content = new T[other->_size];
			else
				this->_content = NULL;
		}

		Array<T>& operator=(const Array<T> &other);
		~Array();
		T&	operator[](const unsigned int index);
		unsigned int	size(void) const;
	private:
		T				*_content;
		unsigned int	_size;
		
};

#endif