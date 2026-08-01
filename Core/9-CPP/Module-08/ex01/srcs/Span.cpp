#include "Span.hpp"
#include <algorithm>

Span::Span()
	: n(0) {}

Span::Span(unsigned int n)
	: n(n) {}

Span::Span(const Span& other)
	: n(other.n),
		elements(other.elements) {}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this -> n = other.n;
		this -> elements = other.elements;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (this -> elements.size() >= this -> n)
		throw SpanFullException();
	this -> elements.push_back(number);
}

int Span::shortestSpan()
{
	if (this -> elements.size() < 2)
		throw NoSpanException();

	std::vector<int> sortedElements = this -> elements;
	std::sort(sortedElements.begin(), sortedElements.end());

	int shortest = sortedElements[1] - sortedElements[0];
	for (size_t i = 1; i < sortedElements.size() - 1; i++)
	{
		int diff = sortedElements[i + 1] - sortedElements[i];
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

int Span::longestSpan()
{
	if (this -> elements.size() < 2)
		throw NoSpanException();

	int max = *std::max_element(this -> elements.begin(), this -> elements.end());
	int min = *std::min_element(this -> elements.begin(), this -> elements.end());

	return max - min;
}