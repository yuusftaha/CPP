#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm> 
#include <iterator>

class Span 
{
	private:
		unsigned int        maxSize;
		std::vector<int>    numbers;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;

		template <typename T>
		void addNumbers(T begin, T end) 
		{
			if (std::distance(begin, end) + numbers.size() > maxSize)
				throw SpanFullException();
			numbers.insert(numbers.end(), begin, end);
		}

		class SpanFullException : public std::exception 
		{
			public:
				virtual const char* what() const throw() 
				{
					return "Exception: Span capacity is full!";
				}
		};

		class NotEnoughNumbersException : public std::exception 
		{
			public:
				virtual const char* what() const throw() 
				{
					return "Exception: Not enough numbers to calculate span!";
				}
		};
};

#endif