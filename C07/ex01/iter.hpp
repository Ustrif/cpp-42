#ifndef __ITER__
#define __ITER__

#define ARR_SIZE 4

#include <iostream>

template<typename T>
void	iter(const T* arr, const std::size_t len, void (*func)(T))
{
	for (std::size_t l = len; l > 0; l--)
	{
		func(arr[len - l]);
	}
}

#endif // __ITER__