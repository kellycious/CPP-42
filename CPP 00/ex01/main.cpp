/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:05:09 by khuynh            #+#    #+#             */
/*   Updated: 2023/06/09 18:47:52 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/Phonebook.hpp"
#include "lib/Contact.hpp"

int	main()
{
	Phonebook allo;
	std::cout << "\033[35mWelcome to the phonebook\033[0m" << std::endl;
	while (1)
	{
		std::string input;
		std::cout << "Please enter your request (\033[32mADD\033[0m | \033[34mSEARCH\033[0m | \033[33mEXIT\033[0m)" << std::endl;
		std::cin >> input;
		if (input == "ADD")
			allo.add_contact(&allo);
		else if (input == "SEARCH")
			allo.search_contact(&allo);
		else if (input == "EXIT")
			break ;
		else
			std::cout << "\033[31mInvalid request\033[0m" << std::endl;
	}
}