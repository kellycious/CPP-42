/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:39:55 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/08 15:21:22 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string name;
		
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void Namer(std::string name);
		void announce(void);
};

	Zombie *newZombie(std::string name);
	Zombie *zombieHorde(int N, std::string name);

#endif