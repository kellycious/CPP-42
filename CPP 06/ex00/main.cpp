/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:30:24 by khuynh            #+#    #+#             */
/*   Updated: 2023/10/22 16:35:09 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main ()
{
	std::string literal;
	std::cout << "Enter a literal: ";
	std::cin >> literal;
	ScalarConverter sc;
	sc.convert(literal);
}