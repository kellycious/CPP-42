/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:19:26 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/15 16:04:48 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->brain = new Brain();
	this->type = "Dog";
}

Dog::Dog(const Dog &cpy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = cpy.type;
	this->brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(i, cpy.brain->getIdea(i));
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog default destructor called" << std::endl;
}

Dog& Dog ::operator=(const Dog &cpy)
{
	std::cout << "Assignment operator called" << std::endl;
	this->type = cpy.type;
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(i, cpy.brain->getIdea(i));
	return *this;
}

Brain* Dog::getBrain() const
{
	return this->brain;
}

void Dog::makeSound() const
{
	std::cout << "woof" << std::endl;
}
