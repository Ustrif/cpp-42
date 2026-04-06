#ifndef __ARR__
#define __ARR__

#include <string>
#include <exception>

template<typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(const Array& other);
		Array &operator = (const Array& other);

		std::size_t size( void ) const;

		T& operator [] (std::size_t index);
		const T& operator [] (std::size_t index) const;

	private:
		T			*t;
		std::size_t	capacity;

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#include "Array.tpp"
#endif // __ARR__