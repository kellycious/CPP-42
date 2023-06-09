/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:39:55 by khuynh            #+#    #+#             */
/*   Updated: 2023/06/09 23:10:33 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string name;
		
	public:
		Zombie(std::string name);
		~Zombie(void);
		void announce(void);
};

	Zombie *newZombie(std::string name);
	void randomChump(std::string name);

#endif