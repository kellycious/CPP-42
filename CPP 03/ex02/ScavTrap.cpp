/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 23:38:11 by khuynh            #+#    #+#             */
/*   Updated: 2023/07/16 20:42:55 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

Scavtrap::Scavtrap() : ClapTrap()
{
	std::cout << "Scavtrap default constructor called" << std::endl;
}

Scavtrap::Scavtrap(std::string const& name) : ClapTrap(name)
{
	std::cout << "Scavtrap constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

Scavtrap::Scavtrap(Scavtrap const& cpy) : ClapTrap(cpy)
{
	std::cout << "Scavtrap copy constructor called" << std::endl;
	*this = cpy;
}

Scavtrap::~Scavtrap()
{
	std::cout << "Scavtrap destructor called" << std::endl;
}

Scavtrap& Scavtrap::operator=(Scavtrap const& rhs)
{
	std::cout << "Scavtrap assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	return *this;
}

void Scavtrap::guardGate()
{
	std::cout << "Scavtrap is in Gate keeper mode" << std::endl;
}