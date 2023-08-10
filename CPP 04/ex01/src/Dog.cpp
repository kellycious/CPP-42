/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:19:26 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/10 17:14:29 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->brain = new Brain();
	this->type = "Dog";
}

Dog::Dog(const Dog &cpy) : Animal (cpy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = cpy;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog default destructor called" << std::endl;
}

Dog& Dog ::operator=(const Dog &cpy)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &cpy)
		this->type = cpy.type;
	this->brain = new Brain();
	*this->brain = *cpy.brain;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "woof" << std::endl;
}

std::string Dog::getIdea(int i) const
{
	return this->brain->getIdea(i);
}

std::string Dog::setIdea(int i, std::string idea)
{
	return this->brain->setIdea(i, idea);
}