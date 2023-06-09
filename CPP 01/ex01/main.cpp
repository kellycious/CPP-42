/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:39:44 by khuynh            #+#    #+#             */
/*   Updated: 2023/06/09 23:16:27 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::string input;
	std::cout << "Please enter a name for your horde" << std::endl;
	std::cin >> input;
	Zombie *zombies = zombieHorde(5, input);
	for (int i = 0; i < 5; i++)
		zombies[i].announce();
	delete [] zombies;
	return 0;
}