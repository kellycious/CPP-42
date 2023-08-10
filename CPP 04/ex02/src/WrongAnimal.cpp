/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:11:13 by khuynh            #+#    #+#             */
/*   Updated: 2023/07/16 23:30:51 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Wrong Animal default constructor called" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &cpy)
{
	std::cout << "Wrong Animal copy constructor called" << std::endl;
	*this = cpy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal default destructor called" << std::endl;
}

WrongAnimal& WrongAnimal ::operator=(const WrongAnimal &cpy)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &cpy)
		this->type = cpy.type;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "quack" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}
