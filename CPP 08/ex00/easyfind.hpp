/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:49:31 by khuynh            #+#    #+#             */
/*   Updated: 2023/11/05 18:46:28 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <stdexcept>

class nomatch : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return "No match found";
		}
};

template <typename T>
int	easyfind(T &one, int second)
{
	typename T::iterator result  = std::find(one.begin(), one.end(), second);
	if (result != one.end())
		return *result;
	throw nomatch();
}

#endif