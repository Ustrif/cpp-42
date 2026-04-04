#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	this->capacity = 0;
	this->t = NULL;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->capacity = n;
	this->t = new T[n]();
}

template <typename T>
Array<T>::~Array()
{
	delete[] (this->t);
}

template <typename T>
std::size_t Array<T>::size( void ) const
{
	return (this->capacity);
}

template <typename T>
Array<T>::Array(const Array& other)
{
	this->capacity = other.size();
	this->t = new T[this->capacity];

	for (std::size_t i = 0; i < this->capacity; i++)
	{
		this->t[i] = other.t[i];
	}
}

template <typename T>
Array<T> Array<T>::operator = (const Array& other)
{
	if (this == &other)
		return (*this);

	if (this->capacity != 0)
		delete (this->t);

	this->capacity = other.size();
	this->t = new T[this->capacity];

	for (std::size_t i = 0; i < this->capacity; i++)
	{
		this->t[i] = other.t[i]; 
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator [] (std::size_t index)
{
	if (index >= this->size())
		throw OutOfBoundsException();
	return (this->t[index]);
}

template <typename T>
const T& Array<T>::operator [] (std::size_t index) const
{
	if (index >= this->size())
		throw OutOfBoundsException();
	return (this->t[index]);
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Index is out of bounds.");
}
