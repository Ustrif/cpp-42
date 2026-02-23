#ifndef __ITER__
#define __ITER__

#define ARR_SIZE 4

#include <iostream>

template<typename T>
void	iter(const T* arr, const std::size_t len, void (*func)(T));

#endif // __ITER__