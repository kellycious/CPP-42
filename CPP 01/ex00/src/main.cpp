/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:39:44 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/08 15:17:07 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Zombie.hpp"

int main()
{
	std::string input;
	std::cout << "Please enter a name for your zombie" << std::endl;
	std::cin >> input;
	Zombie *newy = newZombie(input);
	newy->announce();
	delete newy;
	randomChump("random");
	return 0;
}