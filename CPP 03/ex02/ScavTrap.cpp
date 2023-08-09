/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 23:38:11 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/09 15:47:05 by khuynh           ###   ########.fr       */
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

void Scavtrap::attack(const std::string& target)
{
	if (this->energyPoints <= 0)
	{
		std::cout << this->name << " has no attacks left !" << std::endl;
		return ;
	}
	else if (this->hitPoints <= 0)
	{
		std::cout << this->name << " has no hp left!" << std::endl;
		return ;
	}
	else
	{
		this->energyPoints--;
		std::cout << "Scavtrap " << this->name << " attacks " << target << " [" << this->energyPoints << " attacks left]"<< std::endl;
	}
}

void Scavtrap::guardGate()
{
	std::cout << "Scavtrap is in Gate keeper mode" << std::endl;
}