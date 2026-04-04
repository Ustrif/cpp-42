#ifndef __WEVER__
#define __WEVER__

template<typename T>
void	swap(T& first, T& other)
{
	T temp = first;
	first = other;
	other = temp;
}

template<typename T>
T	min(T& first, T& other)
{
	if (first < other)
		return (first);
	return (other);
}

template<typename T>
T	max(T& first, T& other)
{
	if (first > other)
		return (first);
	return (other);
}

#endif // __WEVER__