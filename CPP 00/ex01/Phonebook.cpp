/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 02:27:50 by khuynh            #+#    #+#             */
/*   Updated: 2023/06/09 19:11:56 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/Phonebook.hpp"
#include "lib/Contact.hpp"

Phonebook::Phonebook(void)
{
	std::cout << "Phonebook constructor called" << std::endl;
	this->index = 0;
	return ;
}
Phonebook::~Phonebook(void)
{
	std::cout << "Phonebook destructor called" << std::endl;
	return ;
}

void	Phonebook::displayer(std::string str)
{
	int	len = 10 - str.length();
	while (len > 0)
	{
		std::cout << " ";
		len--;
	}
	if (str.length() <= 10)
		std::cout << str;
	else
		std::cout << str.substr(0, 9) << ".";
}

void	Phonebook::add_contact(Phonebook *phonebook)
{
	static int	i;
	phonebook->contact[i].input_contact();
	i++;
	if (i == 8)
		i = 0;
	if (phonebook->index < 8)
		phonebook->index++;
}

int	Phonebook::search_contact(Phonebook *phonebook)
{
	std::string	input;
	int			inputy;
	if (phonebook->index == 0)
		return (std::cout << "\033[31mNo contact to display\033[0m" << std::endl, 0);
	std::cout << " \033[1m\033[37mINDEX | FIRST NAME | LAST NAME | NICKNAME\033[0m" << std::endl;
	for (int i = 0; i < phonebook->index; i++)
	{
		std::cout << "    "<< i << "  |";
		phonebook[i].displayer(contact[i].input_fn());
		std::cout << "  |";
		phonebook[i].displayer(contact[i].input_ln());
		std::cout << " |";
		phonebook[i].displayer(contact[i].input_nickname());
		std::cout << std::endl;
	}
	std::cout << "Enter contact index: " << std::endl;
	std::cin >> input;
	for (int i = 0; i < (int)input.length(); i++)
		if (!std::isdigit(input[i]))
			return (std::cout << "\033[31mInvalid command\033[0m" << std::endl, 0);
	inputy = std::atoi(input.c_str());
	if (inputy > phonebook->index - 1 || inputy < 0 || inputy > 7)
		return (std::cout << "\033[31mInvalid index\033[0m" << std::endl, 0);
	std::cout << "First name: " << phonebook->contact[inputy].input_fn() << std::endl;
	std::cout << "Last name: " << phonebook->contact[inputy].input_ln() << std::endl;
	std::cout << "Nickname: " << phonebook->contact[inputy].input_nickname() << std::endl;
	std::cout << "Phone number: " << phonebook->contact[inputy].input_nb() << std::endl;
	std::cout << "Darkest secret: " << phonebook->contact[inputy].input_dsecret() << std::endl;
	return (0);
}