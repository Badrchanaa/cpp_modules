
#include "Span.hpp"
#include <iostream>

Span::Span(unsigned int N): m_Arr(new int[N]), m_Size(0), m_Capacity(N)
{
	std::cout << "Span constructor" << std::endl;
}

Span::Span(const Span& sp): m_Arr(new int[sp.m_Capacity]), m_Size(sp.m_Size), m_Capacity(sp.m_Capacity)
{
	std::cout << "Span copy constructor" << std::endl;
	for (unsigned int i = 0; i < sp.m_Size; i++)
	{
		m_Arr[i] = sp.m_Arr[i];
	}
}

Span&	Span::operator=(Span sp)
{
	std::swap(m_Size, sp.m_Size);
	std::swap(m_Arr, sp.m_Arr);
	std::swap(m_Capacity, sp.m_Capacity);
	return *this;
}

void	Span::addNumber(int a)
{
	if (m_Size == m_Capacity)
		throw std::exception();
	m_Arr[m_Size] = a;
	m_Size++;
}

Span::~Span()
{
	std::cout << "Span destructor" << std::endl;
	delete[] m_Arr;
}

