#ifndef	SPAN_CLASS
#define SPAN_CLASS

#include <vector>
#include <algorithm>
#include <iterator>
#include <list>

class Span
{
	public:
		Span();
		Span(unsigned int n);
		~Span();
		Span(const Span& other);
		Span& operator = (const Span& other);

		void addNumber(int number);
		std::size_t shortestSpan();
		std::size_t longestSpan();
		std::size_t	getCapacity( void ) const;

		template <typename InputIterator>
		void	addNumbers(InputIterator first, InputIterator last);

	private:
		unsigned int		capacity;
		std::vector<int>	datas;


	class FullSpanException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class NoSpanException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

template <typename T>
void Span::addNumbers(T first, T last)
{
	if (std::distance(first, last) + datas.size() > capacity)
		throw Span::FullSpanException();

	datas.insert(datas.end(), first, last);
}

#endif // SPAN_CLASS
