/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:34:08 by khuynh            #+#    #+#             */
/*   Updated: 2023/07/14 15:52:23 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
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
		std::cout << "ClapTrap " << this->name << " has no energy points!" << std::endl;
		return ;
	}
	else if (this->hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " has no hit points!" << std::endl;
		return ;
	}
	else
	{
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= (unsigned int)this->hitPoints)
	{
		std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
		this->hitPoints = 0;
		return ;
	}
	else
	{
		this->hitPoints -= amount;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead, can't be repaired!" << std::endl;
		return ;
	}
	else if (this->energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy points, can't be repaired!" << std::endl;
		return ;
	}
	else
	{
		this->hitPoints += amount;
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name << " be repaired " << amount << " points!" << std::endl;
	}
}

