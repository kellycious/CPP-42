/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:17:44 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/10 00:21:26 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Cat.hpp"

Cat::Cat() : Animal ()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	std::cout << this->type << std::endl;
}

Cat::Cat(const Cat &cpy) : Animal(cpy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = cpy;
}

Cat::~Cat()
{
	std::cout << "Cat default destructor called" << std::endl;
}

Cat& Cat ::operator=(const Cat &cpy)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &cpy)
		this->type = cpy.type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "meow" << std::endl;
}
