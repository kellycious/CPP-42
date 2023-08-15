/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:00:33 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/15 15:56:40 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &cpy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = cpy.ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain default destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain &cpy)
{
	std::cout << "Brain assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = cpy.ideas[i];
	return *this;
}

std::string Brain::getIdea(int i) const
{
	return this->ideas[i];
}

void Brain::setIdea(int i, std::string idea)
{
	if (i < 0 || i > 99)
	{
		std::cout << "Index out of bound" << std::endl;
		return ;
	}
	this->ideas[i] = idea;
}