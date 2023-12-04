/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 01:18:15 by khuynh            #+#    #+#             */
/*   Updated: 2023/12/04 15:04:21 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	FJMI fjmi;
	try
	{
		fjmi.input_parse(ac, av);
		std::cout << "Input: ";
		fjmi.print_vector();
		fjmi.fordjohnson_vector();
		fjmi.fordjohnson_deque();
		std::cout << "After - vector: ";
		fjmi.print_vector();
		std::cout << "After - deque: ";
		fjmi.print_deque();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}	
}
