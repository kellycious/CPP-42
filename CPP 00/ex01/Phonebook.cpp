/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 02:27:50 by khuynh            #+#    #+#             */
/*   Updated: 2023/06/04 02:38:45 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	std::cout << "Phonebook constructor called" << std::endl;
	return ;
}
Phonebook::~Phonebook(void)
{
	std::cout << "Phonebook destructor called" << std::endl;
	return ;
}

void	Phonebook::add_contact(Phonebook *phonebook)
{
	if (phonebook->index == 8)
		phonebook->index = 0;
	phonebook->contact[phonebook->index].input_contact();
	phonebook->index++;
}

int	Phonebook::search_contact(Phonebook *phonebook)
{
	int	input;
	if (phonebook->index == 0)
		return (std::cout << "No contact to display" << std::endl, 0);
	std::cout << "Enter contact index: " << std::endl;
	std::cin >> input;
	if (input < 0 || input > 7)
		return (std::cout << "Invalid index" << std::endl, 0);
	std::cout << "First name: " << phonebook->contact[input].input_fn() << std::endl;
	std::cout << "Last name: " << phonebook->contact[input].input_ln() << std::endl;
	std::cout << "Nickname: " << phonebook->contact[input].input_nickname() << std::endl;
	std::cout << "Phone number: " << phonebook->contact[input].input_nb() << std::endl;
	std::cout << "Darkest secret: " << phonebook->contact[input].input_dsecret() << std::endl;
	return (0);
}