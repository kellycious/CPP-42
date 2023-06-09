/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:31:18 by khuynh            #+#    #+#             */
/*   Updated: 2023/06/09 23:17:27 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *zombies = new Zombie[N];
	std::cout << name << " horde of Zombie is born" << std::endl;
	for (int i = 0; i < N; i++)
		zombies[i].Namer(name);
	return zombies;
}