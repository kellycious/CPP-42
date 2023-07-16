/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:57:22 by khuynh            #+#    #+#             */
/*   Updated: 2023/07/16 20:54:58 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const &cpy) : ClapTrap(cpy)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = cpy;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &cpy)
{
	std::cout << "FragTrap assignation operator called" << std::endl;
	if ( this != &cpy)
	{
		this->name = cpy.name;
		this->attackDamage = cpy.attackDamage;
		this->energyPoints = cpy.energyPoints;
		this->hitPoints = cpy.hitPoints;
	}
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << this-> name << " calls for a High Five" << std::endl;
}