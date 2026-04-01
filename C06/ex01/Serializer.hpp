#ifndef __SERIALIZER__
#define __SERIALIZER__

#include <iostream>
#include "data.hpp"

typedef unsigned int* uintptr_t;

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer& other);
		Serializer operator = (const Serializer& other);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif // __SERIALIZER__