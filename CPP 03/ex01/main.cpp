/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:34:14 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/09 15:31:07 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ClapTrap first("Kelly");
	Scavtrap second("Nour");

	std::cout << std::endl;
	std::cout << "Damage set to 50 for ClapTrap\n" << std::endl;
	
	first.attack("Nour");
	second.takeDamage(50);

	std::cout << std::endl;
	second.guardGate();
	std::cout << std::endl;
	
	second.attack("Kelly");
	first.takeDamage(20);

	std::cout << std::endl;
	
	return (0);
}