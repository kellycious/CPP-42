/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:17:44 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/11 17:14:21 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Cat.hpp"

Cat::Cat() : Animal ()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->brain = new Brain();
	this->type = "Cat";
}

Cat::Cat(const Cat &cpy) : Animal(cpy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = cpy;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat default destructor called" << std::endl;
}

Cat& Cat ::operator=(const Cat &cpy)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &cpy)
		this->type = cpy.type;
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(i, cpy.getIdea(i));
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "meow" << std::endl;
}

std::string Cat::getIdea(int i) const
{
	return this->brain->getIdea(i);
}

std::string Cat::setIdea(int i, std::string idea)
{
	return this->brain->setIdea(i, idea);
}
