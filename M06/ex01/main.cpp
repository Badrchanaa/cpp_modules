#include "Data.hpp"
#include <stdint.h>
#include <iostream>
#include "Serializer.hpp"

int	main()
{
	Data data("hello", 10);

	uintptr_t raw = Serializer::serialize(&data);
	Data	*ptr = Serializer::deserialize(raw);

	std::cout << "ptr->str: " << ptr->str << std::endl;
	std::cout << "ptr->num: " << ptr->num << std::endl;
	return 0;
}