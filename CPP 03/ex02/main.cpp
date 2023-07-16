/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:34:14 by khuynh            #+#    #+#             */
/*   Updated: 2023/07/16 20:54:10 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	ClapTrap first("Kelly");
	Scavtrap second("Nour");
	FragTrap third("Love");
	
	first.attack("Nour");
	second.takeDamage(50);
	second.guardGate();
	third.highFivesGuys();
	second.attack("Kelly");
	first.takeDamage(20);
	
	return (0);
}