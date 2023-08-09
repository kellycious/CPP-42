/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:17:44 by khuynh            #+#    #+#             */
/*   Updated: 2023/07/16 23:31:03 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "Duck";
}

WrongCat::WrongCat(const WrongCat &cpy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = cpy;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat default destructor called" << std::endl;
}

WrongCat& WrongCat ::operator=(const WrongCat &cpy)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &cpy)
		this->type = cpy.type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "quack" << std::endl;
}

std::string WrongCat::getType() const
{
	return ("Duck");
}