#include "Span.hpp"
#include <numeric> 
#include <limits>

Span::Span() : maxSize(0) {}

Span::Span(unsigned int N) : maxSize(N) {}

Span::Span(const Span& other) : maxSize(other.maxSize), numbers(other.numbers) {}

Span::~Span() {}

Span& Span::operator=(const Span& other) 
{
    if (this != &other) {
        this->maxSize = other.maxSize;
        this->numbers = other.numbers; 
    }
    return *this;
}

void Span::addNumber(int number) 
{
    if (numbers.size() >= maxSize)
        throw SpanFullException();
    numbers.push_back(number);
}

int Span::shortestSpan() const 
{
    if (numbers.size() < 2)
        throw NotEnoughNumbersException();

    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();

    for (size_t i = 1; i < sorted.size(); ++i)
	{
        int currentSpan = sorted[i] - sorted[i - 1];
        if (currentSpan < minSpan)
            minSpan = currentSpan;
    }
    return minSpan;
}

int Span::longestSpan() const 
{
    if (numbers.size() < 2)
        throw NotEnoughNumbersException();

    std::vector<int>::const_iterator minIt = std::min_element(numbers.begin(), numbers.end());
    std::vector<int>::const_iterator maxIt = std::max_element(numbers.begin(), numbers.end());

    return *maxIt - *minIt;
}