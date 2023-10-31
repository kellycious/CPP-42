/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:54:02 by khuynh            #+#    #+#             */
/*   Updated: 2023/11/01 00:04:55 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <stdexcept>

class Span
{
	public:
		Span(unsigned int N);
		Span(Span const &cpy);
		~Span();

		Span& operator=(Span const &op);

		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();

		class NoSpan : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "No span can be found";
				}
		};
		
	protected:
		unsigned int	N;
		unsigned int	size;
};

#endif