/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:34:14 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/09 15:48:36 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	ClapTrap first("Kelly");
	Scavtrap second("Nour");
	FragTrap third("Love");

	std::cout << std::endl;
	
	first.attack("Nour");
	second.takeDamage(30);
	std::cout << std::endl;
	second.guardGate();
	third.highFivesGuys();
	std::cout << std::endl;
	second.attack("Kelly");
	first.takeDamage(30);
	std::cout << std::endl;
	
	return (0);
}