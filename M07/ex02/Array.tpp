#pragma once

template <typename T> Array<T>::Array(void)
{
	this->_content = new T[0];
	this->_size = 0;
}

template <typename T> Array<T>::Array(unsigned int n)
{
	this->_content = new T[n];
	this->_size = n;
}

template <typename T> Array<T>::Array(const Array<T> &other)
{
	this->_content = new T[other._size];
	for(unsigned int i = 0; i < other._size; i++)
		this->_content[i] = other._content[i];
	this->_size = other._size;
}

template <typename T> Array<T>& Array<T>::operator=(Array<T> other)
{
	T	*tmp;

	tmp = this->_content;
	this->_content = other._content;
	other._content = tmp;
	this->_size = other._size;
	return *this;
}

template <typename T> Array<T>::~Array(void)
{
	if (this->_content)
		delete[] this->_content;
}

template <typename T> T& Array<T>::operator[](const unsigned int index)
{
	if (index >= this->_size)
		throw std::exception();
	return this->_content[index];
}

template <typename T> const T& Array<T>::operator[](const unsigned int index) const
{
	if (index >= this->_size)
		throw std::exception();
	return this->_content[index];
}

template <typename T> unsigned int	Array<T>::size(void) const
{
	return this->_size;
}