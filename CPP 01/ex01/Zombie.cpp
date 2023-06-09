/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:40:03 by khuynh            #+#    #+#             */
/*   Updated: 2023/06/09 23:11:59 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) { return;}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << this->name << " is born" << std::endl;
	return;
}

Zombie::~Zombie(void) 
{
	std::cout << this->name << " is dead" << std::endl;
	return;
}

void Zombie::Namer(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
