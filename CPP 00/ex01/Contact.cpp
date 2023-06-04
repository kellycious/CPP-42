/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 02:00:20 by khuynh            #+#    #+#             */
/*   Updated: 2023/06/04 02:25:28 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

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

void	Contact::input_contact(void)
{
	std::string input;
	
	std::cout << "Enter first name: "<< std::endl;
	std::cin >> input;
	this->first_name = input;


	std::cout << "Enter last name: "<< std::endl;
	std::cin >> input;
	this->last_name = input;

	std::cout << "Enter nickname: "<< std::endl;
	std::cin >> input;
	this->nickname = input;

	std::cout << "Enter phone number: "<< std::endl;
	std::cin >> input;
	this->phone_nb = input;
	
	std::cout << "Enter darkest secret:"<< std::endl;
	std::cin >> input;
	this->darkest_secret = input;
}