#ifndef	EASY_FIND
#define EASY_FIND

#include <algorithm>

template<typename T>
typename T::iterator	easyfind(T& dataset, const int num)
{
	typename T::iterator	result;

	result = std::find(dataset.begin(), dataset.end(), num);
	return (result);
}

#endif // EASY_FIND
