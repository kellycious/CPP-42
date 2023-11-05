/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:53:49 by khuynh            #+#    #+#             */
/*   Updated: 2023/11/05 18:54:48 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : N(N) {}

Span::~Span(){}

Span::Span(Span const &cpy) : N(cpy.N), size(cpy.size), array(cpy.array) {}

Span	&Span::operator=(Span const &cpy)
{
	if (this!= &cpy)
	{
		N = cpy.N;
		size = cpy.size;
		array = cpy.array;
	}
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->size == this->N)
		throw Span::Maxnb();
	this->array.push_back(n);
	this->size++;
}

void	Span::betterAdd(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (std::distance(begin, end) > int (this->N - this->size))
		throw Span::Maxnb();
	array.insert(array.end(), begin, end);
}

int		Span::shortestSpan()
{
	if (this->array.size() <= 1)
		throw Span::Nospan();
	
	std::vector<int> SortArray(this->array);
	std::sort(SortArray.begin(), SortArray.end());

	
	int	span = __INT_MAX__;

	for (size_t i = 1; i < SortArray.size() ; ++i)
	{
		int diff = SortArray[i] - SortArray[i - 1];
		if (diff < span)
			span = diff;
	}
	return span;
}

int		Span::longestSpan()
{
	if (this->array.size() <= 1)
		throw Span::Nospan();
	
	int max = *std::max_element(this->array.begin(), this->array.end());
	int min = *std::min_element(this->array.begin(), this->array.end());

	return max - min;
}