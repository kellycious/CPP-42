/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:34:14 by khuynh            #+#    #+#             */
/*   Updated: 2023/07/15 23:35:28 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap("Machin chouette");
	ClapTrap clap2(clap);
	ClapTrap clap3("Princesse Crapule");
	
	clap2 = clap3;
	
	clap.attack("Princesse Crapule");
	clap2.takeDamage(5);

	clap2.attack("Machin chouette");
	clap.takeDamage(5);

	clap.attack("Princesse Crapule");
	clap2.takeDamage(5);
	
	return 0;
}