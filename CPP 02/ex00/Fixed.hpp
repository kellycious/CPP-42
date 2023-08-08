/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:45:03 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/09 00:07:05 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	private:
		int value;
		static const int bits = 8;
	
	public:
		Fixed();
		Fixed(const Fixed &f);
		Fixed& operator=(const Fixed &fixed);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
} ;

#endif