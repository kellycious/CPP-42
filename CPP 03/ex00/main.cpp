/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:34:14 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/09 14:53:10 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap("Machin chouette");
	ClapTrap clap2(clap);
	ClapTrap clap3("Princesse Crapule");
	
	clap2 = clap3;
	
	std::cout << std::endl;
	std::cout << "Damage has been set to 5\n" << std::endl;
	
	clap.attack("Princesse Crapule");
	clap2.takeDamage(5);

	std::cout << std::endl;
	clap2.attack("Machin chouette");
	clap.takeDamage(5);

	std::cout << std::endl;
	clap.attack("Princesse Crapule");
	clap2.takeDamage(5);
	std::cout << std::endl;
	
	return 0;
}