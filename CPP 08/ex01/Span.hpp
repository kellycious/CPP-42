/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:54:02 by khuynh            #+#    #+#             */
/*   Updated: 2023/11/05 17:51:10 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <exception>
# include <limits>

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
		
		class Nospan : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Empty array or only one nb stored, thus no span found";
				}
		};

		class Maxnb : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Cannot add nb, no more available space";
				}
		};
		
	protected:
		unsigned int				N;
		unsigned int				size;
		std::vector<int>	array;
};

#endif