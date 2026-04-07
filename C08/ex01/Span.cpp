#include "Span.hpp"

Span::Span(unsigned int n)
{
	this->capacity = n;
}

Span::Span(const Span& other) : datas(other.datas) 
{
	this->capacity = other.getCapacity();
}

Span& Span::operator = (const Span& other)
{
	if (this == &other)
		return (*this);

	this->capacity = other.getCapacity();
	this->datas.assign(other.datas.begin(), other.datas.end());

	return (*this);
}

Span::Span() : capacity(0), datas() {}

Span::~Span() {}

std::size_t Span::shortestSpan()
{
	if (datas.size() <= 1)
		throw (Span::NoSpanException());

	std::vector<int> sorted = datas;
	std::sort(sorted.begin(), sorted.end());

	std::size_t	distance = sorted.at(1) - sorted.at(0);
	
	for (std::size_t i = 0; i < sorted.size() - 1; i++)
	{
		if ((std::size_t) (sorted.at(i + 1) - sorted.at(i)) < distance)
			distance = (sorted.at(i + 1) - sorted.at(i));
	}

	return (distance);
}

std::size_t Span::longestSpan()
{
	if (datas.size() <= 1)
		throw (Span::NoSpanException());
		
	return (*std::max_element(datas.begin(), datas.end())
			- *std::min_element(datas.begin(), datas.end()));
}

void Span::addNumber(int number)
{
	if (this->datas.size() + 1 > this->getCapacity())
		throw (Span::FullSpanException());

	this->datas.push_back(number);
}

std::size_t	Span::getCapacity( void ) const
{
	return (this->capacity);
}

const char* Span::FullSpanException::what() const throw()
{
	return ("Capacity is already full!");
}

const char* Span::NoSpanException::what() const throw()
{
	return ("Span needs min 2 numbers!");
}
