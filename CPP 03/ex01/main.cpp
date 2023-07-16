/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:34:14 by khuynh            #+#    #+#             */
/*   Updated: 2023/07/16 13:19:51 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ClapTrap first("Kelly");
	Scavtrap second("Nour");
	
	first.attack("Nour");
	second.takeDamage(50);
	second.guardGate();
	first.attack("Nour");
	second.takeDamage(50);
	
	return (0);
}