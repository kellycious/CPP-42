/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:33:27 by khuynh            #+#    #+#             */
/*   Updated: 2023/11/28 23:40:40 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int ac, char**av)
{
	if (ac == 2)
	{
		RPN rpn;
		try
		{
			rpn.Execute(av[1]);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else
		std::cout << "Usage: ./rpn \"expression\"" << std::endl;
}