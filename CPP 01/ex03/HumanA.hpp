/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 23:36:00 by khuynh            #+#    #+#             */
/*   Updated: 2023/06/09 23:57:37 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <Weapon.hpp>

class HumanA
{
	private:
		Weapon	weapon;
		std::string name;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void	attack(void);
};

#endif