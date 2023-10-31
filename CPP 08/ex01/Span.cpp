/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:53:49 by khuynh            #+#    #+#             */
/*   Updated: 2023/11/01 00:03:05 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : N(N) {}

Span::~Span(){}

Span::Span(Span const &cpy) : N(cpy.N){}

Span	&Span::operator=(Span const &cpy)
{
	if (this!= &cpy)
		N = cpy.N;
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->size != this->N)
		this->
}