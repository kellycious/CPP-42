/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:44:53 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/10 15:20:43 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "a = " << a << std::endl;
	std::cout << "processing ++a " << ++a << std::endl;
	std::cout << "++a = " << a << std::endl;
	std::cout << "processing a++ " << a++ << std::endl;
	std::cout << "a++ = " << a << std::endl;

	std::cout << "b = " << b << std::endl;

	std::cout << "Max = " << Fixed::max( a, b ) << std::endl;

// 	std::cout << "b / 0  = " << b/0 << std::endl;
	
	return (0);
}