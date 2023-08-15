/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:17:44 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/15 16:05:32 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Cat.hpp"

Cat::Cat() 
{
	std::cout << "Cat default constructor called" << std::endl;
	this->brain = new Brain();
	this->type = "Cat";
}

Cat::Cat(const Cat &cpy) 
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = cpy.type;
	this->brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(i, cpy.brain->getIdea(i));
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
		this->brain->setIdea(i, cpy.brain->getIdea(i));
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "meow" << std::endl;
}

Brain* Cat::getBrain() const
{
	return this->brain;
}
