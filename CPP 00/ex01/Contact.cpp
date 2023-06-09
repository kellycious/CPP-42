/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 02:00:20 by khuynh            #+#    #+#             */
/*   Updated: 2023/06/09 20:15:31 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Contact constructor called" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	std::cout << "Contact destructor called" << std::endl;
	return ;
}
std::string	Contact::input_fn(void)
{
	return (this->first_name);
}

std::string	Contact::input_ln(void)
{
	return (this->last_name);
}

std::string	Contact::input_nickname(void)
{
	return (this->nickname);
}

std::string	Contact::input_nb(void)
{
	return (this->phone_nb);
}

std::string	Contact::input_dsecret(void)
{
	return (this->darkest_secret);
}

int	Contact::input_contact(void)
{
	std::string input;
	
	std::cout << "Enter first name: "<< std::endl;
	std::cin.ignore();
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "\033[31mField cannot be empty\033[0m" << std::endl;
		std::cout << "Enter first name: "<< std::endl;
		std::getline(std::cin, input);
		if (!input.empty())
			break ;
	}
	this->first_name = input;

	std::cout << "Enter last name: "<< std::endl;
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "\033[31mField cannot be empty\033[0m" << std::endl;
		std::cout << "Enter last name: "<< std::endl;
		std::getline(std::cin, input);
		if (!input.empty())
			break ;
	}
	this->last_name = input;

	std::cout << "Enter nickname: "<< std::endl;
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "\033[31mField cannot be empty\033[0m" << std::endl;
		std::cout << "Enter nickname: "<< std::endl;
		std::getline(std::cin, input);
		if (!input.empty())
			break ;
	}
	this->nickname = input;

	std::cout << "Enter phone number: "<< std::endl;
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "\033[31mField cannot be empty\033[0m" << std::endl;
		std::cout << "Enter phone number: "<< std::endl;
		std::getline(std::cin, input);
		if (!input.empty())
			break ;
	}
	this->phone_nb = input;
	
	std::cout << "Enter darkest secret:"<< std::endl;
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "\033[31mField cannot be empty\033[0m" << std::endl;
		std::cout << "Enter darkest secret: "<< std::endl;
		std::getline(std::cin, input);
		if (!input.empty())
			break ;
	}
	this->darkest_secret = input;
	return (0);
}
