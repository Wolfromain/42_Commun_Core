/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:08:01 by rbouquet          #+#    #+#             */
/*   Updated: 2025/06/18 10:58:50 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
	// std::cout << "Default constructor called" << std::endl;
}

Span::Span(const Span &cpy) : _n(cpy._n), _numbers(cpy._numbers)
{
	// std::cout << "Copy constructor called" << std::endl;
}

Span &Span::operator=(const Span &f)
{
	if (this != &f)
	{
		_n = f._n;
		_numbers = f._numbers;
	}
	// std::cout << "Assignment operator called" << std::endl;
	return *this;
}

Span::~Span()
{
		// std::cout << "Destructor called" << std::endl;
}

void Span::addNumber(int number)
{
	if (number < INT_MIN || number > INT_MAX)
		throw OutOfRange();
	if (_numbers.size() > _n)
		throw OutOfRange();
	_numbers.push_back(number);
}

int Span::shortestSpan() const
{
	int j;
	if (_numbers.size() < 2)
		throw OutOfRange();
	int minSpan = INT_MAX;
	std::vector<int> tmp_tab = _numbers;
	std::sort(tmp_tab.begin(), tmp_tab.end());
	for (size_t i = 0; i < tmp_tab.size() - 1; ++i)
	{
		j = tmp_tab[i + 1] - tmp_tab[i];
		if (j < minSpan)
			minSpan = j;
	}
	return (minSpan);
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw OutOfRange();
	int maxSpan = INT_MIN;
	std::vector<int> tmp_tab = _numbers;
	std::sort(tmp_tab.begin(), tmp_tab.end());
	maxSpan = tmp_tab.back() - tmp_tab.front();
	return (maxSpan);
}

void Span::randomFill()
{
	int min = -10;
	int max = 10;

	if (_numbers.size() >= _n)
		throw OutOfRange();
	std::srand(std::time(0));
	for (size_t i = _numbers.size(); i < _n; ++i)
		_numbers.push_back(min + (std::rand() % (max - min + 1)));
}