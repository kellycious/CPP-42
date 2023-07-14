/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:34:14 by khuynh            #+#    #+#             */
/*   Updated: 2023/07/14 15:50:08 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap("Machin chouette");
	ClapTrap clap2(clap);
	ClapTrap clap3;
	
	clap3 = clap2;
	
	clap.attack("Princesse Crapule");
	clap.takeDamage(5);
	clap.beRepaired(5);
	
	return 0;
}