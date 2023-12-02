/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 01:18:15 by khuynh            #+#    #+#             */
/*   Updated: 2023/12/02 01:27:42 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	FJMI fjmi;
	try
	{
		fjmi.input_parse(ac, av);
		std::cout << "Before: ";
		fjmi.print_vector();
		fjmi.sort_vector();
		std::cout << "After: ";
		fjmi.print_vector();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}	
}
