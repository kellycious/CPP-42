/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:34:08 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/09 15:40:06 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hitPoints(100), energyPoints(100), attackDamage(30)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(100), energyPoints(100), attackDamage(30)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &cp)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = cp;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &cp)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this != &cp)
	{
		this->name = cp.name;
		this->hitPoints = cp.hitPoints;
		this->energyPoints = cp.energyPoints;
		this->attackDamage = cp.attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
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
	std::cout << this->name << " attacks " << target << " [" << this->energyPoints << " attacks left]"<< std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= (unsigned int)this->hitPoints)
	{
		std::cout << this->name << " is dead!" << std::endl;
		this->hitPoints = 0;
		return ;
	}
	else
	{
		this->hitPoints -= amount;
		std::cout << this->name << " took " << amount << " points of damage!" << " [" << this->hitPoints << " hp left]" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints <= 0)
	{
		std::cout << this->name << " is dead, can't be saved!" << std::endl;
		return ;
	}
	else if (this->energyPoints <= 0)
	{
		std::cout << this->name << " has no energy point left, can't be boost!" << std::endl;
		return ;
	}
	else
	{
		this->hitPoints += amount;
		this->energyPoints--;
		std::cout << this->name << " gained " << amount << " attacks!" << std::endl;
	}
}

