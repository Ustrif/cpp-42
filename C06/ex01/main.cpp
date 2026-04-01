#include "Serializer.hpp"

int	main (void)
{
	Data data = {.type = 'r', .num = 10};

	uintptr_t address = Serializer::serialize(&data);
	std::cout << "type: " << data.type
			  << " and "
			  << "num: " << data.num 
			  << std::endl;

	std::cout << "Address of data object is: " << &data << std::endl;
	std::cout << "Serialized data: " << address << std::endl;
	std::cout << "Deserialized data: " << Serializer::deserialize(address) << std::endl;

	Data* sameHomeOtherData = Serializer::deserialize(address);
	std::cout << "type: " << sameHomeOtherData->type
			  << " and "
			  << "num: " << sameHomeOtherData->num 
			  << std::endl;
	return (0);
}
