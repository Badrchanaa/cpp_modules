#include "Data.hpp"
#include <stdint.h>
#include <iostream>


uintptr_t	serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int	main()
{
	Data data("hello", 10);

	uintptr_t raw = serialize(&data);
	Data	*ptr = deserialize(raw);

	std::cout << "ptr->str: " << ptr->str << std::endl;
	std::cout << "ptr->num: " << ptr->num << std::endl;
	return 0;
}